from cwrap import BaseCClass
from ecl.util.util import StringList
from res import ResPrototype
from res.job_queue import JobStatusType, ThreadStatusType
from threading import Thread, Lock

import time


class JobQueueNode(BaseCClass):
    TYPE_NAME = "job_queue_node"
    
    _alloc = ResPrototype("void* job_queue_node_alloc_python(char*,"\
                                            "char*,"\
                                            "char*,"\
                                            "int, "\
                                            "stringlist,"\
                                            "int, "\
                                            "char*,"\
                                            "char*,"\
                                            "char*"\
                                            ")", bind=False)
    _free = ResPrototype("void job_queue_node_free(job_queue_node)")
    _submit = ResPrototype("int job_queue_node_submit_simple(job_queue_node, driver)")
    _kill = ResPrototype("bool job_queue_node_kill_simple(job_queue_node, driver)")
    
    _get_status = ResPrototype("int job_queue_node_get_status(job_queue_node)")
    _update_status = ResPrototype("bool job_queue_node_update_status_simple(job_queue_node, driver)")
    _set_status = ResPrototype("void job_queue_node_set_status(job_queue_node, int)")
    _get_submit_attempt = ResPrototype("int job_queue_node_get_submit_attempt(job_queue_node)")

    def __init__(self,job_script, job_name, run_path, num_cpu, 
                    status_file, ok_file, exit_file, 
                    done_callback_function, exit_callback_function, callback_arguments):
        self.done_callback_function = done_callback_function
        self.exit_callback_function = exit_callback_function
        self.callback_arguments = callback_arguments
        argc = 1
        argv = StringList()
        argv.append(run_path)

        self._thread_status = ThreadStatusType.THREAD_READY
        self._thread = None
        self._mutex = Lock()

        self.run_path = run_path
        c_ptr = self._alloc(job_name, run_path, job_script, argc, argv, num_cpu,
                                ok_file, status_file, exit_file, 
                                None, None, None, None)

        if c_ptr is not None:
            super(JobQueueNode, self).__init__(c_ptr)
        else:
            raise ValueError("Unable to create job node object")
    def free(self):
        self._free()

    @property
    def submit_attempt(self):
        return self._get_submit_attempt()

    @property
    def status(self):
        return self._get_status()

    @property
    def thread_status(self):
        return self._thread_status

    def submit(self, driver):
        self._submit(driver)

    def run_done_callback(self):
        return self.done_callback_function(self.callback_arguments)

    def run_exit_callback(self):
        return self.exit_callback_function(self.callback_arguments)
    
    def is_running(self):
        return (self.status ==  JobStatusType.JOB_QUEUE_PENDING or
                self.status == JobStatusType.JOB_QUEUE_SUBMITTED or
                self.status == JobStatusType.JOB_QUEUE_RUNNING  or
                self.status == JobStatusType.JOB_QUEUE_UNKNOWN) # dont stop monitoring if LSF commands are unavailable
    
    def _job_monitor(self, driver, max_submit):

        self._submit(driver)
        self.update_status(driver)

        while self.is_running():
            time.sleep(1)
            self.update_status(driver)
            if self._thread_status == ThreadStatusType.THREAD_STOPPING:
                self._kill(driver)
        if self.status == JobStatusType.JOB_QUEUE_DONE:
            self.run_done_callback()
        elif self.status == JobStatusType.JOB_QUEUE_EXIT:
            if self.submit_attempt < max_submit:
                self._set_thread_status(ThreadStatusType.THREAD_READY)
                return
            else:
                self._set_status(JobStatusType.JOB_QUEUE_FAILED)
                self.run_exit_callback()
        elif self.status == JobStatusType.JOB_QUEUE_IS_KILLED:
            pass
        else:
            self._set_thread_status(ThreadStatusType.THREAD_FAILED)
            raise AssertionError("Unexpected job status type after running job: {}".format(self.status))

        self._set_thread_status(ThreadStatusType.THREAD_DONE)

    def run(self, driver, max_submit=2):
        # Prevent multiple threads working on the same object
        self.wait_for()
        # Do not start if already kill signal is sent
        if self._thread_status == ThreadStatusType.THREAD_STOPPING:
            self._set_thread_status(threadStatusType.THREAD_DONE)

            return
        self._thread_status = ThreadStatusType.THREAD_RUNNING
        try:
            self._thread = Thread(target=self._job_monitor, args=(driver, max_submit))
            self._thread.start()
        except (RuntimeError, NameError):
            self._set_thread_status(ThreadStatusType.THREAD_FAILED)
        
    def stop(self):
        if self._thread_status == ThreadStatusType.THREAD_RUNNING: 
            self._set_thread_status(ThreadStatusType.THREAD_STOPPING)
        else:
            self._set_thread_status(ThreadStatusType.THREAD_DONE)

    def wait_for(self):
        if self._thread is not None and self._thread.is_alive():
            self._thread.join()

    def update_status(self, driver):
        if self.status != JobStatusType.JOB_QUEUE_WAITING:
            self._update_status(driver)

    def _set_thread_status(self, new_status):
        self._mutex.acquire()
        self._thread_status = new_status
        self._mutex.release()
