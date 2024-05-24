// -----------------------------------------------------------------------------
#include "SteamScreenshots.h"
// -----------------------------------------------------------------------------

ScreenshotHandle _SteamScreenshots_::WriteScreenshot(const pVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) {
	DEBUGBREAK("ISteamScreenshots::WriteScreenshot");

	SaveScreenshot(pvRGB, cbRGB, Cx, Cy);
	return k_ScreenshotHandle_Invalid;

}

ScreenshotHandle _SteamScreenshots_::AddScreenshotToLibrary(pCStrA pchFilename, pCStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) {
	DEBUGBREAK("ISteamScreenshots::AddScreenshotToLibrary");

	return k_ScreenshotHandle_Invalid;

}

void _SteamScreenshots_::TriggerScreenshot() {
	DEBUGBREAK("ISteamScreenshots::TriggerScreenshot");

	/* Empty Method */

}

void _SteamScreenshots_::HookScreenshots(Bool bHook) {
	DEBUGBREAK("ISteamScreenshots::HookScreenshots");

	/* Empty Method */

}

Bool _SteamScreenshots_::SetLocation(ScreenshotHandle hScreenshot, pCStrA pchLocation) {
	DEBUGBREAK("ISteamScreenshots::SetLocation");

	return False;

}

Bool _SteamScreenshots_::TagUser(ScreenshotHandle hScreenshot, SteamId_t SteamId) {
	DEBUGBREAK("ISteamScreenshots::TagUser");

	return False;

}

Bool _SteamScreenshots_::TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID) {
	DEBUGBREAK("ISteamScreenshots::TagPublishedFile");

	return False;

}

Bool _SteamScreenshots_::IsScreenshotsHooked() {
	DEBUGBREAK("ISteamScreenshots::IsScreenshotsHooked");

	return False;

}

ScreenshotHandle _SteamScreenshots_::AddVRScreenshotToLibrary(EVRScreenshotType eVRScreenshotType, pCStrA pchFilename, pCStrA pchVRFilename) {
	DEBUGBREAK("ISteamScreenshots::AddVRScreenshotToLibrary");

	return k_ScreenshotHandle_Invalid;

}
