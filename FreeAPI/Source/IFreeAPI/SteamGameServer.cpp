// -----------------------------------------------------------------------------
#include "SteamGameServer.h"
// -----------------------------------------------------------------------------

Bool _SteamGameServer_::InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, const pStrA pchVersionString) {

	return True;

}

void _SteamGameServer_::SetProduct(const pStrA pchProduct) {

	/* Empty Method */

}

void _SteamGameServer_::SetGameDescription(const pStrA pchGameDescription) {

	/* Empty Method */

}

void _SteamGameServer_::SetModDir(const pStrA pchModDir) {

	/* Empty Method */

}

void _SteamGameServer_::SetDedicatedServer(Bool bDedicated) {

	/* Empty Method */

}

void _SteamGameServer_::LogOn(const pStrA pchToken) {

	/* Empty Method */

}

void _SteamGameServer_::LogOnAnonymous() {

	/* Empty Method */

}

void _SteamGameServer_::LogOff() {

	/* Empty Method */

}

Bool _SteamGameServer_::BLoggedOn() {

	return True;

}

Bool _SteamGameServer_::BSecure() {

	return True;

}

SteamId_t _SteamGameServer_::GetSteamID() {

	return k_SteamId_t_Create(
		k_EUniversePublic, k_EAccountTypeIndividual,
		0xFFFFF, 0xFFFFFFFF
	);

}

Bool _SteamGameServer_::WasRestartRequested() {

	return False;

}

void _SteamGameServer_::SetMaxPlayerCount(Int32 cPlayersMax) {

	/* Empty Method */

}

void _SteamGameServer_::SetBotPlayerCount(Int32 cBotplayers) {

	/* Empty Method */

}

void _SteamGameServer_::SetServerName(const pStrA pchServerName) {

	/* Empty Method */

}

void _SteamGameServer_::SetMapName(const pStrA pchMapName) {

	/* Empty Method */

}

void _SteamGameServer_::SetPasswordProtected(Bool bPasswordProtected) {

	/* Empty Method */

}

void _SteamGameServer_::SetSpectatorPort(Uint16 SpectatorPort) {

	/* Empty Method */

}

void _SteamGameServer_::SetSpectatorServerName(const pStrA pchSpectatorServerName) {

	/* Empty Method */

}

void _SteamGameServer_::ClearAllKeyValues() {

	/* Empty Method */

}

void _SteamGameServer_::SetKeyValue(const pStrA pchKey, const pStrA pchValue) {

	/* Empty Method */

}

void _SteamGameServer_::SetGameTags(const pStrA pchGameTags) {

	/* Empty Method */

}

void _SteamGameServer_::SetGameData(const pStrA pchGameData) {

	/* Empty Method */

}

void _SteamGameServer_::SetRegion(const pStrA pchRegion) {

	/* Empty Method */

}

void _SteamGameServer_::SetAdvertiseServerActive(Bool bActive) {

	/* Empty Method */

}

HAuthTicket _SteamGameServer_::GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSnId) {

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

EBeginAuthSessionResult _SteamGameServer_::BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) {

	return k_EBeginAuthSessionResultOK;

}

void _SteamGameServer_::EndAuthSession(SteamId_t SteamId) {

	/* Empty Method */

}

void _SteamGameServer_::CancelAuthTicket(HAuthTicket hAuthTicket) {

	/* Empty Method */

}

EUserHasLicenseForAppResult _SteamGameServer_::UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) {

	return k_EUserHasLicenseResultHasLicense;

}

Bool _SteamGameServer_::RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) {

	return True;

}

void _SteamGameServer_::GetGameplayStats() {

	/* Empty Method */

}

SteamAPICall_t _SteamGameServer_::GetServerReputation() {

	return k_SteamAPICall_Invalid;

}

SteamIPAddress_t _SteamGameServer_::GetPublicIP() {

	/* localhost */

	SteamIPAddress_t steamIPAdrress;
	steamIPAdrress.eSteamIPType = k_ESteamIPTypeIPv4;
	steamIPAdrress.IPv4 = ((((Uint32)((Byte)(127))) << 24) | (((Uint32)((Byte)(0))) << 16) |
		(((Uint32)((Byte)(0))) << 8) | (((Uint32)((Byte)(1)))));

	return steamIPAdrress;

}

Bool _SteamGameServer_::HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) {

	return True;

}

Int32 _SteamGameServer_::GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) {

	return 0;

}

SteamAPICall_t _SteamGameServer_::AssociateWithClan(SteamId_t SteamIdClan) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamGameServer_::ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamGameServer_::SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) {

	return True;

}

SteamId_t _SteamGameServer_::CreateUnauthenticatedUserConnection() {

	return k_SteamId_t_Create(
		k_EUniversePublic, k_EAccountTypeIndividual,
		0xFFFFF, 0xFFFFFFFF
	);

}

void _SteamGameServer_::SendUserDisconnect(SteamId_t SteamIdUser) {

	/* Empty Method */

}

Bool _SteamGameServer_::BUpdateUserData(SteamId_t SteamIdUser, const pStrA pchPlayerName, Uint32 Score) {

	return True;

}

void _SteamGameServer_::SetMasterServerHeartbeatInterval_DEPRECATED(Int32 iHeartbeatInterval) {

	/* Empty Method */

}

void _SteamGameServer_::ForceMasterServerHeartbeat_DEPRECATED() {

	/* Empty Method */

}
