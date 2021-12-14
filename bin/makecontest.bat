@echo off
cd %~dp0
set contestname=%1
cd ..
cd Contest
mkdir %contestname%
cd %contestname%
set no=%2
echo Number of Problems:%no%
echo status:Creating Problems
if %no%==2 (
createproblem A && createproblem B
)
if %no%==3 (
createproblem A && createproblem B && createproblem C
)
if %no%==4 (
createproblem A && createproblem B && createproblem C && createproblem D
)
if %no%==5 (
createproblem A && createproblem B && createproblem C && createproblem D && createproblem E
)
if %no%==6 (
createproblem A && createproblem B && createproblem C && createproblem D && createproblem E && createproblem F
)
if %no%==7 (
createproblem A && createproblem B && createproblem C && createproblem D && createproblem E && createproblem F && createproblem G 
)
if %no%==8 (
createproblem A && createproblem B && createproblem C && createproblem D && createproblem E && createproblem F && createproblem G && createproblem H
)
if %no%==9 (
createproblem A && createproblem B && createproblem C && createproblem D && createproblem E && createproblem F && createproblem G && createproblem H && createproblem I 
)
if %no%==10 (
createproblem A && createproblem B && createproblem C && createproblem D && createproblem E && createproblem F && createproblem G && createproblem H && createproblem I && createproblem J
)
cd A/build