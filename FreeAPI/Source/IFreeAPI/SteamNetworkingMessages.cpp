// -----------------------------------------------------------------------------
#include "SteamNetworkingMessages.h"
// -----------------------------------------------------------------------------

EResult _SteamNetworkingMessages_::SendMessageToUser(const pSteamNetworkingIdentity pIdentityRemote, pCVoid pvData, Uint32 cbData, Int32 nSendFlags, Int32 nRemoteChannel) {
	DEBUGBREAK("ISteamNetworkingMessages::SendMessageToUser");

	return k_EResultNoConnection;

}

Int32 _SteamNetworkingMessages_::ReceiveMessagesOnChannel(Int32 nLocalChannel, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {
	DEBUGBREAK("ISteamNetworkingMessages::ReceiveMessagesOnChannel");

	return 0;

}

Bool _SteamNetworkingMessages_::AcceptSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) {
	DEBUGBREAK("ISteamNetworkingMessages::AcceptSessionWithUser");

	return False;

}

Bool _SteamNetworkingMessages_::CloseSessionWithUser(const pSteamNetworkingIdentity pIdentityRemote) {
	DEBUGBREAK("ISteamNetworkingMessages::CloseSessionWithUser");

	return False;

}

Bool _SteamNetworkingMessages_::CloseChannelWithUser(const pSteamNetworkingIdentity pIdentityRemote, Int32 nLocalChannel) {
	DEBUGBREAK("ISteamNetworkingMessages::CloseChannelWithUser");

	return False;

}

ESteamNetworkingConnectionState _SteamNetworkingMessages_::GetSessionConnectionInfo(const pSteamNetworkingIdentity pIdentityRemote, pSteamNetConnectionInfo_t pConnectionInfo, pSteamNetConnectionRealTimeStatus_t pQuickStatus) {
	DEBUGBREAK("ISteamNetworkingMessages::GetSessionConnectionInfo");

	return k_ESteamNetworkingConnectionState_None;

}
