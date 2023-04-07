#ifndef CHIP8_MEMORY_HPP
#define CHIP8_MEMORY_HPP

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
            throw std::out_of_range(std::string("not in range: ", i));
        return m_buffer[i];
    }

    T operator[](std::size_t i) const {
        if (i >= sz)
            throw std::out_of_range(std::string("not in range: ", i));
        return this[i];
    }

    T *operator&() { return &m_buffer[0]; }
    const T *operator&() const { return &this; }

    T *begin() { return std::begin(m_buffer); }
    T *end() { return std::end(m_buffer); }

    std::size_t size() const { return sz; }

  private:
    T m_buffer[sz];
};
} // namespace chip8

#endif
