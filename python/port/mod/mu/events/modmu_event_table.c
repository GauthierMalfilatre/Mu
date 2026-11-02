#include "py/obj.h"
#include "modmu_event.h"

static const mp_rom_map_elem_t modmu_event_globals_table[] = {};

static MP_DEFINE_CONST_DICT(modmu_event_globals, modmu_event_globals_table);

MP_DEFINE_CONST_OBJ_TYPE(
    modmu_event_type,
    MP_QSTR_Event,
    MP_TYPE_FLAG_NONE,
    make_new,
    (const void *)modmu_event_make_new,
    attr,
    (const void *)modmu_event_attributes,
    locals_dict, &modmu_event_globals
);
