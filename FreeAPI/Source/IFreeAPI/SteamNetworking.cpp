// -----------------------------------------------------------------------------
#include "SteamNetworking.h"
// -----------------------------------------------------------------------------

Bool _SteamNetworking_::SendP2PPacket(SteamId_t SteamIdRemote, pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType, Int32 nChannel) {

	return False;

}

Bool _SteamNetworking_::IsP2PPacketAvailable(pUint32 pcbMsgSize, Int32 nChannel) {

	return False;

}

Bool _SteamNetworking_::ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote, Int32 nChannel) {

	return False;

}

Bool _SteamNetworking_::AcceptP2PSessionWithUser(SteamId_t SteamIdRemote) {

	return False;

}

Bool _SteamNetworking_::CloseP2PSessionWithUser(SteamId_t SteamIdRemote) {

	return False;

}

Bool _SteamNetworking_::CloseP2PChannelWithUser(SteamId_t SteamIdRemote, Int32 nChannel) {

	return False;

}

Bool _SteamNetworking_::GetP2PSessionState(SteamId_t SteamIdRemote, pP2PSessionState_t pConnectionState) {

	return False;

}

Bool _SteamNetworking_::AllowP2PPacketRelay(Bool bAllow) {

	return False;

}

SNetListenSocket_t _SteamNetworking_::CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) {

	return (SNetListenSocket_t)(0x00000000);

}

SNetSocket_t _SteamNetworking_::CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) {

	return (SNetSocket_t)(0x00000000);

}

SNetSocket_t _SteamNetworking_::CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) {

	return (SNetSocket_t)(0x00000000);

}

Bool _SteamNetworking_::DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) {

	return False;

}

Bool _SteamNetworking_::DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) {

	return False;

}

Bool _SteamNetworking_::SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) {

	return False;

}

Bool _SteamNetworking_::IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) {

	return False;

}

Bool _SteamNetworking_::RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) {

	return False;

}

Bool _SteamNetworking_::IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) {

	return False;

}

Bool _SteamNetworking_::RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) {

	return False;

}

Bool _SteamNetworking_::GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) {

	return False;

}

Bool _SteamNetworking_::GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) {

	return False;

}

ESNetSocketConnectionType _SteamNetworking_::GetSocketConnectionType(SNetSocket_t hSocket) {

	return k_ESNetSocketConnectionTypeNotConnected;

}

Int32 _SteamNetworking_::GetMaxPacketSize(SNetSocket_t hSocket) {

	return Int32_MAX;

}
