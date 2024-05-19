#ifndef _STEAMREMOTESTORAGE_
#define _STEAMREMOTESTORAGE_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamRemoteStorage.h"
// -----------------------------------------------------------------------------

typedef struct _UGCFileWriteStreamHandle_Value_ {

	HANDLE hFile;

} UGCFileWriteStreamHandle_Value, *pFileWriteStreamHandle_Value;

typedef class _SteamRemoteStorage_ : public _ISteamRemoteStorage_ {
public:

	_SteamRemoteStorage_();
	_SteamRemoteStorage_(const _SteamRemoteStorage_&) = delete;
	_SteamRemoteStorage_& operator=(const _SteamRemoteStorage_&) = delete;

	/* Local IO */
	Bool FileWrite(const pStrA pchFile, const pVoid pvData, Int32 cbData) override;
	Int32 FileRead(const pStrA pchFile, pVoid pvData, Int32 cbDataToRead) override;
	SteamAPICall_t FileWriteAsync(const pStrA pchFile, const pVoid pvData, Uint32 cbData) override;
	SteamAPICall_t FileReadAsync(const pStrA pchFile, Uint32 nOffset, Uint32 cbToRead) override;
	Bool FileReadAsyncComplete(SteamAPICall_t hReadCall, pVoid pvData, Uint32 cbToRead) override;
	Bool FileForget(const pStrA pchFile) override;
	Bool FileDelete(const pStrA pchFile) override;
	SteamAPICall_t FileShare(const pStrA pchFile) override;
	Bool SetSyncPlatforms(const pStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) override;

	/* Network IO */
	UGCFileWriteStreamHandle_t FileWriteStreamOpen(const pStrA pchFile) override;
	Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, const pVoid pvData, Int32 cbData) override;
	Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) override;
	Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) override;

	Bool FileExists_(const pStrA pchFile) override;
	Bool FilePersisted(const pStrA pchFile) override;
	Int32 GetFileSize(const pStrA pchFile) override;
	Int64 GetFileTimestamp(const pStrA pchFile) override;
	ERemoteStoragePlatform GetSyncPlatforms(const pStrA pchFile) override;

	Int32 GetFileCount() override;
	const pStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) override;
	Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) override;
	Bool IsCloudEnabledForAccount() override;
	Bool IsCloudEnabledForApp() override;
	void SetCloudEnabledForApp(Bool bEnabled) override;

	SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) override;
	Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) override;
	Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA* ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) override;
	Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) override;
	Int32 GetCachedUGCCount() override;
	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) override;

	SteamAPICall_t PublishWorkshopFile(const pStrA pchFile, const pStrA pchPreviewFile, AppId_t nConsumerAppId, const pStrA pchTitle, const pStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) override;
	PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) override;
	Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, const pStrA pchFile) override;
	Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, const pStrA pchPreviewFile) override;
	Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, const pStrA pchTitle) override;
	Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, const pStrA pchDescription) override;
	Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) override;
	Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) override;

	SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) override;
	SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) override;
	SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) override;
	SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) override;
	SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) override;
	Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, const pStrA pchChangeDescription) override;
	SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) override;
	SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) override;
	SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, const pStrA pchVideoAccount, const pStrA pchVideoIdentifier, const pStrA pchPreviewFile, AppId_t iConsumerAppId, const pStrA pchTitle, const pStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) override;
	SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) override;
	SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) override;
	SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) override;
	SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, const pStrA pchLocation, Uint32 nPriority) override;

	Int32 GetLocalFileChangeCount() override;
	const pStrA GetLocalFileChange(Int32 iFile, pERemoteStorageLocalFileChange peRemoteStorageLocalFileChange, pERemoteStorageFilePathType peRemoteStorageFilePathType) override;

	Bool BeginFileWriteBatch() override;
	Bool EndFileWriteBatch() override;

	~_SteamRemoteStorage_();

private:

	UGCFileWriteStreamHandle_Value UGCHandles[256];

} SteamRemoteStorage, *pSteamRemoteStorage;

#endif // !_STEAMREMOTESTORAGE_
