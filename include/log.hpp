#ifndef CHIP8_LOG_HPP
#define CHIP8_LOG_HPP

#include <iostream>
#include <string_view>

namespace chip8 {
class Log {
  public:
    Log(const Log &log) = delete;
    Log &operator=(const Log &log) = delete;

    void error(const std::string &msg);
    void info(const std::string &msg);
    void warn(const std::string &msg);

    static Log *instance(std::ostream &out = std::cout);

  private:
    Log(std::ostream &out) : m_ostream{out} {};

    void write(const std::string &msg);

    std::ostream &m_ostream;
    static Log *s_instance;
};
} // namespace chip8

#endif
