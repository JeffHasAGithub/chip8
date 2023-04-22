#include <catch2/catch.hpp>
#include <stdexcept>

#include "args.hpp"

TEST_CASE("adheres to singleton pattern", "[args]") {
    SECTION("Args::instance() creates singleton on first invocation") {
        Args *args = Args::instance();
        REQUIRE(args != nullptr);
    }

    SECTION("multiple invocations for Args::instance() returns same pointer") {
        Args *args = Args::instance();
        REQUIRE(args == Args::instance());
    }
}
