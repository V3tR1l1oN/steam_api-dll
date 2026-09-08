@echo off
cd /d %~dp0
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars32.bat"

cl /nologo /MD /Ipublic tests\test_basic.cpp /link build\steam_api.lib /OUT:tests\test_basic.exe

if %ERRORLEVEL% EQU 0 (
    echo BUILD OK
    tests\test_basic.exe
) else (
    echo BUILD FAILED
)
