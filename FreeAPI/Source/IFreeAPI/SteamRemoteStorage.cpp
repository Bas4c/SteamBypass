// -----------------------------------------------------------------------------
#include "SteamRemoteStorage.h"
// -----------------------------------------------------------------------------

_SteamRemoteStorage_::_SteamRemoteStorage_() {

	const SizeOF UGCHandleCount =
		sizeof(this->UGCHandles) / sizeof(UGCFileWriteStreamHandle_Value);
	for (SizeOF i = 0; i < UGCHandleCount; i++) {
		this->UGCHandles[i].hFile = INVALID_HANDLE_VALUE;
	}

}

Bool _SteamRemoteStorage_::FileWrite(pCStrA pchFile, const pVoid pvData, Int32 cbData) {

	Bool bSuccess = False;

	if (pchFile != NULL && pvData != NULL && cbData > 0) {

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

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

	Bool bSuccess = False;

	if (pchFile != NULL && pvData != NULL && cbDataToRead > 0) {

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

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

SteamAPICall_t _SteamRemoteStorage_::FileWriteAsync(pCStrA pchFile, const pVoid pvData, Uint32 cbData) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::FileReadAsync(pCStrA pchFile, Uint32 nOffset, Uint32 cbToRead) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::FileReadAsyncComplete(SteamAPICall_t hReadCall, pVoid pvData, Uint32 cbToRead) {

	return False;

}

Bool _SteamRemoteStorage_::FileForget(pCStrA pchFile) {

	return True;

}

Bool _SteamRemoteStorage_::FileDelete(pCStrA pchFile) {

	Bool bSuccess = False;

	if (pchFile != NULL) {

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

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

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::SetSyncPlatforms(pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) {

	return True;

}

UGCFileWriteStreamHandle_t _SteamRemoteStorage_::FileWriteStreamOpen(pCStrA pchFile) {

	UGCFileWriteStreamHandle_t UGCFileWriteStreamHandle = k_UGCFileStreamHandle_Invalid;

	if (pchFile != NULL) {

		const SizeOF UGCHandleCount =
			sizeof(this->UGCHandles) / sizeof(UGCFileWriteStreamHandle_Value);
		for (SizeOF i = 0; i < UGCHandleCount; i++) {
			if (this->UGCHandles[i].hFile == INVALID_HANDLE_VALUE) {

				pStrA pchGameSaveFileName = GetGameSaveFileNameA(
					GetModuleHandleA(NULL), pchFile,
					k_ESaveType_Storage
				);

				if (pchGameSaveFileName != NULL) {

					HANDLE hFile = FSCreateFileA(
						pchGameSaveFileName, GENERIC_WRITE,
						CREATE_ALWAYS
					);

					if (hFile != INVALID_HANDLE_VALUE) {
						this->UGCHandles[i].hFile = hFile;
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

Bool _SteamRemoteStorage_::FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t hWriteStream, const pVoid pvData, Int32 cbData) {

	Bool bSuccess = False;

	if (pvData != NULL && cbData > 0) {
		const SizeOF UGCHandleCount =
			sizeof(this->UGCHandles) / sizeof(UGCFileWriteStreamHandle_Value);
		if (hWriteStream - 1U < UGCHandleCount) {
			if (this->UGCHandles[hWriteStream - 1U].hFile != INVALID_HANDLE_VALUE) {

				LARGE_INTEGER liFilePosition = { 0 };
				SetFilePointerEx(
					this->UGCHandles[hWriteStream - 1U].hFile,
					LARGE_INTEGER{ 0, 0 }, &liFilePosition,
					FILE_CURRENT
				);

				Dword dwWriteAmount = 0U;
				Bool bWriteSuccess = WriteFile(
					this->UGCHandles[hWriteStream - 1U].hFile, pvData, cbData,
					(LPDWORD)(&dwWriteAmount), NULL
				);

				if (bWriteSuccess == True && dwWriteAmount == cbData) {
					bSuccess = True;
				}

				if (bSuccess == False) {

					SetFilePointerEx(
						this->UGCHandles[hWriteStream - 1U].hFile,
						liFilePosition, NULL,
						FILE_BEGIN
					);

					SetEndOfFile(
						this->UGCHandles[hWriteStream - 1U].hFile
					);

				}

			}
		}
	}

	return bSuccess;

}

Bool _SteamRemoteStorage_::FileWriteStreamClose(UGCFileWriteStreamHandle_t hWriteStream) {

	Bool bSuccess = False;

	const SizeOF UGCHandleCount =
		sizeof(this->UGCHandles) / sizeof(UGCFileWriteStreamHandle_Value);
	if (hWriteStream - 1U < UGCHandleCount) {
		if (this->UGCHandles[hWriteStream - 1U].hFile != INVALID_HANDLE_VALUE) {
			CloseHandle(this->UGCHandles[hWriteStream - 1U].hFile);
			this->UGCHandles[hWriteStream - 1U].hFile = INVALID_HANDLE_VALUE;
			bSuccess = True;
		}
	}

	return bSuccess;

}

Bool _SteamRemoteStorage_::FileWriteStreamCancel(UGCFileWriteStreamHandle_t hWriteStream) {

	return this->FileWriteStreamClose(hWriteStream);

}

Bool _SteamRemoteStorage_::FileExists_(pCStrA pchFile) {

	Bool bSuccess = False;

	if (pchFile != NULL) {

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

			bSuccess = FileExistsA(pchGameSaveFileName);
			LocalFree(pchGameSaveFileName);

		}

	}

	return bSuccess;

}

Bool _SteamRemoteStorage_::FilePersisted(pCStrA pchFile) {

	return True;

}

Int32 _SteamRemoteStorage_::GetFileSize(pCStrA pchFile) {

	Int32 cbFileSize = 0;

	if (pchFile != NULL) {

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

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

	Int64 cbFileTimeStamp = 0LL;

	if (pchFile != NULL) {

		pStrA pchGameSaveFileName = GetGameSaveFileNameA(
			GetModuleHandleA(NULL), pchFile,
			k_ESaveType_Storage
		);

		if (pchGameSaveFileName != NULL) {

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

	return k_ERemoteStoragePlatformWindows;

}

Int32 _SteamRemoteStorage_::GetFileCount() {

	return 0;

}

pCStrA _SteamRemoteStorage_::GetFileNameAndSize(Int32 iFile, pInt32 pnFileSizeInBytes) {

	return (pCStrA)(
		""
	);

}

Bool _SteamRemoteStorage_::GetQuota(pUint64 pnTotalBytes, pUint64 pnAvailableBytes) {

	if (pnTotalBytes != NULL) {
		*pnTotalBytes = 0;
	}

	if (pnAvailableBytes != NULL) {
		*pnAvailableBytes = Uint64_MAX;
	}

	return True;

}

Bool _SteamRemoteStorage_::IsCloudEnabledForAccount() {

	return True;

}

Bool _SteamRemoteStorage_::IsCloudEnabledForApp() {

	return True;

}

void _SteamRemoteStorage_::SetCloudEnabledForApp(Bool bEnabled) {

	/* Empty Method */

}

SteamAPICall_t _SteamRemoteStorage_::UGCDownload(UGCHandle_t hUGC, Uint32 nPriority) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::GetUGCDownloadProgress(UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) {

	return False;

}

Bool _SteamRemoteStorage_::GetUGCDetails(UGCHandle_t hUGC, pAppId_t piAppId, pStrA* ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) {

	return False;

}

Int32 _SteamRemoteStorage_::UGCRead(UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) {

	return 0;

}

Int32 _SteamRemoteStorage_::GetCachedUGCCount() {

	return 0;

}

UGCHandle_t _SteamRemoteStorage_::GetCachedUGCHandle(Int32 iCachedContent) {

	return k_UGCHandle_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::PublishWorkshopFile(pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags, EWorkshopFileType eWorkshopFileType) {

	return k_SteamAPICall_Invalid;

}

PublishedFileUpdateHandle_t _SteamRemoteStorage_::CreatePublishedFileUpdateRequest(PublishedFileId_t PublishedFileId) {

	return k_PublishedFileUpdateHandle_Invalid;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) {

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) {

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileTitle(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) {

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) {

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) {

	return False;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileTags(PublishedFileUpdateHandle_t hPublishedFileUpdate, pSteamParamStringArray_t pTags) {

	return False;

}

SteamAPICall_t _SteamRemoteStorage_::CommitPublishedFileUpdate(PublishedFileUpdateHandle_t hPublishedFileUpdate) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::GetPublishedFileDetails(PublishedFileId_t PublishedFileId, Uint32 nSeconds) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::DeletePublishedFile(PublishedFileId_t PublishedFileId) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumerateUserPublishedFiles(Uint32 iStart) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::SubscribePublishedFile(PublishedFileId_t PublishedFileId) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumerateUserSubscribedFiles(Uint32 iStart) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::UnsubscribePublishedFile(PublishedFileId_t PublishedFileId) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamRemoteStorage_::UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) {

	return False;

}

SteamAPICall_t _SteamRemoteStorage_::GetPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::UpdateUserPublishedItemVote(PublishedFileId_t PublishedFileId, Bool bVoteUp) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::GetUserPublishedItemVoteDetails(PublishedFileId_t PublishedFileId) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumerateUserSharedWorkshopFiles(SteamId_t SteamId, Uint32 iStart, pSteamParamStringArray_t pRequiredTags, pSteamParamStringArray_t pExcludedTags) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::PublishVideo(EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::SetUserPublishedFileAction(PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumeratePublishedFilesByUserAction(EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, pSteamParamStringArray_t pTags, pSteamParamStringArray_t pUserTags) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamRemoteStorage_::UGCDownloadToLocation(UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) {

	return k_SteamAPICall_Invalid;

}

Int32 _SteamRemoteStorage_::GetLocalFileChangeCount() {

	return 0;

}

pCStrA _SteamRemoteStorage_::GetLocalFileChange(Int32 iFile, pERemoteStorageLocalFileChange peRemoteStorageLocalFileChange, pERemoteStorageFilePathType peRemoteStorageFilePathType) {

	return (pCStrA)(
		""
	);

}

Bool _SteamRemoteStorage_::BeginFileWriteBatch() {

	return False;

}

Bool _SteamRemoteStorage_::EndFileWriteBatch() {

	return False;

}

_SteamRemoteStorage_::~_SteamRemoteStorage_() {

	const SizeOF UGCHandleCount =
		sizeof(this->UGCHandles) / sizeof(UGCFileWriteStreamHandle_Value);
	for (SizeOF i = 0; i < UGCHandleCount; i++) {
		if (this->UGCHandles[i].hFile != INVALID_HANDLE_VALUE) {
			CloseHandle(this->UGCHandles[i].hFile);
			this->UGCHandles[i].hFile = INVALID_HANDLE_VALUE;
		}
	}

}
