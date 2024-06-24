#ifndef _ISTEAMSCREENSHOTS_
#define _ISTEAMSCREENSHOTS_

#include "..\..\FreeAPI.Typedef.h"

#define k_nScreenshotMaxTaggedUsers ((Int32)(32))
#define k_nScreenshotMaxTaggedPublishedFiles ((Int32)(32))
#define k_cbUFSTagTypeMax ((Uint32)(255))
#define k_cbUFSTagValueMax ((Uint32)(255))
#define k_ScreenshotThumbCx ((Int32)(200))

typedef Uint32 ScreenshotHandle, *pScreenshotHandle;
#define k_ScreenshotHandle_Invalid ((ScreenshotHandle)(0x00000000))

typedef enum _EVRScreenshotType_ {
	
	k_EVRScreenshotType_None,
	k_EVRScreenshotType_Mono,
	k_EVRScreenshotType_Stereo,
	k_EVRScreenshotType_MonoCubemap,
	k_EVRScreenshotType_MonoPanorama,
	k_EVRScreenshotType_StereoPanorama

} EVRScreenshotType, *pEVRScreenshotType;

typedef class _ISteamScreenshots001_ {
public:
	
	virtual ScreenshotHandle WriteScreenshot(pVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) = 0;
	virtual ScreenshotHandle AddScreenshotToLibrary(pCStrA pchFilename, pCStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) = 0;
	virtual void TriggerScreenshot() = 0;
	virtual void HookScreenshots(Bool bHook) = 0;
	virtual Bool SetLocation(ScreenshotHandle hScreenshot, pCStrA pchLocation) = 0;

} ISteamScreenshots001, *IpSteamScreenshots001;

typedef class _ISteamScreenshots002_ {
public:
	
	virtual ScreenshotHandle WriteScreenshot(pVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) = 0;
	virtual ScreenshotHandle AddScreenshotToLibrary(pCStrA pchFilename, pCStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) = 0;
	virtual void TriggerScreenshot() = 0;
	virtual void HookScreenshots(Bool bHook) = 0;
	virtual Bool SetLocation(ScreenshotHandle hScreenshot, pCStrA pchLocation) = 0;
	virtual Bool TagUser(ScreenshotHandle hScreenshot, SteamId_t SteamId) = 0;
	virtual Bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t PublishedFileId) = 0;

} ISteamScreenshots002, *IpSteamScreenshots002;

// -----------------------------------------------------------------------------
// Purpose: Adding screenshots to the user's screenshot library
// -----------------------------------------------------------------------------
typedef class _ISteamScreenshots_ {
public:

	virtual ScreenshotHandle WriteScreenshot(pVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) = 0;
	virtual ScreenshotHandle AddScreenshotToLibrary(pCStrA pchFilename, pCStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) = 0;
	virtual void TriggerScreenshot() = 0;
	virtual void HookScreenshots(Bool bHook) = 0;
	virtual Bool SetLocation(ScreenshotHandle hScreenshot, pCStrA pchLocation) = 0;
	virtual Bool TagUser(ScreenshotHandle hScreenshot, SteamId_t SteamId) = 0;
	virtual Bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool IsScreenshotsHooked() = 0;
	virtual ScreenshotHandle AddVRScreenshotToLibrary(EVRScreenshotType eVRScreenshotType, pCStrA pchFilename, pCStrA pchVRFilename) = 0;

} ISteamScreenshots, *IpSteamScreenshots;

#define STEAMSCREENSHOTS_INTERFACE_VERSION "STEAMSCREENSHOTS_INTERFACE_VERSION003"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// -----------------------------------------------------------------------------
// Purpose: Screenshot successfully written or otherwise added to the library
//  and can now be tagged
// -----------------------------------------------------------------------------
#define k_iCallbback_ScreenshotReady_t ((Int32)(k_iSteamScreenshotsCallbacks + 1))
typedef struct _ScreenshotReady_t_ {

	ScreenshotHandle hLocal;
	EResult eResult;

} ScreenshotReady_t, *pScreenshotReady_t;

// -----------------------------------------------------------------------------
// Purpose: Screenshot has been requested by the user.  Only sent if
//  HookScreenshots() has been called, in which case Steam will not take
//  the screenshot itself.
// -----------------------------------------------------------------------------
#define k_iCallbback_ScreenshotRequested_t ((Int32)(k_iSteamScreenshotsCallbacks + 2))
typedef struct _ScreenshotRequested_t_ {

	Int32 Unused;

} ScreenshotRequested_t, *pScreenshotRequested_t;

#pragma pack(pop)

#endif // _ISTEAMSCREENSHOTS_

