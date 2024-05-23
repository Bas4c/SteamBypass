#ifndef _STEAMUSER_
#define _STEAMUSER_

#include <Shlobj.h>
#include <Shlobj_core.h>
#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamUser.h"
// -----------------------------------------------------------------------------

typedef class _SteamUser_ : public _ISteamUser_ {
public:

	_SteamUser_() = default;
	_SteamUser_(const _SteamUser_&) = delete;
	_SteamUser_& operator=(const _SteamUser_&) = delete;

	HSteamUser GetHSteamUser() override;
	Bool BLoggedOn() override;
	SteamId_t GetSteamId() override;

	/* Parameters:
		 pVoid pvAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
		 Int32 cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
		 SteamId_t SteamIdGameServer - the SteamId of the game server, received from the game server by the client
		 SteamId_t GameId - the Id of the current game. For games without mods, this is just SteamId_t
		 Uint32 nIPServer, Uint16 PortServer - the IP address of the game server
		 Bool bSecure - whether or not the client thinks that the game server is reporting itself as secure
	   Returns the number of bytes written to pvAuthBlob */
	Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) override;
	void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) override;

	void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) override;
	
	/* Get User CSIDL_LOCAL_APPDATA Directotory */
	Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) override;

	void StartVoiceRecording() override;
	void StopVoiceRecording() override;

	/* Read Voice Audio */
	EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) override;
	EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) override;
	/* PCM (16-Bit) Voice Audio */
	EVoiceResult DecompressVoice(const pVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) override;
	/* Usually 48000 or 44100 */
	Uint32 GetVoiceOptimalSampleRate() override;

	HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) override;
	HAuthTicket GetAuthTicketForWebApi(pCStrA pchIdentity) override;

	EBeginAuthSessionResult BeginAuthSession(const pVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) override;
	void EndAuthSession(SteamId_t SteamId) override;
	void CancelAuthTicket(HAuthTicket hAuthTicket) override;

	EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) override;
	Bool BIsBehindNAT() override;
	void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) override;

	SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) override;
	Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) override;

	/* Regular (max level 5) and Foil (max level 1) */
	Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) override;
	Int32 GetPlayerSteamLevel() override;
	SteamAPICall_t RequestStoreAuthURL(pCStrA pchRedirectURL) override;

	Bool BIsPhoneVerified() override;
	Bool BIsTwoFactorEnabled() override;
	Bool BIsPhoneIdentifying() override;
	Bool BIsPhoneRequiringVerification() override;

	SteamAPICall_t GetMarketEligibility() override;
	SteamAPICall_t GetDurationControl() override;
	Bool BSetDurationControlOnlineState(EDurationControlOnlineState eDurationControlOnlineState) override;

	~_SteamUser_() = default;

} SteamUser, *pSteamUser;

#endif // !_STEAMUSER_
