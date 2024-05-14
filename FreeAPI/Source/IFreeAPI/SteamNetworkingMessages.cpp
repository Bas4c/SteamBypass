// -----------------------------------------------------------------------------
#include "SteamNetworkingMessages.h"
// -----------------------------------------------------------------------------

EResult _SteamNetworkingMessages_::SendMessageToUser(const pSteamNetworkingIdentity pIdentityRemote, const pVoid pvData, Uint32 cbData, Int32 nSendFlags, Int32 nRemoteChannel) {

	return k_EResultNoConnection;

}

Int32 _SteamNetworkingMessages_::ReceiveMessagesOnChannel(Int32 nLocalChannel, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {

	return 0;

}

Bool _SteamNetworkingMessages_::AcceptSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) {

	return False;

}

Bool _SteamNetworkingMessages_::CloseSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) {

	return False;

}

Bool _SteamNetworkingMessages_::CloseChannelWithUser(const pSteamNetworkingIdentity pIdentityRemote, Int32 nLocalChannel) {

	return False;

}

ESteamNetworkingConnectionState _SteamNetworkingMessages_::GetSessionConnectionInfo(const pSteamNetworkingIdentity pIdentityRemote, pSteamNetConnectionInfo_t pConnectionInfo, pSteamNetConnectionRealTimeStatus_t pQuickStatus) {

	return k_ESteamNetworkingConnectionState_None;

}
