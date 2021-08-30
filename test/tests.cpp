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

TEST_CASE("Open and close")
{
  SvgGenerator generator;
  REQUIRE(generator.Start() == R"(<svg xmlns="http://www.w3.org/2000/svg">)");
  REQUIRE(generator.Stop() == R"(</svg>)");
}

TEST_CASE("Basic generation")
{
  SvgGenerator generator;
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="0.00" y1="0.00" x2="10.00" y2="0.00" stroke="black" stroke-width="4"/>)");
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="10.00" y1="0.00" x2="20.00" y2="0.00" stroke="black" stroke-width="4"/>)");
}

TEST_CASE("Basic turns")
{
  SvgGenerator generator;
  generator.Turn(Degrees{ 45 });
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="0.00" y1="0.00" x2="7.07" y2="7.07" stroke="black" stroke-width="4"/>)");
  generator.Turn(Degrees{ 90 });
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="7.07" y1="7.07" x2="0.00" y2="14.14" stroke="black" stroke-width="4"/>)");
  generator.Turn(Degrees{ 90 });
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="0.00" y1="14.14" x2="-7.07" y2="7.07" stroke="black" stroke-width="4"/>)");
  generator.Turn(Degrees{ 90 });
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="-7.07" y1="7.07" x2="0.00" y2="0.00" stroke="black" stroke-width="4"/>)");
}

TEST_CASE("Turns as directions")
{
  SvgGenerator generator;
  constexpr double hyp = 128.062485; //sqrt(100*100+80*80);
  generator.Turn(100,80);
  REQUIRE(generator.Wall(Length{ hyp }) == R"(<line x1="0.00" y1="0.00" x2="100.00" y2="80.00" stroke="black" stroke-width="4"/>)");
  generator.Turn(80,100);
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="100.00" y1="80.00" x2="100.00" y2="90.00" stroke="black" stroke-width="4"/>)");
  generator.Turn(80,100);
  REQUIRE(generator.Wall(Length{ hyp }) == R"(<line x1="100.00" y1="90.00" x2="0.00" y2="170.00" stroke="black" stroke-width="4"/>)");
}
