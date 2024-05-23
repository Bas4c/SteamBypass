#ifndef _STEAMUSERSTATS_
#define _STEAMUSERSTATS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamUserStats.h"
// -----------------------------------------------------------------------------

typedef class _SteamUserStats_ : public _ISteamUserStats_ {
public:

	_SteamUserStats_() = default;
	_SteamUserStats_(const _SteamUserStats_&) = delete;
	_SteamUserStats_& operator=(const _SteamUserStats_&) = delete;

	/* Result in UserStatsReceived_t */
	Bool RequestCurrentStats() override;
	Bool GetStat(pCStrA pchName, pInt32 pData) override;
	Bool GetStat(pCStrA pchName, pFloat pData) override;
	Bool SetStat(pCStrA pchName, Int32 Data) override;
	Bool SetStat(pCStrA pchName, Float Data) override;
	Bool UpdateAvgRateStat(pCStrA pchName, Float CountThisSession, Double SessionLength) override;
	Bool GetAchievement(pCStrA pchName, pBool pbAchieved) override;
	Bool SetAchievement(pCStrA pchName) override;
	Bool ClearAchievement(pCStrA pchName) override;
	Bool GetAchievementAndUnlockTime(pCStrA pchName, pBool pbAchieved, pUint32 pnUnlockTime) override;
	Bool StoreStats() override;
	Int32 GetAchievementIcon(pCStrA pchName) override;

	/* (returns "0" when not hidden, "1" when hidden) */
	pCStrA GetAchievementDisplayAttribute(pCStrA pchName, pCStrA pchKey) override;
	Bool IndicateAchievementProgress(pCStrA pchName, Uint32 nCurProgress, Uint32 nMaxProgress) override;

	Uint32 GetNumAchievements() override;
	pCStrA GetAchievementName(Uint32 iAchievement) override;

	SteamAPICall_t RequestUserStats(SteamId_t SteamIdUser) override;
	Bool GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pInt32 pData) override;
	Bool GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pFloat pData) override;

	Bool GetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved) override;
	Bool GetUserAchievementAndUnlockTime(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved, pUint32 punUnlockTime) override;

	Bool ResetAllStats(Bool bAchievementsToo) override;

	SteamAPICall_t FindOrCreateLeaderboard(pCStrA pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType) override;
	SteamAPICall_t FindLeaderboard(pCStrA pchLeaderboardName) override;
	pCStrA GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard) override;
	Int32 GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard) override;
	ELeaderboardSortMethod GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard) override;
	ELeaderboardDisplayType GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard) override;
	SteamAPICall_t DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, Int32 nRangeStart, Int32 nRangeEnd) override;
	SteamAPICall_t DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, pSteamId_t prgUsers, Int32 cUsers) override;
	Bool GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, Int32 index, pLeaderboardEntry_t pLeaderboardEntry, pInt32 pDetails, Int32 cDetailsMax) override;
	SteamAPICall_t UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, Int32 nScore, const pInt32 pScoreDetails, Int32 cScoreDetailsCount) override;

	SteamAPICall_t AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC) override;
	SteamAPICall_t GetNumberOfCurrentPlayers() override;
	SteamAPICall_t RequestGlobalAchievementPercentages() override;

	/* Returns (-1) if there is no data on achievement */
	Int32 GetMostAchievedAchievementInfo(pStrA pchName, Uint32 cchNameLen, pFloat pPercent, pBool pbAchieved) override;
	Int32 GetNextMostAchievedAchievementInfo(Int32 iIteratorPrevious, pStrA pchName, Uint32 cchName, pFloat pPercent, pBool pbAchieved) override;
	Bool GetAchievementAchievedPercent(pCStrA pchName, pFloat pPercent) override;

	SteamAPICall_t RequestGlobalStats(Int32 nHistoryDays) override;
	Bool GetGlobalStat(pCStrA pchStatName, pInt64 pData) override;
	Bool GetGlobalStat(pCStrA pchStatName, pDouble pData) override;
	Int32 GetGlobalStatHistory(pCStrA pchStatName, pInt64 pData, Uint32 cbData) override;
	Int32 GetGlobalStatHistory(pCStrA pchStatName, pDouble pData, Uint32 cbData) override;

	Bool GetAchievementProgressLimits(pCStrA pchName, pInt32 pProgressMin, pInt32 pProgressMax) override;
	Bool GetAchievementProgressLimits(pCStrA pchName, pFloat pProgressMin, pFloat pProgressMax) override;

	~_SteamUserStats_() = default;

} SteamUserStats, *pSteamUserStats;

#endif // !_STEAMUSERSTATS_
