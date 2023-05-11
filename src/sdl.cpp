#include "sdl.hpp"

namespace chip8 {
Sdl *Sdl::s_instance{nullptr};

Sdl::Sdl(const std::string &title, int width, int height) : m_width{width}, m_height{height} {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw SdlException("Could not initialize SDL", SDL_ERR);

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            m_width, m_height, SDL_WINDOW_SHOWN);
    if (!m_window)
        throw SdlException("Could not create SDL window", SDL_ERR);

    m_surface = SDL_GetWindowSurface(m_window);
    if (!m_surface)
        throw SdlException("Could not create SDL surface", SDL_ERR);
}

Sdl *Sdl::instance(int w_width, int w_height) {
    if (s_instance == nullptr)
        s_instance = new Sdl(w_width, w_height);
    return s_instance;
}
} // namespace chip8
