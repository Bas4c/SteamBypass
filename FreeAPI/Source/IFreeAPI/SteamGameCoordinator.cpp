// -----------------------------------------------------------------------------
#include "SteamGameCoordinator.h"
// -----------------------------------------------------------------------------

EGCResults _SteamGameCoordinator_::SendMessage_(Uint32 nMsgType, pVoid pvData, Uint32 cbData) {
	DEBUGBREAK("ISteamGameCoordinator::SendMessage_");

	if (pvData != NULL && cbData != 0) {
		return k_EGCResultOK;
	}

	return k_EGCResultInvalidMessage;

}

Bool _SteamGameCoordinator_::IsMessageAvailable(pUint32 pcbMsgSize) {
	DEBUGBREAK("ISteamGameCoordinator::IsMessageAvailable");

	if (pcbMsgSize != NULL) {
		*pcbMsgSize = 0x00000000;
	}

	return False;

}

EGCResults _SteamGameCoordinator_::RetrieveMessage(pUint32 pnMsgType, pVoid pvDest, Uint32 cbDest, pUint32 pcbMsgSize) {
	DEBUGBREAK("ISteamGameCoordinator::RetrieveMessage");

	if (pvDest != NULL && cbDest != 0) {

		for (Uint32 i = 0; i < cbDest; i++) {
			((pByte)(pvDest))[i] = 0x00;
		}

		if (pnMsgType != NULL) {
			*pnMsgType = 0U;
		}

		if (pcbMsgSize != NULL) {
			*pcbMsgSize = cbDest;
		}

		return k_EGCResultOK;

	}

	return k_EGCResultBufferTooSmall;

}
