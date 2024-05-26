#ifndef _ISTEAMNETWORKINGMESSAGES_
#define _ISTEAMNETWORKINGMESSAGES_

#include "..\..\FreeAPI.Typedef.h"

typedef class _ISteamNetworkingMessages_ {
public:

	/*Returns:
	  k_EREsultOK on success.
	  k_EResultNoConnection */
	virtual EResult SendMessageToUser(const pSteamNetworkingIdentity pIdentityRemote, pCVoid pvData, Uint32 cbData, Int32 nSendFlags, Int32 nRemoteChannel) = 0;

	virtual Int32 ReceiveMessagesOnChannel(Int32 nLocalChannel, /* [out] */ pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) = 0;
	virtual Bool AcceptSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) = 0;
	
	virtual Bool CloseSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) = 0;
	virtual Bool CloseChannelWithUser(const pSteamNetworkingIdentity pIdentityRemote, Int32 nLocalChannel) = 0;
	
	virtual ESteamNetworkingConnectionState GetSessionConnectionInfo(const pSteamNetworkingIdentity pIdentityRemote, /* [out] */ pSteamNetConnectionInfo_t pConnectionInfo, /* [out] */ pSteamNetConnectionRealTimeStatus_t pQuickStatus) = 0;

} ISteamNetworkingMessages, *IpSteamNetworkingMessages;

#define STEAMNETWORKINGMESSAGES_INTERFACE_VERSION "SteamNetworkingMessages002"

#pragma pack(push, 1)

#define k_iCallbback_SteamNetworkingMessagesSessionRequest_t_ ((Int32)(k_iSteamNetworkingMessagesCallbacks + 1))
typedef struct _SteamNetworkingMessagesSessionRequest_t_ {

	SteamNetworkingIdentity SteamNetworkingIdentityRemote;

} SteamNetworkingMessagesSessionRequest_t, *pSteamNetworkingMessagesSessionRequest_t;

#define k_iCallbback_SteamNetworkingMessagesSessionFailed_t_ ((Int32)(k_iSteamNetworkingMessagesCallbacks + 2))
typedef struct _SteamNetworkingMessagesSessionFailed_t_ {

	SteamNetConnectionInfo_t SteamNetConnectionInfo;

} SteamNetworkingMessagesSessionFailed_t, *pSteamNetworkingMessagesSessionFailed_t;

#pragma pack(pop)

#endif // _ISTEAMNETWORKINGMESSAGES_
