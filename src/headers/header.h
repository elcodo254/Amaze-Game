#ifndef HEADER_H
#define HEADER_H

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TEX_COUNT 6
#define TEX_WIDTH 64 /* must be power of two*/
#define TEX_HEIGHT 64 /* must be power of two*/
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "structs.h"
#include "global.h"


int *parseMap(char *filename, int *map);
void loadTextures(char *mapName);
bool init_instance(void);
void updateRenderer(bool textured);
void draw_World(void);
void draw_walls(int *maze, SDL_Point map, vec rayPos, vec rayDir,
                double perpWallDist, int x, int side, bool textured);
void drawTex_floor(SDL_Point map, vec rayDir, double perpWallDist,
                double wallX, int drawEnd, int x, int side);
void raycaster(int *maze, bool textured);
void movement(int *maze);
bool poll_events(void);
void close_SDL(void);
#endif /*HEADER_H*/
