#ifndef ARGS_HPP
#define ARGS_HPP

#include <mutex>
#include <variant>
#include <vector>

namespace chip8 {
class Args {
  public:
    using Value = std::variant<int *, double *, bool *, std::string *>;

    Args(const Args &) = delete;
    Args &operator=(const Args &) = delete;

    void add(const std::vector<std::string> &flags, const Value &val,
             const std::string &help);
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
