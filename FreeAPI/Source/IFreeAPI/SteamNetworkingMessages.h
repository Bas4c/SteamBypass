#ifndef _STEAMNETWORKINGMESSAGES_
#define _STEAMNETWORKINGMESSAGES_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamNetworkingMessages.h"
// -----------------------------------------------------------------------------

typedef class _SteamNetworkingMessages_ : public _ISteamNetworkingMessages_ {
public:

	_SteamNetworkingMessages_() = default;
	_SteamNetworkingMessages_(const _SteamNetworkingMessages_&) = delete;
	_SteamNetworkingMessages_& operator=(const _SteamNetworkingMessages_&) = delete;

	/*Returns:
	  k_EREsultOK on success.
	  k_EResultNoConnection */
	EResult SendMessageToUser(const pSteamNetworkingIdentity pIdentityRemote, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, Int32 nRemoteChannel) override;

	Int32 ReceiveMessagesOnChannel(Int32 nLocalChannel, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) override;
	Bool AcceptSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) override;

	Bool CloseSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) override;
	Bool CloseChannelWithUser(const pSteamNetworkingIdentity pIdentityRemote, Int32 nLocalChannel) override;

	ESteamNetworkingConnectionState GetSessionConnectionInfo(const pSteamNetworkingIdentity pIdentityRemote, pSteamNetConnectionInfo_t pConnectionInfo, pSteamNetConnectionRealTimeStatus_t pQuickStatus) override;

	~_SteamNetworkingMessages_() = default;

} SteamNetworkingMessages, *pSteamNetworkingMessages;

#endif // !_STEAMNETWORKINGMESSAGES_
