#ifndef _STEAMGAMECOORDINATOR_
#define _STEAMGAMECOORDINATOR_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamGameCoordinator.h"
// -----------------------------------------------------------------------------

typedef class _SteamGameCoordinator_ : public _ISteamGameCoordinator_ {
public:

	_SteamGameCoordinator_() = default;
	_SteamGameCoordinator_(const _SteamGameCoordinator_&) = delete;
	_SteamGameCoordinator_& operator=(const _SteamGameCoordinator_&) = delete;

	EGCResults SendMessage_(Uint32 nMsgType, pCVoid pvData, Uint32 cbData) override;
	Bool IsMessageAvailable(pUint32 pcbMsgSize) override;
	EGCResults RetrieveMessage(pUint32 pnMsgType, pVoid pvDest, Uint32 cbDest, pUint32 pcbMsgSize) override;

	~_SteamGameCoordinator_() = default;

} SteamGameCoordinator, *pSteamGameCoordinator;

#endif // !_STEAMGAMECOORDINATOR_
