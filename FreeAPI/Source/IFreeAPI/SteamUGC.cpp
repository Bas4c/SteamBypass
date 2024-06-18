// -----------------------------------------------------------------------------
#include "SteamUGC.h"
// -----------------------------------------------------------------------------

UGCQueryHandle_t _SteamUGC_::CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) {
	DEBUGBREAK("ISteamUGC::CreateQueryUserUGCRequest");

	return k_UGCQueryHandle_Invalid;

}

UGCQueryHandle_t _SteamUGC_::CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) {
	DEBUGBREAK("ISteamUGC::CreateQueryAllUGCRequest");

	return k_UGCQueryHandle_Invalid;

}

UGCQueryHandle_t _SteamUGC_::CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) {
	DEBUGBREAK("ISteamUGC::CreateQueryAllUGCRequest");

	return k_UGCQueryHandle_Invalid;

}

UGCQueryHandle_t _SteamUGC_::CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) {
	DEBUGBREAK("ISteamUGC::CreateQueryUGCDetailsRequest");

	return k_UGCQueryHandle_Invalid;

}

SteamAPICall_t _SteamUGC_::SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) {
	DEBUGBREAK("ISteamUGC::SendQueryUGCRequest");

	return k_SteamAPICall_Invalid;

}

Bool _SteamUGC_::GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCResult");

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCNumTags(UGCQueryHandle_t hUGCQuery, Uint32 i) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCNumTags");

	return 0U;

}

Bool _SteamUGC_::GetQueryUGCTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCTag");

	return False;

}

Bool _SteamUGC_::GetQueryUGCTagDisplayName(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCTagDisplayName");

	return False;

}

Bool _SteamUGC_::GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCPreviewURL");

	return False;

}

Bool _SteamUGC_::GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCMetadata");

	return False;

}

Bool _SteamUGC_::GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCChildren");

	return False;

}

Bool _SteamUGC_::GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCStatistic");

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCNumAdditionalPreviews");

	return 0U;

}

Bool _SteamUGC_::GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCAdditionalPreview");

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCNumKeyValueTags");

	return 0U;

}

Bool _SteamUGC_::GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCKeyValueTag");

	return False;

}

Bool _SteamUGC_::GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, pCStrA pchKey, pStrA pchValue, Uint32 cchValueSize) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCKeyValueTag");

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCContentDescriptors(UGCQueryHandle_t hUGCQuery, Uint32 i, pEUGCContentDescriptorId peEUGCContentDescriptorId, Uint32 cEntries) {
	DEBUGBREAK("ISteamUGC::GetQueryUGCContentDescriptors");

	return 0U;

}

Bool _SteamUGC_::ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) {
	DEBUGBREAK("ISteamUGC::ReleaseQueryUGCRequest");
	
	return False;

}

Bool _SteamUGC_::AddRequiredTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) {
	DEBUGBREAK("ISteamUGC::AddRequiredTag");
	
	return False;

}

Bool _SteamUGC_::AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) {
	DEBUGBREAK("ISteamUGC::AddRequiredTagGroup");
	
	return False;

}

Bool _SteamUGC_::AddExcludedTag(UGCQueryHandle_t hUGCQuery, pCStrA pTagName) {
	DEBUGBREAK("ISteamUGC::AddExcludedTag");
	
	return False;

}

Bool _SteamUGC_::SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) {
	DEBUGBREAK("ISteamUGC::SetReturnOnlyIds");
	
	return False;

}

Bool _SteamUGC_::SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) {
	DEBUGBREAK("ISteamUGC::SetReturnKeyValueTags");
	
	return False;

}

Bool _SteamUGC_::SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) {
	DEBUGBREAK("ISteamUGC::SetReturnLongDescription");
	
	return False;

}

Bool _SteamUGC_::SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) {
	DEBUGBREAK("ISteamUGC::SetReturnMetadata");
	
	return False;

}

Bool _SteamUGC_::SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) {
	DEBUGBREAK("ISteamUGC::SetReturnChildren");
	
	return False;

}

Bool _SteamUGC_::SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) {
	DEBUGBREAK("ISteamUGC::SetReturnAdditionalPreviews");
	
	return False;

}

Bool _SteamUGC_::SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) {
	DEBUGBREAK("ISteamUGC::SetReturnTotalOnly");
	
	return False;

}

Bool _SteamUGC_::SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) {
	DEBUGBREAK("ISteamUGC::SetReturnPlaytimeStats");
	
	return False;

}

Bool _SteamUGC_::SetLanguage(UGCQueryHandle_t hUGCQuery, pCStrA pchLanguage) {
	DEBUGBREAK("ISteamUGC::SetLanguage");
	
	return False;

}

Bool _SteamUGC_::SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) {
	DEBUGBREAK("ISteamUGC::SetAllowCachedResponse");
	
	return False;

}

Bool _SteamUGC_::SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, pCStrA pMatchCloudFileName) {
	DEBUGBREAK("ISteamUGC::SetCloudFileNameFilter");
	
	return False;

}

Bool _SteamUGC_::SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) {
	DEBUGBREAK("ISteamUGC::SetMatchAnyTag");
	
	return False;

}

Bool _SteamUGC_::SetSearchText(UGCQueryHandle_t hUGCQuery, pCStrA pSearchText) {
	DEBUGBREAK("ISteamUGC::SetSearchText");
	
	return False;

}

Bool _SteamUGC_::SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) {
	DEBUGBREAK("ISteamUGC::SetRankedByTrendDays");
	
	return False;

}

Bool _SteamUGC_::SetTimeCreatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) {
	DEBUGBREAK("ISteamUGC::SetTimeCreatedDateRange");
	
	return False;

}

Bool _SteamUGC_::SetTimeUpdatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) {
	DEBUGBREAK("ISteamUGC::SetTimeUpdatedDateRange");
	
	return False;

}

Bool _SteamUGC_::AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamUGC::AddRequiredKeyValueTag");
	
	return False;

}

SteamAPICall_t _SteamUGC_::RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) {
	DEBUGBREAK("ISteamUGC::RequestUGCDetails");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) {
	DEBUGBREAK("ISteamUGC::CreateItem");
	
	return k_SteamAPICall_Invalid;

}

UGCUpdateHandle_t _SteamUGC_::StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::StartItemUpdate");

	return k_UGCUpdateHandle_Invalid;
}

Bool _SteamUGC_::SetItemTitle(UGCUpdateHandle_t hUGCQuery, pCStrA pchTitle) {
	DEBUGBREAK("ISteamUGC::SetItemTitle");

	return False;

}

Bool _SteamUGC_::SetItemDescription(UGCUpdateHandle_t hUGCQuery, pCStrA pchDescription) {
	DEBUGBREAK("ISteamUGC::SetItemDescription");
	
	return False;

}

Bool _SteamUGC_::SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, pCStrA pchLanguage) {
	DEBUGBREAK("ISteamUGC::SetItemUpdateLanguage");
	
	return False;

}

Bool _SteamUGC_::SetItemMetadata(UGCUpdateHandle_t hUGCQuery, pCStrA pchMetaData) {
	DEBUGBREAK("ISteamUGC::SetItemMetadata");
	
	return False;

}

Bool _SteamUGC_::SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) {
	DEBUGBREAK("ISteamUGC::SetItemVisibility");
	
	return False;

}

Bool _SteamUGC_::SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) {
	DEBUGBREAK("ISteamUGC::SetItemTags");
	
	return False;

}

Bool _SteamUGC_::SetItemContent(UGCUpdateHandle_t hUGCQuery, pCStrA pchContentFolder) {
	DEBUGBREAK("ISteamUGC::SetItemContent");
	
	return False;

}

Bool _SteamUGC_::SetItemPreview(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile) {
	DEBUGBREAK("ISteamUGC::SetItemPreview");
	
	return False;

}

Bool _SteamUGC_::SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) {
	DEBUGBREAK("ISteamUGC::SetAllowLegacyUpload");
	
	return False;

}

Bool _SteamUGC_::RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) {
	DEBUGBREAK("ISteamUGC::RemoveAllItemKeyValueTags");
	
	return False;

}

Bool _SteamUGC_::RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey) {
	DEBUGBREAK("ISteamUGC::RemoveItemKeyValueTags");
	
	return False;

}

Bool _SteamUGC_::AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamUGC::AddItemKeyValueTag");
	
	return False;

}

Bool _SteamUGC_::AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, pCStrA pchPreviewFile, EItemPreviewType type) {
	DEBUGBREAK("ISteamUGC::AddItemPreviewFile");
	
	return False;

}

Bool _SteamUGC_::AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, pCStrA pchVideoId) {
	DEBUGBREAK("ISteamUGC::AddItemPreviewVideo");
	
	return False;

}

Bool _SteamUGC_::UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchPreviewFile) {
	DEBUGBREAK("ISteamUGC::UpdateItemPreviewFile");
	
	return False;

}

Bool _SteamUGC_::UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, pCStrA pchVideoId) {
	DEBUGBREAK("ISteamUGC::UpdateItemPreviewVideo");
	
	return False;

}

Bool _SteamUGC_::RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) {
	DEBUGBREAK("ISteamUGC::RemoveItemPreview");
	
	return False;

}

Bool _SteamUGC_::AddContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) {
	DEBUGBREAK("ISteamUGC::AddContentDescriptor");
	
	return False;

}

Bool _SteamUGC_::RemoveContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) {
	DEBUGBREAK("ISteamUGC::RemoveContentDescriptor");
	
	return False;

}

SteamAPICall_t _SteamUGC_::SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, pCStrA pchChangeNote) {
	DEBUGBREAK("ISteamUGC::SubmitItemUpdate");

	return k_SteamAPICall_Invalid;
}

EItemUpdateStatus _SteamUGC_::GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) {
	DEBUGBREAK("ISteamUGC::GetItemUpdateProgress");

	return k_EItemUpdateStatusInvalid;

}

SteamAPICall_t _SteamUGC_::SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) {
	DEBUGBREAK("ISteamUGC::SetUserItemVote");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::GetUserItemVote(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::GetUserItemVote");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::AddItemToFavorites");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::RemoveItemFromFavorites");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::SubscribeItem(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::SubscribeItem");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::UnsubscribeItem(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::UnsubscribeItem");
	
	return k_SteamAPICall_Invalid;

}

Uint32 _SteamUGC_::GetNumSubscribedItems() {
	DEBUGBREAK("ISteamUGC::GetNumSubscribedItems");

	return 0U;

}

Uint32 _SteamUGC_::GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) {
	DEBUGBREAK("ISteamUGC::GetSubscribedItems");
	
	return 0U;

}

Uint32 _SteamUGC_::GetItemState(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::GetItemState");
	
	return 0U;

}

Bool _SteamUGC_::GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) {
	DEBUGBREAK("ISteamUGC::GetItemInstallInfo");
	
	return 0U;

}

Bool _SteamUGC_::GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) {
	DEBUGBREAK("ISteamUGC::GetItemDownloadInfo");
	
	return False;

}

Bool _SteamUGC_::DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) {
	DEBUGBREAK("ISteamUGC::DownloadItem");
	
	return False;

}

Bool _SteamUGC_::BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, pCStrA pchFolder) {
	DEBUGBREAK("ISteamUGC::BInitWorkshopForGameServer");
	
	return False;

}

void _SteamUGC_::SuspendDownloads(Bool bSuspend) {
	DEBUGBREAK("ISteamUGC::SuspendDownloads");

	/* Empty Method */

}

SteamAPICall_t _SteamUGC_::StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) {
	DEBUGBREAK("ISteamUGC::StartPlaytimeTracking");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) {
	DEBUGBREAK("ISteamUGC::StopPlaytimeTracking");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::StopPlaytimeTrackingForAllItems() {
	DEBUGBREAK("ISteamUGC::StopPlaytimeTrackingForAllItems");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) {
	DEBUGBREAK("ISteamUGC::AddDependency");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) {
	DEBUGBREAK("ISteamUGC::RemoveDependency");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) {
	DEBUGBREAK("ISteamUGC::AddAppDependency");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) {
	DEBUGBREAK("ISteamUGC::RemoveAppDependency");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::GetAppDependencies(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::GetAppDependencies");
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::DeleteItem(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamUGC::DeleteItem");
	
	return k_SteamAPICall_Invalid;

}

Bool _SteamUGC_::ShowWorkshopEULA() {
	DEBUGBREAK("ISteamUGC::ShowWorkshopEULA");

	return False;

}

SteamAPICall_t _SteamUGC_::GetWorkshopEULAStatus() {
	DEBUGBREAK("ISteamUGC::GetWorkshopEULAStatus");

	return k_SteamAPICall_Invalid;

}
