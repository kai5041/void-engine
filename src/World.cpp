#include <voe/core/World.hpp>

namespace voe {

World::World(std::mutex &engine_mtx) : mtx(engine_mtx) {}

void World::add_object(Object &obj) {
  std::lock_guard<std::mutex> lock(mtx); // lock

  u32 id = next_id++;
  objects[id] = &obj;
}

Object *World::get_object(u32 id) {
  std::lock_guard<std::mutex> lock(mtx); // lock

  auto it = objects.find(id);
  if (it != objects.end())
    return it->second;
  return nullptr;
}

} // namespace voe
