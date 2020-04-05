cmake_minimum_required(VERSION 3.15)
project(World_Of_Waifus)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(World_Of_Waifus
        src/Includes.hpp
        src/Main.cpp
        src/Utils.cpp
        src/Utils.hpp)
