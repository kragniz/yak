#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
    SDL_Window *window;
    SDL_Surface *screen;
} Game;

typedef struct {
    SDL_Surface *yak;
} Images;

void init_sdl(Game *game) {
    game->window = NULL;
    game->screen = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL_Error: %s\n", SDL_GetError());
    } else {
        game->window = SDL_CreateWindow("Yak", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN);
        if(game->window == NULL) {
            printf("SDL_Error: %s\n", SDL_GetError() );
        } else {
            game->screen = SDL_GetWindowSurface(game->window);
        }
    }
}

void load_images(Images *images) {
    images->yak = NULL;

    images->yak = IMG_Load("resources/yak.png");
    if (images->yak == NULL) {
        printf("Yak image failed to load. SDL_Error: %s\n", SDL_GetError() );
    }
}

int main(int argc, char* args[]) {
    Game *game = malloc(sizeof(Game));
    Images *images = malloc(sizeof(Images));

    init_sdl(game);
    load_images(images);

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL_Error: %s\n", SDL_GetError());
    } else {
        printf("Yaks started\n");


        SDL_FillRect(game->screen, NULL,
                SDL_MapRGB(game->screen->format, 0xAA, 0xAA, 0xAA));
        SDL_BlitSurface(images->yak, NULL, game->screen, NULL );
        SDL_UpdateWindowSurface(game->window);

        SDL_Delay(1000);
    }

    return 0;
}
