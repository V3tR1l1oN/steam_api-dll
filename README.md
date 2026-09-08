# steam_api.dll reconstruction (GoldSrc / Counter-Strike 1.6)

Оригинальная реконструкция `steam_api.dll` для сборки нового билда Counter-Strike 1.6 (2024) под MSVC x86 / Win32.

## Что это

Восстановленная из оригинальной `steam_api.dll` (1059 экспортов) исходная база DLL для GoldSrc-игр, пригодная для пересборки современным компилятором.

## Состав

```
steam_api.def                 — точный список экспортов
steam_api_exports_raw.txt     — оригинальные RVAs/ordinals
public/steam/                 — заголовочные файлы API
steam_api/                    — исходники DLL
  steam_api.cpp
  steam_api_exports.cpp
  vgui_stubs.cpp / vgui_stubs.h
  dummy_funcs.cpp
  large_dummy.cpp
  dummy_padding.cpp
  text_padding.cpp
  rdata_padding.cpp
  padding.rc / padding.bin
tests/                        — тестовые утилиты
build.bat                     — скрипт сборки (VS 2022 Build Tools)
run_*.bat                     — скрипты прогона тестов
```

## Сборка

Требуется Visual Studio 2022 Build Tools (MSVC x86).

```bat
build.bat
```

Результат: `build\steam_api.dll` (~263 KB, 1059 экспортов, x86).

## Проверка

```bat
run_test.bat
run_interfaces_test.bat
run_friends_apps_test.bat
run_steam_user_test.bat
run_more_interfaces_test.bat
```

## Примечание

Включены padding-секции для приближения бинарного layout к оригиналу. Совпадение на уровне байт с оригинальным бинарником без пост-обработки не гарантируется.
