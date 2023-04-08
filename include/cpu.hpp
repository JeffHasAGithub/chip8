#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include <cstdint>
#include "memory.hpp"

namespace chip8 {
class Cpu {
  public:
    Cpu(Memory<std::uint8_t, 4096> &ram): m_ram{ram} {}
    ~Cpu() = default;

  private:
    Memory<std::uint8_t, 4096> &m_ram;
};
} // namespace chip8

#endif
