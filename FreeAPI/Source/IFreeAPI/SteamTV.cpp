// -----------------------------------------------------------------------------
#include "SteamTV.h"
// -----------------------------------------------------------------------------

Bool _SteamTV_::IsBroadcasting(pInt32 pnNumViewers) {

	if (pnNumViewers != NULL) {
		*pnNumViewers = 0;
	}

	return False;

}

void _SteamTV_::AddBroadcastGameData(const pStrA pchKey, const pStrA pchValue) {

	/* Empty Method */

}

void _SteamTV_::RemoveBroadcastGameData(const pStrA pchKey) {

	/* Empty Method */

}

void _SteamTV_::AddTimelineMarker(const pStrA pchTemplateName, Bool bPersistent, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB) {

	/* Empty Method */

}

void _SteamTV_::RemoveTimelineMarker() {

	/* Empty Method */

}

Uint32 _SteamTV_::AddRegion(const pStrA pchElementName, const pStrA pchTimelineDataSection, const pVoid pSteamTVRegion, Int32 eSteamTVRegionBehavior) {

	return 0U;

}

void _SteamTV_::RemoveRegion(Uint32 hRegion) {

	/* Empty Method */

}
