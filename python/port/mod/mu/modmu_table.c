#include "modmu.h"
#include "py/obj.h"

extern const mp_obj_module_t modmu_keyboard_module;
extern const mp_obj_type_t   modmu_app_type;

static MP_DEFINE_CONST_FUN_OBJ_0(modmu_key___init___obj, modmu___init__);

static const mp_rom_map_elem_t modmu_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_mu)},
    {MP_ROM_QSTR(MP_QSTR___init__), MP_ROM_PTR(&modmu_key___init___obj)},

    {MP_ROM_QSTR(MP_QSTR_keyboard), MP_ROM_PTR(&modmu_keyboard_module)},

    { MP_ROM_QSTR(MP_QSTR_App), MP_ROM_PTR(&modmu_app_type) }

};

static MP_DEFINE_CONST_DICT(modmu_module_globals, modmu_module_globals_table);

const mp_obj_module_t modmu_module = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t*)&modmu_module_globals
};
