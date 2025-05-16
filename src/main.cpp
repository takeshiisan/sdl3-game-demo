// INCLUDING LIBRARIES/API THE PROGRAM WILL USE
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

// INCLUDING INCLUDE FILES OF THE PROGRAM
#include "RenderWindow.hpp"
#include "Entity.hpp"

int p_x = 48;
int bulletX = p_x;
int screenX = 1280;
int screenY = 720;

int main() {
    std::cout << "test\n";

    if(!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL_INIT FAILED... SDL ERROR: " << SDL_GetError() << std::endl;
    };

    RenderWindow window("SDL3", screenX, screenY); // RenderwWindow is from RenderWindow.cpp and RenderWindow.hpp

    /* Filepaths to each texture in the game*/
    const char player[] = "../graphics/kenney_pixel-platformer/Tilemap/tilemap-characters.png"; // PATH TO CHARACTER
    const char worldmap[] = "../graphics/kenney_pixel-platformer/Tilemap/tilemap-backgrounds_packed.png"; // PATH TO WORLDMAP
    const char tilemap[] = "../graphics/kenney_pixel-platformer/Tilemap/tilemap.png"; // PATH TO TILEDMAP
    const char bullet[] = "../graphics/kenney_pixel-platformer/Tilemap/tilemap-characters.png";

    SDL_Texture* playerTexture = window.loadTexture(player);
    SDL_Texture* worldTexture = window.loadTexture(worldmap);
    SDL_Texture* tileTexture = window.loadTexture(tilemap);
    SDL_Texture* bulletTexture = window.loadTexture(bullet);
    /* 
        SCALES THE TEXTURE GRAPHIC TO NEAREST
    */
    SDL_SetTextureScaleMode(worldTexture,SDL_SCALEMODE_NEAREST);
    SDL_SetTextureScaleMode(playerTexture,SDL_SCALEMODE_NEAREST);
    SDL_SetTextureScaleMode(bulletTexture,SDL_SCALEMODE_NEAREST);

    /* 
        Bellow is the enumarations 
        for each direction for the player
    */

    enum Direction {    
        DOWN,
        LEFT,
        RIGHT, 
        UP,
        SHOOT
    };

    bool gameRunning = true;
    int dir = 0; 
    SDL_Event e;
    Uint32 lastTicks = SDL_GetTicks();
    /* the heart of the program. this is where different type of events are placed and occurs. keyboard presses, window quits, etc*/
    
    while(gameRunning)
    {
        // Uint32 nowTicks = SDL_GetTicks();

        // // Dt in seconds
        // float deltaTime = (nowTicks - lastTicks) * 0.001f;
        
        // lastTicks = nowTicks;

        while(SDL_PollEvent(&e))
        {
            std::cout << p_x << '\n';
            if(e.type == SDL_EVENT_QUIT)
                gameRunning = false;
            if (e.type == SDL_EVENT_KEY_DOWN) {
                /* the pressed key was Escape? */
                if (e.key.key == SDLK_ESCAPE) {
                    gameRunning = false;
                    std::cout << "ESC button pressed. Exiting..\n";
                }
                if(e.key.scancode == SDL_SCANCODE_D) { dir = RIGHT; };
                if(e.key.scancode == SDL_SCANCODE_A) { dir = LEFT; };
                if(e.key.scancode == SDL_SCANCODE_S) {
                    dir = SHOOT;
                };
            }    
        } 
        switch(dir)
        {
            case RIGHT:
                    p_x += 1; break; 
            case LEFT: 
                    p_x -= 1; break;
            case SHOOT: 
                bulletX += 1;
                break;

        }

        if(p_x >= screenX) {
            p_x = 1200;
        }
        if(p_x <= 0) {
            p_x = 0;
        }

        // MOVEMENT OF PLAYER
        //


        window.clear();
        // window.renderPlayer(bulletTexture, bulletX, 820);
        // window.renderMap(worldTexture);
        // window.renderPlayer(playerTexture, p_x, 520);
        // window.renderPlayer(playerTexture, 128, 520);
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
