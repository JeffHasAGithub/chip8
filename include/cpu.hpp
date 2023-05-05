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
    enum cpu_status_t {
        CPU_OK,
        CPU_BAD_ROM,
        CPU_ERR,
    };

    Cpu(std::istream &rom);
    Cpu(const Cpu &cpu) = delete;
    ~Cpu() = default;

    Cpu &operator=(const Cpu &cpu) = delete;

    OpCode fetch();
    Oper decode(OpCode);
    cpu_status_t execute(Oper);

  private:
    Memory<Byte, mem_sz> m_ram{};
    Memory<Addr, stk_sz> m_stk{};

    Byte m_gp[n_regs]{};  // general purpose registers
    Byte m_dt;            // delay timer
    Byte m_st;            // sound timer
    Addr m_pc{prog_init}; // program counter
    Addr m_i;             // index register
    std::size_t m_sp{};     // stack pointer

    cpu_status_t init_ram(std::istream &rom);
    void init_font();
};
} // namespace chip8

#endif
