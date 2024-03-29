set_property(DIRECTORY PROPERTY LABELS 23)

if(NOT DEFINED cpp23_assume)
message(STATUS "Checking for C++23 features with CMAKE_REQUIRED_FLAGS: ${CMAKE_REQUIRED_FLAGS}")
endif()

check_source_compiles(CXX
"#if !__has_cpp_attribute(assume)
#error \"no assume attribute\"
#endif
int main(){ return 0; }"
cpp23_assume
)

check_cxx_symbol_exists(__cpp_lib_print "version" cpp23_print)
check_cxx_symbol_exists(__cpp_lib_expected "version" cpp23_expected)
check_include_file_cxx(stdfloat cpp23_stdfloat)
check_cxx_symbol_exists(__cpp_lib_unreachable "version" cpp23_unreachable)

set(names
  cpp23_assume
  cpp23_expected
  cpp23_print
  cpp23_stdfloat
)

foreach(t IN ITEMS ${names})
  if(${t})
    add_executable(${t} ${t}.cpp)
    add_test(NAME ${t} COMMAND ${t})
  endif()
endforeach()


if(cpp23_unreachable)
  add_executable(cpp23_unreachable cpp23_unreachable.cpp)
  add_test(NAME cpp23_unreachable
    COMMAND ${CMAKE_COMMAND} -Dexe:FILEPATH=$<TARGET_FILE:cpp23_unreachable> -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/will_fail.cmake)
  set_property(TEST cpp23_unreachable PROPERTY WILL_FAIL TRUE)
endif()


if(TEST expected)
  set_property(TEST expected PROPERTY PASS_REGULAR_EXPRESSION "42")
endif()
