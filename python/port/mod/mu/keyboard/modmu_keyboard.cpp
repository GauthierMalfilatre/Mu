extern "C" {
    #include "modmu_keyboard.h"
    #include "py/obj.h"
}
#include "mod/mu/keyboard/Keys.hpp"

static KeyStates _kb_state;

mp_obj_t modmu_keyboard___init__() {
    _kb_state = KeyStates();
    return mp_const_none;
}

mp_obj_t modmu_keyboard_watch(mp_obj_t key) {
    _kb_state.watch(key);
    return mp_const_none;
}

mp_obj_t modmu_keyboard_unwatch(mp_obj_t key) {
    _kb_state.unwatch(key);
    return mp_const_none;
}

mp_obj_t modmu_keyboard_update() {
    _kb_state.update();
    return mp_const_none;
}

mp_obj_t modmu_keyboard_press(mp_obj_t key) {
    return mp_obj_new_bool(_kb_state.isPress(key));
}

mp_obj_t modmu_keyboard_release(mp_obj_t key) {
    return mp_obj_new_bool(_kb_state.isRelease(key));
}
