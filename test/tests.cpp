#include "PhysicalUnits.h"
#include "SvgGenerator.h"

#include <catch2/catch.hpp>

using namespace simple_svg_floorplan;

TEST_CASE("Vector maths")
{
  Position p{ 2.0, 3.0 };
  Direction d{ 1.0, 2.0 };
  Position sum{ 3.0, 5.0 };

  REQUIRE(p + d == sum);
  p += d;
  REQUIRE(p == sum);
}

TEST_CASE("Generator")
{
  SvgGenerator generator;
  REQUIRE(generator.Start() == R"(<svg xmlns="http://www.w3.org/2000/svg">)");
  REQUIRE(generator.Wall(10) == R"(<line x1="0.00" y1="0.00" x2="10.00" y2="0.00" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Wall(10) == R"(<line x1="10.00" y1="0.00" x2="20.00" y2="0.00" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Stop() == R"(</svg>)");
}

/*

2 .-
I need a Length unit also for the std::string Wall(double length);

3.- 
struct Degrees:double {};

4.-
struct Degrees
{
  double value;
};

struct Radians
{
  double value;
};

5.-
Turn(Direction, angle) -> Direction; // x' = x * cos(angle) - y * sin(angle); 
                                     // y' = x * sin(angle) + y * cos(angle)
                                     // angle > 0 => anticlock
                                     // cos( 90º) = 0 ; sin( 90º) =  1
                                     // cos(-90º) = 0 ; sin(-90º) = -1
                                     // Turn([2,1], -90º) -> [2*0-1*-1, 2*-1+1*0] -> [1,-2]
                                     // sin(angle) = cos(90º-angle)
*/
