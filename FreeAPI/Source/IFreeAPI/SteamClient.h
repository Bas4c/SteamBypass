#ifndef _STEAMCLIENT_
#define _STEAMCLIENT_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamClient.h"
// -----------------------------------------------------------------------------

#include "SteamUser.h"
#include "SteamGameServer.h"
#include "SteamFriends.h"
#include "SteamUtils.h"
#include "SteamMatchmaking.h"
#include "SteamUserStats.h"
#include "SteamGameServerStats.h"
#include "SteamAppTicket.h"
#include "SteamApps.h"
#include "SteamNetworking.h"
#include "SteamRemoteStorage.h"
#include "SteamScreenshots.h"
#include "SteamHTTP.h"
#include "SteamUnifiedMessages.h"
#include "SteamController.h"
#include "SteamUGC.h"
#include "SteamAppList.h"
#include "SteamMusic.h"
#include "SteamMusicRemote.h"
#include "SteamHTMLSurface.h"
#include "SteamInventory.h"
#include "SteamVideo.h"
#include "SteamParentalSettings.h"
#include "SteamInput.h"
#include "SteamRemotePlay.h"
#include "SteamGameCoordinator.h"
#include "SteamPS3OverlayRenderer.h"
#include "SteamMasterServerUpdater.h"
#include "SteamTV.h"
#include "SteamNetworkingUtils.h"
#include "SteamNetworkingSockets.h"
#include "SteamNetworkingMessages.h"
#include "SteamNetworkingSocketsSerialized.h"

typedef class _SteamClient_ : public _ISteamClient007_,
 public _ISteamClient008_, public _ISteamClient009_,
 public _ISteamClient010_, public _ISteamClient011_,
 public _ISteamClient012_, public _ISteamClient013_,
 public _ISteamClient014_, public _ISteamClient015_,
 public _ISteamClient016_, public _ISteamClient017_,
 public _ISteamClient018_, public _ISteamClient019_,
 public _ISteamClient_ {
public:

	_SteamClient_() = default;
	_SteamClient_(const _SteamClient_&) = delete;
	_SteamClient_& operator=(const _SteamClient_&) = delete;

	HSteamPipe CreateSteamPipe() override;
	Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) override;
	HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) override;
	HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe) override;
	HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) override;
	void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) override;

	IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;

	void SetLocalIPBinding(Uint32 nIP, Uint16 Port) override;
	void SetLocalIPBinding(const pSteamIPAddress_t pSteamIPAdrr, Uint16 Port) override;

	IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;

	pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;

	IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamGameSearch GetISteamGameSearch(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;

	/* Applications should use SteamAPI_RunCallbacks() or SteamGameServer_RunCallbacks() instead */
	void RunFrame() override;
	Uint32 GetIPCCallCount() override;

	/* API warning handling
		Int32 is severity; 0: msg, 1: warning
		pCStrA is text of the message
		callbacks will occur directly after the API function is called that generated the warning or message. */
	void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) override;
	Bool BShutdownIfAllPipesClosed() override;

	IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamMusicRemote GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamHTMLSurface GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;

	void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void(*pFunction)()) override;
	void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void(*pFunction)()) override;
	void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) override;

	IpSteamInventory GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamVideo GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamParentalSettings GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamInput GetISteamInput(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamParties GetISteamParties(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamRemotePlay GetISteamRemotePlay(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;

	IpSteamContentServer GetISteamContentServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;
	IpSteamMasterServerUpdater GetISteamMasterServerUpdater(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) override;

	void DestroyAllInterfaces() override;

	~_SteamClient_() = default;

private:

	SteamUser SteamUser;
	SteamGameServer SteamGameServer;
	SteamFriends SteamFriends;
	SteamUtils SteamUtils;
	SteamGameSearch SteamGameSearch;
	SteamMatchmaking SteamMatchmaking;
	SteamMatchmakingServers SteamMatchmakingServers;
	SteamParties SteamParties;
	SteamUserStats SteamUserStats;
	SteamGameServerStats SteamGameServerStats;
	SteamAppTicket SteamAppTicket;
	SteamApps SteamApps;
	SteamNetworking SteamNetworking;
	SteamRemoteStorage SteamRemoteStorage;
	SteamScreenshots SteamScreenshots;
	SteamHTTP SteamHTTP;
	SteamUnifiedMessages SteamUnifiedMessages;
	SteamController SteamController;
	SteamUGC SteamUGC;
	SteamAppList SteamAppList;
	SteamMusic SteamMusic;
	SteamMusicRemote SteamMusicRemote;
	SteamHTMLSurface SteamHTMLSurface;
	SteamInventory SteamInventory;
	SteamVideo SteamVideo;
	SteamParentalSettings SteamParentalSettings;
	SteamInput SteamInput;
	SteamRemotePlay SteamRemotePlay;
	SteamGameCoordinator SteamGameCoordinator;
	SteamPS3OverlayRenderer SteamPS3OverlayRenderer;
	SteamMasterServerUpdater SteamMasterServerUpdater;
	SteamTV SteamTV;
	SteamNetworkingUtils SteamNetworkingUtils;
	SteamNetworkingSockets SteamNetworkingSockets;
	SteamNetworkingMessages SteamNetworkingMessages;
	SteamNetworkingSocketsSerialized SteamNetworkingSocketsSerialized;

} SteamClient, *pSteamClient;

#endif // !_STEAMCLIENT_
