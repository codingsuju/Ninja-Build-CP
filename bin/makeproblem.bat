@echo off
cd %~dp0
cd ..
cd Problemset
mkdir %1
cd %1
cp ../../files/CMakeLists.txt CMakeLists.txt
cp ../../files/code.cpp code.cpp
mkdir bits
cp ../../files/stdc++.h bits/stdc++.h
mkdir build
cd build
cmake -G "Ninja" -S .. -B .
ninja
::start notepad++ ../code.cpp


