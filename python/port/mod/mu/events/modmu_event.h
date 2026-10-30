#pragma once

mp_obj_t modmu_event_make_new(mp_obj_type_t *type, size_t n_args, size_t n_kwargs, const mp_obj_t *args);
void modmu_event_attributes(mp_obj_t thus_obj, qstr attribute, mp_obj_t *dest);
