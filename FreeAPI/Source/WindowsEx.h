#ifndef _WINDOWS_EX_
#define _WINDOWS_EX_

#ifdef __cplusplus
	#define _WINDOWS_EX_API_ extern "C"
#else // !C++
	#define _WINDOWS_EX_API_ extern
#endif

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "Typedef.h"
#include "StrX.h"
// -----------------------------------------------------------------------------

#ifndef __SAL_H_VERSION
	#define _Success_(expr)
	#define _In_
#endif

_WINDOWS_EX_API_ _Success_(return != NULL) pStrW __stdcall LoadModuleNameW(
	_In_ HMODULE hModule,
	_In_ Bool bRemoveFileSpec
);

_WINDOWS_EX_API_ _Success_(return != NULL) pStrA __stdcall LoadModuleNameA(
	_In_ HMODULE hModule,
	_In_ Bool bRemoveFileSpec
);

#ifdef UNICODE
	#define LoadModuleName LoadModuleNameW
#else // ANSI
	#define LoadModuleName LoadModuleNameA
#endif

_WINDOWS_EX_API_ void __stdcall PathRemoveFileSpecExW(
	_In_z_ pStrW pchFileSpec
);

_WINDOWS_EX_API_ void __stdcall PathRemoveFileSpecExA(
	_In_z_ pStrA pchFileSpec
);

#ifdef UNICODE
	#define PathRemoveFileSpecEx PathRemoveFileSpecExW
#else // ANSI
	#define PathRemoveFileSpecEx PathRemoveFileSpecExA
#endif

#endif // !_WINDOWS_EX_
