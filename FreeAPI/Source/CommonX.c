// -----------------------------------------------------------------------------
#include "CommonX.h"
// -----------------------------------------------------------------------------

_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall WideCharToMultiByteAlloc(
	_In_z_ const pStrW pchWideStr
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
	_In_z_ const pStrA pchStr
) {

	Dword sCode = ERROR_INVALID_PARAMETER;
	if (pchStr != NULL) {

		Int32 cchWideStr = MultiByteToWideChar(
			CP_UTF8, WC_COMPOSITECHECK, (LPCSTR)(pchStr), -1,
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
					CP_UTF8, WC_COMPOSITECHECK, (LPCSTR)(pchStr), -1,
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
	_In_z_ const pStrW pchFileSpec
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
	_In_z_ const pStrA pchFileSpec
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
	_In_z_ const pStrW pchFileSpec,
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

			StrW_Copy(pchFileDir, cchFileSpec, pchFileSpec);
			PathRemoveFileSpecExW(pchFileDir);

			sCode = (Dword)(SHCreateDirectoryExW(
				NULL, pchFileDir, NULL
			));

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
	_In_z_ const pStrA pchFileSpec,
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

			StrA_Copy(pchFileDir, cchFileSpec, pchFileSpec);
			PathRemoveFileSpecExA(pchFileDir);

			sCode = (Dword)(SHCreateDirectoryExA(
				NULL, pchFileDir, NULL
			));

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
	_In_bytecount_(cbRgb) const pVoid pvRGB,
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

						LPRGBQUAD pImageData = (LPRGBQUAD)(pImage + cbHeader);

						if (pvRGB != NULL && cbRGB != 0) {
							Dword pixel = 0;
							for (Uint32 i = 0; i < cbRGB / sizeof(RGB); i++) {

								if (pixel >= pixelAmount) {
									break;
								}

								(pImageData[pixel]).rgbRed = (((pRGB)(pvRGB))[i]).rgbRed;
								(pImageData[pixel]).rgbGreen = (((pRGB)(pvRGB))[i]).rgbGreen;
								(pImageData[pixel]).rgbBlue = (((pRGB)(pvRGB))[i]).rgbBlue;

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

								Dword dwWritteAmount = 0U;
								Bool bWriteSuccess = WriteFile(
									hFile, pImage, cbHeader + cbImageSize,
									&dwWritteAmount, NULL
								);

								sCode = GetLastError();
								sCode = (sCode == ERROR_SUCCESS) ? ERROR_HANDLE_EOF : sCode;

								if (bWriteSuccess == True && dwWritteAmount == (cbHeader + cbImageSize)) {
									
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
	_In_opt_z_ const pStrW pchFileSpec,
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

				Dword cchDirectory = StrW_Count(pchDirectory);

				pStrW pchGameFile = (pchFileSpec != NULL) ? pchFileSpec :
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
	_In_opt_z_ const pStrA pchFileSpec,
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
