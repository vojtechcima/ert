/*
   Copyright (C) 2011  Equinor ASA, Norway.

   The file 'field_config.h' is part of ERT - Ensemble based Reservoir Tool.

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

#ifndef ERT_FIELD_CONFIG_H
#define ERT_FIELD_CONFIG_H

#include <stdbool.h>
#include <stdio.h>

#include <ert/util/stringlist.h>
#include <ert/util/type_macros.h>

#include <ert/ecl/ecl_grid.h>
#include <ert/ecl/ecl_kw.h>
#include <ert/ecl/ecl_type.h>

#include <ert/rms/rms_file.hpp>

#include <ert/enkf/active_list.hpp>
#include <ert/enkf/enkf_macros.hpp>
#include <ert/enkf/enkf_types.hpp>
#include <ert/enkf/enkf_util.hpp>
#include <ert/enkf/field_common.hpp>
#include <ert/enkf/field_trans.hpp>

/**
   This is purely a convenience structure used during initialization,
   to denote which arguments are required and, which should be
   defualted.
*/
typedef enum {
    ECLIPSE_RESTART = 1,
    ECLIPSE_PARAMETER = 2,
    GENERAL = 3,
    UNKNOWN_FIELD_TYPE = 4
} field_type_enum;

/**
    The field_file_format_type denotes different ways to store a
    field. Unfortunately the different elements in the enum definition
    have somewhat different properties:


    1. ecl_kw_file is for input - either pack or unpacked.

    2. ecl_kw_file_active_cells / ecl_kw_file_all_cells are for output.

    3. Except for ecl_restart_file all formats are for A FILE (with a
       filename), more or less assuming that this field is the only
       content in the file, whereas ecl_restart_file is for a restart
       block, and not a file.

    This has some slightly unlogical consequences:

     1. The enum has 'file_format' in the name, but ecl_restart_file
        is not a file.

     2. The functions which guess/determine a file type can not return
        all possible values of the enum.

     3. Treatment is not symmetric for input/output.

*/
typedef enum {
    UNDEFINED_FORMAT = 0,
    RMS_ROFF_FILE = 1,
    /** ecl_kw format either packed (i.e. active cells) *or* all cells - used
     * when reading from file. */
    ECL_KW_FILE = 2,
    /** ecl_kw format, only active cells - used writing to file. */
    ECL_KW_FILE_ACTIVE_CELLS = 3,
    /** ecl_kw_format, all cells - used when writing to file. */
    ECL_KW_FILE_ALL_CELLS = 4,
    ECL_GRDECL_FILE = 5,
    /** Assumes packed on export. */
    ECL_FILE = 6,
    FILE_FORMAT_NULL = 7
} field_file_format_type; /* Used when the guess functions are given NULL to check -should never be read. */

/* active_cells currently not really implemented */

void field_config_update_parameter_field(field_config_type *config,
                                         int truncation, double min_value,
                                         double max_value,
                                         field_file_format_type export_format,
                                         const char *init_transform,
                                         const char *output_transform);

void field_config_update_general_field(
    field_config_type *config, int truncation, double min_value,
    double max_value,
    field_file_format_type
        export_format, /* This can be guessed with the field_config_default_export_format( ecl_file ) function. */
    const char *init_transform, const char *input_transform,
    const char *output_transform);

extern "C" field_config_type *
field_config_alloc_empty(const char *ecl_kw_name, ecl_grid_type *ecl_grid,
                         field_trans_table_type *trans_table, bool global_size);

C_USED const char *field_config_default_extension(field_file_format_type, bool);
extern "C" field_file_format_type field_config_guess_file_type(const char *);
ecl_data_type field_config_get_ecl_data_type(const field_config_type *);
void field_config_get_dims(const field_config_type *, int *, int *, int *);
extern "C" PY_USED int field_config_get_nx(const field_config_type *config);
extern "C" PY_USED int field_config_get_ny(const field_config_type *config);
extern "C" PY_USED int field_config_get_nz(const field_config_type *config);
extern "C" void field_config_free(field_config_type *);
int field_config_get_volume(const field_config_type *);
extern "C" int
field_config_get_data_size_from_grid(const field_config_type *config);
void field_config_set_ecl_data_type(field_config_type *, ecl_data_type);
int field_config_get_byte_size(const field_config_type *);
int field_config_get_sizeof_ctype(const field_config_type *);
int field_config_active_index(const field_config_type *, int, int, int);
int field_config_global_index(const field_config_type *, int, int, int);
bool field_config_ijk_valid(const field_config_type *, int, int, int);
extern "C" bool field_config_ijk_active(const field_config_type *config, int i,
                                        int j, int k);
bool field_config_active_cell(const field_config_type *, int, int, int);
field_file_format_type
field_config_get_export_format(const field_config_type *);
void field_config_set_key(field_config_type *, const char *);
void field_config_enkf_OFF(field_config_type *);
bool field_config_enkf_mode(const field_config_type *config);
const char *field_config_get_key(const field_config_type *);
bool field_config_keep_inactive_cells(const field_config_type *);
field_func_type *field_config_get_init_transform(const field_config_type *);
field_func_type *field_config_get_output_transform(const field_config_type *);
bool field_config_is_valid(const field_config_type *field_config);
void field_config_assert_binary(const field_config_type *,
                                const field_config_type *, const char *);
void field_config_assert_unary(const field_config_type *, const char *);

void field_config_set_truncation(field_config_type *, int, double, double);
extern "C" int
field_config_get_truncation_mode(const field_config_type *config);
extern "C" double
field_config_get_truncation_min(const field_config_type *config);
extern "C" double
field_config_get_truncation_max(const field_config_type *config);
extern "C" ecl_grid_type *field_config_get_grid(const field_config_type *);
const char *field_config_get_grid_name(const field_config_type *);

int field_config_parse_user_key(const field_config_type *config,
                                const char *index_key, int *i, int *j, int *k);
bool field_config_parse_user_key__(const char *index_key, int *i, int *j,
                                   int *k);

extern "C" field_file_format_type
field_config_default_export_format(const char *filename);
extern "C" const char *
field_config_get_output_transform_name(const field_config_type *field_config);
extern "C" const char *
field_config_get_init_transform_name(const field_config_type *field_config);

void field_config_fprintf_config(const field_config_type *config,
                                 enkf_var_type var_type, const char *outfile,
                                 const char *infile, const char *min_std_file,
                                 FILE *stream);

extern "C" field_type_enum
field_config_get_type(const field_config_type *config);

/*Generated headers */
UTIL_IS_INSTANCE_HEADER(field_config);
UTIL_SAFE_CAST_HEADER(field_config);
UTIL_SAFE_CAST_HEADER_CONST(field_config);
CONFIG_GET_ECL_KW_NAME_HEADER(field);
VOID_FREE_HEADER(field_config);
VOID_GET_DATA_SIZE_HEADER(field);

#endif
