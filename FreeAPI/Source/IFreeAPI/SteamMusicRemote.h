#ifndef _STEAMMUSICREMOTE_
#define _STEAMMUSICREMOTE_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamMusicRemote.h"
// -----------------------------------------------------------------------------

typedef class _SteamMusicRemote_ : public _ISteamMusicRemote_ {
public:

	_SteamMusicRemote_() = default;
	_SteamMusicRemote_(const _SteamMusicRemote_&) = delete;
	_SteamMusicRemote_& operator=(const _SteamMusicRemote_&) = delete;

	Bool RegisterSteamMusicRemote(const pStrA pchName) override;
	Bool DeregisterSteamMusicRemote() override;
	Bool BIsCurrentMusicRemote() override;
	Bool BActivationSuccess(Bool bValue) override;

	Bool SetDisplayName(const pStrA pchDisplayName) override;
	Bool SetPNGIcon_64x64(pVoid pvData, Uint32 cbDataSize) override;

	Bool EnablePlayPrevious(Bool bValue) override;
	Bool EnablePlayNext(Bool bValue) override;
	Bool EnableShuffled(Bool bValue) override;
	Bool EnableLooped(Bool bValue) override;
	Bool EnableQueue(Bool bValue) override;
	Bool EnablePlaylists(Bool bValue) override;

	Bool UpdatePlaybackStatus(AudioPlayback_Status audioPlayback_Status) override;
	Bool UpdateShuffled(Bool bValue) override;
	Bool UpdateLooped(Bool bValue) override;
	/* Volume is Between 0.0 and 1.0 */
	Bool UpdateVolume(Float sndVolume) override;

	Bool CurrentEntryWillChange() override;
	Bool CurrentEntryIsAvailable(Bool bAvailable) override;
	Bool UpdateCurrentEntryText(const pStrA pchText) override;
	Bool UpdateCurrentEntryElapsedSeconds(Int32 nValue) override;
	Bool UpdateCurrentEntryCoverArt(pVoid pvData, Uint32 cbDataSize) override;
	Bool CurrentEntryDidChange() override;

	Bool QueueWillChange() override;
	Bool ResetQueueEntries() override;
	Bool SetQueueEntry(Int32 nId, Int32 nPosition, const pStrA pchEntryText) override;
	Bool SetCurrentQueueEntry(Int32 nId) override;
	Bool QueueDidChange() override;

	Bool PlaylistWillChange() override;
	Bool ResetPlaylistEntries() override;
	Bool SetPlaylistEntry(Int32 nId, Int32 nPosition, const pStrA pchEntryText) override;
	Bool SetCurrentPlaylistEntry(Int32 nId) override;
	Bool PlaylistDidChange() override;

	~_SteamMusicRemote_() = default;

} SteamMusicRemote, *pSteamMusicRemote;

#endif // !_STEAMMUSICREMOTE_
