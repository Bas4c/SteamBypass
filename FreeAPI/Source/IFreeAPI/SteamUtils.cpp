// -----------------------------------------------------------------------------
#include "SteamUtils.h"
// -----------------------------------------------------------------------------

_SteamUtils_::_SteamUtils_() {

	LANGID lcid = GetUserDefaultUILanguage();
	GetLocaleInfoA(lcid, LOCALE_SISO3166CTRYNAME, this->chCountry, LOCALE_NAME_MAX_LENGTH);

}

Uint32 _SteamUtils_::GetSecondsSinceAppActive() {
	DEBUGBREAK("ISteamUtils::GetSecondsSinceAppActive");

	return 0U;

}

Uint32 _SteamUtils_::GetSecondsSinceComputerActive() {
	DEBUGBREAK("ISteamUtils::GetSecondsSinceComputerActive");

	return 0U;

}

EUniverse _SteamUtils_::GetConnectedUniverse() {
	DEBUGBREAK("ISteamUtils::GetConnectedUniverse");

	return k_EUniverseInternal;

}

Uint32 _SteamUtils_::GetServerRealTime() {
	DEBUGBREAK("ISteamUtils::GetServerRealTime");

	/* January 1, 1970 (start of Unix epoch) in "ticks" */
	const Int64 UnixTimeStart = 0x019DB1DED53E8000;

	Uint64 UTCTime = 0U;
	GetSystemTimeAsFileTime((LPFILETIME)(&UTCTime));
	return (Uint32)((UTCTime - UnixTimeStart) / 10000000);

}

pCStrA _SteamUtils_::GetIPCountry() {
	DEBUGBREAK("ISteamUtils::GetIPCountry");

	return this->chCountry;

}

Bool _SteamUtils_::GetImageSize(Int32 iImage, pUint32 pCx, pUint32 pCy) {
	DEBUGBREAK("ISteamUtils::GetImageSize");

	return False;

}

Bool _SteamUtils_::GetImageRGBA(Int32 iImage, pUint8 pbDest, Int32 nDestSize) {
	DEBUGBREAK("ISteamUtils::GetImageRGBA");

	return False;

}

Bool _SteamUtils_::GetCSERIPPort(pUint32 nIP, pUint16 Port) {
	DEBUGBREAK("ISteamUtils::GetCSERIPPort");

	return False;

}

Uint8 _SteamUtils_::GetCurrentBatteryPower() {
	DEBUGBREAK("ISteamUtils::GetCurrentBatteryPower");

	return 255;

}

AppId_t _SteamUtils_::GetAppId() {
	DEBUGBREAK("ISteamUtils::GetAppId");

	return (AppId_t)(GetGameAppId());

}

void _SteamUtils_::SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition) {
	DEBUGBREAK("ISteamUtils::SetOverlayNotificationPosition");

	/* Empty Method */

}

Bool _SteamUtils_::IsAPICallCompleted(SteamAPICall_t hSteamAPICall, pBool pbFailed) {
	DEBUGBREAK("ISteamUtils::IsAPICallCompleted");

	return False;

}

ESteamAPICallFailure _SteamUtils_::GetAPICallFailureReason(SteamAPICall_t hSteamAPICall) {
	DEBUGBREAK("ISteamUtils::GetAPICallFailureReason");

	return k_ESteamAPICallFailureNone;

}

Bool _SteamUtils_::GetAPICallResult(SteamAPICall_t hSteamAPICall, pVoid pvCallback, Int32 cbCallback, Int32 iCallbackExpected, pBool pbFailed) {
	DEBUGBREAK("ISteamUtils::GetAPICallResult");

	return False;

}

void _SteamUtils_::RunFrame() {
	DEBUGBREAK("ISteamUtils::RunFrame");

	/* Empty Method */

}

Uint32 _SteamUtils_::GetIPCCallCount() {
	DEBUGBREAK("ISteamUtils::GetIPCCallCount");

	return 0U;

}

void _SteamUtils_::SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) {
	DEBUGBREAK("ISteamUtils::SetWarningMessageHook");

	/* Empty Method */

}

Bool _SteamUtils_::IsOverlayEnabled() {
	DEBUGBREAK("ISteamUtils::IsOverlayEnabled");

	return False;

}

Bool _SteamUtils_::BOverlayNeedsPresent() {
	DEBUGBREAK("ISteamUtils::BOverlayNeedsPresent");

	return False;

}

SteamAPICall_t _SteamUtils_::CheckFileSignature(pCStrA pchFileName) {
	DEBUGBREAK("ISteamUtils::CheckFileSignature");

	return k_SteamAPICall_Invalid;

}

#ifdef _PS3
void _SteamUtils_::PostPS3SysutilCallback(Uint64 Status, Uint64 Arg, pVoid pvUserData) {
	DEBUGBREAK("ISteamUtils::PostPS3SysutilCallback");

	/* Empyt Method */

}

Bool _SteamUtils_::BIsReadyToShutdown() {
	DEBUGBREAK("ISteamUtils::BIsReadyToShutdown");

	return True;

}

Bool _SteamUtils_::BIsPSNOnline() {
	DEBUGBREAK("ISteamUtils::BIsPSNOnline");

	return True;

}

void _SteamUtils_::SetPSNGameBootInviteStrings(pCStrA pchSubject, pCStrA pchBody) {
	DEBUGBREAK("ISteamUtils::SetPSNGameBootInviteStrings");

	/* Empty Method */

}
#endif

Bool _SteamUtils_::ShowGamepadTextInput(EGamepadTextInputMode eGamepadTextInputMode, EGamepadTextInputLineMode eGamepadTextInputLineMode, pCStrA pchDescription, Uint32 cchDescription, pCStrA pchExistingText) {
	DEBUGBREAK("ISteamUtils::ShowGamepadTextInput");

	return False;

}

Uint32 _SteamUtils_::GetEnteredGamepadTextLength() {
	DEBUGBREAK("ISteamUtils::GetEnteredGamepadTextLength");

	return 0U;

}

Bool _SteamUtils_::GetEnteredGamepadTextInput(pStrA pchText, Uint32 cchText) {
	DEBUGBREAK("ISteamUtils::GetEnteredGamepadTextInput");

	return False;

}

pCStrA _SteamUtils_::GetSteamUILanguage() {
	DEBUGBREAK("ISteamUtils::GetSteamUILanguage");

	return (pCStrA)(g_chLanguage);

}

Bool _SteamUtils_::IsSteamRunningInVR() {
	DEBUGBREAK("ISteamUtils::IsSteamRunningInVR");

	return False;

}

void _SteamUtils_::SetOverlayNotificationInset(Int32 nHorizontalInset, Int32 nVerticalInset) {
	DEBUGBREAK("ISteamUtils::SetOverlayNotificationInset");

	/* Empty Method */

}

Bool _SteamUtils_::IsSteamInBigPictureMode() {
	DEBUGBREAK("ISteamUtils::IsSteamInBigPictureMode");

	return False;

}

void _SteamUtils_::StartVRDashboard() {
	DEBUGBREAK("ISteamUtils::StartVRDashboard");

	/* Empty Method */

}

Bool _SteamUtils_::IsVRHeadsetStreamingEnabled() {
	DEBUGBREAK("ISteamUtils::IsVRHeadsetStreamingEnabled");

	return False;

}

void _SteamUtils_::SetVRHeadsetStreamingEnabled(Bool bEnabled) {
	DEBUGBREAK("ISteamUtils::SetVRHeadsetStreamingEnabled");

	/* Empty Method */

}

Bool _SteamUtils_::IsSteamChinaLauncher() {
	DEBUGBREAK("ISteamUtils::IsSteamChinaLauncher");

	return False;

}

Bool _SteamUtils_::InitFilterText(Uint32 nFilterOptions) {
	DEBUGBREAK("ISteamUtils::InitFilterText");

	return False;

}

Int32 _SteamUtils_::FilterText(ETextFilteringContext eContext, SteamId_t SourceSteamId, pCStrA pchInputMessage, pStrA pchFilteredText, Uint32 cchFilteredText) {
	DEBUGBREAK("ISteamUtils::FilterText");

	return 0;

}

ESteamIPv6ConnectivityState _SteamUtils_::GetIPv6ConnectivityState(ESteamIPv6ConnectivityProtocol eSteamIPv6ConnectivityProtocol) {
	DEBUGBREAK("ISteamUtils::GetIPv6ConnectivityState");

	return k_ESteamIPv6ConnectivityState_Unknown;

}

Bool _SteamUtils_::IsSteamRunningOnSteamDeck() {
	DEBUGBREAK("ISteamUtils::IsSteamRunningOnSteamDeck");

	return False;

}

Bool _SteamUtils_::ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, Int32 nTextFieldXPosition, Int32 nTextFieldYPosition, Int32 nTextFieldWidth, Int32 nTextFieldHeight) {
	DEBUGBREAK("ISteamUtils::ShowFloatingGamepadTextInput");

	return False;

}

void _SteamUtils_::SetGameLauncherMode(Bool bLauncherMode) {
	DEBUGBREAK("ISteamUtils::SetGameLauncherMode");

	/* Empty Method */

}

Bool _SteamUtils_::DismissFloatingGamepadTextInput() {
	DEBUGBREAK("ISteamUtils::DismissFloatingGamepadTextInput");

	return False;

}
