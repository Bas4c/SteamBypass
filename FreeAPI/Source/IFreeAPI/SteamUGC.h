#ifndef _STEAMUGC_
#define _STEAMUGC_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamUGC.h"
// -----------------------------------------------------------------------------

typedef class _SteamUGC_ : public _ISteamUGC_ {
public:

	_SteamUGC_() = default;
	_SteamUGC_(const _SteamUGC_&) = delete;
	_SteamUGC_& operator=(const _SteamUGC_&) = delete;

	UGCQueryHandle_t CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) override;

	UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) override;
	UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, const pStrA pchCursor) override;

	UGCQueryHandle_t CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) override;
	SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) override;

	Bool GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) override;
	Uint32 GetQueryUGCNumTags(UGCQueryHandle_t hUGCQuery, Uint32 i) override;
	Bool GetQueryUGCTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) override;
	Bool GetQueryUGCTagDisplayName(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) override;
	Bool GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) override;
	Bool GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) override;
	Bool GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) override;
	Bool GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) override;
	Uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) override;
	Bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) override;
	Uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) override;
	Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) override;
	Bool GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, const pStrA pchKey, pStrA pchValue, Uint32 cchValueSize) override;
	Uint32 GetQueryUGCContentDescriptors(UGCQueryHandle_t hUGCQuery, Uint32 i, pEUGCContentDescriptorId peEUGCContentDescriptorId, Uint32 cEntries) override;
	Bool ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) override;

	Bool AddRequiredTag(UGCQueryHandle_t hUGCQuery, const pStrA pTagName) override;
	Bool AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) override;
	Bool AddExcludedTag(UGCQueryHandle_t hUGCQuery, const pStrA pTagName) override;
	Bool SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) override;
	Bool SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) override;
	Bool SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) override;
	Bool SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) override;
	Bool SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) override;
	Bool SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) override;
	Bool SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) override;
	Bool SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) override;
	Bool SetLanguage(UGCQueryHandle_t hUGCQuery, const pStrA pchLanguage) override;
	Bool SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) override;
	Bool SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, const pStrA pMatchCloudFileName) override;
	Bool SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) override;
	Bool SetSearchText(UGCQueryHandle_t hUGCQuery, const pStrA pSearchText) override;
	Bool SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) override;
	Bool SetTimeCreatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) override;
	Bool SetTimeUpdatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) override;
	Bool AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, const pStrA pchKey, const pStrA pchValue) override;
	SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) override;
	SteamAPICall_t CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) override;
	UGCUpdateHandle_t StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) override;
	Bool SetItemTitle(UGCUpdateHandle_t hUGCQuery, const pStrA pchTitle) override;
	Bool SetItemDescription(UGCUpdateHandle_t hUGCQuery, const pStrA pchDescription) override;
	Bool SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, const pStrA pchLanguage) override;
	Bool SetItemMetadata(UGCUpdateHandle_t hUGCQuery, const pStrA pchMetaData) override;
	Bool SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) override;
	Bool SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) override;
	Bool SetItemContent(UGCUpdateHandle_t hUGCQuery, const pStrA pszContentFolder) override;
	Bool SetItemPreview(UGCUpdateHandle_t hUGCQuery, const pStrA pszPreviewFile) override;
	Bool SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) override;
	Bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) override;
	Bool RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, const pStrA pchKey) override;
	Bool AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, const pStrA pchKey, const pStrA pchValue) override;
	Bool AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, const pStrA pszPreviewFile, EItemPreviewType type) override;
	Bool AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, const pStrA pszVideoId) override;
	Bool UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, const pStrA pszPreviewFile) override;
	Bool UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, const pStrA pszVideoId) override;
	Bool RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) override;
	Bool AddContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) override;
	Bool RemoveContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) override;

	SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, const pStrA pchChangeNote) override;
	EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) override;
	SteamAPICall_t SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) override;
	SteamAPICall_t GetUserItemVote(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t SubscribeItem(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t UnsubscribeItem(PublishedFileId_t PublishedFileId) override;
	Uint32 GetNumSubscribedItems() override;
	Uint32 GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) override;
	Uint32 GetItemState(PublishedFileId_t PublishedFileId) override;
	Bool GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) override;
	Bool GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) override;
	Bool DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) override;
	Bool BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, const pStrA pszFolder) override;
	void SuspendDownloads(Bool bSuspend) override;

	SteamAPICall_t StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) override;
	SteamAPICall_t StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) override;
	SteamAPICall_t StopPlaytimeTrackingForAllItems() override;
	SteamAPICall_t AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) override;
	SteamAPICall_t RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) override;
	SteamAPICall_t AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) override;
	SteamAPICall_t RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) override;
	SteamAPICall_t GetAppDependencies(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t DeleteItem(PublishedFileId_t PublishedFileId) override;

	Bool ShowWorkshopEULA() override;
	SteamAPICall_t GetWorkshopEULAStatus() override;

	~_SteamUGC_() = default;

} SteamUGC, *pSteamUGC;

#endif // !_STEAMUGC_
