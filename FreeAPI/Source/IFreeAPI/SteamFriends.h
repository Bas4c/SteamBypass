#ifndef _STEAMFRIENDS_
#define _STEAMFRIENDS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamFriends.h"
// -----------------------------------------------------------------------------

typedef class _SteamFriends_ : public _ISteamFriends003_,
 public _ISteamFriends004_, public _ISteamFriends005_,
 public _ISteamFriends006_, public _ISteamFriends007_,
 public _ISteamFriends008_, public _ISteamFriends009_,
 public _ISteamFriends010_, public _ISteamFriends011_,
 public _ISteamFriends012_, public _ISteamFriends013_,
 public _ISteamFriends014_, public _ISteamFriends015_,
 public _ISteamFriends016_, public _ISteamFriends_ {
public:

	_SteamFriends_();
	_SteamFriends_(const _SteamFriends_&) = delete;
	_SteamFriends_& operator=(const _SteamFriends_&) = delete;

	/* Returns Local Player Name - guaranteed to not be NULL */
	pCStrA GetPersonaName() override;

	/* Sets the player name, stores it on the server and publishes the changes to all friends who are online.
	   Changes take place locally immediately, and a PersonaStateChange_t is posted, presuming success. */
	SteamAPICall_t SetPersonaName(pCStrA pchPersonaName) override;
	EPersonaState GetPersonaState() override;

	/* Takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
		then GetFriendByIndex() can then be used to return the Id's of each of those users */
	Int32 GetFriendCount(Int32 iFriendFlags) override;

	/* iFriend is a index of range [0, GetFriendCount())
	   iFriendsFlags must be the same value as used in GetFriendCount()
		the returned SteamId_t can then be used by all the functions below to access details about the user */
	SteamId_t GetFriendByIndex(Int32 iFriend, Int32 iFriendFlags) override;
	EFriendRelationship GetFriendRelationship(SteamId_t SteamIdFriend) override;
	EPersonaState GetFriendPersonaState(SteamId_t SteamIdFriend) override;
	pCStrA GetFriendPersonaName(SteamId_t SteamIdFriend) override;
	Int32 GetFriendAvatar(SteamId_t SteamIdFriend, EAvatarSize eAvatarSize) override;

	Bool GetFriendGamePlayed(SteamId_t SteamIdFriend, pFriendGameInfo_t pFriendGameInfo) override;
	/* Returns (empty string) when their are no more items in the history */
	pCStrA GetFriendPersonaNameHistory(SteamId_t SteamIdFriend, Int32 iPersonaName) override;
	Int32 GetFriendSteamLevel(SteamId_t SteamIdFriend) override;
	pCStrA GetPlayerNickname(SteamId_t SteamIdPlayer) override;

	Int32 GetFriendsGroupCount() override;
	/* (invalid indices return k_FriendsGroupId_Invalid) */
	FriendsGroupId_t GetFriendsGroupIDByIndex(Int32 iFG) override;
	/* (NULL in the case of invalid group Id's) */
	pCStrA GetFriendsGroupName(FriendsGroupId_t FriendsGroupId) override;
	Int32 GetFriendsGroupMembersCount(FriendsGroupId_t FriendsGroupId) override;
	void GetFriendsGroupMembersList(FriendsGroupId_t FriendsGroupId, pSteamId_t pnSteamIdMembers, Int32 nMembers) override;
	Bool HasFriend(SteamId_t SteamIdFriend, Int32 iFriendFlags) override;

	Int32 GetClanCount() override;
	SteamId_t GetClanByIndex(Int32 iClan) override;
	pCStrA GetClanName(SteamId_t SteamIdClan) override;
	pCStrA GetClanTag(SteamId_t SteamIdClan) override;
	Bool GetClanActivityCounts(SteamId_t SteamIdClan, pInt32 pnOnline, pInt32 pnInGame, pInt32 pnChatting) override;
	SteamAPICall_t DownloadClanActivityCounts(pSteamId_t pnSteamIdClans, Int32 nClansToRequest) override;

	Int32 GetFriendCountFromSource(SteamId_t SteamIdSource) override;
	SteamId_t GetFriendFromSourceByIndex(SteamId_t SteamIdSource, Int32 iFriend) override;
	Bool IsUserInSource(SteamId_t SteamIdUser, SteamId_t SteamIdSource) override;
	void SetInGameVoiceSpeaking(SteamId_t SteamIdUser, Bool bSpeaking) override;

	/* Options: "Friends", "Community", "Players", "Settings",
		"OfficialGameGroup", "Stats", "Achievements", "chatroomgroup/nnnn" */
	void ActivateGameOverlay(pCStrA pchDialogName) override;
	void ActivateGameOverlayToUser(pCStrA pchDialog, SteamId_t SteamId) override;
	void ActivateGameOverlayToWebPage(pCStrA pchURL, EActivateGameOverlayToWebPageMode eActivateGameOverlayToWebPageMode) override;
	void ActivateGameOverlayToStore(AppId_t iAppId, EOverlayToStoreFlag eOverlayToStoreFlag) override;
	void SetPlayedWith(SteamId_t SteamIdUserPlayedWith) override;
	void ActivateGameOverlayInviteDialog(SteamId_t SteamIdLobby) override;

	/* (32x32) avatar of the current user,
		which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set */
	Int32 GetSmallFriendAvatar(SteamId_t SteamIdFriend) override;

	/* (64x64) avatar of the current user,
		which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set */
	Int32 GetMediumFriendAvatar(SteamId_t SteamIdFriend) override;

	/* (128x128) avatar of the current user,
		which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set */
	Int32 GetLargeFriendAvatar(SteamId_t SteamIdFriend) override;

	Bool RequestUserInformation(SteamId_t SteamIdUser, Bool bRequireNameOnly) override;
	SteamAPICall_t RequestClanOfficerList(SteamId_t SteamIdClan) override;

	SteamId_t GetClanOwner(SteamId_t SteamIdClan) override;
	Int32 GetClanOfficerCount(SteamId_t SteamIdClan) override;
	SteamId_t GetClanOfficerByIndex(SteamId_t SteamIdClan, Int32 iOfficer) override;
	Uint32 GetUserRestrictions() override;
	Bool SetRichPresence(pCStrA pchKey, pCStrA pchValue) override;
	void ClearRichPresence() override;
	pCStrA GetFriendRichPresence(SteamId_t SteamIdFriend, pCStrA pchKey) override;
	Int32 GetFriendRichPresenceKeyCount(SteamId_t SteamIdFriend) override;
	pCStrA GetFriendRichPresenceKeyByIndex(SteamId_t SteamIdFriend, Int32 iKey) override;
	void RequestFriendRichPresence(SteamId_t SteamIdFriend) override;
	Bool InviteUserToGame(SteamId_t SteamIdFriend, pCStrA pchConnectString) override;

	Int32 GetCoplayFriendCount() override;
	SteamId_t GetCoplayFriend(Int32 iCoplayFriend) override;
	/* Unix Time */
	Int32 GetFriendCoplayTime(SteamId_t SteamIdFriend) override;
	AppId_t GetFriendCoplayGame(SteamId_t SteamIdFriend) override;

	SteamAPICall_t JoinClanChatRoom(SteamId_t SteamIdClan) override;
	Bool LeaveClanChatRoom(SteamId_t SteamIdClan) override;
	Int32 GetClanChatMemberCount(SteamId_t SteamIdClan) override;
	SteamId_t GetChatMemberByIndex(SteamId_t SteamIdClan, Int32 iUser) override;
	Bool SendClanChatMessage(SteamId_t SteamIdClanChat, pCStrA pchText) override;
	Int32 GetClanChatMessage(SteamId_t SteamIdClanChat, Int32 iMessage, pStrA pchText, Int32 cchTextMax, pEChatEntryType peChatEntryType, pSteamId_t pSteamIdChatter) override;
	Bool IsClanChatAdmin(SteamId_t SteamIdClanChat, SteamId_t SteamIdUser) override;

	Bool IsClanChatWindowOpenInSteam(SteamId_t SteamIdClanChat) override;
	Bool OpenClanChatWindowInSteam(SteamId_t SteamIdClanChat) override;
	Bool CloseClanChatWindowInSteam(SteamId_t SteamIdClanChat) override;

	Bool SetListenForFriendsMessages(Bool bInterceptEnabled) override;
	Bool ReplyToFriendMessage(SteamId_t SteamIdFriend, pCStrA pchMsgToSend) override;
	Int32 GetFriendMessage(SteamId_t SteamIdFriend, Int32 iMessageId, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) override;

	SteamAPICall_t GetFollowerCount(SteamId_t SteamId) override;
	SteamAPICall_t IsFollowing(SteamId_t SteamId) override;
	SteamAPICall_t EnumerateFollowingList(Uint32 iStart) override;

	Bool IsClanPublic(SteamId_t SteamIdClan) override;
	Bool IsClanOfficialGameGroup(SteamId_t SteamIdClan) override;
	Int32 GetNumChatsWithUnreadPriorityMessages() override;

	void ActivateGameOverlayRemotePlayTogetherInviteDialog(SteamId_t SteamIdLobby) override;
	Bool RegisterProtocolInOverlayBrowser(pCStrA pchProtocol) override;
	void ActivateGameOverlayInviteDialogConnectString(pCStrA pchConnectString) override;

	SteamAPICall_t RequestEquippedProfileItems(SteamId_t SteamId) override;
	Bool BHasEquippedProfileItem(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType) override;
	pCStrA GetProfileItemPropertyString(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) override;
	Uint32 GetProfileItemPropertyUint(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) override;

	~_SteamFriends_() = default;

private:

	CharA chString[256];

} SteamFriends, *pSteamFriends;

#endif // !_STEAMFRIENDS_
