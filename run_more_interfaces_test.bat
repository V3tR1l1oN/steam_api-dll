@echo off
cd /d C:\Users\Feliny\Desktop\34434\steam_api-goldsrc
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars32.bat"

cl /nologo /MD /Ipublic /I.. tests\test_more_interfaces.cpp /link build\steam_api.lib /OUT:tests\test_more_interfaces.exe

if %ERRORLEVEL% EQU 0 (
    echo BUILD OK
    tests\test_more_interfaces.exe
) else (
    echo BUILD FAILED
)
