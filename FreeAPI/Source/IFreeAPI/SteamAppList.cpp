// -----------------------------------------------------------------------------
#include "SteamAppList.h"
// -----------------------------------------------------------------------------

Uint32 _SteamAppList_::GetNumInstalledApps() {
	DEBUGBREAK("ISteamAppList::GetNumInstalledApps");

	return 1U;

}

Uint32 _SteamAppList_::GetInstalledApps(pAppId_t pnAppId, Uint32 nAppId) {
	DEBUGBREAK("ISteamAppList::GetInstalledApps");

	if (pnAppId != NULL && nAppId != 0) {
		pnAppId[0] = (AppId_t)(GetGameAppId());
		return 1U;
	}

	return 0U;

}

Int32 _SteamAppList_::GetAppName(AppId_t iAppId, pStrA pchName, Int32 cchNameMax) {
	DEBUGBREAK("ISteamAppList::GetAppName");

	Int32 cchCopied = (-1);

	if (iAppId == (AppId_t)(GetGameAppId())) {
		if (pchName != NULL && cchNameMax > 0) {

			pStrA pchModuleDirectory =
				LoadModuleNameA(GetModuleHandleA(NULL), False);

			if (pchModuleDirectory != NULL) {

				SizeOF cchModuleDirectory =
					StrA_Count(pchModuleDirectory);

				while (cchModuleDirectory != 0) {

					if (
						pchModuleDirectory[cchModuleDirectory - 1] == '\\' ||
						pchModuleDirectory[cchModuleDirectory - 1] == '/'
					) {
						cchModuleDirectory--;
						break;
					}

					cchModuleDirectory--;

				}

				if ((SizeOF)(cchNameMax) >= StrA_Count(pchModuleDirectory + cchModuleDirectory + 1U) + 1U) {
					StrA_Copy(pchName, cchNameMax, pchModuleDirectory + cchModuleDirectory + 1U);
					cchCopied = (Int32)(StrA_Count(pchModuleDirectory + cchModuleDirectory + 1U) + 1U);
				}

				LocalFree(pchModuleDirectory);

			}

		}
	}

	return cchCopied;

}

Int32 _SteamAppList_::GetAppInstallDir(AppId_t iAppId, pStrA pchDirectory, Int32 cchNameMax) {
	DEBUGBREAK("ISteamAppList::GetAppInstallDir");

	Int32 cchCopied = (-1);

	if (iAppId == (AppId_t)(GetGameAppId())) {
		if (pchDirectory != NULL && cchNameMax > 0) {

			pStrA pchModuleDirectory =
				LoadModuleNameA(GetModuleHandleA(NULL), True);
			
			if (pchModuleDirectory != NULL) {

				if ((SizeOF)(cchNameMax) >= StrA_Count(pchModuleDirectory) + 1U) {
					StrA_Copy(pchDirectory, cchNameMax, pchModuleDirectory);
					cchCopied = (Int32)(StrA_Count(pchModuleDirectory) + 1U);
				}

				LocalFree(pchModuleDirectory);

			}

		}
	}

	return cchCopied;

}

Int32 _SteamAppList_::GetAppBuildId(AppId_t iAppId) {
	DEBUGBREAK("ISteamAppList::GetAppBuildId");

	return 1;

}
