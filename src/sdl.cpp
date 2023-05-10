#include "sdl.hpp"

namespace chip8 {
Sdl *Sdl::s_instance{nullptr};

Sdl *Sdl::instance(int w_width, int w_height) {
    if (s_instance == nullptr)
        s_instance = new Sdl(w_width, w_height);
    return s_instance;
}
} // namespace chip8
