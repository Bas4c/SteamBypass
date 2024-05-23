#ifndef _STEAMMATCHMAKING_
#define _STEAMMATCHMAKING_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamMatchmaking.h"
// -----------------------------------------------------------------------------

typedef class _SteamMatchmaking_ : public _ISteamMatchmaking002_,
 public _ISteamMatchmaking003_, public _ISteamMatchmaking004_,
 public _ISteamMatchmaking005_, public _ISteamMatchmaking006_,
 public _ISteamMatchmaking007_, public _ISteamMatchmaking008_,
 public _ISteamMatchmaking_ {
public:

	_SteamMatchmaking_() = default;
	_SteamMatchmaking_(const _SteamMatchmaking_&) = delete;
	_SteamMatchmaking_& operator=(const _SteamMatchmaking_&) = delete;

	Int32 GetFavoriteGameCount() override;
	/* iGame is in range [0, GetFavoriteGameCount()) */
	Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) override;

	Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 unFlags, Uint32 rTime32LastPlayedOnServer) override;
	Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) override;

	void RequestLobbyList_Old() override;
	SteamAPICall_t RequestLobbyList() override;
	void AddRequestLobbyListFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch) override;
	void AddRequestLobbyListStringFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch, ELobbyComparison eComparisonType) override;
	void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) override;
	void AddRequestLobbyListNearValueFilter(pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) override;
	void AddRequestLobbyListSlotsAvailableFilter() override;
	void AddRequestLobbyListFilterSlotsAvailable(Int32 nSlotsAvailable) override;
	void AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter) override;
	void AddRequestLobbyListResultCountFilter(Int32 cMaxResults) override;
	void AddRequestLobbyListCompatibleMembersFilter(SteamId_t SteamIdLobby) override;

	SteamId_t GetLobbyByIndex(Int32 iLobby) override;
	void CreateLobby_Old(Bool bPrivate) override;
	void CreateLobby_Old(ELobbyType eLobbyType) override;
	SteamAPICall_t CreateLobby(ELobbyType eLobbyType, Int32 cMaxMembers) override;
	void JoinLobby_Old(SteamId_t SteamIdLobby) override;
	SteamAPICall_t JoinLobby(SteamId_t SteamIdLobby) override;
	void LeaveLobby(SteamId_t SteamIdLobby) override;
	Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) override;

	Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) override;
	SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) override;

	/* "" when not set */
	pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) override;
	Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) override;
	Int32 GetLobbyDataCount(SteamId_t SteamIdLobby) override;
	Bool GetLobbyDataByIndex(SteamId_t SteamIdLobby, Int32 iLobbyData, pStrA pchKey, Int32 cchKey, pStrA pchValue, Int32 cchValue) override;
	Bool DeleteLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) override;

	/* "" when not set */
	pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) override;
	void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) override;

	Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) override;
	Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) override;
	Bool RequestLobbyData(SteamId_t SteamIdLobby) override;

	void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) override;
	Bool GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) override;

	Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) override;
	/* 0 when no limit is defined */
	Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) override;
	Bool SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) override;
	Bool SetLobbyJoinable(SteamId_t SteamIdLobby, Bool bLobbyJoinable) override;
	SteamId_t GetLobbyOwner(SteamId_t SteamIdLobby) override;
	Bool SetLobbyOwner(SteamId_t SteamIdLobby, SteamId_t SteamIdNewOwner) override;
	Bool SetLinkedLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdLobbyDependent) override;

	Bool RequestFriendsLobbies() override;
	Float GetLobbyDistance(SteamId_t SteamIdLobby) override;
	void SetLobbyVoiceEnabled(SteamId_t SteamIdLobby, Bool bVoiceEnabled) override;
	
	~_SteamMatchmaking_() = default;

} SteamMatchmaking, *pSteamMatchmaking;

// -----------------------------------------------------------------------------

typedef class _SteamMatchmakingServers_ : public _ISteamMatchmakingServers001_,
 public _ISteamMatchmakingServers_ {
public:

	_SteamMatchmakingServers_() = default;
	_SteamMatchmakingServers_(const _SteamMatchmakingServers_&) = delete;
	_SteamMatchmakingServers_& operator=(const _SteamMatchmakingServers_&) = delete;

	HServerListRequest RequestInternetServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) override;
	HServerListRequest RequestLANServerList(AppId_t iApp, IpSteamMatchmakingServerListResponse pRequestServersResponse) override;
	HServerListRequest RequestFriendsServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) override;
	HServerListRequest RequestFavoritesServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) override;
	HServerListRequest RequestHistoryServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) override;
	HServerListRequest RequestSpectatorServerList(AppId_t iApp, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) override;

	void ReleaseRequest(HServerListRequest hServerListRequest) override;

	void RequestInternetServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) override;
	void RequestLANServerList(AppId_t iAppId, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) override;
	void RequestFriendsServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) override;
	void RequestFavoritesServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) override;
	void RequestHistoryServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) override;
	void RequestSpectatorServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) override;

	/* MatchMakingKeyValuePair_t should be one of these:

		"map"
			- Server passes the filter if the server is playing the specified map.
		"gamedataand"
			- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) contains all of the
			specified strings.  The value field is a comma-delimited list of strings to match.
		"gamedataor"
			- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) contains at least one of the
			specified strings.  The value field is a comma-delimited list of strings to match.
		"gamedatanor"
			- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) does not contain any
			of the specified strings.  The value field is a comma-delimited list of strings to check.
		"gametagsand"
			- Server passes the filter if the server's game tags (ISteamGameServer::SetGameTags) contains all
			of the specified strings.  The value field is a comma-delimited list of strings to check.
		"gametagsnor"
			- Server passes the filter if the server's game tags (ISteamGameServer::SetGameTags) does not contain any
			of the specified strings.  The value field is a comma-delimited list of strings to check.
		"addr"
			- Server passes the filter if the server's query address matches the specified IP or IP:port.
		"gameaddr"
			- Server passes the filter if the server's game address matches the specified IP or IP:port.

		The following filter operations ignore the "value" part of MatchMakingKeyValuePair_t

		"dedicated"
			- Server passes the filter if it passed true to SetDedicatedServer.
		"secure"
			- Server passes the filter if the server is VAC-enabled.
		"notfull"
			- Server passes the filter if the player count is less than the reported max player count.
		"hasplayers"
			- Server passes the filter if the player count is greater than zero.
		"noplayers"
			- Server passes the filter if it doesn't have any players.
		"linux"
			- Server passes the filter if it's a linux server

	*/

	pGameServerItem_t GetServerDetails(HServerListRequest hRequest, Int32 iServer) override;

	void CancelQuery(HServerListRequest hRequest) override;
	void RefreshQuery(HServerListRequest hRequest) override;
	Bool IsRefreshing(HServerListRequest hRequest) override;
	Int32 GetServerCount(HServerListRequest hRequest) override;
	void RefreshServer(HServerListRequest hRequest, Int32 iServer) override;

	HServerQuery PingServer(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPingResponse pRequestServersResponse) override;
	HServerQuery PlayerDetails(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPlayersResponse pRequestServersResponse) override;
	HServerQuery ServerRules(Uint32 nIP, Uint16 Port, IpSteamMatchmakingRulesResponse pRequestServersResponse) override;

	void CancelServerQuery(HServerQuery hServerQuery) override;

	pGameServerItem_t GetServerDetails(EMatchMakingType eMatchMakingType, Int32 iServer) override;

	void CancelQuery(EMatchMakingType eMatchMakingType) override;
	void RefreshQuery(EMatchMakingType eMatchMakingType) override;
	Bool IsRefreshing(EMatchMakingType eMatchMakingType) override;
	Int32 GetServerCount(EMatchMakingType eMatchMakingType) override;
	void RefreshServer(EMatchMakingType eMatchMakingType, Int32 iServer) override;

	~_SteamMatchmakingServers_() = default;

} SteamMatchmakingServers, *pSteamMatchmakingServers;

// -----------------------------------------------------------------------------

typedef class _SteamGameSearch_ : public _ISteamGameSearch_ {
public:

	_SteamGameSearch_() = default;
	_SteamGameSearch_(const _SteamGameSearch_&) = delete;
	_SteamGameSearch_& operator=(const _SteamGameSearch_&) = delete;

	EGameSearchErrorCode_t AddGameSearchParams(pCStrA pchKeyToFind, pCStrA pchValuesToFind) override;
	EGameSearchErrorCode_t SearchForGameWithLobby(SteamId_t SteamIdLobby, Int32 nPlayerMin, Int32 nPlayerMax) override;
	EGameSearchErrorCode_t SearchForGameSolo(Int32 nPlayerMin, Int32 nPlayerMax) override;
	EGameSearchErrorCode_t AcceptGame() override;
	EGameSearchErrorCode_t DeclineGame() override;
	EGameSearchErrorCode_t RetrieveConnectionDetails(SteamId_t SteamIdHost, pStrA pchConnectionDetails, Int32 cbConnectionDetails) override;
	EGameSearchErrorCode_t EndGameSearch() override;
	EGameSearchErrorCode_t SetGameHostParams(pCStrA pchKey, pCStrA pchValue) override;
	EGameSearchErrorCode_t SetConnectionDetails(pCStrA pchConnectionDetails, Int32 cbConnectionDetails) override;
	EGameSearchErrorCode_t RequestPlayersForGame(Int32 nPlayerMin, Int32 nPlayerMax, Int32 nMaxTeamSize) override;
	EGameSearchErrorCode_t HostConfirmGameStart(Uint64 UniqueGameId) override;
	EGameSearchErrorCode_t CancelRequestPlayersForGame() override;
	EGameSearchErrorCode_t SubmitPlayerResult(Uint64 UniqueGameId, SteamId_t SteamIdPlayer, EPlayerResult_t EPlayerResult) override;
	EGameSearchErrorCode_t EndGame(Uint64 UniqueGameId) override;

	~_SteamGameSearch_() = default;

} SteamGameSearch, *pSteamGameSearch;

// -----------------------------------------------------------------------------

typedef class _SteamParties_ : public _ISteamParties_ {
public:

	_SteamParties_() = default;
	_SteamParties_(const _SteamParties_&) = delete;
	_SteamParties_& operator=(const _SteamParties_&) = delete;

	Uint32 GetNumActiveBeacons() override;
	PartyBeaconId_t GetPartyBeaconIdByIndex(Uint32 iBeacon) override;
	Bool GetBeaconDetails(PartyBeaconId_t PartyBeaconId, pSteamId_t pSteamIdBeaconOwner, pSteamPartyBeaconLocation_t pLocation, pStrA pchMetadata, Int32 cchMetadata) override;
	SteamAPICall_t JoinParty(PartyBeaconId_t PartyBeaconId) override;

	Bool GetNumAvailableBeaconLocations(pUint32 pNumLocations) override;
	Bool GetAvailableBeaconLocations(pSteamPartyBeaconLocation_t pLocationList, Uint32 uMaxNumLocations) override;

	SteamAPICall_t CreateBeacon(Uint32 nOpenSlots, pSteamPartyBeaconLocation_t pBeaconLocation, pCStrA pchConnectString, pCStrA pchMetadata) override;
	void OnReservationCompleted(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) override;
	void CancelReservation(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) override;
	SteamAPICall_t ChangeNumOpenSlots(PartyBeaconId_t PartyBeaconId, Uint32 nOpenSlots) override;
	Bool DestroyBeacon(PartyBeaconId_t PartyBeaconId) override;
	Bool GetBeaconLocationData(SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eSteamPartyBeaconLocationData, pStrA pchDataString, Int32 cchDataString) override;

	~_SteamParties_() = default;

} SteamParties, *pSteamParties;

#endif // !_STEAMMATCHMAKING_
