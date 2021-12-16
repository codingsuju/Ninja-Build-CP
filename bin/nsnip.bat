@echo off
set previous=%CD%
cd %~dp0
dir ..\cppsnippets\
set /p snip=snip:
CLIP < ..\cppsnippets\%snip%.cpp
cd %previous%
