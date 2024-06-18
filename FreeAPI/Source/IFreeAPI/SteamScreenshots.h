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

	_SteamScreenshots_() = default;
	_SteamScreenshots_(const _SteamScreenshots_&) = delete;
	_SteamScreenshots_& operator=(const _SteamScreenshots_&) = delete;

	ScreenshotHandle WriteScreenshot(pCVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) override;
	ScreenshotHandle AddScreenshotToLibrary(pCStrA pchFilename, pCStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) override;
	void TriggerScreenshot() override;
	void HookScreenshots(Bool bHook) override;
	Bool SetLocation(ScreenshotHandle hScreenshot, pCStrA pchLocation) override;
	Bool TagUser(ScreenshotHandle hScreenshot, SteamId_t SteamId) override;
	Bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t PublishedFileId) override;
	Bool IsScreenshotsHooked() override;
	ScreenshotHandle AddVRScreenshotToLibrary(EVRScreenshotType eVRScreenshotType, pCStrA pchFilename, pCStrA pchVRFilename) override;

	~_SteamScreenshots_() = default;

} SteamScreenshots, *pSteamScreenshots;

#endif // !_STEAMSCREENSHOTS_
