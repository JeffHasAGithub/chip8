/**
 * @file except.hpp
 *
 * The Chip8Exception class provides a common
 * interface for all exceptions thrown from
 * the various emulator subsystems. It is a
 * child of the std::runtime_error class.
 */

#ifndef CHIP8_EXCEPT_HPP
#define CHIP8_EXCEPT_HPP

#include <stdexcept>

namespace chip8 {
class Exception : public std::runtime_error {
  public:
    Exception(const std::string &msg, int err_c = 0)
        : std::runtime_error{msg}, err_c{err_c} {};
    int err_c;
};
} // namespace chip8

#endif
