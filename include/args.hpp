#ifndef CHIP8_ARGS_HPP
#define CHIP8_ARGS_HPP

#include <algorithm>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <variant>
#include <vector>

namespace chip8 {
class ArgsException : public std::runtime_error {
  public:
    ArgsException(const std::string &msg) : std::runtime_error{msg} {};
};

class Args {
  public:
    using Value = std::variant<int *, double *, bool *, std::string *>;

    Args(const Args &) = delete;
    Args &operator=(const Args &) = delete;

    void add(const std::vector<std::string> &flags, const Value &val,
             const std::string &help);
    void clear();
    void parse(int argc, char *argv[]);

    static Args *instance();

  private:
    struct Arg {
        std::vector<std::string> m_flags;
        Value m_value;
        std::string m_help;
    };

    Args() = default;

    std::vector<Arg> m_args{};

    static Args *s_instance;
    static std::mutex s_mutex;
};
} // namespace chip8

#endif
