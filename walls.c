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
void draw_walls(int *maze, SDL_Point map, vec rayPos, vec rayDir,
		double perpWallDist, int x, int side, bool textured)
{
	int drawStart;
	int drawEnd;
	int tileIndex;
	double wallX;
	SDL_Point tex;
	uint32_t color;
	int y;

	if (!textured)
	{
		drawUntex_walls(side);
	}
	else
	{
		drawTex_walls(side);
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
			tex.y = ((((y << 1) - SCREEN_HEIGHT + lineHeight) <<
				  (int)log2(TEX_HEIGHT)) / lineHeight) >> 1;
			color = tiles[tileIndex][tex.x][tex.y];
			/* change color of the wall depending on wall side */
			if (side == 1)
				color = (color >> 1) & 8355711;
			buffer[y][x] = color;
		}
		draw_floor(map, rayDir, perpWallDist, wallX, drawEnd, x, side)
	}
}


/**
 * drawTex_walls - draws textured walls
 * @side: determines where wall is facing
 */
void drawTex_walls(int side)
{

	int lineHeight;
	int drawStart;
	int drawEnd;

	/*calculate height of line to draw on scree*/
	lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
	/*calculate lowest & highest pixel to fill in current stripe*/
	drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;
}


/**
 * drawUntex_walls - draws untextured walls
 * @side: determines where wall is facing(N/S or E/W)
 */
void drawUntex_walls(int side)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	int width;
	int height;

	SDL_GetWindowSize(window, &width, &height);
	/*calculate height of line to draw on scree*/
	lineHeight = (int)(height / perpWallDist);
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


/**
 * draw_floor - draws textured floor and ceiling
 * @map: X/Y coordinates of box of maze currently in
 * @rayDir: direction of X/Y coordinates of ray position
 * @perpWallDist: distance to wall from camera
 * @wallX: X position of where wall was hit by raycaster
 * @drawEnd: end position of wall slice that was drawn
 * @x: number of ray casted
 * @side: determines whether wall is N/S or E/W
 */
void drawTex_floor(SDL_Point map, vec rayDir, double perpWallDist,
		double wallX, int drawEnd, int x, int side)
{
	vec floorWall; /* X/Y position of floor pixel at bottom of wall */
	vec currentFloor; /* X/Y position of current floor pixel */
	SDL_Point floorTex; /* X/Y position corresponding to texture */
	double weight; /* used to find pos of pixel btwn player and wall */
	double currentDist;
	int y;

	floorPixels(map, rayDir, WallX, side);

	if (drawEnd < 0)
		drawEnd = SCREEN_HEIGHT;

	for (y = drawEnd + 1; y < SCREEN_HEIGHT; y++)
	{
		currentDist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);

		weight = currentDist / PerpWallDist;

		currentFloor.x = weight * floorWall.x + (1.0 - weight) * pos.x;
		currentFloor.y = weight * floorWall.y + (1.0 - weight) * pos.y;

		floorTex.x = (int)(currentFloor.x * TEX_WIDTH) % TEX_WIDTH;
		floorTex.y = (int)(currentFloor.y * TEX_HEIGHT) % TEX_HEIGHT;

		/* add floor texture to buffer */
		buffer[y][x] = tiles[5][floorTex.y][floorTex.x];

		/* add ceiling texture to buffer */
		buffer[SCREEN_HEIGHT - y][x] = tiles[4][floorTex.y][floorTex.x];
	}
}


/**
 * floorPixels - calculates position of the wall depending on the side
 * @map: map used
 * @rayDir: X/Y of ray direction
 * @wallX: x position of where wall was hit
 * @side: is wall N/S or E/W facing
 */
void floorPixels(SDL_Point map, vec rayDir, double wallX, int side)
{
	if (side == 0 && rayDir.x > 0)
	{
		floorWall.x = map.x;
		floorWall.y = map.y + wallX;
	}
	else if (side == 0 && rayDir.x < 0)
	{
		floorWall.x = map.x + 1.0;
		floorWall.y = map.y + wallX;
	}
	else if (side == 1 && rayDir.y > 0)
	{
		floorWall.x = map.x + wallX;
		floorWall.y = map.y;
	}
	else
	{
		floorWall.x = map.x + wallX;
		floorWall.y = map.y + 1.0;
	}
}
