/**
 * @file args.hpp
 *
 * The Args class utilizes the singleton pattern
 * for parsing arguments and flags passed to the
 * program at runtime.
 *
 * Runtime errors are passed up the call stack
 * via an instance of the ArgsException class.
 */

#ifndef CHIP8_ARGS_HPP
#define CHIP8_ARGS_HPP

#include "except.hpp"

#include <algorithm>
#include <mutex>
#include <sstream>
#include <variant>
#include <vector>

namespace chip8 {
class ArgsException : public Exception {};

class Args {
  public:
    enum args_status_t {
        ARGS_OK,
        ARGS_ERR
    };

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
