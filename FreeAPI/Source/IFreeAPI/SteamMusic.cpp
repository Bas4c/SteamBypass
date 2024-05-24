// -----------------------------------------------------------------------------
#include "SteamMusic.h"
// -----------------------------------------------------------------------------

_SteamMusic_::_SteamMusic_() {
	
	this->sndVolume = 0.5F;
	this->audioPlaybackStatus = AudioPlayback_Idle;

}

Bool _SteamMusic_::BIsEnabled() {
	DEBUGBREAK("ISteamMusic::BIsEnabled");

	return True;

}

Bool _SteamMusic_::BIsPlaying() {
	DEBUGBREAK("ISteamMusic::BIsPlaying");

	if (this->audioPlaybackStatus == AudioPlayback_Playing) {
		return True;
	}

	return False;

}

AudioPlayback_Status _SteamMusic_::GetPlaybackStatus() {
	DEBUGBREAK("ISteamMusic::GetPlaybackStatus");

	return this->audioPlaybackStatus;

}

void _SteamMusic_::Play() {
	DEBUGBREAK("ISteamMusic::Play");

	this->audioPlaybackStatus = AudioPlayback_Playing;

}

void _SteamMusic_::Pause() {
	DEBUGBREAK("ISteamMusic::Pause");

	this->audioPlaybackStatus = AudioPlayback_Paused;

}

void _SteamMusic_::PlayPrevious() {
	DEBUGBREAK("ISteamMusic::PlayPrevious");

	this->audioPlaybackStatus = AudioPlayback_Playing;

}

void _SteamMusic_::PlayNext() {
	DEBUGBREAK("ISteamMusic::PlayNext");

	this->audioPlaybackStatus = AudioPlayback_Playing;

}

void _SteamMusic_::SetVolume(Float sndVolume) {
	DEBUGBREAK("ISteamMusic::SetVolume");

	this->sndVolume = (sndVolume < 0.0F) ? 0.0F :
		(sndVolume > 1.0F) ? 1.0F : sndVolume;

}

Float _SteamMusic_::GetVolume() {
	DEBUGBREAK("ISteamMusic::GetVolume");

	return this->sndVolume;

}
