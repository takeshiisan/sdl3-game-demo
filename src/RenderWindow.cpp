/* INCLUDE LIBS */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <iostream>

/* INCLUDE HEADER FILE OF RENDERWINDOW */
#include "RenderWindow.hpp"
#include "Entity.hpp"
/*-------------------------*/

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, p_w, p_h,SDL_EVENT_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, NULL);
};

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}


void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::bgcolor(int p_r, int p_g, int p_b, int p_a)
{
    SDL_SetRenderDrawColor(renderer,p_r,p_g,p_b,p_a);
}

void RenderWindow::renderPlayer(SDL_Texture* playerTex, float p_x, float p_y)
{
    SDL_FRect sprite_portion = {0,0,24,26};
    SDL_FRect player_position = {p_x,p_y,48,52};
    SDL_RenderTexture(renderer,playerTex,&sprite_portion,&player_position);
}

void RenderWindow::renderMap(SDL_Texture* worldTex)
{
    SDL_FRect sprite_portion = {0,0,96,72};
    SDL_RenderTexture(renderer,worldTex,&sprite_portion,NULL);
}

void RenderWindow::renderTile(SDL_Texture* tileTex, float p_x, float p_y)
{
    SDL_FRect sprite_portion = {0,0,18,18};
    SDL_FRect tile_position = {p_x,p_y,36,36};
    SDL_RenderTexture(renderer,tileTex,&sprite_portion,&tile_position);
}

// commit