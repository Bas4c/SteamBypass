#ifndef _ISTEAMGAMESERVER_
#define _ISTEAMGAMESERVER_

#include "..\..\FreeAPI.Typedef.h"

typedef class _ISteamGameServer004_ {
public:

	virtual void LogOn() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual Bool BSetServerType(Uint32 nServerFlags, Uint32 nGameIP, Uint16 nGamePort, Uint16 SpectatorPort, Uint16 QueryPort, pCStrA pchGameDir, pCStrA pchVersion, Bool bLANMode) = 0;
	virtual void UpdateServerStatus(Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pSpectatorServerName, pCStrA pchMapName) = 0;
	virtual void UpdateSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetGameType(pCStrA pchGameType) = 0;
	virtual Bool BGetUserAchievementStatus(SteamId_t SteamId, pCStrA pchAchievementName) = 0;

} ISteamGameServer004, *IpSteamGameServer004;

typedef class _ISteamGameServer005_ {
public:

	virtual void LogOn() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual Bool BSetServerType(Uint32 nServerFlags, Uint32 nGameIP, Uint16 nGamePort, Uint16 SpectatorPort, Uint16 QueryPort, pCStrA pchGameDir, pCStrA pchVersion, Bool bLANMode) = 0;
	virtual void UpdateServerStatus(Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pSpectatorServerName, pCStrA pchMapName) = 0;
	virtual void UpdateSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetGameType(pCStrA pchGameType) = 0;
	virtual Bool BGetUserAchievementStatus(SteamId_t SteamId, pCStrA pchAchievementName) = 0;

} ISteamGameServer005, *IpSteamGameServer005;

typedef class _ISteamGameServer008_ {
public:

	virtual void LogOn() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual Bool BSetServerType(Uint32 nServerFlags, Uint32 nGameIP, Uint16 nGamePort, Uint16 SpectatorPort, Uint16 QueryPort, pCStrA pchGameDir, pCStrA pchVersion, Bool bLANMode) = 0;
	virtual void UpdateServerStatus(Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pSpectatorServerName, pCStrA pchMapName) = 0;
	virtual void UpdateSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetGameType(pCStrA pchGameType) = 0;
	virtual Bool BGetUserAchievementStatus(SteamId_t SteamId, pCStrA pchAchievementName) = 0;
	virtual void GetGameplayStats() = 0;
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;
	virtual Uint32 GetPublicIP_Old() = 0;

} ISteamGameServer008, *IpSteamGameServer008;

typedef class _ISteamGameServer009_ {
public:

	virtual void LogOn() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual Bool BSetServerType(Uint32 nServerFlags, Uint32 nGameIP, Uint16 nGamePort, Uint16 SpectatorPort, Uint16 QueryPort, pCStrA pchGameDir, pCStrA pchVersion, Bool bLANMode) = 0;
	virtual void UpdateServerStatus(Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pSpectatorServerName, pCStrA pchMapName) = 0;
	virtual void UpdateSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetGameType(pCStrA pchGameType) = 0;
	virtual Bool BGetUserAchievementStatus(SteamId_t SteamId, pCStrA pchAchievementName) = 0;
	virtual void GetGameplayStats() = 0;
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;
	virtual Uint32 GetPublicIP_Old() = 0;
	virtual void SetGameData(pCStrA pchGameData) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) = 0;

} ISteamGameServer009, *IpSteamGameServer009;

typedef class _ISteamGameServer010_ {
public:

	virtual void LogOn() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual Bool BSetServerType(Uint32 nServerFlags, Uint32 nGameIP, Uint16 nGamePort, Uint16 SpectatorPort, Uint16 QueryPort, pCStrA pchGameDir, pCStrA pchVersion, Bool bLANMode) = 0;
	virtual void UpdateServerStatus(Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pSpectatorServerName, pCStrA pchMapName) = 0;
	virtual void SetGameTags(pCStrA pchGameTags) = 0;
	virtual void GetGameplayStats() = 0;
	virtual SteamAPICall_t GetServerReputation() = 0;
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;
	virtual Uint32 GetPublicIP_Old() = 0;
	virtual void SetGameData(pCStrA pchGameData) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) = 0;
	virtual HAuthTicket GetAuthSessionTicket_Old(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;

} ISteamGameServer010, *IpSteamGameServer010;

typedef class _ISteamGameServer011_ {
public:

	virtual Bool InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, pCStrA pchVersionString) = 0;
	virtual void SetProduct(pCStrA pchProduct) = 0;
	virtual void SetGameDescription(pCStrA pchGameDescription) = 0;
	virtual void SetModDir(pCStrA pchModDir) = 0;
	virtual void SetDedicatedServer(Bool bDedicated) = 0;
	virtual void LogOn(pCStrA pchAccountName, pCStrA pchPassword) = 0;
	virtual void LogOnAnonymous() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool WasRestartRequested() = 0;
	virtual void SetMaxPlayerCount(Int32 cPlayersMax) = 0;
	virtual void SetBotPlayerCount(Int32 cBotplayers) = 0;
	virtual void SetServerName(pCStrA pchServerName) = 0;
	virtual void SetMapName(pCStrA pchMapName) = 0;
	virtual void SetPasswordProtected(Bool bPasswordProtected) = 0;
	virtual void SetSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetSpectatorServerName(pCStrA pchSpectatorServerName) = 0;
	virtual void ClearAllKeyValues() = 0;
	virtual void SetKeyValue(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual void SetGameTags(pCStrA pchGameTags) = 0;
	virtual void SetGameData(pCStrA pchGameData) = 0;
	virtual void SetRegion(pCStrA pchRegion) = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual HAuthTicket GetAuthSessionTicket_Old(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) = 0;
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;
	virtual void GetGameplayStats() = 0;
	virtual SteamAPICall_t GetServerReputation() = 0;
	virtual Uint32 GetPublicIP_Old() = 0;
	virtual Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) = 0;
	virtual Int32 GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) = 0;
	virtual void EnableHeartbeats(Bool bActive) = 0;
	virtual void SetHeartbeatInterval(Int32 iHeartbeatInterval) = 0;
	virtual void ForceHeartbeat() = 0;
	virtual SteamAPICall_t AssociateWithClan(SteamId_t SteamIdClan) = 0;
	virtual SteamAPICall_t ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) = 0;

} ISteamGameServer011, *IpSteamGameServer011;

typedef class _ISteamGameServer012_ {
public:

	virtual Bool InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, pCStrA pchVersionString) = 0;
	virtual void SetProduct(pCStrA pchProduct) = 0;
	virtual void SetGameDescription(pCStrA pchGameDescription) = 0;
	virtual void SetModDir(pCStrA pchModDir) = 0;
	virtual void SetDedicatedServer(Bool bDedicated) = 0;
	virtual void LogOn(pCStrA pchToken) = 0;
	virtual void LogOnAnonymous() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool WasRestartRequested() = 0;
	virtual void SetMaxPlayerCount(Int32 cPlayersMax) = 0;
	virtual void SetBotPlayerCount(Int32 cBotplayers) = 0;
	virtual void SetServerName(pCStrA pchServerName) = 0;
	virtual void SetMapName(pCStrA pchMapName) = 0;
	virtual void SetPasswordProtected(Bool bPasswordProtected) = 0;
	virtual void SetSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetSpectatorServerName(pCStrA pchSpectatorServerName) = 0;
	virtual void ClearAllKeyValues() = 0;
	virtual void SetKeyValue(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual void SetGameTags(pCStrA pchGameTags) = 0;
	virtual void SetGameData(pCStrA pchGameData) = 0;
	virtual void SetRegion(pCStrA pchRegion) = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual HAuthTicket GetAuthSessionTicket_Old(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) = 0;
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;
	virtual void GetGameplayStats() = 0;
	virtual SteamAPICall_t GetServerReputation() = 0;
	virtual Uint32 GetPublicIP_Old() = 0;
	virtual Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) = 0;
	virtual Int32 GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) = 0;
	virtual void EnableHeartbeats(Bool bActive) = 0;
	virtual void SetHeartbeatInterval(Int32 iHeartbeatInterval) = 0;
	virtual void ForceHeartbeat() = 0;
	virtual SteamAPICall_t AssociateWithClan(SteamId_t SteamIdClan) = 0;
	virtual SteamAPICall_t ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) = 0;

} ISteamGameServer012, *IpSteamGameServer012;

typedef class _ISteamGameServer013_ {
public:

	virtual Bool InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, pCStrA pchVersionString) = 0;
	virtual void SetProduct(pCStrA pchProduct) = 0;
	virtual void SetGameDescription(pCStrA pchGameDescription) = 0;
	virtual void SetModDir(pCStrA pchModDir) = 0;
	virtual void SetDedicatedServer(Bool bDedicated) = 0;
	virtual void LogOn(pCStrA pchToken) = 0;
	virtual void LogOnAnonymous() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool WasRestartRequested() = 0;
	virtual void SetMaxPlayerCount(Int32 cPlayersMax) = 0;
	virtual void SetBotPlayerCount(Int32 cBotplayers) = 0;
	virtual void SetServerName(pCStrA pchServerName) = 0;
	virtual void SetMapName(pCStrA pchMapName) = 0;
	virtual void SetPasswordProtected(Bool bPasswordProtected) = 0;
	virtual void SetSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetSpectatorServerName(pCStrA pchSpectatorServerName) = 0;
	virtual void ClearAllKeyValues() = 0;
	virtual void SetKeyValue(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual void SetGameTags(pCStrA pchGameTags) = 0;
	virtual void SetGameData(pCStrA pchGameData) = 0;
	virtual void SetRegion(pCStrA pchRegion) = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual HAuthTicket GetAuthSessionTicket_Old(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) = 0;
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;
	virtual void GetGameplayStats() = 0;
	virtual SteamAPICall_t GetServerReputation() = 0;
	virtual SteamIPAddress_t GetPublicIP() = 0;
	virtual Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) = 0;
	virtual Int32 GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) = 0;
	virtual void EnableHeartbeats(Bool bActive) = 0;
	virtual void SetHeartbeatInterval(Int32 iHeartbeatInterval) = 0;
	virtual void ForceHeartbeat() = 0;
	virtual SteamAPICall_t AssociateWithClan(SteamId_t SteamIdClan) = 0;
	virtual SteamAPICall_t ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) = 0;

} ISteamGameServer013, *IpSteamGameServer013;

typedef class _ISteamGameServer014_ {
public:

	virtual Bool InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, pCStrA pchVersionString) = 0;
	virtual void SetProduct(pCStrA pchProduct) = 0;
	virtual void SetGameDescription(pCStrA pchGameDescription) = 0;
	virtual void SetModDir(pCStrA pchModDir) = 0;
	virtual void SetDedicatedServer(Bool bDedicated) = 0;
	virtual void LogOn(pCStrA pchToken) = 0;
	virtual void LogOnAnonymous() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;
	virtual Bool WasRestartRequested() = 0;
	virtual void SetMaxPlayerCount(Int32 cPlayersMax) = 0;
	virtual void SetBotPlayerCount(Int32 cBotplayers) = 0;
	virtual void SetServerName(pCStrA pchServerName) = 0;
	virtual void SetMapName(pCStrA pchMapName) = 0;
	virtual void SetPasswordProtected(Bool bPasswordProtected) = 0;
	virtual void SetSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetSpectatorServerName(pCStrA pchSpectatorServerName) = 0;
	virtual void ClearAllKeyValues() = 0;
	virtual void SetKeyValue(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual void SetGameTags(pCStrA pchGameTags) = 0;
	virtual void SetGameData(pCStrA pchGameData) = 0;
	virtual void SetRegion(pCStrA pchRegion) = 0;
	virtual void SetAdvertiseServerActive(Bool bActive) = 0;
	virtual HAuthTicket GetAuthSessionTicket_Old(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) = 0;
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;
	virtual void GetGameplayStats() = 0;
	virtual SteamAPICall_t GetServerReputation() = 0;
	virtual SteamIPAddress_t GetPublicIP() = 0;
	virtual Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) = 0;
	virtual Int32 GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) = 0;
	virtual SteamAPICall_t AssociateWithClan(SteamId_t SteamIdClan) = 0;
	virtual SteamAPICall_t ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) = 0;
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;
	virtual void SetMasterServerHeartbeatInterval_DEPRECATED(Int32 iHeartbeatInterval) = 0;
	virtual void ForceMasterServerHeartbeat_DEPRECATED() = 0;

} ISteamGameServer014, *IpSteamGameServer014;

// -----------------------------------------------------------------------------
// Purpose: Functions for authenticating users via SteamAPI
// -----------------------------------------------------------------------------
typedef class _ISteamGameServer_ {
public:

	/* This is called by SteamGameServer_Init */
	virtual Bool InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, pCStrA pchVersionString) = 0;
	virtual void SetProduct(pCStrA pchProduct) = 0;
	virtual void SetGameDescription(pCStrA pchGameDescription) = 0;
	virtual void SetModDir(pCStrA pchModDir) = 0;
	virtual void SetDedicatedServer(Bool bDedicated) = 0;

	/* You need to register for callbacks to determine the result of this operation.
	    SteamServersConnected_t, SteamServerConnectFailure_t,
	    SteamServersDisconnected_t */
	virtual void LogOn(pCStrA pchToken) = 0;
	virtual void LogOnAnonymous() = 0;
	virtual void LogOff() = 0;
	virtual Bool BLoggedOn() = 0;
	virtual Bool BSecure() = 0;
	virtual SteamId_t GetSteamID() = 0;

	/* Returns true if the master server has requested a restart.
	   Only returns true once per request. */
	virtual Bool WasRestartRequested() = 0;
	virtual void SetMaxPlayerCount(Int32 cPlayersMax) = 0;
	virtual void SetBotPlayerCount(Int32 cBotplayers) = 0;
	virtual void SetServerName(pCStrA pchServerName) = 0;
	virtual void SetMapName(pCStrA pchMapName) = 0;
	virtual void SetPasswordProtected(Bool bPasswordProtected) = 0;

	/* Spectator server port to advertise. The default value is zero, meaning the
	   service is not used. If your server receives any info requests on the LAN,
	   this is the value that will be placed into the reply */
	virtual void SetSpectatorPort(Uint16 SpectatorPort) = 0;
	virtual void SetSpectatorServerName(pCStrA pchSpectatorServerName) = 0;
	virtual void ClearAllKeyValues() = 0;
	virtual void SetKeyValue(pCStrA pchKey, pCStrA pchValue) = 0;
	virtual void SetGameTags(pCStrA pchGameTags) = 0;
	virtual void SetGameData(pCStrA pchGameData) = 0;
	virtual void SetRegion(pCStrA pchRegion) = 0;

	/* Indicate whether you wish to be listed on the master server list
	    and/or respond to server browser / LAN discovery packets.
	    The server starts with this value set to false. You should set all
	     relevant server parameters before enabling advertisement on the server. */
	virtual void SetAdvertiseServerActive(Bool bActive) = 0;

	/* Retrieve ticket to be sent to the entity who wishes to authenticate you (using BeginAuthSession API). 
	    pcbTicket retrieves the length of the actual ticket.
	    SteamNetworkingIdentity is an optional parameter to hold the public IP address of the entity you are connecting to
	     if an IP address is passed Steam will only allow the ticket to be used by an entity with that IP address */
	virtual HAuthTicket GetAuthSessionTicket(/* [out] */ pVoid pvTicket, Int32 cbMaxTicket, /* [out] */ pUint32 pcbTicket, /* [out] */ const pSteamNetworkingIdentity pSnId) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) = 0;
	virtual void EndAuthSession(SteamId_t SteamId) = 0;
	virtual void CancelAuthTicket(HAuthTicket hAuthTicket) = 0;
	virtual EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) = 0;

	/* Ask if a user in in the specified group, results returns async by GSUserGroupStatus_t
	    returns False if we're not connected to the steam servers and thus cannot ask */
	virtual Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) = 0;

	virtual void GetGameplayStats() = 0;
	virtual SteamAPICall_t GetServerReputation() = 0;
	virtual SteamIPAddress_t GetPublicIP() = 0;
	virtual Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) = 0;
	virtual Int32 GetNextOutgoingPacket(/* [out] */ pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) = 0;

	virtual SteamAPICall_t AssociateWithClan(SteamId_t SteamIdClan) = 0;
	virtual SteamAPICall_t ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) = 0;

	/* Return Value: Returns True if the users ticket passes basic checks. pSteamIDUser will contain the SteamId of this user. pSteamIDUser must NOT be NULL
	   If the call succeeds then you should expect a GSClientApprove_t or GSClientDeny_t callback which will tell you whether authentication
	    for the user has succeeded or failed (the steamid in the callback will match the one returned by this call) */
	virtual Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, /* [out] */ pSteamId_t pSteamIdUser) = 0;
	virtual SteamId_t CreateUnauthenticatedUserConnection() = 0;
	virtual void SendUserDisconnect(SteamId_t SteamIdUser) = 0;

	/* Return Value: True if successful, False if failure(ie, SteamIdUser wasn't for an active player) */
	virtual Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) = 0;

	virtual void SetMasterServerHeartbeatInterval_DEPRECATED(Int32 iHeartbeatInterval) = 0;
	virtual void ForceMasterServerHeartbeat_DEPRECATED() = 0;

} ISteamGameServer, *IpSteamGameServer;

#define STEAMGAMESERVER_INTERFACE_VERSION "SteamGameServer015"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_EServerFlagNone ((Uint32)(0x00000000))
#define k_EServerFlagActive ((Uint32)(0x00000001))
#define k_EServerFlagSecure ((Uint32)(0x00000002))
#define k_EServerFlagDedicated ((Uint32)(0x00000004))
#define k_EServerFlagLinux ((Uint32)(0x00000008))
#define k_EServerFlagPassworded ((Uint32)(0x00000010))
#define k_EServerFlagPrivate ((Uint32)(0x00000020))

#define k_iCallbback_GSClientApprove_t ((Int32)(k_iSteamGameServerCallbacks + 1))
typedef struct _GSClientApprove_t_ {

	SteamId_t SteamId;
	SteamId_t OwnerSteamId;

} GSClientApprove_t, *pGSClientApprove_t;

#define k_iCallbback_GSClientDeny_t ((Int32)(k_iSteamGameServerCallbacks + 2))
typedef struct _GSClientDeny_t_ {

	SteamId_t SteamId;
	EDenyReason eDenyReason;
	CharA chOptionalText[128];

} GSClientDeny_t, *pGSClientDeny_t;

#define k_iCallbback_GSClientKick_t ((Int32)(k_iSteamGameServerCallbacks + 3))
typedef struct _GSClientKick_t_
{
	SteamId_t SteamId;
	EDenyReason eDenyReason;

} GSClientKick_t, *pGSClientKick_t;

#define k_iCallbback_GSClientAchievementStatus_t ((Int32)(k_iSteamGameServerCallbacks + 6))
typedef struct _GSClientAchievementStatus_t_
{
	Uint64 SteamId;
	CharA pchAchievement[128];
	Bool bUnlocked;

} GSClientAchievementStatus_t, *pGSClientAchievementStatus_t;

// -----------------------------------------------------------------------------
// Purpose: Received when the game server requests to be displayed as secure (VAC protected)
//  bSecure is True if the game server should display itself as secure to users
// -----------------------------------------------------------------------------
#define k_iCallbback_GSPolicyResponse_t ((Int32)(k_iSteamGameServerCallbacks + 15))
typedef struct _GSPolicyResponse_t_ {

	Uint8 bSecure;

} GSPolicyResponse_t, *pGSPolicyResponse_t;

#define k_iCallbback_GSGameplayStats_t ((Int32)(k_iSteamGameServerCallbacks + 7))
typedef struct _GSGameplayStats_t_ {

	EResult eResult;
	Int32	nRank;
	Uint32	unTotalConnects;
	Uint32	unTotalMinutesPlayed;

} GSGameplayStats_t, *pGSGameplayStats_t;

#define k_iCallbback_GSClientGroupStatus_t ((Int32)(k_iSteamGameServerCallbacks + 8))
typedef struct _GSClientGroupStatus_t_ {

	SteamId_t SteamIdUser;
	SteamId_t SteamIdGroup;
	Bool bMember;
	Bool bOfficer;

} GSClientGroupStatus_t, *pGSClientGroupStatus_t;

#define k_iCallbback_GSReputation_t ((Int32)(k_iSteamGameServerCallbacks + 9))
typedef struct _GSReputation_t_ {

	EResult	eResult;
	Uint32	nReputationScore;
	Bool	bBanned;
	Uint32	BannedIP;
	Uint16	BannedPort;
	Uint64	BannedGameID;
	Uint32	BanExpires;

} GSReputation_t, *pGSReputation_t;

#define k_iCallbback_AssociateWithClanResult_t ((Int32)(k_iSteamGameServerCallbacks + 10))
typedef struct _AssociateWithClanResult_t_ {

	EResult	eResult;

} AssociateWithClanResult_t, *pAssociateWithClanResult_t;

#define k_iCallbback_ComputeNewPlayerCompatibilityResult_t ((Int32)(k_iSteamGameServerCallbacks + 11))
typedef struct _ComputeNewPlayerCompatibilityResult_t_ {

	EResult	eResult;
	Int32 cPlayersThatDontLikeCandidate;
	Int32 cPlayersThatCandidateDoesntLike;
	Int32 cClanPlayersThatDontLikeCandidate;
	SteamId_t SteamIdCandidate;

} ComputeNewPlayerCompatibilityResult_t, *pComputeNewPlayerCompatibilityResult_t;

#pragma pack(pop)

#endif // _ISTEAMGAMESERVER_
