#include "modmu_scene.h"
#include "py/obj.h"

static MP_DEFINE_CONST_FUN_OBJ_1(modmu_scene_make_dirty_obj, modmu_scene_make_dirty);
static MP_DEFINE_CONST_FUN_OBJ_1(modmu_scene_mark_clean_obj, modmu_scene_mark_clean);
static MP_DEFINE_CONST_FUN_OBJ_2(modmu_scene_on_start_obj, modmu_scene_on_start);
static MP_DEFINE_CONST_FUN_OBJ_2(modmu_scene_on_dispose_obj, modmu_scene_on_dispose);
static MP_DEFINE_CONST_FUN_OBJ_2(modmu_scene_update_obj, modmu_scene_update);
static MP_DEFINE_CONST_FUN_OBJ_1(modmu_scene_render_obj, modmu_scene_render);

static const mp_rom_map_elem_t modmu_scene_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR_mark_dirty), MP_ROM_PTR(&modmu_scene_make_dirty_obj)},
    {MP_ROM_QSTR(MP_QSTR_mark_clean), MP_ROM_PTR(&modmu_scene_mark_clean_obj)},
    {MP_ROM_QSTR(MP_QSTR_on_start), MP_ROM_PTR(&modmu_scene_on_start_obj)},
    {MP_ROM_QSTR(MP_QSTR_on_dispose), MP_ROM_PTR(&modmu_scene_on_dispose_obj)},
    {MP_ROM_QSTR(MP_QSTR_update), MP_ROM_PTR(&modmu_scene_update_obj)},
    {MP_ROM_QSTR(MP_QSTR_render), MP_ROM_PTR(&modmu_scene_render_obj)},
};

static MP_DEFINE_CONST_DICT(modmu_scene_globals, modmu_scene_globals_table);

MP_DEFINE_CONST_OBJ_TYPE(
    modmu_scene_type,
    MP_QSTR_Scene,
    MP_TYPE_FLAG_NONE,
    make_new,
    modmu_scene_make_new,
    locals_dict, &modmu_scene_globals
);
