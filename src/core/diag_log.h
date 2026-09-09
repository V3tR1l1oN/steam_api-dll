#pragma once
#include <windows.h>

// File log for diagnosing steam_api.dll load issues.
// Written next to the DLL: steam_api_diag.log
namespace diag {
    void open();
    void log(const char* fmt, ...);
    void close();
    void logContext(PEXCEPTION_POINTERS ep);
}
