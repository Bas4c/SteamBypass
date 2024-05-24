// -----------------------------------------------------------------------------
#include "SteamNetworking.h"
// -----------------------------------------------------------------------------

Bool _SteamNetworking_::SendP2PPacket(SteamId_t SteamIdRemote, pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType) {
	DEBUGBREAK("ISteamNetworking::SendP2PPacket");

	return False;

}

Bool _SteamNetworking_::SendP2PPacket(SteamId_t SteamIdRemote, pVoid pbData, Uint32 cbData, EP2PSend eP2PSendType, Int32 nChannel) {
	DEBUGBREAK("ISteamNetworking::SendP2PPacket");

	return False;

}

Bool _SteamNetworking_::IsP2PPacketAvailable(pUint32 pcbMsgSize) {
	DEBUGBREAK("ISteamNetworking::IsP2PPacketAvailable");

	return False;

}

Bool _SteamNetworking_::IsP2PPacketAvailable(pUint32 pcbMsgSize, Int32 nChannel) {
	DEBUGBREAK("ISteamNetworking::IsP2PPacketAvailable");

	return False;

}

Bool _SteamNetworking_::ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote) {
	DEBUGBREAK("ISteamNetworking::ReadP2PPacket");

	return False;

}

Bool _SteamNetworking_::ReadP2PPacket(pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote, Int32 nChannel) {
	DEBUGBREAK("ISteamNetworking::ReadP2PPacket");

	return False;

}

Bool _SteamNetworking_::AcceptP2PSessionWithUser(SteamId_t SteamIdRemote) {
	DEBUGBREAK("ISteamNetworking::AcceptP2PSessionWithUser");

	return False;

}

Bool _SteamNetworking_::CloseP2PSessionWithUser(SteamId_t SteamIdRemote) {
	DEBUGBREAK("ISteamNetworking::CloseP2PSessionWithUser");

	return False;

}

Bool _SteamNetworking_::CloseP2PChannelWithUser(SteamId_t SteamIdRemote, Int32 nChannel) {
	DEBUGBREAK("ISteamNetworking::CloseP2PChannelWithUser");

	return False;

}

Bool _SteamNetworking_::GetP2PSessionState(SteamId_t SteamIdRemote, pP2PSessionState_t pConnectionState) {
	DEBUGBREAK("ISteamNetworking::GetP2PSessionState");

	return False;

}

Bool _SteamNetworking_::AllowP2PPacketRelay(Bool bAllow) {
	DEBUGBREAK("ISteamNetworking::AllowP2PPacketRelay");

	return False;

}

SNetListenSocket_t _SteamNetworking_::CreateListenSocket(Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) {
	DEBUGBREAK("ISteamNetworking::CreateListenSocket");

	return (SNetListenSocket_t)(0x00000000);

}

SNetSocket_t _SteamNetworking_::CreateP2PConnectionSocket(SteamId_t SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSeconds, Bool bAllowUseOfPacketRelay) {
	DEBUGBREAK("ISteamNetworking::CreateP2PConnectionSocket");

	return (SNetSocket_t)(0x00000000);

}

SNetSocket_t _SteamNetworking_::CreateConnectionSocket(SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSeconds) {
	DEBUGBREAK("ISteamNetworking::CreateConnectionSocket");

	return (SNetSocket_t)(0x00000000);

}

Bool _SteamNetworking_::DestroySocket(SNetSocket_t hSocket, Bool bNotifyRemoteEnd) {
	DEBUGBREAK("ISteamNetworking::DestroySocket");

	return False;

}

Bool _SteamNetworking_::DestroyListenSocket(SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) {
	DEBUGBREAK("ISteamNetworking::DestroyListenSocket");

	return False;

}

Bool _SteamNetworking_::SendDataOnSocket(SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) {
	DEBUGBREAK("ISteamNetworking::SendDataOnSocket");

	return False;

}

Bool _SteamNetworking_::IsDataAvailableOnSocket(SNetSocket_t hSocket, pUint32 pcbMsgSize) {
	DEBUGBREAK("ISteamNetworking::IsDataAvailableOnSocket");

	return False;

}

Bool _SteamNetworking_::RetrieveDataFromSocket(SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) {
	DEBUGBREAK("ISteamNetworking::RetrieveDataFromSocket");

	return False;

}

Bool _SteamNetworking_::IsDataAvailable(SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) {
	DEBUGBREAK("ISteamNetworking::IsDataAvailable");

	return False;

}

Bool _SteamNetworking_::RetrieveData(SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) {
	DEBUGBREAK("ISteamNetworking::RetrieveData");

	return False;

}

Bool _SteamNetworking_::GetSocketInfo(SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) {
	DEBUGBREAK("ISteamNetworking::GetSocketInfo");

	return False;

}

Bool _SteamNetworking_::GetListenSocketInfo(SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) {
	DEBUGBREAK("ISteamNetworking::GetListenSocketInfo");

	return False;

}

ESNetSocketConnectionType _SteamNetworking_::GetSocketConnectionType(SNetSocket_t hSocket) {
	DEBUGBREAK("ISteamNetworking::GetSocketConnectionType");

	return k_ESNetSocketConnectionTypeNotConnected;

}

Int32 _SteamNetworking_::GetMaxPacketSize(SNetSocket_t hSocket) {
	DEBUGBREAK("ISteamNetworking::GetMaxPacketSize");

	return Int32_MAX;

}
