/**
 * @file sdl.hpp
 *
 * The Sdl class utilizes the singleton pattern
 * to provide a readily accessible object for
 * accessing the various multimedia subsystems
 * including video, audio, and input.
 */

#ifndef CHIP8_SDL_HPP
#define CHIP8_SDL_HPP

#include "except.hpp"
#include <SDL2/SDL.h>

namespace chip8 {
class SdlException : public Exception {
  public:
    SdlException(const std::string &msg, int err_c) : Exception{msg, err_c} {};
};

class Sdl {
  public:
    enum SdlStatus {
        SDL_OK,
        SDL_ERR,
    };

    ~Sdl();

    Sdl(const Sdl &sdl) = delete;
    Sdl &operator=(const Sdl &sdl) = delete;

    static Sdl *instance(const std::string& title, int width, int height);

  private:
    Sdl(const std::string& title, int width, int height);

    int m_width;
    int m_height;
    SDL_Window* m_window{nullptr};
    SDL_Surface* m_surface{nullptr};

    static Sdl *s_instance;
};
} // namespace chip8

#endif
