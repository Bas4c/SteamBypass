// -----------------------------------------------------------------------------
#include "SteamUserStats.h"
// -----------------------------------------------------------------------------

Bool _SteamUserStats_::RequestCurrentStats() {

	return True;

}

Bool _SteamUserStats_::GetStat(pCStrA pchName, pInt32 pData) {

	return False;

}

Bool _SteamUserStats_::GetStat(pCStrA pchName, pFloat pData) {

	return False;

}

Bool _SteamUserStats_::SetStat(pCStrA pchName, Int32 Data) {

	return False;

}

Bool _SteamUserStats_::SetStat(pCStrA pchName, Float Data) {

	return False;

}

Bool _SteamUserStats_::UpdateAvgRateStat(pCStrA pchName, Float CountThisSession, Double SessionLength) {

	return False;

}

Bool _SteamUserStats_::GetAchievement(pCStrA pchName, pBool pbAchieved) {

	return False;

}

Bool _SteamUserStats_::SetAchievement(pCStrA pchName) {

	return False;

}

Bool _SteamUserStats_::ClearAchievement(pCStrA pchName) {

	return True;

}

Bool _SteamUserStats_::GetAchievementAndUnlockTime(pCStrA pchName, pBool pbAchieved, pUint32 pnUnlockTime) {

	return False;

}

Bool _SteamUserStats_::StoreStats() {

	return True;

}

Int32 _SteamUserStats_::GetAchievementIcon(pCStrA pchName) {

	return 0;

}

pCStrA _SteamUserStats_::GetAchievementDisplayAttribute(pCStrA pchName, pCStrA pchKey) {

	return (pCStrA)(
		"0"
	);

}

Bool _SteamUserStats_::IndicateAchievementProgress(pCStrA pchName, Uint32 nCurProgress, Uint32 nMaxProgress) {

	return False;

}

Uint32 _SteamUserStats_::GetNumAchievements() {

	return 0U;

}

pCStrA _SteamUserStats_::GetAchievementName(Uint32 iAchievement) {

	return (pCStrA)(
		""
	);

}

SteamAPICall_t _SteamUserStats_::RequestUserStats(SteamId_t SteamIdUser) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pInt32 pData) {

	return False;

}

Bool _SteamUserStats_::GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pFloat pData) {

	return False;

}

Bool _SteamUserStats_::GetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved) {

	return False;

}

Bool _SteamUserStats_::GetUserAchievementAndUnlockTime(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved, pUint32 punUnlockTime) {

	return False;

}

Bool _SteamUserStats_::ResetAllStats(Bool bAchievementsToo) {

	return True;

}

SteamAPICall_t _SteamUserStats_::FindOrCreateLeaderboard(pCStrA pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUserStats_::FindLeaderboard(pCStrA pchLeaderboardName) {

	return k_SteamAPICall_Invalid;

}

pCStrA _SteamUserStats_::GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard) {

	return (pCStrA)(
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

Bool _SteamUserStats_::GetAchievementAchievedPercent(pCStrA pchName, pFloat pPercent) {

	return False;

}

SteamAPICall_t _SteamUserStats_::RequestGlobalStats(Int32 nHistoryDays) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamUserStats_::GetGlobalStat(pCStrA pchStatName, pInt64 pData) {

	return False;

}

Bool _SteamUserStats_::GetGlobalStat(pCStrA pchStatName, pDouble pData) {

	return False;

}

Int32 _SteamUserStats_::GetGlobalStatHistory(pCStrA pchStatName, pInt64 pData, Uint32 cbData) {

	return 0;

}

Int32 _SteamUserStats_::GetGlobalStatHistory(pCStrA pchStatName, pDouble pData, Uint32 cbData) {

	return 0;

}

Bool _SteamUserStats_::GetAchievementProgressLimits(pCStrA pchName, pInt32 pProgressMin, pInt32 pProgressMax) {

	return False;

}

Bool _SteamUserStats_::GetAchievementProgressLimits(pCStrA pchName, pFloat pProgressMin, pFloat pProgressMax) {

	return False;

}
