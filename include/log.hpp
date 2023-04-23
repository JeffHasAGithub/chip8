#ifndef CHIP8_LOG_HPP
#define CHIP8_LOG_HPP

#include <iostream>

namespace chip8 {
class Log {
  public:
    Log(const Log &log) = delete;
    Log &operator=(const Log &log) = delete;

    static Log *instance(std::ostream &out = std::cout);

  private:
    Log(std::ostream &out) : m_ostream{out} {};

    std::ostream &m_ostream;
    static Log *s_instance;
};
} // namespace chip8

#endif
