#ifndef _FREE_API_TYPEDEF_
#define _FREE_API_TYPEDEF_

// ----
// Standard Typedef
// ----

#include "Typedef.h"

// #define _SERVER
// #define _PS3

#ifndef _S_CALL_
	#define _S_CALL_ __cdecl
#endif

// ----
// Current Game AppId
// ----

typedef Uint32 AppId_t, *pAppId_t;
#define k_AppId_t_Invalid ((AppId_t)(0x00000000))

// ----
// Current Game SessionId and Current User AccountId
// ----

typedef Uint64 GameId_t_Uint64, *pGameId_t_Uint64;

typedef struct _GameId_t_ {
	GameId_t_Uint64 GameId_Uint64;
} GameId_t, *pGameId_t;

typedef Uint32 AccountId_t, *pAccountId_t;

// ----
// AppId's and DepotId's also presently share the same namespace
// ----

typedef Uint32 DepotId_t, *pDepotId_t;
#define k_DepotId_t_Invalid ((DepotId_t)(0x00000000))

// ----
// Steam Universe
// ----

typedef enum _EUniverse_ {

	k_EUniverseInvalid,
	k_EUniversePublic,
	k_EUniverseBeta,
	k_EUniverseInternal,
	k_EUniverseDev,
	k_EUniverseRC,
	k_EUniverseMax

} EUniverse, *pEUniverse;

// ----
// Steam User Account Type
// ----

typedef enum _EAccountType_ {

	k_EAccountTypeInvalid,
	k_EAccountTypeIndividual,
	k_EAccountTypeMultiseat,
	k_EAccountTypeGameServer,
	k_EAccountTypeAnonGameServer,
	k_EAccountTypePending,
	k_EAccountTypeContentServer,
	k_EAccountTypeClan,
	k_EAccountTypeChat,
	k_EAccountTypeConsoleUser,
	k_EAccountTypeAnonUser,
	k_EAccountTypeMax

} EAccountType, *pEAccountType;

// -----------------------------------------------------------------------------
// XX00000000000000: EUniverse
// 00X0000000000000: EAccountType
// 000XXXXX00000000: ObjectId
// 00000000XXXXXXXX: Instance
// -----------------------------------------------------------------------------
typedef Uint64 SteamId_t_Uint64, *pSteamId_t_Uint64;

typedef struct _SteamId_t_ {
	SteamId_t_Uint64 SteamId_Uint64;
} SteamId_t, *pSteamId_t;

#define k_SteamId_t_Create(eUniverse, eAccountType, ObjectId, Instance) ( \
 ((((SteamId_t_Uint64)((EUniverse)(eUniverse))) << 56) & 0xFF00000000000000) | \
 ((((SteamId_t_Uint64)((EAccountType)(eAccountType))) << 52) & 0x00F0000000000000) | \
 ((((SteamId_t_Uint64)(ObjectId)) << 32) & 0x000FFFFF00000000) | \
 ((((SteamId_t_Uint64)(Instance)) & 0x00000000FFFFFFFF)) \
)

#define k_SteamId_t_Invalid k_SteamId_t_Create( \
 k_EUniverseInvalid, k_EAccountTypeInvalid, \
 0x00000, 0x00000000 \
)

#define k_SteamId_t_LocalUser k_SteamId_t_Create( \
 k_EUniversePublic, k_EAccountTypeIndividual, \
 0x00001, 0x00000001 \
)

// ----
// Seconds elapsed since Jan 1 1970
// ----

typedef Uint32 RTime32, *pRTime32;

// ----
// SteamAPI Call: Handle
// ----

typedef Uint64 SteamAPICall_t, *pSteamAPICall_t;
#define k_SteamAPICall_Invalid ((SteamAPICall_t)(0x0000000000000000))

// ----
// Party BeaconId
// ----

typedef Uint64 PartyBeaconId_t, *pPartyBeaconId_t;
#define k_PartyBeaconId_Invalid ((PartyBeaconId_t)(0x00000000))

// ----
// User Generated Content Handles
// ----

typedef Uint64 UGCHandle_t, *pUGCHandle_t;
#define k_UGCHandle_Invalid ((UGCHandle_t)(0xFFFFFFFFFFFFFFFF))
typedef Uint64 PublishedFileUpdateHandle_t, *pPublishedFileUpdateHandle_t;
#define k_PublishedFileUpdateHandle_Invalid ((PublishedFileUpdateHandle_t)(0xFFFFFFFFFFFFFFFF))
typedef Uint64 PublishedFileId_t, *pPublishedFileId_t;
#define k_PublishedFileId_Invalid ((PublishedFileId_t)(0x0000000000000000))

// -----------------------------------------------------------------------------
// IPv4 -> HostOrder: Uint32 || IPv6 -> NetworkOrder: Uint8[16]
// -----------------------------------------------------------------------------

typedef enum _ESteamIPType_ {

	k_ESteamIPTypeIPv4,
	k_ESteamIPTypeIPv6

} ESteamIPType, *pESteamIPType;

#pragma pack(push, 1)

typedef struct _SteamIPAddress_t_ {

	union {
		Uint32 IPv4; // HostOrder
		Uint8 IPv6[16]; // NetworkOrder
	};

	ESteamIPType eSteamIPType;

} SteamIPAddress_t, *pSteamIPAddress_t;

#pragma pack(pop)

// ----
// HSteamPipe and HSteamUser
// ----

typedef Int32 HSteamPipe, *pHSteamPipe;
#define k_HSteamPipe_Invalid ((HSteamPipe)(0x00000000))
#define k_HSteamPipe_Client  ((HSteamPipe)(0x00000001))
#define k_HSteamPipe_Server  ((HSteamPipe)(0x00000002))

typedef Int32 HSteamUser, *pHSteamUser;
#define k_HSteamUser_LocalUser ((HSteamUser)(0x7FFFFFFF))

// ----
// General Status Codes
// ----

typedef enum _EResult_ {

	k_EResultNone,
	k_EResultOK,
	k_EResultFail,
	k_EResultNoConnection,
	k_EResultNoConnectionRetry,
	k_EResultInvalidPassword,
	k_EResultLoggedInElsewhere,
	k_EResultInvalidProtocolVer,
	k_EResultInvalidParam,
	k_EResultFileNotFound,
	k_EResultBusy,
	k_EResultInvalidState,
	k_EResultInvalidName,
	k_EResultInvalidEmail,
	k_EResultDuplicateName,
	k_EResultAccessDenied,
	k_EResultTimeout,
	k_EResultBanned,
	k_EResultAccountNotFound,
	k_EResultInvalidSteamID,
	k_EResultServiceUnavailable,
	k_EResultNotLoggedOn,
	k_EResultPending,
	k_EResultEncryptionFailure,
	k_EResultInsufficientPrivilege,
	k_EResultLimitExceeded,
	k_EResultRevoked,
	k_EResultExpired,
	k_EResultAlreadyRedeemed,
	k_EResultDuplicateRequest,
	k_EResultAlreadyOwned,
	k_EResultIPNotFound,
	k_EResultPersistFailed,
	k_EResultLockingFailed,
	k_EResultLogonSessionReplaced,
	k_EResultConnectFailed,
	k_EResultHandshakeFailed,
	k_EResultIOFailure,
	k_EResultRemoteDisconnect,
	k_EResultShoppingCartNotFound,
	k_EResultBlocked,
	k_EResultIgnored,
	k_EResultNoMatch,
	k_EResultAccountDisabled,
	k_EResultServiceReadOnly,
	k_EResultAccountNotFeatured,
	k_EResultAdministratorOK,
	k_EResultContentVersion,
	k_EResultTryAnotherCM,
	k_EResultPasswordRequiredToKickSession,
	k_EResultAlreadyLoggedInElsewhere,
	k_EResultSuspended,
	k_EResultCancelled,
	k_EResultDataCorruption,
	k_EResultDiskFull,
	k_EResultRemoteCallFailed,
	k_EResultPasswordUnset,
	k_EResultExternalAccountUnlinked,
	k_EResultPSNTicketInvalid,
	k_EResultExternalAccountAlreadyLinked,
	k_EResultRemoteFileConflict,
	k_EResultIllegalPassword,
	k_EResultSameAsPreviousValue,
	k_EResultAccountLogonDenied,
	k_EResultCannotUseOldPassword,
	k_EResultInvalidLoginAuthCode,
	k_EResultAccountLogonDeniedNoMail,
	k_EResultHardwareNotCapableOfIPT,
	k_EResultIPTInitError,
	k_EResultParentalControlRestricted,
	k_EResultFacebookQueryError,
	k_EResultExpiredLoginAuthCode,
	k_EResultIPLoginRestrictionFailed,
	k_EResultAccountLockedDown,
	k_EResultAccountLogonDeniedVerifiedEmailRequired,
	k_EResultNoMatchingURL,
	k_EResultBadResponse,
	k_EResultRequirePasswordReEntry,
	k_EResultValueOutOfRange,
	k_EResultUnexpectedError,
	k_EResultDisabled,
	k_EResultInvalidCEGSubmission,
	k_EResultRestrictedDevice,
	k_EResultRegionLocked,
	k_EResultRateLimitExceeded,
	k_EResultAccountLoginDeniedNeedTwoFactor,
	k_EResultItemDeleted,
	k_EResultAccountLoginDeniedThrottle,
	k_EResultTwoFactorCodeMismatch,
	k_EResultTwoFactorActivationCodeMismatch,
	k_EResultAccountAssociatedToMultiplePartners,
	k_EResultNotModified,
	k_EResultNoMobileDevice,
	k_EResultTimeNotSynced,
	k_EResultSmsCodeFailed,
	k_EResultAccountLimitExceeded,
	k_EResultAccountActivityLimitExceeded,
	k_EResultPhoneActivityLimitExceeded,
	k_EResultRefundToWallet,
	k_EResultEmailSendFailure,
	k_EResultNotSettled,
	k_EResultNeedCaptcha,
	k_EResultGSLTDenied,
	k_EResultGSOwnerDenied,
	k_EResultInvalidItemType,
	k_EResultIPBanned,
	k_EResultGSLTExpired,
	k_EResultInsufficientFunds,
	k_EResultTooManyPending,
	k_EResultNoSiteLicensesFound,
	k_EResultWGNetworkSendExceeded,
	k_EResultAccountNotFriends,
	k_EResultLimitedUserAccount,
	k_EResultCantRemoveItem,
	k_EResultAccountDeleted,
	k_EResultExistingUserCancelledLicense,
	k_EResultCommunityCooldown,
	k_EResultNoLauncherSpecified,
	k_EResultMustAgreeToSSA,
	k_EResultLauncherMigrated,
	k_EResultSteamRealmMismatch,
	k_EResultInvalidSignature,
	k_EResultParseFailure,
	k_EResultNoVerifiedPhone,
	k_EResultInsufficientBattery,
	k_EResultChargerRequired,
	k_EResultCachedCredentialInvalid,
	K_EResultPhoneNumberIsVOIP

} EResult, *pEResult;

// ----
// Voice Result Error Codes
// ----

typedef enum _EVoiceResult_ {

	k_EVoiceResultOK,
	k_EVoiceResultNotInitialized,
	k_EVoiceResultNotRecording,
	k_EVoiceResultNoData,
	k_EVoiceResultBufferTooSmall,
	k_EVoiceResultDataCorrupted,
	k_EVoiceResultRestricted,
	k_EVoiceResultUnsupportedCodec,
	k_EVoiceResultReceiverOutOfDate,
	k_EVoiceResultReceiverDidNotAnswer

} EVoiceResult, *pEVoiceResult;

// ----
// Chat Entry Types
// ----

typedef enum _EChatEntryType_ {

	k_EChatEntryTypeInvalid,
	k_EChatEntryTypeChatMsg,
	k_EChatEntryTypeTyping,
	k_EChatEntryTypeInviteGame,
	k_EChatEntryTypeEmote,
	k_EChatEntryTypeLobbyGameStart,
	k_EChatEntryTypeLeftConversation,
	k_EChatEntryTypeEntered,
	k_EChatEntryTypeWasKicked,
	k_EChatEntryTypeWasBanned,
	k_EChatEntryTypeDisconnected,
	k_EChatEntryTypeHistoricalChat,
	k_EChatEntryTypeReserved1,
	k_EChatEntryTypeReserved2,
	k_EChatEntryTypeLinkBlocked

} EChatEntryType, *pEChatEntryType;

// ----
// User Stat Type
// ----

typedef enum _ESteamUserStatType_ {
	
	k_ESteamUserStatTypeINVALID,
	k_ESteamUserStatTypeINT,
	k_ESteamUserStatTypeFLOAT,
	k_ESteamUserStatTypeAVGRATE,
	k_ESteamUserStatTypeACHIEVEMENTS,
	k_ESteamUserStatTypeGROUPACHIEVEMENTS,
	k_ESteamUserStatTypeMAX

} ESteamUserStatType, *pESteamUserStatType;

// ----
// Chat Room Enter Responses
// ----

typedef enum _EChatRoomEnterResponse_ {

	k_EChatRoomEnterResponseSuccess,
	k_EChatRoomEnterResponseDoesntExist,
	k_EChatRoomEnterResponseNotAllowed,
	k_EChatRoomEnterResponseFull,
	k_EChatRoomEnterResponseError,
	k_EChatRoomEnterResponseBanned,
	k_EChatRoomEnterResponseLimited,
	k_EChatRoomEnterResponseClanDisabled,
	k_EChatRoomEnterResponseCommunityBan,
	k_EChatRoomEnterResponseMemberBlockedYou,
	k_EChatRoomEnterResponseYouBlockedMember,
	k_EChatRoomEnterResponseNoRankingDataLobby,
	k_EChatRoomEnterResponseNoRankingDataUser,
	k_EChatRoomEnterResponseRankOutOfRange,
	k_EChatRoomEnterResponseRatelimitExceeded

} EChatRoomEnterResponse, *pEChatRoomEnterResponse;

// ----
// Result codes to GSHandleClientDeny/Kick
// ----

typedef enum _EDenyReason_ {
	
	k_EDenyInvalid,
	k_EDenyInvalidVersion,
	k_EDenyGeneric,
	k_EDenyNotLoggedOn,
	k_EDenyNoLicense,
	k_EDenyCheater,
	k_EDenyLoggedInElseWhere,
	k_EDenyUnknownText,
	k_EDenyIncompatibleAnticheat,
	k_EDenyMemoryCorruption,
	k_EDenyIncompatibleSoftware,
	k_EDenySteamConnectionLost,
	k_EDenySteamConnectionError,
	k_EDenySteamResponseTimedOut,
	k_EDenySteamValidationStalled,
	k_EDenySteamOwnerLeftGuestUser

} EDenyReason, *pEDenyReason;

// ----
// Return type of GetAuthSessionTicket
// ----

typedef Uint32 HAuthTicket, *pHAuthTicket;
#define k_HAuthTicket_Invalid ((HAuthTicket)(0x00000000))
#define k_HAuthTicket_Fake_Ticket ((HAuthTicket)(0xFADECAFE))

// ----
// Results From BeginAuthSession
// ----

typedef enum _EBeginAuthSessionResult_ {

	k_EBeginAuthSessionResultOK,
	k_EBeginAuthSessionResultInvalidTicket,
	k_EBeginAuthSessionResultDuplicateRequest,
	k_EBeginAuthSessionResultInvalidVersion,
	k_EBeginAuthSessionResultGameMismatch,
	k_EBeginAuthSessionResultExpiredTicket

} EBeginAuthSessionResult, *pEBeginAuthSessionResult;

// ----
// Callback values for callback ValidateAuthTicketResponse_t
//  which is a response to BeginAuthSession
// ----

typedef enum _EAuthSessionResponse_ {

	k_EAuthSessionResponseOK,
	k_EAuthSessionResponseUserNotConnectedToSteam,
	k_EAuthSessionResponseNoLicenseOrExpired,
	k_EAuthSessionResponseVACBanned,
	k_EAuthSessionResponseLoggedInElseWhere,
	k_EAuthSessionResponseVACCheckTimedOut,
	k_EAuthSessionResponseAuthTicketCanceled,
	k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed,
	k_EAuthSessionResponseAuthTicketInvalid,
	k_EAuthSessionResponsePublisherIssuedBan,
	k_EAuthSessionResponseAuthTicketNetworkIdentityFailure

} EAuthSessionResponse, *pEAuthSessionResponse;

// ----
// Results From UserHasLicenseForApp
// ----

typedef enum _EUserHasLicenseForAppResult_ {

	k_EUserHasLicenseResultHasLicense,
	k_EUserHasLicenseResultDoesNotHaveLicense,
	k_EUserHasLicenseResultNoAuth

} EUserHasLicenseForAppResult, *pEUserHasLicenseForAppResult;

// ----
// Possible Overlay Notification Positions
//----

typedef enum _ENotificationPosition_ {

	k_ENotificationPositionInvalid = (-1),
	k_ENotificationPositionTopLeft,
	k_ENotificationPositionTopRight,
	k_ENotificationPositionBottomLeft,
	k_ENotificationPositionBottomRight

} ENotificationPosition, *pENotificationPosition;

// ----
// Broadcast Upload Result Details
// ----

typedef enum _EBroadcastUploadResult_ {

	k_EBroadcastUploadResultNone,
	k_EBroadcastUploadResultOK,
	k_EBroadcastUploadResultInitFailed,
	k_EBroadcastUploadResultFrameFailed,
	k_EBroadcastUploadResultTimeout,
	k_EBroadcastUploadResultBandwidthExceeded,
	k_EBroadcastUploadResultLowFPS,
	k_EBroadcastUploadResultMissingKeyFrames,
	k_EBroadcastUploadResultNoConnection,
	k_EBroadcastUploadResultRelayFailed,
	k_EBroadcastUploadResultSettingsChanged,
	k_EBroadcastUploadResultMissingAudio,
	k_EBroadcastUploadResultTooFarBehind,
	k_EBroadcastUploadResultTranscodeBehind,
	k_EBroadcastUploadResultNotAllowedToPlay,
	k_EBroadcastUploadResultBusy,
	k_EBroadcastUploadResultBanned,
	k_EBroadcastUploadResultAlreadyActive,
	k_EBroadcastUploadResultForcedOff,
	k_EBroadcastUploadResultAudioBehind,
	k_EBroadcastUploadResultShutdown,
	k_EBroadcastUploadResultDisconnect,
	k_EBroadcastUploadResultVideoInitFailed,
	k_EBroadcastUploadResultAudioInitFailed

} EBroadcastUploadResult, *pEBroadcastUploadResult;

// ----
// IPv6 Address with Mapping to IPv4
// ----

typedef struct _SteamNetworkingIPAddr_ {

	union {

		Uint8 IPv6[16];
		struct {
			Uint64 x0000000000000000;
			Uint16 x0000;
			Uint16 xFFFF;
			Uint8 cbIPv4[4]; // NetworkOrder
		} IPv4;

	};

	Uint16 Port;

} SteamNetworkingIPAddr, *pSteamNetworkingIPAddr;
typedef struct _SteamNetworkingIPAddrRender_ {
	CharA chArray[48];
} SteamNetworkingIPAddrRender, *pSteamNetworkingIPAddrRender;

// ----
// SteamAPI Networking Identity
// ----

typedef enum _ESteamNetworkingIdentityType_ {

	k_ESteamNetworkingIdentityType_Invalid = 0,
	k_ESteamNetworkingIdentityType_SteamId = 16,
	k_ESteamNetworkingIdentityType_XboxPairwiseId = 17,
	k_ESteamNetworkingIdentityType_SonyPSN = 18,
	k_ESteamNetworkingIdentityType_GoogleStadia = 19,
	k_ESteamNetworkingIdentityType_NintendoNetworkServiceAccount,
	k_ESteamNetworkingIdentityType_EpicGameStore,
	k_ESteamNetworkingIdentityType_WeGame,

	/* Use their IP address (and port) as their "identity".
	   These types of identities are always unauthenticated.
	   They are useful for porting plain sockets code, and other
	    situations where you don't care about authentication.
		In this case, the local identity will be "localhost",
	    and the remote address will be their network address.
	     We use the same type for either IPv4 or IPv6, and
	      the address is always store as IPv6. We use IPv4
	      mapped addresses to handle IPv4. */
	k_ESteamNetworkingIdentityType_IPAddress = 1,

	k_ESteamNetworkingIdentityType_GenericString = 2,
	k_ESteamNetworkingIdentityType_GenericBytes = 3,
	k_ESteamNetworkingIdentityType_UnknownType = 4,

	k_ESteamNetworkingIdentityType_Force32bit = 0x7FFFFFFF,

} ESteamNetworkingIdentityType, *pESteamNetworkingIdentityType;
typedef struct _SteamNetworkingIdentity_ {

	ESteamNetworkingIdentityType eSteamNetworkingIdentityType;
	Int32 cbSize;

	union {

		SteamId_t SteamId;
		Uint64 PSnId;
		Uint64 StadiaId;
		CharA chGenericString[32];
		CharA chXboxPairwiseID[33];
		Uint8 GenericBytes[32];
		CharA chUnknownRawString[128];
		SteamNetworkingIPAddr SteamNetworkingIPAddr;
		Uint32 Reserved[32];

	};

} SteamNetworkingIdentity, *pSteamNetworkingIdentity;
typedef struct _SteamNetworkingIdentityRender_ {
	CharA chArray[128];
} SteamNetworkingIdentityRender, *pSteamNetworkingIdentityRender;

// ----
// Callback Function Prototype
// ----

#ifdef __cplusplus
	extern "C" typedef void (*PreMinidumpCallback)
		(pVoid pvContext);
#else // !C++
	typedef void (*PreMinidumpCallback)
		(pVoid pvContext);
#endif

#ifdef __cplusplus
	extern "C" typedef void (_S_CALL_ *SteamAPIWarningMessageHook_t)
		(Int32 sCode, pCStrA pText);
#else // !C++
	typedef void (_S_CALL_ *SteamAPIWarningMessageHook_t)
		(Int32 sCode, pCStrA pText);
#endif

#ifdef __cplusplus
	extern "C" typedef Uint32 (__cdecl *SteamAPI_CheckCallbackRegistered_t)
		(Int32 iCallback);
#else // !C++
	typedef Uint32(__cdecl *SteamAPI_CheckCallbackRegistered_t)
		(Int32 iCallback);
#endif

#define k_iSteamUserCallbacks ((Int32)(100))
#define k_iSteamGameServerCallbacks ((Int32)(200))
#define k_iSteamFriendsCallbacks ((Int32)(300))
#define k_iSteamBillingCallbacks ((Int32)(400))
#define k_iSteamMatchmakingCallbacks ((Int32)(500))
#define k_iSteamContentServerCallbacks ((Int32)(600))
#define k_iSteamUtilsCallbacks ((Int32)(700))
#define k_iClientFriendsCallbacks ((Int32)(800))
#define k_iClientUserCallbacks ((Int32)(900))
#define k_iSteamAppsCallbacks ((Int32)(1000))
#define k_iSteamUserStatsCallbacks ((Int32)(1100))
#define k_iSteamNetworkingCallbacks ((Int32)(1200))
#define k_iSteamNetworkingSocketsCallbacks ((Int32)(1220))
#define k_iSteamNetworkingMessagesCallbacks ((Int32)(1250))
#define k_iSteamNetworkingUtilsCallbacks ((Int32)(1280))
#define k_iClientRemoteStorageCallbacks ((Int32)(1300))
#define k_iSteamRemoteStorageCallbacks ((Int32)(1300))
#define k_iClientDepotBuilderCallbacks ((Int32)(1400))
#define k_iSteamGameServerItemsCallbacks ((Int32)(1500))
#define k_iClientUtilsCallbacks ((Int32)(1600))
#define k_iSteamGameCoordinatorCallbacks ((Int32)(1700))
#define k_iSteamGameServerStatsCallbacks ((Int32)(1800))
#define k_iSteam2AsyncCallbacks ((Int32)(1900))
#define k_iSteamGameStatsCallbacks ((Int32)(2000))
#define k_iClientHTTPCallbacks ((Int32)(2100))
#define k_iSteamHTTPCallbacks ((Int32)(2100))
#define k_iClientScreenshotsCallbacks ((Int32)(2200))
#define k_iSteamScreenshotsCallbacks ((Int32)(2300))
#define k_iClientAudioCallbacks ((Int32)(2400))
#define k_iClientUnifiedMessagesCallbacks ((Int32)(2500))
#define k_iSteamStreamLauncherCallbacks ((Int32)(2600))
#define k_iClientControllerCallbacks ((Int32)(2700))
#define k_iSteamControllerCallbacks ((Int32)(2800))
#define k_iClientParentalSettingsCallbacks ((Int32)(2900))
#define k_iClientDeviceAuthCallbacks ((Int32)(3000))
#define k_iClientNetworkDeviceManagerCallbacks ((Int32)(3100))
#define k_iClientMusicCallbacks ((Int32)(3200))
#define k_iClientRemoteClientManagerCallbacks ((Int32)(3300))
#define k_iClientUGCCallbacks ((Int32)(3400))
#define k_iSteamUGCCallbacks ((Int32)(3400))
#define k_iSteamStreamClientCallbacks ((Int32)(3500))
#define k_IClientProductBuilderCallbacks ((Int32)(3600))
#define k_iClientShortcutsCallbacks ((Int32)(3700))
#define k_iClientRemoteControlManagerCallbacks ((Int32)(3800))
#define k_iSteamAppListCallbacks ((Int32)(3900))
#define k_iSteamMusicCallbacks ((Int32)(4000))
#define k_iSteamMusicRemoteCallbacks ((Int32)(4100))
#define k_iClientVRCallbacks ((Int32)(4200))
#define k_iClientGameNotificationCallbacks ((Int32)(4300)) 
#define k_iSteamGameNotificationCallbacks ((Int32)(4400)) 
#define k_iSteamHTMLSurfaceCallbacks ((Int32)(4500))
#define k_iClientVideoCallbacks ((Int32)(4600))
#define k_iSteamVideoCallbacks ((Int32)(4600))
#define k_iClientInventoryCallbacks ((Int32)(4700))
#define k_iSteamInventoryCallbacks ((Int32)(4700))
#define k_iClientBluetoothManagerCallbacks ((Int32)(4800))
#define k_iClientSharedConnectionCallbacks ((Int32)(4900))
#define k_ISteamParentalSettingsCallbacks ((Int32)(5000))
#define k_iClientShaderCallbacks ((Int32)(5100))
#define k_iSteamGameSearchCallbacks ((Int32)(5200))
#define k_iSteamPartiesCallbacks ((Int32)(5300))
#define k_iClientPartiesCallbacks ((Int32)(5400))
#define k_iSteamSTARCallbacks ((Int32)(5500))
#define k_iClientSTARCallbacks ((Int32)(5600))
#define k_iSteamRemotePlayCallbacks ((Int32)(5700))
#define k_iClientCompatCallbacks ((Int32)(5800))
#define k_iSteamChatCallbacks ((Int32)(5900))
#define k_iClientNetworkingUtilsCallbacks ((Int32)(6000))
#define k_iClientSystemManagerCallbacks ((Int32)(6100))
#define k_iClientStorageDeviceManagerCallbacks ((Int32)(6200))

// ----
// HTTP Method List
// ----

typedef enum _EHTTPMethod_ {

	k_EHTTPMethodInvalid,
	k_EHTTPMethodGET,
	k_EHTTPMethodHEAD,
	k_EHTTPMethodPOST,
	k_EHTTPMethodPUT,
	k_EHTTPMethodDELETE,
	k_EHTTPMethodOPTIONS,
	k_EHTTPMethodPATCH,
	k_EHTTPMethodTRACE,
	k_EHTTPMethodCONNECT

} EHTTPMethod, *pEHTTPMethod;

// ----
// HTTP Status Codes
// ----

typedef enum _EHTTPStatusCode_ {

	k_EHTTPStatusCodeInvalid,
	k_EHTTPStatusCode100Continue = 100,
	k_EHTTPStatusCode101SwitchingProtocols = 101,
	k_EHTTPStatusCode200OK = 200,
	k_EHTTPStatusCode201Created = 201,
	k_EHTTPStatusCode202Accepted = 202,
	k_EHTTPStatusCode203NonAuthoritative = 203,
	k_EHTTPStatusCode204NoContent = 204,
	k_EHTTPStatusCode205ResetContent = 205,
	k_EHTTPStatusCode206PartialContent = 206,
	k_EHTTPStatusCode300MultipleChoices = 300,
	k_EHTTPStatusCode301MovedPermanently = 301,
	k_EHTTPStatusCode302Found = 302,
	k_EHTTPStatusCode303SeeOther = 303,
	k_EHTTPStatusCode304NotModified = 304,
	k_EHTTPStatusCode305UseProxy = 305,
	k_EHTTPStatusCode306Unused = 306,
	k_EHTTPStatusCode307TemporaryRedirect = 307,
	k_EHTTPStatusCode308PermanentRedirect = 308,
	k_EHTTPStatusCode400BadRequest = 400,
	k_EHTTPStatusCode401Unauthorized = 401,
	k_EHTTPStatusCode402PaymentRequired = 402,
	k_EHTTPStatusCode403Forbidden = 403,
	k_EHTTPStatusCode404NotFound = 404,
	k_EHTTPStatusCode405MethodNotAllowed = 405,
	k_EHTTPStatusCode406NotAcceptable = 406,
	k_EHTTPStatusCode407ProxyAuthRequired = 407,
	k_EHTTPStatusCode408RequestTimeout = 408,
	k_EHTTPStatusCode409Conflict = 409,
	k_EHTTPStatusCode410Gone = 410,
	k_EHTTPStatusCode411LengthRequired = 411,
	k_EHTTPStatusCode412PreconditionFailed = 412,
	k_EHTTPStatusCode413RequestEntityTooLarge = 413,
	k_EHTTPStatusCode414RequestURITooLong = 414,
	k_EHTTPStatusCode415UnsupportedMediaType = 415,
	k_EHTTPStatusCode416RequestedRangeNotSatisfiable = 416,
	k_EHTTPStatusCode417ExpectationFailed = 417,
	k_EHTTPStatusCode4xxUnknown = 418,
	k_EHTTPStatusCode429TooManyRequests = 429,
	k_EHTTPStatusCode444ConnectionClosed = 444,
	k_EHTTPStatusCode500InternalServerError = 500,
	k_EHTTPStatusCode501NotImplemented = 501,
	k_EHTTPStatusCode502BadGateway = 502,
	k_EHTTPStatusCode503ServiceUnavailable = 503,
	k_EHTTPStatusCode504GatewayTimeout = 504,
	k_EHTTPStatusCode505HTTPVersionNotSupported = 505,
	k_EHTTPStatusCode5xxUnknown = 599

} EHTTPStatusCode, *pEHTTPStatusCode;

// ----
// Steam Connectivity
// ----

typedef enum _ESteamIPv6ConnectivityProtocol_ {

	k_ESteamIPv6ConnectivityProtocol_Invalid,
	k_ESteamIPv6ConnectivityProtocol_HTTP,
	k_ESteamIPv6ConnectivityProtocol_UDP

} ESteamIPv6ConnectivityProtocol, *pESteamIPv6ConnectivityProtocol;
typedef enum _ESteamIPv6ConnectivityState_ {

	k_ESteamIPv6ConnectivityState_Unknown,
	k_ESteamIPv6ConnectivityState_Good,
	k_ESteamIPv6ConnectivityState_Bad

} ESteamIPv6ConnectivityState, *pESteamIPv6ConnectivityState;

// ----
// Used in MarketEligibilityResponse_t
// ----

typedef enum _EMarketNotAllowedReasonFlags_ {

	k_EMarketNotAllowedReason_None = 0x00000000,
	k_EMarketNotAllowedReason_TemporaryFailure = 0x00000001,
	k_EMarketNotAllowedReason_AccountDisabled = 0x00000002,
	k_EMarketNotAllowedReason_AccountLockedDown = 0x00000004,
	k_EMarketNotAllowedReason_AccountLimited = 0x00000008,
	k_EMarketNotAllowedReason_TradeBanned = 0x00000010,
	k_EMarketNotAllowedReason_AccountNotTrusted = 0x00000020,
	k_EMarketNotAllowedReason_SteamGuardNotEnabled = 0x00000040,
	k_EMarketNotAllowedReason_SteamGuardOnlyRecentlyEnabled = 0x00000080,
	k_EMarketNotAllowedReason_RecentPasswordReset = 0x00000100,
	k_EMarketNotAllowedReason_NewPaymentMethod = 0x00000200,
	k_EMarketNotAllowedReason_InvalidCookie = 0x00000400,
	k_EMarketNotAllowedReason_UsingNewDevice = 0x00008000,
	k_EMarketNotAllowedReason_RecentSelfRefund = 0x01000000,
	k_EMarketNotAllowedReason_NewPaymentMethodCannotBeVerified = 0x02000000,
	k_EMarketNotAllowedReason_NoRecentPurchases = 0x04000000,
	k_EMarketNotAllowedReason_AcceptedWalletGift = 0x08000000

} EMarketNotAllowedReasonFlags, *pEMarketNotAllowedReasonFlags;

// ----
// Duration Control
// ----

typedef enum _EDurationControlProgress_ {

	k_EDurationControlProgress_Full,
	k_EDurationControlProgress_Half,
	k_EDurationControlProgress_None,
	k_EDurationControl_ExitSoon_3h,
	k_EDurationControl_ExitSoon_5h,
	k_EDurationControl_ExitSoon_Night

} EDurationControlProgress, *pEDurationControlProgress;
typedef enum _EDurationControlNotification_ {

	k_EDurationControlNotification_None,
	k_EDurationControlNotification_1Hour,
	k_EDurationControlNotification_3Hours,
	k_EDurationControlNotification_HalfProgress,
	k_EDurationControlNotification_NoProgress,
	k_EDurationControlNotification_ExitSoon_3h,
	k_EDurationControlNotification_ExitSoon_5h,
	k_EDurationControlNotification_ExitSoon_Night

} EDurationControlNotification, *pEDurationControlNotification;
typedef enum _EDurationControlOnlineState_ {

	k_EDurationControlOnlineState_Invalid,
	k_EDurationControlOnlineState_Offline,
	k_EDurationControlOnlineState_Online,
	k_EDurationControlOnlineState_OnlineHighPri

} EDurationControlOnlineState, *pEDurationControlOnlineState;

// ----
// Networking
// ----

typedef enum _EGameSearchErrorCode_t_ {

	k_EGameSearchErrorCode_OK = 1,
	k_EGameSearchErrorCode_Failed_Search_Already_In_Progress,
	k_EGameSearchErrorCode_Failed_No_Search_In_Progress,
	k_EGameSearchErrorCode_Failed_Not_Lobby_Leader,
	k_EGameSearchErrorCode_Failed_No_Host_Available,
	k_EGameSearchErrorCode_Failed_Search_Params_Invalid,
	k_EGameSearchErrorCode_Failed_Offline,
	k_EGameSearchErrorCode_Failed_NotAuthorized,
	k_EGameSearchErrorCode_Failed_Unknown_Error

} EGameSearchErrorCode_t, *pEGameSearchErrorCode_t;
typedef enum _EPlayerResult_t_ {

	k_EPlayerResultFailedToConnect = 1,
	k_EPlayerResultAbandoned,
	k_EPlayerResultKicked,
	k_EPlayerResultIncomplete,
	k_EPlayerResultCompleted

} EPlayerResult_t, *pEPlayerResult_t;

typedef Uint32 HSteamNetConnection, *pHSteamNetConnection;
#define k_HSteamNetConnection_Invalid ((HSteamNetConnection)(0x00000000));

typedef Uint32 HSteamListenSocket, *pHSteamListenSocket;
#define k_HSteamListenSocket_Invalid ((HSteamListenSocket)(0x00000000));

typedef Uint32 HSteamNetPollGroup, *pHSteamNetPollGroup;
#define k_HSteamNetPollGroup_Invalid ((HSteamNetPollGroup)(0x00000000));

typedef Int64 SteamNetworkingMicroseconds, *pSteamNetworkingMicroseconds;
typedef struct _SteamNetworkingMessage_t_Old_ {

	SteamId_t SteamIdSender;
	Int64 nConnectionUserData;
	SteamNetworkingMicroseconds TimeReceived;
	Int64 nMessageNumber;
	void(*Release)
		(_SteamNetworkingMessage_t_Old_ *pSteamNetworkingMessage);
	pVoid pvData;
	Int32 cbSize;
	HSteamNetConnection hSteamNetConnection;
	Int32 nChannel;
	Int32 Padding;

} SteamNetworkingMessage_t_Old, *pSteamNetworkingMessage_t_Old;
typedef struct _SteamNetworkingMessage_t_ {

	pVoid pvData;
	Int32 cbSize;
	HSteamNetConnection hSteamNetConnection;
	SteamNetworkingIdentity IdentityPeer;
	Int64 nConnectionUserData;
	SteamNetworkingMicroseconds TimeReceived;
	Int64 nMessageNumber;
	void (*FreeData)
		(_SteamNetworkingMessage_t_ *pSteamNetworkingMessage);
	void (*Release)
		(_SteamNetworkingMessage_t_ *pSteamNetworkingMessage);
	Int32 nChannel;
	Int32 nFlags;
	Int64 nUserData;
	Uint16 idxLane;
	Uint16 Padding;

} SteamNetworkingMessage_t, *pSteamNetworkingMessage_t;

typedef enum _ESteamNetworkingAvailability_ {
	
	k_ESteamNetworkingAvailability_CannotTry = -102,
	k_ESteamNetworkingAvailability_Failed = -101,
	k_ESteamNetworkingAvailability_Previously = -100,
	k_ESteamNetworkingAvailability_Retrying = -10,
	k_ESteamNetworkingAvailability_NeverTried = 1,
	k_ESteamNetworkingAvailability_Waiting = 2,
	k_ESteamNetworkingAvailability_Attempting = 3,
	k_ESteamNetworkingAvailability_Current = 100,
	k_ESteamNetworkingAvailability_Unknown = 0,
	k_ESteamNetworkingAvailability_Force32bit = 0x7FFFFFFF

} ESteamNetworkingAvailability, *pESteamNetworkingAvailability;
typedef struct _SteamNetworkPingLocation_t_ {

	Byte cbData[512];

} SteamNetworkPingLocation_t, *pSteamNetworkPingLocation_t;

typedef enum _ESteamNetworkingConnectionState_ {

	k_ESteamNetworkingConnectionState_None = 0,
	k_ESteamNetworkingConnectionState_Connecting = 1,
	k_ESteamNetworkingConnectionState_FindingRoute = 2,
	k_ESteamNetworkingConnectionState_Connected = 3,
	k_ESteamNetworkingConnectionState_ClosedByPeer = 4,
	k_ESteamNetworkingConnectionState_ProblemDetectedLocally = 5,
	k_ESteamNetworkingConnectionState_FinWait = -1,
	k_ESteamNetworkingConnectionState_Linger = -2,
	k_ESteamNetworkingConnectionState_Dead = -3,
	k_ESteamNetworkingConnectionState_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingConnectionState, *pESteamNetworkingConnectionState;

#define k_cchSteamNetworkingMaxConnectionCloseReason ((Int32)(128))
#define k_cchSteamNetworkingMaxConnectionDescription ((Int32)(128))
#define k_cchSteamNetworkingMaxConnectionAppName ((Int32)(32))

typedef Uint32 SteamNetworkingPOPID, *pSteamNetworkingPOPID;
typedef struct _SteamNetworkingPOPIDRender_ {
	CharA chArray[8];
} SteamNetworkingPOPIDRender, *pSteamNetworkingPOPIDRender;
typedef struct _SteamNetConnectionInfo_t_Old_ {

	SteamId_t SteamIdRemote;
	Int64 nUserData;
	HSteamListenSocket hListenSocket;
	Uint32 nIPRemote;
	Uint16 PortRemote;
	Uint16 Padding;
	SteamNetworkingPOPID IdPOPRemote;
	SteamNetworkingPOPID IdPOPRelay;
	Int32 eState;
	Int32 eEndReason;
	CharA chEndDebug[k_cchSteamNetworkingMaxConnectionCloseReason];

} SteamNetConnectionInfo_t_Old, *pSteamNetConnectionInfo_t_Old;
typedef struct _SteamNetConnectionInfo_t_ {

	SteamNetworkingIdentity IdentityRemote;
	Int64 nUserData;
	HSteamListenSocket hListenSocket;
	SteamNetworkingIPAddr AddrRemote;
	Uint16 Padding;
	SteamNetworkingPOPID IdPOPRemote;
	SteamNetworkingPOPID IdPOPRelay;
	ESteamNetworkingConnectionState eSteamNetworkingConnectionState;
	Int32 eEndReason;
	CharA chEndDebug[k_cchSteamNetworkingMaxConnectionCloseReason];
	CharA chConnectionDescription[k_cchSteamNetworkingMaxConnectionDescription];
	Int32 nFlags;
	Uint32 Reserved[63];

} SteamNetConnectionInfo_t, *pSteamNetConnectionInfo_t;
typedef struct _SteamNetConnectionRealTimeStatus_t_ {

	ESteamNetworkingConnectionState eSteamNetworkingConnectionState;
	Int32 nPing;
	Float ConnectionQualityLocal;
	Float ConnectionQualityRemote;
	Float OutPacketsPerSec;
	Float OutBytesPerSec;
	Float InPacketsPerSec;
	Float InBytesPerSec;
	Int32 nSendRateBytesPerSecond;
	Int32 cbPendingUnreliable;
	Int32 cbPendingReliable;
	Int32 cbSentUnackedReliable;
	SteamNetworkingMicroseconds QueueTime;
	Uint32 Reserved[16];

} SteamNetConnectionRealTimeStatus_t, *pSteamNetConnectionRealTimeStatus_t;

typedef enum _ESteamNetworkingConfigValue_ {

	k_ESteamNetworkingConfig_Invalid = 0,
	k_ESteamNetworkingConfig_TimeoutInitial = 24,
	k_ESteamNetworkingConfig_TimeoutConnected = 25,
	k_ESteamNetworkingConfig_SendBufferSize = 9,
	k_ESteamNetworkingConfig_ConnectionUserData = 40,
	k_ESteamNetworkingConfig_SendRateMin = 10,
	k_ESteamNetworkingConfig_SendRateMax = 11,
	k_ESteamNetworkingConfig_NagleTime = 12,
	k_ESteamNetworkingConfig_IP_AllowWithoutAuth = 23,
	k_ESteamNetworkingConfig_MTU_PacketSize = 32,
	k_ESteamNetworkingConfig_MTU_DataSize = 33,
	k_ESteamNetworkingConfig_Unencrypted = 34,
	k_ESteamNetworkingConfig_SymmetricConnect = 37,
	k_ESteamNetworkingConfig_LocalVirtualPort = 38,
	k_ESteamNetworkingConfig_DualWifi_Enable = 39,
	k_ESteamNetworkingConfig_EnableDiagnosticsUI = 46,
	k_ESteamNetworkingConfig_FakePacketLoss_Send = 2,
	k_ESteamNetworkingConfig_FakePacketLoss_Recv = 3,
	k_ESteamNetworkingConfig_FakePacketLag_Send = 4,
	k_ESteamNetworkingConfig_FakePacketLag_Recv = 5,
	k_ESteamNetworkingConfig_FakePacketReorder_Send = 6,
	k_ESteamNetworkingConfig_FakePacketReorder_Recv = 7,
	k_ESteamNetworkingConfig_FakePacketReorder_Time = 8,
	k_ESteamNetworkingConfig_FakePacketDup_Send = 26,
	k_ESteamNetworkingConfig_FakePacketDup_Recv = 27,
	k_ESteamNetworkingConfig_FakePacketDup_TimeMax = 28,
	k_ESteamNetworkingConfig_PacketTraceMaxBytes = 41,
	k_ESteamNetworkingConfig_FakeRateLimit_Send_Rate = 42,
	k_ESteamNetworkingConfig_FakeRateLimit_Send_Burst = 43,
	k_ESteamNetworkingConfig_FakeRateLimit_Recv_Rate = 44,
	k_ESteamNetworkingConfig_FakeRateLimit_Recv_Burst = 45,
	k_ESteamNetworkingConfig_Callback_ConnectionStatusChanged = 201,
	k_ESteamNetworkingConfig_Callback_AuthStatusChanged = 202,
	k_ESteamNetworkingConfig_Callback_RelayNetworkStatusChanged = 203,
	k_ESteamNetworkingConfig_Callback_MessagesSessionRequest = 204,
	k_ESteamNetworkingConfig_Callback_MessagesSessionFailed = 205,
	k_ESteamNetworkingConfig_Callback_CreateConnectionSignaling = 206,
	k_ESteamNetworkingConfig_Callback_FakeIPResult = 207,
	k_ESteamNetworkingConfig_P2P_STUN_ServerList = 103,
	k_ESteamNetworkingConfig_P2P_Transport_ICE_Enable = 104,
	k_ESteamNetworkingConfig_P2P_Transport_ICE_Penalty = 105,
	k_ESteamNetworkingConfig_P2P_Transport_SDR_Penalty = 106,
	k_ESteamNetworkingConfig_P2P_TURN_ServerList = 107,
	k_ESteamNetworkingConfig_P2P_TURN_UserList = 108,
	k_ESteamNetworkingConfig_P2P_TURN_PassList = 109,
	k_ESteamNetworkingConfig_P2P_Transport_ICE_Implementation = 110,
	k_ESteamNetworkingConfig_SDRClient_ConsecutitivePingTimeoutsFailInitial = 19,
	k_ESteamNetworkingConfig_SDRClient_ConsecutitivePingTimeoutsFail = 20,
	k_ESteamNetworkingConfig_SDRClient_MinPingsBeforePingAccurate = 21,
	k_ESteamNetworkingConfig_SDRClient_SingleSocket = 22,
	k_ESteamNetworkingConfig_SDRClient_ForceRelayCluster = 29,
	k_ESteamNetworkingConfig_SDRClient_DebugTicketAddress = 30,
	k_ESteamNetworkingConfig_SDRClient_ForceProxyAddr = 31,
	k_ESteamNetworkingConfig_SDRClient_FakeClusterPing = 36,
	k_ESteamNetworkingConfig_DELETED_EnumerateDevVars = 35,
	k_ESteamNetworkingConfigValue_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingConfigValue, *pESteamNetworkingConfigValue;
typedef enum _ESteamNetworkingConfigDataType_ {

	k_ESteamNetworkingConfig_Int32 = 1,
	k_ESteamNetworkingConfig_Int64 = 2,
	k_ESteamNetworkingConfig_Float = 3,
	k_ESteamNetworkingConfig_String = 4,
	k_ESteamNetworkingConfig_Ptr = 5,
	k_ESteamNetworkingConfigDataType_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingConfigDataType, *pESteamNetworkingConfigDataType;
typedef struct _SteamNetworkingConfigValue_t_ {

	ESteamNetworkingConfigValue eValue;
	ESteamNetworkingConfigDataType eDataType;

	union {

		Int32 Int32;
		Int64 Int64;
		Float Float;
		pCStrA pchStr;
		pVoid pvData;

	};

} SteamNetworkingConfigValue_t, *pSteamNetworkingConfigValue_t;

typedef enum _ESteamNetworkingSendType_ {

	k_ESteamNetworkingSendType_Unreliable,
	k_ESteamNetworkingSendType_UnreliableNoNagle = 1,
	k_ESteamNetworkingSendType_UnreliableNoDelay = (2 | 1),
	k_ESteamNetworkingSendType_Reliable = 8,
	k_ESteamNetworkingSendType_ReliableNoNagle = (8 | 1)

} ESteamNetworkingSendType, *pESteamNetworkingSendType;
typedef enum _ESteamNetworkingConfigurationValue_ {

	k_ESteamNetworkingConfigurationValue_FakeMessageLoss_Send,
	k_ESteamNetworkingConfigurationValue_FakeMessageLoss_Recv,
	k_ESteamNetworkingConfigurationValue_FakePacketLoss_Send,
	k_ESteamNetworkingConfigurationValue_FakePacketLoss_Recv,
	k_ESteamNetworkingConfigurationValue_FakePacketLag_Send,
	k_ESteamNetworkingConfigurationValue_FakePacketLag_Recv,
	k_ESteamNetworkingConfigurationValue_FakePacketReorder_Send,
	k_ESteamNetworkingConfigurationValue_FakePacketReorder_Recv,
	k_ESteamNetworkingConfigurationValue_FakePacketReorder_Time,
	k_ESteamNetworkingConfigurationValue_SendBufferSize,
	k_ESteamNetworkingConfigurationValue_MaxRate,
	k_ESteamNetworkingConfigurationValue_MinRate,
	k_ESteamNetworkingConfigurationValue_Nagle_Time,
	k_ESteamNetworkingConfigurationValue_LogLevel_AckRTT,
	k_ESteamNetworkingConfigurationValue_LogLevel_Packet,
	k_ESteamNetworkingConfigurationValue_LogLevel_Message,
	k_ESteamNetworkingConfigurationValue_LogLevel_PacketGaps,
	k_ESteamNetworkingConfigurationValue_LogLevel_P2PRendezvous,
	k_ESteamNetworkingConfigurationValue_LogLevel_RelayPings,
	k_ESteamNetworkingConfigurationValue_ClientConsecutitivePingTimeoutsFailInitial,
	k_ESteamNetworkingConfigurationValue_ClientConsecutitivePingTimeoutsFail,
	k_ESteamNetworkingConfigurationValue_ClientMinPingsBeforePingAccurate,
	k_ESteamNetworkingConfigurationValue_ClientSingleSocket,
	k_ESteamNetworkingConfigurationValue_IP_Allow_Without_Auth,
	k_ESteamNetworkingConfigurationValue_Timeout_Seconds_Initial,
	k_ESteamNetworkingConfigurationValue_Timeout_Seconds_Connected,
	k_ESteamNetworkingConfigurationValue_Count

} ESteamNetworkingConfigurationValue, *pESteamNetworkingConfigurationValue;
typedef enum _ESteamNetworkingConfigurationString_ {
	
	k_ESteamNetworkingConfigurationString_ClientForceRelayCluster,
	k_ESteamNetworkingConfigurationString_ClientDebugTicketAddress,
	k_ESteamNetworkingConfigurationString_ClientForceProxyAddr,
	k_ESteamNetworkingConfigurationString_Count

} ESteamNetworkingConfigurationString, *pESteamNetworkingConfigurationString;
typedef enum _ESteamNetworkingConnectionConfigurationValue_ {

	k_ESteamNetworkingConnectionConfigurationValue_SNP_MaxRate,
	k_ESteamNetworkingConnectionConfigurationValue_SNP_MinRate,
	k_ESteamNetworkingConnectionConfigurationValue_Count

} ESteamNetworkingConnectionConfigurationValue, *pESteamNetworkingConnectionConfigurationValue;

typedef struct _SteamNetConnectionRealTimeLaneStatus_t_ {
	
	Int32 cbPendingUnreliable;
	Int32 cbPendingReliable;
	Int32 cbSentUnackedReliable;
	SteamNetworkingMicroseconds QueueTime;
	Uint32 Reserved[10];

} SteamNetConnectionRealTimeLaneStatus_t, *pSteamNetConnectionRealTimeLaneStatus_t;

#define k_cchMaxSteamNetworkingErrMsg ((Int32)(1024))
typedef char SteamNetworkingErrMsg[k_cchMaxSteamNetworkingErrMsg], *pSteamNetworkingErrMsg;

// ----
// Steam Datagram Tickets
// ----

typedef struct _SteamDatagramHostedAddress_ {

	Int32 cbSize;
	Byte Data[128];

} SteamDatagramHostedAddress, *pSteamDatagramHostedAddress;
typedef struct _SteamDatagramRelayAuthTicket_ {

	SteamNetworkingIdentity IdentityGameserver;
	SteamNetworkingIdentity IdentityAuthorizedClient;
	Uint32 nPublicIP;
	RTime32 TicketExpiry;
	SteamDatagramHostedAddress Routing;
	Uint32 iAppID;
	Int32 nRestrictToVirtualPort;
	Int32 nExtraFields;

	struct {
		
		/* 0: String, 1: Int, 2: Fixed64 */
		Int32 eType;
		CharA chName[28];

		union {

			CharA chString[128];
			Int64 Int;
			Uint64 Fixed64;

		};

	} ExtraFields[16];

} SteamDatagramRelayAuthTicket, *pSteamDatagramRelayAuthTicket;

#define k_cbMaxSteamDatagramGameCoordinatorServerLoginAppData ((Int32)(2048))
#define k_cbMaxSteamDatagramGameCoordinatorServerLoginSerialized ((Int32)(4096))

typedef struct _SteamDatagramGameCoordinatorServerLogin_ {

	SteamNetworkingIdentity Identity;
	SteamDatagramHostedAddress Routing;
	AppId_t iAppId;
	/* Unix Timestamp */
	RTime32 Time;
	Int32 cbAppData;
	Byte AppData[k_cbMaxSteamDatagramGameCoordinatorServerLoginAppData];

} SteamDatagramGameCoordinatorServerLogin, *pSteamDatagramGameCoordinatorServerLogin;

#define k_cbSteamDatagramMaxSerializedTicket ((Int32)(512))
typedef struct _SteamDatagramSignedTicketBlob_ {

	Int32 cbBlob;
	Uint8 Blob[k_cbSteamDatagramMaxSerializedTicket];

} SteamDatagramSignedTicketBlob, *pSteamDatagramSignedTicketBlob;

#endif // !_FREE_API_TYPEDEF_
