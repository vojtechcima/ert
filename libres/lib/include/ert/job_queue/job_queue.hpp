/*
   Copyright (C) 2011  Equinor ASA, Norway.

   The file 'job_queue.h' is part of ERT - Ensemble based Reservoir Tool.

   ERT is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ERT is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.

   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html>
   for more details.
*/

#ifndef ERT_JOB_QUEUE_H
#define ERT_JOB_QUEUE_H
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

#include <ert/res_util/path_fmt.hpp>

#include <ert/job_queue/job_node.hpp>
#include <ert/job_queue/queue_driver.hpp>

typedef struct job_queue_struct job_queue_type;
extern "C" PY_USED void job_queue_submit_complete(job_queue_type *queue);
extern "C" void job_queue_set_driver(job_queue_type *queue,
                                     queue_driver_type *driver);
extern "C" job_queue_type *job_queue_alloc(int, const char *ok_file,
                                           const char *status_file,
                                           const char *exit_file);
extern "C" void job_queue_free(job_queue_type *);

int job_queue_add_job(job_queue_type *, const char *run_cmd,
                      job_callback_ftype *done_callback,
                      job_callback_ftype *retry_callback,
                      job_callback_ftype *exit_callback, void *callback_arg,
                      int num_cpu, const char *, const char *, int argc,
                      const char **argv);

bool job_queue_accept_jobs(const job_queue_type *queue);

void *job_queue_run_jobs__(void *);

int job_queue_iget_status_summary(const job_queue_type *queue,
                                  job_status_type status);

extern "C" PY_USED void
job_queue_set_max_job_duration(job_queue_type *queue, int max_duration_seconds);
extern "C" bool job_queue_kill_job(job_queue_type *queue, int job_index);
extern "C" PY_USED bool job_queue_is_running(const job_queue_type *queue);
void job_queue_set_max_submit(job_queue_type *job_queue, int max_submit);
extern "C" int job_queue_get_max_submit(const job_queue_type *job_queue);
extern "C" int job_queue_get_num_running(const job_queue_type *queue);
extern "C" int job_queue_get_num_pending(const job_queue_type *queue);
extern "C" int job_queue_get_num_waiting(const job_queue_type *queue);
extern "C" int job_queue_get_num_complete(const job_queue_type *queue);
extern "C" PY_USED void *job_queue_iget_driver_data(job_queue_type *queue,
                                                    int job_index);
job_queue_node_type *job_queue_iget_job(job_queue_type *job_queue, int job_nr);

extern "C" char *job_queue_get_ok_file(const job_queue_type *queue);
extern "C" PY_USED char *job_queue_get_exit_file(const job_queue_type *queue);
extern "C" PY_USED char *job_queue_get_status_file(const job_queue_type *queue);
extern "C" PY_USED int job_queue_add_job_node(job_queue_type *queue,
                                              job_queue_node_type *node);

UTIL_SAFE_CAST_HEADER(job_queue);

#endif
