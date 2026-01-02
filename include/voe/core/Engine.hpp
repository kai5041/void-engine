#pragma once

#include <mutex>
#include <voe/defs.hpp>
#include <voe/primitive/Object.hpp>

namespace voe {

class World;

class Engine {
private:
  std::mutex mtx;
  Vec<World> worlds;

public:
  Engine();
  ~Engine();

  void add_world(World *world);

  auto &get_mtx() { return this->mtx; };
};

} // namespace voe
