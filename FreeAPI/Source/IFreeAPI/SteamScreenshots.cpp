// -----------------------------------------------------------------------------
#include "SteamScreenshots.h"
// -----------------------------------------------------------------------------

ScreenshotHandle _SteamScreenshots_::WriteScreenshot(const pVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) {

	SaveScreenshot(pvRGB, cbRGB, Cx, Cy);
	return k_ScreenshotHandle_Invalid;

}

ScreenshotHandle _SteamScreenshots_::AddScreenshotToLibrary(pStrA pchFilename, pStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) {

	return k_ScreenshotHandle_Invalid;

}

void _SteamScreenshots_::TriggerScreenshot() {

	/* Empty Method */

}

void _SteamScreenshots_::HookScreenshots(Bool bHook) {

	/* Empty Method */

}

Bool _SteamScreenshots_::SetLocation(ScreenshotHandle hScreenshot, pStrA pchLocation) {

	return False;

}

Bool _SteamScreenshots_::TagUser(ScreenshotHandle hScreenshot, SteamId_t SteamId) {

	return False;

}

Bool _SteamScreenshots_::TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID) {

	return False;

}

Bool _SteamScreenshots_::IsScreenshotsHooked() {

	return False;

}

ScreenshotHandle _SteamScreenshots_::AddVRScreenshotToLibrary(EVRScreenshotType eVRScreenshotType, pStrA pchFilename, pStrA pchVRFilename) {

	return k_ScreenshotHandle_Invalid;

}
