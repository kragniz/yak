#ifndef YAK_GAME
#define YAK_GAME

#include <stdbool.h>

#define GAME_WIDTH 12
#define GAME_HEIGHT 8
#define TILE_SIZE 64

typedef struct {
    bool quit;
    Uint32 t_last;
    float t_delta;
    SDL_Window *window;
    SDL_Surface *screen;
} Game;

Game *game_new();

void game_tick(Game *game);

#endif
