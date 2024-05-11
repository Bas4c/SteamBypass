#ifndef _STEAMVIDEO_
#define _STEAMVIDEO_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamVideo.h"
// -----------------------------------------------------------------------------

typedef class _SteamVideo_ : public _ISteamVideo_ {

	_SteamVideo_() = default;
	_SteamVideo_(const _SteamVideo_&) = delete;
	_SteamVideo_& operator=(const _SteamVideo_&) = delete;
	
	void GetVideoURL(AppId_t iVideoAppId) override;
	Bool IsBroadcasting(pInt32 pnNumViewers) override;
	void GetOPFSettings(AppId_t iVideoAppId) override;
	Bool GetOPFStringForApp(AppId_t iVideoAppId, pStrA pchOPFString, pInt32 pnOPFString) override;

	~_SteamVideo_() = default;

} SteamVideo, *pSteamVideo;

#endif // !_STEAMVIDEO_
