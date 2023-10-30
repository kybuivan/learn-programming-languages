set_property(DIRECTORY PROPERTY LABELS 17)

check_cxx_symbol_exists(__cpp_fold_expressions "" cpp17_folding)
check_cxx_symbol_exists(__cpp_deduction_guides "" cpp17_deduction_guides)
check_cxx_symbol_exists(__cpp_lib_sample "algorithm" cpp17_sample)
check_cxx_symbol_exists(__cpp_structured_bindings "" cpp17_structured_bindings)

# NOTE: this is not a complete c++17 filesystem check:
check_cxx_symbol_exists(__cpp_lib_filesystem "filesystem" cpp17_filesystem)
check_cxx_symbol_exists(__cpp_lib_optional "optional" cpp17_optional)
check_cxx_symbol_exists(__cpp_lib_any "any" cpp17_any)
check_cxx_symbol_exists(__cpp_lib_string_view "string_view" cpp17_string_view)
check_cxx_symbol_exists(__cpp_lib_variant "variant" cpp17_variant)
check_cxx_symbol_exists(__cpp_lib_execution "execution" cpp17_execution)
check_cxx_symbol_exists(__cpp_lib_memory_resource "memory_resource" cpp17_memory_resource)

check_source_compiles(CXX
"#if !__has_cpp_attribute(maybe_unused)
#error \"no maybe_unused attribute\"
#endif
int main(){ return 0; }"
cpp17_maybe_unused
)

check_source_compiles(CXX
"#if !__has_cpp_attribute(fallthrough)
#error \"no fallthrough attribute\"
#endif
int main(){ return 0; }"
cpp17_fallthrough
)

check_source_compiles(CXX
"int main() {
  switch (int n = 1)
  case 1:
    return 0;
  return 0;
}"
cpp17_init_if_switch
)

set(names
  cpp17_any
  cpp17_deduction_guides
  cpp17_execution
  cpp17_fallthrough
  cpp17_filesystem
  cpp17_folding
  cpp17_init_if_switch
  cpp17_maybe_unused
  cpp17_memory_resource
  cpp17_optional
  cpp17_sample
  cpp17_string_view
  cpp17_structured_bindings
  cpp17_variant
)

foreach(t IN ITEMS ${names})
  if(${t})
    add_executable(${t} ${t}.cpp)
    add_test(NAME ${t} COMMAND ${t})
  endif()
endforeach()

if(TARGET filesystem)
  target_link_libraries(filesystem PRIVATE
  "$<$<CXX_COMPILER_ID:NVHPC>:stdc++fs;stdc++>"
  "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_LESS:$<CXX_COMPILER_VERSION>,9.1.0>>:stdc++fs;stdc++>"
  )
endif()
