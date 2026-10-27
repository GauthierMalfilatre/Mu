extern "C" {
    #include "py/objlist.h"
    #include "py/runtime.h"
    #include "modmu_scenemgr.h"
    #include <py/obj.h>
    #include "../scenes/modmu_scene.h"
}

typedef struct modmu_scene_obj_s modmu_scene_obj_t;

typedef struct modmu_scenemgr_obj_s {

    mp_obj_base_t base;
    mp_obj_t      stack;

} modmu_scenemgr_obj_t;

mp_obj_t modmu_scenemgr_make_new(
    const mp_obj_type_t *type,
    size_t n_args,
    size_t n_kw,
    const mp_obj_t *args
)
{
    mp_arg_check_num(n_args, n_kw, 0, 0, false);

    modmu_scenemgr_obj_t *thus = mp_obj_malloc(modmu_scenemgr_obj_t, type);
    thus->stack = mp_obj_new_list(0, NULL);
    return mp_const_none;
}

mp_obj_t modmu_scenemgr_push(
    size_t n_args,
    const mp_obj_t *args
)
{
    modmu_scenemgr_obj_t *thus  = (modmu_scenemgr_obj_t*)MP_OBJ_TO_PTR(args[0]);
    modmu_scene_obj_t    *scene = (modmu_scene_obj_t*)MP_OBJ_TO_PTR(args[1]);

    // mp_obj_t              ctx   = (n_args >= 3) ? NULL : NULL;
    return mp_const_none;
}
