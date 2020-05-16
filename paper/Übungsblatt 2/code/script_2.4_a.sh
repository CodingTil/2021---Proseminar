#!/bin/bash

for e in $(ls -a); do
    echo $(stat -c '%s %n' "$e")
done