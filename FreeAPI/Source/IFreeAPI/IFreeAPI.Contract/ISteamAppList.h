#ifndef _ISTEAMAPPLIST_
#define _ISTEAMAPPLIST_

#include "..\..\FreeAPI.Typedef.h"

// -----------------------------------------------------------------------------
// Purpose: This is a restricted interface that can only be used by previously approved apps,
//  contact your Steam Account Manager if you believe you need access to this API.
//  This interface lets you detect installed apps for the local Steam client, useful for debugging tools
//   to offer lists of apps to debug via Steam.
// -----------------------------------------------------------------------------
typedef class _ISteamAppList_ {
public:

	virtual Uint32 GetNumInstalledApps() = 0;
	virtual Uint32 GetInstalledApps(/* [out] */ pAppId_t pnAppId, Uint32 nAppId) = 0;
	/* Returns (-1): Name not Found */
	virtual Int32 GetAppName(AppId_t iAppId, /* [out] */ pStrA pchName, Int32 cchNameMax) = 0;
	/* Returns (-1): Install Directory not Found */
	virtual Int32 GetAppInstallDir(AppId_t iAppId, /* [out] */ pStrA pchDirectory, Int32 cchNameMax) = 0;
	/* Returns games current BuildId */
	virtual Int32 GetAppBuildId(AppId_t iAppId) = 0;

} ISteamAppList, *IpSteamAppList;

#define STEAMAPPLIST_INTERFACE_VERSION "STEAMAPPLIST_INTERFACE_VERSION001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// ---------------------------------------------------------------------------------
// Purpose: Sent when a new app is installed (not downloaded yet)
// ---------------------------------------------------------------------------------
#define k_iCallbback_SteamAppInstalled_t ((Int32)(k_iSteamAppListCallbacks + 1))
typedef struct _SteamAppInstalled_t_ {

	AppId_t iAppId;
	Int32 iInstallDirectory;

} SteamAppInstalled_t, *pSteamAppInstalled_t;

// ---------------------------------------------------------------------------------
// Purpose: Sent when an app is uninstalled
// ---------------------------------------------------------------------------------
#define k_iCallbback_SteamAppUninstalled_t ((Int32)(k_iSteamAppListCallbacks + 2))
typedef struct _SteamAppUninstalled_t_ {

	AppId_t iAppId;
	Int32 iInstallDirectory;

} SteamAppUninstalled_t, *pSteamAppUninstalled_t;

#pragma pack(pop)

#endif // _ISTEAMAPPLIST_
