#ifndef _STEAMGAMESTATS_
#define _STEAMGAMESTATS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamGameStats.h"
// -----------------------------------------------------------------------------

typedef class _SteamGameStats_ : public _ISteamGameStats_ {
public:

	SteamAPICall_t GetNewSession(Int8 AccountType, Uint64 AccountId, Int32 iAppId, RTime32 TimeStarted) override;
	SteamAPICall_t EndSession(Uint64 SessSessionIdionId, RTime32 TimeEnded, Int32 ReasonCode) override;
	EResult AddSessionAttributeInt(Uint64 SessionId, pCStrA pchName, Int32 Data) override;
	EResult AddSessionAttributeString(Uint64 SessionId, pCStrA pchName, pCStrA pchData) override;
	EResult AddSessionAttributeFloat(Uint64 SessionId, pCStrA pchName, Float Data) override;

	EResult AddNewRow(pUint64 pRowId, Uint64 SessionId, pCStrA pchTableName) override;
	EResult CommitRow(Uint64 RowId) override;
	EResult CommitOutstandingRows(Uint64 SessionId) override;
	EResult AddRowAttributeInt(Uint64 RowId, pCStrA pchName, Int32 Data) override;
	EResult AddRowAtributeString(Uint64 RowId, pCStrA pchName, pCStrA pchData) override;
	EResult AddRowAttributeFloat(Uint64 RowId, pCStrA pchName, Float Data) override;

	EResult AddSessionAttributeInt64(Uint64 SessionId, pCStrA pchName, Int64 Data) override;
	EResult AddRowAttributeInt64(Uint64 RowId, pCStrA pchName, Int64 Data) override;

} SteamGameStats, *pSteamGameStats;

#endif // !_STEAMGAMESTATS_
