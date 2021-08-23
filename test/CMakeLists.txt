find_package(Catch2 REQUIRED)

add_executable(test_simple_svg_floorplan)
target_sources(test_simple_svg_floorplan PRIVATE tests.cpp catch_main.cpp)
target_link_libraries(test_simple_svg_floorplan PRIVATE lib_core Catch2::Catch2)
