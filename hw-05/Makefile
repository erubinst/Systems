# Makefile for hw-05 programs
# Nuriel Leve and Esme Rubinstein

CFLAGs = -g -pedantix -std=c99 -Wall -Wextra

all: convertWord pigLatin

# convertWord target
convertWord: convertWord.o
	gcc $(CFLAGS) -o convertWord convertWord.o

convertWord.o: convertWord.c
	gcc $(CFLAGS) -c convertWord.c

#pigLatin target
pigLatin: pigLatin.o convertWord.o
	gcc $(CFLAGS) -o pigLatin pigLatin.o convertWord.o

pigLatin.o: pigLatin.c
	gcc $(CFLAGS) -c pigLatin.c

# translateWrod target
convertWordBack: convertWordBack.o
	gcc $(CFLAGS) -o convertWordBack convertWordBack.o

convertWordBack.o: convertWordBack.c
	gcc $(CFLAGS) -c convertWordBack.c

#unpigLatin target
unpigLatin: unpigLatin.o convertWordBack.o
	gcc $(CFLAGS) -o unpigLatin unpigLatin.o convertWordBack.o

unpigLatin.o: unpigLatin.c
	gcc $(CFLAGS) -c unpigLatin.c

#Dialect traget
Dialect: Dialect.o 
	gcc $(CFLAGS) -o Dialect Dialect.o

Dialect.o: Dialect.c
	gcc $(CFLAGS) -c Dialect.c

clean:
	rm -f *.o convertWord pigLatin convertWordBack unpigLatin Dialect
