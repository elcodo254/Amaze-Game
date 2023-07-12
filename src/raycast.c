#include"header.h"
/**
 * raycaster - cast rays to draw ceiling,floor and walls
 * @maze: 2D array defining maze
 * @textured: true if textures enabled otherwise false
 */
void raycaster(int *maze, bool textured)
{
	double cameraX;
	vec rayPos;/*x/r ray position*/
	vec rayDir;/*x/y ray direction*/
	vec deltaDist;/*length of ray one x/y side to the next*/
	vec sideDist;/*length of ray from current pos to next*/
	double perpWallDist;/*distace from camera to wall*/
	SDL_Point map;/*current box in maze(x/y points)*/
	SDL_Point step;
	int hit;/*wall was hit?*/
	int side;/*which wall was hit?*/
	int x;/*ray counter*/

	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		/*calculate ray position;*/
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
		hit = 0;
		while (hit == 0)/**loop for dda calculations*/
		{
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
			if (*((int *)maze + map.x * MAP_WIDTH + map.y) > 0)
				hit = 1;/*check if ray hit wall*/
		}
		/*calculate distance projected in camera direction*/
		if (side == 0)
			perpWallDist = (sideDist.x - deltaDist.x);
		else
			perpWallDist = (sideDist.y - deltaDist.y);
		draw_walls(maze, map, rayPos, rayDir, perpWallDist, x, side, textured);
	}
	updateRenderer(textured);/*update buffer*/
}
