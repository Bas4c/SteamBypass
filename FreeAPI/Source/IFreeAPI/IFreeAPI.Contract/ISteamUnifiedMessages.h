#ifndef _ISTEAMUNIFIEDMESSAGES_
#define _ISTEAMUNIFIEDMESSAGES_

#include "..\..\FreeAPI.Typedef.h"

typedef Uint64 ClientUnifiedMessageHandle, *pClientUnifiedMessageHandle;
#define k_UnifiedMessageHandle_Invalid ((ClientUnifiedMessageHandle)(0x0000000000000000))

// -----------------------------------------------------------------------------
// Purpose: Unified Message API
// -----------------------------------------------------------------------------
typedef class _ISteamUnifiedMessages_ {
public:

	/* Sends a service method (in binary serialized form) using the Steam Client.
	// Returns a unified message handle (k_InvalidUnifiedMessageHandle if could not send the message). */
	virtual ClientUnifiedMessageHandle SendMethod(const pStrA pchServiceMethod, const pVoid pvRequestData, Uint32 nRequestDataSize, Uint64 nContext) = 0;

	/* Gets the size of the response and the EResult.
	   Returns False if the response is not ready yet. */
	virtual Bool GetMethodResponseInfo(ClientUnifiedMessageHandle hHandle, pUint32 pnResponseSize, pEResult peResult) = 0;

	/* Gets a response in binary serialized form (and optionally release the corresponding allocated memory). */
	virtual Bool GetMethodResponseData(ClientUnifiedMessageHandle hHandle, /* [out] */ pVoid pvResponseData, Uint32 nResponseDataSize, Bool bAutoRelease) = 0;
	virtual Bool ReleaseMethod(ClientUnifiedMessageHandle hHandle) = 0;

	/* Sends a service notification (in binary serialized form) using the Steam Client.
	   Returns true if the notification was sent successfully. */
	virtual Bool SendNotification(const pStrA pchServiceNotification, const pVoid pvDataNotificationData, Uint32 nNotificationDataSize) = 0;
	
} ISteamUnifiedMessages, *IpSteamUnifiedMessages;

#define STEAMUNIFIEDMESSAGES_INTERFACE_VERSION "STEAMUNIFIEDMESSAGES_INTERFACE_VERSION001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_SteamUnifiedMessagesSendMethodResult_t ((Int32)(k_iClientUnifiedMessagesCallbacks + 1))
typedef struct _SteamUnifiedMessagesSendMethodResult_t_ {

	ClientUnifiedMessageHandle hHandle;
	Uint64 nContext;
	EResult eResult;
	Uint32 nResponseSize;

} SteamUnifiedMessagesSendMethodResult_t, *pSteamUnifiedMessagesSendMethodResult_t;

#pragma pack(pop)

#endif // _ISTEAMUNIFIEDMESSAGES_
