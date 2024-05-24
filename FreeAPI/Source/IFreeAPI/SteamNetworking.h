#ifndef _STEAMNETWORKING_
#define _STEAMNETWORKING_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamNetworking.h"
// -----------------------------------------------------------------------------

typedef class _SteamNetworking_ : public _ISteamNetworking001_,
 public _ISteamNetworking002_, public _ISteamNetworking003_,
 public _ISteamNetworking004_, public _ISteamNetworking005_,
 public _ISteamNetworking_ {
public:

	_SteamNetworking_() = default;
	_SteamNetworking_(const _SteamNetworking_&) = delete;
	_SteamNetworking_& operator=(const _SteamNetworking_&) = delete;

	/* Sends a P2P packet to the specified user
		UDP-like, unreliable and a max packet size of 1200 bytes
		the first packet send may be delayed as the NAT-traversal code runs
		if we can't get through to the user, an error will be posted via the callback P2PSessionConnectFail_t
		see EP2PSend enum above for the descriptions of the different ways of sending packets
		nChannel is a routing number you can use to help route message to different systems - you'll have to call ReadP2PPacket()
		with the same channel number in order to retrieve the data on the other end
		using different channels to talk to the same user will still use the same underlying p2p connection, saving on resources */
	Bool SendP2PPacket(SteamId_t SteamIdRemote, pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType) override;
	Bool SendP2PPacket(SteamId_t SteamIdRemote, pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType, Int32 nChannel) override;
	Bool IsP2PPacketAvailable(pUint32 pcbMsgSize) override;
	Bool IsP2PPacketAvailable(pUint32 pcbMsgSize, Int32 nChannel) override;

	/* Reads in a packet that has been sent from another user via SendP2PPacket()
		returns the size of the message and the SteamId of the user who sent it in the last two parameters
		if the buffer passed in is too small, the message will be truncated
		this call is not blocking, and will return false if no data is available */
	Bool ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote) override;
	Bool ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote, Int32 nChannel) override;

	Bool AcceptP2PSessionWithUser(SteamId_t SteamIdRemote) override;
	Bool CloseP2PSessionWithUser(SteamId_t SteamIdRemote) override;

	Bool CloseP2PChannelWithUser(SteamId_t SteamIdRemote, Int32 nChannel) override;
	Bool GetP2PSessionState(SteamId_t SteamIdRemote, pP2PSessionState_t pConnectionState) override;
	Bool AllowP2PPacketRelay(Bool bAllow) override;

	SNetListenSocket_t CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) override;
	SNetSocket_t CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) override;
	SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) override;
	Bool DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) override;
	Bool DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) override;

	Bool SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) override;
	Bool IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) override;
	Bool RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) override;
	Bool IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) override;
	Bool RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) override;

	Bool GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) override;
	Bool GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) override;
	ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket) override;
	Int32 GetMaxPacketSize(SNetSocket_t hSocket) override;

	~_SteamNetworking_() = default;

} SteamNetworking, *pSteamNetworking;

#endif // !_STEAMNETWORKING_
