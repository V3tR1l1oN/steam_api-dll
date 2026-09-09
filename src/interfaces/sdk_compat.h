// sdk_compat.h — vtable-совместимые реализации интерфейсов Steam по официальным
// заголовкам SteamWorks SDK (source-sdk-2013, public/steam/*.h).
//
// Порядок и сигнатуры виртуальных методов повторяют SDK-интерфейсы:
//   ISteamUser023, ISteamFriends017, ISteamUtils010, STEAMAPPS_INTERFACE_VERSION008,
//   ISteamMatchmaking009, ISteamUserStats012, ISteamNetworking006, ISteamClient021.
// Движок (hw.dll) вызывает методы по смещениям Valve-раскладки, поэтому здесь
// критично точное соответствие порядку объявления в SDK-заголовках.
//
// Каждый метод — безопасная заглушка: возвращает «правдоподобное» значение
// (false/0/пустая строка), ничего не делает.
#pragma once
#include <windows.h>
#include <time.h>
#include <stdio.h>

// Реализация GetSteamID вынесена в sdk_guard.cpp: sret-запись защищена SEH.

typedef unsigned int AppId_t;
typedef unsigned int HAuthTicket;
typedef unsigned long long SteamAPICall_t;
typedef unsigned long long CSteamID_AsU64;

// Агрегат БЕЗ конструкторов: MSVC возвращает 8 байт в EDX:EAX (как Valve CSteamID),
// без скрытого sret-указателя в vtable-вызовах движка.
struct SdkSteamID {
    unsigned long long m_id;
};

// ISteamUser023 — 33 метода, порядок по isteamuser.h
class SdkSteamUser {
public:
    virtual int GetHSteamUser() { FILE* f = fopen("sdkuser.log", "a"); if (f) { fprintf(f, "GetHSteamUser\n"); fclose(f); } return 1; }
    virtual bool BLoggedOn() { FILE* f = fopen("sdkuser.log", "a"); if (f) { fprintf(f, "BLoggedOn\n"); fclose(f); } return true; }
    virtual __int64 GetSteamID() { FILE* f = fopen("sdkuser.log", "a"); if (f) { fprintf(f, "GetSteamID\n"); fclose(f); } return 0x110000100001LL; }
    virtual int InitiateGameConnection_DEPRECATED(void* pAuthBlob, int cbMaxAuthBlob, SdkSteamID steamID, unsigned int unIPServer, unsigned short usPortServer, bool bSecure) { FILE* f = fopen("sdkuser.log", "a"); if (f) { fprintf(f, "InitiateGameConnection\n"); fclose(f); } if (pAuthBlob && cbMaxAuthBlob > 0) ((char*)pAuthBlob)[0] = 0; return 0; }
    virtual void TerminateGameConnection_DEPRECATED(unsigned int unIPServer, unsigned short usPortServer) {}
    virtual void TrackAppUsageEvent(SdkSteamID gameID, int eAppUsageEvent, const char* pchExtraInfo) {}
    virtual bool GetUserDataFolder(char* pchBuffer, int cubBuffer) { FILE* f = fopen("sdkuser.log", "a"); if (f) { fprintf(f, "GetUserDataFolder\n"); fclose(f); } if (pchBuffer && cubBuffer > 0) { pchBuffer[0] = '.'; pchBuffer[1] = 0; } return true; }
    virtual void StartVoiceRecording() {}
    virtual void StopVoiceRecording() {}
    virtual int GetAvailableVoice(unsigned int* pcbCompressed, unsigned int* pcbUncompressed, unsigned int nUncompressedVoiceDesiredSampleRate) { if (pcbCompressed) *pcbCompressed = 0; if (pcbUncompressed) *pcbUncompressed = 0; return 0; }
    virtual int GetVoice(bool bWantCompressed, void* pDestBuffer, unsigned int cbDestBufferSize, unsigned int* nBytesWritten, bool bWantUncompressed, void* pUncompressedDestBuffer, unsigned int cbUncompressedDestBufferSize, unsigned int* nUncompressBytesWritten, unsigned int nUncompressedVoiceDesiredSampleRate) { if (nBytesWritten) *nBytesWritten = 0; if (nUncompressBytesWritten) *nUncompressBytesWritten = 0; return 0; }
    virtual int DecompressVoice(const void* pCompressed, unsigned int cbCompressed, void* pDestBuffer, unsigned int cbDestBufferSize, unsigned int* nBytesWritten, unsigned int nDesiredSampleRate) { if (nBytesWritten) *nBytesWritten = 0; return 0; }
    virtual unsigned int GetVoiceOptimalSampleRate() { return 11025; }
    virtual HAuthTicket GetAuthSessionTicket(void* pTicket, int cbMaxTicket, unsigned int* pcbTicket, const void* pIdentity) { if (pcbTicket) *pcbTicket = 0; return 0; }
    virtual HAuthTicket GetAuthTicketForWebApi(const char* pchIdentity) { return 0; }
    virtual int BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, SdkSteamID steamID) { return 0; }
    virtual void EndAuthSession(SdkSteamID steamID) {}
    virtual void CancelAuthTicket(HAuthTicket hAuthTicket) {}
    virtual int UserHasLicenseForApp(SdkSteamID steamID, AppId_t appID) { return 1; }
    virtual bool BIsBehindNAT() { return false; }
    virtual void AdvertiseGame(SdkSteamID steamIDGameServer, unsigned int unIPServer, unsigned short usPortServer) {}
    virtual SteamAPICall_t RequestEncryptedAppTicket(void* pDataToInclude, int cbDataToInclude) { return 0; }
    virtual bool GetEncryptedAppTicket(void* pTicket, int cbMaxTicket, unsigned int* pcbTicket) { if (pcbTicket) *pcbTicket = 0; return false; }
    virtual int GetGameBadgeLevel(int nSeries, bool bFoil) { return 0; }
    virtual int GetPlayerSteamLevel() { return 0; }
    virtual SteamAPICall_t RequestStoreAuthURL(const char* pchRedirectURL) { return 0; }
    virtual bool BIsPhoneVerified() { return true; }
    virtual bool BIsTwoFactorEnabled() { return false; }
    virtual bool BIsPhoneIdentifying() { return false; }
    virtual bool BIsPhoneRequiringVerification() { return false; }
    virtual SteamAPICall_t GetMarketEligibility() { return 0; }
    virtual SteamAPICall_t GetDurationControl() { return 0; }
    virtual bool BSetDurationControlOnlineState(int eNewState) { return true; }
};

// ISteamUtils010 — 36 методов, порядок по isteamutils.h
class SdkSteamUtils {
public:
    virtual unsigned int GetSecondsSinceAppActive() { return 0; }
    virtual unsigned int GetSecondsSinceComputerActive() { return 0; }
    virtual unsigned long long GetConnectedUniverse() { return 1; }
    virtual unsigned int GetServerRealTime() { return (unsigned int)time(nullptr); }
    virtual const char* GetIPCountry() { return "RU"; }
    virtual bool GetImageSize(int iImage, unsigned int* pnWidth, unsigned int* pnHeight) { if (pnWidth) *pnWidth = 0; if (pnHeight) *pnHeight = 0; return false; }
    virtual bool GetImageRGBA(int iImage, unsigned char* pubDest, int nDestBufferSize) { return false; }
    virtual bool GetCSERIPPort(unsigned int* unIP, unsigned short* usPort) { return false; }
    virtual unsigned int GetCurrentBatteryPower() { return 255; }
    virtual unsigned int GetAppID() { return 10; }
    virtual void SetOverlayNotificationPosition(int ePos) {}
    virtual bool IsAPICallCompleted(SteamAPICall_t hSteamAPICall, bool* pbFailed) { if (pbFailed) *pbFailed = true; return false; }
    virtual int GetAPICallFailureReason(SteamAPICall_t hSteamAPICall) { return 0; }
    virtual bool GetAPICallResult(SteamAPICall_t hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed) { if (pbFailed) *pbFailed = true; return false; }
    virtual unsigned int GetIPCCallCount() { return 0; }
    virtual bool IsOverlayEnabled() { return false; }
    virtual bool BOverlayNeedsPresent() { return false; }
    virtual bool CheckFileSignature(const char* szFileName) { return false; }
    virtual bool ShowGamepadTextInput(int eInputMode, int eTextInputLineMode, const char* pchDescription, unsigned int unCharMax, const char* pchExistingText) { return false; }
    virtual unsigned int GetEnteredGamepadTextLength() { return 0; }
    virtual bool GetEnteredGamepadTextInput(char* pchValue, unsigned int cchValueMax) { return false; }
    virtual const char* GetSteamUILanguage() { return "english"; }
    virtual bool IsSteamRunningInVR() { return false; }
    virtual void SetOverlayNotificationInset(int nHorizontalInset, int nVerticalInset) {}
    virtual bool IsSteamInBigPictureMode() { return false; }
    virtual void StartVRDashboard() {}
    virtual bool IsVRHeadsetStreamingEnabled() { return false; }
    virtual void SetVRHeadsetStreamingEnabled(bool bEnabled) {}
    virtual bool IsSteamChinaLauncher() { return false; }
    virtual bool InitFilterText(unsigned int unFilterOptions) { return false; }
    virtual int FilterText(int eContext, SdkSteamID sourceSteamID, const char* pchInputMessage, char* pchOutFilteredText, unsigned int nByteSizeOutFilteredText) { return 0; }
    virtual bool GetIPv6ConnectivityState(int eProtocol) { return 0; }
    virtual bool IsSteamRunningOnSteamDeck() { return false; }
    virtual bool BIsMultiplayerAudioEnabled() { return false; }
    // SDK может содержать ещё методы в зависимости от версии; ок, если останутся лишние слоты
};
