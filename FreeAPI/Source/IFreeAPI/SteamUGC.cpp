// -----------------------------------------------------------------------------
#include "SteamUGC.h"
// -----------------------------------------------------------------------------

UGCQueryHandle_t _SteamUGC_::CreateQueryUserUGCRequest(AccountId_t AccountId, EUserUGCList eUserUGCList, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eUserUGCListSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) {

	return k_UGCQueryHandle_Invalid;

}

UGCQueryHandle_t _SteamUGC_::CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) {

	return k_UGCQueryHandle_Invalid;

}

UGCQueryHandle_t _SteamUGC_::CreateQueryAllUGCRequest(EUGCQuery eUGCQuery, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, const pStrA pchCursor) {

	return k_UGCQueryHandle_Invalid;

}

UGCQueryHandle_t _SteamUGC_::CreateQueryUGCDetailsRequest(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileId) {

	return k_UGCQueryHandle_Invalid;

}

SteamAPICall_t _SteamUGC_::SendQueryUGCRequest(UGCQueryHandle_t hUGCQuery) {

	return k_SteamId_t_Invalid;

}

Bool _SteamUGC_::GetQueryUGCResult(UGCQueryHandle_t hUGCQuery, Uint32 i, pSteamUGCDetails_t pSteamUGCDetails) {

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCNumTags(UGCQueryHandle_t hUGCQuery, Uint32 i) {

	return 0U;

}

Bool _SteamUGC_::GetQueryUGCTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) {

	return False;

}

Bool _SteamUGC_::GetQueryUGCTagDisplayName(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iTag, pStrA pchValue, Uint32 cchValue) {

	return False;

}

Bool _SteamUGC_::GetQueryUGCPreviewURL(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchURL, Uint32 cchURL) {

	return False;

}

Bool _SteamUGC_::GetQueryUGCMetadata(UGCQueryHandle_t hUGCQuery, Uint32 i, pStrA pchMetadata, Uint32 cchMetadata) {

	return False;

}

Bool _SteamUGC_::GetQueryUGCChildren(UGCQueryHandle_t hUGCQuery, Uint32 i, pPublishedFileId_t pPublishedFileId, Uint32 cEntries) {

	return False;

}

Bool _SteamUGC_::GetQueryUGCStatistic(UGCQueryHandle_t hUGCQuery, Uint32 i, EItemStatistic eItemStatistic, pUint64 pStatValue) {

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Uint32 i) {

	return 0U;

}

Bool _SteamUGC_::GetQueryUGCAdditionalPreview(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 iPreview, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType pItemPreviewType) {

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCNumKeyValueTags(UGCQueryHandle_t hUGCQuery, Uint32 i) {

	return 0U;

}

Bool _SteamUGC_::GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) {

	return False;

}

Bool _SteamUGC_::GetQueryUGCKeyValueTag(UGCQueryHandle_t hUGCQuery, Uint32 i, const pStrA pchKey, pStrA pchValue, Uint32 cchValueSize) {

	return False;

}

Uint32 _SteamUGC_::GetQueryUGCContentDescriptors(UGCQueryHandle_t hUGCQuery, Uint32 i, pEUGCContentDescriptorId peEUGCContentDescriptorId, Uint32 cEntries) {

	return 0U;

}

Bool _SteamUGC_::ReleaseQueryUGCRequest(UGCQueryHandle_t hUGCQuery) {
	
	return False;

}

Bool _SteamUGC_::AddRequiredTag(UGCQueryHandle_t hUGCQuery, const pStrA pTagName) {
	
	return False;

}

Bool _SteamUGC_::AddRequiredTagGroup(UGCQueryHandle_t hUGCQuery, const pSteamParamStringArray_t pTagGroups) {
	
	return False;

}

Bool _SteamUGC_::AddExcludedTag(UGCQueryHandle_t hUGCQuery, const pStrA pTagName) {
	
	return False;

}

Bool _SteamUGC_::SetReturnOnlyIds(UGCQueryHandle_t hUGCQuery, Bool bReturnOnlyId) {
	
	return False;

}

Bool _SteamUGC_::SetReturnKeyValueTags(UGCQueryHandle_t hUGCQuery, Bool bReturnKeyValueTags) {
	
	return False;

}

Bool _SteamUGC_::SetReturnLongDescription(UGCQueryHandle_t hUGCQuery, Bool bReturnLongDescription) {
	
	return False;

}

Bool _SteamUGC_::SetReturnMetadata(UGCQueryHandle_t hUGCQuery, Bool bReturnMetadata) {
	
	return False;

}

Bool _SteamUGC_::SetReturnChildren(UGCQueryHandle_t hUGCQuery, Bool bReturnChildren) {
	
	return False;

}

Bool _SteamUGC_::SetReturnAdditionalPreviews(UGCQueryHandle_t hUGCQuery, Bool bReturnAdditionalPreviews) {
	
	return False;

}

Bool _SteamUGC_::SetReturnTotalOnly(UGCQueryHandle_t hUGCQuery, Bool bReturnTotalOnly) {
	
	return False;

}

Bool _SteamUGC_::SetReturnPlaytimeStats(UGCQueryHandle_t hUGCQuery, Uint32 nDays) {
	
	return False;

}

Bool _SteamUGC_::SetLanguage(UGCQueryHandle_t hUGCQuery, const pStrA pchLanguage) {
	
	return False;

}

Bool _SteamUGC_::SetAllowCachedResponse(UGCQueryHandle_t hUGCQuery, Uint32 nAgeSeconds) {
	
	return False;

}

Bool _SteamUGC_::SetCloudFileNameFilter(UGCQueryHandle_t hUGCQuery, const pStrA pMatchCloudFileName) {
	
	return False;

}

Bool _SteamUGC_::SetMatchAnyTag(UGCQueryHandle_t hUGCQuery, Bool bMatchAnyTag) {
	
	return False;

}

Bool _SteamUGC_::SetSearchText(UGCQueryHandle_t hUGCQuery, const pStrA pSearchText) {
	
	return False;

}

Bool _SteamUGC_::SetRankedByTrendDays(UGCQueryHandle_t hUGCQuery, Uint32 nDays) {
	
	return False;

}

Bool _SteamUGC_::SetTimeCreatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) {
	
	return False;

}

Bool _SteamUGC_::SetTimeUpdatedDateRange(UGCQueryHandle_t hUGCQuery, RTime32 Start, RTime32 End) {
	
	return False;

}

Bool _SteamUGC_::AddRequiredKeyValueTag(UGCQueryHandle_t hUGCQuery, const pStrA pchKey, const pStrA pchValue) {
	
	return False;

}

SteamAPICall_t _SteamUGC_::RequestUGCDetails(PublishedFileId_t nPublishedFileId, Uint32 uAgeSeconds) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::CreateItem(AppId_t iConsumerAppId, EWorkshopFileType eWorkshopFileType) {
	
	return k_SteamAPICall_Invalid;

}

UGCUpdateHandle_t _SteamUGC_::StartItemUpdate(AppId_t iConsumerAppId, PublishedFileId_t PublishedFileId) {

	return k_UGCUpdateHandle_Invalid;
}

Bool _SteamUGC_::SetItemTitle(UGCUpdateHandle_t hUGCQuery, const pStrA pchTitle) {

	return False;

}

Bool _SteamUGC_::SetItemDescription(UGCUpdateHandle_t hUGCQuery, const pStrA pchDescription) {
	
	return False;

}

Bool _SteamUGC_::SetItemUpdateLanguage(UGCUpdateHandle_t hUGCQuery, const pStrA pchLanguage) {
	
	return False;

}

Bool _SteamUGC_::SetItemMetadata(UGCUpdateHandle_t hUGCQuery, const pStrA pchMetaData) {
	
	return False;

}

Bool _SteamUGC_::SetItemVisibility(UGCUpdateHandle_t hUGCQuery, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility) {
	
	return False;

}

Bool _SteamUGC_::SetItemTags(UGCUpdateHandle_t hUGCUpdate, const pSteamParamStringArray_t pTags) {
	
	return False;

}

Bool _SteamUGC_::SetItemContent(UGCUpdateHandle_t hUGCQuery, const pStrA pszContentFolder) {
	
	return False;

}

Bool _SteamUGC_::SetItemPreview(UGCUpdateHandle_t hUGCQuery, const pStrA pszPreviewFile) {
	
	return False;

}

Bool _SteamUGC_::SetAllowLegacyUpload(UGCUpdateHandle_t hUGCQuery, Bool bAllowLegacyUpload) {
	
	return False;

}

Bool _SteamUGC_::RemoveAllItemKeyValueTags(UGCUpdateHandle_t hUGCQuery) {
	
	return False;

}

Bool _SteamUGC_::RemoveItemKeyValueTags(UGCUpdateHandle_t hUGCQuery, const pStrA pchKey) {
	
	return False;

}

Bool _SteamUGC_::AddItemKeyValueTag(UGCUpdateHandle_t hUGCQuery, const pStrA pchKey, const pStrA pchValue) {
	
	return False;

}

Bool _SteamUGC_::AddItemPreviewFile(UGCUpdateHandle_t hUGCQuery, const pStrA pszPreviewFile, EItemPreviewType type) {
	
	return False;

}

Bool _SteamUGC_::AddItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, const pStrA pszVideoId) {
	
	return False;

}

Bool _SteamUGC_::UpdateItemPreviewFile(UGCUpdateHandle_t hUGCQuery, Uint32 i, const pStrA pszPreviewFile) {
	
	return False;

}

Bool _SteamUGC_::UpdateItemPreviewVideo(UGCUpdateHandle_t hUGCQuery, Uint32 i, const pStrA pszVideoId) {
	
	return False;

}

Bool _SteamUGC_::RemoveItemPreview(UGCUpdateHandle_t hUGCQuery, Uint32 i) {
	
	return False;

}

Bool _SteamUGC_::AddContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) {
	
	return False;

}

Bool _SteamUGC_::RemoveContentDescriptor(UGCUpdateHandle_t hUGCQuery, EUGCContentDescriptorId eUGCContentDescriptorId) {
	
	return False;

}

SteamAPICall_t _SteamUGC_::SubmitItemUpdate(UGCUpdateHandle_t hUGCQuery, const pStrA pchChangeNote) {

	return k_SteamAPICall_Invalid;
}

EItemUpdateStatus _SteamUGC_::GetItemUpdateProgress(UGCUpdateHandle_t hUGCQuery, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) {

	return k_EItemUpdateStatusInvalid;

}

SteamAPICall_t _SteamUGC_::SetUserItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::GetUserItemVote(PublishedFileId_t PublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::AddItemToFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::RemoveItemFromFavorites(AppId_t iAppId, PublishedFileId_t PublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::SubscribeItem(PublishedFileId_t PublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::UnsubscribeItem(PublishedFileId_t PublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

Uint32 _SteamUGC_::GetNumSubscribedItems() {

	return 0U;

}

Uint32 _SteamUGC_::GetSubscribedItems(pPublishedFileId_t pPublishedFileId, Uint32 cEntries) {
	
	return 0U;

}

Uint32 _SteamUGC_::GetItemState(PublishedFileId_t PublishedFileId) {
	
	return 0U;

}

Bool _SteamUGC_::GetItemInstallInfo(PublishedFileId_t PublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolderSize, pUint32 pnTimeStamp) {
	
	return 0U;

}

Bool _SteamUGC_::GetItemDownloadInfo(PublishedFileId_t PublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) {
	
	return False;

}

Bool _SteamUGC_::DownloadItem(PublishedFileId_t PublishedFileId, Bool bHighPriority) {
	
	return False;

}

Bool _SteamUGC_::BInitWorkshopForGameServer(DepotId_t WorkshopDepotId, const pStrA pszFolder) {
	
	return False;

}

void _SteamUGC_::SuspendDownloads(Bool bSuspend) {

	/* Empty Method */

}

SteamAPICall_t _SteamUGC_::StartPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::StopPlaytimeTracking(pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::StopPlaytimeTrackingForAllItems() {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::AddDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::RemoveDependency(PublishedFileId_t ParentPublishedFileId, PublishedFileId_t ChildPublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::AddAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::RemoveAppDependency(PublishedFileId_t PublishedFileId, AppId_t iAppId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::GetAppDependencies(PublishedFileId_t PublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamUGC_::DeleteItem(PublishedFileId_t PublishedFileId) {
	
	return k_SteamAPICall_Invalid;

}

Bool _SteamUGC_::ShowWorkshopEULA() {

	return False;

}

SteamAPICall_t _SteamUGC_::GetWorkshopEULAStatus() {

	return k_SteamAPICall_Invalid;

}
