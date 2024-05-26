#ifndef _ISTEAMUSER_
#define _ISTEAMUSER_

#include "..\..\FreeAPI.Typedef.h"

typedef class _ISteamUser009_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual void RefreshSteam2Login() = 0;

} ISteamUser009, *IpSteamUser009;

typedef class _ISteamUser010_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;

} ISteamUser010, *IpSteamUser010;

typedef class _ISteamUser011_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetCompressedVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten) = 0;

} ISteamUser011, *IpSteamUser011;

typedef class _ISteamUser012_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetCompressedVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten) = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;

} ISteamUser012, *IpSteamUser012;

typedef class _ISteamUser013_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten) = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;

} ISteamUser013, *IpSteamUser013;

typedef class _ISteamUser014_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten) = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;

} ISteamUser014, *IpSteamUser014;

typedef class _ISteamUser015_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;

} ISteamUser015, *IpSteamUser015;

typedef class _ISteamUser016_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;

} ISteamUser016, *IpSteamUser016;

typedef class _ISteamUser017_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) = 0;
	virtual Int32 GetPlayerSteamLevel() = 0;

} ISteamUser017, *IpSteamUser017;

typedef class _ISteamUser018_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) = 0;
	virtual Int32 GetPlayerSteamLevel() = 0;
	virtual SteamAPICall_t RequestStoreAuthURL(pCStrA pchRedirectURL) = 0;

} ISteamUser018, *IpSteamUser018;

typedef class _ISteamUser019_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) = 0;
	virtual Int32 GetPlayerSteamLevel() = 0;
	virtual SteamAPICall_t RequestStoreAuthURL(pCStrA pchRedirectURL) = 0;
	virtual Bool BIsPhoneVerified() = 0;
	virtual Bool BIsTwoFactorEnabled() = 0;
	virtual Bool BIsPhoneIdentifying() = 0;
	virtual Bool BIsPhoneRequiringVerification() = 0;

} ISteamUser019, *IpSteamUser019;

typedef class _ISteamUser020_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) = 0;
	virtual Int32 GetPlayerSteamLevel() = 0;
	virtual SteamAPICall_t RequestStoreAuthURL(pCStrA pchRedirectURL) = 0;
	virtual Bool BIsPhoneVerified() = 0;
	virtual Bool BIsTwoFactorEnabled() = 0;
	virtual Bool BIsPhoneIdentifying() = 0;
	virtual Bool BIsPhoneRequiringVerification() = 0;
	virtual SteamAPICall_t GetMarketEligibility() = 0;
	virtual SteamAPICall_t GetDurationControl() = 0;

} ISteamUser020, *IpSteamUser020;

typedef class _ISteamUser021_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) = 0;
	virtual Int32 GetPlayerSteamLevel() = 0;
	virtual SteamAPICall_t RequestStoreAuthURL(pCStrA pchRedirectURL) = 0;
	virtual Bool BIsPhoneVerified() = 0;
	virtual Bool BIsTwoFactorEnabled() = 0;
	virtual Bool BIsPhoneIdentifying() = 0;
	virtual Bool BIsPhoneRequiringVerification() = 0;
	virtual SteamAPICall_t GetMarketEligibility() = 0;
	virtual SteamAPICall_t GetDurationControl() = 0;
	virtual Bool BSetDurationControlOnlineState(EDurationControlOnlineState eDurationControlOnlineState) = 0;

} ISteamUser021, *IpSteamUser021;

typedef class _ISteamUser022_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;
	virtual Int32 InitiateGameConnection(pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;
	virtual Bool GetUserDataFolder(pStrA pchFolder, Int32 cchFolder) = 0;
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual EVoiceResult GetAvailableVoice(pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;
	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) = 0;
	virtual Int32 GetPlayerSteamLevel() = 0;
	virtual SteamAPICall_t RequestStoreAuthURL(pCStrA pchRedirectURL) = 0;
	virtual Bool BIsPhoneVerified() = 0;
	virtual Bool BIsTwoFactorEnabled() = 0;
	virtual Bool BIsPhoneIdentifying() = 0;
	virtual Bool BIsPhoneRequiringVerification() = 0;
	virtual SteamAPICall_t GetMarketEligibility() = 0;
	virtual SteamAPICall_t GetDurationControl() = 0;
	virtual Bool BSetDurationControlOnlineState(EDurationControlOnlineState eDurationControlOnlineState) = 0;

} ISteamUser022, *IpSteamUser022;

// -----------------------------------------------------------------------------
// Purpose: Functions for accessing and manipulating a steam account
//  associated with one client instance
// -----------------------------------------------------------------------------
typedef class _ISteamUser_ {
public:

	virtual HSteamUser GetHSteamUser() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual SteamId_t GetSteamId() = 0;

	/* Parameters:
	     pVoid pvAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
	     Int32 cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
	     SteamId_t SteamIdGameServer - the SteamId of the game server, received from the game server by the client
	     SteamId_t GameId - the Id of the current game. For games without mods, this is just SteamId_t
	     Uint32 nIPServer, Uint16 PortServer - the IP address of the game server
	     Bool bSecure - whether or not the client thinks that the game server is reporting itself as secure
	   Returns the number of bytes written to pvAuthBlob */
	virtual Int32 InitiateGameConnection(/* [out] */ pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) = 0;
	virtual void TerminateGameConnection(Uint32 nIPServer, Uint16 PortServer) = 0;
	
	virtual void TrackAppUsageEvent(SteamId_t GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) = 0;

	/* Get User CSIDL_LOCAL_APPDATA Directotory */
	virtual Bool GetUserDataFolder(/* [out] */ pStrA pchFolder, Int32 cchFolder) = 0;
	
	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;

	/* Read Voice Audio */
	virtual EVoiceResult GetAvailableVoice(/* [out] */ pUint32 pcbCompressed, /* [out] */ pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	virtual EVoiceResult GetVoice(Bool bWantCompressed, /* [out] */ pVoid pvDest, Uint32 cbDestSize, /* [out] */ pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, /* [out] */ pVoid pUncompressedDest_Deprecated, /* [out] */ Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) = 0;
	/* PCM (16-Bit) Voice Audio */
	virtual EVoiceResult DecompressVoice(pCVoid pCompressed, Uint32 cbCompressed, /* [out] */ pVoid pvDest, Uint32 cbDestSize, /* [out] */ pUint32 nBytesWritten, Uint32 nDesiredSampleRate) = 0;
	/* Usually 48000 or 44100 */
	virtual Uint32 GetVoiceOptimalSampleRate() = 0;

	virtual HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, /* [out] */ pUint32 pcbTicket, /* [opt] */ const pSteamNetworkingIdentity pSteamNetworkingIdentity) = 0;
	virtual HAuthTicket GetAuthTicketForWebApi(pCStrA pchIdentity) = 0;

	virtual EBeginAuthSessionResult BeginAuthSession(pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;

	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t iAppId) = 0;
	virtual Bool BIsBehindNAT() = 0;
	virtual void AdvertiseGame(SteamId_t SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) = 0;

	virtual SteamAPICall_t RequestEncryptedAppTicket(pVoid pvDataToInclude, Int32 cbDataToInclude) = 0;
	virtual Bool GetEncryptedAppTicket(/* [out] */ pVoid pvTicket, Int32 cbMaxTicket, /* [out] */ pUint32 pcbTicket) = 0;

	/* Regular (max level 5) and Foil (max level 1) */
	virtual Int32 GetGameBadgeLevel(Int32 nSeries, Bool bFoil) = 0;
	virtual Int32 GetPlayerSteamLevel() = 0;

	virtual SteamAPICall_t RequestStoreAuthURL(pCStrA pchRedirectURL) = 0;
	virtual Bool BIsPhoneVerified() = 0;
	virtual Bool BIsTwoFactorEnabled() = 0;
	virtual Bool BIsPhoneIdentifying() = 0;
	virtual Bool BIsPhoneRequiringVerification() = 0;

	virtual SteamAPICall_t GetMarketEligibility() = 0;
	virtual SteamAPICall_t GetDurationControl() = 0;
	virtual Bool BSetDurationControlOnlineState(EDurationControlOnlineState eDurationControlOnlineState) = 0;

} ISteamUser, *IpSteamUser;

#define STEAMUSER_INTERFACE_VERSION "SteamUser023"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// -----------------------------------------------------------------------------
// Purpose: Called when an authenticated connection to the Steam back-end has been established.
//  This means the Steam client now has a working connection to the Steam servers.
//  Usually this will have occurred before the game has launched, and should
//   only be seen if the user has dropped connection due to a networking issue
//   or a Steam server update.
// -----------------------------------------------------------------------------
#define k_iCallbback_SteamServersConnected_t_ ((Int32)(k_iSteamUserCallbacks + 1))
typedef struct _SteamServersConnected_t_ {

	Int32 Unused;

} SteamServersConnected_t, *pSteamServersConnected_t;

// -----------------------------------------------------------------------------
// Purpose: Called when a connection attempt has failed
//  this will occur periodically if the Steam client is not connected, 
//  and has failed in it's retry to establish a connection
// -----------------------------------------------------------------------------
#define k_iCallbback_SteamServerConnectFailure_t_ ((Int32)(k_iSteamUserCallbacks + 2))
typedef struct _SteamServerConnectFailure_t_ {

	EResult eResult;
	Bool bStillRetrying;

} SteamServerConnectFailure_t, *pSteamServerConnectFailure_t;

// -----------------------------------------------------------------------------
// Purpose: Called if the client has lost connection to the Steam servers
//  real-time services will be disabled until a matching SteamServersConnected_t has been posted
// -----------------------------------------------------------------------------
#define k_iCallbback_SteamServersDisconnected_t_ ((Int32)(k_iSteamUserCallbacks + 3))
typedef struct _SteamServersDisconnected_t_ {

	EResult eResult;

} SteamServersDisconnected_t, *pSteamServersDisconnected_t;

// -----------------------------------------------------------------------------
// Purpose: Sent by the Steam server to the client telling it to disconnect from the specified game server,
//  which it may be in the process of or already connected to.
//  The game client should immediately disconnect upon receiving this message.
//  This can usually occur if the user doesn't have rights to play on the game server.
// -----------------------------------------------------------------------------
#define k_iCallbback_ClientGameServerDeny_t_ ((Int32)(k_iSteamUserCallbacks + 13))
typedef struct _ClientGameServerDeny_t_ {

	Uint32 iAppId;
	Uint32 GameServerIP;
	Uint16 GameServerPort;
	Uint16 bSecure;
	Uint32 Reason;

} ClientGameServerDeny_t, *pClientGameServerDeny_t;

// -----------------------------------------------------------------------------
// Purpose: Called when the callback system for this client is in an error state (and has flushed pending callbacks)
//  When getting this message the client should disconnect from Steam, reset any stored Steam state and reconnect.
//  This usually occurs in the rare event the Steam client has some kind of fatal error.
// -----------------------------------------------------------------------------
#define k_iCallbback_IPCFailure_t_ ((Int32)(k_iSteamUserCallbacks + 17))
#define k_iCallbback_IPCFailure_t_k_EFailureFlushedCallbackQueue ((Uint8)(0x00))
#define k_iCallbback_IPCFailure_t_k_EFailurePipeFail ((Uint8)(0x01))
typedef struct _IPCFailure_t_ {

	Uint8 eFailureType;

} IPCFailure_t, *pIPCFailure_t;

// -----------------------------------------------------------------------------
// Purpose: Signaled whenever licenses change
// -----------------------------------------------------------------------------
#define k_iCallbback_LicensesUpdated_t_ ((Int32)(k_iSteamUserCallbacks + 25))
typedef struct _LicensesUpdated_t_ {

	Int32 Unused;

} LicensesUpdated_t, *pLicensesUpdated_t;

// -----------------------------------------------------------------------------
// BeginAuthSession Callback
// -----------------------------------------------------------------------------
#define k_iCallbback_ValidateAuthTicketResponse_t_ ((Int32)(k_iSteamUserCallbacks + 43))
typedef struct _ValidateAuthTicketResponse_t_ {

	SteamId_t SteamId;
	EAuthSessionResponse eAuthSessionResponse;
	SteamId_t OwnerSteamId;

} ValidateAuthTicketResponse_t, *pValidateAuthTicketResponse_t;

// -----------------------------------------------------------------------------
// Purpose: Called when a user has responded to a microtransaction authorization request
// -----------------------------------------------------------------------------
#define k_iCallbback_MicroTxnAuthorizationResponse_t_ ((Int32)(k_iSteamUserCallbacks + 52))
typedef struct _MicroTxnAuthorizationResponse_t_ {

	Uint32 iAppId;
	Uint64 OrderId;
	Uint8 bAuthorized;

} MicroTxnAuthorizationResponse_t, *pMicroTxnAuthorizationResponse_t;

// -----------------------------------------------------------------------------
// Purpose: RequestEncryptedAppTicket Result
// -----------------------------------------------------------------------------
#define k_iCallbback_EncryptedAppTicketResponse_t_ ((Int32)(k_iSteamUserCallbacks + 54))
typedef struct _EncryptedAppTicketResponse_t_ {

	EResult eResult;

} EncryptedAppTicketResponse_t, *pEncryptedAppTicketResponse_t;

// -----------------------------------------------------------------------------
// callback for GetAuthSessionTicket
// -----------------------------------------------------------------------------
#define k_iCallbback_GetAuthSessionTicketResponse_t_ ((Int32)(k_iSteamUserCallbacks + 63))
typedef struct _GetAuthSessionTicketResponse_t_ {

	HAuthTicket hAuthTicket;
	EResult eResult;

} GetAuthSessionTicketResponse_t, *pGetAuthSessionTicketResponse_t;

#define k_iCallbback_GameWebCallback_t_ ((Int32)(k_iSteamUserCallbacks + 64))
typedef struct _GameWebCallback_t_ {

	CharA chURL[256];

} GameWebCallback_t, *pGameWebCallback_t;

// -----------------------------------------------------------------------------
// Purpose: Response to ISteamUser::RequestStoreAuthURL
// -----------------------------------------------------------------------------
#define k_iCallbback_StoreAuthURLResponse_t_ ((Int32)(k_iSteamUserCallbacks + 65))
typedef struct _StoreAuthURLResponse_t_ {

	CharA chURL[512];

} StoreAuthURLResponse_t, *pStoreAuthURLResponse_t;

// -----------------------------------------------------------------------------
// Purpose: Rresponse to ISteamUser::GetMarketEligibility
// -----------------------------------------------------------------------------
#define k_iCallbback_MarketEligibilityResponse_t_ ((Int32)(k_iSteamUserCallbacks + 66))
typedef struct _MarketEligibilityResponse_t_ {

	Bool bAllowed;
	EMarketNotAllowedReasonFlags eNotAllowedReason;
	RTime32 AllowedAtTime;
	Int32 cdaySteamGuardRequiredDays;
	Int32 cdayNewDeviceCooldown;

} MarketEligibilityResponse_t, *pMarketEligibilityResponse_t;

#define k_iCallbback_DurationControl_t_ ((Int32)(k_iSteamUserCallbacks + 67))
typedef struct _DurationControl_t_ {


	EResult	eResult;
	AppId_t iAppId;
	Bool	bApplicable;
	Int32	csecsLast5h;
	EDurationControlProgress eDurationControlProgress;
	EDurationControlNotification eDurationControlNotification;
	Int32	csecsToday;
	Int32	csecsRemaining;

} DurationControl_t, *pDurationControl_t;

// -----------------------------------------------------------------------------
// GetTicketForWebApi Callback
// -----------------------------------------------------------------------------
#define k_iCallbback_GetTicketForWebApiResponse_t_ ((Int32)(k_iSteamUserCallbacks + 68))
typedef struct _GetTicketForWebApiResponse_t_ {

	HAuthTicket hAuthTicket;
	EResult eResult;
	Int32 cbTicket;
	Uint8 rgTicket[2560];

} GetTicketForWebApiResponse_t, *pGetTicketForWebApiResponse_t;

#pragma pack(pop)

#endif // _ISTEAMUSER_
