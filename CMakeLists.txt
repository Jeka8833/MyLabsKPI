cmake_minimum_required(VERSION 3.24)
project(TestProject)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(TestProject main.cpp labs/Lab2.cpp labs/Lab2.h Util.cpp Util.h Task.cpp Task.h labs/Lab3.cpp labs/Lab3.h labs/Lab4.cpp labs/Lab4.h labs/Lab5.cpp labs/Lab5.h labs/Lab6.cpp labs/Lab6.h labs/Lab7.cpp labs/Lab7.h labs/Lab8.cpp labs/Lab8.h prac/PR2.cpp prac/PR2.h prac/PR3.cpp prac/PR3.h)