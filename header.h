#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <SDL_IMAGE.H>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "global.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TEX_COUNT 6
#define TEX_WIDTH 64 /* must be power of two*/
#define TEX_HEIGHT 64 /* must be power of two*/
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/**
 * struct vector - defines double vector points
 * @x: point x
 * @y: point y
 */

typedef struct vector
{
	double x;
	double y;
} vec;


bool init_instance(void);
void draw_floor(SDL_Instance instance, vectors vecs);
int poll_events(void);
#endif /*HEADER_H*/
