/*
   Copyright (C) 2013  Equinor ASA, Norway.

   The file 'enkf_main_fs_current_file_test.c' is part of ERT - Ensemble based Reservoir Tool.

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

#include <filesystem>

#include <stdlib.h>

#include <ert/enkf/enkf_fs.hpp>
#include <ert/enkf/enkf_main.hpp>
#include <ert/util/test_util.h>
#include <ert/util/test_work_area.hpp>

namespace fs = std::filesystem;

void test_current_file_not_present_symlink_present(const char *model_config) {
    test_assert_true(fs::exists("Storage/enkf"));
    util_make_slink("enkf", "Storage/current");
    res_config_type *res_config = res_config_alloc_load(model_config);
    enkf_main_type *enkf_main = enkf_main_alloc(res_config);
    test_assert_true(enkf_main_case_is_current(enkf_main, "enkf"));
    test_assert_false(fs::exists("Storage/current"));
    test_assert_true(fs::exists("Storage/current_case"));
    char *current_case = enkf_main_read_alloc_current_case_name(enkf_main);
    test_assert_string_equal(current_case, "enkf");
    free(current_case);
    enkf_main_free(enkf_main);
    res_config_free(res_config);
}

void test_current_file_present(const char *model_config) {
    test_assert_true(fs::exists("Storage/current_case"));
    res_config_type *res_config = res_config_alloc_load(model_config);
    enkf_main_type *enkf_main = enkf_main_alloc(res_config);
    test_assert_true(enkf_main_case_is_current(enkf_main, "enkf"));
    test_assert_false(fs::exists("Storage/current"));
    char *current_case = enkf_main_read_alloc_current_case_name(enkf_main);
    test_assert_string_equal(current_case, "enkf");
    free(current_case);
    enkf_main_free(enkf_main);
    res_config_free(res_config);
}

void test_change_case(const char *model_config) {
    res_config_type *res_config = res_config_alloc_load(model_config);
    enkf_main_type *enkf_main = enkf_main_alloc(res_config);
    enkf_main_select_fs(enkf_main, "default");
    test_assert_true(enkf_main_case_is_current(enkf_main, "default"));
    test_assert_false(enkf_main_case_is_current(enkf_main, "enkf"));
    {
        char *current_case = enkf_main_read_alloc_current_case_name(enkf_main);
        test_assert_string_equal(current_case, "default");
        free(current_case);
    }

    enkf_main_select_fs(enkf_main, "enkf");
    test_assert_true(enkf_main_case_is_current(enkf_main, "enkf"));
    test_assert_false(enkf_main_case_is_current(enkf_main, "default"));
    {
        char *current_case = enkf_main_read_alloc_current_case_name(enkf_main);
        test_assert_string_equal(current_case, "enkf");
        free(current_case);
    }

    enkf_fs_type *enkf_fs = enkf_main_mount_alt_fs(enkf_main, "default", false);
    enkf_main_select_fs(enkf_main, "default");
    test_assert_true(enkf_main_case_is_current(enkf_main, "default"));
    enkf_fs_decref(enkf_fs);
    enkf_main_free(enkf_main);
    res_config_free(res_config);
}

int main(int argc, char **argv) {
    const char *config_file = argv[1];
    ecl::util::TestArea ta("current_file");
    char *model_config;
    util_alloc_file_components(config_file, NULL, &model_config, NULL);
    ta.copy_parent_content(config_file);

    test_current_file_not_present_symlink_present(model_config);
    test_current_file_present(model_config);
    test_change_case(model_config);

    free(model_config);
    exit(0);
}
