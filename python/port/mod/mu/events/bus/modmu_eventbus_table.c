#include "modmu_eventbus.h"
#include "py/obj.h"
#include "py/qstr.h"

static MP_DEFINE_CONST_FUN_OBJ_KW(modmu_eventbus_dispatch_obj, 2, modmu_eventbus_dispatch);

static const mp_rom_map_elem_t modmu_eventbus_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR_dispatch), MP_ROM_PTR(&modmu_eventbus_dispatch_obj)},
};

static MP_DEFINE_CONST_DICT(modmu_eventbus_globals, modmu_eventbus_globals_table);

MP_DEFINE_CONST_OBJ_TYPE(
    modmu_eventbus_type,
    MP_QSTR_EventBus,
    MP_TYPE_FLAG_NONE,
    make_new,
    (const void *)modmu_eventbus_make_new,
    locals_dict, &modmu_eventbus_globals
);
