cmake_minimum_required(VERSION 3.20...3.26)
# CMake 3.20 is oldest version supporting C++23

project(
    "mastering-cpp"
    VERSION 0.1.0
    LANGUAGES C CXX)

enable_testing()

message(STATUS "CMake ${CMAKE_VERSION}")

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(tidy)
  find_program(CLANG_TIDY
  NAMES clang-tidy
  REQUIRED
  PATHS /opt/homebrew/opt/llvm/bin
  )

  set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY})

endif()

# Options
option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)

option(ENABLE_TESTING "Enable a Unit Testing build." ON)

option(ENABLE_CLANG_TIDY "Enable to add clang tidy." OFF)

option(ENABLE_SANITIZE_ADDR "Enable address sanitize." OFF)
option(ENABLE_SANITIZE_UNDEF "Enable undefined sanitize." OFF)
option(ENABLE_SANITIZE_LEAK "Enable leak sanitize (Gcc/Clang only)." OFF)
option(ENABLE_SANITIZE_THREAD "Enable thread sanitize (Gcc/Clang only)." OFF)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)
option(ENABLE_CMAKE_FORMAT "Enable to add cmake-format." ON)

option(ENABLE_LTO "Enable to add Link Time Optimization." ON)

# CMAKE MODULES
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(compilers)
include(ConfigSafeGuards)
include(AddGitSubmodule)
include(Tools)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

add_cmake_format_target()
add_clang_format_target()

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif()

if(ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

if(ENABLE_LTO)
    include(LTO)
endif()

# EXTERNAL LIBRARIES
#include(CPM)
#CPMAddPackage("gh:fmtlib/fmt#9.1.0")
#CPMAddPackage("gh:nlohmann/json@3.11.2")
#CPMAddPackage("gh:catchorg/Catch2@2.13.9")
#CPMAddPackage("gh:jarro2783/cxxopts@3.1.1")
#CPMAddPackage("gh:gabime/spdlog@1.11.0")

set( levels
  "level_05_cpp11_and_beyond"
  "level_09_design_patterns"
  "level_10_projects"
)

foreach(level IN ITEMS ${levels})
    add_subdirectory(${level})
endforeach()