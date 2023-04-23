#include "log.hpp"

namespace chip8 {
Log *Log::s_instance{nullptr};

void Log::write(std::string_view sv) {
    m_ostream << sv;
}

void Log::writeln(std::string_view sv) {
    m_ostream << sv << '\n';
}

Log *Log::instance(std::ostream &out) {
    if (s_instance == nullptr)
        s_instance = new Log(out);
    return s_instance;
}
} // namespace chip8
