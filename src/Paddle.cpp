#include "Paddle.h"
#include <iostream>
#include "renderer.h"

Paddle::Paddle(std::string identifier, double x, double y, double vx, double vy)  {
    position =  std::make_unique<GameVector>(x,y);
    velocity =  std::make_unique<GameVector>(vx, vy);
    rect.x = position.get()->getComponents()._x;
	rect.y = position.get()->getComponents()._y;
	rect.w = 15;
	rect.h = 60;
    id = identifier;
}

Paddle::~Paddle() {
    std::cout << "Paddle desructor called" << std::endl;
}

Paddle::Paddle(const Paddle & other) : rect(other.rect){
    position.reset(new GameVector(other.position->getComponents()._x, other.position->getComponents()._y));
    velocity.reset(new GameVector(other.velocity->getComponents()._x, other.velocity->getComponents()._y));
    std::cout << "Paddle copy constructor" << std::endl;
}

Paddle::Paddle(Paddle && other): rect(other.rect) {
    std::cout << "Paddle move constructor" << std::endl;
    position = std::move(other.position);
    velocity = std::move(other.velocity);
    other.position = nullptr;
}

Paddle & Paddle::operator=(const Paddle & other) {
    std::cout << "Paddle copy = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    std::move(other.position);
    std::move(other.velocity);
    rect = other.rect;
    return *this;
}

Paddle & Paddle::operator=(Paddle &&other) {
    std::cout << "Paddle move = operator" << std::endl;
    if(this == &other) {
        return *this;
    }
    position = std::move(other.position);
    velocity = std::move(other.velocity);
    rect = other.rect;
    other.position = nullptr;
    return *this;
}

void Paddle::Draw(SDL_Renderer* sdl_renderer) {
    rect.x = static_cast<int>(position->getComponents()._x);
	rect.y = static_cast<int>(position->getComponents()._y);
	SDL_RenderFillRect(sdl_renderer, &rect);
}

void Paddle::Update(std::size_t dt, const std::size_t screen_h) {
    auto newPositionY = position.get()->getComponents()._y + velocity.get()->getComponents()._y * dt;
    auto positionX = position.get()->getComponents()._x;
    if(newPositionY < 0) {
        newPositionY = 0;
    } else if(newPositionY > (screen_h - PADDLE_HEIGHT)) {
        newPositionY = screen_h - PADDLE_HEIGHT;
    }
    position->setComponents(positionX, newPositionY);   
}