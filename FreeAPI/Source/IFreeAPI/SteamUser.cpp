// -----------------------------------------------------------------------------
#include "SteamUser.h"
// -----------------------------------------------------------------------------

HSteamUser _SteamUser_::GetHSteamUser() {
	DEBUGBREAK("ISteamUser::GetHSteamUser");

	return k_HSteamUser_LocalUser;

}

Bool _SteamUser_::BLoggedOn() {
	DEBUGBREAK("ISteamUser::BLoggedOn");

	return True;

}

SteamId_t _SteamUser_::GetSteamId() {
	DEBUGBREAK("ISteamUser::GetSteamId");

	return SteamId_t{ k_SteamId_t_LocalUser };

}

Int32 _SteamUser_::InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) {
	DEBUGBREAK("ISteamUser::InitiateGameConnection");

	if (pvAuthBlob != NULL && cbMaxAuthBlob > 0) {
		
		for (Int32 i = 0; i < cbMaxAuthBlob; i++) {
			((pByte)(pvAuthBlob))[i] =
				(Byte)((SteamIdGameServer.SteamId_Uint64 >> ((i % sizeof(SteamId_t)) * 8)) & 0xFF);
		}

		return cbMaxAuthBlob;

	}

	return 0;

}

void _SteamUser_::TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) {
	DEBUGBREAK("ISteamUser::TerminateGameConnection");

	/* Empty Method */

}

void _SteamUser_::TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) {
	DEBUGBREAK("ISteamUser::TrackAppUsageEvent");

	/* Empty Method */

}

Bool _SteamUser_::GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) {
	DEBUGBREAK("ISteamUser::GetUserDataFolder");

	if (pchFolder != NULL && cchFolder > 0) {

		CharA chLocalAppDataFolder[MAX_PATH] = { 0 };
		if (SHGetSpecialFolderPathA(
			NULL, chLocalAppDataFolder, CSIDL_LOCAL_APPDATA, True
		)) {

			if ((SizeOF)(cchFolder) >= StrA_Count(chLocalAppDataFolder) + 1U) {
				StrA_Copy(pchFolder, cchFolder, chLocalAppDataFolder);
				return True;
			}

		}

	}

	return False;

}

void _SteamUser_::StartVoiceRecording() {
	DEBUGBREAK("ISteamUser::StartVoiceRecording");

	/* Empty Method */

}

void _SteamUser_::StopVoiceRecording() {
	DEBUGBREAK("ISteamUser::StopVoiceRecording");

	/* Empty Method */

}

EVoiceResult _SteamUser_::GetCompressedVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) {
	DEBUGBREAK("ISteamUser::GetCompressedVoice");

	return k_EVoiceResultOK;

}


EVoiceResult _SteamUser_::GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) {
	DEBUGBREAK("ISteamUser::GetAvailableVoice");

	return k_EVoiceResultOK;

}

EVoiceResult _SteamUser_::GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated) {
	DEBUGBREAK("ISteamUser::GetVoice");

	return k_EVoiceResultOK;

}

EVoiceResult _SteamUser_::GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) {
	DEBUGBREAK("ISteamUser::GetVoice");

	return k_EVoiceResultOK;

}

EVoiceResult _SteamUser_::DecompressVoice(const pVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten) {
	DEBUGBREAK("ISteamUser::DecompressVoice");

	return k_EVoiceResultOK;

}

EVoiceResult _SteamUser_::DecompressVoice(const pVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) {
	DEBUGBREAK("ISteamUser::DecompressVoice");

	return k_EVoiceResultOK;

}

Uint32 _SteamUser_::GetVoiceOptimalSampleRate() {
	DEBUGBREAK("ISteamUser::GetVoiceOptimalSampleRate");

	return (Uint32)(44100);

}

HAuthTicket _SteamUser_::GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) {
	DEBUGBREAK("ISteamUser::GetAuthSessionTicket");

	return k_HAuthTicket_Invalid;

}

HAuthTicket _SteamUser_::GetAuthTicketForWebApi(pCStrA pchIdentity) {
	DEBUGBREAK("ISteamUser::GetAuthTicketForWebApi");

	return k_HAuthTicket_Invalid;

}

EBeginAuthSessionResult _SteamUser_::BeginAuthSession(const pVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) {
	DEBUGBREAK("ISteamUser::BeginAuthSession");

	return k_EBeginAuthSessionResultOK;

}

void _SteamUser_::EndAuthSession(SteamId_t SteamId) {
	DEBUGBREAK("ISteamUser::EndAuthSession");

	/* Empty Method */

}

void _SteamUser_::CancelAuthTicket(HAuthTicket hAuthTicket) {
	DEBUGBREAK("ISteamUser::CancelAuthTicket");

	/* Empty Method */

}

EUserHasLicenseForAppResult _SteamUser_::UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) {
	DEBUGBREAK("ISteamUser::UserHasLicenseForApp");

	return k_EUserHasLicenseResultHasLicense;

}

Bool _SteamUser_::BIsBehindNAT() {
	DEBUGBREAK("ISteamUser::BIsBehindNAT");

	return True;

}

void _SteamUser_::AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) {
	DEBUGBREAK("ISteamUser::AdvertiseGame");

	/* Empty Method */

}

SteamAPICall_t _SteamUser_::RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) {
	DEBUGBREAK("ISteamUser::RequestEncryptedAppTicket");

	return k_SteamAPICall_Invalid;

}

Bool _SteamUser_::GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) {
	DEBUGBREAK("ISteamUser::GetEncryptedAppTicket");

	if (pvTicket != NULL && cbMaxTicket > 0) {
		if (pcbTicket != NULL) {

			for (Int32 i = 0; i < cbMaxTicket; i++) {
				((pByte)(pvTicket))[i] = (Byte)(i % 256);
			}

			*pcbTicket = cbMaxTicket;
			return True;

		}
	}

	return False;

}

Int32 _SteamUser_::GetGameBadgeLevel(Int32 nSeries, Bool bFoil) {
	DEBUGBREAK("ISteamUser::GetGameBadgeLevel");

	return 0;

}

Int32 _SteamUser_::GetPlayerSteamLevel() {
	DEBUGBREAK("ISteamUser::GetPlayerSteamLevel");

	return Int32_MAX;

}

SteamAPICall_t _SteamUser_::RequestStoreAuthURL(pCStrA pchRedirectURL) {
	DEBUGBREAK("ISteamUser::RequestStoreAuthURL");

	return k_SteamAPICall_Invalid;

}

Bool _SteamUser_::BIsPhoneVerified() {
	DEBUGBREAK("ISteamUser::BIsPhoneVerified");

	return True;

}

Bool _SteamUser_::BIsTwoFactorEnabled() {
	DEBUGBREAK("ISteamUser::BIsTwoFactorEnabled");

	return True;

}

Bool _SteamUser_::BIsPhoneIdentifying() {
	DEBUGBREAK("ISteamUser::BIsPhoneIdentifying");

	return False;

}

Bool _SteamUser_::BIsPhoneRequiringVerification() {
	DEBUGBREAK("ISteamUser::BIsPhoneRequiringVerification");

	return False;

}

SteamAPICall_t _SteamUser_::GetMarketEligibility() {
	DEBUGBREAK("ISteamUser::GetMarketEligibility");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUser_::GetDurationControl() {
	DEBUGBREAK("ISteamUser::GetDurationControl");

	return k_SteamAPICall_Invalid;

}

Bool _SteamUser_::BSetDurationControlOnlineState(EDurationControlOnlineState eDurationControlOnlineState) {
	DEBUGBREAK("ISteamUser::BSetDurationControlOnlineState");

	return True;

}

void _SteamUser_::RefreshSteam2Login() {
	DEBUGBREAK("ISteamUser::RefreshSteam2Login");

	/* Empty Method */

}
