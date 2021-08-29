#pragma once

#include <tuple>
#include <NamedType/named_type.hpp>
#include <numbers>

namespace simple_svg_floorplan {

struct Direction
{
  double x;
  double y;
};

struct Position
{
  double x;
  double y;
  Position &operator+=(const Direction &d)
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

using Lenght = fluent::NamedType<double, struct LenghtTag, fluent::BinaryAddable>;
using Degrees = fluent::NamedType<double, struct DegreesTag, fluent::BinaryAddable>;
struct Radians : fluent::NamedType<double, struct RadiansTag, fluent::BinaryAddable>
{
  using base = fluent::NamedType<double, struct RadiansTag, fluent::BinaryAddable>;
  using base::base;
  Radians(Degrees d) : base{ d.get() * std::numbers::pi / 180.0 } {}
};

}// namespace simple_svg_floorplan
