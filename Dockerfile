# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make

# Copy the current directory contents into the container at /action
COPY . /action

# Set the working directory to /action
WORKDIR /action

# Build the C++ code
RUN g++ -o my-action main.cpp

# Run the action
ENTRYPOINT ["/action/entrypoint.sh"]
