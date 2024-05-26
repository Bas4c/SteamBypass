// -----------------------------------------------------------------------------
#include "SteamMasterServerUpdater.h"
// -----------------------------------------------------------------------------

void _SteamMasterServerUpdater_::SetActive(Bool bActive) {
	DEBUGBREAK("ISteamMasterServerUpdater::SetActive");

	/* Empty Method */

}

void _SteamMasterServerUpdater_::SetHeartbeatInterval(Int32 iHeartbeatInterval) {
	DEBUGBREAK("ISteamMasterServerUpdater::SetHeartbeatInterval");

	/* Empty Method */

}

Bool _SteamMasterServerUpdater_::HandleIncomingPacket(pCVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) {
	DEBUGBREAK("ISteamMasterServerUpdater::HandleIncomingPacket");

	return False;

}

Int32 _SteamMasterServerUpdater_::GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdr, pUint16 pPort) {
	DEBUGBREAK("ISteamMasterServerUpdater::GetNextOutgoingPacket");

	return 0;

}

void _SteamMasterServerUpdater_::SetBasicServerData(Uint16 nProtocolVersion, Bool bDedicatedServer, pCStrA pchRegionName, pCStrA pchProductName, Uint16 nMaxReportedClients, Bool bPasswordProtected, pCStrA pchGameDescription) {
	DEBUGBREAK("ISteamMasterServerUpdater::SetBasicServerData");

	/* Empty Method */

}

void _SteamMasterServerUpdater_::ClearAllKeyValues() {
	DEBUGBREAK("ISteamMasterServerUpdater::ClearAllKeyValues");

	/* Empty Method */

}

void _SteamMasterServerUpdater_::SetKeyValue(pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamMasterServerUpdater::SetKeyValue");

	/* Empty Method */

}

void _SteamMasterServerUpdater_::NotifyShutdown() {
	DEBUGBREAK("ISteamMasterServerUpdater::NotifyShutdown");

	/* Empty Method */

}

Bool _SteamMasterServerUpdater_::WasRestartRequested() {
	DEBUGBREAK("ISteamMasterServerUpdater::WasRestartRequested");

	return False;

}

void _SteamMasterServerUpdater_::ForceHeartbeat() {
	DEBUGBREAK("ISteamMasterServerUpdater::ForceHeartbeat");

	/* Empty Method */

}

Bool _SteamMasterServerUpdater_::AddMasterServer(pCStrA pchServerAddress) {
	DEBUGBREAK("ISteamMasterServerUpdater::AddMasterServer");

	return False;

}

Bool _SteamMasterServerUpdater_::RemoveMasterServer(pCStrA pchServerAddress) {
	DEBUGBREAK("ISteamMasterServerUpdater::RemoveMasterServer");

	return False;

}

Int32 _SteamMasterServerUpdater_::GetNumMasterServers() {
	DEBUGBREAK("ISteamMasterServerUpdater::GetNumMasterServers");

	return 0;

}

Int32 _SteamMasterServerUpdater_::GetMasterServerAddress(Int32 iServer, pStrA pchOut, Int32 cchOut) {
	DEBUGBREAK("ISteamMasterServerUpdater::GetMasterServerAddress");

	return 0;

}
