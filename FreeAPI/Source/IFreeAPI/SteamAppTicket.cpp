// -----------------------------------------------------------------------------
#include "SteamAppTicket.h"
// -----------------------------------------------------------------------------

Uint32 _SteamAppTicket_::GetAppOwnershipTicketData(
	AppId_t iAppId, pVoid pvTicket, Uint32 cbTicket,
	pUint32 piAppId, pUint32 piSteamId,
	pUint32 piSignature, pUint32 pcbSignature
) {
	DEBUGBREAK("ISteamAppTicket::GetAppOwnershipTicketData");

	/* (Fake-Ticket) Signature */
	pCStrA pchSignature = (pCStrA)("++++");
	SizeOF cchSignature = StrA_Count(pchSignature);

	Uint32 cbTicketSize = (Uint32)(sizeof(AppId_t) + sizeof(SteamId_t) +
		cchSignature + 1U);

	if (pvTicket != NULL && cbTicket >= cbTicketSize) {

		*((pAppId_t)(((pByte)(pvTicket)))) =
			iAppId;
		
		*((pSteamId_t)(((pByte)(pvTicket)) + sizeof(AppId_t))) =
			SteamId_t{ k_SteamId_t_LocalUser };

		StrA_Copy(
			(pStrA)(((pByte)(pvTicket)) + sizeof(AppId_t) + sizeof(SteamId_t)),
			cbTicket - sizeof(AppId_t) + sizeof(SteamId_t),
			pchSignature
		);
		
		/* AppId position inside (Fake-Ticket) */
		if (piAppId != NULL) {
			*piAppId = 0U;
		}

		/* SteamId position inside (Fake-Ticket) */
		if (piSteamId != NULL) {
			*piSteamId = sizeof(AppId_t);
		}

		/* Signature position inside (Fake-Ticket) */
		if (piSignature != NULL) {
			*piSignature = sizeof(AppId_t) + sizeof(SteamId_t);
		}

		/* Signature size inside (Fake-Ticket) */
		if (pcbSignature != NULL) {
			*pcbSignature = (Uint32)(cchSignature + 1U);
		}

		return cbTicketSize;

	}

	return 0U;

}
