#include "py/obj.h"
#include "modmu_keyboard.h"

static MP_DEFINE_CONST_FUN_OBJ_2(modmu_keyboard_press_obj, modmu_keyboard_press);
static MP_DEFINE_CONST_FUN_OBJ_2(modmu_keyboard_release_obj, modmu_keyboard_release);
static MP_DEFINE_CONST_FUN_OBJ_1(modmu_keyboard_update_obj, modmu_keyboard_update);

static const mp_rom_map_elem_t modmu_keyboard_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR_press), MP_ROM_PTR(&modmu_keyboard_press_obj)},
    {MP_ROM_QSTR(MP_QSTR_release), MP_ROM_PTR(&modmu_keyboard_release_obj)},
    {MP_ROM_QSTR(MP_QSTR_update), MP_ROM_PTR(&modmu_keyboard_update_obj)},
};

static MP_DEFINE_CONST_DICT(modmu_keyboard_globals, modmu_keyboard_globals_table);

MP_DEFINE_CONST_OBJ_TYPE(
    modmu_keyboard_type,
    MP_QSTR_Keyboard,
    MP_TYPE_FLAG_NONE,
    make_new,
    modmu_keyboard_make_new,
    locals_dict, &modmu_keyboard_globals
);
