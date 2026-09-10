// vproxy.h — vtable-прокси с логированием: копия vtable SdkSteamUser,
// каждый слот обёрнут в лог-функцию, которая пробрасывает вызов в реальный метод.
// Цель: отловить какой vtable-метод движок вызывает перед call 0x0.
#pragma once
#include "../interfaces/sdk_compat.h"
#include "../interfaces/sdk_guard.h"

namespace vproxy {

// Реальные SDK-совместимые объекты (используются в контексте движка)
extern SdkSteamUser g_realUser;
extern SdkSteamUtils g_realUtils;
extern SdkSteamMatchmaking g_realMM;

// Лог-таблица (заполняется в init)
extern void* g_logVtable[33];
extern bool g_initialized;

void init();

// Объект, который мы отдаём движку вместо &s_SdkUser:
// его vtable = g_logObjVtable (все 33 слота логируют и пробрасывают)
void* GetProxyUserObj();

} // namespace vproxy
