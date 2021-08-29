#include "PhysicalUnits.h"
#include "SvgGenerator.h"

#include <catch2/catch.hpp>

#include <numbers>

using namespace simple_svg_floorplan;
using namespace Catch::literals;
const auto zero = Approx{ 0 }.scale(1);

TEST_CASE("Physical unit library")
{
  Length a{ 10.1 }, b{ 20.2 };
  REQUIRE((a + b).get() == 30.3_a);

  Radians r{ Degrees{ 45 } };
  REQUIRE(r.get() == Approx(Radians{ std::numbers::pi / 4 }.get()));

  Direction dir;
  REQUIRE(dir.x == 1.0_a);
  REQUIRE(dir.y == zero);
  dir.Turn(Degrees{ 60 });
  REQUIRE(dir.x == 0.5_a);
  REQUIRE(dir.y == 0.86602540378_a);

  Position p;
  p.Move(Direction{ Degrees{ 90 } }, Length{ 10 });
  REQUIRE(p.x == zero);
  REQUIRE(p.y == 10.0_a);
}

TEST_CASE("Generator")
{
  SvgGenerator generator;
  REQUIRE(generator.Start() == R"(<svg xmlns="http://www.w3.org/2000/svg">)");
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="0.00" y1="0.00" x2="10.00" y2="0.00" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="10.00" y1="0.00" x2="20.00" y2="0.00" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Stop() == R"(</svg>)");
}
