set_property(DIRECTORY PROPERTY LABELS 14)

file(READ thread_count.cpp src)
check_source_compiles(CXX "${src}" cpp14_thread)

check_cxx_symbol_exists(__cpp_lib_make_unique "memory" cpp14_make_unique)


set(names
  make_unique
)

foreach(t IN ITEMS ${names})
  if(cpp14_${t})
    add_executable(${t} ${t}.cpp)
    add_test(NAME ${t} COMMAND ${t})
  endif()
endforeach()

if(cpp14_thread)
  add_executable(thread_count thread_count.cpp)
  add_test(NAME thread COMMAND thread_count)
endif()
