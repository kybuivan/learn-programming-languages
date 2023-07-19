// https://en.cppreference.com/w/cpp/language/auto

#include <initializer_list>
#include <iostream>
#include <vector>


template <typename T>
void printType(const T &value)
{
    std::cout << "Type: " << typeid(value).name() << '\n';
}

// Case 1: The type specifier is a pointer or reference, but not a universal reference.
auto func_for_x(int param)
{
    printType(param);
    // Function for deducing x's type
}

// Case 3: The type specifier is neither a pointer nor a reference.
auto func_for_cx(const int param)
{
    printType(param);
    // Function for deducing cx's type
}

// Case 1: The type specifier is a pointer or reference, but not a universal reference.
auto func_for_rx(const int &param)
{
    printType(param);
    // Function for deducing rx's type
}

int main()
{
    int x = 27;
    const int cx = x;
    const int &rx = x;

    // Case 1: The type specifier is a pointer or reference, but not a universal reference.
    func_for_x(x);   // conceptual call: param's deduced type is x's type
    func_for_cx(cx); // conceptual call: param's deduced type is cx's type
    func_for_rx(rx); // conceptual call: param's deduced type is rx's type

    // Case 2: The type specifier is a universal reference.
    // auto &&uref1 = x;  // x is int and lvalue, so uref1's type is int&
    // auto &&uref2 = cx; // cx is const int and lvalue, so uref2's type is const int&
    // auto &&uref3 = 27; // 27 is int and rvalue, so uref3's type is int&&

    // Array Example
    // const char name[] = "R. N. Briggs";
    // auto arr1 = name;  // arr1's type is const char*
    // auto &arr2 = name; // arr2's type is const char (&)[13]

    // Function Example
    // void someFunc(int, double);
    // auto func1 = someFunc;  // func1's type is void (*)(int, double)
    // auto &func2 = someFunc; // func2's type is void (&)(int, double)

    // Braced Initializer Example
    // auto x1 = 27;   // type is int, value is 27
    // auto x2(27);    // type is int, value is 27
    // auto x3 = {27}; // type is std::initializer_list<int>, value is { 27 }
    // auto x4{27};    // type is std::initializer_list<int>, value is { 27 }

    // Error: Can't deduce type for std::initializer_list<T>
    // auto x5 = { 1, 2, 3.0 };
    return 0;
}
