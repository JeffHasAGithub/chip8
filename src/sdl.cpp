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

Sdl::~Sdl() {
    // m_surface is freed with m_window
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

Sdl::SdlStatus Sdl::run() {
    SDL_Event ev;
    bool done = false;

    while (!done) {
       while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT)
                done = true;
       }

       SDL_FillRect(m_surface, nullptr, SDL_MapRGB(m_surface->format, 0xFF, 0xFF, 0xFF));
       SDL_UpdateWindowSurface(m_window);
    }

    return Sdl::SDL_OK;
}

Sdl *Sdl::instance(const std::string& title, int w_width, int w_height) {
    if (s_instance == nullptr)
        s_instance = new Sdl(title, w_width, w_height);
    return s_instance;
}
} // namespace chip8
