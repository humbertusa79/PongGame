#ifndef PLAYER_H
#define PLAYER_H

#include "SDL_ttf.h"

class Player {
    public:
        Player(double x, double y, double w, double h);
        ~Player();
        void setTexture(SDL_Renderer* sdl_renderer);
        void Draw(SDL_Renderer* sdl_renderer);

    private:
        SDL_Texture * texture;
        SDL_Rect rect {};
};

#endif