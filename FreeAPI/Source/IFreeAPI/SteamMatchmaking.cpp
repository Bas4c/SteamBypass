// -----------------------------------------------------------------------------
#include "SteamMatchmaking.h"
// -----------------------------------------------------------------------------

Int32 _SteamMatchmaking_::GetFavoriteGameCount() {

	return 0;

}

Bool _SteamMatchmaking_::GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) {

	return False;

}

Int32 _SteamMatchmaking_::AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 unFlags, Uint32 rTime32LastPlayedOnServer) {

	return 0;

}

Bool _SteamMatchmaking_::RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) {

	return False;

}

SteamAPICall_t _SteamMatchmaking_::RequestLobbyList() {

	return k_SteamAPICall_Invalid;

}

void _SteamMatchmaking_::AddRequestLobbyListStringFilter(const pStrA pchKeyToMatch, const pStrA pchValueToMatch, ELobbyComparison eComparisonType) {

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListNumericalFilter(const pStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) {

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListNearValueFilter(const pStrA pchKeyToMatch, Int32 nValueToBeCloseTo) {

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListFilterSlotsAvailable(Int32 nSlotsAvailable) {

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter) {

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListResultCountFilter(Int32 cMaxResults) {

	/* Empty Method */

}

void _SteamMatchmaking_::AddRequestLobbyListCompatibleMembersFilter(SteamId_t SteamIdLobby) {

	/* Empty Method */

}

SteamId_t _SteamMatchmaking_::GetLobbyByIndex(Int32 iLobby) {

	return k_SteamId_t_Create(
		k_EUniversePublic, k_EAccountTypeIndividual,
		 0xFFFFF, 0xFFFFFFFF
	);

}

SteamAPICall_t _SteamMatchmaking_::CreateLobby(ELobbyType eLobbyType, Int32 cMaxMembers) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamMatchmaking_::JoinLobby(SteamId_t SteamIdLobby) {

	return k_SteamAPICall_Invalid;

}

void _SteamMatchmaking_::LeaveLobby(SteamId_t SteamIdLobby) {

	/* Empty Method */

}

Bool _SteamMatchmaking_::InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) {

	return False;

}

Int32 _SteamMatchmaking_::GetNumLobbyMembers(SteamId_t SteamIdLobby) {

	return 0;

}

SteamId_t _SteamMatchmaking_::GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) {

	return k_SteamId_t_Create(
		k_EUniversePublic, k_EAccountTypeIndividual,
		0xFFFFF, 0xFFFFFFFF
	);

}

const pStrA _SteamMatchmaking_::GetLobbyData(SteamId_t SteamIdLobby, const pStrA pchKey) {

	return (const pStrA)(
		""
	);

}

Bool _SteamMatchmaking_::SetLobbyData(SteamId_t SteamIdLobby, const pStrA pchKey, const pStrA pchValue) {

	return False;

}

Int32 _SteamMatchmaking_::GetLobbyDataCount(SteamId_t SteamIdLobby) {

	return 0;

}

Bool _SteamMatchmaking_::GetLobbyDataByIndex(SteamId_t SteamIdLobby, Int32 iLobbyData, pStrA pchKey, Int32 cchKey, pStrA pchValue, Int32 cchValue) {

	return False;

}

Bool _SteamMatchmaking_::DeleteLobbyData(SteamId_t SteamIdLobby, const pStrA pchKey) {

	return False;

}

const pStrA _SteamMatchmaking_::GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, const pStrA pchKey) {

	return (const pStrA)(
		""
	);

}

void _SteamMatchmaking_::SetLobbyMemberData(SteamId_t SteamIdLobby, const pStrA pchKey, const pStrA pchValue) {

	/* Empty Method */

}

Bool _SteamMatchmaking_::SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) {

	return False;

}

Int32 _SteamMatchmaking_::GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) {

	return 0;

}

Bool _SteamMatchmaking_::RequestLobbyData(SteamId_t SteamIdLobby) {

	return False;

}

void _SteamMatchmaking_::SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) {

	/* Empty Method */

}

Bool _SteamMatchmaking_::GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) {

	return False;

}

Bool _SteamMatchmaking_::SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) {

	return False;

}

Int32 _SteamMatchmaking_::GetLobbyMemberLimit(SteamId_t SteamIdLobby) {

	return 0;

}

Bool _SteamMatchmaking_::SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) {

	return False;

}

Bool _SteamMatchmaking_::SetLobbyJoinable(SteamId_t SteamIdLobby, Bool bLobbyJoinable) {

	return False;

}

SteamId_t _SteamMatchmaking_::GetLobbyOwner(SteamId_t SteamIdLobby) {

	return k_SteamId_t_Create(
		k_EUniversePublic, k_EAccountTypeIndividual,
		0xFFFFF, 0xFFFFFFFF
	);

}

Bool _SteamMatchmaking_::SetLobbyOwner(SteamId_t SteamIdLobby, SteamId_t SteamIdNewOwner) {

	return False;

}

Bool _SteamMatchmaking_::SetLinkedLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdLobbyDependent) {

	return False;

}

void _SteamMatchmaking_::CheckForPSNGameBootInvite(Uint32 iGameBootAttributes) {

	/* Empty Method */

}

// -----------------------------------------------------------------------------

HServerListRequest _SteamMatchmakingServers_::RequestInternetServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	
	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestLANServerList(AppId_t iApp, IpSteamMatchmakingServerListResponse pRequestServersResponse) {

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestFriendsServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestFavoritesServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestHistoryServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {

	return NULL;

}

HServerListRequest _SteamMatchmakingServers_::RequestSpectatorServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {

	return NULL;

}

void _SteamMatchmakingServers_::ReleaseRequest(HServerListRequest hServerListRequest) {

	/* Empty Method */

}

pGameServerItem_t _SteamMatchmakingServers_::GetServerDetails(HServerListRequest hRequest, Int32 iServer) {
	
	return NULL;

}

void _SteamMatchmakingServers_::CancelQuery(HServerListRequest hRequest) {

	/* Empty Method */

}

void _SteamMatchmakingServers_::RefreshQuery(HServerListRequest hRequest) {

	/* Empty Method */

}

Bool _SteamMatchmakingServers_::IsRefreshing(HServerListRequest hRequest) {
	
	return False;

}

Int32 _SteamMatchmakingServers_::GetServerCount(HServerListRequest hRequest) {
	
	return 0;

}

void _SteamMatchmakingServers_::RefreshServer(HServerListRequest hRequest, Int32 iServer) {

	/* Empty Method */

}

HServerQuery _SteamMatchmakingServers_::PingServer(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPingResponse pRequestServersResponse) {
	
	return k_HServerQuery_Invalid;

}

HServerQuery _SteamMatchmakingServers_::PlayerDetails(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPlayersResponse pRequestServersResponse) {

	return k_HServerQuery_Invalid;

}

HServerQuery _SteamMatchmakingServers_::ServerRules(Uint32 nIP, Uint16 Port, IpSteamMatchmakingRulesResponse pRequestServersResponse) {

	return k_HServerQuery_Invalid;

}

void _SteamMatchmakingServers_::CancelServerQuery(HServerQuery hServerQuery) {

	/* Empty Method */

}

// -----------------------------------------------------------------------------

EGameSearchErrorCode_t _SteamGameSearch_::AddGameSearchParams(pStrA pchKeyToFind, pStrA pchValuesToFind) {
	
	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SearchForGameWithLobby(SteamId_t SteamIdLobby, Int32 nPlayerMin, Int32 nPlayerMax) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SearchForGameSolo(Int32 nPlayerMin, Int32 nPlayerMax) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::AcceptGame() {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::DeclineGame() {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::RetrieveConnectionDetails(SteamId_t SteamIdHost, pStrA pchConnectionDetails, Int32 cbConnectionDetails) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::EndGameSearch() {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SetGameHostParams(pStrA pchKey, pStrA pchValue) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SetConnectionDetails(pStrA pchConnectionDetails, Int32 cbConnectionDetails) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::RequestPlayersForGame(Int32 nPlayerMin, Int32 nPlayerMax, Int32 nMaxTeamSize) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::HostConfirmGameStart(Uint64 UniqueGameId) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::CancelRequestPlayersForGame() {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::SubmitPlayerResult(Uint64 UniqueGameId, SteamId_t SteamIdPlayer, EPlayerResult_t EPlayerResult) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

EGameSearchErrorCode_t _SteamGameSearch_::EndGame(Uint64 UniqueGameId) {

	return k_EGameSearchErrorCode_Failed_Offline;

}

// -----------------------------------------------------------------------------

Uint32 _SteamParties_::GetNumActiveBeacons() {
	
	return 0U;

}

PartyBeaconId_t _SteamParties_::GetPartyBeaconIdByIndex(Uint32 iBeacon) {
	
	return k_PartyBeaconId_Invalid;

}

Bool _SteamParties_::GetBeaconDetails(PartyBeaconId_t PartyBeaconId, pSteamId_t pSteamIdBeaconOwner, pSteamPartyBeaconLocation_t pLocation, pStrA pchMetadata, Int32 cchMetadata) {
	
	return False;

}

SteamAPICall_t _SteamParties_::JoinParty(PartyBeaconId_t PartyBeaconId) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamParties_::GetNumAvailableBeaconLocations(pUint32 pNumLocations) {

	return False;

}

Bool _SteamParties_::GetAvailableBeaconLocations(pSteamPartyBeaconLocation_t pLocationList, Uint32 uMaxNumLocations) {
	
	return False;

}

SteamAPICall_t _SteamParties_::CreateBeacon(Uint32 nOpenSlots, pSteamPartyBeaconLocation_t pBeaconLocation, pStrA pchConnectString, pStrA pchMetadata) {
	
	return k_SteamAPICall_Invalid;

}

void _SteamParties_::OnReservationCompleted(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) {

	/* Empty Method */

}

void _SteamParties_::CancelReservation(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) {

	/* Empty Method */

}

SteamAPICall_t _SteamParties_::ChangeNumOpenSlots(PartyBeaconId_t PartyBeaconId, Uint32 nOpenSlots) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamParties_::DestroyBeacon(PartyBeaconId_t PartyBeaconId) {

	return False;

}

Bool _SteamParties_::GetBeaconLocationData(SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eSteamPartyBeaconLocationData, pStrA pchDataString, Int32 cchDataString) {

	return False;

}
