#ifndef _ISTEAMUTILS_
#define _ISTEAMUTILS_

#include "..\..\FreeAPI.Typedef.h"

typedef enum _ESteamAPICallFailure_ {

	k_ESteamAPICallFailureNone = (-1),
	k_ESteamAPICallFailureSteamGone,
	k_ESteamAPICallFailureNetworkFailure,
	k_ESteamAPICallFailureInvalidHandle,
	k_ESteamAPICallFailureMismatchedCallback

} ESteamAPICallFailure, *pESteamAPICallFailure;

typedef enum _EGamepadTextInputMode_ {

	k_EGamepadTextInputModeNormal,
	k_EGamepadTextInputModePassword

} EGamepadTextInputMode, *pEGamepadTextInputMode;

typedef enum _EGamepadTextInputLineMode_ {

	k_EGamepadTextInputLineModeSingleLine,
	k_EGamepadTextInputLineModeMultipleLines

} EGamepadTextInputLineMode, *pEGamepadTextInputLineMode;

typedef enum _EFloatingGamepadTextInputMode_ {

	k_EFloatingGamepadTextInputModeModeSingleLine,
	k_EFloatingGamepadTextInputModeModeMultipleLines,
	k_EFloatingGamepadTextInputModeModeEmail,
	k_EFloatingGamepadTextInputModeModeNumeric

} EFloatingGamepadTextInputMode, *pEFloatingGamepadTextInputMode;

// The context where text filtering is being done
typedef enum _ETextFilteringContext_ {

	k_ETextFilteringContextUnknown,
	k_ETextFilteringContextGameContent,
	k_ETextFilteringContextChat,
	k_ETextFilteringContextName

} ETextFilteringContext, *pETextFilteringContext;

// -----------------------------------------------------------------------------
// Purpose: interface to user independent utility functions
// -----------------------------------------------------------------------------
typedef class _ISteamUtils_ {
public:

	virtual Uint32 GetSecondsSinceAppActive() = 0;
	virtual Uint32 GetSecondsSinceComputerActive() = 0;
	virtual EUniverse GetConnectedUniverse() = 0;

	/* Number of seconds since January 1, 1970, (Unix Time) */
	virtual Uint32 GetServerRealTime() = 0;

	/* Returns User Country Code: "UK", "US", ... */
	virtual const pStrA GetIPCountry() = 0;

	virtual Bool GetImageSize(Int32 iImage, /* [out] */ pUint32 pCx, /* [out] */ pUint32 pCy) = 0;

	/* ImageData size should be (4 * height * width * sizeof(CharA)): RGBA */
	virtual Bool GetImageRGBA(Int32 iImage, /* [out] */ pUint8 pbDest, Int32 nDestSize) = 0;
	virtual Bool GetCSERIPPort(/* [out] */ pUint32 nIP, /* [out] */ pUint16 Port) = 0;
	virtual Uint8 GetCurrentBatteryPower() = 0;

	/* Returns Current Process AppId */
	virtual AppId_t GetAppId() = 0;
	virtual void SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition) = 0;

	virtual Bool IsAPICallCompleted(SteamAPICall_t hSteamAPICall, /* [out] */ pBool pbFailed) = 0;
	virtual ESteamAPICallFailure GetAPICallFailureReason(SteamAPICall_t hSteamAPICall) = 0;
	virtual Bool GetAPICallResult(SteamAPICall_t hSteamAPICall, /* [out] */ pVoid pCallback, Int32 cbCallback, Int32 iCallbackExpected, /* [out] */ pBool pbFailed) = 0;

	/* Applications should use SteamAPI_RunCallbacks() instead */
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;

	/* API warning handling
	    Int32 is severity; 0: msg, 1: warning
	    const pStrA is text of the message
	    callbacks will occur directly after the API function is called that generated the warning or message. */
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool IsOverlayEnabled() = 0;

	/* Normally this call is unneeded if your game has a constantly running frame loop that calls the
	    D3D Present API, or OGL SwapBuffers API every frame. */
	virtual Bool BOverlayNeedsPresent() = 0;

	/* Asynchronous call to check if an executable file has been signed using the public key set on the signing tab
	   of the partner site, for example to refuse to load modified executable files.  
	   The result is returned in CheckFileSignature_t.
	    k_ECheckFileSignatureNoSignaturesFoundForThisApp - This app has not been configured on the signing tab of the partner site to enable this function.
	    k_ECheckFileSignatureNoSignaturesFoundForThisFile - This file is not listed on the signing tab for the partner site.
	    k_ECheckFileSignatureFileNotFound - The file does not exist on disk.
	    k_ECheckFileSignatureInvalidSignature - The file exists, and the signing tab has been set for this file, but the file is either not signed or the signature does not match.
	    k_ECheckFileSignatureValidSignature - The file is signed and the signature is valid. */
	virtual SteamAPICall_t CheckFileSignature(const pStrA pchFileName) = 0;
	virtual Bool ShowGamepadTextInput(EGamepadTextInputMode eGamepadTextInputMode, EGamepadTextInputLineMode eGamepadTextInputLineMode, const pStrA pchDescription, Uint32 cchDescription, const pStrA pchExistingText) = 0;
	virtual Uint32 GetEnteredGamepadTextLength() = 0;
	virtual Bool GetEnteredGamepadTextInput(/* [out] */ pStrA pchText, Uint32 cchText) = 0;
	
	virtual const pStrA GetSteamUILanguage() = 0;
	virtual Bool IsSteamRunningInVR() = 0;
	virtual void SetOverlayNotificationInset(Int32 nHorizontalInset, Int32 nVerticalInset) = 0;
	virtual Bool IsSteamInBigPictureMode() = 0;
	virtual void StartVRDashboard() = 0;
	virtual Bool IsVRHeadsetStreamingEnabled() = 0;
	virtual void SetVRHeadsetStreamingEnabled(Bool bEnabled) = 0;
	virtual Bool IsSteamChinaLauncher() = 0;
	virtual Bool InitFilterText(Uint32 nFilterOptions) = 0;

	// Filters the provided input message and places the filtered result into pchOutFilteredText, using legally required filtering and additional filtering based on the context and user settings
	//   eContext is the type of content in the input string
	//   SourceSteamId is the Steam ID that is the source of the input string (e.g. the player with the name, or who said the chat text)
	//   pchInputText is the input string that should be filtered, which can be ASCII or UTF-8
	//   pchOutFilteredText is where the output will be placed, even if no filtering is performed
	//   nByteSizeOutFilteredText is the size (in bytes) of pchOutFilteredText, should be at least strlen(pchInputText)+1
	// Returns the number of CharAacters (not bytes) filtered
	virtual Int32 FilterText(ETextFilteringContext eContext, SteamId_t SourceSteamId, const pStrA pchInputMessage, /* [out] */ pStrA pchFilteredText, Uint32 cchFilteredText) = 0;
	virtual ESteamIPv6ConnectivityState GetIPv6ConnectivityState(ESteamIPv6ConnectivityProtocol eSteamIPv6ConnectivityProtocol) = 0;
	virtual Bool IsSteamRunningOnSteamDeck() = 0;
	virtual Bool ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, Int32 nTextFieldXPosition, Int32 nTextFieldYPosition, Int32 nTextFieldWidth, Int32 nTextFieldHeight) = 0;
	virtual void SetGameLauncherMode(Bool bLauncherMode) = 0;
	virtual Bool DismissFloatingGamepadTextInput() = 0;

} ISteamUtils, *IpSteamUtils;

#define STEAMUTILS_INTERFACE_VERSION "SteamUtils010"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// -----------------------------------------------------------------------------
// Purpose: User Country has Changed
// -----------------------------------------------------------------------------
#define k_iCallbback_IPCountry_t ((Int32)(k_iSteamUtilsCallbacks + 1))
typedef struct _IPCountry_t_ {

	Int32 Unused;

} IPCountry_t, *pIPCountry_t;

#define k_iCallbback_LowBatteryPower_t ((Int32)(k_iSteamUtilsCallbacks + 2))
typedef struct _LowBatteryPower_t_ {

	Uint8 nMinutesBatteryLeft;

} LowBatteryPower_t, *pLowBatteryPower_t;

#define k_iCallbback_SteamAPICallCompleted_t ((Int32)(k_iSteamUtilsCallbacks + 3))
typedef struct _SteamAPICallCompleted_t_ {
	
	SteamAPICall_t hAsyncCall;
	Int32 iCallback;
	Uint32 cbParam;

} SteamAPICallCompleted_t, *pSteamAPICallCompleted_t;

#define k_iCallbback_SteamAPICallCompleted_t ((Int32)(k_iSteamUtilsCallbacks + 3))
typedef struct _SteamShutdown_t_ {

	Int32 Unused;

} SteamShutdown_t, *pSteamShutdown_t;

typedef enum _ECheckFileSignature_ {

	k_ECheckFileSignatureInvalidSignature,
	k_ECheckFileSignatureValidSignature,
	k_ECheckFileSignatureFileNotFound,
	k_ECheckFileSignatureNoSignaturesFoundForThisApp,
	k_ECheckFileSignatureNoSignaturesFoundForThisFile

} ECheckFileSignature, *pECheckFileSignature;

#define k_iCallbback_CheckFileSignature_t ((Int32)(k_iSteamUtilsCallbacks + 5))
typedef struct _CheckFileSignature_t_ {

	ECheckFileSignature eCheckFileSignature;

} CheckFileSignature_t, *pCheckFileSignature_t;

#define k_iCallbback_GamepadTextInputDismissed_t ((Int32)(k_iSteamUtilsCallbacks + 14))
typedef struct _GamepadTextInputDismissed_t_ {
	
	Bool bSubmitted;
	Uint32 cchSubmittedText;
	AppId_t iAppId;

} GamepadTextInputDismissed_t, *pGamepadTextInputDismissed_t;

#define k_iCallbback_AppResumingFromSuspend_t ((Int32)(k_iSteamUtilsCallbacks + 36))
typedef struct _AppResumingFromSuspend_t_ {
	
	Int32 Unused;

} AppResumingFromSuspend_t, *pAppResumingFromSuspend_t;

#define k_iCallbback_FloatingGamepadTextInputDismissed_t ((Int32)(k_iSteamUtilsCallbacks + 38))
typedef struct _FloatingGamepadTextInputDismissed_t_ {

	Int32 Unused;

} FloatingGamepadTextInputDismissed_t, *pFloatingGamepadTextInputDismissed_t;

#define k_iCallbback_FilterTextDictionaryChanged_t ((Int32)(k_iSteamUtilsCallbacks + 39))
typedef struct _FilterTextDictionaryChanged_t_ {
	
	Int32 eLanguage;

} FilterTextDictionaryChanged_t, *pFilterTextDictionaryChanged_t;

#pragma pack(pop)

#endif // _ISTEAMUTILS_
