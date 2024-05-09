#ifndef _ISTEAMMUSIC_
#define _ISTEAMMUSIC_

#include "..\..\FreeAPI.Typedef.h"

typedef enum _AudioPlayback_Status_ {

	AudioPlayback_Undefined, 
	AudioPlayback_Playing,
	AudioPlayback_Paused,
	AudioPlayback_Idle

} AudioPlayback_Status, *pAudioPlayback_Status;

// -----------------------------------------------------------------------------
// Purpose: Functions to control music playback in the steam client
// -----------------------------------------------------------------------------
typedef class _ISteamMusic_ {
public:

	virtual Bool BIsEnabled() = 0;
	virtual Bool BIsPlaying() = 0;
	
	virtual AudioPlayback_Status GetPlaybackStatus() = 0; 

	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void PlayPrevious() = 0;
	virtual void PlayNext() = 0;

	/* Volume is Between 0.0 and 1.0 */
	virtual void SetVolume(Float sndVolume) = 0;
	virtual Float GetVolume() = 0;
	
} ISteamMusic, *IpSteamMusic;

#define STEAMMUSIC_INTERFACE_VERSION "STEAMMUSIC_INTERFACE_VERSION001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_PlaybackStatusHasChanged_t ((Int32)(k_iSteamMusicCallbacks + 1))
typedef struct _PlaybackStatusHasChanged_t_ {

	Int32 Unused;

} PlaybackStatusHasChanged_t, *pPlaybackStatusHasChanged_t;

#define k_iCallbback_VolumeHasChanged_t ((Int32)(k_iSteamMusicCallbacks + 2))
typedef struct _VolumeHasChanged_t_ {

	Float sndVolume;

} VolumeHasChanged_t, *pVolumeHasChanged_t;

#pragma pack(pop)

#endif // #define _ISTEAMMUSIC_
