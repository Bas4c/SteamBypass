// -----------------------------------------------------------------------------
#include "SteamFriends.h"
// -----------------------------------------------------------------------------

_SteamFriends_::_SteamFriends_() {

	this->chString[0] = '\0';

}

pCStrA _SteamFriends_::GetPersonaName() {

	return (pCStrA)(
		"LocalPlayer"
	);

}

SteamAPICall_t _SteamFriends_::SetPersonaName(pCStrA pchPersonaName) {

	return k_SteamAPICall_Invalid;

}

EPersonaState _SteamFriends_::GetPersonaState() {

	return k_EPersonaStateOffline;

}

Int32 _SteamFriends_::GetFriendCount(Int32 iFriendFlags) {

	return 0;

}

SteamId_t _SteamFriends_::GetFriendByIndex(Int32 iFriend, Int32 iFriendFlags) {

	return k_SteamId_t_Invalid;

}

EFriendRelationship _SteamFriends_::GetFriendRelationship(SteamId_t SteamIdFriend) {

	return k_EFriendRelationshipNone;

}

EPersonaState _SteamFriends_::GetFriendPersonaState(SteamId_t SteamIdFriend) {

	return k_EPersonaStateOffline;

}

pCStrA _SteamFriends_::GetFriendPersonaName(SteamId_t SteamIdFriend) {

	return (pCStrA)(
		"SteamFriend"
	);

}

Int32 _SteamFriends_::GetFriendAvatar(SteamId_t SteamIdFriend, EAvatarSize eAvatarSize) {
	
	return 0;

}

Bool _SteamFriends_::GetFriendGamePlayed(SteamId_t SteamIdFriend, pFriendGameInfo_t pFriendGameInfo) {

	return False;

}

pCStrA _SteamFriends_::GetFriendPersonaNameHistory(SteamId_t SteamIdFriend, Int32 iPersonaName) {

	return (pCStrA)(
		""
	);

}

Int32 _SteamFriends_::GetFriendSteamLevel(SteamId_t SteamIdFriend) {

	return Int32_MAX;

}

pCStrA _SteamFriends_::GetPlayerNickname(SteamId_t SteamIdPlayer) {

	return (pCStrA)(
		"SteamPlayer"
	);

}

Int32 _SteamFriends_::GetFriendsGroupCount() {

	return 0;

}

FriendsGroupId_t _SteamFriends_::GetFriendsGroupIDByIndex(Int32 iFG) {

	return k_FriendsGroupId_Invalid;

}

pCStrA _SteamFriends_::GetFriendsGroupName(FriendsGroupId_t FriendsGroupId) {

	return (pCStrA)(
		"FriendGroup"
	);

}

Int32 _SteamFriends_::GetFriendsGroupMembersCount(FriendsGroupId_t FriendsGroupId) {

	return 0;

}

void _SteamFriends_::GetFriendsGroupMembersList(FriendsGroupId_t FriendsGroupId, pSteamId_t pnSteamIdMembers, Int32 nMembers) {

	if (pnSteamIdMembers != NULL && nMembers > 0) {
		for (Int32 i = 0; i < nMembers; i++) {
			pnSteamIdMembers[i] = k_SteamId_t_Invalid;
		}
	}

}

Bool _SteamFriends_::HasFriend(SteamId_t SteamIdFriend, Int32 iFriendFlags) {

	return False;

}

Int32 _SteamFriends_::GetClanCount() {

	return 0;

}

SteamId_t _SteamFriends_::GetClanByIndex(Int32 iClan) {

	return k_SteamId_t_Invalid;

}

pCStrA _SteamFriends_::GetClanName(SteamId_t SteamIdClan) {

	return (pCStrA)(
		"Generic"
	);

}

pCStrA _SteamFriends_::GetClanTag(SteamId_t SteamIdClan) {

	return this->GetClanName(SteamIdClan);
}

Bool _SteamFriends_::GetClanActivityCounts(SteamId_t SteamIdClan, pInt32 pnOnline, pInt32 pnInGame, pInt32 pnChatting) {

	return False;

}

SteamAPICall_t _SteamFriends_::DownloadClanActivityCounts(pSteamId_t pnSteamIdClans, Int32 nClansToRequest) {

	return k_SteamAPICall_Invalid;

}

Int32 _SteamFriends_::GetFriendCountFromSource(SteamId_t SteamIdSource) {

	return 0;

}

SteamId_t _SteamFriends_::GetFriendFromSourceByIndex(SteamId_t SteamIdSource, Int32 iFriend) {

	return k_SteamId_t_Invalid;

}

Bool _SteamFriends_::IsUserInSource(SteamId_t SteamIdUser, SteamId_t SteamIdSource) {

	return False;

}

void _SteamFriends_::SetInGameVoiceSpeaking(SteamId_t SteamIdUser, Bool bSpeaking) {

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlay(pCStrA pchDialogName) {

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayToUser(pCStrA pchDialog, SteamId_t SteamId) {

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayToWebPage(pCStrA pchURL, EActivateGameOverlayToWebPageMode eActivateGameOverlayToWebPageMode) {

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayToStore(AppId_t iAppId, EOverlayToStoreFlag eOverlayToStoreFlag) {

	/* Empty Method */

}

void _SteamFriends_::SetPlayedWith(SteamId_t SteamIdUserPlayedWith) {

	/* Empty Method */

}

void _SteamFriends_::ActivateGameOverlayInviteDialog(SteamId_t SteamIdLobby) {

	/* Empty Method */

}

Int32 _SteamFriends_::GetSmallFriendAvatar(SteamId_t SteamIdFriend) {

	return 0;

}

Int32 _SteamFriends_::GetMediumFriendAvatar(SteamId_t SteamIdFriend) {

	return 0;

}

Int32 _SteamFriends_::GetLargeFriendAvatar(SteamId_t SteamIdFriend) {

	return 0;

}

Bool _SteamFriends_::RequestUserInformation(SteamId_t SteamIdUser, Bool bRequireNameOnly) {

	return False;

}

SteamAPICall_t _SteamFriends_::RequestClanOfficerList(SteamId_t SteamIdClan) {

	return k_SteamAPICall_Invalid;

}

SteamId_t _SteamFriends_::GetClanOwner(SteamId_t SteamIdClan) {

	return k_SteamId_t_Invalid;

}

Int32 _SteamFriends_::GetClanOfficerCount(SteamId_t SteamIdClan) {

	return 0;

}

SteamId_t _SteamFriends_::GetClanOfficerByIndex(SteamId_t SteamIdClan, Int32 iOfficer) {

	return k_SteamId_t_Invalid;

}

Uint32 _SteamFriends_::GetUserRestrictions() {

	return 0U;

}

Bool _SteamFriends_::SetRichPresence(pCStrA pchKey, pCStrA pchValue) {

	return False;

}

void _SteamFriends_::ClearRichPresence() {

	/* Empty Method */

}

pCStrA _SteamFriends_::GetFriendRichPresence(SteamId_t SteamIdFriend, pCStrA pchKey) {

	return (pCStrA)(
		""
	);

}

Int32 _SteamFriends_::GetFriendRichPresenceKeyCount(SteamId_t SteamIdFriend) {

	return 0;

}

pCStrA _SteamFriends_::GetFriendRichPresenceKeyByIndex(SteamId_t SteamIdFriend, Int32 iKey) {

	return (pCStrA)(
		""
	);

}

void _SteamFriends_::RequestFriendRichPresence(SteamId_t SteamIdFriend) {

	/* Empty Method */

}

Bool _SteamFriends_::InviteUserToGame(SteamId_t SteamIdFriend, pCStrA pchConnectString) {

	return False;

}

Int32 _SteamFriends_::GetCoplayFriendCount() {

	return 0;

}

SteamId_t _SteamFriends_::GetCoplayFriend(Int32 iCoplayFriend) {

	return k_SteamId_t_Invalid;

}

Int32 _SteamFriends_::GetFriendCoplayTime(SteamId_t SteamIdFriend) {

	return 0;

}

AppId_t _SteamFriends_::GetFriendCoplayGame(SteamId_t SteamIdFriend) {

	return k_AppId_t_Invalid;

}

SteamAPICall_t _SteamFriends_::JoinClanChatRoom(SteamId_t SteamIdClan) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamFriends_::LeaveClanChatRoom(SteamId_t SteamIdClan) {

	return False;

}

Int32 _SteamFriends_::GetClanChatMemberCount(SteamId_t SteamIdClan) {

	return 0;

}

SteamId_t _SteamFriends_::GetChatMemberByIndex(SteamId_t SteamIdClan, Int32 iUser) {

	return k_SteamId_t_Invalid;

}

Bool _SteamFriends_::SendClanChatMessage(SteamId_t SteamIdClanChat, pCStrA pchText) {

	return False;

}

Int32 _SteamFriends_::GetClanChatMessage(SteamId_t SteamIdClanChat, Int32 iMessage, pStrA pchText, Int32 cchTextMax, pEChatEntryType peChatEntryType, pSteamId_t pSteamIdChatter) {

	if (pchText != NULL && cchTextMax > 0) {
		pchText[0] = '\0';
	}

	if (peChatEntryType != NULL) {
		*peChatEntryType = k_EChatEntryTypeInvalid;
	}

	if (pSteamIdChatter != NULL) {
		*pSteamIdChatter = k_SteamId_t_Invalid;
	}

	return 0;

}

Bool _SteamFriends_::IsClanChatAdmin(SteamId_t SteamIdClanChat, SteamId_t SteamIdUser) {

	return False;

}

Bool _SteamFriends_::IsClanChatWindowOpenInSteam(SteamId_t SteamIdClanChat) {

	return False;

}

Bool _SteamFriends_::OpenClanChatWindowInSteam(SteamId_t SteamIdClanChat) {

	return False;

}

Bool _SteamFriends_::CloseClanChatWindowInSteam(SteamId_t SteamIdClanChat) {

	return False;

}

Bool _SteamFriends_::SetListenForFriendsMessages(Bool bInterceptEnabled) {

	return False;

}

Bool _SteamFriends_::ReplyToFriendMessage(SteamId_t SteamIdFriend, pCStrA pchMsgToSend) {

	return False;

}

Int32 _SteamFriends_::GetFriendMessage(SteamId_t SteamIdFriend, Int32 iMessageId, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) {

	if (pvData != NULL && cbData > 0) {
		((pStrA)(pvData))[0] = '\0';
	}

	if (peChatEntryType != NULL) {
		*peChatEntryType = k_EChatEntryTypeInvalid;
	}

	return 0;

}

SteamAPICall_t _SteamFriends_::GetFollowerCount(SteamId_t SteamId) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamFriends_::IsFollowing(SteamId_t SteamId) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamFriends_::EnumerateFollowingList(Uint32 iStart) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamFriends_::IsClanPublic(SteamId_t SteamIdClan) {

	return False;

}

Bool _SteamFriends_::IsClanOfficialGameGroup(SteamId_t SteamIdClan) {

	return False;

}

Int32 _SteamFriends_::GetNumChatsWithUnreadPriorityMessages() {

	return 0;

}

void _SteamFriends_::ActivateGameOverlayRemotePlayTogetherInviteDialog(SteamId_t SteamIdLobby) {

	/* Empty Method */

}

Bool _SteamFriends_::RegisterProtocolInOverlayBrowser(pCStrA pchProtocol) {

	return False;

}

void _SteamFriends_::ActivateGameOverlayInviteDialogConnectString(pCStrA pchConnectString) {

	/* Empty Method */

}

SteamAPICall_t _SteamFriends_::RequestEquippedProfileItems(SteamId_t SteamId) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamFriends_::BHasEquippedProfileItem(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType) {

	return False;

}

pCStrA _SteamFriends_::GetProfileItemPropertyString(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) {

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
