#!/bin/sh

if [ $# -ne 2 ]; then

    echo "not enough arguments passed in!"
    echo "filesdir and searchstr are required! Exiting..."

    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]; then

    echo "$filesdir is not a valid directory on this system! Exiting..."

    exit 1
fi

num_files_in_dir=$(find "$filesdir" -type f | wc -l)
num_matching_lines=$(grep -r -a "$searchstr" "$filesdir"/* | wc -l)

echo "The number of files are $num_files_in_dir and the number of matching lines are $num_matching_lines"