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
    int x;
    int y;
    SDL_Surface *image;
} Yak;

void init_sdl(Game *game) {
    game->window = NULL;
    game->screen = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL_Error: %s\n", SDL_GetError());
    } else {
        game->window = SDL_CreateWindow("Yak", 
                SDL_WINDOWPOS_UNDEFINED,
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

void load_images(Yak *yak) {
    yak->image = NULL;

    yak->image = IMG_Load("resources/yak.png");
    if (yak->image== NULL) {
        printf("Yak image failed to load. SDL_Error: %s\n", SDL_GetError() );
    }
}

void render_yak(Game *game, Yak *yak) {
    SDL_Rect offset;
    offset.x = yak->x;
    offset.y = yak->y;
    offset.w = 0;
    offset.h = 0;

    SDL_BlitSurface(yak->image, NULL, game->screen, &offset);
}

int main(int argc, char* args[]) {
    Game *game = malloc(sizeof(Game));
    init_sdl(game);

    Yak *yak = malloc(sizeof(Yak));
    load_images(yak);
    yak->x = 43;
    yak->y = 31;

    printf("Yaks started\n");

    SDL_FillRect(game->screen, NULL, SDL_MapRGB(game->screen->format, 0xAA, 0xAA, 0xAA));
    render_yak(game, yak);

    SDL_UpdateWindowSurface(game->window);

    SDL_Delay(1000);

    return 0;
}
