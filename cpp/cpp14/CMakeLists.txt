set_property(DIRECTORY PROPERTY LABELS 14)

file(READ cpp14_thread.cpp src)
check_source_compiles(CXX "${src}" cpp14_thread)

check_cxx_symbol_exists(__cpp_lib_make_unique "memory" cpp14_make_unique)
check_cxx_symbol_exists(__cpp_lib_shared_mutex "shared_mutex" cpp14_shared_mutex)


set(names
  cpp14_deprecated
  cpp14_make_unique
  #cpp14_shared_mutex
  cpp14_thread
)

foreach(t IN ITEMS ${names})
  if(${t})
    add_executable(${t} ${t}.cpp)
    add_test(NAME ${t} COMMAND ${t})
  endif()
endforeach()
