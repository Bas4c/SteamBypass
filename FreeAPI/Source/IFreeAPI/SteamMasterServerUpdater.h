#ifndef _STEAMMASTERSERVERUPDATER_
#define _STEAMMASTERSERVERUPDATER_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamMasterServerUpdater.h"
// -----------------------------------------------------------------------------

typedef class _SteamMasterServerUpdater_ : public _ISteamMasterServerUpdater_ {
public:

	_SteamMasterServerUpdater_() = default;
	_SteamMasterServerUpdater_(const _SteamMasterServerUpdater_&) = delete;
	_SteamMasterServerUpdater_& operator=(const _SteamMasterServerUpdater_&) = delete;

	void SetActive(Bool bActive) override;
	void SetHeartbeatInterval(Int32 iHeartbeatInterval) override;
	Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) override;
	Int32 GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdr, pUint16 pPort) override;
	void SetBasicServerData(Uint16 nProtocolVersion, Bool bDedicatedServer, pCStrA pchRegionName, pCStrA pchProductName, Uint16 nMaxReportedClients, Bool bPasswordProtected, pCStrA pchGameDescription) override;
	void ClearAllKeyValues() override;
	void SetKeyValue(pCStrA pchKey, pCStrA pchValue) override;
	void NotifyShutdown() override;
	Bool WasRestartRequested() override;
	void ForceHeartbeat() override;
	Bool AddMasterServer(pCStrA pchServerAddress) override;
	Bool RemoveMasterServer(pCStrA pchServerAddress) override;
	Int32 GetNumMasterServers() override;
	Int32 GetMasterServerAddress(Int32 iServer, pStrA pchOut, Int32 cchOut) override;

	~_SteamMasterServerUpdater_() = default;

} SteamMasterServerUpdater, *pSteamMasterServerUpdater;

#endif // !_STEAMMASTERSERVERUPDATER_
