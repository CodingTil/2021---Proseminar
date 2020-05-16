#!/bin/bash

for i in $(seq 0 3); do
    echo $i $(source ./script_2.4_c.sh $i)
done