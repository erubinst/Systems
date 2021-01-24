#! /bin/bash

# Esme Rubinstein and Nuriel Leve

# lists the 5 largest items (files or directories) in the current directory in decreasing order of size. You should output the sizes in a human readable format.  If the script is run from an empty directory, make sure it prints nothing at all (and not an error message)

# tests if the working directory is empty
if [ ! "$(ls -A $PWD)" ]
then
    echo "$PWD is empty!"
else
    # if no command line arguments, print 5
    if [ $# -eq 0 ]; then
	du -hsx * | sort -rh | head -5
    # if there is a flag, print that many 
    else
	du -hsx * | sort -rh | head $1
    fi
fi

