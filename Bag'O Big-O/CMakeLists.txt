
cmake_minimum_required(VERSION 3.10)
project(cs106b_a5_no_stanford LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(cs106b_a5
    src/main.cpp
    src/Combine.cpp
    src/tests.cpp
)

target_include_directories(cs106b_a5 PRIVATE include)
