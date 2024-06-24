#!/bin/sh -l

# Get the input values
SVG_FOLDER=$1
PNG_FOLDER=$2
GITHUB_TOKEN=$3

# Run the Python script with the provided inputs
python convert-svg-to-png.py $SVG_FOLDER $PNG_FOLDER

# Configure git
git config --global --add safe.directory /github/workspace
git config --global user.name "github-actions[bot]"
git config --global user.email "github-actions[bot]@users.noreply.github.com"

# Add changes to git
git add $PNG_FOLDER

# Commit and push changes
git commit -m "Convert SVG to PNG"
git push
