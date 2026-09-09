#include "diag_log.h"
#include <cstdio>
#include <cstdarg>

namespace diag {

static FILE* g_file = nullptr;
static char g_path[MAX_PATH] = {0};

void open() {
    if (g_file) return;
    GetModuleFileNameA((HMODULE)&open, g_path, MAX_PATH);
    char* slash = strrchr(g_path, '\\');
    if (!slash) slash = strrchr(g_path, '/');
    if (slash) *(slash + 1) = '\0';
    else g_path[0] = '\0';
    strcat(g_path, "steam_api_diag.log");
    g_file = fopen(g_path, "a");
}

void log(const char* fmt, ...) {
    if (!g_file) return;
    SYSTEMTIME st;
    GetLocalTime(&st);
    fprintf(g_file, "[%02d:%02d:%02d.%03d] ",
            st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    va_list args;
    va_start(args, fmt);
    vfprintf(g_file, fmt, args);
    va_end(args);
    fputc('\n', g_file);
    fflush(g_file);
}

void close() {
    if (g_file) {
        fclose(g_file);
        g_file = nullptr;
    }
}

} // namespace diag