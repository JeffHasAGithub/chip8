#include "args.hpp"

namespace chip8 {
Args *Args::s_instance{nullptr};
std::mutex Args::s_mutex{};

void Args::add(const std::vector<std::string> &flags, const Value &val,
               const std::string &help) {
    m_args.push_back(Arg{flags, val, help});
}

Args *Args::instance() {
    std::lock_guard<std::mutex> lock{s_mutex};
    if (s_instance == nullptr)
        s_instance = new Args();
    return s_instance;
}
} // namespace chip8
