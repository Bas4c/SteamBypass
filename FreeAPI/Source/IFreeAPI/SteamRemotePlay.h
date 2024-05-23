#ifndef _STEAMREMOTEPLAY_
#define _STEAMREMOTEPLAY_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamRemotePlay.h"
// -----------------------------------------------------------------------------

typedef class _SteamRemotePlay_ : public _ISteamRemotePlay_ {
public:

	_SteamRemotePlay_() = default;
	_SteamRemotePlay_(const _SteamRemotePlay_&) = delete;
	_SteamRemotePlay_& operator=(const _SteamRemotePlay_&) = delete;

	Uint32 GetSessionCount() override;
	RemotePlaySessionId_t GetSessionID(Int32 iSessionIndex) override;
	SteamId_t GetSessionSteamID(RemotePlaySessionId_t SessionId) override;
	pCStrA GetSessionClientName(RemotePlaySessionId_t SessionId) override;
	ESteamDeviceFormFactor GetSessionClientFormFactor(RemotePlaySessionId_t SessionId) override;
	Bool BGetSessionClientResolution(RemotePlaySessionId_t SessionId, pInt32 pCx, pInt32 pCy) override;
	Bool BSendRemotePlayTogetherInvite(SteamId_t SteamIdFriend) override;

	~_SteamRemotePlay_() = default;

} SteamRemotePlay, *pSteamRemotePlay;

#endif // !_STEAMREMOTEPLAY_
