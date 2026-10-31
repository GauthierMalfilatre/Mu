extern "C" {
    #include "py/misc.h"
    #include "py/runtime.h"
    #include "py/obj.h"
    #include "modmu_eventbus.h"
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

static bool mp_obj_list_lookup(
    mp_obj_t list,
    mp_obj_t what
)
{
    size_t    len;
    mp_obj_t *items;

    mp_obj_list_get(list, &len, &items);
    for (size_t i = 0; i < len; ++i) {
        if (items[i] == what) {
            return true;
        }
    }
    return false;
}

mp_obj_t modmu_eventbus_dispatch(
    size_t n_args,
    const mp_obj_t *args,
    mp_map_t *kwargs
)
{
    size_t n_kw = kwargs ? kwargs->used : 0;
    mp_obj_t kkwargs[1 + 2 * n_kw];
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

    size_t len;
    mp_obj_t *items;
    mp_obj_list_get(bus->subs, &len, &items);

    size_t tuple_len;
    mp_obj_t *tuple_items;
    for (size_t i = 0; i < len; ++i) {
        mp_obj_tuple_get(items[i], &tuple_len, &tuple_items);
        if (tuple_len != 3) continue;
        if (!mp_obj_list_lookup(tuple_items[1], args[1])) continue; 
        mp_call_function_1(
            tuple_items[1],
            event
        );
    }
    return event;
}

mp_obj_t modmu_sub_priority(
    mp_obj_t sub
)
{
    return mp_obj_subscr(sub, MP_OBJ_NEW_SMALL_INT(0), MP_OBJ_SENTINEL);
}

mp_obj_t modmu_eventbus_subscribe(
    size_t n_args,
    const mp_obj_t *pos_args,
    mp_map_t *kw_args
)
{
    modmu_eventbus_obj_t *thus = (modmu_eventbus_obj_t*)MP_OBJ_TO_PTR(pos_args[0]);
    mp_obj_t fn = pos_args[1];
    mp_obj_t names = mp_obj_new_tuple(n_args - 2, pos_args + 2);

    const mp_arg_t allowed[] = {
        { MP_QSTR_priority, MP_ARG_KW_ONLY | MP_ARG_INT, { .u_int = 0 } },
    };

    mp_arg_val_t vals[1];
    mp_arg_parse_all(0, NULL, kw_args, MP_ARRAY_SIZE(allowed), allowed, vals);

    mp_obj_t entry[3] = {
        MP_OBJ_NEW_SMALL_INT(vals[0].u_int),
        fn,
        names
    };
    mp_obj_list_append(thus->subs, mp_obj_new_tuple(3, entry));

    mp_obj_t dest[4];
    mp_load_method(thus->subs, MP_QSTR_sort, dest);
    dest[2] = MP_OBJ_NEW_QSTR(MP_QSTR_key);
    dest[3] = MP_OBJ_FROM_PTR(&modmu_sub_priority_obj);
    mp_call_method_n_kw(0, 1, dest);

    return pos_args[0];
}
