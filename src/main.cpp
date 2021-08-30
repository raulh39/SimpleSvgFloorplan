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
  std::cout << generator.Stop() << '\n';
}
