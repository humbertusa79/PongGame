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
  TTF_Init();
  TTF_Font* font = TTF_OpenFont("../resources/Lemonada-Bold.ttf", 25);
  SDL_Color color = { 255, 255, 255 };
  SDL_Surface * surface = TTF_RenderText_Solid(font,"Welcome", color);
  texture = SDL_CreateTextureFromSurface(sdl_renderer,surface);
  TTF_CloseFont(font);
  SDL_FreeSurface(surface);
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window); 
  SDL_DestroyTexture(texture);
  TTF_Quit();
  SDL_Quit();
}

void Renderer::Render(Paddle* paddle1, Paddle* paddle2, Ball* ball) {
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
  DrawText();
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{" FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}


void Renderer::DrawText() {  
  SDL_RenderCopy(sdl_renderer, texture, NULL, NULL);
}
