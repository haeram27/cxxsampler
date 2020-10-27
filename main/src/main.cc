#include <iostream>
#include "util/time.h"

int main () {

    std::cout << util::time::GetCurrentRfc3339Time() << std::endl;
    return 0;
}
