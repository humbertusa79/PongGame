#include "Ball.h"
#include <iostream>

Ball::Ball(double x, double y, double vx, double vy)  {
    position = std::make_unique<GameVector>(x,y);
    velocity = std::make_unique<GameVector>(vx, vy);
    rect.x = position.get()->getComponents()._x;
	rect.y = position.get()->getComponents()._y;
	rect.w = 15;
	rect.h = 15;
}

Ball::~Ball() {
    std::cout << "Ball desructor called" << std::endl;
}

Ball::Ball(const Ball & other) : rect(other.rect){
    position.reset(new GameVector(other.position->getComponents()._x, other.position->getComponents()._y));
    velocity.reset(new GameVector(other.velocity->getComponents()._x, other.velocity->getComponents()._y));
    std::cout << "ball copy constructor" << std::endl;
}

Ball::Ball(Ball && other): rect(other.rect) {
    std::cout << "ball move constructor" << std::endl;
    position = std::move(other.position);
    velocity = std::move(other.velocity);
    other.position = nullptr;
}

Ball & Ball::operator=(const Ball & other) {
    std::cout << "ball copy = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    std::move(other.position);
    std::move(other.velocity);
    rect = other.rect;
    return *this;
}

Ball & Ball::operator=(Ball &&other) {
    std::cout << "ball move = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    position = std::move(other.position);
    velocity = std::move(other.velocity);
    rect = other.rect;
    other.position = nullptr;
    return *this;
}

void Ball::Update(std::size_t dt, const std::size_t screen_h, const std::size_t screen_w) {
    auto newPositionY = position.get()->getComponents()._y + velocity.get()->getComponents()._y * dt;
    auto newPositionX = position.get()->getComponents()._x + velocity.get()->getComponents()._x * dt;
    position->setComponents(newPositionX, newPositionY); 
}

void Ball::CollideWithPaddle(Contact contact) {
    position->setComponents(position->getComponents()._x + contact.inside, position->getComponents()._y);
    velocity->setComponents(-velocity->getComponents()._x, velocity->getComponents()._y);
    if (contact.type == CollisionType::top)
    {
        velocity->setComponents(velocity->getComponents()._x, -.75f * BALL_SPEED);
    }
    else if (contact.type == CollisionType::bottom)
    {
        velocity->setComponents(velocity->getComponents()._x, .75f * BALL_SPEED);
    }
}

Contact Ball::VerifyPaddleBallCollision(Paddle* const paddle) {
    float ballLeft = getPosition()->getComponents()._x;
    float ballRight = getPosition()->getComponents()._x + BALL_WIDTH;
    float ballTop = getPosition()->getComponents()._y;
    float ballBottom = getPosition()->getComponents()._y + BALL_HEIGHT;

    float paddleLeft = paddle->getPosition()->getComponents()._x + PADDLE_WIDTH / 2.0;
    float paddleRight = paddle->getPosition()->getComponents()._x + PADDLE_WIDTH / 2.0;
    float paddleTop = paddle->getPosition()->getComponents()._y;
    float paddleBottom = paddle->getPosition()->getComponents()._y + PADDLE_HEIGHT;

    Contact contact;
    contact.type = CollisionType::none;
    contact.inside = 0.0f;

    if (ballLeft >= paddleRight)
    {
        return contact;
    }

    if (ballRight <= paddleLeft)
    {
        return contact;
    }

    if (ballTop >= paddleBottom)
    {
        return contact;
    }

    if (ballBottom <= paddleTop)
    {
        return contact;
    }

    float paddleRangeUpper = paddleBottom - (2.0f * PADDLE_HEIGHT / 3.0f);
    float paddleRangeMiddle = paddleBottom - (PADDLE_HEIGHT / 3.0f);

    if (velocity->getComponents()._x < 0)
    {
        contact.inside = paddleRight - ballLeft;
    }
    else if (velocity->getComponents()._x  > 0)
    {
        contact.inside = paddleLeft - ballRight;
    }

    if ((ballBottom > paddleTop)
        && (ballBottom < paddleRangeUpper))
    {
        contact.type = CollisionType::top;
    }
    else if ((ballBottom > paddleRangeUpper)
            && (ballBottom < paddleRangeMiddle))
    {
        contact.type = CollisionType::middle;
    }
    else
    {
        contact.type = CollisionType::bottom;
    }

    return contact;
}

void Ball::Draw(SDL_Renderer* sdl_renderer) {
    rect.x = static_cast<int>(position->getComponents()._x);
	rect.y = static_cast<int>(position->getComponents()._y);
	SDL_RenderFillRect(sdl_renderer, &rect);
}