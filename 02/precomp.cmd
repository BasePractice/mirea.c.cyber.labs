@echo off

set PATH=D:/msys64/mingw64/bin;%PATH%

gcc -E -I../00 -DTASK=02 -DTEST_TARGET task_test.cpp > task_test.precomp.cpp