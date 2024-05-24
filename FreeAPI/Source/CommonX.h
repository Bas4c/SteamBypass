#ifndef _COMMON_X_
#define _COMMON_X_

#ifdef __cplusplus
	#define _COMMON_X_API_ extern "C"
#else // !C++
	#define _COMMON_X_API_ extern
#endif

#include <Shlobj.h>
#include <Shlobj_core.h>
#include <Windows.h>
// -----------------------------------------------------------------------------
#include "Typedef.h"
#include "StrX.h"
// -----------------------------------------------------------------------------

#ifndef __SAL_H_VERSION
	#define _Success_(expr)
	#define _Inout_bytecount_(expr)
	#define _In_bytecount_(expr)
	#define _In_z_ 
	#define _In_opt_z_ 
	#define _In_
#endif

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall WideCharToMultiByteAlloc(
	_In_z_ pCStrW pchWideStr
);

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall MultiByteToWideCharAlloc(
	_In_z_ pCStrA pchStr
);

_COMMON_X_API_ void __stdcall ByteSwap(
	_Inout_bytecount_(cbData) pVoid pvData,
	_In_ SizeOF cbData
);

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall LoadModuleNameW(
	_In_ HMODULE hModule,
	_In_ Bool bRemoveFileSpec
);

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall LoadModuleNameA(
	_In_ HMODULE hModule,
	_In_ Bool bRemoveFileSpec
);

#ifdef UNICODE
	#define LoadModuleName LoadModuleNameW
#else // ANSI
	#define LoadModuleName LoadModuleNameA
#endif

_COMMON_X_API_ void __stdcall PathRemoveFileSpecExW(
	_In_z_ pStrW pchFileSpec
);

_COMMON_X_API_ void __stdcall PathRemoveFileSpecExA(
	_In_z_ pStrA pchFileSpec
);

#ifdef UNICODE
	#define PathRemoveFileSpecEx PathRemoveFileSpecExW
#else // ANSI
	#define PathRemoveFileSpecEx PathRemoveFileSpecExA
#endif

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall SystemTimeStringAllocW(
	_In_ const LPSYSTEMTIME pSystemTime,
	_In_ Bool bForce24HourFormat
);

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall SystemTimeStringAllocA(
	_In_ const LPSYSTEMTIME pSystemTime,
	_In_ Bool bForce24HourFormat
);

#ifdef UNICODE
	#define SystemTimeStringAlloc SystemTimeStringAllocW
#else // ANSI
	#define SystemTimeStringAlloc SystemTimeStringAllocA
#endif

_COMMON_X_API_ Bool __stdcall FileExistsW(
	_In_z_ pCStrW pchFileSpec
);

_COMMON_X_API_ Bool __stdcall FileExistsA(
	_In_z_ pCStrA pchFileSpec
);

#ifdef UNICODE
	#define FileExists FileExistsW
#else // ANSI
	#define FileExists FileExistsA
#endif


/// <returns>On Success Opens File using 'CreateFileW'</returns>
_COMMON_X_API_ HANDLE _Success_(return != INVALID_HANDLE_VALUE) __stdcall FSCreateFileW(
	_In_z_ pCStrW pchFileSpec,
	_In_ Dword dwDesiredAccess,
	_In_ Dword dwCreationDisposition
);

/// <returns>On Success Opens File using 'CreateFileA'</returns>
_COMMON_X_API_ HANDLE _Success_(return != INVALID_HANDLE_VALUE) __stdcall FSCreateFileA(
	_In_z_ pCStrA pchFileSpec,
	_In_ Dword dwDesiredAccess,
	_In_ Dword dwCreationDisposition
);

#ifdef UNICODE
	#define FSCreateFile FSCreateFileW
#else // ANSI
	#define FSCreateFile FSCreateFileA
#endif

#pragma pack(push, 1)

typedef struct _RGB_ {

	Byte rgbRed;
	Byte rgbGreen;
	Byte rgbBlue;

} RGB, *pRGB;

#pragma pack(pop)

_COMMON_X_API_ _Success_(return == True) Bool __stdcall SaveScreenshot(
	_In_bytecount_(cbRGB) const pVoid pvRGB,
	_In_ Uint32 cbRGB,
	_In_ Int32 Cx,
	_In_ Int32 Cy
);

typedef enum _ESaveType_ {

	/* <Module>\\Storage */
	k_ESaveType_Storage,
	/* <Module>\\Sreenshots */
	k_ESaveType_Sreenshots

} ESaveType, *pSaveType;

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrW __stdcall GetGameSaveFileNameW(
	_In_ HMODULE hModule,
	_In_opt_z_ pCStrW pchFileSpec,
	_In_ ESaveType eSaveType
);

/// <returns>On Success Allocates Memory using 'LocalAlloc'</returns>
_COMMON_X_API_ _Success_(return != NULL) pStrA __stdcall GetGameSaveFileNameA(
	_In_ HMODULE hModule,
	_In_opt_z_ pCStrA pchFileSpec,
	_In_ ESaveType eSaveType
);

#ifdef UNICODE
	#define GetGameSaveFileName GetGameSaveFileNameW
#else // ANSI
	#define GetGameSaveFileName GetGameSaveFileNameA
#endif

_COMMON_X_API_ pCStrW __stdcall GetUserUILanguageW(
	void
);

_COMMON_X_API_ pCStrA __stdcall GetUserUILanguageA(
	void
);

#ifdef UNICODE
	#define GetUserUILanguage GetUserUILanguageW
#else // ANSI
	#define GetUserUILanguage GetUserUILanguageA
#endif

_COMMON_X_API_ Uint32 __stdcall GetGameAppId(
	void
);

_COMMON_X_API_ void __stdcall DebugFuncEntryW(
	_In_z_ pCStrW pchFuncName
);

_COMMON_X_API_ void __stdcall DebugFuncEntryA(
	_In_z_ pCStrA pchFuncName
);

#ifdef UNICODE
	#define DebugFuncEntry DebugFuncEntryW
#else // ANSI
	#define DebugFuncEntry DebugFuncEntryA
#endif

#ifndef NOBRAKE
	#define NOBRAKE
#endif

#ifdef DEBUG
	#ifdef NOBRAKE
		#define DEBUGBREAK(FuncName) if (IsDebuggerPresent()) { \
  DebugFuncEntryA(FuncName); \
 }
	#else // BRAKE
		#define DEBUGBREAK(FuncName) if (IsDebuggerPresent()) { \
  DebugFuncEntryA(FuncName); \
  __debugbreak(); \
 }
	#endif
#else
	#define DEBUGBREAK(FuncName)
#endif

_COMMON_X_API_ void __stdcall DebugOutputW(
	_In_z_ pCStrW pchStr
);

_COMMON_X_API_ void __stdcall DebugOutputA(
	_In_z_ pCStrA pchStr
);

#ifdef UNICODE
	#define DebugOutput DebugOutputW
#else // ANSI
	#define DebugOutput DebugOutputA
#endif

#ifdef DEBUG
	#define DEBUG_OUT(TxT) if (IsDebuggerPresent()) \
  DebugOutputA(TxT)
#else
	#define DEBUG_OUT(TxT)
#endif

#endif // !_COMMON_X_
