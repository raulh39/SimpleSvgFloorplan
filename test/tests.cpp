#include "SvgCompiler.h"

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("Empty input produces the minimal SVG")
{
  simple_svg_floorplan::SvgCompiler compiler;
  std::istringstream input{ "" };
  std::ostringstream output;
  compiler.Compile(input, output);
  REQUIRE(output.str() == R"(<svg xmlns="http://www.w3.org/2000/svg">)""\n</svg>");
}
