#include "header.h"

/**
 * main - entry point
 *
 * Return: 0 if successfull
 */

int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);

	/*infinite loop */
	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0,0,0,0);
		SDL_RenderClear(instance.renderer);
		/*drawing goes here*/
		draw_stuff(instance);
		SDL_RenderPresent(instance.renderer);
	}
	return (0);
}
