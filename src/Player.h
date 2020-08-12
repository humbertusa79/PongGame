#ifndef PLAYER_H
#define PLAYER_H

#include "SDL_ttf.h"
#include <string>

class Player {
    public:
        Player(int score, double x, double y, double w, double h);
        ~Player();
        void setTexture(SDL_Renderer* sdl_renderer);
        void Draw(SDL_Renderer* sdl_renderer);
        int getScore() {
            return score;
        }

        void increaseScore(int value) {
            score += value;
        }

    private:
        SDL_Texture * texture;
        SDL_Rect rect {};
        int score;
};

#endif