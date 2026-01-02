#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <voe/renderable/2D/Rect2D.hpp>

#include <SDL3/SDL.h>

namespace voe {

Rect2D::Rect2D(Array<Coordinate2D, 2> points, u8 red, u8 green, u8 blue,
               u8 alpha) {
  r32 x_min = static_cast<r32>(std::min(points[0].x, points[1].x));
  r32 y_min = static_cast<r32>(std::min(points[0].y, points[1].y));
  r32 x_max = static_cast<r32>(std::max(points[0].x, points[1].x));
  r32 y_max = static_cast<r32>(std::max(points[0].y, points[1].y));

  this->width = x_max - x_min;
  this->height = y_max - y_min;

  this->points[0] = {x_min, y_min}; // top-left
  this->points[1] = {x_max, y_min}; // top-right
  this->points[2] = {x_max, y_max}; // bottom-right
  this->points[3] = {x_min, y_max}; // bottom-left

  this->color = {red, green, blue, alpha};
  this->rect = {x_min, y_min, this->width, this->height};
}

void Rect2D::render_step(float dt) {
  SDL_SetRenderDrawColor(this->renderer, this->color.r, this->color.g,
                         this->color.b, this->color.a);

  // outline 
  SDL_RenderRect(this->renderer, &this->rect);

  // fill
  SDL_RenderFillRect(this->renderer, &this->rect);
}

} // namespace voe