#ifndef _STEAMAPPS_
#define _STEAMAPPS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamApps.h"
// -----------------------------------------------------------------------------

typedef class _SteamApps_ : public _ISteamApps001_,
 public _ISteamApps002_, public _ISteamApps003_,
 public _ISteamApps004_, public _ISteamApps005_,
 public _ISteamApps006_, public _ISteamApps007_,
 public _ISteamApps_ {
public:

	_SteamApps_() = default;
	_SteamApps_(const _SteamApps_&) = delete;
	_SteamApps_& operator=(const _SteamApps_&) = delete;

	Int32 GetAppData(AppId_t iAppId, pCStrA pchKey, pStrA pchValue, Int32 cchValueMax) override;

	Bool BIsSubscribed() override;
	Bool BIsLowViolence() override;
	Bool BIsCybercafe() override;
	Bool BIsVACBanned() override;

	pCStrA GetCurrentGameLanguage() override;
	pCStrA GetAvailableGameLanguages() override;

	/* Only use this member if you need to check ownership of another game related to yours */
	Bool BIsSubscribedApp(AppId_t iAppId) override;
	/* Takes AppId of DLC and checks if the user owns the DLC */
	Bool BIsDlcInstalled(AppId_t iAppId) override;

	/* Returns the Unix Time of the purchase of the app */
	Uint32 GetEarliestPurchaseUnixTime(AppId_t iAppId) override;

	/* Checks if the user is subscribed to the current app through a free weekend
		This function will return false for users who have a retail or other type of license
		 before using, please ask your Valve technical contact how to package and secure your free weekened */
	Bool BIsSubscribedFromFreeWeekend() override;

	/* Returns the number of DLC pieces for the running app */
	Int32 GetDLCCount() override;

	/* Returns metadata for DLC by index, of range [0, GetDLCCount()] */
	Bool BGetDLCDataByIndex(Int32 iDLC, pAppId_t pnAppId, pBool pbAvailable, pStrA pchName, Int32 cchNameMax) override;

	void InstallDLC(AppId_t iAppId) override;
	void UninstallDLC(AppId_t iAppId) override;

	/* Request legacy cd-key for yourself or owned DLC. If you are interested in this
		data then make sure you provide us with a list of valid keys to be distributed
		to users when they purchase the game, before the game ships.
		You'll receive an AppProofOfPurchaseKeyResponse_t callback when
		 the key is available (which may be immediately) */
	void RequestAppProofOfPurchaseKey(AppId_t iAppId) override;

	/* Returns current beta branch name, 'public' is the default branch */
	Bool GetCurrentBetaName(pStrA pchName, Int32 cchNameMax) override;
	Bool MarkContentCorrupt(Bool bMissingFilesOnly) override;
	Uint32 GetInstalledDepots(AppId_t iAppId, pDepotId_t pnDepotId, Uint32 nDepotId) override;
	Uint32 GetAppInstallDir(AppId_t iAppId, pStrA pchFolder, Uint32 cchFolderMax) override;
	Bool BIsAppInstalled(AppId_t iAppId) override;
	SteamId_t GetAppOwner() override;

	/* Returns the associated launch param if the game is run via steam://run/<iAppId>//?param1=value1&param2=value2&param3=value3 etc.
	   Parameter names starting with the character '@' are reserved for internal use and will always return and empty string.
	   Parameter names starting with an underscore '_' are reserved for steam features -- they can be queried by the game,
		but it is advised that you not param names beginning with an underscore for your own features.
	   Check for new launch parameters on callback NewUrlLaunchParameters_t */
	pCStrA GetLaunchQueryParam(pCStrA pchKey) override;

	Bool GetDlcDownloadProgress(AppId_t iAppId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) override;
	Int32 GetAppBuildId() override;
	void RequestAllProofOfPurchaseKeys() override;
	SteamAPICall_t GetFileDetails(pCStrA pchFileName) override;
	Int32 GetLaunchCommandLine(pStrA pchCommandLine, Int32 cchCommandLine) override;
	Bool BIsSubscribedFromFamilySharing() override;
	Bool BIsTimedTrial(pUint32 pnSecondsAllowed, pUint32 pnSecondsPlayed) override;
	Bool SetDlcContext(AppId_t iAppId) override;
	
	~_SteamApps_() = default;

} SteamApps, *pSteamApps;

#endif // !_STEAMAPPS_
