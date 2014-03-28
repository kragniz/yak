#ifndef THE_YAKS_ARE_HERE
#define THE_YAKS_ARE_HERE

#include "game.h"

typedef struct {
    int x;
    int y;
    double vel;
    SDL_Surface *image;
} Yak;

Yak *yak_new();

void yak_render(Game *game, Yak *yak);

#endif
