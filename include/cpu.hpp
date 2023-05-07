/**
 * @file cpu.hpp
 *
 * The Cpu class implements the chip8
 * instruction set and coordinates the
 * various emulated subsystems such as
 * memory and the display.
 *
 */

#ifndef CHIP8_CPU_HPP
#define CHIP8_CPU_HPP

#include "common.hpp"
#include "except.hpp"
#include "font.hpp"
#include "memory.hpp"

#include <iostream>

namespace chip8 {
class CpuException : public Exception {
  public:
    CpuException(const std::string &msg, int err_c) : Exception{msg, err_c} {};
};

class Cpu {
  public:
    enum CpuStatus {
        CPU_OK,
        CPU_BAD_ROM,
        CPU_ERR,
    };

    using OpCode = std::uint16_t;
    using Oper = CpuStatus (*)(Cpu&);

    Cpu(std::istream &rom);
    Cpu(const Cpu &cpu) = delete;
    ~Cpu() = default;

    Cpu &operator=(const Cpu &cpu) = delete;

    void fetch();
    void decode();
    CpuStatus execute();

  private:
    Memory<Byte, mem_sz> m_ram{};
    Memory<Addr, stk_sz> m_stk{};

    Byte m_gp[n_regs]{};  // general purpose registers
    Byte m_dt;            // delay timer
    Byte m_st;            // sound timer
    Addr m_pc{prog_init}; // program counter
    Addr m_i;             // index register
    std::size_t m_sp{};   // stack pointer

    OpCode current_opc{};
    Oper current_oper{};

    CpuStatus init_ram(std::istream &rom);
    void init_font();

    friend CpuStatus op_0nnn(Cpu&);
    friend CpuStatus op_1nnn(Cpu&);
    friend CpuStatus op_2nnn(Cpu&);
    friend CpuStatus op_3nnn(Cpu&);
    friend CpuStatus op_4nnn(Cpu&);
    friend CpuStatus op_5nnn(Cpu&);
    friend CpuStatus op_6nnn(Cpu&);
    friend CpuStatus op_7nnn(Cpu&);
    friend CpuStatus op_8nnn(Cpu&);
    friend CpuStatus op_9nnn(Cpu&);
    friend CpuStatus op_Annn(Cpu&);
    friend CpuStatus op_Bnnn(Cpu&);
    friend CpuStatus op_Cnnn(Cpu&);
    friend CpuStatus op_Dnnn(Cpu&);
    friend CpuStatus op_Ennn(Cpu&);
    friend CpuStatus op_Fnnn(Cpu&);
};
} // namespace chip8

#endif
