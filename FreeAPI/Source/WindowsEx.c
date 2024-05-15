// -----------------------------------------------------------------------------
#include "WindowsEx.h"
// -----------------------------------------------------------------------------

_WINDOWS_EX_API_ _Success_(return != NULL) pStrW __stdcall LoadModuleNameW(
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

_WINDOWS_EX_API_ _Success_(return != NULL) pStrA __stdcall LoadModuleNameA(
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

_WINDOWS_EX_API_ void __stdcall PathRemoveFileSpecExW(
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

_WINDOWS_EX_API_ void __stdcall PathRemoveFileSpecExA(
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
