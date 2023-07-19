// https://en.cppreference.com/w/cpp/header/ratio

#include <iostream>
#include <ratio>

int main()
{
    using two_third = std::ratio<2, 3>;
    using one_sixth = std::ratio<1, 6>;
    using sum = std::ratio_add<two_third, one_sixth>;

    std::cout << "2/3 + 1/6 = " << sum::num << '/' << sum::den << '\n';
    return 0;
}
