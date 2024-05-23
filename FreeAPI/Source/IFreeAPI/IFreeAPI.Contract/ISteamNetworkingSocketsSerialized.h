#ifndef _ISTEAMNETWORKINGSOCKETSSERIALIZED_
#define _ISTEAMNETWORKINGSOCKETSSERIALIZED_

#include "..\..\FreeAPI.Typedef.h"

typedef class _ISteamNetworkingSocketsSerialized002_ {
public:
	
	virtual void SendP2PRendezvous(SteamId_t SteamIdRemote, Uint32 ConnectionIdSrc, const pVoid pMsgRendezvous, Uint32 cbRendezvous) = 0;
	virtual void SendP2PConnectionFailure(SteamId_t SteamIdRemote, Uint32 unConnectionIDDest, Uint32 nReason, pCStrA pchReason) = 0;
	virtual SteamAPICall_t GetCertAsync() = 0;
	virtual Int32 GetNetworkConfigJSON(pVoid pvJSON, Uint32 cbSize, pCStrA pchLauncherPartner) = 0;
	virtual void CacheRelayTicket(const pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual Uint32 GetCachedRelayTicketCount() = 0;
	virtual Uint32 GetCachedRelayTicket(Uint32 idxTicket, pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual void PostConnectionStateMsg(const pVoid pvMsg, Uint32 cbMsg) = 0;

} ISteamNetworkingSocketsSerialized002, *IpSteamNetworkingSocketsSerialized002;

typedef class _ISteamNetworkingSocketsSerialized003_ {
public:

	virtual void SendP2PRendezvous(SteamId_t SteamIdRemote, Uint32 unConnectionIDSrc, const pVoid pMsgRendezvous, Uint32 cbRendezvous) = 0;
	virtual void SendP2PConnectionFailure(SteamId_t SteamIdRemote, Uint32 unConnectionIDDest, Uint32 nReason, pCStrA pchReason) = 0;
	virtual SteamAPICall_t GetCertAsync() = 0;
	virtual Int32 GetNetworkConfigJSON(pVoid pvJSON, Uint32 cbSize, pCStrA pchLauncherPartner) = 0;
	virtual void CacheRelayTicket(const pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual Uint32 GetCachedRelayTicketCount() = 0;
	virtual Uint32 GetCachedRelayTicket(Uint32 idxTicket, pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual void PostConnectionStateMsg(const pVoid pvMsg, Uint32 cbMsg) = 0;

} ISteamNetworkingSocketsSerialized003, *IpSteamNetworkingSocketsSerialized003;

typedef class _ISteamNetworkingSocketsSerialized004_ {
public:

	virtual void SendP2PRendezvous(SteamId_t SteamIdRemote, Uint32 ConnectionIdSrc, const pVoid pMsgRendezvous, Uint32 cbRendezvous) = 0;
	virtual void SendP2PConnectionFailure(SteamId_t SteamIdRemote, Uint32 nConnectionIdDest, Uint32 nReason, pCStrA pchReason) = 0;
	virtual SteamAPICall_t GetCertAsync() = 0;
	virtual Int32 GetNetworkConfigJSON(pVoid pvJSON, Uint32 cbSize, pCStrA pchLauncherPartner) = 0;
	virtual void CacheRelayTicket(const pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual Uint32 GetCachedRelayTicketCount() = 0;
	virtual Uint32 GetCachedRelayTicket(Uint32 idxTicket, pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual void PostConnectionStateMsg(const pVoid pvMsg, Uint32 cbMsg) = 0;
	virtual Bool GetSTUNServer(Int32 nNumPort, pStrA pchSTUN, Uint32 cchSTUN) = 0;
	virtual Bool BAllowDirectConnectToPeer(pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;

} ISteamNetworkingSocketsSerialized004, *IpSteamNetworkingSocketsSerialized004;

typedef class _ISteamNetworkingSocketsSerialized_ {
public:

	virtual void SendP2PRendezvous(SteamId_t SteamIdRemote, Uint32 ConnectionIdSrc, const pVoid pMsgRendezvous, Uint32 cbRendezvous) = 0;
	virtual void SendP2PConnectionFailure(SteamId_t SteamIdRemote, Uint32 nConnectionIdDest, Uint32 nReason, pCStrA pchReason) = 0;
	virtual SteamAPICall_t GetCertAsync() = 0;
	virtual Int32 GetNetworkConfigJSON(/* [out] */ pVoid pvJSON, Uint32 cbSize, pCStrA pchLauncherPartner) = 0;
	virtual void CacheRelayTicket(const pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual Uint32 GetCachedRelayTicketCount() = 0;
	virtual Uint32 GetCachedRelayTicket(Uint32 iTicket, /* [out] */ pVoid pvTicket, Uint32 cbTicket) = 0;
	virtual void PostConnectionStateMsg(const pVoid pvMsg, Uint32 cbMsg) = 0;
	virtual Bool GetSTUNServer(Int32 nNumPort, /* [out] */ pStrA pchSTUN, Uint32 cchSTUN) = 0;
	virtual Bool BAllowDirectConnectToPeer(pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual Bool BeginAsyncRequestFakeIP(Int32 nNumPorts) = 0;

} ISteamNetworkingSocketsSerialized, *IpSteamNetworkingSocketsSerialized;

#define STEAMNETWORKINGSOCKETSSERIALIZED_INTERFACE_VERSION "SteamNetworkingSocketsSerialized005"

#pragma pack(push, 1)

#define k_iCallbback_SteamNetworkingSocketsConfigUpdated_t_ ((Int32)(k_iSteamNetworkingCallbacks + 95))
typedef struct _SteamNetworkingSocketsConfigUpdated_t_ {

	Byte Data[4];

} SteamNetworkingSocketsConfigUpdated_t, *pSteamNetworkingSocketsConfigUpdated_t;

#define k_iCallbback_SteamNetworkingSocketsCert_t_ ((Int32)(k_iSteamNetworkingCallbacks + 96))
typedef struct _SteamNetworkingSocketsCert_t_ {

	EResult eResult;
	Uint32 cbCert;
	CharA CertOrMsg[512];
	Uint64 caKeyID;
	Uint32 cbSignature;
	CharA Signature[128];
	Uint32 cbPrivKey;
	CharA PrivateKey[128];

} SteamNetworkingSocketsCert_t, *pSteamNetworkingSocketsCert_t;

#define k_iCallbback_SteamNetworkingSocketsRecvP2PFailure_t_ ((Int32)(k_iSteamNetworkingCallbacks + 97))
typedef struct _SteamNetworkingSocketsRecvP2PFailure_t_ {

	Uint64 SteamIdRemote;
	Uint32 unConnectionIDDest;
	Uint32 Data;
	Uint32 nReason;
	CharA pchReason[128];

} SteamNetworkingSocketsRecvP2PFailure_t, *pSteamNetworkingSocketsRecvP2PFailure_t;

#define k_iCallbback_SteamNetworkingSocketsRecvP2PRendezvous_t_ ((Int32)(k_iSteamNetworkingCallbacks + 98))
typedef struct _SteamNetworkingSocketsRecvP2PRendezvous_t_ {

	Uint64 SteamIdRemote;
	Uint32 unConnectionIDSrc;
	Uint32 cbRendezvous;
	CharA MsgRendezvous[512];

} SteamNetworkingSocketsRecvP2PRendezvous_t, *pSteamNetworkingSocketsRecvP2PRendezvous_t;

#pragma pack(pop)

#endif // _ISTEAMNETWORKINGSOCKETSSERIALIZED_
