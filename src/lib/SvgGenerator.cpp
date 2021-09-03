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

std::string SvgGenerator::Wall(Length length)
{
  auto old_position = current_position;
  current_position.Move(current_direction, length);
  return fmt::format(R"(<line x1="{:.2f}" y1="{:.2f}" x2="{:.2f}" y2="{:.2f}" stroke="black" stroke-width="4"/>)",
    old_position.x,
    old_position.y,
    current_position.x,
    current_position.y);
}

std::string SvgGenerator::Door(Length length, HingePosition hinge_pos, DirectionDoorOpens ddo)
{
  auto open_direction = current_direction;
  open_direction.Turn(Degrees{ 90 });

  auto starting_position = current_position;

  auto open_start_position = current_position;
  open_start_position.Move(open_direction, length);

  current_position.Move(current_direction, length);

  return fmt::format(
    R"(<line stroke-width="1" stroke="black" x1="{0:.2f}" y1="{1:.2f}" x2="{2:.2f}" y2="{3:.2f}"/>)"
    "\n"
    R"(<path d="M {2:.2f} {3:.2f} A {6:.2f} {6:.2f} 0 0 0 {4:.2f} {5:.2f}" fill="none" stroke-width="1" stroke="black"/>)",
    starting_position.x,    // {0}
    starting_position.y,    // {1}
    open_start_position.x,  // {2}
    open_start_position.y,  // {3}
    current_position.x,     // {4}
    current_position.y,     // {5}
    length.get());          // {6}
}
