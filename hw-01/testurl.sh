#! /bin/bash

# Esme Rubinstein and Nuriel Leve
# accepts a list of urls in a separate file and tests if the website is up or not - checkout curl wget and tail commands

# Steps - load in external file,if no file print error message, read external file and loop to test if each website is up or not

if [ $# -eq 0 ]; then
    echo "No arguments provided"
    exit 1
fi

filename=$1
while read line; do
    if ! wget -q --method=HEAD $line; then
	echo "Not Found: $line"
    fi
done < $filename


