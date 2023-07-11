#include "header.h"

/**
 * draw_walls - draws wall
 * @maze: 2D array for maze
 * @map: x/y points of current box in maze
 * @rayPos: x/y points of ray position
 * @rayDir: ray direction
 * @perpWallDist: distance to wall fromcamera
 * @x: number of raycasted
 * @side: determines whether wall N/S or E/W was hit
 * @textured: True if textures is enabled and false otherwise
 */
void draw_walls(int *maze, SDL_Point map, vec rayPos, vec rayDir, double perpWallDist, int x, int side, bool textured)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	int tileIndex;
	double wallX;
	SDL_Point tex;
	uint32_t color;
	int width;
	int height;
	int y;

	if (!textured)
	{
		SDL_GetWindowSize(window, &width, &height);
		/*calculate height of line to draw on scree*/
		lineHeight = (int)(height /perpWallDist);
		/*calculate lowest & highest pixel to fill in current stripe*/
		drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;

		/*set wall colors depending on if side face*/
		if (side == 0)
			SDL_SetRenderDrawColor(renderer, 0xF7, 0xF7, 0xF7, 0xFF);
		else if (side == 1)
			SDL_SetRenderDrawColor(renderer, 0xDE, 0xDE, 0xDE, 0xFF);
		/*draw pixel as vertical line*/
		SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
	}
	else
	{
		drawTex_wall();
	}
}

/**
 * drawTex_wall - draws textured floors
 *
 */
void drawTex_wall(void)
{
	 /*calculate height of line to draw on scree*/
                lineHeight = (int)(SCREEN_HEIGHT /perpWallDist);
                /*calculate lowest & highest pixel to fill in current stripe*/
                drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
                if (drawStart < 0)
                        drawStart = 0;
                drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
                if (drawEnd >= SCREEN_HEIGHT)
                        drawEnd = SCREEN_HEIGHT - 1;

		wallX = 0; /*where exactly the wall was hit*/
		if (side == 0)
			wallX = rayPos.y + perpWallDist * rayDir.y;
		else if (side == 1)
		      wallX = rayPos.x + perpWallDist * rayDir.x;
		tileIndex = *((int *)maze + map.x * MAP_WIDTH + map.y) - 1;
		wallX -= floor((wallX));/*floor returns largest int value*/
		/* get X coordinate of texture corresponding to ray hit */
		tex.x = (int)(wallX * (double)TEX_WIDTH);
		if (side == 0 && rayDir.x > 0)
			tex.x = TEX_WIDTH - tex.x - 1;
		if (side == 1 && rayDir.y < 0)
			tex.x = TEX_WIDTH - tex.x - 1;

		for (y = drawStart; y < drawEnd; y++)
		{
			tex.y = ((((y << 1) - SCREEN_HEIGHT + sliceHeight) <<
				  (int)log2(TEX_HEIGHT)) / sliceHeight) >> 1;

			color = tiles[tileIndex][tex.x][tex.y];

			/* change color of the wall depending on wall side */
			if (side == 1)
				color = (color >> 1) & 8355711;

			buffer[y][x] = color;
		}
		/*draw floor and ceiling*/
		drawTex_wall(map, rayDir, perpWallDist, wallX, drawEnd, x, side)
}
