// -----------------------------------------------------------------------------
#include "SteamUnifiedMessages.h"
// -----------------------------------------------------------------------------

ClientUnifiedMessageHandle _SteamUnifiedMessages_::SendMethod(pCStrA pchServiceMethod, pCVoid pvRequestData, Uint32 nRequestDataSize, Uint64 nContext) {
	DEBUGBREAK("ISteamUnifiedMessages::SendMethod");
	
	return k_UnifiedMessageHandle_Invalid;

}

Bool _SteamUnifiedMessages_::GetMethodResponseInfo(ClientUnifiedMessageHandle hHandle, pUint32 pnResponseSize, pEResult peResult) {
	DEBUGBREAK("ISteamUnifiedMessages::GetMethodResponseInfo");
	
	if (pnResponseSize != NULL) {
		*pnResponseSize = 0U;
	}

	if (peResult != NULL) {
		*peResult = k_EResultNoConnection;
	}

	return False;
}

Bool _SteamUnifiedMessages_::GetMethodResponseData(ClientUnifiedMessageHandle hHandle, pVoid pvResponseData, Uint32 nResponseDataSize, Bool bAutoRelease) {
	DEBUGBREAK("ISteamUnifiedMessages::GetMethodResponseData");
	
	return False;

}

Bool _SteamUnifiedMessages_::ReleaseMethod(ClientUnifiedMessageHandle hHandle) {
	DEBUGBREAK("ISteamUnifiedMessages::ReleaseMethod");

	return False;

}

Bool _SteamUnifiedMessages_::SendNotification(pCStrA pchServiceNotification, pCVoid pvDataNotificationData, Uint32 nNotificationDataSize) {
	DEBUGBREAK("ISteamUnifiedMessages::SendNotification");

	return False;

}
