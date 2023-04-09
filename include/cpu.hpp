#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include "constants.hpp"
#include "memory.hpp"
#include <cstdint>

namespace chip8 {

class Cpu {
  public:
    enum status_t {
        CPU_OK,
        CPU_ERR,
    };

    using byte_t = std::uint8_t;
    using opcode_t = std::uint16_t;
    using addr_t = std::uint16_t;
    using oper_t = status_t (*)(opcode_t);

    Cpu(Memory<std::uint8_t, mem_sz> &ram) : m_ram{ram} {}
    ~Cpu() = default;

    opcode_t fetch();
    oper_t decode(opcode_t);
    status_t execute(oper_t);

  private:
    Memory<std::uint8_t, mem_sz> &m_ram;

    // general purpose registers
    byte_t m_gp[n_regs]{};

    byte_t m_dt; // delay timer
    byte_t m_st; // sound timer

    addr_t m_pc{pc_init}; // program counter
    addr_t m_sp;          // stack pointer
};
} // namespace chip8

#endif
