#ifndef _ISTEAMAPPS_
#define _ISTEAMAPPS_

#include "..\..\FreeAPI.Typedef.h"

#define k_cchAppProofOfPurchaseKeyMax ((Int32)(240))

typedef class _ISteamApps001_ {
public:

	virtual Int32 GetAppData(AppId_t iAppId, pCStrA pchKey, pStrA pchValue, Int32 cchValueMax) = 0;

} ISteamApps001, *IpSteamApps001;

typedef class _ISteamApps002_ {
public:

	virtual Bool BIsSubscribed() = 0;
	virtual Bool BIsLowViolence() = 0;
	virtual Bool BIsCybercafe() = 0;
	virtual Bool BIsVACBanned() = 0;
	virtual pCStrA GetCurrentGameLanguage() = 0;
	virtual pCStrA GetAvailableGameLanguages() = 0;
	virtual Bool BIsSubscribedApp(AppId_t iAppId) = 0;

} ISteamApps002, *IpSteamApps002;

typedef class _ISteamApps003_ {
public:

	virtual Bool BIsSubscribed() = 0;
	virtual Bool BIsLowViolence() = 0;
	virtual Bool BIsCybercafe() = 0;
	virtual Bool BIsVACBanned() = 0;
	virtual pCStrA GetCurrentGameLanguage() = 0;
	virtual pCStrA GetAvailableGameLanguages() = 0;
	virtual Bool BIsSubscribedApp(AppId_t iAppId) = 0;
	virtual Bool BIsDlcInstalled(AppId_t iAppId) = 0;

} ISteamApps003, *IpSteamApps003;

typedef class _ISteamApps004_ {
public:

	virtual Bool BIsSubscribed() = 0;
	virtual Bool BIsLowViolence() = 0;
	virtual Bool BIsCybercafe() = 0;
	virtual Bool BIsVACBanned() = 0;
	virtual pCStrA GetCurrentGameLanguage() = 0;
	virtual pCStrA GetAvailableGameLanguages() = 0;
	virtual Bool BIsSubscribedApp(AppId_t iAppId) = 0;
	virtual Bool BIsDlcInstalled(AppId_t iAppId) = 0;
	virtual Uint32 GetEarliestPurchaseUnixTime(AppId_t iAppId) = 0;
	virtual Bool BIsSubscribedFromFreeWeekend() = 0;
	virtual Int32 GetDLCCount() = 0;
	virtual Bool BGetDLCDataByIndex(Int32 iDLC, pAppId_t pAppId, pBool pbAvailable, pStrA pchName, Int32 cchNameBufferSize) = 0;
	virtual void InstallDLC(AppId_t iAppId) = 0;
	virtual void UninstallDLC(AppId_t iAppId) = 0;

} ISteamApps004, *IpSteamApps004;

typedef class _ISteamApps005_ {
public:

	virtual Bool BIsSubscribed() = 0;
	virtual Bool BIsLowViolence() = 0;
	virtual Bool BIsCybercafe() = 0;
	virtual Bool BIsVACBanned() = 0;
	virtual pCStrA GetCurrentGameLanguage() = 0;
	virtual pCStrA GetAvailableGameLanguages() = 0;
	virtual Bool BIsSubscribedApp(AppId_t iAppId) = 0;
	virtual Bool BIsDlcInstalled(AppId_t iAppId) = 0;
	virtual Uint32 GetEarliestPurchaseUnixTime(AppId_t iAppId) = 0;
	virtual Bool BIsSubscribedFromFreeWeekend() = 0;
	virtual Int32 GetDLCCount() = 0;
	virtual Bool BGetDLCDataByIndex(Int32 iDLC, pAppId_t pAppId, pBool pbAvailable, pStrA pchName, Int32 cchNameBufferSize) = 0;
	virtual void InstallDLC(AppId_t iAppId) = 0;
	virtual void UninstallDLC(AppId_t iAppId) = 0;
	virtual void RequestAppProofOfPurchaseKey(AppId_t iAppId) = 0;
	virtual Bool GetCurrentBetaName(pStrA pchName, Int32 cchNameBufferSize) = 0;
	virtual Bool MarkContentCorrupt(Bool bMissingFilesOnly) = 0;
	virtual Uint32 GetInstalledDepots(AppId_t AppId, pDepotId_t pvecDepots, Uint32 cMaxDepots) = 0;
	virtual Uint32 GetAppInstallDir(AppId_t AppId, pStrA pchFolder, Uint32 cchFolderBufferSize) = 0;
	virtual Bool BIsAppInstalled(AppId_t AppId) = 0;

} ISteamApps005, *IpSteamApps005;

typedef class _ISteamApps006_ {
public:

	virtual Bool BIsSubscribed() = 0;
	virtual Bool BIsLowViolence() = 0;
	virtual Bool BIsCybercafe() = 0;
	virtual Bool BIsVACBanned() = 0;
	virtual pCStrA GetCurrentGameLanguage() = 0;
	virtual pCStrA GetAvailableGameLanguages() = 0;
	virtual Bool BIsSubscribedApp(AppId_t iAppId) = 0;
	virtual Bool BIsDlcInstalled(AppId_t iAppId) = 0;
	virtual Uint32 GetEarliestPurchaseUnixTime(AppId_t iAppId) = 0;
	virtual Bool BIsSubscribedFromFreeWeekend() = 0;
	virtual Int32 GetDLCCount() = 0;
	virtual Bool BGetDLCDataByIndex(Int32 iDLC, pAppId_t pAppId, pBool pbAvailable, pStrA pchName, Int32 cchNameBufferSize) = 0;
	virtual void InstallDLC(AppId_t iAppId) = 0;
	virtual void UninstallDLC(AppId_t iAppId) = 0;
	virtual void RequestAppProofOfPurchaseKey(AppId_t iAppId) = 0;
	virtual Bool GetCurrentBetaName(pStrA pchName, Int32 cchNameBufferSize) = 0;
	virtual Bool MarkContentCorrupt(Bool bMissingFilesOnly) = 0;
	virtual Uint32 GetInstalledDepots(AppId_t AppId, pDepotId_t pvecDepots, Uint32 cMaxDepots) = 0;
	virtual Uint32 GetAppInstallDir(AppId_t AppId, pStrA pchFolder, Uint32 cchFolderBufferSize) = 0;
	virtual Bool BIsAppInstalled(AppId_t AppId) = 0;
	virtual SteamId_t GetAppOwner() = 0;
	virtual pCStrA GetLaunchQueryParam(pCStrA pchKey) = 0;

} ISteamApps006, *IpSteamApps006;

typedef class _ISteamApps007_ {
public:

	virtual Bool BIsSubscribed() = 0;
	virtual Bool BIsLowViolence() = 0;
	virtual Bool BIsCybercafe() = 0;
	virtual Bool BIsVACBanned() = 0;
	virtual pCStrA GetCurrentGameLanguage() = 0;
	virtual pCStrA GetAvailableGameLanguages() = 0;
	virtual Bool BIsSubscribedApp(AppId_t iAppId) = 0;
	virtual Bool BIsDlcInstalled(AppId_t iAppId) = 0;
	virtual Uint32 GetEarliestPurchaseUnixTime(AppId_t iAppId) = 0;
	virtual Bool BIsSubscribedFromFreeWeekend() = 0;
	virtual Int32 GetDLCCount() = 0;
	virtual Bool BGetDLCDataByIndex(Int32 iDLC, pAppId_t pAppId, pBool pbAvailable, pStrA pchName, Int32 cchNameBufferSize) = 0;
	virtual void InstallDLC(AppId_t iAppId) = 0;
	virtual void UninstallDLC(AppId_t iAppId) = 0;
	virtual void RequestAppProofOfPurchaseKey(AppId_t iAppId) = 0;
	virtual Bool GetCurrentBetaName(pStrA pchName, Int32 cchNameBufferSize) = 0;
	virtual Bool MarkContentCorrupt(Bool bMissingFilesOnly) = 0; 
	virtual Uint32 GetInstalledDepots(AppId_t AppId, pDepotId_t pvecDepots, Uint32 cMaxDepots) = 0;
	virtual Uint32 GetAppInstallDir(AppId_t AppId, pStrA pchFolder, Uint32 cchFolderBufferSize) = 0;
	virtual Bool BIsAppInstalled(AppId_t AppId) = 0;
	virtual SteamId_t GetAppOwner() = 0;
	virtual pCStrA GetLaunchQueryParam(pCStrA pchKey) = 0;
	virtual Bool GetDlcDownloadProgress(AppId_t iAppId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Int32 GetAppBuildId() = 0;

} ISteamApps007, *IpSteamApps007;

// -----------------------------------------------------------------------------
// Purpose: Interface to app data
// -----------------------------------------------------------------------------
typedef class _ISteamApps_ {
public:

	virtual Bool BIsSubscribed() = 0;
	virtual Bool BIsLowViolence() = 0;
	virtual Bool BIsCybercafe() = 0;
	virtual Bool BIsVACBanned() = 0;

	virtual pCStrA GetCurrentGameLanguage() = 0;
	virtual pCStrA GetAvailableGameLanguages() = 0;

	/* Only use this member if you need to check ownership of another game related to yours */
	virtual Bool BIsSubscribedApp(AppId_t iAppId) = 0;
	/* Takes AppId of DLC and checks if the user owns the DLC */
	virtual Bool BIsDlcInstalled(AppId_t iAppId) = 0;

	/* Returns the Unix Time of the purchase of the app */
	virtual Uint32 GetEarliestPurchaseUnixTime(AppId_t iAppId) = 0;

	/* Checks if the user is subscribed to the current app through a free weekend
	    This function will return false for users who have a retail or other type of license
	     before using, please ask your Valve technical contact how to package and secure your free weekened */
	virtual Bool BIsSubscribedFromFreeWeekend() = 0;

	/* Returns the number of DLC pieces for the running app */
	virtual Int32 GetDLCCount() = 0;

	/* Returns metadata for DLC by index, of range [0, GetDLCCount()] */
	virtual Bool BGetDLCDataByIndex(Int32 iDLC, /* [out] */ pAppId_t pnAppId, /* [out] */ pBool pbAvailable, /* [out] */ pStrA pchName, Int32 cchNameMax) = 0;

	virtual void InstallDLC(AppId_t iAppId) = 0;
	virtual void UninstallDLC(AppId_t iAppId) = 0;

	/* Request legacy cd-key for yourself or owned DLC. If you are interested in this
	    data then make sure you provide us with a list of valid keys to be distributed
	    to users when they purchase the game, before the game ships.
	    You'll receive an AppProofOfPurchaseKeyResponse_t callback when
	     the key is available (which may be immediately) */
	virtual void RequestAppProofOfPurchaseKey(AppId_t iAppId) = 0;

	/* Returns current beta branch name, 'public' is the default branch */
	virtual Bool GetCurrentBetaName(pStrA pchName, Int32 cchNameMax) = 0;
	virtual Bool MarkContentCorrupt(Bool bMissingFilesOnly) = 0;
	virtual Uint32 GetInstalledDepots(AppId_t iAppId, /* [out] */ pDepotId_t pnDepotId, Uint32 nDepotId) = 0;
	virtual Uint32 GetAppInstallDir(AppId_t iAppId, /* [out] */ pStrA pchFolder, Uint32 cchFolderMax) = 0;
	virtual Bool BIsAppInstalled(AppId_t iAppId) = 0;
	virtual SteamId_t GetAppOwner() = 0; 

	/* Returns the associated launch param if the game is run via steam://run/<iAppId>//?param1=value1&param2=value2&param3=value3 etc.
	   Parameter names starting with the character '@' are reserved for internal use and will always return and empty string.
	   Parameter names starting with an underscore '_' are reserved for steam features -- they can be queried by the game,
	    but it is advised that you not param names beginning with an underscore for your own features.
	   Check for new launch parameters on callback NewUrlLaunchParameters_t */
	virtual pCStrA GetLaunchQueryParam(pCStrA pchKey) = 0;

	virtual Bool GetDlcDownloadProgress(AppId_t iAppId, /* [out] */ pUint64 pnBytesDownloaded, /* [out] */ pUint64 pnBytesTotal) = 0;
	virtual Int32 GetAppBuildId() = 0;
	virtual void RequestAllProofOfPurchaseKeys() = 0;
	virtual SteamAPICall_t GetFileDetails(pCStrA pchFileName) = 0;
	virtual Int32 GetLaunchCommandLine(pStrA pchCommandLine, Int32 cchCommandLine) = 0;
	virtual Bool BIsSubscribedFromFamilySharing() = 0;
	virtual Bool BIsTimedTrial(/* [out] */ pUint32 pnSecondsAllowed, /* [out] */ pUint32 pnSecondsPlayed) = 0;
	virtual Bool SetDlcContext(AppId_t iAppId) = 0;

} ISteamApps, *IpSteamApps;

#define STEAMAPPS_INTERFACE_VERSION "STEAMAPPS_INTERFACE_VERSION008"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// -----------------------------------------------------------------------------
// Purpose: Posted after the user gains ownership of DLC & that DLC is installed
// -----------------------------------------------------------------------------
#define k_iCallbback_DlcInstalled_t ((Int32)(k_iSteamAppsCallbacks + 5))
typedef struct _DlcInstalled_t_ {

	AppId_t iAppId;

} DlcInstalled_t, *pDlcInstalled_t;

// ---------------------------------------------------------------------------------
// Purpose: Posted after the user gains executes a Steam URL with command line or query parameters
//  such as steam://run/<appid>//-commandline/?param1=value1&param2=value2&param3=value3 etc
//  while the game is already running. The new params can be queried
//  with GetLaunchQueryParam and GetLaunchCommandLine
// ---------------------------------------------------------------------------------
#define k_iCallbback_NewUrlLaunchParameters_t ((Int32)(k_iSteamAppsCallbacks + 14))
typedef struct _NewUrlLaunchParameters_t_ {
	
	Int32 Unused;

} NewUrlLaunchParameters_t, *pNewUrlLaunchParameters_t;

// -----------------------------------------------------------------------------
// Purpose: Response to RequestAppProofOfPurchaseKey/RequestAllProofOfPurchaseKeys
//  for supporting third-party cd-keys, or other proof-of-purchase systems.
// -----------------------------------------------------------------------------
#define k_iCallbback_AppProofOfPurchaseKeyResponse_t ((Int32)(k_iSteamAppsCallbacks + 2))
typedef struct _AppProofOfPurchaseKeyResponse_t_ {

	EResult eResult;
	Uint32 iAppId;
	Uint32 cchKeyLength;
	CharA chKey[k_cchAppProofOfPurchaseKeyMax];

} AppProofOfPurchaseKeyResponse_t, *pAppProofOfPurchaseKeyResponse_t;

// -----------------------------------------------------------------------------
// Purpose: Response to GetFileDetails
// -----------------------------------------------------------------------------
#define k_iCallbback_FileDetailsResult_t ((Int32)(k_iSteamAppsCallbacks + 23))
typedef struct _FileDetailsResult_t {

	EResult eResult;
	Uint64 FileSize;
	Uint8 FileSHA1[20];
	Uint32 nFlags;

} FileDetailsResult_t, *pFileDetailsResult_t;

// -----------------------------------------------------------------------------
// Purpose: Called in Timed Trial mode
// -----------------------------------------------------------------------------
#define k_iCallbback_TimedTrialStatus_t ((Int32)(k_iSteamAppsCallbacks + 30))
typedef struct _TimedTrialStatus_t_ {

	AppId_t iAppId;
	Bool bIsOffline;
	Uint32 nSecondsAllowed;
	Uint32 nSecondsPlayed;

} TimedTrialStatus_t, *pTimedTrialStatus_t;

#pragma pack(pop)

#endif // _ISTEAMAPPS_
