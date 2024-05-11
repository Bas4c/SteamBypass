#ifndef _ISTEAMFRIEND_
#define _ISTEAMFRIEND_

#include "..\..\FreeAPI.Typedef.h"

// -----------------------------------------------------------------------------
// Purpose: Set of relationships to other users
// -----------------------------------------------------------------------------
typedef enum _EFriendRelationship_ {

	k_EFriendRelationshipNone,
	k_EFriendRelationshipBlocked,
	k_EFriendRelationshipRequestRecipient,
	k_EFriendRelationshipFriend,
	k_EFriendRelationshipRequestInitiator,
	k_EFriendRelationshipIgnored,
	k_EFriendRelationshipIgnoredFriend,
	k_EFriendRelationshipSuggested_DEPRECATED,
	k_EFriendRelationshipMax,

} EFriendRelationship, *pEFriendRelationship;

#define k_cchMaxFriendsGroupName ((Int32)(65));
#define k_cFriendsGroupLimit ((Int32)(100))

typedef Int16 FriendsGroupId_t, *pFriendsGroupId_t;
#define k_FriendsGroupId_Invalid ((FriendsGroupId_t)(-1));

#define k_cEnumerateFollowersMax ((Int32)(50))

// -----------------------------------------------------------------------------
// Purpose: Friend State
// -----------------------------------------------------------------------------
typedef enum _EPersonaState_ {

	k_EPersonaStateOffline,
	k_EPersonaStateOnline,
	k_EPersonaStateBusy,
	k_EPersonaStateAway,
	k_EPersonaStateSnooze,
	k_EPersonaStateLookingToTrade,
	k_EPersonaStateLookingToPlay,
	k_EPersonaStateInvisible,
	k_EPersonaStateMax

} EPersonaState, *pEPersonaState;

// -----------------------------------------------------------------------------
// Purpose: Friends List Flags
// -----------------------------------------------------------------------------
typedef enum _EFriendFlags_ {

	k_EFriendFlagNone = 0x00,
	k_EFriendFlagBlocked = 0x01,
	k_EFriendFlagFriendshipRequested = 0x02,
	k_EFriendFlagImmediate = 0x04,
	k_EFriendFlagClanMember = 0x08,
	k_EFriendFlagOnGameServer = 0x10,
	k_EFriendFlagHasPlayedWith = 0x20,
	k_EFriendFlagFriendOfFriend = 0x40,
	k_EFriendFlagRequestingFriendship = 0x80,
	k_EFriendFlagRequestingInfo = 0x100,
	k_EFriendFlagIgnored = 0x200,
	k_EFriendFlagIgnoredFriend = 0x400,
	k_EFriendFlagSuggested = 0x800,
	k_EFriendFlagChatMember = 0x1000,
	k_EFriendFlagAll = 0xFFFF

} EFriendFlags, *pEFriendFlags;

#define k_cchPersonaNameMax ((Int32)(128)) /* UTF-8 */
#define k_cwchPersonaNameMax ((Int32)(32)) /* UTF-16 */

typedef struct _FriendGameInfo_t_ {
	GameId_t GameId;
	Uint32 GameIP;
	Uint16 GamePort;
	Uint16 QueryPort;
	SteamId_t SteamIdLobby;
} FriendGameInfo_t, *pFriendGameInfo_t;

// -----------------------------------------------------------------------------
// Purpose: User Restriction Flags
// -----------------------------------------------------------------------------
typedef enum _EUserRestriction_ {

	k_EUserRestrictionNone = 0,
	k_EUserRestrictionUnknown = 1,
	k_EUserRestrictionAnyChat = 2,
	k_EUserRestrictionVoiceChat = 4,
	k_EUserRestrictionGroupChat = 8,
	k_EUserRestrictionRating = 16,
	k_EUserRestrictionGameInvites = 32,
	k_EUserRestrictionTrading = 64

} EUserRestriction, *pEUserRestriction;

// -----------------------------------------------------------------------------
// Purpose: Info About User Session
// -----------------------------------------------------------------------------
typedef struct _FriendSessionStateInfo_t_ {

	Uint32 nOnlineSessionInstances;
	Uint8 iPublishedToFriendsSessionInstance;

} FriendSessionStateInfo_t, *pFriendSessionStateInfo_t;

#define k_cbChatMetadataMax ((Uint32)(8192))

#define k_cchMaxRichPresenceKeys ((Int32)(30))
#define k_cchMaxRichPresenceKeyLength ((Int32)(64))
#define k_cchMaxRichPresenceValueLength ((Int32)(256))

typedef enum _EOverlayToStoreFlag_ {

	k_EOverlayToStoreFlag_None,
	k_EOverlayToStoreFlag_AddToCart,
	k_EOverlayToStoreFlag_AddToCartAndShow

} EOverlayToStoreFlag, *pEOverlayToStoreFlag;

// -----------------------------------------------------------------------------
// Purpose: Tells Steam where to place the browser window inside the overlay
// -----------------------------------------------------------------------------
typedef enum _EActivateGameOverlayToWebPageMode_ {

	k_EActivateGameOverlayToWebPageMode_Default,
	k_EActivateGameOverlayToWebPageMode_Modal

} EActivateGameOverlayToWebPageMode, *pEActivateGameOverlayToWebPageMode;

// -----------------------------------------------------------------------------
// Purpose: See GetProfileItemPropertyString and GetProfileItemPropertyUint
// -----------------------------------------------------------------------------
typedef enum _ECommunityProfileItemType_ {

	k_ECommunityProfileItemType_AnimatedAvatar,
	k_ECommunityProfileItemType_AvatarFrame,
	k_ECommunityProfileItemType_ProfileModifier,
	k_ECommunityProfileItemType_ProfileBackground,
	k_ECommunityProfileItemType_MiniProfileBackground

} ECommunityProfileItemType, *pECommunityProfileItemType;
typedef enum _ECommunityProfileItemProperty_ {

	k_ECommunityProfileItemProperty_ImageSmall,
	k_ECommunityProfileItemProperty_ImageLarge,
	k_ECommunityProfileItemProperty_InternalName,
	k_ECommunityProfileItemProperty_Title,
	k_ECommunityProfileItemProperty_Description,
	k_ECommunityProfileItemProperty_AppId,
	k_ECommunityProfileItemProperty_TypeId,
	k_ECommunityProfileItemProperty_Class,
	k_ECommunityProfileItemProperty_MovieWebM,
	k_ECommunityProfileItemProperty_MovieMP4,
	k_ECommunityProfileItemProperty_MovieWebMSmall,
	k_ECommunityProfileItemProperty_MovieMP4Small

} ECommunityProfileItemProperty, *pECommunityProfileItemProperty;

// -----------------------------------------------------------------------------
// Purpose: interface to accessing information about individual users,
//			that can be a friend, in a group, on a game server or in a lobby with the local user
// -----------------------------------------------------------------------------
typedef class _ISteamFriends_ {
public:

	/* Returns Local Player Name - guaranteed to not be NULL */
	virtual const pStrA GetPersonaName() = 0;

	/* Sets the player name, stores it on the server and publishes the changes to all friends who are online.
	   Changes take place locally immediately, and a PersonaStateChange_t is posted, presuming success. */
	virtual SteamAPICall_t SetPersonaName(const pStrA pchPersonaName) = 0;
	virtual EPersonaState GetPersonaState() = 0;

	/* Takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
	    then GetFriendByIndex() can then be used to return the Id's of each of those users */
	virtual Int32 GetFriendCount(Int32 iFriendFlags) = 0;

	/* iFriend is a index of range [0, GetFriendCount())
	   iFriendsFlags must be the same value as used in GetFriendCount()
	    the returned SteamId_t can then be used by all the functions below to access details about the user */
	virtual SteamId_t GetFriendByIndex(Int32 iFriend, Int32 iFriendFlags) = 0;
	virtual EFriendRelationship GetFriendRelationship(SteamId_t SteamIdFriend) = 0;
	virtual EPersonaState GetFriendPersonaState(SteamId_t SteamIdFriend) = 0;
	virtual const pStrA GetFriendPersonaName(SteamId_t SteamIdFriend) = 0;

	virtual Bool GetFriendGamePlayed(SteamId_t SteamIdFriend, /* [out] */ pFriendGameInfo_t pFriendGameInfo) = 0;
	/* Returns (empty string) when their are no more items in the history */
	virtual const pStrA GetFriendPersonaNameHistory(SteamId_t SteamIdFriend, Int32 iPersonaName) = 0;
	virtual Int32 GetFriendSteamLevel(SteamId_t SteamIdFriend) = 0;
	virtual const pStrA GetPlayerNickname(SteamId_t SteamIdPlayer) = 0;

	virtual Int32 GetFriendsGroupCount() = 0;
	/* (invalid indices return k_FriendsGroupId_Invalid) */
	virtual FriendsGroupId_t GetFriendsGroupIDByIndex(Int32 iFG) = 0;
	/* (NULL in the case of invalid group Id's) */
	virtual const pStrA GetFriendsGroupName(FriendsGroupId_t FriendsGroupId) = 0;
	virtual Int32 GetFriendsGroupMembersCount(FriendsGroupId_t FriendsGroupId) = 0;
	virtual void GetFriendsGroupMembersList(FriendsGroupId_t FriendsGroupId, /* [out] */ pSteamId_t pnSteamIdMembers, Int32 nMembers) = 0;
	virtual Bool HasFriend(SteamId_t SteamIdFriend, Int32 iFriendFlags) = 0;

	virtual Int32 GetClanCount() = 0;
	virtual SteamId_t GetClanByIndex(Int32 iClan) = 0;
	virtual const pStrA GetClanName(SteamId_t SteamIdClan) = 0;
	virtual const pStrA GetClanTag(SteamId_t SteamIdClan) = 0;
	virtual Bool GetClanActivityCounts(SteamId_t SteamIdClan, /* [out] */ pInt32 pnOnline, /* [out] */ pInt32 pnInGame, /* [out] */ pInt32 pnChatting) = 0;
	virtual SteamAPICall_t DownloadClanActivityCounts(pSteamId_t pnSteamIdClans, Int32 nClansToRequest) = 0;

	virtual Int32 GetFriendCountFromSource(SteamId_t SteamIdSource) = 0;
	virtual SteamId_t GetFriendFromSourceByIndex(SteamId_t SteamIdSource, Int32 iFriend) = 0;
	virtual Bool IsUserInSource(SteamId_t SteamIdUser, SteamId_t SteamIdSource) = 0;
	virtual void SetInGameVoiceSpeaking(SteamId_t SteamIdUser, Bool bSpeaking) = 0;

	/* Options: "Friends", "Community", "Players", "Settings",
	    "OfficialGameGroup", "Stats", "Achievements", "chatroomgroup/nnnn" */
	virtual void ActivateGameOverlay(const pStrA pchDialogName) = 0;
	virtual void ActivateGameOverlayToUser(const pStrA pchDialog, SteamId_t SteamId) = 0;
	virtual void ActivateGameOverlayToWebPage(const pStrA pchURL, EActivateGameOverlayToWebPageMode eActivateGameOverlayToWebPageMode) = 0;
	virtual void ActivateGameOverlayToStore(AppId_t iAppId, EOverlayToStoreFlag eOverlayToStoreFlag) = 0;
	virtual void SetPlayedWith(SteamId_t SteamIdUserPlayedWith) = 0;
	virtual void ActivateGameOverlayInviteDialog(SteamId_t SteamIdLobby) = 0;

	/* (32x32) avatar of the current user,
	    which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set */
	virtual Int32 GetSmallFriendAvatar(SteamId_t SteamIdFriend) = 0;

	/* (64x64) avatar of the current user,
	    which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set */
	virtual Int32 GetMediumFriendAvatar(SteamId_t SteamIdFriend) = 0;

	/* (128x128) avatar of the current user,
		which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set */
	virtual Int32 GetLargeFriendAvatar(SteamId_t SteamIdFriend) = 0;

	virtual Bool RequestUserInformation(SteamId_t SteamIdUser, Bool bRequireNameOnly) = 0;
	virtual SteamAPICall_t RequestClanOfficerList(SteamId_t SteamIdClan) = 0;

	virtual SteamId_t GetClanOwner(SteamId_t SteamIdClan) = 0;
	virtual Int32 GetClanOfficerCount(SteamId_t SteamIdClan) = 0;
	virtual SteamId_t GetClanOfficerByIndex(SteamId_t SteamIdClan, Int32 iOfficer) = 0;
	virtual Uint32 GetUserRestrictions() = 0;
	virtual Bool SetRichPresence(const pStrA pchKey, const pStrA pchValue) = 0;
	virtual void ClearRichPresence() = 0;
	virtual const pStrA GetFriendRichPresence(SteamId_t SteamIdFriend, const pStrA pchKey) = 0;
	virtual Int32 GetFriendRichPresenceKeyCount(SteamId_t SteamIdFriend) = 0;
	virtual const pStrA GetFriendRichPresenceKeyByIndex(SteamId_t SteamIdFriend, Int32 iKey) = 0;
	virtual void RequestFriendRichPresence(SteamId_t SteamIdFriend) = 0;
	virtual Bool InviteUserToGame(SteamId_t SteamIdFriend, const pStrA pchConnectString) = 0;

	virtual Int32 GetCoplayFriendCount() = 0;
	virtual SteamId_t GetCoplayFriend(Int32 iCoplayFriend) = 0;
	/* Unix Time */
	virtual Int32 GetFriendCoplayTime(SteamId_t SteamIdFriend) = 0;
	virtual AppId_t GetFriendCoplayGame(SteamId_t SteamIdFriend) = 0;

	virtual SteamAPICall_t JoinClanChatRoom(SteamId_t SteamIdClan) = 0;
	virtual Bool LeaveClanChatRoom(SteamId_t SteamIdClan) = 0;
	virtual Int32 GetClanChatMemberCount(SteamId_t SteamIdClan) = 0;
	virtual SteamId_t GetChatMemberByIndex(SteamId_t SteamIdClan, Int32 iUser) = 0;
	virtual Bool SendClanChatMessage(SteamId_t SteamIdClanChat, const pStrA pchText) = 0;
	virtual Int32 GetClanChatMessage(SteamId_t SteamIdClanChat, Int32 iMessage, /* [out] */ pStrA pchText, Int32 cchTextMax, /* [out] */ pEChatEntryType peChatEntryType, /* [out] */ pSteamId_t pSteamIdChatter) = 0;
	virtual Bool IsClanChatAdmin(SteamId_t SteamIdClanChat, SteamId_t SteamIdUser) = 0;

	virtual Bool IsClanChatWindowOpenInSteam(SteamId_t SteamIdClanChat) = 0;
	virtual Bool OpenClanChatWindowInSteam(SteamId_t SteamIdClanChat) = 0;
	virtual Bool CloseClanChatWindowInSteam(SteamId_t SteamIdClanChat) = 0;

	virtual Bool SetListenForFriendsMessages(Bool bInterceptEnabled) = 0;
	virtual Bool ReplyToFriendMessage(SteamId_t SteamIdFriend, const pStrA pchMsgToSend) = 0;
	virtual Int32 GetFriendMessage(SteamId_t SteamIdFriend, Int32 iMessageId, /* [out] */ pVoid pvData, Int32 cbData, /* [out] */ pEChatEntryType peChatEntryType) = 0;

	virtual SteamAPICall_t GetFollowerCount(SteamId_t SteamId) = 0;
	virtual SteamAPICall_t IsFollowing(SteamId_t SteamId) = 0;
	virtual SteamAPICall_t EnumerateFollowingList(Uint32 iStart) = 0;

	virtual Bool IsClanPublic(SteamId_t SteamIdClan) = 0;
	virtual Bool IsClanOfficialGameGroup(SteamId_t SteamIdClan) = 0;
	virtual Int32 GetNumChatsWithUnreadPriorityMessages() = 0;

	virtual void ActivateGameOverlayRemotePlayTogetherInviteDialog(SteamId_t SteamIdLobby) = 0;
	virtual Bool RegisterProtocolInOverlayBrowser(const pStrA pchProtocol) = 0;
	virtual void ActivateGameOverlayInviteDialogConnectString(const pStrA pchConnectString) = 0;
	
	virtual SteamAPICall_t RequestEquippedProfileItems(SteamId_t SteamId) = 0;
	virtual Bool BHasEquippedProfileItem(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType) = 0;
	virtual const pStrA GetProfileItemPropertyString(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) = 0;
	virtual Uint32 GetProfileItemPropertyUint(SteamId_t SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) = 0;

} ISteamFriends, *IpSteamFriends;

#define STEAMFRIENDS_INTERFACE_VERSION "SteamFriends017"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

typedef enum _EPersonaChange_ {

	k_EPersonaChangeName = 0x0001,
	k_EPersonaChangeStatus = 0x0002,
	k_EPersonaChangeComeOnline = 0x0004,
	k_EPersonaChangeGoneOffline = 0x0008,
	k_EPersonaChangeGamePlayed = 0x0010,
	k_EPersonaChangeGameServer = 0x0020,
	k_EPersonaChangeAvatar = 0x0040,
	k_EPersonaChangeJoinedSource = 0x0080,
	k_EPersonaChangeLeftSource = 0x0100,
	k_EPersonaChangeRelationshipChanged = 0x0200,
	k_EPersonaChangeNameFirstSet = 0x0400,
	k_EPersonaChangeBroadcast = 0x0800,
	k_EPersonaChangeNickname = 0x1000,
	k_EPersonaChangeSteamLevel = 0x2000,
	k_EPersonaChangeRichPresence = 0x4000

} EPersonaChange, *pEPersonaChange;

// -----------------------------------------------------------------------------
// Purpose: Called Friend Status Changes
// -----------------------------------------------------------------------------
#define k_iCallbback_PersonaStateChange_t ((Int32)(k_iSteamFriendsCallbacks + 4))
typedef struct _PersonaStateChange_t_ {
	
	SteamId_t SteamId;
	Int32 nPersonaChangeFlags;

} PersonaStateChange_t, *pPersonaStateChange_t;

// -----------------------------------------------------------------------------
// Purpose: Posted when game overlay activates or deactivates
//  the game can use this to be pause or resume single player games
// -----------------------------------------------------------------------------
#define k_iCallbback_GameOverlayActivated_t ((Int32)(k_iSteamFriendsCallbacks + 31))
typedef struct _GameOverlayActivated_t_ {

	Uint8 bActive;
	Bool bUserInitiated;
	AppId_t iAppId;

} GameOverlayActivated_t, *pGameOverlayActivated_t;

// -----------------------------------------------------------------------------
// Purpose: Called when the user tries to join a different game server from their friends list
//  game client should attempt to connect to specified server when this is received
// -----------------------------------------------------------------------------
#define k_iCallbback_GameServerChangeRequested_t ((Int32)(k_iSteamFriendsCallbacks + 32))
typedef struct _GameServerChangeRequested_t_ {

	CharA chServer[64];
	CharA chPassword[64];

} GameServerChangeRequested_t, *pGameServerChangeRequested_t;

// -----------------------------------------------------------------------------
// Purpose: Called when the user tries to join a lobby from their friends list
//  game client should attempt to connect to specified lobby when this is received
// -----------------------------------------------------------------------------
#define k_iCallbback_GameLobbyJoinRequested_t ((Int32)(k_iSteamFriendsCallbacks + 33))
typedef struct _GameLobbyJoinRequested_t_ {

	SteamId_t SteamIdLobby;
	SteamId_t SteamIdFriend;

} GameLobbyJoinRequested_t, *pGameLobbyJoinRequested_t;

// -----------------------------------------------------------------------------
// Purpose: Called when an avatar is loaded in from a previous GetLargeFriendAvatar() call
//  if the image wasn't already available
// -----------------------------------------------------------------------------
#define k_iCallbback_AvatarImageLoaded_t ((Int32)(k_iSteamFriendsCallbacks + 34))
typedef struct AvatarImageLoaded_t {

	SteamId_t SteamId;
	Int32 iImage;
	Int32 iWide;
	Int32 iTall;

} AvatarImageLoaded_t, *pAvatarImageLoaded_t;

// -----------------------------------------------------------------------------
// Purpose: Marks the return of a request officer list call
// -----------------------------------------------------------------------------
#define k_iCallbback_ClanOfficerListResponse_t ((Int32)(k_iSteamFriendsCallbacks + 35))
typedef struct ClanOfficerListResponse_t {

	SteamId_t SteamIdClan;
	Int32 cOfficers;
	Uint8 bSuccess;

} ClanOfficerListResponse_t, *pClanOfficerListResponse_t;

// -----------------------------------------------------------------------------
// Purpose: Callback indicating updated data about friends rich presence information
// -----------------------------------------------------------------------------
#define k_iCallbback_FriendRichPresenceUpdate_t ((Int32)(k_iSteamFriendsCallbacks + 36))
typedef struct _FriendRichPresenceUpdate_t_ {

	SteamId_t SteamIdFriend;
	AppId_t iAppId;

} FriendRichPresenceUpdate_t, *pFriendRichPresenceUpdate_t;

// -----------------------------------------------------------------------------
// Purpose: Called when the user tries to join a game from their friends list
//  rich presence will have been set with the "connect" key which is set here
// -----------------------------------------------------------------------------
#define k_iCallbback_GameRichPresenceJoinRequested_t ((Int32)(k_iSteamFriendsCallbacks + 37))
typedef struct _GameRichPresenceJoinRequested_t_ {
	
	SteamId_t SteamIdFriend;
	CharA chConnect[k_cchMaxRichPresenceValueLength];

} GameRichPresenceJoinRequested_t, *pGameRichPresenceJoinRequested_t;

// -----------------------------------------------------------------------------
// Purpose: Chat message has been received
// -----------------------------------------------------------------------------
#define k_iCallbback_GameConnectedClanChatMsg_t ((Int32)(k_iSteamFriendsCallbacks + 38))
typedef struct _GameConnectedClanChatMsg_t_ {

	SteamId_t SteamIdClanChat;
	SteamId_t SteamIdUser;
	Int32 iMessageId;

} GameConnectedClanChatMsg_t, *pGameConnectedClanChatMsg_t;


// -----------------------------------------------------------------------------
// Purpose: User has joined a clan chat
// -----------------------------------------------------------------------------
#define k_iCallbback_GameConnectedChatJoin_t ((Int32)(k_iSteamFriendsCallbacks + 39))
typedef struct _GameConnectedChatJoin_t_ {

	SteamId_t SteamIdClanChat;
	SteamId_t SteamIdUser;

} GameConnectedChatJoin_t, *pGameConnectedChatJoin_t;

// -----------------------------------------------------------------------------
// Purpose: User has left the chat we're in
// -----------------------------------------------------------------------------
#define k_iCallbback_GameConnectedChatLeave_t ((Int32)(k_iSteamFriendsCallbacks + 40))
typedef struct _GameConnectedChatLeave_t_ {

	SteamId_t SteamIdClanChat;
	SteamId_t SteamIdUser;
	Bool bKicked;
	Bool bDropped;

} GameConnectedChatLeave_t, *pGameConnectedChatLeave_t;

// -----------------------------------------------------------------------------
// Purpose: DownloadClanActivityCounts() call has finished
// -----------------------------------------------------------------------------
#define k_iCallbback_DownloadClanActivityCountsResult_t ((Int32)(k_iSteamFriendsCallbacks + 41))
typedef struct _DownloadClanActivityCountsResult_t_ {

	Bool bSuccess;

} DownloadClanActivityCountsResult_t, *pDownloadClanActivityCountsResult_t;

// -----------------------------------------------------------------------------
// Purpose: JoinClanChatRoom() call has finished
// -----------------------------------------------------------------------------
#define k_iCallbback_JoinClanChatRoomCompletionResult_t ((Int32)(k_iSteamFriendsCallbacks + 42))
typedef struct _JoinClanChatRoomCompletionResult_t_ {

	SteamId_t SteamIdClanChat;
	EChatRoomEnterResponse eChatRoomEnterResponse;

} JoinClanChatRoomCompletionResult_t, *pJoinClanChatRoomCompletionResult_t;

// -----------------------------------------------------------------------------
// Purpose: Chat message has been received from a user
// -----------------------------------------------------------------------------
#define k_iCallbback_GameConnectedFriendChatMsg_t ((Int32)(k_iSteamFriendsCallbacks + 43))
typedef struct _GameConnectedFriendChatMsg_t_ {

	SteamId_t SteamIdUser;
	Int32 iMessageId;

} GameConnectedFriendChatMsg_t, *pGameConnectedFriendChatMsg_t;

#define k_iCallbback_FriendsGetFollowerCount_t ((Int32)(k_iSteamFriendsCallbacks + 44))
typedef struct _FriendsGetFollowerCount_t_ {

	EResult eResult;
	SteamId_t SteamId;
	Int32 nCount;

} FriendsGetFollowerCount_t, *pFriendsGetFollowerCount_t;

#define k_iCallbback_FriendsIsFollowing_t ((Int32)(k_iSteamFriendsCallbacks + 45))
typedef struct _FriendsIsFollowing_t_ {

	EResult eResult;
	SteamId_t SteamId;
	Bool bIsFollowing;

} FriendsIsFollowing_t, *pFriendsIsFollowing_t;

#define k_iCallbback_FriendsEnumerateFollowingList_t ((Int32)(k_iSteamFriendsCallbacks + 46))
typedef struct _FriendsEnumerateFollowingList_t_ {

	EResult eResult;
	SteamId_t rgSteamID[k_cEnumerateFollowersMax];
	Int32 nResultsReturned;
	Int32 nTotalResultCount;

} FriendsEnumerateFollowingList_t, *pFriendsEnumerateFollowingList_t;

// -----------------------------------------------------------------------------
// Purpose: Reports the result of an attempt to change the user's persona name
// -----------------------------------------------------------------------------
#define k_iCallbback_SetPersonaNameResponse_t ((Int32)(k_iSteamFriendsCallbacks + 47))
typedef struct _SetPersonaNameResponse_t_ {

	Bool bSuccess;
	Bool bLocalSuccess;
	EResult eResult;

} SetPersonaNameResponse_t, *pSetPersonaNameResponse_t;

// -----------------------------------------------------------------------------
// Purpose: Invoked when the status of unread messages changes
// -----------------------------------------------------------------------------
#define k_iCallbback_UnreadChatMessagesChanged_t ((Int32)(k_iSteamFriendsCallbacks + 48))
typedef struct _UnreadChatMessagesChanged_t_ {

	Int32 Unused;

} UnreadChatMessagesChanged_t, *pUnreadChatMessagesChanged_t;

// -----------------------------------------------------------------------------
// Purpose: Dispatched when an overlay browser instance is navigated to a protocol/scheme registered by RegisterProtocolInOverlayBrowser()
// -----------------------------------------------------------------------------
#define k_iCallbback_OverlayBrowserProtocolNavigation_t ((Int32)(k_iSteamFriendsCallbacks + 49))
typedef struct _OverlayBrowserProtocolNavigation_t_ {
	
	CharA chURI[1024];

} OverlayBrowserProtocolNavigation_t, *pOverlayBrowserProtocolNavigation_t;

// -----------------------------------------------------------------------------
// Purpose: User's equipped profile items have changed
// -----------------------------------------------------------------------------
#define k_iCallbback_EquippedProfileItemsChanged_t ((Int32)(k_iSteamFriendsCallbacks + 50))
typedef struct _EquippedProfileItemsChanged_t_ {

	SteamId_t SteamId;

} EquippedProfileItemsChanged_t, *pEquippedProfileItemsChanged_t;

#define k_iCallbback_EquippedProfileItems_t ((Int32)(k_iSteamFriendsCallbacks + 51))
typedef struct _EquippedProfileItems_t_ {
	
	EResult eResult;
	SteamId_t SteamId;
	Bool bHasAnimatedAvatar;
	Bool bHasAvatarFrame;
	Bool bHasProfileModifier;
	Bool bHasProfileBackground;
	Bool bHasMiniProfileBackground;

} EquippedProfileItems_t, *pEquippedProfileItems_t;

#pragma pack(pop)

#endif // _ISTEAMFRIEND_
