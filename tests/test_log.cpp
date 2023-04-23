#include <catch2/catch.hpp>
#include <stdexcept>
#include <sstream>

#include "log.hpp"
using namespace chip8;

TEST_CASE("Log: adheres to singleton pattern", "[log]") {
    SECTION("creates singleton on first invocation") {
        Log *log = Log::instance();
        REQUIRE(log != nullptr);
    }

    SECTION("multiple invocations for Log::instance() returns same pointer") {
        Log *args = Log::instance();
        REQUIRE(args == Log::instance());
    }
}
