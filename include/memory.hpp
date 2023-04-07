#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <array>
#include <cassert>

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

  private:
    std::array<T, sz> m_buffer;
};
} // namespace chip8

#endif
