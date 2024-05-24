#ifndef _STEAMGAMESERVER_
#define _STEAMGAMESERVER_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamGameServer.h"
// -----------------------------------------------------------------------------

typedef class _SteamGameServer_ : public _ISteamGameServer004_,
 public _ISteamGameServer005_, public _ISteamGameServer008_,
 public _ISteamGameServer009_, public _ISteamGameServer010_,
 public _ISteamGameServer011_, public _ISteamGameServer012_,
 public _ISteamGameServer013_, public _ISteamGameServer014_,
 public _ISteamGameServer_ {
public:

	_SteamGameServer_() = default;
	_SteamGameServer_(const _SteamGameServer_&) = delete;
	_SteamGameServer_& operator=(const _SteamGameServer_&) = delete;

	/* This is called by SteamGameServer_Init */
	Bool InitGameServer(Uint32 nIP, Uint16 GamePort, Uint16 QueryPort, Uint32 nFlags, AppId_t iGameAppId, pCStrA pchVersionString) override;
	void SetProduct(pCStrA pchProduct) override;
	void SetGameDescription(pCStrA pchGameDescription) override;
	void SetModDir(pCStrA pchModDir) override;
	void SetDedicatedServer(Bool bDedicated) override;
	
	/* You need to register for callbacks to determine the result of this operation.
			SteamServersConnected_t, SteamServerConnectFailure_t,
			SteamServersDisconnected_t */
	void LogOn() override;
	void LogOn(pCStrA pchAccountName, pCStrA pchPassword) override;
	void LogOn(pCStrA pchToken) override;
	void LogOnAnonymous() override;
	void LogOff() override;
	Bool BLoggedOn() override;
	Bool BSecure() override;
	SteamId_t GetSteamID() override;

	/* Returns true if the master server has requested a restart.
	   Only returns true once per request. */
	Bool WasRestartRequested() override;
	void SetMaxPlayerCount(Int32 cPlayersMax) override;
	void SetBotPlayerCount(Int32 cBotplayers) override;
	void SetServerName(pCStrA pchServerName) override;
	void SetMapName(pCStrA pchMapName) override;
	void SetPasswordProtected(Bool bPasswordProtected) override;

	/* Spectator server port to advertise. The default value is zero, meaning the
	   service is not used. If your server receives any info requests on the LAN,
	   this is the value that will be placed into the reply */
	void SetSpectatorPort(Uint16 SpectatorPort) override;
	void SetSpectatorServerName(pCStrA pchSpectatorServerName) override;
	void ClearAllKeyValues() override;
	void SetKeyValue(pCStrA pchKey, pCStrA pchValue) override;
	void SetGameTags(pCStrA pchGameTags) override;
	void SetGameData(pCStrA pchGameData) override;
	void SetRegion(pCStrA pchRegion) override;

	/* Indicate whether you wish to be listed on the master server list
		and/or respond to server browser / LAN discovery packets.
		The server starts with this value set to false. You should set all
		 relevant server parameters before enabling advertisement on the server. */
	void SetAdvertiseServerActive(Bool bActive) override;

	/* Retrieve ticket to be sent to the entity who wishes to authenticate you (using BeginAuthSession API).
		pcbTicket retrieves the length of the actual ticket.
		SteamNetworkingIdentity is an optional parameter to hold the public IP address of the entity you are connecting to
		 if an IP address is passed Steam will only allow the ticket to be used by an entity with that IP address */
	HAuthTicket GetAuthSessionTicket_Old(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) override;
	HAuthTicket GetAuthSessionTicket(pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSnId) override;
	EBeginAuthSessionResult BeginAuthSession(const pVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t SteamId) override;
	void EndAuthSession(SteamId_t SteamId) override;
	void CancelAuthTicket(HAuthTicket hAuthTicket) override;
	EUserHasLicenseForAppResult UserHasLicenseForApp(SteamId_t SteamId, AppId_t AppId) override;

	/* Ask if a user in in the specified group, results returns async by GSUserGroupStatus_t
		returns False if we're not connected to the steam servers and thus cannot ask */
	Bool RequestUserGroupStatus(SteamId_t SteamIdUser, SteamId_t SteamIdGroup) override;

	void GetGameplayStats() override;
	SteamAPICall_t GetServerReputation() override;
	Uint32 GetPublicIP_Old() override;
	SteamIPAddress_t GetPublicIP() override;
	Bool HandleIncomingPacket(const pVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) override;
	Int32 GetNextOutgoingPacket(pVoid pvOut, Int32 cbMaxOut, pUint32 pNetAdrr, pUint16 pPort) override;

	void EnableHeartbeats(Bool bActive) override;
	void SetHeartbeatInterval(Int32 iHeartbeatInterval) override;
	void ForceHeartbeat() override;

	SteamAPICall_t AssociateWithClan(SteamId_t SteamIdClan) override;
	SteamAPICall_t ComputeNewPlayerCompatibility(SteamId_t SteamIdNewPlayer) override;

	/* Return Value: Returns True if the users ticket passes basic checks. pSteamIDUser will contain the SteamId of this user. pSteamIDUser must NOT be NULL
	   If the call succeeds then you should expect a GSClientApprove_t or GSClientDeny_t callback which will tell you whether authentication
		for the user has succeeded or failed (the steamid in the callback will match the one returned by this call) */
	Bool SendUserConnectAndAuthenticate(Uint32 nIPClient, const pVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) override;
	SteamId_t CreateUnauthenticatedUserConnection() override;
	void SendUserDisconnect(SteamId_t SteamIdUser) override;

	/* Return Value: True if successful, False if failure(ie, SteamIdUser wasn't for an active player) */
	Bool BUpdateUserData(SteamId_t SteamIdUser, pCStrA pchPlayerName, Uint32 Score) override;
	Bool BSetServerType(Uint32 nServerFlags, Uint32 nGameIP, Uint16 nGamePort, Uint16 SpectatorPort, Uint16 QueryPort, pCStrA pchGameDir, pCStrA pchVersion, Bool bLANMode) override;
	void UpdateServerStatus(Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pSpectatorServerName, pCStrA pchMapName) override;
	void UpdateSpectatorPort(Uint16 SpectatorPort) override;
	void SetGameType(pCStrA pchGameType) override;
	Bool BGetUserAchievementStatus(SteamId_t SteamId, pCStrA pchAchievementName) override;

	void SetMasterServerHeartbeatInterval_DEPRECATED(Int32 iHeartbeatInterval) override;
	void ForceMasterServerHeartbeat_DEPRECATED() override;

	~_SteamGameServer_() = default;

} SteamGameServer, *pSteamGameServer;

#endif // !_STEAMGAMESERVER_
