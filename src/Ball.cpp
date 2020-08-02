#include "Ball.h"
#include <iostream>

Ball::Ball(double x, double y)  {
    position = std::make_unique<GameVector>(x,y);
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
    std::cout << "ball copy constructor" << std::endl;
}

Ball::Ball(Ball && other): rect(other.rect) {
    std::cout << "ball move constructor" << std::endl;
    position = std::move(other.position);
    other.position = nullptr;
}

Ball & Ball::operator=(const Ball & other) {
    std::cout << "ball copy = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    std::move(other.position);
    rect = other.rect;
    return *this;
}

Ball & Ball::operator=(Ball &&other) {
    std::cout << "ball move = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    position = std::move(other.position);
    rect = other.rect;
    other.position = nullptr;
    return *this;
}

void Ball::Draw(SDL_Renderer* sdl_renderer) {
    rect.x = static_cast<int>(position->getComponents()._x);
	rect.y = static_cast<int>(position->getComponents()._y);
	SDL_RenderFillRect(sdl_renderer, &rect);
}