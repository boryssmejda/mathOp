#!/bin/sh

. ./project_paths.sh

adb shell
cd /data/local/temp

./test_mathOp_cpp_add
./test_mathOp_cpp_subtract
./test_mathOp_cpp_multiply
./test_mathOp_cpp_divide

# LD_LIBRARY_PATH has to be changed so that the executable can load .so
LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./test_mathOp_c_api_add
LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./test_mathOp_c_api_subtract
LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./test_mathOp_c_api_multiply
LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./test_mathOp_c_api_divide

# just to close adb shell and return to 'normal' terminal
exit
