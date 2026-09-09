#pragma once
#include "../../include/steam/steam_api_goldsrc.h"
#include <string>

class CSteamUser : public ISteamUser {
public:
    CSteamUser();
    virtual ~CSteamUser() = default;

    // ISteamUser implementation
    HSteamUser GetHSteamUser() override;
    bool BLoggedOn() override;
    CSteamID GetSteamID() override;
    bool BIsSameUser(HSteamUser hUser) override;
    int InitiateGameConnection(void* pAuthBlob, int cbMaxAuthBlob, CSteamID steamID, uint32 unGameServerIP, uint16 usGameServerPort, bool bSecure) override;
    void TerminateGameConnection(uint32 unGameServerIP, uint16 usGameServerPort) override;
    void TerminateGameConnection2(uint32 unGameServerIP, uint16 usGameServerPort) override;
    void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo) override;
    bool GetUserDataFolder(char* pchBuffer, int cubBuffer) override;
    void StartVoiceRecording() override;
    void StopVoiceRecording() override;
    int GetVoiceAvailable(bool bCompressed) override;
    int GetVoiceNeeded(bool bCompressed) override;
    int GetVoice(char* pDestBuffer, int cbDestBufferSize, bool bCompressed) override;
    int GetVoiceOptimalSampleRate() override;
    int GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket) override;
    void CancelAuthTicket(uint32 hAuthTicket) override;
    int BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID) override;
    void EndAuthSession(CSteamID steamID) override;
    bool IsVACBanned(int nVACBanIndex) override;
    void RequireShowVACBannedScreen(int nVACBanIndex) override;
    int GetGameBadgeLevel(int nSeries) override;
    void SetDurationControlOnlineState(int nNewState) override;
    bool BIsDurationControlEnabled() override;
    int GetSteamGuardDetails() override;
    bool BIsTwoFactorEnabled() override;
    int GetMarketEligibility() override;
    bool BIsPhoneIdentifying() override;
    bool BIsPhoneRequireVerification() override;
    bool BIsPhoneVerified() override;
    bool BIsAppOwned(int nAppID) override;

private:
    HSteamUser m_hSteamUser;
    CSteamID m_steamID;
    bool m_bLoggedOn;
    bool m_bVoiceRecording;
    bool m_bPhoneVerified;
    bool m_bTwoFactorEnabled;
    std::string m_userDataFolder;
};