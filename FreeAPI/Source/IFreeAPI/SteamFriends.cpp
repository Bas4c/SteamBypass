// -----------------------------------------------------------------------------
#include "SteamFriends.h"
// -----------------------------------------------------------------------------

_SteamFriends_::_SteamFriends_() {

	this->chString[0] = '\0';

}

pCStrA _SteamFriends_::GetPersonaName() {
	DEBUGBREAK("ISteamFriends::GetPersonaName");

	return (pCStrA)(
		"LocalPlayer"
	);

}

SteamAPICall_t _SteamFriends_::SetPersonaName(pCStrA pchPersonaName) {
	DEBUGBREAK("ISteamFriends::SetPersonaName");

	return k_SteamAPICall_Invalid;

}

EPersonaState _SteamFriends_::GetPersonaState() {
	DEBUGBREAK("ISteamFriends::GetPersonaState");

	return k_EPersonaStateOffline;

}

Int32 _SteamFriends_::GetFriendCount(Int32 iFriendFlags) {
	DEBUGBREAK("ISteamFriends::GetFriendCount");

	return 0;

}

SteamId_t _SteamFriends_::GetFriendByIndex(Int32 iFriend, Int32 iFriendFlags) {
	DEBUGBREAK("ISteamFriends::GetFriendByIndex");

	return SteamId_t{ k_SteamId_t_Invalid };

}

EFriendRelationship _SteamFriends_::GetFriendRelationship(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendRelationship");

	return k_EFriendRelationshipNone;

}

EPersonaState _SteamFriends_::GetFriendPersonaState(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendPersonaState");

	return k_EPersonaStateOffline;

}

pCStrA _SteamFriends_::GetFriendPersonaName(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendPersonaName");

	if (SteamIdFriend.SteamId_Uint64 == k_SteamId_t_LocalUser) {
		return (pCStrA)("LocalPlayer");
	}

	return (pCStrA)(
		"SteamFriend"
	);

}

Int32 _SteamFriends_::GetFriendAvatar(SteamId_t SteamIdFriend, EAvatarSize eAvatarSize) {
	DEBUGBREAK("ISteamFriends::GetFriendAvatar");
	
	return 0;

}

Bool _SteamFriends_::GetFriendGamePlayed(SteamId_t SteamIdFriend, pFriendGameInfo_t pFriendGameInfo) {
	DEBUGBREAK("ISteamFriends::GetFriendGamePlayed");

	return False;

}

pCStrA _SteamFriends_::GetFriendPersonaNameHistory(SteamId_t SteamIdFriend, Int32 iPersonaName) {
	DEBUGBREAK("ISteamFriends::GetFriendPersonaNameHistory");

	return (pCStrA)(
		""
	);

}

Int32 _SteamFriends_::GetFriendSteamLevel(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendSteamLevel");

	return Int32_MAX;

}

pCStrA _SteamFriends_::GetPlayerNickname(SteamId_t SteamIdPlayer) {
	DEBUGBREAK("ISteamFriends::GetPlayerNickname");

	if (SteamIdPlayer.SteamId_Uint64 == k_SteamId_t_LocalUser) {
		return (pCStrA)("LocalPlayer");
	}

	return (pCStrA)(
		"SteamPlayer"
	);

}

Int32 _SteamFriends_::GetFriendsGroupCount() {
	DEBUGBREAK("ISteamFriends::GetFriendsGroupCount");

	return 0;

}

FriendsGroupId_t _SteamFriends_::GetFriendsGroupIDByIndex(Int32 iFG) {
	DEBUGBREAK("ISteamFriends::GetFriendsGroupIDByIndex");

	return k_FriendsGroupId_Invalid;

}

pCStrA _SteamFriends_::GetFriendsGroupName(FriendsGroupId_t FriendsGroupId) {
	DEBUGBREAK("ISteamFriends::GetFriendsGroupName");

	return (pCStrA)(
		"FriendGroup"
	);

}

Int32 _SteamFriends_::GetFriendsGroupMembersCount(FriendsGroupId_t FriendsGroupId) {
	DEBUGBREAK("ISteamFriends::GetFriendsGroupMembersCount");

	return 0;

}

void _SteamFriends_::GetFriendsGroupMembersList(FriendsGroupId_t FriendsGroupId, pSteamId_t pnSteamIdMembers, Int32 nMembers) {
	DEBUGBREAK("ISteamFriends::GetFriendsGroupMembersList");

	if (pnSteamIdMembers != NULL && nMembers > 0) {
		for (Int32 i = 0; i < nMembers; i++) {
			pnSteamIdMembers[i] = SteamId_t{ k_SteamId_t_Invalid };
		}
	}

}

Bool _SteamFriends_::HasFriend(SteamId_t SteamIdFriend, Int32 iFriendFlags) {
	DEBUGBREAK("ISteamFriends::HasFriend");

	return False;

}

Int32 _SteamFriends_::GetClanCount() {
	DEBUGBREAK("ISteamFriends::GetClanCount");

	return 0;

}

SteamId_t _SteamFriends_::GetClanByIndex(Int32 iClan) {
	DEBUGBREAK("ISteamFriends::GetClanByIndex");

	return SteamId_t{ k_SteamId_t_Invalid };

}

pCStrA _SteamFriends_::GetClanName(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::GetClanName");

	return (pCStrA)(
		"Generic"
	);

}

pCStrA _SteamFriends_::GetClanTag(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::GetClanTag");

	return this->GetClanName(SteamIdClan);
}

Bool _SteamFriends_::GetClanActivityCounts(SteamId_t SteamIdClan, pInt32 pnOnline, pInt32 pnInGame, pInt32 pnChatting) {
	DEBUGBREAK("ISteamFriends::GetClanActivityCounts");

	return False;

}

SteamAPICall_t _SteamFriends_::DownloadClanActivityCounts(pSteamId_t pnSteamIdClans, Int32 nClansToRequest) {
	DEBUGBREAK("ISteamFriends::DownloadClanActivityCounts");

	return k_SteamAPICall_Invalid;

}

Int32 _SteamFriends_::GetFriendCountFromSource(SteamId_t SteamIdSource) {
	DEBUGBREAK("ISteamFriends::GetFriendCountFromSource");

	return 0;

}

SteamId_t _SteamFriends_::GetFriendFromSourceByIndex(SteamId_t SteamIdSource, Int32 iFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendFromSourceByIndex");

	return SteamId_t{ k_SteamId_t_Invalid };

}

Bool _SteamFriends_::IsUserInSource(SteamId_t SteamIdUser, SteamId_t SteamIdSource) {
	DEBUGBREAK("ISteamFriends::IsUserInSource");

	return False;

}

void _SteamFriends_::SetInGameVoiceSpeaking(SteamId_t SteamIdUser, Bool bSpeaking) {
	DEBUGBREAK("ISteamFriends::SetInGameVoiceSpeaking");

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlay(pCStrA pchDialogName) {
	DEBUGBREAK("ISteamFriends::ActivateGameOverlay");

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayToUser(pCStrA pchDialog, SteamId_t SteamId) {
	DEBUGBREAK("ISteamFriends::ActivateGameOverlayToUser");

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayToWebPage(pCStrA pchURL, EActivateGameOverlayToWebPageMode eActivateGameOverlayToWebPageMode) {
	DEBUGBREAK("ISteamFriends::ActivateGameOverlayToWebPage");

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayToStore(AppId_t iAppId, EOverlayToStoreFlag eOverlayToStoreFlag) {
	DEBUGBREAK("ISteamFriends::ActivateGameOverlayToStore");

	/* Empty Method */

}

void _SteamFriends_::SetPlayedWith(SteamId_t SteamIdUserPlayedWith) {
	DEBUGBREAK("ISteamFriends::SetPlayedWith");

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayInviteDialog(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamFriends::ActivateGameOverlayInviteDialog");

	/* Empty Method */

}

Int32 _SteamFriends_::GetSmallFriendAvatar(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetSmallFriendAvatar");

	return 0;

}

Int32 _SteamFriends_::GetMediumFriendAvatar(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetMediumFriendAvatar");

	return 0;

}

Int32 _SteamFriends_::GetLargeFriendAvatar(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetLargeFriendAvatar");

	return 0;

}

Bool _SteamFriends_::RequestUserInformation(SteamId_t SteamIdUser, Bool bRequireNameOnly) {
	DEBUGBREAK("ISteamFriends::RequestUserInformation");

	return False;

}

SteamAPICall_t _SteamFriends_::RequestClanOfficerList(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::RequestClanOfficerList");

	return k_SteamAPICall_Invalid;

}

SteamId_t _SteamFriends_::GetClanOwner(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::GetClanOwner");

	return SteamId_t{ k_SteamId_t_Invalid };

}

Int32 _SteamFriends_::GetClanOfficerCount(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::GetClanOfficerCount");

	return 0;

}

SteamId_t _SteamFriends_::GetClanOfficerByIndex(SteamId_t SteamIdClan, Int32 iOfficer) {
	DEBUGBREAK("ISteamFriends::GetClanOfficerByIndex");

	return SteamId_t{ k_SteamId_t_Invalid };

}

Uint32 _SteamFriends_::GetUserRestrictions() {
	DEBUGBREAK("ISteamFriends::GetUserRestrictions");

	return 0U;

}

Bool _SteamFriends_::SetRichPresence(pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamFriends::SetRichPresence");

	return False;

}

void _SteamFriends_::ClearRichPresence() {
	DEBUGBREAK("ISteamFriends::ClearRichPresence");

	/* Empty Method */

}

pCStrA _SteamFriends_::GetFriendRichPresence(SteamId_t SteamIdFriend, pCStrA pchKey) {
	DEBUGBREAK("ISteamFriends::GetFriendRichPresence");

	return (pCStrA)(
		""
	);

}

Int32 _SteamFriends_::GetFriendRichPresenceKeyCount(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendRichPresenceKeyCount");

	return 0;

}

pCStrA _SteamFriends_::GetFriendRichPresenceKeyByIndex(SteamId_t SteamIdFriend, Int32 iKey) {
	DEBUGBREAK("ISteamFriends::GetFriendRichPresenceKeyByIndex");

	return (pCStrA)(
		""
	);

}

void _SteamFriends_::RequestFriendRichPresence(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::RequestFriendRichPresence");

	/* Empty Method */

}

Bool _SteamFriends_::InviteUserToGame(SteamId_t SteamIdFriend, pCStrA pchConnectString) {
	DEBUGBREAK("ISteamFriends::InviteUserToGame");

	return False;

}

Int32 _SteamFriends_::GetCoplayFriendCount() {
	DEBUGBREAK("ISteamFriends::GetCoplayFriendCount");

	return 0;

}

SteamId_t _SteamFriends_::GetCoplayFriend(Int32 iCoplayFriend) {
	DEBUGBREAK("ISteamFriends::GetCoplayFriend");

	return SteamId_t{ k_SteamId_t_Invalid };

}

Int32 _SteamFriends_::GetFriendCoplayTime(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendCoplayTime");

	return 0;

}

AppId_t _SteamFriends_::GetFriendCoplayGame(SteamId_t SteamIdFriend) {
	DEBUGBREAK("ISteamFriends::GetFriendCoplayGame");

	return k_AppId_t_Invalid;

}

SteamAPICall_t _SteamFriends_::JoinClanChatRoom(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::JoinClanChatRoom");

	return k_SteamAPICall_Invalid;

}

Bool _SteamFriends_::LeaveClanChatRoom(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::LeaveClanChatRoom");

	return False;

}

Int32 _SteamFriends_::GetClanChatMemberCount(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::GetClanChatMemberCount");

	return 0;

}

SteamId_t _SteamFriends_::GetChatMemberByIndex(SteamId_t SteamIdClan, Int32 iUser) {
	DEBUGBREAK("ISteamFriends::GetChatMemberByIndex");

	return SteamId_t{ k_SteamId_t_Invalid };

}

Bool _SteamFriends_::SendClanChatMessage(SteamId_t SteamIdClanChat, pCStrA pchText) {
	DEBUGBREAK("ISteamFriends::SendClanChatMessage");

	return False;

}

Int32 _SteamFriends_::GetClanChatMessage(SteamId_t SteamIdClanChat, Int32 iMessage, pStrA pchText, Int32 cchTextMax, pEChatEntryType peChatEntryType, pSteamId_t pSteamIdChatter) {
	DEBUGBREAK("ISteamFriends::GetClanChatMessage");

	if (pchText != NULL && cchTextMax > 0) {
		pchText[0] = '\0';
	}

	if (peChatEntryType != NULL) {
		*peChatEntryType = k_EChatEntryTypeInvalid;
	}

	if (pSteamIdChatter != NULL) {
		*pSteamIdChatter = SteamId_t{ k_SteamId_t_Invalid };
	}

	return 0;

}

Bool _SteamFriends_::IsClanChatAdmin(SteamId_t SteamIdClanChat, SteamId_t SteamIdUser) {
	DEBUGBREAK("ISteamFriends::IsClanChatAdmin");

	return False;

}

Bool _SteamFriends_::IsClanChatWindowOpenInSteam(SteamId_t SteamIdClanChat) {
	DEBUGBREAK("ISteamFriends::IsClanChatWindowOpenInSteam");

	return False;

}

Bool _SteamFriends_::OpenClanChatWindowInSteam(SteamId_t SteamIdClanChat) {
	DEBUGBREAK("ISteamFriends::OpenClanChatWindowInSteam");

	return False;

}

Bool _SteamFriends_::CloseClanChatWindowInSteam(SteamId_t SteamIdClanChat) {
	DEBUGBREAK("ISteamFriends::CloseClanChatWindowInSteam");

	return False;

}

Bool _SteamFriends_::SetListenForFriendsMessages(Bool bInterceptEnabled) {
	DEBUGBREAK("ISteamFriends::SetListenForFriendsMessages");

	return False;

}

Bool _SteamFriends_::ReplyToFriendMessage(SteamId_t SteamIdFriend, pCStrA pchMsgToSend) {
	DEBUGBREAK("ISteamFriends::ReplyToFriendMessage");

	return False;

}

Int32 _SteamFriends_::GetFriendMessage(SteamId_t SteamIdFriend, Int32 iMessageId, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) {
	DEBUGBREAK("ISteamFriends::GetFriendMessage");

	if (pvData != NULL && cbData > 0) {
		((pStrA)(pvData))[0] = '\0';
	}

	if (peChatEntryType != NULL) {
		*peChatEntryType = k_EChatEntryTypeInvalid;
	}

	return 0;

}

SteamAPICall_t _SteamFriends_::GetFollowerCount(SteamId_t SteamId) {
	DEBUGBREAK("ISteamFriends::GetFollowerCount");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamFriends_::IsFollowing(SteamId_t SteamId) {
	DEBUGBREAK("ISteamFriends::IsFollowing");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamFriends_::EnumerateFollowingList(Uint32 iStart) {
	DEBUGBREAK("ISteamFriends::EnumerateFollowingList");

	return k_SteamAPICall_Invalid;

}

Bool _SteamFriends_::IsClanPublic(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::IsClanPublic");

	return False;

}

Bool _SteamFriends_::IsClanOfficialGameGroup(SteamId_t SteamIdClan) {
	DEBUGBREAK("ISteamFriends::IsClanOfficialGameGroup");

	return False;

}

Int32 _SteamFriends_::GetNumChatsWithUnreadPriorityMessages() {
	DEBUGBREAK("ISteamFriends::GetNumChatsWithUnreadPriorityMessages");

	return 0;

}

void _SteamFriends_::ActivateGameOverlayRemotePlayTogetherInviteDialog(SteamId_t SteamIdLobby) {
	DEBUGBREAK("ISteamFriends::ActivateGameOverlayRemotePlayTogetherInviteDialog");

	/* Empty Method */

}

Bool _SteamFriends_::RegisterProtocolInOverlayBrowser(pCStrA pchProtocol) {
	DEBUGBREAK("ISteamFriends::RegisterProtocolInOverlayBrowser");

	return False;

}

void _SteamFriends_::ActivateGameOverlayInviteDialogConnectString(pCStrA pchConnectString) {
	DEBUGBREAK("ISteamFriends::ActivateGameOverlayInviteDialogConnectString");

	/* Empty Method */

}

SteamAPICall_t _SteamFriends_::RequestEquippedProfileItems(SteamId_t SteamId) {
	DEBUGBREAK("ISteamFriends::RequestEquippedProfileItems");

	return k_SteamAPICall_Invalid;

}

Bool _SteamFriends_::BHasEquippedProfileItem(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType) {
	DEBUGBREAK("ISteamFriends::BHasEquippedProfileItem");

	return False;

}

pCStrA _SteamFriends_::GetProfileItemPropertyString(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) {
	DEBUGBREAK("ISteamFriends::GetProfileItemPropertyString");

	switch (eCommunityProfileItemType) {
		case k_ECommunityProfileItemType_AnimatedAvatar:
			StrA_Copy(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("AnimatedAvatar"));
			break;
		case k_ECommunityProfileItemType_AvatarFrame:
			StrA_Copy(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("AvatarFrame"));
			break;
		case k_ECommunityProfileItemType_ProfileModifier:
			StrA_Copy(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("ProfileModifier"));
			break;
		case k_ECommunityProfileItemType_ProfileBackground:
			StrA_Copy(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("ProfileBackground"));
			break;
		case k_ECommunityProfileItemType_MiniProfileBackground:
			StrA_Copy(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("MiniProfileBackground"));
			break;
	}

	switch (eCommunityProfileItemProperty) {
		case k_ECommunityProfileItemProperty_ImageSmall:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("ImageSmall"));
			break;
		case k_ECommunityProfileItemProperty_ImageLarge:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("ImageLarge"));
			break;
		case k_ECommunityProfileItemProperty_InternalName:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("InternalName"));
			break;
		case k_ECommunityProfileItemProperty_Title:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("Title"));
			break;
		case k_ECommunityProfileItemProperty_Description:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("Description"));
			break;
		case k_ECommunityProfileItemProperty_AppId:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("AppId"));
			break;
		case k_ECommunityProfileItemProperty_TypeId:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("TypeId"));
			break;
		case k_ECommunityProfileItemProperty_Class:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("Class"));
			break;
		case k_ECommunityProfileItemProperty_MovieWebM:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("MovieWebM"));
			break;
		case k_ECommunityProfileItemProperty_MovieMP4:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("MovieMP4"));
			break;
		case k_ECommunityProfileItemProperty_MovieWebMSmall:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("MovieWebMSmall"));
			break;
		case k_ECommunityProfileItemProperty_MovieMP4Small:
			StrA_Cat(this->chString, sizeof(this->chString) / sizeof(CharA),
				(pCStrA)("MovieMP4Small"));
			break;
	}

	return (pCStrA)(
		this->chString
	);

}

Uint32 _SteamFriends_::GetProfileItemPropertyUint(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) {
	DEBUGBREAK("ISteamFriends::GetProfileItemPropertyUint");

	Uint32 itemProperty = 0U;

	switch (eCommunityProfileItemType) {
		case k_ECommunityProfileItemType_AnimatedAvatar:
			itemProperty += k_ECommunityProfileItemType_AnimatedAvatar;
			break;
		case k_ECommunityProfileItemType_AvatarFrame:
			itemProperty += k_ECommunityProfileItemType_AvatarFrame;
			break;
		case k_ECommunityProfileItemType_ProfileModifier:
			itemProperty += k_ECommunityProfileItemType_ProfileModifier;
			break;
		case k_ECommunityProfileItemType_ProfileBackground:
			itemProperty += k_ECommunityProfileItemType_ProfileBackground;
			break;
		case k_ECommunityProfileItemType_MiniProfileBackground:
			itemProperty += k_ECommunityProfileItemType_MiniProfileBackground;
			break;
	}

	switch (eCommunityProfileItemProperty) {
		case k_ECommunityProfileItemProperty_ImageSmall:
			itemProperty += k_ECommunityProfileItemProperty_ImageSmall;
			break;
		case k_ECommunityProfileItemProperty_ImageLarge:
			itemProperty += k_ECommunityProfileItemProperty_ImageLarge;
			break;
		case k_ECommunityProfileItemProperty_InternalName:
			itemProperty += k_ECommunityProfileItemProperty_InternalName;
			break;
		case k_ECommunityProfileItemProperty_Title:
			itemProperty += k_ECommunityProfileItemProperty_Title;
			break;
		case k_ECommunityProfileItemProperty_Description:
			itemProperty += k_ECommunityProfileItemProperty_Description;
			break;
		case k_ECommunityProfileItemProperty_AppId:
			itemProperty += k_ECommunityProfileItemProperty_AppId;
			break;
		case k_ECommunityProfileItemProperty_TypeId:
			itemProperty += k_ECommunityProfileItemProperty_TypeId;
			break;
		case k_ECommunityProfileItemProperty_Class:
			itemProperty += k_ECommunityProfileItemProperty_Class;
			break;
		case k_ECommunityProfileItemProperty_MovieWebM:
			itemProperty += k_ECommunityProfileItemProperty_MovieWebM;
			break;
		case k_ECommunityProfileItemProperty_MovieMP4:
			itemProperty += k_ECommunityProfileItemProperty_MovieMP4;
			break;
		case k_ECommunityProfileItemProperty_MovieWebMSmall:
			itemProperty += k_ECommunityProfileItemProperty_MovieWebMSmall;
			break;
		case k_ECommunityProfileItemProperty_MovieMP4Small:
			itemProperty += k_ECommunityProfileItemProperty_MovieMP4Small;
			break;
	}

	return itemProperty;

}
