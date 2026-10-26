#ifndef PYTHON_PORT_MOD_MU_KEYS_HPP
    #define PYTHON_PORT_MOD_MU_KEYS_HPP
    #include "ion/keyboard.h"
    #include "layout_keyboard.h"
    #include "py/obj.h"
#include <cstdint>

class KeyStates {
    public:
        constexpr KeyStates() : m_last(0), m_now(0) {}

        void update() {
            m_last = m_now;
            m_now = Ion::Keyboard::scan();
        }

        bool isPress(mp_obj_t key) {
            return (uint64_t(m_now) & ~uint64_t(m_last) & bit(key)) != 0;
        }

        bool isRelease(mp_obj_t key) {
            return (~(uint64_t)m_now & (uint64_t)m_last & bit(key)) != 0;
        }

    private:
        private:
            static uint64_t bit(mp_obj_t key) {
                mp_int_t k = mp_obj_get_int(key);
                if (k < 0 || k > 63) {
                    assert(1 == 0);
                }
                return 1ULL << k;
            }

        Ion::Keyboard::State m_last;
        Ion::Keyboard::State m_now;

};

#endif /* PYTHON_PORT_MOD_MU_KEYS_HPP */
