#ifndef YAK_GAME
#define YAK_GAME
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct {
    bool quit;
    SDL_Window *window;
    SDL_Surface *screen;
} Game;

#endif
