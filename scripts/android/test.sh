#!/bin/sh

. ./project_paths.sh

adb shell
cd /data/local/temp

./test_mathOp_add
./test_mathOp_subtract
./test_mathOp_multiply
./test_mathOp_divide

# just to close adb shell and return to 'normal' terminal
exit
