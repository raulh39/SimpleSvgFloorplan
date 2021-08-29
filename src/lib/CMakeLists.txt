add_library(lib_core OBJECT)

target_sources(lib_core
  PRIVATE
    SvgCompiler.cpp
    SvgGenerator.cpp
)

target_link_libraries( lib_core
  PUBLIC
    fmt::fmt
    namedtype::namedtype
)
target_include_directories(lib_core PUBLIC .)
