# Use Ubuntu 20.04 as the base image
FROM ubuntu:20.04

# Set environment variables to avoid user interaction prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    libfltk1.3-dev \
    libopencv-dev \
    git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set up a user for development
RUN useradd -ms /bin/bash devuser
USER devuser
WORKDIR /home/devuser

# Copy the project into the container
COPY . /home/devuser/fltk_opencv_project
WORKDIR /home/devuser/fltk_opencv_project

