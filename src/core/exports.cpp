// Auto-generated FULL implementations for steam_api.dll
#include "../../include/steam/steam_api_goldsrc.h"
#include "diag_log.h"
#include "../interfaces/steam_user.h"
#include "../interfaces/steam_friends.h"
#include "../interfaces/steam_utils.h"
#include "../interfaces/steam_apps.h"
#include "../interfaces/steam_networking.h"
#include "../interfaces/steam_matchmaking.h"
#include "../interfaces/steam_userstats.h"
#include "../interfaces/steam_music.h"
#include "../interfaces/steam_networking_sockets.h"
#include "../interfaces/steam_networking_messages.h"

// Прозрачное перенаправление вызовов в оригинальную steam_api.dll (когда она загружена).
#include "proxy.h"

// Возвращает адрес SteamInternal_GameServer_Init в оригинальной DLL (или 0).
static void* GetGSInitTarget() {
    SteamProxy::Instance().Init();
    return SteamProxy::Instance().GetOriginal("SteamInternal_GameServer_Init");
}

#define FORWARD0(NAME) do { \
    auto orig = (void*(*)())SteamProxy::Instance().GetOriginal("SteamAPI_ISteamClient_" #NAME); \
    if (orig) return orig(); \
    return (void*)1; \
} while(0)
#define FORWARD1(NAME, A) do { \
    auto orig = (void*(*)(void*))SteamProxy::Instance().GetOriginal("SteamAPI_ISteamClient_" #NAME); \
    if (orig) return orig((void*)(A)); \
    return (void*)1; \
} while(0)
#define FORWARD2(NAME, A, B) do { \
    auto orig = (void*(*)(void*, const char*))SteamProxy::Instance().GetOriginal("SteamAPI_ISteamClient_" #NAME); \
    if (orig) return orig((void*)(A), (const char*)(B)); \
    return (void*)1; \
} while(0)

// Interface singletons (defined in steam_api.cpp)
extern CSteamClient s_SteamClient;
extern CSteamUser s_SteamUser;
extern CSteamFriends s_SteamFriends;
extern CSteamUtils s_SteamUtils;
extern CSteamApps s_SteamApps;
extern CSteamNetworking s_SteamNetworking;
extern CSteamMatchmaking s_SteamMatchmaking;
extern CSteamUserStats s_SteamUserStats;
extern CSteamAppList s_SteamAppList;
extern CSteamController s_SteamController;
extern CSteamHTMLSurface s_SteamHTMLSurface;
extern CSteamHTTP s_SteamHTTP;
extern CSteamInput s_SteamInput;
extern CSteamInventory s_SteamInventory;
extern CSteamMatchmakingClient s_SteamMatchmakingClient;
extern CSteamMatchmakingServers s_SteamMatchmakingServers;
extern CSteamMusic s_SteamMusic;
extern CSteamNetworkingSockets s_SteamNetworkingSockets;
extern CSteamNetworkingMessages s_SteamNetworkingMessages;
extern CSteamNetworkingUtils s_SteamNetworkingUtils;
extern CSteamParentalSettings s_SteamParentalSettings;
extern CSteamParties s_SteamParties;
extern CSteamRemotePlay s_SteamRemotePlay;
extern CSteamRemoteStorage s_SteamRemoteStorage;
extern CSteamScreenshots s_SteamScreenshots;
extern CSteamUGC s_SteamUGC;
extern CSteamVideo s_SteamVideo;

extern "C" {

void* GetHSteamPipe();
void* GetHSteamUser();
void* SteamAPI_GetHSteamPipe() { diag::log("call: SteamAPI_GetHSteamPipe"); return GetHSteamPipe(); } // @3
void* SteamAPI_GetHSteamUser() { diag::log("call: SteamAPI_GetHSteamUser"); return GetHSteamUser(); } // @4
void* SteamAPI_GetSteamInstallPath() { diag::log("call: SteamAPI_GetSteamInstallPath"); return nullptr; } // @5
void* SteamAPI_ISteamAppList_GetAppBuildId() { return nullptr; } // @6
void* SteamAPI_ISteamAppList_GetAppInstallDir() { return nullptr; } // @7
void* SteamAPI_ISteamAppList_GetAppName() { return nullptr; } // @8
void* SteamAPI_ISteamAppList_GetInstalledApps() { return nullptr; } // @9
void* SteamAPI_ISteamAppList_GetNumInstalledApps() { return nullptr; } // @10
void* SteamAPI_ISteamApps_BGetDLCDataByIndex() { return nullptr; } // @11
bool SteamAPI_ISteamApps_BIsAppInstalled(int id) { diag::log("call: BIsAppInstalled id=%d -> %d", id, (int)s_SteamApps.BIsAppInstalled(id)); return s_SteamApps.BIsAppInstalled(id); } // @12
bool SteamAPI_ISteamApps_BIsCybercafe() { return s_SteamApps.BIsCybercafe(); } // @13
bool SteamAPI_ISteamApps_BIsDlcInstalled(int id) { return s_SteamApps.BIsDlcInstalled(id); } // @14
bool SteamAPI_ISteamApps_BIsLowViolence() { return s_SteamApps.BIsLowViolence(); } // @15
bool SteamAPI_ISteamApps_BIsSubscribed() { return s_SteamApps.BIsSubscribed(); } // @16
bool SteamAPI_ISteamApps_BIsSubscribedApp(int id) { return s_SteamApps.BIsSubscribedApp(id); } // @17
bool SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing() { return s_SteamApps.BIsSubscribedFromFamilySharing(); } // @18
void* SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend() { return nullptr; } // @19
bool SteamAPI_ISteamApps_BIsTimedTrial() { return s_SteamApps.BIsTimedTrial(); } // @20
bool SteamAPI_ISteamApps_BIsVACBanned() { return s_SteamApps.BIsVACBanned(); } // @21
int SteamAPI_ISteamApps_GetAppBuildId() { return s_SteamApps.GetAppBuildId(); } // @22
bool SteamAPI_ISteamApps_GetAppInstallDir(int id, char* buf, int len) { return s_SteamApps.BGetAppInstallDir(id, buf, len); } // @23
uint64 SteamAPI_ISteamApps_GetAppOwner() { return s_SteamApps.GetAppOwner(); } // @24
const char* SteamAPI_ISteamApps_GetAvailableGameLanguages() { return s_SteamApps.GetAvailableGameLanguages(); } // @25
const char* SteamAPI_ISteamApps_GetCurrentBetaName() { return s_SteamApps.GetCurrentBetaName(); } // @26
const char* SteamAPI_ISteamApps_GetCurrentGameLanguage() { return s_SteamApps.GetCurrentGameLanguage(); } // @27
int SteamAPI_ISteamApps_GetDLCCount() { return s_SteamApps.GetDLCCount(); } // @28
void* SteamAPI_ISteamApps_GetDlcDownloadProgress() { return nullptr; } // @29
void* SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime() { return nullptr; } // @30
void* SteamAPI_ISteamApps_GetFileDetails() { return nullptr; } // @31
void* SteamAPI_ISteamApps_GetInstalledDepots() { return nullptr; } // @32
void* SteamAPI_ISteamApps_GetInstalledLanguages() { return nullptr; } // @33
const char* SteamAPI_ISteamApps_GetLaunchCommandLine() { return s_SteamApps.GetLaunchCommandLine(); } // @34
const char* SteamAPI_ISteamApps_GetLaunchQueryParam(const char* k) { return s_SteamApps.GetLaunchQueryParam(k); } // @35
void* SteamAPI_ISteamApps_InstallDLC() { return nullptr; } // @37
void* SteamAPI_ISteamApps_IsAppDLCInstalled() { return nullptr; } // @38
void* SteamAPI_ISteamApps_MarkContentCorrupt() { return nullptr; } // @39
void* SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys() { return nullptr; } // @40
void* SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey() { return nullptr; } // @41
void* SteamAPI_ISteamApps_SetAppBuildId() { return nullptr; } // @42
void* SteamAPI_ISteamApps_StartAppInstallation() { return nullptr; } // @43
void* SteamAPI_ISteamApps_UninstallDLC() { return nullptr; } // @44
void* SteamAPI_ISteamClient_BReleaseSteamPipe(void* h) { diag::log("call: BReleaseSteamPipe h=%p", h); FORWARD1(BReleaseSteamPipe, h); } // @45
void* SteamAPI_ISteamClient_BShutdownIfAllPipesClosed() { return (void*)0; } // @46
void* SteamAPI_ISteamClient_ConnectToGlobalUser(void* h) { diag::log("call: ConnectToGlobalUser h=%p", h); FORWARD1(ConnectToGlobalUser, h); } // @47
void* SteamAPI_ISteamClient_CreateLocalUser(void* h, int b) { diag::log("call: CreateLocalUser h=%p b=%d", h, b); FORWARD2(CreateLocalUser, h, b); } // @48
void* SteamAPI_ISteamClient_CreateSteamPipe() { diag::log("call: CreateSteamPipe"); FORWARD0(CreateSteamPipe); } // @49
void* SteamAPI_ISteamClient_GetCCallback() { return nullptr; } // @50
void* SteamAPI_ISteamClient_GetCellID() { return nullptr; } // @51
void* SteamAPI_ISteamClient_GetClientVersion() { return nullptr; } // @52
void* SteamAPI_ISteamClient_GetComputerForBind() { return nullptr; } // @53
void* SteamAPI_ISteamClient_GetContentServerInfo() { return nullptr; } // @54
void* SteamAPI_ISteamClient_GetCurrentBetaName() { return nullptr; } // @55
void* SteamAPI_ISteamClient_GetIP() { return nullptr; } // @56
void* SteamAPI_ISteamClient_GetISteamAppList() { return nullptr; } // @57
void* SteamAPI_ISteamClient_GetISteamApps(const char* v) { diag::log("call: GetISteamApps v=%s", v?v:"?"); FORWARD1(GetISteamApps, v); } // @59
void* SteamAPI_ISteamClient_GetISteamClient() { return nullptr; } // @61
void* SteamAPI_ISteamClient_GetISteamController() { return nullptr; } // @62
void* SteamAPI_ISteamClient_GetISteamFriends(void* h, const char* v) { diag::log("call: GetISteamFriends h=%p v=%s", h, v?v:"?"); FORWARD2(GetISteamFriends, h, v); } // @63
void* SteamAPI_ISteamClient_GetISteamGameSearch() { return nullptr; } // @64
void* SteamAPI_ISteamClient_GetISteamGameServer() { return nullptr; } // @65
void* SteamAPI_ISteamClient_GetISteamGameServerStats() { return nullptr; } // @66
void* SteamAPI_ISteamClient_GetISteamGenericInterface() { return nullptr; } // @67
void* SteamAPI_ISteamClient_GetISteamHTMLSurface() { return nullptr; } // @68
void* SteamAPI_ISteamClient_GetISteamHTTP() { return nullptr; } // @69
void* SteamAPI_ISteamClient_GetISteamInput() { return nullptr; } // @70
void* SteamAPI_ISteamClient_GetISteamInventory() { return nullptr; } // @71
void* SteamAPI_ISteamClient_GetISteamMatchmaking(void* h, const char* v) { diag::log("call: GetISteamMatchmaking v=%s", v?v:"?"); FORWARD2(GetISteamMatchmaking, h, v); } // @72
void* SteamAPI_ISteamClient_GetISteamMatchmakingServers(void* h, const char* v) { diag::log("call: GetISteamMatchmakingServers v=%s", v?v:"?"); return &s_SteamMatchmaking; } // @73
void* SteamAPI_ISteamClient_GetISteamMusic() { return nullptr; } // @74
void* SteamAPI_ISteamClient_GetISteamMusicRemote() { return nullptr; } // @75
void* SteamAPI_ISteamClient_GetISteamNetworking(void* h, const char* v) { diag::log("call: GetISteamNetworking v=%s", v?v:"?"); FORWARD2(GetISteamNetworking, h, v); } // @76
void* SteamAPI_ISteamClient_GetISteamNetworkingSockets() { return nullptr; } // @77
void* SteamAPI_ISteamClient_GetISteamNetworkingUtils() { return nullptr; } // @78
void* SteamAPI_ISteamClient_GetISteamParentalSettings() { return nullptr; } // @79
void* SteamAPI_ISteamClient_GetISteamParties() { return nullptr; } // @80
void* SteamAPI_ISteamClient_GetISteamRemotePlay() { return nullptr; } // @81
void* SteamAPI_ISteamClient_GetISteamRemoteStorage() { return nullptr; } // @82
void* SteamAPI_ISteamClient_GetISteamScreenshots() { return nullptr; } // @83
void* SteamAPI_ISteamClient_GetISteamSteamController() { return nullptr; } // @84
void* SteamAPI_ISteamClient_GetISteamUGC() { return nullptr; } // @85
void* SteamAPI_ISteamClient_GetISteamUser(void* h, const char* v) { diag::log("call: GetISteamUser h=%p v=%s", h, v?v:"?"); FORWARD2(GetISteamUser, h, v); } // @86
void* SteamAPI_ISteamClient_GetISteamUserStats(void* h, const char* v) { diag::log("call: GetISteamUserStats v=%s", v?v:"?"); FORWARD2(GetISteamUserStats, h, v); } // @87
void* SteamAPI_ISteamClient_GetISteamUtils(const char* v) { diag::log("call: GetISteamUtils v=%s", v?v:"?"); FORWARD1(GetISteamUtils, v); } // @88
void* SteamAPI_ISteamClient_GetISteamVideo() { return nullptr; } // @89
void* SteamAPI_ISteamClient_GetLocalIP() { return nullptr; } // @90
void* SteamAPI_ISteamClient_GetMatchmaking() { return nullptr; } // @91
void* SteamAPI_ISteamClient_GetPersonaName() { return nullptr; } // @92
void* SteamAPI_ISteamClient_GetServerRealTime() { return nullptr; } // @93
void* SteamAPI_ISteamClient_GetService() { return nullptr; } // @94
void* SteamAPI_ISteamClient_GetSteam2DesktopPath() { return nullptr; } // @95
void* SteamAPI_ISteamClient_GetSteam2Path() { return nullptr; } // @96
void* SteamAPI_ISteamClient_GetSteam3Path() { return nullptr; } // @97
void* SteamAPI_ISteamClient_GetSteamClientVersion() { return nullptr; } // @98
void* SteamAPI_ISteamClient_InitConnect() { return nullptr; } // @99
void* SteamAPI_ISteamClient_InstallSteam2() { return nullptr; } // @100
void* SteamAPI_ISteamClient_ReleaseLocalUser() { return nullptr; } // @101
void* SteamAPI_ISteamClient_RemoteStorage() { return nullptr; } // @102
void* SteamAPI_ISteamClient_RunFrame() { return nullptr; } // @103
void* SteamAPI_ISteamClient_SetLocalIPBinding() { return nullptr; } // @104
void* SteamAPI_ISteamClient_SetRetry() { return nullptr; } // @105
void* SteamAPI_ISteamClient_Shutdown() { return nullptr; } // @106
void* SteamAPI_ISteamClient_UninstallSteam2() { return nullptr; } // @107
void* SteamAPI_ISteamController_ActivateActionSet() { return nullptr; } // @108
void* SteamAPI_ISteamController_ActivateActionSetLayer() { return nullptr; } // @109
void* SteamAPI_ISteamController_ActivateEchoActionSet() { return nullptr; } // @110
void* SteamAPI_ISteamController_GetActionSetHandle() { return nullptr; } // @111
void* SteamAPI_ISteamController_GetActiveActionSetLayers() { return nullptr; } // @112
void* SteamAPI_ISteamController_GetAnalogActionData() { return nullptr; } // @113
void* SteamAPI_ISteamController_GetAnalogActionHandle() { return nullptr; } // @114
void* SteamAPI_ISteamController_GetAnalogActionOrigins() { return nullptr; } // @115
void* SteamAPI_ISteamController_GetConnectedControllers() { return nullptr; } // @116
void* SteamAPI_ISteamController_GetControllerBindingRevision() { return nullptr; } // @117
void* SteamAPI_ISteamController_GetControllerForGamepadIndex() { return nullptr; } // @118
void* SteamAPI_ISteamController_GetCurrentActionSet() { return nullptr; } // @119
void* SteamAPI_ISteamController_GetDigitalActionData() { return nullptr; } // @120
void* SteamAPI_ISteamController_GetDigitalActionOrigins() { return nullptr; } // @121
void* SteamAPI_ISteamController_GetGamepadIndexForController() { return nullptr; } // @122
void* SteamAPI_ISteamController_GetGlyphForActionOrigin() { return nullptr; } // @123
void* SteamAPI_ISteamController_GetInputTypeForHandle() { return nullptr; } // @124
void* SteamAPI_ISteamController_GetMotionData() { return nullptr; } // @125
void* SteamAPI_ISteamController_GetRemotePlaySessionID() { return nullptr; } // @126
void* SteamAPI_ISteamController_GetSessionInputConfigurationSettings() { return nullptr; } // @127
void* SteamAPI_ISteamController_GetStringForActionOrigin() { return nullptr; } // @128
void* SteamAPI_ISteamController_GetStringForAnalogActionName() { return nullptr; } // @129
void* SteamAPI_ISteamController_GetStringForDigitalActionName() { return nullptr; } // @130
void* SteamAPI_ISteamController_GetStringForXboxOrigin() { return nullptr; } // @131
void* SteamAPI_ISteamController_Init() { return nullptr; } // @132
void* SteamAPI_ISteamController_RunFrame() { return nullptr; } // @133
void* SteamAPI_ISteamController_RunFrame_StoreActions() { return nullptr; } // @134
void* SteamAPI_ISteamController_SetActionSetReference() { return nullptr; } // @135
void* SteamAPI_ISteamController_SetChannel() { return nullptr; } // @136
void* SteamAPI_ISteamController_SetConnectedController() { return nullptr; } // @137
void* SteamAPI_ISteamController_SetCurrentActionSet() { return nullptr; } // @138
void* SteamAPI_ISteamController_SetLEDColor() { return nullptr; } // @139
void* SteamAPI_ISteamController_SetMotion() { return nullptr; } // @140
void* SteamAPI_ISteamController_ShowBindingPanel() { return nullptr; } // @141
void* SteamAPI_ISteamController_Shutdown() { return nullptr; } // @142
void* SteamAPI_ISteamController_ShowDigitalActionOrigins() { return nullptr; } // @143
void* SteamAPI_ISteamController_ShowAnalogActionOrigins() { return nullptr; } // @144
void* SteamAPI_ISteamController_StopAnalogActionMomentum() { return nullptr; } // @145
void* SteamAPI_ISteamController_StopHapticPulse() { return nullptr; } // @146
void* SteamAPI_ISteamController_TranslateActionOrigin() { return nullptr; } // @147
void* SteamAPI_ISteamController_TriggerHapticPulse() { return nullptr; } // @148
void* SteamAPI_ISteamController_TriggerHapticPulse2() { return nullptr; } // @149
void* SteamAPI_ISteamController_TriggerSimpleHapticEvent() { return nullptr; } // @150
void* SteamAPI_ISteamController_TriggerVibration() { return nullptr; } // @151
void* SteamAPI_ISteamController_TriggerVibrationExtended() { return nullptr; } // @152
void* SteamAPI_ISteamController_Vibration() { return nullptr; } // @153
void* SteamAPI_ISteamFriends_ActivateGameOverlay() { return nullptr; } // @154
void* SteamAPI_ISteamFriends_ActivateGameOverlayToStore() { return nullptr; } // @155
void* SteamAPI_ISteamFriends_ActivateGameOverlayToUser() { return nullptr; } // @156
void* SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage() { return nullptr; } // @157
void* SteamAPI_ISteamFriends_ClearRichPresence() { return nullptr; } // @158
void* SteamAPI_ISteamFriends_DownloadClanActivityCounts() { return nullptr; } // @159
void* SteamAPI_ISteamFriends_DownloadClanOfficerList() { return nullptr; } // @160
void* SteamAPI_ISteamFriends_EnumerateFollowingList() { return nullptr; } // @161
void* SteamAPI_ISteamFriends_GetChatMemberByIndex() { return nullptr; } // @162
void* SteamAPI_ISteamFriends_GetClanActivityCounts() { return nullptr; } // @163
void* SteamAPI_ISteamFriends_GetClanByIndex() { return nullptr; } // @164
void* SteamAPI_ISteamFriends_GetClanChatMessages() { return nullptr; } // @165
void* SteamAPI_ISteamFriends_GetClanCount() { return nullptr; } // @166
void* SteamAPI_ISteamFriends_GetClanName() { return nullptr; } // @167
void* SteamAPI_ISteamFriends_GetClanOfficerCount() { return nullptr; } // @168
void* SteamAPI_ISteamFriends_GetClanOfficers() { return nullptr; } // @169
void* SteamAPI_ISteamFriends_GetClanOwner() { return nullptr; } // @170
void* SteamAPI_ISteamFriends_GetClanTag() { return nullptr; } // @171
void* SteamAPI_ISteamFriends_GetCoplayFriend() { return nullptr; } // @172
void* SteamAPI_ISteamFriends_GetCoplayFriendCount() { return nullptr; } // @173
void* SteamAPI_ISteamFriends_GetCoplayFriends() { return nullptr; } // @174
void* SteamAPI_ISteamFriends_GetFollowerCount() { return nullptr; } // @175
void* SteamAPI_ISteamFriends_GetFollowing() { return nullptr; } // @176
void* SteamAPI_ISteamFriends_GetFriendByIndex() { return nullptr; } // @177
void* SteamAPI_ISteamFriends_GetFriendCoplayGame() { return nullptr; } // @178
void* SteamAPI_ISteamFriends_GetFriendCoplayTime() { return nullptr; } // @179
void* SteamAPI_ISteamFriends_GetFriendCount() { return nullptr; } // @180
void* SteamAPI_ISteamFriends_GetFriendFromSourceByIndex() { return nullptr; } // @181
void* SteamAPI_ISteamFriends_GetFriendGamePlayed() { return nullptr; } // @182
void* SteamAPI_ISteamFriends_GetFriendGameServerInfo() { return nullptr; } // @183
void* SteamAPI_ISteamFriends_GetFriendGroup() { return nullptr; } // @184
void* SteamAPI_ISteamFriends_GetFriendGroupByIndex() { return nullptr; } // @185
void* SteamAPI_ISteamFriends_GetFriendGroupCount() { return nullptr; } // @186
void* SteamAPI_ISteamFriends_GetFriendGroups() { return nullptr; } // @187
void* SteamAPI_ISteamFriends_GetFriendPersonaName() { return nullptr; } // @188
void* SteamAPI_ISteamFriends_GetFriendPersonaNameHistory() { return nullptr; } // @189
void* SteamAPI_ISteamFriends_GetFriendPersonaState() { return nullptr; } // @190
void* SteamAPI_ISteamFriends_GetFriendRelationship() { return nullptr; } // @191
void* SteamAPI_ISteamFriends_GetFriendRichPresence() { return nullptr; } // @192
void* SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex() { return nullptr; } // @193
void* SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount() { return nullptr; } // @194
void* SteamAPI_ISteamFriends_GetFriendSteamLevel() { return nullptr; } // @195
void* SteamAPI_ISteamFriends_GetFriendsGroupID() { return nullptr; } // @196
void* SteamAPI_ISteamFriends_GetFriendsGroupName() { return nullptr; } // @197
void* SteamAPI_ISteamFriends_GetFriendsGroupMembersList() { return nullptr; } // @198
void* SteamAPI_ISteamFriends_GetFriendsGroupMembersCount() { return nullptr; } // @199
void* SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex() { return nullptr; } // @201
void* SteamAPI_ISteamFriends_GetFriendsGroupMembers() { return nullptr; } // @202
void* SteamAPI_ISteamFriends_GetFriendsGroupCount() { return nullptr; } // @204
void* SteamAPI_ISteamFriends_GetFriendsGroupNameByIndex() { return nullptr; } // @206
void* SteamAPI_ISteamFriends_GetGameBrowserEntry() { return nullptr; } // @207
void* SteamAPI_ISteamFriends_GetGameGamelingInfo() { return nullptr; } // @208
void* SteamAPI_ISteamFriends_GetGameListEntry() { return nullptr; } // @209
void* SteamAPI_ISteamFriends_GetGroupActivityCounts() { return nullptr; } // @210
void* SteamAPI_ISteamFriends_GetGroupByIndex() { return nullptr; } // @211
void* SteamAPI_ISteamFriends_GetGroupCount() { return nullptr; } // @212
void* SteamAPI_ISteamFriends_GetGroupName() { return nullptr; } // @213
void* SteamAPI_ISteamFriends_GetGroupTag() { return nullptr; } // @214
void* SteamAPI_ISteamFriends_GetLargeFriendAvatar() { return nullptr; } // @215
void* SteamAPI_ISteamFriends_GetMediumFriendAvatar() { return nullptr; } // @216
void* SteamAPI_ISteamFriends_GetNextRichPresenceKey() { return nullptr; } // @217
void* SteamAPI_ISteamFriends_GetOnlineFriendCount() { return nullptr; } // @218
void* SteamAPI_ISteamFriends_GetPersonaName() { return nullptr; } // @219
void* SteamAPI_ISteamFriends_GetPersonaState() { return nullptr; } // @220
void* SteamAPI_ISteamFriends_GetPersonaStateHistory() { return nullptr; } // @221
void* SteamAPI_ISteamFriends_GetPlayerAvatar() { return nullptr; } // @222
void* SteamAPI_ISteamFriends_GetSmallFriendAvatar() { return nullptr; } // @223
void* SteamAPI_ISteamFriends_GetFriendAvatar() { return nullptr; } // @224
void* SteamAPI_ISteamFriends_GetUserAvatar() { return nullptr; } // @225
void* SteamAPI_ISteamFriends_HasFriend() { return nullptr; } // @226
void* SteamAPI_ISteamFriends_IsUserInSource() { return nullptr; } // @227
void* SteamAPI_ISteamFriends_InviteUserToClan() { return nullptr; } // @228
void* SteamAPI_ISteamFriends_InviteUserToGame() { return nullptr; } // @229
void* SteamAPI_ISteamFriends_IsFollowing() { return nullptr; } // @230
void* SteamAPI_ISteamFriends_LeaveChatRoom() { return nullptr; } // @231
void* SteamAPI_ISteamFriends_LeaveClan() { return nullptr; } // @232
void* SteamAPI_ISteamFriends_OpenChatInviteInGameOverlay() { return nullptr; } // @233
void* SteamAPI_ISteamFriends_OpenClanChat() { return nullptr; } // @234
void* SteamAPI_ISteamFriends_OpenFriendsChat() { return nullptr; } // @235
void* SteamAPI_ISteamFriends_OpenGameInviteInGameOverlay() { return nullptr; } // @236
void* SteamAPI_ISteamFriends_OpenGuildInviteInGameOverlay() { return nullptr; } // @237
void* SteamAPI_ISteamFriends_OpenSteamFriendChat() { return nullptr; } // @238
void* SteamAPI_ISteamFriends_RegisterProtocol() { return nullptr; } // @239
void* SteamAPI_ISteamFriends_RemoveFriend() { return nullptr; } // @240
void* SteamAPI_ISteamFriends_RemoveFromSource() { return nullptr; } // @241
void* SteamAPI_ISteamFriends_RequestClanOfficerList() { return nullptr; } // @242
void* SteamAPI_ISteamFriends_RequestClosestPlayerData() { return nullptr; } // @243
void* SteamAPI_ISteamFriends_RequestFriendRichPresence() { return nullptr; } // @244
void* SteamAPI_ISteamFriends_RequestUserStats() { return nullptr; } // @245
void* SteamAPI_ISteamFriends_SendMsgToChat() { return nullptr; } // @246
void* SteamAPI_ISteamFriends_SetHasRichPresence() { return nullptr; } // @247
void* SteamAPI_ISteamFriends_SetListenForFriendsMessages() { return nullptr; } // @248
void* SteamAPI_ISteamFriends_SetPersonaName() { return nullptr; } // @249
void* SteamAPI_ISteamFriends_SetPersonaState() { return nullptr; } // @250
void* SteamAPI_ISteamFriends_SetRichPresence() { return nullptr; } // @251
void* SteamAPI_ISteamFriends_StoreRichPresence() { return nullptr; } // @252
void* SteamAPI_ISteamFriends_SubscribeToRepository() { return nullptr; } // @253
void* SteamAPI_ISteamFriends_UnsubscribeFromRepository() { return nullptr; } // @254
void* SteamAPI_ISteamFriends_IsFollower() { return nullptr; } // @256
void* SteamAPI_ISteamHTMLSurface_AllowStartRequest() { return nullptr; } // @257
void* SteamAPI_ISteamHTMLSurface_Cancel() { return nullptr; } // @258
void* SteamAPI_ISteamHTMLSurface_CreateCookie() { return nullptr; } // @259
void* SteamAPI_ISteamHTMLSurface_DeleteCookie() { return nullptr; } // @260
void* SteamAPI_ISteamHTMLSurface_Destroy() { return nullptr; } // @261
void* SteamAPI_ISteamHTMLSurface_Find() { return nullptr; } // @262
void* SteamAPI_ISteamHTMLSurface_GetLinkAtPosition() { return nullptr; } // @263
void* SteamAPI_ISteamHTMLSurface_GetSize() { return nullptr; } // @264
void* SteamAPI_ISteamHTMLSurface_GoBack() { return nullptr; } // @265
void* SteamAPI_ISteamHTMLSurface_GoForward() { return nullptr; } // @266
void* SteamAPI_ISteamHTMLSurface_HasContentFinished() { return nullptr; } // @267
void* SteamAPI_ISteamHTMLSurface_Init() { return nullptr; } // @268
void* SteamAPI_ISteamHTMLSurface_JSDialogResponse() { return nullptr; } // @269
void* SteamAPI_ISteamHTMLSurface_KeyChar() { return nullptr; } // @270
void* SteamAPI_ISteamHTMLSurface_KeyDown() { return nullptr; } // @271
void* SteamAPI_ISteamHTMLSurface_KeyUp() { return nullptr; } // @272
void* SteamAPI_ISteamHTMLSurface_LoadURL() { return nullptr; } // @273
void* SteamAPI_ISteamHTMLSurface_MouseDoubleClick() { return nullptr; } // @274
void* SteamAPI_ISteamHTMLSurface_MouseDown() { return nullptr; } // @275
void* SteamAPI_ISteamHTMLSurface_MouseMove() { return nullptr; } // @276
void* SteamAPI_ISteamHTMLSurface_MouseUp() { return nullptr; } // @277
void* SteamAPI_ISteamHTMLSurface_MouseWheel() { return nullptr; } // @278
void* SteamAPI_ISteamHTMLSurface_Navigate() { return nullptr; } // @279
void* SteamAPI_ISteamHTMLSurface_PasteFromClipboard() { return nullptr; } // @280
void* SteamAPI_ISteamHTMLSurface_Reload() { return nullptr; } // @281
void* SteamAPI_ISteamHTMLSurface_RemoveBrowser() { return nullptr; } // @282
void* SteamAPI_ISteamHTMLSurface_SetBackgroundMode() { return nullptr; } // @283
void* SteamAPI_ISteamHTMLSurface_SetCookie() { return nullptr; } // @284
void* SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor() { return nullptr; } // @285
void* SteamAPI_ISteamHTMLSurface_SetHorizontalScroll() { return nullptr; } // @286
void* SteamAPI_ISteamHTMLSurface_SetKeyFocus() { return nullptr; } // @287
void* SteamAPI_ISteamHTMLSurface_SetPageScaleFactor() { return nullptr; } // @288
void* SteamAPI_ISteamHTMLSurface_SetSize() { return nullptr; } // @289
void* SteamAPI_ISteamHTMLSurface_SetVerticalScroll() { return nullptr; } // @290
void* SteamAPI_ISteamHTMLSurface_Stop() { return nullptr; } // @291
void* SteamAPI_ISteamHTMLSurface_ViewSource() { return nullptr; } // @292
void* SteamAPI_ISteamHTTP_CreateHTTPRequest() { return nullptr; } // @293
void* SteamAPI_ISteamHTTP_DeferHTTPRequest() { return nullptr; } // @294
void* SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct() { return nullptr; } // @295
void* SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut() { return nullptr; } // @296
void* SteamAPI_ISteamHTTP_GetHTTPResponseBodyData() { return nullptr; } // @297
void* SteamAPI_ISteamHTTP_GetHTTPResponseBodySize() { return nullptr; } // @298
void* SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize() { return nullptr; } // @299
void* SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue() { return nullptr; } // @300
void* SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData() { return nullptr; } // @301
void* SteamAPI_ISteamHTTP_PrioritizeHTTPRequest() { return nullptr; } // @302
void* SteamAPI_ISteamHTTP_ReleaseHTTPRequest() { return nullptr; } // @303
void* SteamAPI_ISteamHTTP_SendHTTPRequest() { return nullptr; } // @304
void* SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse() { return nullptr; } // @305
void* SteamAPI_ISteamHTTP_SetHTTPRequestContextValue() { return nullptr; } // @306
void* SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer() { return nullptr; } // @307
void* SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter() { return nullptr; } // @308
void* SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue() { return nullptr; } // @309
void* SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout() { return nullptr; } // @310
void* SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody() { return nullptr; } // @311
void* SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate() { return nullptr; } // @312
void* SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo() { return nullptr; } // @313
void* SteamAPI_ISteamInput_ActivateActionSet() { return nullptr; } // @314
void* SteamAPI_ISteamInput_ActivateActionSetLayer() { return nullptr; } // @315
void* SteamAPI_ISteamInput_ActivateEchoActionSet() { return nullptr; } // @316
void* SteamAPI_ISteamInput_GetActionSetHandle() { return nullptr; } // @317
void* SteamAPI_ISteamInput_GetActiveActionSetLayers() { return nullptr; } // @318
void* SteamAPI_ISteamInput_GetAnalogActionData() { return nullptr; } // @319
void* SteamAPI_ISteamInput_GetAnalogActionHandle() { return nullptr; } // @320
void* SteamAPI_ISteamInput_GetAnalogActionOrigins() { return nullptr; } // @321
void* SteamAPI_ISteamInput_GetConnectedControllers() { return nullptr; } // @322
void* SteamAPI_ISteamInput_GetControllerBindingRevision() { return nullptr; } // @323
void* SteamAPI_ISteamInput_GetControllerForGamepadIndex() { return nullptr; } // @324
void* SteamAPI_ISteamInput_GetCurrentActionSet() { return nullptr; } // @325
void* SteamAPI_ISteamInput_GetDigitalActionData() { return nullptr; } // @326
void* SteamAPI_ISteamInput_GetDigitalActionOrigins() { return nullptr; } // @327
void* SteamAPI_ISteamInput_GetGamepadIndexForController() { return nullptr; } // @328
void* SteamAPI_ISteamInput_GetGlyphForActionOrigin() { return nullptr; } // @329
void* SteamAPI_ISteamInput_GetInputTypeForHandle() { return nullptr; } // @330
void* SteamAPI_ISteamInput_GetMotionData() { return nullptr; } // @331
void* SteamAPI_ISteamInput_GetRemotePlaySessionID() { return nullptr; } // @332
void* SteamAPI_ISteamInput_GetSessionInputConfigurationSettings() { return nullptr; } // @333
void* SteamAPI_ISteamInput_GetStringForActionOrigin() { return nullptr; } // @334
void* SteamAPI_ISteamInput_GetStringForAnalogActionName() { return nullptr; } // @335
void* SteamAPI_ISteamInput_GetStringForDigitalActionName() { return nullptr; } // @336
void* SteamAPI_ISteamInput_GetStringForXboxOrigin() { return nullptr; } // @337
void* SteamAPI_ISteamInput_Init() { return nullptr; } // @338
void* SteamAPI_ISteamInput_RunFrame() { return nullptr; } // @339
void* SteamAPI_ISteamInput_RunFrame_StoreActions() { return nullptr; } // @340
void* SteamAPI_ISteamInput_SetActionSetReference() { return nullptr; } // @341
void* SteamAPI_ISteamInput_SetChannel() { return nullptr; } // @342
void* SteamAPI_ISteamInput_SetConnectedController() { return nullptr; } // @343
void* SteamAPI_ISteamInput_SetCurrentActionSet() { return nullptr; } // @344
void* SteamAPI_ISteamInput_SetLEDColor() { return nullptr; } // @345
void* SteamAPI_ISteamInput_SetMotion() { return nullptr; } // @346
void* SteamAPI_ISteamInput_ShowBindingPanel() { return nullptr; } // @347
void* SteamAPI_ISteamInput_Shutdown() { return nullptr; } // @348
void* SteamAPI_ISteamInput_ShowDigitalActionOrigins() { return nullptr; } // @349
void* SteamAPI_ISteamInput_ShowAnalogActionOrigins() { return nullptr; } // @350
void* SteamAPI_ISteamInput_StopAnalogActionMomentum() { return nullptr; } // @351
void* SteamAPI_ISteamInput_StopHapticPulse() { return nullptr; } // @352
void* SteamAPI_ISteamInput_StopHapticPulse2() { return nullptr; } // @353
void* SteamAPI_ISteamInput_TriggerHapticPulse() { return nullptr; } // @354
void* SteamAPI_ISteamInput_TriggerHapticPulse2() { return nullptr; } // @355
void* SteamAPI_ISteamInput_TriggerSimpleHapticEvent() { return nullptr; } // @356
void* SteamAPI_ISteamInput_TriggerVibration() { return nullptr; } // @357
void* SteamAPI_ISteamInput_TriggerVibrationExtended() { return nullptr; } // @358
void* SteamAPI_ISteamInput_Vibration() { return nullptr; } // @359
void* SteamAPI_ISteamInventory_AddPromoItem() { return nullptr; } // @360
void* SteamAPI_ISteamInventory_AddPromoItems() { return nullptr; } // @361
void* SteamAPI_ISteamInventory_CheckResultSteamID() { return nullptr; } // @362
void* SteamAPI_ISteamInventory_ExchangeItems() { return nullptr; } // @363
void* SteamAPI_ISteamInventory_GenerateItems() { return nullptr; } // @364
void* SteamAPI_ISteamInventory_GetAllItems() { return nullptr; } // @365
void* SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs() { return nullptr; } // @366
void* SteamAPI_ISteamInventory_GetItemByID() { return nullptr; } // @367
void* SteamAPI_ISteamInventory_GetItemDefinition() { return nullptr; } // @368
void* SteamAPI_ISteamInventory_GetItemDefinitionIDs() { return nullptr; } // @369
void* SteamAPI_ISteamInventory_GetItemDefinitionProperty() { return nullptr; } // @370
void* SteamAPI_ISteamInventory_GetItemIDs() { return nullptr; } // @371
void* SteamAPI_ISteamInventory_GetItemPrice() { return nullptr; } // @372
void* SteamAPI_ISteamInventory_GetItemsByID() { return nullptr; } // @373
void* SteamAPI_ISteamInventory_GetItemsWithPrices() { return nullptr; } // @374
void* SteamAPI_ISteamInventory_GetNumItemsWithPrices() { return nullptr; } // @375
void* SteamAPI_ISteamInventory_GetResultItemProperty() { return nullptr; } // @376
void* SteamAPI_ISteamInventory_GetResultItems() { return nullptr; } // @377
void* SteamAPI_ISteamInventory_GetResultStatus() { return nullptr; } // @378
void* SteamAPI_ISteamInventory_GetStackableQuantity() { return nullptr; } // @379
void* SteamAPI_ISteamInventory_LoadItemDefinitions() { return nullptr; } // @380
void* SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitions() { return nullptr; } // @381
void* SteamAPI_ISteamInventory_RequestPrices() { return nullptr; } // @382
void* SteamAPI_ISteamInventory_Serialize() { return nullptr; } // @383
void* SteamAPI_ISteamInventory_SerializeResult() { return nullptr; } // @384
void* SteamAPI_ISteamInventory_SetProperty() { return nullptr; } // @385
void* SteamAPI_ISteamInventory_SetProperty0() { return nullptr; } // @386
void* SteamAPI_ISteamInventory_StartPurchase() { return nullptr; } // @390
void* SteamAPI_ISteamInventory_StartUpdateProperties() { return nullptr; } // @391
void* SteamAPI_ISteamInventory_SubmitUpdateProperties() { return nullptr; } // @392
void* SteamAPI_ISteamInventory_TransferItemQuantity() { return nullptr; } // @393
void* SteamAPI_ISteamInventory_TriggerItemDrop() { return nullptr; } // @394
void* SteamAPI_ISteamMatchmaking_AddFavoriteGame() { return nullptr; } // @395
void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter() { return nullptr; } // @396
void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable() { return nullptr; } // @397
void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter() { return nullptr; } // @398
void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter() { return nullptr; } // @399
void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter() { return nullptr; } // @400
void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListWarehouseFilter() { return nullptr; } // @401
void* SteamAPI_ISteamMatchmaking_CloseChat() { return nullptr; } // @402
void* SteamAPI_ISteamMatchmaking_CloseClanChat() { return nullptr; } // @403
void* SteamAPI_ISteamMatchmaking_CloseP2PWithUser() { return nullptr; } // @404
void* SteamAPI_ISteamMatchmaking_CreateLobby() { return nullptr; } // @405
void* SteamAPI_ISteamMatchmaking_CreateQuery() { return nullptr; } // @406
void* SteamAPI_ISteamMatchmaking_DeleteServer() { return nullptr; } // @407
void* SteamAPI_ISteamMatchmaking_Destroy() { return nullptr; } // @408
void* SteamAPI_ISteamMatchmaking_DestroyLobby() { return nullptr; } // @409
void* SteamAPI_ISteamMatchmaking_GetArtifactContents() { return nullptr; } // @410
void* SteamAPI_ISteamMatchmaking_GetArtifactCount() { return nullptr; } // @411
void* SteamAPI_ISteamMatchmaking_GetChats() { return nullptr; } // @412
void* SteamAPI_ISteamMatchmaking_GetClientPing() { return nullptr; } // @413
void* SteamAPI_ISteamMatchmaking_GetLobby() { return nullptr; } // @414
void* SteamAPI_ISteamMatchmaking_GetLobbyByIndex() { return nullptr; } // @415
void* SteamAPI_ISteamMatchmaking_GetLobbyChatEntry() { return nullptr; } // @416
void* SteamAPI_ISteamMatchmaking_GetLobbyChatMessage() { return nullptr; } // @417
void* SteamAPI_ISteamMatchmaking_GetLobbyData() { return nullptr; } // @418
void* SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex() { return nullptr; } // @419
void* SteamAPI_ISteamMatchmaking_GetLobbyDataCount() { return nullptr; } // @420
void* SteamAPI_ISteamMatchmaking_GetLobbyGameServer() { return nullptr; } // @421
void* SteamAPI_ISteamMatchmaking_GetLobbyGameServerList() { return nullptr; } // @422
void* SteamAPI_ISteamMatchmaking_GetLobbyID() { return nullptr; } // @423
void* SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex() { return nullptr; } // @424
void* SteamAPI_ISteamMatchmaking_GetLobbyMemberCount() { return nullptr; } // @425
void* SteamAPI_ISteamMatchmaking_GetLobbyMemberData() { return nullptr; } // @426
void* SteamAPI_ISteamMatchmaking_GetLobbyMetadata() { return nullptr; } // @427
void* SteamAPI_ISteamMatchmaking_GetLobbyMetadataByIndex() { return nullptr; } // @428
void* SteamAPI_ISteamMatchmaking_GetLobbyMetadataCount() { return nullptr; } // @429
void* SteamAPI_ISteamMatchmaking_GetLobbyChat() { return nullptr; } // @430
void* SteamAPI_ISteamMatchmaking_GetMatchmaking() { return nullptr; } // @431
void* SteamAPI_ISteamMatchmaking_GetNumChatsWith() { return nullptr; } // @432
void* SteamAPI_ISteamMatchmaking_GetFavoriteGame() { return nullptr; } // @433
void* SteamAPI_ISteamMatchmaking_GetFavoriteGameCount() { return nullptr; } // @434
void* SteamAPI_ISteamMatchmaking_GetServer() { return nullptr; } // @435
void* SteamAPI_ISteamMatchmaking_GetServerByIndex() { return nullptr; } // @436
void* SteamAPI_ISteamMatchmaking_GetServerCount() { return nullptr; } // @437
void* SteamAPI_ISteamMatchmaking_GetServerDetails() { return nullptr; } // @438
void* SteamAPI_ISteamMatchmaking_GetServerList() { return nullptr; } // @439
void* SteamAPI_ISteamMatchmaking_GetServerPing() { return nullptr; } // @440
void* SteamAPI_ISteamMatchmaking_GetSessionParams() { return nullptr; } // @441
void* SteamAPI_ISteamMatchmaking_GetUserDetail() { return nullptr; } // @442
void* SteamAPI_ISteamMatchmaking_InitiateConnection() { return nullptr; } // @443
void* SteamAPI_ISteamMatchmaking_InviteUserToLobby() { return nullptr; } // @444
void* SteamAPI_ISteamMatchmaking_InviteUserToLobbyByID() { return nullptr; } // @445
void* SteamAPI_ISteamMatchmaking_IsConnected() { return nullptr; } // @446
void* SteamAPI_ISteamMatchmaking_IsPingInProgress() { return nullptr; } // @447
void* SteamAPI_ISteamMatchmaking_LeaveLobby() { return nullptr; } // @448
void* SteamAPI_ISteamMatchmaking_Log() { return nullptr; } // @449
void* SteamAPI_ISteamMatchmaking_OnConsoleConnect() { return nullptr; } // @450
void* SteamAPI_ISteamMatchmaking_OnConsoleDisconnect() { return nullptr; } // @451
void* SteamAPI_ISteamMatchmaking_OnP2PConnect() { return nullptr; } // @452
void* SteamAPI_ISteamMatchmaking_OnP2PDisconnect() { return nullptr; } // @453
void* SteamAPI_ISteamMatchmaking_Ping() { return nullptr; } // @454
void* SteamAPI_ISteamMatchmaking_PingResponse() { return nullptr; } // @455
void* SteamAPI_ISteamMatchmaking_RemoveFavoriteGame() { return nullptr; } // @456
void* SteamAPI_ISteamMatchmaking_RemoveRequestLobbyListDistanceFilter() { return nullptr; } // @457
void* SteamAPI_ISteamMatchmaking_RemoveRequestLobbyListFilterSlotsAvailable() { return nullptr; } // @458
void* SteamAPI_ISteamMatchmaking_RemoveRequestLobbyListNearValueFilter() { return nullptr; } // @459
void* SteamAPI_ISteamMatchmaking_RemoveRequestLobbyListNumericalFilter() { return nullptr; } // @460
void* SteamAPI_ISteamMatchmaking_RemoveRequestLobbyListStringFilter() { return nullptr; } // @461
void* SteamAPI_ISteamMatchmaking_RemoveRequestLobbyListWarehouseFilter() { return nullptr; } // @462
void* SteamAPI_ISteamMatchmaking_Request() { return nullptr; } // @463
void* SteamAPI_ISteamMatchmaking_RequestChats() { return nullptr; } // @464
void* SteamAPI_ISteamMatchmaking_RequestClanOfficerList() { return nullptr; } // @465
void* SteamAPI_ISteamMatchmaking_RequestFriendsLobbies() { return nullptr; } // @466
void* SteamAPI_ISteamMatchmaking_RequestGlobalClanList() { return nullptr; } // @467
void* SteamAPI_ISteamMatchmaking_RequestGroup() { return nullptr; } // @468
void* SteamAPI_ISteamMatchmaking_RequestGroupOfficers() { return nullptr; } // @469
void* SteamAPI_ISteamMatchmaking_RequestLobbyList() { return nullptr; } // @470
void* SteamAPI_ISteamMatchmaking_RequestMatches() { return nullptr; } // @471
void* SteamAPI_ISteamMatchmaking_RequestMemberByIndex() { return nullptr; } // @472
void* SteamAPI_ISteamMatchmaking_RequestPrivateUserData() { return nullptr; } // @473
void* SteamAPI_ISteamMatchmaking_RequestQuery() { return nullptr; } // @474
void* SteamAPI_ISteamMatchmaking_RequestServerList() { return nullptr; } // @475
void* SteamAPI_ISteamMatchmaking_RequestUserInfo() { return nullptr; } // @476
void* SteamAPI_ISteamMatchmaking_SendLobbyChatMsg() { return nullptr; } // @477
void* SteamAPI_ISteamMatchmaking_SendP2PPacket() { return nullptr; } // @478
void* SteamAPI_ISteamMatchmaking_SetAlwaysAccept() { return nullptr; } // @479
void* SteamAPI_ISteamMatchmaking_SetCallbacks() { return nullptr; } // @480
void* SteamAPI_ISteamMatchmaking_SetConnectedClan() { return nullptr; } // @481
void* SteamAPI_ISteamMatchmaking_SetContactSockets() { return nullptr; } // @482
void* SteamAPI_ISteamMatchmaking_SetCTTT() { return nullptr; } // @483
void* SteamAPI_ISteamMatchmaking_SetGameData() { return nullptr; } // @484
void* SteamAPI_ISteamMatchmaking_SetGameDataNoLock() { return nullptr; } // @485
void* SteamAPI_ISteamMatchmaking_SetGameLobby() { return nullptr; } // @486
void* SteamAPI_ISteamMatchmaking_SetGameServer() { return nullptr; } // @487
void* SteamAPI_ISteamMatchmaking_SetGameServerNoLock() { return nullptr; } // @488
void* SteamAPI_ISteamMatchmaking_SetLobby() { return nullptr; } // @489
void* SteamAPI_ISteamMatchmaking_SetLobbyAdmin() { return nullptr; } // @490
void* SteamAPI_ISteamMatchmaking_SetLobbyChat() { return nullptr; } // @491
void* SteamAPI_ISteamMatchmaking_SetLobbyData() { return nullptr; } // @492
void* SteamAPI_ISteamMatchmaking_SetLobbyData64() { return nullptr; } // @493
void* SteamAPI_ISteamMatchmaking_SetLobbyEmpty() { return nullptr; } // @494
void* SteamAPI_ISteamMatchmaking_SetLobbyGameServer() { return nullptr; } // @495
void* SteamAPI_ISteamMatchmaking_SetLobbyKind() { return nullptr; } // @496
void* SteamAPI_ISteamMatchmaking_SetLobbyLimit() { return nullptr; } // @497
void* SteamAPI_ISteamMatchmaking_SetLobbyMemberData() { return nullptr; } // @498
void* SteamAPI_ISteamMatchmaking_SetLobbyOwner() { return nullptr; } // @499
void* SteamAPI_ISteamMatchmaking_SetLobbyPrivate() { return nullptr; } // @500
void* SteamAPI_ISteamMatchmaking_SetLobbyPublic() { return nullptr; } // @501
void* SteamAPI_ISteamMatchmaking_SetLobbyVisible() { return nullptr; } // @502
void* SteamAPI_ISteamMatchmaking_SetMaster() { return nullptr; } // @503
void* SteamAPI_ISteamMatchmaking_SetMetadata() { return nullptr; } // @504
void* SteamAPI_ISteamMatchmaking_SetNetworkOn() { return nullptr; } // @505
void* SteamAPI_ISteamMatchmaking_SetPacketSize() { return nullptr; } // @506
void* SteamAPI_ISteamMatchmaking_SetPing() { return nullptr; } // @507
void* SteamAPI_ISteamMatchmaking_SetPort() { return nullptr; } // @508
void* SteamAPI_ISteamMatchmaking_SetProtocol() { return nullptr; } // @509
void* SteamAPI_ISteamMatchmaking_SetRemovable() { return nullptr; } // @510
void* SteamAPI_ISteamMatchmaking_SetServer() { return nullptr; } // @511
void* SteamAPI_ISteamMatchmaking_SetServerGroup() { return nullptr; } // @512
void* SteamAPI_ISteamMatchmaking_SetServerList() { return nullptr; } // @513
void* SteamAPI_ISteamMatchmaking_SetSpawn() { return nullptr; } // @514
void* SteamAPI_ISteamMatchmaking_SetToken() { return nullptr; } // @515
void* SteamAPI_ISteamMatchmaking_SetType() { return nullptr; } // @516
void* SteamAPI_ISteamMatchmaking_SetUsername() { return nullptr; } // @517
void* SteamAPI_ISteamMatchmaking_Startup() { return nullptr; } // @518
void* SteamAPI_ISteamMatchmaking_UpdateSession() { return nullptr; } // @519
void* SteamAPI_ISteamMatchmakingClient_CancelServerQuery() { return nullptr; } // @520
void* SteamAPI_ISteamMatchmakingClient_CheckConnection() { return nullptr; } // @521
void* SteamAPI_ISteamMatchmakingClient_Connect() { return nullptr; } // @523
void* SteamAPI_ISteamMatchmakingClient_ConnectP2P() { return nullptr; } // @524
void* SteamAPI_ISteamMatchmakingClient_ConnectP2PRelay() { return nullptr; } // @525
void* SteamAPI_ISteamMatchmakingClient_CreateConnect() { return nullptr; } // @526
void* SteamAPI_ISteamMatchmakingClient_GetChat() { return nullptr; } // @527
void* SteamAPI_ISteamMatchmakingClient_GetLobbyService() { return nullptr; } // @528
void* SteamAPI_ISteamMatchmakingClient_GetMatchmaking() { return nullptr; } // @529
void* SteamAPI_ISteamMatchmakingClient_GetPing() { return nullptr; } // @530
void* SteamAPI_ISteamMatchmakingClient_GetPublicIP() { return nullptr; } // @531
void* SteamAPI_ISteamMatchmakingClient_IsConnected() { return nullptr; } // @532
void* SteamAPI_ISteamMatchmakingClient_IsRelay() { return nullptr; } // @533
void* SteamAPI_ISteamMatchmakingClient_SendMsg() { return nullptr; } // @534
void* SteamAPI_ISteamMatchmakingServers_CancelQuery() { return nullptr; } // @535
void* SteamAPI_ISteamMatchmakingServers_CancelServerQuery() { return nullptr; } // @536
void* SteamAPI_ISteamMatchmakingServers_Close() { return nullptr; } // @537
void* SteamAPI_ISteamMatchmakingServers_CreateQuery() { return nullptr; } // @538
void* SteamAPI_ISteamMatchmakingServers_DestroyRequest() { return nullptr; } // @539
void* SteamAPI_ISteamMatchmakingServers_GetServerDetails() { return nullptr; } // @540
void* SteamAPI_ISteamMatchmakingServers_GetServerList() { return nullptr; } // @541
void* SteamAPI_ISteamMatchmakingServers_GetServerPing() { return nullptr; } // @542
void* SteamAPI_ISteamMatchmakingServers_GetSessionToken() { return nullptr; } // @543
void* SteamAPI_ISteamMatchmakingServers_GetVersion() { return nullptr; } // @544
void* SteamAPI_ISteamMatchmakingServers_HandleIncomingPacket() { return nullptr; } // @545
void* SteamAPI_ISteamMatchmakingServers_Init() { return nullptr; } // @546
void* SteamAPI_ISteamMatchmakingServers_JoinServer() { return nullptr; } // @547
void* SteamAPI_ISteamMatchmakingServers_LeaveServer() { return nullptr; } // @548
void* SteamAPI_ISteamMatchmakingServers_PingServer() { return nullptr; } // @549
void* SteamAPI_ISteamMatchmakingServers_Refresh() { return nullptr; } // @550
void* SteamAPI_ISteamMatchmakingServers_RefreshQuery() { return nullptr; } // @551
void* SteamAPI_ISteamMatchmakingServers_RefreshServer() { return nullptr; } // @552
void* SteamAPI_ISteamMatchmakingServers_RefreshServerByIndex() { return nullptr; } // @553
void* SteamAPI_ISteamMatchmakingServers_RequestAppList() { return nullptr; } // @554
void* SteamAPI_ISteamMatchmakingServers_RequestGroup() { return nullptr; } // @555
void* SteamAPI_ISteamMatchmakingServers_RequestHeartbeat() { return nullptr; } // @556
void* SteamAPI_ISteamMatchmakingServers_RequestLANServers() { return nullptr; } // @557
void* SteamAPI_ISteamMatchmakingServers_RequestLegacyServerList() { return nullptr; } // @558
void* SteamAPI_ISteamMatchmakingServers_RequestLocalServer() { return nullptr; } // @559
void* SteamAPI_ISteamMatchmakingServers_RequestMasters() { return nullptr; } // @560
void* SteamAPI_ISteamMatchmakingServers_RequestNeighbors() { return nullptr; } // @561
void* SteamAPI_ISteamMatchmakingServers_RequestOtherUser() { return nullptr; } // @562
void* SteamAPI_ISteamMatchmakingServers_RequestPing() { return nullptr; } // @563
void* SteamAPI_ISteamMatchmakingServers_RequestPlayerList() { return nullptr; } // @564
void* SteamAPI_ISteamMatchmakingServers_RequestRules() { return nullptr; } // @565
void* SteamAPI_ISteamMatchmakingServers_RequestServer() { return nullptr; } // @566
void* SteamAPI_ISteamMatchmakingServers_RequestServerByIndex() { return nullptr; } // @567
void* SteamAPI_ISteamMatchmakingServers_RequestServers() { return nullptr; } // @568
void* SteamAPI_ISteamMatchmakingServers_RequestServersMatchmaking() { return nullptr; } // @569
void* SteamAPI_ISteamMatchmakingServers_SendResponse() { return nullptr; } // @570
void* SteamAPI_ISteamMatchmakingServers_SendUserConnect() { return nullptr; } // @571
void* SteamAPI_ISteamMatchmakingServers_SendUserDisconnect() { return nullptr; } // @572
void* SteamAPI_ISteamMatchmakingServers_SetGame() { return nullptr; } // @573
void* SteamAPI_ISteamMatchmakingServers_SetHeartbeat() { return nullptr; } // @574
void* SteamAPI_ISteamMatchmakingServers_SetPassword() { return nullptr; } // @575
void* SteamAPI_ISteamMatchmakingServers_SetPing() { return nullptr; } // @576
void* SteamAPI_ISteamMatchmakingServers_SetPort() { return nullptr; } // @577
void* SteamAPI_ISteamMatchmakingServers_SetProtocol() { return nullptr; } // @578
void* SteamAPI_ISteamMatchmakingServers_SetRegion() { return nullptr; } // @579
void* SteamAPI_ISteamMatchmakingServers_SetServer() { return nullptr; } // @580
void* SteamAPI_ISteamMatchmakingServers_SetServerList() { return nullptr; } // @581
void* SteamAPI_ISteamMatchmakingServers_Startup() { return nullptr; } // @582
void* SteamAPI_ISteamMatchmakingServers_Update() { return nullptr; } // @583
void* SteamAPI_ISteamNetworking_AcceptP2PSession() { return nullptr; } // @584
void* SteamAPI_ISteamNetworking_AllowP2PPacketRelay() { return nullptr; } // @585
void* SteamAPI_ISteamNetworking_CloseP2PChannelWithUser() { return nullptr; } // @586
void* SteamAPI_ISteamNetworking_CloseP2PSessionWithUser() { return nullptr; } // @587
void* SteamAPI_ISteamNetworking_ConnectP2P() { return nullptr; } // @588
void* SteamAPI_ISteamNetworking_ConnectP2PCustomSignaling() { return nullptr; } // @589
void* SteamAPI_ISteamNetworking_ConnectP2PRelay() { return nullptr; } // @591
void* SteamAPI_ISteamNetworking_ConnectTCPP() { return nullptr; } // @592
void* SteamAPI_ISteamNetworking_CreateConnect() { return nullptr; } // @593
void* SteamAPI_ISteamNetworking_CreateLobby() { return nullptr; } // @594
void* SteamAPI_ISteamNetworking_CreateP2PConnectionSocket() { return nullptr; } // @595
void* SteamAPI_ISteamNetworking_CreateP2PListenSocket() { return nullptr; } // @597
void* SteamAPI_ISteamNetworking_CreateP2PListenSocketCustom() { return nullptr; } // @599
void* SteamAPI_ISteamNetworking_CreateQuery() { return nullptr; } // @600
void* SteamAPI_ISteamNetworking_CreateSocket() { return nullptr; } // @601
void* SteamAPI_ISteamNetworking_DestroyListenSocket() { return nullptr; } // @602
void* SteamAPI_ISteamNetworking_DestroyP2PListenerSocket() { return nullptr; } // @603
void* SteamAPI_ISteamNetworking_DestroySocket() { return nullptr; } // @604
void* SteamAPI_ISteamNetworking_Disconnect() { return nullptr; } // @605
void* SteamAPI_ISteamNetworking_GetIdentity() { return nullptr; } // @606
void* SteamAPI_ISteamNetworking_GetListenSocketAddress() { return nullptr; } // @607
void* SteamAPI_ISteamNetworking_GetMaxPacketSize() { return nullptr; } // @608
void* SteamAPI_ISteamNetworking_GetP2PConnectionInfo() { return nullptr; } // @609
void* SteamAPI_ISteamNetworking_GetP2PSessionState() { return nullptr; } // @610
void* SteamAPI_ISteamNetworking_GetPacketSize() { return nullptr; } // @611
void* SteamAPI_ISteamNetworking_GetSockets() { return nullptr; } // @612
void* SteamAPI_ISteamNetworking_Init() { return nullptr; } // @613
void* SteamAPI_ISteamNetworking_IsDataAvailable() { return nullptr; } // @614
void* SteamAPI_ISteamNetworking_IsDataAvailableOnSocket() { return nullptr; } // @615
void* SteamAPI_ISteamNetworking_IsListening() { return nullptr; } // @616
void* SteamAPI_ISteamNetworking_ListenOnChannel() { return nullptr; } // @617
void* SteamAPI_ISteamNetworking_ReceiveDataOnSocket() { return nullptr; } // @618
void* SteamAPI_ISteamNetworking_ReceiveP2PPacket() { return nullptr; } // @619
void* SteamAPI_ISteamNetworking_RejectSession() { return nullptr; } // @621
void* SteamAPI_ISteamNetworking_SendDataOnSocket() { return nullptr; } // @622
void* SteamAPI_ISteamNetworking_SendDataToSocket() { return nullptr; } // @623
void* SteamAPI_ISteamNetworking_SendP2P() { return nullptr; } // @624
void* SteamAPI_ISteamNetworking_SendP2PCustomSignal() { return nullptr; } // @625
void* SteamAPI_ISteamNetworking_SendP2PPacket() { return nullptr; } // @626
void* SteamAPI_ISteamNetworking_SendPacket() { return nullptr; } // @627
void* SteamAPI_ISteamNetworking_SetP2PConnect() { return nullptr; } // @628
void* SteamAPI_ISteamNetworking_SetP2PCustomSignaling() { return nullptr; } // @629
void* SteamAPI_ISteamNetworking_SetP2PSessionConnect() { return nullptr; } // @630
void* SteamAPI_ISteamNetworking_SetP2PSessionDisconnect() { return nullptr; } // @631
void* SteamAPI_ISteamNetworking_SetP2PSessionInfo() { return nullptr; } // @632
void* SteamAPI_ISteamNetworking_SetP2PSessionSettings() { return nullptr; } // @633
void* SteamAPI_ISteamNetworking_SetSocket() { return nullptr; } // @634
void* SteamAPI_ISteamNetworking_SetSpawn() { return nullptr; } // @635
void* SteamAPI_ISteamNetworking_Shutdown() { return nullptr; } // @636
void* SteamAPI_ISteamNetworking_StartHackingWebSockets() { return nullptr; } // @637
void* SteamAPI_ISteamNetworking_UseSocket() { return nullptr; } // @638
void* SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel() { return nullptr; } // @640
void* SteamAPI_ISteamNetworkingMessages_SendMessageToUser() { return nullptr; } // @641
void* SteamAPI_ISteamNetworkingSockets_AcceptConnection() { return nullptr; } // @642
void* SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP() { return nullptr; } // @643
void* SteamAPI_ISteamNetworkingSockets_CloseConnection() { return nullptr; } // @644
void* SteamAPI_ISteamNetworkingSockets_CloseListenSocket() { return nullptr; } // @645
void* SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes() { return nullptr; } // @646
void* SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress() { return nullptr; } // @647
void* SteamAPI_ISteamNetworkingSockets_ConnectCallback() { return nullptr; } // @648
void* SteamAPI_ISteamNetworkingSockets_ConnectConnect() { return nullptr; } // @649
void* SteamAPI_ISteamNetworkingSockets_ConnectP2P() { return nullptr; } // @650
void* SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling() { return nullptr; } // @651
void* SteamAPI_ISteamNetworkingSockets_ConnectP2PRelay() { return nullptr; } // @652
void* SteamAPI_ISteamNetworkingSockets_CreateFakeIPPair() { return nullptr; } // @653
void* SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket() { return nullptr; } // @654
void* SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP() { return nullptr; } // @655
void* SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P() { return nullptr; } // @656
void* SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP() { return nullptr; } // @657
void* SteamAPI_ISteamNetworkingSockets_CreatePollGroup() { return nullptr; } // @658
void* SteamAPI_ISteamNetworkingSockets_CreateSocketPair() { return nullptr; } // @659
void* SteamAPI_ISteamNetworkingSockets_DestroyFakeIPPair() { return nullptr; } // @660
void* SteamAPI_ISteamNetworkingSockets_DestroyPollGroup() { return nullptr; } // @661
void* SteamAPI_ISteamNetworkingSockets_EndFakeIPPair() { return nullptr; } // @662
void* SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer() { return nullptr; } // @663
void* SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection() { return nullptr; } // @664
void* SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus() { return nullptr; } // @665
void* SteamAPI_ISteamNetworkingSockets_GetCertificateRequest() { return nullptr; } // @666
void* SteamAPI_ISteamNetworkingSockets_GetConnectionInfo() { return nullptr; } // @667
void* SteamAPI_ISteamNetworkingSockets_GetConnectionName() { return nullptr; } // @668
void* SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus() { return nullptr; } // @669
void* SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus() { return nullptr; } // @670
void* SteamAPI_ISteamNetworkingSockets_GetFakeIP() { return nullptr; } // @671
void* SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin() { return nullptr; } // @672
void* SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress() { return nullptr; } // @673
void* SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID() { return nullptr; } // @674
void* SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort() { return nullptr; } // @675
void* SteamAPI_ISteamNetworkingSockets_GetIdentity() { return nullptr; } // @676
void* SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress() { return nullptr; } // @677
void* SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection() { return nullptr; } // @678
void* SteamAPI_ISteamNetworkingSockets_InitAuthentication() { return nullptr; } // @679
void* SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket() { return nullptr; } // @680
void* SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection() { return nullptr; } // @681
void* SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup() { return nullptr; } // @682
void* SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal() { return nullptr; } // @683
void* SteamAPI_ISteamNetworkingSockets_ResetIdentity() { return nullptr; } // @685
void* SteamAPI_ISteamNetworkingSockets_SendMessageToConnection() { return nullptr; } // @686
void* SteamAPI_ISteamNetworkingSockets_SendRemoteHost() { return nullptr; } // @687
void* SteamAPI_ISteamNetworkingSockets_SendSignal() { return nullptr; } // @688
void* SteamAPI_ISteamNetworkingSockets_SetConnectionUserData() { return nullptr; } // @689
void* SteamAPI_ISteamNetworkingSockets_SetGlobalConfigValueBool() { return nullptr; } // @690
void* SteamAPI_ISteamNetworkingSockets_SetGlobalConfigValueFloat() { return nullptr; } // @691
void* SteamAPI_ISteamNetworkingSockets_SetGlobalConfigValueInt32() { return nullptr; } // @692
void* SteamAPI_ISteamNetworkingSockets_SetGlobalConfigValueInt64() { return nullptr; } // @693
void* SteamAPI_ISteamNetworkingSockets_SetGlobalConfigValueString() { return nullptr; } // @694
void* SteamAPI_ISteamNetworkingSockets_SetLocalMode() { return nullptr; } // @695
void* SteamAPI_ISteamNetworkingSockets_SetConnectionConfigValueBool() { return nullptr; } // @696
void* SteamAPI_ISteamNetworkingSockets_SetConnectionConfigValueFloat() { return nullptr; } // @697
void* SteamAPI_ISteamNetworkingSockets_SetConnectionConfigValueInt32() { return nullptr; } // @698
void* SteamAPI_ISteamNetworkingSockets_SetConnectionConfigValueInt64() { return nullptr; } // @699
void* SteamAPI_ISteamNetworkingSockets_SetConnectionConfigValueString() { return nullptr; } // @700
void* SteamAPI_ISteamNetworkingUtils_AllocateMessage() { return nullptr; } // @701
void* SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate() { return nullptr; } // @702
void* SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString() { return nullptr; } // @703
void* SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations() { return nullptr; } // @704
void* SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost() { return nullptr; } // @705
void* SteamAPI_ISteamNetworkingUtils_GetConfigValue() { return nullptr; } // @706
void* SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo() { return nullptr; } // @707
void* SteamAPI_ISteamNetworkingUtils_GetConnectionInfo() { return nullptr; } // @708
void* SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP() { return nullptr; } // @709
void* SteamAPI_ISteamNetworkingUtils_GetFakeIP() { return nullptr; } // @710
void* SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType() { return nullptr; } // @711
void* SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation() { return nullptr; } // @712
void* SteamAPI_ISteamNetworkingUtils_GetNetworkInfo() { return nullptr; } // @713
void* SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus() { return nullptr; } // @714
void* SteamAPI_ISteamNetworkingUtils_GetSTUNStatus() { return nullptr; } // @715
void* SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess() { return nullptr; } // @716
void* SteamAPI_ISteamNetworkingUtils_IsFakeIPv4() { return nullptr; } // @717
void* SteamAPI_ISteamNetworkingUtils_IterateGenericConfigValues() { return nullptr; } // @718
void* SteamAPI_ISteamNetworkingUtils_ParsePingLocationString() { return nullptr; } // @720
void* SteamAPI_ISteamNetworkingUtils_ResetAllConfigValues() { return nullptr; } // @721
void* SteamAPI_ISteamNetworkingUtils_SetConfigValueBool() { return nullptr; } // @722
void* SteamAPI_ISteamNetworkingUtils_SetConfigValueFloat() { return nullptr; } // @723
void* SteamAPI_ISteamNetworkingUtils_SetConfigValueInt32() { return nullptr; } // @724
void* SteamAPI_ISteamNetworkingUtils_SetConfigValueInt64() { return nullptr; } // @725
void* SteamAPI_ISteamNetworkingUtils_SetConfigValueString() { return nullptr; } // @726
void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetworkingMessagesSessionFailed() { return nullptr; } // @727
void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetworkingMessagesSessionRequest() { return nullptr; } // @728
void* SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueBool() { return nullptr; } // @729
void* SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueFloat() { return nullptr; } // @730
void* SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueInt32() { return nullptr; } // @731
void* SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueInt64() { return nullptr; } // @732
void* SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueString() { return nullptr; } // @733
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType() { return nullptr; } // @734
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_HasBeenLocallyModified() { return nullptr; } // @735
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_IsLocalhost() { return nullptr; } // @736
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString() { return nullptr; } // @737
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_SetAddress() { return nullptr; } // @738
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_SetFromHttpRequest() { return nullptr; } // @739
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_SetIPv4() { return nullptr; } // @740
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString() { return nullptr; } // @741
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_AreIdentitiesEqual() { return nullptr; } // @742
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_AreIdentitiesSameType() { return nullptr; } // @743
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_Clear() { return nullptr; } // @744
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_GetAffinity() { return nullptr; } // @745
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_GetConnectionName() { return nullptr; } // @746
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_GetGenericBytes() { return nullptr; } // @747
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_GetIPAddr() { return nullptr; } // @748
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_GetLocalHost() { return nullptr; } // @749
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_GetSteamAccount() { return nullptr; } // @750
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_GetSteamID() { return nullptr; } // @751
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_IsInvalid() { return nullptr; } // @752
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString() { return nullptr; } // @753
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_SetAffinity() { return nullptr; } // @754
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_SetConnectionName() { return nullptr; } // @755
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_SetGenericBytes() { return nullptr; } // @756
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_SetIPAddr() { return nullptr; } // @757
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_SetLocalHost() { return nullptr; } // @758
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_SetSteamAccount() { return nullptr; } // @759
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_SetSteamID() { return nullptr; } // @760
void* SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString() { return nullptr; } // @761
void* SteamAPI_ISteamParentalSettings_BIsAppBlocked() { return nullptr; } // @762
void* SteamAPI_ISteamParentalSettings_BIsAppInBlockList() { return nullptr; } // @763
void* SteamAPI_ISteamParentalSettings_BIsFeatureBlocked() { return nullptr; } // @764
void* SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList() { return nullptr; } // @765
void* SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled() { return nullptr; } // @766
void* SteamAPI_ISteamParentalSettings_BIsParentalLockLocked() { return nullptr; } // @767
void* SteamAPI_ISteamParentalSettings_GetBlockedAppCount() { return nullptr; } // @768
void* SteamAPI_ISteamParentalSettings_GetBlockedApps() { return nullptr; } // @769
void* SteamAPI_ISteamParentalSettings_GetTrustMessage() { return nullptr; } // @770
void* SteamAPI_ISteamParentalSettings_RequestChanges() { return nullptr; } // @771
void* SteamAPI_ISteamParentalSettings_SetTrustMessage() { return nullptr; } // @772
void* SteamAPI_ISteamParties_CancelReservation() { return nullptr; } // @773
void* SteamAPI_ISteamParties_ChangeNumOpenSlots() { return nullptr; } // @774
void* SteamAPI_ISteamParties_CreateBeacon() { return nullptr; } // @775
void* SteamAPI_ISteamParties_DestroyBeacon() { return nullptr; } // @776
void* SteamAPI_ISteamParties_GetAvailableBeacon() { return nullptr; } // @777
void* SteamAPI_ISteamParties_GetBeaconByIndex() { return nullptr; } // @778
void* SteamAPI_ISteamParties_GetBeaconDetails() { return nullptr; } // @779
void* SteamAPI_ISteamParties_GetNumActiveBeacons() { return nullptr; } // @780
void* SteamAPI_ISteamParties_JoinParty() { return nullptr; } // @781
void* SteamAPI_ISteamParties_OnReservationCompleted() { return nullptr; } // @782
void* SteamAPI_ISteamParties_SetPartyItem() { return nullptr; } // @783
void* SteamAPI_ISteamRemotePlay_BGetSessionClientResolution() { return nullptr; } // @784
void* SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite() { return nullptr; } // @785
void* SteamAPI_ISteamRemotePlay_GetAssociatedAccount() { return nullptr; } // @786
void* SteamAPI_ISteamRemotePlay_GetAssociatedUsers() { return nullptr; } // @787
void* SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor() { return nullptr; } // @788
void* SteamAPI_ISteamRemotePlay_GetSessionClientName() { return nullptr; } // @789
void* SteamAPI_ISteamRemotePlay_GetSessionClientVersion() { return nullptr; } // @790
void* SteamAPI_ISteamRemotePlay_GetSessionCount() { return nullptr; } // @791
void* SteamAPI_ISteamRemotePlay_GetSessionID() { return nullptr; } // @792
void* SteamAPI_ISteamRemotePlay_GetSessionSteamID() { return nullptr; } // @793
void* SteamAPI_ISteamRemotePlay_InviteUserToRemotePlayTogether() { return nullptr; } // @794
void* SteamAPI_ISteamRemotePlay_StartRemotePlayTogether() { return nullptr; } // @795
void* SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch() { return nullptr; } // @796
void* SteamAPI_ISteamRemoteStorage_CancelFileWriteBatch() { return nullptr; } // @797
void* SteamAPI_ISteamRemoteStorage_CommitFileWriteBatch() { return nullptr; } // @798
void* SteamAPI_ISteamRemoteStorage_DeleteFile() { return nullptr; } // @799
void* SteamAPI_ISteamRemoteStorage_DeleteUserFile() { return nullptr; } // @800
void* SteamAPI_ISteamRemoteStorage_FileExists() { return nullptr; } // @801
void* SteamAPI_ISteamRemoteStorage_FilePersisted() { return nullptr; } // @802
void* SteamAPI_ISteamRemoteStorage_FileRead() { return nullptr; } // @803
void* SteamAPI_ISteamRemoteStorage_FileReadAsync() { return nullptr; } // @804
void* SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete() { return nullptr; } // @805
void* SteamAPI_ISteamRemoteStorage_FileReadComplete() { return nullptr; } // @806
void* SteamAPI_ISteamRemoteStorage_FileSync() { return nullptr; } // @807
void* SteamAPI_ISteamRemoteStorage_FileWrite() { return nullptr; } // @808
void* SteamAPI_ISteamRemoteStorage_FileWriteAsync() { return nullptr; } // @809
void* SteamAPI_ISteamRemoteStorage_FileWriteStreamClose() { return nullptr; } // @810
void* SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen() { return nullptr; } // @811
void* SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk() { return nullptr; } // @812
void* SteamAPI_ISteamRemoteStorage_GetBroadcastSessionInfo() { return nullptr; } // @813
void* SteamAPI_ISteamRemoteStorage_GetFileCount() { return nullptr; } // @814
void* SteamAPI_ISteamRemoteStorage_GetFileExists() { return nullptr; } // @815
void* SteamAPI_ISteamRemoteStorage_GetFileList() { return nullptr; } // @816
void* SteamAPI_ISteamRemoteStorage_GetFileSize() { return nullptr; } // @817
void* SteamAPI_ISteamRemoteStorage_GetFileTimestamp() { return nullptr; } // @818
void* SteamAPI_ISteamRemoteStorage_GetLocalFilePath() { return nullptr; } // @819
void* SteamAPI_ISteamRemoteStorage_GetPersistentContainer() { return nullptr; } // @820
void* SteamAPI_ISteamRemoteStorage_GetSyncPlatforms() { return nullptr; } // @821
void* SteamAPI_ISteamRemoteStorage_IsFileSyncing() { return nullptr; } // @822
void* SteamAPI_ISteamRemoteStorage_SetSyncPlatforms() { return nullptr; } // @823
void* SteamAPI_ISteamRemoteStorage_ShowWord() { return nullptr; } // @824
void* SteamAPI_ISteamScreenshots_AddScreenshotToLibrary() { return nullptr; } // @825
void* SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary() { return nullptr; } // @826
void* SteamAPI_ISteamScreenshots_GetTaggedScreenshotCount() { return nullptr; } // @827
void* SteamAPI_ISteamScreenshots_GetTaggedScreenshots() { return nullptr; } // @828
void* SteamAPI_ISteamScreenshots_HookScreenshots() { return nullptr; } // @829
void* SteamAPI_ISteamScreenshots_IsScreenshotsHooked() { return nullptr; } // @830
void* SteamAPI_ISteamScreenshots_LocationWrite() { return nullptr; } // @831
void* SteamAPI_ISteamScreenshots_ReadScreenshot() { return nullptr; } // @832
void* SteamAPI_ISteamScreenshots_SetLocation() { return nullptr; } // @833
void* SteamAPI_ISteamScreenshots_TagPublishedFile() { return nullptr; } // @834
void* SteamAPI_ISteamScreenshots_TagUser() { return nullptr; } // @835
void* SteamAPI_ISteamScreenshots_WriteScreenshot() { return nullptr; } // @836
void* SteamAPI_ISteamUGC_AddAppDependency() { return nullptr; } // @837
void* SteamAPI_ISteamUGC_AddContentDescriptor() { return nullptr; } // @838
void* SteamAPI_ISteamUGC_AddExcludedTag() { return nullptr; } // @839
void* SteamAPI_ISteamUGC_AddItemPreview() { return nullptr; } // @840
void* SteamAPI_ISteamUGC_AddItemPreviewFile() { return nullptr; } // @841
void* SteamAPI_ISteamUGC_AddItemPreviewVideo() { return nullptr; } // @842
void* SteamAPI_ISteamUGC_AddItemToFavorites() { return nullptr; } // @843
void* SteamAPI_ISteamUGC_AddRequiredTag() { return nullptr; } // @844
void* SteamAPI_ISteamUGC_AddRequiredTagGroup() { return nullptr; } // @845
void* SteamAPI_ISteamUGC_AddDependency() { return nullptr; } // @846
void* SteamAPI_ISteamUGC_CreateItem() { return nullptr; } // @847
void* SteamAPI_ISteamUGC_DeleteItem() { return nullptr; } // @848
void* SteamAPI_ISteamUGC_DownloadItem() { return nullptr; } // @849
void* SteamAPI_ISteamUGC_GetAppDependencies() { return nullptr; } // @850
void* SteamAPI_ISteamUGC_GetAppInstallDir() { return nullptr; } // @851
void* SteamAPI_ISteamUGC_GetContentDescriptorCount() { return nullptr; } // @852
void* SteamAPI_ISteamUGC_GetContentDescriptor() { return nullptr; } // @853
void* SteamAPI_ISteamUGC_GetDownloadProgress() { return nullptr; } // @854
void* SteamAPI_ISteamUGC_GetDownloadState() { return nullptr; } // @855
void* SteamAPI_ISteamUGC_GetFileState() { return nullptr; } // @856
void* SteamAPI_ISteamUGC_GetItemInstallInfo() { return nullptr; } // @857
void* SteamAPI_ISteamUGC_GetItemState() { return nullptr; } // @858
void* SteamAPI_ISteamUGC_GetItemUpdateProgress() { return nullptr; } // @859
void* SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview() { return nullptr; } // @860
void* SteamAPI_ISteamUGC_GetQueryUGCChildren() { return nullptr; } // @861
void* SteamAPI_ISteamUGC_GetQueryUGCDetails() { return nullptr; } // @862
void* SteamAPI_ISteamUGC_GetQueryUGCFileURL() { return nullptr; } // @863
void* SteamAPI_ISteamUGC_GetQueryUGCMetadata() { return nullptr; } // @864
void* SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews() { return nullptr; } // @865
void* SteamAPI_ISteamUGC_GetQueryUGCNumChildren() { return nullptr; } // @866
void* SteamAPI_ISteamUGC_GetQueryUGCNumTags() { return nullptr; } // @867
void* SteamAPI_ISteamUGC_GetQueryUGCPreviewURL() { return nullptr; } // @868
void* SteamAPI_ISteamUGC_GetQueryUGCRow() { return nullptr; } // @869
void* SteamAPI_ISteamUGC_GetQueryUGCSDK() { return nullptr; } // @870
void* SteamAPI_ISteamUGC_GetQueryUGCSearchText() { return nullptr; } // @871
void* SteamAPI_ISteamUGC_GetQueryUGCTag() { return nullptr; } // @872
void* SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName() { return nullptr; } // @873
void* SteamAPI_ISteamUGC_GetQueryUGCTotalRows() { return nullptr; } // @874
void* SteamAPI_ISteamUGC_GetServerRealTime() { return nullptr; } // @875
void* SteamAPI_ISteamUGC_GetItemDownloadInfo() { return nullptr; } // @876
void* SteamAPI_ISteamUGC_GetUserItemVote() { return nullptr; } // @877
void* SteamAPI_ISteamUGC_RemoveAppDependency() { return nullptr; } // @878
void* SteamAPI_ISteamUGC_RemoveContentDescriptor() { return nullptr; } // @879
void* SteamAPI_ISteamUGC_RemoveExcludedTag() { return nullptr; } // @880
void* SteamAPI_ISteamUGC_RemoveItemPreview() { return nullptr; } // @881
void* SteamAPI_ISteamUGC_RemoveItemFromFavorites() { return nullptr; } // @882
void* SteamAPI_ISteamUGC_RemoveRequiredTag() { return nullptr; } // @883
void* SteamAPI_ISteamUGC_RemoveRequiredTagGroup() { return nullptr; } // @884
void* SteamAPI_ISteamUGC_RequestItemDaily() { return nullptr; } // @885
void* SteamAPI_ISteamUGC_SetAssetType() { return nullptr; } // @886
void* SteamAPI_ISteamUGC_SetCategory() { return nullptr; } // @887
void* SteamAPI_ISteamUGC_SetChannel() { return nullptr; } // @888
void* SteamAPI_ISteamUGC_SetCheatComment() { return nullptr; } // @889
void* SteamAPI_ISteamUGC_SetCloudFileNameFilter() { return nullptr; } // @890
void* SteamAPI_ISteamUGC_SetContent() { return nullptr; } // @891
void* SteamAPI_ISteamUGC_SetCustomScreenshot() { return nullptr; } // @892
void* SteamAPI_ISteamUGC_SetDescription() { return nullptr; } // @893
void* SteamAPI_ISteamUGC_SetDeviceID() { return nullptr; } // @894
void* SteamAPI_ISteamUGC_SetForumIdent() { return nullptr; } // @895
void* SteamAPI_ISteamUGC_SetHideFromHans() { return nullptr; } // @896
void* SteamAPI_ISteamUGC_SetItemContent() { return nullptr; } // @897
void* SteamAPI_ISteamUGC_SetItemCustomStatus() { return nullptr; } // @898
void* SteamAPI_ISteamUGC_SetItemDescription() { return nullptr; } // @899
void* SteamAPI_ISteamUGC_SetItemMetadata() { return nullptr; } // @900
void* SteamAPI_ISteamUGC_SetItemPreview() { return nullptr; } // @901
void* SteamAPI_ISteamUGC_SetItemPreviewFile() { return nullptr; } // @902
void* SteamAPI_ISteamUGC_SetItemPreviewVideo() { return nullptr; } // @903
void* SteamAPI_ISteamUGC_SetItemTags() { return nullptr; } // @904
void* SteamAPI_ISteamUGC_SetItemTitle() { return nullptr; } // @905
void* SteamAPI_ISteamUGC_SetItemUpdateLanguage() { return nullptr; } // @906
void* SteamAPI_ISteamUGC_SetItemVisibility() { return nullptr; } // @907
void* SteamAPI_ISteamUGC_SetLanguage() { return nullptr; } // @908
void* SteamAPI_ISteamUGC_SetMetadata() { return nullptr; } // @909
void* SteamAPI_ISteamUGC_SetNumSecondsBeforeStart() { return nullptr; } // @910
void* SteamAPI_ISteamUGC_SetPreviewFile() { return nullptr; } // @911
void* SteamAPI_ISteamUGC_SetPreviewURL() { return nullptr; } // @912
void* SteamAPI_ISteamUGC_SetPrivacy() { return nullptr; } // @913
void* SteamAPI_ISteamUGC_SetRating() { return nullptr; } // @914
void* SteamAPI_ISteamUGC_SetRemoteStorage() { return nullptr; } // @915
void* SteamAPI_ISteamUGC_SetReturnAdditionalPreviews() { return nullptr; } // @916
void* SteamAPI_ISteamUGC_SetReturnChildren() { return nullptr; } // @917
void* SteamAPI_ISteamUGC_SetReturnDays() { return nullptr; } // @918
void* SteamAPI_ISteamUGC_SetReturnDescription() { return nullptr; } // @919
void* SteamAPI_ISteamUGC_SetReturnLongDescription() { return nullptr; } // @920
void* SteamAPI_ISteamUGC_SetReturnMetadata() { return nullptr; } // @921
void* SteamAPI_ISteamUGC_SetReturnOnlyIDs() { return nullptr; } // @922
void* SteamAPI_ISteamUGC_SetReturnPlaytimeStats() { return nullptr; } // @924
void* SteamAPI_ISteamUGC_SetReturnPrimaryCategory() { return nullptr; } // @925
void* SteamAPI_ISteamUGC_SetReturnProperties() { return nullptr; } // @926
void* SteamAPI_ISteamUGC_SetReturnRateOnly() { return nullptr; } // @927
void* SteamAPI_ISteamUGC_SetReturnShortDescription() { return nullptr; } // @928
void* SteamAPI_ISteamUGC_SetReturnTags() { return nullptr; } // @929
void* SteamAPI_ISteamUGC_SetReturnTotalOnly() { return nullptr; } // @930
void* SteamAPI_ISteamUGC_SetSearchText() { return nullptr; } // @931
void* SteamAPI_ISteamUGC_SetShouldCache() { return nullptr; } // @932
void* SteamAPI_ISteamUGC_SetShowPreviews() { return nullptr; } // @933
void* SteamAPI_ISteamUGC_SetSort() { return nullptr; } // @934
void* SteamAPI_ISteamUGC_SetPreview() { return nullptr; } // @935
void* SteamAPI_ISteamUGC_SetTags() { return nullptr; } // @936
void* SteamAPI_ISteamUGC_SetTitle() { return nullptr; } // @937
void* SteamAPI_ISteamUGC_SetVisibility() { return nullptr; } // @938
void* SteamAPI_ISteamUGC_SetWebsite() { return nullptr; } // @939
void* SteamAPI_ISteamUGC_StartItemUpdate() { return nullptr; } // @940
void* SteamAPI_ISteamUGC_StartPlaytimeTracking() { return nullptr; } // @941
void* SteamAPI_ISteamUGC_StopPlaytimeTracking() { return nullptr; } // @943
void* SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems() { return nullptr; } // @944
void* SteamAPI_ISteamUGC_SubscribeItem() { return nullptr; } // @945
void* SteamAPI_ISteamUGC_SuspendPlaytimeDownloads() { return nullptr; } // @946
void* SteamAPI_ISteamUGC_UnsubscribeItem() { return nullptr; } // @947
void* SteamAPI_ISteamUGC_UpdateItem() { return nullptr; } // @948
void* SteamAPI_ISteamUGC_UpdateItemPreview() { return nullptr; } // @949
void* SteamAPI_ISteamUser_AdvertiseGame() { return nullptr; } // @950
void* SteamAPI_ISteamUser_BIsBehindNAT() { return nullptr; } // @951
bool SteamAPI_ISteamUser_BIsPhoneIdentifying() { return s_SteamUser.BIsPhoneIdentifying(); } // @952
bool SteamAPI_ISteamUser_BIsPhoneRequiringVerification() { return s_SteamUser.BIsPhoneRequireVerification(); } // @953
bool SteamAPI_ISteamUser_BIsPhoneVerified() { return s_SteamUser.BIsPhoneVerified(); } // @954
bool SteamAPI_ISteamUser_BIsTwoFactorEnabled() { return s_SteamUser.BIsTwoFactorEnabled(); } // @955
bool SteamAPI_ISteamUser_BLoggedOn() { return s_SteamUser.BLoggedOn(); } // @956
void* SteamAPI_ISteamUser_BSetDurationControlOnlineState() { return nullptr; } // @957
int SteamAPI_ISteamUser_BeginAuthSession(const void* t, int n, uint64 id) { return s_SteamUser.BeginAuthSession(t, n, CSteamID(id)); } // @958
void SteamAPI_ISteamUser_CancelAuthTicket(unsigned int t) { s_SteamUser.CancelAuthTicket(t); } // @959
void SteamAPI_ISteamUser_EndAuthSession(uint64 id) { s_SteamUser.EndAuthSession(CSteamID(id)); } // @960
int SteamAPI_ISteamUser_GetAppID() { return 10; } // @961
int SteamAPI_ISteamUser_GetAuthSessionTicket(void* t, int m, unsigned int* s) { return s_SteamUser.GetAuthSessionTicket(t, m, s); } // @962
int SteamAPI_ISteamUser_GetGameBadgeLevel(int s) { return s_SteamUser.GetGameBadgeLevel(s); } // @963
int SteamAPI_ISteamUser_GetHSteamUser() { return s_SteamUser.GetHSteamUser(); } // @964
int SteamAPI_ISteamUser_GetMarketEligibility() { return s_SteamUser.GetMarketEligibility(); } // @965
void* SteamAPI_ISteamUser_GetPlayerSteamLevel() { return nullptr; } // @966
uint64 SteamAPI_ISteamUser_GetSteamID() { return s_SteamUser.GetSteamID(); } // @967
bool SteamAPI_ISteamUser_GetUserDataFolder(char* buf, int len) { return s_SteamUser.GetUserDataFolder(buf, len); } // @968
int SteamAPI_ISteamUser_GetVoice(void* buf, int len, bool b) { return s_SteamUser.GetVoice((char*)buf, len, b); } // @969
int SteamAPI_ISteamUser_GetVoiceOptimalSampleRate() { return s_SteamUser.GetVoiceOptimalSampleRate(); } // @970
int SteamAPI_ISteamUser_InitiateGameConnection(void* p, int n, uint64 id, int ip, short port, bool b) { return s_SteamUser.InitiateGameConnection(p, n, CSteamID(id), ip, port, b); } // @971
void* SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED() { return nullptr; } // @972
void* SteamAPI_ISteamUser_LoggedOn() { return nullptr; } // @973
void* SteamAPI_ISteamUser_RequestEncryptedAppTicket() { return nullptr; } // @974
void SteamAPI_ISteamUser_StartVoiceRecording() { s_SteamUser.StartVoiceRecording(); } // @975
void SteamAPI_ISteamUser_StopVoiceRecording() { s_SteamUser.StopVoiceRecording(); } // @976
void SteamAPI_ISteamUser_TerminateGameConnection(int ip, short port) { s_SteamUser.TerminateGameConnection(ip, port); } // @977
void SteamAPI_ISteamUser_TerminateGameConnection2(int ip, short port) { s_SteamUser.TerminateGameConnection2(ip, port); } // @978
void SteamAPI_ISteamUser_TrackAppUsageEvent(int id, int evt, const char* info) { s_SteamUser.TrackAppUsageEvent(CGameID(id), evt, info); } // @979
void* SteamAPI_ISteamUser_Voice() { return nullptr; } // @980
void* SteamAPI_ISteamUserStats_AttachLeaderboardUGC() { return nullptr; } // @981
void* SteamAPI_ISteamUserStats_ClearAchievement() { return nullptr; } // @982
void* SteamAPI_ISteamUserStats_DownloadLeaderboardEntries() { return nullptr; } // @983
void* SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers() { return nullptr; } // @984
void* SteamAPI_ISteamUserStats_FindLeaderboard() { return nullptr; } // @985
void* SteamAPI_ISteamUserStats_FindOrCreateLeaderboard() { return nullptr; } // @986
void* SteamAPI_ISteamUserStats_GetAchievement() { return nullptr; } // @987
void* SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime() { return nullptr; } // @988
void* SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute() { return nullptr; } // @989
void* SteamAPI_ISteamUserStats_GetAchievementIcon() { return nullptr; } // @990
void* SteamAPI_ISteamUserStats_GetAchievementProgress() { return nullptr; } // @991
void* SteamAPI_ISteamUserStats_GetAchievementProgressLimits() { return nullptr; } // @992
void* SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32() { return nullptr; } // @993
void* SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt64() { return nullptr; } // @994
void* SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry() { return nullptr; } // @995
void* SteamAPI_ISteamUserStats_GetGlobalStat() { return nullptr; } // @996
void* SteamAPI_ISteamUserStats_GetGlobalStatDouble() { return nullptr; } // @997
void* SteamAPI_ISteamUserStats_GetGlobalStatHistory() { return nullptr; } // @998
void* SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble() { return nullptr; } // @999
void* SteamAPI_ISteamUserStats_GetGlobalStatInt64() { return nullptr; } // @1000
void* SteamAPI_ISteamUserStats_GetLeaderboardDisplayType() { return nullptr; } // @1001
void* SteamAPI_ISteamUserStats_GetLeaderboardEntryCount() { return nullptr; } // @1002
void* SteamAPI_ISteamUserStats_GetLeaderboardName() { return nullptr; } // @1003
void* SteamAPI_ISteamUserStats_GetLeaderboardSortMethod() { return nullptr; } // @1004
void* SteamAPI_ISteamUserStats_GetMostAchievedAchievement() { return nullptr; } // @1005
void* SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo() { return nullptr; } // @1006
void* SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo() { return nullptr; } // @1007
void* SteamAPI_ISteamUserStats_GetNumAchievedAchievements() { return nullptr; } // @1008
void* SteamAPI_ISteamUserStats_GetUserAchievement() { return nullptr; } // @1009
void* SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime() { return nullptr; } // @1010
void* SteamAPI_ISteamUserStats_GetUserStat() { return nullptr; } // @1011
void* SteamAPI_ISteamUserStats_GetUserStatDouble() { return nullptr; } // @1012
void* SteamAPI_ISteamUserStats_GetUserStatFloat() { return nullptr; } // @1013
void* SteamAPI_ISteamUserStats_GetUserStatInt32() { return nullptr; } // @1014
void* SteamAPI_ISteamUserStats_IndicateAchievementProgress() { return nullptr; } // @1015
void* SteamAPI_ISteamUserStats_RequestCurrentStats() { return nullptr; } // @1016
void* SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages() { return nullptr; } // @1017
void* SteamAPI_ISteamUserStats_RequestGlobalStats() { return nullptr; } // @1018
void* SteamAPI_ISteamUserStats_RequestUserStats() { return nullptr; } // @1019
void* SteamAPI_ISteamUserStats_ResetAllStats() { return nullptr; } // @1020
void* SteamAPI_ISteamUserStats_SetAchievement() { return nullptr; } // @1021
void* SteamAPI_ISteamUserStats_SetStat() { return nullptr; } // @1022
void* SteamAPI_ISteamUserStats_SetStatDouble() { return nullptr; } // @1023
void* SteamAPI_ISteamUserStats_SetStatFloat() { return nullptr; } // @1024
void* SteamAPI_ISteamUserStats_SetStatInt32() { return nullptr; } // @1025
void* SteamAPI_ISteamUserStats_SetUserAchievement() { return nullptr; } // @1026
void* SteamAPI_ISteamUserStats_SetUserStatDouble() { return nullptr; } // @1027
void* SteamAPI_ISteamUserStats_SetUserStatFloat() { return nullptr; } // @1028
void* SteamAPI_ISteamUserStats_SetUserStatInt32() { return nullptr; } // @1029
void* SteamAPI_ISteamUserStats_StoreStats() { return nullptr; } // @1030
void* SteamAPI_ISteamUserStats_UpdateAvgRateStat() { return nullptr; } // @1031
void* SteamAPI_ISteamUtils_ActivateGameOverlay() { return nullptr; } // @1032
void* SteamAPI_ISteamUtils_ActivateGameOverlayToStore() { return nullptr; } // @1033
void* SteamAPI_ISteamUtils_ActivateGameOverlayToUser() { return nullptr; } // @1034
void* SteamAPI_ISteamUtils_ActivateGameOverlayToWebPage() { return nullptr; } // @1035
bool SteamAPI_ISteamUtils_BOverlayNeedsPresent() { return s_SteamUtils.BOverlayNeedsPresent(); } // @1036
void* SteamAPI_ISteamUtils_BSetBPlaytestPreference() { return nullptr; } // @1037
void* SteamAPI_ISteamUtils_CheckFileSignature() { return nullptr; } // @1038
void* SteamAPI_ISteamUtils_ClearGameOverlay() { return nullptr; } // @1039
void* SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput() { return nullptr; } // @1040
void* SteamAPI_ISteamUtils_FilterText() { return nullptr; } // @1041
void* SteamAPI_ISteamUtils_GetAPICallFailureReason() { return nullptr; } // @1042
void* SteamAPI_ISteamUtils_GetAPICallResult() { return nullptr; } // @1043
int SteamAPI_ISteamUtils_GetAppID() { return s_SteamUtils.GetAppID(); } // @1044
void* SteamAPI_ISteamUtils_GetBatteryPower() { return nullptr; } // @1045
void* SteamAPI_ISteamUtils_GetBPlaytestState() { return nullptr; } // @1046
int SteamAPI_ISteamUtils_GetBuildID() { return s_SteamUtils.GetBuildID(); } // @1047
int SteamAPI_ISteamUtils_GetConnectedUniverse() { return s_SteamUtils.GetConnectedUniverse(); } // @1048
int SteamAPI_ISteamUtils_GetCurrentBatteryPower() { return s_SteamUtils.GetCurrentBatteryPower(); } // @1049
void* SteamAPI_ISteamUtils_GetEnteredGamepadTextInput() { return nullptr; } // @1050
void* SteamAPI_ISteamUtils_GetEnteredScreenKeyboardLayout() { return nullptr; } // @1051
void* SteamAPI_ISteamUtils_GetEnteredScreenKeyboardLanguage() { return nullptr; } // @1052
int SteamAPI_ISteamUtils_GetSecondsSinceAppActive() { return s_SteamUtils.GetSecondsSinceAppActive(); } // @1053
int SteamAPI_ISteamUtils_GetSecondsSinceComputerActive() { return s_SteamUtils.GetSecondsSinceComputerActive(); } // @1054
int SteamAPI_ISteamUtils_GetServerRealTime() { return s_SteamUtils.GetServerRealTime(); } // @1055
const char* SteamAPI_ISteamUtils_GetSteamInstallPath() { return s_SteamUtils.GetSteamInstallPath(); } // @1056
const char* SteamAPI_ISteamUtils_GetSteamUILanguage() { return s_SteamUtils.GetSteamUILanguage(); } // @1057
void* SteamAPI_ISteamUtils_GetUpdateSchedule() { return nullptr; } // @1058
void* SteamAPI_ISteamUtils_GetWindowClientSize() { return nullptr; } // @1059
void* SteamAPI_ISteamUtils_GetWindowRect() { return nullptr; } // @1060
void* SteamAPI_ISteamUtils_InitFilterText() { return nullptr; } // @1061
void* SteamAPI_ISteamUtils_IsAPICallCompleted() { return nullptr; } // @1062
bool SteamAPI_ISteamUtils_IsOverlayEnabled() { return s_SteamUtils.IsOverlayEnabled(); } // @1063
bool SteamAPI_ISteamUtils_IsSteamInBigPictureMode() { return s_SteamUtils.IsSteamInBigPictureMode(); } // @1064
void* SteamAPI_ISteamUtils_IsSteamRunningInVR() { return nullptr; } // @1065
void* SteamAPI_ISteamUtils_IsSteamTurkey() { return nullptr; } // @1066
bool SteamAPI_ISteamUtils_IsSteamChina() { return s_SteamUtils.IsSteamChina(); } // @1067
bool SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled() { return s_SteamUtils.IsVRHeadsetStreamingEnabled(); } // @1068
void* SteamAPI_ISteamUtils_IsVRDashboardVisible() { return nullptr; } // @1069
void* SteamAPI_SetWarningMessageHook() { return nullptr; } // @1070
void* SteamAPI_ISteamUtils_LoadSettings() { return nullptr; } // @1071
void* SteamAPI_ISteamUtils_SetGameLauncherMode() { return nullptr; } // @1072
void* SteamAPI_ISteamUtils_SetOverlayNotificationPosition() { return nullptr; } // @1073
void SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled(bool b) { s_SteamUtils.SetVRHeadsetStreamingEnabled(b); } // @1074
void* SteamAPI_ISteamUtils_SetWindowsFontPath() { return nullptr; } // @1075
void* SteamAPI_ISteamUtils_ShowFloatingGamepadTextInput() { return nullptr; } // @1076
void* SteamAPI_ISteamUtils_ShowGamepadTextInput() { return nullptr; } // @1077
void SteamAPI_ISteamUtils_StartVRDashboard() { s_SteamUtils.StartVRDashboard(); } // @1078
void* SteamAPI_ISteamUtils_StoreSettings() { return nullptr; } // @1079
void* SteamAPI_ISteamVideo_GetBroadcastSessionInfo() { return nullptr; } // @1080
void* SteamAPI_ISteamVideo_GetOPFSettings() { return nullptr; } // @1081
void* SteamAPI_ISteamVideo_GetOPFStringForApp() { return nullptr; } // @1082
void* SteamAPI_ISteamVideo_GetVideoURL() { return nullptr; } // @1083
void* SteamAPI_ISteamVideo_IsBroadcasting() { return nullptr; } // @1084
void* SteamAPI_ISteamVideo_IsSteamInBigPictureMode() { return nullptr; } // @1085
int SteamAPI_ISteamMusic_GetPlaybackStatus() { return s_SteamMusic.GetPlaybackStatus(); } // @1086
float SteamAPI_ISteamMusic_GetVolume() { return s_SteamMusic.GetVolume(); } // @1087
bool SteamAPI_ISteamMusic_IsEnabled() { return s_SteamMusic.BIsEnabled(); } // @1088
bool SteamAPI_ISteamMusic_IsPlaying() { return s_SteamMusic.BIsPlaying(); } // @1089
void SteamAPI_ISteamMusic_Pause() { s_SteamMusic.Pause(); } // @1090
void SteamAPI_ISteamMusic_Play() { s_SteamMusic.Play(); } // @1091
void SteamAPI_ISteamMusic_PlayNext() { s_SteamMusic.PlayNext(); } // @1092
void SteamAPI_ISteamMusic_PlayPrevious() { s_SteamMusic.PlayPrevious(); } // @1093
void SteamAPI_ISteamMusic_SetVolume(float v) { s_SteamMusic.SetVolume(v); } // @1094
void* SteamAPI_MarkServer() { return nullptr; } // @1095
void* SteamAPI_ReleaseLockThread() { return nullptr; } // @1096
void* SteamAPI_SetBreakpadAppID() { return nullptr; } // @1098
void* SteamAPI_SetLocalIPBinding() { return nullptr; } // @1099
void* SteamAPI_UseBreakpadCrashHandler() { return nullptr; } // @1100
void* SteamAPI_WriteMiniDump() { return nullptr; } // @1101
void* SteamAPI_WriteMiniDumpUsingExceptionInfo() { return nullptr; } // @1102
void* SteamAPI_RestartAppIfNecessary() { return nullptr; } // @1104
void* SteamAPI_Init2() { return nullptr; } // @1106
void* SteamAPI_RegisterInterfaceFunc() { return nullptr; } // @1107
void* SteamAPI_QueryInterfaceFunc() { return nullptr; } // @1108
void* SteamAPI_GetSteamClientVersion() { return nullptr; } // @1109
void* SteamAPI_GetSteamUtilsVersion() { return nullptr; } // @1110
void* SteamAPI_GetSteamUserVersion() { return nullptr; } // @1111
void* SteamAPI_GetSteamFriendsVersion() { return nullptr; } // @1112
void* SteamAPI_GetSteamAppsVersion() { return nullptr; } // @1113
void* SteamAPI_GetSteamNetworkingVersion() { return nullptr; } // @1114
void* SteamAPI_GetSteamMatchmakingVersion() { return nullptr; } // @1115
void* SteamAPI_GetSteamUserStatsVersion() { return nullptr; } // @1116
void* SteamAPI_GetSteamControllerVersion() { return nullptr; } // @1117
void* SteamAPI_GetSteamHTMLSurfaceVersion() { return nullptr; } // @1118
void* SteamAPI_GetSteamInputVersion() { return nullptr; } // @1119
void* SteamAPI_GetSteamInventoryVersion() { return nullptr; } // @1120
void* SteamAPI_GetSteamRemoteStorageVersion() { return nullptr; } // @1121
void* SteamAPI_GetSteamScreenshotsVersion() { return nullptr; } // @1122
void* SteamAPI_GetSteamVideoVersion() { return nullptr; } // @1123
void* SteamAPI_GetSteamMusicVersion() { return nullptr; } // @1124
void* SteamAPI_GetSteamUnifiedMessagesVersion() { return nullptr; } // @1125
void* SteamAPI_GetSteamMusicRemoteVersion() { return nullptr; } // @1126
void* SteamAPI_GetSteamHTTPVersion() { return nullptr; } // @1127
void* SteamAPI_GetSteamUGCVersion() { return nullptr; } // @1128
void* SteamAPI_GetSteamNetworkingSocketsVersion() { return nullptr; } // @1129
void* SteamAPI_GetSteamNetworkingMessagesVersion() { return nullptr; } // @1130
void* SteamAPI_GetSteamNetworkingUtilsVersion() { return nullptr; } // @1131
void* SteamAPI_GetSteamParentalSettingsVersion() { return nullptr; } // @1132
void* SteamAPI_GetSteamPartiesVersion() { return nullptr; } // @1133
void* SteamAPI_GetSteamRemotePlayVersion() { return nullptr; } // @1134
void* SteamAPI_GetSteam2Path() { return nullptr; } // @1140
void* SteamAPI_GetSteam2DesktopPath() { return nullptr; } // @1141
void* SteamAPI_GetSteam3Path() { return nullptr; } // @1142
void* SteamGameServer_GetIPCCallCount() { return nullptr; } // @1150
void* SteamInternal_SetStructuredDefine() { return nullptr; } // @1161
void* SteamAPI_Unsafe_SetAlternativeCacheDirectory() { return nullptr; } // @1163
void* SteamAPI_SetAPILazyLoader() { return nullptr; } // @1164
void* SteamAPI_SetNotification() { return nullptr; } // @1165
void* SteamAPI_WriteMiniDumpSetComment() { return nullptr; } // @1166



void* SteamAPI_ISteamClient_GetIPCCallCount() { return nullptr; } // @45

void* SteamAPI_ISteamClient_ReleaseUser() { return nullptr; } // @73

void* SteamAPI_ISteamClient_SetWarningMessageHook() { return nullptr; } // @75

void* SteamAPI_ISteamController_DeactivateActionSetLayer() { return nullptr; } // @78

void* SteamAPI_ISteamController_DeactivateAllActionSetLayers() { return nullptr; } // @79

void* SteamAPI_ISteamController_GetActionOriginFromXboxOrigin() { return nullptr; } // @80

void* SteamAPI_ISteamController_GetDigitalActionHandle() { return nullptr; } // @91

void* SteamAPI_ISteamController_GetGlyphForXboxOrigin() { return nullptr; } // @95

void* SteamAPI_ISteamController_TriggerRepeatedHapticPulse() { return nullptr; } // @108

void* SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog() { return nullptr; } // @111

void* SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString() { return nullptr; } // @112

void* SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog() { return nullptr; } // @113

void* SteamAPI_ISteamFriends_CloseClanChatWindowInSteam() { return nullptr; } // @118

void* SteamAPI_ISteamFriends_GetClanChatMemberCount() { return nullptr; } // @124

void* SteamAPI_ISteamFriends_GetClanChatMessage() { return nullptr; } // @125

void* SteamAPI_ISteamFriends_GetClanOfficerByIndex() { return nullptr; } // @128

void* SteamAPI_ISteamFriends_GetFriendCountFromSource() { return nullptr; } // @139

void* SteamAPI_ISteamFriends_GetFriendMessage() { return nullptr; } // @142

void* SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages() { return nullptr; } // @158

void* SteamAPI_ISteamFriends_GetPlayerNickname() { return nullptr; } // @161

void* SteamAPI_ISteamFriends_GetUserRestrictions() { return nullptr; } // @163

void* SteamAPI_ISteamFriends_IsClanChatAdmin() { return nullptr; } // @166

void* SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam() { return nullptr; } // @167

void* SteamAPI_ISteamFriends_IsClanOfficialGameGroup() { return nullptr; } // @168

void* SteamAPI_ISteamFriends_IsClanPublic() { return nullptr; } // @169

void* SteamAPI_ISteamFriends_JoinClanChatRoom() { return nullptr; } // @172

void* SteamAPI_ISteamFriends_LeaveClanChatRoom() { return nullptr; } // @173

void* SteamAPI_ISteamFriends_OpenClanChatWindowInSteam() { return nullptr; } // @174

void* SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser() { return nullptr; } // @175

void* SteamAPI_ISteamFriends_ReplyToFriendMessage() { return nullptr; } // @176

void* SteamAPI_ISteamFriends_RequestUserInformation() { return nullptr; } // @179

void* SteamAPI_ISteamFriends_SendClanChatMessage() { return nullptr; } // @180

void* SteamAPI_ISteamFriends_SetInGameVoiceSpeaking() { return nullptr; } // @181

void* SteamAPI_ISteamFriends_SetPlayedWith() { return nullptr; } // @184

void* SteamAPI_ISteamGameSearch_AcceptGame() { return nullptr; } // @186

void* SteamAPI_ISteamGameSearch_AddGameSearchParams() { return nullptr; } // @187

void* SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame() { return nullptr; } // @188

void* SteamAPI_ISteamGameSearch_DeclineGame() { return nullptr; } // @189

void* SteamAPI_ISteamGameSearch_EndGame() { return nullptr; } // @190

void* SteamAPI_ISteamGameSearch_EndGameSearch() { return nullptr; } // @191

void* SteamAPI_ISteamGameSearch_HostConfirmGameStart() { return nullptr; } // @192

void* SteamAPI_ISteamGameSearch_RequestPlayersForGame() { return nullptr; } // @193

void* SteamAPI_ISteamGameSearch_RetrieveConnectionDetails() { return nullptr; } // @194

void* SteamAPI_ISteamGameSearch_SearchForGameSolo() { return nullptr; } // @195

void* SteamAPI_ISteamGameSearch_SearchForGameWithLobby() { return nullptr; } // @196

void* SteamAPI_ISteamGameSearch_SetConnectionDetails() { return nullptr; } // @197

void* SteamAPI_ISteamGameSearch_SetGameHostParams() { return nullptr; } // @198

void* SteamAPI_ISteamGameSearch_SubmitPlayerResult() { return nullptr; } // @199

void* SteamAPI_ISteamGameServerStats_ClearUserAchievement() { return nullptr; } // @200

void* SteamAPI_ISteamGameServerStats_GetUserAchievement() { return nullptr; } // @201

void* SteamAPI_ISteamGameServerStats_GetUserStatFloat() { return nullptr; } // @202

void* SteamAPI_ISteamGameServerStats_GetUserStatInt32() { return nullptr; } // @203

void* SteamAPI_ISteamGameServerStats_RequestUserStats() { return nullptr; } // @204

void* SteamAPI_ISteamGameServerStats_SetUserAchievement() { return nullptr; } // @205

void* SteamAPI_ISteamGameServerStats_SetUserStatFloat() { return nullptr; } // @206

void* SteamAPI_ISteamGameServerStats_SetUserStatInt32() { return nullptr; } // @207

void* SteamAPI_ISteamGameServerStats_StoreUserStats() { return nullptr; } // @208

void* SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat() { return nullptr; } // @209

void* SteamAPI_ISteamGameServer_AssociateWithClan() { return nullptr; } // @210

void* SteamAPI_ISteamGameServer_BLoggedOn() { return nullptr; } // @211

void* SteamAPI_ISteamGameServer_BSecure() { return nullptr; } // @212

void* SteamAPI_ISteamGameServer_BUpdateUserData() { return nullptr; } // @213

void* SteamAPI_ISteamGameServer_BeginAuthSession() { return nullptr; } // @214

void* SteamAPI_ISteamGameServer_CancelAuthTicket() { return nullptr; } // @215

void* SteamAPI_ISteamGameServer_ClearAllKeyValues() { return nullptr; } // @216

void* SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility() { return nullptr; } // @217

void* SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection() { return nullptr; } // @218

void* SteamAPI_ISteamGameServer_EndAuthSession() { return nullptr; } // @219

void* SteamAPI_ISteamGameServer_GetAuthSessionTicket() { return nullptr; } // @220

void* SteamAPI_ISteamGameServer_GetGameplayStats() { return nullptr; } // @221

void* SteamAPI_ISteamGameServer_GetNextOutgoingPacket() { return nullptr; } // @222

void* SteamAPI_ISteamGameServer_GetPublicIP() { return nullptr; } // @223

void* SteamAPI_ISteamGameServer_GetServerReputation() { return nullptr; } // @224

void* SteamAPI_ISteamGameServer_GetSteamID() { return nullptr; } // @225

void* SteamAPI_ISteamGameServer_HandleIncomingPacket() { return nullptr; } // @226

void* SteamAPI_ISteamGameServer_LogOff() { return nullptr; } // @227

void* SteamAPI_ISteamGameServer_LogOn() { return nullptr; } // @228

void* SteamAPI_ISteamGameServer_LogOnAnonymous() { return nullptr; } // @229

void* SteamAPI_ISteamGameServer_RequestUserGroupStatus() { return nullptr; } // @230

void* SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED() { return nullptr; } // @231

void* SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED() { return nullptr; } // @232

void* SteamAPI_ISteamGameServer_SetAdvertiseServerActive() { return nullptr; } // @233

void* SteamAPI_ISteamGameServer_SetBotPlayerCount() { return nullptr; } // @234

void* SteamAPI_ISteamGameServer_SetDedicatedServer() { return nullptr; } // @235

void* SteamAPI_ISteamGameServer_SetGameData() { return nullptr; } // @236

void* SteamAPI_ISteamGameServer_SetGameDescription() { return nullptr; } // @237

void* SteamAPI_ISteamGameServer_SetGameTags() { return nullptr; } // @238

void* SteamAPI_ISteamGameServer_SetKeyValue() { return nullptr; } // @239

void* SteamAPI_ISteamGameServer_SetMapName() { return nullptr; } // @240

void* SteamAPI_ISteamGameServer_SetMaxPlayerCount() { return nullptr; } // @241

void* SteamAPI_ISteamGameServer_SetModDir() { return nullptr; } // @242

void* SteamAPI_ISteamGameServer_SetPasswordProtected() { return nullptr; } // @243

void* SteamAPI_ISteamGameServer_SetProduct() { return nullptr; } // @244

void* SteamAPI_ISteamGameServer_SetRegion() { return nullptr; } // @245

void* SteamAPI_ISteamGameServer_SetServerName() { return nullptr; } // @246

void* SteamAPI_ISteamGameServer_SetSpectatorPort() { return nullptr; } // @247

void* SteamAPI_ISteamGameServer_SetSpectatorServerName() { return nullptr; } // @248

void* SteamAPI_ISteamGameServer_UserHasLicenseForApp() { return nullptr; } // @249

void* SteamAPI_ISteamGameServer_WasRestartRequested() { return nullptr; } // @250

void* SteamAPI_ISteamHTMLSurface_AddHeader() { return nullptr; } // @251

void* SteamAPI_ISteamHTMLSurface_CopyToClipboard() { return nullptr; } // @253

void* SteamAPI_ISteamHTMLSurface_CreateBrowser() { return nullptr; } // @254

void* SteamAPI_ISteamHTMLSurface_ExecuteJavascript() { return nullptr; } // @255

void* SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse() { return nullptr; } // @256

void* SteamAPI_ISteamHTMLSurface_OpenDeveloperTools() { return nullptr; } // @272

void* SteamAPI_ISteamHTMLSurface_Shutdown() { return nullptr; } // @284

void* SteamAPI_ISteamHTMLSurface_StopFind() { return nullptr; } // @285

void* SteamAPI_ISteamHTMLSurface_StopLoad() { return nullptr; } // @286

void* SteamAPI_ISteamHTTP_CreateCookieContainer() { return nullptr; } // @288

void* SteamAPI_ISteamHTTP_ReleaseCookieContainer() { return nullptr; } // @299

void* SteamAPI_ISteamHTTP_SetCookie() { return nullptr; } // @303

void* SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS() { return nullptr; } // @304

void* SteamAPI_ISteamInput_BNewDataAvailable() { return nullptr; } // @315

void* SteamAPI_ISteamInput_BWaitForData() { return nullptr; } // @316

void* SteamAPI_ISteamInput_DeactivateActionSetLayer() { return nullptr; } // @317

void* SteamAPI_ISteamInput_DeactivateAllActionSetLayers() { return nullptr; } // @318

void* SteamAPI_ISteamInput_EnableActionEventCallbacks() { return nullptr; } // @319

void* SteamAPI_ISteamInput_EnableDeviceCallbacks() { return nullptr; } // @320

void* SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin() { return nullptr; } // @321

void* SteamAPI_ISteamInput_GetDeviceBindingRevision() { return nullptr; } // @330

void* SteamAPI_ISteamInput_GetDigitalActionHandle() { return nullptr; } // @332

void* SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy() { return nullptr; } // @335

void* SteamAPI_ISteamInput_GetGlyphForXboxOrigin() { return nullptr; } // @336

void* SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin() { return nullptr; } // @337

void* SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin() { return nullptr; } // @338

void* SteamAPI_ISteamInput_Legacy_TriggerHapticPulse() { return nullptr; } // @348

void* SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse() { return nullptr; } // @349

void* SteamAPI_ISteamInput_SetInputActionManifestFilePath() { return nullptr; } // @351

void* SteamAPI_ISteamInput_TranslateActionOrigin() { return nullptr; } // @356

void* SteamAPI_ISteamInventory_ConsumeItem() { return nullptr; } // @363

void* SteamAPI_ISteamInventory_DeserializeResult() { return nullptr; } // @364

void* SteamAPI_ISteamInventory_DestroyResult() { return nullptr; } // @365

void* SteamAPI_ISteamInventory_GetResultTimestamp() { return nullptr; } // @379

void* SteamAPI_ISteamInventory_GrantPromoItems() { return nullptr; } // @380

void* SteamAPI_ISteamInventory_InspectItem() { return nullptr; } // @381

void* SteamAPI_ISteamInventory_RemoveProperty() { return nullptr; } // @383

void* SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs() { return nullptr; } // @384

void* SteamAPI_ISteamInventory_SendItemDropHeartbeat() { return nullptr; } // @386

void* SteamAPI_ISteamInventory_SetPropertyBool() { return nullptr; } // @388

void* SteamAPI_ISteamInventory_SetPropertyFloat() { return nullptr; } // @389

void* SteamAPI_ISteamInventory_SetPropertyInt64() { return nullptr; } // @390

void* SteamAPI_ISteamInventory_SetPropertyString() { return nullptr; } // @391

void* SteamAPI_ISteamInventory_TradeItems() { return nullptr; } // @395

void* SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond() { return nullptr; } // @398

void* SteamAPI_ISteamMatchmakingPingResponse_ServerResponded() { return nullptr; } // @399

void* SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList() { return nullptr; } // @400

void* SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond() { return nullptr; } // @401

void* SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete() { return nullptr; } // @402

void* SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond() { return nullptr; } // @403

void* SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete() { return nullptr; } // @404

void* SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded() { return nullptr; } // @405

void* SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete() { return nullptr; } // @406

void* SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond() { return nullptr; } // @407

void* SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded() { return nullptr; } // @408

void* SteamAPI_ISteamMatchmakingServers_GetServerCount() { return nullptr; } // @411

void* SteamAPI_ISteamMatchmakingServers_IsRefreshing() { return nullptr; } // @413

void* SteamAPI_ISteamMatchmakingServers_PlayerDetails() { return nullptr; } // @415

void* SteamAPI_ISteamMatchmakingServers_ReleaseRequest() { return nullptr; } // @418

void* SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList() { return nullptr; } // @419

void* SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList() { return nullptr; } // @420

void* SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList() { return nullptr; } // @421

void* SteamAPI_ISteamMatchmakingServers_RequestInternetServerList() { return nullptr; } // @422

void* SteamAPI_ISteamMatchmakingServers_RequestLANServerList() { return nullptr; } // @423

void* SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList() { return nullptr; } // @424

void* SteamAPI_ISteamMatchmakingServers_ServerRules() { return nullptr; } // @425

void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter() { return nullptr; } // @427

void* SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter() { return nullptr; } // @432

void* SteamAPI_ISteamMatchmaking_DeleteLobbyData() { return nullptr; } // @435

void* SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit() { return nullptr; } // @446

void* SteamAPI_ISteamMatchmaking_GetLobbyOwner() { return nullptr; } // @447

void* SteamAPI_ISteamMatchmaking_GetNumLobbyMembers() { return nullptr; } // @448

void* SteamAPI_ISteamMatchmaking_JoinLobby() { return nullptr; } // @450

void* SteamAPI_ISteamMatchmaking_RequestLobbyData() { return nullptr; } // @453

void* SteamAPI_ISteamMatchmaking_SetLinkedLobby() { return nullptr; } // @456

void* SteamAPI_ISteamMatchmaking_SetLobbyJoinable() { return nullptr; } // @459

void* SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit() { return nullptr; } // @461

void* SteamAPI_ISteamMatchmaking_SetLobbyType() { return nullptr; } // @463

void* SteamAPI_ISteamMusicRemote_BActivationSuccess() { return nullptr; } // @464

void* SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote() { return nullptr; } // @465

void* SteamAPI_ISteamMusicRemote_CurrentEntryDidChange() { return nullptr; } // @466

void* SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable() { return nullptr; } // @467

void* SteamAPI_ISteamMusicRemote_CurrentEntryWillChange() { return nullptr; } // @468

void* SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote() { return nullptr; } // @469

void* SteamAPI_ISteamMusicRemote_EnableLooped() { return nullptr; } // @470

void* SteamAPI_ISteamMusicRemote_EnablePlayNext() { return nullptr; } // @471

void* SteamAPI_ISteamMusicRemote_EnablePlayPrevious() { return nullptr; } // @472

void* SteamAPI_ISteamMusicRemote_EnablePlaylists() { return nullptr; } // @473

void* SteamAPI_ISteamMusicRemote_EnableQueue() { return nullptr; } // @474

void* SteamAPI_ISteamMusicRemote_EnableShuffled() { return nullptr; } // @475

void* SteamAPI_ISteamMusicRemote_PlaylistDidChange() { return nullptr; } // @476

void* SteamAPI_ISteamMusicRemote_PlaylistWillChange() { return nullptr; } // @477

void* SteamAPI_ISteamMusicRemote_QueueDidChange() { return nullptr; } // @478

void* SteamAPI_ISteamMusicRemote_QueueWillChange() { return nullptr; } // @479

void* SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote() { return nullptr; } // @480

void* SteamAPI_ISteamMusicRemote_ResetPlaylistEntries() { return nullptr; } // @481

void* SteamAPI_ISteamMusicRemote_ResetQueueEntries() { return nullptr; } // @482

void* SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry() { return nullptr; } // @483

void* SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry() { return nullptr; } // @484

void* SteamAPI_ISteamMusicRemote_SetDisplayName() { return nullptr; } // @485

void* SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64() { return nullptr; } // @486

void* SteamAPI_ISteamMusicRemote_SetPlaylistEntry() { return nullptr; } // @487

void* SteamAPI_ISteamMusicRemote_SetQueueEntry() { return nullptr; } // @488

void* SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt() { return nullptr; } // @489

void* SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds() { return nullptr; } // @490

void* SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText() { return nullptr; } // @491

void* SteamAPI_ISteamMusicRemote_UpdateLooped() { return nullptr; } // @492

void* SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus() { return nullptr; } // @493

void* SteamAPI_ISteamMusicRemote_UpdateShuffled() { return nullptr; } // @494

void* SteamAPI_ISteamMusicRemote_UpdateVolume() { return nullptr; } // @495

bool SteamAPI_ISteamMusic_BIsEnabled() { return s_SteamMusic.BIsEnabled(); } // @496

bool SteamAPI_ISteamMusic_BIsPlaying() { return s_SteamMusic.BIsPlaying(); } // @497

void* SteamAPI_ISteamNetworkingFakeUDPPort_DestroyFakeUDPPort() { return nullptr; } // @505

void* SteamAPI_ISteamNetworkingFakeUDPPort_ReceiveMessages() { return nullptr; } // @506

void* SteamAPI_ISteamNetworkingFakeUDPPort_ScheduleCleanup() { return nullptr; } // @507

void* SteamAPI_ISteamNetworkingFakeUDPPort_SendMessageToFakeIP() { return nullptr; } // @508

void* SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser() { return nullptr; } // @509

void* SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser() { return nullptr; } // @510

void* SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser() { return nullptr; } // @511

void* SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo() { return nullptr; } // @512

void* SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer() { return nullptr; } // @523

void* SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort() { return nullptr; } // @524

void* SteamAPI_ISteamNetworkingSockets_GetConnectionUserData() { return nullptr; } // @539

void* SteamAPI_ISteamNetworkingSockets_RunCallbacks() { return nullptr; } // @555

void* SteamAPI_ISteamNetworkingSockets_SendMessages() { return nullptr; } // @557

void* SteamAPI_ISteamNetworkingSockets_SetCertificate() { return nullptr; } // @558

void* SteamAPI_ISteamNetworkingSockets_SetConnectionName() { return nullptr; } // @559

void* SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup() { return nullptr; } // @560

void* SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp() { return nullptr; } // @572

void* SteamAPI_ISteamNetworkingUtils_GetPOPCount() { return nullptr; } // @573

void* SteamAPI_ISteamNetworkingUtils_GetPOPList() { return nullptr; } // @574

void* SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter() { return nullptr; } // @575

void* SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP() { return nullptr; } // @576

void* SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues() { return nullptr; } // @580

void* SteamAPI_ISteamNetworkingUtils_SetConfigValue() { return nullptr; } // @582

void* SteamAPI_ISteamNetworkingUtils_SetConfigValueStruct() { return nullptr; } // @583

void* SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueFloat() { return nullptr; } // @584

void* SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueInt32() { return nullptr; } // @585

void* SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueString() { return nullptr; } // @586

void* SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction() { return nullptr; } // @587

void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_FakeIPResult() { return nullptr; } // @588

void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionFailed() { return nullptr; } // @589

void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionRequest() { return nullptr; } // @590

void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetAuthenticationStatusChanged() { return nullptr; } // @591

void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetConnectionStatusChanged() { return nullptr; } // @592

void* SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamRelayNetworkStatusChanged() { return nullptr; } // @593

void* SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValuePtr() { return nullptr; } // @596

void* SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser() { return nullptr; } // @603

void* SteamAPI_ISteamNetworking_CreateConnectionSocket() { return nullptr; } // @607

void* SteamAPI_ISteamNetworking_CreateListenSocket() { return nullptr; } // @608

void* SteamAPI_ISteamNetworking_GetListenSocketInfo() { return nullptr; } // @612

void* SteamAPI_ISteamNetworking_GetSocketConnectionType() { return nullptr; } // @615

void* SteamAPI_ISteamNetworking_GetSocketInfo() { return nullptr; } // @616

void* SteamAPI_ISteamNetworking_IsP2PPacketAvailable() { return nullptr; } // @619

void* SteamAPI_ISteamNetworking_ReadP2PPacket() { return nullptr; } // @620

void* SteamAPI_ISteamNetworking_RetrieveData() { return nullptr; } // @621

void* SteamAPI_ISteamNetworking_RetrieveDataFromSocket() { return nullptr; } // @622

void* SteamAPI_ISteamParties_GetAvailableBeaconLocations() { return nullptr; } // @635

void* SteamAPI_ISteamParties_GetBeaconLocationData() { return nullptr; } // @638

void* SteamAPI_ISteamParties_GetNumAvailableBeaconLocations() { return nullptr; } // @640

void* SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate() { return nullptr; } // @651

void* SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest() { return nullptr; } // @652

void* SteamAPI_ISteamRemoteStorage_DeletePublishedFile() { return nullptr; } // @653

void* SteamAPI_ISteamRemoteStorage_EndFileWriteBatch() { return nullptr; } // @654

void* SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction() { return nullptr; } // @655

void* SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles() { return nullptr; } // @656

void* SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles() { return nullptr; } // @657

void* SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles() { return nullptr; } // @658

void* SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles() { return nullptr; } // @659

void* SteamAPI_ISteamRemoteStorage_FileDelete() { return nullptr; } // @660

void* SteamAPI_ISteamRemoteStorage_FileForget() { return nullptr; } // @662

void* SteamAPI_ISteamRemoteStorage_FileShare() { return nullptr; } // @667

void* SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel() { return nullptr; } // @670

void* SteamAPI_ISteamRemoteStorage_GetCachedUGCCount() { return nullptr; } // @674

void* SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle() { return nullptr; } // @675

void* SteamAPI_ISteamRemoteStorage_GetFileNameAndSize() { return nullptr; } // @677

void* SteamAPI_ISteamRemoteStorage_GetLocalFileChange() { return nullptr; } // @680

void* SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount() { return nullptr; } // @681

void* SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails() { return nullptr; } // @682

void* SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails() { return nullptr; } // @683

void* SteamAPI_ISteamRemoteStorage_GetQuota() { return nullptr; } // @684

void* SteamAPI_ISteamRemoteStorage_GetUGCDetails() { return nullptr; } // @686

void* SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress() { return nullptr; } // @687

void* SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails() { return nullptr; } // @688

void* SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount() { return nullptr; } // @689

void* SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp() { return nullptr; } // @690

void* SteamAPI_ISteamRemoteStorage_PublishVideo() { return nullptr; } // @691

void* SteamAPI_ISteamRemoteStorage_PublishWorkshopFile() { return nullptr; } // @692

void* SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp() { return nullptr; } // @693

void* SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction() { return nullptr; } // @695

void* SteamAPI_ISteamRemoteStorage_SubscribePublishedFile() { return nullptr; } // @696

void* SteamAPI_ISteamRemoteStorage_UGCDownload() { return nullptr; } // @697

void* SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation() { return nullptr; } // @698

void* SteamAPI_ISteamRemoteStorage_UGCRead() { return nullptr; } // @699

void* SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile() { return nullptr; } // @700

void* SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription() { return nullptr; } // @701

void* SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile() { return nullptr; } // @702

void* SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile() { return nullptr; } // @703

void* SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription() { return nullptr; } // @704

void* SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags() { return nullptr; } // @705

void* SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle() { return nullptr; } // @706

void* SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility() { return nullptr; } // @707

void* SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote() { return nullptr; } // @708

void* SteamAPI_ISteamScreenshots_TriggerScreenshot() { return nullptr; } // @716

void* SteamAPI_ISteamUGC_AddItemKeyValueTag() { return nullptr; } // @721

void* SteamAPI_ISteamUGC_AddRequiredKeyValueTag() { return nullptr; } // @725

void* SteamAPI_ISteamUGC_BInitWorkshopForGameServer() { return nullptr; } // @728

void* SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor() { return nullptr; } // @730

void* SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage() { return nullptr; } // @731

void* SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest() { return nullptr; } // @732

void* SteamAPI_ISteamUGC_CreateQueryUserUGCRequest() { return nullptr; } // @733

void* SteamAPI_ISteamUGC_GetNumSubscribedItems() { return nullptr; } // @741

void* SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag() { return nullptr; } // @742

void* SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag() { return nullptr; } // @745

void* SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags() { return nullptr; } // @748

void* SteamAPI_ISteamUGC_GetQueryUGCResult() { return nullptr; } // @751

void* SteamAPI_ISteamUGC_GetQueryUGCStatistic() { return nullptr; } // @752

void* SteamAPI_ISteamUGC_GetSubscribedItems() { return nullptr; } // @755

void* SteamAPI_ISteamUGC_GetWorkshopEULAStatus() { return nullptr; } // @757

void* SteamAPI_ISteamUGC_ReleaseQueryUGCRequest() { return nullptr; } // @758

void* SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags() { return nullptr; } // @759

void* SteamAPI_ISteamUGC_RemoveDependency() { return nullptr; } // @761

void* SteamAPI_ISteamUGC_RemoveItemKeyValueTags() { return nullptr; } // @763

void* SteamAPI_ISteamUGC_RequestUGCDetails() { return nullptr; } // @765

void* SteamAPI_ISteamUGC_SendQueryUGCRequest() { return nullptr; } // @766

void* SteamAPI_ISteamUGC_SetAllowCachedResponse() { return nullptr; } // @767

void* SteamAPI_ISteamUGC_SetAllowLegacyUpload() { return nullptr; } // @768

void* SteamAPI_ISteamUGC_SetMatchAnyTag() { return nullptr; } // @779

void* SteamAPI_ISteamUGC_SetRankedByTrendDays() { return nullptr; } // @780

void* SteamAPI_ISteamUGC_SetReturnKeyValueTags() { return nullptr; } // @783

void* SteamAPI_ISteamUGC_SetTimeCreatedDateRange() { return nullptr; } // @790

void* SteamAPI_ISteamUGC_SetTimeUpdatedDateRange() { return nullptr; } // @791

void* SteamAPI_ISteamUGC_SetUserItemVote() { return nullptr; } // @792

void* SteamAPI_ISteamUGC_ShowWorkshopEULA() { return nullptr; } // @793

void* SteamAPI_ISteamUGC_SubmitItemUpdate() { return nullptr; } // @798

void* SteamAPI_ISteamUGC_SuspendDownloads() { return nullptr; } // @800

void* SteamAPI_ISteamUGC_UpdateItemPreviewFile() { return nullptr; } // @802

void* SteamAPI_ISteamUGC_UpdateItemPreviewVideo() { return nullptr; } // @803

void* SteamAPI_ISteamUserStats_GetAchievementAchievedPercent() { return nullptr; } // @811

void* SteamAPI_ISteamUserStats_GetAchievementName() { return nullptr; } // @815

void* SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat() { return nullptr; } // @816

void* SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64() { return nullptr; } // @821

void* SteamAPI_ISteamUserStats_GetNumAchievements() { return nullptr; } // @829

void* SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers() { return nullptr; } // @830

void* SteamAPI_ISteamUserStats_GetStatFloat() { return nullptr; } // @831

void* SteamAPI_ISteamUserStats_GetStatInt32() { return nullptr; } // @832

void* SteamAPI_ISteamUserStats_UploadLeaderboardScore() { return nullptr; } // @848

void* SteamAPI_ISteamUser_DecompressVoice() { return nullptr; } // @859

void* SteamAPI_ISteamUser_GetAvailableVoice() { return nullptr; } // @862

void* SteamAPI_ISteamUser_GetDurationControl() { return nullptr; } // @863

void* SteamAPI_ISteamUser_GetEncryptedAppTicket() { return nullptr; } // @864

void* SteamAPI_ISteamUser_RequestStoreAuthURL() { return nullptr; } // @875

void* SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED() { return nullptr; } // @878

void* SteamAPI_ISteamUser_UserHasLicenseForApp() { return nullptr; } // @880

void* SteamAPI_ISteamUtils_GetEnteredGamepadTextLength() { return nullptr; } // @891

void* SteamAPI_ISteamUtils_GetIPCCallCount() { return nullptr; } // @892

void* SteamAPI_ISteamUtils_GetIPCountry() { return nullptr; } // @893

void* SteamAPI_ISteamUtils_GetIPv6ConnectivityState() { return nullptr; } // @894

void* SteamAPI_ISteamUtils_GetImageRGBA() { return nullptr; } // @895

void* SteamAPI_ISteamUtils_GetImageSize() { return nullptr; } // @896

void* SteamAPI_ISteamUtils_IsSteamChinaLauncher() { return nullptr; } // @904

void* SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck() { return nullptr; } // @907

void* SteamAPI_ISteamUtils_SetOverlayNotificationInset() { return nullptr; } // @910

void* SteamAPI_ISteamUtils_SetWarningMessageHook() { return nullptr; } // @913



void* SteamAPI_InitAnonymousUser() { return nullptr; } // @922

void* SteamAPI_InitSafe() { return nullptr; } // @923

void* SteamAPI_IsSteamRunning() { diag::log("call: SteamAPI_IsSteamRunning"); return (void*)1; } // @924

void* SteamAPI_ManualDispatch_FreeLastCallback() { return nullptr; } // @925

void* SteamAPI_ManualDispatch_GetAPICallResult() { return nullptr; } // @926

void* SteamAPI_ManualDispatch_GetNextCallback() { return nullptr; } // @927

void* SteamAPI_ManualDispatch_Init() { diag::log("call: SteamAPI_ManualDispatch_Init"); return nullptr; } // @928

void* SteamAPI_ManualDispatch_RunFrame() { return nullptr; } // @929

void* SteamAPI_MatchMakingKeyValuePair_t_Construct() { return nullptr; } // @930

void* SteamAPI_RegisterCallResult(void* result, void* apicall) { diag::log("call: SteamAPI_RegisterCallResult result=%p call=%p", result, apicall); auto orig = (void*(*)(void*, void*))SteamProxy::Instance().GetOriginal("SteamAPI_RegisterCallResult"); if (orig) { orig(result, apicall); diag::log("  -> forwarded to original"); } return nullptr; } // @931

void* SteamAPI_RegisterCallback(void* callback, int idata) { diag::log("call: SteamAPI_RegisterCallback cb=%p size=%d", callback, idata); auto orig = (void*(*)(void*, int))SteamProxy::Instance().GetOriginal("SteamAPI_RegisterCallback"); if (orig) { orig(callback, idata); diag::log("  -> forwarded to original"); } else { diag::log("  !! no original SteamAPI_RegisterCallback"); } return nullptr; } // @932

void* SteamAPI_ReleaseCurrentThreadMemory() { return nullptr; } // @933



void* SteamAPI_SetMiniDumpComment() { return nullptr; } // @937

void* SteamAPI_SetTryCatchCallbacks() { return nullptr; } // @938



void* SteamAPI_SteamAppList_v001() { return nullptr; } // @940

void* SteamAPI_SteamApps_v008() { return nullptr; } // @941

void* SteamAPI_SteamController_v008() { return nullptr; } // @942

void* SteamAPI_SteamDatagramHostedAddress_Clear() { return nullptr; } // @943

void* SteamAPI_SteamDatagramHostedAddress_GetPopID() { return nullptr; } // @944

void* SteamAPI_SteamDatagramHostedAddress_SetDevAddress() { return nullptr; } // @945

void* SteamAPI_SteamFriends_v017() { return nullptr; } // @946

void* SteamAPI_SteamGameSearch_v001() { return nullptr; } // @947

void* SteamAPI_SteamGameServerHTTP_v003() { return nullptr; } // @948

void* SteamAPI_SteamGameServerInventory_v003() { return nullptr; } // @949

void* SteamAPI_SteamGameServerNetworkingMessages_SteamAPI_v002() { return nullptr; } // @950

void* SteamAPI_SteamGameServerNetworkingSockets_SteamAPI_v012() { return nullptr; } // @951

void* SteamAPI_SteamGameServerNetworking_v006() { return nullptr; } // @952

void* SteamAPI_SteamGameServerStats_v001() { return nullptr; } // @953

void* SteamAPI_SteamGameServerUGC_v016() { return nullptr; } // @954

void* SteamAPI_SteamGameServerUtils_v010() { return nullptr; } // @955

void* SteamAPI_SteamGameServer_v014() { return nullptr; } // @956

void* SteamAPI_SteamHTMLSurface_v005() { return nullptr; } // @957

void* SteamAPI_SteamHTTP_v003() { return nullptr; } // @958

void* SteamAPI_SteamIPAddress_t_IsSet() { return nullptr; } // @959

void* SteamAPI_SteamInput_v006() { return nullptr; } // @960

void* SteamAPI_SteamInventory_v003() { return nullptr; } // @961

void* SteamAPI_SteamMatchmakingServers_v002() { return nullptr; } // @962

void* SteamAPI_SteamMatchmaking_v009() { return nullptr; } // @963

void* SteamAPI_SteamMusicRemote_v001() { return nullptr; } // @964

void* SteamAPI_SteamMusic_v001() { return nullptr; } // @965

void* SteamAPI_SteamNetworkingConfigValue_t_SetFloat() { return nullptr; } // @966

void* SteamAPI_SteamNetworkingConfigValue_t_SetInt32() { return nullptr; } // @967

void* SteamAPI_SteamNetworkingConfigValue_t_SetInt64() { return nullptr; } // @968

void* SteamAPI_SteamNetworkingConfigValue_t_SetPtr() { return nullptr; } // @969

void* SteamAPI_SteamNetworkingConfigValue_t_SetString() { return nullptr; } // @970

void* SteamAPI_SteamNetworkingIPAddr_Clear() { return nullptr; } // @971

void* SteamAPI_SteamNetworkingIPAddr_GetFakeIPType() { return nullptr; } // @972

void* SteamAPI_SteamNetworkingIPAddr_GetIPv4() { return nullptr; } // @973

void* SteamAPI_SteamNetworkingIPAddr_IsEqualTo() { return nullptr; } // @974

void* SteamAPI_SteamNetworkingIPAddr_IsFakeIP() { return nullptr; } // @975

void* SteamAPI_SteamNetworkingIPAddr_IsIPv4() { return nullptr; } // @976

void* SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros() { return nullptr; } // @977

void* SteamAPI_SteamNetworkingIPAddr_IsLocalHost() { return nullptr; } // @978

void* SteamAPI_SteamNetworkingIPAddr_ParseString() { return nullptr; } // @979

void* SteamAPI_SteamNetworkingIPAddr_SetIPv4() { return nullptr; } // @980

void* SteamAPI_SteamNetworkingIPAddr_SetIPv6() { return nullptr; } // @981

void* SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost() { return nullptr; } // @982

void* SteamAPI_SteamNetworkingIPAddr_ToString() { return nullptr; } // @983

void* SteamAPI_SteamNetworkingIdentity_Clear() { return nullptr; } // @984

void* SteamAPI_SteamNetworkingIdentity_GetFakeIPType() { return nullptr; } // @985

void* SteamAPI_SteamNetworkingIdentity_GetGenericBytes() { return nullptr; } // @986

void* SteamAPI_SteamNetworkingIdentity_GetGenericString() { return nullptr; } // @987

void* SteamAPI_SteamNetworkingIdentity_GetIPAddr() { return nullptr; } // @988

void* SteamAPI_SteamNetworkingIdentity_GetIPv4() { return nullptr; } // @989

void* SteamAPI_SteamNetworkingIdentity_GetPSNID() { return nullptr; } // @990

void* SteamAPI_SteamNetworkingIdentity_GetStadiaID() { return nullptr; } // @991

void* SteamAPI_SteamNetworkingIdentity_GetSteamID() { return nullptr; } // @992

void* SteamAPI_SteamNetworkingIdentity_GetSteamID64() { return nullptr; } // @993

void* SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID() { return nullptr; } // @994

void* SteamAPI_SteamNetworkingIdentity_IsEqualTo() { return nullptr; } // @995

void* SteamAPI_SteamNetworkingIdentity_IsFakeIP() { return nullptr; } // @996

void* SteamAPI_SteamNetworkingIdentity_IsInvalid() { return nullptr; } // @997

void* SteamAPI_SteamNetworkingIdentity_IsLocalHost() { return nullptr; } // @998

void* SteamAPI_SteamNetworkingIdentity_ParseString() { return nullptr; } // @999

void* SteamAPI_SteamNetworkingIdentity_SetGenericBytes() { return nullptr; } // @1000

void* SteamAPI_SteamNetworkingIdentity_SetGenericString() { return nullptr; } // @1001

void* SteamAPI_SteamNetworkingIdentity_SetIPAddr() { return nullptr; } // @1002

void* SteamAPI_SteamNetworkingIdentity_SetIPv4Addr() { return nullptr; } // @1003

void* SteamAPI_SteamNetworkingIdentity_SetLocalHost() { return nullptr; } // @1004

void* SteamAPI_SteamNetworkingIdentity_SetPSNID() { return nullptr; } // @1005

void* SteamAPI_SteamNetworkingIdentity_SetStadiaID() { return nullptr; } // @1006

void* SteamAPI_SteamNetworkingIdentity_SetSteamID() { return nullptr; } // @1007

void* SteamAPI_SteamNetworkingIdentity_SetSteamID64() { return nullptr; } // @1008

void* SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID() { return nullptr; } // @1009

void* SteamAPI_SteamNetworkingIdentity_ToString() { return nullptr; } // @1010

void* SteamAPI_SteamNetworkingMessage_t_Release() { return nullptr; } // @1011

void* SteamAPI_SteamNetworkingMessages_SteamAPI_v002() { return nullptr; } // @1012

void* SteamAPI_SteamNetworkingSockets_SteamAPI_v012() { return nullptr; } // @1013

void* SteamAPI_SteamNetworkingUtils_SteamAPI_v004() { return nullptr; } // @1014

void* SteamAPI_SteamNetworking_v006() { return nullptr; } // @1015

void* SteamAPI_SteamParentalSettings_v001() { return nullptr; } // @1016

void* SteamAPI_SteamParties_v002() { return nullptr; } // @1017

void* SteamAPI_SteamRemotePlay_v001() { return nullptr; } // @1018

void* SteamAPI_SteamRemoteStorage_v016() { return nullptr; } // @1019

void* SteamAPI_SteamScreenshots_v003() { return nullptr; } // @1020

void* SteamAPI_SteamUGC_v016() { return nullptr; } // @1021

void* SteamAPI_SteamUserStats_v012() { return nullptr; } // @1022

void* SteamAPI_SteamUser_v021() { return nullptr; } // @1023

void* SteamAPI_SteamUtils_v010() { return nullptr; } // @1024

void* SteamAPI_SteamVideo_v002() { return nullptr; } // @1025

void* SteamAPI_UnregisterCallResult() { return nullptr; } // @1026

void* SteamAPI_UnregisterCallback() { return nullptr; } // @1027

void* SteamAPI_gameserveritem_t_Construct() { return nullptr; } // @1030

void* SteamAPI_gameserveritem_t_GetName() { return nullptr; } // @1031

void* SteamAPI_gameserveritem_t_SetName() { return nullptr; } // @1032

void* SteamAPI_servernetadr_t_Assign() { return nullptr; } // @1033

void* SteamAPI_servernetadr_t_Construct() { return nullptr; } // @1034

void* SteamAPI_servernetadr_t_GetConnectionAddressString() { return nullptr; } // @1035

void* SteamAPI_servernetadr_t_GetConnectionPort() { return nullptr; } // @1036

void* SteamAPI_servernetadr_t_GetIP() { return nullptr; } // @1037

void* SteamAPI_servernetadr_t_GetQueryAddressString() { return nullptr; } // @1038

void* SteamAPI_servernetadr_t_GetQueryPort() { return nullptr; } // @1039

void* SteamAPI_servernetadr_t_Init() { return nullptr; } // @1040

void* SteamAPI_servernetadr_t_IsLessThan() { return nullptr; } // @1041

void* SteamAPI_servernetadr_t_SetConnectionPort() { return nullptr; } // @1042

void* SteamAPI_servernetadr_t_SetIP() { return nullptr; } // @1043

void* SteamAPI_servernetadr_t_SetQueryPort() { return nullptr; } // @1044
void* SteamInternal_CreateInterface(const char* name) { diag::log("call: SteamInternal_CreateInterface name=%s", name?name:"?"); return nullptr; } // @1055

// Транзит с неизвестной сигнатурой: параметры не трогаем, просто прыгаем в оригинал.
// cdecl: стек очищает вызывающий, поэтому чистый jmp сохраняет все аргументы.
__declspec(naked) void SteamInternal_GameServer_Init() {
    __asm {
        call    GSInitThunk
        jmp     eax
    GSInitThunk:
        push    ecx
        push    edx
        call    GetGSInitTarget
        pop     edx
        pop     ecx
        ret
    }
} // @1058

} // extern "C"

