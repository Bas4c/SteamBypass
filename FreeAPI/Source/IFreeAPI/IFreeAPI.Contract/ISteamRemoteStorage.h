#ifndef _ISTEAMREMOTESTORAGE_
#define _ISTEAMREMOTESTORAGE_

#include "..\..\FreeAPI.Typedef.h"

// -----------------------------------------------------------------------------
// Purpose: Defines the largest allowed file size. Cloud files cannot be written
//  in a single chunk over 100MB (and cannot be over 200MB total)
// -----------------------------------------------------------------------------
#define k_CloudFileChunkMaxSize ((Uint32)(104857600))

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

typedef struct _SteamParamStringArray_t_ {

	pCStrA *ppStrings;
	Int32 nNumStrings;

} SteamParamStringArray_t, *pSteamParamStringArray_t;

#pragma pack(pop)

typedef Uint64 UGCFileWriteStreamHandle_t, *pUGCFileWriteStreamHandle_t;
#define k_UGCFileStreamHandle_Invalid ((UGCFileWriteStreamHandle_t)(0xFFFFFFFFFFFFFFFF))

#define k_cchPublishedDocumentTitleMax ((Uint32)(128 + 1))
#define k_cchPublishedDocumentDescriptionMax ((Uint32)(8000))
#define k_cchPublishedDocumentChangeDescriptionMax ((Uint32)(8000))
#define k_EnumeratePublishedFilesMaxResults ((Uint32)(50))
#define k_cchTagListMax ((Uint32)(1024 + 1))
#define k_cchFilenameMax ((Uint32)(260))
#define k_cchPublishedFileURLMax ((Uint32)(256))

typedef enum _ERemoteStoragePlatform_ {

	k_ERemoteStoragePlatformNone = 0x00000001,
	k_ERemoteStoragePlatformWindows = 0x00000001,
	k_ERemoteStoragePlatformOSX = 0x00000002,
	k_ERemoteStoragePlatformPS3 = 0x00000004,
	k_ERemoteStoragePlatformLinux = 0x00000008,
	k_ERemoteStoragePlatformSwitch = 0x00000010,
	k_ERemoteStoragePlatformAndroid = 0x00000020,
	k_ERemoteStoragePlatformIOS = 0x00000040,
	k_ERemoteStoragePlatformAll = 0xFFFFFFFF

} ERemoteStoragePlatform, *pERemoteStoragePlatform;

typedef enum _ERemoteStoragePublishedFileVisibility_ {

	k_ERemoteStoragePublishedFileVisibilityPublic,
	k_ERemoteStoragePublishedFileVisibilityFriendsOnly,
	k_ERemoteStoragePublishedFileVisibilityPrivate,
	k_ERemoteStoragePublishedFileVisibilityUnlisted

} ERemoteStoragePublishedFileVisibility, *pERemoteStoragePublishedFileVisibility;

typedef enum _EWorkshopFileType_ {

	k_EWorkshopFileTypeFirst,
	k_EWorkshopFileTypeCommunity = 0,
	k_EWorkshopFileTypeMicrotransaction = 1,
	k_EWorkshopFileTypeCollection,
	k_EWorkshopFileTypeArt,
	k_EWorkshopFileTypeVideo,
	k_EWorkshopFileTypeScreenshot5,
	k_EWorkshopFileTypeGame,
	k_EWorkshopFileTypeSoftware,
	k_EWorkshopFileTypeConcept,
	k_EWorkshopFileTypeWebGuide,
	k_EWorkshopFileTypeIntegratedGuide,
	k_EWorkshopFileTypeMerch,
	k_EWorkshopFileTypeControllerBinding,
	k_EWorkshopFileTypeSteamworksAccessInvite,
	k_EWorkshopFileTypeSteamVideo,
	k_EWorkshopFileTypeGameManagedItem,
	k_EWorkshopFileTypeMax

} EWorkshopFileType, *pEWorkshopFileType;

typedef enum _EWorkshopVote_ {

	k_EWorkshopVoteUnvoted,
	k_EWorkshopVoteFor,
	k_EWorkshopVoteAgainst,
	k_EWorkshopVoteLater

} EWorkshopVote, *pEWorkshopVote;

typedef enum _EWorkshopFileAction_ {

	k_EWorkshopFileActionPlayed,
	k_EWorkshopFileActionCompleted

} EWorkshopFileAction, *pEWorkshopFileAction;

typedef enum _EWorkshopEnumerationType_ {

	k_EWorkshopEnumerationTypeRankedByVote,
	k_EWorkshopEnumerationTypeRecent,
	k_EWorkshopEnumerationTypeTrending,
	k_EWorkshopEnumerationTypeFavoritesOfFriends,
	k_EWorkshopEnumerationTypeVotedByFriends,
	k_EWorkshopEnumerationTypeContentByFriends,
	k_EWorkshopEnumerationTypeRecentFromFollowedUsers

} EWorkshopEnumerationType, *pEWorkshopEnumerationType;

typedef enum _EWorkshopVideoProvider_ {

	k_EWorkshopVideoProviderNone,
	k_EWorkshopVideoProviderYoutube

} EWorkshopVideoProvider, *pEWorkshopVideoProvider;

typedef enum _EUGCReadAction_ {

	k_EUGCRead_ContinueReadingUntilFinished,
	k_EUGCRead_ContinueReading,
	k_EUGCRead_Close

} EUGCReadAction, *pEUGCReadAction;

typedef enum _ERemoteStorageLocalFileChange_ {

	k_ERemoteStorageLocalFileChange_Invalid,
	k_ERemoteStorageLocalFileChange_FileUpdated,
	k_ERemoteStorageLocalFileChange_FileDeleted

} ERemoteStorageLocalFileChange, *pERemoteStorageLocalFileChange;

typedef enum _ERemoteStorageFilePathType_ {

	k_ERemoteStorageFilePathType_Invalid,
	k_ERemoteStorageFilePathType_Absolute,
	k_ERemoteStorageFilePathType_APIFilename

} ERemoteStorageFilePathType, *pERemoteStorageFilePathType;

typedef struct _RemoteStorageUpdatePublishedFileRequest_t_ {

	PublishedFileId_t PublishedFileId;
	pCStrA pchFile;
	pCStrA pchPreviewFile;
	pCStrA pchTitle;
	pCStrA pchDescription;
	ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility;
	SteamParamStringArray_t *pTags;
	Bool bUpdateFile;
	Bool bUpdatePreviewFile;
	Bool bUpdateTitle;
	Bool bUpdateDescription;
	Bool bUpdateVisibility;
	Bool bUpdateTags;

} RemoteStorageUpdatePublishedFileRequest_t, *pRemoteStorageUpdatePublishedFileRequest_t;

typedef class _ISteamRemoteStorage001_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;

} ISteamRemoteStorage001, *IpSteamRemoteStorage001;

typedef class _ISteamRemoteStorage002_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;

} ISteamRemoteStorage002, *IpSteamRemoteStorage002;

typedef class _ISteamRemoteStorage003_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;

} ISteamRemoteStorage003, *IpSteamRemoteStorage003;

typedef class _ISteamRemoteStorage004_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;

} ISteamRemoteStorage004, *IpSteamRemoteStorage004;

typedef class _ISteamRemoteStorage005_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	#if defined(_PS3) || defined(_SERVER)
	virtual void GetFileListFromServer() = 0;
	virtual Bool FileFetch(pCStrA pchFile) = 0;
	virtual Bool FilePersist(pCStrA pchFile) = 0;
	virtual Bool SynchronizeToClient() = 0;
	virtual Bool SynchronizeToServer() = 0;
	virtual Bool ResetFileRequestState() = 0;
	#endif
	virtual SteamAPICall_t PublishFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual Bool UpdatePublishedFile(RemoteStorageUpdatePublishedFileRequest_t UpdatePublishedFileRequest) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;

} ISteamRemoteStorage005, *IpSteamRemoteStorage005;

typedef class _ISteamRemoteStorage006_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;

} ISteamRemoteStorage006, *IpSteamRemoteStorage006;

typedef class _ISteamRemoteStorage007_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;

} ISteamRemoteStorage007, *IpSteamRemoteStorage007;

typedef class _ISteamRemoteStorage008_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;

} ISteamRemoteStorage008, *IpSteamRemoteStorage008;

typedef class _ISteamRemoteStorage009_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA* ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;

} ISteamRemoteStorage009, *IpSteamRemoteStorage009;

typedef class _ISteamRemoteStorage010_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;
	virtual SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) = 0;

} ISteamRemoteStorage010, *IpSteamRemoteStorage010;

typedef class _ISteamRemoteStorage011_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;
	virtual SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) = 0;

} ISteamRemoteStorage011, *IpSteamRemoteStorage011;

typedef class _ISteamRemoteStorage012_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	#if defined(_PS3) || defined(_SERVER)
	virtual void GetFileListFromServer() = 0;
	virtual Bool FileFetch(pCStrA pchFile) = 0;
	virtual Bool FilePersist(pCStrA pchFile) = 0;
	virtual Bool SynchronizeToClient() = 0;
	virtual Bool SynchronizeToServer() = 0;
	virtual Bool ResetFileRequestState() = 0;
	#endif
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;
	virtual SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) = 0;

} ISteamRemoteStorage012, *IpSteamRemoteStorage012;

typedef class _ISteamRemoteStorage013_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual SteamAPICall_t FileWriteAsync(pCStrA pchFile, pCVoid pvData, Uint32 cbData) = 0;
	virtual SteamAPICall_t FileReadAsync(pCStrA pchFile, Uint32 nOffset, Uint32 cbToRead) = 0;
	virtual Bool FileReadAsyncComplete(SteamAPICall_t hReadCall, pVoid pvData, Uint32 cbToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	#if defined(_PS3) || defined(_SERVER)
	virtual void GetFileListFromServer() = 0;
	virtual Bool FileFetch(pCStrA pchFile) = 0;
	virtual Bool FilePersist(pCStrA pchFile) = 0;
	virtual Bool SynchronizeToClient() = 0;
	virtual Bool SynchronizeToServer() = 0;
	virtual Bool ResetFileRequestState() = 0;
	#endif
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;
	virtual SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) = 0;

} ISteamRemoteStorage013, *IpSteamRemoteStorage013;

typedef class _ISteamRemoteStorage014_ {
public:

	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) = 0;
	virtual SteamAPICall_t FileWriteAsync(pCStrA pchFile, pCVoid pvData, Uint32 cbData) = 0;
	virtual SteamAPICall_t FileReadAsync(pCStrA pchFile, Uint32 nOffset, Uint32 cbToRead) = 0;
	virtual Bool FileReadAsyncComplete(SteamAPICall_t hReadCall, pVoid pvData, Uint32 cbToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;
	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;
	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;
	#if defined(_PS3) || defined(_SERVER)
	virtual void GetFileListFromServer() = 0;
	virtual Bool FileFetch(pCStrA pchFile) = 0;
	virtual Bool FilePersist(pCStrA pchFile) = 0;
	virtual Bool SynchronizeToClient() = 0;
	virtual Bool SynchronizeToServer() = 0;
	virtual Bool ResetFileRequestState() = 0;
	#endif
	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;
	virtual SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) = 0;

} ISteamRemoteStorage014, *IpSteamRemoteStorage014;

// -----------------------------------------------------------------------------
// Purpose: Functions for accessing, reading and writing files stored remotely 
//  and cached locally
// -----------------------------------------------------------------------------
typedef class _ISteamRemoteStorage_ {
public:

	/* Local IO */
	virtual Bool FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) = 0;
	virtual Int32 FileRead(pCStrA pchFile, /* [out] */ pVoid pvData, Int32 cbDataToRead) = 0;
	virtual SteamAPICall_t FileWriteAsync(pCStrA pchFile, pCVoid pvData, Uint32 cbData) = 0;
	virtual SteamAPICall_t FileReadAsync(pCStrA pchFile, Uint32 nOffset, Uint32 cbToRead) = 0;
	virtual Bool FileReadAsyncComplete(SteamAPICall_t hReadCall, /* [out] */ pVoid pvData, Uint32 cbToRead) = 0;
	virtual Bool FileForget(pCStrA pchFile) = 0;
	virtual Bool FileDelete(pCStrA pchFile) = 0;
	virtual SteamAPICall_t FileShare(pCStrA pchFile) = 0;
	virtual Bool SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) = 0;
	
	/* Network IO */
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen(pCStrA pchFile) = 0;
	virtual Bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) = 0;
	virtual Bool FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) = 0;
	virtual Bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) = 0;

	virtual Bool FileExists_(pCStrA pchFile) = 0;
	virtual Bool FilePersisted(pCStrA pchFile) = 0;
	virtual Int32 GetFileSize(pCStrA pchFile) = 0;
	virtual Int64 GetFileTimestamp(pCStrA pchFile) = 0;
	virtual ERemoteStoragePlatform GetSyncPlatforms(pCStrA pchFile) = 0;

	virtual Int32 GetFileCount() = 0;
	virtual pCStrA GetFileNameAndSize(Int32 iFile, /* [out] */ pInt32 pnFileSizeInBytes) = 0;
	virtual Bool GetQuota(/* [out] */ pUint64 pnTotalBytes, /* [out] */ pUint64 pnAvailableBytes) = 0;
	virtual Bool IsCloudEnabledForAccount() = 0;
	virtual Bool IsCloudEnabledForApp() = 0;
	virtual void SetCloudEnabledForApp(Bool bEnabled) = 0;

	virtual SteamAPICall_t UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) = 0;
	virtual Bool GetUGCDownloadProgress(UGCHandle_t hUGC, /* [out] */ pInt32 pnBytesDownloaded, /* [out] */ pInt32 pnBytesExpected) = 0;
	virtual Bool GetUGCDetails(UGCHandle_t hUGC, /* [out] */ pAppId_t piAppId, /* [out] */ pStrA *ppchName, /* [out] */ pInt32 pnFileSizeInBytes, /* [out] */ pSteamId_t pSteamIdOwner) = 0;
	virtual Int32 UGCRead(UGCHandle_t hUGC, /* [out] */ pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) = 0;
	virtual Int32 GetCachedUGCCount() = 0;
	virtual	UGCHandle_t GetCachedUGCHandle(Int32 iCachedContent) = 0;

	virtual SteamAPICall_t PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) = 0;
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) = 0;
	virtual Bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) = 0;
	virtual Bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) = 0;
	virtual Bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) = 0;
	virtual Bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) = 0;
	virtual Bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) = 0;
	
	virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) = 0;
	virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) = 0;
	virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserPublishedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSubscribedFiles(Uint32 iStart) = 0;
	virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) = 0;
	virtual Bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) = 0;
	virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) = 0;
	virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) = 0;
	virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) = 0;
	virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) = 0;
	virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) = 0;
	virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) = 0;
	virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) = 0;
	virtual SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) = 0;
	
	virtual Int32 GetLocalFileChangeCount() = 0;
	virtual pCStrA GetLocalFileChange(Int32 iFile, pERemoteStorageLocalFileChange peRemoteStorageLocalFileChange, pERemoteStorageFilePathType peRemoteStorageFilePathType) = 0;
	
	virtual Bool BeginFileWriteBatch() = 0;
	virtual Bool EndFileWriteBatch() = 0;

} ISteamRemoteStorage, *IpSteamRemoteStorage;

#define STEAMREMOTESTORAGE_INTERFACE_VERSION "STEAMREMOTESTORAGE_INTERFACE_VERSION016"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// -----------------------------------------------------------------------------
// Purpose: FileShare Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageFileShareResult_t ((Int32)(k_iSteamRemoteStorageCallbacks + 7))
typedef struct _RemoteStorageFileShareResult_t_ {

	EResult eResult;
	UGCHandle_t hUGC;
	CharA chFilename[k_cchFilenameMax];

} RemoteStorageFileShareResult_t, *pRemoteStorageFileShareResult_t;

// -----------------------------------------------------------------------------
// Purpose: PublishFile Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStoragePublishFileResult_t ((Int32)(k_iSteamRemoteStorageCallbacks + 9))
typedef struct _RemoteStoragePublishFileResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	Bool bUserNeedsToAcceptWorkshopLegalAgreement;

} RemoteStoragePublishFileResult_t, *pRemoteStoragePublishFileResult_t;

// -----------------------------------------------------------------------------
// Purpose: DeletePublishedFile Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageDeletePublishedFileResult_t ((Int32)(k_iSteamRemoteStorageCallbacks + 11))
typedef struct _RemoteStorageDeletePublishedFileResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;

} RemoteStorageDeletePublishedFileResult_t, *pRemoteStorageDeletePublishedFileResult_t;

// -----------------------------------------------------------------------------
// Purpose: EnumerateUserPublishedFiles Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageEnumerateUserPublishedFilesResult_t ((Int32)(k_iSteamRemoteStorageCallbacks + 12))
typedef struct _RemoteStorageEnumerateUserPublishedFilesResult_t_ {

	EResult eResult;
	Int32 nResultsReturned;
	Int32 nTotalResultCount;
	PublishedFileId_t rgPublishedFileId[k_EnumeratePublishedFilesMaxResults];

} RemoteStorageEnumerateUserPublishedFilesResult_t, *pRemoteStorageEnumerateUserPublishedFilesResult_t;

// -----------------------------------------------------------------------------
// Purpose: SubscribePublishedFile Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageSubscribePublishedFileResult_t ((Int32)(k_iSteamRemoteStorageCallbacks + 13))
typedef struct _RemoteStorageSubscribePublishedFileResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;

} RemoteStorageSubscribePublishedFileResult_t, *pRemoteStorageSubscribePublishedFileResult_t;

// -----------------------------------------------------------------------------
// Purpose: EnumerateSubscribePublishedFiles Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageEnumerateUserSubscribedFilesResult_t ((Int32)(k_iSteamRemoteStorageCallbacks + 14))
typedef struct _RemoteStorageEnumerateUserSubscribedFilesResult_t_ {
	
	EResult eResult;
	Int32 nResultsReturned;
	Int32 nTotalResultCount;
	PublishedFileId_t rgPublishedFileId[k_EnumeratePublishedFilesMaxResults];
	Uint32 rgRTimeSubscribed[k_EnumeratePublishedFilesMaxResults];

} RemoteStorageEnumerateUserSubscribedFilesResult_t, *pRemoteStorageEnumerateUserSubscribedFilesResult_t;

// -----------------------------------------------------------------------------
// Purpose: UnsubscribePublishedFile Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageUnsubscribePublishedFileResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 15))
typedef struct _RemoteStorageUnsubscribePublishedFileResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;

} RemoteStorageUnsubscribePublishedFileResult_t, *pRemoteStorageUnsubscribePublishedFileResult_t;

// -----------------------------------------------------------------------------
// Purpose: CommitPublishedFileUpdate Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageUpdatePublishedFileResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 16))
typedef struct _RemoteStorageUpdatePublishedFileResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	Bool bUserNeedsToAcceptWorkshopLegalAgreement;

} RemoteStorageUpdatePublishedFileResult_t, *pRemoteStorageUpdatePublishedFileResult_t;

// -----------------------------------------------------------------------------
// Purpose: UGCDownload Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageDownloadUGCResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 17))
typedef struct _RemoteStorageDownloadUGCResult_t_ {

	EResult eResult;
	UGCHandle_t hUGC;
	AppId_t iAppId;
	Int32 nSizeInBytes;
	CharA chFileName[k_cchFilenameMax]; 
	Uint64 SteamIdOwner;

} RemoteStorageDownloadUGCResult_t, *pRemoteStorageDownloadUGCResult_t;

// -----------------------------------------------------------------------------
// Purpose: GetPublishedFileDetails Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageGetPublishedFileDetailsResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 18))
typedef struct _RemoteStorageGetPublishedFileDetailsResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	AppId_t iCreatorAppId;
	AppId_t iConsumerAppId;
	CharA chTitle[k_cchPublishedDocumentTitleMax];
	CharA chDescription[k_cchPublishedDocumentDescriptionMax];
	UGCHandle_t hUGC;
	UGCHandle_t hPreviewUGC;
	Uint64 SteamIdOwner;
	RTime32 Created;
	RTime32 Updated;
	ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility;
	Bool bBanned;
	CharA chTags[k_cchTagListMax];
	Bool bTagsTruncated;
	CharA pchFileName[k_cchFilenameMax];
	Int32 nFileSize;
	Int32 nPreviewFileSize;
	CharA chURL[k_cchPublishedFileURLMax];
	EWorkshopFileType eWorkshopFileType;
	Bool bAcceptedForUse;

} RemoteStorageGetPublishedFileDetailsResult_t, *pRemoteStorageGetPublishedFileDetailsResult_t;

#define k_iCallbback_RemoteStorageEnumerateWorkshopFilesResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 19))
typedef struct _RemoteStorageEnumerateWorkshopFilesResult_t_ {

	EResult eResult;
	Int32 nResultsReturned;
	Int32 nTotalResultCount;
	PublishedFileId_t rgPublishedFileId[k_EnumeratePublishedFilesMaxResults];
	Float rgScore[k_EnumeratePublishedFilesMaxResults];
	AppId_t nAppId;
	Uint32 iStart;

} RemoteStorageEnumerateWorkshopFilesResult_t, *pRemoteStorageEnumerateWorkshopFilesResult_t;

// -----------------------------------------------------------------------------
// Purpose: GetPublishedItemVoteDetails Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageGetPublishedItemVoteDetailsResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 20))
typedef struct _RemoteStorageGetPublishedItemVoteDetailsResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	Int32 nVotesFor;
	Int32 nVotesAgainst;
	Int32 nReports;
	Float Score;

} RemoteStorageGetPublishedItemVoteDetailsResult_t, *pRemoteStorageGetPublishedItemVoteDetailsResult_t;

// -----------------------------------------------------------------------------
// Purpose: User subscribed to File
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStoragePublishedFileSubscribed_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 21))
typedef struct _RemoteStoragePublishedFileSubscribed_t_ {

	PublishedFileId_t PublishedFileId;
	AppId_t iAppId;

} RemoteStoragePublishedFileSubscribed_t, *pRemoteStoragePublishedFileSubscribed_t;

// -----------------------------------------------------------------------------
// Purpose: User unsubscribed From File
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStoragePublishedFileUnsubscribed_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 22))
typedef struct _RemoteStoragePublishedFileUnsubscribed_t_ {

	PublishedFileId_t PublishedFileId;
	AppId_t iAppId;

} RemoteStoragePublishedFileUnsubscribed_t, *pRemoteStoragePublishedFileUnsubscribed_t;

// -----------------------------------------------------------------------------
// Purpose: Published file that user owns was deleted
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStoragePublishedFileDeleted_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 23))
typedef struct _RemoteStoragePublishedFileDeleted_t_ {

	PublishedFileId_t PublishedFileId;
	AppId_t iAppId;

} RemoteStoragePublishedFileDeleted_t, *pRemoteStoragePublishedFileDeleted_t;

// -----------------------------------------------------------------------------
// Purpose:UpdateUserPublishedItemVote Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageUpdateUserPublishedItemVoteResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 24))
typedef struct _RemoteStorageUpdateUserPublishedItemVoteResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;

} RemoteStorageUpdateUserPublishedItemVoteResult_t, *pRemoteStorageUpdateUserPublishedItemVoteResult_t;

// -----------------------------------------------------------------------------
// Purpose:GetUserPublishedItemVoteDetails Call Result
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageUserVoteDetails_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 25))
typedef struct _RemoteStorageUserVoteDetails_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	EWorkshopVote eWorkshopVote;

} RemoteStorageUserVoteDetails_t, *pRemoteStorageUserVoteDetails_t;

#define k_iCallbback_RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 26))
typedef struct _RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_ {

	EResult eResult;
	Int32 nResultsReturned;
	Int32 nTotalResultCount;
	PublishedFileId_t rgPublishedFileId[k_EnumeratePublishedFilesMaxResults];

} RemoteStorageEnumerateUserSharedWorkshopFilesResult_t, *pRemoteStorageEnumerateUserSharedWorkshopFilesResult_t;

#define k_iCallbback_RemoteStorageSetUserPublishedFileActionResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 27))
typedef struct _RemoteStorageSetUserPublishedFileActionResult_t_ {

	EResult eResult;
	PublishedFileId_t PublishedFileId;
	EWorkshopFileAction eWorkshopFileAction;

} RemoteStorageSetUserPublishedFileActionResult_t, *pRemoteStorageSetUserPublishedFileActionResult_t;

#define k_iCallbback_RemoteStorageEnumeratePublishedFilesByUserActionResult_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 28))
typedef struct _RemoteStorageEnumeratePublishedFilesByUserActionResult_t_ {

	EResult eResult;
	EWorkshopFileAction eAction;
	Int32 nResultsReturned;
	Int32 nTotalResultCount;
	PublishedFileId_t rgPublishedFileId[k_EnumeratePublishedFilesMaxResults];
	RTime32 rgUpdated[k_EnumeratePublishedFilesMaxResults];

} RemoteStorageEnumeratePublishedFilesByUserActionResult_t, *pRemoteStorageEnumeratePublishedFilesByUserActionResult_t;

// -----------------------------------------------------------------------------
// Purpose: Called periodically while PublishWorkshopFile
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStoragePublishFileProgress_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 29))
typedef struct _RemoteStoragePublishFileProgress_t_ {

	Double PercentFile;
	Bool bPreview;

} RemoteStoragePublishFileProgress_t, *pRemoteStoragePublishFileProgress_t;

// -----------------------------------------------------------------------------
// Purpose: Called when the content published File is updated
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStoragePublishedFileUpdated_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 30))
typedef struct _RemoteStoragePublishedFileUpdated_t_ {

	PublishedFileId_t PublishedFileId;
	AppId_t iAppId;
	Uint64 Unused;

} RemoteStoragePublishedFileUpdated_t, *pRemoteStoragePublishedFileUpdated_t;

// -----------------------------------------------------------------------------
// Purpose: Called when FileWriteAsync completes
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageFileWriteAsyncComplete_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 31))
typedef struct _RemoteStorageFileWriteAsyncComplete_t_ {

	EResult	eResult;

} RemoteStorageFileWriteAsyncComplete_t, *pRemoteStorageFileWriteAsyncComplete_t;

// -----------------------------------------------------------------------------
// Purpose: Called when a FileReadAsync completes
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageFileReadAsyncComplete_t_ ((Int32)(k_iSteamRemoteStorageCallbacks + 32))
typedef struct _RemoteStorageFileReadAsyncComplete_t_ {

	SteamAPICall_t hFileReadAsync;
	EResult	eResult;
	Uint32 nOffset;
	Uint32 cbRead;

} RemoteStorageFileReadAsyncComplete_t, *pRemoteStorageFileReadAsyncComplete_t;

// -----------------------------------------------------------------------------
// Purpose: one or more files for this app have changed locally after syncing
//  to remote session changes
// -----------------------------------------------------------------------------
#define k_iCallbback_RemoteStorageLocalFileChange_t ((Int32)(k_iSteamRemoteStorageCallbacks + 33))
typedef struct _RemoteStorageLocalFileChange_t_ {
	
	Int32 Unused;

} RemoteStorageLocalFileChange_t, *pRemoteStorageLocalFileChange_t;

#pragma pack(pop)

#endif // _ISTEAMREMOTESTORAGE_
