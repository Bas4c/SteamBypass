// -----------------------------------------------------------------------------
#include "SteamNetworkingSocketsSerialized.h"
// -----------------------------------------------------------------------------

void _SteamNetworkingSocketsSerialized_::SendP2PRendezvous(SteamId_t SteamIdRemote, Uint32 ConnectionIdSrc, const pVoid pMsgRendezvous, Uint32 cbRendezvous) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::SendP2PRendezvous");

	/* Empty Method */

}

void _SteamNetworkingSocketsSerialized_::SendP2PConnectionFailure(SteamId_t SteamIdRemote, Uint32 nConnectionIdDest, Uint32 nReason, pCStrA pchReason) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::SendP2PConnectionFailure");

	/* Empty Method */

}

SteamAPICall_t _SteamNetworkingSocketsSerialized_::GetCertAsync() {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::GetCertAsync");

	return k_SteamAPICall_Invalid;

}

Int32 _SteamNetworkingSocketsSerialized_::GetNetworkConfigJSON(pVoid pvJSON, Uint32 cbSize, pCStrA pchLauncherPartner) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::GetNetworkConfigJSON");

	return 0;

}

void _SteamNetworkingSocketsSerialized_::CacheRelayTicket(const pVoid pvTicket, Uint32 cbTicket) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::CacheRelayTicket");

	/* Empty Method */

}

Uint32 _SteamNetworkingSocketsSerialized_::GetCachedRelayTicketCount() {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::GetCachedRelayTicketCount");

	return 0U;

}

Uint32 _SteamNetworkingSocketsSerialized_::GetCachedRelayTicket(Uint32 iTicket, pVoid pvTicket, Uint32 cbTicket) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::GetCachedRelayTicket");

	return 0U;

}

void _SteamNetworkingSocketsSerialized_::PostConnectionStateMsg(const pVoid pvMsg, Uint32 cbMsg) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::PostConnectionStateMsg");

	/* Empty Method */

}

Bool _SteamNetworkingSocketsSerialized_::GetSTUNServer(Int32 nNumPort, pStrA pchSTUN, Uint32 cchSTUN) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::GetSTUNServer");

	return False;

}

Bool _SteamNetworkingSocketsSerialized_::BAllowDirectConnectToPeer(pSteamNetworkingIdentity pSteamNetworkingIdentity) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::BAllowDirectConnectToPeer");

	return True;

}

Bool _SteamNetworkingSocketsSerialized_::BeginAsyncRequestFakeIP(Int32 nNumPorts) {
	DEBUGBREAK("ISteamNetworkingSocketsSerialized::BeginAsyncRequestFakeIP");

	return False;

}
