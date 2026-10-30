#include <cstddef>
extern "C" {
    #include "py/runtime.h"
    #include "py/obj.h"
}

typedef struct modmu_eventbus_obj_s {

    mp_obj_base_t base;
    mp_obj_t      subs;

} modmu_eventbus_obj_t;

mp_obj_t modmu_eventbus_make_new(
    mp_obj_type_t *type,
    size_t         n_args,
    size_t         n_kwargs,
    const mp_obj_t *args
)
{
    mp_arg_check_num(n_args, n_kwargs, 0, 0, false);

    modmu_eventbus_obj_t *thus = mp_obj_malloc(modmu_eventbus_obj_t, type);

    thus->subs = mp_obj_new_list(0, (mp_obj_t*)0);
    return MP_OBJ_FROM_PTR(thus);
}

mp_obj_t modmu_eventbus_dispatch(
    size_t          n_args,
    const mp_obj_t *args,
    mp_map_t       *kwargs
)
{
    size_t n_kw = kwargs ? kwargs->used : 0;

    // TODO : Transform mp_map_t into a flat mp_obj_t []
    mp_obj_t flatten[n_kw * 2];

    // mp_map_init_fixed_table(mp_map_t *map, size_t n, const mp_obj_t *table)

    return mp_const_none;
}
