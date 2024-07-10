// -----------------------------------------------------------------------------
#include "SteamGameStats.h"
// -----------------------------------------------------------------------------

SteamAPICall_t _SteamGameStats_::GetNewSession(Int8 AccountType, Uint64 AccountId, Int32 iAppId, RTime32 TimeStarted) {
	DEBUGBREAK("ISteamGameStats::GetNewSession");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamGameStats_::EndSession(Uint64 SessSessionIdionId, RTime32 TimeEnded, Int32 ReasonCode) {
	DEBUGBREAK("ISteamGameStats::EndSession");
	
	return k_SteamAPICall_Invalid;

}

EResult _SteamGameStats_::AddSessionAttributeInt(Uint64 SessionId, pCStrA pchName, Int32 Data) {
	DEBUGBREAK("ISteamGameStats::AddSessionAttributeInt");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::AddSessionAttributeString(Uint64 SessionId, pCStrA pchName, pCStrA pchData) {
	DEBUGBREAK("ISteamGameStats::AddSessionAttributeString");

	return k_EResultFail;

}

EResult _SteamGameStats_::AddSessionAttributeFloat(Uint64 SessionId, pCStrA pchName, Float Data) {
	DEBUGBREAK("ISteamGameStats::AddSessionAttributeFloat");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::AddNewRow(pUint64 pRowId, Uint64 SessionId, pCStrA pchTableName) {
	DEBUGBREAK("ISteamGameStats::AddNewRow");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::CommitRow(Uint64 RowId) {
	DEBUGBREAK("ISteamGameStats::CommitRow");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::CommitOutstandingRows(Uint64 SessionId) {
	DEBUGBREAK("ISteamGameStats::CommitOutstandingRows");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::AddRowAttributeInt(Uint64 RowId, pCStrA pchName, Int32 Data) {
	DEBUGBREAK("ISteamGameStats::AddRowAttributeInt");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::AddRowAtributeString(Uint64 RowId, pCStrA pchName, pCStrA pchData) {
	DEBUGBREAK("ISteamGameStats::AddRowAtributeString");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::AddRowAttributeFloat(Uint64 RowId, pCStrA pchName, Float Data) {
	DEBUGBREAK("ISteamGameStats::AddRowAttributeFloat");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::AddSessionAttributeInt64(Uint64 SessionId, pCStrA pchName, Int64 Data) {
	DEBUGBREAK("ISteamGameStats::AddSessionAttributeInt64");
	
	return k_EResultFail;

}

EResult _SteamGameStats_::AddRowAttributeInt64(Uint64 RowId, pCStrA pchName, Int64 Data) {
	DEBUGBREAK("ISteamGameStats::AddRowAttributeInt64");
	
	return k_EResultFail;

}
