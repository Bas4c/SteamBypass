#ifndef _ISTEAMGAMECOORDINATOR_
#define _ISTEAMGAMECOORDINATOR_

#include "..\..\FreeAPI.Typedef.h"

typedef enum _EGCResults_ {

	k_EGCResultOK,
	k_EGCResultNoMessage,
	k_EGCResultBufferTooSmall,
	k_EGCResultNotLoggedOn,
	k_EGCResultInvalidMessage

} EGCResults, *pEGCResults;

// -----------------------------------------------------------------------------
// Purpose: Functions for sending and receiving messages from the Game Coordinator
//  for this application
// -----------------------------------------------------------------------------
typedef class _ISteamGameCoordinator_ {
public:

	virtual EGCResults SendMessage_(Uint32 nMsgType, pCVoid pvData, Uint32 cbData) = 0;
	virtual Bool IsMessageAvailable(/* [out] */ pUint32 pcbMsgSize) = 0;
	virtual EGCResults RetrieveMessage(/* [out] */ pUint32 pnMsgType, /* [out] */ pVoid pvDest, Uint32 cbDest, /* [out] */ pUint32 pcbMsgSize) = 0;

} ISteamGameCoordinator, *IpSteamGameCoordinator;

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION "SteamGameCoordinator001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_GCMessageAvailable_t_ ((Int32)(k_iSteamGameCoordinatorCallbacks + 1))
typedef struct _GCMessageAvailable_t_ {

	Uint32 nMessageSize;

} GCMessageAvailable_t, *pGCMessageAvailable_t;

#define k_iCallbback_GCMessageFailed_t_ ((Int32)(k_iSteamGameCoordinatorCallbacks + 2))
typedef struct _GCMessageFailed_t_ {

	Int32 Unused;

} GCMessageFailed_t, *pGCMessageFailed_t;

#pragma pack(pop)

#endif // _ISTEAMGAMECOORDINATOR_
