#include "args.hpp"

Args *Args::s_instance{nullptr};
std::mutex Args::s_mutex{};
