#ifndef _STEAMNETWORKINGSOCKETS_
#define _STEAMNETWORKINGSOCKETS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamNetworkingSockets.h"
// -----------------------------------------------------------------------------

typedef class _SteamNetworkingSockets_ : public _ISteamNetworkingSockets001_,
 public _ISteamNetworkingSockets002_, public _ISteamNetworkingSockets003_,
 public _ISteamNetworkingSockets004_, public _ISteamNetworkingSockets006_,
 public _ISteamNetworkingSockets008_, public _ISteamNetworkingSockets009_,
 public _ISteamNetworkingSockets_ {
public:

	_SteamNetworkingSockets_() = default;
	_SteamNetworkingSockets_(const _SteamNetworkingSockets_&) = delete;
	_SteamNetworkingSockets_& operator=(const _SteamNetworkingSockets_&) = delete;

	HSteamListenSocket CreateListenSocket(Int32 nSteamConnectVirtualPort, Uint32 IP, Uint16 Port) override;
	HSteamNetConnection ConnectBySteamID(SteamId_t SteamIdTarget, Int32 nVirtualPort) override;
	HSteamNetConnection ConnectByIPv4Address(Uint32 nIP, Uint16 Port) override;
	HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) override;
	HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) override;
	HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort) override;
	HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort) override;
	HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	EResult AcceptConnection(HSteamNetConnection hConnection) override;
	Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) override;
	Bool CloseListenSocket(HSteamListenSocket hSocket) override;

	Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) override;
	Int64 GetConnectionUserData(HSteamNetConnection hPeer) override;
	void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) override;
	Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) override;
	EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) override;
	void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) override;
	EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) override;
	Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t_Old *ppMessages, Int32 nMessages) override;
	Int32 ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t_Old *ppMessages, Int32 nMaxMessages) override;
	Int32 ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) override;
	Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) override;
	
	Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t_Old pInfo) override;
	Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) override;
	Bool GetListenSocketInfo(HSteamListenSocket hSocket, pUint32 nIP, pUint16 pPort) override;
	Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) override;
	EResult GetConnectionRealTimeStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStatus, Int32 nLanes, pSteamNetConnectionRealTimeLaneStatus_t pLanes) override;
	Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) override;
	Bool GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) override;
	Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) override;
	EResult ConfigureConnectionLanes(HSteamNetConnection hConnection, Int32 nNumLanes, const pInt32 pLanePriorities, const pUint16 pLaneWeights) override;
	Bool GetIdentity(pSteamNetworkingIdentity pIdentity) override;

	ESteamNetworkingAvailability InitAuthentication() override;
	ESteamNetworkingAvailability GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) override;
	HSteamNetPollGroup CreatePollGroup() override;
	Bool DestroyPollGroup(HSteamNetPollGroup hSteamNetPollGroup) override;
	Bool SetConnectionPollGroup(HSteamNetConnection hConnection, HSteamNetPollGroup hSteamNetPollGroup) override;
	Int32 ReceiveMessagesOnPollGroup(HSteamNetPollGroup hSteamNetPollGroup, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) override;
	Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) override;
	Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) override;
	HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort) override;
	Bool GetHostedDedicatedServerAddress_Old(pSteamDatagramHostedAddress pRouting) override;
	HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort) override;
	HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	Uint16 GetHostedDedicatedServerPort() override;
	SteamNetworkingPOPID GetHostedDedicatedServerPOPID() override;
	EResult GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) override;
	HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	EResult GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) override;
	HSteamNetConnection ConnectP2PCustomSignaling(IpSteamNetworkingConnectionCustomSignaling pSignaling, const pSteamNetworkingIdentity pPeerIdentity, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	Bool ReceivedP2PCustomSignal(const pVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) override;
	Bool GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) override;
	Bool SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) override;
	void ResetIdentity(const pSteamNetworkingIdentity pIdentity) override;

	/* Applications should use SteamAPI_RunCallbacks() or SteamGameServer_RunCallbacks() instead */
	void RunCallbacks(IpSteamNetworkingSocketsCallbacks pCallbacks) override;
	void RunCallbacks() override;

	Bool BeginAsyncRequestFakeIP(Int32 nNumPorts) override;
	void GetFakeIP(Int32 idxFirstPort, pSteamNetworkingFakeIPResult_t pInfo) override;
	HSteamListenSocket CreateListenSocketP2PFakeIP(Int32 idxFakePort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) override;
	EResult GetRemoteFakeIPForConnection(HSteamNetConnection hConnection, pSteamNetworkingIPAddr pAddr) override;
	IpSteamNetworkingFakeUDPPort CreateFakeUDPPort(Int32 iFakeServerPort) override;

	pCStrA GetConfigurationValueName(ESteamNetworkingConfigurationValue eConfigValue) override;
	Int32 GetConfigurationString(ESteamNetworkingConfigurationString eConfigString, pStrA pchDest, Int32 cchDest) override;
	Bool SetConfigurationString(ESteamNetworkingConfigurationString eConfigString, pCStrA pchString) override;
	pCStrA GetConfigurationStringName(ESteamNetworkingConfigurationString eConfigString) override;
	Int32 GetConnectionConfigurationValue(HSteamNetConnection hConnection, ESteamNetworkingConnectionConfigurationValue eConfigValue) override;
	Bool SetConnectionConfigurationValue(HSteamNetConnection hConnection, ESteamNetworkingConnectionConfigurationValue eConfigValue, Int32 nValue) override;

	~_SteamNetworkingSockets_() = default;

} SteamNetworkingSockets, *pSteamNetworkingSockets;

#endif // !_STEAMNETWORKINGSOCKETS_
