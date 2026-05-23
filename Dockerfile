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
RUN curl -L -o gcc-arm-none-eabi.tar.bz2 https://developer.arm.com/-/media/files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2 \
    && tar -xjf gcc-arm-none-eabi.tar.bz2 -C /opt \
    && rm gcc-arm-none-eabi.tar.bz2

RUN mkdir -p /root/.ssh && \
    ssh-keyscan github.com >> /root/.ssh/known_hosts

# Set environment variables for ARM GCC toolchain
ENV PATH="/opt/gcc-arm-none-eabi-10.3-2021.10/bin:${PATH}"

ARG GIT_USER
ARG GIT_EMAIL
RUN git config --global user.name "$GIT_USER" \
    && git config --global user.email "$GIT_EMAIL"

ARG ENTRYPOINT_PATH=/scripts/entrypoint.sh
ARG BUILD_PATH=/scripts/build.sh

# Copy the entrypoint script into the docker container
COPY --chmod=0755 ${ENTRYPOINT_PATH} /scripts/entrypoint.sh
COPY --chmod=0755 ${BUILD_PATH} /scripts/build.sh

# Set the default command to run when the container starts
ENTRYPOINT ["entrypoint.sh"]

WORKDIR /project