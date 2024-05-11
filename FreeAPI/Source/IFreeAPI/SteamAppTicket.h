#ifndef _STEAMAPPTICKET_
#define _STEAMAPPTICKET_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamAppTicket.h"
// -----------------------------------------------------------------------------

typedef class _SteamAppTicket_ : public _ISteamAppTicket_ {
public:

	_SteamAppTicket_() = default;
	_SteamAppTicket_(const _SteamAppTicket_&) = delete;
	_SteamAppTicket_& operator=(const _SteamAppTicket_&) = delete;

	Uint32 GetAppOwnershipTicketData(
		AppId_t iAppId, pVoid pvTicket, Uint32 cbTicket,
		pUint32 piAppId, pUint32 piSteamId,
		pUint32 piSignature, pUint32 pcbSignature
	) override;

	~_SteamAppTicket_() = default;

} SteamAppTicket, *pSteamAppTicket;

#endif // !_STEAMAPPTICKET_
