#include "steam_user.h"
#include <windows.h>
#include <shlobj.h>
#include <cstring>

CSteamUser::CSteamUser()
    : m_hSteamUser(1),
      m_steamID(0x110000100001),
      m_bLoggedOn(true),
      m_bVoiceRecording(false),
      m_bPhoneVerified(false),
      m_bTwoFactorEnabled(false)
{
    // Определяем папку для пользовательских данных
    char path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, path))) {
        m_userDataFolder = std::string(path) + "\\SteamAPI";
        CreateDirectoryA(m_userDataFolder.c_str(), NULL);
    } else {
        m_userDataFolder = ".\\steam_user_data";
        CreateDirectoryA(m_userDataFolder.c_str(), NULL);
    }
}

HSteamUser CSteamUser::GetHSteamUser() {
    return m_hSteamUser;
}

bool CSteamUser::BLoggedOn() {
    return m_bLoggedOn;
}

CSteamID CSteamUser::GetSteamID() {
    return m_steamID;
}

bool CSteamUser::BIsSameUser(HSteamUser hUser) {
    return hUser == m_hSteamUser;
}

int CSteamUser::InitiateGameConnection(void* pAuthBlob, int cbMaxAuthBlob, CSteamID steamID, uint32 unGameServerIP, uint16 usGameServerPort, bool bSecure) {
    // Возвращаем фиктивный тикет
    if (pAuthBlob && cbMaxAuthBlob >= 4) {
        memset(pAuthBlob, 0xAA, 4);
        return 4;
    }
    return 0;
}

void CSteamUser::TerminateGameConnection(uint32 unGameServerIP, uint16 usGameServerPort) {
    // Ничего не делаем
}

void CSteamUser::TerminateGameConnection2(uint32 unGameServerIP, uint16 usGameServerPort) {
    // Ничего не делаем
}

void CSteamUser::TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo) {
    // Игнорируем
}

bool CSteamUser::GetUserDataFolder(char* pchBuffer, int cubBuffer) {
    if (cubBuffer > 0) {
        strncpy_s(pchBuffer, cubBuffer, m_userDataFolder.c_str(), _TRUNCATE);
        return true;
    }
    return false;
}

void CSteamUser::StartVoiceRecording() {
    m_bVoiceRecording = true;
}

void CSteamUser::StopVoiceRecording() {
    m_bVoiceRecording = false;
}

int CSteamUser::GetVoiceAvailable(bool bCompressed) {
    return 0;
}

int CSteamUser::GetVoiceNeeded(bool bCompressed) {
    return 0;
}

int CSteamUser::GetVoice(char* pDestBuffer, int cbDestBufferSize, bool bCompressed) {
    return 0;
}

int CSteamUser::GetVoiceOptimalSampleRate() {
    return 11025;
}

int CSteamUser::GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket) {
    // Фиктивный тикет
    if (pTicket && cbMaxTicket >= 4) {
        memset(pTicket, 0xBB, 4);
        if (pcbTicket) *pcbTicket = 4;
        return 0;
    }
    return 0;
}

void CSteamUser::CancelAuthTicket(uint32 hAuthTicket) {
    // Ничего не делаем
}

int CSteamUser::BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID) {
    // Всегда успех
    return 0;
}

void CSteamUser::EndAuthSession(CSteamID steamID) {
    // Ничего не делаем
}

bool CSteamUser::IsVACBanned(int nVACBanIndex) {
    return false;
}

void CSteamUser::RequireShowVACBannedScreen(int nVACBanIndex) {
    // Ничего не делаем
}

int CSteamUser::GetGameBadgeLevel(int nSeries) {
    return 0;
}

void CSteamUser::SetDurationControlOnlineState(int nNewState) {
    // Ничего не делаем
}

bool CSteamUser::BIsDurationControlEnabled() {
    return false;
}

int CSteamUser::GetSteamGuardDetails() {
    return 0;
}

bool CSteamUser::BIsTwoFactorEnabled() {
    return m_bTwoFactorEnabled;
}

int CSteamUser::GetMarketEligibility() {
    return 0;
}

bool CSteamUser::BIsPhoneIdentifying() {
    return false;
}

bool CSteamUser::BIsPhoneRequireVerification() {
    return false;
}

bool CSteamUser::BIsPhoneVerified() {
    return m_bPhoneVerified;
}

bool CSteamUser::BIsAppOwned(int nAppID) {
    return true;
}