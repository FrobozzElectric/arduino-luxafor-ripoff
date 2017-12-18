#!/bin/bash

arduino=$1

while true; do
    for i in {000..767}; do
        trap "echo \" exited on $i\"; exit" SIGINT
        ./set_led.py $arduino $i
        sleep .04
    done
done
