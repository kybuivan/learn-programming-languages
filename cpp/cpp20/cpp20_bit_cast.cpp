// https://en.cppreference.com/w/cpp/numeric/bit_cast

#include <bit>
#include <cstdint>
#include <iostream>

constexpr double f64v = 19880124.0;
constexpr auto u64v = std::bit_cast<std::uint64_t>(f64v);
static_assert(std::bit_cast<double>(u64v) == f64v); // round-trip

constexpr std::uint64_t u64v2 = 0x3fe9000000000000ull;
constexpr auto f64v2 = std::bit_cast<double>(u64v2);
static_assert(std::bit_cast<std::uint64_t>(f64v2) == u64v2); // round-trip

int main()
{
    std::cout << "std::bit_cast<std::uint64_t>(" << std::fixed << f64v << ") == 0x" << std::hex << u64v << '\n'
              << "std::bit_cast<double>(0x" << std::hex << u64v2 << ") == " << std::fixed << f64v2 << '\n';

    return 0;
}
