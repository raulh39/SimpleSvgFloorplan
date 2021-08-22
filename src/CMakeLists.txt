# Generic test that uses conan libs
add_executable(simple_svg_floorplan main.cpp)
target_link_libraries(
  simple_svg_floorplan
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
