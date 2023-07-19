// https://en.cppreference.com/w/cpp/container/array

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>

int main()
{
    // construction uses aggregate initialization
    std::array<int, 3> a1{{1, 2, 3}};  // double-braces required in C++11 prior to
                                       // the CWG 1270 revision (not needed in C++11
                                       // after the revision and in C++14 and beyond)

    std::array<int, 3> a2 = {1, 2, 3}; // double braces never required after =

    std::array<std::string, 2> a3 = {std::string("a"), "b"};

    // container operations are supported
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << '\n';

    // ranged for loop is supported
    for (const auto &s : a3)
        std::cout << s << ' ';

    return 0;
}
