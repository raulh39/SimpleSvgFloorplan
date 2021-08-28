#pragma once

#include "Point.h"
#include <string>

namespace simple_svg_floorplan {

class SvgGenerator
{
public:
  std::string Start();
  std::string Stop();
  std::string Wall(double length);

private:
  Point<double> current_position;
};

}// namespace simple_svg_floorplan
