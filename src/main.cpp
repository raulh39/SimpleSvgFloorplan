#include "SvgGenerator.h"

#include <iostream>
#include <docopt/docopt.h>
#include <fmt/core.h>

static constexpr auto USAGE =
  R"(Simple SVG Floorplanner.

    Usage:
          simple_svg_floorplan <input_file>
          simple_svg_floorplan (-h | --help)
          simple_svg_floorplan --version
 Options:
          -h --help     Show this screen.
          --version     Show version.
)";

int main(int argc, const char **argv)
{
  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    { std::next(argv), std::next(argv, argc) },
    true,// show help if requested
    "Simple SVG Floorplanner 0.1");// version string

  using namespace simple_svg_floorplan;
  SvgGenerator generator;
  generator.Move(Position{ 200, 200 });
  std::cout << generator.Start() << '\n';
  std::cout << generator.Wall(Length{ 17 }) << '\n';
  generator.FaceTo(101, -80);
  std::cout << generator.Wall(Length{ 129 }) << '\n';
  generator.FaceTo(1, 0);
  std::cout << generator.Wall(Length{ 112 }) << '\n';
  generator.FaceTo(101, 80);
  std::cout << generator.Wall(Length{ 129 }) << '\n';
  generator.FaceTo(1, 0);
  std::cout << generator.Wall(Length{ 63 }) << '\n';
  std::cout << generator.Door(Length{ 75 }, HingePosition::near, DirectionDoorOpens::right) << '\n';
  std::cout << generator.Door(Length{ 75 }, HingePosition::far, DirectionDoorOpens::right) << '\n';
  std::cout << generator.Wall(Length{ 31 }) << '\n';
  generator.Turn(Degrees{ 90 });
  std::cout << generator.Wall(Length{ 365 }) << '\n';
  generator.Turn(Degrees{ 90 });
  std::cout << generator.Wall(Length{ 186 }) << '\n';
  generator.Turn(Degrees{ -90 });
  std::cout << generator.Wall(Length{ 96 }) << '\n';
  generator.Turn(Degrees{ 91 });
  std::cout << generator.Wall(Length{ 14 }) << '\n';
  std::cout << generator.Door(Length{ 72.5 }, HingePosition::near, DirectionDoorOpens::right) << '\n';
  std::cout << generator.Door(Length{ 30 }, HingePosition::far, DirectionDoorOpens::right) << '\n';
  std::cout << generator.Wall(Length{ 19 }) << '\n';
  generator.Turn(Degrees{ -90 });
  std::cout << generator.Wall(Length{ 7 }) << '\n';
  generator.Turn(Degrees{ 90 });
  std::cout << generator.Wall(Length{ 253 }) << '\n';
  generator.Turn(Degrees{ 90 });
  std::cout << generator.Wall(Length{ 7 }) << '\n';
  generator.Turn(Degrees{ -90 });
  std::cout << generator.Wall(Length{ 10 }) << '\n';
  generator.Turn(Degrees{ 90 });
  std::cout << generator.Wall(Length{ 455 }) << '\n';
  std::cout << generator.Stop() << '\n';
}
