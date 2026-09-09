@echo off
cd /d %~dp0

cmake -B build -G "Visual Studio 17 2022" -A Win32
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: CMake configure failed. Install CMake 3.15+ and VS 2022 Build Tools.
    exit /b 1
)

cmake --build build --config Release
if %ERRORLEVEL% EQU 0 (
    echo.
    echo BUILD OK: build\Release\steam_api.dll
    dir build\Release\steam_api.dll | findstr steam_api.dll
) else (
    echo BUILD FAILED
    exit /b 1
)