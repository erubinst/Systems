Esme Rubinstein and Nuriel Leve
Extra Credit Lab

1. grep -E ^[^[aeiou]*[aeiou][^aeiou]*$ $WORDS
2. grep -E a.*e.*i.*o.*u.* $WORDS
3. grep -E [a-z]{22} $WORDS
4.
5.
6. grep -E "^([b-df-hj-np-tv-z][aeiou]){3,}$" $WORDS
7. 
8. sed -n -e 's/snow fall/summertime/g' -e 's/wind chill/summertime/gp' textfile.txt
9. sed -n -e '/^computer/,/^science/p' $WORDS
10. sed -n -e 's/\bteh\b/the/gp' -e 's/\bTeh\b/The/gp' textfile.txt
11. sed 's/\(.*\) \(.*$\)/\2 \1/I' textfile.txt
12. 
13. sed 's/\(\/\*\) \(.*\) \(\*\/\)/\/\/ \2/I' textfile.txt
14. sed -n -e 's/cs 241/CSCI 241/gp' textfile.txt  
15. 
16. sed -e 's/^\(.\{20\}\).*/\1/' $WORDS
17. 
18. 
19. sed 's/\b\([0-9]\{3\}\)\([0-9]\{3\}\)\([0-9]\{4\}\)\b/(\1) \2-\3/' textfile.txt
20. 
