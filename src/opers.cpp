#include "opers.hpp"

namespace chip8 {
static std::size_t extract_nnn(Addr addr) {
    return Bits{addr}.extract(0x0FFF);
}

Cpu::CpuStatus op_0nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }

// Jump to location 'nnn'
Cpu::CpuStatus op_1nnn(Cpu &cpu) {
    Bits bits{cpu.current_opc};
    cpu.m_pc = bits.extract(0x0FFF);

    return Cpu::CpuStatus::CPU_OK;
}

Cpu::CpuStatus op_2nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_3nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_4nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_5nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_6nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_7nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_8nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_9nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Annn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Bnnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Cnnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Dnnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Ennn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Fnnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
} // namespace chip8
