set_property(DIRECTORY PROPERTY LABELS 11)

set(names
  cpp11_array
  cpp11_async
  cpp11_atomic
  cpp11_auto
  cpp11_bind
  cpp11_constexpr
  cpp11_constructor
  cpp11_current_exception
  cpp11_decltype
  cpp11_deleted_functions
  cpp11_default_constructor
  cpp11_enum
  cpp11_forward
  cpp11_future
  cpp11_getenv
  cpp11_lambda
  cpp11_move
  cpp11_mutex
  cpp11_noexcept
  cpp11_nullptr
  cpp11_override
  cpp11_packaged_task
  cpp11_promise
  cpp11_ratio
  cpp11_rvalue_references
  cpp11_shared_future
  cpp11_shared_ptr
  cpp11_template
  cpp11_thread
  cpp11_tuple
  cpp11_unique_ptr
  cpp11_using
  cpp11_weak_ptr
)

if(WIN32)
  list(APPEND names cpp11_GetLastError)
endif()

foreach(t IN LISTS names)
  add_executable(${t} ${t}.cpp)
  add_test(NAME ${t} COMMAND ${t})
endforeach()


if(TEST cpp11_GetLastError)
  set_property(TEST cpp11_GetLastError PROPERTY WILL_FAIL true)
endif()
