#include "modmu.h"
#include "py/obj.h"

static MP_DEFINE_CONST_FUN_OBJ_0(modmu_key___init___obj, modmu___init__);

static MP_DEFINE_CONST_FUN_OBJ_1(modmu_key_watch_obj, modmu_key_watch);
static MP_DEFINE_CONST_FUN_OBJ_1(modmu_key_unwatch_obj, modmu_key_unwatch);

static MP_DEFINE_CONST_FUN_OBJ_0(modmu_key_update_obj, modmu_key_update);

static const mp_rom_map_elem_t modmu_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_mu)},
    {MP_ROM_QSTR(MP_QSTR___init__), MP_ROM_PTR(&modmu_key___init___obj)},

    {MP_ROM_QSTR(MP_QSTR_key_watch), MP_ROM_PTR(&modmu_key_watch_obj)},
    {MP_ROM_QSTR(MP_QSTR_key_unwatch), MP_ROM_PTR(&modmu_key_unwatch_obj)},
    {MP_ROM_QSTR(MP_QSTR_key_update), MP_ROM_PTR(&modmu_key_update_obj)},
};

static MP_DEFINE_CONST_DICT(modmu_module_globals, modmu_module_globals_table);

const mp_obj_module_t modmu_module = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t*)&modmu_module_globals
};
