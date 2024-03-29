set_property(DIRECTORY PROPERTY LABELS 20)

if(HAVE_MODULES)
  add_subdirectory(cpp20_module)
endif()

check_cxx_symbol_exists(__cpp_lib_coroutine "version" cpp20_coroutine)
check_cxx_symbol_exists(__cpp_lib_math_constants "version" cpp20_numbers)
check_cxx_symbol_exists(__cpp_lib_source_location "version" cpp20_source_location)

check_cxx_symbol_exists(__cpp_lib_barrier "barrier" cpp20_barrier)
check_cxx_symbol_exists(__cpp_lib_concepts "concepts" cpp20_concepts)
check_cxx_symbol_exists(__cpp_lib_latch "latch" cpp20_latch)
check_cxx_symbol_exists(__cpp_lib_bit_cast "bit" cpp20_bit_cast)
check_cxx_symbol_exists(__cpp_lib_ranges "ranges" cpp20_ranges)
check_cxx_symbol_exists(__cpp_lib_span "span" cpp20_span)

check_source_compiles(CXX
"#if !__has_cpp_attribute(likely)
#error \"no likely attribute\"
#endif
int main(){ return 0; }"
cpp20_likely
)

check_source_compiles(CXX
"#include <algorithm>
int main(){
    const int n = 3;
    const auto v = {4, 1, 3, 2};

    std::ranges::find(v, n);
    return 0;
}"
cpp20_ranges_find
)

set(names
  cpp20_barrier
  cpp20_bit_cast
  cpp20_concepts
  cpp20_latch
  cpp20_likely
  cpp20_numbers
  cpp20_ranges_find
  cpp20_ranges
  cpp20_source_location
  cpp20_span
)

foreach(t IN ITEMS ${names})
  if(${t})
    add_executable(${t} ${t}.cpp)
    add_test(NAME ${t} COMMAND ${t})
  endif()
endforeach()

if(cpp20_coroutine)
  add_subdirectory(cpp20_coroutine)
endif()
