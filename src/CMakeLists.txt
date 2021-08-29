cmake_minimum_required(VERSION 3.16.3)
project(SimpleSvgFloorplan)

find_package(fmt REQUIRED)
find_package(docopt REQUIRED)
find_package(namedtype REQUIRED)

add_subdirectory(lib)

add_executable(simple_svg_floorplan)
target_sources(simple_svg_floorplan PRIVATE main.cpp)
target_link_libraries(simple_svg_floorplan PRIVATE lib_core fmt::fmt docopt::docopt)
