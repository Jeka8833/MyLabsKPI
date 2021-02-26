cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(TestProject main.cpp labs/Lab2.cpp labs/Lab2.h Util.cpp Util.h labs/Lab.cpp labs/Lab.h labs/Lab3.cpp labs/Lab3.h labs/Lab4.cpp labs/Lab4.h labs/Lab5.cpp labs/Lab5.h labs/Lab6.cpp labs/Lab6.h labs/Lab7.cpp labs/Lab7.h labs/Lab8.cpp labs/Lab8.h)