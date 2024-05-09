#ifndef _ISTEAMGAMESERVERSTATS_
#define _ISTEAMGAMESERVERSTATS_

#include "..\..\FreeAPI.Typedef.h"

// -----------------------------------------------------------------------------
// Purpose: Functions to authenticate users via Steam to play on a game server
// -----------------------------------------------------------------------------
typedef class _ISteamGameServerStats_ {
public:

	virtual SteamAPICall_t RequestUserStats(SteamId_t SteamIdUser) = 0;
	virtual Bool GetUserStat(SteamId_t SteamIdUser, const pStrA pchName, /* [out] */ pInt32 pData) = 0;
	virtual Bool GetUserStat(SteamId_t SteamIdUser, const pStrA pchName, /* [out] */ pFloat pData) = 0;
	virtual Bool GetUserAchievement(SteamId_t SteamIdUser, const pStrA pchName, /* [out] */ pBool pbAchieved) = 0;

	virtual Bool SetUserStat(SteamId_t SteamIdUser, const pStrA pchName, Int32 Data) = 0;
	virtual Bool SetUserStat(SteamId_t SteamIdUser, const pStrA pchName, Float Data) = 0;
	virtual Bool UpdateUserAvgRateStat(SteamId_t SteamIdUser, const pStrA pchName, Float CountThisSession, Double SessionLength) = 0;
	
	virtual Bool SetUserAchievement(SteamId_t SteamIdUser, const pStrA pchName) = 0;
	virtual Bool ClearUserAchievement(SteamId_t SteamIdUser, const pStrA pchName) = 0;

	virtual SteamAPICall_t StoreUserStats(SteamId_t SteamIdUser) = 0;

} ISteamGameServerStats, *IpSteamGameServerStats;

#define STEAMGAMESERVERSTATS_INTERFACE_VERSION "SteamGameServerStats001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_GSStatsReceived_t_ ((Int32)(k_iSteamGameServerStatsCallbacks + 0))
typedef struct _GSStatsReceived_t_ {

	EResult		eResult;
	SteamId_t	SteamIdUser;

} GSStatsReceived_t, *pGSStatsReceived_t;

#define k_iCallbback_GSStatsStored_t_ ((Int32)(k_iSteamGameServerStatsCallbacks + 1))
typedef struct _GSStatsStored_t_ {

	EResult		eResult;
	SteamId_t	SteamIdUser;

} GSStatsStored_t, *pGSStatsStored_t;

#define k_iCallbback_GSStatsUnloaded_t_ ((Int32)(k_iSteamUserStatsCallbacks + 8))
typedef struct _GSStatsUnloaded_t_ {

	SteamId_t	SteamIdUser;

} GSStatsUnloaded_t, *pGSStatsUnloaded_t;

#pragma pack(pop)

#endif // _ISTEAMGAMESERVERSTATS_
