extern "C" {
    #include "py/runtime.h"
    #include "py/obj.h"
    #include "modmu_event.h"
}

#define MAX_NAME_SIZE 32

typedef struct modmu_event_obj_s {

    mp_obj_base_t base;
    mp_obj_t      type;
    mp_obj_t      data;

} modmu_event_obj_t;

void modmu_event_attributes(
    mp_obj_t thus_obj,
    qstr attribute,
    mp_obj_t *dest
)
{
    modmu_event_obj_t *app = (modmu_event_obj_t *)MP_OBJ_TO_PTR(thus_obj);

    if (dest[0] != MP_OBJ_NULL) return;

    if (attribute == MP_QSTR_type) {
        dest[0] = app->type;
    } else if (attribute == MP_QSTR_data) {
        dest[0] = app->data;
    } else {
        dest[1] = MP_OBJ_SENTINEL;
    }
}

mp_obj_t modmu_event_make_new(
    mp_obj_type_t *type,
    size_t         n_args,
    size_t         n_kwargs,
    const mp_obj_t *args
)
{
    mp_arg_check_num(n_args, n_kwargs, 1, 16, true);

    modmu_event_obj_t *thus = mp_obj_malloc(modmu_event_obj_t, type);

    thus->type = args[0];
    thus->data = mp_obj_new_dict(n_kwargs);
    for (size_t i = 0; i < n_kwargs; ++i) {
        mp_obj_dict_store(thus->data, args[n_args + i * 2], args[n_args + i * 2 + 1]);
    }
    return MP_OBJ_FROM_PTR(thus);
}
