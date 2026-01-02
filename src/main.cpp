#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <iostream>

#include <voe/core/Engine.hpp>
#include <voe/core/World.hpp>
#include <voe/primitive/Coordinate.hpp>
#include <voe/renderable/2D/Rect2D.hpp>

using namespace voe;

int main() {
  std::cout << "Running VoE\n";
  Engine engine;
  World my_world(engine.get_mtx());

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Renderer *renderer = nullptr;
  SDL_Window *window = nullptr;
  SDL_CreateWindowAndRenderer("Cyber料理", 500, 500, SDL_WINDOW_RESIZABLE,
                              &window, &renderer);

  Rect2D rect({Coordinate2D{0, 0}, {200, 150}}, 255, 255, 255, 255);
  rect.set_renderer(renderer);

  bool running = true;
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        running = false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    rect.render_step(0);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
