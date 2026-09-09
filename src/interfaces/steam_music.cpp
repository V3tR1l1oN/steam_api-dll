#include "steam_music.h"

CSteamMusic::CSteamMusic() : m_bEnabled(true), m_bPlaying(false), m_nStatus(0), m_flVolume(1.0f) {}

bool CSteamMusic::BIsEnabled() { return m_bEnabled; }
bool CSteamMusic::BIsPlaying() { return m_bPlaying; }
int CSteamMusic::GetPlaybackStatus() { return m_nStatus; }
float CSteamMusic::GetVolume() { return m_flVolume; }
void CSteamMusic::Pause() { m_bPlaying = false; }
void CSteamMusic::Play() { m_bPlaying = true; }
void CSteamMusic::PlayNext() {}
void CSteamMusic::PlayPrevious() {}
void CSteamMusic::SetVolume(float flVolume) { m_flVolume = flVolume; }