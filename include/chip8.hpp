/**
 * @file chip8.hpp
 *
 * The top-level header file for the project.
 * It includes all other local header files
 * and it is the only file to be included in
 * 'main'.
 */

#ifndef CHIP8_HPP
#define CHIP8_HPP

#include "args.hpp"
#include "common.hpp"
#include "cpu.hpp"
#include "log.hpp"
#include "memory.hpp"
#include "sdl.hpp"

namespace chip8 {
enum Chip8Status {
    CHIP8_OK,
    CHIP8_ERR,
};

/**
 * The only function to be called from 'main'.
 * All runtime exceptions must be handled here
 * if not earlier.
 *
 * @param argc program argument count
 * @param argv program arguments
 *
 * @return The status code to be passed for 'main'
 * to return to the OS.
 */
Chip8Status run(int argc, char *argv[]);
} // namespace chip8

#endif
