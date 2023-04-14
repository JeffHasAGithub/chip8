#ifndef CHIP8_COMMON_HPP
#define CHIP8_COMMON_HPP

#include <cstdint>

namespace chip8 {
using byte_t = std::uint8_t;
using opcode_t = std::uint16_t;
using addr_t = std::uint16_t;
using oper_t = int (*)(opcode_t);

enum class chip8_status_t {
    CHIP8_OK,
    CHIP8_ERR,
};

enum class cpu_status_t {
    CPU_OK,
    CPU_ERR,
};

inline constexpr int mem_sz{0x1000};
inline constexpr int prog_init{0x200};
inline constexpr int n_regs{0x10};
} // namespace chip8

#endif
