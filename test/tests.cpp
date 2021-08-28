#include "SvgGenerator.h"

#include <catch2/catch.hpp>

TEST_CASE("Empty input produces the minimal SVG")
{
  simple_svg_floorplan::SvgGenerator generator;
  REQUIRE(generator.Start() == R"(<svg xmlns="http://www.w3.org/2000/svg">)");
  REQUIRE(generator.Wall(10) == R"(<line x1="0.0" y1="0.0" x2="10.0" y2="0.0" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Wall(10) == R"(<line x1="10.0" y1="0.0" x2="20.0" y2="0.0" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Stop() == R"(</svg>)");
}
