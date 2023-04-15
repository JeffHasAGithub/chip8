#ifndef CHIP8_STACK_HPP
#define CHIP8_STACK_HPP

#include "memory.hpp"

namespace chip8 {
template <typename T, std::size_t sz>
class Stack: public Memory<T, sz> {
    Stack() = default; 
    ~Stack() = default;
};
}

#endif
