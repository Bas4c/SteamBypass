#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <new>
// -----------------------------------------------------------------------------
#include "FreeAPI.Typedef.h"
#include "CommonX.h"
#include "StrX.h"
// -----------------------------------------------------------------------------

#include "IFreeAPI\SteamClient.h"

#ifndef _FREE_API_
	#ifdef __cplusplus
		#define _FREE_API_ extern "C"
	#else // !C++
		#define _FREE_API_ extern
	#endif
#endif

#pragma region .data

pSteamClient g_SteamClientGameServer = NULL;

pStrW g_pchModuleDirectory = NULL;
pStrA g_pchModuleDirectoryUTF8 = NULL;

#pragma endregion

#pragma region internal

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

		g_pchModuleDirectory =
			LoadModuleNameW(hInstance, True);

		if (g_pchModuleDirectory != NULL) {

			g_pchModuleDirectoryUTF8 =
				WideCharToMultiByteAlloc(g_pchModuleDirectory);

			if (g_pchModuleDirectoryUTF8 != NULL) {

				pVoid pMemory = (pVoid)(HeapAlloc(
					GetProcessHeap(), HEAP_ZERO_MEMORY,
					sizeof(SteamClient)
				));

				if (pMemory != NULL) {

					try {

						pSteamClient pObject = new (pMemory) SteamClient();

						if (pObject == pMemory) {
							g_SteamClientGameServer = pObject;
							return TRUE;
						} else {
							pObject->~_SteamClient_();
						}

					} catch (...) {

					}

					HeapFree(
						GetProcessHeap(), 0U,
						pMemory
					);

				}

				LocalFree(g_pchModuleDirectoryUTF8);
				g_pchModuleDirectoryUTF8 = NULL;

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

		if (g_SteamClientGameServer != NULL) {

			g_SteamClientGameServer->~_SteamClient_();

			HeapFree(
				GetProcessHeap(), 0U,
				(pVoid)(g_SteamClientGameServer)
			);

			g_SteamClientGameServer = NULL;

		}

		return TRUE;

	}

	return TRUE;

}

#pragma endregion

// -----------------------------------------------------------------------------
// FreeAPI Functions
// -----------------------------------------------------------------------------

_FREE_API_ Bool __cdecl SteamAPI_Init(
	void
) {
	DEBUGBREAK("SteamAPI_Init");

	return True;

}

_FREE_API_ Bool __cdecl SteamAPI_InitSafe(
	void
) {
	DEBUGBREAK("SteamAPI_InitSafe");

	return SteamAPI_Init();

}

_FREE_API_ Bool __cdecl SteamAPI_InitAnonymousUser(
	void
) {
	DEBUGBREAK("SteamAPI_InitAnonymousUser");

	return SteamAPI_Init();

}

_FREE_API_ void __cdecl SteamAPI_Shutdown(
	void
) {
	DEBUGBREAK("SteamAPI_Shutdown");

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_IsSteamRunning(
	void
) {
	DEBUGBREAK("SteamAPI_IsSteamRunning");

	return True;

}

_FREE_API_ pCStrA __cdecl SteamAPI_GetSteamInstallPath(
	void
) {
	DEBUGBREAK("SteamAPI_GetSteamInstallPath");

	return g_pchModuleDirectoryUTF8;
	
}

_FREE_API_ HSteamPipe __cdecl SteamAPI_GetHSteamPipe(
	void
) {
	DEBUGBREAK("SteamAPI_GetHSteamPipe");

	return k_HSteamPipe_Client;

}

_FREE_API_ HSteamUser __cdecl SteamAPI_GetHSteamUser(
	void
) {
	DEBUGBREAK("SteamAPI_GetHSteamUser");

	return k_HSteamUser_LocalUser;

}

// -----------------------------------------------------------------------------
// CallbackAPI
// -----------------------------------------------------------------------------

_FREE_API_ void __cdecl SteamAPI_SetTryCatchCallbacks(
	Bool bTryCatchCallbacks
) {
	DEBUGBREAK("SteamAPI_SetTryCatchCallbacks");

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_RestartAppIfNecessary(
	AppId_t AppId
) {
	DEBUGBREAK("SteamAPI_RestartAppIfNecessary");

	return False;

}

_FREE_API_ void __cdecl SteamAPI_RegisterCallback(
	void (__cdecl *pCallback) (pVoid pStruct), Int32 iCallback
) {
	DEBUGBREAK("SteamAPI_RegisterCallback");

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_UnregisterCallback(
	void (__cdecl *pCallback) (pVoid pStruct), Int32 iCallback
) {
	DEBUGBREAK("SteamAPI_UnregisterCallback");

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_RegisterCallResult(
	void (__cdecl *pCallResult) (pVoid pStruct, Bool bCallResult),
	SteamAPICall_t hSteamAPICall
) {
	DEBUGBREAK("SteamAPI_RegisterCallResult");

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_UnregisterCallResult(
	void (__cdecl *pCallResult) (pVoid pStruct, Bool bCallResult),
	SteamAPICall_t hSteamAPICall
) {
	DEBUGBREAK("SteamAPI_UnregisterCallResult");

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_RunCallbacks(
	void
) {
	DEBUGBREAK("SteamAPI_RunCallbacks");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// BreakpadAPI Functions
// -----------------------------------------------------------------------------

_FREE_API_ void __cdecl  SteamAPI_SetBreakpadAppID(
	AppId_t AppId
) {
	DEBUGBREAK("SteamAPI_SetBreakpadAppID");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// pTime: "hh:mm:ss"
// pDate: "Mmm dd yyyy"
// -----------------------------------------------------------------------------
_FREE_API_ void __cdecl SteamAPI_UseBreakpadCrashHandler(
	pCStrA pchVersion, pCStrA pchDate,
	pCStrA pchTime, Bool bFullMemoryDumps,
	pVoid pvUserContext, void (__cdecl *PreMinidumpCallback) (pVoid pvUserContext)
) {
	DEBUGBREAK("SteamAPI_UseBreakpadCrashHandler");

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_ReleaseCurrentThreadMemory(
	void
) {
	DEBUGBREAK("SteamAPI_ReleaseCurrentThreadMemory");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// Crash Dump Functions
// -----------------------------------------------------------------------------

_FREE_API_ void __cdecl SteamAPI_WriteMiniDump(
	Uint32 sCode, pVoid pvExceptionInfo,
	Uint32 BuildId
) {
	DEBUGBREAK("SteamAPI_WriteMiniDump");

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_SetMiniDumpComment(
	pCStrA pchText
) {
	DEBUGBREAK("SteamAPI_SetMiniDumpComment");

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
	DEBUGBREAK("SteamInternal_ContextInit");

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
	DEBUGBREAK("SteamInternal_GameServer_Init");

	return True;

}

_FREE_API_ pVoid __cdecl SteamInternal_CreateInterface(
	pCStrA pchVersion
) {
	DEBUGBREAK("SteamInternal_CreateInterface");

	if (pchVersion == NULL) {
		return NULL;
	}

	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient007"), True))
		return (pVoid)((IpSteamClient007)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient008"), True))
		return (pVoid)((IpSteamClient008)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient009"), True))
		return (pVoid)((IpSteamClient009)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient010"), True))
		return (pVoid)((IpSteamClient010)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient011"), True))
		return (pVoid)((IpSteamClient011)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient012"), True))
		return (pVoid)((IpSteamClient012)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient013"), True))
		return (pVoid)((IpSteamClient013)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient014"), True))
		return (pVoid)((IpSteamClient014)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient015"), True))
		return (pVoid)((IpSteamClient015)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient016"), True))
		return (pVoid)((IpSteamClient016)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient017"), True))
		return (pVoid)((IpSteamClient017)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient018"), True))
		return (pVoid)((IpSteamClient018)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)("SteamClient019"), True))
		return (pVoid)((IpSteamClient019)(g_SteamClientGameServer));
	if (StrA_Cmp(pchVersion, (pCStrA)(STEAMCLIENT_INTERFACE_VERSION), True))
		return (pVoid)((IpSteamClient)(g_SteamClientGameServer));

	return g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser, k_HSteamPipe_Client,
		pchVersion
	);

}

_FREE_API_ pVoid __cdecl SteamInternal_FindOrCreateUserInterface(
	HSteamUser hSteamUser, pCStrA pchVersion
) {
	DEBUGBREAK("SteamInternal_FindOrCreateUserInterface");

	return SteamInternal_CreateInterface(
		pchVersion
	);

}
_FREE_API_ pVoid __cdecl SteamInternal_FindOrCreateGameServerInterface(
	HSteamUser hSteamUser, pCStrA pchVersion
) {
	DEBUGBREAK("SteamInternal_FindOrCreateGameServerInterface");

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
	DEBUGBREAK("SteamAPI_ManualDispatch_Init");

	/* Empty Function */

}

_FREE_API_ void __cdecl SteamAPI_ManualDispatch_RunFrame(
	HSteamPipe hSteamPipe
) {
	DEBUGBREAK("SteamAPI_ManualDispatch_RunFrame");

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_ManualDispatch_GetNextCallback(
	HSteamPipe hSteamPipe, pCallbackMsg_t pCallbackMsg
) {
	DEBUGBREAK("SteamAPI_ManualDispatch_GetNextCallback");

	return False;

}

_FREE_API_ void __cdecl SteamAPI_ManualDispatch_FreeLastCallback(
	HSteamPipe hSteamPipe
) {
	DEBUGBREAK("SteamAPI_ManualDispatch_FreeLastCallback");

	/* Empty Function */

}

_FREE_API_ Bool __cdecl SteamAPI_ManualDispatch_GetAPICallResult(
	HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall,
	void (__cdecl *CallResult) (pVoid pStruct, Bool bCallResult),
	Int32 iCallback, Int32 iCallbackExpected, pBool pbFailed
) {
	DEBUGBREAK("SteamAPI_ManualDispatch_GetAPICallResult");

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
	DEBUGBREAK("SteamGameServer_Init");

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
	DEBUGBREAK("SteamGameServer_InitSafe");

	return SteamGameServer_Init(
		nIP, SteamPort,
		GamePort, QueryPort,
		eServerMode, pVersionString
	);

}

_FREE_API_ HSteamPipe __cdecl SteamGameServer_GetHSteamPipe(
	void
) {
	DEBUGBREAK("SteamGameServer_GetHSteamPipe");

	return SteamAPI_GetHSteamPipe();

}

_FREE_API_ HSteamUser __cdecl SteamGameServer_GetHSteamUser(
	void
) {
	DEBUGBREAK("SteamGameServer_GetHSteamUser");

	return SteamAPI_GetHSteamUser();

}

_FREE_API_ Bool __cdecl SteamGameServer_BSecure(
	void
) {
	DEBUGBREAK("SteamGameServer_BSecure");

	return True;

}

_FREE_API_ Uint32 __cdecl SteamGameServer_GetIPCCallCount(
	void
) {
	DEBUGBREAK("SteamGameServer_GetIPCCallCount");

	return 0U;

}

_FREE_API_ SteamId_t __cdecl SteamGameServer_GetSteamID(
	void
) {
	DEBUGBREAK("SteamGameServer_GetSteamID");

	return k_SteamId_t_LocalUser;

}

_FREE_API_ void __cdecl SteamGameServer_RunCallbacks(
	void
) {
	DEBUGBREAK("SteamGameServer_RunCallbacks");

	SteamAPI_RunCallbacks();

}

_FREE_API_ void __cdecl SteamGameServer_Shutdown(
	void
) {
	DEBUGBREAK("SteamGameServer_Shutdown");

	SteamAPI_Shutdown();

}

// -----------------------------------------------------------------------------
