#ifndef _STEAMNETWORKINGSOCKETSSERIALIZED_
#define _STEAMNETWORKINGSOCKETSSERIALIZED_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamNetworkingSocketsSerialized.h"
// -----------------------------------------------------------------------------

typedef class _SteamNetworkingSocketsSerialized_ : public _ISteamNetworkingSocketsSerialized002_,
 public _ISteamNetworkingSocketsSerialized003_, public _ISteamNetworkingSocketsSerialized004_,
 public _ISteamNetworkingSocketsSerialized_ {
public:

	_SteamNetworkingSocketsSerialized_() = default;
	_SteamNetworkingSocketsSerialized_(const _SteamNetworkingSocketsSerialized_&) = delete;
	_SteamNetworkingSocketsSerialized_& operator=(const _SteamNetworkingSocketsSerialized_&) = delete;

	void SendP2PRendezvous(SteamId_t SteamIdRemote, Uint32 ConnectionIdSrc, const pVoid pMsgRendezvous, Uint32 cbRendezvous) override;
	void SendP2PConnectionFailure(SteamId_t SteamIdRemote, Uint32 nConnectionIdDest, Uint32 nReason, pCStrA pchReason) override;
	SteamAPICall_t GetCertAsync() override;
	Int32 GetNetworkConfigJSON(pVoid pvJSON, Uint32 cbSize, pCStrA pchLauncherPartner) override;
	void CacheRelayTicket(const pVoid pvTicket, Uint32 cbTicket) override;
	Uint32 GetCachedRelayTicketCount() override;
	Uint32 GetCachedRelayTicket(Uint32 iTicket, pVoid pvTicket, Uint32 cbTicket) override;
	void PostConnectionStateMsg(const pVoid pvMsg, Uint32 cbMsg) override;
	Bool GetSTUNServer(Int32 nNumPort, pStrA pchSTUN, Uint32 cchSTUN) override;
	Bool BAllowDirectConnectToPeer(pSteamNetworkingIdentity pSteamNetworkingIdentity) override;
	Bool BeginAsyncRequestFakeIP(Int32 nNumPorts) override;

	~_SteamNetworkingSocketsSerialized_() = default;

} SteamNetworkingSocketsSerialized, *pSteamNetworkingSocketsSerialized;

#endif // !_STEAMNETWORKINGSOCKETSSERIALIZED_
