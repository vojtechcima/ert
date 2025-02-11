.. _ert_kw_full_doc:

List of Keywords
====================

For your convenience, the description of the keywords in the ERT configuration file
are divided into the following groups:

* Basic required keywords not related to parametrization. I.e. keywords giving
  the data, grid, schedule and observation file, defining how to run simulations
  and how to store results. These keywords are described in :ref:`Basic required
  keywords.<basic_required_keywords>`
* Basic optional keywords not related to parametrization. These keywords are
  described in :ref:`Basic optional keywords <basic_optional_keywords>`.
* Keywords related to parametrization of the ECLIPSE model. These keywords are
  described in :ref:`Parametrization keywords<parameterization_keywords>`.
* Advanced keywords not related to parametrization. These keywords are described
  in :ref:`Advanced optional keywords<advanced_optional_keywords>`.


List of keywords
----------------

=====================================================================   ======================================  ==============================  ==============================================================================================================================================
Keyword name                                                            Required                                Default value                   Purpose
=====================================================================   ======================================  ==============================  ==============================================================================================================================================
:ref:`ANALYSIS_COPY <analysis_copy>`                                    NO                                                                      Create new instance of analysis module
:ref:`ANALYSIS_SET_VAR <analysis_set_var>`                              NO                                                                      Set analysis module internal state variable
:ref:`ANALYSIS_SELECT <analysis_select>`                                NO                                      STD_ENKF                        Select analysis module to use in update
:ref:`CASE_TABLE <case_table>`                                          NO                                                                      Deprecated
:ref:`DATA_FILE <data_file>`                                            NO                                                                      Provide an ECLIPSE data file for the problem
:ref:`DATA_KW <data_kw>`                                                NO                                                                      Replace strings in ECLIPSE .DATA files
:ref:`DEFINE <define>`                                                  NO                                                                      Define keywords with config scope
:ref:`DELETE_RUNPATH <delete_runpath>`                                  NO                                                                      Explicitly tell ERT to delete the runpath when a job is complete
:ref:`ECLBASE <eclbase>`                                                YES\*                                                                   Define a name for the ECLIPSE simulations. \*Either JOBNAME or ECLBASE must be specified
:ref:`END_DATE <end_date>`                                              NO                                                                      You can tell ERT how long the simulations should be - for error check
:ref:`ENKF_ALPHA <enkf_alpha>`                                          NO                                      3.0                             Parameter controlling outlier behaviour in EnKF algorithm
:ref:`ENKF_FORCE_NCOMP <enkf_force_ncomp>`                              NO                                      0                               Indicate if ERT should force a specific number of principal components
:ref:`ENKF_NCOMP <enkf_ncomp>`                                          NO                                                                      Number of PC to use when forcing a fixed number; used in combination with kw ENKF_FORCE_NCOMP
:ref:`ENKF_RERUN <enkf_rerun>`                                          NO                                      FALSE                           Should the simulations be restarted from time zero after each update?
:ref:`ENKF_TRUNCATION <enkf_truncation>`                                NO                                      0.99                            Cutoff used on singular value spectrum
:ref:`ENSPATH <enspath>`                                                NO                                      storage                         Folder used for storage of simulation results
:ref:`FIELD <field>`                                                    NO                                                                      Adds grid parameters
:ref:`FORWARD_MODEL <forward_model>`                                    NO                                                                      Add the running of a job to the simulation forward model
:ref:`GEN_DATA <gen_data>`                                              NO                                                                      Specify a general type of data created/updated by the forward model
:ref:`GEN_KW <gen_kw>`                                                  NO                                                                      Add a scalar parameter
:ref:`GEN_KW_TAG_FORMAT <gen_kw_tag_format>`                            NO                                      <%s>                            Format used to add keys in the GEN_KW template files
:ref:`GEN_PARAM <gen_param>`                                            NO                                                                      Add a general parameter
:ref:`GRID <grid>`                                                      NO                                                                      Provide an ECLIPSE grid for the reservoir model
:ref:`HISTORY_SOURCE <history_source>`                                  NO                                      REFCASE_HISTORY                 Source used for historical values
:ref:`HOOK_WORKFLOW <hook_workflow>`                                    NO                                                                      Install a workflow to be run automatically
:ref:`INSTALL_JOB <install_job>`                                        NO                                                                      Install a job for use in a forward model
:ref:`ITER_CASE <iter_Case>`                                            NO                                      IES%d                           Case name format - iterated ensemble smoother
:ref:`ITER_COUNT <iter_count>`                                          NO                                      4                               Number of iterations - iterated ensemble smoother
:ref:`ITER_RETRY_COUNT <iter_retry_count>`                              NO                                      4                               Number of retries for a iteration - iterated ensemble smoother
:ref:`JOBNAME <jobname>`                                                YES\*                                                                   Name used for simulation files. \*Either JOBNAME or ECLBASE must be specified
:ref:`JOB_SCRIPT <job_script>`                                          NO                                                                      Python script managing the forward model
:ref:`LOAD_WORKFLOW <load_workflow>`                                    NO                                                                      Load a workflow into ERT
:ref:`LOAD_WORKFLOW_JOB <load_workflow_job>`                            NO                                                                      Load a workflow job into ERT
:ref:`LICENSE_PATH <license_path>`                                      NO                                                                      A path where ert-licenses to e.g. RMS are stored
:ref:`LOG_FILE <log_file>`                                              NO                                      -                               Ignored
:ref:`LOG_LEVEL <log_level>`                                            NO                                      -                               Ignored
:ref:`MAX_RESAMPLE <max_resample>`                                      NO                                      1                               How many times should ERT resample & retry a simulation
:ref:`MAX_RUNTIME <max_runtime>`                                        NO                                      0                               Set the maximum runtime in seconds for a realization
:ref:`MAX_SUBMIT <max_submit>`                                          NO                                      2                               How many times should the queue system retry a simulation
:ref:`MIN_REALIZATIONS <min_realizations>`                              NO                                      0                               Set the number of minimum reservoir realizations to run before long running realizations are stopped. Keyword STOP_LONG_RUNNING must be set to TRUE when MIN_REALIZATIONS are set
:ref:`NUM_CPU <num_cpu>`                                                YES                                                                     Set the number of CPUs. Intepretation varies depending on context
:ref:`NUM_REALIZATIONS <num_realizations>`                              YES                                                                     Set the number of reservoir realizations to use
:ref:`OBS_CONFIG <obs_config>`                                          NO                                                                      File specifying observations with uncertainties
:ref:`QUEUE_OPTION <queue_option>`                                      NO                                                                      Set options for an ERT queue system
:ref:`QUEUE_SYSTEM <queue_system>`                                      NO                                                                      System used for running simulation jobs
:ref:`REFCASE <refcase>`                                                NO                                                                      Reference case used for observations and plotting (See HISTORY_SOURCE and SUMMARY)
:ref:`REFCASE_LIST <refcase_list>`                                      NO                                                                      Full path to Eclipse .DATA files containing completed runs (which you can add to plots)
:ref:`RERUN_START  <rerun_start>`                                       NO                                      0                               Deprecated
:ref:`RESULT_PATH  <result_path>`                                       NO                                      results/step_%d                 Define where ERT should store results
:ref:`RFTPATH <rftpath>`                                                NO                                      rft                             Path to where the rft well observations are stored
:ref:`RUNPATH <runpath>`                                                NO                                      simulations/realization%d       Directory to run simulations
:ref:`RUNPATH_FILE <runpath_file>`                                      NO                                      .ert_runpath_list               Name of file with path for all forward models that ERT has run. To be used by user defined scripts to find the realizations
:ref:`RUN_TEMPLATE <run_template>`                                      NO                                                                      Install arbitrary files in the runpath directory
:ref:`SCHEDULE_PREDICTION_FILE <schedule_prediction_file>`              NO                                                                      Schedule prediction file
:ref:`SETENV <setenv>`                                                  NO                                                                      You can modify the UNIX environment with SETENV calls
:ref:`SIMULATION_JOB <simulation_job>`                                  NO                                                                      Experimental alternative to FORWARD_MODEL
:ref:`SINGLE_NODE_UPDATE <single_node_update>`                          NO                                      FALSE                           Splits the dataset into individual parameters
:ref:`STOP_LONG_RUNNING <stop_long_running>`                            NO                                      FALSE                           Stop long running realizations after minimum number of realizations (MIN_REALIZATIONS) have run
:ref:`SUMMARY  <summary>`                                               NO                                                                      Add summary variables for internalization
:ref:`SURFACE <surface>`                                                NO                                                                      Surface parameter read from RMS IRAP file
:ref:`TIME_MAP  <time_map>`                                             NO                                                                      Ability to manually enter a list of dates to establish report step <-> dates mapping
:ref:`UMASK <umask>`                                                    NO                                                                      DEPRECATED: Control the permissions on files created by ERT
:ref:`UPDATE_LOG_PATH  <update_log_path>`                               NO                                      update_log                      Summary of the update steps are stored in this directory
:ref:`UPDATE_PATH  <update_path>`                                       NO                                                                      Modify a UNIX path variable like LD_LIBRARY_PATH
:ref:`WORKFLOW_JOB_DIRECTORY  <workflow_job_directory>`                 NO                                                                      Directory containing workflow jobs
=====================================================================   ======================================  ==============================  ==============================================================================================================================================



Basic required keywords
-----------------------
.. _basic_required_keywords:

These keywords must be set to make ERT function properly.

.. _data_file:
.. topic:: DATA_FILE

        Name of the template ECLIPSE data file used to control the simulations.
        A modified realization specific version of this file will be prepared by ERT,
        named according to :ref:`ECLBASE <ECLBASE>` and copied to the runpath
        folder.


        *Example:*

        ::

                -- Load the data file called ECLIPSE.DATA
                DATA_FILE ECLIPSE.DATA

        Necessary preparations to this file include:

        1. Insert ``INCLUDE`` statements to include the various uncertainty
           parameters in use at the right place in the datafile.

        2. Make sure that the include files used in the datafiles can be
           correctly resolved from the runpath location.

        3. See the ``DATA_KW`` keyword which can be used to utilize more template
           functionality in the eclipse datafile.



.. _eclbase:
.. topic:: ECLBASE

        The ECLBASE keyword sets the basename for the ECLIPSE simulations which will
        be generated by ERT. It can (and should, for your convenience) contain a %d
        specifier, which will be replaced with the realization numbers when running
        ECLIPSE. Note that due to limitations in ECLIPSE, the ECLBASE string must be
        in strictly upper or lower case.

        *Example:*

        ::

                -- Use eclipse/model/MY_VERY_OWN_OIL_FIELD-0 etc. as basename.
                -- When ECLIPSE is running, the %d will be, replaced with
                -- realization number, and directories ''eclipse/model''
                -- will be generated by ERT if they do not already exist, giving:
                --
                -- eclipse/model/MY_VERY_OWN_OIL_FIELD-0
                -- eclipse/model/MY_VERY_OWN_OIL_FIELD-1
                -- eclipse/model/MY_VERY_OWN_OIL_FIELD-2
                -- ...
                -- and so on.

                ECLBASE eclipse/model/MY_VERY_OWN_OIL_FIELD-%d

        **Note:** JOBNAME can be used as an alternative to ECLBASE.

.. _jobname:
.. topic::  JOBNAME

        As an alternative to the ECLBASE keyword you can use the JOBNAME keyword; in
        particular in cases where your forward model does not include ECLIPSE at all
        that makes more sense. If JOBNAME is used instead of ECLBASE the same rules of
        no-mixed-case apply.

.. _grid:
.. topic:: GRID

        This is the name of an existing GRID/EGRID file for your ECLIPSE model. If you
        had to create a new grid file when preparing your ECLIPSE reservoir model for
        use with ERT, this should point to the new .EGRID file. The main use of the
        grid is to map out active and inactive cells when using FIELD data and define
	the dimension of the property parameter files in the FIELD keyword. If you do
        not use FIELD data you do not need the GRID keyword. The grid argument will
        only be used by the main ERT application and not passed down to the forward
        model in any way.

	A new way of handling property values for the FIELD keyword is to use a
        help grid called ERTBOX grid. The GRID keyword should in this case specify
        the ERTBOX filename (which is in EGRID format). The ERTBOX grid 
        is a grid with the same spatial location and rotation (x,y location) as the 
	modelling grid, but it is a regular grid in a rectangular box. The dimensions 
	of the ERTBOX grid laterally is the same as the modelling grid, but the number 
	of layers is only large enough to store the properties for one zone, not the 
	whole modelling grid.
	
	The number of layers must at least be as large as the number of layers 
        in the zone in the modelling grid with most layers. The properties used in
	the FIELD keyword have the dimension of the ERTBOX grid and represents 
	properties of one zone from the modelling grid. Each grid cell in the modelling 
	grid for a given zone corresponds to one unique grid cell 
	in the ERTBOX grid. Inactive grid cells in the modelling grid also corresponds 
	to grid cells in the ERTBOX grid. There may exists layers of grid cells in the 
	ERTBOX grid that does not corresponds to grid cells in the modelling grid. 
	It is recommended to let all grid cells in the ERTBOX grid be active and have
	realistic values and not a 'missing code'. For cases where the modelling grid 
	is kept fixed for all realisations, this is not important, but for cases where 
	the number of layers for the zones in the modelling grid may vary from 
	realisation to realisation, this approach is more robust. It avoids mixing real 
	physical values from one realisation with missing code value from another 
	realization when calculating updated ensemble vectors.
	 

        *Example:*

        ::

                -- Load the .EGRID file called MY_GRID.EGRID
                GRID MY_GRID.EGRID


.. _num_realizations:
.. topic:: NUM_REALIZATIONS

        This is just the size of the ensemble, i.e. the number of realizations/members
        in the ensemble.

        *Example:*

        ::

                -- Use 200 realizations/members
                NUM_REALIZATIONS 200

.. _num_cpu:
.. topic:: NUM_CPU

    Equates to the ``-n`` argument in the context of LSF. For TORQUE, it is
    simply a upper bound for the product of nodes and CPUs per node.

    *Example:*

    ::

        NUM_CPU 2


Basic optional keywords
-----------------------
.. _basic_optional_keywords:

These keywords are optional. However, they serve many useful purposes, and it is
recommended that you read through this section to get a thorough idea of what's
possible to do with ERT.

.. _data_kw:
.. topic:: DATA_KW

        The keyword DATA_KW can be used for inserting strings into placeholders in the
        ECLIPSE data file. For instance, it can be used to insert include paths.

        *Example:*

        ::

                -- Define the alias MY_PATH using DATA_KW. Any instances of <MY_PATH> (yes, with brackets)
                -- in the ECLIPSE data file will now be replaced with /mnt/my_own_disk/my_reservoir_model
                -- when running the ECLIPSE jobs.
                DATA_KW  MY_PATH  /mnt/my_own_disk/my_reservoir_model

        The DATA_KW keyword is of course optional. Note also that ERT has some
        built in magic strings.


.. _license_path:
.. topic:: LICENSE_PATH

    A path where ert-licenses to e.g. RMS are stored.


.. _random_seed:
.. topic:: RANDOM_SEED

        Set specific seed for reproducibility.


.. _log_file:
.. topic:: LOG_FILE

        Ignored. Was used to specify log output file.


.. _log_level:
.. topic:: LOG_LEVEL

        Ignored. Was used to specify log level to output. Today this is
        controlled via Python's logging module.

.. _delete_runpath:
.. topic:: DELETE_RUNPATH

        When the ERT application is running it creates directories for
        the forward model simulations, one for each realization. When
        the simulations are done, ERT will load the results into the
        internal database. By default the realization folders will be
        left intact after ERT has loaded the results, but using the
        keyword DELETE_RUNPATH you can request to have (some of) the
        directories deleted after results have been loaded.

        *Example A:*

        ::

                -- Delete simulation directories 0 to 99
                DELETE_RUNPATH 0-99

        *Example B:*

        ::

                -- Delete simulation directories 0 to 10 as well as 12, 15 and 20.
                DELETE_RUNPATH 0 - 10, 12, 15, 20

        The DELETE_RUNPATH keyword is optional.


.. _rerun_start:
.. topic:: RERUN_START

        `RERUN_START` is deprecated.


.. _end_date:
.. topic:: END_DATE

        When running a set of models from beginning to end ERT does
        not know in advance how long the simulation is supposed to be,
        it is therefore impossible beforehand to determine which
        restart file number should be used as target file, and the
        procedure used for Smoother runs can not be used to verify that an
        ECLIPSE simulation has run to the end.

        By using the END_DATE keyword you can tell ERT that the
        simulation should go at least up to the date given by
        END_DATE, otherwise they will be regarded as failed. The
        END_DATE does not need to correspond exactly to the end date
        of the simulation, it must just be set so that all simulations
        which go to or beyond END_DATE are regarded as successful.

        *Example:*

        ::

                END_DATE  2010-05-10

        With this END_DATE setting all simulations which have gone to
        at least May 10th 2010 are OK. Date format YYYY-MM-DD is required.
        Other time formats, like DD/MM/YYYY or DD.MM.YYYY, are deprecated
        and its support will be removed in a future release.


.. _enspath:
.. topic:: ENSPATH

        The ENSPATH should give the name of a folder that will be used
        for storage by ERT. Note that the contents of
        this folder is not intended for human inspection. By default,
        ENSPATH is set to "storage".

        *Example:*

        ::

                -- Use internal storage in /mnt/my_big_enkf_disk
                ENSPATH /mnt/my_big_enkf_disk

        The ENSPATH keyword is optional.


.. _history_source:
.. topic:: HISTORY_SOURCE

        In the observation configuration file you can enter
        observations with the keyword HISTORY_OBSERVATION; this means
        that ERT will extract observed values from the model
        historical summary vectors of the reference case. What source
        to use for the  historical values can be controlled with the
        HISTORY_SOURCE keyword. The different possible values for the
        HISTORY_SOURCE keyword are:


        REFCASE_HISTORY
                This is the default value for HISTORY_SOURCE,
                ERT will fetch the historical values from the *xxxH*
                keywords in the refcase summary, e.g. observations of
                WGOR:OP_1 is based the WGORH:OP_1 vector from the
                refcase summary.

        REFCASE_SIMULATED
                In this case the historical values are based on the
                simulated values from the refcase, this is mostly relevant when a you want
                compare with another case which serves as 'the truth'.

        When setting HISTORY_SOURCE to either REFCASE_SIMULATED or REFCASE_HISTORY you
        must also set the REFCASE variable to point to the ECLIPSE data file in an
        existing reference case (should be created with the same schedule file as you
        are using now).

        *Example:*

        ::

                -- Use historic data from reference case
                HISTORY_SOURCE  REFCASE_HISTORY
                REFCASE         /somefolder/ECLIPSE.DATA

        The HISTORY_SOURCE keyword is optional.

.. _refcase:
.. topic:: REFCASE

        The REFCASE key is used to provide ERT an existing ECLIPSE simulation
        from which it can read various information at startup. The intention is
        to ease the configuration needs for the user. Functionality provided with the
        refcase:

        * summary keys are read from the refcase to enable use of wildcards.

        * extract observed values from the refcase using the
          :ref:`HISTORY_OBSERVATION <HISTORY_OBSERVATION>` and
          :ref:`HISTORY_SOURCE <HISTORY_SOURCE>` keys.


        The REFCASE keyword should point to an existing ECLIPSE simulation;
        ert will then look up and load the corresponding summary results.

        *Example:*

        ::

                -- The REFCASE keyword points to the datafile of an existing ECLIPSE simulation.
                REFCASE /path/to/somewhere/SIM_01_BASE.DATA


        Please note that the refcase is a common source of frustration for ERT users. The
        reason is that ERT indexes summary observation values according to the report steping
        of the reservoir simulator. This indexing is extracted by the report steps of the
        refcase when staring ERT. Later on when extracting results from forecasted
        simulations ERT requires that the indexing is according to that of the refcase. During a
        project it is very easy to introduce inconsistencies between the indexing in the
        refcase, the forward model and the internalized summary results in storage.
        Unfortunately, ERT does not handle this well and leaves the user with cryptical
        error messages.

        For the time being, it is hence necessary to keep the reporting as defined in the
        SCHEDULE section of the refcase and the model used in the project identical.

        The HISTORY_SOURCE keyword is optional. But if you are to perform model updating,
        indexing of summary observations need to be defined. This is either done by the
        REFCASE or the :ref:`TIME_MAP <TIME_MAP>` keyord, and the former is recommended.


.. _install_job:
.. topic:: INSTALL_JOB

        The INSTALL_JOB keyword is used to instruct ERT how to run
        external applications and scripts, i.e. defining a job. After a job has been
        defined with INSTALL_JOB, it can be used with the FORWARD_MODEL keyword. For
        example, if you have a script which generates relative permeability curves
        from a set of parameters, it can be added as a job, allowing you to do history
        matching and sensitivity analysis on the parameters defining the relative
        permeability curves.

        The INSTALL_JOB keyword takes two arguments, a job name and the name of a
        configuration file for that particular job.

        *Example:*

        ::

                -- Define a Lomeland relative permeabilty job.
                -- The file jobs/lomeland.txt contains a detailed
                -- specification of the job.
                INSTALL_JOB LOMELAND jobs/lomeland.txt

        The configuration file used to specify an external job is easy to use and very
        flexible. It is documented in Customizing the simulation workflow in ERT.

        The INSTALL_JOB keyword is optional.

.. _obs_config:
.. topic:: OBS_CONFIG

        The OBS_CONFIG key should point to a file defining observations and associated
        uncertainties. The file should be in plain text and formatted according to the
        guidelines given in :ref:`Creating an observation file for use with ERT<Configuring_observations_for_ERT>`.

	    If you include HISTORY_OBSERVATION in the observation file, you must
	    provide a reference Eclipse case through the REFCASE keyword.

        *Example:*

        ::

                -- Use the observations in my_observations.txt
                OBS_CONFIG my_observations.txt

        The OBS_CONFIG keyword is optional, but for your own convenience, it is
        strongly recommended to provide an observation file.

.. _result_path:
.. topic:: RESULT_PATH

        ERT will print some simple tabulated results at each report
        step. The RESULT_PATH keyword should point to a folder where the tabulated
        results are to be written. It can contain a %d specifier, which will be
        replaced with the report step. The default value for RESULT_PATH is
        "results/step_%d".

        *Example:*

        ::

                -- Changing RESULT_PATH
                RESULT_PATH my_nice_results/step-%d

        The RESULT_PATH keyword is optional.

.. _runpath:
.. topic:: RUNPATH

        The RUNPATH keyword should give the name of the folders where the ECLIPSE
        simulations are executed. It should contain at least one %d specifier, which
        will be replaced by the realization number when ERT creates the folders.
        Optionally, it can contain one more %d specifier, which will be replaced by
        the iteration number.

        By default, RUNPATH is set to "simulations/realization-%d".

        *Example A:*

        ::

                -- Giving a RUNPATH with just one %d specifer.
                RUNPATH /mnt/my_scratch_disk/realization-%d

        *Example B:*

        ::

                -- Giving a RUNPATH with two %d specifers.
                RUNPATH /mnt/my_scratch_disk/realization-%d/iteration-%d

        The RUNPATH keyword is optional.


.. _runpath_file:
.. topic:: RUNPATH_FILE

        When running workflows based on external scripts it is necessary to 'tell' the
        external script in some way or another were all the realisations are located in
        the filesystem. Since the number of realisations can be quite high this will
        easily overflow the commandline buffer; the solution which is used is therefore
        to let ERT write a regular file which looks like this::

                0   /path/to/realization-0   CASE0   iter
                1   /path/to/realization-1   CASE1   iter
                ...
                N   /path/to/realization-N   CASEN   iter

        The path to this file can then be passed to the scripts using the
        magic string <RUNPATH_FILE>. The RUNPATH_FILE will by default be
        stored as .ert_runpath_list in the same directory as the configuration
        file, but you can set it to something else with the RUNPATH_FILE key.


.. _run_template:
.. topic:: RUN_TEMPLATE

        Install arbitrary files in the runpath directory.


Keywords controlling the simulations
------------------------------------
.. _keywords_controlling_the_simulations:

.. _min_realizations:
.. topic:: MIN_REALIZATIONS

        MIN_REALIZATIONS is the minimum number of realizations that
        must have succeeded for the simulation to be regarded as a
        success.

        MIN_REALIZATIONS can also be used in combination with
        STOP_LONG_RUNNING, see the documentation for STOP_LONG_RUNNING
        for a description of this.

        *Example:*

        ::

                MIN_REALIZATIONS  20

        The MIN_REALIZATIONS key can also be set as a percentage of
        NUM_REALIZATIONS

        ::

                MIN_REALIZATIONS  10%

        The MIN_REALIZATIONS key is optional, but if it has not been
        set *all* the realisations must succeed.

        Please note that MIN_REALIZATIONS = 0 means all simulations must succeed
        (this happens to be the default value). Note MIN_REALIZATIONS is rounded up
        e.g. 2% of 20 realizations is rounded to 1.


.. _stop_long_running:
.. topic:: STOP_LONG_RUNNING

        The STOP_LONG_RUNNING key is used in combination with the MIN_REALIZATIONS key
        to control the runtime of simulations. When STOP_LONG_RUNNING is set to TRUE,
        MIN_REALIZATIONS is the minimum number of realizations run before the
        simulation is stopped. After MIN_REALIZATIONS have succeded successfully, the
        realizatons left are allowed to run for 25% of the average runtime for
        successful realizations, and then killed.

        *Example:*

        ::

                -- Stop long running realizations after 20 realizations have succeeded
                MIN_REALIZATIONS  20
                STOP_LONG_RUNNING TRUE

        The STOP_LONG_RUNNING key is optional. The MIN_REALIZATIONS key must be set
        when STOP_LONG_RUNNING is set to TRUE.


.. _max_runtime:
.. topic:: MAX_RUNTIME

        The MAX_RUNTIME keyword is used to control the runtime of simulations. When
        MAX_RUNTIME is set, a job is only allowed to run for MAX_RUNTIME, given in
        seconds. A value of 0 means unlimited runtime.

        *Example:*

        ::

                -- Let each realizations run for 50 seconds
                MAX_RUNTIME 50

        The MAX_RUNTIME key is optional.


Parameterization keywords
-------------------------
.. _parameterization_keywords:

The keywords in this section are used to define a parametrization of the ECLIPSE
model. I.e. defining which parameters to change in a sensitivity analysis
and/or history matching project.


.. _case_table:
.. topic:: CASE_TABLE

        `CASE_TABLE` is deprecated.


.. _field:
.. topic:: FIELD

        The FIELD keyword is used to parametrize quantities which have extent over the
        full grid. Both dynamic properties like pressure, and static properties like
        porosity, are implemented in terms of FIELD objects. When adding fields in the
        config file the syntax is a bit different for dynamic fields (typically
        solution data from ECLIPSE) and parameter fields like permeability and
        porosity or Gaussian Random Fields used by APS.

        **Dynamic fields**

        To add a dynamic field the entry in the configuration file looks like this:

        ::

                FIELD   <ID>   DYNAMIC  MIN:X  MAX:Y

        In this case ID is not an arbitrary string; it must coincide with the keyword
        name found in the ECLIPSE restart file, e.g. PRESSURE. Optionally, you can add
        a minimum and/or a maximum value with MIN:X and MAX:Y.

        *Example A:*

        ::

                -- Adding pressure field (unbounded)
                FIELD PRESSURE DYNAMIC

        *Example B:*

        ::

                -- Adding a bounded water saturation field
                FIELD SWAT DYNAMIC MIN:0.2 MAX:0.95

        **Parameter fields**

        A parameter field (e.g. porosity or permeability or Gaussian Random Fields from APS) is defined as follows:

        ::

                FIELD  ID PARAMETER   <ECLIPSE_FILE>  INIT_FILES:/path/%d  MIN:X MAX:Y OUTPUT_TRANSFORM:FUNC INIT_TRANSFORM:FUNC  FORWARD_INIT:True

	Here ID must be the same as the name of the parameter in the INIT_FILES.
        ECLIPSE_FILE is the name of the file ERT will export this field to when 
        running simulations. Note that there should be an IMPORT statement in 
        the ECLIPSE data file corresponding to the name given with ECLIPSE_FILE in case
        the field parameter is a field used in ECLIPSE data file like perm or poro. 
        INIT_FILES is a filename (with an embedded %d if FORWARD_INIT is set to False)
        to load the initial field from. Can be RMS ROFF format, ECLIPSE restart format
        or ECLIPSE GRDECL format.

        FORWARD_INIT:True means that the files specified in the INIT_FILES are expected 
        to be created by a forward model, and does not need any embedded %d.
	FORWARD_INIT:False means that the files must have been created before running
        ERT and need an embedded %d.

        The input arguments MIN, MAX, INIT_TRANSFORM and OUTPUT_TRANSFORM are all
        optional. MIN and MAX are as for dynamic fields.

        For Assisted history matching, the variables in ERT should be normally
        distributed internally - the purpose of the transformations is to enable
        working with normally distributed variables internally in ERT. Thus, the
        optional arguments INIT_TRANSFORM:FUNC and OUTPUT_TRANSFORM:FUNC are used to
        transform the user input of parameter distribution. INIT_TRANSFORM:FUNC is a
        function which will be applied when they are loaded to ERT.
        OUTPUT_TRANSFORM:FUNC is a function which will be applied to the field when it
        is exported from ERT, and FUNC is the name of a transformation function to be
        applied. The avaialble functions are listed below:

        | "POW10"                       : This function will raise x to the power of 10: :math:`y = 10^x`
        | "TRUNC_POW10" : This function will raise x to the power of 10 - and truncate lower values at 0.001.
        | "LOG"                 : This function will take the NATURAL logarithm of :math:`x: y = \ln{x}`
        | "LN"                  : This function will take the NATURAL logarithm of :math:`x: y = \ln{x}`
        | "LOG10"                       : This function will take the log10 logarithm of :math:`x: y = \log_{10}{x}`
        | "EXP"                 : This function will calculate :math:`y = e^x`.
        | "LN0"                 : This function will calculate :math:`y = \ln{x} + 0.000001`
        | "EXP0"                        : This function will calculate :math:`y = e^x - 0.000001`

        For example, the most common scenario is that underlying log-normal
        distributed permeability in RMS are transformed to normally distributted in
        ERT, then you do:

        INIT_TRANSFORM:LOG To ensure that the variables which were initially
        log-normal distributed are transformed to normal distribution when they are
        loaded into ERT.

        OUTPUT_TRANSFORM:EXP To ensure that the variables are reexponentiated to be
        log-normal distributed before going out to Eclipse.

        If users specify the wrong function name (e.g INIT_TRANSFORM:I_DONT_KNOW), ERT
        will stop and print all the valid function names.

        Regarding format of ECLIPSE_FILE: The default format for the parameter fields
        is binary format of the same type as used in the ECLIPSE restart files. This
        requires that the ECLIPSE datafile contains an IMPORT statement. The advantage
        with using a binary format is that the files are smaller, and reading/writing
        is faster than for plain text files. If you give the ECLIPSE_FILE with the
        extension .grdecl (arbitrary case), ERT will produce ordinary .grdecl files,
        which are loaded with an INCLUDE statement. This is probably what most users
        are used to beforehand - but we recommend the IMPORT form. When using RMS APS 
        plugin to create Gaussian Random Fields, the recommended file format is ROFF binary.

        *Example C:*

        ::

                -- Use Gaussian Random Fields from APS for zone Volon.
		-- RMS APSGUI plugin will create the files specified in INIT_FILES.
		-- ERT will read the INIT_FILES in iteration 0 and write the updated GRF
		-- fields to the files following the keyword PARAMETER after updating.
		-- NOTE: The ERTBOX grid is a container for GRF values (or perm or poro values) and
		-- is used to define the dimension of the fields. It is NOT the modelling grid 
		-- used in RMS or the simulation grid used by ECLIPSE. 
                FIELD  aps_Volon_GRF1  PARAMETER  aps_Volon_GRF1.roff  INIT_FILES:rms/output/aps/aps_Volon_GRF1.roff   MIN:-5.5  MAX:5.5  FORWARD_INIT:True
                FIELD  aps_Volon_GRF2  PARAMETER  aps_Volon_GRF2.roff  INIT_FILES:rms/output/aps/aps_Volon_GRF2.roff   MIN:-5.5  MAX:5.5  FORWARD_INIT:True
                FIELD  aps_Volon_GRF3  PARAMETER  aps_Volon_GRF3.roff  INIT_FILES:rms/output/aps/aps_Volon_GRF3.roff   MIN:-5.5  MAX:5.5  FORWARD_INIT:True

        *Example D:*

        ::

                -- Use perm field for zone A
		-- The GRID keyword should refer to the ERTBOX grid defining the size of the field.
		-- Permeability must be sampled from the geomodel/simulation grid zone into the ERTBOX grid
		-- and exported to /some/path/filename. Note that the name of the property in the input file
		-- in INIT_FILES must be the same as the ID.
                FIELD  perm_zone_A   PARAMETER  perm_zone_A.roff  INIT_FILES:/some/path/perm_zone_A.roff     INIT_TRANSFORM:LOG  OUTPUT_TRANSFORM:EXP   MIN:-5.5  MAX:5.5  FORWARD_INIT:True




        **General fields**

        In addition to dynamic and parameter field there is also a general field,
        where you have fine grained control over input/output. Use of the general
        field type is only relevant for advanced features. The arguments for the
        general field type are as follows:

        ::

                FIELD   ID  GENERAL    FILE_GENERATED_BY_ERT  FILE_LOADED_BY_ERT    <OPTIONS>

        The OPTIONS argument is the same as for the parameter field.

.. _gen_data:
.. topic:: GEN_DATA

        The GEN_DATA keyword is used when estimating data types which ERT does not
        know anything about. GEN_DATA is very similar to GEN_PARAM, but GEN_DATA is
        used for data which are updated/created by the forward model like e.g. seismic
        data. In the main configuration file the input for a GEN_DATA instance is as
        follows:

        ::

                GEN_DATA  ID RESULT_FILE:yyy INPUT_FORMAT:xx  REPORT_STEPS:10,20  ECL_FILE:xxx  OUTPUT_FORMAT:xx  INIT_FILES:/path/files%d TEMPLATE:/template_file TEMPLATE_KEY:magic_string

        The GEN_DATA keyword has many options; in many cases you can leave many of
        them off. We therefore list the required and the optional options separately:

        **Required GEN_DATA options**

        * RESULT_FILE - This is the name of the file generated by the forward model and read by ERT. This filename _must_ have a %d as part of the name, that %d will be replaced by report step when loading.
        * INPUT_FORMAT - The format of the file written by the forward model (i.e. RESULT_FILE) and read by ERT, valid values are ASCII, BINARY_DOUBLE and BINARY_FLOAT.
        * REPORT_STEPS - A list of the report step(s) where you expect the forward model to create a result file. I.e. if the forward model should create a result file for report steps 50 and 100 this setting should be: REPORT_STEPS:50,100. If you have observations of this GEN_DATA data the RESTART setting of the corresponding GENERAL_OBSERVATION must match one of the values given by REPORT_STEPS.

        **Optional GEN_DATA options**

        * ECL_FILE - This is the name of file written by ERT to be read by the forward model.
        * OUTPUT_FORMAT - The format of the files written by ERT and read by the forward model, valid values are ASCII, BINARY_DOUBLE, BINARY_FLOAT and ASCII_TEMPLATE. If you use ASCII_TEMPLATE you must also supply values for TEMPLATE and TEMPLATE_KEY.
        * INIT_FILES - Format string with '%d' of files to load the initial data from.

        *Example:*

        ::

                GEN_DATA 4DWOC  INPUT_FORMAT:ASCII   RESULT_FILE:SimulatedWOC%d.txt   REPORT_STEPS:10,100

        Here we introduce a GEN_DATA instance with name 4DWOC. When the forward model
        has run it should create two files with name SimulatedWOC10.txt and
        SimulatedWOC100.txt. The result files are in ASCII format, ERT will look for
        these files and load the content. The files should be pure numbers - without
        any header.

        **Observe that the GEN_DATA RESULT_FILE setting must have a %d format specifier, that will be replaced with the report step.**


.. _gen_kw:
.. topic:: GEN_KW

        The GEN_KW (abbreviation of general keyword) parameter is based on a template
        file and substitution. In the main config file a GEN_KW instance is defined as
        follows:

        ::

                GEN_KW  ID  my_template.txt  my_eclipse_include.txt  my_priors.txt

        Here ID is an (arbitrary) unique string, my_template.txt is the name of a
        template file, my_eclipse_include.txt is the name of the file which is made
        for each member based on my_template.txt and my_priors.txt is a file
        containing a list of parametrized keywords and a prior distribution for each.
        Note that you must manually edit the ECLIPSE data file so that
        my_eclipse_include.txt is included.

        Let us consider an example where the GEN_KW parameter type is used to estimate
        pore volume multipliers. We would then declare a GEN_KW instance in the main
        ERT configuration file:

        Naming a `GEN_KW` parameter `PRED` will prevent the parameter from being
        added to a update_step dataset.

        ::

                GEN_KW PAR_MULTPV multpv_template.txt multpv.txt multpv_priors.txt

        In the GRID or EDIT section of the ECLIPSE data file, we would insert the
        following include statement:

        ::

                INCLUDE
                 'multpv.txt' /

        The template file multpv_template.txt would contain some parametrized ECLIPSE
        statements:

        ::

                BOX
                 1 10 1 30 13 13 /
                MULTPV
                 300*<MULTPV_BOX1> /
                ENDBOX

                BOX
                 1 10 1 30 14 14 /
                MULTPV
                 300*<MULTPV_BOX2> /
                ENDBOX

        Here, <MULTPV_BOX1> and <MULTPV_BOX2> will act as magic strings. Note that the
        '<' '>' must be present around the magic strings. In this case, the parameter
        configuration file multpv_priors.txt could look like this:

        ::

                MULTPV_BOX2 UNIFORM 0.98 1.03
                MULTPV_BOX1 UNIFORM 0.85 1.00

        In general, the first keyword on each line in the parameter configuration file
        defines a key, which when found in the template file enclosed in '<' and '>',
        is replaced with a value. The rest of the line defines a prior distribution
        for the key. See Prior distributions available in ERT for a list of available
        prior distributions.

        **Example: Using GEN_KW to estimate fault transmissibility multipliers**

        Previously ERT supported a datatype MULTFLT for estimating fault
        transmissibility multipliers. This has now been deprecated, as the
        functionality can be easily achieved with the help of GEN_KW. In the ERT
        config file:

        ::

                GEN_KW  MY-FAULTS   MULTFLT.tmpl   MULTFLT.INC   MULTFLT.txt

        Here MY-FAULTS is the (arbitrary) key assigned to the fault multiplers,
        MULTFLT.tmpl is the template file, which can look like this:

        ::

                MULTFLT
                 'FAULT1'   <FAULT1>  /
                 'FAULT2'   <FAULT2>  /
                /

        and finally the initial distribution of the parameters FAULT1 and FAULT2 are
        defined in the file MULTFLT.txt:

        ::

                FAULT1   LOGUNIF   0.00001   0.1
                FAULT2   UNIFORM   0.00      1.0


        Loading GEN_KW values from an external file

        The default use of the GEN_KW keyword is to let the ERT application sample
        random values for the elements in the GEN_KW instance, but it is also possible
        to tell ERT to load a precreated set of data files, this can for instance be
        used as a component in an experimental design based workflow. When using
        external files to initialize the GEN_KW instances you supply an extra keyword
        ``INIT_FILE:/path/to/priors/files%d`` which tells where the prior files are:

        ::

                GEN_KW  MY-FAULTS   MULTFLT.tmpl   MULTFLT.INC   MULTFLT.txt    INIT_FILES:priors/multflt/faults%d

        In the example above you must prepare files priors/multflt/faults0,
        priors/multflt/faults1, ... priors/multflt/faultsn which ERT will load when
        you initialize the case. The format of the GEN_KW input files can be of two
        varieties:

        1. The files can be plain ASCII text files with a list of numbers:

        ::

                1.25
                2.67

        The numbers will be assigned to parameters in the order found in the
        MULTFLT.txt file.

        2. Alternatively values and keywords can be interleaved as in:

        ::

                FAULT1 1.25
                FAULT2 2.56

        in this case the ordering can differ in the init files and the parameter file.

        The heritage of the ERT program is based on the EnKF algorithm, and the EnKF
        algorithm evolves around Gaussian variables - internally the GEN_KW variables
        are assumed to be samples from the N(0,1) distribution, and the distributions
        specified in the parameters file are based on transformations starting with a
        N(0,1) distributed variable. The slightly awkward consequence of this is that
        to let your sampled values pass through ERT unmodified you must configure the
        distribution NORMAL 0 1 in the parameter file; alternatively if you do not
        intend to update the GEN_KW variable you can use the distribution RAW.


.. _gen_param:
.. topic:: GEN_PARAM

        The GEN_PARAM parameter type is used to estimate parameters which do not
        really fit into any of the other categories. As an example, consider the
        following situation:

        Some external Software (e.g. Cohiba) makes a large vector of random numbers
        which will serve as input to the forward model. It is no requirement that the
        parameter set is large, but if it only consists of a few parameters the GEN_KW
        type will be easier to use. We want to update this parameter with ERT. In
        the main configuration file the input for a GEN_PARAM instance is as follows:

        ::

                GEN_PARAM  ID  ECLIPSE_FILE  INPUT_FORMAT:xx  OUTPUT_FORMAT:xx  INIT_FILES:/path/to/init/files%d (TEMPLATE:/template_file KEY:magic_string)

        here ID is the usual unique string identifying this instance and ECLIPSE_FILE
        is the name of the file which is written into the run directories. The three
        arguments GEN_PARAM, ID and ECLIPSE_FILE must be the three first arguments. In
        addition you must have three additional arguments, INPUT_FORMAT, OUTPUT_FORMAT
        and INIT_FILES. INPUT_FORMAT is the format of the files ERT should load to
        initialize, and OUTPUT_FORMAT is the format of the files ERT writes for the
        forward model. The valid values are:

        * ASCII - This is just text file with formatted numbers.
        * ASCII_TEMPLATE - A plain text file with formatted numbers, and an arbitrary
          header/footer.
        * BINARY_FLOAT - A vector of binary float numbers.
        * BINARY_DOUBLE - A vector of binary double numbers.

        Regarding the different formats - observe the following:

        #. Except the format ASCII_TEMPLATE the files contain no header information.
        #. The format ASCII_TEMPLATE can only be used as output format.
        #. If you use the output format ASCII_TEMPLATE you must also supply a
           TEMPLATE:X and KEY:Y option. See documentation of this below.
        #. For the binary formats files generated by Fortran can not be used - can
           easily be supported on request.

        **Regarding templates:** If you use OUTPUT_FORMAT:ASCII_TEMPLATE you must also
        supply the arguments TEMPLATE:/template/file and KEY:MaGiCKEY. The template
        file is an arbitrary existing text file, and KEY is a magic string found in
        this file. When ERT is running the magic string is replaced with parameter
        data when the ECLIPSE_FILE is written to the directory where the simulation
        is run from. Consider for example the following configuration:

        ::

                TEMPLATE:/some/file   KEY:Magic123

        The template file can look like this (only the Magic123 is special):

        ::

                Header line1
                Header line2
                ============
                Magic123
                ============
                Footer line1
                Footer line2

        When ERT is running the string Magic123 is replaced with parameter values,
        and the resulting file will look like this:

        ::

                Header line1
                Header line2
                ============
                1.6723
                5.9731
                4.8881
                .....
                ============
                Footer line1
                Footer line2


.. _gen_kw_tag_format:
.. topic:: GEN_KW_TAG_FORMAT

        Format used to add keys in the `GEN_KW` template files.


.. _surface:
.. topic:: SURFACE

        The SURFACE keyword can be used to work with surface from RMS in the irap
        format. The surface keyword is configured like this:

        ::

                SURFACE TOP   OUTPUT_FILE:surf.irap   INIT_FILES:Surfaces/surf%d.irap   BASE_SURFACE:Surfaces/surf0.irap

        The first argument, TOP in the example above, is the identifier you want to
        use for this surface in ERT. The OUTPUT_FILE key is the name of surface file
        which ERT will generate for you, INIT_FILES points to a list of files which
        are used to initialize, and BASE_SURFACE must point to one existing surface
        file. When loading the surfaces ERT will check that all the headers are
        compatible. An example of a surface IRAP file is:

        ::

                -996   511     50.000000     50.000000
                444229.9688   457179.9688  6809537.0000  6835037.0000
                260      -30.0000   444229.9688  6809537.0000
                0     0     0     0     0     0     0
                2735.7461    2734.8909    2736.9705    2737.4048    2736.2539    2737.0122
                2740.2644    2738.4014    2735.3770    2735.7327    2733.4944    2731.6448
                2731.5454    2731.4810    2730.4644    2730.5591    2729.8997    2726.2217
                2721.0996    2716.5913    2711.4338    2707.7791    2705.4504    2701.9187
                ....

        The surface data will typically be fed into other programs like Cohiba or RMS.
        The data can be updated using e.g. the Smoother.

        **Initializing from the FORWARD MODEL**

        All the parameter types like FIELD, GEN_KW, GEN_PARAM and SURFACE can be
        initialized from the forward model. To achieve this you just add the setting
        FORWARD_INIT:True to the configuration. When using forward init the
        initialization will work like this:

        #. The explicit initialization from the case menu, or when you start a
           simulation, will be ignored.
        #. When the FORWARD_MODEL is complete ERT will try to initialize the node
           based on files created by the forward model. If the init fails the job as a
           whole will fail.
        #. If a node has been initialized, it will not be initialized again if you run
           again. [Should be possible to force this ....]

        When using FORWARD_INIT:True ERT will consider the INIT_FILES setting to find
        which file to initialize from. If the INIT_FILES setting contains a relative
        filename, it will be interpreted relatively to the runpath directory. In the
        example below we assume that RMS has created a file petro.grdecl which
        contains both the PERMX and the PORO fields in grdecl format; we wish to
        initialize PERMX and PORO nodes from these files:

        ::

                FIELD   PORO  PARAMETER    poro.grdecl     INIT_FILES:petro.grdecl  FORWARD_INIT:True
                FIELD   PERMX PARAMETER    permx.grdecl    INIT_FILES:petro.grdecl  FORWARD_INIT:True

        Observe that forward model has created the file petro.grdecl and the nodes
        PORO and PERMX create the ECLIPSE input files poro.grdecl and permx.grdecl, to
        ensure that ECLIPSE finds the input files poro.grdecl and permx.grdecl the
        forward model should contain a job which will copy/convert petro.grdecl ->
        (poro.grdecl,permx.grdecl), this job should not overwrite existing versions of
        permx.grdecl and poro.grdecl. This extra hoops is not strictly needed in all
        cases, but strongly recommended to ensure that you have control over which
        data is used, and that everything is consistent in the case where the forward
        model is run again.


.. _summary:
.. topic:: SUMMARY

        The SUMMARY keyword is used to add variables from the ECLIPSE summary file to
        the parametrization. The keyword expects a string, which should have the
        format VAR:WGRNAME. Here, VAR should be a quantity, such as WOPR, WGOR, RPR or
        GWCT. Moreover, WGRNAME should refer to a well, group or region. If it is a
        field property, such as FOPT, WGRNAME need not be set to FIELD.

        *Example:*

        ::

                -- Using the SUMMARY keyword to add diagnostic variables
                SUMMARY WOPR:MY_WELL
                SUMMARY RPR:8
                SUMMARY F*          -- Use of wildcards requires that you have entered a REFCASE.

        The SUMMARY keyword has limited support for '*' wildcards, if your key
        contains one or more '*' characters all matching variables from the refcase
        are selected. Observe that if your summary key contains wildcards you must
        supply a refcase with the REFCASE key - otherwise it will fail hard.

        **Note:** Properties added using the SUMMARY keyword are only diagnostic. I.e. they have no effect on the sensitivity analysis or history match.


.. _keywords_controlling_the_es_algorithm:

Keywords controlling the ES algorithm
-------------------------------------


.. _enkf_alpha:
.. topic:: ENKF_ALPHA

        See the sub keyword :code:`ENKF_ALPHA` under the :code:`UPDATE_SETTINGS` keyword.

.. _enkf_bootstrap:
.. topic:: ENKF_BOOTSTRAP

        Boolean specifying if we want to resample the Kalman gain matrix in the update
        step. The purpose is to avoid that the ensemble covariance collapses. When
        this keyword is true each ensemble member will be updated based on a Kalman
        gain matrix estimated from a resampling with replacement of the full ensemble.

        In theory and in practice this has worked well when one uses a small number of
        ensemble members.


.. _enkf_force_ncomp:
.. topic:: ENKF_FORCE_NCOMP

        Bool specifying if we want to force the subspace dimension we want to use in
        the EnKF updating scheme (SVD-based) to a specific integer. This is an
        alternative to selecting the dimension using ENKF_TRUNCATION.

        *Example:*

        ::

                -- Setting the the subspace dimension to 2
                ENKF_FORCE_NCOMP     TRUE
                ENKF_NCOMP              2


.. _enkf_mode:
.. topic:: ENKF_MODE

        The ENKF_MODE keyword is used to select which EnKF algorithm to use. Use the
        value STANDARD for the original EnKF algorithm, or SQRT for the so-called
        square root scheme. The default value for ENKF_MODE is STANDARD.

        *Example A:*

        ::

                -- Using the square root update
                ENKF_MODE SQRT

        *Example B:*

        ::

                -- Using the standard update
                ENKF_MODE STANDARD

        The ENKF_MODE keyword is optional.


.. _enkf_ncomp:
.. topic:: ENKF_NCOMP

        Integer specifying the subspace dimension. Requires that ENKF_FORCE_NCOMP is
        TRUE.

.. _enkf_rerun:
.. topic:: ENKF_RERUN

        This is a boolean switch - TRUE or FALSE. Should the simulation start from
        time zero after each update.


.. _enkf_truncation:
.. topic:: ENKF_TRUNCATION

        Truncation factor for the SVD-based EnKF algorithm (see Evensen, 2007). In
        this algorithm, the forecasted data will be projected into a low dimensional
        subspace before assimilation. This can substantially improve on the results
        obtained with the EnKF, especially if the data ensemble matrix is highly
        collinear (Saetrom and Omre, 2010). The subspace dimension, p, is selected
        such that


        :math:`\frac{\sum_{i=1}^{p} s_i^2}{\sum_{i=1}^r s_i^2} \geq \mathrm{ENKF\_TRUNCATION}`

        where si is the ith singular value of the centered data ensemble matrix and r
        is the rank of this matrix. This criterion is similar to the explained
        variance criterion used in Principal Component Analysis (see e.g. Mardia et
        al. 1979).

        The default value of ENKF_TRUNCATION is 0.98. If ensemble collapse is a big
        problem, a smaller value should be used (e.g 0.90 or smaller). However, this
        does not guarantee that the problem of ensemble collapse will disappear. Note
        that setting the truncation factor to 1.00, will recover the Standard-EnKF
        algorithm if and only if the covariance matrix for the observation errors is
        proportional to the identity matrix.


.. _update_log_path:
.. topic:: UPDATE_LOG_PATH

        A summary of the data used for updates are stored in this directory.


.. _update_settings:
.. topic:: UPDATE_SETTINGS

        The :code:`UPDATE_SETTINGS` keyword is a *super-keyword* which can be used to
        control parameters which apply to the Ensemble Smoother update algorithm. The
        :code:`UPDATE_SETTINGS` currently supports the two subkeywords:

        ENKF_ALPHA Scaling factor used when detecting outliers. Increasing this
        factor means that more observations will potentially be included in the
        assimilation. The default value is 3.00..

        Including outliers in the Smoother algorithm can dramatically increase the
        coupling between the ensemble members. It is therefore important to filter out
        these outlier data prior to data assimilation. An observation, :math:`\textstyle
        d^o_i`, will be classified as an outlier if

        :math:`|d^o_i - \bar{d}_i| > \mathrm{ENKF\_ALPHA} \left(s_{d_i} + \sigma_{d^o_i}\right)`

        where :math:`\textstyle\boldsymbol{d}^o` is the vector of observed data,
        :math:`\textstyle\boldsymbol{\bar{d}}` is the average of the forcasted data ensemble,
        :math:`\textstyle\boldsymbol{s_{d}}` is the vector of estimated standard deviations
        for the forcasted data ensemble, and :math:`\textstyle\boldsymbol{s_{d}^o}` is the
        vector standard deviations for the observation error (specified a priori).


        STD_CUTOFF If the ensemble variation for one particular measurment is below
        this limit the observation will be deactivated. The default value for
        this cutoff is 1e-6.

        Observe that for the updates many settings should be applied on the analysis
        module in question.



**References**

* Evensen, G. (2007). "Data Assimilation, the Ensemble Kalman Filter", Springer.
* Mardia, K. V., Kent, J. T. and Bibby, J. M. (1979). "Multivariate Analysis", Academic Press.
* Saetrom, J. and Omre, H. (2010). "Ensemble Kalman filtering with shrinkage regression techniques", Computational Geosciences (online first).


Analysis module
---------------
.. _analysis_module:

The final EnKF linear algebra is performed in an analysis module. The keywords
to load, select and modify the analysis modules are documented here.

.. _analysis_select:
.. topic:: ANALYSIS_SELECT

        This command is used to select which analysis module to actually use in the
        updates:

        ::

                ANALYSIS_SELECT ANAME


.. _analysis_set_var:
.. topic:: ANALYSIS_SET_VAR

        The analysis modules can have internal state, like e.g. truncation cutoff
        values, these values can be manipulated from the config file using the
        ANALYSIS_SET_VAR keyword:

        ::

                ANALYSIS_SET_VAR  ANAME  ENKF_TRUNCATION  0.97

        Here `ANAME` must be one of `IES` and `STD_ENKF` which are the two
        analysis modules currently available. To use this you must know which
        variables the module supports setting this way. If you try to set an
        unknown variable you will get an error message on stderr.


.. _analysis_copy:
.. topic:: ANALYSIS_COPY

        With the ANALYSIS_COPY keyword you can create a new instance of a module. This
        can be convenient if you want to run the same algorithm with the different
        settings:

        ::

                ANALYSIS_COPY  A1  A2

        We copy `A1` -> `A2`, where `A1` must be one of available analysis
        modules `STD_ENKF` and `IES`. After the copy operation the modules `A1`
        and `A2` are 100% identical. We then set the truncation to two different
        values:

        ::

                ANALYSIS_SET_VAR A1 ENKF_TRUNCATION 0.95
                ANALYSIS_SET_VAR A2 ENKF_TRUNCATION 0.98


.. _iter_case:
.. topic:: ITER_CASE


        Case name format - iterated ensemble smoother.
                By default, this value is set to `ITERATED_ENSEMBLE_SMOOTHER%d`.


.. _iter_count:
.. topic:: ITER_COUNT

        Number of iterations - iterated ensemble smoother.
                Default is 4.


.. _iter_retry_count:
.. topic:: ITER_RETRY_COUNT

        Number of retries for a iteration - iterated ensemble smoother.
                Defaults to 4.


.. _max_resample:
.. topic:: MAX_RESAMPLE

        How many times should ERT resample & retry a simulation.
                Default is 1.


.. _max_submit:
.. topic:: MAX_SUBMIT

        How many times should the queue system retry a simulation.
                Default is 2.


.. _single_node_update:
.. topic:: SINGLE_NODE_UPDATE

        Splits the dataset into individual parameters.


Advanced optional keywords
--------------------------
.. _advanced_optional_keywords:

The keywords in this section, controls advanced features of ERT. Insight in
the internals of ERT and/or ECLIPSE may
be required to fully understand their effect. Moreover, many of these keywords
are defined in the site configuration, and thus optional to set for the user,
but required when installing ERT at a new site.


.. _define:
.. topic:: DEFINE

        With the DEFINE keyword you can define key-value pairs which will be
        substituted in the rest of the configuration file. The DEFINE keyword expects
        two arguments: a key and a value to replace for that key. Later instances of
        the key enclosed in '<' and '>' will be substituted with the value. The value
        can consist of several strings, in that case they will be joined by one single
        space.

        *Example:*

        ::

                -- Define ECLIPSE_PATH and ECLIPSE_BASE
                DEFINE  ECLIPSE_PATH  /path/to/eclipse/run
                DEFINE  ECLIPSE_BASE  STATF02
                DEFINE  KEY           VALUE1       VALUE2 VALUE3            VALUE4

                -- Set the GRID in terms of the ECLIPSE_PATH
                -- and ECLIPSE_BASE keys.
                GRID    <ECLIPSE_PATH>/<ECLIPSE_BASE>.EGRID

        Observe that when you refer to the keys later in the config file they must be
        enclosed in '<' and '>'. Furthermore, a key-value pair must be defined in the
        config file before it can be used. The last key defined above (KEY) will be
        replaced with VALUE1 VALUE2 VALUE3 VALUE4 - i.e. the extra spaces will be
        discarded.


.. _time_map:
.. topic:: TIME_MAP

        Normally the mapping between report steps and true dates is inferred by
        ERT indirectly by loading the ECLIPSE summary files. In cases where you
        do not have any ECLIPSE summary files you can use the TIME_MAP keyword
        to specify a file with dates which are used to establish this mapping:

        *Example:*

        ::

                -- Load a list of dates from external file: "time_map.txt"
                TIME_MAP time_map.txt

        The format of the TIME_MAP file should just be a list of dates formatted as
        YYYY-MM-DD. The example file below has four dates:

        ::

                2000-01-01
                2000-07-01
                2001-01-01
                2001-07-01



.. _schedule_prediction_file:
.. topic:: SCHEDULE_PREDICTION_FILE

        This is the name of a schedule prediction file. It can contain %d to get
        different files for different members. Observe that the ECLIPSE datafile
        should include only one schedule file, even if you are doing predictions.


Keywords related to running the forward model
---------------------------------------------
.. _keywords_related_to_running_the_forward_model:



.. _forward_model:
.. topic:: FORWARD_MODEL

        The FORWARD_MODEL keyword is used to define how the simulations are executed.
        E.g., which version of ECLIPSE to use, which rel.perm script to run, which
        rock physics model to use etc. Jobs (i.e. programs and scripts) that are to be
        used in the FORWARD_MODEL keyword must be defined using the INSTALL_JOB
        keyword. A set of default jobs is available, and by default FORWARD_MODEL
        takes the value ECLIPSE100.

        The FORWARD_MODEL keyword expects a series of keywords, each defined with
        INSTALL_JOB. ERT will execute the jobs sequentially, in the order they
        are entered.

        *Example A:*

        ::

                -- Suppose that "MY_RELPERM_SCRIPT" has been defined with
                -- the INSTALL_JOB keyword. This FORWARD_MODEL will execute
                -- "MY_RELPERM_SCRIPT" before ECLIPSE100.
                FORWARD_MODEL MY_RELPERM_SCRIPT ECLIPSE100

        *Example B:*

        ::

                -- Suppose that "MY_RELPERM_SCRIPT" and "MY_ROCK_PHYSICS_MODEL"
                -- has been defined with the INSTALL_JOB keyword.
                -- This FORWARD_MODEL will execute "MY_RELPERM_SCRIPT", then
                -- "ECLIPSE100" and in the end "MY_ROCK_PHYSICS_MODEL".
                FORWARD_MODEL MY_RELPERM_SCRIPT ECLIPSE100 MY_ROCK_PHYSICS_MODEL

        For advanced jobs you can pass string arguments to the job using a KEY=VALUE
        based approach, this is further described in: passing arguments. In available
        jobs in ERT you can see a list of the jobs which are available.


.. _simulation_job:
.. topic:: SIMULATION_JOB

        Experimental alternative to `FORWARD_MODEL`.


.. _job_script:
.. topic:: JOB_SCRIPT

        Running the forward model from ERT is a multi-level process which can be
        summarized as follows:

        #. A Python module called jobs.py is written and stored in the directory where
           the forward simulation is run. The jobs.py module contains a list of
           job-elements, where each element is a Python representation of the code
           entered when installing the job.
        #. ERT submits a Python script to the enkf queue system, this
           script then loads the jobs.py module to find out which programs to run, and
           how to run them.
        #. The job_script starts and monitors the individual jobs in the jobs.py
           module.

        The JOB_SCRIPT variable should point at the Python script which is managing
        the forward model. This should normally be set in the site wide configuration
        file.

.. _queue_system:
.. topic:: QUEUE_SYSTEM

        The keyword QUEUE_SYSTEM can be used to control where the simulation jobs are
        executed. It can take the values LSF, TORQUE, SLURM, RSH (*deprecated*) and LOCAL.

        ::

                -- Tell ERT to use the LSF cluster.
                QUEUE_SYSTEM LSF

        The QUEUE_SYSTEM keyword is optional, and usually defaults to LSF (this is
        site dependent).

.. _queue_option:
.. topic:: QUEUE_OPTION

        The chosen queue system can be configured further to for instance define the
        resources it is using. The different queues have individual options that are
        configurable.

.. _lsf_list_of_kwds:

Available LSF configuration options
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. _lsf_server:
.. topic:: LSF_SERVER

        By using the LSF_SERVER option you essentially tell ERT two things about how
        jobs should be submitted to LSF:

        #. You tell ERT that jobs should be submitted using shell commands.
        #. You tell ERT which server should be used when submitting.

        So when your configuration file has the setting:

        ::

                QUEUE_OPTION LSF LSF_SERVER   be-grid01

        ERT will use ssh to submit your jobs using shell commands on the server
        be-grid01. For this to work you must have passwordless ssh to the server
        be-grid01. If you give the special server name LOCAL ERT will submit using
        shell commands on the current workstation.

        **bsub/bjobs/bkill options**

        By default ERT will use the shell commands bsub, bjobs and bkill to interact
        with the queue system, i.e. whatever binaries are first in your PATH will be
        used. For fine grained control of the shell based submission you can tell ERT
        which programs to use:

        ::

                QUEUE_OPTION   LSF  BJOBS_CMD  /path/to/my/bjobs
                QUEUE_OPTION   LSF  BSUB_CMD   /path/to/my/bsub

        *Example 1*

        ::

                LSF_SERVER    be-grid01
                QUEUE_OPTION  LSF     BJOBS_CMD   /path/to/my/bjobs
                QUEUE_OPTION  LSF     BSUB_CMD    /path/to/my/bsub

        In this example we tell ERT to submit jobs from the workstation be-grid01
        using custom binaries for bsub and bjobs.

.. _lsf_queue:
.. topic:: LSF_QUEUE

        ::

                QUEUE_OPTION LSF LSF_QUEUE name_of_queue

        The name of the LSF queue you are running simulations in.
        For example, ``bsub``, this option will be passed to the ``-q`` parameter:
        https://www.ibm.com/support/knowledgecenter/SSWRJV_10.1.0/lsf_command_ref/bsub.q.1.html

.. _lsf_resource:
.. topic:: LSF_RESOURCE

        ::

                QUEUE_OPTION LSF LSF_RESOURCE resource_string

        From https://www.ibm.com/support/knowledgecenter/SSWRJV_10.1.0/lsf_admin/res_req_strings_about.html:

        Most LSF commands accept a -R res_req argument to specify resource
        requirements. The exact behavior depends on the command. For
        example, specifying a resource requirement for the lsload command
        displays the load levels for all hosts that have the requested resources.

        Specifying resource requirements for the lsrun command causes LSF to
        select the best host out of the set of hosts that have the requested
        resources.

        A resource requirement string describes the resources that a job needs.
        LSF uses resource requirements to select hosts for remote execution and
        job execution.

        Resource requirement strings can be simple (applying to the entire job)
        or compound (applying to the specified number of slots).

.. _lsf_rsh_cmd:
.. topic:: LSF_RSH_CMD

        ::

                QUEUE_OPTION LSF LSF_RSH_CMD name_of_queue

        This option sets the *remote shell* command, which defaults to ``/usr/bin/ssh``.

.. _lsf_login_shell:
.. topic:: LSF_LOGIN_SHELL

        ::

                QUEUE_OPTION LSF LSF_LOGIN_SHELL name_of_queue

        Equates to the ``-L`` parameter of e.g. ``bsub``:
        https://www.ibm.com/support/knowledgecenter/en/SSWRJV_10.1.0/lsf_command_ref/bsub.__l.1.html
        Useful if you need to force the ``bsub`` command to use e.g. ``/bin/csh``.

.. _bsub_cmd:
.. topic:: BSUB_CMD

        The ``bsub`` command. Default: ``bsub``.

        ::

                QUEUE_OPTION LSF BSUB_CMD command

.. _bjobs_cmd:
.. topic:: BJOBS_CMD

        The ``bjobs`` command. Default: ``bjobs``.

        ::

                QUEUE_OPTION LSF BJOBS_CMD command


.. _bkill_cmd:
.. topic:: BKILL_CMD

        The ``bkill`` command. Default: ``bkill``.

        ::

                QUEUE_OPTION LSF BKILL_CMD command


.. _bhist_cmd:
.. topic:: BHIST_CMD

        The ``bhist`` command. Default: ``bhist``.

        ::

                QUEUE_OPTION LSF BHIST_CMD command


.. _bjobs_timeout:
.. topic:: BJOBS_TIMEOUT

        Determines how long-lived the job cache is. Default: ``0`` (i.e. no cache).

        ::

                QUEUE_OPTION LSF BJOBS_TIMEOUT 0


.. _debug_output:
.. topic:: DEBUG_OUTPUT

        Whether or not to output debug information to ``stdout`` (i.e. your
        console). Default: ``FALSE``, but note that the LSF queue system will
        change this value in various failure modes.

        ::

                QUEUE_OPTION LSF DEBUG_OUTPUT FALSE


.. _submit_sleep:
.. topic:: SUBMIT_SLEEP

        Determines for how long the system will sleep between submitting jobs.
        Defaults to 0.

        ::

                QUEUE_OPTION LSF SUBMIT_SLEEP 5


.. _project_code:
.. topic:: PROJECT_CODE

        Equates to the ``-P`` parameter for e.g. ``bsub``. See https://www.ibm.com/support/knowledgecenter/SSWRJV_10.1.0/lsf_command_ref/bsub.__p.1.html

        ::

                QUEUE_OPTION LSF PROJECT_CODE command


.. _exclude_host:
.. topic:: EXCLUDE_HOST

        Comma separated list of hosts to be excluded. The LSF system will pass this
        list of hosts to the ``-R`` argument of e.g. ``bsub`` with the criteria
        ``hname!=<exluded_host_1>``.

        ::

                QUEUE_OPTION LSF EXCLUDE_HOST host1,host2


.. _lsf_max_running:
.. topic:: MAX_RUNNING

        The queue option MAX_RUNNING controls the maximum number of simultaneous jobs
        submitted to the queue when using (in this case) the LSF option in
        QUEUE_SYSTEM.

        ::

                QUEUE_SYSTEM LSF
                -- Submit no more than 30 simultaneous jobs
                -- to the TORQUE cluster.
                QUEUE_OPTION LSF MAX_RUNNING 30


.. _torque_list_of_kwds:

Available TORQUE configuration options
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. _torque_sub_stat_del_cmd:
.. topic:: QSUB_CMD|QSTAT_CMD|QDEL_CMD

        By default ERT will use the shell commands qsub,qstat and qdel to interact with
        the queue system, i.e. whatever binaries are first in your PATH will be used.
        For fine grained control of the shell based submission you can tell ERT which
        programs to use:

        ::

                QUEUE_SYSTEM TORQUE
                QUEUE_OPTION TORQUE QSUB_CMD /path/to/my/qsub
                QUEUE_OPTION TORQUE QSTAT_CMD /path/to/my/qstat
                QUEUE_OPTION TORQUE QDEL_CMD /path/to/my/qdel

In this example we tell ERT to submit jobs using custom binaries for bsub and
bjobs.


.. _torque_queue:
.. topic:: QUEUE

        The name of the TORQUE queue you are running simulations in.

        ::

                QUEUE_OPTION TORQUE QUEUE name_of_queue

.. _torque_cluster_label:
.. topic:: CLUSTER_LABEL

        The name of the TORQUE cluster you are running simulations in. This
        might be a label (serveral clusters), or a single one, as in this example baloo.

        ::

                QUEUE_OPTION TORQUE CLUSTER_LABEL baloo

.. _torque_max_running:
.. topic:: MAX_RUNNING

        The queue option MAX_RUNNING controls the maximum number of simultaneous jobs
        submitted to the queue when using (in this case) the TORQUE option in
        QUEUE_SYSTEM.

        ::

                QUEUE_SYSTEM TORQUE
                -- Submit no more than 30 simultaneous jobs
                -- to the TORQUE cluster.
                QUEUE_OPTION TORQUE MAX_RUNNING 30


.. _torque_nodes_cpus:
.. topic:: NUM_NODES|NUM_CPUS_PER_NODE

        When using TORQUE, you must specify how many nodes a single job should
        use, and how many CPUs per node. The default setup in ERT will use one node and
        one CPU. These options are called NUM_NODES and NUM_CPUS_PER_NODE.

        If the numbers specified is higher than supported by the cluster (i.e. use 32
        CPUs, but no node has more than 16), the job will not start.

        If you wish to increase this number, the program running (typically ECLIPSE)
        will usually also have to be told to correspondingly use more processing units
        (keyword PARALLEL)

        ::

                QUEUE_SYSTEM TORQUE
                -- Use more nodes and CPUs
                -- in the TORQUE cluster per job submitted
                -- This should (in theory) allow for 24 processing
                -- units to be used by eg. ECLIPSE
                QUEUE_OPTION TORQUE NUM_NODES 3
                QUEUE_OPTION TORQUE NUM_CPUS_PER_NODE 8

.. _torque_keep_qsub_output:
.. topic:: KEEP_QSUB_OUTPUT

        Sometimes the error messages from qsub can be useful, if something is seriously
        wrong with the environment or setup. To keep this output (stored in your home
        folder), use this:

        ::

                QUEUE_OPTION TORQUE KEEP_QSUB_OUTPUT 1


.. _torque_submit_sleep:
.. topic:: SUBMIT_SLEEP

        To be more gentle with the TORQUE system you can instruct the driver to sleep
        for every submit request. The argument to the SUBMIT_SLEEP is the number of
        seconds to sleep for every submit, which can be a fraction like 0.5.

        ::

                QUEUE_OPTION TORQUE SUBMIT_SLEEP 0.5

.. _torque_debug_output:
.. topic:: DEBUG_OUTPUT

        You can ask the TORQUE driver to store a debug log of the jobs submitted, and
        the resulting job id. This is done with the queue option DEBUG_OUTPUT:

        ::

                QUEUE_OPTION TORQUE DEBUG_OUTPUT torque_log.txt

.. _configuring_the_rsh_queue:

Configuring the RSH queue (deprecated)
--------------------------------------

.. _rsh_host:
.. topic:: RSH_HOST

        You can run the forward model on workstations using remote-shell
        commands. To use the RSH queue system you must first set a list of computers
        which ERT can use for running jobs:

        ::

                QUEUE_OPTION RSH RSH_HOST   computer1:2  computer2:2   large_computer:8

        Here you tell ERT that you can run on three different computers: computer1,
        computer2 and large_computer. The two first computers can accept two jobs,
        and the last can take eight jobs. Observe the following when using RSH:

        You must have passwordless login to the computers listed in RSH_HOST otherwise
        it will fail hard. ERT does not consider total load on the various computers;
        if have said it can take two jobs, it will get two jobs, irrespective of the
        existing load.

.. _rsh_command:
.. topic:: RSH_COMMAND

        This is the name of the executable used to invoke remote shell operations.
        Will typically be either rsh or ssh. The command given to RSH_COMMAND must
        either be in PATH or an absolute path.

        ::

                QUEUE_OPTION RSH RSH_COMMAND /usr/bin/ssh


.. _max_running_rsh:
.. topic:: MAX_RUNNING

        The queue option keyword MAX_RUNNING controls the maximum number of simultaneous
        jobs running when (in this case) using the RSH option in QUEUE_SYSTEM. If MAX_RUNNING
        exceeds the total capacity defined in RSH_HOST, it will automatically be truncated to
        that capacity.

        *Example:*

        ::

                QUEUE_SYSTEM RSH
                -- No more than 10 simultaneous jobs
                -- running via RSH.
                QUEUE_OPTION RSH MAX_RUNNING 10


.. _configuring_the_slurm_queue:

Configuring the SLURM queue
--------------------------------------

        The slurm queue managing tool has a very fine grained control. In ERT only the options that
        are the most necessary have been added.

.. _slurm_sbatch:
.. topic:: SBATCH

        Command used to submit the jobs.

        ::

                QUEUE_OPTION SLURM SBATCH


.. _slurm_scancel:
.. topic:: SCANCEL

        Command used to cancel the jobs.

        ::

                QUEUE_OPTION SLURM SCANCEL


.. _slurm_scontrol:
.. topic:: SCONTROL

        Command to modify configuration and state

        ::

                QUEUE_OPTION SLURM SCONTROL


.. _slurm_squeue:
.. topic:: SQUEUE

        Command to view information about the queue

        ::

                QUEUE_OPTION SLURM SQUEUE


.. _slurm_partition:
.. topic:: PARTITION

        Partition/queue in which to run the jobs

        ::

                QUEUE_OPTION SLURM PARTITION


.. _slurm_squeue_timeout:
.. topic:: SQUEUE_TIMEOUT

        Specify timeout used when querying for status of the jobs while running.

        ::

                QUEUE_OPTION SLURM SQUEUE_TIMEOUT 10

.. _slurm_smax_runtime:
.. topic:: MAX_RUNTIME

        Specify the maximum runtime (in seconds) for how long a job can run.

        ::

                QUEUE_OPTION SLURM MAX_RUNTIME 100

.. _slurm_memory:
.. topic:: MEMORY

        Memory required per node (MB).
        ::

                QUEUE_OPTION SLURM MEMORY 16000

.. _slurm_memory_per_cpu:
.. topic:: MEMORY_PER_CPU (MB).


        Memory required per allocated CPU
        ::

                QUEUE_OPTION SLURM MEMORY_PER_CPU 4000

.. _slurm_include_host:
.. topic:: INCLUDE_HOST

        Specific host names to use when running the jobs. It is possible to add multiple
        hosts separated by space or comma in one option call

        ::

                QUEUE_OPTION SLURM INCLUDE_HOST host1,host2

.. _slurm_exclude_host:
.. topic:: EXCLUDE_HOST

        Specific host names to exclude when running the jobs. It is possible to add multiple
        hosts separated by space or comma in one option call

        ::

                QUEUE_OPTION SLURM EXCLUDE_HOST host3,host4


.. _max_running_slurm:
.. topic:: MAX_RUNNING

        The queue option keyword MAX_RUNNING controls the maximum number of simultaneous
        jobs running when (in this case) using the SLURM option in QUEUE_SYSTEM.

        *Example:*

        ::

                QUEUE_SYSTEM SLURM
                -- No more than 10 simultaneous jobs
                -- running via SLURM.
                QUEUE_OPTION SLURM MAX_RUNNING 10

Keywords related to plotting
----------------------------
.. _keywords_related_to_plotting:


.. _refcase_list:
.. topic:: REFCASE_LIST

        Provide one or more Eclipse .DATA files for a refcase to be added in the
        plots. This refcase will be plotted in different colours. The summary files
        related to the refcase should be in the same folder as the refcase.

        *Example:*

        ::

                REFCASE_LIST /path/to/refcase1/file1.DATA /path/to/refcase2/file2.DATA


.. _rftpath:
.. topic:: RFTPATH


        RFTPATHs argument is the path to where the rft-files are located.

        ::

                RFTPATH  ../models/wells/rft/




.. _hook_workflow:
.. topic:: HOOK_WORKFLOW

    With the keyword :code:`HOOK_WORKFLOW` you can configure workflow
    'hooks'; meaning workflows which will be run automatically at
    certain points during ERTs execution. Currently there are five
    points in ERTs flow of execution where you can hook in a workflow,
    before the simulations start, :code:`PRE_SIMULATION`; after all
    the simulations have completed, :code:`POST_SIMULATION`; before the
    update step, :code:`PRE_UPDATE`; :code:`POST_UPDATE`; after the update
    step and :code:`PRE_FIRST_UPDATE` only before the first update.
    :code:`PRE_FIRST_UPDATE` will run before :code:`PRE_UPDATE`.
    For non iterative algorithms, :code:`PRE_FIRST_UPDATE` is equal to
    :code:`PRE_UPDATE`. The :code:`POST_SIMULATION` hook is
    typically used to trigger QC workflows:

    ::

        HOOK_WORKFLOW initWFLOW        PRE_SIMULATION
        HOOK_WORKFLOW preUpdateWFLOW   PRE_UPDATE
        HOOK_WORKFLOW postUpdateWFLOW  POST_UPDATE
        HOOK_WORKFLOW QC_WFLOW1        POST_SIMULATION
        HOOK_WORKFLOW QC_WFLOW2        POST_SIMULATION


    In this example the workflow :code:`initWFLOW` will run after all
    the simulation directories have been created, just before the
    forward model is submitted to the queue. The workflow
    :code:`preUpdateWFLOW` will be run before the update step and
    :code:`postUpdateWFLOW` will be run after the update step. When
    all the simulations are complete the two workflows
    :code:`QC_WFLOW1` and :code:`QC_WFLOW2` will be run.

    Observe that the workflows being 'hooked in' with the
    :code:`HOOK_WORKFLOW` must be loaded with the
    :code:`LOAD_WORKFLOW` keyword.

    Currently, :code:`PRE_UPDATE` and :code:`POST_UPDATE` are only
    available from python.


.. _load_workflow:
.. topic:: LOAD_WORKFLOW

    Load a workflow into ERT.


.. _load_workflow_job:
.. topic:: LOAD_WORKFLOW_JOB

    Load a workflow job into ERT.


.. _workflow_job_directory:
.. topic:: WORKFLOW_JOB_DIRECTORY

        Directory containing workflow jobs.


Manipulating the Unix environment
---------------------------------
.. _manipulating_the_unix_environment:

The two keywords SETENV and UPDATE_PATH can be used to manipulate the Unix
environment of the ERT process, the manipulations only apply to the running ERT
instance, and are not applied to the shell.


.. _setenv:
.. topic:: SETENV

        You can use the SETENV keyword to alter the unix environment ERT is running
        in. This is probably most relevant for setting up the environment for the
        external jobs invoked by ERT.

        *Example:*

        ::

                -- Setting up LSF
                SETENV  LSF_BINDIR      /prog/LSF/7.0/linux2.6-glibc2.3-x86_64/bin
                SETENV  LSF_LIBDIR      /prog/LSF/7.0/linux2.6-glibc2.3-x86_64/lib
                SETENV  LSF_UIDDIR      /prog/LSF/7.0/linux2.6-glibc2.3-x86_64/lib/uid
                SETENV  LSF_SERVERDIR   /prog/LSF/7.0/linux2.6-glibc2.3-x86_64/etc
                SETENV  LSF_ENVDIR      /prog/LSF/conf

        Observe that the SETENV command is not as powerful as the corresponding shell
        utility. In particular you can not use $VAR to refer to the existing value of
        an environment variable. To add elements to the PATH variable it is easier to
        use the UPDATE_PATH keyword.


.. _update_path:
.. topic:: UPDATE_PATH

        The UPDATE_PATH keyword will prepend a new element to an existing PATH
        variable, i.e. the config.

        ::

                UPDATE_PATH   PATH  /some/funky/path/bin

        will be equivalent to the shell command:

        ::

                setenv PATH /some/funky/path/bin:$PATH

        The whole thing is just a workaround because we can not use $PATH.


.. _umask:
.. topic:: UMASK

        This feature is deprecated and will be removed in a future release.

        The `umask` is a concept used by Linux to control the permissions on
        newly created files. By default the files created by ERT will have the
        default permissions of your account, but by using the keyword `UMASK`
        you can alter the permissions of files created by ERT.

        To determine the initial permissions on newly created files start with
        the initial permissions `-rw-rw-rw-` (octal 0666) for files and
        `-rwxrwxrwx` (octal 0777) for directories, and then *~subtract* the
        current umask setting. So if you wish the newly created files to have
        permissions `-rw-r-----` you need to subtract write permissions for
        group and read and write permissions for others - corresponding to
        `umask 0026`.

        ::

           UMASK 0022

        We remove write permissions from group and others, implying that
        everyone can read the files and directories created by ert, but only the
        owner can write to them. Also everyone can execute the directories (i.e.
        list the content).

        The umask setting in ERT is passed on to the forward model, and should
        apply to the files/directories created by the forward model also.
        However - the executables in the forward model can in principle set it's
        own umask setting or alter permissions in another way - so there is no
        guarantee that the umask setting will apply to all files created by the
        forward model.

        The octal permissions are based on three octal numbers for owner, group
        and others, where each value is based on adding the constants:

         1: Execute permission
         2: Write permission
         4: Read permission

        So an octal permission of 0754 means:

         - Owner(7) can execute(1), write(2) and read(4).
         - Group(5) can execute(1) and read(4).
         - Others(2) can read(4)

        Setting UMASK to 0 is not supported as it poses a potential security risk.