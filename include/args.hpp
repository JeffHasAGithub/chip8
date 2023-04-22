#ifndef ARGS_HPP
#define ARGS_HPP

#include <mutex>

class Args {
  public:
    Args(const Args &) = delete;
    Args &operator=(const Args &) = delete;

    static Args *instance();

  private:
    Args();

    static Args *s_instance;
    static std::mutex s_mutex;
};

#endif
