#include <SDL2/SDL.h>

#include "yak.h"
#include "game.h"

void yak_render(Game *game, Yak *yak) {
    SDL_Rect offset;
    offset.x = yak->x;
    offset.y = yak->y;
    offset.w = 0;
    offset.h = 0;

    SDL_BlitSurface(yak->image, NULL, game->screen, &offset);
}

Yak *yak_new() {
    Yak *yak = malloc(sizeof(Yak));
    yak->x = 0;
    yak->y = 0;
    return yak;
}
