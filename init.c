#include "header.h"

/**
 * init_instance - initializes sdl
 *
 * Return: True on success, False on failure
 */

bool init_instance(void)
{
	bool success = true;

	window = NULL;
	renderer = NULL;

	/*Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL failed initialise: %s\n", SDL_GetError());
		success = false;
	}
	/*create a new window instance */
	window = SDL_CreateWindow("AMAZE", SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED,
			  SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());

		success = false;
	}

	/*create new Renderer instance linked to the window*/
	renderer = SDL_CreateRenderer(instance->window, -1,
			 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		success = false;
	}
	/*create texture in window*/
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (texture == NULL)
	{
		fprintf(stderr, "SDL_CreateTexture Error: %s\n", SDL_GetError());
		success = false;
	}
	return (success);
}


/**
 * updateRenderer - updates renderer with updated buffer / texture
 * @textured: True if user enabled textures, otherwise False
 * Return: void
 */
void updateRenderer(bool textured)
{
	int x, y; /* loop counters */

	/* draw buffer to renderer */
	if (textured)
	{
		SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * 4);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);

		/* clear buffer */
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			for (y = 0; y < SCREEN_HEIGHT; y++)
			{
				buffer[y][x] = 0;
			}
		}
	}

	/* update screen */
	SDL_RenderPresent(renderer);
}


/**
 * close_SDL - close sdl
 */
void close_SDL(void)
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
