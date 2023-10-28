cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)

project(HelloWorld)

add_executable(HelloWorld 
main.cpp
MyModule.ixx
)