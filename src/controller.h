#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Paddle.h"

class Controller {
 public:
  void HandleInput(bool &running, Paddle* paddle1, Paddle* paddle2) const;
};

#endif