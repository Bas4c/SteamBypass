// -----------------------------------------------------------------------------
#include "SteamAppTicket.h"
// -----------------------------------------------------------------------------

Uint32 _SteamAppTicket_::GetAppOwnershipTicketData(
	AppId_t iAppId, pVoid pvTicket, Uint32 cbTicket,
	pUint32 piAppId, pUint32 piSteamId,
	pUint32 piSignature, pUint32 pcbSignature
) {
	
	/* (Fake-Ticket) Signature */
	const pStrA pchSignature = (const pStrA)("++++");
	SizeOF cchSignature = StrA_Count(pchSignature);

	Uint32 cbTicketSize = sizeof(AppId_t) + sizeof(SteamId_t) +
		cchSignature + 1U;

	if (pvTicket != NULL && cbTicket >= cbTicketSize) {

		*((pAppId_t)(((pByte)(pvTicket)))) =
			iAppId;
		
		*((pSteamId_t)(((pByte)(pvTicket)) + sizeof(AppId_t))) = k_SteamId_t_Create(
			k_EUniversePublic, k_EAccountTypeIndividual,
			0xFFFFF, 0xFFFFFFFF
		);

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
			*pcbSignature = cchSignature + 1U;
		}

		return cbTicketSize;

	}

	return 0U;

}
