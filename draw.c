#include "header.h"
/**
 * draw_stuff - draws a simple line
 * @instance: instance of Instance structure
 */
void draw_stuff(SDL_Instance instance)
{
	SDL_SetRenderDrawColor(instance.renderer, 96, 128, 255, 255);
	SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}
