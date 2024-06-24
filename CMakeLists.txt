cmake_minimum_required(VERSION 3.10)

# Set the project name
project(my_github_action)

# Add the executable
add_executable(my_github_action main.cpp)

# Include stb_image
include_directories(${CMAKE_SOURCE_DIR})
