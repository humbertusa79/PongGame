#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "Ball.h"
#include "Paddle.h"
#include "Player.h"
#include <memory>

class Renderer {
 public:
  std::size_t screen_width;
  std::size_t screen_height;
  Renderer(const std::size_t screen_w, const std::size_t screen_h);
  ~Renderer();

  void Render(Paddle* paddle1, Paddle* paddle2, Ball* ball, Player* player1, Player* player2);
  void UpdateWindowTitle(int score, int fps);
  void SetTexture(Player* player);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
};

#endif