#include "header.h"
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
