#include "bits.hpp"

namespace chip8 {
namespace bits {
std::size_t extract(std::size_t val, std::size_t mask) {
    return val & mask;
}

std::size_t on(std::size_t val, std::size_t mask) {
    return val | mask;
}

std::size_t off(std::size_t val, std::size_t mask) {
    return val & ~mask;
}

std::size_t flip(std::size_t val, std::size_t mask) {
    return val ^ mask;
}
} // namespace bits
} // namespace chip8
