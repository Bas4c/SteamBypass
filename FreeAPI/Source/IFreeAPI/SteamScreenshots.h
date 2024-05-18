#ifndef _STEAMSCREENSHOTS_
#define _STEAMSCREENSHOTS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamScreenshots.h"
// -----------------------------------------------------------------------------

typedef class _SteamScreenshots_ : public _ISteamScreenshots_ {
public:

	ScreenshotHandle WriteScreenshot(const pVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) override;
	ScreenshotHandle AddScreenshotToLibrary(pStrA pchFilename, pStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) override;
	void TriggerScreenshot() override;
	void HookScreenshots(Bool bHook) override;
	Bool SetLocation(ScreenshotHandle hScreenshot, pStrA pchLocation) override;
	Bool TagUser(ScreenshotHandle hScreenshot, SteamId_t SteamId) override;
	Bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID) override;
	Bool IsScreenshotsHooked() override;
	ScreenshotHandle AddVRScreenshotToLibrary(EVRScreenshotType eVRScreenshotType, pStrA pchFilename, pStrA pchVRFilename) override;

} SteamScreenshots, *pSteamScreenshots;

#endif // !_STEAMSCREENSHOTS_
