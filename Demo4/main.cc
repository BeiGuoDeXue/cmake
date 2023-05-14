#include <iostream>
#include "math/MathFunctions.h"
#include "config.h"

#ifdef USE_MYMATH
    #include "math/MathFunctions.h"
#else
    #include <math.h>
#endif


int main() {
    std::cout << "Hello, World!" << std::endl;
#ifdef USE_MYMATH
    double ret = power(1, 2);
    std::cout << "USE MYMATH " << ret << std::endl;
#else
    double ret = pow(1, 2);
    std::cout << "NOT USE MYMATH " << ret << std::endl;
#endif

    return 0;
}
