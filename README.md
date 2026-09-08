# steam_api.dll reconstruction (CS 1.6 2024)

Полный исходный код реконструкции `steam_api.dll`, взятой из последнего актуального билда Counter-Strike 1.6 (2024). Выполнено обратным инжинирингом.

## Что это

Восстановленная оригинальная `steam_api.dll` для GoldSrc-игр. Исходный бинарник декомпилирован и пересобран в читаемый исходный код, который можно собирать современным MSVC.

## Источник

- Бинарник: последняя актуальная версия `steam_api.dll` из CS 1.6 (2024)
- Метод: полный реверс-инжиниринг и реконструкция исходного кода
- Экспорты: 1059 функций (точно соответствует оригиналу)
- Архитектура: x86 / Win32

## Состав репозитория

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

## Сборка

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

## Лицензия

Проект распространяется под [GNU General Public License v3.0](LICENSE).

## Примечание

В репозитории присутствуют padding-секции, необходимые для приближения бинарного layout к оригинальному файлу. Точное совпадение на уровне байт без пост-обработки с оригинальным бинарником не гарантируется.
