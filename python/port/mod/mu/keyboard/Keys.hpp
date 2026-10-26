#ifndef PYTHON_PORT_MOD_MU_KEYS_HPP
    #define PYTHON_PORT_MOD_MU_KEYS_HPP
    #include "ion/keyboard.h"
    #include "layout_keyboard.h"
    #include "py/obj.h"

class KeyStates {
    public:
        constexpr KeyStates() : m_dict() {}

        void update() {
            auto m = mp_obj_dict_get_map(getInstance());
            Ion::Keyboard::State state = Ion::Keyboard::scan();
            for (size_t i = 0; i < m->alloc; ++i) {
                if (MP_MAP_SLOT_IS_FILLED(m, i)) {
                    mp_obj_t value = m->table[i].value;

                    if (value == NULL) {
                        continue;
                    }

                    size_t len;
                    mp_obj_t *arr;
                    mp_obj_get_array(value, &len, &arr);

                    if (len < 2) {
                        continue;
                    }

                    Ion::Keyboard::Key key = static_cast<Ion::Keyboard::Key>(mp_obj_get_int(m->table[i].key));
                    micropython_port_interrupt_if_needed();
                    arr[0] = arr[1];
                    arr[1] = mp_obj_new_bool(state.keyDown(key));
                }
            }
        }

        void watch(mp_obj_t key) {
            mp_obj_t items[2] = { mp_const_false, mp_const_false };
            mp_obj_t list = mp_obj_new_list(2, items);
            mp_obj_dict_store(getInstance(), key, list);
        }

        void unwatch(mp_obj_t key) {
            mp_map_elem_t *elem = mp_map_lookup(mp_obj_dict_get_map(getInstance()), key, MP_MAP_LOOKUP_REMOVE_IF_FOUND);
            (void)elem;
        }

        bool isPress(mp_obj_t key) {
            bool prev = false, curr = false;
            if (getState(key, prev, curr)) {
                return (!prev && curr);
            }
            return false;
        }

        bool isRelease(mp_obj_t key) {
            bool prev = false, curr = false;
            if (getState(key, prev, curr)) {
                return (prev && !curr);
            }
            return false;
        }

    private:
        mp_obj_t m_dict = 0;

        mp_obj_t getInstance() {
            if (m_dict == 0) {
                m_dict = mp_obj_new_dict(0);
            }
            return m_dict;
        }

        bool getState(mp_obj_t key, bool &out_prev, bool &out_curr) {
            mp_map_elem_t *elem = mp_map_lookup(mp_obj_dict_get_map(getInstance()), key, MP_MAP_LOOKUP);
            if (elem == NULL || elem->value == MP_OBJ_NULL) {
                return false;
            }

            size_t len;
            mp_obj_t *items;
            mp_obj_get_array(elem->value, &len, &items);

            if (len < 2) {
                return false;
            }

            out_prev = mp_obj_is_true(items[0]);
            out_curr = mp_obj_is_true(items[1]);
            return true;
        }
    };

#endif /* PYTHON_PORT_MOD_MU_KEYS_HPP */
