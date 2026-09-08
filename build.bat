@echo off
cd /d %~dp0

if defined VCToolsInstallDir (
    set "VCVARS=%VCToolsInstallDir%\..\..\VC\Auxiliary\Build\vcvars32.bat"
    if exist "%VCVARS%" (
        call "%VCVARS%"
    )
) else (
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars32.bat" (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars32.bat"
    ) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars32.bat" (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars32.bat"
    )
)

if not defined VisualStudioVersion (
    echo ERROR: Visual Studio not found
    exit /b 1
)

echo Using: %VisualStudioVersion%

if not exist "build" mkdir build

cl /nologo /W0 /MT /O2 /D_USRDLL /D_WINDLL /DNOMINMAX ^
   /I"public" /c steam_api\steam_api.cpp /Fo:build\steam_api.obj

cl /nologo /W0 /MT /O2 /D_USRDLL /D_WINDLL /DNOMINMAX ^
   /I"public" /c steam_api_exports.cpp /Fo:build\steam_api_exports.obj

cl /nologo /W0 /MT /O2 /D_USRDLL /D_WINDLL /DNOMINMAX ^
   /I"public" /c steam_api\vgui_stubs.cpp /Fo:build\vgui_stubs.obj

cl /nologo /W0 /MT /O2 /D_USRDLL /D_WINDLL /DNOMINMAX ^
   /I"public" /c steam_api\dummy_funcs.cpp /Fo:build\dummy_funcs.obj

cl /nologo /W0 /MT /Od /D_USRDLL /D_WINDLL /DNOMINMAX ^
   /I"public" /c steam_api\large_dummy.cpp /Fo:build\large_dummy.obj

cl /nologo /W0 /MT /O2 /D_USRDLL /D_WINDLL /DNOMINMAX ^
   /I"public" /c steam_api\dummy_padding.cpp /Fo:build\dummy_padding.obj

link /DLL /DEF:steam_api.def /MACHINE:X86 /OUT:build\steam_api.dll ^
    build\steam_api.obj build\steam_api_exports.obj build\vgui_stubs.obj build\dummy_funcs.obj build\large_dummy.obj build\dummy_padding.obj build\padding.res ^
    kernel32.lib user32.lib advapi32.lib ^
    /OPT:NOREF

if %ERRORLEVEL% EQU 0 (
    echo.
    echo BUILD OK: build\steam_api.dll
    dir build\steam_api.dll
) else (
    echo.
    echo BUILD FAILED
    exit /b 1
)
