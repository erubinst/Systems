# Makefile for hello.c
# Nuriel Leve and Esme Rubinstein

CFLAGs = -g -pedantix -std=c99 -Wall -Wextra

all: hello rot128 diamond

# hello target
hello: hello.o
	gcc $(CFLAGS) -o hello hello.o

hello.o: hello.c
	gcc $(CFLAGS) -c hello.c

clean:
	rm -f *.o hello rot128 diamond

# rot128 target
rot128: rot128.o
	gcc $(CFLAGS) -o rot128 rot128.o

rot128.o: rot128.c
	gcc $(CFLAGS) -c rot128.c

#diamond target
diamond: diamond.o
	gcc $(CFLAGS) -o diamond diamond.o

diamond.o: diamond.c
	gcc $(CFLAGS) -c diamond.c



