@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

mkdir .build_msc_x64
cd .build_msc_x64
cmake .. -DCMAKE_BUILD_TYPE=Release -G "NMake Makefiles"
nmake
pause