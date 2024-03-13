#include "emulator.h"
#include "preprocessor.h"

void start_program(const std::string &filename) {
    Memory memory;
    run_program(memory, filename);
}