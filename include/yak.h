#ifndef THE_YAKS_ARE_HERE
#define THE_YAKS_ARE_HERE

typedef struct {
    float x;
    float y;
    int x_tile;
    int y_tile;
    double vel;
    SDL_Surface *image;
} Yak;

Yak *yak_new();

void yak_render(Yak *yak, SDL_Surface *surface);

void yak_update(Yak *yak, float time);

#endif
