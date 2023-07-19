// https://en.cppreference.com/w/cpp/utility/move

#include <iostream>
#include <string>
#include <utility>

class MyObject
{
public:
    MyObject(const std::string &str) : data(str)
    {
        std::cout << "Constructor: " << data << std::endl;
    }

    // Move constructor
    MyObject(std::string &&str) : data(std::move(str))
    {
        std::cout << "Move constructor: " << data << std::endl;
    }

    // Move assignment operator
    MyObject &operator=(std::string &&str)
    {
        data = std::move(str);
        std::cout << "Move assignment operator: " << data << std::endl;
        return *this;
    }

private:
    std::string data;
};

int main()
{
    std::string source = "Hello, World!";
    std::string newStr = "New String";

    // Using std::move to invoke the move constructor
    MyObject obj1(std::move(source));

    // Using std::move to invoke the move assignment operator
    obj1 = std::move(newStr);

    return 0;
}
