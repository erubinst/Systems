#!/bin/sh

echo "MAKING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
make clean
make
echo "MAKEFILE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
cat *akefile
echo "README %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
cat README*
echo
echo "CHAINING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
echo -32767 0xffff 071 0b101 cat | valgrind -q --leak-check=full ./tobinary | valgrind -q --leak-check=full ./tohex | valgrind -q --leak-check=full ./tooctal | valgrind -q --leak-check=full ./todecimal > numbers.test


echo "CHECKING DIFF"
diff numbers.test ../chaintest
echo "If there's no real diff output, all is well"

echo "ENCODE -- ZEROS AND ONES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
cat README* | valgrind -q --leak-check=full ./encode_bits > bits.test
cat bits.test | valgrind -q --leak-check=full ./decode_bits > out.test

tail --bytes=16 bits.test
echo "\n^^ Should be Ones and Zeros"
echo "CHECKING DIFF"
diff README* out.test
echo "If there's no real diff output, all is well"
echo
echo
echo "ENCODE -- OCTAL (EXTRA CREDIT) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
cat README* | valgrind -q --leak-check=full ./encode_bits -o > bits.test
cat bits.test | valgrind -q --leak-check=full ./decode_bits -o > out.test

tail --bytes=16 bits.test
echo "\n^^ Should be Octal"
echo "CHECKING DIFF"
diff README* out.test
echo "If there's no real diff output, all is well"
echo
echo "ENCODE -- HEX (EXTRA CREDIT) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
cat README* | valgrind -q --leak-check=full ./encode_bits -h > bits.test
cat bits.test | valgrind -q --leak-check=full ./decode_bits -h > out.test

tail --bytes=16 bits.test
echo "\n^^ Should be Hex"
echo "CHECKING DIFF"
diff README* out.test
echo "If there's no real diff output, all is well"
echo
echo
echo "FREQ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
valgrind -q --leak-check=full ./freq* < ~rhoyle/pub/cs241/hw04/hamlet.txt
rm bits.test out.test numbers.test
