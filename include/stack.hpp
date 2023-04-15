#ifndef CHIP8_STACK_HPP
#define CHIP8_STACK_HPP

#include "common.hpp"
#include "memory.hpp"

namespace chip8 {
template <typename T, std::size_t sz>
class Stack: public Memory<T, sz> {
public:
    Stack() = default; 
    ~Stack() = default;
private:
    std::size_t m_sp{sz - 1};
};
}

#endif
