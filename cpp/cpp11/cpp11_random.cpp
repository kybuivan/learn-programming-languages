// https://en.cppreference.com/w/cpp/numeric/random

#include <cassert>
#include <random>
 
int main()
{
    std::mt19937 gen32;
    std::mt19937_64 gen64;
 
    gen32.discard(10'000 - 1);
    gen64.discard(10'000 - 1);
 
    assert(gen32() == 4'123'659'995);
    assert(gen64() == 9'981'545'732'273'789'042ull);
    return 0;
}