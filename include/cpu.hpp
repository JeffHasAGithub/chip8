#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include "memory.hpp"
#include <cstdint>

namespace chip8 {

class Cpu {
  public:
    using opcode_t = std::uint16_t;

    Cpu(Memory<std::uint8_t, 4096> &ram) : m_ram{ram} {}
    ~Cpu() = default;

    opcode_t fetch();

  private:
    Memory<std::uint8_t, 4096> &m_ram;
    std::uint16_t m_pc{0x200};
};
} // namespace chip8

#endif
