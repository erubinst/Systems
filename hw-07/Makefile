# Makefile for hw-07 programs
# Nuriel Leve and Esme Rubinstein

CFLAGs = -g -pedantix -std=c99 -Wall -Wextra

all: add multiply

# add target
add: add.o 
	gcc $(CFLAGS) -o add add.o 

add.o: add.c
	gcc $(CFLAGS) -c add.c


#multiply target
multiply: multiply.o
	gcc $(CFLAGS) -o multiply multiply.o

multiply.o: multiply.c
	gcc $(CFLAGS) -c multiply.c


clean:
	rm -f *.o add multiply 
