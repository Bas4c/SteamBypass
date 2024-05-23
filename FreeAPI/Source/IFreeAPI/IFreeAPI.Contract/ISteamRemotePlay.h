#ifndef _ISTEAMREMOTEPLAY_
#define _ISTEAMREMOTEPLAY_

#include "..\..\FreeAPI.Typedef.h"

typedef enum _ESteamDeviceFormFactor_ {

	k_ESteamDeviceFormFactorUnknown,
	k_ESteamDeviceFormFactorPhone,
	k_ESteamDeviceFormFactorTablet,
	k_ESteamDeviceFormFactorComputer,
	k_ESteamDeviceFormFactorTV

} ESteamDeviceFormFactor, *pESteamDeviceFormFactor;

typedef Uint32 RemotePlaySessionId_t, *pRemotePlaySessionId_t;

// -----------------------------------------------------------------------------
// Purpose: Functions to provide information about Steam Remote Play sessions
// -----------------------------------------------------------------------------
typedef class _ISteamRemotePlay_ {
public:

	virtual Uint32 GetSessionCount() = 0;
	virtual RemotePlaySessionId_t GetSessionID(Int32 iSessionIndex) = 0;
	virtual SteamId_t GetSessionSteamID(RemotePlaySessionId_t SessionId) = 0;
	virtual pCStrA GetSessionClientName(RemotePlaySessionId_t SessionId) = 0;
	virtual ESteamDeviceFormFactor GetSessionClientFormFactor(RemotePlaySessionId_t SessionId) = 0;
	virtual Bool BGetSessionClientResolution(RemotePlaySessionId_t SessionId, /* [out] */ pInt32 pCx, /* [out] */ pInt32 pCy) = 0;
	virtual Bool BSendRemotePlayTogetherInvite(SteamId_t SteamIdFriend) = 0;

} ISteamRemotePlay, *IpSteamRemotePlay;

#define STEAMREMOTEPLAY_INTERFACE_VERSION "STEAMREMOTEPLAY_INTERFACE_VERSION001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_SteamRemotePlaySessionConnected_t ((Int32)(k_iSteamRemotePlayCallbacks + 1))
typedef struct _SteamRemotePlaySessionConnected_t_ {
	
	RemotePlaySessionId_t SessionId;

} SteamRemotePlaySessionConnected_t, *pSteamRemotePlaySessionConnected_t;

#define k_iCallbback_SteamRemotePlaySessionDisconnected_t ((Int32)(k_iSteamRemotePlayCallbacks + 2))
typedef struct _SteamRemotePlaySessionDisconnected_t_ {
	
	RemotePlaySessionId_t SessionId;

} SteamRemotePlaySessionDisconnected_t, *pSteamRemotePlaySessionDisconnected_t;

#define k_iCallbback_SteamRemotePlayTogetherGuestInvite_t ((Int32)(k_iSteamRemotePlayCallbacks + 3))
typedef struct _SteamRemotePlayTogetherGuestInvite_t_ {
	
	CharA chConnectURL[1024];

} SteamRemotePlayTogetherGuestInvite_t, *pSteamRemotePlayTogetherGuestInvite_t;

#pragma pack(pop)

#endif // _ISTEAMREMOTEPLAY_
