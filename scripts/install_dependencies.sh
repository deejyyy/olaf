#!/bin/bash

# Install dependencies for building and running the project
sudo apt update \
    && sudo apt install -y --no-install-recommends \
    build-essential \
    make \
    cmake \
    ninja-build \
    git \
    wget \
    tar \
    xz-utils

cd /opt
sudo mkdir arm-gcc
sudo chown $USER:$USER arm-gcc
cd arm-gcc

wget https://developer.arm.com/-/media/Files/downloads/gnu/15.2.rel1/binrel/arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi.tar.xz

tar -xf arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi.tar.xz

echo 'export PATH=/opt/arm-gcc/arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi/bin:$PATH' >> ~/.bashrc

source ~/.bashrc

arm-none-eabi-gcc -v