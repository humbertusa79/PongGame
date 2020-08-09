#ifndef BALL_H
#define BALL_H


#include "gameVector.h"
#include "SDL.h"
#include <memory>
#include "Paddle.h"

static int BALL_WIDTH = 50;
static int BALL_HEIGHT = 50;
static const float BALL_SPEED = 1.0f;

enum class CollisionType {
    none,
    bottom,
    middle,
    top,
    left,
    right
};

struct Contact {
    CollisionType type;
    float inside;
};

class Ball {
    public:
        Ball(double x, double y, double vx, double vy);
        ~Ball();
        Ball(const Ball & other);
        Ball(Ball && other);
        Ball & operator=(const Ball & other);
        Ball & operator=(Ball &&other);
        void Draw(SDL_Renderer* sdl_renderer);
        void Update(std::size_t dt, const std::size_t screen_h, const std::size_t screen_w);
        void CollideWithPaddle(Contact contact);
        Contact VerifyPaddleBallCollision(Paddle* const paddle);
        Contact VerifyWallCollision(const std::size_t screen_h, const std::size_t screen_w);
        void CollideWithWall(Contact contact, const std::size_t screen_h, const std::size_t screen_w);
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
        std::unique_ptr<GameVector> velocity;
        SDL_Rect rect {};
};

#endif