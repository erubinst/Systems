# Esme Rubinstein and Nuriel Leve

CFLAGs = -g -pedantic -std=c99 -Wall -Wextra

all: charFrequency encode_bits decode_bits bits tobinary tohex tooctal todecimal

#charFrequency target
charFrequency: charFrequency.o
	gcc $(CFLAGS)  -o charFrequency charFrequency.o

charFrequency.o: charFrequency.c
	gcc $(CFLAGS) -c charFrequency.c

#encode_bits target
encode_bits: encode_bits.o bits.o
	gcc $(CFLAGS) -o encode_bits encode_bits.o bits.o -lm

encode_bits.o: encode_bits.c
	gcc $(CFLAGS)  -c  encode_bits.c -lm


#decode_bits target
decode_bits: decode_bits.o bits.o
	gcc $(CFLAGS) -o decode_bits decode_bits.o bits.o -lm

decode_bits.o: decode_bits.c
	gcc $(CFLAGS) -c decode_bits.c -lm


#bits target
bits: bits.o
	gcc $(CFLAGS) -o bits bits.o -lm

bits.o: bits.c bits.h
	gcc $(CFLAGS) -c bits.c -lm

#tobinary target
tobinary: tobinary.o
	gcc $(CFLAGS) -o tobinary tobinary.o getnum.o

tobinary.o: tobinary.c
	gcc $(CFLAGS) -c tobinary.c getnum.c

tohex: tohex.o
	gcc $(CFLAGS) -o tohex tohex.o getnum.o
tohex.o: tohex.c
	gcc $(CFLAGS) -c tohex.c getnum.c

tooctal: tooctal.o
	gcc $(CFLAGS) -o tooctal tooctal.o getnum.o

tooctal.o: tooctal.c
	gcc $(CFLAGS) -c tooctal.c getnum.c

todecimal: todecimal.o
	gcc $(CFLAGS) -o todecimal todecimal.o getnum.o

todecimal.o: todecimal.c
	gcc $(CFLAGS) -c todecimal.c getnum.c
clean:
	rm -f *.o charFrequency encode_bits decode_bits bits tobinary tohex tooctal todecial
