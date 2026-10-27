#include "modmu_app.h"
#include "py/obj.h"

static MP_DEFINE_CONST_FUN_OBJ_1(modmu_app_run_obj, modmu_app_run);

static const mp_rom_map_elem_t modmu_app_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR_run), MP_ROM_PTR(&modmu_app_run_obj)},
};

static MP_DEFINE_CONST_DICT(modmu_app_globals, modmu_app_globals_table);

MP_DEFINE_CONST_OBJ_TYPE(
    modmu_app_type,
    MP_QSTR_App,
    MP_TYPE_FLAG_NONE,
    make_new,
    modmu_app_make_new,
    locals_dict, &modmu_app_globals
);
