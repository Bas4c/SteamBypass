// -----------------------------------------------------------------------------
#include "SteamNetworkingSockets.h"
// -----------------------------------------------------------------------------

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamListenSocket_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamNetConnection_Invalid;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketP2P(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamListenSocket_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamNetConnection_Invalid;

}

EResult _SteamNetworkingSockets_::AcceptConnection(HSteamNetConnection hConnection) {

	return k_EResultInvalidState;

}

Bool _SteamNetworkingSockets_::CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) {

	return False;

}

Bool _SteamNetworkingSockets_::CloseListenSocket(HSteamListenSocket hSocket) {

	return False;

}

Bool _SteamNetworkingSockets_::SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) {

	return False;

}

Int64 _SteamNetworkingSockets_::GetConnectionUserData(HSteamNetConnection hPeer) {

	return 0LL;

}

void _SteamNetworkingSockets_::SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) {

	/* Empty Method */

}

Bool _SteamNetworkingSockets_::GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) {

	if (pchName != NULL && cchName > 0) {
		pchName[0] = '\0';
	}

	return False;

}

EResult _SteamNetworkingSockets_::SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) {

	return k_EResultNoConnection;

}

void _SteamNetworkingSockets_::SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) {

	/* Empty Method */

}

EResult _SteamNetworkingSockets_::FlushMessagesOnConnection(HSteamNetConnection hConnection) {

	return k_EResultNoConnection;

}

Int32 _SteamNetworkingSockets_::ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {

	return 0;

}

Bool _SteamNetworkingSockets_::GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) {

	return False;

}

EResult _SteamNetworkingSockets_::GetConnectionRealTimeStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStatus, Int32 nLanes, pSteamNetConnectionRealTimeLaneStatus_t pLanes) {

	return k_EResultNoConnection;

}

Int32 _SteamNetworkingSockets_::GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) {

	if (pchBuf != NULL && cchBuf > 0) {
		pchBuf[0] = '\0';
	}

	return 0;

}

Bool _SteamNetworkingSockets_::GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) {

	return False;

}

Bool _SteamNetworkingSockets_::CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) {

	return False;

}

EResult _SteamNetworkingSockets_::ConfigureConnectionLanes(HSteamNetConnection hConnection, Int32 nNumLanes, const pInt32 pLanePriorities, const pUint16 pLaneWeights) {

	return k_EResultInvalidState;

}

Bool _SteamNetworkingSockets_::GetIdentity(pSteamNetworkingIdentity pIdentity) {

	return False;

}

ESteamNetworkingAvailability _SteamNetworkingSockets_::InitAuthentication() {

	SteamNetAuthenticationStatus_t details;
	return this->GetAuthenticationStatus(&details);

}

ESteamNetworkingAvailability _SteamNetworkingSockets_::GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) {

	if (pDetails != NULL) {
		pDetails->eSteamNetworkingAvailability = k_ESteamNetworkingAvailability_Current;
		pDetails->chDebugMsg[0] = '\0';
	}

	return k_ESteamNetworkingAvailability_Current;

}

HSteamNetPollGroup _SteamNetworkingSockets_::CreatePollGroup() {

	return k_HSteamNetPollGroup_Invalid;

}

Bool _SteamNetworkingSockets_::DestroyPollGroup(HSteamNetPollGroup hSteamNetPollGroup) {

	return False;

}

Bool _SteamNetworkingSockets_::SetConnectionPollGroup(HSteamNetConnection hConnection, HSteamNetPollGroup hSteamNetPollGroup) {

	return False;

}

Int32 _SteamNetworkingSockets_::ReceiveMessagesOnPollGroup(HSteamNetPollGroup hSteamNetPollGroup, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {

	return 0;

}

Bool _SteamNetworkingSockets_::ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) {

	return False;

}

Int32 _SteamNetworkingSockets_::FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) {

	return 0;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamNetConnection_Invalid;

}

Uint16 _SteamNetworkingSockets_::GetHostedDedicatedServerPort() {

	return 80;

}

SteamNetworkingPOPID _SteamNetworkingSockets_::GetHostedDedicatedServerPOPID() {

	return (SteamNetworkingPOPID)(0x00000000);

}

EResult _SteamNetworkingSockets_::GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) {

	return k_EResultInvalidState;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamListenSocket_Invalid;

}

EResult _SteamNetworkingSockets_::GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) {

	/* January 1, 1970 (start of Unix epoch) in "ticks" */
	const Int64 UnixTimeStart = 0x019DB1DED53E8000;

	Uint64 UTCTime = 0U;
	GetSystemTimeAsFileTime((LPFILETIME)(&UTCTime));
	RTime32 Time = (RTime32)((UTCTime - UnixTimeStart) / 10000000);

	if (pLoginInfo != NULL) {
		pLoginInfo->iAppId = (AppId_t)(0x00000000);
		pLoginInfo->Identity.eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_IPAddress;
		pLoginInfo->Identity.cbSize = sizeof(SteamNetworkingIPAddr);
		pLoginInfo->Identity.SteamNetworkingIPAddr.IPv4.x0000000000000000 = 0x0000000000000000;
		pLoginInfo->Identity.SteamNetworkingIPAddr.IPv4.x0000 = 0x0000;
		pLoginInfo->Identity.SteamNetworkingIPAddr.IPv4.xFFFF = 0xFFFF;
		pLoginInfo->Identity.SteamNetworkingIPAddr.IPv4.cbIPv4[0] = 127;
		pLoginInfo->Identity.SteamNetworkingIPAddr.IPv4.cbIPv4[1] = 0;
		pLoginInfo->Identity.SteamNetworkingIPAddr.IPv4.cbIPv4[2] = 0;
		pLoginInfo->Identity.SteamNetworkingIPAddr.IPv4.cbIPv4[3] = 1;
		pLoginInfo->Identity.SteamNetworkingIPAddr.Port = 80;
		pLoginInfo->Routing.cbSize = 0;
		pLoginInfo->Time = Time;
	}

	if (pvBlob != NULL) {
		if (pcbSignedBlob != NULL) {
			((pByte)(pvBlob))[0] = 0xFF;
			*pcbSignedBlob = 1;

		}
	}

	return k_EResultOK;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectP2PCustomSignaling(IpSteamNetworkingConnectionCustomSignaling pSignaling, const pSteamNetworkingIdentity pPeerIdentity, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamNetConnection_Invalid;

}

Bool _SteamNetworkingSockets_::ReceivedP2PCustomSignal(const pVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) {

	return False;

}

Bool _SteamNetworkingSockets_::GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) {

	return False;

}

Bool _SteamNetworkingSockets_::SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) {

	return False;

}

void _SteamNetworkingSockets_::ResetIdentity(const pSteamNetworkingIdentity pIdentity) {

	/* Empty Method */

}

void _SteamNetworkingSockets_::RunCallbacks() {

	/* Empty Method */

}

Bool _SteamNetworkingSockets_::BeginAsyncRequestFakeIP(Int32 nNumPorts) {

	return False;

}

void _SteamNetworkingSockets_::GetFakeIP(Int32 idxFirstPort, pSteamNetworkingFakeIPResult_t pInfo) {

	/* Empty Method */

}

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketP2PFakeIP(Int32 idxFakePort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {

	return k_HSteamListenSocket_Invalid;

}

EResult _SteamNetworkingSockets_::GetRemoteFakeIPForConnection(HSteamNetConnection hConnection, pSteamNetworkingIPAddr pAddr) {

	return k_EResultIPNotFound;

}

IpSteamNetworkingFakeUDPPort _SteamNetworkingSockets_::CreateFakeUDPPort(Int32 iFakeServerPort) {

	return NULL;

}
