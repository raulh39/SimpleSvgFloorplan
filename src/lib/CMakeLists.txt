add_library(lib_core OBJECT)

target_sources(lib_core
  PRIVATE
    SvgCompiler.cpp
    SvgGenerator.cpp
)

target_link_libraries( lib_core
  PUBLIC
    fmt::fmt
)
target_include_directories(lib_core PUBLIC .)
target_compile_features(lib_core PUBLIC cxx_std_20)
