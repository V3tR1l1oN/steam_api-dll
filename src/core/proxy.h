#pragma once
#include <windows.h>
#include <string>
#include <vector>

// Прокси к оригинальной steam_api.dll Valve.
// Если Steam установлен и DLL найдена — вызовы перенаправляются ей,
// игра выглядит как обычный Steam-клиент. Если нет — работаем сами (offline).
//
// steamclient-режим: прямое подключение к ядру Steam (steamclient.dll) через
// его CreateInterface, с собственным callback registry (аналог Valve).
class SteamProxy {
public:
    static SteamProxy& Instance();

    // Пытается загрузить оригинальную steam_api.dll (или steamclient). Идемпотентен.
    bool Init();
    void Shutdown();

    bool IsSteamLoaded() const { return m_bSteamLoaded; }
    bool IsSteamClientMode() const { return m_bSteamClientMode; }

    // Адрес функции из оригинальной DLL/steamclient (nullptr, если нет)
    void* GetOriginal(const char* funcName);
    // CreateInterface адрес steamclient.dll (для steamclient-режима)
    void* GetClientCreateInterface();
    HMODULE GetSteamClientModule() { return m_hSteamAPI; }
    void SetSteamClientObj(void* p);
    void* GetSteamClientObj();

    // Callback registry: движковые колбэки + диспетчеризация из RunCallbacks
    void RegisterCallback(void* cb, int id);
    void DispatchCallback(int id, void* data, int size);

private:
    SteamProxy() = default;
    ~SteamProxy();

    SteamProxy(const SteamProxy&) = delete;
    SteamProxy& operator=(const SteamProxy&) = delete;

    HMODULE m_hSteamAPI = nullptr;
    bool m_bSteamLoaded = false;
    bool m_bSteamClientMode = false;
    void* m_pSteamClientObj = nullptr;

    struct CallbackEntry { void* cb; int id; };
    std::vector<CallbackEntry> m_callbacks;
};
