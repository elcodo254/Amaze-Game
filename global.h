#ifndef GLOBAL_H
#define GLOBAL_H

/* renderers*/
extern SDL_Window *widow;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;

/*texture buffer*/
extern uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
extern uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
/*vector - position*/
extern vec pos;
/*vector - direction*/
extern vec dir;
/*vector - camera plane*/
extern vec plane;
/*current frame time*/
extern double time;

#endif /*GLOBAL_H*/
