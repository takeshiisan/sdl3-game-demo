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
        void bgcolor(); //renders a background colour
	//  void render(Entity& p_entity);
	void display();
private:
	    SDL_Window* window;
	    SDL_Renderer* renderer;

};