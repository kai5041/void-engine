#pragma once

#include <voe/primitive/Object.hpp>

namespace voe {

class RenderableObject : public Object {
public:
  RenderableObject() {}
  ~RenderableObject() {}
  void render_step(float dt) {}
};

} // namespace voe
