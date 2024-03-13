#include "include/Stack.h"
#include "emulator.h"


int main(int argc, char *argv[]) {
    std::string filename = argv[1];
    start_program(filename);
}
