// https://en.cppreference.com/w/cpp/error/system_error

#include <iostream>
#include <system_error>
#include <thread>
 
int main()
{
    try
    {
        std::thread().detach(); // attempt to detach a non-thread
    }
    catch(const std::system_error& e)
    {
        std::cout << "Caught system_error with code "
                     "[" << e.code() << "] meaning "
                     "[" << e.what() << "]\n";
    }
    return 0;
}