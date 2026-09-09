@echo off
echo Signing steam_api.dll with self-signed certificate...
echo Make sure you have makecert and signtool in PATH (Windows SDK).
makecert -r -pe -n "CN=SteamAPI Test" -ss MY -sr CurrentUser steam_api_test.cer
signtool sign /v /s MY /n "SteamAPI Test" build\Release\steam_api.dll
echo Done.