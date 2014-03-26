CC= gcc
LIBS= -lSDL2

all: yak

yak: main.c
	$(CC) $< -o $@ $(LIBS)
