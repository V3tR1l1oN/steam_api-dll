// vproxy.cpp — vtable-прокси с логированием вызовов движка
#include "vproxy.h"
#include "../core/diag_log.h"

namespace vproxy {

SdkSteamUser g_realUser;
SdkSteamUtils g_realUtils;
SdkSteamMatchmaking g_realMM;
void* g_logVtable[33];
void* g_logObjVtable[33];
bool g_initialized = false;

// Каждый thunk: логирует слот, возвращает безопасное значение.
// Аргументы игнорируются (мы только ищем какой слот вызывает 0x0).
static int __fastcall Thunk_0_GetHSteamUser(void* self, void* edx_or_arg) {
    diag::log("vcall slot=0 GetHSteamUser");
    return 1;
}
static bool __fastcall Thunk_1_BLoggedOn(void* self, void* edx_or_arg) {
    diag::log("vcall slot=1 BLoggedOn");
    return true;
}
static __int64 __fastcall Thunk_2_GetSteamID(void* self, void* edx_or_arg) {
    diag::log("vcall slot=2 GetSteamID");
    return 0x110000100001LL;
}
static int __fastcall Thunk_3_InitiateGameConnection_DEPRECATED(void* self, void* edx_or_arg) {
    diag::log("vcall slot=3 InitiateGameConnection_DEPRECATED");
    return 1;
}
static void __fastcall Thunk_4_TerminateGameConnection_DEPRECATED(void* self, void* edx_or_arg) {
    diag::log("vcall slot=4 TerminateGameConnection_DEPRECATED");

}
static void __fastcall Thunk_5_TrackAppUsageEvent(void* self, void* edx_or_arg) {
    diag::log("vcall slot=5 TrackAppUsageEvent");

}
static bool __fastcall Thunk_6_GetUserDataFolder(void* self, void* edx_or_arg) {
    diag::log("vcall slot=6 GetUserDataFolder");
    return true;
}
static void __fastcall Thunk_7_StartVoiceRecording(void* self, void* edx_or_arg) {
    diag::log("vcall slot=7 StartVoiceRecording");

}
static void __fastcall Thunk_8_StopVoiceRecording(void* self, void* edx_or_arg) {
    diag::log("vcall slot=8 StopVoiceRecording");

}
static int __fastcall Thunk_9_GetAvailableVoice(void* self, void* edx_or_arg) {
    diag::log("vcall slot=9 GetAvailableVoice");
    return 1;
}
static int __fastcall Thunk_10_GetVoice(void* self, void* edx_or_arg) {
    diag::log("vcall slot=10 GetVoice");
    return 1;
}
static int __fastcall Thunk_11_DecompressVoice(void* self, void* edx_or_arg) {
    diag::log("vcall slot=11 DecompressVoice");
    return 1;
}
static unsigned int __fastcall Thunk_12_GetVoiceOptimalSampleRate(void* self, void* edx_or_arg) {
    diag::log("vcall slot=12 GetVoiceOptimalSampleRate");
    return 0;
}
static unsigned int __fastcall Thunk_13_GetAuthSessionTicket(void* self, void* edx_or_arg) {
    diag::log("vcall slot=13 GetAuthSessionTicket");
    return 0;
}
static unsigned int __fastcall Thunk_14_GetAuthTicketForWebApi(void* self, void* edx_or_arg) {
    diag::log("vcall slot=14 GetAuthTicketForWebApi");
    return 0;
}
static int __fastcall Thunk_15_BeginAuthSession(void* self, void* edx_or_arg) {
    diag::log("vcall slot=15 BeginAuthSession");
    return 1;
}
static void __fastcall Thunk_16_EndAuthSession(void* self, void* edx_or_arg) {
    diag::log("vcall slot=16 EndAuthSession");

}
static void __fastcall Thunk_17_CancelAuthTicket(void* self, void* edx_or_arg) {
    diag::log("vcall slot=17 CancelAuthTicket");

}
static int __fastcall Thunk_18_UserHasLicenseForApp(void* self, void* edx_or_arg) {
    diag::log("vcall slot=18 UserHasLicenseForApp");
    return 1;
}
static bool __fastcall Thunk_19_BIsBehindNAT(void* self, void* edx_or_arg) {
    diag::log("vcall slot=19 BIsBehindNAT");
    return true;
}
static void __fastcall Thunk_20_AdvertiseGame(void* self, void* edx_or_arg) {
    diag::log("vcall slot=20 AdvertiseGame");

}
static unsigned long long __fastcall Thunk_21_RequestEncryptedAppTicket(void* self, void* edx_or_arg) {
    diag::log("vcall slot=21 RequestEncryptedAppTicket");
    return 0;
}
static bool __fastcall Thunk_22_GetEncryptedAppTicket(void* self, void* edx_or_arg) {
    diag::log("vcall slot=22 GetEncryptedAppTicket");
    return true;
}
static int __fastcall Thunk_23_GetGameBadgeLevel(void* self, void* edx_or_arg) {
    diag::log("vcall slot=23 GetGameBadgeLevel");
    return 1;
}
static int __fastcall Thunk_24_GetPlayerSteamLevel(void* self, void* edx_or_arg) {
    diag::log("vcall slot=24 GetPlayerSteamLevel");
    return 1;
}
static unsigned long long __fastcall Thunk_25_RequestStoreAuthURL(void* self, void* edx_or_arg) {
    diag::log("vcall slot=25 RequestStoreAuthURL");
    return 0;
}
static bool __fastcall Thunk_26_BIsPhoneVerified(void* self, void* edx_or_arg) {
    diag::log("vcall slot=26 BIsPhoneVerified");
    return true;
}
static bool __fastcall Thunk_27_BIsTwoFactorEnabled(void* self, void* edx_or_arg) {
    diag::log("vcall slot=27 BIsTwoFactorEnabled");
    return true;
}
static bool __fastcall Thunk_28_BIsPhoneIdentifying(void* self, void* edx_or_arg) {
    diag::log("vcall slot=28 BIsPhoneIdentifying");
    return true;
}
static bool __fastcall Thunk_29_BIsPhoneRequiringVerification(void* self, void* edx_or_arg) {
    diag::log("vcall slot=29 BIsPhoneRequiringVerification");
    return true;
}
static unsigned long long __fastcall Thunk_30_GetMarketEligibility(void* self, void* edx_or_arg) {
    diag::log("vcall slot=30 GetMarketEligibility");
    return 0;
}
static unsigned long long __fastcall Thunk_31_GetDurationControl(void* self, void* edx_or_arg) {
    diag::log("vcall slot=31 GetDurationControl");
    return 0;
}
static bool __fastcall Thunk_32_BSetDurationControlOnlineState(void* self, void* edx_or_arg) {
    diag::log("vcall slot=32 BSetDurationControlOnlineState");
    return true;
}

void init() {
    if (g_initialized) return;
    g_logVtable[0] = (void*)&Thunk_0_GetHSteamUser;
    g_logVtable[1] = (void*)&Thunk_1_BLoggedOn;
    g_logVtable[2] = (void*)&Thunk_2_GetSteamID;
    g_logVtable[3] = (void*)&Thunk_3_InitiateGameConnection_DEPRECATED;
    g_logVtable[4] = (void*)&Thunk_4_TerminateGameConnection_DEPRECATED;
    g_logVtable[5] = (void*)&Thunk_5_TrackAppUsageEvent;
    g_logVtable[6] = (void*)&Thunk_6_GetUserDataFolder;
    g_logVtable[7] = (void*)&Thunk_7_StartVoiceRecording;
    g_logVtable[8] = (void*)&Thunk_8_StopVoiceRecording;
    g_logVtable[9] = (void*)&Thunk_9_GetAvailableVoice;
    g_logVtable[10] = (void*)&Thunk_10_GetVoice;
    g_logVtable[11] = (void*)&Thunk_11_DecompressVoice;
    g_logVtable[12] = (void*)&Thunk_12_GetVoiceOptimalSampleRate;
    g_logVtable[13] = (void*)&Thunk_13_GetAuthSessionTicket;
    g_logVtable[14] = (void*)&Thunk_14_GetAuthTicketForWebApi;
    g_logVtable[15] = (void*)&Thunk_15_BeginAuthSession;
    g_logVtable[16] = (void*)&Thunk_16_EndAuthSession;
    g_logVtable[17] = (void*)&Thunk_17_CancelAuthTicket;
    g_logVtable[18] = (void*)&Thunk_18_UserHasLicenseForApp;
    g_logVtable[19] = (void*)&Thunk_19_BIsBehindNAT;
    g_logVtable[20] = (void*)&Thunk_20_AdvertiseGame;
    g_logVtable[21] = (void*)&Thunk_21_RequestEncryptedAppTicket;
    g_logVtable[22] = (void*)&Thunk_22_GetEncryptedAppTicket;
    g_logVtable[23] = (void*)&Thunk_23_GetGameBadgeLevel;
    g_logVtable[24] = (void*)&Thunk_24_GetPlayerSteamLevel;
    g_logVtable[25] = (void*)&Thunk_25_RequestStoreAuthURL;
    g_logVtable[26] = (void*)&Thunk_26_BIsPhoneVerified;
    g_logVtable[27] = (void*)&Thunk_27_BIsTwoFactorEnabled;
    g_logVtable[28] = (void*)&Thunk_28_BIsPhoneIdentifying;
    g_logVtable[29] = (void*)&Thunk_29_BIsPhoneRequiringVerification;
    g_logVtable[30] = (void*)&Thunk_30_GetMarketEligibility;
    g_logVtable[31] = (void*)&Thunk_31_GetDurationControl;
    g_logVtable[32] = (void*)&Thunk_32_BSetDurationControlOnlineState;
    g_initialized = true;
}

void* GetProxyUserObj() {
    init();
    // объект = структура, первое поле = указатель на g_logVtable
    static void* proxyObj[2] = { (void*)g_logVtable, nullptr };
    return (void*)proxyObj;
}

} // namespace vproxy
namespace vproxy {
static const char* friendsMethods[10] = {
    "GetPersonaName", "SetPersonaName", "GetPersonaState", "GetFriendCount",
    "GetFriendByIndex", "GetFriendRelationship", "GetFriendPersonaState",
    "GetFriendPersonaName", "GetFriendGamePlayed", "GetFriendPersonaNameHistory"
};
static void* g_friendsVtable[10];
static bool g_friendsInit = false;
void initFriends() {
    if (g_friendsInit) return;
    for (int i = 0; i < 10; ++i) g_friendsVtable[i] = nullptr;
    g_friendsInit = true;
}
void* GetProxyFriendsObj() {
    initFriends();
    static void* proxyFriends[10] = { nullptr };
    // все слоты возвращают безопасные 0
    return (void*)proxyFriends;
}
} // namespace vproxy