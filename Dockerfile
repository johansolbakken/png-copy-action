# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    libpng-dev

# Copy the current directory contents into the container at /action
COPY . /action

# Set the working directory to /action
WORKDIR /action

# Build the C++ code
RUN cmake . && make

# Run the action
ENTRYPOINT ["/action/entrypoint.sh"]
