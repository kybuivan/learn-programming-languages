#include <iostream>
#include <vector>

class Widget
{
public:
    Widget()
    {
        std::cout << "Default constructor called." << std::endl;
    }

    Widget([[maybe_unused]] const Widget &other)
    {
        std::cout << "Copy constructor called." << std::endl;
    }

    Widget &operator=([[maybe_unused]] const Widget &other)
    {
        std::cout << "Copy assignment operator called." << std::endl;
        return *this;
    }
};

int main()
{
    // int x(0);                     // initializer is in parentheses
    // int y = 0;                    // initializer follows "="
    // int z{0};                     // initializer is in braces
    // int w = {0};                  // initializer uses//
    // std::vector<int> v1{1, 3, 5}; // v1's initial content is 1, 3, 5

    Widget w1;      // call default constructor
    Widget w2 = w1; // not an assignment; calls copy ctor
    w1 = w2;        // an assignment; calls copy operator=

    return 0;
}
