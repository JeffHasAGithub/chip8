#ifndef ARGS_HPP
#define ARGS_HPP

#include <mutex>
#include <variant>

class Args {
  public:
    using Value = std::variant<int *, double *, bool *, std::string *>;

    Args(const Args &) = delete;
    Args &operator=(const Args &) = delete;

    static Args *instance();

  private:
    Args() = default;

    static Args *s_instance;
    static std::mutex s_mutex;
};

#endif
