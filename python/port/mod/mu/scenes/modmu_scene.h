#pragma once
#include "py/obj.h"

mp_obj_t modmu_scene_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
mp_obj_t modmu_scene_make_dirty(mp_obj_t thus_obj);
mp_obj_t modmu_scene_is_dirty(mp_obj_t thus_obj);
mp_obj_t modmu_scene_mark_clean(mp_obj_t thus_obj);
mp_obj_t modmu_scene_update(mp_obj_t thus_obj,mp_obj_t app_obj);
mp_obj_t modmu_scene_render(mp_obj_t thus_obj);
mp_obj_t modmu_scene_on_start(mp_obj_t thus_obj, mp_obj_t app_obj);
mp_obj_t modmu_scene_on_dispose(mp_obj_t thus_obj, mp_obj_t app_obj);
