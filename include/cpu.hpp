#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include "common.hpp"
#include "memory.hpp"

namespace chip8 {
class Cpu {
  public:
    Cpu() = default;
    ~Cpu() = default;

    opcode_t fetch();
    oper_t decode(opcode_t);
    cpu_status_t execute(oper_t);

  private:
    Memory<byte_t, mem_sz> m_ram{};

    byte_t m_gp[n_regs]{}; // general purpose registers
    byte_t m_dt;           // delay timer
    byte_t m_st;           // sound timer
    addr_t m_pc{pc_init};  // program counter
    addr_t m_sp;           // stack pointer
};
} // namespace chip8

#endif
