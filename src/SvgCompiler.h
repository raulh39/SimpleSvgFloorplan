#pragma once

#include <iostream>

namespace simple_svg_floorplan {

class SvgCompiler
{
public:
  void Compile(std::istream &input, std::ostream &output);
};

}// namespace simple_svg_floorplan
