cmake_minimum_required(VERSION 3.16.3)
project(SimpleSvgFloorplan VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# main code
add_subdirectory(src)

# tests
add_subdirectory(test)
