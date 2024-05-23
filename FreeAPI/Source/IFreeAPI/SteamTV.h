#ifndef _STEAMTV_
#define _STEAMTV_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamTV.h"
// -----------------------------------------------------------------------------

typedef class _SteamTV_ : public _ISteamTV_ {
public:

	_SteamTV_() = default;
	_SteamTV_(const _SteamTV_&) = delete;
	_SteamTV_& operator=(const _SteamTV_&) = delete;

	Bool IsBroadcasting(pInt32 pnNumViewers) override;
	void AddBroadcastGameData(pCStrA pchKey, pCStrA pchValue) override;
	void RemoveBroadcastGameData(pCStrA pchKey) override;
	void AddTimelineMarker(pCStrA pchTemplateName, Bool bPersistent, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB) override;
	void RemoveTimelineMarker() override;
	Uint32 AddRegion(pCStrA pchElementName, pCStrA pchTimelineDataSection, const pVoid pSteamTVRegion, Int32 eSteamTVRegionBehavior) override;
	void RemoveRegion(Uint32 hRegion) override;

	~_SteamTV_() = default;

} SteamTV, *pSteamTV;

#endif // !_STEAMTV_
