#include "controller.h"
#include <iostream>
#include "SDL.h"
#include<memory>
#include <iostream>

void Controller::HandleInput(bool &running, Paddle* paddle1, Paddle* paddle2, const std::size_t screen_h) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_w:
          paddle1->Update(-1, screen_h);
          break;
        case SDLK_s:
          paddle1->Update(1, screen_h);
          break;
        case SDLK_UP:
          paddle2->Update(-1, screen_h);
          break;
        case SDLK_DOWN:
          paddle2->Update(1, screen_h);
          break;
      }
    }
  }
}