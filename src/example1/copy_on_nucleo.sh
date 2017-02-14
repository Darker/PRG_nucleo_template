#!/bin/bash
# The nucleo should auto-mount on this path
# if it doesn't, tough luck
NUCLEO_PATH=/media/$USER/NODE_F446RE
# Binary is expected as the first argument
BINARY_PATH=$1

if [ -d $NUCLEO_PATH ] 
then
    echo "Directory $NUCLEO_PATH exists, copying binary to nucleo:"
    if [ ! -z "$BINARY_PATH" ] && [ -f "$BINARY_PATH" ]; then
        cp $BINARY_PATH $NUCLEO_PATH
    else
        echo "File $BINARY_PATH does not exist, did you run make first? Did you pass the file path as first argument?"
    fi
     
else
    echo "Error: Directory $NUCLEO_PATH not found. Nucleo should auto-mount in that directory."
fi

