#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include "common.hpp"
#include "memory.hpp"
#include "stack.hpp"
#include <iostream>

namespace chip8 {
class Cpu {
  public:
    Cpu(std::istream &rom) {
        while (rom && m_pc < prog_end)
            rom >> m_ram[m_pc++];

        if (!rom.eof())
            throw std::runtime_error("failure reading rom");
    }
    Cpu(const Cpu &cpu) = delete;

    ~Cpu() = default;

    Cpu &operator=(const Cpu &cpu) = delete;

    opcode_t fetch();
    oper_t decode(opcode_t);
    cpu_status_t execute(oper_t);

  private:
    Memory<byte_t, mem_sz> m_ram{};
    Stack<addr_t, stk_sz> m_stk{m_sp};

    byte_t m_gp[n_regs]{};  // general purpose registers
    byte_t m_dt;            // delay timer
    byte_t m_st;            // sound timer
    addr_t m_pc{prog_init}; // program counter
    addr_t m_i;             // index register
    std::size_t m_sp{};     // stack pointer
};
} // namespace chip8

#endif
