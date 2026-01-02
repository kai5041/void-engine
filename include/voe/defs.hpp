#pragma once

#include <array>
#include <cstdint>

#include <ostream>
#include <unordered_map>
#include <vector>

namespace voe {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using r32 = float;
using r64 = double;

template <typename T, typename U> using Map = std::unordered_map<T, U>;
template <typename Tp, std::size_t Nm> using Array = std::array<Tp, Nm>;

template <typename T> using Vec = std::vector<T>;

inline std::ostream &operator<<(std::ostream &os, u8 value) {
  return os << static_cast<unsigned int>(value);
}

using String = std::string;

} // namespace voe
