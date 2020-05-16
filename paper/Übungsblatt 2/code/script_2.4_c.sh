#!/bin/bash

# Parameter is team size
teams () {
    FILE=$(sort teamnamen.txt | uniq -c | sed 's/^ *//' | grep -c "^$1")
    echo ${FILE}
}

if [ $# -eq 0 ]; then
    teams 3
else
    if [ $1 -eq "0" ]; then
        echo $(grep -cvP '\S' teamnamen.txt)
    else 
        teams "$1"
    fi
fi