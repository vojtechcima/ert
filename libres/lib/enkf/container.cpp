/*
   Copyright (C) 2012  Equinor ASA, Norway.

   The file 'container.c' is part of ERT - Ensemble based Reservoir Tool.

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

#include <ert/util/util.h>
#include <ert/util/vector.h>

#include <ert/enkf/container.hpp>
#include <ert/enkf/container_config.hpp>

struct container_struct {
    int __type_id;
    const container_config_type *config;
    vector_type *nodes;
};

// Used by the VOID_ALLOC macro
C_USED container_type *container_alloc(const container_config_type *config) {
    container_type *container =
        (container_type *)util_malloc(sizeof *container);
    UTIL_TYPE_ID_INIT(container, CONTAINER);
    container->config = config;
    container->nodes = vector_alloc_new();
    return container;
}

void container_free(container_type *container) {
    vector_free(container->nodes);
    free(container);
}

void container_add_node(container_type *container, void *child_node) {
    vector_append_ref(container->nodes, child_node);
}

const void *container_iget_node(const container_type *container, int index) {
    return vector_iget_const(container->nodes, index); // CXX_CAST_ERROR
}

int container_get_size(const container_type *container) {
    return vector_get_size(container->nodes);
}

void container_assert_size(const container_type *container) {
    if (vector_get_size(container->nodes) !=
        container_config_get_size(container->config))
        util_abort("%s: container size mismatch. Current:%d  Config:%d \n",
                   __func__, container_get_size(container),
                   container_config_get_size(container->config));
}

UTIL_IS_INSTANCE_FUNCTION(container, CONTAINER)
UTIL_SAFE_CAST_FUNCTION(container, CONTAINER)
UTIL_SAFE_CAST_FUNCTION_CONST(container, CONTAINER)
VOID_ALLOC(container)
VOID_FREE(container)
