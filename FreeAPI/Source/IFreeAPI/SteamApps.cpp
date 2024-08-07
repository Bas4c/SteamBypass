// -----------------------------------------------------------------------------
#include "SteamApps.h"
// -----------------------------------------------------------------------------

Int32 _SteamApps_::GetAppData(AppId_t iAppId, pCStrA pchKey, pStrA pchValue, Int32 cchValueMax) {
	DEBUGBREAK("ISteamApps::GetAppData");

	return 0;

}

Bool _SteamApps_::BIsSubscribed() {
	DEBUGBREAK("ISteamApps::BIsSubscribed");

	return True;

}

Bool _SteamApps_::BIsLowViolence() {
	DEBUGBREAK("ISteamApps::BIsLowViolence");

	return False;

}

Bool _SteamApps_::BIsCybercafe() {
	DEBUGBREAK("ISteamApps::BIsCybercafe");

	return False;

}

Bool _SteamApps_::BIsVACBanned() {
	DEBUGBREAK("ISteamApps::BIsVACBanned");

	return False;

}

pCStrA _SteamApps_::GetCurrentGameLanguage() {
	DEBUGBREAK("ISteamApps::GetCurrentGameLanguage");

	return (pCStrA)(g_chLanguage);

}

pCStrA _SteamApps_::GetAvailableGameLanguages() {
	DEBUGBREAK("ISteamApps::GetAvailableGameLanguages");

	return (pCStrA)(g_chLanguage);

}

Bool _SteamApps_::BIsSubscribedApp(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::BIsSubscribedApp");

	return True;

}

Bool _SteamApps_::BIsDlcInstalled(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::BIsDlcInstalled");

	return True;

}

Uint32 _SteamApps_::GetEarliestPurchaseUnixTime(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::GetEarliestPurchaseUnixTime");

	/* January 1, 1970 (start of Unix epoch) in "ticks" */
	const Int64 UnixTimeStart = 0x019DB1DED53E8000;

	Uint64 UTCTime = 0U;
	GetSystemTimeAsFileTime((LPFILETIME)(&UTCTime));

	return (Uint32)((UTCTime - UnixTimeStart) / 10000000);

}

Bool _SteamApps_::BIsSubscribedFromFreeWeekend() {
	DEBUGBREAK("ISteamApps::BIsSubscribedFromFreeWeekend");

	return False;

}

Int32 _SteamApps_::GetDLCCount() {
	DEBUGBREAK("ISteamApps::GetDLCCount");

	return Int32_MAX;

}

Bool _SteamApps_::BGetDLCDataByIndex(Int32 iDLC, pAppId_t pnAppId, pBool pbAvailable, pStrA pchName, Int32 cchNameMax) {
	DEBUGBREAK("ISteamApps::BGetDLCDataByIndex");

	return False;

}

void _SteamApps_::InstallDLC(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::InstallDLC");

	/* Empty Method */

}

void _SteamApps_::UninstallDLC(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::UninstallDLC");

	/* Empty Method */

}

void _SteamApps_::RequestAppProofOfPurchaseKey(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::RequestAppProofOfPurchaseKey");

	/* Empty Method */

}

Bool _SteamApps_::GetCurrentBetaName(pStrA pchName, Int32 cchNameMax) {
	DEBUGBREAK("ISteamApps::GetCurrentBetaName");

	pCStrA pchBetaName = (pCStrA)("public");
	if (pchName != NULL && cchNameMax > 0) {
		if ((SizeOF)(cchNameMax) >= StrA_Count(pchBetaName) + 1U) {
			StrA_Copy(pchName, cchNameMax, pchBetaName);
			return True;
		}
	}

	return False;

}

Bool _SteamApps_::MarkContentCorrupt(Bool bMissingFilesOnly) {
	DEBUGBREAK("ISteamApps::MarkContentCorrupt");

	return False;

}

Uint32 _SteamApps_::GetInstalledDepots(AppId_t iAppId, pDepotId_t pnDepotId, Uint32 nDepotId) {
	DEBUGBREAK("ISteamApps::GetInstalledDepots");

	return 0U;

}

Uint32 _SteamApps_::GetAppInstallDir(AppId_t iAppId, pStrA pchFolder, Uint32 cchFolderMax) {
	DEBUGBREAK("ISteamApps::GetAppInstallDir");

	Uint32 cchCopied = 0U;

	if (iAppId == (AppId_t)(GetGameAppId())) {
		if (pchFolder != NULL && cchFolderMax > 0) {

			pStrA pchModuleDirectory =
				LoadModuleNameA(GetModuleHandleA(NULL), True);

			if (pchModuleDirectory != NULL) {

				if ((SizeOF)(cchFolderMax) >= StrA_Count(pchModuleDirectory) + 1U) {
					StrA_Copy(pchFolder, cchFolderMax, pchModuleDirectory);
					cchCopied = (Uint32)(StrA_Count(pchModuleDirectory) + 1U);
				}

				LocalFree(pchModuleDirectory);

			}

		}
	}

	return cchCopied;

}

Bool _SteamApps_::BIsAppInstalled(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::BIsAppInstalled");

	if (iAppId == (AppId_t)(GetGameAppId())) {
		return True;
	}

	return False;

}

SteamId_t _SteamApps_::GetAppOwner() {
	DEBUGBREAK("ISteamApps::GetAppOwner");

	return SteamId_t{ g_SteamId_Uint64 };

}

pCStrA _SteamApps_::GetLaunchQueryParam(pCStrA pchKey) {
	DEBUGBREAK("ISteamApps::GetLaunchQueryParam");

	return (pCStrA)(
		""
	);

}

Bool _SteamApps_::GetDlcDownloadProgress(AppId_t iAppId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) {
	DEBUGBREAK("ISteamApps::GetDlcDownloadProgress");

	if (pnBytesDownloaded != NULL) {
		*pnBytesDownloaded = 1000ULL;
	}

	if (pnBytesTotal != NULL) {
		*pnBytesTotal = 1000ULL;
	}

	return True;

}

Int32 _SteamApps_::GetAppBuildId() {
	DEBUGBREAK("ISteamApps::GetAppBuildId");

	return 1;

}

void _SteamApps_::RequestAllProofOfPurchaseKeys() {
	DEBUGBREAK("ISteamApps::RequestAllProofOfPurchaseKeys");

	/* Empty Method */

}

SteamAPICall_t _SteamApps_::GetFileDetails(pCStrA pchFileName) {
	DEBUGBREAK("ISteamApps::GetFileDetails");

	return k_SteamAPICall_Invalid;

}

Int32 _SteamApps_::GetLaunchCommandLine(pStrA pchCommandLine, Int32 cchCommandLine) {
	DEBUGBREAK("ISteamApps::GetLaunchCommandLine");

	pStrA pchCmdLine = GetCommandLineA();
	if (pchCommandLine != NULL && cchCommandLine > 0) {
		if ((SizeOF)(cchCommandLine) >= StrA_Count(pchCmdLine) + 1U) {
			StrA_Copy(pchCommandLine, cchCommandLine, pchCmdLine);
			return (Int32)(StrA_Count(pchCmdLine) + 1U);
		}
	}

	return 0U;

}

Bool _SteamApps_::BIsSubscribedFromFamilySharing() {
	DEBUGBREAK("ISteamApps::BIsSubscribedFromFamilySharing");

	return False;

}

Bool _SteamApps_::BIsTimedTrial(pUint32 pnSecondsAllowed, pUint32 pnSecondsPlayed) {
	DEBUGBREAK("ISteamApps::BIsTimedTrial");

	if (pnSecondsAllowed != NULL) {
		*pnSecondsAllowed = Uint32_MAX;
	}

	if (pnSecondsPlayed != NULL) {
		*pnSecondsPlayed = 0U;
	}

	return False;

}

Bool _SteamApps_::SetDlcContext(AppId_t iAppId) {
	DEBUGBREAK("ISteamApps::SetDlcContext");

	return True;

}

#ifdef _PS3
SteamAPICall_t _SteamApps_::RegisterActivationCode(pCStrA pchActivationCode) {
	DEBUGBREAK("ISteamApps::RegisterActivationCode");

	return k_SteamAPICall_Invalid;

}
#endif
