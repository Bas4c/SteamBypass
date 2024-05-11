#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
// -----------------------------------------------------------------------------
#include "FreeAPI.Typedef.h"
#include "StrX.h"
// -----------------------------------------------------------------------------

#ifndef _FREE_API_
	#ifdef __cplusplus
		#define _FREE_API_ extern "C"
	#else // !C++
		#define _FREE_API_ extern
	#endif
#endif

#pragma region .data

pStrW g_pchModuleDirectory = NULL;
pStrA g_pchModuleDirectoryUTF8 = NULL;

#pragma endregion

#pragma region internal

_Success_(return != NULL) pStrW __stdcall LoadModuleNameW(
	_In_ HMODULE hModule
);

_FREE_API_ Bool WINAPI DllMain(
	_In_ HINSTANCE hInstance, _In_ DWORD dwReason,
	_In_opt_ LPVOID lpReserved
) {

	if (dwReason == DLL_PROCESS_ATTACH) {

		#ifdef DEBUG
			MessageBoxA(
				HWND_DESKTOP, "FreeAPI Loaded", 
				"Attach Debugger", MB_OK
			);
		#endif

		g_pchModuleDirectory = LoadModuleNameW(hInstance);
		if (g_pchModuleDirectory != NULL) {

			Dword cchCount =
				(Dword)(StrW_Count(g_pchModuleDirectory));

			while (cchCount != 0) {

				if (g_pchModuleDirectory[cchCount - 1] == L'\\') {
					g_pchModuleDirectory[cchCount - 1] = L'\0';
					cchCount--;
					break;
				}

				g_pchModuleDirectory[cchCount - 1] = L'\0';
				cchCount--;

			}

			Int32 nUTF8 = WideCharToMultiByte(
				CP_UTF8, WC_COMPOSITECHECK, (LPWSTR)(g_pchModuleDirectory), -1,
				NULL, 0, NULL, NULL
			);

			if (nUTF8 != 0) {

				g_pchModuleDirectoryUTF8 =
					(pStrA)(LocalAlloc(LPTR, nUTF8));

				if (g_pchModuleDirectoryUTF8 != NULL) {

					WideCharToMultiByte(
						CP_UTF8, WC_COMPOSITECHECK, (LPWSTR)(g_pchModuleDirectory), -1,
						(LPSTR)(g_pchModuleDirectoryUTF8), nUTF8, NULL, NULL
					);

					return TRUE;

				}

			}

			LocalFree(g_pchModuleDirectory);
			g_pchModuleDirectory = NULL;

		}

		return FALSE;

	}

	if (dwReason == DLL_PROCESS_DETACH) {

		if (g_pchModuleDirectory != NULL) {
			LocalFree(g_pchModuleDirectory);
			g_pchModuleDirectory = NULL;
		}

		if (g_pchModuleDirectoryUTF8 != NULL) {
			LocalFree(g_pchModuleDirectoryUTF8);
			g_pchModuleDirectoryUTF8 = NULL;
		}

		return TRUE;

	}

	return TRUE;

}

_Success_(return != NULL) pStrW __stdcall LoadModuleNameW(
	_In_ HMODULE hModule
) {

	Dword nModuleName = MAX_PATH;
	const Dword nMax = Uint32_MAX / sizeof(CharW);

	pStrW pchModuleName = (pStrW)(LocalAlloc(
		LPTR, nModuleName * sizeof(CharW)
	));

	if (pchModuleName == NULL) {
		SetLastError(ERROR_NOT_ENOUGH_MEMORY);
		return NULL;
	}

	Dword nChar = GetModuleFileNameW(
		hModule, ((LPWSTR)(pchModuleName)),
		nModuleName
	);

	while (True) {

		if (nChar != nModuleName) {
			break;
		}

		LocalFree(pchModuleName);

		Dword nFree = nMax - nModuleName;
		if (nFree == 0U) {
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return NULL;
		}

		nModuleName += (nModuleName / 2 > nFree) ?
			nFree : nModuleName / 2;

		pchModuleName = (pStrW)(LocalAlloc(
			LPTR, nModuleName * sizeof(CharW)
		));

		if (pchModuleName == NULL) {
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return NULL;
		}

		nChar = GetModuleFileNameW(
			hModule, ((LPWSTR)(pchModuleName)),
			nModuleName
		);

	}

	if (nChar == 0U) {
		/* LastError is Set By GetModuleFileNameW */
		LocalFree(pchModuleName);
		return NULL;
	}

	SetLastError(ERROR_SUCCESS);
	return pchModuleName;

}

#pragma endregion

// -----------------------------------------------------------------------------
// FreeAPI Functions
// -----------------------------------------------------------------------------

_FREE_API_ Bool __cdecl SteamAPI_Init(
	void
) {

	return True;

}

_FREE_API_ Bool __cdecl SteamAPI_InitSafe(
	void
) {

	return SteamAPI_Init();

}

_FREE_API_ Bool __cdecl SteamAPI_InitAnonymousUser(
	void
) {

	return SteamAPI_Init();

}

_FREE_API_ void __cdecl SteamAPI_Shutdown(
	void
) {

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_IsSteamRunning(
	void
) {

	return True;

}

_FREE_API_ const pStrA __cdecl SteamAPI_GetSteamInstallPath(
	void
) {

	return g_pchModuleDirectoryUTF8;
	
}

_FREE_API_ HSteamPipe __cdecl SteamAPI_GetHSteamPipe(
	void
) {

	return k_HSteamPipe_Client;

}

_FREE_API_ HSteamUser __cdecl SteamAPI_GetHSteamUser(
	void
) {

	return k_HSteamUser_LocalUser;

}

// -----------------------------------------------------------------------------
// CallbackAPI
// -----------------------------------------------------------------------------

_FREE_API_ void __cdecl SteamAPI_SetTryCatchCallbacks(
	Bool bTryCatchCallbacks
) {

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_RestartAppIfNecessary(
	AppId_t AppId
) {

	return False;

}

_FREE_API_ void __cdecl SteamAPI_RegisterCallback(
	void (__cdecl *pCallback) (pVoid pStruct), Int32 iCallback
) {

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_UnregisterCallback(
	void (__cdecl *pCallback) (pVoid pStruct), Int32 iCallback
) {

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_RegisterCallResult(
	void (__cdecl *pCallResult) (pVoid pStruct, Bool bCallResult),
	SteamAPICall_t hSteamAPICall
) {

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_UnregisterCallResult(
	void (__cdecl *pCallResult) (pVoid pStruct, Bool bCallResult),
	SteamAPICall_t hSteamAPICall
) {

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_RunCallbacks(
	void
) {

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// BreakpadAPI Functions
// -----------------------------------------------------------------------------

_FREE_API_ void __cdecl  SteamAPI_SetBreakpadAppID(
	AppId_t AppId
) {

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// pTime: "hh:mm:ss"
// pDate: "Mmm dd yyyy"
// -----------------------------------------------------------------------------
_FREE_API_ void __cdecl SteamAPI_UseBreakpadCrashHandler(
	const pStrA pchVersion, const pStrA pchDate,
	const pStrA pchTime, Bool bFullMemoryDumps,
	pVoid pvUserContext, void (__cdecl *PreMinidumpCallback) (pVoid pvUserContext)
) {

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_ReleaseCurrentThreadMemory(
	void
) {

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// Crash Dump Functions
// -----------------------------------------------------------------------------

_FREE_API_ void __cdecl SteamAPI_WriteMiniDump(
	Uint32 sCode, pVoid pvExceptionInfo,
	Uint32 BuildId
) {

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_SetMiniDumpComment(
	const pStrA pchText
) {

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// FreeAPI Internals
// -----------------------------------------------------------------------------

typedef enum _EServerMode_ {

	k_EServerModeInvalid,
	k_EServerModeNoAuthentication,
	k_EServerModeAuthentication,
	k_EServerModeAuthenticationAndSecure

} EServerMode, *pEServerMode;

typedef struct _SteamContext_ {

	void (*InitContext) (pVoid pvContext);
	SizeOF cCount;
	pVoid pvContext;

} SteamContext, *pSteamContext;

_FREE_API_ pVoid __cdecl SteamInternal_ContextInit(
	pSteamContext pSelf
) {

	if (pSelf == NULL) {
		return NULL;
	}

	pSelf->cCount++;
	pSelf->InitContext(&pSelf->pvContext);

	return &pSelf->pvContext;

}

_FREE_API_ Bool __cdecl SteamInternal_GameServer_Init(
	Uint32 nIP, Uint16 SteamPort,
	Uint16 GamePort, Uint16 QueryPort,
	EServerMode eServerMode, pStrA pVersionString
) {

	return True;

}

_FREE_API_ pVoid __cdecl SteamInternal_CreateInterface(
	const pStrA pchVersion
) {

	if (pchVersion == NULL) {
		return NULL;
	}

	return NULL;

}

_FREE_API_ pVoid __cdecl SteamInternal_FindOrCreateUserInterface(
	HSteamUser hSteamUser, const pStrA pchVersion
) {

	return SteamInternal_CreateInterface(
		pchVersion
	);

}
_FREE_API_ pVoid __cdecl SteamInternal_FindOrCreateGameServerInterface(
	HSteamUser hSteamUser, const pStrA pchVersion
) {

	return SteamInternal_CreateInterface(
		pchVersion
	);

}

// -----------------------------------------------------------------------------
// Manual Callback Functions
// -----------------------------------------------------------------------------

typedef struct _CallbackMsg_t_ {

	Int32 cbParam;
	HSteamUser hSteamUser;
	Int32 iCallback;
	pVoid pbParam;

} CallbackMsg_t, *pCallbackMsg_t;


_FREE_API_ void __cdecl SteamAPI_ManualDispatch_Init(
	void
) {

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_ManualDispatch_RunFrame(
	HSteamPipe hSteamPipe
) {

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_ManualDispatch_GetNextCallback(
	HSteamPipe hSteamPipe, pCallbackMsg_t pCallbackMsg
) {

	return False;

}

_FREE_API_ void __cdecl SteamAPI_ManualDispatch_FreeLastCallback(
	HSteamPipe hSteamPipe
) {

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_ManualDispatch_GetAPICallResult(
	HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall,
	void (__cdecl *CallResult) (pVoid pStruct, Bool bCallResult),
	Int32 iCallback, Int32 iCallbackExpected, pBool pbFailed
) {

	return False;

}

// -----------------------------------------------------------------------------
// Steam Game Server Functions
// -----------------------------------------------------------------------------

_FREE_API_ Bool __cdecl SteamGameServer_Init(
	Uint32 nIP, Uint16 SteamPort,
	Uint16 GamePort, Uint16 QueryPort,
	EServerMode eServerMode, pStrA pVersionString
) {

	return SteamInternal_GameServer_Init(
		nIP, SteamPort,
		GamePort, QueryPort,
		eServerMode, pVersionString
	);

}

_FREE_API_ Bool __cdecl SteamGameServer_InitSafe(
	Uint32 nIP, Uint16 SteamPort,
	Uint16 GamePort, Uint16 QueryPort,
	EServerMode eServerMode, pStrA pVersionString
) {

	return SteamGameServer_Init(
		nIP, SteamPort,
		GamePort, QueryPort,
		eServerMode, pVersionString
	);

}

_FREE_API_ HSteamPipe __cdecl SteamGameServer_GetHSteamPipe(
	void
) {

	return SteamAPI_GetHSteamPipe();

}

_FREE_API_ HSteamUser __cdecl SteamGameServer_GetHSteamUser(
	void
) {

	return SteamAPI_GetHSteamUser();

}

_FREE_API_ Bool __cdecl SteamGameServer_BSecure(
	void
) {

	return True;

}

_FREE_API_ Uint32 __cdecl SteamGameServer_GetIPCCallCount(
	void
) {

	return 0U;

}

_FREE_API_ SteamId_t __cdecl SteamGameServer_GetSteamID(
	void
) {

	return k_SteamId_t_Create(
		k_EUniversePublic, k_EAccountTypeIndividual,
		0xFFFFF, 0xFFFFFFFF
	);

}

_FREE_API_ void __cdecl SteamGameServer_RunCallbacks(
	void
) {

	SteamAPI_RunCallbacks();

}

_FREE_API_ void __cdecl SteamGameServer_Shutdown(
	void
) {

	SteamAPI_Shutdown();

}

// -----------------------------------------------------------------------------
