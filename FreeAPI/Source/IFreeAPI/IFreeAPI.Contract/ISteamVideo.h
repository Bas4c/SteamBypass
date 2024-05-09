#ifndef _ISTEAMVIDEO_
#define _ISTEAMVIDEO_

#include "..\..\FreeAPI.Typedef.h"

// -----------------------------------------------------------------------------
// Purpose: Steam Video API
// -----------------------------------------------------------------------------
typedef class _ISteamVideo_ {
public:
	
	virtual void GetVideoURL(AppId_t iVideoAppId) = 0;
	virtual Bool IsBroadcasting(/* [out] */ pInt32 pnNumViewers) = 0;
	virtual void GetOPFSettings(AppId_t iVideoAppId) = 0;
	virtual Bool GetOPFStringForApp(AppId_t iVideoAppId, /* [out] */ pStrA pchOPFString, pInt32 pnOPFString) = 0;

} ISteamVideo, *IpSteamVideo;

#define STEAMVIDEO_INTERFACE_VERSION "STEAMVIDEO_INTERFACE_V002"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_BroadcastUploadStart_t ((Int32)(iClientVideoCallbacks + 4))
typedef struct _BroadcastUploadStart_t_ {

	Int32 Unused;

} BroadcastUploadStart_t, *pBroadcastUploadStart_t;

#define k_iCallbback_BroadcastUploadStop_t ((Int32)(iClientVideoCallbacks + 5))
typedef struct _BroadcastUploadStop_t_ {

	EBroadcastUploadResult eBroadcastUploadResult;

} roadcastUploadStop_t, *proadcastUploadStop_t;

#define k_iCallbback_GetVideoURLResult_t ((Int32)(k_iSteamVideoCallbacks + 11))
typedef struct _GetVideoURLResult_t_ {

	EResult eResult;
	AppId_t iVideoAppId;
	CharA chURL[256];

} GetVideoURLResult_t, *pGetVideoURLResult_t;

#define k_iCallbback_GetOPFSettingsResult_t ((Int32)(k_iSteamVideoCallbacks + 24))
typedef struct _GetOPFSettingsResult_t_ {

	EResult eResult;
	AppId_t iVideoAppId;

} GetOPFSettingsResult_t, *pGetOPFSettingsResult_t;

#pragma pack(pop)

#endif // _ISTEAMVIDEO_
