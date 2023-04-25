#include "chip8.hpp"

#include <iostream>

namespace chip8 {
chip8_status_t run(int argc, char *argv[]) {
    Args *args{Args::instance()};
    Log *log{Log::instance()};

    return chip8_status_t::CHIP8_OK;
}
} // namespace chip8
