#ifndef _ISTEAMNETWORKING_
#define _ISTEAMNETWORKING_

#include "..\..\FreeAPI.Typedef.h"

typedef enum _EP2PSessionError_ {

	k_EP2PSessionErrorNone,
	k_EP2PSessionErrorNotRunningApp,
	k_EP2PSessionErrorNoRightsToApp,
	k_EP2PSessionErrorDestinationNotLoggedIn,
	k_EP2PSessionErrorTimeout,
	k_EP2PSessionErrorMax

} EP2PSessionError, *pEP2PSessionError;

typedef enum _EP2PSend_ {

	k_EP2PSendUnreliable,
	k_EP2PSendUnreliableNoDelay,
	k_EP2PSendReliable,
	k_EP2PSendReliableWithBuffering

} EP2PSend, *pEP2PSend;

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

typedef struct _P2PSessionState_t_ {

	Uint8 bConnectionActive;
	Uint8 bConnecting;
	Uint8 eP2PSessionError;	
	Uint8 bUsingRelay;
	Int32 nBytesQueuedForSend;
	Int32 nPacketsQueuedForSend;
	Uint32 RemoteIP;
	Uint16 RemotePort;

} P2PSessionState_t, *pP2PSessionState_t;

#pragma pack(pop)

typedef Uint32 SNetSocket_t, *pSNetSocket_t;
typedef Uint32 SNetListenSocket_t, *pSNetListenSocket_t;

typedef enum _ESNetSocketState_ {

	k_ESNetSocketStateInvalid,
	k_ESNetSocketStateConnected,
	k_ESNetSocketStateInitiated = 10,
	k_ESNetSocketStateLocalCandidatesFound,
	k_ESNetSocketStateReceivedRemoteCandidates,
	k_ESNetSocketStateChallengeHandshake = 15,
	k_ESNetSocketStateDisconnecting = 21,
	k_ESNetSocketStateLocalDisconnect,
	k_ESNetSocketStateTimeoutDuringConnect,
	k_ESNetSocketStateRemoteEndDisconnected,
	k_ESNetSocketStateConnectionBroken

} ESNetSocketState, *pESNetSocketState;

typedef enum _ESNetSocketConnectionType_ {

	k_ESNetSocketConnectionTypeNotConnected,
	k_ESNetSocketConnectionTypeUDP,
	k_ESNetSocketConnectionTypeUDPRelay

} ESNetSocketConnectionType, *pESNetSocketConnectionType;

typedef class _ISteamNetworking001_ {
public:

	virtual SNetListenSocket_t CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) = 0;
	virtual Bool DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) = 0;
	virtual Bool IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) = 0;
	virtual Bool RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) = 0;
	virtual Bool IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) = 0;
	virtual Bool GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) = 0;

} ISteamNetworking001, *IpSteamNetworking001;

typedef class _ISteamNetworking002_ {
public:

	virtual SNetListenSocket_t CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) = 0;
	virtual Bool DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) = 0;
	virtual Bool IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) = 0;
	virtual Bool RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) = 0;
	virtual Bool IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) = 0;
	virtual Bool GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) = 0;
	virtual ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket) = 0;
	virtual Int32 GetMaxPacketSize(SNetSocket_t hSocket) = 0;

} ISteamNetworking002, *IpSteamNetworking002;

typedef class _ISteamNetworking003_ {
public:

	virtual Bool SendP2PPacket(SteamId_t SteamIdRemote, const pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType) = 0;
	virtual Bool IsP2PPacketAvailable(pUint32 pcbMsgSize) = 0;
	virtual Bool ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote) = 0;
	virtual Bool AcceptP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;
	virtual Bool CloseP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;
	virtual Bool GetP2PSessionState(SteamId_t SteamIdRemote, pP2PSessionState_t pConnectionState) = 0;
	virtual SNetListenSocket_t CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) = 0;
	virtual Bool DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) = 0;
	virtual Bool IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) = 0;
	virtual Bool RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) = 0;
	virtual Bool IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) = 0;
	virtual Bool GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) = 0;
	virtual ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket) = 0;
	virtual Int32 GetMaxPacketSize(SNetSocket_t hSocket) = 0;

} ISteamNetworking003, *IpSteamNetworking003;

typedef class _ISteamNetworking004_ {
public:

	virtual Bool SendP2PPacket(SteamId_t SteamIdRemote, const pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType, Int32 nChannel) = 0;
	virtual Bool IsP2PPacketAvailable(pUint32 pcbMsgSize, Int32 nChannel) = 0;
	virtual Bool ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote, Int32 nChannel) = 0;
	virtual Bool AcceptP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;
	virtual Bool CloseP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;
	virtual Bool GetP2PSessionState(SteamId_t SteamIdRemote, pP2PSessionState_t pConnectionState) = 0;
	virtual SNetListenSocket_t CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) = 0;
	virtual Bool DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) = 0;
	virtual Bool IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) = 0;
	virtual Bool RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) = 0;
	virtual Bool IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) = 0;
	virtual Bool GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) = 0;
	virtual ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket) = 0;
	virtual Int32 GetMaxPacketSize(SNetSocket_t hSocket) = 0;

} ISteamNetworking004, *IpSteamNetworking004;

typedef class _ISteamNetworking005_ {
public:

	virtual Bool SendP2PPacket(SteamId_t SteamIdRemote, const pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType, Int32 nChannel) = 0;
	virtual Bool IsP2PPacketAvailable(pUint32 pcbMsgSize, Int32 nChannel) = 0;
	virtual Bool ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote, Int32 nChannel) = 0;
	virtual Bool AcceptP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;
	virtual Bool CloseP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;
	virtual Bool CloseP2PChannelWithUser(SteamId_t SteamIdRemote, Int32 nChannel) = 0;
	virtual Bool GetP2PSessionState(SteamId_t SteamIdRemote, pP2PSessionState_t pConnectionState) = 0;
	virtual Bool AllowP2PPacketRelay(Bool bAllow) = 0;
	virtual SNetListenSocket_t CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) = 0;
	virtual Bool DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) = 0;
	virtual Bool IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) = 0;
	virtual Bool RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) = 0;
	virtual Bool IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) = 0;
	virtual Bool GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) = 0;
	virtual Bool GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) = 0;
	virtual ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket) = 0;
	virtual Int32 GetMaxPacketSize(SNetSocket_t hSocket) = 0;

} ISteamNetworking005, *IpSteamNetworking005;

// -----------------------------------------------------------------------------
// Purpose: Functions for making connections and sending data between clients,
//  traversing NAT's where possible
// -----------------------------------------------------------------------------
typedef class _ISteamNetworking_ {
public:

	/* Sends a P2P packet to the specified user
	    UDP-like, unreliable and a max packet size of 1200 bytes
	    the first packet send may be delayed as the NAT-traversal code runs
	    if we can't get through to the user, an error will be posted via the callback P2PSessionConnectFail_t
	    see EP2PSend enum above for the descriptions of the different ways of sending packets
	    nChannel is a routing number you can use to help route message to different systems - you'll have to call ReadP2PPacket() 
	    with the same channel number in order to retrieve the data on the other end
	    using different channels to talk to the same user will still use the same underlying p2p connection, saving on resources */
	virtual Bool SendP2PPacket(SteamId_t SteamIdRemote, const pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType, Int32 nChannel) = 0;
	virtual Bool IsP2PPacketAvailable(/* [out] */ pUint32 pcbMsgSize, Int32 nChannel) = 0;

	/* Reads in a packet that has been sent from another user via SendP2PPacket()
	    returns the size of the message and the SteamId of the user who sent it in the last two parameters
	    if the buffer passed in is too small, the message will be truncated
	    this call is not blocking, and will return false if no data is available */
	virtual Bool ReadP2PPacket(/* [out] */ pVoid pbDest, Uint32 cbDest, /* [out] */ pUint32 pcbMsgSize, /* [out] */ pSteamId_t pSteamIdRemote, Int32 nChannel) = 0;

	virtual Bool AcceptP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;
	virtual Bool CloseP2PSessionWithUser(SteamId_t SteamIdRemote) = 0;

	virtual Bool CloseP2PChannelWithUser(SteamId_t SteamIdRemote, Int32 nChannel) = 0;
	virtual Bool GetP2PSessionState(SteamId_t SteamIdRemote, /* [out] */ pP2PSessionState_t pConnectionState) = 0;
	virtual Bool AllowP2PPacketRelay(Bool bAllow) = 0;

	virtual SNetListenSocket_t CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) = 0;
	virtual SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) = 0;
	virtual Bool DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;
	virtual Bool DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) = 0;

	virtual Bool SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) = 0;
	virtual Bool IsDataAvailableOnSocket(SNetSocket_t hSocket, /* [out] */ pUint32 pcbMsgSize) = 0;
	virtual Bool RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, /* [out] */ pUint32 pcbMsgSize) = 0;
	virtual Bool IsDataAvailable(SNetListenSocket_t hListenSocket, /* [out] */ pUint32 pcbMsgSize, /* [out] */ pSNetSocket_t phSocket) = 0;
	virtual Bool RetrieveData(SNetListenSocket_t hListenSocket, /* [out] */ pVoid pbDest, Uint32 cbDest, /* [out] */ pUint32 pcbMsgSize, /* [out] */ pSNetSocket_t phSocket) = 0;
	
	virtual Bool GetSocketInfo(SNetSocket_t hSocket, /* [out] */ pSteamId_t pSteamIdRemote, /* [out] */ pInt32 peSocketStatus, /* [out] */ pSteamIPAddress_t pnIPAddrRemote, /* [out] */ pUint16 pPortRemote) = 0;
	virtual Bool GetListenSocketInfo(SNetListenSocket_t hListenSocket,/* [out] */  pSteamIPAddress_t pnIP, /* [out] */ pUint16 pPort) = 0;
	virtual ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket) = 0;
	virtual Int32 GetMaxPacketSize(SNetSocket_t hSocket) = 0;

} ISteamNetworking, *IpSteamNetworking;

#define STEAMNETWORKING_INTERFACE_VERSION "SteamNetworking006"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_SocketStatusCallback_t ((Int32)(k_iSteamNetworkingCallbacks + 1))
typedef struct _SocketStatusCallback_t_ {

	SNetSocket_t hSocket;
	SNetListenSocket_t hListenSocket;
	SteamId_t SteamIdRemote;
	Int32 eSNetSocketState;

} SocketStatusCallback_t, *pSocketStatusCallback_t;

#define k_iCallbback_P2PSessionRequest_t ((Int32)(k_iSteamNetworkingCallbacks + 2))
typedef struct _P2PSessionRequest_t_ {

	SteamId_t SteamIdRemote;

} P2PSessionRequest_t, *pP2PSessionRequest_t;

#define k_iCallbback_P2PSessionConnectFail_t ((Int32)(k_iSteamNetworkingCallbacks + 3))
typedef struct _P2PSessionConnectFail_t_ {
	
	SteamId_t SteamIdRemote;
	Uint8 eP2PSessionError;

} P2PSessionConnectFail_t, *pP2PSessionConnectFail_t;

#pragma pack(pop)

#endif // _ISTEAMNETWORKING_
