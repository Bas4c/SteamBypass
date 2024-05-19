// -----------------------------------------------------------------------------
#include "SteamUnifiedMessages.h"
// -----------------------------------------------------------------------------

ClientUnifiedMessageHandle _SteamUnifiedMessages_::SendMethod(const pStrA pchServiceMethod, const pVoid pvRequestData, Uint32 nRequestDataSize, Uint64 nContext) {
	
	return k_UnifiedMessageHandle_Invalid;

}

Bool _SteamUnifiedMessages_::GetMethodResponseInfo(ClientUnifiedMessageHandle hHandle, pUint32 pnResponseSize, pEResult peResult) {
	
	if (pnResponseSize != NULL) {
		*pnResponseSize = 0U;
	}

	if (peResult != NULL) {
		*peResult = k_EResultNoConnection;
	}

	return False;
}

Bool _SteamUnifiedMessages_::GetMethodResponseData(ClientUnifiedMessageHandle hHandle, pVoid pvResponseData, Uint32 nResponseDataSize, Bool bAutoRelease) {
	
	return False;

}

Bool _SteamUnifiedMessages_::ReleaseMethod(ClientUnifiedMessageHandle hHandle) {

	return False;

}

Bool _SteamUnifiedMessages_::SendNotification(const pStrA pchServiceNotification, const pVoid pvDataNotificationData, Uint32 nNotificationDataSize) {

	return False;

}
