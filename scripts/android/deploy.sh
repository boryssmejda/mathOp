#!/bin/sh

. ./project_paths.sh

adb push $BUILD_DIR/test/test_mathOp_add \
         $BUILD_DIR/test/test_mathOp_subtract \
         $BUILD_DIR/test/test_mathOp_multiply \
         $BUILD_DIR/test/test_mathOp_divide \
         /data/local/tmp

adb shell
cd /data/local/temp

# deployed files have no execution privilegies
chmod +x *

# just to close adb shell and return to 'normal' terminal
exit
