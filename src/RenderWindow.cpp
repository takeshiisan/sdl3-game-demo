/* INCLUDE LIBS */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

/* INCLUDE HEADER FILE OF RENDERWINDOW */

#include "../include/RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, p_w, p_h,SDL_EVENT_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, NULL);
};

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