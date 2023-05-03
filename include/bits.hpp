/**
 * @file bits.hpp
 *
 * The Bits class provides methods for
 * manipulating and transforming bit
 * patterns equivalent to the address
 * width of the application (e.g. 32-bit, 64-bit).
 */

#ifndef CHIP8_BITS_HPP
#define CHIP8_BITS_HPP

#include <cstddef>

namespace chip8 {
class Bits {
  public:
    Bits(std::size_t val = 0) : m_value{val} {};
    ~Bits() = default;

    std::size_t on(std::size_t mask) { return m_value | mask; }
    std::size_t off(std::size_t mask) { return m_value & ~mask; }
    std::size_t flip(std::size_t mask) { return m_value ^ mask; }
    std::size_t extract(std::size_t mask) { return m_value & mask; }

  private:
    std::size_t m_value;
};
} // namespace chip8

#endif
