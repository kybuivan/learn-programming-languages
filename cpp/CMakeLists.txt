cmake_minimum_required(VERSION 3.20...3.26)
# CMake 3.20 is oldest version supporting C++23

project(
    "learn-cpp"
    VERSION 0.1.0
    LANGUAGES C CXX)

enable_testing()

message(STATUS "CMake ${CMAKE_VERSION}")

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CMAKE MODULES
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(compilers)

add_subdirectory(cpp11)
add_subdirectory(cpp14)
add_subdirectory(cpp17)
add_subdirectory(cpp20)
add_subdirectory(cpp23)