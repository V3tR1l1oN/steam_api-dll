#pragma once
#include "../../include/steam/steam_api_goldsrc.h"

class CSteamMusic : public ISteamMusic {
public:
    CSteamMusic();
    virtual ~CSteamMusic() = default;

    bool BIsEnabled() override;
    bool BIsPlaying() override;
    int GetPlaybackStatus() override;
    float GetVolume() override;
    void Pause() override;
    void Play() override;
    void PlayNext() override;
    void PlayPrevious() override;
    void SetVolume(float flVolume) override;

private:
    bool m_bEnabled;
    bool m_bPlaying;
    int m_nStatus;
    float m_flVolume;
};