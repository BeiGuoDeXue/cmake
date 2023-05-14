#include <iostream>
#include "math/MathFunctions.h"
#include "config.h"

#ifdef HAVE_POW
    #include "math/MathFunctions.h"
#else
    #include <math.h>
#endif


int main() {
    std::cout << "Hello, World!" << std::endl;
#ifdef HAVE_POW
    double ret = power(1, 2);
    std::cout << "HAVE POW " << ret << std::endl;
#else
    double ret = pow(1, 2);
    std::cout << "NOT HAVE POW " << ret << std::endl;
#endif

    return 0;
}
