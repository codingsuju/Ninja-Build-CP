@echo off
mkdir %1
cd %1
cp ../../../files/CMakeLists.txt CMakeLists.txt
cp ../../../files/code.cpp code.cpp
mkdir build
cd build
cmake -G "Ninja" -S .. -B .
ninja
::start notepad++ ../code.cpp
cd ../..


