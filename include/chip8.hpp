#ifndef CHIP8_HPP
#define CHIP8_HPP

#include "args.hpp"
#include "common.hpp"
#include "cpu.hpp"
#include "memory.hpp"

namespace chip8 {
chip8_status_t run(int argc, char *argv[]);
} // namespace chip8

#endif
