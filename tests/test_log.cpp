#include <catch2/catch.hpp>
#include <stdexcept>

#include "log.hpp"
using namespace chip8;

TEST_CASE("Log: adheres to singleton pattern", "[log]") {
    SECTION("Log::instance() creates singleton on first invocation") {
        Log *log = Log::instance();
        REQUIRE(log != nullptr);
    }

    SECTION("Log: multiple invocations for Log::instance() returns same pointer") {
        Log *args = Log::instance();
        REQUIRE(args == Log::instance());
    }
}
