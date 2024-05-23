#ifndef _ISTEAMNETWORKINGSOCKETS_
#define _ISTEAMNETWORKINGSOCKETS_

#include "..\..\FreeAPI.Typedef.h"
#include "ISteamNetworking.h"

// -----------------------------------------------------------------------------
// Purpose: Calbback Interface
// -----------------------------------------------------------------------------
typedef class _ISteamNetworkingConnectionCustomSignaling_ {

	virtual Bool SendSignal(HSteamNetConnection hConnection, const pSteamNetConnectionInfo_t pInfo, const pVoid pvMsg, Int32 cbMsg) = 0;
	virtual void Release(void) = 0;

} ISteamNetworkingConnectionCustomSignaling, *IpSteamNetworkingConnectionCustomSignaling;

// -----------------------------------------------------------------------------
// Purpose: Calbback Interface
// -----------------------------------------------------------------------------
typedef class _ISteamNetworkingCustomSignalingRecvContext_ {

	virtual IpSteamNetworkingConnectionCustomSignaling _OnConnectRequest(HSteamNetConnection hConnection, const pSteamNetworkingIdentity pIdentityPeer) = 0;
	virtual void SendRejectionSignal(const pSteamNetworkingIdentity pidentityPeer, const pVoid pvMsg, Int32 cbMsg) = 0;

} ISteamNetworkingCustomSignalingRecvContext, *IpSteamNetworkingCustomSignalingRecvContext;

typedef class _ISteamNetworkingFakeUDPPort_ {
public:

	virtual void DestroyFakeUDPPort() = 0;
	virtual EResult SendMessageToFakeIP(const pSteamNetworkingIPAddr pRemoteAddress, const pVoid pData, Uint32 cbData, Int32 nSendFlags) = 0;
	virtual Int32 ReceiveMessages(/* [out] */ pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) = 0;
	virtual void ScheduleCleanup(const pSteamNetworkingIPAddr pRemoteAddress) = 0;

} ISteamNetworkingFakeUDPPort, *IpSteamNetworkingFakeUDPPort;

#define STEAMNETWORKINGFAKEUDPPORT_INTERFACE_VERSION "SteamNetworkingFakeUDPPort001"

typedef struct _SteamNetConnectionStatusChangedCallback_t_ SteamNetConnectionStatusChangedCallback_t, *pSteamNetConnectionStatusChangedCallback_t;

// -----------------------------------------------------------------------------
// Purpose: Calbback Interface
// -----------------------------------------------------------------------------
typedef class _ISteamNetworkingSocketsCallbacks_ {
public:

	virtual void OnSteamNetConnectionStatusChanged(pSteamNetConnectionStatusChangedCallback_t pConnectionStatusChanged) = 0;
	virtual void OnP2PSessionRequest(pP2PSessionRequest_t pP2PSessionRequest) = 0;
	virtual void OnP2PSessionConnectFail(pP2PSessionConnectFail_t pP2PSessionConnectFail) = 0;

} ISteamNetworkingSocketsCallbacks, *IpSteamNetworkingSocketsCallbacks;

typedef struct _SteamNetAuthenticationStatus_t_ SteamNetAuthenticationStatus_t, *pSteamNetAuthenticationStatus_t;
typedef struct _SteamNetworkingFakeIPResult_t_ SteamNetworkingFakeIPResult_t, *pSteamNetworkingFakeIPResult_t;

typedef class _ISteamNetworkingSockets001_ {
public:

	virtual HSteamListenSocket CreateListenSocket(Int32 nSteamConnectVirtualPort, Uint32 IP, Uint16 Port) = 0;
	virtual HSteamNetConnection ConnectBySteamID(SteamId_t steamIdTarget, Int32 nVirtualPort) = 0;
	virtual HSteamNetConnection ConnectByIPv4Address(Uint32 nIP, Uint16 Port) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;
	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t_Old *ppMessages, Int32 nMessages) = 0;
	virtual Int32 ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t_Old *ppMessages, Int32 nMaxMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t_Old pInfo) = 0;
	virtual Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketInfo(HSteamListenSocket hSocket, pUint32 nIP, pUint16 pPort) = 0;
	virtual Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual Bool GetHostedDedicatedServerAddress_Old(pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort) = 0;
	virtual pCStrA GetConfigurationValueName(ESteamNetworkingConfigurationValue eConfigValue) = 0;
	virtual Int32 GetConfigurationString(ESteamNetworkingConfigurationString eConfigString, pStrA pchDest, Int32 cchDest) = 0;
	virtual Bool SetConfigurationString(ESteamNetworkingConfigurationString eConfigString, pCStrA pchString) = 0;
	virtual pCStrA GetConfigurationStringName(ESteamNetworkingConfigurationString eConfigString) = 0;
	virtual Int32 GetConnectionConfigurationValue(HSteamNetConnection hConnection, ESteamNetworkingConnectionConfigurationValue eConfigValue) = 0;
	virtual Bool SetConnectionConfigurationValue(HSteamNetConnection hConnection, ESteamNetworkingConnectionConfigurationValue eConfigValue, Int32 nValue) = 0;
	virtual void RunCallbacks(IpSteamNetworkingSocketsCallbacks pCallbacks) = 0;

} ISteamNetworkingSockets001, *IpSteamNetworkingSockets001;

typedef class _ISteamNetworkingSockets002_ {
public:

	virtual HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort) = 0;
	virtual HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;
	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Int32 ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) = 0;
	virtual Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual Bool GetIdentity(pSteamNetworkingIdentity pIdentity) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual Bool GetHostedDedicatedServerAddress_Old(pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort) = 0;
	virtual void RunCallbacks(IpSteamNetworkingSocketsCallbacks pCallbacks) = 0;

} ISteamNetworkingSockets002, *IpSteamNetworkingSockets002;

typedef class _ISteamNetworkingSockets003_ {
public:

	virtual HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort) = 0;
	virtual HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;
	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Int32 ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) = 0;
	virtual Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual Bool GetIdentity(pSteamNetworkingIdentity pIdentity) = 0;
	virtual ESteamNetworkingAvailability InitAuthentication() = 0;
	virtual ESteamNetworkingAvailability GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) = 0;
	virtual Bool GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual EResult GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort) = 0;
	virtual EResult GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) = 0;
	virtual void RunCallbacks(IpSteamNetworkingSocketsCallbacks pCallbacks) = 0;

} ISteamNetworkingSockets003, *IpSteamNetworkingSockets003;

typedef class _ISteamNetworkingSockets004_ {
public:

	virtual HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort) = 0;
	virtual HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;
	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Int32 ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) = 0;
	virtual Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual Bool GetIdentity(pSteamNetworkingIdentity pIdentity) = 0;
	virtual ESteamNetworkingAvailability InitAuthentication() = 0;
	virtual ESteamNetworkingAvailability GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) = 0;
	virtual Bool GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual EResult GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort) = 0;
	virtual EResult GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) = 0;
	virtual void RunCallbacks(IpSteamNetworkingSocketsCallbacks pCallbacks) = 0;

} ISteamNetworkingSockets004, *IpSteamNetworkingSockets004;

typedef class _ISteamNetworkingSockets006_ {
public:

	virtual HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;
	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Int32 ReceiveMessagesOnListenSocket(HSteamListenSocket hSocket, pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) = 0;
	virtual Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual Bool GetIdentity(pSteamNetworkingIdentity pIdentity) = 0;
	virtual ESteamNetworkingAvailability InitAuthentication() = 0;
	virtual ESteamNetworkingAvailability GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual EResult GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) = 0;
	virtual HSteamNetConnection ConnectP2PCustomSignaling(IpSteamNetworkingConnectionCustomSignaling pSignaling, const pSteamNetworkingIdentity pPeerIdentity, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Bool ReceivedP2PCustomSignal(const pVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) = 0;
	virtual Bool GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual void RunCallbacks(IpSteamNetworkingSocketsCallbacks pCallbacks) = 0;

} ISteamNetworkingSockets006, *IpSteamNetworkingSockets006;

typedef class _ISteamNetworkingSockets008_ {
public:

	virtual HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;
	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) = 0;
	virtual Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual Bool GetIdentity(pSteamNetworkingIdentity pIdentity) = 0;
	virtual ESteamNetworkingAvailability InitAuthentication() = 0;
	virtual ESteamNetworkingAvailability GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) = 0;
	virtual HSteamNetPollGroup CreatePollGroup() = 0;
	virtual Bool DestroyPollGroup(HSteamNetPollGroup hSteamNetPollGroup) = 0;
	virtual Bool SetConnectionPollGroup(HSteamNetConnection hConnection, HSteamNetPollGroup hSteamNetPollGroup) = 0;
	virtual Int32 ReceiveMessagesOnPollGroup(HSteamNetPollGroup hSteamNetPollGroup, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual EResult GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) = 0;
	virtual HSteamNetConnection ConnectP2PCustomSignaling(IpSteamNetworkingConnectionCustomSignaling pSignaling, const pSteamNetworkingIdentity pPeerIdentity, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Bool ReceivedP2PCustomSignal(const pVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) = 0;
	virtual Bool GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual void RunCallbacks() = 0;

} ISteamNetworkingSockets008, *IpSteamNetworkingSockets008;

typedef class _ISteamNetworkingSockets009_ {
public:

	virtual HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;
	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) = 0;
	virtual Bool GetQuickConnectionStatus(HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketAddress(HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual Bool CreateSocketPair(pHSteamNetConnection pConnection1, pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual Bool GetIdentity(pSteamNetworkingIdentity pIdentity) = 0;
	virtual ESteamNetworkingAvailability InitAuthentication() = 0;
	virtual ESteamNetworkingAvailability GetAuthenticationStatus(pSteamNetAuthenticationStatus_t pDetails) = 0;
	virtual HSteamNetPollGroup CreatePollGroup() = 0;
	virtual Bool DestroyPollGroup(HSteamNetPollGroup hSteamNetPollGroup) = 0;
	virtual Bool SetConnectionPollGroup(HSteamNetConnection hConnection, HSteamNetPollGroup hSteamNetPollGroup) = 0;
	virtual Int32 ReceiveMessagesOnPollGroup(HSteamNetPollGroup hSteamNetPollGroup, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual EResult GetHostedDedicatedServerAddress(pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult GetGameCoordinatorServerLogin(pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) = 0;
	virtual HSteamNetConnection ConnectP2PCustomSignaling(IpSteamNetworkingConnectionCustomSignaling pSignaling, const pSteamNetworkingIdentity pPeerIdentity, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Bool ReceivedP2PCustomSignal(const pVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) = 0;
	virtual Bool GetCertificateRequest(pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool SetCertificate(const pVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual void RunCallbacks() = 0;

} ISteamNetworkingSockets009, *IpSteamNetworkingSockets009;

typedef class _ISteamNetworkingSockets_ {
public:

	virtual HSteamListenSocket CreateListenSocketIP(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectByIPAddress(const pSteamNetworkingIPAddr pSteamNetworkingIPAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamListenSocket CreateListenSocketP2P(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual HSteamNetConnection ConnectP2P(const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult AcceptConnection(HSteamNetConnection hConnection) = 0;
	virtual Bool CloseConnection(HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) = 0;
	virtual Bool CloseListenSocket(HSteamListenSocket hSocket) = 0;

	virtual Bool SetConnectionUserData(HSteamNetConnection hPeer, Int64 nUserData) = 0;
	virtual Int64 GetConnectionUserData(HSteamNetConnection hPeer) = 0;
	virtual void SetConnectionName(HSteamNetConnection hPeer, pCStrA pchName) = 0;
	virtual Bool GetConnectionName(HSteamNetConnection hPeer, /* [out] */ pStrA pchName, Int32 cchName) = 0;
	virtual EResult SendMessageToConnection(HSteamNetConnection hConnection, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) = 0;
	virtual void SendMessages(Int32 nMessages, pSteamNetworkingMessage_t pMessages, pInt64 pMessageNumberOrResult) = 0;
	virtual EResult FlushMessagesOnConnection(HSteamNetConnection hConnection) = 0;
	virtual Int32 ReceiveMessagesOnConnection(HSteamNetConnection hConnection, /* [out] */ pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Bool GetConnectionInfo(HSteamNetConnection hConnection, /* [out] */ pSteamNetConnectionInfo_t pInfo) = 0;
	virtual EResult GetConnectionRealTimeStatus(HSteamNetConnection hConnection, /* [out] */ pSteamNetConnectionRealTimeStatus_t pStatus, Int32 nLanes, /* [out] */ pSteamNetConnectionRealTimeLaneStatus_t pLanes) = 0;
	virtual Int32 GetDetailedConnectionStatus(HSteamNetConnection hConnection, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool GetListenSocketAddress(HSteamListenSocket hSocket, /* [out] */ pSteamNetworkingIPAddr pSteamNetworkingIPAddr) = 0;
	virtual Bool CreateSocketPair(/* [out] */ pHSteamNetConnection pConnection1, /* [out] */ pHSteamNetConnection pConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) = 0;
	virtual EResult ConfigureConnectionLanes(HSteamNetConnection hConnection, Int32 nNumLanes, const pInt32 pLanePriorities, const pUint16 pLaneWeights) = 0;
	virtual Bool GetIdentity(/* [out] */ pSteamNetworkingIdentity pIdentity) = 0;

	virtual ESteamNetworkingAvailability InitAuthentication() = 0;
	virtual ESteamNetworkingAvailability GetAuthenticationStatus(/* [out] */ pSteamNetAuthenticationStatus_t pDetails) = 0;
	virtual HSteamNetPollGroup CreatePollGroup() = 0;
	virtual Bool DestroyPollGroup(HSteamNetPollGroup hSteamNetPollGroup) = 0;
	virtual Bool SetConnectionPollGroup(HSteamNetConnection hConnection, HSteamNetPollGroup hSteamNetPollGroup) = 0;
	virtual Int32 ReceiveMessagesOnPollGroup(HSteamNetPollGroup hSteamNetPollGroup, /* [out] */ pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Bool ReceivedRelayAuthTicket(const pVoid pvTicket, Int32 cbTicket, /* [out] */ pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual Int32 FindRelayAuthTicketForServer(const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, /* [out] */ pSteamDatagramRelayAuthTicket pParsedTicket) = 0;
	virtual HSteamNetConnection ConnectToHostedDedicatedServer(const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Uint16 GetHostedDedicatedServerPort() = 0;
	virtual SteamNetworkingPOPID GetHostedDedicatedServerPOPID() = 0;
	virtual EResult GetHostedDedicatedServerAddress(/* [out] */ pSteamDatagramHostedAddress pRouting) = 0;
	virtual HSteamListenSocket CreateHostedDedicatedServerListenSocket(Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult GetGameCoordinatorServerLogin(/* [out] */ pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) = 0;
	virtual HSteamNetConnection ConnectP2PCustomSignaling(IpSteamNetworkingConnectionCustomSignaling pSignaling, const pSteamNetworkingIdentity pPeerIdentity, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual Bool ReceivedP2PCustomSignal(const pVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) = 0;
	virtual Bool GetCertificateRequest(pInt32 pcbBlob, /* [out] */ pVoid pvBlob, /* [out] */ pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual Bool SetCertificate(const pVoid pCertificate, Int32 cbCertificate, /* [out] */ pSteamNetworkingErrMsg pErrMsg) = 0;
	virtual void ResetIdentity(const pSteamNetworkingIdentity pIdentity) = 0;

	/* Applications should use SteamAPI_RunCallbacks() or SteamGameServer_RunCallbacks() instead */
	virtual void RunCallbacks() = 0;

	virtual Bool BeginAsyncRequestFakeIP(Int32 nNumPorts) = 0;
	virtual void GetFakeIP(Int32 idxFirstPort, /* [out] */ pSteamNetworkingFakeIPResult_t pInfo) = 0;
	virtual HSteamListenSocket CreateListenSocketP2PFakeIP(Int32 idxFakePort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) = 0;
	virtual EResult GetRemoteFakeIPForConnection(HSteamNetConnection hConnection, /* [out] */ pSteamNetworkingIPAddr pAddr) = 0;
	virtual IpSteamNetworkingFakeUDPPort CreateFakeUDPPort(Int32 iFakeServerPort) = 0;

} ISteamNetworkingSockets, *IpSteamNetworkingSockets;

#define STEAMNETWORKINGSOCKETS_INTERFACE_VERSION "SteamNetworkingSockets012"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_SteamNetConnectionStatusChangedCallback_t_ ((Int32)(k_iSteamNetworkingSocketsCallbacks + 1))
typedef struct _SteamNetConnectionStatusChangedCallback_t_ {

	HSteamNetConnection hSteamNetConnection;
	SteamNetConnectionInfo_t SteamNetConnectionInfo;
	ESteamNetworkingConnectionState eOldState;

} SteamNetConnectionStatusChangedCallback_t, *pSteamNetConnectionStatusChangedCallback_t;

#define k_iCallbback_SteamNetAuthenticationStatus_t_ ((Int32)(k_iSteamNetworkingSocketsCallbacks + 2))
typedef struct _SteamNetAuthenticationStatus_t_ {

	ESteamNetworkingAvailability eSteamNetworkingAvailability;
	CharA chDebugMsg[256];

} SteamNetAuthenticationStatus_t, *pSteamNetAuthenticationStatus_t;

#define k_iCallbback_SteamNetworkingFakeIPResult_t_ ((Int32)(k_iSteamNetworkingSocketsCallbacks + 3))
typedef struct _SteamNetworkingFakeIPResult_t_ {

	EResult eResult;
	SteamNetworkingIdentity Identity;
	Uint32 nIP;
	Uint16 nPorts[8];

} SteamNetworkingFakeIPResult_t, *pSteamNetworkingFakeIPResult_t;

#pragma pack(pop)

#endif // _ISTEAMNETWORKINGSOCKETS_
