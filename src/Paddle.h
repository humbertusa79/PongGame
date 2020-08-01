#ifndef PADDLE_H
#define PADDLE_H


#include "gameVector.h"
#include "SDL.h"
#include <memory>

static int PADDLE_WIDTH = 50;
static int PADDLE_HEIGHT = 250;

class Paddle {
    public:
        Paddle(double x, double y);
        ~Paddle();
        Paddle(const Paddle & other);
        Paddle(Paddle && other);
        Paddle & operator=(const Paddle & other);
        Paddle & operator=(Paddle &&other);
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