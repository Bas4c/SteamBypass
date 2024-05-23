#ifndef _ISTEAMUSERSTATS_
#define _ISTEAMUSERSTATS_

#include "..\..\FreeAPI.Typedef.h"

#define k_cchStatNameMax ((Int32)(128))
#define k_cchLeaderboardNameMax ((Int32)(128))
#define k_cLeaderboardDetailsMax ((Int32)(64))

typedef Uint64 SteamLeaderboard_t, *pSteamLeaderboard_t;
typedef Uint64 SteamLeaderboardEntries_t, *pSteamLeaderboardEntries_t;

typedef enum _ELeaderboardDataRequest_ {

	k_ELeaderboardDataRequestGlobal,
	k_ELeaderboardDataRequestGlobalAroundUser,
	k_ELeaderboardDataRequestFriends,
	k_ELeaderboardDataRequestUsers

} ELeaderboardDataRequest, *pELeaderboardDataRequest;

typedef enum _ELeaderboardSortMethod_ {

	k_ELeaderboardSortMethodNone,
	k_ELeaderboardSortMethodAscending,
	k_ELeaderboardSortMethodDescending

} ELeaderboardSortMethod, *pELeaderboardSortMethod;

typedef enum _ELeaderboardDisplayType_ {

	k_ELeaderboardDisplayTypeNone,
	k_ELeaderboardDisplayTypeNumeric,
	k_ELeaderboardDisplayTypeTimeSeconds,
	k_ELeaderboardDisplayTypeTimeMilliSeconds

} ELeaderboardDisplayType, *pELeaderboardDisplayType;

typedef enum _ELeaderboardUploadScoreMethod_ {

	k_ELeaderboardUploadScoreMethodNone,
	k_ELeaderboardUploadScoreMethodKeepBest,
	k_ELeaderboardUploadScoreMethodForceUpdate

} ELeaderboardUploadScoreMethod, *pELeaderboardUploadScoreMethod;

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

typedef struct _LeaderboardEntry_t_ {

	SteamId_t SteamIdUser;
	Int32 nGlobalRank;
	Int32 nScore;
	Int32 cDetails;
	UGCHandle_t hUGC;

} LeaderboardEntry_t, *pLeaderboardEntry_t;

#pragma pack(pop)

// -----------------------------------------------------------------------------
// Purpose: Functions to access user stats, achievements, and leaderboard information
// -----------------------------------------------------------------------------
typedef class _ISteamUserStats_ {
public:

	/* Result in UserStatsReceived_t */
	virtual Bool RequestCurrentStats() = 0;
	virtual Bool GetStat(pCStrA pchName, /* [out] */ pInt32 pData) = 0;
	virtual Bool GetStat(pCStrA pchName, /* [out] */ pFloat pData) = 0;
	virtual Bool SetStat(pCStrA pchName, Int32 Data) = 0;
	virtual Bool SetStat(pCStrA pchName, Float Data) = 0;
	virtual Bool UpdateAvgRateStat(pCStrA pchName, Float CountThisSession, Double SessionLength) = 0;
	virtual Bool GetAchievement(pCStrA pchName, /* [out] */ pBool pbAchieved) = 0;
	virtual Bool SetAchievement(pCStrA pchName) = 0;
	virtual Bool ClearAchievement(pCStrA pchName) = 0;
	virtual Bool GetAchievementAndUnlockTime(pCStrA pchName, /* [out] */ pBool pbAchieved, /* [out] */ pUint32 pnUnlockTime) = 0;
	virtual Bool StoreStats() = 0;
	virtual Int32 GetAchievementIcon(pCStrA pchName) = 0;

	/* (returns "0" when not hidden, "1" when hidden) */
	virtual pCStrA GetAchievementDisplayAttribute(pCStrA pchName, pCStrA pchKey) = 0;
	virtual Bool IndicateAchievementProgress(pCStrA pchName, Uint32 nCurProgress, Uint32 nMaxProgress) = 0;

	virtual Uint32 GetNumAchievements() = 0;
	virtual pCStrA GetAchievementName(Uint32 iAchievement) = 0;

	virtual SteamAPICall_t RequestUserStats(SteamId_t SteamIdUser) = 0;
	virtual Bool GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, /* [out] */ pInt32 pData) = 0;
	virtual Bool GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, /* [out] */ pFloat pData) = 0;

	virtual Bool GetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName, /* [out] */ pBool pbAchieved) = 0;
	virtual Bool GetUserAchievementAndUnlockTime(SteamId_t SteamIdUser, pCStrA pchName, /* [out] */ pBool pbAchieved, /* [out] */ pUint32 punUnlockTime) = 0;

	virtual Bool ResetAllStats(Bool bAchievementsToo) = 0;
	
	virtual SteamAPICall_t FindOrCreateLeaderboard(pCStrA pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType) = 0;
	virtual SteamAPICall_t FindLeaderboard(pCStrA pchLeaderboardName) = 0;
	virtual pCStrA GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard) = 0;
	virtual Int32 GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard) = 0;
	virtual ELeaderboardSortMethod GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard) = 0;
	virtual ELeaderboardDisplayType GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard) = 0;
	virtual SteamAPICall_t DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, Int32 nRangeStart, Int32 nRangeEnd) = 0;
	virtual SteamAPICall_t DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, /* [out] */ pSteamId_t prgUsers, Int32 cUsers) = 0;
	virtual Bool GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, Int32 index, /* [out] */ pLeaderboardEntry_t pLeaderboardEntry, /* [out] */ pInt32 pDetails, Int32 cDetailsMax) = 0;
	virtual SteamAPICall_t UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, Int32 nScore, const pInt32 pScoreDetails, Int32 cScoreDetailsCount) = 0;
	
	virtual SteamAPICall_t AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC) = 0;
	virtual SteamAPICall_t GetNumberOfCurrentPlayers() = 0;
	virtual SteamAPICall_t RequestGlobalAchievementPercentages() = 0;

	/* Returns (-1) if there is no data on achievement */
	virtual Int32 GetMostAchievedAchievementInfo(pStrA pchName, Uint32 cchNameLen, /* [out] */ pFloat pPercent, /* [out] */ pBool pbAchieved) = 0;
	virtual Int32 GetNextMostAchievedAchievementInfo(Int32 iIteratorPrevious, pStrA pchName, Uint32 cchName, /* [out] */ pFloat pPercent, /* [out] */ pBool pbAchieved) = 0;
	virtual Bool GetAchievementAchievedPercent(pCStrA pchName, /* [out] */ pFloat pPercent) = 0;

	virtual SteamAPICall_t RequestGlobalStats(Int32 nHistoryDays) = 0;
	virtual Bool GetGlobalStat(pCStrA pchStatName, /* [out] */ pInt64 pData) = 0;
	virtual Bool GetGlobalStat(pCStrA pchStatName, /* [out] */ pDouble pData) = 0;
	virtual Int32 GetGlobalStatHistory(pCStrA pchStatName, /* [out] */ pInt64 pData, Uint32 cbData) = 0;
	virtual Int32 GetGlobalStatHistory(pCStrA pchStatName, /* [out] */ pDouble pData, Uint32 cbData) = 0;

	virtual Bool GetAchievementProgressLimits(pCStrA pchName, /* [out] */ pInt32 pProgressMin, /* [out] */ pInt32 pProgressMax) = 0;
	virtual Bool GetAchievementProgressLimits(pCStrA pchName, /* [out] */ pFloat pProgressMin, /* [out] */ pFloat pProgressMax) = 0;

} ISteamUserStats, *IpSteamUserStats;

#define STEAMUSERSTATS_INTERFACE_VERSION "STEAMUSERSTATS_INTERFACE_VERSION012"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_UserStatsReceived_t_ ((Int32)(k_iSteamUserStatsCallbacks + 1))
typedef struct _UserStatsReceived_t_ {

	Uint64 GameId;
	EResult eResult;
	SteamId_t SteamIdUser;

} UserStatsReceived_t, *pUserStatsReceived_t;

#define k_iCallbback_UserStatsStored_t_ ((Int32)(k_iSteamUserStatsCallbacks + 2))
typedef struct _UserStatsStored_t_ {

	Uint64 GameId;
	EResult eResult;

} UserStatsStored_t, *pUserStatsStored_t;

#define k_iCallbback_UserAchievementStored_t_ ((Int32)(k_iSteamUserStatsCallbacks + 3))
typedef struct _UserAchievementStored_t_ {


	Uint64 GameId;
	Bool bGroupAchievement;
	CharA rgchAchievementName[k_cchStatNameMax];
	Uint32 nCurProgress;
	Uint32 nMaxProgress;

} UserAchievementStored_t, *pUserAchievementStored_t;

#define k_iCallbback_LeaderboardFindResult_t_ ((Int32)(k_iSteamUserStatsCallbacks + 4))
typedef struct _LeaderboardFindResult_t_ {

	SteamLeaderboard_t hSteamLeaderboard;
	Uint8 bLeaderboardFound;

} LeaderboardFindResult_t, *pLeaderboardFindResult_t;

// -----------------------------------------------------------------------------
// Purpose: CallResult indicating scores for a leaderboard have been downloaded and are ready to be retrieved, returned as a result of DownloadLeaderboardEntries()
// use CCallResult<> to map this async result to a member function
// -----------------------------------------------------------------------------
#define k_iCallbback_LeaderboardScoresDownloaded_t_ ((Int32)(k_iSteamUserStatsCallbacks + 5))
typedef struct _LeaderboardScoresDownloaded_t_ {

	SteamLeaderboard_t hSteamLeaderboard;
	SteamLeaderboardEntries_t hSteamLeaderboardEntries;
	Int32 cEntryCount;

} LeaderboardScoresDownloaded_t, *pLeaderboardScoresDownloaded_t;

// -----------------------------------------------------------------------------
// Purpose: CallResult indicating scores has been uploaded, returned as a result of UploadLeaderboardScore()
//  use CCallResult<> to map this async result to a member function
// -----------------------------------------------------------------------------
#define k_iCallbback_LeaderboardScoreUploaded_t_ ((Int32)(k_iSteamUserStatsCallbacks + 6))
typedef struct _LeaderboardScoreUploaded_t_ {

	Uint8 bSuccess;
	SteamLeaderboard_t hSteamLeaderboard;
	Int32 nScore;
	Uint8 bScoreChanged;
	Int32 nGlobalRankNew;
	Int32 nGlobalRankPrevious;

} LeaderboardScoreUploaded_t, *pLeaderboardScoreUploaded_t;

#define k_iCallbback_NumberOfCurrentPlayers_t_ ((Int32)(k_iSteamUserStatsCallbacks + 7))
typedef struct _NumberOfCurrentPlayers_t_ {

	Uint8 bSuccess;
	Int32 cPlayers;

} NumberOfCurrentPlayers_t, *pNumberOfCurrentPlayers_t;

// -----------------------------------------------------------------------------
#define k_iCallbback_UserStatsUnloaded_t_ ((Int32)(k_iSteamUserStatsCallbacks + 8))
typedef struct _UserStatsUnloaded_t_ {

	SteamId_t SteamIdUser;

} UserStatsUnloaded_t, *pUserStatsUnloaded_t;

#define k_iCallbback_UserAchievementIconFetched_t_ ((Int32)(k_iSteamUserStatsCallbacks + 9))
typedef struct _UserAchievementIconFetched_t_ {

	GameId_t GameId;
	CharA chAchievementName[k_cchStatNameMax];
	Bool bAchieved;
	Int32 hIcon;

} UserAchievementIconFetched_t, *pUserAchievementIconFetched_t;

#define k_iCallbback_GlobalAchievementPercentagesReady_t_ ((Int32)(k_iSteamUserStatsCallbacks + 10))
typedef struct _GlobalAchievementPercentagesReady_t_ {

	Uint64 GameId;
	EResult eResult;

} GlobalAchievementPercentagesReady_t, *pGlobalAchievementPercentagesReady_t;

#define k_iCallbback_LeaderboardUGCSet_t_ ((Int32)(k_iSteamUserStatsCallbacks + 11))
typedef struct _LeaderboardUGCSet_t_ {

	EResult eResult;
	SteamLeaderboard_t hSteamLeaderboard;

} LeaderboardUGCSet_t, *pLeaderboardUGCSet_t;

#define k_iCallbback_PS3TrophiesInstalled_t_ ((Int32)(k_iSteamUserStatsCallbacks + 12))
typedef struct _PS3TrophiesInstalled_t_ {

	Uint64	GameId;
	EResult eResult;
	Uint64 RequiredDiskSpace;

} PS3TrophiesInstalled_t, *pPS3TrophiesInstalled_t;

#define k_iCallbback_GlobalStatsReceived_t_ ((Int32)(k_iSteamUserStatsCallbacks + 12))
typedef struct _GlobalStatsReceived_t_ {

	Uint64	GameId;
	EResult	eResult;

} GlobalStatsReceived_t, *pGlobalStatsReceived_t;

#pragma pack(pop)

#endif // ISTEAMUSER_H
