#ifndef _STEAMMUSIC_
#define _STEAMMUSIC_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamMusic.h"
// -----------------------------------------------------------------------------

typedef class _SteamMusic_ : public _ISteamMusic_ {
public:

	_SteamMusic_();
	_SteamMusic_(const _SteamMusic_&) = delete;
	_SteamMusic_& operator=(const _SteamMusic_&) = delete;

	Bool BIsEnabled() override;
	Bool BIsPlaying() override;

	AudioPlayback_Status GetPlaybackStatus() override;

	void Play() override;
	void Pause() override;
	void PlayPrevious() override;
	void PlayNext() override;

	/* Volume is Between 0.0 and 1.0 */
	void SetVolume(Float sndVolume) override;
	Float GetVolume() override;

	~_SteamMusic_() = default;

private:

	Float sndVolume;
	AudioPlayback_Status audioPlaybackStatus;

} SteamMusic, *pSteamMusic;

#endif // !_STEAMMUSIC_
