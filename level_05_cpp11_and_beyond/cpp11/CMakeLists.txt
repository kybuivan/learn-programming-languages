set_property(DIRECTORY PROPERTY LABELS 11)

set(names
  array
  async
  atomic
  auto
  bind
  constexpr
  constructor
  current_exception
  decltype
  deleted_functions
  default_constructor
  enum
  forward
  future
  getenv
  lambda
  move
  mutex
  noexcept
  nullptr
  override
  packaged_task
  promise
  ratio
  rvalue_references
  shared_future
  shared_ptr
  template
  thread
  tuple
  unique_ptr
  using
  weak_ptr
)

if(WIN32)
  list(APPEND names GetLastError)
endif()

foreach(t IN LISTS names)
  add_executable(${t} ${t}.cpp)
  add_test(NAME ${t} COMMAND ${t})
endforeach()


if(TEST GetLastError)
  set_property(TEST GetLastError PROPERTY WILL_FAIL true)
endif()
