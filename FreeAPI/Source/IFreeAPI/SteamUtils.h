#ifndef _STEAMUTILS_
#define _STEAMUTILS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamUtils.h"
// -----------------------------------------------------------------------------

typedef class _SteamUtils_ : public _ISteamUtils002_,
 public _ISteamUtils003_, public _ISteamUtils004_,
 public _ISteamUtils005_, public _ISteamUtils006_,
 public _ISteamUtils007_, public _ISteamUtils008_,
 public _ISteamUtils009_, public _ISteamUtils_ {
public:

	_SteamUtils_();
	_SteamUtils_(const _SteamUtils_&) = delete;
	_SteamUtils_& operator=(const _SteamUtils_&) = delete;

	Uint32 GetSecondsSinceAppActive() override;
	Uint32 GetSecondsSinceComputerActive() override;
	EUniverse GetConnectedUniverse() override;

	/* Number of seconds since January 1, 1970, (Unix Time) */
	Uint32 GetServerRealTime() override;

	/* Returns User Country Code: "UK", "US", ... */
	pCStrA GetIPCountry() override;

	Bool GetImageSize(Int32 iImage, pUint32 pCx, pUint32 pCy) override;

	/* ImageData size should be (4 * height * width * sizeof(CharA)): RGBA */
	Bool GetImageRGBA(Int32 iImage, pUint8 pbDest, Int32 nDestSize) override;
	Bool GetCSERIPPort(pUint32 nIP, pUint16 Port) override;
	Uint8 GetCurrentBatteryPower() override;

	/* Returns Current Process AppId */
	AppId_t GetAppId() override;
	void SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition) override;

	Bool IsAPICallCompleted(SteamAPICall_t hSteamAPICall, pBool pbFailed) override;
	ESteamAPICallFailure GetAPICallFailureReason(SteamAPICall_t hSteamAPICall) override;
	Bool GetAPICallResult(SteamAPICall_t hSteamAPICall, pVoid pvCallback, Int32 cbCallback, Int32 iCallbackExpected, pBool pbFailed) override;

	/* Applications should use SteamAPI_RunCallbacks() instead */
	void RunFrame() override;
	Uint32 GetIPCCallCount() override;

	/* API warning handling
		Int32 is severity; 0: msg, 1: warning
		pCStrA is text of the message
		callbacks will occur directly after the API function is called that generated the warning or message. */
	void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) override;
	Bool IsOverlayEnabled() override;

	/* Normally this call is unneeded if your game has a constantly running frame loop that calls the
		D3D Present API, or OGL SwapBuffers API every frame. */
	Bool BOverlayNeedsPresent() override;

	/* Asynchronous call to check if an executable file has been signed using the public key set on the signing tab
	   of the partner site, for example to refuse to load modified executable files.
	   The result is returned in CheckFileSignature_t.
		k_ECheckFileSignatureNoSignaturesFoundForThisApp - This app has not been configured on the signing tab of the partner site to enable this function.
		k_ECheckFileSignatureNoSignaturesFoundForThisFile - This file is not listed on the signing tab for the partner site.
		k_ECheckFileSignatureFileNotFound - The file does not exist on disk.
		k_ECheckFileSignatureInvalidSignature - The file exists, and the signing tab has been set for this file, but the file is either not signed or the signature does not match.
		k_ECheckFileSignatureValidSignature - The file is signed and the signature is valid. */
	SteamAPICall_t CheckFileSignature(pCStrA pchFileName) override;

	#ifdef _PS3
	void PostPS3SysutilCallback(Uint64 Status, Uint64 Arg, pVoid pvUserData) override;
	Bool BIsReadyToShutdown() override;
	Bool BIsPSNOnline() override;
	void SetPSNGameBootInviteStrings(pCStrA pchSubject, pCStrA pchBody) override;
	#endif

	Bool ShowGamepadTextInput(EGamepadTextInputMode eGamepadTextInputMode, EGamepadTextInputLineMode eGamepadTextInputLineMode, pCStrA pchDescription, Uint32 cchDescription, pCStrA pchExistingText) override;
	Uint32 GetEnteredGamepadTextLength() override;
	Bool GetEnteredGamepadTextInput(pStrA pchText, Uint32 cchText) override;

	pCStrA GetSteamUILanguage() override;
	Bool IsSteamRunningInVR() override;
	void SetOverlayNotificationInset(Int32 nHorizontalInset, Int32 nVerticalInset) override;
	Bool IsSteamInBigPictureMode() override;
	void StartVRDashboard() override;
	Bool IsVRHeadsetStreamingEnabled() override;
	void SetVRHeadsetStreamingEnabled(Bool bEnabled) override;
	Bool IsSteamChinaLauncher() override;
	Bool InitFilterText(Uint32 nFilterOptions) override;

	// Filters the provided input message and places the filtered result into pchOutFilteredText, using legally required filtering and additional filtering based on the context and user settings
	//   eContext is the type of content in the input string
	//   SourceSteamId is the Steam ID that is the source of the input string (e.g. the player with the name, or who said the chat text)
	//   pchInputText is the input string that should be filtered, which can be ASCII or UTF-8
	//   pchOutFilteredText is where the output will be placed, even if no filtering is performed
	//   nByteSizeOutFilteredText is the size (in bytes) of pchOutFilteredText, should be at least strlen(pchInputText)+1
	// Returns the number of CharAacters (not bytes) filtered
	Int32 FilterText(ETextFilteringContext eContext, SteamId_t SourceSteamId, pCStrA pchInputMessage, pStrA pchFilteredText, Uint32 cchFilteredText) override;
	ESteamIPv6ConnectivityState GetIPv6ConnectivityState(ESteamIPv6ConnectivityProtocol eSteamIPv6ConnectivityProtocol) override;
	Bool IsSteamRunningOnSteamDeck() override;
	Bool ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, Int32 nTextFieldXPosition, Int32 nTextFieldYPosition, Int32 nTextFieldWidth, Int32 nTextFieldHeight) override;
	void SetGameLauncherMode(Bool bLauncherMode) override;
	Bool DismissFloatingGamepadTextInput() override;

	~_SteamUtils_() = default;

private:

	CharA chCountry[LOCALE_NAME_MAX_LENGTH];

} SteamUtils, *pSteamUtils;

#endif // !_STEAMUTILS_
