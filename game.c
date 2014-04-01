#include <SDL2/SDL.h>

#include "game.h"

Game *game_new() {
    Game *game = malloc(sizeof(Game));
    game->window = NULL;
    game->screen = NULL;
    game->t_last = 0;
    game->t_delta = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Error: %s\n", SDL_GetError());
    } else {
        game->window = SDL_CreateWindow("Yak", 
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                GAME_WIDTH * TILE_SIZE,
                GAME_HEIGHT * TILE_SIZE,
                SDL_WINDOW_SHOWN);
        if(game->window == NULL) {
            printf("SDL_Error: %s\n", SDL_GetError() );
        } else {
            game->screen = SDL_GetWindowSurface(game->window);
        }
    }
    return game;
}

void game_tick(Game *game) {
    Uint32 t_current = SDL_GetTicks();
    game->t_delta = (t_current - game->t_last) / 1000.0f;
    game->t_last = t_current;
}
