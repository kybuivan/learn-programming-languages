#include <iostream>
#include <memory>
#include <unordered_map>

// Alias declaration using 'using'
using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;

// Typedef
typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS_Typedef;

int main()
{
    // Using the alias declaration
    UPtrMapSS map1 = std::make_unique<std::unordered_map<std::string, std::string>>();
    (*map1)["key1"] = "value1";
    (*map1)["key2"] = "value2";

    // Using the typedef
    UPtrMapSS_Typedef map2 = std::make_unique<std::unordered_map<std::string, std::string>>();
    (*map2)["key1"] = "value1";
    (*map2)["key2"] = "value2";

    // Printing the values from map1
    std::cout << "Values from map1:" << std::endl;
    for (const auto &pair : *map1)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Printing the values from map2
    std::cout << "Values from map2:" << std::endl;
    for (const auto &pair : *map2)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
