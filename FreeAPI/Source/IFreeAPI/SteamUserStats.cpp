// -----------------------------------------------------------------------------
#include "SteamUserStats.h"
// -----------------------------------------------------------------------------

Uint32 _SteamUserStats_::GetNumStats(GameId_t GameId) {
	DEBUGBREAK("ISteamUserStats::GetNumStats");

	return 0U;

}

pCStrA _SteamUserStats_::GetStatName(GameId_t GameId, Uint32 iStat) {
	DEBUGBREAK("ISteamUserStats::GetStatName");

	return (pCStrA)(
		""
	);

}

ESteamUserStatType _SteamUserStats_::GetStatType(GameId_t GameId, pCStrA pchName) {
	DEBUGBREAK("ISteamUserStats::GetStatType");

	return k_ESteamUserStatTypeINVALID;

}

Uint32 _SteamUserStats_::GetNumAchievements(GameId_t GameId) {
	DEBUGBREAK("ISteamUserStats::GetNumAchievements");

	return 0U;

}

pCStrA _SteamUserStats_::GetAchievementName(GameId_t GameId, Uint32 iAchievement) {
	DEBUGBREAK("ISteamUserStats::GetAchievementName");

	return (pCStrA)(
		""
	);

}

Uint32 _SteamUserStats_::GetNumGroupAchievements(GameId_t GameId) {
	DEBUGBREAK("ISteamUserStats::GetNumGroupAchievements");

	return 0U;

}

pCStrA _SteamUserStats_::GetGroupAchievementName(GameId_t GameId, Uint32 iAchievement) {
	DEBUGBREAK("ISteamUserStats::GetGroupAchievementName");

	return (pCStrA)(
		""
	);

}

Bool _SteamUserStats_::RequestCurrentStats() {
	DEBUGBREAK("ISteamUserStats::RequestCurrentStats");

	return True;

}

Bool _SteamUserStats_::GetStat(pCStrA pchName, pInt32 pData) {
	DEBUGBREAK("ISteamUserStats::GetStat");

	return False;

}

Bool _SteamUserStats_::GetStat(pCStrA pchName, pFloat pData) {
	DEBUGBREAK("ISteamUserStats::GetStat");

	return False;

}

Bool _SteamUserStats_::SetStat(pCStrA pchName, Int32 Data) {
	DEBUGBREAK("ISteamUserStats::SetStat");

	return False;

}

Bool _SteamUserStats_::SetStat(pCStrA pchName, Float Data) {
	DEBUGBREAK("ISteamUserStats::SetStat");

	return False;

}

Bool _SteamUserStats_::UpdateAvgRateStat(pCStrA pchName, Float CountThisSession, Double SessionLength) {
	DEBUGBREAK("ISteamUserStats::UpdateAvgRateStat");

	return False;

}

Bool _SteamUserStats_::GetAchievement(pCStrA pchName, pBool pbAchieved) {
	DEBUGBREAK("ISteamUserStats::GetAchievement");

	return False;

}

Bool _SteamUserStats_::GetGroupAchievement(GameId_t GameId, pCStrA pchName, pBool pbAchieved) {
	DEBUGBREAK("ISteamUserStats::GetGroupAchievement");

	return False;

}

Bool _SteamUserStats_::SetAchievement(pCStrA pchName) {
	DEBUGBREAK("ISteamUserStats::SetAchievement");

	return False;

}

Bool _SteamUserStats_::SetGroupAchievement(GameId_t GameId, pCStrA pchName) {
	DEBUGBREAK("ISteamUserStats::SetGroupAchievement");

	return False;

}

Bool _SteamUserStats_::ClearAchievement(pCStrA pchName) {
	DEBUGBREAK("ISteamUserStats::ClearAchievement");

	return True;

}

Bool _SteamUserStats_::ClearGroupAchievement(GameId_t GameId, pCStrA pchName) {
	DEBUGBREAK("ISteamUserStats::ClearGroupAchievement");

	return False;

}

Bool _SteamUserStats_::GetAchievementAndUnlockTime(pCStrA pchName, pBool pbAchieved, pUint32 pnUnlockTime) {
	DEBUGBREAK("ISteamUserStats::GetAchievementAndUnlockTime");

	return False;

}

Bool _SteamUserStats_::StoreStats() {
	DEBUGBREAK("ISteamUserStats::StoreStats");

	return True;

}

Int32 _SteamUserStats_::GetAchievementIcon(pCStrA pchName) {
	DEBUGBREAK("ISteamUserStats::GetAchievementIcon");

	return 0;

}

pCStrA _SteamUserStats_::GetAchievementDisplayAttribute(pCStrA pchName, pCStrA pchKey) {
	DEBUGBREAK("ISteamUserStats::GetAchievementDisplayAttribute");

	return (pCStrA)(
		"0"
	);

}

Bool _SteamUserStats_::IndicateAchievementProgress(pCStrA pchName, Uint32 nCurProgress, Uint32 nMaxProgress) {
	DEBUGBREAK("ISteamUserStats::IndicateAchievementProgress");

	return False;

}

Uint32 _SteamUserStats_::GetNumAchievements() {
	DEBUGBREAK("ISteamUserStats::GetNumAchievements");

	return 0U;

}

pCStrA _SteamUserStats_::GetAchievementName(Uint32 iAchievement) {
	DEBUGBREAK("ISteamUserStats::GetAchievementName");

	return (pCStrA)(
		""
	);

}

SteamAPICall_t _SteamUserStats_::RequestUserStats(SteamId_t SteamIdUser) {
	DEBUGBREAK("ISteamUserStats::RequestUserStats");

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pInt32 pData) {
	DEBUGBREAK("ISteamUserStats::GetUserStat");

	return False;

}

Bool _SteamUserStats_::GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pFloat pData) {
	DEBUGBREAK("ISteamUserStats::GetUserStat");

	return False;

}

Bool _SteamUserStats_::GetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved) {
	DEBUGBREAK("ISteamUserStats::GetUserAchievement");

	return False;

}

Bool _SteamUserStats_::GetUserAchievementAndUnlockTime(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved, pUint32 punUnlockTime) {
	DEBUGBREAK("ISteamUserStats::GetUserAchievementAndUnlockTime");

	return False;

}

Bool _SteamUserStats_::ResetAllStats(Bool bAchievementsToo) {
	DEBUGBREAK("ISteamUserStats::ResetAllStats");

	return True;

}

SteamAPICall_t _SteamUserStats_::FindOrCreateLeaderboard(pCStrA pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType) {
	DEBUGBREAK("ISteamUserStats::FindOrCreateLeaderboard");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::FindLeaderboard(pCStrA pchLeaderboardName) {
	DEBUGBREAK("ISteamUserStats::FindLeaderboard");

	return k_SteamAPICall_Invalid;

}

pCStrA _SteamUserStats_::GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("ISteamUserStats::GetLeaderboardName");

	return (pCStrA)(
		""
	);

}

Int32 _SteamUserStats_::GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("ISteamUserStats::GetLeaderboardEntryCount");

	return 0;

}

ELeaderboardSortMethod _SteamUserStats_::GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("ISteamUserStats::GetLeaderboardSortMethod");

	return k_ELeaderboardSortMethodNone;

}

ELeaderboardDisplayType _SteamUserStats_::GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("ISteamUserStats::GetLeaderboardDisplayType");

	return k_ELeaderboardDisplayTypeNone;

}

SteamAPICall_t _SteamUserStats_::DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, Int32 nRangeStart, Int32 nRangeEnd) {
	DEBUGBREAK("ISteamUserStats::DownloadLeaderboardEntries");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, pSteamId_t prgUsers, Int32 cUsers) {
	DEBUGBREAK("ISteamUserStats::DownloadLeaderboardEntriesForUsers");

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, Int32 index, pLeaderboardEntry_t pLeaderboardEntry, pInt32 pDetails, Int32 cDetailsMax) {
	DEBUGBREAK("ISteamUserStats::GetDownloadedLeaderboardEntry");

	return False;

}

SteamAPICall_t _SteamUserStats_::UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, Int32 nScore, const pInt32 pScoreDetails, Int32 cScoreDetailsCount) {
	DEBUGBREAK("ISteamUserStats::UploadLeaderboardScore");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC) {
	DEBUGBREAK("ISteamUserStats::AttachLeaderboardUGC");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::GetNumberOfCurrentPlayers() {
	DEBUGBREAK("ISteamUserStats::GetNumberOfCurrentPlayers");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::RequestGlobalAchievementPercentages() {
	DEBUGBREAK("ISteamUserStats::RequestGlobalAchievementPercentages");

	return k_SteamAPICall_Invalid;

}

Int32 _SteamUserStats_::GetMostAchievedAchievementInfo(pStrA pchName, Uint32 cchNameLen, pFloat pPercent, pBool pbAchieved) {
	DEBUGBREAK("ISteamUserStats::GetMostAchievedAchievementInfo");

	return 0;
}

Int32 _SteamUserStats_::GetNextMostAchievedAchievementInfo(Int32 iIteratorPrevious, pStrA pchName, Uint32 cchName, pFloat pPercent, pBool pbAchieved) {
	DEBUGBREAK("ISteamUserStats::GetNextMostAchievedAchievementInfo");

	return 0;

}

Bool _SteamUserStats_::GetAchievementAchievedPercent(pCStrA pchName, pFloat pPercent) {
	DEBUGBREAK("ISteamUserStats::GetAchievementAchievedPercent");

	return False;

}

SteamAPICall_t _SteamUserStats_::RequestGlobalStats(Int32 nHistoryDays) {
	DEBUGBREAK("ISteamUserStats::RequestGlobalStats");

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetGlobalStat(pCStrA pchStatName, pInt64 pData) {
	DEBUGBREAK("ISteamUserStats::GetGlobalStat");

	return False;

}

Bool _SteamUserStats_::GetGlobalStat(pCStrA pchStatName, pDouble pData) {
	DEBUGBREAK("ISteamUserStats::GetGlobalStat");

	return False;

}

Int32 _SteamUserStats_::GetGlobalStatHistory(pCStrA pchStatName, pInt64 pData, Uint32 cbData) {
	DEBUGBREAK("ISteamUserStats::GetGlobalStatHistory");

	return 0;

}

Int32 _SteamUserStats_::GetGlobalStatHistory(pCStrA pchStatName, pDouble pData, Uint32 cbData) {
	DEBUGBREAK("ISteamUserStats::GetGlobalStatHistory");

	return 0;

}

#ifdef _PS3
Bool _SteamUserStats_::InstallPS3Trophies() {
	DEBUGBREAK("ISteamUserStats::InstallPS3Trophies");

	return True;

}

Uint64 _SteamUserStats_::GetTrophySpaceRequiredBeforeInstall() {
	DEBUGBREAK("ISteamUserStats::GetTrophySpaceRequiredBeforeInstall");

	return Uint64_MAX;

}

Bool _SteamUserStats_::SetUserStatsData(const pVoid pvData, Uint32 cbData) {
	DEBUGBREAK("ISteamUserStats::SetUserStatsData");

	return False;

}

Bool _SteamUserStats_::GetUserStatsData(pVoid pvData, Uint32 cbData, pUint32 pcbWritten) {
	DEBUGBREAK("ISteamUserStats::GetUserStatsData");

	return False;

}

#endif

Bool _SteamUserStats_::GetAchievementProgressLimits(pCStrA pchName, pInt32 pProgressMin, pInt32 pProgressMax) {
	DEBUGBREAK("ISteamUserStats::GetAchievementProgressLimits");

	return False;

}

Bool _SteamUserStats_::GetAchievementProgressLimits(pCStrA pchName, pFloat pProgressMin, pFloat pProgressMax) {
	DEBUGBREAK("ISteamUserStats::GetAchievementProgressLimits");

	return False;

}
