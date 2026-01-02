#pragma once

#include <mutex>
#include <voe/defs.hpp>
#include <voe/primitive/Object.hpp>

namespace voe {

class World {
protected:
  Map<u32, Object *> objects;
  std::mutex &mtx; // reference to Engine mutex
  u32 next_id = 1;

public:
  explicit World(std::mutex &engine_mtx);
  ~World() = default;

  void add_object(Object &obj);

  Object *get_object(u32 id);
};

} // namespace voe
