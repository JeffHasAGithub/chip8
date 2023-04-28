#include "cpu.hpp"

namespace chip8 {
Cpu::Cpu(std::istream &rom) {
    int status = init_ram(rom);

    if (status == cpu_status_t::CPU_BAD_ROM)
        throw CpuException("could not read rom", status);

    init_font();
}

opcode_t Cpu::fetch() {
    opcode_t op{};

    op |= m_ram[m_pc++] << 8;
    op |= m_ram[m_pc];

    return op;
}

oper_t Cpu::decode(opcode_t opc) { return nullptr; }
Cpu::cpu_status_t Cpu::execute(oper_t oper) { return cpu_status_t::CPU_OK; }

Cpu::cpu_status_t Cpu::init_ram(std::istream &rom) {
    cpu_status_t status{cpu_status_t::CPU_OK};

    while (rom && m_pc < prog_end)
        rom >> m_ram[m_pc++];

    if (!rom.eof())
        status = cpu_status_t::CPU_BAD_ROM;
    return status;
}

void Cpu::init_font() {
    for (std::size_t i{0}; i < font.size(); ++i)
        m_ram[i] = font[i];
}
} // namespace chip8
