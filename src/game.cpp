#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game() {
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  auto screenWidth = renderer.screen_width;
  auto screenHeight = renderer.screen_height;
  ball = std::make_unique<Ball>(screenWidth/2.0, screenWidth/2.0, BALL_SPEED, 0.0f);
  paddle1 = std::make_unique<Paddle>("Paddle 1", 80.0, screenHeight/2.0, 0.0f, 0.0f);
  paddle2 = std::make_unique<Paddle>("Paddle 2", screenWidth - 80.0, screenHeight/2.0, 0.0f,0.0f);
  double scoreWidth = 100;
  double scoreHeight = 100;
  player1 = std::make_unique<Player>(0, (screenWidth/4.0) - (scoreWidth/2.0), 0, scoreWidth, scoreHeight);
  player2 = std::make_unique<Player>(0, 3 * (screenWidth/4.0) - (scoreWidth/2.0), 0, scoreWidth, scoreHeight);
  renderer.SetTexture(player1.get());
  renderer.SetTexture(player2.get());
  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, paddle1.get(), paddle2.get(), screenHeight);
    Update(target_frame_duration, screenHeight, screenWidth, renderer);
    renderer.Render(paddle1.get(), paddle2.get(), ball.get(), player1.get(), player2.get());
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update(std::size_t dt, const std::size_t screen_h, const std::size_t screen_w, Renderer &renderer) {
  paddle1->Update(dt, screen_h);
  paddle2->Update(dt, screen_h);
  ball->Update(dt, screen_w, screen_w);
  CheckCollisions(paddle1.get(), paddle2.get(), ball.get(), screen_h, screen_w, renderer);
}

void Game::CheckCollisions(Paddle* const paddleOne, Paddle* const paddleTwo, Ball* const ball, const std::size_t screen_h, const std::size_t screen_w, Renderer &renderer) {
  Contact contact;
  contact = ball->VerifyPaddleBallCollision(paddleOne);
  if (contact.type != CollisionType::none)
  {
	  ball->CollideWithPaddle(contact);
    return;
  }
  contact = ball->VerifyPaddleBallCollision(paddleTwo);
  if(contact.type != CollisionType::none) {
    ball->CollideWithPaddle(contact);
    return;
  }

  contact = ball->VerifyWallCollision(screen_h, screen_w);
  if(contact.type != CollisionType::none) {
    ball->CollideWithWall(contact, screen_h, screen_w);
    if(contact.type == CollisionType::left){
      player2->increaseScore(1);
      renderer.SetTexture(player2.get());
    }
    if(contact.type == CollisionType::right) {
      player1->increaseScore(1);
      renderer.SetTexture(player1.get());
    }
    return;
  }
}
