// https://en.cppreference.com/w/cpp/language/function#Deleted_functions

#include <iostream>

// Example 1: Deleting a member function
class MyClass
{
public:
    void foo() = delete; // Deleted member function

    void bar()
    {
        std::cout << "Called bar()" << std::endl;
    }
};

// Example 2: Deleting a non-member function template
template <typename T>
void process(T value)
{
    std::cout << "Processing value: " << value << std::endl;
}

template <>
void process<double>(double) = delete; // Deleted template specialization

struct sometype
{
    void *operator new(std::size_t) = delete;
    void *operator new[](std::size_t) = delete;
};

int main()
{
    // Example 1: Using deleted member function
    MyClass obj;
    // obj.foo(); // Uncommenting this line will result in a compilation error
    obj.bar(); // Calling non-deleted member function

    std::cout << std::endl;

    // Example 2: Using deleted non-member function template
    process(10); // Calling process() with int value
    // process(3.14); // Uncommenting this line will result in a compilation error

    // sometype *p = new sometype; // error: attempts to call deleted sometype::operator new

    return 0;
}
