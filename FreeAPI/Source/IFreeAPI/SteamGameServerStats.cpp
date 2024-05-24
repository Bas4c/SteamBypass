// -----------------------------------------------------------------------------
#include "SteamGameServerStats.h"
// -----------------------------------------------------------------------------

SteamAPICall_t _SteamGameServerStats_::RequestUserStats(SteamId_t SteamIdUser) {
	DEBUGBREAK("ISteamGameServerStats::RequestUserStats");

	return k_SteamAPICall_Invalid;

}

Bool _SteamGameServerStats_::GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pInt32 pData) {
	DEBUGBREAK("ISteamGameServerStats::GetUserStat");

	return True;

}

Bool _SteamGameServerStats_::GetUserStat(SteamId_t SteamIdUser, pCStrA pchName, pFloat pData) {
	DEBUGBREAK("ISteamGameServerStats::GetUserStat");

	return True;

}

Bool _SteamGameServerStats_::GetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName, pBool pbAchieved) {
	DEBUGBREAK("ISteamGameServerStats::GetUserAchievement");

	return True;

}

Bool _SteamGameServerStats_::SetUserStat(SteamId_t SteamIdUser, pCStrA pchName, Int32 Data) {
	DEBUGBREAK("ISteamGameServerStats::SetUserStat");

	return True;

}

Bool _SteamGameServerStats_::SetUserStat(SteamId_t SteamIdUser, pCStrA pchName, Float Data) {
	DEBUGBREAK("ISteamGameServerStats::SetUserStat");

	return True;

}

Bool _SteamGameServerStats_::UpdateUserAvgRateStat(SteamId_t SteamIdUser, pCStrA pchName, Float CountThisSession, Double SessionLength) {
	DEBUGBREAK("ISteamGameServerStats::UpdateUserAvgRateStat");

	return True;

}

Bool _SteamGameServerStats_::SetUserAchievement(SteamId_t SteamIdUser, pCStrA pchName) {
	DEBUGBREAK("ISteamGameServerStats::SetUserAchievement");

	return True;

}

Bool _SteamGameServerStats_::ClearUserAchievement(SteamId_t SteamIdUser, pCStrA pchName) {
	DEBUGBREAK("ISteamGameServerStats::ClearUserAchievement");

	return True;

}

SteamAPICall_t _SteamGameServerStats_::StoreUserStats(SteamId_t SteamIdUser) {
	DEBUGBREAK("ISteamGameServerStats::StoreUserStats");

	return k_SteamAPICall_Invalid;

}
