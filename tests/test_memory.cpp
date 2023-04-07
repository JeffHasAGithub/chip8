#ifndef CHIP8_TEST_MEMORY_H
#define CHIP8_TEST_MEMORY_H

#include <catch2/catch.hpp>
#include <stdexcept>

#include "memory.hpp"

TEST_CASE("constructors", "[memory]") {
    int dv = 0xFF;
    chip8::Memory<int, 3> mem{dv};

    auto it = mem.begin(), stop = mem.end();
    for (; it != stop; ++it)
        REQUIRE(*it == dv);
}

TEST_CASE("subscript operators", "[memory]") {
    chip8::Memory<int, 3> mem;
    chip8::Memory<int, 3> cmem;

    SECTION("throws 'out of range' exceptions") {
        REQUIRE_THROWS_AS(mem[4], std::out_of_range);
        REQUIRE_THROWS_AS(cmem[4], std::out_of_range);
    }
}

#endif
