#pragma once

#include <tuple>
#include <NamedType/named_type.hpp>
#include <cmath>
#include <numbers>

namespace simple_svg_floorplan {

using Length = fluent::NamedType<double, struct LenghtTag, fluent::BinaryAddable>;
using Degrees = fluent::NamedType<double, struct DegreesTag, fluent::BinaryAddable>;
struct Radians : fluent::NamedType<double, struct RadiansTag, fluent::BinaryAddable>
{
  using base = fluent::NamedType<double, struct RadiansTag, fluent::BinaryAddable>;
  using base::base;
  Radians(Degrees d) : base{ d.get() * std::numbers::pi / 180.0 } {}
};

struct Direction
{
  double x;
  double y;
  explicit Direction(Radians r = Radians{ 0 }) : x{ std::cos(r.get()) },
                                                 y{ std::sin(r.get()) }
  {}
  void Turn(Radians angle)
  {
    double old_x = x;
    double old_y = y;
    auto cosine = std::cos(angle.get());
    auto sine = std::sin(angle.get());
    x = old_x * cosine - old_y * sine;
    y = old_x * sine + old_y * cosine;
  }

  void FaceTo(double dx, double dy)
  {
    double hyp = std::sqrt(dx * dx + dy * dy);
    x = dx / hyp;
    y = dy / hyp;
  }
};

struct Position
{
  double x;
  double y;
  Position() : x{ 0 }, y{ 0 } {}
  Position(double x_, double y_) : x{ x_ }, y{ y_ } {}
  void Move(Direction d, Length l)
  {
    x += d.x * l.get();
    y += d.y * l.get();
  }
};

}// namespace simple_svg_floorplan
