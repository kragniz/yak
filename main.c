#include <stdio.h>
#include "SDL2/SDL.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;

    SDL_Surface* screen = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL_Error: %s\n", SDL_GetError());
    } else {
        printf("Yaks started\n");
        window = SDL_CreateWindow("Yak", SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED,
                                         SCREEN_WIDTH,
                                         SCREEN_HEIGHT,
                                         SDL_WINDOW_SHOWN);
        if(window == NULL) {
            printf( "SDL_Error: %s\n", SDL_GetError() );
        } else {
            screen = SDL_GetWindowSurface(window);

            // fill white
            SDL_FillRect(screen, NULL,
                         SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);

            SDL_Delay(2000);
        }
    }

    return 0;
}
