#pragma once

#include <py/obj.h>

mp_obj_t modmu_app_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
mp_obj_t modmu_app_run(mp_obj_t thus_obj);
void modmu_app_attributes(mp_obj_t thus_obj, qstr attribute, mp_obj_t *dest);
