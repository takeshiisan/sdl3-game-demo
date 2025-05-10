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

    RenderWindow window("SDL3", 1280, 720); // RenderwWindow is from RenderWindow.cpp and RenderWindow.hpp

    /* Filepaths to each texture in the game*/
    const char player[] = "/home/nathantan/Documents/001-Code/sdl2/sdl3-game-demo/graphics/kenney_pixel-platformer/Tilemap/tilemap-characters.png"; // PATH TO CHARACTER
    const char worldmap[] = "/home/nathantan/Documents/001-Code/sdl2/sdl3-game-demo/graphics/kenney_pixel-platformer/Tilemap/tilemap-backgrounds_packed.png"; // PATH TO WORLDMAP
    const char tilemap[] = "/home/nathantan/Documents/001-Code/sdl2/sdl3-game-demo/graphics/kenney_pixel-platformer/Tilemap/tilemap.png"; // PATH TO TILEDMAP

    SDL_Texture* playerTexture = window.loadTexture(player);
    SDL_Texture* worldTexture = window.loadTexture(worldmap);
    SDL_Texture* tileTexture = window.loadTexture(tilemap);
    /* 
        SCALES THE TEXTURE GRAPHIC TO NEAREST
    */
    SDL_SetTextureScaleMode(worldTexture,SDL_SCALEMODE_NEAREST);
    SDL_SetTextureScaleMode(playerTexture,SDL_SCALEMODE_NEAREST);

    bool gameRunning = true;

    SDL_Event e;

    /* the heart of the program. this is where different type of events are placed and occurs. keyboard presses, window quits, etc*/
    
    while(gameRunning)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_EVENT_QUIT)
                gameRunning = false;
            if (e.type == SDL_EVENT_KEY_DOWN) {
                /* the pressed key was Escape? */
                if (e.key.key == SDLK_ESCAPE) {
                    gameRunning = false;
                    std::cout << "ESC button pressed. Exiting..\n";
                }
                if(e.key.scancode == SDL_SCANCODE_W) {
                        
                    std::cout << "W key pressed\n";
                }
            }    
        } 
        window.clear();
        window.renderMap(worldTexture);
        window.renderPlayer(playerTexture, 48, 520);
        window.renderPlayer(playerTexture, 128, 520);
        window.renderTile(tileTexture,128,580);
        window.bgcolor(0,255,0,255);
        window.display();
        
    }
    window.cleanUp();
    SDL_Quit();

}

/*
   commit
*/