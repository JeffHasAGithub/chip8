#include "args.hpp"

Args *Args::s_instance{nullptr};
std::mutex Args::s_mutex{};

Args *Args::instance() {
    std::lock_guard<std::mutex> lock{s_mutex};
    if (s_instance == nullptr)
        s_instance = new Args();
    return s_instance;
}
