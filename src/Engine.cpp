#include <voe/core/Engine.hpp>
#include <voe/core/World.hpp>

namespace voe {

Engine::Engine() {}
Engine::~Engine() {}

void Engine::add_world(World *world) {
  std::lock_guard<std::mutex> lock(mtx);

  worlds.emplace_back(mtx);
}

} // namespace voe