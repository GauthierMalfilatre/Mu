#include "modmu_scenemgr.h"
#include "py/obj.h"

static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(modmu_scenemgr_push_obj, 2, 3, modmu_scenemgr_push);
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(modmu_scenemgr_pop_obj, 2, 3, modmu_scenemgr_pop);
static MP_DEFINE_CONST_FUN_OBJ_1(modmu_scenemgr_current_obj, modmu_scenemgr_current);

static const mp_rom_map_elem_t modmu_scenemgr_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR_push), MP_ROM_PTR(&modmu_scenemgr_push_obj)},
    {MP_ROM_QSTR(MP_QSTR_pop), MP_ROM_PTR(&modmu_scenemgr_pop_obj)},
    {MP_ROM_QSTR(MP_QSTR_current), MP_ROM_PTR(&modmu_scenemgr_current_obj)},
};

static MP_DEFINE_CONST_DICT(modmu_scenemgr_globals, modmu_scenemgr_globals_table);

MP_DEFINE_CONST_OBJ_TYPE(
    modmu_scenemgr_type,
    MP_QSTR_SceneManager,
    MP_TYPE_FLAG_NONE,
    make_new,
    modmu_scenemgr_make_new,
    locals_dict, &modmu_scenemgr_globals
);
