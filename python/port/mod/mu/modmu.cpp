extern "C" {
    #include "modmu.h"
    #include "py/obj.h"
    #include "mod/mu/keyboard/modmu_keyboard.h"
}

mp_obj_t modmu___init__() {
    modmu_keyboard___init__();
    return mp_const_none;
}
