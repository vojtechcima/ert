/*
   Copyright (C) 2011  Equinor ASA, Norway.

   The file 'rms_type.h' is part of ERT - Ensemble based Reservoir Tool.

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

#ifndef ERT_RMS_TYPE_H
#define ERT_RMS_TYPE_H
#include <stdio.h>
#include <stdlib.h>

enum rms_type_enum_def {
    rms_char_type,
    rms_float_type,
    rms_double_type,
    rms_bool_type,
    rms_byte_type,
    rms_int_type
};

typedef enum rms_type_enum_def rms_type_enum;

/* This *really* should not be exported ... */

typedef struct {
    rms_type_enum rms_type;
    int sizeof_ctype;

} __rms_type;

void rms_type_free(void *);
__rms_type *rms_type_alloc(rms_type_enum, int);

#endif
