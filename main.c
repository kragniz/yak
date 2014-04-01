#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "yak.h"
#include "game.h"

typedef struct {
    SDL_Surface *tile_1;
    SDL_Surface *tile_2;
} Images;

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

    Yak *yak = yak_new();
    Images *images = malloc(sizeof(Images));
    images_load(images, yak);

    printf("Yaks started\n");

    SDL_Event e;
    while (!game->quit) {
        if(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                game->quit = true;
            } else if(e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                    case SDLK_UP:
                        yak->vel = -200;
                        break;
                    case SDLK_LEFT:
                        break;
                }
            }

        }

        yak_update(yak, game->t_delta);
        game_tick(game);

        SDL_FillRect(game->screen, NULL,
                SDL_MapRGB(game->screen->format, 0xAA, 0xAA, 0xAA));
        render_background(game, images);
        yak_render(yak, game->screen);

        SDL_UpdateWindowSurface(game->window);
    }

    return 0;
}
