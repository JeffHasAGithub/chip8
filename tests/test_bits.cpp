#include <catch2/catch.hpp>

#include "bits.hpp"
using namespace chip8;

TEST_CASE("Bits: turn on bits", "[bits]") {
    Bits bits{0xFF00};
    REQUIRE(bits.on(0xFF) == 0xFFFF);
}

TEST_CASE("Bits: turn off bits", "[bits]") {
    Bits bits{0xFFEE};
    REQUIRE(bits.off(0xFF00) == 0x00EE);
}

TEST_CASE("Bits: flip bits", "[bits]") {
    Bits bits{0xEF};
    REQUIRE(bits.flip(0xFF) == 0x10);
}

TEST_CASE("Bits: extract bits", "[bits]") {
    Bits bits{0xAABBCCDD};
    REQUIRE(bits.extract(0x00FF0000) == 0x00BB0000);
}
