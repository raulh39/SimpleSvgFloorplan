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
  void Turn(Radians angle) {
    current_direction.Turn(angle);
  }
  void Turn(double dx, double dy) {
    current_direction.Turn(dx, dy);
  }

private:
  Position current_position;
  Direction current_direction{};
};

}// namespace simple_svg_floorplan
