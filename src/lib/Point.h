#pragma once

namespace simple_svg_floorplan {

template<typename T = double>
struct Point
{
  T x;
  T y;
  Point &operator+=(const Point<T> &rhs);
};

template<typename T>
inline Point<T> operator+(const Point<T> &lhs, const Point<T> &rhs)
{
  return Point<T>{ lhs.x + rhs.x, lhs.y + rhs.y };
}

template<typename T>
inline Point<T> &Point<T>::operator+=(const Point<T> &rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

}// namespace simple_svg_floorplan
