#pragma once

namespace simple_svg_floorplan {

struct Direction
{
  double x;
  double y;
  auto operator<=>(const Direction &) const = default;
};

struct Position
{
  double x;
  double y;
  auto operator<=>(const Position &) const = default;
  Position & operator+=(const Direction &d)
  {
    x += d.x;
    y += d.y;
    return *this;
  }
};

inline Position operator+(const Position &p, const Direction &d)
{
  return { p.x + d.x, p.y + d.y };
}

}// namespace simple_svg_floorplan
