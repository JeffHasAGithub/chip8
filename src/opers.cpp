#include "opers.hpp"

namespace chip8 {
static constexpr Addr nnn_mask{0x0FFF};
static constexpr Addr kk_mask{0x00FF};
static constexpr Addr x_mask{0x0F00};
static constexpr Addr y_mask{0x00F0};

static std::size_t extract_mask(Addr addr, Addr mask) {
    return Bits{addr}.extract(mask);
}

static std::size_t extract_x(Addr addr) {
    return extract_mask(addr, x_mask) >> 8;
}

static std::size_t extract_y(Addr addr) {
    return extract_mask(addr, y_mask) >> 4;
}

Cpu::CpuStatus op_0nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }

// Jump to location 'nnn'
Cpu::CpuStatus op_1nnn(Cpu &cpu) {
    cpu.m_pc = extract_mask(cpu.current_opc, nnn_mask);

    return Cpu::CpuStatus::CPU_OK;
}

Cpu::CpuStatus op_2nnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }

// 3xkk - SE Vx, byte
// Skip next instruction if Vx == kk
Cpu::CpuStatus op_3nnn(Cpu &cpu) {
    std::size_t x = extract_x(cpu.current_opc);
    Byte kk = extract_mask(cpu.current_opc, kk_mask);

    if (cpu.m_gp[x] == kk)
        cpu.m_pc += 2;

    return Cpu::CpuStatus::CPU_OK;
}

// 4xkk - SNE Vx, byte
// Skip next instruction if Vx != kk
Cpu::CpuStatus op_4nnn(Cpu &cpu) {
    std::size_t x = extract_x(cpu.current_opc);
    Byte kk = extract_mask(cpu.current_opc, kk_mask);

    if (cpu.m_gp[x] != kk)
        cpu.m_pc += 2;

    return Cpu::CpuStatus::CPU_OK;
}

// 5xy0 - SE Vx, Vy
// Skip next instruction if Vx == Vy
Cpu::CpuStatus op_5nnn(Cpu &cpu) {
    std::size_t x = extract_x(cpu.current_opc);
    std::size_t y = extract_y(cpu.current_opc);

    if (cpu.m_gp[x] == cpu.m_gp[y])
        cpu.m_pc += 2;

    return Cpu::CpuStatus::CPU_OK;
}

// 6xkk - LD Vx, byte
// Load kk into Vx
Cpu::CpuStatus op_6nnn(Cpu &cpu) {
    std::size_t x = extract_x(cpu.current_opc);
    Byte kk = extract_mask(cpu.current_opc, kk_mask);

    cpu.m_gp[x] = kk;
    return Cpu::CpuStatus::CPU_OK;
}

// 7xkk - ADD Vx, byte
// Load the value of Vx + kk into Vx
Cpu::CpuStatus op_7nnn(Cpu &cpu) {
    std::size_t x = extract_x(cpu.current_opc);
    Byte kk = extract_mask(cpu.current_opc, kk_mask);

    cpu.m_gp[x] += kk;
    return Cpu::CpuStatus::CPU_OK;
}

// 8nnn - Performs oper based on least significant nibble
Cpu::CpuStatus op_8nnn(Cpu &cpu) {
    std::size_t x{extract_x(cpu.current_opc)};
    std::size_t y{extract_y(cpu.current_opc)};
    Byte n = extract_mask(cpu.current_opc, 0x000F);

    switch (n) {
    case 0x00:
        // 8xy0 - LD Vx, Vy
        // Load the value of Vy into Vx
        cpu.m_gp[x] = cpu.m_gp[y];
        break;
    case 0x01:
        // 8xy1 - OR Vx, Vy
        // Load the value of Vx | Vy into Vx
        cpu.m_gp[x] |= cpu.m_gp[y];
        break;
    case 0x02:
        // 8xy2 - AND Vx, Vy
        // Load the value of Vx & Vy into Vx
        cpu.m_gp[x] &= cpu.m_gp[y];
        break;
    case 0x03:
        // 8xy3 - XOR Vx, Vy
        // Load the value of Vx ^ Vy into Vx
        cpu.m_gp[x] ^= cpu.m_gp[y];
        break;
    case 0x04:
        // 8xy4 - ADD Vx, Vy
        // Load the value of Vx + Vy into Vx, VF = carry
        cpu.m_gp[0x0F] = (cpu.m_gp[x] + cpu.m_gp[y] > 0xFF) ? 0x01 : 0x00;
        cpu.m_gp[x] += cpu.m_gp[y];
        break;
    case 0x05:
        // 8xy5 - SUB Vx, Vy
        // Load the value of Vx - Vy into Vx, VF = !borrow
        cpu.m_gp[0x0F] = (cpu.m_gp[x] > cpu.m_gp[y]) ? 0x01 : 0x00;
        cpu.m_gp[x] -= cpu.m_gp[y];
        break;
    case 0x06:
        // 8xy6 - SHR Vx
        // Load the result of Vx / 2 into Vx, VF = LSB
        cpu.m_gp[0x0F] = extract_mask(cpu.current_opc, 0x0001);
        cpu.m_gp[x] >>= 0x01;
        break;
    case 0x07:
        // 8xy7 - SUBN Vx, Vy
        // Load the value of Vy - Vx into Vx, VF = !borrow
        cpu.m_gp[0x0F] = (cpu.m_gp[y] > cpu.m_gp[x]) ? 0x01 : 0x00;
        cpu.m_gp[x] = cpu.m_gp[y] - cpu.m_gp[x];
        break;
    case 0x0E:
        // 8xyE - SHL Vx
        // Load the result of Vx * 2 into Vx, VF = MSB
        cpu.m_gp[0x0F] = extract_mask(cpu.current_opc, 0x8000);
        cpu.m_gp[x] <<= 0x01;
        break;
    default:
        return Cpu::CpuStatus::CPU_BAD_OP;
    }

    return Cpu::CpuStatus::CPU_OK;
}

// 9xy0 - SNE Vx, Vy
// Skip next instruction if Vx != Vy
Cpu::CpuStatus op_9nnn(Cpu &cpu) {
    std::size_t x{extract_x(cpu.current_opc)};
    std::size_t y{extract_y(cpu.current_opc)};

    if (cpu.m_gp[x] != cpu.m_gp[y])
        cpu.m_pc += 2;

    return Cpu::CpuStatus::CPU_OK;
}

// Annn - LD I, nnn
// Load the value nnn into I
Cpu::CpuStatus op_Annn(Cpu &cpu) {
    Addr nnn = extract_mask(cpu.current_opc, nnn_mask);
    cpu.m_i = nnn;

    return Cpu::CpuStatus::CPU_OK;
}

// Bnnn - JP V0, nnn
// Jump to location V0 + nnn
Cpu::CpuStatus op_Bnnn(Cpu &cpu) {
    Addr nnn = extract_mask(cpu.current_opc, nnn_mask);
    cpu.m_pc = cpu.m_gp[0x00] + nnn;

    return Cpu::CpuStatus::CPU_OK;
}

// Cxkk - RND Vx, byte
// Load a randomized byte value & kk into Vx
Cpu::CpuStatus op_Cnnn(Cpu &cpu) {
    std::size_t x{extract_x(cpu.current_opc)};
    Byte kk = extract_mask(cpu.current_opc, kk_mask);

    std::mt19937 mt{};
    Byte rbyte = mt() % 0x100;

    cpu.m_gp[x] = rbyte & kk;
    return Cpu::CpuStatus::CPU_OK;
}

Cpu::CpuStatus op_Dnnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Ennn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
Cpu::CpuStatus op_Fnnn(Cpu &) { return Cpu::CpuStatus::CPU_OK; }
} // namespace chip8
