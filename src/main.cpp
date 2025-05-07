// INCLUDING LIBRARIES/API THE PROGRAM WILL USE
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

// INCLUDING INCLUDE FILES OF THE PROGRAM
#include "RenderWindow.hpp"
#include "Entity.hpp"

int main() {
    std::cout << "test\n";

    if(!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL_INIT FAILED... SDL ERROR: " << SDL_GetError() << std::endl;
    };

    RenderWindow window("SDL3", 640, 480); // RenderwWindow is from RenderWindow.cpp and RenderWindow.hpp
    
    const char player[] = "/home/nathantan/Documents/001-Code/sdl2/sdl3-game-demo/graphics/kenney_pixel-platformer/Tilemap/tilemap-characters.png"; // PATH TO CHARACTER

    SDL_Texture* playerTexture = window.loadTexture(player);

    bool gameRunning = true;

    SDL_Event event;

    /* the heart of the program. this is where different type of events are placed and occurs. keyboard presses, window quits, etc*/
    
    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT)
                gameRunning = false;
        } 
        window.clear();
        window.renderPlayer(playerTexture);
        window.bgcolor(0,255,0,255);
        window.display();
        

    }
    window.cleanUp();
    SDL_Quit();

}

/*
   commit
*/