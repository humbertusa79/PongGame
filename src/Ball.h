#ifndef BALL_H
#define BALL_H


#include "gameVector.h"
#include "SDL.h"
#include <memory>

static int BALL_WIDTH = 50;
static int BALL_HEIGHT = 50;

class Ball {
    public:
        Ball(double x, double y);
        ~Ball();
        Ball(const Ball & other);
        Ball(Ball && other);
        Ball & operator=(const Ball & other);
        Ball & operator=(Ball &&other);
        void Draw(SDL_Renderer* sdl_renderer);

        void setPosition(GameVector* pos) {;
            position = std::make_unique<GameVector>(*pos);
        }

        GameVector* getPosition() {
            return position.get();
        }

        void setRect(SDL_Rect rectangle) {
            rect = rectangle;
        }

        SDL_Rect getRect() {
            return rect;
        }

    private:
        std::unique_ptr<GameVector> position;
        SDL_Rect rect {};
};

#endif