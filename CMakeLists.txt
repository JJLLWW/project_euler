cmake_minimum_required(VERSION 3.11.0)

project(hello_world)
set(EXE_NAME "output")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
# std::lcm and std::gcd require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${EXE_NAME} 
    src/main.cpp 
    src/euler_1_to_50.cpp
    src/euler_1_to_50_tests.cpp
    )

# the CONFIG is required, need more cmake/vcpkg knowledge.
find_package(fmt CONFIG REQUIRED)
target_include_directories(${EXE_NAME} PUBLIC src/include)
target_link_libraries(${EXE_NAME} PRIVATE fmt::fmt-header-only)