cmake_minimum_required(VERSION 3.3)
project(Snowmans)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework OpenGL -framework GLUT")

set(SOURCE_FILES main.cpp Menu.h Controller.h Context.h Snowman.h)
add_executable(Snowmans ${SOURCE_FILES})