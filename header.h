#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <SDL2/SDL.H>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

/**
 * struct SDL_Instance - defines struct holding ref to renederer and window
 * @renderer: pointer to sdl renderer
 * @window: pointer to sdl window
 */

typedef struct SDL_Instance
{
	SDL_Renderer *renderer;
	SDL_Window *window;
} SDL_Instance;

int init_instance(SDL_Instance *);

#endif /*HEADER_H*/
