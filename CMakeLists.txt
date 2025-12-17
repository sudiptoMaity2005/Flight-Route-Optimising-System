cmake_minimum_required(VERSION 3.10)
project(FlightPlanner)

set(CMAKE_CXX_STANDARD 17)

# Linking both source files into one program
add_executable(FlightPlanner main.cpp RoutePlanner.cpp)