#ifndef THE_YAKS_ARE_HERE
#define THE_YAKS_ARE_HERE

typedef struct {
    int x;
    int y;
    double vel;
    SDL_Surface *image;
} Yak;

Yak *yak_new();

void yak_render(Yak *yak, SDL_Surface *surface);

#endif
