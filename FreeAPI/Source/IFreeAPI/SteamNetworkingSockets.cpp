// -----------------------------------------------------------------------------
#include "SteamNetworkingSockets.h"
// -----------------------------------------------------------------------------

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocket(Int32 nSteamConnectVirtualPort, Uint32 IP, Uint16 Port) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateListenSocket");
	
	return k_HSteamListenSocket_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectBySteamID(SteamId_t SteamIdTarget, Int32 nVirtualPort) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectBySteamID");

	return k_HSteamNetConnection_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectByIPv4Address(Uint32 nIP, Uint16 Port) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectByIPv4Address");

	return k_HSteamNetConnection_Invalid;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateListenSocketIP");

	return k_HSteamListenSocket_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectByIPAddress");

	return k_HSteamNetConnection_Invalid;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketP2P(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateListenSocketP2P");

	return k_HSteamListenSocket_Invalid;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateListenSocketIP");

	return k_HSteamListenSocket_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectByIPAddress");

	return k_HSteamListenSocket_Invalid;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketP2P(Int32 nLocalVirtualPort) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateListenSocketP2P");

	return k_HSteamListenSocket_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectP2P");

	return k_HSteamNetConnection_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectP2P");

	return k_HSteamNetConnection_Invalid;

}

EResult _SteamNetworkingSockets_::AcceptConnection(HSteamNetConnection hConnection) {
	DEBUGBREAK("ISteamNetworkingSockets::AcceptConnection");

	return k_EResultInvalidState;

}

Bool _SteamNetworkingSockets_::CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) {
	DEBUGBREAK("ISteamNetworkingSockets::CloseConnection");

	return False;

}

Bool _SteamNetworkingSockets_::CloseListenSocket(HSteamListenSocket hSocket) {
	DEBUGBREAK("ISteamNetworkingSockets::CloseListenSocket");

	return False;

}

Bool _SteamNetworkingSockets_::SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) {
	DEBUGBREAK("ISteamNetworkingSockets::SetConnectionUserData");

	return False;

}

Int64 _SteamNetworkingSockets_::GetConnectionUserData(HSteamNetConnection hPeer) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConnectionUserData");

	return 0LL;

}

void _SteamNetworkingSockets_::SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) {
	DEBUGBREAK("ISteamNetworkingSockets::SetConnectionName");

	/* Empty Method */

}

Bool _SteamNetworkingSockets_::GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConnectionName");

	if (pchName != NULL && cchName > 0) {
		pchName[0] = '\0';
	}

	return False;

}

EResult _SteamNetworkingSockets_::SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) {
	DEBUGBREAK("ISteamNetworkingSockets::SendMessageToConnection");

	return k_EResultNoConnection;

}

void _SteamNetworkingSockets_::SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) {
	DEBUGBREAK("ISteamNetworkingSockets::SendMessages");

	/* Empty Method */

}

EResult _SteamNetworkingSockets_::FlushMessagesOnConnection(HSteamNetConnection hConnection) {
	DEBUGBREAK("ISteamNetworkingSockets::FlushMessagesOnConnection");

	return k_EResultNoConnection;

}

Int32 _SteamNetworkingSockets_::ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t_Old *ppMessages, Int32 nMessages) {
	DEBUGBREAK("ISteamNetworkingSockets::ReceiveMessagesOnConnection");

	return 0;

}

Int32 _SteamNetworkingSockets_::ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t_Old *ppMessages, Int32 nMaxMessages) {
	DEBUGBREAK("ISteamNetworkingSockets::ReceiveMessagesOnListenSocket");

	return 0;

}

Int32 _SteamNetworkingSockets_::ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) {
	DEBUGBREAK("ISteamNetworkingSockets::ReceiveMessagesOnListenSocket");

	return 0;

}

Int32 _SteamNetworkingSockets_::ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {
	DEBUGBREAK("ISteamNetworkingSockets::ReceiveMessagesOnConnection");

	return 0;

}

Bool _SteamNetworkingSockets_::GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t_Old pInfo) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConnectionInfo");

	return False;

}

Bool _SteamNetworkingSockets_::GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) {
	DEBUGBREAK("ISteamNetworkingSockets::GetQuickConnectionStatus");

	return False;

}

Bool _SteamNetworkingSockets_::GetListenSocketInfo(HSteamListenSocket hSocket, pUint32 nIP, pUint16 pPort) {
	DEBUGBREAK("ISteamNetworkingSockets::GetListenSocketInfo");

	return False;

}

Bool _SteamNetworkingSockets_::GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConnectionInfo");

	return False;

}

EResult _SteamNetworkingSockets_::GetConnectionRealTimeStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStatus, Int32 nLanes, pSteamNetConnectionRealTimeLaneStatus_t pLanes) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConnectionRealTimeStatus");

	return k_EResultNoConnection;

}

Int32 _SteamNetworkingSockets_::GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) {
	DEBUGBREAK("ISteamNetworkingSockets::GetDetailedConnectionStatus");

	if (pchBuf != NULL && cchBuf > 0) {
		pchBuf[0] = '\0';
	}

	return 0;

}

Bool _SteamNetworkingSockets_::GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) {
	DEBUGBREAK("ISteamNetworkingSockets::GetListenSocketAddress");

	return False;

}

Bool _SteamNetworkingSockets_::CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateSocketPair");

	return False;

}

EResult _SteamNetworkingSockets_::ConfigureConnectionLanes(HSteamNetConnection hConnection, Int32 nNumLanes, const pInt32 pLanePriorities, const pUint16 pLaneWeights) {
	DEBUGBREAK("ISteamNetworkingSockets::ConfigureConnectionLanes");

	return k_EResultInvalidState;

}

Bool _SteamNetworkingSockets_::GetIdentity(pSteamNetworkingIdentity pIdentity) {
	DEBUGBREAK("ISteamNetworkingSockets::GetIdentity");

	return False;

}

ESteamNetworkingAvailability _SteamNetworkingSockets_::InitAuthentication() {
	DEBUGBREAK("ISteamNetworkingSockets::InitAuthentication");

	SteamNetAuthenticationStatus_t details;
	return this->GetAuthenticationStatus(&details);

}

ESteamNetworkingAvailability _SteamNetworkingSockets_::GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) {
	DEBUGBREAK("ISteamNetworkingSockets::GetAuthenticationStatus");

	if (pDetails != NULL) {
		pDetails->eSteamNetworkingAvailability = k_ESteamNetworkingAvailability_Current;
		pDetails->chDebugMsg[0] = '\0';
	}

	return k_ESteamNetworkingAvailability_Current;

}

HSteamNetPollGroup _SteamNetworkingSockets_::CreatePollGroup() {
	DEBUGBREAK("ISteamNetworkingSockets::CreatePollGroup");

	return k_HSteamNetPollGroup_Invalid;

}

Bool _SteamNetworkingSockets_::DestroyPollGroup(HSteamNetPollGroup hSteamNetPollGroup) {
	DEBUGBREAK("ISteamNetworkingSockets::DestroyPollGroup");

	return False;

}

Bool _SteamNetworkingSockets_::SetConnectionPollGroup(HSteamNetConnection hConnection, HSteamNetPollGroup hSteamNetPollGroup) {
	DEBUGBREAK("ISteamNetworkingSockets::SetConnectionPollGroup");

	return False;

}

Int32 _SteamNetworkingSockets_::ReceiveMessagesOnPollGroup(HSteamNetPollGroup hSteamNetPollGroup, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {
	DEBUGBREAK("ISteamNetworkingSockets::ReceiveMessagesOnPollGroup");

	return 0;

}

Bool _SteamNetworkingSockets_::ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) {
	DEBUGBREAK("ISteamNetworkingSockets::ReceivedRelayAuthTicket");

	return False;

}

Int32 _SteamNetworkingSockets_::FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) {
	DEBUGBREAK("ISteamNetworkingSockets::FindRelayAuthTicketForServer");

	return 0;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectToHostedDedicatedServer");

	return k_HSteamNetConnection_Invalid;

}

Bool _SteamNetworkingSockets_::GetHostedDedicatedServerAddress_Old(pSteamDatagramHostedAddress pRouting) {
	DEBUGBREAK("ISteamNetworkingSockets::GetHostedDedicatedServerAddress_Old");

	return False;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateHostedDedicatedServerListenSocket");
	
	return k_HSteamListenSocket_Invalid;

}

HSteamNetConnection _SteamNetworkingSockets_::ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("ISteamNetworkingSockets::ConnectToHostedDedicatedServer");

	return k_HSteamNetConnection_Invalid;

}

Uint16 _SteamNetworkingSockets_::GetHostedDedicatedServerPort() {
	DEBUGBREAK("ISteamNetworkingSockets::GetHostedDedicatedServerPort");

	return 80;

}

SteamNetworkingPOPID _SteamNetworkingSockets_::GetHostedDedicatedServerPOPID() {
	DEBUGBREAK("ISteamNetworkingSockets::GetHostedDedicatedServerPOPID");

	return (SteamNetworkingPOPID)(0x00000000);

}

EResult _SteamNetworkingSockets_::GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) {
	DEBUGBREAK("ISteamNetworkingSockets::GetHostedDedicatedServerAddress");

	return k_EResultInvalidState;

}

HSteamListenSocket _SteamNetworkingSockets_::CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateHostedDedicatedServerListenSocket");

	return k_HSteamListenSocket_Invalid;

}

EResult _SteamNetworkingSockets_::GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) {
	DEBUGBREAK("ISteamNetworkingSockets::GetGameCoordinatorServerLogin");

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
	DEBUGBREAK("ISteamNetworkingSockets::ConnectP2PCustomSignaling");

	return k_HSteamNetConnection_Invalid;

}

Bool _SteamNetworkingSockets_::ReceivedP2PCustomSignal(const pVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) {
	DEBUGBREAK("ISteamNetworkingSockets::ReceivedP2PCustomSignal");

	return False;

}

Bool _SteamNetworkingSockets_::GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) {
	DEBUGBREAK("ISteamNetworkingSockets::GetCertificateRequest");

	return False;

}

Bool _SteamNetworkingSockets_::SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) {
	DEBUGBREAK("ISteamNetworkingSockets::SetCertificate");

	return False;

}

void _SteamNetworkingSockets_::ResetIdentity(const pSteamNetworkingIdentity pIdentity) {
	DEBUGBREAK("ISteamNetworkingSockets::ResetIdentity");

	/* Empty Method */

}

void _SteamNetworkingSockets_::RunCallbacks(IpSteamNetworkingSocketsCallbacks pCallbacks) {
	DEBUGBREAK("ISteamNetworkingSockets::RunCallbacks");

	/* Empty Method */

}

void _SteamNetworkingSockets_::RunCallbacks() {
	DEBUGBREAK("ISteamNetworkingSockets::RunCallbacks");

	/* Empty Method */

}

Bool _SteamNetworkingSockets_::BeginAsyncRequestFakeIP(Int32 nNumPorts) {
	DEBUGBREAK("ISteamNetworkingSockets::BeginAsyncRequestFakeIP");

	return False;

}

void _SteamNetworkingSockets_::GetFakeIP(Int32 idxFirstPort, pSteamNetworkingFakeIPResult_t pInfo) {
	DEBUGBREAK("ISteamNetworkingSockets::GetFakeIP");

	/* Empty Method */

}

HSteamListenSocket _SteamNetworkingSockets_::CreateListenSocketP2PFakeIP(Int32 idxFakePort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateListenSocketP2PFakeIP");

	return k_HSteamListenSocket_Invalid;

}

EResult _SteamNetworkingSockets_::GetRemoteFakeIPForConnection(HSteamNetConnection hConnection, pSteamNetworkingIPAddr pAddr) {
	DEBUGBREAK("ISteamNetworkingSockets::GetRemoteFakeIPForConnection");

	return k_EResultIPNotFound;

}

IpSteamNetworkingFakeUDPPort _SteamNetworkingSockets_::CreateFakeUDPPort(Int32 iFakeServerPort) {
	DEBUGBREAK("ISteamNetworkingSockets::CreateFakeUDPPort");

	return NULL;

}

pCStrA _SteamNetworkingSockets_::GetConfigurationValueName(ESteamNetworkingConfigurationValue eConfigValue) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConfigurationValueName");
	
	switch (eConfigValue) {
		case k_ESteamNetworkingConfigurationValue_FakeMessageLoss_Send:
			return (pCStrA)("FakeMessageLoss_Send");
		case k_ESteamNetworkingConfigurationValue_FakeMessageLoss_Recv:
			return (pCStrA)("FakeMessageLoss_Recv");
		case k_ESteamNetworkingConfigurationValue_FakePacketLoss_Send:
			return (pCStrA)("FakePacketLoss_Send");
		case k_ESteamNetworkingConfigurationValue_FakePacketLoss_Recv:
			return (pCStrA)("FakePacketLoss_Recv");
		case k_ESteamNetworkingConfigurationValue_FakePacketLag_Send:
			return (pCStrA)("FakePacketLag_Send");
		case k_ESteamNetworkingConfigurationValue_FakePacketLag_Recv:
			return (pCStrA)("FakePacketLag_Recv");
		case k_ESteamNetworkingConfigurationValue_FakePacketReorder_Send:
			return (pCStrA)("FakePacketReorder_Send");
		case k_ESteamNetworkingConfigurationValue_FakePacketReorder_Recv:
			return (pCStrA)("FakePacketReorder_Recv");
		case k_ESteamNetworkingConfigurationValue_FakePacketReorder_Time:
			return (pCStrA)("FakePacketReorder_Time");
		case k_ESteamNetworkingConfigurationValue_SendBufferSize:
			return (pCStrA)("SendBufferSize");
		case k_ESteamNetworkingConfigurationValue_MaxRate:
			return (pCStrA)("MaxRate");
		case k_ESteamNetworkingConfigurationValue_MinRate:
			return (pCStrA)("MinRate");
		case k_ESteamNetworkingConfigurationValue_Nagle_Time:
			return (pCStrA)("Nagle_Time");
		case k_ESteamNetworkingConfigurationValue_LogLevel_AckRTT:
			return (pCStrA)("LogLevel_AckRTT");
		case k_ESteamNetworkingConfigurationValue_LogLevel_Packet:
			return (pCStrA)("LogLevel_Packet");
		case k_ESteamNetworkingConfigurationValue_LogLevel_Message:
			return (pCStrA)("LogLevel_Message");
		case k_ESteamNetworkingConfigurationValue_LogLevel_PacketGaps:
			return (pCStrA)("LogLevel_PacketGaps");
		case k_ESteamNetworkingConfigurationValue_LogLevel_P2PRendezvous:
			return (pCStrA)("LogLevel_P2PRendezvous");
		case k_ESteamNetworkingConfigurationValue_LogLevel_RelayPings:
			return (pCStrA)("LogLevel_RelayPings");
		case k_ESteamNetworkingConfigurationValue_ClientConsecutitivePingTimeoutsFailInitial:
			return (pCStrA)("ClientConsecutitivePingTimeoutsFailInitial");
		case k_ESteamNetworkingConfigurationValue_ClientConsecutitivePingTimeoutsFail:
			return (pCStrA)("ClientConsecutitivePingTimeoutsFail");
		case k_ESteamNetworkingConfigurationValue_ClientMinPingsBeforePingAccurate:
			return (pCStrA)("ClientMinPingsBeforePingAccurate");
		case k_ESteamNetworkingConfigurationValue_ClientSingleSocket:
			return (pCStrA)("ClientSingleSocket");
		case k_ESteamNetworkingConfigurationValue_IP_Allow_Without_Auth:
			return (pCStrA)("IP_Allow_Without_Auth");
		case k_ESteamNetworkingConfigurationValue_Timeout_Seconds_Initial:
			return (pCStrA)("Timeout_Seconds_Initial");
		case k_ESteamNetworkingConfigurationValue_Timeout_Seconds_Connected:
			return (pCStrA)("Timeout_Seconds_Connected");
	}

	return (pCStrA)(
		""
	);

}

Int32 _SteamNetworkingSockets_::GetConfigurationString(ESteamNetworkingConfigurationString eConfigString, pStrA pchDest, Int32 cchDest) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConfigurationString");
	
	return 0;

}

Bool _SteamNetworkingSockets_::SetConfigurationString(ESteamNetworkingConfigurationString eConfigString, pCStrA pchString) {
	DEBUGBREAK("ISteamNetworkingSockets::SetConfigurationString");
	
	return False;

}

pCStrA _SteamNetworkingSockets_::GetConfigurationStringName(ESteamNetworkingConfigurationString eConfigString) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConfigurationStringName");
	
	switch (eConfigString) {
		case k_ESteamNetworkingConfigurationString_ClientForceRelayCluster:
			return (pCStrA)("ClientForceRelayCluster");
		case k_ESteamNetworkingConfigurationString_ClientDebugTicketAddress:
			return (pCStrA)("ClientDebugTicketAddress");
		case k_ESteamNetworkingConfigurationString_ClientForceProxyAddr:
			return (pCStrA)("ClientForceProxyAddr");
	}

	return (pCStrA)(
		""
	);

}

Int32 _SteamNetworkingSockets_::GetConnectionConfigurationValue(HSteamNetConnection hConnection, ESteamNetworkingConnectionConfigurationValue eConfigValue) {
	DEBUGBREAK("ISteamNetworkingSockets::GetConnectionConfigurationValue");
	
	return 0;

}

Bool _SteamNetworkingSockets_::SetConnectionConfigurationValue(HSteamNetConnection hConnection, ESteamNetworkingConnectionConfigurationValue eConfigValue, Int32 nValue) {
	DEBUGBREAK("ISteamNetworkingSockets::SetConnectionConfigurationValue");
	
	return False;

}
