#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"

class Game {
 public:
  Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:
  int score{0};
  void Update();
  std::unique_ptr<Ball> ball;
  std::unique_ptr<Paddle> paddle1;
  std::unique_ptr<Paddle> paddle2;
};

#endif