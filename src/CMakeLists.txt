cmake_minimum_required(VERSION 3.16.3)
project(SimpleSvgFloorplan)

add_subdirectory(lib)

find_package(fmt REQUIRED)
find_package(docopt REQUIRED)

add_executable(simple_svg_floorplan)
target_sources(simple_svg_floorplan PRIVATE main.cpp)
target_link_libraries(simple_svg_floorplan PRIVATE lib_core fmt::fmt docopt::docopt)
