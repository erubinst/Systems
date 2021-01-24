#!/bin/bash

# Nuriel Leve and Esme Rubinstein
# copy one or more recent files into the backup directory
# check if files are more recent than the file that exists in the back, if not, do nothing, if so, copy to the backup directory  

# copy is cp file1 file2 file3 backup


# for ((i = 2; i <= $#; i++ )); do
# cp -u -r $2 $1
# done

for file in $(echo $@ | cut -f 2- -d ' ')
do
    # echo $file
    cp -u -r $file $1
done

