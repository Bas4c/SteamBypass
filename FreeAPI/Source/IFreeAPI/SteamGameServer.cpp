// -----------------------------------------------------------------------------
#include "SteamGameServer.h"
// -----------------------------------------------------------------------------

Bool _SteamGameServer_::InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, pCStrA pchVersionString) {
	DEBUGBREAK("ISteamGameServer::InitGameServer");

	return True;

}

void _SteamGameServer_::SetProduct(pCStrA pchProduct) {
	DEBUGBREAK("ISteamGameServer::SetProduct");

	/* Empty Method */

}

void _SteamGameServer_::SetGameDescription(pCStrA pchGameDescription) {
	DEBUGBREAK("ISteamGameServer::SetGameDescription");

	/* Empty Method */

}

void _SteamGameServer_::SetModDir(pCStrA pchModDir) {
	DEBUGBREAK("ISteamGameServer::SetModDir");

	/* Empty Method */

}

void _SteamGameServer_::SetDedicatedServer(Bool bDedicated) {
	DEBUGBREAK("ISteamGameServer::SetDedicatedServer");

	/* Empty Method */

}

void _SteamGameServer_::LogOn() {
	DEBUGBREAK("ISteamGameServer::LogOn");

	/* Empty Method */

}

void _SteamGameServer_::LogOn(pCStrA pchAccountName, pCStrA pchPassword) {
	DEBUGBREAK("ISteamGameServer::LogOn");

	/* Empty Method */

}

void _SteamGameServer_::LogOn(pCStrA pchToken) {
	DEBUGBREAK("ISteamGameServer::LogOn");

	/* Empty Method */

}

void _SteamGameServer_::LogOnAnonymous() {
	DEBUGBREAK("ISteamGameServer::LogOnAnonymous");

	/* Empty Method */

}

void _SteamGameServer_::LogOff() {
	DEBUGBREAK("ISteamGameServer::LogOff");

	/* Empty Method */

}

Bool _SteamGameServer_::BLoggedOn() {
	DEBUGBREAK("ISteamGameServer::BLoggedOn");

	return True;

}

Bool _SteamGameServer_::BSecure() {
	DEBUGBREAK("ISteamGameServer::BSecure");

	return True;

}

SteamId_t _SteamGameServer_::GetSteamID() {
	DEBUGBREAK("ISteamGameServer::GetSteamID");

	return SteamId_t{ k_SteamId_t_LocalUser };

}

Bool _SteamGameServer_::WasRestartRequested() {
	DEBUGBREAK("ISteamGameServer::WasRestartRequested");

	return False;

}

void _SteamGameServer_::SetMaxPlayerCount(Int32 cPlayersMax) {
	DEBUGBREAK("ISteamGameServer::SetMaxPlayerCount");

	/* Empty Method */

}

void _SteamGameServer_::SetBotPlayerCount(Int32 cBotplayers) {
	DEBUGBREAK("ISteamGameServer::SetBotPlayerCount");

	/* Empty Method */

}

void _SteamGameServer_::SetServerName(pCStrA pchServerName) {
	DEBUGBREAK("ISteamGameServer::SetServerName");

	/* Empty Method */

}

void _SteamGameServer_::SetMapName(pCStrA pchMapName) {
	DEBUGBREAK("ISteamGameServer::SetMapName");

	/* Empty Method */

}

void _SteamGameServer_::SetPasswordProtected(Bool bPasswordProtected) {
	DEBUGBREAK("ISteamGameServer::SetPasswordProtected");

	/* Empty Method */

}

void _SteamGameServer_::SetSpectatorPort(Uint16 SpectatorPort) {
	DEBUGBREAK("ISteamGameServer::SetSpectatorPort");

	/* Empty Method */

}

void _SteamGameServer_::SetSpectatorServerName(pCStrA pchSpectatorServerName) {
	DEBUGBREAK("ISteamGameServer::SetSpectatorServerName");

	/* Empty Method */

}

void _SteamGameServer_::ClearAllKeyValues() {
	DEBUGBREAK("ISteamGameServer::ClearAllKeyValues");

	/* Empty Method */

}

void _SteamGameServer_::SetKeyValue(pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamGameServer::SetKeyValue");

	/* Empty Method */

}

void _SteamGameServer_::SetGameTags(pCStrA pchGameTags) {
	DEBUGBREAK("ISteamGameServer::SetGameTags");

	/* Empty Method */

}

void _SteamGameServer_::SetGameData(pCStrA pchGameData) {
	DEBUGBREAK("ISteamGameServer::SetGameData");

	/* Empty Method */

}

void _SteamGameServer_::SetRegion(pCStrA pchRegion) {
	DEBUGBREAK("ISteamGameServer::SetRegion");

	/* Empty Method */

}

void _SteamGameServer_::SetAdvertiseServerActive(Bool bActive) {
	DEBUGBREAK("ISteamGameServer::SetAdvertiseServerActive");

	/* Empty Method */

}

HAuthTicket _SteamGameServer_::GetAuthSessionTicket_Old(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) {
	DEBUGBREAK("ISteamGameServer::GetAuthSessionTicket_Old");
	
	if (pvTicket != NULL && cbMaxTicket > 0) {
		if (pcbTicket != NULL) {

			for (Int32 i = 0; i < cbMaxTicket; i++) {
				((pByte)(pvTicket))[i] = (Byte)(i % 256);
			}

			*pcbTicket = cbMaxTicket;
			return k_HAuthTicket_Fake_Ticket;

		}
	}

	return k_HAuthTicket_Invalid;

}

HAuthTicket _SteamGameServer_::GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSnId) {
	DEBUGBREAK("ISteamGameServer::GetAuthSessionTicket");

	if (pvTicket != NULL && cbMaxTicket > 0) {
		if (pcbTicket != NULL) {

			for (Int32 i = 0; i < cbMaxTicket; i++) {
				((pByte)(pvTicket))[i] = (Byte)(i % 256);
			}

			*pcbTicket = cbMaxTicket;
			return k_HAuthTicket_Fake_Ticket;

		}
	}

	return k_HAuthTicket_Invalid;

}

EBeginAuthSessionResult _SteamGameServer_::BeginAuthSession(pCVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) {
	DEBUGBREAK("ISteamGameServer::BeginAuthSession");

	return k_EBeginAuthSessionResultOK;

}

void _SteamGameServer_::EndAuthSession(SteamId_t SteamId) {
	DEBUGBREAK("ISteamGameServer::EndAuthSession");

	/* Empty Method */

}

void _SteamGameServer_::CancelAuthTicket(HAuthTicket hAuthTicket) {
	DEBUGBREAK("ISteamGameServer::CancelAuthTicket");

	/* Empty Method */

}

EUserHasLicenseForAppResult _SteamGameServer_::UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) {
	DEBUGBREAK("ISteamGameServer::UserHasLicenseForApp");

	return k_EUserHasLicenseResultHasLicense;

}

Bool _SteamGameServer_::RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) {
	DEBUGBREAK("ISteamGameServer::RequestUserGroupStatus");

	return True;

}

void _SteamGameServer_::GetGameplayStats() {
	DEBUGBREAK("ISteamGameServer::GetGameplayStats");

	/* Empty Method */

}

SteamAPICall_t _SteamGameServer_::GetServerReputation() {
	DEBUGBREAK("ISteamGameServer::GetServerReputation");

	return k_SteamAPICall_Invalid;

}

Uint32 _SteamGameServer_::GetPublicIP_Old() {
	DEBUGBREAK("ISteamGameServer::GetPublicIP_Old");

	return ((((Uint32)((Byte)(127))) << 24) | (((Uint32)((Byte)(0))) << 16) |
		(((Uint32)((Byte)(0))) << 8) | (((Uint32)((Byte)(1)))));

}

SteamIPAddress_t _SteamGameServer_::GetPublicIP() {
	DEBUGBREAK("ISteamGameServer::GetPublicIP");

	/* localhost */

	SteamIPAddress_t steamIPAdrress = { 0 };
	steamIPAdrress.eSteamIPType = k_ESteamIPTypeIPv4;
	steamIPAdrress.IPv4 = ((((Uint32)((Byte)(127))) << 24) | (((Uint32)((Byte)(0))) << 16) |
		(((Uint32)((Byte)(0))) << 8) | (((Uint32)((Byte)(1)))));

	return steamIPAdrress;

}

Bool _SteamGameServer_::HandleIncomingPacket(pCVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) {
	DEBUGBREAK("ISteamGameServer::HandleIncomingPacket");

	return True;

}

Int32 _SteamGameServer_::GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) {
	DEBUGBREAK("ISteamGameServer::GetNextOutgoingPacket");

	return 0;

}

void _SteamGameServer_::EnableHeartbeats(Bool bActive) {
	DEBUGBREAK("ISteamGameServer::EnableHeartbeats");

	/* Empty Method */

}

void _SteamGameServer_::SetHeartbeatInterval(Int32 iHeartbeatInterval) {
	DEBUGBREAK("ISteamGameServer::SetHeartbeatInterval");

	/* Empty Method */

}

void _SteamGameServer_::ForceHeartbeat() {
	DEBUGBREAK("ISteamGameServer::ForceHeartbeat");

	/* Empty Method */

}

SteamAPICall_t _SteamGameServer_::AssociateWithClan(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamGameServer::AssociateWithClan");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamGameServer_::ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) {
	DEBUGBREAK("ISteamGameServer::ComputeNewPlayerCompatibility");

	return k_SteamAPICall_Invalid;

}

Bool _SteamGameServer_::SendUserConnectAndAuthenticate(Uint32 nIPClient, pCVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) {
	DEBUGBREAK("ISteamGameServer::SendUserConnectAndAuthenticate");

	if (pSteamIdUser != NULL) {
		*pSteamIdUser = SteamId_t{ k_SteamId_t_LocalUser };
	}

	return True;

}

SteamId_t _SteamGameServer_::CreateUnauthenticatedUserConnection() {
	DEBUGBREAK("ISteamGameServer::CreateUnauthenticatedUserConnection");

	return SteamId_t{ k_SteamId_t_LocalUser };

}

void _SteamGameServer_::SendUserDisconnect(SteamId_t SteamIdUser) {
	DEBUGBREAK("ISteamGameServer::SendUserDisconnect");

	/* Empty Method */

}

Bool _SteamGameServer_::BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) {
	DEBUGBREAK("ISteamGameServer::BUpdateUserData");

	return True;

}

Bool _SteamGameServer_::BSetServerType(Uint32 nServerFlags, Uint32 nGameIP, Uint16 nGamePort, Uint16 SpectatorPort, Uint16 QueryPort, pCStrA pchGameDir, pCStrA pchVersion, Bool bLANMode) {
	DEBUGBREAK("ISteamGameServer::BSetServerType");
	
	return True;

}

void _SteamGameServer_::UpdateServerStatus(Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pSpectatorServerName, pCStrA pchMapName) {
	DEBUGBREAK("ISteamGameServer::UpdateServerStatus");

	/* Empty Method */

}

void _SteamGameServer_::UpdateSpectatorPort(Uint16 SpectatorPort) {
	DEBUGBREAK("ISteamGameServer::UpdateSpectatorPort");

	/* Empty Method */

}

void _SteamGameServer_::SetGameType(pCStrA pchGameType) {
	DEBUGBREAK("ISteamGameServer::SetGameType");

	/* Empty Method */

}

Bool _SteamGameServer_::BGetUserAchievementStatus(SteamId_t SteamId, pCStrA pchAchievementName) {
	DEBUGBREAK("ISteamGameServer::BGetUserAchievementStatus");
	
	return False;

}

void _SteamGameServer_::SetMasterServerHeartbeatInterval_DEPRECATED(Int32 iHeartbeatInterval) {
	DEBUGBREAK("ISteamGameServer::SetMasterServerHeartbeatInterval_DEPRECATED");

	/* Empty Method */

}

void _SteamGameServer_::ForceMasterServerHeartbeat_DEPRECATED() {
	DEBUGBREAK("ISteamGameServer::ForceMasterServerHeartbeat_DEPRECATED");

	/* Empty Method */

}
