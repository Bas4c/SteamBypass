// -----------------------------------------------------------------------------
#include "SteamMasterServerUpdater.h"
// -----------------------------------------------------------------------------

void _SteamMasterServerUpdater_::SetActive(Bool bActive) {

	/* Empty Method */

}

void _SteamMasterServerUpdater_::SetHeartbeatInterval(Int32 iHeartbeatInterval) {

	/* Empty Method */

}

Bool _SteamMasterServerUpdater_::HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) {

	return False;

}

Int32 _SteamMasterServerUpdater_::GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdr, pUint16 pPort) {

	return 0;

}

void _SteamMasterServerUpdater_::SetBasicServerData(Uint16 nProtocolVersion, Bool bDedicatedServer, pCStrA pchRegionName, pCStrA pchProductName, Uint16 nMaxReportedClients, Bool bPasswordProtected, pCStrA pchGameDescription) {

	/* Empty Method */

}

void _SteamMasterServerUpdater_::ClearAllKeyValues() {

	/* Empty Method */

}

void _SteamMasterServerUpdater_::SetKeyValue(pCStrA pchKey, pCStrA pchValue) {

	/* Empty Method */

}

void _SteamMasterServerUpdater_::NotifyShutdown() {

	/* Empty Method */

}

Bool _SteamMasterServerUpdater_::WasRestartRequested() {

	return False;

}

void _SteamMasterServerUpdater_::ForceHeartbeat() {

	/* Empty Method */

}

Bool _SteamMasterServerUpdater_::AddMasterServer(pCStrA pchServerAddress) {

	return False;

}

Bool _SteamMasterServerUpdater_::RemoveMasterServer(pCStrA pchServerAddress) {

	return False;

}

Int32 _SteamMasterServerUpdater_::GetNumMasterServers() {

	return 0;

}

Int32 _SteamMasterServerUpdater_::GetMasterServerAddress(Int32 iServer, pStrA pchOut, Int32 cchOut) {

	return 0;

}
