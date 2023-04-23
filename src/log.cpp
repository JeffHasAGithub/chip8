#include "log.hpp"

namespace chip8 {
Log *Log::s_instance{nullptr};

void Log::write(const std::string &msg) {
    m_ostream << msg;
}

void Log::writeln(const std::string &msg) {
    write(msg + '\n');
}

void Log::error(const std::string &msg) {
    write("[ERROR] " + msg);
}

void Log::info(const std::string &msg) {
    write("[INFO] " + msg); 
}

void Log::warn(const std::string &msg) {
    write("[WARN] " + msg);
}

Log *Log::instance(std::ostream &out) {
    if (s_instance == nullptr)
        s_instance = new Log(out);
    return s_instance;
}
} // namespace chip8
