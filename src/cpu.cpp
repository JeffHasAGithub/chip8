#include "cpu.hpp"

#include <iostream>

using namespace chip8;

std::uint16_t chip8::Cpu::fetch() {
    std::uint16_t op{};

    op |= m_ram[m_pc++] << 8;
    op |= m_ram[m_pc];

    return op;
}
