#include <SDL2/SDL.h>

#include "yak.h"

Yak *yak_new() {
    Yak *yak = malloc(sizeof(Yak));
    yak->x = 0;
    yak->y = 0;
    return yak;
}

void yak_render(Yak *yak, SDL_Surface *surface) {
    SDL_Rect offset;
    offset.x = yak->x;
    offset.y = yak->y;
    offset.w = 0;
    offset.h = 0;

    SDL_BlitSurface(yak->image, NULL, surface, &offset);
}
