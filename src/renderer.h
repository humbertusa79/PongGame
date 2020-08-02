#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "Ball.h"
#include "Paddle.h"
#include <memory>


static  std::size_t screen_width;
static  std::size_t screen_height;

class Renderer {
 public:
  Renderer(const std::size_t screen_w, const std::size_t screen_h);
  ~Renderer();

  void Render();
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  std::unique_ptr<Ball> ball;
  std::unique_ptr<Paddle> paddle1;
  std::unique_ptr<Paddle> paddle2;
};

#endif