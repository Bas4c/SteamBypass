#ifndef _ISTEAMMASTERSERVERUPDATER_
#define _ISTEAMMASTERSERVERUPDATER_

#include "..\..\FreeAPI.Typedef.h"

// -----------------------------------------------------------------------------
// Purpose: Game engines use this to tell the Steam master servers
//  about their games so their games can show up in the server browser.
// -----------------------------------------------------------------------------
typedef class _ISteamMasterServerUpdater_ {
public:

	virtual void SetActive(Bool bActive) = 0;
	virtual void SetHeartbeatInterval(Int32 iHeartbeatInterval) = 0;
	virtual Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) = 0;
	virtual Int32 GetNextOutgoingPacket(/* [out] */ pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdr, pUint16 pPort) = 0;
	virtual void SetBasicServerData(Uint16 nProtocolVersion, Bool bDedicatedServer, pCStrA pchRegionName, pCStrA pchProductName, Uint16 nMaxReportedClients, Bool bPasswordProtected, pCStrA pchGameDescription) = 0;
	virtual void ClearAllKeyValues() = 0;
	virtual void SetKeyValue(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual void NotifyShutdown() = 0;
	virtual Bool WasRestartRequested() = 0;
	virtual void ForceHeartbeat() = 0;
	virtual Bool AddMasterServer(pCStrA pchServerAddress) = 0;
	virtual Bool RemoveMasterServer(pCStrA pchServerAddress) = 0;
	virtual Int32 GetNumMasterServers() = 0;
	virtual Int32 GetMasterServerAddress(Int32 iServer, /* [out] */ pStrA pchOut, Int32 cchOut) = 0;

} ISteamMasterServerUpdater, *IpSteamMasterServerUpdater;

#define STEAMMASTERSERVERUPDATER_INTERFACE_VERSION "SteamMasterServerUpdater001"

#endif // _ISTEAMMASTERSERVERUPDATER_
