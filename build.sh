PRESET_NAME=olaf_app
BUILD_PATH="build/${PRESET_NAME}"

rm -rf $BUILD_PATH

mkdir -p $BUILD_PATH

# cmake --preset $PRESET_NAME
cmake -S . -B $BUILD_PATH
# cmake --build --preset $PRESET_NAME
