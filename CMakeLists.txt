cmake_minimum_required(VERSION 3.11.0)

project(hello_world)
set(EXE_NAME "output")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(${EXE_NAME} src/main.cpp)

# the CONFIG is required, need more cmake knowledge.
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${EXE_NAME} PRIVATE fmt::fmt-header-only)