/*
   Copyright (C) 2011  Equinor ASA, Norway.

   The file 'path_fmt.h' is part of ERT - Ensemble based Reservoir Tool.

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

#ifndef ERT_PATH_FMT_H
#define ERT_PATH_FMT_H

#include <stdarg.h>
#include <stdbool.h>

#include <ert/util/node_ctype.hpp>

typedef struct path_fmt_struct path_fmt_type;

extern "C" path_fmt_type *path_fmt_alloc_directory_fmt(const char *);
path_fmt_type *path_fmt_alloc_path_fmt(const char *);
char *path_fmt_alloc_path(const path_fmt_type *, bool, ...);
char *path_fmt_alloc_file(const path_fmt_type *, bool, ...);
extern "C" void path_fmt_free(path_fmt_type *);
void path_fmt_free__(void *arg);
extern "C" const char *path_fmt_get_fmt(const path_fmt_type *);
void path_fmt_reset_fmt(path_fmt_type *, const char *);
path_fmt_type *path_fmt_realloc_path_fmt(path_fmt_type *path_fmt,
                                         const char *fmt);

#endif
