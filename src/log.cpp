#include "log.hpp"

namespace chip8 {
Log *Log::s_instance{nullptr};

Log *Log::instance(std::ostream &out) {
    if (s_instance == nullptr)
        s_instance = new Log(out);
    return s_instance;
}
} // namespace chip8
