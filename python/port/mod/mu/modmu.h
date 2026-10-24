#pragma once
#include <py/obj.h>

mp_obj_t modmu___init__();

mp_obj_t modmu_key_watch(mp_obj_t key);
mp_obj_t modmu_key_unwatch(mp_obj_t key);
mp_obj_t modmu_key_update();
mp_obj_t modmu_key_release(mp_obj_t key);
mp_obj_t modmu_key_press(mp_obj_t key);
