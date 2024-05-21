// -----------------------------------------------------------------------------
#include "SteamClient.h"
// -----------------------------------------------------------------------------

HSteamPipe _SteamClient_::CreateSteamPipe() {

	return k_HSteamPipe_Client;

}

Bool _SteamClient_::BReleaseSteamPipe(HSteamPipe hSteamPipe) {

	return True;

}

HSteamUser _SteamClient_::ConnectToGlobalUser(HSteamPipe hSteamPipe) {

	return k_HSteamUser_LocalUser;

}

HSteamUser _SteamClient_::CreateLocalUser(pHSteamPipe phSteamPipe) {
	
	if (phSteamPipe != NULL) {
		*phSteamPipe = k_HSteamPipe_Client;
	}

	return k_HSteamUser_LocalUser;

}

HSteamUser _SteamClient_::CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) {

	if (phSteamPipe != NULL) {
		*phSteamPipe = k_HSteamPipe_Client;
	}

	return k_HSteamUser_LocalUser;

}

void _SteamClient_::ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) {

	/* Empty Method */

}

IpSteamUser _SteamClient_::GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser006"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser007"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser008"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser009"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser010"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser011"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser012"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser013"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser014"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser015"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser016"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser017"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser018"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser019"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser020"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser021"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUser022"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMUSER_INTERFACE_VERSION), True)
		) {
			return (IpSteamUser)(&this->SteamUser);
		}
	}

	return NULL;

}

IpSteamGameServer _SteamClient_::GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer004"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer004)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer005"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer005)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer008"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer008)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer009"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer009)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer010"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer010)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer011"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer011)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer012"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer012)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer013"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer013)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamGameServer014"), True))
			return (IpSteamGameServer)((pVoid)((IpSteamGameServer014)(&this->SteamGameServer)));
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMGAMESERVER_INTERFACE_VERSION), True))
			return (IpSteamGameServer)(&this->SteamGameServer);
	}

	return NULL;

}

void _SteamClient_::SetLocalIPBinding(Uint32 nIP, Uint16 Port) {

	/* Empty Method */

}

void _SteamClient_::SetLocalIPBinding(const pSteamIPAddress_t pSteamIPAdrr, Uint16 Port) {

	/* Empty Method */

}

IpSteamFriends _SteamClient_::GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends003"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends003)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends004"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends004)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends005"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends005)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends006"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends006)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends007"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends007)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends008"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends008)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends009"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends009)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends010"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends010)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends011"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends011)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends012"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends013)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends014"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends014)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends015"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends015)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamFriends016"), True))
			return (IpSteamFriends)((pVoid)((IpSteamFriends016)(&this->SteamFriends)));
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMFRIENDS_INTERFACE_VERSION), True))
			return (IpSteamFriends)(&this->SteamFriends);
	}

	return NULL;

}

IpSteamUtils _SteamClient_::GetISteamUtils(HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils006"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils007"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils008"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamUtils009"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMUTILS_INTERFACE_VERSION), True)
		) {
			return (IpSteamUtils)(&this->SteamUtils);
		}
	}

	return NULL;

}

IpSteamMatchmaking _SteamClient_::GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking006"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking007"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMaking008"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMMATCHMAKING_INTERFACE_VERSION), True)
		) {
			return (IpSteamMatchmaking)(&this->SteamMatchmaking);
		}
	}

	return NULL;

}

IpSteamMatchmakingServers _SteamClient_::GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamMatchMakingServers001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION), True)
		) {
			return (IpSteamMatchmakingServers)(&this->SteamMatchmakingServers);
		}
	}

	return NULL;

}

pVoid _SteamClient_::GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {

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
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMAPPTICKET_INTERFACE_VERSION), True))
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
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMGAMECOORDINATOR_INTERFACE_VERSION), True))
			return (IpSteamGameCoordinator)(&this->SteamGameCoordinator);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamPS3OverlayRenderer"), True) != SizeOF_MAX)
			return (IpSteamPS3OverlayRenderer)(&this->SteamPS3OverlayRenderer);
		pGeneric = this->GetISteamMasterServerUpdater(hSteamUser, hSteamPipe, pchVersion);
		if (pGeneric != NULL)
			return pGeneric;
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMTV_INTERFACE_VERSION), True))
			return (IpSteamTV)(&this->SteamTV);
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingUtils001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingUtils002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingUtils003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMNETWORKINGUTILS_INTERFACE_VERSION), True)
		)
			return (IpSteamNetworkingUtils)(&this->SteamNetworkingUtils);
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets006"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets007"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets008"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets009"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets010"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSockets011"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMNETWORKINGSOCKETS_INTERFACE_VERSION), True)
		)
			return (IpSteamNetworkingSockets)(&this->SteamNetworkingSockets);
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingMessages001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMNETWORKINGMESSAGES_INTERFACE_VERSION), True)
		)
			return (IpSteamNetworkingMessages)(&this->SteamNetworkingMessages);
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworkingSocketsSerialized001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMNETWORKINGSOCKETSSERIALIZED_INTERFACE_VERSION), True)
		)
			return (IpSteamNetworkingSocketsSerialized)(&this->SteamNetworkingSocketsSerialized);

	}

	return NULL;

}

IpSteamUserStats _SteamClient_::GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION006"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION007"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION008"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION009"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION010"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUSERSTATS_INTERFACE_VERSION011"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMUSERSTATS_INTERFACE_VERSION), True)
		) {
			return (IpSteamUserStats)(&this->SteamUserStats);
		}
	}

	return NULL;

}

IpSteamGameServerStats _SteamClient_::GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMGAMESERVERSTATS_INTERFACE_VERSION), True)) {
			return (IpSteamGameServerStats)(&this->SteamGameServerStats);
		}
	}

	return NULL;

}

IpSteamApps _SteamClient_::GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMAPPS_INTERFACE_VERSION001"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps001)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMAPPS_INTERFACE_VERSION002"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps002)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMAPPS_INTERFACE_VERSION003"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps003)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMAPPS_INTERFACE_VERSION004"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps004)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMAPPS_INTERFACE_VERSION005"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps005)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMAPPS_INTERFACE_VERSION006"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps006)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMAPPS_INTERFACE_VERSION007"), True))
			return (IpSteamApps)((pVoid)((IpSteamApps007)(&this->SteamApps)));
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMAPPS_INTERFACE_VERSION), True))
			return (IpSteamApps)((pVoid)((IpSteamApps)(&this->SteamApps)));
	}

	return NULL;

}

IpSteamNetworking _SteamClient_::GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworking001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworking002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworking003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworking004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamNetworking005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMNETWORKING_INTERFACE_VERSION), True)
		) {
			return (IpSteamNetworking)(&this->SteamNetworking);
		}
	}

	return NULL;

}

IpSteamRemoteStorage _SteamClient_::GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION006"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION007"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION008"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION009"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION010"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION011"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION012"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION013"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION014"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMREMOTESTORAGE_INTERFACE_VERSION015"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMREMOTESTORAGE_INTERFACE_VERSION), True)
		) {
			return (IpSteamRemoteStorage)(&this->SteamRemoteStorage);
		}
	}

	return NULL;

}

IpSteamScreenshots _SteamClient_::GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("STEAMSCREENSHOTS_INTERFACE_VERSION001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMSCREENSHOTS_INTERFACE_VERSION002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMSCREENSHOTS_INTERFACE_VERSION), True)
			) {
			return (IpSteamScreenshots)(&this->SteamScreenshots);
		}
	}

	return NULL;

}

IpSteamGameSearch _SteamClient_::GetISteamGameSearch(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMGAMESEARCH_INTERFACE_VERSION), True)) {
			return (IpSteamGameSearch)(&this->SteamGameSearch);
		}
	}

	return NULL;

}

void _SteamClient_::RunFrame() {

	/* Empty Method */

}

Uint32 _SteamClient_::GetIPCCallCount() {

	return 0U;

}

void _SteamClient_::SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction) {

	/* Empty Method */

}

Bool _SteamClient_::BShutdownIfAllPipesClosed() {

	return True;

}

IpSteamHTTP _SteamClient_::GetISteamHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("STEAMHTTP_INTERFACE_VERSION001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMHTTP_INTERFACE_VERSION002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMHTTP_INTERFACE_VERSION), True)
		) {
			return (IpSteamHTTP)(&this->SteamHTTP);
		}
	}

	return NULL;

}

IpSteamUnifiedMessages _SteamClient_::DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMUNIFIEDMESSAGES_INTERFACE_VERSION), True)) {
			return (IpSteamUnifiedMessages)(&this->SteamUnifiedMessages);
		}
	}

	return NULL;

}

IpSteamController _SteamClient_::GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamController001"), True))
			return (IpSteamController)((pVoid)((IpSteamController001)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamController002"), True))
			return (IpSteamController)((pVoid)((IpSteamController002)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamController003"), True))
			return (IpSteamController)((pVoid)((IpSteamController003)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamController004"), True))
			return (IpSteamController)((pVoid)((IpSteamController004)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamController005"), True))
			return (IpSteamController)((pVoid)((IpSteamController005)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamController006"), True))
			return (IpSteamController)((pVoid)((IpSteamController006)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (const pStrA)("SteamController007"), True))
			return (IpSteamController)((pVoid)((IpSteamController007)(&this->SteamController)));
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMCONTROLLER_INTERFACE_VERSION), True))
			return (IpSteamController)(&this->SteamController);
	}

	return NULL;

}

IpSteamUGC _SteamClient_::GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION006"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION007"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION008"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION009"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION010"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION011"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION012"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION013"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION014"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION015"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMUGC_INTERFACE_VERSION016"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMUGC_INTERFACE_VERSION), True)
		) {
			return (IpSteamUGC)(&this->SteamUGC);
		}
	}

	return NULL;

}

IpSteamAppList _SteamClient_::GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMAPPLIST_INTERFACE_VERSION), True)) {
			return (IpSteamAppList)(&this->SteamAppList);
		}
	}

	return NULL;

}

IpSteamMusic _SteamClient_::GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMMUSIC_INTERFACE_VERSION), True)) {
			return (IpSteamMusic)(&this->SteamMusic);
		}
	}

	return NULL;

}

IpSteamMusicRemote _SteamClient_::GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMMUSICREMOTE_INTERFACE_VERSION), True)) {
			return (IpSteamMusicRemote)(&this->SteamMusicRemote);
		}
	}

	return NULL;

}

IpSteamHTMLSurface _SteamClient_::GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_001"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface001)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_002"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface002)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_003"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface003)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (const pStrA)("STEAMHTMLSURFACE_INTERFACE_VERSION_004"), True))
			return (IpSteamHTMLSurface)((pVoid)((IpSteamHTMLSurface004)(&this->SteamHTMLSurface)));
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMHTMLSURFACE_INTERFACE_VERSION), True))
			return (IpSteamHTMLSurface)(&this->SteamHTMLSurface);
	}

	return NULL;

}

void _SteamClient_::DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void(*pFunction)()) {

	/* Empty Method */

}

void _SteamClient_::DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void(*pFunction)()) {

	/* Empty Method */

}

void _SteamClient_::Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t pFunction) {

	/* Empty Method */

}

IpSteamInventory _SteamClient_::GetISteamInventory(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("STEAMINVENTORY_INTERFACE_V001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("STEAMINVENTORY_INTERFACE_V002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMINVENTORY_INTERFACE_VERSION), True)
		) {
			return (IpSteamInventory)(&this->SteamInventory);
		}
	}

	return NULL;

}

IpSteamVideo _SteamClient_::GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("STEAMVIDEO_INTERFACE_V001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMVIDEO_INTERFACE_VERSION), True)
		) {
			return (IpSteamVideo)(&this->SteamVideo);
		}
	}

	return NULL;

}

IpSteamParentalSettings _SteamClient_::GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMPARENTALSETTINGS_INTERFACE_VERSION), True)) {
			return (IpSteamParentalSettings)(&this->SteamParentalSettings);
		}
	}

	return NULL;

}

IpSteamInput _SteamClient_::GetISteamInput(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamInput001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamInput002"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamInput003"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamInput004"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)("SteamInput005"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMINPUT_INTERFACE_VERSION), True)
		) {
			return (IpSteamInput)(&this->SteamInput);
		}
	}

	return NULL;

}

IpSteamParties _SteamClient_::GetISteamParties(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (
			StrA_Cmp(pchVersion, (const pStrA)("SteamParties001"), True) ||
			StrA_Cmp(pchVersion, (const pStrA)(STEAMPARTIES_INTERFACE_VERSION), True)
		) {
			return (IpSteamParties)(&this->SteamParties);
		}
	}

	return NULL;

}

IpSteamRemotePlay _SteamClient_::GetISteamRemotePlay(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMREMOTEPLAY_INTERFACE_VERSION), True)) {
			return (IpSteamRemotePlay)(&this->SteamRemotePlay);
		}
	}

	return NULL;

}

IpSteamContentServer _SteamClient_::GetISteamContentServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {
	
	if (pchVersion != NULL) {
		return NULL;
	}

	return NULL;

}

IpSteamMasterServerUpdater _SteamClient_::GetISteamMasterServerUpdater(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {
	
	if (pchVersion != NULL) {
		if (StrA_Cmp(pchVersion, (const pStrA)(STEAMMASTERSERVERUPDATER_INTERFACE_VERSION), True)) {
			return (IpSteamMasterServerUpdater)(&this->SteamMasterServerUpdater);
		}
	}

	return NULL;

}

void _SteamClient_::DestroyAllInterfaces() {

	/* Empty Method */

}
