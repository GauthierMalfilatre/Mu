#include "poincare/left_square_bracket_layout.h"
extern "C" {
    #include "py/runtime.h"
    #include "py/obj.h"
}

extern mp_obj_type_t modmu_event_type;

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
    size_t n_args,
    const mp_obj_t *args,
    mp_map_t *kwargs
)
{
    size_t n_kw = kwargs ? kwargs->used : 0;
    mp_obj_t kkwargs[1 + 2 * n_kw];
    size_t len;
    mp_obj_t *items;
    modmu_eventbus_obj_t *bus = (modmu_eventbus_obj_t*)MP_OBJ_FROM_PTR(args[0]);

    kkwargs[0] = args[1];
    size_t k = 1;
    if (kwargs) {
        for (size_t i = 0; i < kwargs->alloc; ++i) {
            if (mp_map_slot_is_filled(kwargs, i)) {
                kkwargs[k++] = kwargs->table[i].key;
                kkwargs[k++] = kwargs->table[i].value;
            }
        }
    }
    mp_obj_t event = mp_call_function_n_kw(MP_OBJ_FROM_PTR(&modmu_event_type), 1, n_kw, kkwargs);
    mp_obj_list_get(bus->subs, &len, &items);
    
    for (size_t i = 0; i < len; ++i) {
        // mp_call_function_2(
        //     mp_obj_tuple_get(mp_obj_t self_in, size_t *len, mp_obj_t **items)items[i],
        //     mp_obj_t arg1,
        //     mp_obj_t arg2
        // );
    }
    return event;
}
