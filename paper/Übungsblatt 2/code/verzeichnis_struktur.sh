#!/bin/bash

# Basename
# Anzahl tabs
print_directory () {
    for e in "$1"*; do
        if [ -f "$e" ]; then
            for i in $(seq 1 $2); do
                printf "\t";
            done
            OUTPUT=$(sed 's/^\.//g' <<<$e)
            OUTPUT=$(sed 's:^/::g' <<<$OUTPUT)
            printf "File: $OUTPUT \n";
        fi
    done

    for e in "$1"*; do
        if [ -d "$e" ]; then
            for i in $(seq 1 $2); do
                printf "\t";
            done
            OUTPUT=$(sed 's/^\.//g' <<<$e)
            OUTPUT=$(sed 's:^/::g' <<<$OUTPUT)
            printf "Directory: $OUTPUT \n"
            print_directory "$e/" $(($2+1))
        fi
    done
}

if [ $# -eq 0 ]; then
    print_directory "./" 0
else
    print_directory "$1" 0
fi