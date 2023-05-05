#include "chip8.hpp"

#include <iostream>

namespace chip8 {
Chip8Status run(int argc, char *argv[]) {
    Args *args{Args::instance()};
    Log *log{Log::instance()};

    return Chip8Status::CHIP8_OK;
}
} // namespace chip8
