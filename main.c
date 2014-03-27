#include <stdio.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define GAME_WIDTH 12
#define GAME_HEIGHT 8
#define TILE_SIZE 64

typedef struct {
    bool quit;
    SDL_Window *window;
    SDL_Surface *screen;
} Game;

typedef struct {
    int x;
    int y;
    SDL_Surface *image;
} Yak;

typedef struct {
    SDL_Surface *tile_1;
    SDL_Surface *tile_2;
} Images;

enum KeyPresses
{
    KEY_PRESS_UP,
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
};

void init_sdl(Game *game) {
    game->window = NULL;
    game->screen = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL_Error: %s\n", SDL_GetError());
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
}

Game *game_new() {
    Game *game = malloc(sizeof(Game));
    init_sdl(game);
    return game;
}

SDL_Surface *load_image(char *path) {
    SDL_Surface *loc = NULL;
    loc = IMG_Load(path);
    if (loc == NULL) {
        printf("Image '%s' failed to load. SDL_Error: %s\n", path, SDL_GetError());
    }
    return loc;
}

void images_load(Images *images, Yak *yak) {
    yak->image = load_image("resources/yak.png");
    images->tile_1 = load_image("resources/tile_1.png");
    images->tile_2 = load_image("resources/tile_2.png");
}

void render_yak(Game *game, Yak *yak) {
    SDL_Rect offset;
    offset.x = yak->x;
    offset.y = yak->y;
    offset.w = 0;
    offset.h = 0;

    SDL_BlitSurface(yak->image, NULL, game->screen, &offset);
}

void render_background(Game *game, Images *images) {
    SDL_Rect offset;
    offset.x = offset.y = offset.w = offset.h = 0;

    int i;
    int j;
    for (i=0; i < GAME_HEIGHT; i++) {
        for (j=0; j < GAME_WIDTH; j++) {
            offset.x = j * images->tile_1->w;
            offset.y = i * images->tile_1->h;
            if ((j+i) % 2 == 0) {
                SDL_BlitSurface(images->tile_1, NULL, game->screen, &offset);
            } else {
                SDL_BlitSurface(images->tile_2, NULL, game->screen, &offset);
            }
        }
    }
}

int main(int argc, char* args[]) {
    Game *game = game_new();

    Yak *yak = malloc(sizeof(Yak));
    Images *images = malloc(sizeof(Images));
    images_load(images, yak);
    yak->x = 43;
    yak->y = 31;

    printf("Yaks started\n");

    SDL_Event e;
    while (!game->quit) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                game->quit = true;
            }
            SDL_FillRect(game->screen, NULL,
                    SDL_MapRGB(game->screen->format, 0xAA, 0xAA, 0xAA));
            render_background(game, images);
            render_yak(game, yak);

            SDL_UpdateWindowSurface(game->window);
        }
    }

    return 0;
}
