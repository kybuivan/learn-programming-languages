# C++ Standard Library headers
Giao diện (interface) của thư viện chuẩn C++ được định nghĩa bởi tập hợp các tiêu đề (headers) sau đây.

## Concepts library
- `<concepts>`(C++20): các khái niệm cơ bản của thư viện

## Coroutines library
- [`<coroutine>`]()(C++20): Coroutine support library

## Utilities library
- `<any>`(C++17): std::any class
- `<bitset>`: std::bitset class template
- `<chrono>`(C++11): C++ time utilities
- `<compare>`(C++20): Three-way comparison operator support
- `<csetjmp>`: Macro (and function) that saves (and jumps) to an execution context
- `<csignal>`: Functions and macro constants for signal management
- `<cstdarg>`: Handling of variable length argument lists
- `<cstddef>`: Standard macros and typedefs
- `<cstdlib>`: General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search
- `<ctime>`: C-style time/date utilities
- `<expected>`(C++23): std::expected class template
- `<functional>`: Function objects, Function invocations, Bind operations and Reference wrappers
- `<initializer_list>` (C++11): std::initializer_list class template
- `<optional>`(C++17): std::optional class template
- `<source_location>`(C++20): Supplies means to obtain source code location
- `<tuple>`(C++11): std::tuple class template
- `<type_traits>`(C++11): Compile-time type information
- `<typeindex>`(C++11): std::type_index
- `<typeinfo>`: Runtime type information utilities
- `<utility>`: Various utility components
- `<variant>`(C++17): std::variant class template
- `<version>`(C++20): Supplies implementation-dependent library information
### Dynamic memory management
- `<memory>`: High-level memory management utilities
- `<memory_resource>` (C++17): Polymorphic allocators and memory resources
- `<new>`: Low-level memory management utilities
- `<scoped_allocator>` (C++11): Nested allocator class
### Numeric limits
- `<cfloat>`: Limits of floating-point types
- `<cinttypes>` (C++11): Formatting macros, intmax_t and uintmax_t math and conversions
- `<climits>`: Limits of integral types
- `<cstdint>` (C++11): Fixed-width integer types and limits of other types
- `<limits>`: Uniform way to query properties of arithmetic types
- `<stdfloat>` (C++23): Optional extended floating-point types
### Error handling
- `<cassert>`: Conditionally compiled macro that compares its argument to zero
- `<cerrno>`: Macro containing the last error number
- `<exception>`: Exception handling utilities
- `<stacktrace>` (C++23): Stacktrace library
- `<stdexcept>`: Standard exception objects
- `<system_error>` (C++11): Defines std::error_code, a platform-dependent error code
## Strings library
- `<cctype>`: Functions to determine the category of narrow characters
- `<charconv>` (C++17): std::to_chars and std::from_chars
- `<cstring>`: Various narrow character string handling functions
- `<cuchar>` (C++11): C-style Unicode character conversion functions
- `<cwchar>`: Various wide and multibyte string handling functions
- `<cwctype>`: Functions to determine the category of wide characters
- `<format>` (C++20): Formatting library including std::format
- `<string>`: std::basic_string class template
- `<string_view>` (C++17): std::basic_string_view class template
## Containers library
- `<array>` (C++11): std::array container
- `<deque>`: std::deque container
- `<flat_map>` (C++23): std::flat_map and std::flat_multimap container adaptors
- `<flat_set>` (C++23): std::flat_set and std::flat_multiset container adaptors
- `<forward_list>` (C++11): std::forward_list container
- `<list>`: std::list container
- `<map>`: std::map and std::multimap associative containers
- `<mdspan>` (C++23): std::mdspan view
- `<queue>`: std::queue and std::priority_queue container adaptors
- `<set>`: std::set and std::multiset associative containers
- `<span>` (C++20): std::span view
- `<stack>`: std::stack container adaptor
- `<unordered_map>` (C++11): std::unordered_map and std::unordered_multimap unordered associative containers
- `<unordered_set>` (C++11): std::unordered_set and std::unordered_multiset unordered associative containers
- `<vector>`: std::vector container
## Iterators library
- `<iterator>`: Range iterators
## Ranges library
- `<generator>` (C++23): std::generator class template
- `<ranges>` (C++20): Range access, primitives, requirements, utilities, and adaptors
## Algorithms library
- `<algorithm>`: Algorithms that operate on ranges
- `<execution>` (C++17): Predefined execution policies for parallel versions of the algorithms
## Numerics library
- `<bit>` (C++20): Bit manipulation functions
- `<cfenv>` (C++11): Floating-point environment access functions
- `<cmath>`: Common mathematics functions
- `<complex>`: Complex number type
- `<numbers>` (C++20): Math constants
- `<numeric>`: Numeric operations on values in ranges
- `<random>` (C++11): Random number generators and distributions
- `<ratio>` (C++11): Compile-time rational arithmetic
- `<valarray>`: Class for representing and manipulating arrays of values
## Localization library
- `<clocale>`: C localization utilities
- `<codecvt>` (C++11, deprecated in C++17): Unicode conversion facilities
- `<locale>`: Localization utilities
## Input/output library
- `<cstdio>`: C-style input-output functions
- `<fstream>`: std::basic_fstream, std::basic_ifstream, std::basic_ofstream class templates, and several typedefs
- `<iomanip>`: Helper functions to control the format of input and output
- `<ios>`: std::ios_base class, std::basic_ios class template, and several typedefs
- `<iosfwd>`: Forward declarations of all classes in the input/output library
- `<iostream>`: Several standard stream objects
- `<istream>`: std::basic_istream class template and several typedefs
- `<ostream>`: std::basic_ostream, std::basic_iostream class templates, and several typedefs
- `<print>` (C++23): Formatted output library including std::print
- `<spanstream>` (C++23): std::basic_spanstream, std::basic_ispanstream, std::basic_ospanstream class templates, and typedefs
- `<sstream>`: std::basic_stringstream, std::basic_istringstream, std::basic_ostringstream class templates, and several typedefs
- `<streambuf>`: std::basic_streambuf class template
- `<strstream>` (deprecated in C++98): std::strstream, std::istrstream, std::ostrstream
- `<syncstream>` (C++20): std::basic_osyncstream, std::basic_syncbuf, and typedefs
## Filesystem library
- `<filesystem>` (C++17): std::path class and supporting functions
## Regular Expressions library
- `<regex>` (C++11): Classes, algorithms, and iterators to support regular expression processing
## Atomic Operations library
- `<atomic>` (C++11): Atomic operations library
## Thread support library
- `<barrier>`(C++20): rào cản
- `<condition_variable>`(C++11): điều kiện chờ của luồng
- `<future>`(C++11): nguyên tố cơ bản cho tính toán bất đồng bộ
- `<latch>`(C++20): latchs
- `<mutex>`(C++11): nguyên tố cơ bản cho khóa chung (Mutual exclusion primitives)
- `<semaphore>`(C++20): hàng ngăn (Semaphores)
- `<shared_mutex>`(C++14): nguyên tố cơ bản cho khóa chung dùng chia sẻ (Shared mutual exclusion primitives)
- `<stop_token>`(C++20): stop token cho std::jthread
- `<thread>`(C++11): lớp std::thread và các hàm hỗ trợ