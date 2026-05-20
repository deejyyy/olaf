PRESET_NAME=olaf_app

rm -rf build/$PRESET_NAME

mkdir -p build/$PRESET_NAME


cmake --preset $PRESET_NAME
cmake --build --preset $PRESET_NAME
