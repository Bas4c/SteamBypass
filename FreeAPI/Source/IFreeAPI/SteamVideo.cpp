// -----------------------------------------------------------------------------
#include "SteamVideo.h"
// -----------------------------------------------------------------------------

void _SteamVideo_::GetVideoURL(AppId_t iVideoAppId) {

	/* Empty Method */

}

Bool _SteamVideo_::IsBroadcasting(pInt32 pnNumViewers) {

	if (pnNumViewers != NULL) {
		*pnNumViewers = 0;
	}

	return False;

}

void _SteamVideo_::GetOPFSettings(AppId_t iVideoAppId) {

	/* Empty Method */

}

Bool _SteamVideo_::GetOPFStringForApp(AppId_t iVideoAppId, pStrA pchOPFString, pInt32 pnOPFString) {

	if (pchOPFString != NULL && pnOPFString != NULL) {
		if (*pnOPFString > 0) {
			pchOPFString[0] = '\0';
			*pnOPFString = 1;
		}
	}

	return False;

}
