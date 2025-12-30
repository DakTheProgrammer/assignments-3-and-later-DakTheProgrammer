#!/bin/sh

if [ $# -ne 2 ]; then

    echo "not enough arguments passed in!"
    echo "writefile and writestr are required! Exiting..."

    exit 1
fi

writefile=$1
writestr=$2

dir_name=$(dirname "$writefile")

if [ ! -d "$dir_name" ]; then
    
    mkdir -p "$dir_name" && touch "$writefile"
else

    touch "$writefile"
fi

if [ $? -ne 0 ]; then

    echo "Unable to create file $writefile! Exiting..."

    exit 1
fi

echo "$writestr" > "$writefile"