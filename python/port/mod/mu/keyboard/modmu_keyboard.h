#pragma once
#include <py/obj.h>

mp_obj_t modmu_keyboard_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);

mp_obj_t modmu_keyboard_release(mp_obj_t thus_obj, mp_obj_t key);
mp_obj_t modmu_keyboard_press(mp_obj_t thus_obj, mp_obj_t key);
mp_obj_t modmu_keyboard_update(mp_obj_t thus_obj);
