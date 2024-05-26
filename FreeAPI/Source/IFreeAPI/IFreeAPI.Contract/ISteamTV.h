#ifndef _ISTEAMTV_
#define _ISTEAMTV_

#include "..\..\FreeAPI.Typedef.h"

typedef class _ISteamTV_ {
public:

	virtual Bool IsBroadcasting(pInt32 pnNumViewers) = 0;
	virtual void AddBroadcastGameData(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual void RemoveBroadcastGameData(pCStrA pchKey) = 0;
	virtual void AddTimelineMarker(pCStrA pchTemplateName, Bool bPersistent, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB) = 0;
	virtual void RemoveTimelineMarker() = 0;
	virtual Uint32 AddRegion(pCStrA pchElementName, pCStrA pchTimelineDataSection, pCVoid pSteamTVRegion, Int32 eSteamTVRegionBehavior) = 0;
	virtual void RemoveRegion(Uint32 hRegion) = 0;

} ISteamTV, *IpSteamTV;

#define STEAMTV_INTERFACE_VERSION "STEAMTV_INTERFACE_V001"

#endif // _ISTEAMTV_
