#include "chip8.hpp"

int main(int argc, char *argv[]) {
    return static_cast<int>(chip8::run(argc, argv));
}
