#include <catch2/catch.hpp>
#include <stdexcept>

#include "args.hpp"
using namespace chip8;

char** setup_args(std::initializer_list<std::string> args) {
        char** argv = new char*[args.size()];
        for (unsigned i{0}; i < args.size(); ++i)
            argv[i] = const_cast<char*>((args.begin() + i)->c_str());
        return argv;
}

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

TEST_CASE("manages flags passed to it", "[args]") {
    int ival;
    double dval;
    bool bval;
    std::string sval;
    Args *args = Args::instance();

    SECTION("valid flags") {
        char** argv = setup_args({"test_prog", "-i=1", "--double=3.14", "-b", "-s=Hello"});

        args->add({"-i", "--int"}, &ival, "");
        args->add({"-d", "--double"}, &dval, "");
        args->add({"-b", "--bool"}, &bval, "");
        args->add({"-s", "--string"}, &sval, "");
        args->parse(5, argv);

        REQUIRE(ival == 1);
        REQUIRE(dval == 3.14);
        REQUIRE(bval == true);
        REQUIRE(sval == "Hello");
    }

    args->clear();

    SECTION("invalid flags") {
        char** argv = setup_args({"test_prog" "--double=3.14"});

        args->add({"-i", "--int"}, &ival, "");
        REQUIRE_THROWS(args->parse(2, argv));
    }
}
