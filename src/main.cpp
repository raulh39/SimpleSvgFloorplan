#include <functional>
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

  fmt::print("Nothing to see here. Keep going. Keep the good work with \"{}\"\n", args.at("<input_file>").asString());
}
