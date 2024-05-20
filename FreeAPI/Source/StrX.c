#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
// -----------------------------------------------------------------------------
#include "StrX.h"
// -----------------------------------------------------------------------------

_STR_X_API_ SizeOF __stdcall StrW_Count(
	_In_z_ const pStrW pchSrc
) {

	if (pchSrc == NULL) {
		return 0;
	}

	SizeOF i = 0;
	while (pchSrc[i] != L'\0') {
		i++;
	}

	return i;

}

_STR_X_API_ SizeOF __stdcall StrA_Count(
	_In_z_ const pStrA pchSrc
) {

	if (pchSrc == NULL) {
		return 0;
	}

	SizeOF i = 0;
	while (pchSrc[i] != '\0') {
		i++;
	}

	return i;

}

_STR_X_API_ pStrW __stdcall StrW_Copy(
	_Out_z_cap_(cchMax) pStrW pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrW pchSrc
) {

	if (pchDest == NULL || cchMax == 0) {
		return pchDest;
	}

	// (Null) String is Same as (Empty) String
	if (pchSrc == NULL) {
		pchDest[0] = L'\0';
		return pchDest;
	}

	SizeOF i = 0;
	while (i < cchMax) {

		pchDest[i] = pchSrc[i];

		if (pchDest[i] == L'\0') {
			break;
		}

		i++;

	}

	// Truncate
	if (i == cchMax) {
		pchDest[i - 1] = L'\0';
	}

	return pchDest;

}

_STR_X_API_ pStrA __stdcall StrA_Copy(
	_Out_z_cap_(cchMax) pStrA pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrA pchSrc
) {

	if (pchDest == NULL || cchMax == 0) {
		return pchDest;
	}

	// (Null) String is Same as (Empty) String
	if (pchSrc == NULL) {
		pchDest[0] = '\0';
		return pchDest;
	}

	SizeOF i = 0;
	while (i < cchMax) {

		pchDest[i] = pchSrc[i];

		if (pchDest[i] == '\0') {
			break;
		}

		i++;

	}

	// Truncate
	if (i == cchMax) {
		pchDest[i - 1] = '\0';
	}

	return pchDest;

}

_STR_X_API_ pStrW __stdcall StrW_Cat(
	_Inout_z_cap_(cchMax) pStrW pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrW pchSrc
) {

	if (pchDest == NULL || cchMax == 0) {
		return pchDest;
	}

	SizeOF i = 0;
	while (i < cchMax) {

		if (pchDest[i] == L'\0') {
			StrW_Copy(pchDest + i, cchMax - i, pchSrc);
			return pchDest;
		}

		i++;

	}

	return pchDest;

}

_STR_X_API_ pStrA __stdcall StrA_Cat(
	_Inout_z_cap_(cchMax) pStrA pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrA pchSrc
) {

	if (pchDest == NULL || cchMax == 0) {
		return pchDest;
	}

	SizeOF i = 0;
	while (i < cchMax) {

		if (pchDest[i] == '\0') {
			StrA_Copy(pchDest + i, cchMax - i, pchSrc);
			return pchDest;
		}

		i++;

	}

	return pchDest;

}

_STR_X_API_ Bool __stdcall StrW_Cmp(
	_In_z_ const pStrW pchCmp,
	_In_z_ const pStrW pchSrc,
	_In_ Bool iCase
) {

	if (pchCmp == pchSrc) {
		return True;
	}

	if (pchCmp == NULL || pchSrc == NULL) {
		return False;
	}

	SizeOF i = 0;
	while (True) {

		if (iCase == True) {

			if (CharUpperW(((LPWSTR)(pchSrc[i]))) != CharUpperW(((LPWSTR)(pchSrc[i])))) {
				return False;
			}

		} else {

			if (pchCmp[i] != pchSrc[i]) {
				return False;
			}

		}

		if (pchCmp[i] == L'\0') {
			return True;
		}

		i++;

	}

	return False;

}

_STR_X_API_ Bool __stdcall StrA_Cmp(
	_In_z_ const pStrA pchCmp,
	_In_z_ const pStrA pchSrc,
	_In_ Bool iCase
) {

	if (pchCmp == pchSrc) {
		return True;
	}

	if (pchCmp == NULL || pchSrc == NULL) {
		return False;
	}

	SizeOF i = 0;
	while (True) {

		if (iCase == True) {

			if (CharUpperA(((LPSTR)(pchSrc[i]))) != CharUpperA(((LPSTR)(pchSrc[i])))) {
				return False;
			}

		} else {

			if (pchCmp[i] != pchSrc[i]) {
				return False;
			}

		}

		if (pchCmp[i] == L'\0') {
			return True;
		}

		i++;

	}

	return False;

}

_STR_X_API_ SizeOF __stdcall StrW_StrW(
	_In_z_ const pStrW pchStr,
	_In_z_ const pStrW pchStrStr,
	_In_ Bool iCase
) {

	if (pchStr == pchStrStr) {
		return True;
	}

	if (pchStr == NULL || pchStrStr == NULL) {
		return False;
	}

	SizeOF cchStr = StrW_Count(pchStr);
	SizeOF cchStrStr = StrW_Count(pchStrStr);

	for (SizeOF i = 0U; i < cchStr; i++) {
		
		SizeOF j = 0U;
		for (j = 0U; j < cchStrStr && i + j < cchStr; j++) {
			
			if (iCase == True) {

				if (CharUpperW(((LPWSTR)(pchStr[i + j]))) != CharUpperW(((LPWSTR)(pchStrStr[j])))) {
					break;
				}

			} else {

				if (pchStr[i + j] != pchStrStr[j]) {
					break;
				}

			}
		}

		if (j == cchStrStr) {

			return i;

		}

	}

	return SizeOF_MAX;

}

_STR_X_API_ SizeOF __stdcall StrA_StrA(
	_In_z_ const pStrA pchStr,
	_In_z_ const pStrA pchStrStr,
	_In_ Bool iCase
) {

	if (pchStr == pchStrStr) {
		return True;
	}

	if (pchStr == NULL || pchStrStr == NULL) {
		return False;
	}

	SizeOF cchStr = StrA_Count(pchStr);
	SizeOF cchStrStr = StrA_Count(pchStrStr);

	for (SizeOF i = 0U; i < cchStr; i++) {

		SizeOF j = 0U;
		for (j = 0U; j < cchStrStr && i + j < cchStr; j++) {

			if (iCase == True) {

				if (CharUpperA(((LPSTR)(pchStr[i + j]))) != CharUpperA(((LPSTR)(pchStrStr[j])))) {
					break;
				}

			} else {

				if (pchStr[i + j] != pchStrStr[j]) {
					break;
				}

			}
		}

		if (j == cchStrStr) {

			return i;

		}

	}

	return SizeOF_MAX;

}
