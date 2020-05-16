#!/bin/bash
while true;
do
if ps -p "$1" > /dev/null
then
echo Process $1 is running.
else
echo Process $1 is not running.
fi
sleep $2;
done