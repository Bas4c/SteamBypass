// -----------------------------------------------------------------------------
#include "SteamRemotePlay.h"
// -----------------------------------------------------------------------------

Uint32 _SteamRemotePlay_::GetSessionCount() {

	return 0U;

}

RemotePlaySessionId_t _SteamRemotePlay_::GetSessionID(Int32 iSessionIndex) {

	return (RemotePlaySessionId_t)(0x000000000);

}

SteamId_t _SteamRemotePlay_::GetSessionSteamID(RemotePlaySessionId_t SessionId) {

	return k_SteamId_t_Invalid;

}

pCStrA _SteamRemotePlay_::GetSessionClientName(RemotePlaySessionId_t SessionId) {

	return (pCStrA)(
		""
	);

}

ESteamDeviceFormFactor _SteamRemotePlay_::GetSessionClientFormFactor(RemotePlaySessionId_t SessionId) {

	return k_ESteamDeviceFormFactorComputer;

}

Bool _SteamRemotePlay_::BGetSessionClientResolution(RemotePlaySessionId_t SessionId, pInt32 pCx, pInt32 pCy) {

	if (pCx != NULL) {
		*pCx = GetSystemMetrics(SM_CXSCREEN);
	}

	if (pCy != NULL) {
		*pCy = GetSystemMetrics(SM_CYSCREEN);
	}

	return True;

}

Bool _SteamRemotePlay_::BSendRemotePlayTogetherInvite(SteamId_t SteamIdFriend) {

	return False;

}
