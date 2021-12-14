@echo off
set previous=%CD%
cd %~dp0
type ..\cppsnippets\%1.cpp >> %previous%\..\code.cpp
cd %previous%
