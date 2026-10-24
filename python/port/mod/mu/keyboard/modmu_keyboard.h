#pragma once
#include <py/obj.h>

mp_obj_t modmu_keyboard___init__();

mp_obj_t modmu_keyboard_watch(mp_obj_t key);
mp_obj_t modmu_keyboard_unwatch(mp_obj_t key);
mp_obj_t modmu_keyboard_update();
mp_obj_t modmu_keyboard_release(mp_obj_t key);
mp_obj_t modmu_keyboard_press(mp_obj_t key);
