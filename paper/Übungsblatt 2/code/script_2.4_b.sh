#!/bin/bash

for e in $(ls -a); do
    echo $(stat -c '%n %s' "$e")
done