#include "stack.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("push onto stack", "[stack]") {
    chip8::Stack<int, 8> stck{};

    // stack pointer updates on each push
    for (std::size_t i{0}; i < stck.size(); ++i) {
        stck.push(i);
        REQUIRE(stck.sp() == stck.size() - i - 1);
    }
    
    // exception is thrown when push occurs at stack limit
    REQUIRE_THROWS(stck.push(1));
}

TEST_CASE("pop off of stack", "[stack]") {
    chip8::Stack<int, 8> stck{};

    for (std::size_t i{0}; i < stck.size(); ++i)
        stck.push(i);

    // stack pointer updates on each pop
    for (std::size_t i{0}; i < stck.size(); ++i) {
        REQUIRE(stck.sp() == i);
        stck.pop();
    }
    // exception is thrown when pop occurs at the bottom of the stack
    REQUIRE_THROWS(stck.pop());
}
