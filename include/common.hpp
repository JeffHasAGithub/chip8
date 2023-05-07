/**
 * @file common.hpp
 *
 * A set of common types and constants to
 * be used throughout the project. It cannot
 * include any project level header files.
 *
 */

#ifndef CHIP8_COMMON_HPP
#define CHIP8_COMMON_HPP

#include <cstdint>

namespace chip8 {
using Byte = std::uint8_t;
using Addr = std::uint16_t;

inline constexpr int mem_sz{0x1000};
inline constexpr int stk_sz{0x10};
inline constexpr int prog_init{0x200};
inline constexpr int prog_end{0x600};
inline constexpr int n_regs{0x10};
} // namespace chip8

#endif
