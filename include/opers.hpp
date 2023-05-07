/**
 * @file opers.hpp
 *
 * The original Chip8 implementation had
 * 36 instructions. Rather than declare
 * 36 separate instructions, we declare
 * 16 'handlers' based on the first nibble
 * of the given instruction. The handler will
 * decode the full instruction and either
 * delegate to a separate function or execute
 * the instruction inline.
 */

#ifndef CHIP8_OPERS_HPP
#define CHIP8_OPERS_HPP

#include "cpu.hpp"

namespace chip8 {
Cpu::CpuStatus op_0nnn(Cpu &);
Cpu::CpuStatus op_1nnn(Cpu &);
Cpu::CpuStatus op_2nnn(Cpu &);
Cpu::CpuStatus op_3nnn(Cpu &);
Cpu::CpuStatus op_4nnn(Cpu &);
Cpu::CpuStatus op_5nnn(Cpu &);
Cpu::CpuStatus op_6nnn(Cpu &);
Cpu::CpuStatus op_7nnn(Cpu &);
Cpu::CpuStatus op_8nnn(Cpu &);
Cpu::CpuStatus op_9nnn(Cpu &);
Cpu::CpuStatus op_Annn(Cpu &);
Cpu::CpuStatus op_Bnnn(Cpu &);
Cpu::CpuStatus op_Cnnn(Cpu &);
Cpu::CpuStatus op_Dnnn(Cpu &);
Cpu::CpuStatus op_Ennn(Cpu &);
Cpu::CpuStatus op_Fnnn(Cpu &);
} // namespace chip8

#endif
