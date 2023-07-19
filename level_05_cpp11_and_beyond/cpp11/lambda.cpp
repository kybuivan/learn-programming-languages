// https://en.cppreference.com/w/cpp/language/lambda

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> c{1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i) { std::cout << i << ' '; });
    std::cout << '\n';

    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';

    constexpr int fib_max{8};
    std::cout << "Emulate `recursive lambda` calls:\nFibonacci numbers: ";
    auto nth_fibonacci = [](int n) {
        std::function<int(int, int, int)> fib = [&](int n, int a, int b) { return n ? fib(n - 1, a + b, a) : b; };
        return fib(n, 0, 1);
    };

    for (int i{1}; i <= fib_max; ++i)
        std::cout << nth_fibonacci(i) << (i < fib_max ? ", " : "\n");

    return 0;
}
