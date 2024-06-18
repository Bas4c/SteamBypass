#ifndef _ISTEAMUGC_
#define _ISTEAMUGC_

#include "..\..\FreeAPI.Typedef.h"
#include "ISteamRemoteStorage.h"

typedef Uint64 UGCQueryHandle_t, *pUGCQueryHandle_t;
#define k_UGCQueryHandle_Invalid ((UGCQueryHandle_t)(0xFFFFFFFFFFFFFFFF))
typedef Uint64 UGCUpdateHandle_t, *pUGCUpdateHandle_t;
#define k_UGCUpdateHandle_Invalid ((UGCUpdateHandle_t)(0xFFFFFFFFFFFFFFFF))

typedef enum _EUGCMatchingUGCType_ {

	k_EUGCMatchingUGCType_Items,
	k_EUGCMatchingUGCType_Items_Mtx,
	k_EUGCMatchingUGCType_Items_ReadyToUse,
	k_EUGCMatchingUGCType_Collections,
	k_EUGCMatchingUGCType_Artwork,
	k_EUGCMatchingUGCType_Videos,
	k_EUGCMatchingUGCType_Screenshots,
	k_EUGCMatchingUGCType_AllGuides,
	k_EUGCMatchingUGCType_WebGuides,
	k_EUGCMatchingUGCType_IntegratedGuides,
	k_EUGCMatchingUGCType_UsableInGame,
	k_EUGCMatchingUGCType_ControllerBindings,
	k_EUGCMatchingUGCType_GameManagedItems,
	k_EUGCMatchingUGCType_All = (-1)

} EUGCMatchingUGCType, *pEUGCMatchingUGCType;

typedef enum _EUserUGCList_ {

	k_EUserUGCList_Published,
	k_EUserUGCList_VotedOn,
	k_EUserUGCList_VotedUp,
	k_EUserUGCList_VotedDown,
	k_EUserUGCList_WillVoteLater,
	k_EUserUGCList_Favorited,
	k_EUserUGCList_Subscribed,
	k_EUserUGCList_UsedOrPlayed,
	k_EUserUGCList_Followed

} EUserUGCList, *pEUserUGCList;

typedef enum _EUserUGCListSortOrder_ {

	k_EUserUGCListSortOrder_CreationOrderDesc,
	k_EUserUGCListSortOrder_CreationOrderAsc,
	k_EUserUGCListSortOrder_TitleAsc,
	k_EUserUGCListSortOrder_LastUpdatedDesc,
	k_EUserUGCListSortOrder_SubscriptionDateDesc,
	k_EUserUGCListSortOrder_VoteScoreDesc,
	k_EUserUGCListSortOrder_ForModeration

} EUserUGCListSortOrder, *pEUserUGCListSortOrder;

typedef enum _EUGCQuery_ {

	k_EUGCQuery_RankedByVote,
	k_EUGCQuery_RankedByPublicationDate,
	k_EUGCQuery_AcceptedForGameRankedByAcceptanceDate,
	k_EUGCQuery_RankedByTrend,
	k_EUGCQuery_FavoritedByFriendsRankedByPublicationDate,
	k_EUGCQuery_CreatedByFriendsRankedByPublicationDate,
	k_EUGCQuery_RankedByNumTimesReported,
	k_EUGCQuery_CreatedByFollowedUsersRankedByPublicationDate,
	k_EUGCQuery_NotYetRated,
	k_EUGCQuery_RankedByTotalVotesAsc,
	k_EUGCQuery_RankedByVotesUp,
	k_EUGCQuery_RankedByTextSearch,
	k_EUGCQuery_RankedByTotalUniqueSubscriptions,
	k_EUGCQuery_RankedByPlaytimeTrend,
	k_EUGCQuery_RankedByTotalPlaytime,
	k_EUGCQuery_RankedByAveragePlaytimeTrend,
	k_EUGCQuery_RankedByLifetimeAveragePlaytime,
	k_EUGCQuery_RankedByPlaytimeSessionsTrend,
	k_EUGCQuery_RankedByLifetimePlaytimeSessions,
	k_EUGCQuery_RankedByLastUpdatedDate

} EUGCQuery, *pEUGCQuery;

typedef enum _EItemUpdateStatus_ {

	k_EItemUpdateStatusInvalid,
	k_EItemUpdateStatusPreparingConfig,
	k_EItemUpdateStatusPreparingContent,
	k_EItemUpdateStatusUploadingContent,
	k_EItemUpdateStatusUploadingPreviewFile,
	k_EItemUpdateStatusCommittingChanges

} EItemUpdateStatus, *pEItemUpdateStatus;

typedef enum _EItemState_ {

	k_EItemStateNone = 0,
	k_EItemStateSubscribed = 1,
	k_EItemStateLegacyItem = 2,
	k_EItemStateInstalled = 4,
	k_EItemStateNeedsUpdate = 8,
	k_EItemStateDownloading = 16,
	k_EItemStateDownloadPending = 32

} EItemState, *pEItemState;

typedef enum _EItemStatistic_ {

	k_EItemStatistic_NumSubscriptions,
	k_EItemStatistic_NumFavorites,
	k_EItemStatistic_NumFollowers,
	k_EItemStatistic_NumUniqueSubscriptions,
	k_EItemStatistic_NumUniqueFavorites,
	k_EItemStatistic_NumUniqueFollowers,
	k_EItemStatistic_NumUniqueWebsiteViews,
	k_EItemStatistic_ReportScore,
	k_EItemStatistic_NumSecondsPlayed,
	k_EItemStatistic_NumPlaytimeSessions,
	k_EItemStatistic_NumComments,
	k_EItemStatistic_NumSecondsPlayedDuringTimePeriod,
	k_EItemStatistic_NumPlaytimeSessionsDuringTimePeriod

} EItemStatistic, *pEItemStatistic;

typedef enum _EItemPreviewType_ {

	k_EItemPreviewType_Image,
	k_EItemPreviewType_YouTubeVideo,
	k_EItemPreviewType_Sketchfab,
	k_EItemPreviewType_EnvironmentMap_HorizontalCross,	// Cube Map
	// +---+---+-------+
	// |   |Up |       |
	// +---+---+---+---+
	// | L | F | R | B |
	// +---+---+---+---+
	// |   |Dn |       |
	// +---+---+---+---+
	k_EItemPreviewType_EnvironmentMap_LatLong,
	k_EItemPreviewType_ReservedMax = 255,

} EItemPreviewType, *pEItemPreviewType;

typedef enum _EUGCContentDescriptorId_ {

	k_EUGCContentDescriptor_NudityOrSexualContent = 1,
	k_EUGCContentDescriptor_FrequentViolenceOrGore,
	k_EUGCContentDescriptor_AdultOnlySexualContent,
	k_EUGCContentDescriptor_GratuitousSexualContent,
	k_EUGCContentDescriptor_AnyMatureContent

} EUGCContentDescriptorId, *pEUGCContentDescriptorId;

#define k_NumUGCResultsPerPage ((Uint32)(50))
#define k_cchDeveloperMetadataMax ((Uint32)(5000))

typedef struct _SteamUGCDetails_t_ {

	PublishedFileId_t PublishedFileId;
	EResult eResult;
	EWorkshopFileType eFileType;
	AppId_t iCreatorAppId;
	AppId_t iConsumerAppId;
	CharA chTitle[k_cchPublishedDocumentTitleMax];
	CharA chDescription[k_cchPublishedDocumentDescriptionMax];
	Uint64 SteamIdOwner;
	RTime32 Created;
	RTime32 Updated;
	RTime32 AddedToUserList;
	ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility;
	Bool bBanned;
	Bool bAcceptedForUse;
	Bool bTagsTruncated;
	CharA chTags[k_cchTagListMax];
	UGCHandle_t hUGC;
	UGCHandle_t hPreviewUGC;
	CharA pchFileName[k_cchFilenameMax];
	Int32 nFileSize;
	Int32 nPreviewFileSize;
	CharA chURL[k_cchPublishedFileURLMax];
	Uint32 nVotesUp;
	Uint32 nVotesDown;
	Float Score;
	Uint32 nNumChildren;

} SteamUGCDetails_t, *pSteamUGCDetails_t;

typedef class _ISteamUGC001_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;

} ISteamUGC001, *IpSteamUGC001;

typedef class _ISteamUGC002_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;

} ISteamUGC002, *IpSteamUGC002;

typedef class _ISteamUGC003_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;

} ISteamUGC003, *IpSteamUGC003;

typedef class _ISteamUGC004_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;

} ISteamUGC004, *IpSteamUGC004;

typedef class _ISteamUGC005_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;

} ISteamUGC005, *IpSteamUGC005;

typedef class _ISteamUGC006_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;

} ISteamUGC006, *IpSteamUGC006;

typedef class _ISteamUGC007_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;

} ISteamUGC007, *IpSteamUGC007;

typedef class _ISteamUGC008_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;

} ISteamUGC008, *IpSteamUGC008;

typedef class _ISteamUGC009_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;

} ISteamUGC009, *IpSteamUGC009;

typedef class _ISteamUGC010_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;
	virtual SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) = 0;

} ISteamUGC010, *IpSteamUGC010;

typedef class _ISteamUGC012_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;
	virtual SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) = 0;

} ISteamUGC012, *IpSteamUGC012;

typedef class _ISteamUGC013_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, pCStrA pchKey, pStrA pchValue, Uint32 cchValueSize) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;
	virtual SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) = 0;

} ISteamUGC013, *IpSteamUGC013;

typedef class _ISteamUGC014_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, pCStrA pchKey, pStrA pchValue, Uint32 cchValueSize) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;
	virtual SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) = 0;

} ISteamUGC014, *IpSteamUGC014;

typedef class _ISteamUGC015_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Uint32 GetQueryUGCNumTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCTagDisplayName(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, pCStrA pchKey, pStrA pchValue, Uint32 cchValueSize) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;
	virtual SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool ShowWorkshopEULA() = 0;
	virtual SteamAPICall_t GetWorkshopEULAStatus() = 0;

} ISteamUGC015, *IpSteamUGC015;

typedef class _ISteamUGC016_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) = 0;
	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Uint32 GetQueryUGCNumTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCTagDisplayName(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, pCStrA pchKey, pStrA pchValue, Uint32 cchValueSize) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;
	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetTimeCreatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) = 0;
	virtual Bool SetTimeUpdatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;
	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;
	virtual SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool ShowWorkshopEULA() = 0;
	virtual SteamAPICall_t GetWorkshopEULAStatus() = 0;

} ISteamUGC016, *IpSteamUGC016;

// -----------------------------------------------------------------------------
// Purpose: Steam UGC Support API
// -----------------------------------------------------------------------------
typedef class _ISteamUGC_ {
public:

	virtual UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) = 0;
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) = 0;

	virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) = 0;
	virtual SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;

	virtual Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, /* [out] */ pSteamUGCDetails_t pSteamUGCDetails) = 0;
	virtual Uint32 GetQueryUGCNumTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, /* [out] */ pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCTagDisplayName(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, /* [out] */ pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, /* [out] */ pStrA pchURL, Uint32 cchURL) = 0;
	virtual Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, /* [out] */ pStrA pchMetadata, Uint32 cchMetadata) = 0;
	virtual Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, /* [out] */ pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, /* [out] */ pUint64 pStatValue) = 0;
	virtual Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, /* [out] */ pStrA pchURLOrVideoId, Uint32 cchURL, /* [out] */ pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) = 0;
	virtual Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, /* [out] */ pStrA pchKey, Uint32 cchKey, /* [out] */ pStrA pchValue, Uint32 cchValue) = 0;
	virtual Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, pCStrA pchKey, pStrA pchValue, Uint32 cchValueSize) = 0;
	virtual Uint32 GetQueryUGCContentDescriptors(UGCQueryHandle_t hUGCQuery, Uint32 i, /* [out] */ pEUGCContentDescriptorId peEUGCContentDescriptorId, Uint32 cEntries) = 0;
	virtual Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) = 0;

	virtual Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) = 0;
	virtual Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) = 0;
	virtual Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) = 0;
	virtual Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) = 0;
	virtual Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) = 0;
	virtual Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) = 0;
	virtual Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) = 0;
	virtual Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) = 0;
	virtual Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) = 0;
	virtual Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) = 0;
	virtual Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) = 0;
	virtual Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) = 0;
	virtual Bool SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) = 0;
	virtual Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) = 0;
	virtual Bool SetTimeCreatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) = 0;
	virtual Bool SetTimeUpdatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) = 0;
	virtual Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) = 0;
	virtual SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) = 0;
	virtual UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) = 0;
	virtual Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) = 0;
	virtual Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) = 0;
	virtual Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) = 0;
	virtual Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) = 0;
	virtual Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) = 0;
	virtual Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) = 0;
	virtual Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) = 0;
	virtual Bool SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) = 0;
	virtual Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) = 0;
	virtual Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) = 0;
	virtual Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) = 0;
	virtual Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) = 0;
	virtual Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) = 0;
	virtual Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) = 0;
	virtual Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) = 0;
	virtual Bool AddContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) = 0;
	virtual Bool RemoveContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) = 0;
	
	virtual SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) = 0;
	virtual EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, /* [out] */ pUint64 pnBytesProcessed, pUint64 pnBytesTotal) = 0;
	virtual SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) = 0;
	virtual Uint32 GetNumSubscribedItems() = 0;
	virtual Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) = 0;
	virtual Uint32 GetItemState(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, /* [out] */ pUint64 pnSizeOnDisk, /* [out] */ pStrA pchFolder, Uint32 cchFolderSize, /* [out] */ pUint32 pnTimeStamp) = 0;
	virtual Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, /* [out] */ pUint64 pnBytesDownloaded, /* [out] */ pUint64 pnBytesTotal) = 0;
	virtual Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) = 0;
	virtual Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) = 0;
	virtual void SuspendDownloads(Bool bSuspend) = 0;

	virtual SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) = 0;
	virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() = 0;
	virtual SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) = 0;
	virtual SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) = 0;
	virtual SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) = 0;
	
	virtual Bool ShowWorkshopEULA() = 0;
	virtual SteamAPICall_t GetWorkshopEULAStatus() = 0;

} ISteamUGC, *IpSteamUGC;

#define STEAMUGC_INTERFACE_VERSION "STEAMUGC_INTERFACE_VERSION017"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_SteamUGCQueryCompleted_t_ ((Int32)(k_iSteamUGCCallbacks + 1))
typedef struct _SteamUGCQueryCompleted_t_ {

	UGCQueryHandle_t hUGCQuery;
	EResult eResult;
	Uint32 nNumResultsReturned;
	Uint32 nTotalMatchingResults;
	Bool bCachedData;
	CharA chNextCursor[k_cchPublishedFileURLMax];

} SteamUGCQueryCompleted_t, *pSteamUGCQueryCompleted_t;

#define k_iCallbback_SteamUGCRequestUGCDetailsResult_t_ ((Int32)(k_iSteamUGCCallbacks + 2))
typedef struct _SteamUGCRequestUGCDetailsResult_t_ {

	SteamUGCDetails_t SteamUGCDetails;
	Bool bCachedData;

} SteamUGCRequestUGCDetailsResult_t, *pSteamUGCRequestUGCDetailsResult_t;

// -----------------------------------------------------------------------------
// Purpose: ISteamUGC::CreateItem Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_CreateItemResult_t_ ((Int32)(k_iSteamUGCCallbacks + 3))
typedef struct _CreateItemResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	Bool bUserNeedsToAcceptWorkshopLegalAgreement;

} CreateItemResult_t, *pCreateItemResult_t;

// -----------------------------------------------------------------------------
// Purpose: ISteamUGC::SubmitItemUpdate Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_SubmitItemUpdateResult_t_ ((Int32)(k_iSteamUGCCallbacks + 4))
typedef struct _SubmitItemUpdateResult_t_ {

	EResult eResult;
	Bool bUserNeedsToAcceptWorkshopLegalAgreement;
	PublishedFileId_t PublishedFileId;

} SubmitItemUpdateResult_t, *pSubmitItemUpdateResult_t;

#define k_iCallbback_ItemInstalled_t_ ((Int32)(k_iSteamUGCCallbacks + 5))
typedef struct _ItemInstalled_t_ {

	AppId_t iAppId;
	PublishedFileId_t PublishedFileId;

} ItemInstalled_t, *pItemInstalled_t;

// -----------------------------------------------------------------------------
// Purpose: DownloadItem Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_DownloadItemResult_t_ ((Int32)(k_iSteamUGCCallbacks + 6))
typedef struct _DownloadItemResult_t_ {

	AppId_t iAppId;
	PublishedFileId_t PublishedFileId;
	EResult eResult;
} DownloadItemResult_t, *pDownloadItemResult_t;

// -----------------------------------------------------------------------------
// Purpose: AddItemToFavorites or RemoveItemFromFavorites Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_UserFavoriteItemsListChanged_t_ ((Int32)(k_iSteamUGCCallbacks + 7))
typedef struct _UserFavoriteItemsListChanged_t_ {

	PublishedFileId_t PublishedFileId;
	EResult eResult;
	Bool bWasAddRequest;

} UserFavoriteItemsListChanged_t, *pUserFavoriteItemsListChanged_t;

// -----------------------------------------------------------------------------
// Purpose: SetUserItemVote Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_SetUserItemVoteResult_t_ ((Int32)(k_iSteamUGCCallbacks + 8))
typedef struct _SetUserItemVoteResult_t_ {

	PublishedFileId_t PublishedFileId;
	EResult eResult;
	Bool bVoteUp;

} SetUserItemVoteResult_t, *pSetUserItemVoteResult_t;

// -----------------------------------------------------------------------------
// Purpose: GetUserItemVote Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_GetUserItemVoteResult_t_ ((Int32)(k_iSteamUGCCallbacks + 9))
typedef struct _GetUserItemVoteResult_t_ {

	PublishedFileId_t PublishedFileId;
	EResult eResult;
	Bool bVotedUp;
	Bool bVotedDown;
	Bool bVoteSkipped;

} GetUserItemVoteResult_t, *pGetUserItemVoteResult_t;

// -----------------------------------------------------------------------------
// Purpose: StartPlaytimeTracking Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_StartPlaytimeTrackingResult_t_ ((Int32)(k_iSteamUGCCallbacks + 10))
typedef struct _StartPlaytimeTrackingResult_t_ {

	EResult eResult;

} StartPlaytimeTrackingResult_t, *pStartPlaytimeTrackingResult_t;

// -----------------------------------------------------------------------------
// Purpose: StopPlaytimeTracking Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_StopPlaytimeTrackingResult_t_ ((Int32)(k_iSteamUGCCallbacks + 11))
typedef struct _StopPlaytimeTrackingResult_t_ {

	EResult eResult;

} StopPlaytimeTrackingResult_t, *pStopPlaytimeTrackingResult_t;

// -----------------------------------------------------------------------------
// Purpose: AddDependency Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_AddUGCDependencyResult_t_ ((Int32)(k_iSteamUGCCallbacks + 12))
typedef struct _AddUGCDependencyResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	PublishedFileId_t ChildPublishedFileId;

} AddUGCDependencyResult_t, *pAddUGCDependencyResult_t;

// -----------------------------------------------------------------------------
// Purpose: RemoveDependency Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoveUGCDependencyResult_t_ ((Int32)(k_iSteamUGCCallbacks + 13))
typedef struct _RemoveUGCDependencyResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	PublishedFileId_t ChildPublishedFileId;

} RemoveUGCDependencyResult_t, *pRemoveUGCDependencyResult_t;

// -----------------------------------------------------------------------------
// Purpose: AddAppDependency Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_AddAppDependencyResult_t_ ((Int32)(k_iSteamUGCCallbacks + 14))
typedef struct _AddAppDependencyResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	AppId_t iAppId;

} AddAppDependencyResult_t, *pAddAppDependencyResult_t;

// -----------------------------------------------------------------------------
// Purpose: RemoveAppDependency Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoveAppDependencyResult_t_ ((Int32)(k_iSteamUGCCallbacks + 15))
typedef struct _RemoveAppDependencyResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	AppId_t iAppId;

} RemoveAppDependencyResult_t, *pRemoveAppDependencyResult_t;

// -----------------------------------------------------------------------------
// Purpose: Callback may be called Call Result
//  multiple times until all app dependencies have been returned.
// -----------------------------------------------------------------------------
#define k_iCallbback_GetAppDependenciesResult_t_ ((Int32)(k_iSteamUGCCallbacks + 16))
typedef struct _GetAppDependenciesResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	AppId_t rgAppId[32];
	Uint32 nNumAppDependencies;
	Uint32 nTotalNumAppDependencies;

} GetAppDependenciesResult_t, *pGetAppDependenciesResult_t;

// -----------------------------------------------------------------------------
// Purpose: DeleteItem Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_DeleteItemResult_t_ ((Int32)(k_iSteamUGCCallbacks + 17))
typedef struct _DeleteItemResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;

} DeleteItemResult_t, *pDeleteItemResult_t;

#define k_iCallbback_UserSubscribedItemsListChanged_t_ ((Int32)(k_iSteamUGCCallbacks + 18))
typedef struct _UserSubscribedItemsListChanged_t_ {

	AppId_t iAppId;

} UserSubscribedItemsListChanged_t, *pUserSubscribedItemsListChanged_t;

#define k_iCallbback_WorkshopEULAStatus_t_ ((Int32)(k_iSteamUGCCallbacks + 20))
typedef struct _WorkshopEULAStatus_t_ {

	EResult eResult;
	AppId_t iAppId;
	Uint32 nVersion;
	RTime32 Action;
	Bool bAccepted;
	Bool bNeedsAction;

} WorkshopEULAStatus_t, *pWorkshopEULAStatus_t;

#pragma pack(pop)

#endif // _ISTEAMUGC_
