// https://en.cppreference.com/w/cpp/language/reference#Rvalue_references

#include <iostream>
#include <utility>

void f(int &x)
{
    std::cout << "lvalue reference overload f(" << x << ")\n";
}

void f(const int &x)
{
    std::cout << "lvalue reference to const overload f(" << x << ")\n";
}

void f(int &&x)
{
    std::cout << "rvalue reference overload f(" << x << ")\n";
}

int main()
{
    int i = 1;
    const int ci = 2;

    f(i);            // calls f(int&)
    f(ci);           // calls f(const int&)
    f(3);            // calls f(int&&)
                     // would call f(const int&) if f(int&&) overload wasn't provided
    f(std::move(i)); // calls f(int&&)

    // rvalue reference variables are lvalues when used in expressions
    int &&x = 1;
    f(x);            // calls f(int& x)
    f(std::move(x)); // calls f(int&& x)

    return 0;
}
