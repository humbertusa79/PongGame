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
  void CheckCollisions(Paddle* const paddleOne, Paddle* const paddleTwo, Ball* const ball, const std::size_t screen_h, const std::size_t screen_w, Renderer &renderer);

 private:
  void Update(std::size_t dt, const std::size_t screen_h, const std::size_t screen_w, Renderer &renderer);
  std::unique_ptr<Ball> ball;
  std::unique_ptr<Paddle> paddle1;
  std::unique_ptr<Paddle> paddle2;
  std::unique_ptr<Player> player1;
  std::unique_ptr<Player> player2;
};

#endif