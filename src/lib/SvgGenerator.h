#pragma once

#include "PhysicalUnits.h"
#include <string>

namespace simple_svg_floorplan {

class SvgGenerator
{
public:
  std::string Start();
  std::string Stop();
  std::string Wall(Length length);

private:
  Position current_position;
  Direction current_direction{Radians{0}};
};

}// namespace simple_svg_floorplan
