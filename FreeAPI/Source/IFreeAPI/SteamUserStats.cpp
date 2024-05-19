// -----------------------------------------------------------------------------
#include "SteamUserStats.h"
// -----------------------------------------------------------------------------

Bool _SteamUserStats_::RequestCurrentStats() {

	return True;

}

Bool _SteamUserStats_::GetStat(const pStrA pchName, pInt32 pData) {

	return False;

}

Bool _SteamUserStats_::GetStat(const pStrA pchName, pFloat pData) {

	return False;

}

Bool _SteamUserStats_::SetStat(const pStrA pchName, Int32 Data) {

	return False;

}

Bool _SteamUserStats_::SetStat(const pStrA pchName, Float Data) {

	return False;

}

Bool _SteamUserStats_::UpdateAvgRateStat(const pStrA pchName, Float CountThisSession, Double SessionLength) {

	return False;

}

Bool _SteamUserStats_::GetAchievement(const pStrA pchName, pBool pbAchieved) {

	return False;

}

Bool _SteamUserStats_::SetAchievement(const pStrA pchName) {

	return False;

}

Bool _SteamUserStats_::ClearAchievement(const pStrA pchName) {

	return True;

}

Bool _SteamUserStats_::GetAchievementAndUnlockTime(const pStrA pchName, pBool pbAchieved, pUint32 pnUnlockTime) {

	return False;

}

Bool _SteamUserStats_::StoreStats() {

	return True;

}

Int32 _SteamUserStats_::GetAchievementIcon(const pStrA pchName) {

	return 0;

}

const pStrA _SteamUserStats_::GetAchievementDisplayAttribute(const pStrA pchName, const pStrA pchKey) {

	return (const pStrA)(
		"0"
	);

}

Bool _SteamUserStats_::IndicateAchievementProgress(const pStrA pchName, Uint32 nCurProgress, Uint32 nMaxProgress) {

	return False;

}

Uint32 _SteamUserStats_::GetNumAchievements() {

	return 0U;

}

const pStrA _SteamUserStats_::GetAchievementName(Uint32 iAchievement) {

	return (const pStrA)(
		""
	);

}

SteamAPICall_t _SteamUserStats_::RequestUserStats(SteamId_t SteamIdUser) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetUserStat(SteamId_t SteamIdUser, const pStrA pchName, pInt32 pData) {

	return False;

}

Bool _SteamUserStats_::GetUserStat(SteamId_t SteamIdUser, const pStrA pchName, pFloat pData) {

	return False;

}

Bool _SteamUserStats_::GetUserAchievement(SteamId_t SteamIdUser, const pStrA pchName, pBool pbAchieved) {

	return False;

}

Bool _SteamUserStats_::GetUserAchievementAndUnlockTime(SteamId_t SteamIdUser, const pStrA pchName, pBool pbAchieved, pUint32 punUnlockTime) {

	return False;

}

Bool _SteamUserStats_::ResetAllStats(Bool bAchievementsToo) {

	return True;

}

SteamAPICall_t _SteamUserStats_::FindOrCreateLeaderboard(const pStrA pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::FindLeaderboard(const pStrA pchLeaderboardName) {

	return k_SteamAPICall_Invalid;

}

const pStrA _SteamUserStats_::GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard) {

	return (const pStrA)(
		""
	);

}

Int32 _SteamUserStats_::GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard) {

	return 0;

}

ELeaderboardSortMethod _SteamUserStats_::GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard) {

	return k_ELeaderboardSortMethodNone;

}

ELeaderboardDisplayType _SteamUserStats_::GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard) {

	return k_ELeaderboardDisplayTypeNone;

}

SteamAPICall_t _SteamUserStats_::DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, Int32 nRangeStart, Int32 nRangeEnd) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, pSteamId_t prgUsers, Int32 cUsers) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, Int32 index, pLeaderboardEntry_t pLeaderboardEntry, pInt32 pDetails, Int32 cDetailsMax) {

	return False;

}

SteamAPICall_t _SteamUserStats_::UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, Int32 nScore, const pInt32 pScoreDetails, Int32 cScoreDetailsCount) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::GetNumberOfCurrentPlayers() {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::RequestGlobalAchievementPercentages() {

	return k_SteamAPICall_Invalid;

}

Int32 _SteamUserStats_::GetMostAchievedAchievementInfo(pStrA pchName, Uint32 cchNameLen, pFloat pPercent, pBool pbAchieved) {

	return 0;
}

Int32 _SteamUserStats_::GetNextMostAchievedAchievementInfo(Int32 iIteratorPrevious, pStrA pchName, Uint32 cchName, pFloat pPercent, pBool pbAchieved) {

	return 0;

}

Bool _SteamUserStats_::GetAchievementAchievedPercent(const pStrA pchName, pFloat pPercent) {

	return False;

}

SteamAPICall_t _SteamUserStats_::RequestGlobalStats(Int32 nHistoryDays) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetGlobalStat(const pStrA pchStatName, pInt64 pData) {

	return False;

}

Bool _SteamUserStats_::GetGlobalStat(const pStrA pchStatName, pDouble pData) {

	return False;

}

Int32 _SteamUserStats_::GetGlobalStatHistory(const pStrA pchStatName, pInt64 pData, Uint32 cbData) {

	return 0;

}

Int32 _SteamUserStats_::GetGlobalStatHistory(const pStrA pchStatName, pDouble pData, Uint32 cbData) {

	return 0;

}

Bool _SteamUserStats_::GetAchievementProgressLimits(const pStrA pchName, pInt32 pProgressMin, pInt32 pProgressMax) {

	return False;

}

Bool _SteamUserStats_::GetAchievementProgressLimits(const pStrA pchName, pFloat pProgressMin, pFloat pProgressMax) {

	return False;

}
