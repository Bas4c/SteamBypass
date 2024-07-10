#ifndef _ISTEAMGAMESTATS_
#define _ISTEAMGAMESTATS_

#include "..\..\FreeAPI.Typedef.h"

//-----------------------------------------------------------------------------
// Purpose: AccountType for GetNewSession
//-----------------------------------------------------------------------------
typedef enum _EGameStatsAccountType_ {

	k_EGameStatsAccountType_Steam = 1,
	k_EGameStatsAccountType_Xbox = 2,
	k_EGameStatsAccountType_SteamGameServer = 3

} EGameStatsAccountType, *pEGameStatsAccountType;

// -----------------------------------------------------------------------------
// Purpose: Functions for recording game play sessions and details thereof
// -----------------------------------------------------------------------------
typedef class _ISteamGameStats_ {
public:

	virtual SteamAPICall_t GetNewSession(Int8 AccountType, Uint64 AccountId, Int32 iAppId, RTime32 TimeStarted) = 0;
	virtual SteamAPICall_t EndSession(Uint64 SessSessionIdionId, RTime32 TimeEnded, Int32 ReasonCode) = 0;
	virtual EResult AddSessionAttributeInt(Uint64 SessionId, pCStrA pchName, Int32 Data) = 0;
	virtual EResult AddSessionAttributeString(Uint64 SessionId, pCStrA pchName, pCStrA pchData) = 0;
	virtual EResult AddSessionAttributeFloat(Uint64 SessionId, pCStrA pchName, Float Data) = 0;

	virtual EResult AddNewRow(pUint64 pRowId, Uint64 SessionId, pCStrA pchTableName) = 0;
	virtual EResult CommitRow(Uint64 RowId) = 0;
	virtual EResult CommitOutstandingRows(Uint64 SessionId) = 0;
	virtual EResult AddRowAttributeInt(Uint64 RowId, pCStrA pchName, Int32 Data) = 0;
	virtual EResult AddRowAtributeString(Uint64 RowId, pCStrA pchName, pCStrA pchData) = 0;
	virtual EResult AddRowAttributeFloat(Uint64 RowId, pCStrA pchName, Float Data) = 0;

	virtual EResult AddSessionAttributeInt64(Uint64 SessionId, pCStrA pchName, Int64 Data) = 0;
	virtual EResult AddRowAttributeInt64(Uint64 RowId, pCStrA pchName, Int64 Data) = 0;

} ISteamGameStats, *IpSteamGameStats;

#define STEAMGAMESTATS_INTERFACE_VERSION  "SteamGameStats001"

//-----------------------------------------------------------------------------
// Purpose: Callback for GetNewSession() method
//-----------------------------------------------------------------------------
#define k_iCallbback_GameStatsSessionIssued_t ((Int32)(k_iSteamGameStatsCallbacks + 1))
typedef struct _GameStatsSessionIssued_t_ {

	Uint64	SessionId;
	EResult	eResult;
	Bool	bCollectingAny;
	Bool	bCollectingDetails;

} GameStatsSessionIssued_t, *pGameStatsSessionIssued_t;

//-----------------------------------------------------------------------------
// Purpose: Callback for EndSession() method
//-----------------------------------------------------------------------------
#define k_iCallbback_GameStatsSessionClosed_t ((Int32)(k_iSteamGameStatsCallbacks + 2))
typedef struct _GameStatsSessionClosed_t_{

	Uint64	SessionId;
	EResult	eResult;

} GameStatsSessionClosed_t, *pGameStatsSessionClosed_t;

#endif // !_ISTEAMGAMESTATS_
