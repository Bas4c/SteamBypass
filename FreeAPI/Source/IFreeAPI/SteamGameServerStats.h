#ifndef _STEAMGAMESERVERSTATS_
#define _STEAMGAMESERVERSTATS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamGameServerStats.h"
// -----------------------------------------------------------------------------

typedef class _SteamGameServerStats_ : public _ISteamGameServerStats_ {
public:

	_SteamGameServerStats_() = default;
	_SteamGameServerStats_(const _SteamGameServerStats_&) = delete;
	_SteamGameServerStats_& operator=(const _SteamGameServerStats_&) = delete;

	SteamAPICall_t RequestUserStats(SteamId_t SteamIdUser) override;
	Bool GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pInt32 pData) override;
	Bool GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pFloat pData) override;
	Bool GetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved) override;

	Bool SetUserStat(SteamId_t SteamIdUser, pCStrA pchName, Int32 Data) override;
	Bool SetUserStat(SteamId_t SteamIdUser, pCStrA pchName, Float Data) override;
	Bool UpdateUserAvgRateStat(SteamId_t SteamIdUser, pCStrA pchName, Float CountThisSession, Double SessionLength) override;
	
	Bool SetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName) override;
	Bool ClearUserAchievement(SteamId_t SteamIdUser, pCStrA pchName) override;

	SteamAPICall_t StoreUserStats(SteamId_t SteamIdUser) override;

	~_SteamGameServerStats_() = default;

} SteamGameServerStats, *pSteamGameServerStats;

#endif // !_STEAMGAMESERVERSTATS_
