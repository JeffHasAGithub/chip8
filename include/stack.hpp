#ifndef CHIP8_STACK_HPP
#define CHIP8_STACK_HPP

#include "memory.hpp"
#include <stdexcept>

namespace chip8 {
template <typename T, std::size_t sz>
class Stack : public Memory<T, sz> {
  public:
    Stack(std::size_t &sp) : m_sp(sp) { m_sp = 0; }
    Stack(std::size_t &sp, T dv) : Memory<T, sz>(dv), Stack<T, sz>(sp) {}
    ~Stack() = default;

    void push(T val) {
        if (m_sp < 0)
            throw std::out_of_range("beyond stack range");
        (*this)[--m_sp] = val;
    }

    T pop() {
        if (m_sp >= sz)
            throw std::out_of_range("beyond stack range");
        return (*this)[m_sp++];
    }

    std::size_t sp() const { return m_sp; }

  private:
    std::size_t &m_sp;
};
} // namespace chip8

#endif
