#include "SvgGenerator.h"

#include <fmt/core.h>

using namespace simple_svg_floorplan;

std::string SvgGenerator::Start()
{
  return R"(<svg xmlns="http://www.w3.org/2000/svg">)";
}

std::string SvgGenerator::Stop()
{
  return "</svg>";
}

std::string SvgGenerator::Wall(double length)
{
  auto old_position = current_position;
  current_position += Point<>{ length, 0 };
  return fmt::format(R"(<line x1="{}" y1="{}" x2="{}" y2="{}" stroke="black" stroke-width="4"/>)",
    old_position.x,
    old_position.y,
    current_position.x,
    current_position.y);
}
