#pragma once
#include "py/obj.h"

mp_obj_t modmu_eventbus_make_new(mp_obj_type_t *type, size_t n_args, size_t n_kwargs, const mp_obj_t *args);
mp_obj_t modmu_eventbus_dispatch(size_t n_args, const mp_obj_t *args, mp_map_t *kwargs);
