// https://en.cppreference.com/w/cpp/utility/program/getenv

#include <cstdlib>
#include <iostream>


int main()
{

#ifdef _WIN32
    auto k = "USERPROFILE";
#else
    auto k = "HOME";
#endif

    auto home_dir = std::getenv(k);
    if (!home_dir)
    {
        std::cerr << "getenv(" << k << ") failed" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "home directory: " << home_dir << std::endl;

    return 0;
}
