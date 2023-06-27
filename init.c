#include "header.h"

/**
 * init_instance - initializes sdl instance
 * @instance: pointer to an instance
 *
 * Return: 0 on success or negative error code on failure
 */

int init_instance(SDL_Instance *instance)
{
	/*Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL failed to initialise:
				 %s\n", SDL_GetError());
		return (1);
	}
	/*create a new window instance */
	instance->window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED,
			  SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/*create new Renderer instance linked to the window*/
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
			 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
