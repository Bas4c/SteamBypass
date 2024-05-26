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

typedef class _SteamRemoteStorage_ : public _ISteamRemoteStorage001_,
 public _ISteamRemoteStorage002_, public _ISteamRemoteStorage003_,
 public _ISteamRemoteStorage004_, public _ISteamRemoteStorage005_,
 public _ISteamRemoteStorage006_, public _ISteamRemoteStorage007_,
 public _ISteamRemoteStorage008_, public _ISteamRemoteStorage009_,
 public _ISteamRemoteStorage010_, public _ISteamRemoteStorage011_,
 public _ISteamRemoteStorage012_, public _ISteamRemoteStorage013_,
 public _ISteamRemoteStorage014_, public _ISteamRemoteStorage_ {
public:

	_SteamRemoteStorage_();
	_SteamRemoteStorage_(const _SteamRemoteStorage_&) = delete;
	_SteamRemoteStorage_& operator=(const _SteamRemoteStorage_&) = delete;

	/* Local IO */
	Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) override;
	Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) override;
	SteamAPICall_t FileWriteAsync(pCStrA pchFile, pCVoid pvData, Uint32 cbData) override;
	SteamAPICall_t FileReadAsync(pCStrA pchFile, Uint32 nOffset, Uint32 cbToRead) override;
	Bool FileReadAsyncComplete(SteamAPICall_t hReadCall, pVoid pvData, Uint32 cbToRead) override;
	Bool FileForget(pCStrA pchFile) override;
	Bool FileDelete(pCStrA pchFile) override;
	SteamAPICall_t FileShare(pCStrA pchFile) override;
	Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) override;

	/* Network IO */
	UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) override;
	Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) override;
	Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) override;
	Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) override;

	Bool FileExists_(pCStrA pchFile) override;
	Bool FilePersisted(pCStrA pchFile) override;
	Int32 GetFileSize(pCStrA pchFile) override;
	Int64 GetFileTimestamp(pCStrA pchFile) override;
	ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) override;

	Int32 GetFileCount() override;
	pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) override;
	Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) override;
	Bool IsCloudEnabledForAccount() override;
	Bool IsCloudEnabledForApp() override;
	void SetCloudEnabledForApp(Bool bEnabled) override;

	SteamAPICall_t UGCDownload(UGCHandle_t hUGC) override;
	SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) override;
	Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) override;
	Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) override;
	Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) override;
	Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset) override;
	Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) override;
	Int32 GetCachedUGCCount() override;
	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) override;

	#if defined(_PS3) || defined(_SERVER)
	void GetFileListFromServer() override;
	Bool FileFetch(pCStrA pchFile) override;
	Bool FilePersist(pCStrA pchFile) override;
	Bool SynchronizeToClient() override;
	Bool SynchronizeToServer() override;
	Bool ResetFileRequestState() override;
	#endif

	SteamAPICall_t PublishFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) override;
	SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) override;
	Bool UpdatePublishedFile(RemoteStorageUpdatePublishedFileRequest_t UpdatePublishedFileRequest) override;
	PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) override;
	Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) override;
	Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) override;
	Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) override;
	Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) override;
	Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) override;
	Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) override;

	SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) override;
	SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) override;
	SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) override;
	SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) override;
	SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) override;
	Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) override;
	SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) override;
	SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) override;
	SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) override;
	SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) override;
	SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) override;
	SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) override;
	SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) override;
	SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) override;

	Int32 GetLocalFileChangeCount() override;
	pCStrA GetLocalFileChange(Int32 iFile, pERemoteStorageLocalFileChange peRemoteStorageLocalFileChange, pERemoteStorageFilePathType peRemoteStorageFilePathType) override;

	Bool BeginFileWriteBatch() override;
	Bool EndFileWriteBatch() override;

	~_SteamRemoteStorage_();

private:

	UGCFileWriteStreamHandle_Value UGCHandle[256];

 } SteamRemoteStorage, *pSteamRemoteStorage;

#endif // !_STEAMREMOTESTORAGE_
