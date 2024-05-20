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

HSteamUser _SteamClient_::CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) {

	return k_HSteamUser_LocalUser;

}

void _SteamClient_::ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) {

	/* Empty Method */

}

IpSteamUser _SteamClient_::GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamUser"), True) != SizeOF_MAX) {
			return (IpSteamUser)(&this->SteamUser);
		}
	}

	return NULL;

}

IpSteamGameServer _SteamClient_::GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamGameServer"), True) != SizeOF_MAX) {
			return (IpSteamGameServer)(&this->SteamGameServer);
		}
	}

	return NULL;

}

void _SteamClient_::SetLocalIPBinding(const pSteamIPAddress_t pSteamIPAdrr, Uint16 Port) {

	/* Empty Method */

}

IpSteamFriends _SteamClient_::GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamFriends"), True) != SizeOF_MAX) {
			return (IpSteamFriends)(&this->SteamFriends);
		}
	}

	return NULL;

}

IpSteamUtils _SteamClient_::GetISteamUtils(HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamUtils"), True) != SizeOF_MAX) {
			return (IpSteamUtils)(&this->SteamUtils);
		}
	}

	return NULL;

}

IpSteamMatchmaking _SteamClient_::GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamMatchmaking"), True) != SizeOF_MAX) {
			return (IpSteamMatchmaking)(&this->SteamMatchmaking);
		}
	}

	return NULL;

}

IpSteamMatchmakingServers _SteamClient_::GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamMatchmakingServers"), True) != SizeOF_MAX) {
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
		if (StrA_StrA(pchVersion, (const pStrA)("SteamAppTicket"), True) != SizeOF_MAX)
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
		if (StrA_StrA(pchVersion, (const pStrA)("SteamUnifiedMessages"), True) != SizeOF_MAX)
			return (IpSteamUnifiedMessages)(&this->SteamUnifiedMessages);
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
		if (StrA_StrA(pchVersion, (const pStrA)("SteamGameCoordinator"), True) != SizeOF_MAX)
			return (IpSteamGameCoordinator)(&this->SteamGameCoordinator);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamPS3OverlayRenderer"), True) != SizeOF_MAX)
			return (IpSteamPS3OverlayRenderer)(&this->SteamPS3OverlayRenderer);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamMasterServerUpdater"), True) != SizeOF_MAX)
			return (IpSteamMasterServerUpdater)(&this->SteamMasterServerUpdater);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamTV"), True) != SizeOF_MAX)
			return (IpSteamTV)(&this->SteamTV);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamNetworkingUtils"), True) != SizeOF_MAX)
			return (IpSteamNetworkingUtils)(&this->SteamNetworkingUtils);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamNetworkingSockets"), True) != SizeOF_MAX)
			return (IpSteamNetworkingSockets)(&this->SteamNetworkingSockets);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamNetworkingMessages"), True) != SizeOF_MAX)
			return (IpSteamNetworkingMessages)(&this->SteamNetworkingMessages);
		if (StrA_StrA(pchVersion, (const pStrA)("SteamNetworkingSocketsSerialized"), True) != SizeOF_MAX)
			return (IpSteamNetworkingSocketsSerialized)(&this->SteamNetworkingSocketsSerialized);

	}

	return NULL;

}

IpSteamUserStats _SteamClient_::GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamUserStats"), True) != SizeOF_MAX) {
			return (IpSteamUserStats)(&this->SteamUserStats);
		}
	}

	return NULL;

}

IpSteamGameServerStats _SteamClient_::GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamGameServerStats"), True) != SizeOF_MAX) {
			return (IpSteamGameServerStats)(&this->SteamGameServerStats);
		}
	}

	return NULL;

}

IpSteamApps _SteamClient_::GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamApps"), True) != SizeOF_MAX) {
			return (IpSteamApps)(&this->SteamApps);
		}
	}

	return NULL;

}

IpSteamNetworking _SteamClient_::GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamNetworking"), True) != SizeOF_MAX) {
			return (IpSteamNetworking)(&this->SteamNetworking);
		}
	}

	return NULL;

}

IpSteamRemoteStorage _SteamClient_::GetISteamRemoteStorage(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamRemoteStorage"), True) != SizeOF_MAX) {
			return (IpSteamRemoteStorage)(&this->SteamRemoteStorage);
		}
	}

	return NULL;

}

IpSteamScreenshots _SteamClient_::GetISteamScreenshots(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamScreenshots"), True) != SizeOF_MAX) {
			return (IpSteamScreenshots)(&this->SteamScreenshots);
		}
	}

	return NULL;

}

IpSteamGameSearch _SteamClient_::GetISteamGameSearch(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamGameSearch"), True) != SizeOF_MAX) {
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
		if (StrA_StrA(pchVersion, (const pStrA)("SteamHTTP"), True) != SizeOF_MAX) {
			return (IpSteamHTTP)(&this->SteamHTTP);
		}
	}

	return NULL;

}

IpSteamUnifiedMessages _SteamClient_::DEPRECATED_GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamUnifiedMessages"), True) != SizeOF_MAX) {
			return (IpSteamUnifiedMessages)(&this->SteamUnifiedMessages);
		}
	}

	return NULL;

}

IpSteamController _SteamClient_::GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamController"), True) != SizeOF_MAX) {
			return (IpSteamController)(&this->SteamController);
		}
	}

	return NULL;

}

IpSteamUGC _SteamClient_::GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamUGC"), True) != SizeOF_MAX) {
			return (IpSteamUGC)(&this->SteamUGC);
		}
	}

	return NULL;

}

IpSteamAppList _SteamClient_::GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamAppList"), True) != SizeOF_MAX) {
			return (IpSteamAppList)(&this->SteamAppList);
		}
	}

	return NULL;

}

IpSteamMusic _SteamClient_::GetISteamMusic(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamMusic"), True) != SizeOF_MAX) {
			return (IpSteamMusic)(&this->SteamMusic);
		}
	}

	return NULL;

}

IpSteamMusicRemote _SteamClient_::GetISteamMusicRemote(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamMusicRemote"), True) != SizeOF_MAX) {
			return (IpSteamMusicRemote)(&this->SteamMusicRemote);
		}
	}

	return NULL;

}

IpSteamHTMLSurface _SteamClient_::GetISteamHTMLSurface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamHTMLSurface"), True) != SizeOF_MAX) {
			return (IpSteamHTMLSurface)(&this->SteamHTMLSurface);
		}
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
		if (StrA_StrA(pchVersion, (const pStrA)("SteamInventory"), True) != SizeOF_MAX) {
			return (IpSteamInventory)(&this->SteamInventory);
		}
	}

	return NULL;

}

IpSteamVideo _SteamClient_::GetISteamVideo(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamVideo"), True) != SizeOF_MAX) {
			return (IpSteamVideo)(&this->SteamVideo);
		}
	}

	return NULL;

}

IpSteamParentalSettings _SteamClient_::GetISteamParentalSettings(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamParentalSettings"), True) != SizeOF_MAX) {
			return (IpSteamParentalSettings)(&this->SteamParentalSettings);
		}
	}

	return NULL;

}

IpSteamInput _SteamClient_::GetISteamInput(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamInput"), True) != SizeOF_MAX) {
			return (IpSteamInput)(&this->SteamInput);
		}
	}

	return NULL;

}

IpSteamParties _SteamClient_::GetISteamParties(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamParties"), True) != SizeOF_MAX) {
			return (IpSteamParties)(&this->SteamParties);
		}
	}

	return NULL;

}

IpSteamRemotePlay _SteamClient_::GetISteamRemotePlay(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const pStrA pchVersion) {

	if (pchVersion != NULL) {
		if (StrA_StrA(pchVersion, (const pStrA)("SteamRemotePlay"), True) != SizeOF_MAX) {
			return (IpSteamRemotePlay)(&this->SteamRemotePlay);
		}
	}

	return NULL;

}

void _SteamClient_::DestroyAllInterfaces() {

	/* Empty Method */

}
