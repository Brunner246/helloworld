cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)

project(HelloWorld)

add_library(HelloWorld SHARED 
main.cpp
MyModule.ixx
)