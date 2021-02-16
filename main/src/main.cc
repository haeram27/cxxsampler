#include <iostream>
#include <string>
#include "util/pipe.h"

int main () {
    std::string name {"init"};
    std::cout << R"(ps hocomm 1:)" << std::endl;
    std::cout << util::pipe::pexec(R"(ps hocomm 1)") << std::endl;
    std::cout << (name.compare(util::pipe::pexec(R"(ps hocomm 1)"))) << std::endl;
    std::cout << ((util::pipe::pexec(R"(ps hocomm 1)")).find("init") != std::string::npos) << std::endl;

    return 0;
}
