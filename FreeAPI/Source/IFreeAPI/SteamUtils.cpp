// -----------------------------------------------------------------------------
#include "SteamUtils.h"
// -----------------------------------------------------------------------------

_SteamUtils_::_SteamUtils_() {

	this->chCountry[0] = '\0';

	LANGID lcid = GetUserDefaultUILanguage();
	GetLocaleInfoA(lcid, LOCALE_SISO3166CTRYNAME, this->chCountry, LOCALE_NAME_MAX_LENGTH);

}

Uint32 _SteamUtils_::GetSecondsSinceAppActive() {

	return 0U;

}

Uint32 _SteamUtils_::GetSecondsSinceComputerActive() {

	return 0U;

}

EUniverse _SteamUtils_::GetConnectedUniverse() {

	return k_EUniverseInternal;

}

Uint32 _SteamUtils_::GetServerRealTime() {

	/* January 1, 1970 (start of Unix epoch) in "ticks" */
	const Int64 UnixTimeStart = 0x019DB1DED53E8000;

	Uint64 UTCTime = 0U;
	GetSystemTimeAsFileTime((LPFILETIME)(&UTCTime));
	return (Uint32)((UTCTime - UnixTimeStart) / 10000000);

}

pCStrA _SteamUtils_::GetIPCountry() {

	return this->chCountry;

}

Bool _SteamUtils_::GetImageSize(Int32 iImage, pUint32 pCx, pUint32 pCy) {

	return False;

}

Bool _SteamUtils_::GetImageRGBA(Int32 iImage, pUint8 pbDest, Int32 nDestSize) {

	return False;

}

Bool _SteamUtils_::GetCSERIPPort(pUint32 nIP, pUint16 Port) {

	return False;

}

Uint8 _SteamUtils_::GetCurrentBatteryPower() {

	return 255;

}

AppId_t _SteamUtils_::GetAppId() {

	return (AppId_t)(GetGameAppId());

}

void _SteamUtils_::SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition) {

	/* Empty Method */

}

Bool _SteamUtils_::IsAPICallCompleted(SteamAPICall_t hSteamAPICall, pBool pbFailed) {

	return False;

}

ESteamAPICallFailure _SteamUtils_::GetAPICallFailureReason(SteamAPICall_t hSteamAPICall) {

	return k_ESteamAPICallFailureNone;

}

Bool _SteamUtils_::GetAPICallResult(SteamAPICall_t hSteamAPICall, pVoid pvCallback, Int32 cbCallback, Int32 iCallbackExpected, pBool pbFailed) {

	return False;

}

void _SteamUtils_::RunFrame() {

	/* Empty Method */

}

Uint32 _SteamUtils_::GetIPCCallCount() {

	return 0U;

}

void _SteamUtils_::SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) {

	/* Empty Method */

}

Bool _SteamUtils_::IsOverlayEnabled() {

	return False;

}

Bool _SteamUtils_::BOverlayNeedsPresent() {

	return False;

}

SteamAPICall_t _SteamUtils_::CheckFileSignature(pCStrA pchFileName) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamUtils_::ShowGamepadTextInput(EGamepadTextInputMode eGamepadTextInputMode, EGamepadTextInputLineMode eGamepadTextInputLineMode, pCStrA pchDescription, Uint32 cchDescription, pCStrA pchExistingText) {

	return False;

}

Uint32 _SteamUtils_::GetEnteredGamepadTextLength() {

	return 0U;

}

Bool _SteamUtils_::GetEnteredGamepadTextInput(pStrA pchText, Uint32 cchText) {

	return False;

}

pCStrA _SteamUtils_::GetSteamUILanguage() {

	return GetUserUILanguageA();

}

Bool _SteamUtils_::IsSteamRunningInVR() {

	return False;

}

void _SteamUtils_::SetOverlayNotificationInset(Int32 nHorizontalInset, Int32 nVerticalInset) {

	/* Empty Method */

}

Bool _SteamUtils_::IsSteamInBigPictureMode() {

	return False;

}

void _SteamUtils_::StartVRDashboard() {

	/* Empty Method */

}

Bool _SteamUtils_::IsVRHeadsetStreamingEnabled() {

	return False;

}

void _SteamUtils_::SetVRHeadsetStreamingEnabled(Bool bEnabled) {

	/* Empty Method */

}

Bool _SteamUtils_::IsSteamChinaLauncher() {

	return False;

}

Bool _SteamUtils_::InitFilterText(Uint32 nFilterOptions) {

	return False;

}

Int32 _SteamUtils_::FilterText(ETextFilteringContext eContext, SteamId_t SourceSteamId, pCStrA pchInputMessage, pStrA pchFilteredText, Uint32 cchFilteredText) {

	return 0;

}

ESteamIPv6ConnectivityState _SteamUtils_::GetIPv6ConnectivityState(ESteamIPv6ConnectivityProtocol eSteamIPv6ConnectivityProtocol) {

	return k_ESteamIPv6ConnectivityState_Unknown;

}

Bool _SteamUtils_::IsSteamRunningOnSteamDeck() {

	return False;

}

Bool _SteamUtils_::ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, Int32 nTextFieldXPosition, Int32 nTextFieldYPosition, Int32 nTextFieldWidth, Int32 nTextFieldHeight) {

	return False;

}

void _SteamUtils_::SetGameLauncherMode(Bool bLauncherMode) {

	/* Empty Method */

}

Bool _SteamUtils_::DismissFloatingGamepadTextInput() {

	return False;

}
