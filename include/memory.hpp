#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <cassert>
#include <iterator>
#include <stdexcept>

namespace chip8 {

template <typename T, std::size_t sz> class Memory {
  public:
    Memory() = default;
    Memory(T dv) {
        auto it = begin(), stop = end();
        for (; it != stop; ++it)
            *it = dv;
    }

    ~Memory() = default;

    T &operator[](std::size_t i) {
        if (i >= sz)
            throw std::out_of_range(
                std::string("not in range: ", i)
            );

        return m_buffer[i];
    }

    T operator[](std::size_t i) const {
        if (i >= sz)
            throw std::out_of_range(
                std::string("not in range: ", i)
            );

        return m_buffer[i];
    }

    T *begin() { return std::begin(m_buffer); }
    T *end() { return std::end(m_buffer); }

  private:
    T m_buffer[sz];
};
} // namespace chip8

#endif
