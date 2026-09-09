// vproxy.h — vtable-прокси с логированием: копия vtable SdkSteamUser,
// каждый слот обёрнут в лог-функцию, которая пробрасывает вызов в реальный метод.
// Цель: отловить какой vtable-метод движок вызывает перед call 0x0.
#pragma once
#include "../interfaces/sdk_compat.h"

namespace vproxy {

// Реальный объект, на который пробрасываем
extern SdkSteamUser g_realUser;

// Лог-таблица (заполняется в init)
extern void* g_logVtable[33];
extern void* g_logObjVtable[33]; // vtable для объекта (указатель на g_logVtable)
extern bool g_initialized;

void init();

// Объект, который мы отдаём движку вместо &s_SdkUser:
// его vtable = g_logObjVtable (все 33 слота логируют и пробрасывают)
void* GetProxyUserObj();

} // namespace vproxy
