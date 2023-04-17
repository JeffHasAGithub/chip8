#include "cpu.hpp"

namespace chip8 {
Cpu::Cpu(std::istream &rom) {
    if (init_ram(rom) == cpu_status_t::CPU_BAD_ROM)
        throw std::runtime_error("could not read rom");
}

opcode_t Cpu::fetch() {
    opcode_t op{};

    op |= m_ram[m_pc++] << 8;
    op |= m_ram[m_pc];

    return op;
}

oper_t Cpu::decode(opcode_t opc) { return nullptr; }
cpu_status_t Cpu::execute(oper_t oper) { return cpu_status_t::CPU_OK; }

cpu_status_t Cpu::init_ram(std::istream &rom) {
    cpu_status_t status{cpu_status_t::CPU_OK};

    while (rom && m_pc < prog_end)
        rom >> m_ram[m_pc++];

    if (!rom.eof())
        status = cpu_status_t::CPU_BAD_ROM;
    return status;
}
} // namespace chip8
