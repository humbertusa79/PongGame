#ifndef PADDLE_H
#define PADDLE_H


#include "gameVector.h"
#include "SDL.h"
#include <memory>
#include <string>

static int PADDLE_WIDTH = 50;
static int PADDLE_HEIGHT = 50;

class Paddle {
    public:
        Paddle(std::string identifier, double x, double y);
        ~Paddle();
        Paddle(const Paddle & other);
        Paddle(Paddle && other);
        Paddle & operator=(const Paddle & other);
        Paddle & operator=(Paddle &&other);
        void Draw(SDL_Renderer* sdl_renderer);
        void Update(int direction, const std::size_t screen_h);

    private:
        std::unique_ptr<GameVector> position;
        std::unique_ptr<GameVector> velocity;
        std::string id;
        SDL_Rect rect {};
};

#endif