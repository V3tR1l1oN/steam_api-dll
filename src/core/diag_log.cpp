#include "diag_log.h"
#include <cstdio>
#include <cstdarg>

namespace diag {

static FILE* g_file = nullptr;
static char g_path[MAX_PATH] = {0};

void open() {
    if (g_file) return;
    HMODULE hSelf = nullptr;
    GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCSTR)&open, &hSelf);
    GetModuleFileNameA(hSelf, g_path, MAX_PATH);
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
void diag::logContext(PEXCEPTION_POINTERS ep) {
    if (!g_file || !ep || !ep->ContextRecord) return;
    CONTEXT* c2 = ep->ContextRecord;
    fprintf(g_file, "    EAX=%08lX EBX=%08lX ECX=%08lX EDX=%08lX\n",
        (unsigned long)c2->Eax, (unsigned long)c2->Ebx, (unsigned long)c2->Ecx, (unsigned long)c2->Edx);
    fprintf(g_file, "    ESI=%08lX EDI=%08lX ESP=%08lX EBP=%08lX EIP=%08lX\n",
        (unsigned long)c2->Esi, (unsigned long)c2->Edi, (unsigned long)c2->Esp,
        (unsigned long)c2->Ebp, (unsigned long)c2->Eip);
    unsigned long* sp = (unsigned long*)c2->Esp;
    fprintf(g_file, "    stack:");
    for (int i = 0; i < 16; ++i) fprintf(g_file, " %08lX", sp[i]);
    fprintf(g_file, "\n");
    fflush(g_file);
}
