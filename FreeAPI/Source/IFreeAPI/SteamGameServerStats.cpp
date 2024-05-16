// -----------------------------------------------------------------------------
#include "SteamGameServerStats.h"
// -----------------------------------------------------------------------------

SteamAPICall_t _SteamGameServerStats_::RequestUserStats(SteamId_t SteamIdUser) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamGameServerStats_::GetUserStat(SteamId_t SteamIdUser, const pStrA pchName, pInt32 pData) {

	return True;

}

Bool _SteamGameServerStats_::GetUserStat(SteamId_t SteamIdUser, const pStrA pchName, pFloat pData) {

	return True;

}

Bool _SteamGameServerStats_::GetUserAchievement(SteamId_t SteamIdUser, const pStrA pchName, pBool pbAchieved) {

	return True;

}

Bool _SteamGameServerStats_::SetUserStat(SteamId_t SteamIdUser, const pStrA pchName, Int32 Data) {

	return True;

}

Bool _SteamGameServerStats_::SetUserStat(SteamId_t SteamIdUser, const pStrA pchName, Float Data) {

	return True;

}

Bool _SteamGameServerStats_::UpdateUserAvgRateStat(SteamId_t SteamIdUser, const pStrA pchName, Float CountThisSession, Double SessionLength) {

	return True;

}

Bool _SteamGameServerStats_::SetUserAchievement(SteamId_t SteamIdUser, const pStrA pchName) {

	return True;

}

Bool _SteamGameServerStats_::ClearUserAchievement(SteamId_t SteamIdUser, const pStrA pchName) {

	return True;

}

SteamAPICall_t _SteamGameServerStats_::StoreUserStats(SteamId_t SteamIdUser) {

	return k_SteamAPICall_Invalid;

}
