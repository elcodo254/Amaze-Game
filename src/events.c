#include "headers/header.h"
/**
 * poll_events - retrieves events on each frame
 * Return:0 on success
 */
bool poll_events(void)
{
	SDL_Event event;
	SDL_KeyboardEvent key;
	bool quit;

	quit = false;
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				key = event.key;
				/* If 'ESC' is pressed*/
				if (key.keysym.scancode == 0X29)
				quit = true;
				break;
		}
	}
	return (quit);
}


/**
 * movement - move players depending on key pressed
 * @maze: maze
 */
void movement(int *maze)
{
	const uint8_t *keystate; /* current key state */
	double oldTime; /*previous time frame*/
	double frameTime; /*time frame*/
	double moveSpeed; /*move speed*/
	double oldDirX, oldPlaneX; /*previous x points od dir plane*/
	double rotateSpeed;/*rotate speed*/
	keystate = SDL_GetKeyboardState(NULL);
	oldTime = time;
	time = SDL_GetTicks();
	frameTime = (time - oldTime) / 1000.0;
	moveSpeed = frameTime * 5.0;
	rotateSpeed = frameTime * 3.0;

	/*move forward*/
	if (keystate[SDL_SCANCODE_W])
	{
		if (!*((int *)maze + (int)(pos.x + dir.x * moveSpeed)
		       * MAP_WIDTH + (int)pos.y))
			pos.x += dir.x * moveSpeed;
		if (!*((int *)maze + (int)pos.x * MAP_WIDTH +
		       (int)(pos.y + dir.y * moveSpeed)))
			pos.y += dir.y * moveSpeed;
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

	/*strafe left*/
	if (keystate[SDL_SCANCODE_Q])
	{
		if (!*((int *)maze + (int)(pos.x - plane.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x -= plane.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y - plane.y * moveSpeed)))
			pos.y -= plane.y * moveSpeed;
	}
	/*strafe right*/
	if (keystate[SDL_SCANCODE_E])
	{
		if (!*((int *)maze + (int)(pos.x + plane.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x += plane.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y + plane.y * moveSpeed)))
			pos.y += plane.y * moveSpeed;
	}


	/*rotate left*/
	if (keystate[SDL_SCANCODE_A])
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
	if (keystate[SDL_SCANCODE_D])
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
