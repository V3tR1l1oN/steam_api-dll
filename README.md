# steam_api.dll reconstruction (CS 1.6 2024)

Полная реконструкция `steam_api.dll` из последнего актуального билда Counter-Strike 1.6 (2024) методом реверс-инжиниринга. Репозиторий содержит как готовую DLL, так и полный исходный код для сборки и модификации.

## Источник и версия

- Бинарник: `steam_api.dll` из последнего актуального билда CS 1.6
- Движок/билд: **build 10210** (`25th Anniversary Update`)
- Сборка: **Exe build: 19:06:31 Oct 7 2024**
- Протокол: **48**
- Ядро: **hl.exe 1.1.1.1**
- Метод: полный реверс-инжиниринг и реконструкция исходного кода
- Экспорты: **1059 функций** (точно соответствует оригиналу)
- Архитектура: **x86 / Win32**

## Что в репозитории

```
steam_api.def                 — точный список 1059 экспортов
steam_api_exports_raw.txt     — оригинальные RVAs и ordinals
public/steam/                 — заголовочные файлы GoldSrc API
steam_api/                    — исходный код DLL
  steam_api.cpp               — основная реализация
  steam_api_exports.cpp       — таблица экспортов
  vgui_stubs.cpp / .h         — заглушки VGUI
  dummy_funcs.cpp             — dummy-функции для layout
  large_dummy.cpp             — большая dummy-функция
  dummy_padding.cpp           — padding данные
  text_padding.cpp            — padding в секции .text
  rdata_padding.cpp           — padding в секции .rdata
  padding.rc / padding.bin    — ресурсы
tests/                        — тестовые утилиты
build.bat                     — скрипт сборки (VS 2022 Build Tools)
run_*.bat                     — скрипты прогона тестов
```

## Использование

### Готовая DLL

Можно использовать уже собранную `steam_api.dll` из релизов.

### Сборка из исходников

Требуется **Visual Studio 2022 Build Tools** (MSVC x86).

```bat
build.bat
```

Результат: `build\steam_api.dll` (~263 KB, 1059 экспортов, x86)

## Проверка

```bat
run_test.bat
run_interfaces_test.bat
run_friends_apps_test.bat
run_steam_user_test.bat
run_more_interfaces_test.bat
```

Все тесты проходят успешно.

## Модификация

Исходный код открыт для улучшения и модификации. Вы можете:
- Добавлять новые реализации интерфейсов
- Исправлять баги
- Оптимизировать код
- Адаптировать под новые версии клиента

## Лицензия

Проект распространяется под [GNU General Public License v3.0](LICENSE).
