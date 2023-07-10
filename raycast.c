#include"header.h"
/**
 * raycaster - cast rays to draw ceiling,floor and walls
 * @maze: 2D array defining maze
 * @textured: true if textures enabled otherwise false
 */
void raycaster(int *maze, bool textured)
{
	double cameraX;/*x-coordinate in camera space*/
	double perpWallDist; /*distance of perpendicular ray to wall*/
	vec rayPos;    /*x/y coordinates of ray position*/
	vec rayDir;    /*x/y points of ray direction*/
	vec sideDist; /* length of ray from current position to next x/y-side*/
	vec deltaDist; /*length of ray from one x/y-side to next x/y-side*/
	SDL_Point map; /*x/y points for box of the we are in*/
	SDL_Point step; /* x/y direction to step in*/

	int hit;/*check if wall was hit*/
	int side;/*which wall was hit N/S or E/W*/

	int x;/*ray counter*/

	/*cast ray for every column*/
	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		/*calculate ray position and direction*/
		cameraX = 2 * x / (double)(SCREEN_WIDTH) - 1;
		/*ray position starts at players initial position*/
		rayPos.x = pos.x;
		rayPos.y = pos.y;
		/*ray direction*/
		rayDir.x = dir.x + plane.x * cameraX;
		rayDir.y = dir.y + plane.y * cameraX;

		/*current box on the map*/
		map.x = (int)(rayPos.x);
		map.y = (int)(rayPos.y);
		/*calculate length of ray to next x/y-side*/
		deltaDist.x = sqrt(1 + (pow(rayDir.y, 2)) / pow(rayDir.x, 2));	
		deltaDist.y = sqrt(1 + (pow(rayDir.x, 2)) / pow(rayDir.y, 2));
		/*calculate step and initial sideDist*/
		if (rayDir.x < 0)
		{
			step.x = -1;
			sideDist.x = (pos.x - map.x) * deltaDist.x;
		}
		else
		{
			step.x = 1;
			sideDist.x = (map.x + 1.0 - rayPos.x) * deltaDist.x;
		}
		if (rayDir.y < 0)
		{
			step.y = -1;
			sideDist.y = (map.y + 1.0 - rayPos.x) * deltaDist.y;
		}
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
			if (*((int *)maze + map + map.x * MAP_WIDTH +map.y) > 0)
				hit = 1;
		}
		/*calculate distance projected in camera direction*/
		if (side == 0)
			perpWallDist = (sideDist.x - deltaDist.x);
		else
			perpWallDist = (sideDist.y - deltaDist.y);
	}
	/* update buffer*/
	updateRenderer(textured);
}
