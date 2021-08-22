#include "SvgCompiler.h"

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("starting")
{
  simple_svg_floorplan::SvgCompiler compiler;
  std::istringstream input{ "" };
  std::ostringstream output;
  compiler.Compile(input, output);
}
