#pragma once

#include <SDL3/SDL_render.h>
#include <voe/defs.hpp>
#include <voe/primitive/Coordinate.hpp>
#include <voe/renderable/RenderableObject.hpp>

#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>

namespace voe {

class Rect2D : public RenderableObject {
private:
  // [top-right, bottom-right, bottom-left, top-left]
  Array<Coordinate2D, 4> points;

  SDL_Renderer *renderer = nullptr;

  SDL_FRect rect;
  SDL_Color color;

  r32 width = 0.0;
  r32 height = 0.0;

public:
  // Top-left and bottom-right points
  Rect2D(Array<Coordinate2D, 2> points, u8 red, u8 green, u8 blue, u8 alpha);

  Array<r32, 2> get_dimensions() const { return {this->width, this->height}; }

  void set_renderer(SDL_Renderer *renderer) { this->renderer = renderer; }

  void render_step(float dt);
};

} // namespace voe
