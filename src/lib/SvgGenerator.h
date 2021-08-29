#pragma once

#include "PhysicalUnits.h"
#include <string>

namespace simple_svg_floorplan {

class SvgGenerator
{
public:
  std::string Start();
  std::string Stop();
  std::string Wall(double length);

private:
  Position current_position;
};

}// namespace simple_svg_floorplan
