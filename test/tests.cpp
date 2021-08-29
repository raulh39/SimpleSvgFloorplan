#include "PhysicalUnits.h"
#include "SvgGenerator.h"

#include <catch2/catch.hpp>

#include <numbers>

using namespace simple_svg_floorplan;
using namespace Catch::literals;

TEST_CASE("Physical unit library")
{
  Length a{ 10.1 }, b{ 20.2 };
  REQUIRE((a + b).get() == 30.3_a);

  Radians r{ Degrees{ 45 } };
  REQUIRE(r.get() == Approx(Radians{ std::numbers::pi / 4 }.get()));

  Direction dir{ Degrees{ 60 } };
  REQUIRE(dir.x == 0.5_a);
  REQUIRE(dir.y == 0.86602540378_a);

  Position p;
  p.Move(Direction{Degrees{90}}, Length{10});
  REQUIRE(p.x == Approx{0}.scale(1));
  REQUIRE(p.y == 10.0_a);
}

TEST_CASE("Generator")
{
  SvgGenerator generator;
  REQUIRE(generator.Start() == R"(<svg xmlns="http://www.w3.org/2000/svg">)");
  REQUIRE(generator.Wall(Length{10}) == R"(<line x1="0.00" y1="0.00" x2="10.00" y2="0.00" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Wall(Length{10}) == R"(<line x1="10.00" y1="0.00" x2="20.00" y2="0.00" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Stop() == R"(</svg>)");
}

/*
5.-
Turn(Direction, angle) -> Direction; // x' = x * cos(angle) - y * sin(angle); 
                                     // y' = x * sin(angle) + y * cos(angle)
                                     // angle > 0 => anticlock
                                     // cos( 90º) = 0 ; sin( 90º) =  1
                                     // cos(-90º) = 0 ; sin(-90º) = -1
                                     // Turn([2,1], -90º) -> [2*0-1*-1, 2*-1+1*0] -> [1,-2]
                                     // sin(angle) = cos(90º-angle)

*/
