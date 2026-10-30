#include "py/qstr.h"
extern "C" {
    #include "py/runtime.h"
    #include "modmu_scenemgr.h"
    #include <py/obj.h>
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
    return MP_OBJ_FROM_PTR(thus);
}

mp_obj_t modmu_scenemgr_push(
    size_t n_args,
    const mp_obj_t *args
)
{
    modmu_scenemgr_obj_t *thus  = (modmu_scenemgr_obj_t*)MP_OBJ_TO_PTR(args[0]);
    modmu_scene_obj_t    *scene = (modmu_scene_obj_t*)MP_OBJ_TO_PTR(args[1]);

    mp_obj_t              ctx   = (n_args >= 3) ? args[2] : mp_const_none;

    mp_obj_list_append(thus->stack, scene);

    mp_obj_t dest[3];
    mp_load_method(scene, MP_QSTR_on_start, dest);
    dest[2] = ctx;
    mp_call_method_n_kw(1, 0, dest);

    return MP_OBJ_FROM_PTR(scene);
}

mp_obj_t modmu_scenemgr_pop(
    size_t n_args,
    const mp_obj_t *args
)
{
    modmu_scenemgr_obj_t *thus  = (modmu_scenemgr_obj_t*)MP_OBJ_TO_PTR(args[0]);
    mp_obj_t              ctx   = (n_args >= 2) ? args[1] : mp_const_none;

    mp_obj_t dest[2];
    mp_load_method(thus->stack, MP_QSTR_pop, dest);
    mp_obj_t scene = mp_call_method_n_kw(0, 0, dest);

    mp_obj_t dest_[3];
    mp_load_method(scene, MP_QSTR_on_dispose, dest_);
    dest_[2] = ctx;
    mp_call_method_n_kw(1, 0, dest_);

    return scene;
}

mp_obj_t modmu_scenemgr_current(
    mp_obj_t thus_obj
)
{
    modmu_scenemgr_obj_t *thus = (modmu_scenemgr_obj_t*)MP_OBJ_TO_PTR(thus_obj);

    size_t len;
    mp_obj_t *items;
    mp_obj_list_get(thus->stack, &len, &items);
    return (len > 0) ? items[len - 1] : mp_const_none;
}

mp_obj_t modmu_scenemgr_change(
    size_t n_args,
    const mp_obj_t *args
)
{
    while (modmu_scenemgr_current(args[0]) != mp_const_none) {
        modmu_scenemgr_pop(n_args, (const mp_obj_t [2]){ args[0], (n_args >= 3) ? args[2] : mp_const_none});
    }
    modmu_scenemgr_push(n_args, args);
    return args[1];
}
