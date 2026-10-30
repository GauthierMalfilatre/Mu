#include "modmu.h"
#include "py/obj.h"
#include "py/qstr.h"

extern const mp_obj_type_t   modmu_app_type;
extern const mp_obj_type_t   modmu_scene_type;
extern const mp_obj_type_t   modmu_scenemgr_type;
extern const mp_obj_type_t   modmu_keyboard_type;

static MP_DEFINE_CONST_FUN_OBJ_0(modmu_key___init___obj, modmu___init__);

static const mp_rom_map_elem_t modmu_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_mu)},
    {MP_ROM_QSTR(MP_QSTR___init__), MP_ROM_PTR(&modmu_key___init___obj)},

    {MP_ROM_QSTR(MP_QSTR_App), MP_ROM_PTR(&modmu_app_type) },
    {MP_ROM_QSTR(MP_QSTR_Scene), MP_ROM_PTR(&modmu_scene_type)},
    {MP_ROM_QSTR(MP_QSTR_SceneManager), MP_ROM_PTR(&modmu_scenemgr_type)},
    {MP_ROM_QSTR(MP_QSTR_Keyboard), MP_ROM_PTR(&modmu_keyboard_type)},

};

static MP_DEFINE_CONST_DICT(modmu_module_globals, modmu_module_globals_table);

const mp_obj_module_t modmu_module = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t*)&modmu_module_globals
};
