#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

class Entity
{
public:
    Entity();
    void player_1();
private:
    SDL_Texture* p_1;
};