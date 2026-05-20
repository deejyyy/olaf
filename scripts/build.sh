#!/usr/bin/env bash

# This is a build script to build the project's artifacts and run unit tests.
#
# Functionality:
#     - Compiles project build artifacts and runs tests using CMake workflows.
#
# Prerequisites:
#     - This script assumes that the build environment has already been set up.
#
# Usage:
#     - This script will use the build directory at the root of the repository when building.
#
#     - This script can called manually using the following syntax:
#
#         > build.sh [--cmake-preset=<preset>] [--build-artifacts=<true|false>] [--test-artifacts=<true|false>]
#     		--cmake-preset=<preset>    			Optional CMake preset to use (default: Release).
#     		--build-artifacts=<true|false>  	Whether to build artifacts; accepts a value or acts as a boolean
#                                				(default: true). Omit value to treat as true, set to false to skip.
#     		--test-artifacts=<true|false>  		Whether to build and run tests; accepts a value or acts as a boolean
#                                				(default: true). Omit value to treat as true, set to false to skip.
#
#             - Examples:
#                 > build.sh
#                 > scripts/build.sh --cmake-preset Debug --build-artifacts true --test-artifacts=false
#                 > ../build.sh --cmake-preset=Release --build-artifacts=true --test-artifacts=true

# Set script to exit on any errors
set -e


# Parse named flags
while [[ $# -gt 0 ]]; do
	case "$1" in
		--cmake-preset=*)
			cmake_preset="${1#*=}"
			shift
			;;
		--cmake-preset)
			cmake_preset="$2"
			shift 2
			;;
        --build-artifacts=*)
			build_artifacts="${1#*=}"
			shift
			;;
		--build-artifacts)
			if [[ $# -gt 1 && "${2}" != --* ]]; then
				build_artifacts="$2"
				shift 2
			else
				build_artifacts=true
				shift
			fi
			;;
        --test-artifacts=*)
			test_artifacts="${1#*=}"
			shift
			;;
		--test-artifacts)
			if [[ $# -gt 1 && "${2}" != --* ]]; then
				test_artifacts="$2"
				shift 2
			else
				test_artifacts=true
				shift
			fi
			;;
		*)
			echo "Unknown flag: $1" >&2
			exit 1
			;;
	esac
done


# Define default cmake preset
cmake_preset="${cmake_preset:-release}"
build_artifacts="${build_artifacts:-true}"
test_artifacts="${test_artifacts:-true}"

# Define cmake build and test presets
cmake_build_preset="olaf-${cmake_preset}-app"
cmake_test_preset="olaf-${cmake_preset}-test"


# Change directory to the root of the current repository
cd "$(git rev-parse --show-toplevel)"

# Change directory to to the root of the main repository
while [ -n "$(git rev-parse --show-superproject-working-tree)" ]; do
    cd "$(git rev-parse --show-superproject-working-tree)"
done


# Check if build workflow should be executed
if [[ "${build_artifacts}" == "true" ]]; then

	# Run cmake workflow preset to compile build artifacts
	cmake --preset ${cmake_build_preset}

fi

# Check if test workflow should be executed
if [[ "${test_artifacts}" == "true" ]]; then

	# Run cmake workflow preset to compile and run unit tests
	cmake --preset ${cmake_test_preset}

fi
