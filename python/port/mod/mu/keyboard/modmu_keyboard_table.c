#include "modmu_keyboard.h"
#include "py/obj.h"

static MP_DEFINE_CONST_FUN_OBJ_0(modmu_keyboard___init___obj, modmu_keyboard___init__);

static MP_DEFINE_CONST_FUN_OBJ_0(modmu_keyboard_update_obj, modmu_keyboard_update);

static MP_DEFINE_CONST_FUN_OBJ_1(modmu_keyboard_press_obj, modmu_keyboard_press);
static MP_DEFINE_CONST_FUN_OBJ_1(modmu_keyboard_release_obj, modmu_keyboard_release);

static const mp_rom_map_elem_t modmu_keyboard_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_mu_dot_keyboard)},
    {MP_ROM_QSTR(MP_QSTR___init__), MP_ROM_PTR(&modmu_keyboard___init___obj)},

    {MP_ROM_QSTR(MP_QSTR_update), MP_ROM_PTR(&modmu_keyboard_update_obj)},
    {MP_ROM_QSTR(MP_QSTR_press), MP_ROM_PTR(&modmu_keyboard_press_obj)},
    {MP_ROM_QSTR(MP_QSTR_release), MP_ROM_PTR(&modmu_keyboard_release_obj)},
};

static MP_DEFINE_CONST_DICT(modmu_keyboard_module_globals, modmu_keyboard_module_globals_table);

const mp_obj_module_t modmu_keyboard_module = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t*)&modmu_keyboard_module_globals
};
