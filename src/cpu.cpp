#include "cpu.hpp"

namespace chip8 {
Cpu::Cpu(std::istream &rom) {
    int status = init_ram(rom);

    if (status == CpuStatus::CPU_BAD_ROM)
        throw CpuException("could not read rom", status);

    init_font();
}

void Cpu::fetch() {
    OpCode opc{};

    opc |= m_ram[m_pc++] << 8;
    opc |= m_ram[m_pc];

    current_opc = opc;
}

void Cpu::decode() {}
Cpu::CpuStatus Cpu::execute() { return CpuStatus::CPU_OK; }

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
