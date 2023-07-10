#ifndef HEADER_H
#define HEADER_H


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TEX_COUNT 6
#define TEX_WIDTH 64 /* must be power of two*/
#define TEX_HEIGHT 64 /* must be power of two*/
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "structs.h"
#include "global.h"

/**
 * struct point_s - defines double vector points
 * @x: point x
 * @y: point y
 */

typedef struct point_s
{
        double x;
        double y;
} point_t;

bool init_instance(void);
int *parseMap(char *filename, int *map);
void draw_World(void);
int poll_events(void);
void close_SDL(void);
void loadTextures(char *mapName)
#endif /*HEADER_H*/
