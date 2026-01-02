#pragma once

#include <ostream>

#include <voe/defs.hpp>

namespace voe {

class Coordinate2D {
public:
  r32 x = 0;
  r32 y = 0;
};

class Coordinate3D {
public:
  r32 x = 0;
  r32 y = 0;
  r32 z = 0;
};

} // namespace voe

inline std::ostream &operator<<(std::ostream &os,
                                const voe::Coordinate2D &value) {
  return os << "(x=" << value.x << ", y=" << value.y << ")";
}

inline std::ostream &operator<<(std::ostream &os,
                                const voe::Coordinate3D &value) {
  return os << "(x=" << value.x << ", y=" << value.y << ", z=" << value.z
            << ")";
}
