#ifndef PADDLE_H
#define PADDLE_H


#include "gameVector.h"
#include "SDL.h"
#include <memory>
#include <string>

static int PADDLE_WIDTH = 50;
static int PADDLE_HEIGHT = 90;
static const float PADDLE_SPEED = 1.0f;

class Paddle {
    public:
        Paddle(std::string identifier, double x, double y, double vx, double vy);
        ~Paddle();
        Paddle(const Paddle & other);
        Paddle(Paddle && other);
        Paddle & operator=(const Paddle & other);
        Paddle & operator=(Paddle &&other);
        void Draw(SDL_Renderer* sdl_renderer);
        void Update(std::size_t dt, const std::size_t screen_h);
        GameVector* getPosition() {
            return position.get();
        }
        void setVelocity(double vx, double vy) {
            velocity.get()->setComponents(vx, vy);
        }
        GameVector* getVelocity() {
            return velocity.get();
        }

    private:
        std::unique_ptr<GameVector> position;
        std::string id;
        std::unique_ptr<GameVector> velocity;
        SDL_Rect rect {};
};

#endif