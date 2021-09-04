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
  constexpr double hyp = 128.062485;//sqrt(100*100+80*80);
  generator.FaceTo(100, 80);
  REQUIRE(generator.Wall(Length{ hyp }) == R"(<line x1="0.00" y1="0.00" x2="100.00" y2="80.00" stroke="black" stroke-width="4"/>)");
  generator.FaceTo(0, 1);
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="100.00" y1="80.00" x2="100.00" y2="90.00" stroke="black" stroke-width="4"/>)");
  generator.FaceTo(80, 100);
  REQUIRE(generator.Wall(Length{ hyp }) == R"(<line x1="100.00" y1="90.00" x2="180.00" y2="190.00" stroke="black" stroke-width="4"/>)");
}

TEST_CASE("Move")
{
  SvgGenerator generator;
  generator.Move(Position{ 200, 100 });
  REQUIRE(generator.Wall(Length{ 10 }) == R"(<line x1="200.00" y1="100.00" x2="210.00" y2="100.00" stroke="black" stroke-width="4"/>)");
}

TEST_CASE("Door")
{
  SvgGenerator generator;
  generator.Move(Position{ 100, 10 });
  generator.FaceTo(1, 0);
  REQUIRE(
    generator.Door(Length{ 80 }, HingePosition::near, DirectionDoorOpens::right) == 
    R"(<line stroke-width="1" stroke="black" x1="100.00" y1="10.00" x2="100.00" y2="90.00"/>)""\n"
    R"(<path d="M 100.00 90.00 A 80.00 80.00 0 0 0 180.00 10.00" fill="none" stroke-width="1" stroke="black"/>)"
  );

  generator.Move(Position{ 100, 200 });
  REQUIRE(
    generator.Door(Length{ 70 }, HingePosition::near, DirectionDoorOpens::left) == 
    R"(<line stroke-width="1" stroke="black" x1="100.00" y1="200.00" x2="100.00" y2="130.00"/>)""\n"
    R"(<path d="M 100.00 130.00 A 70.00 70.00 0 0 1 170.00 200.00" fill="none" stroke-width="1" stroke="black"/>)"
  );

  generator.Move(Position{ 100, 300 });
  REQUIRE(
    generator.Door(Length{ 70 }, HingePosition::far, DirectionDoorOpens::right) == 
    R"(<line stroke-width="1" stroke="black" x1="170.00" y1="300.00" x2="170.00" y2="370.00"/>)""\n"
    R"(<path d="M 100.00 300.00 A 70.00 70.00 0 0 0 170.00 370.00" fill="none" stroke-width="1" stroke="black"/>)"
  );

  generator.Move(Position{ 100, 500 });
  REQUIRE(
    generator.Door(Length{ 70 }, HingePosition::far, DirectionDoorOpens::left) == 
    R"(<line stroke-width="1" stroke="black" x1="170.00" y1="500.00" x2="170.00" y2="430.00"/>)""\n"
    R"(<path d="M 100.00 500.00 A 70.00 70.00 0 0 1 170.00 430.00" fill="none" stroke-width="1" stroke="black"/>)"
  );
}
