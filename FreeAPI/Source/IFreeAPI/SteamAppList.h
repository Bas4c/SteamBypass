#ifndef _STEAMAPPLIST_
#define _STEAMAPPLIST_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamAppList.h"
// -----------------------------------------------------------------------------

typedef class _SteamAppList_ : public _ISteamAppList_ {
public:

	_SteamAppList_() = default;
	_SteamAppList_(const _SteamAppList_&) = delete;
	_SteamAppList_& operator=(const _SteamAppList_&) = delete;

	Uint32 GetNumInstalledApps() override;
	Uint32 GetInstalledApps(pAppId_t pnAppId, Uint32 nAppId) override;
	/* Returns (-1): Name not Found */
	Int32 GetAppName(AppId_t iAppId, pStrA pchName, Int32 cchNameMax) override;
	/* Returns (-1): Install Directory not Found */
	Int32 GetAppInstallDir(AppId_t iAppId, pStrA pchDirectory, Int32 cchNameMax) override;
	/* Returns games current BuildId */
	Int32 GetAppBuildId(AppId_t iAppId) override;

	~_SteamAppList_() = default;

} SteamAppList, *pSteamAppList;

#endif // !_STEAMAPPLIST_
