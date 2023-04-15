#ifndef CHIP8_STACK_HPP
#define CHIP8_STACK_HPP

#include "common.hpp"
#include "memory.hpp"
#include <stdexcept>

namespace chip8 {
template <typename T, std::size_t sz>
class Stack: public Memory<T, sz> {
public:
    Stack() = default; 
    ~Stack() = default;

    void push(T val) {
        if (m_sp == 0)
            throw std::out_of_range("bottom of the stack");
        this[m_sp--] = val;
    }
private:
    std::size_t m_sp{sz - 1};
};
}

#endif
