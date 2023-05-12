#include "chip8.hpp"

#include <iostream>

namespace chip8 {
Chip8Status run(int argc, char *argv[]) {
    Args *args{Args::instance()};
    Log *log{Log::instance()};

    Sdl *sdl{Sdl::instance("Chip8", 640, 480)};
    sdl->run();

    return Chip8Status::CHIP8_OK;
}
} // namespace chip8
