#include "SvgCompiler.h"

using namespace simple_svg_floorplan;

void SvgCompiler::Compile(std::istream &, std::ostream &os)
{
  os << R"(<svg xmlns="http://www.w3.org/2000/svg">)";
  os << '\n';
  os << "</svg>";
}
