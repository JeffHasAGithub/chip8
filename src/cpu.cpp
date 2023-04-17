#include "cpu.hpp"

namespace chip8 {
Cpu::Cpu(std::istream &rom) {
    while (rom && m_pc < prog_end)
        rom >> m_ram[m_pc++];

    if (!rom.eof())
        throw std::runtime_error("failure reading rom");
}

opcode_t Cpu::fetch() {
    opcode_t op{};

    op |= m_ram[m_pc++] << 8;
    op |= m_ram[m_pc];

    return op;
}

oper_t Cpu::decode(opcode_t opc) { return nullptr; }
cpu_status_t Cpu::execute(oper_t oper) { return cpu_status_t::CPU_OK; }
} // namespace chip8
