CC= gcc
LIBS= -lSDL2 -lSDL2_image
CFLAGS= -Wall -Werror -std=c99 -I include

IDIR=include
_DEPS= yak.h game.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR=obj
_OBJ = main.o yak.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: yak

$(ODIR)/%.o: %.c $(DEPS)
	mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

yak: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

run: yak
	./yak

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
