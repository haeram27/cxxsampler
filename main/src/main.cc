#include <iostream>
#include "util/pipe.h"

int main () {
    std::cout << R"(readlink /proc/1/exe:)" << std::endl;
    std::cout << util::pipe::pexec(R"(readlink /proc/1/exe)") << std::endl;
    return 0;
}
