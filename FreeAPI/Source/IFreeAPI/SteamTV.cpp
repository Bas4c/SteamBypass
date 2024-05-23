// -----------------------------------------------------------------------------
#include "SteamTV.h"
// -----------------------------------------------------------------------------

Bool _SteamTV_::IsBroadcasting(pInt32 pnNumViewers) {

	if (pnNumViewers != NULL) {
		*pnNumViewers = 0;
	}

	return False;

}

void _SteamTV_::AddBroadcastGameData(pCStrA pchKey, pCStrA pchValue) {

	/* Empty Method */

}

void _SteamTV_::RemoveBroadcastGameData(pCStrA pchKey) {

	/* Empty Method */

}

void _SteamTV_::AddTimelineMarker(pCStrA pchTemplateName, Bool bPersistent, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB) {

	/* Empty Method */

}

void _SteamTV_::RemoveTimelineMarker() {

	/* Empty Method */

}

Uint32 _SteamTV_::AddRegion(pCStrA pchElementName, pCStrA pchTimelineDataSection, const pVoid pSteamTVRegion, Int32 eSteamTVRegionBehavior) {

	return 0U;

}

void _SteamTV_::RemoveRegion(Uint32 hRegion) {

	/* Empty Method */

}
