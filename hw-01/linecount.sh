#! /bin/bash

# Nuriel Leve and Esme Rubinstein

#print out the total nuber of lines in all of the fles in the current working directory


#how to find total lines in file
# wc -l [filename]

#find current directory, and use wc to find all the files in each file of directory

#print the total 


find . -name '*.*' -type f -exec cat {} + | wc -l







