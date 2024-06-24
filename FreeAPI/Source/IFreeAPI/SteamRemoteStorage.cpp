// -----------------------------------------------------------------------------
#include "SteamRemoteStorage.h"
// -----------------------------------------------------------------------------

_SteamRemoteStorage_::_SteamRemoteStorage_() {

	const SizeOF UGCHandleCount =
		sizeof(this->UGCHandle) / sizeof(UGCFileWriteStreamHandle_Value);
	for (SizeOF i = 0; i < UGCHandleCount; i++) {
		this->UGCHandle[i].hFile = INVALID_HANDLE_VALUE;
	}

}

Bool _SteamRemoteStorage_::FileWrite(pCStrA pchFile, pCVoid pvData, Int32 cbData) {
	DEBUGBREAK("ISteamRemoteStorage::FileWrite");

	Bool bSuccess = False;

	if (pchFile != NULL && pvData != NULL && cbData > 0) {

		DEBUG_OUT(pchFile);

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

			SizeOF cchGameSaveFileName = StrA_Count(pchGameSaveFileName);
			for (SizeOF i = 0; i < cchGameSaveFileName; i++) {
				if (pchGameSaveFileName[i] == '/') {
					pchGameSaveFileName[i] = '\\';
				}
			}

			HANDLE hFile = FSCreateFileA(
				pchGameSaveFileName, GENERIC_WRITE,
				CREATE_ALWAYS
			);

			if (hFile != INVALID_HANDLE_VALUE) {

				Dword dwWriteAmount = 0U;
				Bool bWriteSuccess = WriteFile(
					hFile, pvData, cbData,
					(LPDWORD)(&dwWriteAmount), NULL
				);

				if (bWriteSuccess == True && dwWriteAmount == cbData) {
					bSuccess = True;
				}

				CloseHandle(hFile);

				if (bSuccess == False) {
					DeleteFileA(pchGameSaveFileName);
				}

			}

			LocalFree(pchGameSaveFileName);

		}

	}

	return bSuccess;

}

Int32 _SteamRemoteStorage_::FileRead(pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) {
	DEBUGBREAK("ISteamRemoteStorage::FileRead");

	Bool bSuccess = False;

	if (pchFile != NULL && pvData != NULL && cbDataToRead > 0) {

		DEBUG_OUT(pchFile);

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

			SizeOF cchGameSaveFileName = StrA_Count(pchGameSaveFileName);
			for (SizeOF i = 0; i < cchGameSaveFileName; i++) {
				if (pchGameSaveFileName[i] == '/') {
					pchGameSaveFileName[i] = '\\';
				}
			}

			HANDLE hFile = FSCreateFileA(
				pchGameSaveFileName, GENERIC_READ,
				OPEN_EXISTING
			);

			if (hFile != INVALID_HANDLE_VALUE) {

				Dword dwReadAmount = 0U;
				Bool bWriteSuccess = ReadFile(
					hFile, pvData, cbDataToRead,
					(LPDWORD)(&dwReadAmount), NULL
				);

				if (bWriteSuccess == True && dwReadAmount == cbDataToRead) {
					bSuccess = True;
				}

				CloseHandle(hFile);

			}

			LocalFree(pchGameSaveFileName);

		}

	}

	return bSuccess;

}

SteamAPICall_t _SteamRemoteStorage_::FileWriteAsync(pCStrA pchFile, pCVoid pvData, Uint32 cbData) {
	DEBUGBREAK("ISteamRemoteStorage::FileWriteAsync");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::FileReadAsync(pCStrA pchFile, Uint32 nOffset, Uint32 cbToRead) {
	DEBUGBREAK("ISteamRemoteStorage::FileReadAsync");

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::FileReadAsyncComplete(SteamAPICall_t hReadCall, pVoid pvData, Uint32 cbToRead) {
	DEBUGBREAK("ISteamRemoteStorage::FileReadAsyncComplete");

	return False;

}

Bool _SteamRemoteStorage_::FileForget(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FileForget");

	return True;

}

Bool _SteamRemoteStorage_::FileDelete(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FileDelete");

	Bool bSuccess = False;

	if (pchFile != NULL) {

		DEBUG_OUT(pchFile);

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

			SizeOF cchGameSaveFileName = StrA_Count(pchGameSaveFileName);
			for (SizeOF i = 0; i < cchGameSaveFileName; i++) {
				if (pchGameSaveFileName[i] == '/') {
					pchGameSaveFileName[i] = '\\';
				}
			}

			if (FileExistsA(pchGameSaveFileName)) {
				DeleteFileA(pchGameSaveFileName);
				bSuccess = True;
			}

			LocalFree(pchGameSaveFileName);

		}

	}

	return bSuccess;

}

SteamAPICall_t _SteamRemoteStorage_::FileShare(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FileShare");

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) {
	DEBUGBREAK("ISteamRemoteStorage::SetSyncPlatforms");

	return True;

}

UGCFileWriteStreamHandle_t _SteamRemoteStorage_::FileWriteStreamOpen(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FileWriteStreamOpen");

	UGCFileWriteStreamHandle_t UGCFileWriteStreamHandle = k_UGCFileStreamHandle_Invalid;

	if (pchFile != NULL) {

		DEBUG_OUT(pchFile);

		const SizeOF UGCHandleCount =
			sizeof(this->UGCHandle) / sizeof(UGCFileWriteStreamHandle_Value);
		for (SizeOF i = 0; i < UGCHandleCount; i++) {
			if (this->UGCHandle[i].hFile == INVALID_HANDLE_VALUE) {

				pStrA pchGameSaveFileName = GetGameSaveFileNameA(
					GetModuleHandleA(NULL), pchFile,
					k_ESaveType_Storage
				);

				if (pchGameSaveFileName != NULL) {

					SizeOF cchGameSaveFileName = StrA_Count(pchGameSaveFileName);
					for (SizeOF i = 0; i < cchGameSaveFileName; i++) {
						if (pchGameSaveFileName[i] == '/') {
							pchGameSaveFileName[i] = '\\';
						}
					}

					HANDLE hFile = FSCreateFileA(
						pchGameSaveFileName, GENERIC_WRITE,
						CREATE_ALWAYS
					);

					if (hFile != INVALID_HANDLE_VALUE) {
						this->UGCHandle[i].hFile = hFile;
						UGCFileWriteStreamHandle = (UGCFileWriteStreamHandle_t)(i) + 1U;
					}

					LocalFree(pchGameSaveFileName);

				}

				break;

			}
		}

	}

	return UGCFileWriteStreamHandle;

}

Bool _SteamRemoteStorage_::FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) {
	DEBUGBREAK("ISteamRemoteStorage::FileWriteStreamWriteChunk");

	Bool bSuccess = False;

	if (pvData != NULL && cbData > 0) {
		const SizeOF UGCHandleCount =
			sizeof(this->UGCHandle) / sizeof(UGCFileWriteStreamHandle_Value);
		if (hWriteStream - 1U < UGCHandleCount) {
			if (this->UGCHandle[hWriteStream - 1U].hFile != INVALID_HANDLE_VALUE) {

				LARGE_INTEGER liFilePosition = { 0 };
				SetFilePointerEx(
					this->UGCHandle[hWriteStream - 1U].hFile,
					LARGE_INTEGER{ 0, 0 }, &liFilePosition,
					FILE_CURRENT
				);

				Dword dwWriteAmount = 0U;
				Bool bWriteSuccess = WriteFile(
					this->UGCHandle[hWriteStream - 1U].hFile, pvData, cbData,
					(LPDWORD)(&dwWriteAmount), NULL
				);

				if (bWriteSuccess == True && dwWriteAmount == cbData) {
					bSuccess = True;
				}

				if (bSuccess == False) {

					SetFilePointerEx(
						this->UGCHandle[hWriteStream - 1U].hFile,
						liFilePosition, NULL,
						FILE_BEGIN
					);

					SetEndOfFile(
						this->UGCHandle[hWriteStream - 1U].hFile
					);

				}

			}
		}
	}

	return bSuccess;

}

Bool _SteamRemoteStorage_::FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) {
	DEBUGBREAK("ISteamRemoteStorage::FileWriteStreamClose");

	Bool bSuccess = False;

	const SizeOF UGCHandleCount =
		sizeof(this->UGCHandle) / sizeof(UGCFileWriteStreamHandle_Value);
	if (hWriteStream - 1U < UGCHandleCount) {
		if (this->UGCHandle[hWriteStream - 1U].hFile != INVALID_HANDLE_VALUE) {
			CloseHandle(this->UGCHandle[hWriteStream - 1U].hFile);
			this->UGCHandle[hWriteStream - 1U].hFile = INVALID_HANDLE_VALUE;
			bSuccess = True;
		}
	}

	return bSuccess;

}

Bool _SteamRemoteStorage_::FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) {
	DEBUGBREAK("ISteamRemoteStorage::FileWriteStreamCancel");

	return this->FileWriteStreamClose(hWriteStream);

}

Bool _SteamRemoteStorage_::FileExists_(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FileExists_");

	Bool bSuccess = False;

	if (pchFile != NULL) {

		DEBUG_OUT(pchFile);

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

			SizeOF cchGameSaveFileName = StrA_Count(pchGameSaveFileName);
			for (SizeOF i = 0; i < cchGameSaveFileName; i++) {
				if (pchGameSaveFileName[i] == '/') {
					pchGameSaveFileName[i] = '\\';
				}
			}

			bSuccess = FileExistsA(pchGameSaveFileName);
			LocalFree(pchGameSaveFileName);

		}

	}

	return bSuccess;

}

Bool _SteamRemoteStorage_::FilePersisted(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FilePersisted");

	return True;

}

Int32 _SteamRemoteStorage_::GetFileSize(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::GetFileSize");

	Int32 cbFileSize = 0;

	if (pchFile != NULL) {

		DEBUG_OUT(pchFile);

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

			SizeOF cchGameSaveFileName = StrA_Count(pchGameSaveFileName);
			for (SizeOF i = 0; i < cchGameSaveFileName; i++) {
				if (pchGameSaveFileName[i] == '/') {
					pchGameSaveFileName[i] = '\\';
				}
			}

			HANDLE hFile = FSCreateFileA(
				pchGameSaveFileName, 0U,
				OPEN_EXISTING
			);

			if (hFile != INVALID_HANDLE_VALUE) {

				BY_HANDLE_FILE_INFORMATION bhfi = { 0 };

				GetFileInformationByHandle(
					hFile, &bhfi
				);

				Int64 cbFileSizeLarge = 0;
				((pInt32)(&cbFileSizeLarge))[0] = bhfi.nFileSizeLow;
				((pInt32)(&cbFileSizeLarge))[1] = bhfi.nFileSizeHigh;
				
				cbFileSize = (cbFileSizeLarge > (Int64)(Int32_MAX)) ? Int32_MAX : (Int32)(cbFileSizeLarge);

				CloseHandle(hFile);

			}

			LocalFree(pchGameSaveFileName);

		}

	}

	return cbFileSize;

}

Int64 _SteamRemoteStorage_::GetFileTimestamp(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::GetFileTimestamp");

	Int64 cbFileTimeStamp = 0LL;

	if (pchFile != NULL) {

		DEBUG_OUT(pchFile);

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

			SizeOF cchGameSaveFileName = StrA_Count(pchGameSaveFileName);
			for (SizeOF i = 0; i < cchGameSaveFileName; i++) {
				if (pchGameSaveFileName[i] == '/') {
					pchGameSaveFileName[i] = '\\';
				}
			}

			HANDLE hFile = FSCreateFileA(
				pchGameSaveFileName, 0U,
				OPEN_EXISTING
			);

			if (hFile != INVALID_HANDLE_VALUE) {

				BY_HANDLE_FILE_INFORMATION bhfi = { 0 };

				GetFileInformationByHandle(
					hFile, &bhfi
				);

				((pInt32)(&cbFileTimeStamp))[0] = bhfi.ftCreationTime.dwLowDateTime;
				((pInt32)(&cbFileTimeStamp))[1] = bhfi.ftCreationTime.dwHighDateTime;

				CloseHandle(hFile);

			}

			LocalFree(pchGameSaveFileName);

		}

	}

	return cbFileTimeStamp;

}

ERemoteStoragePlatform _SteamRemoteStorage_::GetSyncPlatforms(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::GetSyncPlatforms");

	return k_ERemoteStoragePlatformWindows;

}

Int32 _SteamRemoteStorage_::GetFileCount() {
	DEBUGBREAK("ISteamRemoteStorage::GetFileCount");

	return 0;

}

pCStrA _SteamRemoteStorage_::GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) {
	DEBUGBREAK("ISteamRemoteStorage::GetFileNameAndSize");

	return (pCStrA)(
		""
	);

}

Bool _SteamRemoteStorage_::GetQuota(pUint32 pnTotalBytes, pUint32 pnAvailableBytes) {
	DEBUGBREAK("ISteamRemoteStorage::GetQuota");

	if (pnTotalBytes != NULL) {
		*pnTotalBytes = 0;
	}

	if (pnAvailableBytes != NULL) {
		*pnAvailableBytes = Uint32_MAX;
	}

	return True;

}

Bool _SteamRemoteStorage_::GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) {
	DEBUGBREAK("ISteamRemoteStorage::GetQuota");

	if (pnTotalBytes != NULL) {
		*pnTotalBytes = 0;
	}

	if (pnAvailableBytes != NULL) {
		*pnAvailableBytes = Uint64_MAX;
	}

	return True;

}

Bool _SteamRemoteStorage_::IsCloudEnabledForAccount() {
	DEBUGBREAK("ISteamRemoteStorage::IsCloudEnabledForAccount");

	return True;

}

Bool _SteamRemoteStorage_::IsCloudEnabledForApp() {
	DEBUGBREAK("ISteamRemoteStorage::IsCloudEnabledForApp");

	return True;

}

void _SteamRemoteStorage_::SetCloudEnabledForApp(Bool bEnabled) {
	DEBUGBREAK("ISteamRemoteStorage::SetCloudEnabledForApp");

	/* Empty Method */

}

SteamAPICall_t _SteamRemoteStorage_::UGCDownload(UGCHandle_t hUGC) {
	DEBUGBREAK("ISteamRemoteStorage::UGCDownload");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) {
	DEBUGBREAK("ISteamRemoteStorage::UGCDownload");

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) {
	DEBUGBREAK("ISteamRemoteStorage::GetUGCDownloadProgress");

	return False;

}

Bool _SteamRemoteStorage_::GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA* ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) {
	DEBUGBREAK("ISteamRemoteStorage::GetUGCDetails");

	return False;

}

Int32 _SteamRemoteStorage_::UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead) {
	DEBUGBREAK("ISteamRemoteStorage::UGCRead");

	return 0;

}

Int32 _SteamRemoteStorage_::UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset) {
	DEBUGBREAK("ISteamRemoteStorage::UGCRead");
	
	return 0;

}

Int32 _SteamRemoteStorage_::UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) {
	DEBUGBREAK("ISteamRemoteStorage::UGCRead");

	return 0;

}

Int32 _SteamRemoteStorage_::GetCachedUGCCount() {
	DEBUGBREAK("ISteamRemoteStorage::GetCachedUGCCount");

	return 0;

}

UGCHandle_t _SteamRemoteStorage_::GetCachedUGCHandle(Int32 iCachedContent) {
	DEBUGBREAK("ISteamRemoteStorage::GetCachedUGCHandle");

	return k_UGCHandle_Invalid;

}

#if defined(_PS3) || defined(_SERVER)
void _SteamRemoteStorage_::GetFileListFromServer() {
	DEBUGBREAK("ISteamRemoteStorage::GetFileListFromServer");

	/* Empty Method */

}

Bool _SteamRemoteStorage_::FileFetch(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FileFetch");

	return True;

}

Bool _SteamRemoteStorage_::FilePersist(pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::FilePersist");

	return True;

}

Bool _SteamRemoteStorage_::SynchronizeToClient() {
	DEBUGBREAK("ISteamRemoteStorage::SynchronizeToClient");

	return True;

}

Bool _SteamRemoteStorage_::SynchronizeToServer() {
	DEBUGBREAK("ISteamRemoteStorage::SynchronizeToServer");

	return True;

}

Bool _SteamRemoteStorage_::ResetFileRequestState() {
	DEBUGBREAK("ISteamRemoteStorage::ResetFileRequestState");

	return True;

}
#endif

SteamAPICall_t _SteamRemoteStorage_::PublishFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) {
	DEBUGBREAK("ISteamRemoteStorage::PublishFile");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) {
	DEBUGBREAK("ISteamRemoteStorage::PublishWorkshopFile");

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::UpdatePublishedFile(RemoteStorageUpdatePublishedFileRequest_t UpdatePublishedFileRequest) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFile");
	
	return False;

}

PublishedFileUpdateHandle_t _SteamRemoteStorage_::CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamRemoteStorage::CreatePublishedFileUpdateRequest");

	return k_PublishedFileUpdateHandle_Invalid;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFileFile");

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFilePreviewFile");

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFileTitle");

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFileDescription");

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFileVisibility");

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFileTags");

	return False;

}

SteamAPICall_t _SteamRemoteStorage_::CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) {
	DEBUGBREAK("ISteamRemoteStorage::CommitPublishedFileUpdate");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::GetPublishedFileDetails(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamRemoteStorage::GetPublishedFileDetails");

	return k_SteamAPICall_Invalid;

}
SteamAPICall_t _SteamRemoteStorage_::GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) {
	DEBUGBREAK("ISteamRemoteStorage::GetPublishedFileDetails");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::DeletePublishedFile(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamRemoteStorage::DeletePublishedFile");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumerateUserPublishedFiles(Uint32 iStart) {
	DEBUGBREAK("ISteamRemoteStorage::EnumerateUserPublishedFiles");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::SubscribePublishedFile(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamRemoteStorage::SubscribePublishedFile");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumerateUserSubscribedFiles(Uint32 iStart) {
	DEBUGBREAK("ISteamRemoteStorage::EnumerateUserSubscribedFiles");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamRemoteStorage::UnsubscribePublishedFile");

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) {
	DEBUGBREAK("ISteamRemoteStorage::UpdatePublishedFileSetChangeDescription");

	return False;

}

SteamAPICall_t _SteamRemoteStorage_::GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamRemoteStorage::GetPublishedItemVoteDetails");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) {
	DEBUGBREAK("ISteamRemoteStorage::UpdateUserPublishedItemVote");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("ISteamRemoteStorage::GetUserPublishedItemVoteDetails");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) {
	DEBUGBREAK("ISteamRemoteStorage::EnumerateUserSharedWorkshopFiles");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) {
	DEBUGBREAK("ISteamRemoteStorage::PublishVideo");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) {
	DEBUGBREAK("ISteamRemoteStorage::SetUserPublishedFileAction");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) {
	DEBUGBREAK("ISteamRemoteStorage::EnumeratePublishedFilesByUserAction");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) {
	DEBUGBREAK("ISteamRemoteStorage::EnumeratePublishedWorkshopFiles");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) {
	DEBUGBREAK("ISteamRemoteStorage::UGCDownloadToLocation");

	return k_SteamAPICall_Invalid;

}

Int32 _SteamRemoteStorage_::GetLocalFileChangeCount() {
	DEBUGBREAK("ISteamRemoteStorage::GetLocalFileChangeCount");

	return 0;

}

pCStrA _SteamRemoteStorage_::GetLocalFileChange(Int32 iFile, pERemoteStorageLocalFileChange peRemoteStorageLocalFileChange, pERemoteStorageFilePathType peRemoteStorageFilePathType) {
	DEBUGBREAK("ISteamRemoteStorage::GetLocalFileChange");

	return (pCStrA)(
		""
	);

}

Bool _SteamRemoteStorage_::BeginFileWriteBatch() {
	DEBUGBREAK("ISteamRemoteStorage::BeginFileWriteBatch");

	return False;

}

Bool _SteamRemoteStorage_::EndFileWriteBatch() {
	DEBUGBREAK("ISteamRemoteStorage::EndFileWriteBatch");

	return False;

}

_SteamRemoteStorage_::~_SteamRemoteStorage_() {

	const SizeOF UGCHandleCount =
		sizeof(this->UGCHandle) / sizeof(UGCFileWriteStreamHandle_Value);
	for (SizeOF i = 0; i < UGCHandleCount; i++) {
		if (this->UGCHandle[i].hFile != INVALID_HANDLE_VALUE) {
			CloseHandle(this->UGCHandle[i].hFile);
			this->UGCHandle[i].hFile = INVALID_HANDLE_VALUE;
		}
	}

}
