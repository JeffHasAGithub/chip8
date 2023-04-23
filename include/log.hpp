#ifndef CHIP8_LOG_HPP
#define CHIP8_LOG_HPP

#include <iostream>
#include <string_view>

namespace chip8 {
class Log {
  public:
    Log(const Log &log) = delete;
    Log &operator=(const Log &log) = delete;

    void write(std::string_view sv);
    void writeln(std::string_view sv);

    static Log *instance(std::ostream &out = std::cout);

  private:
    Log(std::ostream &out) : m_ostream{out} {};

    std::ostream &m_ostream;
    static Log *s_instance;
};
} // namespace chip8

#endif
