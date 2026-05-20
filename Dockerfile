# Use the latest official ubuntu as the base image
FROM ubuntu:24.04

# Disable interactive prompts during package installation
ARG DEBIAN_FRONTEND=noninteractive

# Install required packages
RUN apt update \
    && apt install -y \
        cmake \
        wget \
        curl \
        git \
        locales \
        ninja-build \
        pkg-config \
        python3 \
        python3-pip \
        sudo \
        tar \
        xz-utils

# Install ARM GCC toolchain
RUN curl -L -o gcc-arm-none-eabi.tar.bz2 https://developer.arm.com/-/media/Files/downloads/gnu-rm/12-2024q2/gcc-arm-none-eabi-12-2024-q2-update-x86_64-linux.tar.bz2 \
    && tar -xjf gcc-arm-none-eabi.tar.bz2 -C /opt \
    && rm gcc-arm-none-eabi.tar.bz2

# Set environment variables for ARM GCC toolchain
ENV PATH="/opt/gcc-arm-none-eabi-12-2024-q2-update/bin:${PATH}"

# Copy the entrypoint script into the docker container
COPY --chmod=0755 ${ENTRYPOINT_PATH} /usr/local/bin/entrypoint.sh

# Set the default command to run when the container starts
ENTRYPOINT ["entrypoint.sh"]

WORKDIR /project