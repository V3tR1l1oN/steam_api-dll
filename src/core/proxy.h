#pragma once
#include <windows.h>
#include <string>

// Прокси к оригинальной steam_api.dll Valve.
// Если Steam установлен и DLL найдена — вызовы перенаправляются ей,
// игра выглядит как обычный Steam-клиент. Если нет — работаем сами (offline).
class SteamProxy {
public:
    static SteamProxy& Instance();

    // Пытается загрузить оригинальную steam_api.dll. Идемпотентен.
    bool Init();
    void Shutdown();

    bool IsSteamLoaded() const { return m_bSteamLoaded; }

    // Адрес функции из оригинальной DLL (nullptr, если Steam не загружен)
    void* GetOriginal(const char* funcName);

private:
    SteamProxy() = default;
    ~SteamProxy();

    SteamProxy(const SteamProxy&) = delete;
    SteamProxy& operator=(const SteamProxy&) = delete;

    HMODULE m_hSteamAPI = nullptr;
    bool m_bSteamLoaded = false;
};