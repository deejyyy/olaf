#!/usr/bin/env bash

# This is an entrypoint script to complete environment setup in the docker container
#
# Functionality:
#     - Sources the toolchain so that it always available at run time
#     - Executes the command passed to the container
#
# Prerequisites:
#     - This script assumes that the docker container has already been built.
#
# Usage:
#     - This script is called automatically when the docker container starts.
#     - It can also be invoked manually, passing the command to run.
#
#         > entrypoint.sh
#
#             - Examples:
#                 > scripts/entrypoint.sh
#                 > entrypoint.sh



# Set script to exit on any errors
set -e


# Source the environment to enable the toolchain
export PATH="${TOOLCHAIN_SOURCE_PATH}:$PATH"

# Execute the specified command or service
if [ "$#" -gt 0 ]; then
    exec "$@"
else
    exec bash
fi
