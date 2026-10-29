
#include "py/qstr.h"
extern "C" {
    #include "modmu_app.h"
    #include "py/obj.h"
    #include "py/runtime.h"
    #include "mod/mu/scenemanager/modmu_scenemgr.h"
}

extern const mp_obj_type_t   modmu_scenemgr_type;

/**
 * @brief The App class basicaly
 */
typedef struct modmu_app_obj_s {

    mp_obj_base_t base;       //!< The base, idk what is that for ...
    bool          is_running; //!< Is the app running
    mp_obj_t      scenemgr;   //!< Scene manager bro

} modmu_app_obj_t;

mp_obj_t modmu_app_make_new(
    const mp_obj_type_t *type,
    size_t n_args,
    size_t n_kw,
    const mp_obj_t *args
)
{
    mp_arg_check_num(n_args, n_kw, 0, 0, false);

    modmu_app_obj_t* thus = mp_obj_malloc(modmu_app_obj_t, type);
    thus->is_running = false;
    thus->scenemgr   = modmu_scenemgr_make_new(&modmu_scenemgr_type, 0, 0, NULL);
    return MP_OBJ_FROM_PTR(thus);
}

void modmu_app_attributes(
    mp_obj_t thus_obj,
    qstr attribute,
    mp_obj_t *dest
) {
    modmu_app_obj_t *app = (modmu_app_obj_t *)MP_OBJ_FROM_PTR(thus_obj);

    if (dest[0] != MP_OBJ_NULL) return;

    if (attribute == MP_QSTR_scenes) {
        dest[0] = app->scenemgr;
    } else {
        dest[1] = MP_OBJ_SENTINEL;
    }
}

mp_obj_t modmu_app_run(
    mp_obj_t thus_obj
)
{
    modmu_app_obj_t* thus = (modmu_app_obj_t*)MP_OBJ_TO_PTR(thus_obj);
    mp_obj_t scene;

    thus->is_running = true;
    while (thus->is_running) {
        scene = modmu_scenemgr_current(thus->scenemgr);
        if (!scene) break;

        mp_obj_t dest[3];
        mp_load_method(scene, MP_QSTR_update, dest);
        dest[2] = thus_obj;
        mp_call_method_n_kw(1, 0, dest);

        mp_load_method(scene, MP_QSTR_render, dest);
        mp_call_method_n_kw(0, 0, dest);
    }
    thus->is_running = false;
    return mp_const_none;
}
