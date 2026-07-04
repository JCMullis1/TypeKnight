#!/bin/bash
# Exit immedietely if a compilation command fails
set -e

gcc main.c tkSDL.c -o main -lSDL2 -lSDL2_image -lSDL2_ttf
echo "Build successful!"
echo "Running main"
./main
