// https://en.cppreference.com/w/cpp/utility/variant

#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<int, float, std::string> myVariant;

    // Assigning an int to the variant
    myVariant = 42;
    std::cout << "Value of myVariant: " << std::get<int>(myVariant) << std::endl;

    // Assigning a float to the variant
    myVariant = 3.14f;
    std::cout << "Value of myVariant: " << std::get<float>(myVariant) << std::endl;

    // Assigning a string to the variant
    myVariant = "Hello, variant!";
    std::cout << "Value of myVariant: " << std::get<std::string>(myVariant) << std::endl;

    // Trying to access the variant with the wrong type
    try
    {
        std::cout << std::get<int>(myVariant) << std::endl;
    }
    catch (const std::bad_variant_access &ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
