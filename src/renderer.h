#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "Ball.h"
#include "Paddle.h"
#include <memory>

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render();
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;

  std::unique_ptr<Ball> ball;
  std::unique_ptr<Paddle> paddle1;
  std::unique_ptr<Paddle> paddle2;
};

#endif