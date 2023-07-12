#include "headers/header.h"

/*global variable*/
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
vec pos;
vec dir;
vec plane;
double time;


/**
 * main - entry point
 * @argc: arguments count
 * @argv: pointer to arguments vector
 *
 * Return: 0 if successfull, 1 on failure
 */

int main(int argc, char *argv[])
{
	int *maze; /*2D array defining maze map*/
	char *mapName;
	bool textured;

	/* x and y start position*/
	pos.x = 22;
	pos.y = 12;
	/*initial direction vector*/
	dir.x = -1;
	dir.y = 0;
	/*the 2d raycaster version of camera plane*/
	plane.x = 0;
	plane.y = 0.66;
	/*time of current frame*/
	time = 0;

	mapName = "\0";
	textured = true;
	if (argc == 3)
	{
		if (strcmp(argv[2], "untex") == 0)
			textured = false;
		mapName = argv[1];
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1], "untex") == 0)
		{
			mapName = "maps/map_0";
			textured = false;
		}
		else
			mapName = argv[1];
	}
	else if (argc == 1)
		mapName = "maps/map_0";

	/*start SDL and create window and renderer*/
	if (init_instance() != 0)
		return (1);
	/*parse maze file*/
	maze = NULL;
	maze = parseMap(mapName, maze);
	if (maze == NULL)
		return (1);

	if (textured)
		loadTextures(mapName);

	/*infinite loop */
	while (!poll_events())
	{
		if (!textured)
			draw_World();/*flat */
		raycaster(maze, textured);
		movement(maze);
	}
	close_SDL();
	free(maze);
	return (0);
}
