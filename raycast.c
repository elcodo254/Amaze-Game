#include"header.h"
/**
 * raycaster - cast rays to draw ceiling,floor and walls
 * @maze: 2D array defining maze
 * @textured: true if textures enabled otherwise false
 */
void raycaster(int *maze, bool textured)
{
	double perpWallDist; /*distance of perpendicular ray to wall*/
	SDL_Point step; /* x/y direction to step in*/
	int hit;/*check if wall was hit*/
	int side;/*which wall was hit N/S or E/W*/

	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		initial_calculations();
		/*perform DDA(Digital Differential Analysis)*/
		hit = 0;
		while (hit == 0)
		{
			/*jump to next map square*/
			if (sideDist.x < sideDist.y)
			{
				sideDist.x += deltaDist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				sideDist.y += deltaDist.y;
				map.y += step.y;
				side = 1;
			}
			/*check if ray hit a wall*/
			if (*((int *)maze + map + map.x * MAP_WIDTH + map.y) > 0)
				hit = 1;
		}
		/*calculate distance projected in camera direction*/
		if (side == 0)
			perpWallDist = (sideDist.x - deltaDist.x);
		else
			perpWallDist = (sideDist.y - deltaDist.y);
		draw_walls(maze, map, rayDir, perpWallDist, x, side, textured);
	}
	/* update buffer*/
	updateRenderer(textured);
}


/**
 * init_calculations - initial computations for DDA
 */
void init_calculations(void)
{
	/*calculate ray position and direction*/
	cameraX = 2 * x / (double)(SCREEN_WIDTH) - 1;
	rayPos.x = pos.x;
	rayPos.y = pos.y;
	rayDir.x = dir.x + plane.x * cameraX;
	rayDir.y = dir.y + plane.y * cameraX;
	map.x = (int)(rayPos.x);
	map.y = (int)(rayPos.y);
	/*calculate length of ray to next x/y-side*/
	deltaDist.x = sqrt(1 + (pow(rayDir.y, 2)) / pow(rayDir.x, 2));
	deltaDist.y = sqrt(1 + (pow(rayDir.x, 2)) / pow(rayDir.y, 2));
	/*calculate step and initial sideDist*/
	if (rayDir.x < 0)
	{
		step.x = -1;
		sideDist.x = (rayPos.x - map.x) * deltaDist.x;
	}
	else
	{
		step.x = 1;
		sideDist.x = (map.x + 1.0 - rayPos.x) * deltaDist.x;
	}
	if (rayDir.y < 0)
	{
		step.y = -1;
		sideDist.y = (rayPos.y - map.y) * deltaDist.y;
	}
	else
	{
		step.y = 1;
		sideDist.y = (map.y + 1.0 - rayPos.y) * deltaDist.y;
	}
}
