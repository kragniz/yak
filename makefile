CC= gcc
LIBS= -lSDL2 -lSDL2_image
CFLAGS= -Wall

all: yak

yak: main.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
