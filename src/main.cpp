// INCLUDING LIBRARIES/API THE PROGRAM WILL USE
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

// INCLUDING INCLUDE FILES OF THE PROGRAM
#include "RenderWindow.hpp"
#include "Entity.hpp"

float p_x = 48.0;
float p_y = 520.0;
int bulletX = 100;
int screenX = 1280;
int screenY = 720;
float xSpeed = 2.5;
float ySpeed = 2.5;

void fire();

int main() {
    std::cout << "test\n";

    if(!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL_INIT FAILED... SDL ERROR: " << SDL_GetError() << std::endl;
    };

    RenderWindow window("SDL3", screenX, screenY); // RenderwWindow is from RenderWindow.cpp and RenderWindow.hpp
    
    
    // VARIABLES THAT UPDATES TIME
    Uint64 last_tick = 0;
    Uint64 current_tick = 0;
    float delta_time;


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
        SHOOT,
        STOP
    };

    bool gameRunning = true;
    int dir = 0; 
    SDL_Event e;
    
    /* the heart of the program. this is where different type of events are placed and occurs. keyboard presses, window quits, etc*/
    
    while(gameRunning)
    {
        // update
        last_tick = current_tick;
        current_tick = SDL_GetTicks();
        delta_time = (current_tick - last_tick) / 1000.0f;

        while(SDL_PollEvent(&e))
        {
            std::cout << p_x << '\n';
            std::cout << "bullet pos: " << bulletX << '\n';
            std::cout << "posY " << p_y << "\n";
            // bulletX = p_x;
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
                if(e.key.scancode == SDL_SCANCODE_S) { dir = DOWN; };
                if(e.key.scancode == SDL_SCANCODE_W) { dir = UP; };
                }    
                // When key is released
            if (e.type == SDL_EVENT_KEY_UP) {
                if(e.key.scancode == SDL_SCANCODE_D) {
                    std::cout << "D KEY RELEASED\n";
                    dir = STOP;
                };
                if(e.key.scancode == SDL_SCANCODE_A) {
                    std::cout << "A KEY RELEASED\n";
                    dir = STOP;
                };
                if(e.key.scancode == SDL_SCANCODE_W) {
                    std::cout << "W KEY RELEASED\n";
                    dir = STOP;
                };
                if(e.key.scancode == SDL_SCANCODE_S) {
                    std::cout << "S KEY RELEASED\n";
                    dir = STOP;
                };
            }
        } 

        if(p_x >= 1240) {
            p_x = 1240;
        }
        if(p_x <= 0) {
            p_x = 0;
        }
        if(p_y >= 650) {
            p_y = 650;
        }
        if(p_y <= 0) {
            p_y = 0;
        }

        switch(dir)
        {
            case RIGHT:
                    p_x += xSpeed; break; 
            case LEFT: 
                    p_x -= xSpeed; break;
            case STOP:
                p_x = p_x;
                p_y = p_y;
                break;
            case UP:
                    p_y -= ySpeed; break;
            case DOWN:
                    p_y += ySpeed; break;

        }
        

        window.clear();
        window.renderMap(worldTexture);
        window.renderPlayer(playerTexture, p_x, p_y);
        // window.renderPlayer(playerTexture, 128, 520);
        window.renderTile(tileTexture,128.0,580.0);
        window.bgcolor(0,255,0,255);
        window.display();

        SDL_Delay(1);
        
    }
    window.cleanUp();
    SDL_Quit();

}

//supposedly a shoot function for the character but I think I will scratch this later on
void fire(){
    bulletX = p_x;
    for(bulletX;bulletX < screenX;bulletX += 1) {
        if(bulletX > screenX) {break;}
    }
}

/*
   commit
*/
