#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class RenderWindow 
{
public:
        RenderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* loadTexture(const char* p_filepath);
        void cleanUp();
        void clear();
        void bgcolor(int p_r, int p_g, int p_b, int p_a); //renders a background colour
	//  void render(Entity& p_entity);
	void display();
        void renderPlayer(SDL_Texture* playerTex, float p_x, float p_y);
        void renderMap(SDL_Texture* worldTex);
        void renderTile(SDL_Texture* tileTex, float p_x, float p_y);
private:
	    SDL_Window* window;
	    SDL_Renderer* renderer;

};

//commit