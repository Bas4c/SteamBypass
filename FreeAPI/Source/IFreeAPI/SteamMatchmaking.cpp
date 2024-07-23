// -----------------------------------------------------------------------------
#include "SteamMatchmaking.h"
// -----------------------------------------------------------------------------

Int32 _SteamMatchmaking_::GetFavoriteGameCount() {
	DEBUGBREAK("ISteamMatchmaking::GetFavoriteGameCount");

	return 0;

}

Bool _SteamMatchmaking_::GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) {
	DEBUGBREAK("ISteamMatchmaking::GetFavoriteGame");

	return False;

}

Int32 _SteamMatchmaking_::AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 unFlags, Uint32 rTime32LastPlayedOnServer) {
	DEBUGBREAK("ISteamMatchmaking::AddFavoriteGame");

	return 0;

}

Bool _SteamMatchmaking_::RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) {
	DEBUGBREAK("ISteamMatchmaking::RemoveFavoriteGame");

	return False;

}

void _SteamMatchmaking_::RequestLobbyList_Old() {
	DEBUGBREAK("ISteamMatchmaking::RequestLobbyList_Old");

	/* Empty Method */

}

SteamAPICall_t _SteamMatchmaking_::RequestLobbyList() {
	DEBUGBREAK("ISteamMatchmaking::RequestLobbyList");

	return k_SteamAPICall_Invalid;

}

void _SteamMatchmaking_::AddRequestLobbyListFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListFilter");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListStringFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch, ELobbyComparison eComparisonType) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListStringFilter");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListNumericalFilter");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListNearValueFilter(pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListNearValueFilter");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListSlotsAvailableFilter() {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListSlotsAvailableFilter");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListFilterSlotsAvailable(Int32 nSlotsAvailable) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListFilterSlotsAvailable");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListDistanceFilter");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListResultCountFilter(Int32 cMaxResults) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListResultCountFilter");

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListCompatibleMembersFilter(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::AddRequestLobbyListCompatibleMembersFilter");

	/* Empty Method */

}

SteamId_t _SteamMatchmaking_::GetLobbyByIndex(Int32 iLobby) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyByIndex");

	return SteamId_t{ g_SteamId_Uint64 };

}

void _SteamMatchmaking_::CreateLobby_Old(Bool bPrivate) {
	DEBUGBREAK("ISteamMatchmaking::CreateLobby_Old");

	/* Empty Method */

}

void _SteamMatchmaking_::CreateLobby_Old(ELobbyType eLobbyType) {
	DEBUGBREAK("ISteamMatchmaking::CreateLobby_Old");

	/* Empty Method */

}

SteamAPICall_t _SteamMatchmaking_::CreateLobby(ELobbyType eLobbyType, Int32 cMaxMembers) {
	DEBUGBREAK("ISteamMatchmaking::CreateLobby");

	return k_SteamAPICall_Invalid;

}

void _SteamMatchmaking_::JoinLobby_Old(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::JoinLobby_Old");

	/* Empty Method */

}

SteamAPICall_t _SteamMatchmaking_::JoinLobby(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::JoinLobby");

	return k_SteamAPICall_Invalid;

}

void _SteamMatchmaking_::LeaveLobby(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::LeaveLobby");

	/* Empty Method */

}

Bool _SteamMatchmaking_::InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) {
	DEBUGBREAK("ISteamMatchmaking::InviteUserToLobby");

	return False;

}

Int32 _SteamMatchmaking_::GetNumLobbyMembers(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::GetNumLobbyMembers");

	return 0;

}

SteamId_t _SteamMatchmaking_::GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyMemberByIndex");

	return SteamId_t{ g_SteamId_Uint64 };

}

pCStrA _SteamMatchmaking_::GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyData");

	return (pCStrA)(
		""
	);

}

Bool _SteamMatchmaking_::SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyData");

	return False;

}

Int32 _SteamMatchmaking_::GetLobbyDataCount(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyDataCount");

	return 0;

}

Bool _SteamMatchmaking_::GetLobbyDataByIndex(SteamId_t SteamIdLobby, Int32 iLobbyData, pStrA pchKey, Int32 cchKey, pStrA pchValue, Int32 cchValue) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyDataByIndex");

	return False;

}

Bool _SteamMatchmaking_::DeleteLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) {
	DEBUGBREAK("ISteamMatchmaking::DeleteLobbyData");

	return False;

}

pCStrA _SteamMatchmaking_::GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyMemberData");

	return (pCStrA)(
		""
	);

}

void _SteamMatchmaking_::SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyMemberData");

	/* Empty Method */

}

Bool _SteamMatchmaking_::SendLobbyChatMsg(SteamId_t SteamIdLobby, pCVoid pvMsgBody, Int32 cbMsgBody) {
	DEBUGBREAK("ISteamMatchmaking::SendLobbyChatMsg");

	return False;

}

Int32 _SteamMatchmaking_::GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyChatEntry");

	return 0;

}

Bool _SteamMatchmaking_::RequestLobbyData(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::RequestLobbyData");

	return False;

}

void _SteamMatchmaking_::SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyGameServer");

	/* Empty Method */

}

Bool _SteamMatchmaking_::GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyGameServer");

	return False;

}

Bool _SteamMatchmaking_::SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyMemberLimit");

	return False;

}

Int32 _SteamMatchmaking_::GetLobbyMemberLimit(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyMemberLimit");

	return 0;

}

Bool _SteamMatchmaking_::SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyType");

	return False;

}

Bool _SteamMatchmaking_::SetLobbyJoinable(SteamId_t SteamIdLobby, Bool bLobbyJoinable) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyJoinable");

	return False;

}

SteamId_t _SteamMatchmaking_::GetLobbyOwner(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyOwner");

	return SteamId_t{ g_SteamId_Uint64 };

}

Bool _SteamMatchmaking_::SetLobbyOwner(SteamId_t SteamIdLobby, SteamId_t SteamIdNewOwner) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyOwner");

	return False;

}

Bool _SteamMatchmaking_::SetLinkedLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdLobbyDependent) {
	DEBUGBREAK("ISteamMatchmaking::SetLinkedLobby");

	return False;

}

#ifdef _PS3
void _SteamMatchmaking_::CheckForPSNGameBootInvite(Uint32 iGameBootAttributes) {
	DEBUGBREAK("ISteamMatchmaking::CheckForPSNGameBootInvite");

	/* Empty Method */

}
#endif

Bool _SteamMatchmaking_::RequestFriendsLobbies() {
	DEBUGBREAK("ISteamMatchmaking::RequestFriendsLobbies");

	return False;

}

Float _SteamMatchmaking_::GetLobbyDistance(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamMatchmaking::GetLobbyDistance");
	
	return 0.0F;

}

void _SteamMatchmaking_::SetLobbyVoiceEnabled(SteamId_t SteamIdLobby, Bool bVoiceEnabled) {
	DEBUGBREAK("ISteamMatchmaking::SetLobbyVoiceEnabled");

	/* Empty Method */

}

// -----------------------------------------------------------------------------

HServerListRequest _SteamMatchmakingServers_::RequestInternetServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestInternetServerList");
	
	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestLANServerList(AppId_t iApp, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestLANServerList");

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestFriendsServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestFriendsServerList");

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestFavoritesServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestFavoritesServerList");

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestHistoryServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestHistoryServerList");

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestSpectatorServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestSpectatorServerList");

	return NULL;

}

void _SteamMatchmakingServers_::ReleaseRequest(HServerListRequest hServerListRequest) {
	DEBUGBREAK("ISteamMatchmakingServers::ReleaseRequest");

	/* Empty Method */

}

void _SteamMatchmakingServers_::RequestInternetServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestInternetServerList");

	/* Empty Method */
}

void _SteamMatchmakingServers_::RequestLANServerList(AppId_t iAppId, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestLANServerList");

	/* Empty Method */
}

void _SteamMatchmakingServers_::RequestFriendsServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestFriendsServerList");

	/* Empty Method */
};

void _SteamMatchmakingServers_::RequestFavoritesServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestFavoritesServerList");

	/* Empty Method */
};

void _SteamMatchmakingServers_::RequestHistoryServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestHistoryServerList");

	/* Empty Method */
};

void _SteamMatchmakingServers_::RequestSpectatorServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::RequestSpectatorServerList");

	/* Empty Method */
};

pGameServerItem_t _SteamMatchmakingServers_::GetServerDetails(HServerListRequest hRequest, Int32 iServer) {
	DEBUGBREAK("ISteamMatchmakingServers::GetServerDetails");
	
	return NULL;

}

void _SteamMatchmakingServers_::CancelQuery(HServerListRequest hRequest) {
	DEBUGBREAK("ISteamMatchmakingServers::CancelQuery");

	/* Empty Method */

}

void _SteamMatchmakingServers_::RefreshQuery(HServerListRequest hRequest) {
	DEBUGBREAK("ISteamMatchmakingServers::RefreshQuery");

	/* Empty Method */

}

Bool _SteamMatchmakingServers_::IsRefreshing(HServerListRequest hRequest) {
	DEBUGBREAK("ISteamMatchmakingServers::IsRefreshing");
	
	return False;

}

Int32 _SteamMatchmakingServers_::GetServerCount(HServerListRequest hRequest) {
	DEBUGBREAK("ISteamMatchmakingServers::GetServerCount");
	
	return 0;

}

void _SteamMatchmakingServers_::RefreshServer(HServerListRequest hRequest, Int32 iServer) {
	DEBUGBREAK("ISteamMatchmakingServers::RefreshServer");

	/* Empty Method */

}

HServerQuery _SteamMatchmakingServers_::PingServer(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPingResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::PingServer");
	
	return k_HServerQuery_Invalid;

}

HServerQuery _SteamMatchmakingServers_::PlayerDetails(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPlayersResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::PlayerDetails");

	return k_HServerQuery_Invalid;

}

HServerQuery _SteamMatchmakingServers_::ServerRules(Uint32 nIP, Uint16 Port, IpSteamMatchmakingRulesResponse pRequestServersResponse) {
	DEBUGBREAK("ISteamMatchmakingServers::ServerRules");

	return k_HServerQuery_Invalid;

}

void _SteamMatchmakingServers_::CancelServerQuery(HServerQuery hServerQuery) {
	DEBUGBREAK("ISteamMatchmakingServers::CancelServerQuery");

	/* Empty Method */

}

pGameServerItem_t _SteamMatchmakingServers_::GetServerDetails(EMatchMakingType eMatchMakingType, Int32 iServer) {
	DEBUGBREAK("ISteamMatchmakingServers::GetServerDetails");

	return NULL;

}

void _SteamMatchmakingServers_::CancelQuery(EMatchMakingType eMatchMakingType) {
	DEBUGBREAK("ISteamMatchmakingServers::CancelQuery");

	/* Empty Method */

}

void _SteamMatchmakingServers_::RefreshQuery(EMatchMakingType eMatchMakingType) {
	DEBUGBREAK("ISteamMatchmakingServers::RefreshQuery");

	/* Empty Method */

}

Bool _SteamMatchmakingServers_::IsRefreshing(EMatchMakingType eMatchMakingType) {
	DEBUGBREAK("ISteamMatchmakingServers::IsRefreshing");

	return False;

}

Int32 _SteamMatchmakingServers_::GetServerCount(EMatchMakingType eMatchMakingType) {
	DEBUGBREAK("ISteamMatchmakingServers::GetServerCount");

	return 0;

}

void _SteamMatchmakingServers_::RefreshServer(EMatchMakingType eMatchMakingType, Int32 iServer) {
	DEBUGBREAK("ISteamMatchmakingServers::RefreshServer");

	/* Empty Method */

}

// -----------------------------------------------------------------------------

EGameSearchErrorCode_t _SteamGameSearch_::AddGameSearchParams(pCStrA pchKeyToFind, pCStrA pchValuesToFind) {
	DEBUGBREAK("ISteamGameSearch::AddGameSearchParams");
	
	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SearchForGameWithLobby(SteamId_t SteamIdLobby, Int32 nPlayerMin, Int32 nPlayerMax) {
	DEBUGBREAK("ISteamGameSearch::SearchForGameWithLobby");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SearchForGameSolo(Int32 nPlayerMin, Int32 nPlayerMax) {
	DEBUGBREAK("ISteamGameSearch::SearchForGameSolo");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::AcceptGame() {
	DEBUGBREAK("ISteamGameSearch::AcceptGame");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::DeclineGame() {
	DEBUGBREAK("ISteamGameSearch::DeclineGame");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::RetrieveConnectionDetails(SteamId_t SteamIdHost, pStrA pchConnectionDetails, Int32 cbConnectionDetails) {
	DEBUGBREAK("ISteamGameSearch::RetrieveConnectionDetails");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::EndGameSearch() {
	DEBUGBREAK("ISteamGameSearch::EndGameSearch");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SetGameHostParams(pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamGameSearch::SetGameHostParams");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SetConnectionDetails(pCStrA pchConnectionDetails, Int32 cbConnectionDetails) {
	DEBUGBREAK("ISteamGameSearch::SetConnectionDetails");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::RequestPlayersForGame(Int32 nPlayerMin, Int32 nPlayerMax, Int32 nMaxTeamSize) {
	DEBUGBREAK("ISteamGameSearch::RequestPlayersForGame");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::HostConfirmGameStart(Uint64 UniqueGameId) {
	DEBUGBREAK("ISteamGameSearch::HostConfirmGameStart");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::CancelRequestPlayersForGame() {
	DEBUGBREAK("ISteamGameSearch::CancelRequestPlayersForGame");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SubmitPlayerResult(Uint64 UniqueGameId, SteamId_t SteamIdPlayer, EPlayerResult_t EPlayerResult) {
	DEBUGBREAK("ISteamGameSearch::SubmitPlayerResult");

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::EndGame(Uint64 UniqueGameId) {
	DEBUGBREAK("ISteamGameSearch::EndGame");

	return k_EGameSearchErrorCode_Failed_Offline;

}

// -----------------------------------------------------------------------------

Uint32 _SteamParties_::GetNumActiveBeacons() {
	DEBUGBREAK("ISteamParties::GetNumActiveBeacons");
	
	return 0U;

}

PartyBeaconId_t _SteamParties_::GetPartyBeaconIdByIndex(Uint32 iBeacon) {
	DEBUGBREAK("ISteamParties::GetPartyBeaconIdByIndex");
	
	return k_PartyBeaconId_Invalid;

}

Bool _SteamParties_::GetBeaconDetails(PartyBeaconId_t PartyBeaconId, pSteamId_t pSteamIdBeaconOwner, pSteamPartyBeaconLocation_t pLocation, pStrA pchMetadata, Int32 cchMetadata) {
	DEBUGBREAK("ISteamParties::GetBeaconDetails");
	
	return False;

}

SteamAPICall_t _SteamParties_::JoinParty(PartyBeaconId_t PartyBeaconId) {
	DEBUGBREAK("ISteamParties::JoinParty");

	return k_SteamAPICall_Invalid;

}

Bool _SteamParties_::GetNumAvailableBeaconLocations(pUint32 pNumLocations) {
	DEBUGBREAK("ISteamParties::GetNumAvailableBeaconLocations");

	return False;

}

Bool _SteamParties_::GetAvailableBeaconLocations(pSteamPartyBeaconLocation_t pLocationList, Uint32 uMaxNumLocations) {
	DEBUGBREAK("ISteamParties::GetAvailableBeaconLocations");
	
	return False;

}

SteamAPICall_t _SteamParties_::CreateBeacon(Uint32 nOpenSlots, pSteamPartyBeaconLocation_t pBeaconLocation, pCStrA pchConnectString, pCStrA pchMetadata) {
	DEBUGBREAK("ISteamParties::CreateBeacon");
	
	return k_SteamAPICall_Invalid;

}

void _SteamParties_::OnReservationCompleted(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) {
	DEBUGBREAK("ISteamParties::OnReservationCompleted");

	/* Empty Method */

}

void _SteamParties_::CancelReservation(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) {
	DEBUGBREAK("ISteamParties::CancelReservation");

	/* Empty Method */

}

SteamAPICall_t _SteamParties_::ChangeNumOpenSlots(PartyBeaconId_t PartyBeaconId, Uint32 nOpenSlots) {
	DEBUGBREAK("ISteamParties::ChangeNumOpenSlots");

	return k_SteamAPICall_Invalid;

}

Bool _SteamParties_::DestroyBeacon(PartyBeaconId_t PartyBeaconId) {
	DEBUGBREAK("ISteamParties::DestroyBeacon");

	return False;

}

Bool _SteamParties_::GetBeaconLocationData(SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eSteamPartyBeaconLocationData, pStrA pchDataString, Int32 cchDataString) {
	DEBUGBREAK("ISteamParties::GetBeaconLocationData");

	return False;

}
