#ifndef _ISTEAMCLIENT_
#define _ISTEAMCLIENT_

#include "..\..\FreeAPI.Typedef.h"

#include "ISteamUser.h"
#include "ISteamGameServer.h"
#include "ISteamFriends.h"
#include "ISteamUtils.h"
#include "ISteamMatchmaking.h"
#include "ISteamUserStats.h"
#include "ISteamGameServerStats.h"
#include "ISteamAppTicket.h"
#include "ISteamApps.h"
#include "ISteamNetworking.h"
#include "ISteamRemoteStorage.h"
#include "ISteamScreenshots.h"
#include "ISteamHTTP.h"
#include "ISteamUnifiedMessages.h"
#include "ISteamController.h"
#include "ISteamUGC.h"
#include "ISteamAppList.h"
#include "ISteamMusic.h"
#include "ISteamMusicRemote.h"
#include "ISteamHTMLSurface.h"
#include "ISteamInventory.h"
#include "ISteamVideo.h"
#include "ISteamParentalSettings.h"
#include "ISteamInput.h"
#include "ISteamRemotePlay.h"
#include "ISteamGameCoordinator.h"
#include "ISteamPS3OverlayRenderer.h"
#include "ISteamMasterServerUpdater.h"
#include "ISteamTV.h"
#include "ISteamNetworkingUtils.h"
#include "ISteamNetworkingSockets.h"
#include "ISteamNetworkingMessages.h"
#include "ISteamNetworkingSocketsSerialized.h"

typedef pVoid IpSteamContentServer;

typedef class _ISteamClient007_ {
public:
	
	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamContentServer GetISteamContentServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMasterServerUpdater GetISteamMasterServerUpdater(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;

} ISteamClient007, *IpSteamClient007;

typedef class _ISteamClient008_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamContentServer GetISteamContentServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMasterServerUpdater GetISteamMasterServerUpdater(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;

} ISteamClient008, *IpSteamClient008;

typedef class _ISteamClient009_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMasterServerUpdater GetISteamMasterServerUpdater(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamuser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;

} ISteamClient009, *IpSteamClient009;

typedef class _ISteamClient010_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMasterServerUpdater GetISteamMasterServerUpdater(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	#ifdef _PS3
	virtual IpSteamPS3OverlayRender GetISteamPS3OverlayRender() = 0;
	#endif
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient010, *IpSteamClient010;

typedef class _ISteamClient011_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	#ifdef _PS3
	virtual IpSteamPS3OverlayRender GetISteamPS3OverlayRender() = 0;
	#endif
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient011, *IpSteamClient011;

typedef class _ISteamClient012_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	#ifdef _PS3
	virtual IpSteamPS3OverlayRender GetISteamPS3OverlayRender() = 0;
	#endif
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient012, *IpSteamClient012;

typedef class _ISteamClient013_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	#ifdef _PS3
	virtual IpSteamPS3OverlayRender GetISteamPS3OverlayRender() = 0;
	#endif
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamInventory GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamVideo GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient013, *IpSteamClient013;

typedef class _ISteamClient014_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	#ifdef _PS3
	virtual IpSteamPS3OverlayRender GetISteamPS3OverlayRender() = 0;
	#endif
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient014, *IpSteamClient014;

typedef class _ISteamClient015_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	#ifdef _PS3
	virtual IpSteamPS3OverlayRender GetISteamPS3OverlayRender() = 0;
	#endif
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusicRemote GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient015, *IpSteamClient015;

typedef class _ISteamClient016_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	#ifdef _PS3
	virtual IpSteamPS3OverlayRender GetISteamPS3OverlayRender() = 0;
	#endif
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusicRemote GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamHTMLSurface GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) = 0;

} ISteamClient016, *IpSteamClient016;

typedef class _ISteamClient017_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusicRemote GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamHTMLSurface GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) = 0;
	virtual IpSteamInventory GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamVideo GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamParentalSettings GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient017, *IpSteamClient017;

typedef class _ISteamClient018_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameSearch GetISteamGameSearch(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusicRemote GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamHTMLSurface GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) = 0;
	virtual IpSteamInventory GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamVideo GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamParentalSettings GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamInput GetISteamInput(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamParties GetISteamParties(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient018, *IpSteamClient018;

typedef class _ISteamClient019_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;
	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void SetLocalIPBinding(Uint32 nIP, Uint16 Port) = 0;
	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameSearch GetISteamGameSearch(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;
	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusicRemote GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamHTMLSurface GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) = 0;
	virtual IpSteamInventory GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamVideo GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamParentalSettings GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamInput GetISteamInput(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamParties GetISteamParties(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemotePlay GetISteamRemotePlay(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

} ISteamClient019, *IpSteamClient019;

// -----------------------------------------------------------------------------
// Purpose: Interface to creating a new steam instance, or to
//  connect to an existing steam instance, whether it's in a
//  different process or is local.
// -----------------------------------------------------------------------------
typedef class _ISteamClient_ {
public:

	virtual HSteamPipe CreateSteamPipe() = 0;
	virtual Bool BReleaseSteamPipe(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe) = 0;
	virtual HSteamUser CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) = 0;
	virtual void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) = 0;

	virtual IpSteamUser GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServer GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

	virtual void SetLocalIPBinding(const pSteamIPAddress_t pSteamIPAdrr, Uint16 Port) = 0;

	virtual IpSteamFriends GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUtils GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmaking GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMatchmakingServers GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

	virtual pVoid GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	
	virtual IpSteamUserStats GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameServerStats GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamApps GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamNetworking GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemoteStorage GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamScreenshots GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamGameSearch GetISteamGameSearch(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

	/* Applications should use SteamAPI_RunCallbacks() or SteamGameServer_RunCallbacks() instead */
	virtual void RunFrame() = 0;
	virtual Uint32 GetIPCCallCount() = 0;

	/* API warning handling
	    Int32 is severity; 0: msg, 1: warning
	    pCStrA is text of the message
	    callbacks will occur directly after the API function is called that generated the warning or message. */
	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) = 0;
	virtual Bool BShutdownIfAllPipesClosed() = 0;

	virtual IpSteamHTTP GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUnifiedMessages DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamController GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamUGC GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamAppList GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusic GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamMusicRemote GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamHTMLSurface GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

	virtual void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void (*pFunction) ()) = 0;
	virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) = 0;

	virtual IpSteamInventory GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamVideo GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamParentalSettings GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamInput GetISteamInput(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamParties GetISteamParties(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;
	virtual IpSteamRemotePlay GetISteamRemotePlay(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) = 0;

	virtual void DestroyAllInterfaces() = 0;

} ISteamClient, *IpSteamClient;

#define STEAMCLIENT_INTERFACE_VERSION "SteamClient020"

#endif // _ISTEAMCLIENT_
