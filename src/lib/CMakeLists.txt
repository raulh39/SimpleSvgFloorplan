add_library(lib_core OBJECT)

target_sources(lib_core
  PRIVATE SvgCompiler.cpp)

# target_link_libraries(
#   lib_core
# )
target_include_directories(lib_core PUBLIC .)
