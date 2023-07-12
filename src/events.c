#include "headers/header.h"
/**
 * poll_events - retrieves events on each frame
 * Return:0 on success
 */
int poll_events(void)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				/* If 'ESC' is pressed*/
				if (key.keysym.scancode == 0X29)
					return (1);
				break;
		}
	}
	return (0);
}


/**
 * movement - move players depending on key pressed
 * @maze: maze
 */
void movement(int *maze)
{
	backForward(maze);
	cameraRotate();
}

/**
 * backForward - checks user input for movement
 * @maze: 2D array defining maze map
 */
void backForward(int *maze)
{
	const uint8_t *keystate; /* current key state */
	double oldTime; /*previous time frame*/
	double frameTime; /*time frame*/
	double moveSpeed; /*move speed*/

	keystate = SDL_GetKeyboardState(NULL);
	oldTime = time;
	time = SDL_GetTicks();
	frameTime = (time - oldTime) / 1000.0;
	moveSpeed = frameTime * 5.0;

	/*move forward*/
	if (keystate[SDL_SCANCODE_W])
	{
		if (!*((int *)maze + (int)(pos.x + dir.x * moveSpeed)
		       * MAP_WIDTH + (int)pos.y))
			pos.x += dir.x * moveSpeed;
		if (!*((int *)maze + (int)pos.x * MAP_WIDTH +
		       (int)(pos.y + dir.y * moveSpeed)))
			pos.y = dir.y * moveSpeed;
	}
	/*move back*/
	if (keystate[SDL_SCANCODE_S])
	{
		if (!*((int *)maze + (int)(pos.x - dir.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x -= dir.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y - dir.y * moveSpeed)))
			pos.y -= dir.y * moveSpeed;
	}
}


/**
 * cameraRotate - checks user input for camera rotation
 */
void cameraRotate(void)
{
	const uint8_t *keystate; /* current key state */
	double oldTime; /*previous time frame*/
	double frameTime; /*time frame*/
	double oldDirX, oldPlaneX; /*previous dir.x and plane.x*/
	double rotateSpeed; /*move speed*/

	keystate = SDL_GetKeyboardState(NULL);
	oldTime = time;
	time = SDL_GetTicks();
	frameTime = (time - oldTime) / 1000.0;
	rotateSpeed = frameTime * 3.0;

	/*rotate left*/
	if (keystate[SDL_SCANCODE_D])
	{
		/*rotate camera direction*/
		oldDirX = dir.x;
		dir.x = dir.x * cos(rotateSpeed) - dir.y * sin(rotateSpeed);
		dir.y = oldDirX * sin(rotateSpeed) + dir.y * cos(rotateSpeed);
		/*rotate camera plane*/
		oldPlaneX = plane.x;
		plane.x = plane.x * cos(rotateSpeed) -
			plane.y * sin(rotateSpeed);
		plane.y = oldPlaneX * sin(rotateSpeed)
			+ plane.y * cos(rotateSpeed);
	}
	/*roate right*/
	if (keystate[SDL_SCANCODE_A])
	{
		/*rotate camera direction*/
		oldDirX = dir.x;
		dir.x = dir.x * cos(-rotateSpeed) - dir.y * sin(-rotateSpeed);
		dir.y = oldDirX * sin(-rotateSpeed) + dir.y * cos(-rotateSpeed);
		/*rotate camera plane*/
		oldPlaneX = plane.x;
		plane.x = plane.x * cos(-rotateSpeed) - plane.y * sin(-rotateSpeed);
		plane.y = oldPlaneX * sin(-rotateSpeed) + plane.y * cos(-rotateSpeed);
	}
}
