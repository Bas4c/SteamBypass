// -----------------------------------------------------------------------------
#include "SteamNetworkingSocketsSerialized.h"
// -----------------------------------------------------------------------------

void _SteamNetworkingSocketsSerialized_::SendP2PRendezvous(SteamId_t SteamIdRemote, Uint32 ConnectionIdSrc, const pVoid pMsgRendezvous, Uint32 cbRendezvous) {

	/* Empty Method */

}

void _SteamNetworkingSocketsSerialized_::SendP2PConnectionFailure(SteamId_t SteamIdRemote, Uint32 nConnectionIdDest, Uint32 nReason, pCStrA pchReason) {

	/* Empty Method */

}

SteamAPICall_t _SteamNetworkingSocketsSerialized_::GetCertAsync() {

	return k_SteamAPICall_Invalid;

}

Int32 _SteamNetworkingSocketsSerialized_::GetNetworkConfigJSON(pVoid pvJSON, Uint32 cbSize, pCStrA pchLauncherPartner) {

	return 0;

}

void _SteamNetworkingSocketsSerialized_::CacheRelayTicket(const pVoid pvTicket, Uint32 cbTicket) {

	/* Empty Method */

}

Uint32 _SteamNetworkingSocketsSerialized_::GetCachedRelayTicketCount() {

	return 0U;

}

Uint32 _SteamNetworkingSocketsSerialized_::GetCachedRelayTicket(Uint32 iTicket, pVoid pvTicket, Uint32 cbTicket) {

	return 0U;

}

void _SteamNetworkingSocketsSerialized_::PostConnectionStateMsg(const pVoid pMsg, Uint32 cbMsg) {

	/* Empty Method */

}

Bool _SteamNetworkingSocketsSerialized_::GetSTUNServer(Int32 nNumPort, pStrA pchSTUN, Uint32 cchSTUN) {

	return False;

}

Bool _SteamNetworkingSocketsSerialized_::BAllowDirectConnectToPeer(pSteamNetworkingIdentity pSteamNetworkingIdentity) {

	return True;

}

Bool _SteamNetworkingSocketsSerialized_::BeginAsyncRequestFakeIP(Int32 nNumPorts) {

	return False;

}
