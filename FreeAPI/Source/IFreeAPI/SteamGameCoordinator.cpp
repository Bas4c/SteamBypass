// -----------------------------------------------------------------------------
#include "SteamGameCoordinator.h"
// -----------------------------------------------------------------------------

EGCResults _SteamGameCoordinator_::SendMessage_(Uint32 nMsgType, pCVoid pvData, Uint32 cbData) {
	DEBUGBREAK("ISteamGameCoordinator::SendMessage_");

	return k_EGCResultOK;

}

Bool _SteamGameCoordinator_::IsMessageAvailable(pUint32 pcbMsgSize) {
	DEBUGBREAK("ISteamGameCoordinator::IsMessageAvailable");

	return False;

}

EGCResults _SteamGameCoordinator_::RetrieveMessage(pUint32 pnMsgType, pVoid pvDest, Uint32 cbDest, pUint32 pcbMsgSize) {
	DEBUGBREAK("ISteamGameCoordinator::RetrieveMessage");

	return k_EGCResultNoMessage;

}
