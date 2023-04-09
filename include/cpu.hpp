#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include <cstdint>
#include "memory.hpp"

namespace chip8 {

class Cpu {
  public:
    using opcode_t = std::uint16_t;
    using addr_t = std::uint16_t;
    enum status_t {
        CPU_OK,
        CPU_ERR,
    };

    Cpu(Memory<std::uint8_t, 4096> &ram) : m_ram{ram} {}
    ~Cpu() = default;

    opcode_t fetch();

  private:
    Memory<std::uint8_t, 4096> &m_ram;
    addr_t m_pc{0x200};
};
} // namespace chip8

#endif
