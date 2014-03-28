#include <SDL2/SDL.h>

#include "yak.h"

Yak *yak_new() {
    Yak *yak = malloc(sizeof(Yak));
    yak->x = 0;
    yak->y = 24;
    yak->x_tile = 0;
    yak->y_tile = 0;
    yak->vel = -40;
    return yak;
}

void yak_update(Yak *yak, float t_delta) {
    yak->vel = yak->vel + (50 * t_delta);
    yak->y = yak->y + (yak->vel * t_delta);
}

void yak_render(Yak *yak, SDL_Surface *surface) {
    SDL_Rect offset;
    offset.x = yak->x;
    offset.y = yak->y;
    offset.w = 0;
    offset.h = 0;

    SDL_BlitSurface(yak->image, NULL, surface, &offset);
}
