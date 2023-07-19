// https://en.cppreference.com/w/cpp/language/templates

#include <array>
#include <iostream>

// Case 1: ParamType is a Reference
template <typename T>
void f1(T &param)
{
    // param is an lvalue reference
    std::cout << "param is a reference to " << typeid(param).name() << std::endl;
}

// Case 2: ParamType is a Universal Reference
template <typename T>
void f2(T &&param)
{
    // param is a universal reference
    std::cout << "param is a universal reference to " << typeid(param).name() << std::endl;
}

// Case 3: ParamType is Neither a Pointer nor a Reference
template <typename T>
void f3(T param)
{
    // param is passed by value
    std::cout << "param is passed by value: " << typeid(param).name() << std::endl;
}

// Array Argument Example
template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

// Function Argument Example
void someFunc(int, double);

template <typename T>
void f(T param)
{
    // param is passed by value
    std::cout << "param is passed by value: " << typeid(param).name() << std::endl;
}

template <typename T>
void g(T &param)
{
    // param is a reference
    std::cout << "param is a reference to " << typeid(param).name() << std::endl;
}

int main()
{
    int x = 27;
    const int cx = x;
    const int &rx = x;

    // Case 1: ParamType is a Reference
    f1(x);
    f1(cx);
    f1(rx);

    // Case 2: ParamType is a Universal Reference
    f2(x);
    f2(cx);
    f2(rx);
    f2(27);

    // Case 3: ParamType is Neither a Pointer nor a Reference
    f3(x);
    f3(cx);
    f3(rx);
    f3(27);

    const char name[] = "J. P. Briggs";

    // Array Argument Example
    f(name);
    g(name);

    int keyVals[] = {1, 3, 7, 9, 11, 22, 35};

    std::cout << "Number of elements in keyVals: " << arraySize(keyVals) << std::endl;

    return 0;
}
