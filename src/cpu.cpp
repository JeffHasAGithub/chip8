#include "cpu.hpp"

namespace chip8 {
Cpu::Cpu(std::istream &rom) {
    int status = init_ram(rom);

    if (status == CpuStatus::CPU_BAD_ROM)
        throw CpuException("could not read rom", status);

    init_font();
}

OpCode Cpu::fetch() {
    OpCode op{};

    op |= m_ram[m_pc++] << 8;
    op |= m_ram[m_pc];

    return op;
}

Oper Cpu::decode(OpCode opc) { return nullptr; }
Cpu::CpuStatus Cpu::execute(Oper oper) { return CpuStatus::CPU_OK; }

Cpu::CpuStatus Cpu::init_ram(std::istream &rom) {
    CpuStatus status{CpuStatus::CPU_OK};

    while (rom && m_pc < prog_end)
        rom >> m_ram[m_pc++];

    if (!rom.eof())
        status = CpuStatus::CPU_BAD_ROM;
    return status;
}

void Cpu::init_font() {
    for (std::size_t i{0}; i < font.size(); ++i)
        m_ram[i] = font[i];
}
} // namespace chip8
