// -----------------------------------------------------------------------------
#include "SteamClient.h"
// -----------------------------------------------------------------------------

HSteamPipe _SteamClient_::CreateSteamPipe() {
	DEBUGBREAK("ISteamClient::CreateSteamPipe");

	return k_HSteamPipe_Client;

}

Bool _SteamClient_::BReleaseSteamPipe(HSteamPipe hSteamPipe) {
	DEBUGBREAK("ISteamClient::BReleaseSteamPipe");

	return True;

}

HSteamUser _SteamClient_::ConnectToGlobalUser(HSteamPipe hSteamPipe) {
	DEBUGBREAK("ISteamClient::ConnectToGlobalUser");

	return k_HSteamUser_LocalUser;

}

HSteamUser _SteamClient_::CreateLocalUser(pHSteamPipe phSteamPipe) {
	DEBUGBREAK("ISteamClient::CreateLocalUser");
	
	if (phSteamPipe != NULL) {
		*phSteamPipe = k_HSteamPipe_Client;
	}

	return k_HSteamUser_LocalUser;

}

HSteamUser _SteamClient_::CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) {
	DEBUGBREAK("ISteamClient::CreateLocalUser");

	if (phSteamPipe != NULL) {
		*phSteamPipe = k_HSteamPipe_Client;
	}

	return k_HSteamUser_LocalUser;

}

void _SteamClient_::ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) {
	DEBUGBREAK("ISteamClient::ReleaseUser");

	/* Empty Method */

}

IpSteamUser _SteamClient_::GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamUser");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser001"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser002"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser003"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser004"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser005"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser006"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser007"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser008"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser009"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser010"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser011"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser012"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser013"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser014"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser015"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser016"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser017"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser018"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser019"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser020"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser021"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("SteamUser022"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)(STEAMUSER_INTERFACE_VERSION), True)
		) {
			return (IpSteamUser)(&this->SteamUser);
		}
	}

	return NULL;

}

IpSteamGameServer _SteamClient_::GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamGameServer");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer004"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer004)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer005"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer005)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer008"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer008)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer009"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer009)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer010"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer010)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer011"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer011)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer012"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer012)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer013"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer013)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamGameServer014"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer014)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMGAMESERVER_INTERFACE_VERSION), True))
			return (IpSteamGameServer)(&this->SteamGameServer);
	}

	return NULL;

}

void _SteamClient_::SetLocalIPBinding(Uint32 nIP, Uint16 Port) {
	DEBUGBREAK("ISteamClient::SetLocalIPBinding");

	/* Empty Method */

}

void _SteamClient_::SetLocalIPBinding(const pSteamIPAddress_t pSteamIPAdrr, Uint16 Port) {
	DEBUGBREAK("ISteamClient::SetLocalIPBinding");

	/* Empty Method */

}

IpSteamFriends _SteamClient_::GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamFriends");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends003"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends003)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends004"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends004)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends005"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends005)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends006"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends006)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends007"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends007)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends008"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends008)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends009"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends009)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends010"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends010)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends011"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends011)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends012"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends013)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends014"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends014)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends015"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends015)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamFriends016"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends016)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMFRIENDS_INTERFACE_VERSION), True))
			return (IpSteamFriends)(&this->SteamFriends);
	}

	return NULL;

}

IpSteamUtils _SteamClient_::GetISteamUtils(HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamUtils");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils002"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils002)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils003"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils003)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils004"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils004)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils005"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils005)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils006"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils006)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils007"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils007)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils008"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils008)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamUtils009"), True))
			return (IpSteamUtils)((pVoid)((IpSteamUtils009)(&this->SteamUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMUTILS_INTERFACE_VERSION), True))
			return (IpSteamUtils)(&this->SteamUtils);
	}

	return NULL;

}

IpSteamMatchmaking _SteamClient_::GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamMatchmaking");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMaking002"), True))
			return (IpSteamMatchmaking)((pVoid)((IpSteamMatchmaking002)(&this->SteamMatchmaking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMaking003"), True))
			return (IpSteamMatchmaking)((pVoid)((IpSteamMatchmaking003)(&this->SteamMatchmaking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMaking004"), True))
			return (IpSteamMatchmaking)((pVoid)((IpSteamMatchmaking004)(&this->SteamMatchmaking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMaking005"), True))
			return (IpSteamMatchmaking)((pVoid)((IpSteamMatchmaking005)(&this->SteamMatchmaking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMaking006"), True))
			return (IpSteamMatchmaking)((pVoid)((IpSteamMatchmaking006)(&this->SteamMatchmaking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMaking007"), True))
			return (IpSteamMatchmaking)((pVoid)((IpSteamMatchmaking007)(&this->SteamMatchmaking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMaking008"), True))
			return (IpSteamMatchmaking)((pVoid)((IpSteamMatchmaking008)(&this->SteamMatchmaking)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMMATCHMAKING_INTERFACE_VERSION), True))
			return (IpSteamMatchmaking)(&this->SteamMatchmaking);
	}

	return NULL;

}

IpSteamMatchmakingServers _SteamClient_::GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamMatchmakingServers");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamMatchMakingServers001"), True))
			return (IpSteamMatchmakingServers)((pVoid)((IpSteamMatchmakingServers001)(&this->SteamMatchmakingServers)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION), True))
			return (IpSteamMatchmakingServers)(&this->SteamMatchmakingServers);
	}

	return NULL;

}

pVoid _SteamClient_::GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamGenericInterface");

	if (pchVersion != NULL) {

		DEBUG_OUT(pchVersion);

		pVoid pGeneric = NULL;
		pGeneric = this->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamUtils(hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamGameSearch(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamParties(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamGameServerStats(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMAPPTICKET_INTERFACE_VERSION), True))
			return (IpSteamAppTicket)(&this->SteamAppTicket);
		pGeneric = this->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamRemoteStorage(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamScreenshots(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamHTTP(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->DEPRECATED_GetISteamUnifiedMessages(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamMusic(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamMusicRemote(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamHTMLSurface(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamInventory(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamVideo(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamParentalSettings(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamInput(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		pGeneric = this->GetISteamRemotePlay(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		#ifdef _PS3
		pGeneric = this->GetISteamPS3OverlayRender();
		if (pGeneric != NULL)
			return pGeneric;
		#endif
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMGAMECOORDINATOR_INTERFACE_VERSION), True))
			return (IpSteamGameCoordinator)(&this->SteamGameCoordinator);
		pGeneric = this->GetISteamMasterServerUpdater(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMTV_INTERFACE_VERSION), True))
			return (IpSteamTV)(&this->SteamTV);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingUtils001"), True))
			return (IpSteamNetworkingUtils)((pVoid)((IpSteamNetworkingUtils001)(&this->SteamNetworkingUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingUtils002"), True))
			return (IpSteamNetworkingUtils)((pVoid)((IpSteamNetworkingUtils002)(&this->SteamNetworkingUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingUtils003"), True))
			return (IpSteamNetworkingUtils)((pVoid)((IpSteamNetworkingUtils003)(&this->SteamNetworkingUtils)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMNETWORKINGUTILS_INTERFACE_VERSION), True))
			return (IpSteamNetworkingUtils)(&this->SteamNetworkingUtils);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSockets001"), True))
			return (IpSteamNetworkingSockets)((pVoid)((IpSteamNetworkingSockets001)(&this->SteamNetworkingSockets)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSockets002"), True))
			return (IpSteamNetworkingSockets)((pVoid)((IpSteamNetworkingSockets002)(&this->SteamNetworkingSockets)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSockets003"), True))
			return (IpSteamNetworkingSockets)((pVoid)((IpSteamNetworkingSockets003)(&this->SteamNetworkingSockets)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSockets004"), True))
			return (IpSteamNetworkingSockets)((pVoid)((IpSteamNetworkingSockets004)(&this->SteamNetworkingSockets)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSockets006"), True))
			return (IpSteamNetworkingSockets)((pVoid)((IpSteamNetworkingSockets006)(&this->SteamNetworkingSockets)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSockets008"), True))
			return (IpSteamNetworkingSockets)((pVoid)((IpSteamNetworkingSockets008)(&this->SteamNetworkingSockets)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSockets009"), True))
			return (IpSteamNetworkingSockets)((pVoid)((IpSteamNetworkingSockets009)(&this->SteamNetworkingSockets)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMNETWORKINGSOCKETS_INTERFACE_VERSION), True))
			return (IpSteamNetworkingSockets)(&this->SteamNetworkingSockets);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMNETWORKINGMESSAGES_INTERFACE_VERSION), True))
			return (IpSteamNetworkingMessages)(&this->SteamNetworkingMessages);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSocketsSerialized002"), True))
			return (IpSteamNetworkingSocketsSerialized)((pVoid)((IpSteamNetworkingSocketsSerialized002)(&this->SteamNetworkingSocketsSerialized)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSocketsSerialized003"), True))
			return (IpSteamNetworkingSocketsSerialized)((pVoid)((IpSteamNetworkingSocketsSerialized003)(&this->SteamNetworkingSocketsSerialized)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworkingSocketsSerialized004"), True))
			return (IpSteamNetworkingSocketsSerialized)((pVoid)((IpSteamNetworkingSocketsSerialized004)(&this->SteamNetworkingSocketsSerialized)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMNETWORKINGSOCKETSSERIALIZED_INTERFACE_VERSION), True))
			return (IpSteamNetworkingSocketsSerialized)(&this->SteamNetworkingSocketsSerialized);

	}

	return NULL;

}

IpSteamUserStats _SteamClient_::GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamUserStats");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION001"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION002"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION003"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION004"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION005"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION006"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION007"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION008"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION009"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION010"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUSERSTATS_INTERFACE_VERSION011"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)(STEAMUSERSTATS_INTERFACE_VERSION), True)
		) {
			return (IpSteamUserStats)(&this->SteamUserStats);
		}
	}

	return NULL;

}

IpSteamGameServerStats _SteamClient_::GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamGameServerStats");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMGAMESERVERSTATS_INTERFACE_VERSION), True))
			return (IpSteamGameServerStats)(&this->SteamGameServerStats);
	}

	return NULL;

}

IpSteamApps _SteamClient_::GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamApps");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMAPPS_INTERFACE_VERSION001"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps001)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMAPPS_INTERFACE_VERSION002"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps002)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMAPPS_INTERFACE_VERSION003"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps003)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMAPPS_INTERFACE_VERSION004"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps004)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMAPPS_INTERFACE_VERSION005"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps005)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMAPPS_INTERFACE_VERSION006"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps006)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMAPPS_INTERFACE_VERSION007"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps007)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMAPPS_INTERFACE_VERSION), True))
			return (IpSteamApps)((pVoid)((IpSteamApps)(&this->SteamApps)));
	}

	return NULL;

}

IpSteamNetworking _SteamClient_::GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamNetworking");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworking001"), True))
			return (IpSteamNetworking)((pVoid)((IpSteamNetworking001)(&this->SteamNetworking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworking002"), True))
			return (IpSteamNetworking)((pVoid)((IpSteamNetworking002)(&this->SteamNetworking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworking003"), True))
			return (IpSteamNetworking)((pVoid)((IpSteamNetworking003)(&this->SteamNetworking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworking004"), True))
			return (IpSteamNetworking)((pVoid)((IpSteamNetworking004)(&this->SteamNetworking)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamNetworking005"), True))
			return (IpSteamNetworking)((pVoid)((IpSteamNetworking005)(&this->SteamNetworking)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMNETWORKING_INTERFACE_VERSION), True))
			return (IpSteamNetworking)(&this->SteamNetworking);
	}

	return NULL;

}

IpSteamRemoteStorage _SteamClient_::GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamRemoteStorage");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION001"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage001)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION002"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage002)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION003"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage003)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION004"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage004)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION005"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage005)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION006"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage006)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION007"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage007)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION008"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage008)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION009"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage009)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION010"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage010)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION011"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage011)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION012"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage012)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION013"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage013)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION014"), True))
			return (IpSteamRemoteStorage)((pVoid)((IpSteamRemoteStorage014)(&this->SteamRemoteStorage)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMREMOTESTORAGE_INTERFACE_VERSION), True))
			return (IpSteamRemoteStorage)(&this->SteamRemoteStorage);
	}

	return NULL;

}

IpSteamScreenshots _SteamClient_::GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamScreenshots");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMSCREENSHOTS_INTERFACE_VERSION), True))
			return (IpSteamScreenshots)(&this->SteamScreenshots);
	}

	return NULL;

}

IpSteamGameSearch _SteamClient_::GetISteamGameSearch(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamGameSearch");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMGAMESEARCH_INTERFACE_VERSION), True))
			return (IpSteamGameSearch)(&this->SteamGameSearch);
	}

	return NULL;

}

void _SteamClient_::RunFrame() {
	DEBUGBREAK("ISteamClient::RunFrame");

	/* Empty Method */

}

Uint32 _SteamClient_::GetIPCCallCount() {
	DEBUGBREAK("ISteamClient::GetIPCCallCount");

	return 0U;

}

void _SteamClient_::SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) {
	DEBUGBREAK("ISteamClient::SetWarningMessageHook");

	/* Empty Method */

}

Bool _SteamClient_::BShutdownIfAllPipesClosed() {
	DEBUGBREAK("ISteamClient::BShutdownIfAllPipesClosed");

	return True;

}

#ifdef _PS3
IpSteamPS3OverlayRender _SteamClient_::GetISteamPS3OverlayRender() {
	DEBUGBREAK("ISteamClient::GetISteamPS3OverlayRender");

	DEBUG_OUT("SteamPS3OverlayRender001");
	return (IpSteamPS3OverlayRender)(&this->SteamPS3OverlayRender);

}
#endif

IpSteamHTTP _SteamClient_::GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamHTTP");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMHTTP_INTERFACE_VERSION001"), True))
			return (IpSteamHTTP)((pVoid)((IpSteamHTTP001)(&this->SteamHTTP)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMHTTP_INTERFACE_VERSION002"), True))
			return (IpSteamHTTP)((pVoid)((IpSteamHTTP002)(&this->SteamHTTP)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMHTTP_INTERFACE_VERSION), True))
			return (IpSteamHTTP)(&this->SteamHTTP);
	}

	return NULL;

}

IpSteamUnifiedMessages _SteamClient_::DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::DEPRECATED_GetISteamUnifiedMessages");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMUNIFIEDMESSAGES_INTERFACE_VERSION), True))
			return (IpSteamUnifiedMessages)(&this->SteamUnifiedMessages);
	}

	return NULL;

}

IpSteamController _SteamClient_::GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamController");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamController001"), True))
			return (IpSteamController)((pVoid)((IpSteamController001)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamController002"), True))
			return (IpSteamController)((pVoid)((IpSteamController002)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamController003"), True))
			return (IpSteamController)((pVoid)((IpSteamController003)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamController004"), True))
			return (IpSteamController)((pVoid)((IpSteamController004)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamController005"), True))
			return (IpSteamController)((pVoid)((IpSteamController005)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamController006"), True))
			return (IpSteamController)((pVoid)((IpSteamController006)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamController007"), True))
			return (IpSteamController)((pVoid)((IpSteamController007)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMCONTROLLER_INTERFACE_VERSION), True))
			return (IpSteamController)(&this->SteamController);
	}

	return NULL;

}

IpSteamUGC _SteamClient_::GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamUGC");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION001"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION002"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION003"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION004"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION005"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION006"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION007"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION008"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION009"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION010"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION011"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION012"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION013"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION014"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION015"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)("STEAMUGC_INTERFACE_VERSION016"), True) ||
			StrA_Cmp(pchVersion, (pCStrA)(STEAMUGC_INTERFACE_VERSION), True)
		) {
			return (IpSteamUGC)(&this->SteamUGC);
		}
	}

	return NULL;

}

IpSteamAppList _SteamClient_::GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamAppList");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMAPPLIST_INTERFACE_VERSION), True))
			return (IpSteamAppList)(&this->SteamAppList);
	}

	return NULL;

}

IpSteamMusic _SteamClient_::GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamMusic");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMMUSIC_INTERFACE_VERSION), True))
			return (IpSteamMusic)(&this->SteamMusic);
	}

	return NULL;

}

IpSteamMusicRemote _SteamClient_::GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamMusicRemote");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMMUSICREMOTE_INTERFACE_VERSION), True))
			return (IpSteamMusicRemote)(&this->SteamMusicRemote);
	}

	return NULL;

}

IpSteamHTMLSurface _SteamClient_::GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamHTMLSurface");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_001"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface001)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_002"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface002)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_003"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface003)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_004"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface004)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMHTMLSURFACE_INTERFACE_VERSION), True))
			return (IpSteamHTMLSurface)(&this->SteamHTMLSurface);
	}

	return NULL;

}

void _SteamClient_::DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void(*pFunction)()) {
	DEBUGBREAK("ISteamClient::DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess");

	/* Empty Method */

}

void _SteamClient_::DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void(*pFunction)()) {
	DEBUGBREAK("ISteamClient::DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess");

	/* Empty Method */

}

void _SteamClient_::Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) {
	DEBUGBREAK("ISteamClient::Set_SteamAPI_CCheckCallbackRegisteredInProcess");

	/* Empty Method */

}

IpSteamInventory _SteamClient_::GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamInventory");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMINVENTORY_INTERFACE_V001"), True))
			return (IpSteamInventory)((pVoid)((IpSteamInventory001)(&this->SteamInventory)));
		if (StrA_Cmp(pchVersion, (pCStrA)("STEAMINVENTORY_INTERFACE_V002"), True))
			return (IpSteamInventory)((pVoid)((IpSteamInventory002)(&this->SteamInventory)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMINVENTORY_INTERFACE_VERSION), True))
			return (IpSteamInventory)(&this->SteamInventory);
	}

	return NULL;

}

IpSteamVideo _SteamClient_::GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamVideo");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMVIDEO_INTERFACE_VERSION), True))
			return (IpSteamVideo)(&this->SteamVideo);
	}

	return NULL;

}

IpSteamParentalSettings _SteamClient_::GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamParentalSettings");
	
	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMPARENTALSETTINGS_INTERFACE_VERSION), True))
			return (IpSteamParentalSettings)(&this->SteamParentalSettings);
	}

	return NULL;

}

IpSteamInput _SteamClient_::GetISteamInput(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamInput");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamInput001"), True))
			return (IpSteamInput)((pVoid)((IpSteamInput001)(&this->SteamInput)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamInput002"), True))
			return (IpSteamInput)((pVoid)((IpSteamInput002)(&this->SteamInput)));
		if (StrA_Cmp(pchVersion, (pCStrA)("SteamInput005"), True))
			return (IpSteamInput)((pVoid)((IpSteamInput005)(&this->SteamInput)));
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMINPUT_INTERFACE_VERSION), True))
			return (IpSteamInput)(&this->SteamInput);
	}

	return NULL;

}

IpSteamParties _SteamClient_::GetISteamParties(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamParties");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMPARTIES_INTERFACE_VERSION), True))
			return (IpSteamParties)(&this->SteamParties);
	}

	return NULL;

}

IpSteamRemotePlay _SteamClient_::GetISteamRemotePlay(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamRemotePlay");

	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMREMOTEPLAY_INTERFACE_VERSION), True))
			return (IpSteamRemotePlay)(&this->SteamRemotePlay);
	}

	return NULL;

}

IpSteamContentServer _SteamClient_::GetISteamContentServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamContentServer");
	
	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		DEBUG_OUT("Not Implemented");
		return NULL;
	}

	return NULL;

}

IpSteamMasterServerUpdater _SteamClient_::GetISteamMasterServerUpdater(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("ISteamClient::GetISteamMasterServerUpdater");
	
	if (pchVersion != NULL) {
		DEBUG_OUT(pchVersion);
		if (StrA_Cmp(pchVersion, (pCStrA)(STEAMMASTERSERVERUPDATER_INTERFACE_VERSION), True))
			return (IpSteamMasterServerUpdater)(&this->SteamMasterServerUpdater);
	}

	return NULL;

}

void _SteamClient_::DestroyAllInterfaces() {
	DEBUGBREAK("ISteamClient::DestroyAllInterfaces");

	/* Empty Method */

}
