#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <cassert>
#include <iterator>

namespace chip8 {

template <typename T, std::size_t sz> class Memory {
  public:
    Memory() = default;
    ~Memory() = default;

    T &operator[](std::size_t i) {
        assert(i < sz);
        return m_buffer[i];
    }

    T operator[](std::size_t i) const {
        assert(i < sz);
        return m_buffer[i];
    }

    T* begin() { return std::begin(m_buffer); }
    T* end() { return std::end(m_buffer); }

  private:
    T m_buffer[sz];
};
} // namespace chip8

#endif
