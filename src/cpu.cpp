#include "cpu.hpp"

namespace chip8 {
Cpu::opcode_t Cpu::fetch() {
    opcode_t op{};

    op |= m_ram[m_pc++] << 8;
    op |= m_ram[m_pc];

    return op;
}

Cpu::oper_t Cpu::decode(opcode_t opc) { return nullptr; }
} // namespace chip8
