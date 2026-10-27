extern "C" {
    #include "modmu_app.h"
    #include "py/obj.h"
    #include "py/runtime.h"
}

/**
 * @brief The App class basicaly
 */
typedef struct modmu_app_obj_s {

    mp_obj_base_t base;       //!< The base, idk what is that for ...
    bool          is_running; //!< Is the app running

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
    return MP_OBJ_FROM_PTR(thus);
}

mp_obj_t modmu_app_run(
    mp_obj_t thus_obj
)
{
    modmu_app_obj_t* thus = (modmu_app_obj_t*)MP_OBJ_TO_PTR(thus_obj);

    thus->is_running = true;
    while (thus->is_running) {
        // TODO: Scene, keyboard, and tickrate
    }
    thus->is_running = false;
    return mp_const_none;
}
