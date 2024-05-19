#ifndef _STEAMUNIFIEDMESSAGES_
#define _STEAMUNIFIEDMESSAGES_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamUnifiedMessages.h"
// -----------------------------------------------------------------------------

typedef class _SteamUnifiedMessages_ : public _ISteamUnifiedMessages_ {
public:

	_SteamUnifiedMessages_() = default;
	_SteamUnifiedMessages_(const _SteamUnifiedMessages_&) = delete;
	_SteamUnifiedMessages_& operator=(const _SteamUnifiedMessages_&) = delete;

	/* Sends a service method (in binary serialized form) using the Steam Client.
	   Returns a unified message handle (k_InvalidUnifiedMessageHandle if could not send the message). */
	ClientUnifiedMessageHandle SendMethod(const pStrA pchServiceMethod, const pVoid pvRequestData, Uint32 nRequestDataSize, Uint64 nContext) override;

	/* Gets the size of the response and the EResult.
	   Returns False if the response is not ready yet. */
	Bool GetMethodResponseInfo(ClientUnifiedMessageHandle hHandle, pUint32 pnResponseSize, pEResult peResult) override;

	/* Gets a response in binary serialized form (and optionally release the corresponding allocated memory). */
	Bool GetMethodResponseData(ClientUnifiedMessageHandle hHandle, pVoid pvResponseData, Uint32 nResponseDataSize, Bool bAutoRelease) override;
	Bool ReleaseMethod(ClientUnifiedMessageHandle hHandle) override;

	/* Sends a service notification (in binary serialized form) using the Steam Client.
	   Returns true if the notification was sent successfully. */
	Bool SendNotification(const pStrA pchServiceNotification, const pVoid pvDataNotificationData, Uint32 nNotificationDataSize) override;

	~_SteamUnifiedMessages_() = default;

} SteamUnifiedMessages, *pSteamUnifiedMessages;

#endif // !_STEAMUNIFIEDMESSAGES_
