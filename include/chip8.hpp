#ifndef CHIP8_HPP
#define CHIP8_HPP

#include "constants.hpp"
#include "cpu.hpp"
#include "memory.hpp"

namespace chip8 {
enum status_t {
    CHIP8_OK,
    CHIP8_ERR,
};
} // namespace chip8

#endif
