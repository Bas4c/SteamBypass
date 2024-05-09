#ifndef _ISTEAMAPPTICKET_
#define _ISTEAMAPPTICKET_

#include "..\..\FreeAPI.Typedef.h"

// -----------------------------------------------------------------------------
// Purpose: Hand out a reasonable "Future Proof" view of an app ownership ticket
//  the raw (signed) buffer, and indices into that buffer where the AppId and 
//  SteamId are located. The sizes of the AppId and SteamId are implicit in 
//  (each version of) the interface - currently Uint32 AppId and Uint64 SteamId
// -----------------------------------------------------------------------------
typedef class _ISteamAppTicket_ {
public:

	virtual Uint32 GetAppOwnershipTicketData(
		AppId_t iAppId, /* [out] */ pVoid pvData, Uint32 cbDataSize,
		/* [out] */ pAppId_t piAppId, /* [out] */ pSteamId_t piSteamId,
		/* [out] */ pUint32 piSignature, Uint32 pcbSignature
	) = 0;

} ISteamAppTicket, *IpSteamAppTicket;

#define STEAMAPPTICKET_INTERFACE_VERSION "STEAMAPPTICKET_INTERFACE_VERSION001"

#endif // _ISTEAMAPPTICKET_
