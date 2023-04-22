#ifndef ARGS_HPP
#define ARGS_HPP

#include <mutex>
#include <variant>
#include <vector>

class Args {
  public:
    using Value = std::variant<int *, double *, bool *, std::string *>;

    Args(const Args &) = delete;
    Args &operator=(const Args &) = delete;

    static Args *instance();

  private:
    struct Arg {
        std::vector<std::string> m_flags;
        Value m_value;
        std::string m_help;
    };

    Args() = default;

    static Args *s_instance;
    static std::mutex s_mutex;
};

#endif
