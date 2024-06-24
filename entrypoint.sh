#!/bin/sh -l

# Get the input values
SVG_FOLDER=$1
PNG_FOLDER=$2

# Run the Python script with the provided inputs
python convert-svg-to-png.py $SVG_FOLDER $PNG_FOLDER