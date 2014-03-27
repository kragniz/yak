CC= gcc
LIBS= -lSDL2 -lSDL2_image
CFLAGS= -Wall -Werror -std=c99 -I.
DEPS= yak.h game.h
OBJ = main.o yak.o

all: yak

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

yak: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm *.o
	rm yak
