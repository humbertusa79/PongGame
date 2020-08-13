#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_w,
                   const std::size_t screen_h) {
    screen_width = screen_w;
    screen_height = screen_h;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }


  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window); 
}

void Renderer::SetTexture(Player* player) {
  player->setTexture(sdl_renderer);
}

void Renderer::Render(Paddle* paddle1, Paddle* paddle2, Ball* ball, Player* player1, Player* player2) {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (int y = 0; y <  screen_height; y++) {
    if(y % 5) {
      SDL_RenderDrawPoint(sdl_renderer, screen_width / 2, y);
    }
  }
  ball->Draw(sdl_renderer);
  paddle1->Draw(sdl_renderer);
  paddle2->Draw(sdl_renderer);
  player1->Draw(sdl_renderer);
  player2->Draw(sdl_renderer);
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int fps) {
  std::string title{" FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
