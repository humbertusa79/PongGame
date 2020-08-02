#include "Paddle.h"
#include <iostream>
#include "renderer.h"

Paddle::Paddle(double x, double y, std::unique_ptr<GameVector> velocity)  {
    position =  std::make_unique<GameVector>(GameVector(x,y)); //std::unique_ptr<GameVector>(new GameVector(x, y));
    velocity =  std::move(velocity);
    rect.x = x;
	rect.y = y;
	rect.w = 15;
	rect.h = 60;
}

Paddle::~Paddle() {}

Paddle::Paddle(const Paddle & other) : rect(other.rect){
    position.reset(new GameVector(other.position->getComponents()._x, other.position->getComponents()._y));
    std::cout << "Paddle copy constructor" << std::endl;
}

Paddle::Paddle(Paddle && other): rect(other.rect) {
    std::cout << "Paddle move constructor" << std::endl;
    position = std::move(other.position);
    other.position = nullptr;
}

Paddle & Paddle::operator=(const Paddle & other) {
    std::cout << "Paddle copy = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    std::move(other.position);
    rect = other.rect;
    return *this;
}

Paddle & Paddle::operator=(Paddle &&other) {
    std::cout << "Paddle move = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    position = std::move(other.position);
    rect = other.rect;
    other.position = nullptr;
    return *this;
}

void Paddle::Draw(SDL_Renderer* sdl_renderer) {
    rect.x = static_cast<int>(position->getComponents()._x);
	rect.y = static_cast<int>(position->getComponents()._y);
	SDL_RenderFillRect(sdl_renderer, &rect);
}

void Paddle::Update(double dt) {
    auto newPositionX = velocity.get()->getComponents()._x * dt;
    auto newPositionY = velocity.get()->getComponents()._y * dt;
    auto newPosition = std::make_unique<GameVector>(GameVector(newPositionX, newPositionY));
    position = std::move(newPosition);
    if(position->getComponents()._y < 0) {
        position->setComponents(position->getComponents()._x, 0);
    } else if(position->getComponents()._y > (screen_height - PADDLE_HEIGHT)) {
        position->setComponents(position->getComponents()._x, (screen_height - PADDLE_HEIGHT)); 
    }
}