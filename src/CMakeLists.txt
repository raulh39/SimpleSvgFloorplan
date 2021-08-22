# Generic test that uses conan libs
add_library(lib_simple_svg_floorplan OBJECT)

target_sources(lib_simple_svg_floorplan
  PRIVATE SvgCompiler.cpp)
target_link_libraries(
  lib_simple_svg_floorplan
  PRIVATE project_options
          project_warnings
)
target_include_directories(lib_simple_svg_floorplan PUBLIC .)

add_executable(simple_svg_floorplan main.cpp)
target_link_libraries(
  simple_svg_floorplan
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt)
