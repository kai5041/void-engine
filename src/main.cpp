#include <SDL3/SDL.h>
#include <iostream>

#include <voe/core/Engine.hpp>
#include <voe/core/World.hpp>
#include <voe/primitive/Coordinate.hpp>
#include <voe/renderable/2D/Rect2D.hpp>

using namespace voe;

//extern "C" int SDL_main(int argc, char *argv[]) {
//  std::cout << "Running VoE on Android\n";
//
//  Engine engine;
//  World my_world(engine.get_mtx());
//
//  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
//    std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
//    return -1;
//  }
//
//  SDL_Window *window = nullptr;
//  SDL_Renderer *renderer = nullptr;
//  SDL_CreateWindowAndRenderer("test", 500, 500, SDL_WINDOW_RESIZABLE, &window,
//                              &renderer);
//
//  Rect2D rect({Coordinate2D{0, 0}, {200, 150}}, 255, 255, 255, 255);
//  rect.set_renderer(renderer);
//
//  bool running = true;
//  SDL_Event event;
//
//  while (running) {
//    while (SDL_PollEvent(&event)) {
//      if (event.type == SDL_EVENT_QUIT)
//        running = false;
//    }
//
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_RenderClear(renderer);
//
//    rect.render_step(0);
//
//    SDL_RenderPresent(renderer);
//  }
//
//  SDL_DestroyRenderer(renderer);
//  SDL_DestroyWindow(window);
//  SDL_Quit();
//
//  return 0;
//}
//