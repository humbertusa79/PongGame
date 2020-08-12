#include "Player.h"


Player::Player(double x, double y, double w, double h) {
    TTF_Init();
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

Player::~Player(){
    SDL_DestroyTexture(texture);
    TTF_Quit();
    SDL_Quit();
}

void Player::setTexture(SDL_Renderer* sdl_renderer) {
    TTF_Font* font = TTF_OpenFont("../resources/Lemonada-Bold.ttf", 25);
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,"Welcome", color);
    texture = SDL_CreateTextureFromSurface(sdl_renderer,surface);
    TTF_CloseFont(font);
    SDL_FreeSurface(surface);
}

void Player::Draw(SDL_Renderer* sdl_renderer){
    SDL_RenderCopy(sdl_renderer, texture, NULL, &rect);
}