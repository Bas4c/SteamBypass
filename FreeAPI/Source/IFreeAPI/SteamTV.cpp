// -----------------------------------------------------------------------------
#include "SteamTV.h"
// -----------------------------------------------------------------------------

Bool _SteamTV_::IsBroadcasting(pInt32 pnNumViewers) {
	DEBUGBREAK("ISteamTV::IsBroadcasting");

	if (pnNumViewers != NULL) {
		*pnNumViewers = 0;
	}

	return False;

}

void _SteamTV_::AddBroadcastGameData(pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamTV::AddBroadcastGameData");

	/* Empty Method */

}

void _SteamTV_::RemoveBroadcastGameData(pCStrA pchKey) {
	DEBUGBREAK("ISteamTV::RemoveBroadcastGameData");

	/* Empty Method */

}

void _SteamTV_::AddTimelineMarker(pCStrA pchTemplateName, Bool bPersistent, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB) {
	DEBUGBREAK("ISteamTV::AddTimelineMarker");

	/* Empty Method */

}

void _SteamTV_::RemoveTimelineMarker() {
	DEBUGBREAK("ISteamTV::RemoveTimelineMarker");

	/* Empty Method */

}

Uint32 _SteamTV_::AddRegion(pCStrA pchElementName, pCStrA pchTimelineDataSection, const pVoid pSteamTVRegion, Int32 eSteamTVRegionBehavior) {
	DEBUGBREAK("ISteamTV::AddRegion");

	return 0U;

}

void _SteamTV_::RemoveRegion(Uint32 hRegion) {
	DEBUGBREAK("ISteamTV::RemoveRegion");

	/* Empty Method */

}
