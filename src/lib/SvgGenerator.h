#pragma once

#include "PhysicalUnits.h"
#include <string>

namespace simple_svg_floorplan {

enum class HingePosition
{
  near,
  far
};

enum class DirectionDoorOpens
{
  right,
  left
};

class SvgGenerator
{
public:
  std::string Start();
  std::string Stop();
  std::string Wall(Length length);
  std::string Door(Length length, HingePosition hinge_pos, DirectionDoorOpens ddo);
  void Turn(Radians angle) {
    current_direction.Turn(angle);
  }
  void FaceTo(double dx, double dy) {
    current_direction.FaceTo(dx, dy);
  }
  void Move(const Position &new_position)
  {
    current_position = new_position;
  }

private:
  Position current_position;
  Direction current_direction{};
};

}// namespace simple_svg_floorplan
