# Makefile for hw-06 programs
# Nuriel Leve and Esme Rubinstein

CFLAGs = -g -pedantix -std=c99 -Wall -Wextra

all: sort mystrtol

# sort target
sort: sort.o mystrtol.o
	gcc $(CFLAGS) -o sort sort.c mystrtol.o 

sort.o: sort.c mystrtol.c
	gcc $(CFLAGS) -c sort.c

mystrtol: mystrtol.o
	gcc $(CFLAGS) -o mystrtol mystrtol.o

mystrtol.o: mystrtol.c
	gcc $(CFLAGS) -c mystrtol.c

clean:
	rm -f *.o sort mystrtol
