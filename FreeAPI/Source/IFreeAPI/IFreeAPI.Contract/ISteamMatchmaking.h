#ifndef _ISTEAMMATCHMAKING_
#define _ISTEAMMATCHMAKING_

#include "..\..\FreeAPI.Typedef.h"
#include "ISteamFriends.h"

#define k_cbMaxGameServerGameDir ((Int32)(32))
#define k_cbMaxGameServerMapName ((Int32)(32))
#define k_cbMaxGameServerGameDescription ((Int32)(64))
#define k_cbMaxGameServerName ((Int32)(64))
#define k_cbMaxGameServerTags ((Int32)(128))
#define k_cbMaxGameServerGameData ((Int32)(2048))

typedef struct _MatchMakingKeyValuePair_t_ {

	CharA chKey[256];
	CharA chValue[256];

} MatchMakingKeyValuePair_t, *pMatchMakingKeyValuePair_t;

typedef enum _EMatchMakingServerResponse_ {

	k_EMatchMakingServerResponse_ServerResponded,
	k_EMatchMakingServerResponse_ServerFailedToRespond,
	k_EMatchMakingServerResponse_NoServersListedOnMasterServer

} EMatchMakingServerResponse, *pEMatchMakingServerResponse;

/* String Format: "<nIP:0>.<nIP:1>.<nIP:2>.<nIP:3>:<ConnectionPort>" */
typedef struct _ServerNETAdrr_t_ {

	Uint16	ConnectionPort;
	Uint16	QueryPort;
	Uint32  nIP;

} ServerNETAdrr_t, *pServerNETAdrr_t;

typedef struct _GameServerItem_t_ {

	ServerNETAdrr_t ServerNETAdrr;
	Int32 PingMiliseconds;
	Bool bHadSuccessfulResponse;
	Bool bDoNotRefresh;
	CharA chGameDir[k_cbMaxGameServerGameDir];
	CharA chMap[k_cbMaxGameServerMapName];
	CharA chGameDescription[k_cbMaxGameServerGameDescription];
	AppId_t iAppId;
	Int32 nPlayers;
	Int32 nMaxPlayers;
	Int32 nBotPlayers;
	Bool bPassword;
	Bool bSecure;
	Uint32 TimeLastPlayed;
	Int32 nServerVersion;
	CharA chServerName[k_cbMaxGameServerName];
	CharA chGameTags[k_cbMaxGameServerTags];
	SteamId_t SteamId;

} GameServerItem_t, *pGameServerItem_t;

typedef enum _ELobbyType_ {

	k_ELobbyTypePrivate,
	k_ELobbyTypeFriendsOnly,
	k_ELobbyTypePublic,
	k_ELobbyTypeInvisible,
	k_ELobbyTypePrivateUnique

} ELobbyType, *pELobbyType;

typedef enum _ELobbyComparison_ {

	k_ELobbyComparisonEqualToOrLessThan = -2,
	k_ELobbyComparisonLessThan = -1,
	k_ELobbyComparisonEqual = 0,
	k_ELobbyComparisonGreaterThan = 1,
	k_ELobbyComparisonEqualToOrGreaterThan = 2,
	k_ELobbyComparisonNotEqual = 3

} ELobbyComparison, *pELobbyComparison;

// lobby search distance. Lobby results are sorted from closest to farthest.
typedef enum _ELobbyDistanceFilter_ {
	k_ELobbyDistanceFilterClose,
	k_ELobbyDistanceFilterDefault,
	k_ELobbyDistanceFilterFar,
	k_ELobbyDistanceFilterWorldwide,
} ELobbyDistanceFilter, *pELobbyDistanceFilter;

#define k_MaxLobbyKeyLength ((Int32)(255))

typedef class _ISteamMatchmaking002_ {
public:

	virtual Int32 GetFavoriteGameCount() = 0;
	virtual Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) = 0;
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;
	virtual void RequestLobbyList_Old() = 0;
	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual void CreateLobby_Old(Bool bPrivate) = 0;
	virtual void JoinLobby_Old(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;
	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;

} ISteamMatchmaking002, *IpSteamMatchmaking002;

typedef class _ISteamMatchmaking003_ {
public:

	virtual Int32 GetFavoriteGameCount() = 0;
	virtual Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) = 0;
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;
	virtual void RequestLobbyList_Old() = 0;
	virtual void AddRequestLobbyListFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch) = 0;
	virtual void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListSlotsAvailableFilter() = 0;
	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual void CreateLobby_Old(Bool bPrivate) = 0;
	virtual void JoinLobby_Old(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;
	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;
	virtual Bool GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) = 0;
	virtual Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) = 0;
	virtual Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyVoiceEnabled(SteamId_t SteamIdLobby, Bool bVoiceEnabled) = 0;
	virtual Bool RequestFriendsLobbies() = 0;

} ISteamMatchmaking003, *IpSteamMatchmaking003;

typedef class _ISteamMatchmaking004_ {
public:

	virtual Int32 GetFavoriteGameCount() = 0;
	virtual Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) = 0;
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;
	virtual void RequestLobbyList_Old() = 0;
	virtual void AddRequestLobbyListFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch) = 0;
	virtual void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListSlotsAvailableFilter() = 0;
	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual void CreateLobby_Old(Bool bPrivate) = 0;
	virtual void JoinLobby_Old(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;
	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;
	virtual Bool GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) = 0;
	virtual Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) = 0;
	virtual Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) = 0;
	virtual Bool RequestFriendsLobbies() = 0;

} ISteamMatchmaking004, *IpSteamMatchmaking004;

typedef class _ISteamMatchmaking005_ {
public:

	virtual Int32 GetFavoriteGameCount() = 0;
	virtual Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) = 0;
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;
	virtual void RequestLobbyList_Old() = 0;
	virtual void AddRequestLobbyListFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch) = 0;
	virtual void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListSlotsAvailableFilter() = 0;
	virtual void AddRequestLobbyListNearValueFilter(pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) = 0;
	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual void CreateLobby_Old(ELobbyType eLobbyType) = 0;
	virtual void JoinLobby_Old(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;
	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;
	virtual Bool GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) = 0;
	virtual Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) = 0;
	virtual Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) = 0;
	virtual Bool RequestFriendsLobbies() = 0;
	virtual Bool SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) = 0;
	virtual SteamId_t GetLobbyOwner(SteamId_t SteamIdLobby) = 0;
	virtual Float GetLobbyDistance(SteamId_t SteamIdLobby) = 0;

} ISteamMatchmaking005, *IpSteamMatchmaking005;

typedef class _ISteamMatchmaking006_ {
public:

	virtual Int32 GetFavoriteGameCount() = 0;
	virtual Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) = 0;
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;
	virtual SteamAPICall_t RequestLobbyList() = 0;
	virtual void AddRequestLobbyListFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch) = 0;
	virtual void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListNearValueFilter(pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) = 0;
	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual SteamAPICall_t CreateLobby(ELobbyType eLobbyType, Int32 cMaxMembers) = 0;
	virtual SteamAPICall_t JoinLobby(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;
	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;
	virtual Bool GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) = 0;
	virtual Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) = 0;
	virtual Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) = 0;
	virtual Bool SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) = 0;
	virtual SteamId_t GetLobbyOwner(SteamId_t SteamIdLobby) = 0;

} ISteamMatchmaking006, *IpSteamMatchmaking006;

typedef class _ISteamMatchmaking007_ {
public:

	virtual Int32 GetFavoriteGameCount() = 0;
	virtual Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) = 0;
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;
	virtual SteamAPICall_t RequestLobbyList() = 0;
	virtual void AddRequestLobbyListStringFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListNearValueFilter(pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) = 0;
	virtual void AddRequestLobbyListFilterSlotsAvailable(Int32 nSlotsAvailable) = 0;
	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual SteamAPICall_t CreateLobby(ELobbyType eLobbyType, Int32 cMaxMembers) = 0;
	virtual SteamAPICall_t JoinLobby(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;
	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Int32 GetLobbyDataCount(SteamId_t SteamIdLobby) = 0;
	virtual Bool GetLobbyDataByIndex(SteamId_t SteamIdLobby, Int32 iLobbyData, pStrA pchKey, Int32 cchKey, pStrA pchValue, Int32 cchValue) = 0;
	virtual Bool DeleteLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;
	virtual Bool GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) = 0;
	virtual Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) = 0;
	virtual Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) = 0;
	virtual Bool SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) = 0;
	virtual Bool SetLobbyJoinable(SteamId_t SteamIdLobby, Bool bLobbyJoinable) = 0;
	virtual SteamId_t GetLobbyOwner(SteamId_t SteamIdLobby) = 0;
	virtual Bool SetLobbyOwner(SteamId_t SteamIdLobby, SteamId_t SteamIdNewOwner) = 0;

} ISteamMatchmaking007, *IpSteamMatchmaking007;

typedef class _ISteamMatchmaking008_ {
public:

	virtual Int32 GetFavoriteGameCount() = 0;
	virtual Bool GetFavoriteGame(Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) = 0;
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;
	virtual SteamAPICall_t RequestLobbyList() = 0;
	virtual void AddRequestLobbyListStringFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListNearValueFilter(pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) = 0;
	virtual void AddRequestLobbyListFilterSlotsAvailable(Int32 nSlotsAvailable) = 0;
	virtual void AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter) = 0;
	virtual void AddRequestLobbyListResultCountFilter(Int32 cMaxResults) = 0;
	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual SteamAPICall_t CreateLobby(ELobbyType eLobbyType, Int32 cMaxMembers) = 0;
	virtual SteamAPICall_t JoinLobby(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;
	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Int32 GetLobbyDataCount(SteamId_t SteamIdLobby) = 0;
	virtual Bool GetLobbyDataByIndex(SteamId_t SteamIdLobby, Int32 iLobbyData, pStrA pchKey, Int32 cchKey, pStrA pchValue, Int32 cchValue) = 0;
	virtual Bool DeleteLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;
	virtual Bool GetLobbyGameServer(SteamId_t SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) = 0;
	virtual Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) = 0;
	virtual Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) = 0;
	virtual Bool SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) = 0;
	virtual Bool SetLobbyJoinable(SteamId_t SteamIdLobby, Bool bLobbyJoinable) = 0;
	virtual SteamId_t GetLobbyOwner(SteamId_t SteamIdLobby) = 0;
	virtual Bool SetLobbyOwner(SteamId_t SteamIdLobby, SteamId_t SteamIdNewOwner) = 0;

} ISteamMatchmaking008, *IpSteamMatchmaking008;

// -----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to favorites
//  and to operate on game lobbies.
// -----------------------------------------------------------------------------
typedef class _ISteamMatchmaking_ {
public:
	
	virtual Int32 GetFavoriteGameCount() = 0;
	/* iGame is in range [0, GetFavoriteGameCount()) */
	virtual Bool GetFavoriteGame(Int32 iGame, /* [out] */ pAppId_t piAppId, /* [out] */ pUint32 pnIP, /* [out] */ pUint16 pnConnectionPort, /* [out] */ pUint16 pQueryPort, /* [out] */ pUint32 pnFlags, /* [out] */ pRTime32 pLastPlayedOnServer) = 0;
	
	virtual Int32 AddFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, Uint32 rTime32LastPlayedOnServer) = 0;
	virtual Bool RemoveFavoriteGame(AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) = 0;

	virtual SteamAPICall_t RequestLobbyList() = 0;
	virtual void AddRequestLobbyListStringFilter(pCStrA pchKeyToMatch, pCStrA pchValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListNumericalFilter(pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) = 0;
	virtual void AddRequestLobbyListNearValueFilter(pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) = 0;
	virtual void AddRequestLobbyListFilterSlotsAvailable(Int32 nSlotsAvailable) = 0;
	virtual void AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter) = 0;
	virtual void AddRequestLobbyListResultCountFilter(Int32 cMaxResults) = 0;
	virtual void AddRequestLobbyListCompatibleMembersFilter(SteamId_t SteamIdLobby) = 0;

	virtual SteamId_t GetLobbyByIndex(Int32 iLobby) = 0;
	virtual SteamAPICall_t CreateLobby(ELobbyType eLobbyType, Int32 cMaxMembers) = 0;
	virtual SteamAPICall_t JoinLobby(SteamId_t SteamIdLobby) = 0;
	virtual void LeaveLobby(SteamId_t SteamIdLobby) = 0;
	virtual Bool InviteUserToLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdInvite) = 0;

	virtual Int32 GetNumLobbyMembers(SteamId_t SteamIdLobby) = 0;
	virtual SteamId_t GetLobbyMemberByIndex(SteamId_t SteamIdLobby, Int32 iMember) = 0;

	/* "" when not set */
	virtual pCStrA GetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;
	virtual Bool SetLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Int32 GetLobbyDataCount(SteamId_t SteamIdLobby) = 0;
	virtual Bool GetLobbyDataByIndex(SteamId_t SteamIdLobby, Int32 iLobbyData, /* [out] */ pStrA pchKey, Int32 cchKey, /* [out] */ pStrA pchValue, Int32 cchValue) = 0;
	virtual Bool DeleteLobbyData(SteamId_t SteamIdLobby, pCStrA pchKey) = 0;

	/* "" when not set */
	virtual pCStrA GetLobbyMemberData(SteamId_t SteamIdLobby, SteamId_t SteamIdUser, pCStrA pchKey) = 0;
	virtual void SetLobbyMemberData(SteamId_t SteamIdLobby, pCStrA pchKey, pCStrA pchValue) = 0;

	virtual Bool SendLobbyChatMsg(SteamId_t SteamIdLobby, const pVoid pvMsgBody, Int32 cbMsgBody) = 0;
	virtual Int32 GetLobbyChatEntry(SteamId_t SteamIdLobby, Int32 iChatId, /* [out] */ pSteamId_t pSteamIdUser, /* [out] */ pVoid pvData, Int32 cbData, /* [out] */ pEChatEntryType peChatEntryType) = 0;
	virtual Bool RequestLobbyData(SteamId_t SteamIdLobby) = 0;
	
	virtual void SetLobbyGameServer(SteamId_t SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t SteamIdGameServer) = 0;
	virtual Bool GetLobbyGameServer(SteamId_t SteamIdLobby, /* [out] */ pUint32 pnGameServerIP, /* [out] */ pUint16 pnGameServerPort, /* [out] */ pSteamId_t pSteamIdGameServer) = 0;

	virtual Bool SetLobbyMemberLimit(SteamId_t SteamIdLobby, Int32 cMaxMembers) = 0;
	/* 0 when no limit is defined */
	virtual Int32 GetLobbyMemberLimit(SteamId_t SteamIdLobby) = 0;
	virtual Bool SetLobbyType(SteamId_t SteamIdLobby, ELobbyType eLobbyType) = 0;
	virtual Bool SetLobbyJoinable(SteamId_t SteamIdLobby, Bool bLobbyJoinable) = 0;
	virtual SteamId_t GetLobbyOwner(SteamId_t SteamIdLobby) = 0;
	virtual Bool SetLobbyOwner(SteamId_t SteamIdLobby, SteamId_t SteamIdNewOwner) = 0;
	virtual Bool SetLinkedLobby(SteamId_t SteamIdLobby, SteamId_t SteamIdLobbyDependent) = 0;

	#ifdef _PS3
	virtual void CheckForPSNGameBootInvite(Uint32 iGameBootAttributes) = 0;
	#endif

} ISteamMatchmaking, *IpSteamMatchmaking;

#define STEAMMATCHMAKING_INTERFACE_VERSION "SteamMatchMaking009"

typedef pVoid HServerListRequest, *pHServerListRequest;

typedef class _ISteamMatchmakingServerListResponse001_ {
public:

	virtual void ServerResponded(Int32 iServer) = 0;
	virtual void ServerFailedToRespond( Int32 iServer) = 0;
	virtual void RefreshComplete(EMatchMakingServerResponse eMatchMakingServerResponse) = 0;

} ISteamMatchmakingServerListResponse001, *IpSteamMatchmakingServerListResponse001;

// -----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after a server list refresh
//  or an individual server update.
// -----------------------------------------------------------------------------
typedef class _ISteamMatchmakingServerListResponse_ {
public:

	virtual void ServerResponded(HServerListRequest hRequest, Int32 iServer) = 0;
	virtual void ServerFailedToRespond(HServerListRequest hRequest, Int32 iServer) = 0;
	virtual void RefreshComplete(HServerListRequest hRequest, EMatchMakingServerResponse eMatchMakingServerResponse) = 0;

} ISteamMatchmakingServerListResponse, *IpSteamMatchmakingServerListResponse;

// -----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after pinging an individual server 
// -----------------------------------------------------------------------------
typedef class _ISteamMatchmakingPingResponse_ {
public:

	virtual void ServerResponded(/* [out] */ pGameServerItem_t pGameServerItem) = 0;
	virtual void ServerFailedToRespond() = 0;

} ISteamMatchmakingPingResponse, *IpSteamMatchmakingPingResponse;

// -----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after requesting details on
//  who is playing on a particular server.
// -----------------------------------------------------------------------------
typedef class _ISteamMatchmakingPlayersResponse_ {
public:

	virtual void AddPlayerToList(pCStrA pchName, Int32 nScore, Float TimePlayed) = 0;
	virtual void PlayersFailedToRespond() = 0;
	virtual void PlayersRefreshComplete() = 0;

} ISteamMatchmakingPlayersResponse, *IpSteamMatchmakingPlayersResponse;

// -----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after requesting rules
//  details on a particular server.
// -----------------------------------------------------------------------------
typedef class _ISteamMatchmakingRulesResponse_ {
public:

	virtual void RulesResponded(pCStrA pchRule, pCStrA pchValue) = 0;
	virtual void RulesFailedToRespond() = 0;
	virtual void RulesRefreshComplete() = 0;

} ISteamMatchmakingRulesResponse, *IpSteamMatchmakingRulesResponse;

typedef Int32 HServerQuery, *pHServerQuery;
#define k_HServerQuery_Invalid ((HServerQuery)(0xFFFFFFFF))

typedef enum _EMatchMakingType_ {

	k_EMatchMakingType_InternetServer,
	k_EMatchMakingType_LANServer,
	k_EMatchMakingType_FriendsServer,
	k_EMatchMakingType_FavoritesServer,
	k_EMatchMakingType_HistoryServer,
	k_EMatchMakingType_SpectatorServer,
	k_EMatchMakingType_InvalidServer

} EMatchMakingType, *pEMatchMakingType;

typedef class _ISteamMatchmakingServers001_ {
public:

	virtual void RequestInternetServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) = 0;
	virtual void RequestLANServerList(AppId_t iAppId, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) = 0;
	virtual void RequestFriendsServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) = 0;
	virtual void RequestFavoritesServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) = 0;
	virtual void RequestHistoryServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) = 0;
	virtual void RequestSpectatorServerList(AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse001 pRequestServersResponse) = 0;
	virtual pGameServerItem_t GetServerDetails(EMatchMakingType eMatchMakingType, Int32 iServer) = 0;
	virtual void CancelQuery(EMatchMakingType eMatchMakingType) = 0;
	virtual void RefreshQuery(EMatchMakingType eMatchMakingType) = 0;
	virtual Bool IsRefreshing(EMatchMakingType eMatchMakingType) = 0;
	virtual Int32 GetServerCount(EMatchMakingType eMatchMakingType) = 0;
	virtual void RefreshServer(EMatchMakingType eMatchMakingType, Int32 iServer) = 0;
	virtual HServerQuery PingServer(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPingResponse pRequestServersResponse) = 0;
	virtual HServerQuery PlayerDetails(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPlayersResponse pRequestServersResponse) = 0;
	virtual HServerQuery ServerRules(Uint32 nIP, Uint16 Port, IpSteamMatchmakingRulesResponse pRequestServersResponse) = 0;
	virtual void CancelServerQuery(HServerQuery hServerQuery) = 0;

} ISteamMatchmakingServers001, *IpSteamMatchmakingServers001;

// -----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to game lists and details
// -----------------------------------------------------------------------------
typedef class _ISteamMatchmakingServers_ {
public:

	virtual HServerListRequest RequestInternetServerList(AppId_t iApp, /* [out] */ pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) = 0;
	virtual HServerListRequest RequestLANServerList(AppId_t iApp, IpSteamMatchmakingServerListResponse pRequestServersResponse) = 0;
	virtual HServerListRequest RequestFriendsServerList(AppId_t iApp, /* [out] */ pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) = 0;
	virtual HServerListRequest RequestFavoritesServerList(AppId_t iApp, /* [out] */ pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) = 0;
	virtual HServerListRequest RequestHistoryServerList(AppId_t iApp, /* [out] */ pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) = 0;
	virtual HServerListRequest RequestSpectatorServerList(AppId_t iApp, /* [out] */ pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) = 0;
	
	virtual void ReleaseRequest(HServerListRequest hServerListRequest) = 0;

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

	virtual pGameServerItem_t GetServerDetails(HServerListRequest hRequest, Int32 iServer) = 0;

	virtual void CancelQuery(HServerListRequest hRequest) = 0;
	virtual void RefreshQuery(HServerListRequest hRequest) = 0;
	virtual Bool IsRefreshing(HServerListRequest hRequest) = 0;
	virtual Int32 GetServerCount(HServerListRequest hRequest) = 0;
	virtual void RefreshServer(HServerListRequest hRequest, Int32 iServer) = 0;

	virtual HServerQuery PingServer(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPingResponse pRequestServersResponse) = 0;
	virtual HServerQuery PlayerDetails(Uint32 nIP, Uint16 Port, IpSteamMatchmakingPlayersResponse pRequestServersResponse) = 0;
	virtual HServerQuery ServerRules(Uint32 nIP, Uint16 Port, IpSteamMatchmakingRulesResponse pRequestServersResponse) = 0;
	
	virtual void CancelServerQuery(HServerQuery hServerQuery) = 0;

} ISteamMatchmakingServers, *IpSteamMatchmakingServers;

#define STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION "SteamMatchMakingServers002"

#define k_nFavoriteFlagNone ((Uint32)(0x00000000))
#define k_nFavoriteFlagFavorite ((Uint32)(0x00000001))
#define k_nFavoriteFlagHistory ((Uint32)(0x00000002))

typedef enum _EChatMemberStateChange_ {

	k_EChatMemberStateChangeEntered = 0x00000001,
	k_EChatMemberStateChangeLeft = 0x00000002,
	k_EChatMemberStateChangeDisconnected = 0x00000004,
	k_EChatMemberStateChangeKicked = 0x00000008,
	k_EChatMemberStateChangeBanned = 0x00000010

} EChatMemberStateChange, *pEChatMemberStateChange;

#define BChatMemberStateChangeRemoved(rgChatMemberStateChangeFlags) ( \
 rgChatMemberStateChangeFlags & ( \
  k_EChatMemberStateChangeDisconnected | k_EChatMemberStateChangeLeft | k_EChatMemberStateChangeKicked | k_EChatMemberStateChangeBanned \
 ) \
)

// -----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to favorites
//  and to operate on game lobbies.
// -----------------------------------------------------------------------------
typedef class _ISteamGameSearch_ {
public:
	
	virtual EGameSearchErrorCode_t AddGameSearchParams(pCStrA pchKeyToFind, pCStrA pchValuesToFind) = 0;
	virtual EGameSearchErrorCode_t SearchForGameWithLobby(SteamId_t SteamIdLobby, Int32 nPlayerMin, Int32 nPlayerMax) = 0;
	virtual EGameSearchErrorCode_t SearchForGameSolo(Int32 nPlayerMin, Int32 nPlayerMax) = 0;
	virtual EGameSearchErrorCode_t AcceptGame() = 0;
	virtual EGameSearchErrorCode_t DeclineGame() = 0;
	virtual EGameSearchErrorCode_t RetrieveConnectionDetails(SteamId_t SteamIdHost, pStrA pchConnectionDetails, Int32 cbConnectionDetails) = 0;
	virtual EGameSearchErrorCode_t EndGameSearch() = 0;
	virtual EGameSearchErrorCode_t SetGameHostParams(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual EGameSearchErrorCode_t SetConnectionDetails(pCStrA pchConnectionDetails, Int32 cbConnectionDetails) = 0;
	virtual EGameSearchErrorCode_t RequestPlayersForGame(Int32 nPlayerMin, Int32 nPlayerMax, Int32 nMaxTeamSize) = 0;
	virtual EGameSearchErrorCode_t HostConfirmGameStart(Uint64 UniqueGameId) = 0;
	virtual EGameSearchErrorCode_t CancelRequestPlayersForGame() = 0;
	virtual EGameSearchErrorCode_t SubmitPlayerResult(Uint64 UniqueGameId, SteamId_t SteamIdPlayer, EPlayerResult_t EPlayerResult) = 0;
	virtual EGameSearchErrorCode_t EndGame(Uint64 UniqueGameId) = 0;

} ISteamGameSearch, *IpSteamGameSearch;

#define STEAMGAMESEARCH_INTERFACE_VERSION "SteamMatchGameSearch001"

typedef enum _ESteamPartyBeaconLocationType_ {

	k_ESteamPartyBeaconLocationType_Invalid,
	k_ESteamPartyBeaconLocationType_ChatGroup,
	k_ESteamPartyBeaconLocationType_Max

} ESteamPartyBeaconLocationType, *pESteamPartyBeaconLocationType;

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

typedef struct _SteamPartyBeaconLocation_t_ {

	ESteamPartyBeaconLocationType eSteamPartyBeaconLocationType;
	Uint64 LocationId;

} SteamPartyBeaconLocation_t, *pSteamPartyBeaconLocation_t;

#pragma pack(pop)

typedef enum _ESteamPartyBeaconLocationData_ {

	k_ESteamPartyBeaconLocationDataInvalid,
	k_ESteamPartyBeaconLocationDataName,
	k_ESteamPartyBeaconLocationDataIconURLSmall,
	k_ESteamPartyBeaconLocationDataIconURLMedium,
	k_ESteamPartyBeaconLocationDataIconURLLarge

} ESteamPartyBeaconLocationData, *pESteamPartyBeaconLocationData;

typedef class _ISteamParties_ {
public:

	virtual Uint32 GetNumActiveBeacons() = 0;
	virtual PartyBeaconId_t GetPartyBeaconIdByIndex(Uint32 iBeacon) = 0;
	virtual Bool GetBeaconDetails(PartyBeaconId_t PartyBeaconId, /* [out] */ pSteamId_t pSteamIdBeaconOwner, /* [out] */ pSteamPartyBeaconLocation_t pLocation, /* [out] */ pStrA pchMetadata, Int32 cchMetadata) = 0;
	virtual SteamAPICall_t JoinParty(PartyBeaconId_t PartyBeaconId) = 0;

	virtual Bool GetNumAvailableBeaconLocations(pUint32 pNumLocations) = 0;
	virtual Bool GetAvailableBeaconLocations(/* [out] */ pSteamPartyBeaconLocation_t pLocationList, Uint32 uMaxNumLocations) = 0;

	virtual SteamAPICall_t CreateBeacon(Uint32 nOpenSlots, pSteamPartyBeaconLocation_t pBeaconLocation, pCStrA pchConnectString, pCStrA pchMetadata) = 0;
	virtual void OnReservationCompleted(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) = 0;
	virtual void CancelReservation(PartyBeaconId_t PartyBeaconId, SteamId_t SteamIdUser) = 0;
	virtual SteamAPICall_t ChangeNumOpenSlots(PartyBeaconId_t PartyBeaconId, Uint32 nOpenSlots) = 0;
	virtual Bool DestroyBeacon(PartyBeaconId_t PartyBeaconId) = 0;

	virtual Bool GetBeaconLocationData(SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eSteamPartyBeaconLocationData, /* [out] */ pStrA pchDataString, Int32 cchDataString) = 0;

} ISteamParties, *IpSteamParties;

#define STEAMPARTIES_INTERFACE_VERSION "SteamParties002"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// -----------------------------------------------------------------------------
// Purpose: Server was added/removed from the favorites list, you should refresh now
// -----------------------------------------------------------------------------
#define k_iCallbback_FavoritesListChanged_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 2))
typedef struct _FavoritesListChanged_t_ {

	Uint32 nIP;
	Uint32 QueryPort;
	Uint32 nConnectionPort;
	Uint32 iAppId;
	Uint32 nFlags;
	Bool bAdd;
	AccountId_t AccountId;

} FavoritesListChanged_t, *pFavoritesListChanged_t;

// -----------------------------------------------------------------------------
// Purpose: Someone has invited you to join Lobby
//  normally you don't need to do anything with this, since
//  the Steam UI will also display '<user> has invited you to the lobby, join?' dialog
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyInvite_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 3))
typedef struct _LobbyInvite_t_ {

	Uint64 SteamIdUser;
	Uint64 SteamIdLobby;
	Uint64 GameId;

} LobbyInvite_t, *pLobbyInvite_t;

// -----------------------------------------------------------------------------
// Purpose: Sent on entering lobby
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyEnter_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 4))
typedef struct _LobbyEnter_t_ {

	Uint64 SteamIdLobby;
	Uint32 rgChatPermissions;
	Bool bLocked;
	EChatRoomEnterResponse eChatRoomEnterResponse;

} LobbyEnter_t, *pLobbyEnter_t;

// -----------------------------------------------------------------------------
// Purpose: The lobby metadata has changed
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyDataUpdate_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 5))
typedef struct _LobbyDataUpdate_t_ {

	Uint64 SteamIdLobby;
	Uint64 SteamIdMember;
	Uint8 bSuccess;

} LobbyDataUpdate_t, *pLobbyDataUpdate_t;

// -----------------------------------------------------------------------------
// Purpose: The lobby chat room state has changed
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyChatUpdate_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 6))
typedef struct _LobbyChatUpdate_t_ {

	Uint64 SteamIdLobby;
	Uint64 SteamIdUserChanged;
	Uint64 SteamIdMakingChange;
	Uint32 rgChatMemberStateChange;

} LobbyChatUpdate_t, *pLobbyChatUpdate_t;

// -----------------------------------------------------------------------------
// Purpose: Chat message for this lobby has been sent
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyChatMsg_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 7))
typedef struct _LobbyChatMsg_t_ {

	Uint64 SteamIdLobby;
	Uint64 SteamIdUser;
	Uint8 eChatEntryType;
	Uint32 iChatId;

} LobbyChatMsg_t, *pLobbyChatMsg_t;


// -----------------------------------------------------------------------------
// Purpose: A game created a game for all the members of the lobby to join,
//  as triggered by SetLobbyGameServer
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyGameCreated_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 9))
typedef struct _LobbyGameCreated_t_ {

	Uint64 SteamIdLobby;
	Uint64 SteamIdGameServer;
	Uint32 nIP;
	Uint16 Port;

} LobbyGameCreated_t, *pLobbyGameCreated_t;

// -----------------------------------------------------------------------------
// Purpose: Number of matching lobbies found
//  iterate the returned lobbies with GetLobbyByIndex
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyMatchList_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 10))
typedef struct _LobbyMatchList_t_ {

	Uint32 nLobbiesMatching;

} LobbyMatchList_t, *pLobbyMatchList_t;

// -----------------------------------------------------------------------------
// Purpose: Posted if user is forcefully removed from lobby
//  can occur if user loses connection to Steam
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyKicked_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 12))
typedef struct _LobbyKicked_t_ {

	Uint64 SteamIdLobby;
	Uint64 SteamIdAdmin;
	Uint8 bKickedDueToDisconnect;
} LobbyKicked_t, *pLobbyKicked_t;


// -----------------------------------------------------------------------------
// Purpose: Result of our request to create a Lobby
// -----------------------------------------------------------------------------
#define k_iCallbback_LobbyCreated_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 13))
typedef struct _LobbyCreated_t_ {

	/* k_EResultNoConnection - your Steam client doesn't have a connection to the back-end
	   k_EResultTimeout - you the message to the Steam servers, but it didn't respond
	   k_EResultFail - the server responded, but with an unknown internal error
	   k_EResultAccessDenied - your game isn't set to allow lobbies, or your client does haven't rights to play the game
	   k_EResultLimitExceeded - your game client has created too many lobbies */
	EResult eResult;
	Uint64 SteamIdLobby;

} LobbyCreated_t, *pLobbyCreated_t;

// -----------------------------------------------------------------------------
// Purpose: RequestFriendsLobbies Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RequestFriendsLobbiesResponse_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 14))
typedef struct _RequestFriendsLobbiesResponse_t_ {

	Uint64 SteamIdFriend;
	Uint64 SteamIdLobby;
	Int32 cResultIndex;
	Int32 cResultsTotal;

} RequestFriendsLobbiesResponse_t, *pRequestFriendsLobbiesResponse_t;

// -----------------------------------------------------------------------------
// Purpose: CheckForPSNGameBootInvite Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_PSNGameBootInviteResult_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 15))
typedef struct _PSNGameBootInviteResult_t_ {

	Bool bGameBootInviteExists;
	SteamId_t SteamIdLobby;

} PSNGameBootInviteResult_t, *pPSNGameBootInviteResult_t;

// -----------------------------------------------------------------------------
// Purpose: Result of our request to create a Lobby
// -----------------------------------------------------------------------------
#define k_iCallbback_FavoritesListAccountsUpdated_t_ ((Int32)(k_iSteamMatchmakingCallbacks + 16))
typedef struct _FavoritesListAccountsUpdated_t_ {

	EResult eResult;

} FavoritesListAccountsUpdated_t, *pFavoritesListAccountsUpdated_t;

#define k_iCallbback_SearchForGameProgressCallback_t_ ((Int32)(k_iSteamGameSearchCallbacks + 1))
typedef struct _SearchForGameProgressCallback_t_ {

	Uint64 SearchId;
	EResult eResult;
	SteamId_t LobbyId;
	SteamId_t SteamIdEndedSearch;
	Int32 nSecondsRemainingEstimate;
	Int32 cPlayersSearching;

} SearchForGameProgressCallback_t, *pSearchForGameProgressCallback_t;

#define k_iCallbback_SearchForGameResultCallback_t_ ((Int32)(k_iSteamGameSearchCallbacks + 2))
typedef struct _SearchForGameResultCallback_t_ {

	Uint64 SearchId;
	EResult eResult;
	Int32 nCountPlayersInGame;
	Int32 nCountAcceptedGame;
	SteamId_t SteamIdHost;
	Bool bFinalCallback;

} SearchForGameResultCallback_t, *pSearchForGameResultCallback_t;

#define k_iCallbback_RequestPlayersForGameProgressCallback_t_ ((Int32)(k_iSteamGameSearchCallbacks + 11))
typedef struct _RequestPlayersForGameProgressCallback_t_ {

	EResult eResult;
	Uint64  SearchId;

} RequestPlayersForGameProgressCallback_t, *pRequestPlayersForGameProgressCallback_t;

#define k_iCallbback_RequestPlayersForGameResultCallback_t_ ((Int32)(k_iSteamGameSearchCallbacks + 12))
#define k_iCallbback_RequestPlayersForGameResultCallback_t_k_EStateUnknown ((Int32)(0x00000000))
#define k_iCallbback_RequestPlayersForGameResultCallback_t_k_EStatePlayerAccepted ((Int32)(0x00000001))
#define k_iCallbback_RequestPlayersForGameResultCallback_t_k_EStatePlayerDeclined ((Int32)(0x00000002))
typedef struct _RequestPlayersForGameResultCallback_t_ {

	EResult eResult;
	Uint64  SearchId;
	SteamId_t SteamIdPlayerFound;
	SteamId_t SteamIdLobby;
	Int32 ePlayerAcceptState;
	Int32 nPlayerIndex;
	Int32 nTotalPlayersFound;
	Int32 nTotalPlayersAcceptedGame;
	Int32 nSuggestedTeamIndex;
	Uint64 UniqueGameId;

} RequestPlayersForGameResultCallback_t, *pRequestPlayersForGameResultCallback_t;

#define k_iCallbback_RequestPlayersForGameFinalResultCallback_t_ ((Int32)(k_iSteamGameSearchCallbacks + 13))
typedef struct _RequestPlayersForGameFinalResultCallback_t_ {

	EResult eResult;
	Uint64  SearchId;
	Uint64 UniqueGameId;

} RequestPlayersForGameFinalResultCallback_t, *pRequestPlayersForGameFinalResultCallback_t;

#define k_iCallbback_SubmitPlayerResultResultCallback_t_ ((Int32)(k_iSteamGameSearchCallbacks + 14))
typedef struct _SubmitPlayerResultResultCallback_t_ {

	EResult eResult;
	Uint64 UniqueGameId;
	SteamId_t SteamIdPlayer;

} SubmitPlayerResultResultCallback_t, *pSubmitPlayerResultResultCallback_t;

#define k_iCallbback_EndGameResultCallback_t_ ((Int32)(k_iSteamGameSearchCallbacks + 15))
typedef struct _EndGameResultCallback_t_ {

	EResult eResult;
	Uint64 UniqueGameId;

} EndGameResultCallback_t, *pEndGameResultCallback_t;

#define k_iCallbback_JoinPartyCallback_t_ ((Int32)(k_iSteamPartiesCallbacks + 1))
typedef struct _JoinPartyCallback_t_ {

	EResult eResult;
	PartyBeaconId_t PartyBeaconId;
	SteamId_t SteamIdBeaconOwner;
	CharA chConnectString[256];

} JoinPartyCallback_t, *pJoinPartyCallback_t;

#define k_iCallbback_CreateBeaconCallback_t_ ((Int32)(k_iSteamPartiesCallbacks + 2))
typedef struct _CreateBeaconCallback_t_ {

	EResult eResult;
	PartyBeaconId_t PartyBeaconId;

} CreateBeaconCallback_t, *pCreateBeaconCallback_t;

#define k_iCallbback_ReservationNotificationCallback_t_ ((Int32)(k_iSteamPartiesCallbacks + 3))
typedef struct _ReservationNotificationCallback_t_ {

	PartyBeaconId_t PartyBeaconId;
	SteamId_t SteamIdJoiner;

} ReservationNotificationCallback_t, *pReservationNotificationCallback_t;

#define k_iCallbback_ChangeNumOpenSlotsCallback_t_ ((Int32)(k_iSteamPartiesCallbacks + 4))
typedef struct _ChangeNumOpenSlotsCallback_t_ {

	EResult eResult;

} ChangeNumOpenSlotsCallback_t, *pChangeNumOpenSlotsCallback_t;

#define k_iCallbback_AvailableBeaconLocationsUpdated_t_ ((Int32)(k_iSteamPartiesCallbacks + 5))
typedef struct _AvailableBeaconLocationsUpdated_t_ {

	Int32 Unused;

} AvailableBeaconLocationsUpdated_t, *pAvailableBeaconLocationsUpdated_t;

#define k_iCallbback_ActiveBeaconsUpdated_t_ ((Int32)(k_iSteamPartiesCallbacks + 6))
typedef struct _ActiveBeaconsUpdated_t_ {

	Int32 Unused;

} ActiveBeaconsUpdated_t, *pActiveBeaconsUpdated_t;

#pragma pack(pop)

#endif // _ISTEAMMATCHMAKING_
