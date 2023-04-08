#include "cpu.hpp"

#include <iostream>

using namespace chip8;

chip8::Cpu::opcode_t chip8::Cpu::fetch() {
    opcode_t op{};

    op |= m_ram[m_pc++] << 8;
    op |= m_ram[m_pc];

    return op;
}
