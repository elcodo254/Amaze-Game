#include "header.h"
/**
 * draw_World - draws plain ceiling and floor
 */
void draw_World(void)
{
	SDL_Rect ceiling;
	SDL_Rect floor;
	int width;
	int height;

	SDL_GetWindowSize(window, &width, &height);

	ceiling.x = 0;
	ceiling.y = 0;
	ceiling.w = width;
	ceiling.h = height / 2;

	floor.x = 0;
	floor.y = height / 2;
	floor.w = width;
	dloor.h = height / 2;

	/*draw floor*/
	SDL_SetRenderDrawColor(renderer, 0x59, 0x85, 0x94, 0xFF);
	SDL_RenderFillRect(renderer, &ceiling);

	/*draw floor*/
	SDL_SetRenderDrawColor(renderer, 0x1E, 0x29, 0x34, 0xFF);
	SDL_SetRenderFillRect(renderer, &floor);
}
