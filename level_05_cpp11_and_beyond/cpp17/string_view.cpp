// https://en.cppreference.com/w/cpp/string/basic_string_view

#include <iostream>
#include <string_view>

int main()
{
    constexpr std::string_view unicode[]{"▀▄─", "▄▀─", "▀─▄", "▄─▀"};

    for (int y{}, p{}; y != 6; ++y, p = ((p + 1) % 4))
    {
        for (int x{}; x != 16; ++x)
            std::cout << unicode[p];
        std::cout << '\n';
    }

    return 0;
}
