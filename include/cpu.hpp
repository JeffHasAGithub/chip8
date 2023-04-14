#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include "common.hpp"
#include "memory.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace chip8 {
class Cpu {
  public:
    Cpu(const std::string& rom) {
        std::ifstream fin{rom, std::ios::binary};

        if (!fin)
            throw std::runtime_error("could not open rom: " + rom);

        while (fin && m_pc < 0x600)
            fin >> m_mem[m_pc++];

        if (!fin.eof())
            throw std::runtime_error("failure reading from rom: " + rom);
    }
    Cpu(const Cpu &cpu) = delete;

    ~Cpu() = default;

    Cpu &operator=(const Cpu &cpu) = delete;

    opcode_t fetch();
    oper_t decode(opcode_t);
    cpu_status_t execute(oper_t);

  private:
    Memory<byte_t, mem_sz> m_mem{};

    byte_t m_gp[n_regs]{}; // general purpose registers
    byte_t m_dt;           // delay timer
    byte_t m_st;           // sound timer
    addr_t m_pc{pc_init};  // program counter
    addr_t m_sp;           // stack pointer
    addr_t m_i;            // index register
};
} // namespace chip8

#endif
