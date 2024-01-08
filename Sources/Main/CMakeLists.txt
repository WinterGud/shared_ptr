cmake_cmake_minimum_required(VERSION 3.6)

# Set the project name
project (Main)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
	main.cpp
	shared_ptr.hpp
)

add_executable(Main ${SOURCES})