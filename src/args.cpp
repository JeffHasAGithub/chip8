#include "args.hpp"
#include <iostream>

namespace chip8 {
Args *Args::s_instance{nullptr};
std::mutex Args::s_mutex{};

void Args::add(const std::vector<std::string> &flags, const Value &val,
               const std::string &help) {
    m_args.push_back(Arg{flags, val, help});
}

void Args::parse(int argc, char *argv[]) {
    for (int i{0}; i < argc; ++i) {
        std::string flag{argv[i]};
        std::string val{};

        std::size_t sep_pos = flag.find('=');
        if (sep_pos != std::string::npos) {
            val = flag.substr(sep_pos + 1);
            flag = flag.substr(0, sep_pos);
        }

        for (auto const &arg : m_args) {
            if (std::find(arg.m_flags.begin(), arg.m_flags.end(), flag) !=
                arg.m_flags.end()) {

                if (std::holds_alternative<bool*>(arg.m_value)) {
                    if (val.empty() || val == "true" || val == "false")
                        *std::get<bool*>(arg.m_value) = (val != "false");
                } else if (std::holds_alternative<std::string*>(arg.m_value)) {
                    *std::get<std::string*>(arg.m_value) = val;
                } else {
                    std::visit(
                        [&val](auto&& arg) {
                            std::stringstream ss{val};
                            ss >> *arg;
                        },
                        arg.m_value
                    );
                }
            }
        }
    }
}

Args *Args::instance() {
    std::lock_guard<std::mutex> lock{s_mutex};
    if (s_instance == nullptr)
        s_instance = new Args();
    return s_instance;
}
} // namespace chip8
