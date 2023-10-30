// https://en.cppreference.com/w/cpp/filesystem

#include <cstdlib>
#include <filesystem>
#include <iostream>

int main()
{
    std::cout << "temporary dir: " << std::filesystem::temp_directory_path() << std::endl;
    std::cout << "current dir: " << std::filesystem::current_path() << std::endl;

    return 0;
}
