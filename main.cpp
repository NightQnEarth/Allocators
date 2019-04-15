#include <iostream>
#include "RunTests.h"

#define TESTING

int main(int argc, char* argv[])
{
#ifdef TESTING

    return TestsRunner::run_tests(argc, argv);

#endif

    std::cout << "Hello, world!" << std::endl;

    return 0;
}
