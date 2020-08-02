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

void Ball::Update(std::size_t dt) {
    auto newPositionY = position.get()->getComponents()._y + velocity.get()->getComponents()._y * dt;
    auto positionX = position.get()->getComponents()._x * velocity.get()->getComponents()._x * dt;
    position->setComponents(positionX, newPositionY); 
}

void Ball::Draw(SDL_Renderer* sdl_renderer) {
    rect.x = static_cast<int>(position->getComponents()._x);
	rect.y = static_cast<int>(position->getComponents()._y);
	SDL_RenderFillRect(sdl_renderer, &rect);
}