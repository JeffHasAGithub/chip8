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

namespace chip8 {
class Sdl {
  public:
    Sdl(const Sdl &sdl) = delete;
    Sdl &operator=(const Sdl &sdl) = delete;

    static Sdl *instance();

  private:
    Sdl(int width, int height) : m_width{width}, m_height{height} {};

    int m_width;
    int m_height;
    static Sdl *s_instance;
};
} // namespace chip8

#endif
