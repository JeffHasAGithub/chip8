#include "cpu.hpp"

namespace chip8 {
Cpu::CpuStatus op_0nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_1nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_2nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_3nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_4nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_5nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_6nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_7nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_8nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_9nnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Annn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Bnnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Cnnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Dnnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Ennn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Fnnn(Cpu&) { return Cpu::CpuStatus::CPU_OK; }

static std::array<Cpu::Oper, 0x10> opers{
    op_0nnn, op_1nnn, op_2nnn, op_3nnn, op_4nnn,
    op_5nnn, op_6nnn, op_7nnn, op_8nnn, op_9nnn,
    op_Annn, op_Bnnn, op_Cnnn, op_Dnnn, op_Ennn,
    op_Fnnn
};

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
