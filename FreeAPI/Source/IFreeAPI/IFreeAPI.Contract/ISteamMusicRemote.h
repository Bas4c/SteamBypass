#ifndef _ISTEAMMUSICREMOTE_
#define _ISTEAMMUSICREMOTE_

#include "..\..\FreeAPI.Typedef.h"
#include "ISteamMusic.h"

#define k_SteamMusicNameMaxLength ((Int32)(255))
#define k_SteamMusicPNGMaxLength ((Int32)(65535))

typedef class _ISteamMusicRemote_ {
public: 

	virtual Bool RegisterSteamMusicRemote(const pStrA pchName) = 0;
	virtual Bool DeregisterSteamMusicRemote() = 0;
	virtual Bool BIsCurrentMusicRemote() = 0;
	virtual Bool BActivationSuccess(Bool bValue) = 0;

	virtual Bool SetDisplayName(const pStrA pchDisplayName) = 0;
	virtual Bool SetPNGIcon_64x64(pVoid pvData, Uint32 cbDataSize) = 0;

	virtual Bool EnablePlayPrevious(Bool bValue) = 0;
	virtual Bool EnablePlayNext(Bool bValue) = 0;
	virtual Bool EnableShuffled(Bool bValue) = 0;
	virtual Bool EnableLooped(Bool bValue) = 0;
	virtual Bool EnableQueue(Bool bValue) = 0;
	virtual Bool EnablePlaylists(Bool bValue) = 0;

	virtual Bool UpdatePlaybackStatus(AudioPlayback_Status audioPlayback_Status) = 0;
	virtual Bool UpdateShuffled(Bool bValue) = 0;
	virtual Bool UpdateLooped(Bool bValue) = 0;
	/* Volume is Between 0.0 and 1.0 */
	virtual Bool UpdateVolume(Float sndVolume) = 0;

	virtual Bool CurrentEntryWillChange() = 0;
	virtual Bool CurrentEntryIsAvailable(Bool bAvailable) = 0;
	virtual Bool UpdateCurrentEntryText(const pStrA pchText) = 0;
	virtual Bool UpdateCurrentEntryElapsedSeconds(Int32 nValue) = 0;
	virtual Bool UpdateCurrentEntryCoverArt(pVoid pvData, Uint32 cbDataSize) = 0;
	virtual Bool CurrentEntryDidChange() = 0;

	virtual Bool QueueWillChange() = 0;
	virtual Bool ResetQueueEntries() = 0;
	virtual Bool SetQueueEntry(Int32 nId, Int32 nPosition, const pStrA pchEntryText) = 0;
	virtual Bool SetCurrentQueueEntry(Int32 nId) = 0;
	virtual Bool QueueDidChange() = 0;

	virtual Bool PlaylistWillChange() = 0;
	virtual Bool ResetPlaylistEntries() = 0;
	virtual Bool SetPlaylistEntry(Int32 nId, Int32 nPosition, const pStrA pchEntryText) = 0;
	virtual Bool SetCurrentPlaylistEntry(Int32 nId) = 0;
	virtual Bool PlaylistDidChange() = 0;

} ISteamMusicRemote, *IpSteamMusicRemote;

#define STEAMMUSICREMOTE_INTERFACE_VERSION "STEAMMUSICREMOTE_INTERFACE_VERSION001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_MusicPlayerRemoteWillActivate_t ((Int32)(k_iSteamMusicRemoteCallbacks + 1))
typedef struct _MusicPlayerRemoteWillActivate_t_ {

	Int32 Unused;

} MusicPlayerRemoteWillActivate_t, *pMusicPlayerRemoteWillActivate_t;

#define k_iCallbback_MusicPlayerRemoteWillDeactivate_t ((Int32)k_iSteamMusicRemoteCallbacks + 2))
typedef struct _MusicPlayerRemoteWillDeactivate_t_ {
	
	Int32 Unused;

} MusicPlayerRemoteWillDeactivate_t, *pMusicPlayerRemoteWillDeactivate_t;

#define k_iCallbback_MusicPlayerRemoteToFront_t ((Int32)k_iSteamMusicRemoteCallbacks + 3))
typedef struct _MusicPlayerRemoteToFront_t_ {

	Int32 Unused;

} MusicPlayerRemoteToFront_t, *pMusicPlayerRemoteToFront_t;

#define k_iCallbback_MusicPlayerWillQuit_t ((Int32)k_iSteamMusicRemoteCallbacks + 4))
typedef struct _MusicPlayerWillQuit_t_ {

	Int32 Unused;

} MusicPlayerWillQuit_t, *pMusicPlayerWillQuit_t;

#define k_iCallbback_MusicPlayerWantsPlay_t ((Int32)k_iSteamMusicRemoteCallbacks + 5))
typedef struct _MusicPlayerWantsPlay_t_ {

	Int32 Unused;

} MusicPlayerWantsPlay_t, *pMusicPlayerWantsPlay_t;

#define k_iCallbback_MusicPlayerWantsPause_t ((Int32)k_iSteamMusicRemoteCallbacks + 6))
typedef struct _MusicPlayerWantsPause_t_ {

	Int32 Unused;

} MusicPlayerWantsPause_t, *pMusicPlayerWantsPause_t;

#define k_iCallbback_MusicPlayerWantsPlayPrevious_t ((Int32)k_iSteamMusicRemoteCallbacks + 7))
typedef struct _MusicPlayerWantsPlayPrevious_t_ {

	Int32 Unused;

} MusicPlayerWantsPlayPrevious_t, *pMusicPlayerWantsPlayPrevious_t;

#define k_iCallbback_MusicPlayerWantsPlayNext_t ((Int32)k_iSteamMusicRemoteCallbacks + 8))
typedef struct _MusicPlayerWantsPlayNext_t_ {

	Int32 Unused;

} MusicPlayerWantsPlayNext_t, *pMusicPlayerWantsPlayNext_t;

#define k_iCallbback_MusicPlayerWantsShuffled_t ((Int32)k_iSteamMusicRemoteCallbacks + 9))
typedef struct _MusicPlayerWantsShuffled_t_ {
	
	Bool bShuffled;

} MusicPlayerWantsShuffled_t, *pMusicPlayerWantsShuffled_t;

#define k_iCallbback_MusicPlayerWantsLooped_t ((Int32)k_iSteamMusicRemoteCallbacks + 10))
typedef struct _MusicPlayerWantsLooped_t_ {
	
	Bool bLooped;

} MusicPlayerWantsLooped_t, *pMusicPlayerWantsLooped_t;

#define k_iCallbback_MusicPlayerWantsVolume_t ((Int32)k_iSteamMusicCallbacks + 11))
typedef struct _MusicPlayerWantsVolume_t_ {
	
	Float sndVolume;

} MusicPlayerWantsVolume_t, *pMusicPlayerWantsVolume_t;

#define k_iCallbback_MusicPlayerSelectsQueueEntry_t ((Int32)k_iSteamMusicCallbacks + 12))
typedef struct _MusicPlayerSelectsQueueEntry_t_ {

	Int32 nId;

} MusicPlayerSelectsQueueEntry_t, *pMusicPlayerSelectsQueueEntry_t;

#define k_iCallbback_MusicPlayerSelectsPlaylistEntry_t ((Int32)k_iSteamMusicCallbacks + 13))
typedef struct _MusicPlayerSelectsPlaylistEntry_t_ {
	
	Int32 nId;

} MusicPlayerSelectsPlaylistEntry_t, *pMusicPlayerSelectsPlaylistEntry_t;

#define k_iCallbback_MusicPlayerWantsPlayingRepeatStatus_t ((Int32)k_iSteamMusicRemoteCallbacks + 14))
typedef struct _MusicPlayerWantsPlayingRepeatStatus_t_ {

	Int32 nPlayingRepeatStatus;

} MusicPlayerWantsPlayingRepeatStatus_t, *pMusicPlayerWantsPlayingRepeatStatus_t;

#pragma pack(pop)

#endif // #define _ISTEAMMUSICREMOTE_
