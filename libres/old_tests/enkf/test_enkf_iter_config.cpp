/*
   Copyright (C) 2013  Equinor ASA, Norway.

   The file 'enkf_iter_config.c' is part of ERT - Ensemble based Reservoir Tool.

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
#include <stdio.h>
#include <stdlib.h>

#include <ert/config/config_parser.hpp>

#include <ert/util/test_util.h>

#include <ert/enkf/analysis_iter_config.hpp>
#include <ert/enkf/config_keys.hpp>
#include <ert/enkf/enkf_defaults.hpp>

#define TMP_PATH "/tmp"
char *create_config_file(const char *enspath_fmt, const char *runpath_fmt,
                         int iter_count) {
    char *config_file = util_alloc_tmp_file(TMP_PATH, "iter-config", false);
    FILE *stream = util_fopen(config_file, "w");
    fprintf(stream, "%s  %s\n", ITER_CASE_KEY, enspath_fmt);
    fprintf(stream, "%s  %d\n", ITER_COUNT_KEY, iter_count);
    fclose(stream);
    return config_file;
}

void test_set() {
    analysis_iter_config_type *iter_config = analysis_iter_config_alloc();

    test_assert_false(analysis_iter_config_case_fmt_set(iter_config));
    analysis_iter_config_set_case_fmt(iter_config, "case%d");
    test_assert_true(analysis_iter_config_case_fmt_set(iter_config));

    test_assert_false(analysis_iter_config_num_iterations_set(iter_config));
    analysis_iter_config_set_num_iterations(iter_config, 77);
    test_assert_true(analysis_iter_config_num_iterations_set(iter_config));

    test_assert_int_equal(
        analysis_iter_config_get_num_retries_per_iteration(iter_config), 4);
    analysis_iter_config_set_num_retries_per_iteration(iter_config, 10);
    test_assert_int_equal(
        analysis_iter_config_get_num_retries_per_iteration(iter_config), 10);

    analysis_iter_config_free(iter_config);
}

int main(int argc, char **argv) {
    const char *enspath_fmt = "iter%d";
    const char *runpath_fmt = "run/iter%d/real%d";
    const int iter_count = 10;
    char *config_file =
        create_config_file(enspath_fmt, runpath_fmt, iter_count);

    config_parser_type *config = config_alloc();
    config_content_type *content;
    analysis_iter_config_add_config_items(config);

    content = config_parse(config, config_file, NULL, NULL, NULL, NULL,
                           CONFIG_UNRECOGNIZED_ERROR, true);
    test_assert_true(config_content_is_valid(content));

    test_assert_true(config_content_has_item(content, ITER_CASE_KEY));
    test_assert_true(config_content_has_item(content, ITER_COUNT_KEY));

    {
        analysis_iter_config_type *iter_config = analysis_iter_config_alloc();
        char itercase[50];
        sprintf(itercase, DEFAULT_ANALYSIS_ITER_CASE, 5);
        test_assert_string_equal(analysis_iter_config_iget_case(iter_config, 5),
                                 itercase);
        analysis_iter_config_init(iter_config, content);

        test_assert_int_equal(
            analysis_iter_config_get_num_iterations(iter_config), iter_count);
        test_assert_string_equal(analysis_iter_config_iget_case(iter_config, 5),
                                 "iter5");

        analysis_iter_config_free(iter_config);
    }
    remove(config_file);
    free(config_file);
    config_content_free(content);
    config_free(config);

    test_set();
    exit(0);
}
