/*
   Copyright (C) 2017  Equinor ASA, Norway.

   The file 'subst_config.h' is part of ERT - Ensemble based Reservoir Tool.

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

#ifndef ERT_SUBST_CONFIG_H
#define ERT_SUBST_CONFIG_H

#include <ert/tooling.hpp>

typedef struct subst_config_struct subst_config_type;

extern "C" subst_config_type *
subst_config_alloc(const config_content_type *user_config);
extern "C" PY_USED subst_config_type *
subst_config_alloc_full(const subst_list_type *define_list);
extern "C" void subst_config_free(subst_config_type *subst_config);

extern "C" subst_list_type *
subst_config_get_subst_list(subst_config_type *subst_type);

void subst_config_add_internal_subst_kw(subst_config_type *, const char *,
                                        const char *, const char *);
void subst_config_add_subst_kw(subst_config_type *subst_config, const char *key,
                               const char *value);

#endif
