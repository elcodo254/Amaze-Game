#include "header.h"

/**
 * loadTextures - loads textures for the walls and ceiling
 * @mapName: name of loaded map
 */
void loadTextures(char *mapName)
{
	/*array of loaded textures*/
	SDL_Surface *texSrc[TEX_COUNT];
	uint8_t *pixel;/*color value*/
	int i, j, k;/*loop counters*/

	if (strcmp(mapName, "maps/map_0") == 0)
	{
		texSrc[0] = IMG_Load("textures/wall1.png");
		texSrc[1] = IMG_Load("textures/wall2.png");
		texSrc[2] = IMG_Load("textures/windowtree.png");
		texSrc[3] = IMG_Load("textures/windowspooky.png");
		texSrc[4] = IMG_Load("textures/ceiling.png");
		texSrc[5] = IMG_Load("textures/floorboards.png");
	}
	else
	{
		texSrc[0] = IMG_Load("textures/hedge1.png");
		texSrc[1] = IMG_Load("textures/hedge2.png");
		texSrc[2] = IMG_Load("textures/gate.png");
		texSrc[3] = IMG_Load("textures/hedge1.png");
		texSrc[4] = IMG_Load("textures/sky.png");
		texSrc[5] = IMG_Load("textures/grass.png")
	}
	/* get colors from texture pixel*/
	for (i = 0; i < TEX_COUNT; i++)
	{
		for (j = 0; j < TEX_HEIGHT; j++)
		{
			for (k = 0; k < TEX_WIDTH; k++)
			{
				pixel = (uint8_t *)texSrc[i]->pixels
					+k * texSrc[i]->pitch +
					j * texSrc[i]->format->BytesPerPixel;
				tiles[i][j][k] = pixel[0] | pixel[1] << 8 | pixel[2] << 16;
			}
		}
	}
	/*free SDL_SSurfaces*/
	for (i = 0; i < TEX_COUNT; i++)
	{
		SDL_FreeSurface(texSrc[i]);
		texSrc[i] = NULL;
	}
}
