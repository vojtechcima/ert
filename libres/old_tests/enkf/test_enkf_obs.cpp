/*
   Copyright (C) 2013  Equinor ASA, Norway.

   The file 'enkf_enkf_obs_tests.c' is part of ERT - Ensemble based Reservoir Tool.

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

#include <ert/util/test_util.h>

#include <ert/ecl/ecl_grid.h>
#include <ert/ecl/ecl_sum.h>

#include <ert/enkf/enkf_obs.hpp>
#include <ert/enkf/summary_obs.hpp>

int main(int argc, char **argv) {
    history_type *history = NULL;
    time_map_type *external_time_map = NULL;
    ecl_grid_type *grid = NULL;
    ensemble_config_type *ensemble_config = NULL;
    ecl_sum_type *refcase = NULL;

    enkf_obs_type *enkf_obs = enkf_obs_alloc(history, external_time_map, grid,
                                             refcase, ensemble_config);

    obs_vector_type *obs_vector =
        obs_vector_alloc(SUMMARY_OBS, "WWCT", NULL, 2);
    summary_obs_type *summary_obs1 =
        summary_obs_alloc("SummaryKey", "ObservationKey", 43.2, 2.0);
    obs_vector_install_node(obs_vector, 0, summary_obs1);

    summary_obs_type *summary_obs2 =
        summary_obs_alloc("SummaryKey2", "ObservationKey2", 4.2, 0.1);
    obs_vector_install_node(obs_vector, 1, summary_obs2);

    obs_vector_type *obs_vector2 =
        obs_vector_alloc(SUMMARY_OBS, "WWCT2", NULL, 2);
    summary_obs_type *summary_obs3 =
        summary_obs_alloc("SummaryKey", "ObservationKey", 43.2, 2.0);
    obs_vector_install_node(obs_vector2, 0, summary_obs3);

    summary_obs_type *summary_obs4 =
        summary_obs_alloc("SummaryKey2", "ObservationKey2", 4.2, 0.1);
    obs_vector_install_node(obs_vector2, 1, summary_obs4);

    enkf_obs_add_obs_vector(enkf_obs, obs_vector);
    enkf_obs_add_obs_vector(enkf_obs, obs_vector2);

    enkf_obs_free(enkf_obs);

    exit(0);
}
