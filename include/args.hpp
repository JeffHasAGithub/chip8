#ifndef ARGS_HPP
#define ARGS_HPP

#include <mutex>

class Args {
  public:
    Args(const Args &) = delete;
    Args &operator=(const Args &) = delete;

    static Args *instance(int argc, char *argv[]);

  private:
    Args();
    Args(int argc, char *argv[]);

    static Args *s_instance;
    static std::mutex s_mutex;
};

#endif
