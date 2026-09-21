#include "matrices.h"
#include "utils.h"
#include <SDL3/SDL.h>
#include <cglm/types.h>
#include <stdbool.h>
#include <time.h>

int main() {

  vec4 worldPoints[8] = {
      {-1.0f, -1.0f, 1.0f, 1.0f},  {1.0f, -1.0f, 1.0f, 1.0f},
      {1.0f, 1.0f, 1.0f, 1.0f},    {-1.0f, 1.0f, 1.0f, 1.0f},
      {-1.0f, -1.0f, -1.0f, 1.0f}, {1.0f, -1.0f, -1.0f, 1.0f},
      {1.0f, 1.0f, -1.0f, 1.0f},   {-1.0f, 1.0f, -1.0f, 1.0f}};

  SDL_FPoint pix[8];
  SDL_FPoint lines[16];

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL initerro: %s", SDL_GetError());
    return -1;
  }

  SDL_Window *window = SDL_CreateWindow("CUBE", WIDTH, HEIGHT, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  bool running = true;
  uint64_t frame_start_ns = SDL_GetTicksNS();
  SDL_Event event;

  // clock
  while (running) {
    frame_start_ns = SDL_GetTicksNS();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }
    projectPoints(worldPoints, pix);
    fillLines(pix, lines);

    // setting bg to gray
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    // setting the pixel color to green

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    SDL_RenderLines(renderer, lines, 16);

    SDL_RenderPresent(renderer);

    uint64_t frame_elapsed_ns = SDL_GetTicksNS() - frame_start_ns;

    if (frame_elapsed_ns < TARGET_FRAME_NS) {
      uint64_t wait_ns = TARGET_FRAME_NS - frame_elapsed_ns;
      SDL_DelayPrecise(wait_ns);
    }
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
