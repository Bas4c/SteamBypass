// -----------------------------------------------------------------------------
#include "CommonX.h"
// -----------------------------------------------------------------------------

_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall WideCharToMultiByteAlloc(
	_In_z_ pCStrW pchWideStr
) {

	Dword sCode = ERROR_INVALID_PARAMETER;
	if (pchWideStr != NULL) {

		Int32 cchStr = WideCharToMultiByte(
			CP_UTF8, WC_COMPOSITECHECK, (LPCWSTR)(pchWideStr), -1,
			NULL, 0, NULL, NULL
		);

		sCode = GetLastError();
		if (cchStr != 0) {

			pStrA pchStr = (pStrA)(LocalAlloc(
				LPTR, cchStr
			));

			sCode = ERROR_NOT_ENOUGH_MEMORY;
			if (pchStr != NULL) {

				WideCharToMultiByte(
					CP_UTF8, WC_COMPOSITECHECK, (LPCWSTR)(pchWideStr), -1,
					pchStr, cchStr, NULL, NULL
				);

				SetLastError(ERROR_SUCCESS);
				return pchStr;

			}

		}

	}

	SetLastError(sCode);
	return NULL;

}

_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall MultiByteToWideCharAlloc(
	_In_z_ pCStrA pchStr
) {

	Dword sCode = ERROR_INVALID_PARAMETER;
	if (pchStr != NULL) {

		Int32 cchWideStr = MultiByteToWideChar(
			CP_UTF8, MB_PRECOMPOSED, (LPCSTR)(pchStr), -1,
			NULL, 0
		);

		sCode = GetLastError();
		if (cchWideStr != 0) {

			pStrW pchWideStr = (pStrW)(LocalAlloc(
				LPTR, cchWideStr * sizeof(CharW)
			));

			sCode = ERROR_NOT_ENOUGH_MEMORY;
			if (pchWideStr != NULL) {

				MultiByteToWideChar(
					CP_UTF8, MB_PRECOMPOSED, (LPCSTR)(pchStr), -1,
					pchWideStr, cchWideStr
				);

				SetLastError(ERROR_SUCCESS);
				return pchWideStr;

			}

		}

	}

	SetLastError(sCode);
	return NULL;

}

_COMMON_X_API_ void __stdcall ByteSwap(
	_Inout_bytecount_(cbData) pVoid pvData,
	_In_ SizeOF cbData
) {

	if (pvData != NULL && cbData != 0) {

		for (SizeOF i = 0; i < cbData; i++) {

			/* Bytes already Swapped */
			if (i >= cbData / 2U) {
				break;
			}

			Byte x = ((pByte)(pvData))[i];
			((pByte)(pvData))[i] = ((pByte)(pvData))[cbData - 1 - i];
			((pByte)(pvData))[cbData - 1 - i] = x;

		}

	}

}

_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall LoadModuleNameW(
	_In_ HMODULE hModule,
	_In_ Bool bRemoveFileSpec
) {

	Dword cchModuleName = MAX_PATH;
	const Dword cchMax = Uint32_MAX / sizeof(CharW);

	pStrW pchModuleName = (pStrW)(LocalAlloc(
		LPTR, cchModuleName * sizeof(CharW)
	));

	if (pchModuleName == NULL) {
		SetLastError(ERROR_NOT_ENOUGH_MEMORY);
		return NULL;
	}

	Dword cchChar = GetModuleFileNameW(
		hModule, ((LPWSTR)(pchModuleName)),
		cchModuleName
	);

	while (True) {

		if (cchChar != cchModuleName) {
			break;
		}

		LocalFree(pchModuleName);

		Dword cchFree = cchMax - cchModuleName;
		if (cchFree == 0U) {
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return NULL;
		}

		cchModuleName += (cchModuleName / 2 > cchFree) ?
			cchFree : cchModuleName / 2;

		pchModuleName = (pStrW)(LocalAlloc(
			LPTR, cchModuleName * sizeof(CharW)
		));

		if (pchModuleName == NULL) {
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return NULL;
		}

		cchChar = GetModuleFileNameW(
			hModule, ((LPWSTR)(pchModuleName)),
			cchModuleName
		);

	}

	if (cchChar == 0U) {
		Dword sCode = GetLastError();
		LocalFree(pchModuleName);
		SetLastError(sCode);
		return NULL;
	}

	if (bRemoveFileSpec == True) {
		PathRemoveFileSpecExW(pchModuleName);
	}

	SetLastError(ERROR_SUCCESS);
	return pchModuleName;

}

_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall LoadModuleNameA(
	_In_ HMODULE hModule,
	_In_ Bool bRemoveFileSpec
) {

	Dword cchModuleName = MAX_PATH;
	const Dword cchMax = Uint32_MAX / sizeof(CharA);

	pStrA pchModuleName = (pStrA)(LocalAlloc(
		LPTR, cchModuleName * sizeof(CharA)
	));

	if (pchModuleName == NULL) {
		SetLastError(ERROR_NOT_ENOUGH_MEMORY);
		return NULL;
	}

	Dword cchChar = GetModuleFileNameA(
		hModule, ((LPSTR)(pchModuleName)),
		cchModuleName
	);

	while (True) {

		if (cchChar != cchModuleName) {
			break;
		}

		LocalFree(pchModuleName);

		Dword cchFree = cchMax - cchModuleName;
		if (cchFree == 0U) {
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return NULL;
		}

		cchModuleName += (cchModuleName / 2 > cchFree) ?
			cchFree : cchModuleName / 2;

		pchModuleName = (pStrA)(LocalAlloc(
			LPTR, cchModuleName * sizeof(CharA)
		));

		if (pchModuleName == NULL) {
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return NULL;
		}

		cchChar = GetModuleFileNameA(
			hModule, ((LPSTR)(pchModuleName)),
			cchModuleName
		);

	}

	if (cchChar == 0U) {
		Dword sCode = GetLastError();
		LocalFree(pchModuleName);
		SetLastError(sCode);
		return NULL;
	}

	if (bRemoveFileSpec == True) {
		PathRemoveFileSpecExA(pchModuleName);
	}

	SetLastError(ERROR_SUCCESS);
	return pchModuleName;

}

_COMMON_X_API_ void __stdcall PathRemoveFileSpecExW(
	_In_z_ pStrW pchFileSpec
) {

	if (pchFileSpec != NULL) {

		SizeOF cchCount =
			StrW_Count(pchFileSpec);

		while (cchCount != 0) {

			if (
				pchFileSpec[cchCount - 1] == L'\\' ||
				pchFileSpec[cchCount - 1] == L'/'
			) {
				pchFileSpec[cchCount - 1] = L'\0';
				cchCount--;
				break;
			}

			pchFileSpec[cchCount - 1] = L'\0';
			cchCount--;

		}

	}

}

_COMMON_X_API_ void __stdcall PathRemoveFileSpecExA(
	_In_z_ pStrA pchFileSpec
) {

	if (pchFileSpec != NULL) {

		SizeOF cchCount =
			StrA_Count(pchFileSpec);

		while (cchCount != 0) {

			if (
				pchFileSpec[cchCount - 1] == L'\\' ||
				pchFileSpec[cchCount - 1] == L'/'
			) {
				pchFileSpec[cchCount - 1] = '\0';
				cchCount--;
				break;
			}

			pchFileSpec[cchCount - 1] = '\0';
			cchCount--;

		}

	}

}

_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall SystemTimeStringAllocW(
	_In_ const LPSYSTEMTIME pSystemTime,
	_In_ Bool bForce24HourFormat
) {

	Dword dwFlags = (bForce24HourFormat == True) ?
		TIME_NOTIMEMARKER | TIME_FORCE24HOURFORMAT : 0U;

	Int32 cchCount = GetTimeFormatW(
		LOCALE_USER_DEFAULT, dwFlags,
		pSystemTime, NULL, NULL, 0
	);

	Dword sCode = GetLastError();
	if (cchCount != 0) {

		pStrW pchTime = (pStrW)(LocalAlloc(
			LPTR, cchCount * sizeof(CharW)
		));

		sCode = ERROR_NOT_ENOUGH_MEMORY;
		if (pchTime != NULL) {

			cchCount = GetTimeFormatW(
				LOCALE_USER_DEFAULT, dwFlags,
				pSystemTime, NULL, (LPWSTR)(pchTime), cchCount
			);

			sCode = GetLastError();
			if (cchCount != 0) {
				sCode = ERROR_SUCCESS;
				SetLastError(sCode);
				return pchTime;
			}

			LocalFree(pchTime);

		}

	}

	SetLastError(
		(sCode == ERROR_OUTOFMEMORY) ?
		ERROR_NOT_ENOUGH_MEMORY : sCode
	);

	return NULL;

}

_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall SystemTimeStringAllocA(
	_In_ const LPSYSTEMTIME pSystemTime,
	_In_ Bool bForce24HourFormat
) {

	Dword dwFlags = (bForce24HourFormat == True) ?
		TIME_NOTIMEMARKER | TIME_FORCE24HOURFORMAT : 0U;

	Int32 cchCount = GetTimeFormatA(
		LOCALE_USER_DEFAULT, dwFlags,
		pSystemTime, NULL, NULL, 0
	);

	Dword sCode = GetLastError();
	if (cchCount != 0) {

		pStrA pchTime = (pStrA)(LocalAlloc(
			LPTR, cchCount * sizeof(CharA)
		));

		sCode = ERROR_NOT_ENOUGH_MEMORY;
		if (pchTime != NULL) {

			cchCount = GetTimeFormatA(
				LOCALE_USER_DEFAULT, dwFlags,
				pSystemTime, NULL, (LPSTR)(pchTime), cchCount
			);

			sCode = GetLastError();
			if (cchCount != 0) {
				sCode = ERROR_SUCCESS;
				SetLastError(sCode);
				return pchTime;
			}

			LocalFree(pchTime);

		}

	}

	SetLastError(
		(sCode == ERROR_OUTOFMEMORY) ?
		ERROR_NOT_ENOUGH_MEMORY : sCode
	);

	return NULL;

}

_COMMON_X_API_ Bool __stdcall FileExistsW(
	_In_z_ pCStrW pchFileSpec
) {

	Dword sCode = ERROR_INVALID_PARAMETER;
	if (pchFileSpec != NULL) {

		WIN32_FIND_DATAW w32Fd = { 0 };
		HANDLE hFindFile = FindFirstFileW(pchFileSpec, &w32Fd);

		sCode = GetLastError();
		if (hFindFile != INVALID_HANDLE_VALUE) {
			
			sCode = ERROR_FILE_NOT_FOUND;
			if ((w32Fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0U) {
				FindClose(hFindFile);
				SetLastError(ERROR_SUCCESS);
				return True;
			}

			FindClose(hFindFile);

		}

	}

	SetLastError(sCode);
	return False;

}

_COMMON_X_API_ Bool __stdcall FileExistsA(
	_In_z_ pCStrA pchFileSpec
) {

	Dword sCode = ERROR_INVALID_PARAMETER;
	if (pchFileSpec != NULL) {

		WIN32_FIND_DATAA w32Fd = { 0 };
		HANDLE hFindFile = FindFirstFileA(pchFileSpec, &w32Fd);

		sCode = GetLastError();
		if (hFindFile != INVALID_HANDLE_VALUE) {

			sCode = ERROR_FILE_NOT_FOUND;
			if ((w32Fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0U) {
				FindClose(hFindFile);
				SetLastError(ERROR_SUCCESS);
				return True;
			}

			FindClose(hFindFile);

		}

	}

	SetLastError(sCode);
	return False;

}

_COMMON_X_API_ HANDLE _Success_(return != INVALID_HANDLE_VALUE) __stdcall FSCreateFileW(
	_In_z_ pCStrW pchFileSpec,
	_In_ Dword dwDesiredAccess,
	_In_ Dword dwCreationDisposition
) {

	/* Result File Handle */
	HANDLE hFile = INVALID_HANDLE_VALUE;

	Dword sCode = ERROR_INVALID_PARAMETER;
	if (pchFileSpec != NULL) {

		SizeOF cchFileSpec = StrW_Count(pchFileSpec) + 1U;
		pStrW pchFileDir = (pStrW)(HeapAlloc(
			GetProcessHeap(), HEAP_ZERO_MEMORY,
			cchFileSpec * sizeof(CharW)
		));

		sCode = ERROR_NOT_ENOUGH_MEMORY;
		if (pchFileDir != NULL) {

			sCode = ERROR_SUCCESS;

			StrW_Copy(pchFileDir, cchFileSpec, pchFileSpec);
			PathRemoveFileSpecExW(pchFileDir);

			if (dwCreationDisposition != OPEN_EXISTING && dwCreationDisposition != TRUNCATE_EXISTING) {
				sCode = (Dword)(SHCreateDirectoryExW(
					NULL, pchFileDir, NULL
				));
			}

			sCode = (sCode == ERROR_ALREADY_EXISTS) ?
				ERROR_SUCCESS : sCode;

			if (sCode == ERROR_SUCCESS) {

				hFile = CreateFileW(
					pchFileSpec, dwDesiredAccess,
					FILE_SHARE_READ, NULL, dwCreationDisposition,
					FILE_ATTRIBUTE_NORMAL, NULL
				);

				sCode = GetLastError();

			}

			HeapFree(
				GetProcessHeap(), 0U,
				pchFileDir
			);

		}

	}

	SetLastError(sCode);
	return hFile;

}

_COMMON_X_API_ HANDLE _Success_(return != INVALID_HANDLE_VALUE) __stdcall FSCreateFileA(
	_In_z_ pCStrA pchFileSpec,
	_In_ Dword dwDesiredAccess,
	_In_ Dword dwCreationDisposition
) {

	/* Result File Handle */
	HANDLE hFile = INVALID_HANDLE_VALUE;

	Dword sCode = ERROR_INVALID_PARAMETER;
	if (pchFileSpec != NULL) {

		SizeOF cchFileSpec = StrA_Count(pchFileSpec) + 1U;
		pStrA pchFileDir = (pStrA)(HeapAlloc(
			GetProcessHeap(), HEAP_ZERO_MEMORY,
			cchFileSpec * sizeof(CharA)
		));

		sCode = ERROR_NOT_ENOUGH_MEMORY;
		if (pchFileDir != NULL) {

			sCode = ERROR_SUCCESS;

			StrA_Copy(pchFileDir, cchFileSpec, pchFileSpec);
			PathRemoveFileSpecExA(pchFileDir);

			if (dwCreationDisposition != OPEN_EXISTING && dwCreationDisposition != TRUNCATE_EXISTING) {
				sCode = (Dword)(SHCreateDirectoryExA(
					NULL, pchFileDir, NULL
				));
			}

			sCode = (sCode == ERROR_ALREADY_EXISTS) ?
				ERROR_SUCCESS : sCode;

			if (sCode == ERROR_SUCCESS) {

				hFile = CreateFileA(
					pchFileSpec, dwDesiredAccess,
					FILE_SHARE_READ, NULL, dwCreationDisposition,
					FILE_ATTRIBUTE_NORMAL, NULL
				);

				sCode = GetLastError();

			}

			HeapFree(
				GetProcessHeap(), 0U,
				pchFileDir
			);

		}

	}

	SetLastError(sCode);
	return hFile;

}

_COMMON_X_API_ _Success_(return == True) Bool __stdcall SaveScreenshot(
	_In_bytecount_(cbRGB) pCVoid pvRGB,
	_In_ Uint32 cbRGB,
	_In_ Int32 Cx,
	_In_ Int32 Cy
) {

	Word x = 0xAA55;
	Bool isLittle = (((pByte)(&x))[0] == 0x55) ? True : False;

	Bool bSuccess = False;
	Dword sCode = ERROR_INVALID_PARAMETER;
	if (Cx > 0 && Cy > 0) {

		sCode = ERROR_FILE_TOO_LARGE;
		Dword cbImageSize = Cx * Cy;
		if (cbImageSize / Cy == Cx) {

			Dword pixelAmount = cbImageSize;
			cbImageSize = cbImageSize * sizeof(RGBQUAD);
			if (cbImageSize / sizeof(RGBQUAD) == pixelAmount) {

				const Dword cbHeader = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
				Dword cbFree = Uint32_MAX - cbImageSize;
				if (cbHeader <= cbFree) {

					pByte pImage = (pByte)(HeapAlloc(
						GetProcessHeap(), HEAP_ZERO_MEMORY,
						cbHeader + cbImageSize
					));

					sCode = ERROR_NOT_ENOUGH_MEMORY;
					if (pImage != NULL) {

						// -----------------------------------------------------------------------------
						LPBITMAPFILEHEADER pBitmapFileHeader = (LPBITMAPFILEHEADER)(pImage);
						((pByte)(pBitmapFileHeader->bfType))[0] = 'B';
						((pByte)(pBitmapFileHeader->bfType))[1] = 'M';
						pBitmapFileHeader->bfSize = cbHeader + cbImageSize;
						if (!isLittle) ByteSwap(&pBitmapFileHeader->bfSize, sizeof(pBitmapFileHeader->bfSize));
						pBitmapFileHeader->bfOffBits = cbHeader;
						if (!isLittle) ByteSwap(&pBitmapFileHeader->bfOffBits, sizeof(pBitmapFileHeader->bfOffBits));
						// -----------------------------------------------------------------------------
						LPBITMAPINFOHEADER pBitmapInfoHeader = (LPBITMAPINFOHEADER)(pImage + (cbHeader - sizeof(BITMAPINFOHEADER)));
						pBitmapInfoHeader->biSize = sizeof(BITMAPINFOHEADER);
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biSize, sizeof(pBitmapInfoHeader->biSize));
						pBitmapInfoHeader->biWidth = Cx;
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biWidth, sizeof(pBitmapInfoHeader->biWidth));
						pBitmapInfoHeader->biHeight = Cy * (-1);
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biHeight, sizeof(pBitmapInfoHeader->biHeight));
						pBitmapInfoHeader->biPlanes = 1;
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biPlanes, sizeof(pBitmapInfoHeader->biPlanes));
						pBitmapInfoHeader->biBitCount = 32;
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biBitCount, sizeof(pBitmapInfoHeader->biBitCount));
						pBitmapInfoHeader->biCompression = BI_RGB;
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biCompression, sizeof(pBitmapInfoHeader->biCompression));
						pBitmapInfoHeader->biXPelsPerMeter = Cx;
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biXPelsPerMeter, sizeof(pBitmapInfoHeader->biXPelsPerMeter));
						pBitmapInfoHeader->biYPelsPerMeter = Cy;
						if (!isLittle) ByteSwap(&pBitmapInfoHeader->biYPelsPerMeter, sizeof(pBitmapInfoHeader->biYPelsPerMeter));
						// -----------------------------------------------------------------------------

						RGBQUAD *pImageData = (RGBQUAD*)(pImage + cbHeader);

						if (pvRGB != NULL && cbRGB != 0) {
							Dword pixel = 0;
							for (Uint32 i = 0; i < cbRGB / sizeof(RGB); i++) {

								if (pixel >= pixelAmount) {
									break;
								}

								#pragma warning(push)
								#pragma warning(disable : 6385)
								(pImageData[pixel]).rgbRed = (((pRGB)(pvRGB))[i]).rgbRed;
								(pImageData[pixel]).rgbGreen = (((pRGB)(pvRGB))[i]).rgbGreen;
								(pImageData[pixel]).rgbBlue = (((pRGB)(pvRGB))[i]).rgbBlue;
								#pragma warning(pop)

								pixel++;

							}
						}

						// -----------------------------------------------------------------------------

						pStrW pchGameSaveFileName = GetGameSaveFileNameW(
							GetModuleHandleW(NULL), NULL,
							k_ESaveType_Sreenshots
						);

						sCode = GetLastError();
						if (pchGameSaveFileName != NULL) {

							HANDLE hFile = FSCreateFileW(
								pchGameSaveFileName, GENERIC_WRITE,
								CREATE_ALWAYS
							);

							sCode = GetLastError();
							if (hFile != INVALID_HANDLE_VALUE) {

								Dword dwWriteAmount = 0U;
								Bool bWriteSuccess = WriteFile(
									hFile, pImage, cbHeader + cbImageSize,
									&dwWriteAmount, NULL
								);

								sCode = GetLastError();
								sCode = (sCode == ERROR_SUCCESS) ? ERROR_HANDLE_EOF : sCode;

								if (bWriteSuccess == True && dwWriteAmount == (cbHeader + cbImageSize)) {
									
									sCode = ERROR_SUCCESS;
									bSuccess = True;

								}

								CloseHandle(hFile);
								
								if (bSuccess == False) {
									DeleteFileW(pchGameSaveFileName);
								}

							}

							LocalFree(pchGameSaveFileName);

						}

						HeapFree(
							GetProcessHeap(), 0U,
							pImage
						);

					}

				}

			}

		}

	}

	SetLastError(sCode);
	return bSuccess;

}

_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall GetGameSaveFileNameW(
	_In_ HMODULE hModule,
	_In_opt_z_ pCStrW pchFileSpec,
	_In_ ESaveType eSaveType
) {

	const Dword cchMax = MAX_PATH - 1U;
	pStrW pchModuleDirectory = LoadModuleNameW(hModule, True);

	Dword sCode = GetLastError();
	if (pchModuleDirectory != NULL) {

		Dword cchModuleDirectory =
			(Dword)(StrW_Count(pchModuleDirectory));

		sCode = ERROR_MRM_FILEPATH_TOO_LONG;
		if (cchModuleDirectory <= cchMax) {
			sCode = ERROR_SUCCESS;

			pStrW pchGameSaveFileName = NULL;
			pStrW pchDirectory = NULL;

			switch (eSaveType) {
				case k_ESaveType_Storage:
					pchDirectory = L"\\Storage\\";
					break;
				case k_ESaveType_Sreenshots:
					pchDirectory = L"\\Sreenshots\\";
					break;
				default:
					sCode = ERROR_INVALID_PARAMETER;
					break;
			}

			if (sCode == ERROR_SUCCESS) {

				Dword cchDirectory = (Dword)(StrW_Count(pchDirectory));

				pCStrW pchGameFile = (pchFileSpec != NULL) ? pchFileSpec :
					(eSaveType == k_ESaveType_Sreenshots) ? L"Sreenshot.bmp" : L"Save.dat";
				SizeOF cchGameFile = StrW_Count(pchGameFile);

				pchGameFile = (cchGameFile != 0) ? pchGameFile :
					(eSaveType == k_ESaveType_Sreenshots) ? L"Sreenshot.bmp" : L"Save.dat";
				cchGameFile = StrW_Count(pchGameFile);

				sCode = ERROR_MRM_FILEPATH_TOO_LONG;
				if (cchGameFile <= cchMax) {
					if (cchModuleDirectory + cchDirectory + cchGameFile <= cchMax) {

						pchGameSaveFileName = (pStrW)(LocalAlloc(
							LPTR, (cchMax + 1U) * sizeof(CharW)
						));

						sCode = ERROR_NOT_ENOUGH_MEMORY;
						if (pchGameSaveFileName != NULL) {
							sCode = ERROR_SUCCESS;

							if (eSaveType == k_ESaveType_Sreenshots) {

								CharW chDirectory[MAX_PATH] = { 0 };
								StrW_Copy(chDirectory, MAX_PATH, pchModuleDirectory);
								StrW_Cat(chDirectory, MAX_PATH, pchDirectory);

								sCode = ERROR_MRM_FILEPATH_TOO_LONG;
								if (PathMakeUniqueName(pchGameSaveFileName, cchMax + 1U,
									pchGameFile, NULL, chDirectory
								)) {

									sCode = ERROR_SUCCESS;
									LocalFree(pchModuleDirectory);
									SetLastError(sCode);
									return pchGameSaveFileName;

								}

							} else {

								sCode = ERROR_SUCCESS;

								StrW_Copy(pchGameSaveFileName, cchMax + 1U, pchModuleDirectory);
								StrW_Cat(pchGameSaveFileName, cchMax + 1U, pchDirectory);
								StrW_Cat(pchGameSaveFileName, cchMax + 1U, pchGameFile);

								LocalFree(pchModuleDirectory);
								SetLastError(sCode);
								return pchGameSaveFileName;

							}

							LocalFree(pchGameSaveFileName);

						}


					}
				}

			}

			LocalFree(pchModuleDirectory);

		}

	}

	SetLastError(sCode);
	return NULL;

}

_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall GetGameSaveFileNameA(
	_In_ HMODULE hModule,
	_In_opt_z_ pCStrA pchFileSpec,
	_In_ ESaveType eSaveType
) {

	Dword sCode = ERROR_SUCCESS;
	pStrW pwchFileSpec = NULL;

	if (pchFileSpec != NULL) {

		pwchFileSpec = MultiByteToWideCharAlloc(pchFileSpec);
		sCode = GetLastError();

	}

	pStrA pchGameSaveFileName = NULL;
	if (sCode == ERROR_SUCCESS) {

		pStrW pwchGameSaveFileName = GetGameSaveFileNameW(
			hModule, pwchFileSpec,
			eSaveType
		);

		sCode = GetLastError();
		if (pwchGameSaveFileName != NULL) {

			pchGameSaveFileName = WideCharToMultiByteAlloc(pwchGameSaveFileName);
			sCode = GetLastError();
			LocalFree(pwchGameSaveFileName);

		}

		if (pwchFileSpec != NULL) {
			LocalFree(pwchFileSpec);
		}

	}

	SetLastError(sCode);
	return pchGameSaveFileName;

}

_COMMON_X_API_ pCStrW __stdcall GetUserUILanguageW(
	void
) {

	LANGID lcid = GetUserDefaultUILanguage();

	CharW chLang[LOCALE_NAME_MAX_LENGTH] = { 0 };
	GetLocaleInfoW(lcid, LOCALE_SISO639LANGNAME, chLang, LOCALE_NAME_MAX_LENGTH);
	CharW chCountry[LOCALE_NAME_MAX_LENGTH] = { 0 };
	GetLocaleInfoW(lcid, LOCALE_SISO3166CTRYNAME, chCountry, LOCALE_NAME_MAX_LENGTH);

	if (StrW_Cmp(chLang, L"ar", True)) {
		return L"arabic";
	} else if (StrW_Cmp(chLang, L"bg", True)) {
		return L"bulgarian";
	} else if (StrW_Cmp(chLang, L"zh", True) && StrW_Cmp(chCountry, L"CN", True)) {
		return L"schinese";
	} else if (StrW_Cmp(chLang, L"zh", True) && StrW_Cmp(chCountry, L"TW", True)) {
		return L"tchinese";
	} else if (StrW_Cmp(chLang, L"cs", True)) {
		return L"czech";
	} else if (StrW_Cmp(chLang, L"da", True)) {
		return L"danish";
	} else if (StrW_Cmp(chLang, L"nl", True)) {
		return L"dutch";
	} else if (StrW_Cmp(chLang, L"en", True)) {
		return L"english";
	} else if (StrW_Cmp(chLang, L"fi", True)) {
		return L"finnish";
	} else if (StrW_Cmp(chLang, L"fr", True)) {
		return L"french";
	} else if (StrW_Cmp(chLang, L"de", True)) {
		return L"german";
	} else if (StrW_Cmp(chLang, L"el", True)) {
		return L"greek";
	} else if (StrW_Cmp(chLang, L"hu", True)) {
		return L"hungarian";
	} else if (StrW_Cmp(chLang, L"id", True)) {
		return L"indonesian";
	} else if (StrW_Cmp(chLang, L"it", True)) {
		return L"italian";
	} else if (StrW_Cmp(chLang, L"ja", True)) {
		return L"japanese";
	} else if (StrW_Cmp(chLang, L"ko", True)) {
		return L"koreana";
	} else if (StrW_Cmp(chLang, L"no", True)) {
		return L"norwegian";
	} else if (StrW_Cmp(chLang, L"pl", True)) {
		return L"polish";
	} else if (StrW_Cmp(chLang, L"pt", True) && StrW_Cmp(chCountry, L"BR", True)) {
		return L"brazilian";
	} else if (StrW_Cmp(chLang, L"pt", True)) {
		return L"portuguese";
	} else if (StrW_Cmp(chLang, L"ro", True)) {
		return L"romanian";
	} else if (StrW_Cmp(chLang, L"ru", True)) {
		return L"russian";
	} else if (StrW_Cmp(chLang, L"es", True) && StrW_Cmp(chCountry, L"419", True)) {
		return L"latam";
	} else if (StrW_Cmp(chLang, L"es", True)) {
		return L"spanish";
	} else if (StrW_Cmp(chLang, L"sv", True)) {
		return L"swedish";
	} else if (StrW_Cmp(chLang, L"th", True)) {
		return L"thai";
	} else if (StrW_Cmp(chLang, L"tr", True)) {
		return L"turkish";
	} else if (StrW_Cmp(chLang, L"uk", True)) {
		return L"ukrainian";
	} else if (StrW_Cmp(chLang, L"vn", True)) {
		return L"vietnamese";
	}

	return L"english";

}

_COMMON_X_API_ pCStrA __stdcall GetUserUILanguageA(
	void
) {

	LANGID lcid = GetUserDefaultUILanguage();

	CharA chLang[LOCALE_NAME_MAX_LENGTH] = { 0 };
	GetLocaleInfoA(lcid, LOCALE_SISO639LANGNAME, chLang, LOCALE_NAME_MAX_LENGTH);
	CharA chCountry[LOCALE_NAME_MAX_LENGTH] = { 0 };
	GetLocaleInfoA(lcid, LOCALE_SISO3166CTRYNAME, chCountry, LOCALE_NAME_MAX_LENGTH);

	if (StrA_Cmp(chLang, "ar", True)) {
		return "arabic";
	} else if (StrA_Cmp(chLang, "bg", True)) {
		return "bulgarian";
	} else if (StrA_Cmp(chLang, "zh", True) && StrA_Cmp(chCountry, "CN", True)) {
		return "schinese";
	} else if (StrA_Cmp(chLang, "zh", True) && StrA_Cmp(chCountry, "TW", True)) {
		return "tchinese";
	} else if (StrA_Cmp(chLang, "cs", True)) {
		return "czech";
	} else if (StrA_Cmp(chLang, "da", True)) {
		return "danish";
	} else if (StrA_Cmp(chLang, "nl", True)) {
		return "dutch";
	} else if (StrA_Cmp(chLang, "en", True)) {
		return "english";
	} else if (StrA_Cmp(chLang, "fi", True)) {
		return "finnish";
	} else if (StrA_Cmp(chLang, "fr", True)) {
		return "french";
	} else if (StrA_Cmp(chLang, "de", True)) {
		return "german";
	} else if (StrA_Cmp(chLang, "el", True)) {
		return "greek";
	} else if (StrA_Cmp(chLang, "hu", True)) {
		return "hungarian";
	} else if (StrA_Cmp(chLang, "id", True)) {
		return "indonesian";
	} else if (StrA_Cmp(chLang, "it", True)) {
		return "italian";
	} else if (StrA_Cmp(chLang, "ja", True)) {
		return "japanese";
	} else if (StrA_Cmp(chLang, "ko", True)) {
		return "koreana";
	} else if (StrA_Cmp(chLang, "no", True)) {
		return "norwegian";
	} else if (StrA_Cmp(chLang, "pl", True)) {
		return "polish";
	} else if (StrA_Cmp(chLang, "pt", True) && StrA_Cmp(chCountry, "BR", True)) {
		return "brazilian";
	} else if (StrA_Cmp(chLang, "pt", True)) {
		return "portuguese";
	} else if (StrA_Cmp(chLang, "ro", True)) {
		return "romanian";
	} else if (StrA_Cmp(chLang, "ru", True)) {
		return "russian";
	} else if (StrA_Cmp(chLang, "es", True) && StrA_Cmp(chCountry, "419", True)) {
		return "latam";
	} else if (StrA_Cmp(chLang, "es", True)) {
		return "spanish";
	} else if (StrA_Cmp(chLang, "sv", True)) {
		return "swedish";
	} else if (StrA_Cmp(chLang, "th", True)) {
		return "thai";
	} else if (StrA_Cmp(chLang, "tr", True)) {
		return "turkish";
	} else if (StrA_Cmp(chLang, "uk", True)) {
		return "ukrainian";
	} else if (StrA_Cmp(chLang, "vn", True)) {
		return "vietnamese";
	}

	return "english";

}

_COMMON_X_API_ Uint32 __stdcall GetGameAppId(
	void
) {

	const Dword cchMax = MAX_PATH - 1U;
	pStrW pchModuleDirectory = LoadModuleNameW(GetModuleHandleW(NULL), True);

	Dword sCode = GetLastError();
	if (pchModuleDirectory != NULL) {

		Dword cchModuleDirectory =
			(Dword)(StrW_Count(pchModuleDirectory));

		sCode = ERROR_MRM_FILEPATH_TOO_LONG;
		if (cchModuleDirectory <= cchMax) {

			pCStrW pchAppIdFileSpec = L"\\steam_appid.txt";
			Dword cchAppIdFileSpec =
				(Dword)(StrW_Count(pchAppIdFileSpec));

			sCode = ERROR_MRM_FILEPATH_TOO_LONG;
			if (cchModuleDirectory + cchAppIdFileSpec <= cchMax) {

				CharW chAppIdFilePath[MAX_PATH] = { 0 };
				StrW_Copy(chAppIdFilePath, MAX_PATH, pchModuleDirectory);
				StrW_Cat(chAppIdFilePath, MAX_PATH, pchAppIdFileSpec);

				HANDLE hFile = FSCreateFileW(
					chAppIdFilePath, GENERIC_READ,
					OPEN_EXISTING
				);

				sCode = GetLastError();
				if (hFile != INVALID_HANDLE_VALUE) {

					Uint32 GameAppId = 0U;
					CharA cDigit = 0x00;

					while(True) {

						Dword dwReadAmount = 0U;
						Bool bSuccess = ReadFile(
							hFile, &cDigit, sizeof(CharA),
							&dwReadAmount, NULL
						);

						sCode = GetLastError();
						sCode = (sCode == ERROR_SUCCESS) ? ERROR_HANDLE_EOF : sCode;

						if (bSuccess == True) {

							if (dwReadAmount == 0U) {
								break;
							}

							sCode = ERROR_SUCCESS;

							if (cDigit < '0' || cDigit > '9') {
								break;
							}

							GameAppId = (GameAppId * 10) + (cDigit - '0');

						}

					}

					CloseHandle(hFile);

					if (sCode == ERROR_SUCCESS || sCode == ERROR_HANDLE_EOF) {

						LocalFree(pchModuleDirectory);
						SetLastError(ERROR_SUCCESS);
						return GameAppId;

					}

				}

			}

		}

		LocalFree(pchModuleDirectory);

	}

	SetLastError(sCode);
	return 0U;

}

_COMMON_X_API_ void __stdcall DebugFuncEntryW(
	_In_z_ pCStrW pchFuncName
) {

	if (pchFuncName != NULL) {

		HMODULE hModule = NULL;
		GetModuleHandleExW(
			GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
			GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(LPCWSTR)(DebugFuncEntryW),
			&hModule
		);
		
		/* Excludes '!' Character */
		const SizeOF cchMax = (SizeOF_MAX / sizeof(CharW)) - 4U;
		pStrW pchModuleDirectory = LoadModuleNameW(hModule, False);

		if (pchModuleDirectory != NULL) {

			SizeOF cchModuleDirectory =
				StrW_Count(pchModuleDirectory);

			while (cchModuleDirectory != 0) {

				if (
					pchModuleDirectory[cchModuleDirectory - 1] == L'\\' ||
					pchModuleDirectory[cchModuleDirectory - 1] == L'/'
					) {
					cchModuleDirectory--;
					break;
				}

				cchModuleDirectory--;

			}

			SizeOF cchModuleName = StrW_Count(pchModuleDirectory + cchModuleDirectory + 1U);
			SizeOF cchFuncName = StrW_Count(pchFuncName);
			if (cchModuleName <= cchMax && cchFuncName <= cchMax) {
				
				SizeOF cchFree = cchMax - cchModuleName;
				if (cchFuncName <= cchFree) {

					SizeOF cchDbgMsg = cchModuleName + cchFuncName + 3U;
					pStrW pchDbgMsg = HeapAlloc(
						GetProcessHeap(), HEAP_ZERO_MEMORY,
						(cchDbgMsg + 1U) * sizeof(CharW)
					);

					if (pchDbgMsg != NULL) {

						/* Format: "<Module>!<FuncName>" */

						StrW_Copy(pchDbgMsg, cchDbgMsg, pchModuleDirectory + cchModuleDirectory + 1U);
						StrW_Cat(pchDbgMsg, cchDbgMsg, L"!");
						StrW_Cat(pchDbgMsg, cchDbgMsg, pchFuncName);
						StrW_Cat(pchDbgMsg, cchDbgMsg, L"\r\n");

						OutputDebugStringW(pchDbgMsg);

						HeapFree(
							GetProcessHeap(), 0U,
							pchDbgMsg
						);

					}

				}

			}

			LocalFree(pchModuleDirectory);

		}

	}

}

_COMMON_X_API_ void __stdcall DebugFuncEntryA(
	_In_z_ pCStrA pchFuncName
) {

	if (pchFuncName != NULL) {

		HMODULE hModule = NULL;
		GetModuleHandleExA(
			GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
			GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(LPCSTR)(DebugFuncEntryA),
			&hModule
		);

		/* Excludes '!' Character */
		const SizeOF cchMax = (SizeOF_MAX / sizeof(CharA)) - 4U;
		pStrA pchModuleDirectory = LoadModuleNameA(hModule, False);

		if (pchModuleDirectory != NULL) {

			SizeOF cchModuleDirectory =
				StrA_Count(pchModuleDirectory);

			while (cchModuleDirectory != 0) {

				if (
					pchModuleDirectory[cchModuleDirectory - 1] == '\\' ||
					pchModuleDirectory[cchModuleDirectory - 1] == '/'
					) {
					cchModuleDirectory--;
					break;
				}

				cchModuleDirectory--;

			}

			SizeOF cchModuleName = StrA_Count(pchModuleDirectory + cchModuleDirectory + 1U);
			SizeOF cchFuncName = StrA_Count(pchFuncName);
			if (cchModuleName <= cchMax && cchFuncName <= cchMax) {

				SizeOF cchFree = cchMax - cchModuleName;
				if (cchFuncName <= cchFree) {

					SizeOF cchDbgMsg = cchModuleName + cchFuncName + 3U;
					pStrA pchDbgMsg = HeapAlloc(
						GetProcessHeap(), HEAP_ZERO_MEMORY,
						(cchDbgMsg + 1U) * sizeof(CharA)
					);

					if (pchDbgMsg != NULL) {

						/* Format: "<Module>!<FuncName>" */

						StrA_Copy(pchDbgMsg, cchDbgMsg, pchModuleDirectory + cchModuleDirectory + 1U);
						StrA_Cat(pchDbgMsg, cchDbgMsg, "!");
						StrA_Cat(pchDbgMsg, cchDbgMsg, pchFuncName);
						StrA_Cat(pchDbgMsg, cchDbgMsg, "\r\n");

						OutputDebugStringA(pchDbgMsg);

						HeapFree(
							GetProcessHeap(), 0U,
							pchDbgMsg
						);

					}

				}

			}

			LocalFree(pchModuleDirectory);

		}

	}

}

_COMMON_X_API_ void __stdcall DebugOutputW(
	_In_z_ pCStrW pchStr
) {

	if (pchStr != NULL) {

		const SizeOF cchMax = (SizeOF_MAX / sizeof(CharW)) - 4U;
		SizeOF cchStr = StrW_Count(pchStr);
		if (cchStr <= cchMax) {

			pStrW pchDbgOut = HeapAlloc(
				GetProcessHeap(), HEAP_ZERO_MEMORY,
				(cchStr + 4U) * sizeof(CharW)
			);

			if (pchDbgOut != NULL) {

				StrW_Copy(pchDbgOut, cchStr + 4U, L"\t");
				StrW_Cat(pchDbgOut, cchStr + 4U, pchStr);
				StrW_Cat(pchDbgOut, cchStr + 4U, L"\r\n");

				OutputDebugStringW(pchDbgOut);

				HeapFree(
					GetProcessHeap(), 0U,
					pchDbgOut
				);

			}

		}

	}

}

_COMMON_X_API_ void __stdcall DebugOutputA(
	_In_z_ pCStrA pchStr
) {

	if (pchStr != NULL) {

		const SizeOF cchMax = (SizeOF_MAX / sizeof(CharA)) - 4U;
		SizeOF cchStr = StrA_Count(pchStr);
		if (cchStr <= cchMax) {

			pStrA pchDbgOut = HeapAlloc(
				GetProcessHeap(), HEAP_ZERO_MEMORY,
				(cchStr + 4U) * sizeof(CharA)
			);

			if (pchDbgOut != NULL) {

				StrA_Copy(pchDbgOut, cchStr + 4U, "\t");
				StrA_Cat(pchDbgOut, cchStr + 4U, pchStr);
				StrA_Cat(pchDbgOut, cchStr + 4U, "\r\n");

				OutputDebugStringA(pchDbgOut);

				HeapFree(
					GetProcessHeap(), 0U,
					pchDbgOut
				);

			}

		}

	}

}
