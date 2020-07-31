#include "Ball.h"
#include <iostream>

Ball::Ball(double x, double y)  {
    position = std::unique_ptr<GameVector>(new GameVector(x, y));
    rect.x = x;
	rect.y = y;
	rect.w = 15;
	rect.h = 15;
}

Ball::~Ball() {}

Ball::Ball(const Ball & other) : position(std::move(other.position.get())) , rect(other.rect){
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
    std::cout << "pos X =" << position->getComponents()._x << std::endl;
    std::cout << "pos Y =" << position->getComponents()._y << std::endl;
    rect.x = static_cast<int>(position->getComponents()._x);
	rect.y = static_cast<int>(position->getComponents()._y);
	SDL_RenderFillRect(sdl_renderer, &rect);
}