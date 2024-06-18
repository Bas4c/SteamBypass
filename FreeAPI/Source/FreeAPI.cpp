#pragma comment(linker, \
	"\"/manifestdependency:type='win32' \
	name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
	processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"" \
)

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

Bool g_bDllLoaded = False;

/* Global SteamClient Pointer */
IpSteamClient g_pSteamClientGameServer = NULL;
/* Internal SteamClient Pointer */
pSteamClient g_SteamClientGameServer = NULL;

pStrW g_pchModuleDirectory = NULL;
pStrA g_pchModuleDirectoryUTF8 = NULL;

CharA g_chString[1024] = { 0 };
pSteamAPI_VerT g_SteamAPI_VerT = NULL;

#pragma endregion

_FREE_API_ pVoid _S_CALL_ SteamInternal_CreateInterface(pCStrA pchVersion);

#pragma region internal

_FREE_API_ Bool WINAPI DllMain(
	_In_ HINSTANCE hInstance, _In_ DWORD dwReason,
	_In_opt_ LPVOID lpReserved
) {

	if (dwReason == DLL_PROCESS_ATTACH) {

		if (g_bDllLoaded == True) {
			
			DEBUGBREAK("DllMain:EntryPoint");
			DEBUG_OUT("DLL_PROCESS_ATTACH\r\n\t\tAlready Loaded == True");
			return TRUE;
			
		} else {

			#ifdef DEBUG
			MessageBoxA(
				HWND_DESKTOP, "FreeAPI Loaded",
				"Attach Debugger", MB_OK
			);
			#endif
			
			DEBUGBREAK("DllMain:EntryPoint");
			DEBUG_OUT("DLL_PROCESS_ATTACH\r\n\t\tAlready Loaded == False");
			
		}

		g_pchModuleDirectory =
			LoadModuleNameW(hInstance, True);

		if (g_pchModuleDirectory != NULL) {

			g_pchModuleDirectoryUTF8 =
				WideCharToMultiByteAlloc(g_pchModuleDirectory);

			if (g_pchModuleDirectoryUTF8 != NULL) {

				g_SteamAPI_VerT = (pSteamAPI_VerT)(HeapAlloc(
					GetProcessHeap(), HEAP_ZERO_MEMORY,
					sizeof(SteamAPI_VerT)
				));

				if (g_SteamAPI_VerT != NULL) {

					if (SteamAPI_VerT_Construct(g_SteamAPI_VerT)) {

						pVoid pMemory = (pVoid)(HeapAlloc(
							GetProcessHeap(), HEAP_ZERO_MEMORY,
							sizeof(SteamClient)
						));

						if (pMemory != NULL) {

							try {

								pSteamClient pObject = new (pMemory) SteamClient();

								if (pObject == pMemory) {
									g_SteamClientGameServer = pObject;
									g_pSteamClientGameServer =
										(IpSteamClient)(SteamInternal_CreateInterface(g_SteamAPI_VerT->chSteamClient));
									g_bDllLoaded = True;
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

					}

					HeapFree(
						GetProcessHeap(), 0U,
						g_SteamAPI_VerT
					);

					g_SteamAPI_VerT = NULL;

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

		DEBUGBREAK("DllMain:EntryPoint");
		DEBUG_OUT("DLL_PROCESS_DETACH");

		/* Process is Terminating Forcefully */
		if (lpReserved != NULL) {
			return TRUE;
		}

		if (g_pchModuleDirectory != NULL) {
			LocalFree(g_pchModuleDirectory);
			g_pchModuleDirectory = NULL;
		}

		if (g_pchModuleDirectoryUTF8 != NULL) {
			LocalFree(g_pchModuleDirectoryUTF8);
			g_pchModuleDirectoryUTF8 = NULL;
		}

		if (g_SteamAPI_VerT != NULL) {

			HeapFree(
				GetProcessHeap(), 0U,
				g_SteamAPI_VerT
			);

			g_SteamAPI_VerT = NULL;

		}

		if (g_pSteamClientGameServer != NULL) {
			g_pSteamClientGameServer = NULL;
		}

		if (g_SteamClientGameServer != NULL) {

			g_SteamClientGameServer->~_SteamClient_();

			HeapFree(
				GetProcessHeap(), 0U,
				(pVoid)(g_SteamClientGameServer)
			);

			g_SteamClientGameServer = NULL;

		}

		g_bDllLoaded = False;

		return TRUE;

	}

	return TRUE;

}

#pragma endregion

// -----------------------------------------------------------------------------
// FreeAPI Functions
// -----------------------------------------------------------------------------

_FREE_API_ Bool _S_CALL_ SteamAPI_Init() {
	DEBUGBREAK("SteamAPI_Init");

	return True;

}

_FREE_API_ Bool _S_CALL_ SteamAPI_InitSafe() {
	DEBUGBREAK("SteamAPI_InitSafe");

	return SteamAPI_Init();

}

_FREE_API_ Bool _S_CALL_ SteamAPI_InitAnonymousUser() {
	DEBUGBREAK("SteamAPI_InitAnonymousUser");

	return SteamAPI_Init();

}

_FREE_API_ void _S_CALL_ SteamAPI_Shutdown() {
	DEBUGBREAK("SteamAPI_Shutdown");

	/* Empty Function */

}

_FREE_API_ Bool _S_CALL_ SteamAPI_IsSteamRunning() {
	DEBUGBREAK("SteamAPI_IsSteamRunning");

	return True;

}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_GetSteamInstallPath() {
	DEBUGBREAK("SteamAPI_GetSteamInstallPath");

	return g_pchModuleDirectoryUTF8;

}

_FREE_API_ HSteamPipe _S_CALL_ SteamAPI_GetHSteamPipe() {
	DEBUGBREAK("SteamAPI_GetHSteamPipe");

	return k_HSteamPipe_Client;

}

_FREE_API_ HSteamUser _S_CALL_ SteamAPI_GetHSteamUser() {
	DEBUGBREAK("SteamAPI_GetHSteamUser");

	return k_HSteamUser_LocalUser;

}

// -----------------------------------------------------------------------------
// CallbackAPI
// -----------------------------------------------------------------------------

_FREE_API_ void _S_CALL_ SteamAPI_SetTryCatchCallbacks() {
	DEBUGBREAK("SteamAPI_SetTryCatchCallbacks");

	/* Empty Function */

}

_FREE_API_ Bool SteamAPI_RestartApp(AppId_t AppId) {
	DEBUGBREAK("SteamAPI_RestartApp");

	return False;

}

_FREE_API_ Bool _S_CALL_ SteamAPI_RestartAppIfNecessary() {
	DEBUGBREAK("SteamAPI_RestartAppIfNecessary");

	return False;

}

_FREE_API_ void _S_CALL_ SteamAPI_RegisterCallback(
	void (_S_CALL_ *pCallback) (pVoid pStruct),
	Int32 iCallback) {
	DEBUGBREAK("SteamAPI_RegisterCallback");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ SteamAPI_UnregisterCallback(
	void (_S_CALL_ *pCallback) (pVoid pStruct),
	Int32 iCallback) {
	DEBUGBREAK("SteamAPI_UnregisterCallback");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ SteamAPI_RegisterCallResult(
	void (_S_CALL_ *pCallResult) (pVoid pStruct, Bool bCallResult),
	SteamAPICall_t hSteamAPICall) {
	DEBUGBREAK("SteamAPI_RegisterCallResult");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ SteamAPI_UnregisterCallResult(
	void (_S_CALL_ *pCallResult) (pVoid pStruct, Bool bCallResult),
	SteamAPICall_t hSteamAPICall) {
	DEBUGBREAK("SteamAPI_UnregisterCallResult");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ SteamAPI_RunCallbacks() {
	DEBUGBREAK("SteamAPI_RunCallbacks");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// VR Functions
// -----------------------------------------------------------------------------

_FREE_API_ pVoid _S_CALL_ VR_Init(pInt32 pError, Int32 eType) {
	DEBUGBREAK("VR_Init");

	if (pError != NULL) {
		*pError = 108;
	}

	return NULL;

}

_FREE_API_ pVoid _S_CALL_ VR_GetGenericInterface(pCStrA pchInterfaceVersion, pInt32 peError) {
	DEBUGBREAK("VR_GetGenericInterface");
	
	return NULL;

}

_FREE_API_ pCStrA _S_CALL_ VR_GetStringForHmdError(Int32 Error) {
	DEBUGBREAK("VR_GetStringForHmdError");
	
	if (Error == 108) {
		return (pCStrA)("HmdError_Init_HmdNotFound");
	}

	return (pCStrA)("");

}

_FREE_API_ Bool _S_CALL_ VR_IsHmdPresent() {
	DEBUGBREAK("VR_IsHmdPresent");

	return False;

}

_FREE_API_ void _S_CALL_ VR_Shutdown() {
	DEBUGBREAK("VR_Shutdown");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// BreakpadAPI Functions
// -----------------------------------------------------------------------------

_FREE_API_ void _S_CALL_  SteamAPI_SetBreakpadAppID(AppId_t AppId) {
	DEBUGBREAK("SteamAPI_SetBreakpadAppID");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// pTime: "hh:mm:ss"
// pDate: "Mmm dd yyyy"
// -----------------------------------------------------------------------------
_FREE_API_ void _S_CALL_ SteamAPI_UseBreakpadCrashHandler(
	pCStrA pchVersion, pCStrA pchDate,
	pCStrA pchTime, Bool bFullMemoryDumps,
	pVoid pvUserContext, void (_S_CALL_ *PreMinidumpCallback) (pVoid pvUserContext)) {
	DEBUGBREAK("SteamAPI_UseBreakpadCrashHandler");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ SteamAPI_ReleaseCurrentThreadMemory() {
	DEBUGBREAK("SteamAPI_ReleaseCurrentThreadMemory");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// Crash Dump Functions
// -----------------------------------------------------------------------------

_FREE_API_ void _S_CALL_ SteamAPI_WriteMiniDump(
	Uint32 sCode, pVoid pvExceptionInfo,
	Uint32 BuildId) {
	DEBUGBREAK("SteamAPI_WriteMiniDump");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ SteamAPI_SetMiniDumpComment(pCStrA pchText) {
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

_FREE_API_ pVoid _S_CALL_ SteamInternal_ContextInit(pSteamContext pSelf) {
	DEBUGBREAK("SteamInternal_ContextInit");

	if (pSelf == NULL) {
		return NULL;
	}

	pSelf->cCount++;
	pSelf->InitContext(&pSelf->pvContext);

	return &pSelf->pvContext;

}

_FREE_API_ Bool _S_CALL_ SteamInternal_GameServer_Init(
	Uint32 nIP, Uint16 SteamPort, Uint16 GamePort, Uint16 QueryPort,
	EServerMode eServerMode, pStrA pVersionString) {
	DEBUGBREAK("SteamInternal_GameServer_Init");

	return True;

}

_FREE_API_ pVoid _S_CALL_ SteamInternal_CreateInterface(pCStrA pchVersion) {
	DEBUGBREAK("SteamInternal_CreateInterface");

	if (pchVersion == NULL) {
		return NULL;
	}

	DEBUG_OUT(pchVersion);

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

_FREE_API_ pVoid _S_CALL_ SteamGameServerInternal_CreateInterface(pCStrA pchVersion) {
	DEBUGBREAK("SteamGameServerInternal_CreateInterface");

	return SteamInternal_CreateInterface(pchVersion);

}

_FREE_API_ pVoid _S_CALL_ SteamInternal_FindOrCreateUserInterface(
	HSteamUser hSteamUser,
	pCStrA pchVersion) {
	DEBUGBREAK("SteamInternal_FindOrCreateUserInterface");

	return SteamInternal_CreateInterface(
		pchVersion
	);

}
_FREE_API_ pVoid _S_CALL_ SteamInternal_FindOrCreateGameServerInterface(
	HSteamUser hSteamUser,
	pCStrA pchVersion) {
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

_FREE_API_ void _S_CALL_ SteamAPI_ManualDispatch_Init() {
	DEBUGBREAK("SteamAPI_ManualDispatch_Init");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ SteamAPI_ManualDispatch_RunFrame(HSteamPipe hSteamPipe) {
	DEBUGBREAK("SteamAPI_ManualDispatch_RunFrame");

	/* Empty Function */

}

_FREE_API_ Bool _S_CALL_ SteamAPI_ManualDispatch_GetNextCallback(
	HSteamPipe hSteamPipe,
	pCallbackMsg_t pCallbackMsg) {
	DEBUGBREAK("SteamAPI_ManualDispatch_GetNextCallback");

	return False;

}

_FREE_API_ void _S_CALL_ SteamAPI_ManualDispatch_FreeLastCallback(HSteamPipe hSteamPipe) {
	DEBUGBREAK("SteamAPI_ManualDispatch_FreeLastCallback");

	/* Empty Function */

}

_FREE_API_ Bool _S_CALL_ SteamAPI_ManualDispatch_GetAPICallResult(
	HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall,
	void (_S_CALL_ *CallResult) (pVoid pStruct, Bool bCallResult),
	Int32 iCallback, Int32 iCallbackExpected, pBool pbFailed) {
	DEBUGBREAK("SteamAPI_ManualDispatch_GetAPICallResult");

	return False;

}

// -----------------------------------------------------------------------------
// Steam Game Server Functions
// -----------------------------------------------------------------------------

_FREE_API_ Bool _S_CALL_ SteamGameServer_Init(
	Uint32 nIP, Uint16 SteamPort, Uint16 GamePort, Uint16 QueryPort,
	EServerMode eServerMode, pStrA pVersionString) {
	DEBUGBREAK("SteamGameServer_Init");

	return SteamInternal_GameServer_Init(
		nIP, SteamPort,
		GamePort, QueryPort,
		eServerMode, pVersionString
	);

}

_FREE_API_ Bool _S_CALL_ SteamGameServer_InitSafe(
	Uint32 nIP, Uint16 SteamPort, Uint16 GamePort, Uint16 QueryPort,
	EServerMode eServerMode, pStrA pVersionString) {
	DEBUGBREAK("SteamGameServer_InitSafe");

	return SteamGameServer_Init(
		nIP, SteamPort,
		GamePort, QueryPort,
		eServerMode, pVersionString
	);

}

_FREE_API_ HSteamPipe _S_CALL_ SteamGameServer_GetHSteamPipe() {
	DEBUGBREAK("SteamGameServer_GetHSteamPipe");

	return SteamAPI_GetHSteamPipe();

}

_FREE_API_ HSteamUser _S_CALL_ SteamGameServer_GetHSteamUser() {
	DEBUGBREAK("SteamGameServer_GetHSteamUser");

	return SteamAPI_GetHSteamUser();

}

_FREE_API_ Bool _S_CALL_ SteamGameServer_BSecure() {
	DEBUGBREAK("SteamGameServer_BSecure");

	return True;

}

_FREE_API_ Uint32 _S_CALL_ SteamGameServer_GetIPCCallCount() {
	DEBUGBREAK("SteamGameServer_GetIPCCallCount");

	return 0U;

}

_FREE_API_ SteamId_t _S_CALL_ SteamGameServer_GetSteamID() {
	DEBUGBREAK("SteamGameServer_GetSteamID");

	return SteamId_t{ k_SteamId_t_LocalUser };

}

_FREE_API_ void _S_CALL_ SteamGameServer_RunCallbacks() {
	DEBUGBREAK("SteamGameServer_RunCallbacks");

	SteamAPI_RunCallbacks();

}

_FREE_API_ void _S_CALL_ SteamGameServer_Shutdown() {
	DEBUGBREAK("SteamGameServer_Shutdown");

	SteamAPI_Shutdown();

}


// -----------------------------------------------------------------------------
// SteamClient Internal Functions
// -----------------------------------------------------------------------------

_FREE_API_ void _S_CALL_ Steam_RunCallbacks(HSteamPipe hSteamPipe, Bool bGameServerCallbacks) {
	DEBUGBREAK("Steam_RunCallbacks");

	SteamAPI_RunCallbacks();

	if (bGameServerCallbacks == True) {
		SteamGameServer_RunCallbacks();
	}

}

_FREE_API_ void _S_CALL_ Steam_RegisterInterfaceFuncs(pVoid hModule) {
	DEBUGBREAK("Steam_RegisterInterfaceFuncs");

	/* Empty Function */

}

_FREE_API_ HSteamUser _S_CALL_ Steam_GetHSteamUserCurrent() {
	DEBUGBREAK("Steam_GetHSteamUserCurrent");
	
	return SteamAPI_GetHSteamUser();

}

_FREE_API_ Bool _S_CALL_ Steam_BGetCallback(HSteamPipe hSteamPipe, pCallbackMsg_t pCallbackMsg) {
	DEBUGBREAK("Steam_BGetCallback");

	SteamAPI_ManualDispatch_Init();
	return SteamAPI_ManualDispatch_GetNextCallback(hSteamPipe, pCallbackMsg);

}

_FREE_API_ void _S_CALL_ Steam_FreeLastCallback(HSteamPipe hSteamPipe) {
	DEBUGBREAK("Steam_FreeLastCallback");

	return SteamAPI_ManualDispatch_FreeLastCallback(hSteamPipe);

}

_FREE_API_ Bool _S_CALL_ Steam_GetAPICallResult(HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall, void (_S_CALL_ *CallResult) (pVoid pStruct, Bool bCallResult), Int32 cbCallback, Int32 iCallbackExpected, pBool pbFailed) {
	DEBUGBREAK("Steam_GetAPICallResult");

	return SteamAPI_ManualDispatch_GetAPICallResult(hSteamPipe, hSteamAPICall, CallResult, cbCallback, iCallbackExpected, pbFailed);

}

_FREE_API_ pVoid _S_CALL_ CreateInterface(pCStrA pchVersion, pInt32 pReturnCode) {
	DEBUGBREAK("CreateInterface");

	return SteamInternal_CreateInterface(pchVersion);

}

_FREE_API_ void _S_CALL_ Breakpad_SteamMiniDumpInit(Uint32 arg1, pCStrA arg2, pCStrA arg3) {
	DEBUGBREAK("Breakpad_SteamMiniDumpInit");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Breakpad_SteamSetAppID(AppId_t iAppId) {
	DEBUGBREAK("Breakpad_SteamSetAppID");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Breakpad_SteamSetSteamID(SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("Breakpad_SteamSetSteamID");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Breakpad_SteamWriteMiniDumpSetComment(pCStrA pchMsg) {
	DEBUGBREAK("Breakpad_SteamWriteMiniDumpSetComment");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId(Int32 arg1, Int32 arg2) {
	DEBUGBREAK("Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId");

	/* Empty Function */

}

_FREE_API_ Bool _S_CALL_ Steam_BConnected(HSteamUser hSteamUser, HSteamPipe hSteamPipe) {
	DEBUGBREAK("Steam_BConnected");
	
	return True;

}

_FREE_API_ Bool _S_CALL_ Steam_BLoggedOn(HSteamUser hSteamUser, HSteamPipe hSteamPipe) {
	DEBUGBREAK("Steam_BLoggedOn");

	return True;

}

_FREE_API_ Bool _S_CALL_ Steam_BReleaseSteamPipe(HSteamPipe hSteamPipe) {
	DEBUGBREAK("Steam_BReleaseSteamPipe");

	return False;

}

_FREE_API_ HSteamUser _S_CALL_ Steam_ConnectToGlobalUser(HSteamPipe hSteamPipe) {
	DEBUGBREAK("Steam_ConnectToGlobalUser");
	
	return k_HSteamUser_Invalid;

}

_FREE_API_ HSteamUser _S_CALL_ Steam_CreateGlobalUser(pHSteamPipe phSteamPipe) {
	DEBUGBREAK("Steam_CreateGlobalUser");

	return k_HSteamUser_Invalid;

}

_FREE_API_ HSteamUser _S_CALL_ Steam_CreateLocalUser(pHSteamPipe phSteamPipe, EAccountType eAccountType) {
	DEBUGBREAK("Steam_CreateLocalUser");

	if (phSteamPipe != NULL) {
		*phSteamPipe = k_HSteamPipe_Client;
	}

	return k_HSteamUser_LocalUser;

}

_FREE_API_ HSteamPipe _S_CALL_ Steam_CreateSteamPipe() {
	DEBUGBREAK("Steam_CreateSteamPipe");
	
	return k_HSteamPipe_Client;

}

_FREE_API_ Bool _S_CALL_ Steam_GSBLoggedOn(pVoid phSteamHandle) {
	DEBUGBREAK("Steam_GSBLoggedOn");
	
	return False;

}

_FREE_API_ Bool _S_CALL_ Steam_GSBSecure(pVoid phSteamHandle) {
	DEBUGBREAK("Steam_GSBSecure");

	return False;

}

_FREE_API_ Bool _S_CALL_ Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient(pVoid phSteamHandle, pVoid pvEncryptionKey, pUint32 pcbEncryptionKey, Uint32 cbEncryptionKey) {
	DEBUGBREAK("Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient");

	return False;

}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ Steam_GSGetSteamID() {
	DEBUGBREAK("Steam_GSGetSteamID");

	return k_SteamId_t_Invalid;

}

_FREE_API_ void _S_CALL_ Steam_GSLogOff(pVoid phSteamHandle) {
	DEBUGBREAK("Steam_GSLogOff");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Steam_GSLogOn(pVoid phSteamHandle) {
	DEBUGBREAK("Steam_GSLogOn");

	/* Empty Function */

}

_FREE_API_ Bool _S_CALL_ Steam_GSRemoveUserConnect(pVoid phSteamHandle, Uint32 UserId) {
	DEBUGBREAK("Steam_GSRemoveUserConnect");

	return False;

}

_FREE_API_ Bool _S_CALL_ Steam_GSSendSteam2UserConnect(pVoid phSteamHandle, Uint32 UserId, pCVoid pvRawKey, Uint32 cbKey, Uint32 nIPPublic, Uint16 Port, pCVoid pvCookie, Uint32 cbCookie) {
	DEBUGBREAK("Steam_GSSendSteam2UserConnect");

	return False;

}

_FREE_API_ Bool _S_CALL_ Steam_GSSendSteam3UserConnect(pVoid phSteamHandle, SteamId_t_Uint64 SteamId, Uint32 nIPPublic, pCVoid pvCookie, Uint32 cbCookie) {
	DEBUGBREAK("Steam_GSSendSteam3UserConnect");

	return False;

}

_FREE_API_ Bool _S_CALL_ Steam_GSSendUserDisconnect(pVoid phSteamHandle, SteamId_t_Uint64 SteamId, Uint32 UserId) {
	DEBUGBREAK("Steam_GSSendUserDisconnect");

	return False;

}

_FREE_API_ Bool _S_CALL_ Steam_GSSendUserStatusResponse(pVoid phSteamHandle, SteamId_t_Uint64 SteamId, Int32 nSecondsConnected, Int32 nSecondsSinceLast) {
	DEBUGBREAK("Steam_GSSendUserStatusResponse");

	return False;

}

_FREE_API_ Bool _S_CALL_ Steam_GSSetServerType(pVoid phSteamHandle, Int32 iAppIdServed, Uint32 nServerFlags, Uint32 nGameIP, Uint32 GamePort, pCStrA pchGameDirectory, pCStrA pchVersion) {
	DEBUGBREAK("Steam_GSSetServerType");

	return False;

}

_FREE_API_ void _S_CALL_ Steam_GSSetSpawnCount(pVoid phSteamHandle, Uint32 cSpawn) {
	DEBUGBREAK("Steam_GSSetSpawnCount");

	/* Empty Function */

}

_FREE_API_ Bool _S_CALL_ Steam_GSUpdateStatus(pVoid phSteamHandle, Int32 cPlayers, Int32 cPlayersMax, Int32 cBotPlayers, pCStrA pchServerName, pCStrA pchMapName) {
	DEBUGBREAK("Steam_GSUpdateStatus");

	return False;

}

_FREE_API_ pVoid _S_CALL_ Steam_GetGSHandle(HSteamUser hSteamUser, HSteamPipe hSteamPipe) {
	DEBUGBREAK("Steam_GetGSHandle");

	return NULL;

}

_FREE_API_ Int32 _S_CALL_ Steam_InitiateGameConnection(HSteamUser hSteamUser, HSteamPipe hSteamPipe, pVoid pvBlob, Int32 cbMaxBlob, Uint64 steamID, Int32 iGameAppId, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) {
	DEBUGBREAK("Steam_InitiateGameConnection");

	return 0;

}

_FREE_API_ void _S_CALL_ Steam_LogOff(HSteamUser hSteamUser, HSteamPipe hSteamPipe) {
	DEBUGBREAK("Steam_LogOff");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Steam_LogOn(HSteamUser hSteamUser, HSteamPipe hSteamPipe, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("Steam_LogOn");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Steam_ReleaseThreadLocalMemory(Bool bThreadExit) {
	DEBUGBREAK("Steam_ReleaseThreadLocalMemory");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Steam_ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hSteamUser) {
	DEBUGBREAK("Steam_ReleaseUser");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Steam_SetLocalIPBinding(Uint32 nIP, Uint16 LocalPort) {
	DEBUGBREAK("Steam_SetLocalIPBinding");

	/* Empty Function */

}

_FREE_API_ void _S_CALL_ Steam_TerminateGameConnection(HSteamUser hSteamUser, HSteamPipe hSteamPipe, Uint32 nIPServer, Uint16 PortServer) {
	DEBUGBREAK("Steam_TerminateGameConnection");

	/* Empty Function */

}

// -----------------------------------------------------------------------------
// FreeAPI Accessor Functions
// -----------------------------------------------------------------------------

#pragma region FreeAPI.Accessor

_FREE_API_ IpSteamAppList _S_CALL_ SteamAPI_SteamAppList() {
	DEBUGBREAK("SteamAppList");
	return g_SteamClientGameServer->GetISteamAppList(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamAppList
	);
}

_FREE_API_ IpSteamApps _S_CALL_ SteamAPI_SteamApps() {
	DEBUGBREAK("SteamApps");
	return g_SteamClientGameServer->GetISteamApps(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamApps
	);
}

_FREE_API_ IpSteamClient _S_CALL_ SteamAPI_SteamClient() {
	DEBUGBREAK("SteamClient");
	return (IpSteamClient)(SteamInternal_CreateInterface(
		g_SteamAPI_VerT->chSteamClient
	));
}

_FREE_API_ IpSteamController _S_CALL_ SteamAPI_SteamController() {
	DEBUGBREAK("SteamController");
	return g_SteamClientGameServer->GetISteamController(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamController
	);
}

_FREE_API_ IpSteamFriends _S_CALL_ SteamAPI_SteamFriends() {
	DEBUGBREAK("SteamFriends");
	return g_SteamClientGameServer->GetISteamFriends(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamFriends
	);
}

_FREE_API_ IpSteamGameServer _S_CALL_ SteamAPI_SteamGameServer() {
	DEBUGBREAK("SteamGameServer");
	return g_SteamClientGameServer->GetISteamGameServer(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamGameServer
	);
}

_FREE_API_ IpSteamGameServerStats _S_CALL_ SteamAPI_SteamGameServerStats() {
	DEBUGBREAK("SteamGameServerStats");
	return g_SteamClientGameServer->GetISteamGameServerStats(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamGameServerStats
	);
}

_FREE_API_ IpSteamHTMLSurface _S_CALL_ SteamAPI_SteamHTMLSurface() {
	DEBUGBREAK("SteamHTMLSurface");
	return g_SteamClientGameServer->GetISteamHTMLSurface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamHTMLSurface
	);
}

_FREE_API_ IpSteamHTTP _S_CALL_ SteamAPI_SteamHTTP() {
	DEBUGBREAK("SteamHTTP");
	return g_SteamClientGameServer->GetISteamHTTP(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamHTTP
	);
}

_FREE_API_ IpSteamInput _S_CALL_ SteamAPI_SteamInput() {
	DEBUGBREAK("SteamInput");
	return g_SteamClientGameServer->GetISteamInput(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamInput
	);
}

_FREE_API_ IpSteamInventory _S_CALL_ SteamAPI_SteamInventory() {
	DEBUGBREAK("SteamInventory");
	return g_SteamClientGameServer->GetISteamInventory(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamInventory
	);
}

_FREE_API_ IpSteamMatchmaking _S_CALL_ SteamAPI_SteamMatchmaking() {
	DEBUGBREAK("SteamMatchmaking");
	return g_SteamClientGameServer->GetISteamMatchmaking(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamMatchmaking
	);
}

_FREE_API_ IpSteamMatchmakingServers _S_CALL_ SteamAPI_SteamMatchmakingServers() {
	DEBUGBREAK("SteamMatchmakingServers");
	return g_SteamClientGameServer->GetISteamMatchmakingServers(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamMatchmakingServers
	);
}

_FREE_API_ IpSteamMusicRemote _S_CALL_ SteamAPI_SteamMusicRemote() {
	DEBUGBREAK("SteamMusicRemote");
	return g_SteamClientGameServer->GetISteamMusicRemote(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamMusicRemote
	);
}

_FREE_API_ IpSteamGameSearch _S_CALL_ SteamAPI_SteamGameSearch() {
	DEBUGBREAK("SteamGameSearch");
	return g_SteamClientGameServer->GetISteamGameSearch(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamGameSearch
	);
}

_FREE_API_ IpSteamParties _S_CALL_ SteamAPI_SteamParties() {
	DEBUGBREAK("SteamParties");
	return g_SteamClientGameServer->GetISteamParties(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamParties
	);
}

_FREE_API_ IpSteamMusic _S_CALL_ SteamAPI_SteamMusic() {
	DEBUGBREAK("SteamMusic");
	return g_SteamClientGameServer->GetISteamMusic(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamMusic
	);
}

_FREE_API_ IpSteamNetworking _S_CALL_ SteamAPI_SteamNetworking() {
	DEBUGBREAK("SteamNetworking");
	return (IpSteamNetworking)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamNetworking
	));
}

_FREE_API_ IpSteamNetworkingMessages _S_CALL_ SteamAPI_SteamNetworkingMessages() {
	DEBUGBREAK("SteamNetworkingMessages");
	return (IpSteamNetworkingMessages)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamNetworkingMessages
	));
}

_FREE_API_ IpSteamNetworkingSockets _S_CALL_ SteamAPI_SteamNetworkingSockets() {
	DEBUGBREAK("SteamNetworkingSockets");
	return (IpSteamNetworkingSockets)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamNetworkingSockets
	));
}

_FREE_API_ IpSteamNetworkingUtils _S_CALL_ SteamAPI_SteamNetworkingUtils() {
	DEBUGBREAK("SteamNetworkingUtils");
	return (IpSteamNetworkingUtils)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamNetworkingUtils
	));
}

_FREE_API_ IpSteamParentalSettings _S_CALL_ SteamAPI_SteamParentalSettings() {
	DEBUGBREAK("SteamParentalSettings");
	return g_SteamClientGameServer->GetISteamParentalSettings(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamParentalSettings
	);
}

_FREE_API_ IpSteamRemotePlay _S_CALL_ SteamAPI_SteamRemotePlay() {
	DEBUGBREAK("SteamRemotePlay");
	return g_SteamClientGameServer->GetISteamRemotePlay(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamRemotePlay
	);
}

_FREE_API_ IpSteamRemoteStorage _S_CALL_ SteamAPI_SteamRemoteStorage() {
	DEBUGBREAK("SteamRemoteStorage");
	return g_SteamClientGameServer->GetISteamRemoteStorage(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamRemoteStorage
	);
}

_FREE_API_ IpSteamScreenshots _S_CALL_ SteamAPI_SteamScreenshots() {
	DEBUGBREAK("SteamScreenshots");
	return g_SteamClientGameServer->GetISteamScreenshots(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamScreenshots
	);
}

_FREE_API_ IpSteamUGC _S_CALL_ SteamAPI_SteamUGC() {
	DEBUGBREAK("SteamUGC");
	return g_SteamClientGameServer->GetISteamUGC(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamUGC
	);
}

_FREE_API_ IpSteamUnifiedMessages _S_CALL_ SteamAPI_SteamUnifiedMessages() {
	DEBUGBREAK("SteamUnifiedMessages");
	return g_SteamClientGameServer->DEPRECATED_GetISteamUnifiedMessages(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamUnifiedMessages
	);
}

_FREE_API_ IpSteamUser _S_CALL_ SteamAPI_SteamUser() {
	DEBUGBREAK("SteamUser");
	return g_SteamClientGameServer->GetISteamUser(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamUser
	);
}

_FREE_API_ IpSteamUserStats _S_CALL_ SteamAPI_SteamUserStats() {
	DEBUGBREAK("SteamUserStats");
	return g_SteamClientGameServer->GetISteamUserStats(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamUserStats
	);
}

_FREE_API_ IpSteamUtils _S_CALL_ SteamAPI_SteamUtils() {
	DEBUGBREAK("SteamUtils");
	return g_SteamClientGameServer->GetISteamUtils(
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamUtils
	);
}

_FREE_API_ IpSteamVideo _S_CALL_ SteamAPI_SteamVideo() {
	DEBUGBREAK("SteamVideo");
	return g_SteamClientGameServer->GetISteamVideo(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamVideo
	);
}

_FREE_API_ IpSteamMasterServerUpdater _S_CALL_ SteamAPI_SteamMasterServerUpdater() {
	DEBUGBREAK("SteamMasterServerUpdater");
	return g_SteamClientGameServer->GetISteamMasterServerUpdater(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, g_SteamAPI_VerT->chSteamMasterServerUpdater
	);
}

#pragma endregion

// -----------------------------------------------------------------------------
// FreeAPI Flat Functions
// -----------------------------------------------------------------------------

#pragma region FreaAPI.Flat

/* ISteamClient */

_FREE_API_ HSteamPipe _S_CALL_ SteamAPI_ISteamClient_CreateSteamPipe(IpSteamClient pSelf) {
	DEBUGBREAK("SteamAPI_ISteamClient_CreateSteamPipe");
	return g_SteamClientGameServer->CreateSteamPipe();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamClient_BReleaseSteamPipe(IpSteamClient pSelf, HSteamPipe hSteamPipe) {
	DEBUGBREAK("SteamAPI_ISteamClient_BReleaseSteamPipe");
	return g_SteamClientGameServer->BReleaseSteamPipe(hSteamPipe);
}

_FREE_API_ HSteamUser _S_CALL_ SteamAPI_ISteamClient_ConnectToGlobalUser(IpSteamClient pSelf, HSteamPipe hSteamPipe) {
	DEBUGBREAK("SteamAPI_ISteamClient_ConnectToGlobalUser");
	return g_SteamClientGameServer->ConnectToGlobalUser(hSteamPipe);
}

_FREE_API_ HSteamUser _S_CALL_ SteamAPI_ISteamClient_CreateLocalUser(IpSteamClient pSelf, pHSteamPipe phSteamPipe, EAccountType eAccountType) {
	DEBUGBREAK("SteamAPI_ISteamClient_CreateLocalUser");
	return g_SteamClientGameServer->CreateLocalUser(phSteamPipe, eAccountType);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamClient_ReleaseUser(IpSteamClient pSelf, HSteamPipe hSteamPipe, HSteamUser hSteamUser) {
	DEBUGBREAK("SteamAPI_ISteamClient_ReleaseUser");
	return g_SteamClientGameServer->ReleaseUser(hSteamPipe, hSteamUser);
}

_FREE_API_ IpSteamUser _S_CALL_ SteamAPI_ISteamClient_GetISteamUser(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamUser");
	return g_SteamClientGameServer->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamGameServer _S_CALL_ SteamAPI_ISteamClient_GetISteamGameServer(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamGameServer");
	return g_SteamClientGameServer->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamClient_SetLocalIPBinding(IpSteamClient pSelf, const pSteamIPAddress_t pSteamIPAddr, Uint16 Port) {
	DEBUGBREAK("SteamAPI_ISteamClient_SetLocalIPBinding");
	return g_SteamClientGameServer->SetLocalIPBinding(pSteamIPAddr, Port);
}

_FREE_API_ IpSteamFriends _S_CALL_ SteamAPI_ISteamClient_GetISteamFriends(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamFriends");
	return g_SteamClientGameServer->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamUtils _S_CALL_ SteamAPI_ISteamClient_GetISteamUtils(IpSteamClient pSelf, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamUtils");
	return g_SteamClientGameServer->GetISteamUtils(hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamMatchmaking _S_CALL_ SteamAPI_ISteamClient_GetISteamMatchmaking(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamMatchmaking");
	return g_SteamClientGameServer->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamMatchmakingServers _S_CALL_ SteamAPI_ISteamClient_GetISteamMatchmakingServers(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamMatchmakingServers");
	return g_SteamClientGameServer->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ pVoid _S_CALL_ SteamAPI_ISteamClient_GetISteamGenericInterface(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamGenericInterface");
	return g_SteamClientGameServer->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamUserStats _S_CALL_ SteamAPI_ISteamClient_GetISteamUserStats(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamUserStats");
	return g_SteamClientGameServer->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamGameServerStats _S_CALL_ SteamAPI_ISteamClient_GetISteamGameServerStats(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamGameServerStats");
	return g_SteamClientGameServer->GetISteamGameServerStats(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamApps _S_CALL_ SteamAPI_ISteamClient_GetISteamApps(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamApps");
	return g_SteamClientGameServer->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamNetworking _S_CALL_ SteamAPI_ISteamClient_GetISteamNetworking(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamNetworking");
	return g_SteamClientGameServer->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamRemoteStorage _S_CALL_ SteamAPI_ISteamClient_GetISteamRemoteStorage(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamRemoteStorage");
	return g_SteamClientGameServer->GetISteamRemoteStorage(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamScreenshots _S_CALL_ SteamAPI_ISteamClient_GetISteamScreenshots(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamScreenshots");
	return g_SteamClientGameServer->GetISteamScreenshots(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamGameSearch _S_CALL_ SteamAPI_ISteamClient_GetISteamGameSearch(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamGameSearch");
	return g_SteamClientGameServer->GetISteamGameSearch(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamClient_GetIPCCallCount(IpSteamClient pSelf) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetIPCCallCount");
	return g_SteamClientGameServer->GetIPCCallCount();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamClient_SetWarningMessageHook(IpSteamClient pSelf, SteamAPIWarningMessageHook_t pFunction) {
	DEBUGBREAK("SteamAPI_ISteamClient_SetWarningMessageHook");
	return g_SteamClientGameServer->SetWarningMessageHook(pFunction);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamClient_BShutdownIfAllPipesClosed(IpSteamClient pSelf) {
	DEBUGBREAK("SteamAPI_ISteamClient_BShutdownIfAllPipesClosed");
	return g_SteamClientGameServer->BShutdownIfAllPipesClosed();
}

_FREE_API_ IpSteamHTTP _S_CALL_ SteamAPI_ISteamClient_GetISteamHTTP(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamHTTP");
	return g_SteamClientGameServer->GetISteamHTTP(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamController _S_CALL_ SteamAPI_ISteamClient_GetISteamController(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamController");
	return g_SteamClientGameServer->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamUGC _S_CALL_ SteamAPI_ISteamClient_GetISteamUGC(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamUGC");
	return g_SteamClientGameServer->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamAppList _S_CALL_ SteamAPI_ISteamClient_GetISteamAppList(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamAppList");
	return g_SteamClientGameServer->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamMusic _S_CALL_ SteamAPI_ISteamClient_GetISteamMusic(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamMusic");
	return g_SteamClientGameServer->GetISteamMusic(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamMusicRemote _S_CALL_ SteamAPI_ISteamClient_GetISteamMusicRemote(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamMusicRemote");
	return g_SteamClientGameServer->GetISteamMusicRemote(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamHTMLSurface _S_CALL_ SteamAPI_ISteamClient_GetISteamHTMLSurface(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamHTMLSurface");
	return g_SteamClientGameServer->GetISteamHTMLSurface(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamInventory _S_CALL_ SteamAPI_ISteamClient_GetISteamInventory(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamInventory");
	return g_SteamClientGameServer->GetISteamInventory(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamVideo _S_CALL_ SteamAPI_ISteamClient_GetISteamVideo(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamVideo");
	return g_SteamClientGameServer->GetISteamVideo(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamParentalSettings _S_CALL_ SteamAPI_ISteamClient_GetISteamParentalSettings(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamParentalSettings");
	return g_SteamClientGameServer->GetISteamParentalSettings(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamInput _S_CALL_ SteamAPI_ISteamClient_GetISteamInput(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamInput");
	return g_SteamClientGameServer->GetISteamInput(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamParties _S_CALL_ SteamAPI_ISteamClient_GetISteamParties(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamParties");
	return g_SteamClientGameServer->GetISteamParties(hSteamUser, hSteamPipe, pchVersion);
}

_FREE_API_ IpSteamRemotePlay _S_CALL_ SteamAPI_ISteamClient_GetISteamRemotePlay(IpSteamClient pSelf, HSteamUser hSteamUser, HSteamPipe hSteamPipe, pCStrA pchVersion) {
	DEBUGBREAK("SteamAPI_ISteamClient_GetISteamRemotePlay");
	return g_SteamClientGameServer->GetISteamRemotePlay(hSteamUser, hSteamPipe, pchVersion);
}

/* ISteamUser */

_FREE_API_ IpSteamUser _S_CALL_ SteamAPI_SteamUser_v020() {
	DEBUGBREAK("SteamAPI_SteamUser_v020");
	return g_SteamClientGameServer->GetISteamUser(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamUser020"
	);
}

_FREE_API_ IpSteamUser _S_CALL_ SteamAPI_SteamUser_v021() {
	DEBUGBREAK("SteamAPI_SteamUser_v021");
	return g_SteamClientGameServer->GetISteamUser(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamUser021"
	);
}

_FREE_API_ IpSteamUser _S_CALL_ SteamAPI_SteamUser_v022() {
	DEBUGBREAK("SteamAPI_SteamUser_v022");
	return g_SteamClientGameServer->GetISteamUser(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamUser022"
	);
}

_FREE_API_ IpSteamUser _S_CALL_ SteamAPI_SteamUser_v023() {
	DEBUGBREAK("SteamAPI_SteamUser_v023");
	return g_SteamClientGameServer->GetISteamUser(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamUser023"
	);
}

_FREE_API_ HSteamUser _S_CALL_ SteamAPI_ISteamUser_GetHSteamUser(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetHSteamUser");
	return (g_SteamClientGameServer->SteamUser).GetHSteamUser();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_BLoggedOn(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_BLoggedOn");
	return (g_SteamClientGameServer->SteamUser).BLoggedOn();
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamUser_GetSteamID(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetSteamID");
	return (g_SteamClientGameServer->SteamUser).GetSteamId().SteamId_Uint64;
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUser_InitiateGameConnection(IpSteamUser pSelf, pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t_Uint64 SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) {
	DEBUGBREAK("SteamAPI_ISteamUser_InitiateGameConnection");
	return (g_SteamClientGameServer->SteamUser).InitiateGameConnection(pvAuthBlob, cbMaxAuthBlob, SteamId_t{ SteamIdGameServer }, nIPServer, PortServer, bSecure);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_TerminateGameConnection(IpSteamUser pSelf, Uint32 nIPServer, Uint16 PortServer) {
	DEBUGBREAK("SteamAPI_ISteamUser_TerminateGameConnection");
	return (g_SteamClientGameServer->SteamUser).TerminateGameConnection(nIPServer, PortServer);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED(IpSteamUser pSelf, pVoid pvAuthBlob, Int32 cbMaxAuthBlob, SteamId_t_Uint64 SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer, Bool bSecure) {
	DEBUGBREAK("SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED");
	return (g_SteamClientGameServer->SteamUser).InitiateGameConnection(pvAuthBlob, cbMaxAuthBlob, SteamId_t{ SteamIdGameServer }, nIPServer, PortServer, bSecure);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED(IpSteamUser pSelf, Uint32 nIPServer, Uint16 PortServer) {
	DEBUGBREAK("SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED");
	return (g_SteamClientGameServer->SteamUser).TerminateGameConnection(nIPServer, PortServer);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_TrackAppUsageEvent(IpSteamUser pSelf, SteamId_t_Uint64 GameId, Int32 eAppUsageEvent, pCStrA pchExtraInfo) {
	DEBUGBREAK("SteamAPI_ISteamUser_TrackAppUsageEvent");
	return (g_SteamClientGameServer->SteamUser).TrackAppUsageEvent(SteamId_t{ GameId }, eAppUsageEvent, pchExtraInfo);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_GetUserDataFolder(IpSteamUser pSelf, pStrA pchFolder, Int32 cchFolder) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetUserDataFolder");
	return (g_SteamClientGameServer->SteamUser).GetUserDataFolder(pchFolder, cchFolder);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_StartVoiceRecording(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_StartVoiceRecording");
	return (g_SteamClientGameServer->SteamUser).StartVoiceRecording();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_StopVoiceRecording(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_StopVoiceRecording");
	return (g_SteamClientGameServer->SteamUser).StopVoiceRecording();
}

_FREE_API_ EVoiceResult _S_CALL_ SteamAPI_ISteamUser_GetAvailableVoice(IpSteamUser pSelf, pUint32 pcbCompressed, pUint32 pcbUncompressed_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetAvailableVoice");
	return (g_SteamClientGameServer->SteamUser).GetAvailableVoice(pcbCompressed, pcbUncompressed_Deprecated, nUncompressedVoiceDesiredSampleRate_Deprecated);
}

_FREE_API_ EVoiceResult _S_CALL_ SteamAPI_ISteamUser_GetVoice(IpSteamUser pSelf, Bool bWantCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Bool bWantUncompressed_Deprecated, pVoid pUncompressedDest_Deprecated, Uint32 cbUncompressedDestSize_Deprecated, pUint32 nUncompressBytesWritten_Deprecated, Uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetVoice");
	return (g_SteamClientGameServer->SteamUser).GetVoice(bWantCompressed, pvDest, cbDestSize, nBytesWritten, bWantUncompressed_Deprecated, pUncompressedDest_Deprecated, cbUncompressedDestSize_Deprecated, nUncompressBytesWritten_Deprecated);
}

_FREE_API_ EVoiceResult _S_CALL_ SteamAPI_ISteamUser_DecompressVoice(IpSteamUser pSelf, pCVoid pCompressed, Uint32 cbCompressed, pVoid pvDest, Uint32 cbDestSize, pUint32 nBytesWritten, Uint32 nDesiredSampleRate) {
	DEBUGBREAK("SteamAPI_ISteamUser_DecompressVoice");
	return (g_SteamClientGameServer->SteamUser).DecompressVoice(pCompressed, cbCompressed, pvDest, cbDestSize, nBytesWritten, nDesiredSampleRate);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUser_GetVoiceOptimalSampleRate(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetVoiceOptimalSampleRate");
	return (g_SteamClientGameServer->SteamUser).GetVoiceOptimalSampleRate();
}

_FREE_API_ HAuthTicket _S_CALL_ SteamAPI_ISteamUser_GetAuthSessionTicket(IpSteamUser pSelf, pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSteamNetworkingIdentity) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetAuthSessionTicket");
	return (g_SteamClientGameServer->SteamUser).GetAuthSessionTicket(pvTicket, cbMaxTicket, pcbTicket, pSteamNetworkingIdentity);
}

_FREE_API_ HAuthTicket _S_CALL_ SteamAPI_ISteamUser_GetAuthTicketForWebApi(IpSteamUser pSelf, pCStrA pchIdentity) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetAuthTicketForWebApi");
	return (g_SteamClientGameServer->SteamUser).GetAuthTicketForWebApi(pchIdentity);
}

_FREE_API_ EBeginAuthSessionResult _S_CALL_ SteamAPI_ISteamUser_BeginAuthSession(IpSteamUser pSelf, pCVoid pAuthTicket, Int32 cbAuthTicket, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamUser_BeginAuthSession");
	return (g_SteamClientGameServer->SteamUser).BeginAuthSession(pAuthTicket, cbAuthTicket, SteamId_t{ SteamId });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_EndAuthSession(IpSteamUser pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamUser_EndAuthSession");
	return (g_SteamClientGameServer->SteamUser).EndAuthSession(SteamId_t{ SteamId });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_CancelAuthTicket(IpSteamUser pSelf, HAuthTicket hAuthTicket) {
	DEBUGBREAK("SteamAPI_ISteamUser_CancelAuthTicket");
	return (g_SteamClientGameServer->SteamUser).CancelAuthTicket(hAuthTicket);
}

_FREE_API_ EUserHasLicenseForAppResult _S_CALL_ SteamAPI_ISteamUser_UserHasLicenseForApp(IpSteamUser pSelf, SteamId_t_Uint64 SteamId, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamUser_UserHasLicenseForApp");
	return (g_SteamClientGameServer->SteamUser).UserHasLicenseForApp(SteamId_t{ SteamId }, iAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_BIsBehindNAT(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_BIsBehindNAT");
	return (g_SteamClientGameServer->SteamUser).BIsBehindNAT();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUser_AdvertiseGame(IpSteamUser pSelf, SteamId_t_Uint64 SteamIdGameServer, Uint32 nIPServer, Uint16 PortServer) {
	DEBUGBREAK("SteamAPI_ISteamUser_AdvertiseGame");
	return (g_SteamClientGameServer->SteamUser).AdvertiseGame(SteamId_t{ SteamIdGameServer }, nIPServer, PortServer);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUser_RequestEncryptedAppTicket(IpSteamUser pSelf, pVoid pvDataToInclude, Int32 cbDataToInclude) {
	DEBUGBREAK("SteamAPI_ISteamUser_RequestEncryptedAppTicket");
	return (g_SteamClientGameServer->SteamUser).RequestEncryptedAppTicket(pvDataToInclude, cbDataToInclude);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_GetEncryptedAppTicket(IpSteamUser pSelf, pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetEncryptedAppTicket");
	return (g_SteamClientGameServer->SteamUser).GetEncryptedAppTicket(pvTicket, cbMaxTicket, pcbTicket);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUser_GetGameBadgeLevel(IpSteamUser pSelf, Int32 nSeries, Bool bFoil) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetGameBadgeLevel");
	return (g_SteamClientGameServer->SteamUser).GetGameBadgeLevel(nSeries, bFoil);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUser_GetPlayerSteamLevel(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetPlayerSteamLevel");
	return (g_SteamClientGameServer->SteamUser).GetPlayerSteamLevel();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUser_RequestStoreAuthURL(IpSteamUser pSelf, pCStrA pchRedirectURL) {
	DEBUGBREAK("SteamAPI_ISteamUser_RequestStoreAuthURL");
	return (g_SteamClientGameServer->SteamUser).RequestStoreAuthURL(pchRedirectURL);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_BIsPhoneVerified(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_BIsPhoneVerified");
	return (g_SteamClientGameServer->SteamUser).BIsPhoneVerified();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_BIsTwoFactorEnabled(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_BIsTwoFactorEnabled");
	return (g_SteamClientGameServer->SteamUser).BIsTwoFactorEnabled();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_BIsPhoneIdentifying(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_BIsPhoneIdentifying");
	return (g_SteamClientGameServer->SteamUser).BIsPhoneIdentifying();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_BIsPhoneRequiringVerification(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_BIsPhoneRequiringVerification");
	return (g_SteamClientGameServer->SteamUser).BIsPhoneRequiringVerification();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUser_GetMarketEligibility(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetMarketEligibility");
	return (g_SteamClientGameServer->SteamUser).GetMarketEligibility();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUser_GetDurationControl(IpSteamUser pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUser_GetDurationControl");
	return (g_SteamClientGameServer->SteamUser).GetDurationControl();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUser_BSetDurationControlOnlineState(IpSteamUser pSelf, EDurationControlOnlineState eDurationControlOnlineState) {
	DEBUGBREAK("SteamAPI_ISteamUser_BSetDurationControlOnlineState");
	return (g_SteamClientGameServer->SteamUser).BSetDurationControlOnlineState(eDurationControlOnlineState);
}

/* ISteamFriends */

_FREE_API_ IpSteamFriends _S_CALL_ SteamAPI_SteamFriends_v017() {
	DEBUGBREAK("SteamAPI_SteamFriends_v017");
	return g_SteamClientGameServer->GetISteamFriends(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamFriends017"
	);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetPersonaName(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetPersonaName");
	return (g_SteamClientGameServer->SteamFriends).GetPersonaName();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_SetPersonaName(IpSteamFriends pSelf, pCStrA pchPersonaName) {
	DEBUGBREAK("SteamAPI_ISteamFriends_SetPersonaName");
	return (g_SteamClientGameServer->SteamFriends).SetPersonaName(pchPersonaName);
}

_FREE_API_ EPersonaState _S_CALL_ SteamAPI_ISteamFriends_GetPersonaState(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetPersonaState");
	return (g_SteamClientGameServer->SteamFriends).GetPersonaState();
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendCount(IpSteamFriends pSelf, Int32 iFriendFlags) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendCount");
	return (g_SteamClientGameServer->SteamFriends).GetFriendCount(iFriendFlags);
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamFriends_GetFriendByIndex(IpSteamFriends pSelf, Int32 iFriend, Int32 iFriendFlags) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendByIndex");
	return (g_SteamClientGameServer->SteamFriends).GetFriendByIndex(iFriend, iFriendFlags).SteamId_Uint64;
}

_FREE_API_ EFriendRelationship _S_CALL_ SteamAPI_ISteamFriends_GetFriendRelationship(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendRelationship");
	return (g_SteamClientGameServer->SteamFriends).GetFriendRelationship(SteamId_t{ SteamIdFriend });
}

_FREE_API_ EPersonaState _S_CALL_ SteamAPI_ISteamFriends_GetFriendPersonaState(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendPersonaState");
	return (g_SteamClientGameServer->SteamFriends).GetFriendPersonaState(SteamId_t{ SteamIdFriend });
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetFriendPersonaName(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendPersonaName");
	return (g_SteamClientGameServer->SteamFriends).GetFriendPersonaName(SteamId_t{ SteamIdFriend });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_GetFriendGamePlayed(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, pFriendGameInfo_t pFriendGameInfo) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendGamePlayed");
	return (g_SteamClientGameServer->SteamFriends).GetFriendGamePlayed(SteamId_t{ SteamIdFriend }, pFriendGameInfo);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetFriendPersonaNameHistory(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, Int32 iPersonaName) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendPersonaNameHistory");
	return (g_SteamClientGameServer->SteamFriends).GetFriendPersonaNameHistory(SteamId_t{ SteamIdFriend }, iPersonaName);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendSteamLevel(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendSteamLevel");
	return (g_SteamClientGameServer->SteamFriends).GetFriendSteamLevel(SteamId_t{ SteamIdFriend });
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetPlayerNickname(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdPlayer) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetPlayerNickname");
	return (g_SteamClientGameServer->SteamFriends).GetPlayerNickname(SteamId_t{ SteamIdPlayer });
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendsGroupCount(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendsGroupCount");
	return (g_SteamClientGameServer->SteamFriends).GetFriendsGroupCount();
}

_FREE_API_ FriendsGroupId_t _S_CALL_ SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex(IpSteamFriends pSelf, Int32 iFG) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex");
	return (g_SteamClientGameServer->SteamFriends).GetFriendsGroupIDByIndex(iFG);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetFriendsGroupName(IpSteamFriends pSelf, FriendsGroupId_t FriendsGroupId) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendsGroupName");
	return (g_SteamClientGameServer->SteamFriends).GetFriendsGroupName(FriendsGroupId);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendsGroupMembersCount(IpSteamFriends pSelf, FriendsGroupId_t FriendsGroupId) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendsGroupMembersCount");
	return (g_SteamClientGameServer->SteamFriends).GetFriendsGroupMembersCount(FriendsGroupId);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_GetFriendsGroupMembersList(IpSteamFriends pSelf, FriendsGroupId_t FriendsGroupId, pSteamId_t pnSteamIdMembers, Int32 nMembers) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendsGroupMembersList");
	return (g_SteamClientGameServer->SteamFriends).GetFriendsGroupMembersList(FriendsGroupId, pnSteamIdMembers, nMembers);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_HasFriend(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, Int32 iFriendFlags) {
	DEBUGBREAK("SteamAPI_ISteamFriends_HasFriend");
	return (g_SteamClientGameServer->SteamFriends).HasFriend(SteamId_t{ SteamIdFriend }, iFriendFlags);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetClanCount(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanCount");
	return (g_SteamClientGameServer->SteamFriends).GetClanCount();
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamFriends_GetClanByIndex(IpSteamFriends pSelf, Int32 iClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanByIndex");
	return (g_SteamClientGameServer->SteamFriends).GetClanByIndex(iClan).SteamId_Uint64;
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetClanName(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanName");
	return (g_SteamClientGameServer->SteamFriends).GetClanName(SteamId_t{ SteamIdClan });
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetClanTag(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanTag");
	return (g_SteamClientGameServer->SteamFriends).GetClanTag(SteamId_t{ SteamIdClan });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_GetClanActivityCounts(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan, pInt32 pnOnline, pInt32 pnInGame, pInt32 pnChatting) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanActivityCounts");
	return (g_SteamClientGameServer->SteamFriends).GetClanActivityCounts(SteamId_t{ SteamIdClan }, pnOnline, pnInGame, pnChatting);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_DownloadClanActivityCounts(IpSteamFriends pSelf, pSteamId_t pSteamIdClans, Int32 nClansToRequest) {
	DEBUGBREAK("SteamAPI_ISteamFriends_DownloadClanActivityCounts");
	return (g_SteamClientGameServer->SteamFriends).DownloadClanActivityCounts(pSteamIdClans, nClansToRequest);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendCountFromSource(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdSource) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendCountFromSource");
	return (g_SteamClientGameServer->SteamFriends).GetFriendCountFromSource(SteamId_t{ SteamIdSource });
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamFriends_GetFriendFromSourceByIndex(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdSource, Int32 iFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendFromSourceByIndex");
	return (g_SteamClientGameServer->SteamFriends).GetFriendFromSourceByIndex(SteamId_t{ SteamIdSource }, iFriend).SteamId_Uint64;
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_IsUserInSource(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdUser, SteamId_t_Uint64 SteamIdSource) {
	DEBUGBREAK("SteamAPI_ISteamFriends_IsUserInSource");
	return (g_SteamClientGameServer->SteamFriends).IsUserInSource(SteamId_t{ SteamIdUser }, SteamId_t{ SteamIdSource });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_SetInGameVoiceSpeaking(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdUser, Bool bSpeaking) {
	DEBUGBREAK("SteamAPI_ISteamFriends_SetInGameVoiceSpeaking");
	return (g_SteamClientGameServer->SteamFriends).SetInGameVoiceSpeaking(SteamId_t{ SteamIdUser }, bSpeaking);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ActivateGameOverlay(IpSteamFriends pSelf, pCStrA pchDialogName) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ActivateGameOverlay");
	return (g_SteamClientGameServer->SteamFriends).ActivateGameOverlay(pchDialogName);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ActivateGameOverlayToUser(IpSteamFriends pSelf, pCStrA pchDialog, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ActivateGameOverlayToUser");
	return (g_SteamClientGameServer->SteamFriends).ActivateGameOverlayToUser(pchDialog, SteamId_t{ SteamId });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage(IpSteamFriends pSelf, pCStrA pchURL, EActivateGameOverlayToWebPageMode eActivateGameOverlayToWebPageMode) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage");
	return (g_SteamClientGameServer->SteamFriends).ActivateGameOverlayToWebPage(pchURL, eActivateGameOverlayToWebPageMode);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ActivateGameOverlayToStore(IpSteamFriends pSelf, AppId_t iAppId, EOverlayToStoreFlag eOverlayToStoreFlag) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ActivateGameOverlayToStore");
	return (g_SteamClientGameServer->SteamFriends).ActivateGameOverlayToStore(iAppId, eOverlayToStoreFlag);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_SetPlayedWith(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdUserPlayedWith) {
	DEBUGBREAK("SteamAPI_ISteamFriends_SetPlayedWith");
	return (g_SteamClientGameServer->SteamFriends).SetPlayedWith(SteamId_t{ SteamIdUserPlayedWith });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog");
	return (g_SteamClientGameServer->SteamFriends).ActivateGameOverlayInviteDialog(SteamId_t{ SteamIdLobby });
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetSmallFriendAvatar(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetSmallFriendAvatar");
	return (g_SteamClientGameServer->SteamFriends).GetSmallFriendAvatar(SteamId_t{ SteamIdFriend });
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetMediumFriendAvatar(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetMediumFriendAvatar");
	return (g_SteamClientGameServer->SteamFriends).GetMediumFriendAvatar(SteamId_t{ SteamIdFriend });
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetLargeFriendAvatar(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetLargeFriendAvatar");
	return (g_SteamClientGameServer->SteamFriends).GetLargeFriendAvatar(SteamId_t{ SteamIdFriend });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_RequestUserInformation(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdUser, Bool bRequireNameOnly) {
	DEBUGBREAK("SteamAPI_ISteamFriends_RequestUserInformation");
	return (g_SteamClientGameServer->SteamFriends).RequestUserInformation(SteamId_t{ SteamIdUser }, bRequireNameOnly);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_RequestClanOfficerList(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_RequestClanOfficerList");
	return (g_SteamClientGameServer->SteamFriends).RequestClanOfficerList(SteamId_t{ SteamIdClan });
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamFriends_GetClanOwner(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanOwner");
	return (g_SteamClientGameServer->SteamFriends).GetClanOwner(SteamId_t{ SteamIdClan }).SteamId_Uint64;
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetClanOfficerCount(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanOfficerCount");
	return (g_SteamClientGameServer->SteamFriends).GetClanOfficerCount(SteamId_t{ SteamIdClan });
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamFriends_GetClanOfficerByIndex(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan, Int32 iOfficer) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanOfficerByIndex");
	return (g_SteamClientGameServer->SteamFriends).GetClanOfficerByIndex(SteamId_t{ SteamIdClan }, iOfficer).SteamId_Uint64;
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamFriends_GetUserRestrictions(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetUserRestrictions");
	return (g_SteamClientGameServer->SteamFriends).GetUserRestrictions();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_SetRichPresence(IpSteamFriends pSelf, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamFriends_SetRichPresence");
	return (g_SteamClientGameServer->SteamFriends).SetRichPresence(pchKey, pchValue);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ClearRichPresence(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ClearRichPresence");
	return (g_SteamClientGameServer->SteamFriends).ClearRichPresence();
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetFriendRichPresence(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendRichPresence");
	return (g_SteamClientGameServer->SteamFriends).GetFriendRichPresence(SteamId_t{ SteamIdFriend }, pchKey);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount");
	return (g_SteamClientGameServer->SteamFriends).GetFriendRichPresenceKeyCount(SteamId_t{ SteamIdFriend });
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, Int32 iKey) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex");
	return (g_SteamClientGameServer->SteamFriends).GetFriendRichPresenceKeyByIndex(SteamId_t{ SteamIdFriend }, iKey);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_RequestFriendRichPresence(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_RequestFriendRichPresence");
	return (g_SteamClientGameServer->SteamFriends).RequestFriendRichPresence(SteamId_t{ SteamIdFriend });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_InviteUserToGame(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, pCStrA pchConnectionectString) {
	DEBUGBREAK("SteamAPI_ISteamFriends_InviteUserToGame");
	return (g_SteamClientGameServer->SteamFriends).InviteUserToGame(SteamId_t{ SteamIdFriend }, pchConnectionectString);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetCoplayFriendCount(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetCoplayFriendCount");
	return (g_SteamClientGameServer->SteamFriends).GetCoplayFriendCount();
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamFriends_GetCoplayFriend(IpSteamFriends pSelf, Int32 iCoplayFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetCoplayFriend");
	return (g_SteamClientGameServer->SteamFriends).GetCoplayFriend(iCoplayFriend).SteamId_Uint64;
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendCoplayTime(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendCoplayTime");
	return (g_SteamClientGameServer->SteamFriends).GetFriendCoplayTime(SteamId_t{ SteamIdFriend });
}

_FREE_API_ AppId_t _S_CALL_ SteamAPI_ISteamFriends_GetFriendCoplayGame(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendCoplayGame");
	return (g_SteamClientGameServer->SteamFriends).GetFriendCoplayGame(SteamId_t{ SteamIdFriend });
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_JoinClanChatRoom(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_JoinClanChatRoom");
	return (g_SteamClientGameServer->SteamFriends).JoinClanChatRoom(SteamId_t{ SteamIdClan });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_LeaveClanChatRoom(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_LeaveClanChatRoom");
	return (g_SteamClientGameServer->SteamFriends).LeaveClanChatRoom(SteamId_t{ SteamIdClan });
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetClanChatMemberCount(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanChatMemberCount");
	return (g_SteamClientGameServer->SteamFriends).GetClanChatMemberCount(SteamId_t{ SteamIdClan });
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamFriends_GetChatMemberByIndex(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan, Int32 iUser) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetChatMemberByIndex");
	return (g_SteamClientGameServer->SteamFriends).GetChatMemberByIndex(SteamId_t{ SteamIdClan }, iUser).SteamId_Uint64;
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_SendClanChatMessage(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClanChat, pCStrA pchText) {
	DEBUGBREAK("SteamAPI_ISteamFriends_SendClanChatMessage");
	return (g_SteamClientGameServer->SteamFriends).SendClanChatMessage(SteamId_t{ SteamIdClanChat }, pchText);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetClanChatMessage(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClanChat, Int32 iMessage, pStrA pchText, Int32 cchText, pEChatEntryType peChatEntryType, pSteamId_t pSteamIdChatter) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetClanChatMessage");
	return (g_SteamClientGameServer->SteamFriends).GetClanChatMessage(SteamId_t{ SteamIdClanChat }, iMessage, pchText, cchText, peChatEntryType, pSteamIdChatter);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_IsClanChatAdmin(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClanChat, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamFriends_IsClanChatAdmin");
	return (g_SteamClientGameServer->SteamFriends).IsClanChatAdmin(SteamId_t{ SteamIdClanChat }, SteamId_t{ SteamIdUser });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClanChat) {
	DEBUGBREAK("SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam");
	return (g_SteamClientGameServer->SteamFriends).IsClanChatWindowOpenInSteam(SteamId_t{ SteamIdClanChat });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_OpenClanChatWindowInSteam(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClanChat) {
	DEBUGBREAK("SteamAPI_ISteamFriends_OpenClanChatWindowInSteam");
	return (g_SteamClientGameServer->SteamFriends).OpenClanChatWindowInSteam(SteamId_t{ SteamIdClanChat });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_CloseClanChatWindowInSteam(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClanChat) {
	DEBUGBREAK("SteamAPI_ISteamFriends_CloseClanChatWindowInSteam");
	return (g_SteamClientGameServer->SteamFriends).CloseClanChatWindowInSteam(SteamId_t{ SteamIdClanChat });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_SetListenForFriendsMessages(IpSteamFriends pSelf, Bool bInterceptEnabled) {
	DEBUGBREAK("SteamAPI_ISteamFriends_SetListenForFriendsMessages");
	return (g_SteamClientGameServer->SteamFriends).SetListenForFriendsMessages(bInterceptEnabled);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_ReplyToFriendMessage(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, pCStrA pchMsgToSend) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ReplyToFriendMessage");
	return (g_SteamClientGameServer->SteamFriends).ReplyToFriendMessage(SteamId_t{ SteamIdFriend }, pchMsgToSend);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetFriendMessage(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdFriend, Int32 iMessageId, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFriendMessage");
	return (g_SteamClientGameServer->SteamFriends).GetFriendMessage(SteamId_t{ SteamIdFriend }, iMessageId, pvData, cbData, peChatEntryType);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_GetFollowerCount(IpSteamFriends pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetFollowerCount");
	return (g_SteamClientGameServer->SteamFriends).GetFollowerCount(SteamId_t{ SteamId });
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_IsFollowing(IpSteamFriends pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamFriends_IsFollowing");
	return (g_SteamClientGameServer->SteamFriends).IsFollowing(SteamId_t{ SteamId });
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_EnumerateFollowingList(IpSteamFriends pSelf, Uint32 iStart) {
	DEBUGBREAK("SteamAPI_ISteamFriends_EnumerateFollowingList");
	return (g_SteamClientGameServer->SteamFriends).EnumerateFollowingList(iStart);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_IsClanPublic(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_IsClanPublic");
	return (g_SteamClientGameServer->SteamFriends).IsClanPublic(SteamId_t{ SteamIdClan });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_IsClanOfficialGameGroup(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamFriends_IsClanOfficialGameGroup");
	return (g_SteamClientGameServer->SteamFriends).IsClanOfficialGameGroup(SteamId_t{ SteamIdClan });
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages(IpSteamFriends pSelf) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages");
	return (g_SteamClientGameServer->SteamFriends).GetNumChatsWithUnreadPriorityMessages();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog(IpSteamFriends pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog");
	return (g_SteamClientGameServer->SteamFriends).ActivateGameOverlayRemotePlayTogetherInviteDialog(SteamId_t{ SteamIdLobby });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser(IpSteamFriends pSelf, pCStrA pchProtocol) {
	DEBUGBREAK("SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser");
	return (g_SteamClientGameServer->SteamFriends).RegisterProtocolInOverlayBrowser(pchProtocol);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString(IpSteamFriends pSelf, pCStrA pchConnectionectString) {
	DEBUGBREAK("SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString");
	return (g_SteamClientGameServer->SteamFriends).ActivateGameOverlayInviteDialogConnectString(pchConnectionectString);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamFriends_RequestEquippedProfileItems(IpSteamFriends pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamFriends_RequestEquippedProfileItems");
	return (g_SteamClientGameServer->SteamFriends).RequestEquippedProfileItems(SteamId_t{ SteamId });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamFriends_BHasEquippedProfileItem(IpSteamFriends pSelf, SteamId_t_Uint64 SteamId, ECommunityProfileItemType eCommunityProfileItemType) {
	DEBUGBREAK("SteamAPI_ISteamFriends_BHasEquippedProfileItem");
	return (g_SteamClientGameServer->SteamFriends).BHasEquippedProfileItem(SteamId_t{ SteamId }, eCommunityProfileItemType);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamFriends_GetProfileItemPropertyString(IpSteamFriends pSelf, SteamId_t_Uint64 SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetProfileItemPropertyString");
	return (g_SteamClientGameServer->SteamFriends).GetProfileItemPropertyString(SteamId_t{ SteamId }, eCommunityProfileItemType, eCommunityProfileItemProperty);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamFriends_GetProfileItemPropertyUint(IpSteamFriends pSelf, SteamId_t_Uint64 SteamId, ECommunityProfileItemType eCommunityProfileItemType, ECommunityProfileItemProperty eCommunityProfileItemProperty) {
	DEBUGBREAK("SteamAPI_ISteamFriends_GetProfileItemPropertyUint");
	return (g_SteamClientGameServer->SteamFriends).GetProfileItemPropertyUint(SteamId_t{ SteamId }, eCommunityProfileItemType, eCommunityProfileItemProperty);
}

/* ISteamUtils */

_FREE_API_ IpSteamUtils _S_CALL_ SteamAPI_SteamUtils_v009() {
	DEBUGBREAK("SteamAPI_SteamUtils_v009");
	return g_SteamClientGameServer->GetISteamUtils(
		k_HSteamPipe_Client, "SteamUtils009"
	);
}

_FREE_API_ IpSteamUtils _S_CALL_ SteamAPI_SteamUtils_v010() {
	DEBUGBREAK("SteamAPI_SteamUtils_v010");
	return g_SteamClientGameServer->GetISteamUtils(
		k_HSteamPipe_Client, "SteamUtils010"
	);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUtils_GetSecondsSinceAppActive(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetSecondsSinceAppActive");
	return (g_SteamClientGameServer->SteamUtils).GetSecondsSinceAppActive();
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUtils_GetSecondsSinceComputerActive(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetSecondsSinceComputerActive");
	return (g_SteamClientGameServer->SteamUtils).GetSecondsSinceComputerActive();
}

_FREE_API_ EUniverse _S_CALL_ SteamAPI_ISteamUtils_GetConnectedUniverse(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetConnectedUniverse");
	return (g_SteamClientGameServer->SteamUtils).GetConnectedUniverse();
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUtils_GetServerRealTime(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetServerRealTime");
	return (g_SteamClientGameServer->SteamUtils).GetServerRealTime();
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamUtils_GetIPCountry(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetIPCountry");
	return (g_SteamClientGameServer->SteamUtils).GetIPCountry();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_GetImageSize(IpSteamUtils pSelf, Int32 iImage, pUint32 pCx, pUint32 pCy) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetImageSize");
	return (g_SteamClientGameServer->SteamUtils).GetImageSize(iImage, pCx, pCy);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_GetImageRGBA(IpSteamUtils pSelf, Int32 iImage, pUint8 pbDest, Int32 nDestSize) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetImageRGBA");
	return (g_SteamClientGameServer->SteamUtils).GetImageRGBA(iImage, pbDest, nDestSize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_GetCSERIPPort(IpSteamUtils pSelf, pUint32 nIP, pUint16 Port) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetCSERIPPort");
	return (g_SteamClientGameServer->SteamUtils).GetCSERIPPort(nIP, Port);
}

_FREE_API_ Uint8 _S_CALL_ SteamAPI_ISteamUtils_GetCurrentBatteryPower(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetCurrentBatteryPower");
	return (g_SteamClientGameServer->SteamUtils).GetCurrentBatteryPower();
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUtils_GetAppID(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetAppID");
	return (g_SteamClientGameServer->SteamUtils).GetAppId();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUtils_SetOverlayNotificationPosition(IpSteamUtils pSelf, ENotificationPosition eNotificationPosition) {
	DEBUGBREAK("SteamAPI_ISteamUtils_SetOverlayNotificationPosition");
	return (g_SteamClientGameServer->SteamUtils).SetOverlayNotificationPosition(eNotificationPosition);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_IsAPICallCompleted(IpSteamUtils pSelf, SteamAPICall_t hSteamAPICall, pBool pbFailed) {
	DEBUGBREAK("SteamAPI_ISteamUtils_IsAPICallCompleted");
	return (g_SteamClientGameServer->SteamUtils).IsAPICallCompleted(hSteamAPICall, pbFailed);
}

_FREE_API_ ESteamAPICallFailure _S_CALL_ SteamAPI_ISteamUtils_GetAPICallFailureReason(IpSteamUtils pSelf, SteamAPICall_t hSteamAPICall) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetAPICallFailureReason");
	return (g_SteamClientGameServer->SteamUtils).GetAPICallFailureReason(hSteamAPICall);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_GetAPICallResult(IpSteamUtils pSelf, SteamAPICall_t hSteamAPICall, pVoid pvCallback, Int32 cbCallback, Int32 iCallbackExpected, pBool pbFailed) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetAPICallResult");
	return (g_SteamClientGameServer->SteamUtils).GetAPICallResult(hSteamAPICall, pvCallback, cbCallback, iCallbackExpected, pbFailed);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUtils_GetIPCCallCount(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetIPCCallCount");
	return (g_SteamClientGameServer->SteamUtils).GetIPCCallCount();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUtils_SetWarningMessageHook(IpSteamUtils pSelf, SteamAPIWarningMessageHook_t pFunction) {
	DEBUGBREAK("SteamAPI_ISteamUtils_SetWarningMessageHook");
	return (g_SteamClientGameServer->SteamUtils).SetWarningMessageHook(pFunction);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_IsOverlayEnabled(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_IsOverlayEnabled");
	return (g_SteamClientGameServer->SteamUtils).IsOverlayEnabled();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_BOverlayNeedsPresent(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_BOverlayNeedsPresent");
	return (g_SteamClientGameServer->SteamUtils).BOverlayNeedsPresent();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUtils_CheckFileSignature(IpSteamUtils pSelf, pCStrA pchFileName) {
	DEBUGBREAK("SteamAPI_ISteamUtils_CheckFileSignature");
	return (g_SteamClientGameServer->SteamUtils).CheckFileSignature(pchFileName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_ShowGamepadTextInput(IpSteamUtils pSelf, EGamepadTextInputMode eGamepadTextInputMode, EGamepadTextInputLineMode eGamepadTextInputLineMode, pCStrA pchDescription, Uint32 cchDescription, pCStrA pchExistingText) {
	DEBUGBREAK("SteamAPI_ISteamUtils_ShowGamepadTextInput");
	return (g_SteamClientGameServer->SteamUtils).ShowGamepadTextInput(eGamepadTextInputMode, eGamepadTextInputLineMode, pchDescription, cchDescription, pchExistingText);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUtils_GetEnteredGamepadTextLength(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetEnteredGamepadTextLength");
	return (g_SteamClientGameServer->SteamUtils).GetEnteredGamepadTextLength();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_GetEnteredGamepadTextInput(IpSteamUtils pSelf, pStrA pchText, Uint32 cchText) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetEnteredGamepadTextInput");
	return (g_SteamClientGameServer->SteamUtils).GetEnteredGamepadTextInput(pchText, cchText);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamUtils_GetSteamUILanguage(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetSteamUILanguage");
	return (g_SteamClientGameServer->SteamUtils).GetSteamUILanguage();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_IsSteamRunningInVR(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_IsSteamRunningInVR");
	return (g_SteamClientGameServer->SteamUtils).IsSteamRunningInVR();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUtils_SetOverlayNotificationInset(IpSteamUtils pSelf, Int32 nHorizontalInset, Int32 nVerticalInset) {
	DEBUGBREAK("SteamAPI_ISteamUtils_SetOverlayNotificationInset");
	return (g_SteamClientGameServer->SteamUtils).SetOverlayNotificationInset(nHorizontalInset, nVerticalInset);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_IsSteamInBigPictureMode(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_IsSteamInBigPictureMode");
	return (g_SteamClientGameServer->SteamUtils).IsSteamInBigPictureMode();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUtils_StartVRDashboard(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_StartVRDashboard");
	return (g_SteamClientGameServer->SteamUtils).StartVRDashboard();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled");
	return (g_SteamClientGameServer->SteamUtils).IsVRHeadsetStreamingEnabled();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled(IpSteamUtils pSelf, Bool bEnabled) {
	DEBUGBREAK("SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled");
	return (g_SteamClientGameServer->SteamUtils).SetVRHeadsetStreamingEnabled(bEnabled);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_IsSteamChinaLauncher(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_IsSteamChinaLauncher");
	return (g_SteamClientGameServer->SteamUtils).IsSteamChinaLauncher();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_InitFilterText(IpSteamUtils pSelf, Uint32 nFilterOptions) {
	DEBUGBREAK("SteamAPI_ISteamUtils_InitFilterText");
	return (g_SteamClientGameServer->SteamUtils).InitFilterText(nFilterOptions);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUtils_FilterText(IpSteamUtils pSelf, ETextFilteringContext eContext, SteamId_t_Uint64 SourceSteamId, pCStrA pchInputMessage, pStrA pchFilteredText, Uint32 cchFilteredText) {
	DEBUGBREAK("SteamAPI_ISteamUtils_FilterText");
	return (g_SteamClientGameServer->SteamUtils).FilterText(eContext, SteamId_t{ SourceSteamId }, pchInputMessage, pchFilteredText, cchFilteredText);
}

_FREE_API_ ESteamIPv6ConnectivityState _S_CALL_ SteamAPI_ISteamUtils_GetIPv6ConnectivityState(IpSteamUtils pSelf, ESteamIPv6ConnectivityProtocol eSteamIPv6ConnectivityProtocol) {
	DEBUGBREAK("SteamAPI_ISteamUtils_GetIPv6ConnectivityState");
	return (g_SteamClientGameServer->SteamUtils).GetIPv6ConnectivityState(eSteamIPv6ConnectivityProtocol);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck");
	return (g_SteamClientGameServer->SteamUtils).IsSteamRunningOnSteamDeck();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_ShowModalGamepadTextInput(IpSteamUtils pSelf, EGamepadTextInputLineMode eLineInputMode) {
	DEBUGBREAK("SteamAPI_ISteamUtils_ShowModalGamepadTextInput");
	return (g_SteamClientGameServer->SteamUtils).ShowFloatingGamepadTextInput((EFloatingGamepadTextInputMode)(eLineInputMode), 0, 0, 0, 0);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_ShowFloatingGamepadTextInput(IpSteamUtils pSelf, EFloatingGamepadTextInputMode eKeyboardMode, Int32 nTextFieldXPosition, Int32 nTextFieldYPosition, Int32 nTextFieldWidth, Int32 nTextFieldHeight) {
	DEBUGBREAK("SteamAPI_ISteamUtils_ShowFloatingGamepadTextInput");
	return (g_SteamClientGameServer->SteamUtils).ShowFloatingGamepadTextInput(eKeyboardMode, nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUtils_SetGameLauncherMode(IpSteamUtils pSelf, Bool bLauncherMode) {
	DEBUGBREAK("SteamAPI_ISteamUtils_SetGameLauncherMode");
	return (g_SteamClientGameServer->SteamUtils).SetGameLauncherMode(bLauncherMode);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput(IpSteamUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput");
	return (g_SteamClientGameServer->SteamUtils).DismissFloatingGamepadTextInput();
}

/* ISteamMatchmaking */

_FREE_API_ IpSteamMatchmaking _S_CALL_ SteamAPI_SteamMatchmaking_v009() {
	DEBUGBREAK("SteamAPI_SteamMatchmaking_v009");
	return g_SteamClientGameServer->GetISteamMatchmaking(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamMatchMaking009"
	);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamMatchmaking_GetFavoriteGameCount(IpSteamMatchmaking pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetFavoriteGameCount");
	return (g_SteamClientGameServer->SteamMatchmaking).GetFavoriteGameCount();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_GetFavoriteGame(IpSteamMatchmaking pSelf, Int32 iGame, pAppId_t piAppId, pUint32 pnIP, pUint16 pnConnectionPort, pUint16 pQueryPort, pUint32 pnFlags, pRTime32 pLastPlayedOnServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetFavoriteGame");
	return (g_SteamClientGameServer->SteamMatchmaking).GetFavoriteGame(iGame, piAppId, pnIP, pnConnectionPort, pQueryPort, pnFlags, pLastPlayedOnServer);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamMatchmaking_AddFavoriteGame(IpSteamMatchmaking pSelf, AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags, RTime32 LastPlayedOnServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddFavoriteGame");
	return (g_SteamClientGameServer->SteamMatchmaking).AddFavoriteGame(iAppId, nIP, nConnectionPort, QueryPort, nFlags, LastPlayedOnServer);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_RemoveFavoriteGame(IpSteamMatchmaking pSelf, AppId_t iAppId, Uint32 nIP, Uint16 nConnectionPort, Uint16 QueryPort, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_RemoveFavoriteGame");
	return (g_SteamClientGameServer->SteamMatchmaking).RemoveFavoriteGame(iAppId, nIP, nConnectionPort, QueryPort, nFlags);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamMatchmaking_RequestLobbyList(IpSteamMatchmaking pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_RequestLobbyList");
	return (g_SteamClientGameServer->SteamMatchmaking).RequestLobbyList();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter(IpSteamMatchmaking pSelf, pCStrA pchKeyToMatch, pCStrA pchValueToMatch, ELobbyComparison eComparisonType) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter");
	return (g_SteamClientGameServer->SteamMatchmaking).AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter(IpSteamMatchmaking pSelf, pCStrA pchKeyToMatch, Int32 nValueToMatch, ELobbyComparison eComparisonType) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter");
	return (g_SteamClientGameServer->SteamMatchmaking).AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(IpSteamMatchmaking pSelf, pCStrA pchKeyToMatch, Int32 nValueToBeCloseTo) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter");
	return (g_SteamClientGameServer->SteamMatchmaking).AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(IpSteamMatchmaking pSelf, Int32 nSlotsAvailable) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable");
	return (g_SteamClientGameServer->SteamMatchmaking).AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter(IpSteamMatchmaking pSelf, ELobbyDistanceFilter eLobbyDistanceFilter) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter");
	return (g_SteamClientGameServer->SteamMatchmaking).AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(IpSteamMatchmaking pSelf, Int32 cMaxResults) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter");
	return (g_SteamClientGameServer->SteamMatchmaking).AddRequestLobbyListResultCountFilter(cMaxResults);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter");
	return (g_SteamClientGameServer->SteamMatchmaking).AddRequestLobbyListCompatibleMembersFilter(SteamId_t{ SteamIdLobby });
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyByIndex(IpSteamMatchmaking pSelf, Int32 iLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyByIndex");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyByIndex(iLobby).SteamId_Uint64;
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamMatchmaking_CreateLobby(IpSteamMatchmaking pSelf, ELobbyType eLobbyType, Int32 cMaxMembers) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_CreateLobby");
	return (g_SteamClientGameServer->SteamMatchmaking).CreateLobby(eLobbyType, cMaxMembers);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamMatchmaking_JoinLobby(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_JoinLobby");
	return (g_SteamClientGameServer->SteamMatchmaking).JoinLobby(SteamId_t{ SteamIdLobby });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_LeaveLobby(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_LeaveLobby");
	return (g_SteamClientGameServer->SteamMatchmaking).LeaveLobby(SteamId_t{ SteamIdLobby });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_InviteUserToLobby(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, SteamId_t_Uint64 SteamIdInvite) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_InviteUserToLobby");
	return (g_SteamClientGameServer->SteamMatchmaking).InviteUserToLobby(SteamId_t{ SteamIdLobby }, SteamId_t{ SteamIdInvite });
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamMatchmaking_GetNumLobbyMembers(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetNumLobbyMembers");
	return (g_SteamClientGameServer->SteamMatchmaking).GetNumLobbyMembers(SteamId_t{ SteamIdLobby });
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, Int32 iMember) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyMemberByIndex(SteamId_t{ SteamIdLobby }, iMember).SteamId_Uint64;
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyData(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyData");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyData(SteamId_t{ SteamIdLobby }, pchKey);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_SetLobbyData(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLobbyData");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLobbyData(SteamId_t{ SteamIdLobby }, pchKey, pchValue);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyDataCount(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyDataCount");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyDataCount(SteamId_t{ SteamIdLobby });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, Int32 iLobbyData, pStrA pchKey, Int32 cchKey, pStrA pchValue, Int32 cchValue) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyDataByIndex(SteamId_t{ SteamIdLobby }, iLobbyData, pchKey, cchKey, pchValue, cchValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_DeleteLobbyData(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_DeleteLobbyData");
	return (g_SteamClientGameServer->SteamMatchmaking).DeleteLobbyData(SteamId_t{ SteamIdLobby }, pchKey);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyMemberData(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, SteamId_t_Uint64 SteamIdUser, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyMemberData");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyMemberData(SteamId_t{ SteamIdLobby }, SteamId_t{ SteamIdUser }, pchKey);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_SetLobbyMemberData(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLobbyMemberData");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLobbyMemberData(SteamId_t{ SteamIdLobby }, pchKey, pchValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_SendLobbyChatMsg(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, pCVoid pvMsgBody, Int32 cbMsgBody) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SendLobbyChatMsg");
	return (g_SteamClientGameServer->SteamMatchmaking).SendLobbyChatMsg(SteamId_t{ SteamIdLobby }, pvMsgBody, cbMsgBody);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyChatEntry(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, Int32 iChatId, pSteamId_t pSteamIdUser, pVoid pvData, Int32 cbData, pEChatEntryType peChatEntryType) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyChatEntry");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyChatEntry(SteamId_t{ SteamIdLobby }, iChatId, pSteamIdUser, pvData, cbData, peChatEntryType);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_RequestLobbyData(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_RequestLobbyData");
	return (g_SteamClientGameServer->SteamMatchmaking).RequestLobbyData(SteamId_t{ SteamIdLobby });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmaking_SetLobbyGameServer(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, Uint32 nGameServerIP, Uint16 nGameServerPort, SteamId_t_Uint64 SteamIdGameServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLobbyGameServer");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLobbyGameServer(SteamId_t{ SteamIdLobby }, nGameServerIP, nGameServerPort, SteamId_t{ SteamIdGameServer });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyGameServer(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, pUint32 pnGameServerIP, pUint16 pnGameServerPort, pSteamId_t pSteamIdGameServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyGameServer");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyGameServer(SteamId_t{ SteamIdLobby }, pnGameServerIP, pnGameServerPort, pSteamIdGameServer);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, Int32 cMaxMembers) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLobbyMemberLimit(SteamId_t{ SteamIdLobby }, cMaxMembers);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyMemberLimit(SteamId_t{ SteamIdLobby });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_SetLobbyType(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, ELobbyType eLobbyType) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLobbyType");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLobbyType(SteamId_t{ SteamIdLobby }, eLobbyType);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_SetLobbyJoinable(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, Bool bLobbyJoinable) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLobbyJoinable");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLobbyJoinable(SteamId_t{ SteamIdLobby }, bLobbyJoinable);
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamMatchmaking_GetLobbyOwner(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_GetLobbyOwner");
	return (g_SteamClientGameServer->SteamMatchmaking).GetLobbyOwner(SteamId_t{ SteamIdLobby }).SteamId_Uint64;
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_SetLobbyOwner(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, SteamId_t_Uint64 SteamIdNewOwner) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLobbyOwner");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLobbyOwner(SteamId_t{ SteamIdLobby }, SteamId_t{ SteamIdNewOwner });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmaking_SetLinkedLobby(IpSteamMatchmaking pSelf, SteamId_t_Uint64 SteamIdLobby, SteamId_t_Uint64 SteamIdLobbyDependent) {
	DEBUGBREAK("SteamAPI_ISteamMatchmaking_SetLinkedLobby");
	return (g_SteamClientGameServer->SteamMatchmaking).SetLinkedLobby(SteamId_t{ SteamIdLobby }, SteamId_t{ SteamIdLobbyDependent });
}

/* ISteamMatchmakingServerListResponse */

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded(IpSteamMatchmakingServerListResponse pSelf, HServerListRequest hRequest, Int32 iServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded");
	if (pSelf != NULL) {
		pSelf->ServerResponded(hRequest, iServer);
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond(IpSteamMatchmakingServerListResponse pSelf, HServerListRequest hRequest, Int32 iServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond");
	if (pSelf != NULL) {
		pSelf->ServerFailedToRespond(hRequest, iServer);
	}
}
_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete(IpSteamMatchmakingServerListResponse pSelf, HServerListRequest hRequest, EMatchMakingServerResponse eMatchMakingServerResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete");
	if (pSelf != NULL) {
		pSelf->RefreshComplete(hRequest, eMatchMakingServerResponse);
	}
}

/* ISteamMatchmakingPingResponse */

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingPingResponse_ServerResponded(IpSteamMatchmakingPingResponse pSelf, pGameServerItem_t pGameServerItem) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingPingResponse_ServerResponded");
	if (pSelf != NULL) {
		pSelf->ServerResponded(pGameServerItem);
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond(IpSteamMatchmakingPingResponse pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond");
	if (pSelf != NULL) {
		pSelf->ServerFailedToRespond();
	}
}

/* ISteamMatchmakingPlayersResponse */

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList(IpSteamMatchmakingPlayersResponse pSelf, pCStrA pchName, Int32 nScore, Float TimePlayed) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList");
	if (pSelf != NULL) {
		pSelf->AddPlayerToList(pchName, nScore, TimePlayed);
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond(IpSteamMatchmakingPlayersResponse pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond");
	if (pSelf != NULL) {
		pSelf->PlayersFailedToRespond();
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete(IpSteamMatchmakingPlayersResponse pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete");
	if (pSelf != NULL) {
		pSelf->PlayersRefreshComplete();
	}
}

/* ISteamMatchmakingRulesResponse */

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded(IpSteamMatchmakingRulesResponse pSelf, pCStrA pchRule, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded");
	if (pSelf != NULL) {
		pSelf->RulesResponded(pchRule, pchValue);
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond(IpSteamMatchmakingRulesResponse pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond");
	if (pSelf != NULL) {
		pSelf->RulesFailedToRespond();
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete(IpSteamMatchmakingRulesResponse pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete");
	if (pSelf != NULL) {
		pSelf->RulesRefreshComplete();
	}
}

/* ISteamMatchmakingServers */

_FREE_API_ IpSteamMatchmakingServers _S_CALL_ SteamAPI_SteamMatchmakingServers_v002() {
	DEBUGBREAK("SteamAPI_SteamMatchmakingServers_v002");
	return g_SteamClientGameServer->GetISteamMatchmakingServers(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamMatchMakingServers002"
	);
}

_FREE_API_ HServerListRequest _S_CALL_ SteamAPI_ISteamMatchmakingServers_RequestInternetServerList(IpSteamMatchmakingServers pSelf, AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RequestInternetServerList");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RequestInternetServerList(iAppId, ppchFilters, nFilters, pRequestServersResponse);
}

_FREE_API_ HServerListRequest _S_CALL_ SteamAPI_ISteamMatchmakingServers_RequestLANServerList(IpSteamMatchmakingServers pSelf, AppId_t iAppId, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RequestLANServerList");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RequestLANServerList(iAppId, pRequestServersResponse);
}

_FREE_API_ HServerListRequest _S_CALL_ SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList(IpSteamMatchmakingServers pSelf, AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RequestFriendsServerList(iAppId, ppchFilters, nFilters, pRequestServersResponse);
}

_FREE_API_ HServerListRequest _S_CALL_ SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList(IpSteamMatchmakingServers pSelf, AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RequestFavoritesServerList(iAppId, ppchFilters, nFilters, pRequestServersResponse);
}

_FREE_API_ HServerListRequest _S_CALL_ SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList(IpSteamMatchmakingServers pSelf, AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RequestHistoryServerList(iAppId, ppchFilters, nFilters, pRequestServersResponse);
}

_FREE_API_ HServerListRequest _S_CALL_ SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList(IpSteamMatchmakingServers pSelf, AppId_t iAppId, pMatchMakingKeyValuePair_t *ppchFilters, Uint32 nFilters, IpSteamMatchmakingServerListResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RequestSpectatorServerList(iAppId, ppchFilters, nFilters, pRequestServersResponse);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServers_ReleaseRequest(IpSteamMatchmakingServers pSelf, HServerListRequest hServerListRequest) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_ReleaseRequest");
	return (g_SteamClientGameServer->SteamMatchmakingServers).ReleaseRequest(hServerListRequest);
}

_FREE_API_ pGameServerItem_t _S_CALL_ SteamAPI_ISteamMatchmakingServers_GetServerDetails(IpSteamMatchmakingServers pSelf, HServerListRequest hRequest, Int32 iServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_GetServerDetails");
	return (g_SteamClientGameServer->SteamMatchmakingServers).GetServerDetails(hRequest, iServer);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServers_CancelQuery(IpSteamMatchmakingServers pSelf, HServerListRequest hRequest) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_CancelQuery");
	return (g_SteamClientGameServer->SteamMatchmakingServers).CancelQuery(hRequest);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServers_RefreshQuery(IpSteamMatchmakingServers pSelf, HServerListRequest hRequest) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RefreshQuery");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RefreshQuery(hRequest);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMatchmakingServers_IsRefreshing(IpSteamMatchmakingServers pSelf, HServerListRequest hRequest) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_IsRefreshing");
	return (g_SteamClientGameServer->SteamMatchmakingServers).IsRefreshing(hRequest);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamMatchmakingServers_GetServerCount(IpSteamMatchmakingServers pSelf, HServerListRequest hRequest) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_GetServerCount");
	return (g_SteamClientGameServer->SteamMatchmakingServers).GetServerCount(hRequest);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServers_RefreshServer(IpSteamMatchmakingServers pSelf, HServerListRequest hRequest, Int32 iServer) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_RefreshServer");
	return (g_SteamClientGameServer->SteamMatchmakingServers).RefreshServer(hRequest, iServer);
}

_FREE_API_ HServerQuery _S_CALL_ SteamAPI_ISteamMatchmakingServers_PingServer(IpSteamMatchmakingServers pSelf, Uint32 nIP, Uint16 Port, IpSteamMatchmakingPingResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_PingServer");
	return (g_SteamClientGameServer->SteamMatchmakingServers).PingServer(nIP, Port, pRequestServersResponse);
}

_FREE_API_ HServerQuery _S_CALL_ SteamAPI_ISteamMatchmakingServers_PlayerDetails(IpSteamMatchmakingServers pSelf, Uint32 nIP, Uint16 Port, IpSteamMatchmakingPlayersResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_PlayerDetails");
	return (g_SteamClientGameServer->SteamMatchmakingServers).PlayerDetails(nIP, Port, pRequestServersResponse);
}

_FREE_API_ HServerQuery _S_CALL_ SteamAPI_ISteamMatchmakingServers_ServerRules(IpSteamMatchmakingServers pSelf, Uint32 nIP, Uint16 Port, IpSteamMatchmakingRulesResponse pRequestServersResponse) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_ServerRules");
	return (g_SteamClientGameServer->SteamMatchmakingServers).ServerRules(nIP, Port, pRequestServersResponse);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMatchmakingServers_CancelServerQuery(IpSteamMatchmakingServers pSelf, HServerQuery hServerQuery) {
	DEBUGBREAK("SteamAPI_ISteamMatchmakingServers_CancelServerQuery");
	return (g_SteamClientGameServer->SteamMatchmakingServers).CancelServerQuery(hServerQuery);
}

/* ISteamGameSearch */

_FREE_API_ IpSteamGameSearch _S_CALL_ SteamAPI_SteamGameSearch_v001() {
	DEBUGBREAK("SteamAPI_SteamGameSearch_v001");
	return g_SteamClientGameServer->GetISteamGameSearch(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamMatchGameSearch001"
	);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_AddGameSearchParams(IpSteamGameSearch pSelf, pCStrA pchKeyToFind, pCStrA pchValuesToFind) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_AddGameSearchParams");
	return (g_SteamClientGameServer->SteamGameSearch).AddGameSearchParams(pchKeyToFind, pchKeyToFind);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_SearchForGameWithLobby(IpSteamGameSearch pSelf, SteamId_t_Uint64 SteamIdLobby, Int32 nPlayerMin, Int32 nPlayerMax) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_SearchForGameWithLobby");
	return (g_SteamClientGameServer->SteamGameSearch).SearchForGameWithLobby(SteamId_t{ SteamIdLobby }, nPlayerMin, nPlayerMax);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_SearchForGameSolo(IpSteamGameSearch pSelf, Int32 nPlayerMin, Int32 nPlayerMax) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_SearchForGameSolo");
	return (g_SteamClientGameServer->SteamGameSearch).SearchForGameSolo(nPlayerMin, nPlayerMax);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_AcceptGame(IpSteamGameSearch pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_AcceptGame");
	return (g_SteamClientGameServer->SteamGameSearch).AcceptGame();
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_DeclineGame(IpSteamGameSearch pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_DeclineGame");
	return (g_SteamClientGameServer->SteamGameSearch).DeclineGame();
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_RetrieveConnectionDetails(IpSteamGameSearch pSelf, SteamId_t_Uint64 SteamIdHost, pStrA pchConnectionectionDetails, Int32 cbConnectionDetails) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_RetrieveConnectionDetails");
	return (g_SteamClientGameServer->SteamGameSearch).RetrieveConnectionDetails(SteamId_t{ SteamIdHost }, pchConnectionectionDetails, cbConnectionDetails);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_EndGameSearch(IpSteamGameSearch pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_EndGameSearch");
	return (g_SteamClientGameServer->SteamGameSearch).EndGameSearch();
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_SetGameHostParams(IpSteamGameSearch pSelf, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_SetGameHostParams");
	return (g_SteamClientGameServer->SteamGameSearch).SetGameHostParams(pchKey, pchValue);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_SetConnectionDetails(IpSteamGameSearch pSelf, pCStrA pchConnectionectionDetails, Int32 cbConnectionDetails) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_SetConnectionDetails");
	return (g_SteamClientGameServer->SteamGameSearch).SetConnectionDetails(pchConnectionectionDetails, cbConnectionDetails);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_RequestPlayersForGame(IpSteamGameSearch pSelf, Int32 nPlayerMin, Int32 nPlayerMax, Int32 nMaxTeamSize) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_RequestPlayersForGame");
	return (g_SteamClientGameServer->SteamGameSearch).RequestPlayersForGame(nPlayerMin, nPlayerMax, nMaxTeamSize);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_HostConfirmGameStart(IpSteamGameSearch pSelf, Uint64 UniqueGameId) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_HostConfirmGameStart");
	return (g_SteamClientGameServer->SteamGameSearch).HostConfirmGameStart(UniqueGameId);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame(IpSteamGameSearch pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame");
	return (g_SteamClientGameServer->SteamGameSearch).CancelRequestPlayersForGame();
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_SubmitPlayerResult(IpSteamGameSearch pSelf, Uint64 UniqueGameId, SteamId_t_Uint64 SteamIdPlayer, EPlayerResult_t EPlayerResult) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_SubmitPlayerResult");
	return (g_SteamClientGameServer->SteamGameSearch).SubmitPlayerResult(UniqueGameId, SteamId_t{ SteamIdPlayer }, EPlayerResult);
}

_FREE_API_ EGameSearchErrorCode_t _S_CALL_ SteamAPI_ISteamGameSearch_EndGame(IpSteamGameSearch pSelf, Uint64 UniqueGameId) {
	DEBUGBREAK("SteamAPI_ISteamGameSearch_EndGame");
	return (g_SteamClientGameServer->SteamGameSearch).EndGame(UniqueGameId);
}

/* ISteamParties */

_FREE_API_ IpSteamParties _S_CALL_ SteamAPI_SteamParties_v002() {
	DEBUGBREAK("SteamAPI_SteamParties_v002");
	return g_SteamClientGameServer->GetISteamParties(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamParties002"
	);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamParties_GetNumActiveBeacons(IpSteamParties pSelf) {
	DEBUGBREAK("SteamAPI_ISteamParties_GetNumActiveBeacons");
	return (g_SteamClientGameServer->SteamParties).GetNumActiveBeacons();
}

_FREE_API_ PartyBeaconId_t _S_CALL_ SteamAPI_ISteamParties_GetBeaconByIndex(IpSteamParties pSelf, Uint32 iBeacon) {
	DEBUGBREAK("SteamAPI_ISteamParties_GetBeaconByIndex");
	return (g_SteamClientGameServer->SteamParties).GetPartyBeaconIdByIndex(iBeacon);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParties_GetBeaconDetails(IpSteamParties pSelf, PartyBeaconId_t PartyBeaconId, pSteamId_t pSteamIdBeaconOwner, pSteamPartyBeaconLocation_t pLocation, pStrA pchMetadata, Int32 cchMetadata) {
	DEBUGBREAK("SteamAPI_ISteamParties_GetBeaconDetails");
	return (g_SteamClientGameServer->SteamParties).GetBeaconDetails(PartyBeaconId, pSteamIdBeaconOwner, pLocation, pchMetadata, cchMetadata);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamParties_JoinParty(IpSteamParties pSelf, PartyBeaconId_t PartyBeaconId) {
	DEBUGBREAK("SteamAPI_ISteamParties_JoinParty");
	return (g_SteamClientGameServer->SteamParties).JoinParty(PartyBeaconId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParties_GetNumAvailableBeaconLocations(IpSteamParties pSelf, pUint32 pNumLocations) {
	DEBUGBREAK("SteamAPI_ISteamParties_GetNumAvailableBeaconLocations");
	return (g_SteamClientGameServer->SteamParties).GetNumAvailableBeaconLocations(pNumLocations);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParties_GetAvailableBeaconLocations(IpSteamParties pSelf, pSteamPartyBeaconLocation_t pLocationList, Uint32 uMaxNumLocations) {
	DEBUGBREAK("SteamAPI_ISteamParties_GetAvailableBeaconLocations");
	return (g_SteamClientGameServer->SteamParties).GetAvailableBeaconLocations(pLocationList, uMaxNumLocations);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamParties_CreateBeacon(IpSteamParties pSelf, Uint32 nOpenSlots, pSteamPartyBeaconLocation_t pBeaconLocation, pCStrA pchConnectionectString, pCStrA pchMetadata) {
	DEBUGBREAK("SteamAPI_ISteamParties_CreateBeacon");
	return (g_SteamClientGameServer->SteamParties).CreateBeacon(nOpenSlots, pBeaconLocation, pchConnectionectString, pchMetadata);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamParties_OnReservationCompleted(IpSteamParties pSelf, PartyBeaconId_t PartyBeaconId, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamParties_OnReservationCompleted");
	return (g_SteamClientGameServer->SteamParties).OnReservationCompleted(PartyBeaconId, SteamId_t{ SteamIdUser });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamParties_CancelReservation(IpSteamParties pSelf, PartyBeaconId_t PartyBeaconId, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamParties_CancelReservation");
	return (g_SteamClientGameServer->SteamParties).CancelReservation(PartyBeaconId, SteamId_t{ SteamIdUser });
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamParties_ChangeNumOpenSlots(IpSteamParties pSelf, PartyBeaconId_t PartyBeaconId, Uint32 nOpenSlots) {
	DEBUGBREAK("SteamAPI_ISteamParties_ChangeNumOpenSlots");
	return (g_SteamClientGameServer->SteamParties).ChangeNumOpenSlots(PartyBeaconId, nOpenSlots);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParties_DestroyBeacon(IpSteamParties pSelf, PartyBeaconId_t PartyBeaconId) {
	DEBUGBREAK("SteamAPI_ISteamParties_DestroyBeacon");
	return (g_SteamClientGameServer->SteamParties).DestroyBeacon(PartyBeaconId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParties_GetBeaconLocationData(IpSteamParties pSelf, SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eSteamPartyBeaconLocationData, pStrA pchDataString, Int32 cchDataString) {
	DEBUGBREAK("SteamAPI_ISteamParties_GetBeaconLocationData");
	return (g_SteamClientGameServer->SteamParties).GetBeaconLocationData(BeaconLocation, eSteamPartyBeaconLocationData, pchDataString, cchDataString);
}

/* ISteamRemoteStorage */

_FREE_API_ IpSteamRemoteStorage _S_CALL_ SteamAPI_SteamRemoteStorage_v014() {
	DEBUGBREAK("SteamAPI_SteamRemoteStorage_v014");
	return g_SteamClientGameServer->GetISteamRemoteStorage(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMREMOTESTORAGE_INTERFACE_VERSION014"
	);
}

_FREE_API_ IpSteamRemoteStorage _S_CALL_ SteamAPI_SteamRemoteStorage_v016() {
	DEBUGBREAK("SteamAPI_SteamRemoteStorage_v016");
	return g_SteamClientGameServer->GetISteamRemoteStorage(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMREMOTESTORAGE_INTERFACE_VERSION016"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileWrite(IpSteamRemoteStorage pSelf, pCStrA pchFile, pCVoid pvData, Int32 cbData) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileWrite");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileWrite(pchFile, pvData, cbData);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamRemoteStorage_FileRead(IpSteamRemoteStorage pSelf, pCStrA pchFile, pVoid pvData, Int32 cbDataToRead) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileRead");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileRead(pchFile, pvData, cbDataToRead);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_FileWriteAsync(IpSteamRemoteStorage pSelf, pCStrA pchFile, pCVoid pvData, Uint32 cbData) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileWriteAsync");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileWriteAsync(pchFile, pvData, cbData);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_FileReadAsync(IpSteamRemoteStorage pSelf, pCStrA pchFile, Uint32 nOffset, Uint32 cbToRead) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileReadAsync");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileReadAsync(pchFile, nOffset, cbToRead);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete(IpSteamRemoteStorage pSelf, SteamAPICall_t hReadCall, pVoid pvData, Uint32 cbToRead) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileReadAsyncComplete(hReadCall, pvData, cbToRead);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileForget(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileForget");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileForget(pchFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileDelete(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileDelete");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileDelete(pchFile);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_FileShare(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileShare");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileShare(pchFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_SetSyncPlatforms(IpSteamRemoteStorage pSelf, pCStrA pchFile, ERemoteStoragePlatform eRemoteStoragePlatform) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_SetSyncPlatforms");
	return (g_SteamClientGameServer->SteamRemoteStorage).SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
}

_FREE_API_ UGCFileWriteStreamHandle_t _S_CALL_ SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileWriteStreamOpen(pchFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk(IpSteamRemoteStorage pSelf, UGCFileWriteStreamHandle_t hWriteStream, pCVoid pvData, Int32 cbData) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileWriteStreamWriteChunk(hWriteStream, pvData, cbData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileWriteStreamClose(IpSteamRemoteStorage pSelf, UGCFileWriteStreamHandle_t hWriteStream) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileWriteStreamClose");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileWriteStreamClose(hWriteStream);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel(IpSteamRemoteStorage pSelf, UGCFileWriteStreamHandle_t hWriteStream) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileWriteStreamCancel(hWriteStream);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FileExists(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FileExists");
	return (g_SteamClientGameServer->SteamRemoteStorage).FileExists_(pchFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_FilePersisted(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_FilePersisted");
	return (g_SteamClientGameServer->SteamRemoteStorage).FilePersisted(pchFile);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamRemoteStorage_GetFileSize(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetFileSize");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetFileSize(pchFile);
}

_FREE_API_ Int64 _S_CALL_ SteamAPI_ISteamRemoteStorage_GetFileTimestamp(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetFileTimestamp");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetFileTimestamp(pchFile);
}

_FREE_API_ ERemoteStoragePlatform _S_CALL_ SteamAPI_ISteamRemoteStorage_GetSyncPlatforms(IpSteamRemoteStorage pSelf, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetSyncPlatforms");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetSyncPlatforms(pchFile);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamRemoteStorage_GetFileCount(IpSteamRemoteStorage pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetFileCount");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetFileCount();
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamRemoteStorage_GetFileNameAndSize(IpSteamRemoteStorage pSelf, Int32 iFile, pInt32 pnFileSizeInBytes) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetFileNameAndSize");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetFileNameAndSize(iFile, pnFileSizeInBytes);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_GetQuota(IpSteamRemoteStorage pSelf, pUint64 pnTotalBytes, pUint64 pnAvailableBytes) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetQuota");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetQuota(pnTotalBytes, pnAvailableBytes);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount(IpSteamRemoteStorage pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount");
	return (g_SteamClientGameServer->SteamRemoteStorage).IsCloudEnabledForAccount();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp(IpSteamRemoteStorage pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp");
	return (g_SteamClientGameServer->SteamRemoteStorage).IsCloudEnabledForApp();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp(IpSteamRemoteStorage pSelf, Bool bEnabled) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp");
	return (g_SteamClientGameServer->SteamRemoteStorage).SetCloudEnabledForApp(bEnabled);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_UGCDownload(IpSteamRemoteStorage pSelf, UGCHandle_t hUGC, Uint32 nPriority) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UGCDownload");
	return (g_SteamClientGameServer->SteamRemoteStorage).UGCDownload(hUGC, nPriority);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress(IpSteamRemoteStorage pSelf, UGCHandle_t hUGC, pInt32 pnBytesDownloaded, pInt32 pnBytesExpected) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetUGCDownloadProgress(hUGC, pnBytesDownloaded, pnBytesExpected);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_GetUGCDetails(IpSteamRemoteStorage pSelf, UGCHandle_t hUGC, pAppId_t piAppId, pStrA *ppchName, pInt32 pnFileSizeInBytes, pSteamId_t pSteamIdOwner) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetUGCDetails");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetUGCDetails(hUGC, piAppId, ppchName, pnFileSizeInBytes, pSteamIdOwner);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamRemoteStorage_UGCRead(IpSteamRemoteStorage pSelf, UGCHandle_t hUGC, pVoid pvData, Int32 cbDataToRead, Uint32 cOffset, EUGCReadAction eAction) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UGCRead");
	return (g_SteamClientGameServer->SteamRemoteStorage).UGCRead(hUGC, pvData, cbDataToRead, cOffset, eAction);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamRemoteStorage_GetCachedUGCCount(IpSteamRemoteStorage pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetCachedUGCCount");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetCachedUGCCount();
}

_FREE_API_ UGCHandle_t _S_CALL_ SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle(IpSteamRemoteStorage pSelf, Int32 iCachedContent) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetCachedUGCHandle(iCachedContent);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_PublishWorkshopFile(IpSteamRemoteStorage pSelf, pCStrA pchFile, pCStrA pchPreviewFile, AppId_t nConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, SteamParamStringArray_t* pTags, EWorkshopFileType eWorkshopFileType) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_PublishWorkshopFile");
	return (g_SteamClientGameServer->SteamRemoteStorage).PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eRemoteStoragePublishedFileVisibility, pTags, eWorkshopFileType);
}

_FREE_API_ PublishedFileUpdateHandle_t _S_CALL_ SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest");
	return (g_SteamClientGameServer->SteamRemoteStorage).CreatePublishedFileUpdateRequest(PublishedFileId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdatePublishedFileFile(hPublishedFileUpdate, pchFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchPreviewFile) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdatePublishedFilePreviewFile(hPublishedFileUpdate, pchPreviewFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchTitle) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdatePublishedFileTitle(hPublishedFileUpdate, pchTitle);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchDescription) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdatePublishedFileDescription(hPublishedFileUpdate, pchDescription);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate, ERemoteStoragePublishedFileVisibility eVisibility) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdatePublishedFileVisibility(hPublishedFileUpdate, eVisibility);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate, SteamParamStringArray_t* pTags) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdatePublishedFileTags(hPublishedFileUpdate, pTags);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate");
	return (g_SteamClientGameServer->SteamRemoteStorage).CommitPublishedFileUpdate(hPublishedFileUpdate);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId, Uint32 nSeconds) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetPublishedFileDetails(PublishedFileId, nSeconds);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_DeletePublishedFile(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_DeletePublishedFile");
	return (g_SteamClientGameServer->SteamRemoteStorage).DeletePublishedFile(PublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles(IpSteamRemoteStorage pSelf, Uint32 iStart) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles");
	return (g_SteamClientGameServer->SteamRemoteStorage).EnumerateUserPublishedFiles(iStart);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_SubscribePublishedFile(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_SubscribePublishedFile");
	return (g_SteamClientGameServer->SteamRemoteStorage).SubscribePublishedFile(PublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles(IpSteamRemoteStorage pSelf, Uint32 iStart) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles");
	return (g_SteamClientGameServer->SteamRemoteStorage).EnumerateUserSubscribedFiles(iStart);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile");
	return (g_SteamClientGameServer->SteamRemoteStorage).UnsubscribePublishedFile(PublishedFileId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription(IpSteamRemoteStorage pSelf, PublishedFileUpdateHandle_t hPublishedFileUpdate, pCStrA pchChangeDescription) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdatePublishedFileSetChangeDescription(hPublishedFileUpdate, pchChangeDescription);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetPublishedItemVoteDetails(PublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId, Bool bVoteUp) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote");
	return (g_SteamClientGameServer->SteamRemoteStorage).UpdateUserPublishedItemVote(PublishedFileId, bVoteUp);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetUserPublishedItemVoteDetails(PublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles(IpSteamRemoteStorage pSelf, SteamId_t_Uint64 SteamId, Uint32 iStart, SteamParamStringArray_t* pRequiredTags, SteamParamStringArray_t* pExcludedTags) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles");
	return (g_SteamClientGameServer->SteamRemoteStorage).EnumerateUserSharedWorkshopFiles(SteamId_t{ SteamId }, iStart, pRequiredTags, pExcludedTags);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_PublishVideo(IpSteamRemoteStorage pSelf, EWorkshopVideoProvider eVideoProvider, pCStrA pchVideoAccount, pCStrA pchVideoIdentifier, pCStrA pchPreviewFile, AppId_t iConsumerAppId, pCStrA pchTitle, pCStrA pchDescription, ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility, pSteamParamStringArray_t pTags) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_PublishVideo");
	return (g_SteamClientGameServer->SteamRemoteStorage).PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, iConsumerAppId, pchTitle, pchDescription, eRemoteStoragePublishedFileVisibility, pTags);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction(IpSteamRemoteStorage pSelf, PublishedFileId_t PublishedFileId, EWorkshopFileAction eAction) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction");
	return (g_SteamClientGameServer->SteamRemoteStorage).SetUserPublishedFileAction(PublishedFileId, eAction);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction(IpSteamRemoteStorage pSelf, EWorkshopFileAction eWorkshopFileAction, Uint32 iStart) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction");
	return (g_SteamClientGameServer->SteamRemoteStorage).EnumeratePublishedFilesByUserAction(eWorkshopFileAction, iStart);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles(IpSteamRemoteStorage pSelf, EWorkshopEnumerationType eEnumerationType, Uint32 iStart, Uint32 unCount, Uint32 unDays, SteamParamStringArray_t* pTags, SteamParamStringArray_t* pUserTags) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles");
	return (g_SteamClientGameServer->SteamRemoteStorage).EnumeratePublishedWorkshopFiles(eEnumerationType, iStart, unCount, unDays, pTags, pUserTags);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation(IpSteamRemoteStorage pSelf, UGCHandle_t hUGC, pCStrA pchLocation, Uint32 nPriority) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation");
	return (g_SteamClientGameServer->SteamRemoteStorage).UGCDownloadToLocation(hUGC, pchLocation, nPriority);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount(IpSteamRemoteStorage pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetLocalFileChangeCount();
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamRemoteStorage_GetLocalFileChange(IpSteamRemoteStorage pSelf, Int32 iFile, pERemoteStorageLocalFileChange peRemoteStorageLocalFileChange, pERemoteStorageFilePathType peRemoteStorageFilePathType) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_GetLocalFileChange");
	return (g_SteamClientGameServer->SteamRemoteStorage).GetLocalFileChange(iFile, peRemoteStorageLocalFileChange, peRemoteStorageFilePathType);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch(IpSteamRemoteStorage pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch");
	return (g_SteamClientGameServer->SteamRemoteStorage).BeginFileWriteBatch();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemoteStorage_EndFileWriteBatch(IpSteamRemoteStorage pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemoteStorage_EndFileWriteBatch");
	return (g_SteamClientGameServer->SteamRemoteStorage).EndFileWriteBatch();
}

/* ISteamUserStats */

_FREE_API_ IpSteamUserStats _S_CALL_ SteamAPI_SteamUserStats_v011() {
	DEBUGBREAK("SteamAPI_SteamUserStats_v011");
	return g_SteamClientGameServer->GetISteamUserStats(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMUSERSTATS_INTERFACE_VERSION011"
	);
}

_FREE_API_ IpSteamUserStats _S_CALL_ SteamAPI_SteamUserStats_v012() {
	DEBUGBREAK("SteamAPI_SteamUserStats_v012");
	return g_SteamClientGameServer->GetISteamUserStats(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMUSERSTATS_INTERFACE_VERSION012"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_RequestCurrentStats(IpSteamUserStats pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_RequestCurrentStats");
	return (g_SteamClientGameServer->SteamUserStats).RequestCurrentStats();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetStatInt32(IpSteamUserStats pSelf, pCStrA pchName, pInt32 pData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetStatInt32");
	return (g_SteamClientGameServer->SteamUserStats).GetStat(pchName, pData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetStatFloat(IpSteamUserStats pSelf, pCStrA pchName, pFloat pData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetStatFloat");
	return (g_SteamClientGameServer->SteamUserStats).GetStat(pchName, pData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_SetStatInt32(IpSteamUserStats pSelf, pCStrA pchName, Int32 Data) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_SetStatInt32");
	return (g_SteamClientGameServer->SteamUserStats).SetStat(pchName, Data);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_SetStatFloat(IpSteamUserStats pSelf, pCStrA pchName, Float Data) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_SetStatFloat");
	return (g_SteamClientGameServer->SteamUserStats).SetStat(pchName, Data);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_UpdateAvgRateStat(IpSteamUserStats pSelf, pCStrA pchName, Float CountThisSession, Double SessionLength) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_UpdateAvgRateStat");
	return (g_SteamClientGameServer->SteamUserStats).UpdateAvgRateStat(pchName, CountThisSession, SessionLength);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetAchievement(IpSteamUserStats pSelf, pCStrA pchName, pBool pbAchieved) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievement");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievement(pchName, pbAchieved);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_SetAchievement(IpSteamUserStats pSelf, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_SetAchievement");
	return (g_SteamClientGameServer->SteamUserStats).SetAchievement(pchName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_ClearAchievement(IpSteamUserStats pSelf, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_ClearAchievement");
	return (g_SteamClientGameServer->SteamUserStats).ClearAchievement(pchName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime(IpSteamUserStats pSelf, pCStrA pchName, pBool pbAchieved, pUint32 pnUnlockTime) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievementAndUnlockTime(pchName, pbAchieved, pnUnlockTime);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_StoreStats(IpSteamUserStats pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_StoreStats");
	return (g_SteamClientGameServer->SteamUserStats).StoreStats();
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUserStats_GetAchievementIcon(IpSteamUserStats pSelf, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievementIcon");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievementIcon(pchName);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute(IpSteamUserStats pSelf, pCStrA pchName, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievementDisplayAttribute(pchName, pchKey);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_IndicateAchievementProgress(IpSteamUserStats pSelf, pCStrA pchName, Uint32 nCurProgress, Uint32 nMaxProgress) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_IndicateAchievementProgress");
	return (g_SteamClientGameServer->SteamUserStats).IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUserStats_GetNumAchievements(IpSteamUserStats pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetNumAchievements");
	return (g_SteamClientGameServer->SteamUserStats).GetNumAchievements();
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamUserStats_GetAchievementName(IpSteamUserStats pSelf, Uint32 iAchievement) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievementName");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievementName(iAchievement);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_RequestUserStats(IpSteamUserStats pSelf, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_RequestUserStats");
	return (g_SteamClientGameServer->SteamUserStats).RequestUserStats(SteamId_t{ SteamIdUser });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetUserStatInt32(IpSteamUserStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, pInt32 pData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetUserStatInt32");
	return (g_SteamClientGameServer->SteamUserStats).GetUserStat(SteamId_t{ SteamIdUser }, pchName, pData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetUserStatFloat(IpSteamUserStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, pFloat pData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetUserStatFloat");
	return (g_SteamClientGameServer->SteamUserStats).GetUserStat(SteamId_t{ SteamIdUser }, pchName, pData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetUserAchievement(IpSteamUserStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, pBool pbAchieved) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetUserAchievement");
	return (g_SteamClientGameServer->SteamUserStats).GetUserAchievement(SteamId_t{ SteamIdUser }, pchName, pbAchieved);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime(IpSteamUserStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, pBool pbAchieved, pUint32 punUnlockTime) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime");
	return (g_SteamClientGameServer->SteamUserStats).GetUserAchievementAndUnlockTime(SteamId_t{ SteamIdUser }, pchName, pbAchieved, punUnlockTime);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_ResetAllStats(IpSteamUserStats pSelf, Bool bAchievementsToo) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_ResetAllStats");
	return (g_SteamClientGameServer->SteamUserStats).ResetAllStats(bAchievementsToo);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(IpSteamUserStats pSelf, pCStrA pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_FindOrCreateLeaderboard");
	return (g_SteamClientGameServer->SteamUserStats).FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_FindLeaderboard(IpSteamUserStats pSelf, pCStrA pchLeaderboardName) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_FindLeaderboard");
	return (g_SteamClientGameServer->SteamUserStats).FindLeaderboard(pchLeaderboardName);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamUserStats_GetLeaderboardName(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetLeaderboardName");
	return (g_SteamClientGameServer->SteamUserStats).GetLeaderboardName(hSteamLeaderboard);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUserStats_GetLeaderboardEntryCount(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetLeaderboardEntryCount");
	return (g_SteamClientGameServer->SteamUserStats).GetLeaderboardEntryCount(hSteamLeaderboard);
}

_FREE_API_ ELeaderboardSortMethod _S_CALL_ SteamAPI_ISteamUserStats_GetLeaderboardSortMethod(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetLeaderboardSortMethod");
	return (g_SteamClientGameServer->SteamUserStats).GetLeaderboardSortMethod(hSteamLeaderboard);
}

_FREE_API_ ELeaderboardDisplayType _S_CALL_ SteamAPI_ISteamUserStats_GetLeaderboardDisplayType(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetLeaderboardDisplayType");
	return (g_SteamClientGameServer->SteamUserStats).GetLeaderboardDisplayType(hSteamLeaderboard);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, Int32 nRangeStart, Int32 nRangeEnd) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_DownloadLeaderboardEntries");
	return (g_SteamClientGameServer->SteamUserStats).DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard, pSteamId_t prgUsers, Int32 cUsers) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers");
	return (g_SteamClientGameServer->SteamUserStats).DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry(IpSteamUserStats pSelf, SteamLeaderboardEntries_t hSteamLeaderboardEntries, Int32 index, LeaderboardEntry_t* pLeaderboardEntry, pInt32 pDetails, Int32 cDetailsMax) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry");
	return (g_SteamClientGameServer->SteamUserStats).GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_UploadLeaderboardScore(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, Int32 nScore, const pInt32 pScoreDetails, Int32 cScoreDetailsCount) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_UploadLeaderboardScore");
	return (g_SteamClientGameServer->SteamUserStats).UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_AttachLeaderboardUGC(IpSteamUserStats pSelf, SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_AttachLeaderboardUGC");
	return (g_SteamClientGameServer->SteamUserStats).AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers(IpSteamUserStats pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers");
	return (g_SteamClientGameServer->SteamUserStats).GetNumberOfCurrentPlayers();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages(IpSteamUserStats pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages");
	return (g_SteamClientGameServer->SteamUserStats).RequestGlobalAchievementPercentages();
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo(IpSteamUserStats pSelf, pStrA pchName, Uint32 cchName, pFloat pPercent, pBool pbAchieved) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo");
	return (g_SteamClientGameServer->SteamUserStats).GetMostAchievedAchievementInfo(pchName, cchName, pPercent, pbAchieved);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo(IpSteamUserStats pSelf, Int32 iIteratorPrevious, pStrA pchName, Uint32 cchName, pFloat pPercent, pBool pbAchieved) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo");
	return (g_SteamClientGameServer->SteamUserStats).GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName, cchName, pPercent, pbAchieved);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetAchievementAchievedPercent(IpSteamUserStats pSelf, pCStrA pchName, pFloat pPercent) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievementAchievedPercent");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievementAchievedPercent(pchName, pPercent);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUserStats_RequestGlobalStats(IpSteamUserStats pSelf, Int32 nHistoryDays) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_RequestGlobalStats");
	return (g_SteamClientGameServer->SteamUserStats).RequestGlobalStats(nHistoryDays);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetGlobalStatInt64(IpSteamUserStats pSelf, pCStrA pchStatName, pInt64 pData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetGlobalStatInt64");
	return (g_SteamClientGameServer->SteamUserStats).GetGlobalStat(pchStatName, pData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetGlobalStatDouble(IpSteamUserStats pSelf, pCStrA pchStatName, pDouble pData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetGlobalStatDouble");
	return (g_SteamClientGameServer->SteamUserStats).GetGlobalStat(pchStatName, pData);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64(IpSteamUserStats pSelf, pCStrA pchStatName, pInt64 pData, Uint32 cbData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64");
	return (g_SteamClientGameServer->SteamUserStats).GetGlobalStatHistory(pchStatName, pData, cbData);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble(IpSteamUserStats pSelf, pCStrA pchStatName, pDouble pData, Uint32 cbData) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble");
	return (g_SteamClientGameServer->SteamUserStats).GetGlobalStatHistory(pchStatName, pData, cbData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32(IpSteamUserStats pSelf, pCStrA pchName, pInt32 pProgressMin, pInt32 pProgressMax) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievementProgressLimits(pchName, pProgressMin, pProgressMax);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat(IpSteamUserStats pSelf, pCStrA pchName, pFloat pProgressMin, pFloat pProgressMax) {
	DEBUGBREAK("SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat");
	return (g_SteamClientGameServer->SteamUserStats).GetAchievementProgressLimits(pchName, pProgressMin, pProgressMax);
}

/* ISteamApps */

_FREE_API_ IpSteamApps _S_CALL_ SteamAPI_SteamApps_v008() {
	DEBUGBREAK("SteamAPI_SteamApps_v008");
	return g_SteamClientGameServer->GetISteamApps(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMAPPS_INTERFACE_VERSION008"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsSubscribed(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsSubscribed");
	return (g_SteamClientGameServer->SteamApps).BIsSubscribed();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsLowViolence(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsLowViolence");
	return (g_SteamClientGameServer->SteamApps).BIsLowViolence();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsCybercafe(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsCybercafe");
	return (g_SteamClientGameServer->SteamApps).BIsCybercafe();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsVACBanned(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsVACBanned");
	return (g_SteamClientGameServer->SteamApps).BIsVACBanned();
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamApps_GetCurrentGameLanguage(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetCurrentGameLanguage");
	return (g_SteamClientGameServer->SteamApps).GetCurrentGameLanguage();
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamApps_GetAvailableGameLanguages(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetAvailableGameLanguages");
	return (g_SteamClientGameServer->SteamApps).GetAvailableGameLanguages();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsSubscribedApp(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsSubscribedApp");
	return (g_SteamClientGameServer->SteamApps).BIsSubscribedApp(iAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsDlcInstalled(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsDlcInstalled");
	return (g_SteamClientGameServer->SteamApps).BIsDlcInstalled(iAppId);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime");
	return (g_SteamClientGameServer->SteamApps).GetEarliestPurchaseUnixTime(iAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend");
	return (g_SteamClientGameServer->SteamApps).BIsSubscribedFromFreeWeekend();
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamApps_GetDLCCount(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetDLCCount");
	return (g_SteamClientGameServer->SteamApps).GetDLCCount();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BGetDLCDataByIndex(IpSteamApps pSelf, Int32 iDLC, pAppId_t pnAppId, pBool pbAvailable, pStrA pchName, Int32 cchNameSize) {
	DEBUGBREAK("SteamAPI_ISteamApps_BGetDLCDataByIndex");
	return (g_SteamClientGameServer->SteamApps).BGetDLCDataByIndex(iDLC, pnAppId, pbAvailable, pchName, cchNameSize);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamApps_InstallDLC(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_InstallDLC");
	return (g_SteamClientGameServer->SteamApps).InstallDLC(iAppId);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamApps_UninstallDLC(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_UninstallDLC");
	return (g_SteamClientGameServer->SteamApps).UninstallDLC(iAppId);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey");
	return (g_SteamClientGameServer->SteamApps).RequestAppProofOfPurchaseKey(iAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_GetCurrentBetaName(IpSteamApps pSelf, pStrA pchName, Int32 cchNameMax) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetCurrentBetaName");
	return (g_SteamClientGameServer->SteamApps).GetCurrentBetaName(pchName, cchNameMax);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_MarkContentCorrupt(IpSteamApps pSelf, Bool bMissingFilesOnly) {
	DEBUGBREAK("SteamAPI_ISteamApps_MarkContentCorrupt");
	return (g_SteamClientGameServer->SteamApps).MarkContentCorrupt(bMissingFilesOnly);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamApps_GetInstalledDepots(IpSteamApps pSelf, AppId_t iAppId, pDepotId_t pnDepotId, Uint32 nDepotId) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetInstalledDepots");
	return (g_SteamClientGameServer->SteamApps).GetInstalledDepots(iAppId, pnDepotId, nDepotId);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamApps_GetAppInstallDir(IpSteamApps pSelf, AppId_t iAppId, pStrA pchFolder, Uint32 cchFolder) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetAppInstallDir");
	return (g_SteamClientGameServer->SteamApps).GetAppInstallDir(iAppId, pchFolder, cchFolder);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsAppInstalled(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsAppInstalled");
	return (g_SteamClientGameServer->SteamApps).BIsAppInstalled(iAppId);
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamApps_GetAppOwner(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetAppOwner");
	return (g_SteamClientGameServer->SteamApps).GetAppOwner().SteamId_Uint64;
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamApps_GetLaunchQueryParam(IpSteamApps pSelf, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetLaunchQueryParam");
	return (g_SteamClientGameServer->SteamApps).GetLaunchQueryParam(pchKey);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_GetDlcDownloadProgress(IpSteamApps pSelf, AppId_t iAppId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetDlcDownloadProgress");
	return (g_SteamClientGameServer->SteamApps).GetDlcDownloadProgress(iAppId, pnBytesDownloaded, pnBytesTotal);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamApps_GetAppBuildId(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetAppBuildId");
	return (g_SteamClientGameServer->SteamApps).GetAppBuildId();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys");
	return (g_SteamClientGameServer->SteamApps).RequestAllProofOfPurchaseKeys();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamApps_GetFileDetails(IpSteamApps pSelf, pCStrA pchFileName) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetFileDetails");
	return (g_SteamClientGameServer->SteamApps).GetFileDetails(pchFileName);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamApps_GetLaunchCommandLine(IpSteamApps pSelf, pStrA pchCommandLine, Int32 cchCommandLine) {
	DEBUGBREAK("SteamAPI_ISteamApps_GetLaunchCommandLine");
	return (g_SteamClientGameServer->SteamApps).GetLaunchCommandLine(pchCommandLine, cchCommandLine);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing(IpSteamApps pSelf) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing");
	return (g_SteamClientGameServer->SteamApps).BIsSubscribedFromFamilySharing();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_BIsTimedTrial(IpSteamApps pSelf, pUint32 pnSecondsAllowed, pUint32 pnSecondsPlayed) {
	DEBUGBREAK("SteamAPI_ISteamApps_BIsTimedTrial");
	return (g_SteamClientGameServer->SteamApps).BIsTimedTrial(pnSecondsAllowed, pnSecondsPlayed);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamApps_SetDlcContext(IpSteamApps pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamApps_SetDlcContext");
	return (g_SteamClientGameServer->SteamApps).SetDlcContext(iAppId);
}

/* ISteamNetworking */

_FREE_API_ IpSteamNetworking _S_CALL_ SteamAPI_SteamNetworking_v006() {
	DEBUGBREAK("SteamAPI_SteamNetworking_v006");
	return g_SteamClientGameServer->GetISteamNetworking(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworking006"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_SendP2PPacket(IpSteamNetworking pSelf, SteamId_t_Uint64 SteamIdRemote, pCVoid pbData, Uint32 cbData, EP2PSend eP2PSendType, Int32 nChannel) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_SendP2PPacket");
	return (g_SteamClientGameServer->SteamNetworking).SendP2PPacket(SteamId_t{ SteamIdRemote }, pbData, cbData, eP2PSendType);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_IsP2PPacketAvailable(IpSteamNetworking pSelf, pUint32 pcbMsgSize, Int32 nChannel) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_IsP2PPacketAvailable");
	return (g_SteamClientGameServer->SteamNetworking).IsP2PPacketAvailable(pcbMsgSize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_ReadP2PPacket(IpSteamNetworking pSelf, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSteamId_t pSteamIdRemote, Int32 nChannel) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_ReadP2PPacket");
	return (g_SteamClientGameServer->SteamNetworking).ReadP2PPacket(pbDest, cbDest, pcbMsgSize, pSteamIdRemote);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser(IpSteamNetworking pSelf, SteamId_t_Uint64 SteamIdRemote) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser");
	return (g_SteamClientGameServer->SteamNetworking).AcceptP2PSessionWithUser(SteamId_t{ SteamIdRemote });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_CloseP2PSessionWithUser(IpSteamNetworking pSelf, SteamId_t_Uint64 SteamIdRemote) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_CloseP2PSessionWithUser");
	return (g_SteamClientGameServer->SteamNetworking).CloseP2PSessionWithUser(SteamId_t{ SteamIdRemote });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_CloseP2PChannelWithUser(IpSteamNetworking pSelf, SteamId_t_Uint64 SteamIdRemote, Int32 nChannel) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_CloseP2PChannelWithUser");
	return (g_SteamClientGameServer->SteamNetworking).CloseP2PChannelWithUser(SteamId_t{ SteamIdRemote }, nChannel);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_GetP2PSessionState(IpSteamNetworking pSelf, SteamId_t_Uint64 SteamIdRemote, pP2PSessionState_t pConnectionState) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_GetP2PSessionState");
	return (g_SteamClientGameServer->SteamNetworking).GetP2PSessionState(SteamId_t{ SteamIdRemote }, pConnectionState);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_AllowP2PPacketRelay(IpSteamNetworking pSelf, Bool bAllow) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_AllowP2PPacketRelay");
	return (g_SteamClientGameServer->SteamNetworking).AllowP2PPacketRelay(bAllow);
}

_FREE_API_ SNetListenSocket_t _S_CALL_ SteamAPI_ISteamNetworking_CreateListenSocket(IpSteamNetworking pSelf, Int32 nVirtualP2PPort, SteamIPAddress_t nIP, Uint16 Port, Bool bAllowUseOfPacketRelay) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_CreateListenSocket");
	return (g_SteamClientGameServer->SteamNetworking).CreateListenSocket(nVirtualP2PPort, nIP, Port, bAllowUseOfPacketRelay);
}

_FREE_API_ SNetSocket_t _S_CALL_ SteamAPI_ISteamNetworking_CreateP2PConnectionSocket(IpSteamNetworking pSelf, SteamId_t_Uint64 SteamIdTarget, Int32 nVirtualPort, Int32 nTimeoutSecconds, Bool bAllowUseOfPacketRelay) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_CreateP2PConnectionSocket");
	return (g_SteamClientGameServer->SteamNetworking).CreateP2PConnectionSocket(SteamId_t{ SteamIdTarget }, nVirtualPort, nTimeoutSecconds, bAllowUseOfPacketRelay);
}

_FREE_API_ SNetSocket_t _S_CALL_ SteamAPI_ISteamNetworking_CreateConnectionSocket(IpSteamNetworking pSelf, SteamIPAddress_t nIP, Uint16 Port, Int32 nTimeoutSecconds) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_CreateConnectionSocket");
	return (g_SteamClientGameServer->SteamNetworking).CreateConnectionSocket(nIP, Port, nTimeoutSecconds);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_DestroySocket(IpSteamNetworking pSelf, SNetSocket_t hSocket, Bool bNotifyRemoteEnd) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_DestroySocket");
	return (g_SteamClientGameServer->SteamNetworking).DestroySocket(hSocket, bNotifyRemoteEnd);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_DestroyListenSocket(IpSteamNetworking pSelf, SNetListenSocket_t hSocket, Bool bNotifyRemoteEnd) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_DestroyListenSocket");
	return (g_SteamClientGameServer->SteamNetworking).DestroyListenSocket(hSocket, bNotifyRemoteEnd);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_SendDataOnSocket(IpSteamNetworking pSelf, SNetSocket_t hSocket, pVoid pbData, Uint32 cbData, Bool bReliable) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_SendDataOnSocket");
	return (g_SteamClientGameServer->SteamNetworking).SendDataOnSocket(hSocket, pbData, cbData, bReliable);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_IsDataAvailableOnSocket(IpSteamNetworking pSelf, SNetSocket_t hSocket, pUint32 pcbMsgSize) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_IsDataAvailableOnSocket");
	return (g_SteamClientGameServer->SteamNetworking).IsDataAvailableOnSocket(hSocket, pcbMsgSize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_RetrieveDataFromSocket(IpSteamNetworking pSelf, SNetSocket_t hSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_RetrieveDataFromSocket");
	return (g_SteamClientGameServer->SteamNetworking).RetrieveDataFromSocket(hSocket, pbDest, cbDest, pcbMsgSize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_IsDataAvailable(IpSteamNetworking pSelf, SNetListenSocket_t hListenSocket, pUint32 pcbMsgSize, pSNetSocket_t phSocket) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_IsDataAvailable");
	return (g_SteamClientGameServer->SteamNetworking).IsDataAvailable(hListenSocket, pcbMsgSize, phSocket);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_RetrieveData(IpSteamNetworking pSelf, SNetListenSocket_t hListenSocket, pVoid pbDest, Uint32 cbDest, pUint32 pcbMsgSize, pSNetSocket_t phSocket) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_RetrieveData");
	return (g_SteamClientGameServer->SteamNetworking).RetrieveData(hListenSocket, pbDest, cbDest, pcbMsgSize, phSocket);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_GetSocketInfo(IpSteamNetworking pSelf, SNetSocket_t hSocket, pSteamId_t pSteamIdRemote, pInt32 peSocketStatus, pSteamIPAddress_t pnIPAddrRemote, pUint16 pPortRemote) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_GetSocketInfo");
	return (g_SteamClientGameServer->SteamNetworking).GetSocketInfo(hSocket, pSteamIdRemote, peSocketStatus, pnIPAddrRemote, pPortRemote);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworking_GetListenSocketInfo(IpSteamNetworking pSelf, SNetListenSocket_t hListenSocket, pSteamIPAddress_t pnIP, pUint16 pPort) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_GetListenSocketInfo");
	return (g_SteamClientGameServer->SteamNetworking).GetListenSocketInfo(hListenSocket, pnIP, pPort);
}

_FREE_API_ ESNetSocketConnectionType _S_CALL_ SteamAPI_ISteamNetworking_GetSocketConnectionType(IpSteamNetworking pSelf, SNetSocket_t hSocket) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_GetSocketConnectionType");
	return (g_SteamClientGameServer->SteamNetworking).GetSocketConnectionType(hSocket);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworking_GetMaxPacketSize(IpSteamNetworking pSelf, SNetSocket_t hSocket) {
	DEBUGBREAK("SteamAPI_ISteamNetworking_GetMaxPacketSize");
	return (g_SteamClientGameServer->SteamNetworking).GetMaxPacketSize(hSocket);
}

/* ISteamScreenshots */

_FREE_API_ IpSteamScreenshots _S_CALL_ SteamAPI_SteamScreenshots_v003() {
	DEBUGBREAK("SteamAPI_SteamScreenshots_v003");
	return g_SteamClientGameServer->GetISteamScreenshots(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMSCREENSHOTS_INTERFACE_VERSION003"
	);
}

_FREE_API_ ScreenshotHandle _S_CALL_ SteamAPI_ISteamScreenshots_WriteScreenshot(IpSteamScreenshots pSelf, pVoid pvRGB, Uint32 cbRGB, Int32 Cx, Int32 Cy) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_WriteScreenshot");
	return (g_SteamClientGameServer->SteamScreenshots).WriteScreenshot(pvRGB, cbRGB, Cx, Cy);
}

_FREE_API_ ScreenshotHandle _S_CALL_ SteamAPI_ISteamScreenshots_AddScreenshotToLibrary(IpSteamScreenshots pSelf, pCStrA pchFilename, pCStrA pchThumbnailFilename, Int32 Cx, Int32 Cy) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_AddScreenshotToLibrary");
	return (g_SteamClientGameServer->SteamScreenshots).AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, Cx, Cy);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamScreenshots_TriggerScreenshot(IpSteamScreenshots pSelf) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_TriggerScreenshot");
	return (g_SteamClientGameServer->SteamScreenshots).TriggerScreenshot();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamScreenshots_HookScreenshots(IpSteamScreenshots pSelf, Bool bHook) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_HookScreenshots");
	return (g_SteamClientGameServer->SteamScreenshots).HookScreenshots(bHook);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamScreenshots_SetLocation(IpSteamScreenshots pSelf, ScreenshotHandle hScreenshot, pCStrA pchLocation) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_SetLocation");
	return (g_SteamClientGameServer->SteamScreenshots).SetLocation(hScreenshot, pchLocation);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamScreenshots_TagUser(IpSteamScreenshots pSelf, ScreenshotHandle hScreenshot, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_TagUser");
	return (g_SteamClientGameServer->SteamScreenshots).TagUser(hScreenshot, SteamId_t{ SteamId });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamScreenshots_TagPublishedFile(IpSteamScreenshots pSelf, ScreenshotHandle hScreenshot, PublishedFileId_t PublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_TagPublishedFile");
	return (g_SteamClientGameServer->SteamScreenshots).TagPublishedFile(hScreenshot, PublishedFileId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamScreenshots_IsScreenshotsHooked(IpSteamScreenshots pSelf) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_IsScreenshotsHooked");
	return (g_SteamClientGameServer->SteamScreenshots).IsScreenshotsHooked();
}

_FREE_API_ ScreenshotHandle _S_CALL_ SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary(IpSteamScreenshots pSelf, EVRScreenshotType eVRScreenshotType, pCStrA pchFilename, pCStrA pchVRFilename) {
	DEBUGBREAK("SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary");
	return (g_SteamClientGameServer->SteamScreenshots).AddVRScreenshotToLibrary(eVRScreenshotType, pchFilename, pchVRFilename);
}

/* ISteamMusic */

_FREE_API_ IpSteamMusic _S_CALL_ SteamAPI_SteamMusic_v001() {
	DEBUGBREAK("SteamAPI_SteamMusic_v001");
	return g_SteamClientGameServer->GetISteamMusic(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMMUSIC_INTERFACE_VERSION001"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusic_BIsEnabled(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_BIsEnabled");
	return (g_SteamClientGameServer->SteamMusic).BIsEnabled();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusic_BIsPlaying(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_BIsPlaying");
	return (g_SteamClientGameServer->SteamMusic).BIsPlaying();
}

_FREE_API_ AudioPlayback_Status _S_CALL_ SteamAPI_ISteamMusic_GetPlaybackStatus(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_GetPlaybackStatus");
	return (g_SteamClientGameServer->SteamMusic).GetPlaybackStatus();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMusic_Play(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_Play");
	return (g_SteamClientGameServer->SteamMusic).Play();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMusic_Pause(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_Pause");
	return (g_SteamClientGameServer->SteamMusic).Pause();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMusic_PlayPrevious(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_PlayPrevious");
	return (g_SteamClientGameServer->SteamMusic).PlayPrevious();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMusic_PlayNext(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_PlayNext");
	return (g_SteamClientGameServer->SteamMusic).PlayNext();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamMusic_SetVolume(IpSteamMusic pSelf, Float sndVolume) {
	DEBUGBREAK("SteamAPI_ISteamMusic_SetVolume");
	return (g_SteamClientGameServer->SteamMusic).SetVolume(sndVolume);
}

_FREE_API_ Float _S_CALL_ SteamAPI_ISteamMusic_GetVolume(IpSteamMusic pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusic_GetVolume");
	return (g_SteamClientGameServer->SteamMusic).GetVolume();
}

/* ISteamMusicRemote */

_FREE_API_ IpSteamMusicRemote _S_CALL_ SteamAPI_SteamMusicRemote_v001() {
	DEBUGBREAK("SteamAPI_SteamMusicRemote_v001");
	return g_SteamClientGameServer->GetISteamMusicRemote(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMMUSICREMOTE_INTERFACE_VERSION001"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote(IpSteamMusicRemote pSelf, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote");
	return (g_SteamClientGameServer->SteamMusicRemote).RegisterSteamMusicRemote(pchName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote");
	return (g_SteamClientGameServer->SteamMusicRemote).DeregisterSteamMusicRemote();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote");
	return (g_SteamClientGameServer->SteamMusicRemote).BIsCurrentMusicRemote();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_BActivationSuccess(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_BActivationSuccess");
	return (g_SteamClientGameServer->SteamMusicRemote).BActivationSuccess(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_SetDisplayName(IpSteamMusicRemote pSelf, pCStrA pchDisplayName) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_SetDisplayName");
	return (g_SteamClientGameServer->SteamMusicRemote).SetDisplayName(pchDisplayName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64(IpSteamMusicRemote pSelf, pVoid pvData, Uint32 cbDataSize) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64");
	return (g_SteamClientGameServer->SteamMusicRemote).SetPNGIcon_64x64(pvData, cbDataSize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_EnablePlayPrevious(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_EnablePlayPrevious");
	return (g_SteamClientGameServer->SteamMusicRemote).EnablePlayPrevious(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_EnablePlayNext(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_EnablePlayNext");
	return (g_SteamClientGameServer->SteamMusicRemote).EnablePlayNext(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_EnableShuffled(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_EnableShuffled");
	return (g_SteamClientGameServer->SteamMusicRemote).EnableShuffled(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_EnableLooped(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_EnableLooped");
	return (g_SteamClientGameServer->SteamMusicRemote).EnableLooped(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_EnableQueue(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_EnableQueue");
	return (g_SteamClientGameServer->SteamMusicRemote).EnableQueue(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_EnablePlaylists(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_EnablePlaylists");
	return (g_SteamClientGameServer->SteamMusicRemote).EnablePlaylists(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus(IpSteamMusicRemote pSelf, AudioPlayback_Status audioPlayback_Status) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus");
	return (g_SteamClientGameServer->SteamMusicRemote).UpdatePlaybackStatus(audioPlayback_Status);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_UpdateShuffled(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_UpdateShuffled");
	return (g_SteamClientGameServer->SteamMusicRemote).UpdateShuffled(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_UpdateLooped(IpSteamMusicRemote pSelf, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_UpdateLooped");
	return (g_SteamClientGameServer->SteamMusicRemote).UpdateLooped(bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_UpdateVolume(IpSteamMusicRemote pSelf, Float sndVolume) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_UpdateVolume");
	return (g_SteamClientGameServer->SteamMusicRemote).UpdateVolume(sndVolume);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_CurrentEntryWillChange(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_CurrentEntryWillChange");
	return (g_SteamClientGameServer->SteamMusicRemote).CurrentEntryWillChange();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable(IpSteamMusicRemote pSelf, Bool bAvailable) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable");
	return (g_SteamClientGameServer->SteamMusicRemote).CurrentEntryIsAvailable(bAvailable);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText(IpSteamMusicRemote pSelf, pCStrA pchText) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText");
	return (g_SteamClientGameServer->SteamMusicRemote).UpdateCurrentEntryText(pchText);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds(IpSteamMusicRemote pSelf, Int32 nValue) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds");
	return (g_SteamClientGameServer->SteamMusicRemote).UpdateCurrentEntryElapsedSeconds(nValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt(IpSteamMusicRemote pSelf, pVoid pvData, Uint32 cbDataSize) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt");
	return (g_SteamClientGameServer->SteamMusicRemote).UpdateCurrentEntryCoverArt(pvData, cbDataSize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_CurrentEntryDidChange(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_CurrentEntryDidChange");
	return (g_SteamClientGameServer->SteamMusicRemote).CurrentEntryDidChange();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_QueueWillChange(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_QueueWillChange");
	return (g_SteamClientGameServer->SteamMusicRemote).QueueWillChange();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_ResetQueueEntries(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_ResetQueueEntries");
	return (g_SteamClientGameServer->SteamMusicRemote).ResetQueueEntries();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_SetQueueEntry(IpSteamMusicRemote pSelf, Int32 nId, Int32 nPosition, pCStrA pchEntryText) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_SetQueueEntry");
	return (g_SteamClientGameServer->SteamMusicRemote).SetQueueEntry(nId, nPosition, pchEntryText);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry(IpSteamMusicRemote pSelf, Int32 nId) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry");
	return (g_SteamClientGameServer->SteamMusicRemote).SetCurrentQueueEntry(nId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_QueueDidChange(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_QueueDidChange");
	return (g_SteamClientGameServer->SteamMusicRemote).QueueDidChange();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_PlaylistWillChange(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_PlaylistWillChange");
	return (g_SteamClientGameServer->SteamMusicRemote).PlaylistWillChange();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_ResetPlaylistEntries(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_ResetPlaylistEntries");
	return (g_SteamClientGameServer->SteamMusicRemote).ResetPlaylistEntries();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_SetPlaylistEntry(IpSteamMusicRemote pSelf, Int32 nId, Int32 nPosition, pCStrA pchEntryText) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_SetPlaylistEntry");
	return (g_SteamClientGameServer->SteamMusicRemote).SetPlaylistEntry(nId, nPosition, pchEntryText);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry(IpSteamMusicRemote pSelf, Int32 nId) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry");
	return (g_SteamClientGameServer->SteamMusicRemote).SetCurrentPlaylistEntry(nId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamMusicRemote_PlaylistDidChange(IpSteamMusicRemote pSelf) {
	DEBUGBREAK("SteamAPI_ISteamMusicRemote_PlaylistDidChange");
	return (g_SteamClientGameServer->SteamMusicRemote).PlaylistDidChange();
}

/* ISteamHTTP */

_FREE_API_ IpSteamHTTP _S_CALL_ SteamAPI_SteamHTTP_v003() {
	DEBUGBREAK("SteamAPI_SteamHTTP_v003");
	return g_SteamClientGameServer->GetISteamHTTP(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMHTTP_INTERFACE_VERSION003"
	);
}

_FREE_API_ HTTPRequestHandle _S_CALL_ SteamAPI_ISteamHTTP_CreateHTTPRequest(IpSteamHTTP pSelf, EHTTPMethod eHTTPRequestMethod, pCStrA pchAbsoluteURL) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_CreateHTTPRequest");
	return (g_SteamClientGameServer->SteamHTTP).CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestContextValue(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, Uint64 ContextValue) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestContextValue");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestContextValue(hRequest, ContextValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, Uint32 nTimeoutSeconds) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestNetworkActivityTimeout(hRequest, nTimeoutSeconds);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pCStrA pchHeaderName, pCStrA pchHeaderValue) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pCStrA pchParamName, pCStrA pchParamValue) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SendHTTPRequest(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pSteamAPICall_t phCall) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SendHTTPRequest");
	return (g_SteamClientGameServer->SteamHTTP).SendHTTPRequest(hRequest, phCall);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pSteamAPICall_t phCall) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse");
	return (g_SteamClientGameServer->SteamHTTP).SendHTTPRequestAndStreamResponse(hRequest, phCall);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_DeferHTTPRequest(IpSteamHTTP pSelf, HTTPRequestHandle hRequest) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_DeferHTTPRequest");
	return (g_SteamClientGameServer->SteamHTTP).DeferHTTPRequest(hRequest);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_PrioritizeHTTPRequest(IpSteamHTTP pSelf, HTTPRequestHandle hRequest) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_PrioritizeHTTPRequest");
	return (g_SteamClientGameServer->SteamHTTP).PrioritizeHTTPRequest(hRequest);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint32 pnResponseHeaderSize) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize");
	return (g_SteamClientGameServer->SteamHTTP).GetHTTPResponseHeaderSize(hRequest, pchHeaderName, pnResponseHeaderSize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint8 pnHeaderValue, Uint32 nHeaderValue) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue");
	return (g_SteamClientGameServer->SteamHTTP).GetHTTPResponseHeaderValue(hRequest, pchHeaderName, pnHeaderValue, nHeaderValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_GetHTTPResponseBodySize(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pUint32 pnBodySize) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_GetHTTPResponseBodySize");
	return (g_SteamClientGameServer->SteamHTTP).GetHTTPResponseBodySize(hRequest, pnBodySize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_GetHTTPResponseBodyData(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pUint8 pnBodyData, Uint32 nBodyData) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_GetHTTPResponseBodyData");
	return (g_SteamClientGameServer->SteamHTTP).GetHTTPResponseBodyData(hRequest, pnBodyData, nBodyData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, Uint32 cOffset, pUint8 pnBodyData, Uint32 nBodyData) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData");
	return (g_SteamClientGameServer->SteamHTTP).GetHTTPStreamingResponseBodyData(hRequest, cOffset, pnBodyData, nBodyData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_ReleaseHTTPRequest(IpSteamHTTP pSelf, HTTPRequestHandle hRequest) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_ReleaseHTTPRequest");
	return (g_SteamClientGameServer->SteamHTTP).ReleaseHTTPRequest(hRequest);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pFloat pPercent) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct");
	return (g_SteamClientGameServer->SteamHTTP).GetHTTPDownloadProgressPct(hRequest, pPercent);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pCStrA pchContentType, pUint8 pbBody, Uint32 cbBody) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestRawPostBody(hRequest, pchContentType, pbBody, cbBody);
}

_FREE_API_ HTTPCookieContainerHandle _S_CALL_ SteamAPI_ISteamHTTP_CreateCookieContainer(IpSteamHTTP pSelf, Bool bAllowResponsesToModify) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_CreateCookieContainer");
	return (g_SteamClientGameServer->SteamHTTP).CreateCookieContainer(bAllowResponsesToModify);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_ReleaseCookieContainer(IpSteamHTTP pSelf, HTTPCookieContainerHandle hCookieContainer) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_ReleaseCookieContainer");
	return (g_SteamClientGameServer->SteamHTTP).ReleaseCookieContainer(hCookieContainer);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetCookie(IpSteamHTTP pSelf, HTTPCookieContainerHandle hCookieContainer, pCStrA pchHost, pCStrA pchUrl, pCStrA pchCookie) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetCookie");
	return (g_SteamClientGameServer->SteamHTTP).SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestCookieContainer(hRequest, hCookieContainer);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pCStrA pchUserAgentInfo) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, Bool bRequireVerifiedCertificate) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, Uint32 nMilliseconds) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS");
	return (g_SteamClientGameServer->SteamHTTP).SetHTTPRequestAbsoluteTimeoutMS(hRequest, nMilliseconds);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut(IpSteamHTTP pSelf, HTTPRequestHandle hRequest, pBool pbWasTimedOut) {
	DEBUGBREAK("SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut");
	return (g_SteamClientGameServer->SteamHTTP).GetHTTPRequestWasTimedOut(hRequest, pbWasTimedOut);
}

/* ISteamInput */

_FREE_API_ IpSteamInput _S_CALL_ SteamAPI_SteamInput_v001() {
	DEBUGBREAK("SteamAPI_SteamInput_v001");
	return g_SteamClientGameServer->GetISteamInput(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamInput001"
	);
}

_FREE_API_ IpSteamInput _S_CALL_ SteamAPI_SteamInput_v002() {
	DEBUGBREAK("SteamAPI_SteamInput_v002");
	return g_SteamClientGameServer->GetISteamInput(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamInput002"
	);
}

_FREE_API_ IpSteamInput _S_CALL_ SteamAPI_SteamInput_v005() {
	DEBUGBREAK("SteamAPI_SteamInput_v005");
	return g_SteamClientGameServer->GetISteamInput(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamInput005"
	);
}

_FREE_API_ IpSteamInput _S_CALL_ SteamAPI_SteamInput_v006() {
	DEBUGBREAK("SteamAPI_SteamInput_v006");
	return g_SteamClientGameServer->GetISteamInput(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamInput006"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInput_Init(IpSteamInput pSelf, Bool bExplicitlyCallRunFrame) {
	DEBUGBREAK("SteamAPI_ISteamInput_Init");
	return (g_SteamClientGameServer->SteamInput).Init(bExplicitlyCallRunFrame);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInput_Shutdown(IpSteamInput pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInput_Shutdown");
	return (g_SteamClientGameServer->SteamInput).Shutdown();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInput_SetInputActionManifestFilePath(IpSteamInput pSelf, pCStrA pchInputActionManifestAbsolutePath) {
	DEBUGBREAK("SteamAPI_ISteamInput_SetInputActionManifestFilePath");
	return (g_SteamClientGameServer->SteamInput).SetInputActionManifestFilePath(pchInputActionManifestAbsolutePath);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_RunFrame(IpSteamInput pSelf, Bool bReservedValue) {
	DEBUGBREAK("SteamAPI_ISteamInput_RunFrame");
	return (g_SteamClientGameServer->SteamInput).RunFrame(bReservedValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInput_BWaitForData(IpSteamInput pSelf, Bool bWaitForever, Uint32 Timeout) {
	DEBUGBREAK("SteamAPI_ISteamInput_BWaitForData");
	return (g_SteamClientGameServer->SteamInput).BWaitForData(bWaitForever, Timeout);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInput_BNewDataAvailable(IpSteamInput pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInput_BNewDataAvailable");
	return (g_SteamClientGameServer->SteamInput).BNewDataAvailable();
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamInput_GetConnectedControllers(IpSteamInput pSelf, pInputHandle_t phController) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetConnectedControllers");
	return (g_SteamClientGameServer->SteamInput).GetConnectedControllers(phController);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_EnableDeviceCallbacks(IpSteamInput pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInput_EnableDeviceCallbacks");
	return (g_SteamClientGameServer->SteamInput).EnableDeviceCallbacks();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_EnableActionEventCallbacks(IpSteamInput pSelf, SteamInputActionEventCallback pFunction) {
	DEBUGBREAK("SteamAPI_ISteamInput_EnableActionEventCallbacks");
	return (g_SteamClientGameServer->SteamInput).EnableActionEventCallbacks(pFunction);
}

_FREE_API_ InputActionSetHandle_t _S_CALL_ SteamAPI_ISteamInput_GetActionSetHandle(IpSteamInput pSelf, pCStrA pchActionSetName) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetActionSetHandle");
	return (g_SteamClientGameServer->SteamInput).GetActionSetHandle(pchActionSetName);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_ActivateActionSet(IpSteamInput pSelf, InputHandle_t hController, InputActionSetHandle_t hActionSet) {
	DEBUGBREAK("SteamAPI_ISteamInput_ActivateActionSet");
	return (g_SteamClientGameServer->SteamInput).ActivateActionSet(hController, hActionSet);
}

_FREE_API_ InputActionSetHandle_t _S_CALL_ SteamAPI_ISteamInput_GetCurrentActionSet(IpSteamInput pSelf, InputHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetCurrentActionSet");
	return (g_SteamClientGameServer->SteamInput).GetCurrentActionSet(hController);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_ActivateActionSetLayer(IpSteamInput pSelf, InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("SteamAPI_ISteamInput_ActivateActionSetLayer");
	return (g_SteamClientGameServer->SteamInput).ActivateActionSetLayer(hController, hActionSetLayer);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_DeactivateActionSetLayer(IpSteamInput pSelf, InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("SteamAPI_ISteamInput_DeactivateActionSetLayer");
	return (g_SteamClientGameServer->SteamInput).DeactivateActionSetLayer(hController, hActionSetLayer);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_DeactivateAllActionSetLayers(IpSteamInput pSelf, InputHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamInput_DeactivateAllActionSetLayers");
	return (g_SteamClientGameServer->SteamInput).DeactivateAllActionSetLayers(hController);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamInput_GetActiveActionSetLayers(IpSteamInput pSelf, InputHandle_t hController, pInputActionSetHandle_t phActionSet) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetActiveActionSetLayers");
	return (g_SteamClientGameServer->SteamInput).GetActiveActionSetLayers(hController, phActionSet);
}

_FREE_API_ InputDigitalActionHandle_t _S_CALL_ SteamAPI_ISteamInput_GetDigitalActionHandle(IpSteamInput pSelf, pCStrA pchActionSetName) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetDigitalActionHandle");
	return (g_SteamClientGameServer->SteamInput).GetDigitalActionHandle(pchActionSetName);
}

_FREE_API_ InputDigitalActionData_t _S_CALL_ SteamAPI_ISteamInput_GetDigitalActionData(IpSteamInput pSelf, InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetDigitalActionData");
	return (g_SteamClientGameServer->SteamInput).GetDigitalActionData(hController, hDigitalAction);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamInput_GetDigitalActionOrigins(IpSteamInput pSelf, InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, pEInputActionOrigin peInputActionOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetDigitalActionOrigins");
	return (g_SteamClientGameServer->SteamInput).GetDigitalActionOrigins(hController, hActionSet, hDigitalAction, peInputActionOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetStringForDigitalActionName(IpSteamInput pSelf, InputDigitalActionHandle_t hDigitalAction) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetStringForDigitalActionName");
	return (g_SteamClientGameServer->SteamInput).GetStringForDigitalActionName(hDigitalAction);
}

_FREE_API_ InputAnalogActionHandle_t _S_CALL_ SteamAPI_ISteamInput_GetAnalogActionHandle(IpSteamInput pSelf, pCStrA pchActionSetName) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetAnalogActionHandle");
	return (g_SteamClientGameServer->SteamInput).GetAnalogActionHandle(pchActionSetName);
}

_FREE_API_ InputAnalogActionData_t _S_CALL_ SteamAPI_ISteamInput_GetAnalogActionData(IpSteamInput pSelf, InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetAnalogActionData");
	return (g_SteamClientGameServer->SteamInput).GetAnalogActionData(hController, hAnalogAction);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamInput_GetAnalogActionOrigins(IpSteamInput pSelf, InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, pEInputActionOrigin peInputActionOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetAnalogActionOrigins");
	return (g_SteamClientGameServer->SteamInput).GetAnalogActionOrigins(hController, hActionSet, hAnalogAction, peInputActionOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin(IpSteamInput pSelf, EInputActionOrigin eOrigin, ESteamInputGlyphSize eSize, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin");
	return (g_SteamClientGameServer->SteamInput).GetGlyphPNGForActionOrigin(eOrigin, eSize, nFlags);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetGlyphForActionOrigin(IpSteamInput pSelf, EInputActionOrigin eOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetGlyphForActionOrigin");
	return (g_SteamClientGameServer->SteamInput).GetGlyphForActionOrigin_Legacy(eOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin(IpSteamInput pSelf, EInputActionOrigin eOrigin, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin");
	return (g_SteamClientGameServer->SteamInput).GetGlyphSVGForActionOrigin(eOrigin, nFlags);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy(IpSteamInput pSelf, EInputActionOrigin eOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy");
	return (g_SteamClientGameServer->SteamInput).GetGlyphForActionOrigin_Legacy(eOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetStringForActionOrigin(IpSteamInput pSelf, EInputActionOrigin eOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetStringForActionOrigin");
	return (g_SteamClientGameServer->SteamInput).GetStringForActionOrigin(eOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetStringForAnalogActionName(IpSteamInput pSelf, InputAnalogActionHandle_t hDigitalAction) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetStringForAnalogActionName");
	return (g_SteamClientGameServer->SteamInput).GetStringForAnalogActionName(hDigitalAction);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_StopAnalogActionMomentum(IpSteamInput pSelf, InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("SteamAPI_ISteamInput_StopAnalogActionMomentum");
	return (g_SteamClientGameServer->SteamInput).StopAnalogActionMomentum(hController, hAnalogAction);
}

_FREE_API_ InputMotionData_t _S_CALL_ SteamAPI_ISteamInput_GetMotionData(IpSteamInput pSelf, InputHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetMotionData");
	return (g_SteamClientGameServer->SteamInput).GetMotionData(hController);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_TriggerVibration(IpSteamInput pSelf, InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) {
	DEBUGBREAK("SteamAPI_ISteamInput_TriggerVibration");
	return (g_SteamClientGameServer->SteamInput).TriggerVibration(hController, LeftSpeed, RightSpeed);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_TriggerVibrationExtended(IpSteamInput pSelf, InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed, Uint16 LeftTriggerSpeed, Uint16 RightTriggerSpeed) {
	DEBUGBREAK("SteamAPI_ISteamInput_TriggerVibrationExtended");
	return (g_SteamClientGameServer->SteamInput).TriggerVibrationExtended(hController, LeftSpeed, RightSpeed, LeftTriggerSpeed, RightTriggerSpeed);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_TriggerSimpleHapticEvent(IpSteamInput pSelf, InputHandle_t hController, EControllerHapticLocation eHapticLocation, Uint8 nIntensity, CharA nGainDB, Uint8 nOtherIntensity, CharA nOtherGainDB) {
	DEBUGBREAK("SteamAPI_ISteamInput_TriggerSimpleHapticEvent");
	return (g_SteamClientGameServer->SteamInput).TriggerSimpleHapticEvent(hController, eHapticLocation, nIntensity, nGainDB, nOtherIntensity, nOtherGainDB);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_SetLEDColor(IpSteamInput pSelf, InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamInput_SetLEDColor");
	return (g_SteamClientGameServer->SteamInput).SetLEDColor(hController, nColorR, nColorG, nColorB, nFlags);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_TriggerHapticPulse(IpSteamInput pSelf, InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) {
	DEBUGBREAK("SteamAPI_ISteamInput_TriggerHapticPulse");
	return (g_SteamClientGameServer->SteamInput).Legacy_TriggerHapticPulse(hController, eTargetPad, DurationMicroSeconds);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_TriggerRepeatedHapticPulse(IpSteamInput pSelf, InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamInput_TriggerRepeatedHapticPulse");
	return (g_SteamClientGameServer->SteamInput).Legacy_TriggerRepeatedHapticPulse(hController, eTargetPad, DurationMicroSeconds, OffMicroSeconds, nRepeat, nFlags);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_Legacy_TriggerHapticPulse(IpSteamInput pSelf, InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) {
	DEBUGBREAK("SteamAPI_ISteamInput_Legacy_TriggerHapticPulse");
	return (g_SteamClientGameServer->SteamInput).Legacy_TriggerHapticPulse(hController, eTargetPad, DurationMicroSeconds);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse(IpSteamInput pSelf, InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse");
	return (g_SteamClientGameServer->SteamInput).Legacy_TriggerRepeatedHapticPulse(hController, eTargetPad, DurationMicroSeconds, OffMicroSeconds, nRepeat, nFlags);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInput_ShowBindingPanel(IpSteamInput pSelf, InputHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamInput_ShowBindingPanel");
	return (g_SteamClientGameServer->SteamInput).ShowBindingPanel(hController);
}

_FREE_API_ ESteamInputType _S_CALL_ SteamAPI_ISteamInput_GetInputTypeForHandle(IpSteamInput pSelf, InputHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetInputTypeForHandle");
	return (g_SteamClientGameServer->SteamInput).GetInputTypeForHandle(hController);
}

_FREE_API_ InputHandle_t _S_CALL_ SteamAPI_ISteamInput_GetControllerForGamepadIndex(IpSteamInput pSelf, Int32 nIndex) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetControllerForGamepadIndex");
	return (g_SteamClientGameServer->SteamInput).GetControllerForGamepadIndex(nIndex);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamInput_GetGamepadIndexForController(IpSteamInput pSelf, InputHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetGamepadIndexForController");
	return (g_SteamClientGameServer->SteamInput).GetGamepadIndexForController(hController);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetStringForXboxOrigin(IpSteamInput pSelf, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetStringForXboxOrigin");
	return (g_SteamClientGameServer->SteamInput).GetStringForXboxOrigin(eXboxOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamInput_GetGlyphForXboxOrigin(IpSteamInput pSelf, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetGlyphForXboxOrigin");
	return (g_SteamClientGameServer->SteamInput).GetGlyphForXboxOrigin(eXboxOrigin);
}

_FREE_API_ EInputActionOrigin _S_CALL_ SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin(IpSteamInput pSelf, InputHandle_t hController, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin");
	return (g_SteamClientGameServer->SteamInput).GetActionOriginFromXboxOrigin(hController, eXboxOrigin);
}

_FREE_API_ EInputActionOrigin _S_CALL_ SteamAPI_ISteamInput_TranslateActionOrigin(IpSteamInput pSelf, ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin) {
	DEBUGBREAK("SteamAPI_ISteamInput_TranslateActionOrigin");
	return (g_SteamClientGameServer->SteamInput).TranslateActionOrigin(eDestinationInputType, eSourceOrigin);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInput_GetDeviceBindingRevision(IpSteamInput pSelf, InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetDeviceBindingRevision");
	return (g_SteamClientGameServer->SteamInput).GetDeviceBindingRevision(hController, pMajor, pMinor);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamInput_GetRemotePlaySessionID(IpSteamInput pSelf, InputHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetRemotePlaySessionID");
	return (g_SteamClientGameServer->SteamInput).GetRemotePlaySessionID(hController);
}

_FREE_API_ Uint16 _S_CALL_ SteamAPI_ISteamInput_GetSessionInputConfigurationSettings(IpSteamInput pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInput_GetSessionInputConfigurationSettings");
	return (g_SteamClientGameServer->SteamInput).GetSessionInputConfigurationSettings();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInput_SetDualSenseTriggerEffect(IpSteamInput pSelf, InputHandle_t hController, const pScePadTriggerEffect pScePadTriggerEffect) {
	DEBUGBREAK("SteamAPI_ISteamInput_SetDualSenseTriggerEffect");
	return (g_SteamClientGameServer->SteamInput).SetDualSenseTriggerEffect(hController, pScePadTriggerEffect);
}

/* ISteamController */

_FREE_API_ IpSteamController _S_CALL_ SteamAPI_SteamController_v007() {
	DEBUGBREAK("SteamAPI_SteamController_v007");
	return g_SteamClientGameServer->GetISteamController(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamController007"
	);
}

_FREE_API_ IpSteamController _S_CALL_ SteamAPI_SteamController_v008() {
	DEBUGBREAK("SteamAPI_SteamController_v008");
	return g_SteamClientGameServer->GetISteamController(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamController008"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamController_Init(IpSteamController pSelf) {
	DEBUGBREAK("SteamAPI_ISteamController_Init");
	return (g_SteamClientGameServer->SteamController).Init();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamController_Shutdown(IpSteamController pSelf) {
	DEBUGBREAK("SteamAPI_ISteamController_Shutdown");
	return (g_SteamClientGameServer->SteamController).Shutdown();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_RunFrame(IpSteamController pSelf) {
	DEBUGBREAK("SteamAPI_ISteamController_RunFrame");
	return (g_SteamClientGameServer->SteamController).RunFrame();
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamController_GetConnectedControllers(IpSteamController pSelf, pControllerHandle_t phController) {
	DEBUGBREAK("SteamAPI_ISteamController_GetConnectedControllers");
	return (g_SteamClientGameServer->SteamController).GetConnectedControllers(phController);
}

_FREE_API_ ControllerActionSetHandle_t _S_CALL_ SteamAPI_ISteamController_GetActionSetHandle(IpSteamController pSelf, pCStrA pchActionSetName) {
	DEBUGBREAK("SteamAPI_ISteamController_GetActionSetHandle");
	return (g_SteamClientGameServer->SteamController).GetActionSetHandle(pchActionSetName);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_ActivateActionSet(IpSteamController pSelf, ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet) {
	DEBUGBREAK("SteamAPI_ISteamController_ActivateActionSet");
	return (g_SteamClientGameServer->SteamController).ActivateActionSet(hController, hActionSet);
}

_FREE_API_ ControllerActionSetHandle_t _S_CALL_ SteamAPI_ISteamController_GetCurrentActionSet(IpSteamController pSelf, ControllerHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamController_GetCurrentActionSet");
	return (g_SteamClientGameServer->SteamController).GetCurrentActionSet(hController);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_ActivateActionSetLayer(IpSteamController pSelf, ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("SteamAPI_ISteamController_ActivateActionSetLayer");
	return (g_SteamClientGameServer->SteamController).ActivateActionSetLayer(hController, hActionSetLayer);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_DeactivateActionSetLayer(IpSteamController pSelf, ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("SteamAPI_ISteamController_DeactivateActionSetLayer");
	return (g_SteamClientGameServer->SteamController).DeactivateActionSetLayer(hController, hActionSetLayer);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_DeactivateAllActionSetLayers(IpSteamController pSelf, ControllerHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamController_DeactivateAllActionSetLayers");
	return (g_SteamClientGameServer->SteamController).DeactivateAllActionSetLayers(hController);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamController_GetActiveActionSetLayers(IpSteamController pSelf, ControllerHandle_t hController, pControllerActionSetHandle_t phActionSetLayer) {
	DEBUGBREAK("SteamAPI_ISteamController_GetActiveActionSetLayers");
	return (g_SteamClientGameServer->SteamController).GetActiveActionSetLayers(hController, phActionSetLayer);
}

_FREE_API_ ControllerDigitalActionHandle_t _S_CALL_ SteamAPI_ISteamController_GetDigitalActionHandle(IpSteamController pSelf, pCStrA pchActionSetName) {
	DEBUGBREAK("SteamAPI_ISteamController_GetDigitalActionHandle");
	return (g_SteamClientGameServer->SteamController).GetDigitalActionHandle(pchActionSetName);
}

_FREE_API_ InputDigitalActionData_t _S_CALL_ SteamAPI_ISteamController_GetDigitalActionData(IpSteamController pSelf, ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) {
	DEBUGBREAK("SteamAPI_ISteamController_GetDigitalActionData");
	return (g_SteamClientGameServer->SteamController).GetDigitalActionData(hController, hDigitalAction);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamController_GetDigitalActionOrigins(IpSteamController pSelf, ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, EControllerActionOrigin* peInputActionOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_GetDigitalActionOrigins");
	return (g_SteamClientGameServer->SteamController).GetDigitalActionOrigins(hController, hActionSet, hDigitalAction, peInputActionOrigin);
}

_FREE_API_ ControllerAnalogActionHandle_t _S_CALL_ SteamAPI_ISteamController_GetAnalogActionHandle(IpSteamController pSelf, pCStrA pchActionSetName) {
	DEBUGBREAK("SteamAPI_ISteamController_GetAnalogActionHandle");
	return (g_SteamClientGameServer->SteamController).GetAnalogActionHandle(pchActionSetName);
}

_FREE_API_ InputAnalogActionData_t _S_CALL_ SteamAPI_ISteamController_GetAnalogActionData(IpSteamController pSelf, ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("SteamAPI_ISteamController_GetAnalogActionData");
	return (g_SteamClientGameServer->SteamController).GetAnalogActionData(hController, hAnalogAction);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamController_GetAnalogActionOrigins(IpSteamController pSelf, ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, EControllerActionOrigin* peInputActionOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_GetAnalogActionOrigins");
	return (g_SteamClientGameServer->SteamController).GetAnalogActionOrigins(hController, hActionSet, hAnalogAction, peInputActionOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamController_GetGlyphForActionOrigin(IpSteamController pSelf, EControllerActionOrigin eControllerActionOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_GetGlyphForActionOrigin");
	return (g_SteamClientGameServer->SteamController).GetGlyphForActionOrigin(eControllerActionOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamController_GetStringForActionOrigin(IpSteamController pSelf, EControllerActionOrigin eControllerActionOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_GetStringForActionOrigin");
	return (g_SteamClientGameServer->SteamController).GetStringForActionOrigin(eControllerActionOrigin);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_StopAnalogActionMomentum(IpSteamController pSelf, ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("SteamAPI_ISteamController_StopAnalogActionMomentum");
	return (g_SteamClientGameServer->SteamController).StopAnalogActionMomentum(hController, hAnalogAction);
}

_FREE_API_ InputMotionData_t _S_CALL_ SteamAPI_ISteamController_GetMotionData(IpSteamController pSelf, ControllerHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamController_GetMotionData");
	return (g_SteamClientGameServer->SteamController).GetMotionData(hController);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_TriggerHapticPulse(IpSteamController pSelf, ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) {
	DEBUGBREAK("SteamAPI_ISteamController_TriggerHapticPulse");
	return (g_SteamClientGameServer->SteamController).TriggerHapticPulse(hController, eTargetPad, DurationMicroSeconds);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_TriggerRepeatedHapticPulse(IpSteamController pSelf, ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamController_TriggerRepeatedHapticPulse");
	return (g_SteamClientGameServer->SteamController).TriggerRepeatedHapticPulse(hController, eTargetPad, DurationMicroSeconds, OffMicroSeconds, nRepeat, nFlags);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_TriggerVibration(IpSteamController pSelf, ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) {
	DEBUGBREAK("SteamAPI_ISteamController_TriggerVibration");
	return (g_SteamClientGameServer->SteamController).TriggerVibration(hController, LeftSpeed, RightSpeed);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamController_SetLEDColor(IpSteamController pSelf, ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) {
	DEBUGBREAK("SteamAPI_ISteamController_SetLEDColor");
	return (g_SteamClientGameServer->SteamController).SetLEDColor(hController, nColorR, nColorG, nColorB, nFlags);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamController_ShowBindingPanel(IpSteamController pSelf, ControllerHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamController_ShowBindingPanel");
	return (g_SteamClientGameServer->SteamController).ShowBindingPanel(hController);
}

_FREE_API_ ESteamInputType _S_CALL_ SteamAPI_ISteamController_GetInputTypeForHandle(IpSteamController pSelf, ControllerHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamController_GetInputTypeForHandle");
	return (g_SteamClientGameServer->SteamController).GetInputTypeForHandle(hController);
}

_FREE_API_ ControllerHandle_t _S_CALL_ SteamAPI_ISteamController_GetControllerForGamepadIndex(IpSteamController pSelf, Int32 iController) {
	DEBUGBREAK("SteamAPI_ISteamController_GetControllerForGamepadIndex");
	return (g_SteamClientGameServer->SteamController).GetControllerForGamepadIndex(iController);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamController_GetGamepadIndexForController(IpSteamController pSelf, ControllerHandle_t hController) {
	DEBUGBREAK("SteamAPI_ISteamController_GetGamepadIndexForController");
	return (g_SteamClientGameServer->SteamController).GetGamepadIndexForController(hController);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamController_GetStringForXboxOrigin(IpSteamController pSelf, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_GetStringForXboxOrigin");
	return (g_SteamClientGameServer->SteamController).GetStringForXboxOrigin(eXboxOrigin);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamController_GetGlyphForXboxOrigin(IpSteamController pSelf, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_GetGlyphForXboxOrigin");
	return (g_SteamClientGameServer->SteamController).GetGlyphForXboxOrigin(eXboxOrigin);
}

_FREE_API_ EControllerActionOrigin _S_CALL_ SteamAPI_ISteamController_GetActionOriginFromXboxOrigin(IpSteamController pSelf, ControllerHandle_t hController, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_GetActionOriginFromXboxOrigin");
	return (g_SteamClientGameServer->SteamController).GetActionOriginFromXboxOrigin_(hController, eXboxOrigin);
}

_FREE_API_ EControllerActionOrigin _S_CALL_ SteamAPI_ISteamController_TranslateActionOrigin(IpSteamController pSelf, ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin) {
	DEBUGBREAK("SteamAPI_ISteamController_TranslateActionOrigin");
	return (g_SteamClientGameServer->SteamController).TranslateActionOrigin(eDestinationInputType, eSourceOrigin);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamController_GetControllerBindingRevision(IpSteamController pSelf, ControllerHandle_t hController, pInt32 pMajor, pInt32 pMinor) {
	DEBUGBREAK("SteamAPI_ISteamController_GetControllerBindingRevision");
	return (g_SteamClientGameServer->SteamController).GetControllerBindingRevision(hController, pMajor, pMinor);
}

/* ISteamUGC */

_FREE_API_ IpSteamUGC _S_CALL_ SteamAPI_SteamUGC_v014() {
	DEBUGBREAK("SteamAPI_SteamUGC_v014");
	return g_SteamClientGameServer->GetISteamUGC(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMUGC_INTERFACE_VERSION014"
	);
}

_FREE_API_ IpSteamUGC _S_CALL_ SteamAPI_SteamUGC_v015() {
	DEBUGBREAK("SteamAPI_SteamUGC_v015");
	return g_SteamClientGameServer->GetISteamUGC(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMUGC_INTERFACE_VERSION015"
	);
}

_FREE_API_ IpSteamUGC _S_CALL_ SteamAPI_SteamUGC_v016() {
	DEBUGBREAK("SteamAPI_SteamUGC_v016");
	return g_SteamClientGameServer->GetISteamUGC(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMUGC_INTERFACE_VERSION016"
	);
}

_FREE_API_ IpSteamUGC _S_CALL_ SteamAPI_SteamUGC_v017() {
	DEBUGBREAK("SteamAPI_SteamUGC_v017");
	return g_SteamClientGameServer->GetISteamUGC(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMUGC_INTERFACE_VERSION017"
	);
}

_FREE_API_ UGCQueryHandle_t _S_CALL_ SteamAPI_ISteamUGC_CreateQueryUserUGCRequest(IpSteamUGC pSelf, AccountId_t AccountId, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) {
	DEBUGBREAK("SteamAPI_ISteamUGC_CreateQueryUserUGCRequest");
	return (g_SteamClientGameServer->SteamUGC).CreateQueryUserUGCRequest(AccountId, eListType, eMatchingUGCType, eSortOrder, iCreatorAppId, iConsumerAppId, nPage);
}

_FREE_API_ UGCQueryHandle_t _S_CALL_ SteamAPI_ISteamUGC_CreateQueryAllUGCRequest(IpSteamUGC pSelf, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) {
	DEBUGBREAK("SteamAPI_ISteamUGC_CreateQueryAllUGCRequest");
	return (g_SteamClientGameServer->SteamUGC).CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, iCreatorAppId, iConsumerAppId, nPage);
}

_FREE_API_ UGCQueryHandle_t _S_CALL_ SteamAPI_ISteamUGC_CreateQueryAllUGCRequest0(IpSteamUGC pSelf, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) {
	DEBUGBREAK("SteamAPI_ISteamUGC_CreateQueryAllUGCRequest0");
	return (g_SteamClientGameServer->SteamUGC).CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, iCreatorAppId, iConsumerAppId, pchCursor);
}

_FREE_API_ UGCQueryHandle_t _S_CALL_ SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage(IpSteamUGC pSelf, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, Uint32 nPage) {
	DEBUGBREAK("SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage");
	return (g_SteamClientGameServer->SteamUGC).CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, iCreatorAppId, iConsumerAppId, nPage);
}

_FREE_API_ UGCQueryHandle_t _S_CALL_ SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor(IpSteamUGC pSelf, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t iCreatorAppId, AppId_t iConsumerAppId, pCStrA pchCursor) {
	DEBUGBREAK("SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor");
	return (g_SteamClientGameServer->SteamUGC).CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, iCreatorAppId, iConsumerAppId, pchCursor);
}

_FREE_API_ UGCQueryHandle_t _S_CALL_ SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest(IpSteamUGC pSelf, pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) {
	DEBUGBREAK("SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest");
	return (g_SteamClientGameServer->SteamUGC).CreateQueryUGCDetailsRequest(pPublishedFileId, nNumPublishedFileIds);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_SendQueryUGCRequest(IpSteamUGC pSelf, UGCQueryHandle_t hUGC) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SendQueryUGCRequest");
	return (g_SteamClientGameServer->SteamUGC).SendQueryUGCRequest(hUGC);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCResult(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, pSteamUGCDetails_t pDetails) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCResult");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCResult(hUGC, index, pDetails);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCNumTags(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCNumTags");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCNumTags(hUGC, index);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCTag(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, Uint32 indexTag, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCTag");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCTag(hUGC, index, indexTag, pchValue, cchValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, Uint32 indexTag, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCTagDisplayName(hUGC, index, indexTag, pchValue, cchValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCPreviewURL(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, pStrA pchURL, Uint32 cchURL) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCPreviewURL");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCPreviewURL(hUGC, index, pchURL, cchURL);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCMetadata(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, pStrA pchMetadata, Uint32 cchMetadata) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCMetadata");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCMetadata(hUGC, index, pchMetadata, cchMetadata);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCChildren(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, pPublishedFileId_t pPublishedFileId, Uint32 cMaxEntries) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCChildren");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCChildren(hUGC, index, pPublishedFileId, cMaxEntries);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCStatistic(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, EItemStatistic eStatType, pUint64 pStatValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCStatistic");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCStatistic(hUGC, index, eStatType, pStatValue);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCNumAdditionalPreviews(hUGC, index);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, Uint32 previewIndex, pStrA pchURLOrVideoId, Uint32 cchURL, pStrA pchOriginalFileName, Uint32 cchOriginalFileName, pEItemPreviewType peItemPreviewType) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCAdditionalPreview(hUGC, index, previewIndex, pchURLOrVideoId, cchURL, pchOriginalFileName, cchOriginalFileName, peItemPreviewType);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCNumKeyValueTags(hUGC, index);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag0(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, pStrA pchKey, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCKeyValueTag(hUGC, index, pchKey, pchValue, cchValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, Uint32 keyValueTagIndex, pStrA pchKey, Uint32 cchKey, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCKeyValueTag(hUGC, index, keyValueTagIndex,pchKey, cchKey, pchValue, cchValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, pCStrA pchKey, pStrA pchValue, Uint32 cchValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCKeyValueTag(hUGC, index, pchKey, pchValue, cchValue);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 index, pEUGCContentDescriptorId peDescriptors, Uint32 cMaxEntries) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetQueryUGCContentDescriptors");
	return (g_SteamClientGameServer->SteamUGC).GetQueryUGCContentDescriptors(hUGC, index, peDescriptors, cMaxEntries);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_ReleaseQueryUGCRequest(IpSteamUGC pSelf, UGCQueryHandle_t hUGC) {
	DEBUGBREAK("SteamAPI_ISteamUGC_ReleaseQueryUGCRequest");
	return (g_SteamClientGameServer->SteamUGC).ReleaseQueryUGCRequest(hUGC);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddRequiredTag(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, pCStrA pTagName) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddRequiredTag");
	return (g_SteamClientGameServer->SteamUGC).AddRequiredTag(hUGC, pTagName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddRequiredTagGroup(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, const pSteamParamStringArray_t pTagGroups) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddRequiredTagGroup");
	return (g_SteamClientGameServer->SteamUGC).AddRequiredTagGroup(hUGC, pTagGroups);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddExcludedTag(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, pCStrA pTagName) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddExcludedTag");
	return (g_SteamClientGameServer->SteamUGC).AddExcludedTag(hUGC, pTagName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnOnlyIDs(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bReturnOnlyIds) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnOnlyIDs");
	return (g_SteamClientGameServer->SteamUGC).SetReturnOnlyIds(hUGC, bReturnOnlyIds);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnKeyValueTags(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bReturnKeyValueTags) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnKeyValueTags");
	return (g_SteamClientGameServer->SteamUGC).SetReturnKeyValueTags(hUGC, bReturnKeyValueTags);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnLongDescription(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bReturnLongDescription) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnLongDescription");
	return (g_SteamClientGameServer->SteamUGC).SetReturnLongDescription(hUGC, bReturnLongDescription);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnMetadata(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bReturnMetadata) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnMetadata");
	return (g_SteamClientGameServer->SteamUGC).SetReturnMetadata(hUGC, bReturnMetadata);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnChildren(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bReturnChildren) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnChildren");
	return (g_SteamClientGameServer->SteamUGC).SetReturnChildren(hUGC, bReturnChildren);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnAdditionalPreviews(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bReturnAdditionalPreviews) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnAdditionalPreviews");
	return (g_SteamClientGameServer->SteamUGC).SetReturnAdditionalPreviews(hUGC, bReturnAdditionalPreviews);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnTotalOnly(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bReturnTotalOnly) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnTotalOnly");
	return (g_SteamClientGameServer->SteamUGC).SetReturnTotalOnly(hUGC, bReturnTotalOnly);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetReturnPlaytimeStats(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 nDays) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetReturnPlaytimeStats");
	return (g_SteamClientGameServer->SteamUGC).SetReturnPlaytimeStats(hUGC, nDays);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetLanguage(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, pCStrA pchLanguage) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetLanguage");
	return (g_SteamClientGameServer->SteamUGC).SetLanguage(hUGC, pchLanguage);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetAllowCachedResponse(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 nMaxAgeSeconds) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetAllowCachedResponse");
	return (g_SteamClientGameServer->SteamUGC).SetAllowCachedResponse(hUGC, nMaxAgeSeconds);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetCloudFileNameFilter(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, pCStrA pchMatchCloudFileName) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetCloudFileNameFilter");
	return (g_SteamClientGameServer->SteamUGC).SetCloudFileNameFilter(hUGC, pchMatchCloudFileName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetMatchAnyTag(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Bool bMatchAnyTag) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetMatchAnyTag");
	return (g_SteamClientGameServer->SteamUGC).SetMatchAnyTag(hUGC, bMatchAnyTag);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetSearchText(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, pCStrA pchSearchText) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetSearchText");
	return (g_SteamClientGameServer->SteamUGC).SetSearchText(hUGC, pchSearchText);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetRankedByTrendDays(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, Uint32 nDays) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetRankedByTrendDays");
	return (g_SteamClientGameServer->SteamUGC).SetRankedByTrendDays(hUGC, nDays);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetTimeCreatedDateRange(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, RTime32 Start, RTime32 End) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetTimeCreatedDateRange");
	return (g_SteamClientGameServer->SteamUGC).SetTimeCreatedDateRange(hUGC, Start, End);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetTimeUpdatedDateRange(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, RTime32 Start, RTime32 End) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetTimeUpdatedDateRange");
	return (g_SteamClientGameServer->SteamUGC).SetTimeUpdatedDateRange(hUGC, Start, End);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddRequiredKeyValueTag(IpSteamUGC pSelf, UGCQueryHandle_t hUGC, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddRequiredKeyValueTag");
	return (g_SteamClientGameServer->SteamUGC).AddRequiredKeyValueTag(hUGC, pchKey, pchValue);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_RequestUGCDetails(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId, Uint32 nMaxAgeSeconds) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RequestUGCDetails");
	return (g_SteamClientGameServer->SteamUGC).RequestUGCDetails(nPublishedFileId, nMaxAgeSeconds);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_CreateItem(IpSteamUGC pSelf, AppId_t iConsumerAppId, EWorkshopFileType eFileType) {
	DEBUGBREAK("SteamAPI_ISteamUGC_CreateItem");
	return (g_SteamClientGameServer->SteamUGC).CreateItem(iConsumerAppId, eFileType);
}

_FREE_API_ UGCUpdateHandle_t _S_CALL_ SteamAPI_ISteamUGC_StartItemUpdate(IpSteamUGC pSelf, AppId_t iConsumerAppId, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_StartItemUpdate");
	return (g_SteamClientGameServer->SteamUGC).StartItemUpdate(iConsumerAppId, nPublishedFileId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemTitle(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchTitle) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemTitle");
	return (g_SteamClientGameServer->SteamUGC).SetItemTitle(hUGC, pchTitle);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemDescription(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchDescription) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemDescription");
	return (g_SteamClientGameServer->SteamUGC).SetItemDescription(hUGC, pchDescription);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemUpdateLanguage(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchLanguage) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemUpdateLanguage");
	return (g_SteamClientGameServer->SteamUGC).SetItemUpdateLanguage(hUGC, pchLanguage);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemMetadata(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchMetaData) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemMetadata");
	return (g_SteamClientGameServer->SteamUGC).SetItemMetadata(hUGC, pchMetaData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemVisibility(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, ERemoteStoragePublishedFileVisibility eVisibility) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemVisibility");
	return (g_SteamClientGameServer->SteamUGC).SetItemVisibility(hUGC, eVisibility);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemTags(IpSteamUGC pSelf, UGCUpdateHandle_t hPublishedFileUpdate, const pSteamParamStringArray_t pTags) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemTags");
	return (g_SteamClientGameServer->SteamUGC).SetItemTags(hPublishedFileUpdate, pTags);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemContent(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchContentFolder) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemContent");
	return (g_SteamClientGameServer->SteamUGC).SetItemContent(hUGC, pchContentFolder);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetItemPreview(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchPreviewFile) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetItemPreview");
	return (g_SteamClientGameServer->SteamUGC).SetItemPreview(hUGC, pchPreviewFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_SetAllowLegacyUpload(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, Bool bAllowLegacyUpload) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetAllowLegacyUpload");
	return (g_SteamClientGameServer->SteamUGC).SetAllowLegacyUpload(hUGC, bAllowLegacyUpload);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags");
	return (g_SteamClientGameServer->SteamUGC).RemoveAllItemKeyValueTags(hUGC);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_RemoveItemKeyValueTags(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RemoveItemKeyValueTags");
	return (g_SteamClientGameServer->SteamUGC).RemoveItemKeyValueTags(hUGC, pchKey);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddItemKeyValueTag(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddItemKeyValueTag");
	return (g_SteamClientGameServer->SteamUGC).AddRequiredKeyValueTag(hUGC, pchKey, pchValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddItemPreviewFile(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchPreviewFile, EItemPreviewType eItemPreviewType) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddItemPreviewFile");
	return (g_SteamClientGameServer->SteamUGC).AddItemPreviewFile(hUGC, pchPreviewFile, eItemPreviewType);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddItemPreviewVideo(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchVideoId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddItemPreviewVideo");
	return (g_SteamClientGameServer->SteamUGC).AddItemPreviewVideo(hUGC, pchVideoId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_UpdateItemPreviewFile(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, Uint32 index, pCStrA pchPreviewFile) {
	DEBUGBREAK("SteamAPI_ISteamUGC_UpdateItemPreviewFile");
	return (g_SteamClientGameServer->SteamUGC).UpdateItemPreviewFile(hUGC, index, pchPreviewFile);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_UpdateItemPreviewVideo(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, Uint32 index, pCStrA pchVideoId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_UpdateItemPreviewVideo");
	return (g_SteamClientGameServer->SteamUGC).UpdateItemPreviewVideo(hUGC, index, pchVideoId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_RemoveItemPreview(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, Uint32 index) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RemoveItemPreview");
	return (g_SteamClientGameServer->SteamUGC).RemoveItemPreview(hUGC, index);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_AddContentDescriptor(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, EUGCContentDescriptorId eEUGCContentDescriptorId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddContentDescriptor");
	return (g_SteamClientGameServer->SteamUGC).AddContentDescriptor(hUGC, eEUGCContentDescriptorId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_RemoveContentDescriptor(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, EUGCContentDescriptorId eEUGCContentDescriptorId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RemoveContentDescriptor");
	return (g_SteamClientGameServer->SteamUGC).RemoveContentDescriptor(hUGC, eEUGCContentDescriptorId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_SubmitItemUpdate(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pCStrA pchChangeNote) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SubmitItemUpdate");
	return (g_SteamClientGameServer->SteamUGC).SubmitItemUpdate(hUGC, pchChangeNote);
}

_FREE_API_ EItemUpdateStatus _S_CALL_ SteamAPI_ISteamUGC_GetItemUpdateProgress(IpSteamUGC pSelf, UGCUpdateHandle_t hUGC, pUint64 pnBytesProcessed, pUint64 pnBytesTotal) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetItemUpdateProgress");
	return (g_SteamClientGameServer->SteamUGC).GetItemUpdateProgress(hUGC, pnBytesProcessed, pnBytesTotal);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_SetUserItemVote(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId, Bool bVoteUp) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SetUserItemVote");
	return (g_SteamClientGameServer->SteamUGC).SetUserItemVote(nPublishedFileId, bVoteUp);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_GetUserItemVote(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetUserItemVote");
	return (g_SteamClientGameServer->SteamUGC).GetUserItemVote(nPublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_AddItemToFavorites(IpSteamUGC pSelf, AppId_t iAppId, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddItemToFavorites");
	return (g_SteamClientGameServer->SteamUGC).AddItemToFavorites(iAppId, nPublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_RemoveItemFromFavorites(IpSteamUGC pSelf, AppId_t iAppId, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RemoveItemFromFavorites");
	return (g_SteamClientGameServer->SteamUGC).RemoveItemFromFavorites(iAppId, nPublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_SubscribeItem(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SubscribeItem");
	return (g_SteamClientGameServer->SteamUGC).SubscribeItem(nPublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_UnsubscribeItem(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_UnsubscribeItem");
	return (g_SteamClientGameServer->SteamUGC).UnsubscribeItem(nPublishedFileId);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUGC_GetNumSubscribedItems(IpSteamUGC pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetNumSubscribedItems");
	return (g_SteamClientGameServer->SteamUGC).GetNumSubscribedItems();
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUGC_GetSubscribedItems(IpSteamUGC pSelf, pPublishedFileId_t pPublishedFileId, Uint32 cMaxEntries) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetSubscribedItems");
	return (g_SteamClientGameServer->SteamUGC).GetSubscribedItems(pPublishedFileId, cMaxEntries);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamUGC_GetItemState(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetItemState");
	return (g_SteamClientGameServer->SteamUGC).GetItemState(nPublishedFileId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetItemInstallInfo(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId, pUint64 pnSizeOnDisk, pStrA pchFolder, Uint32 cchFolder, pUint32 pnTimeStamp) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetItemInstallInfo");
	return (g_SteamClientGameServer->SteamUGC).GetItemInstallInfo(nPublishedFileId, pnSizeOnDisk, pchFolder, cchFolder, pnTimeStamp);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_GetItemDownloadInfo(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId, pUint64 pnBytesDownloaded, pUint64 pnBytesTotal) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetItemDownloadInfo");
	return (g_SteamClientGameServer->SteamUGC).GetItemDownloadInfo(nPublishedFileId, pnBytesDownloaded, pnBytesTotal);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_DownloadItem(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId, Bool bHighPriority) {
	DEBUGBREAK("SteamAPI_ISteamUGC_DownloadItem");
	return (g_SteamClientGameServer->SteamUGC).DownloadItem(nPublishedFileId, bHighPriority);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_BInitWorkshopForGameServer(IpSteamUGC pSelf, DepotId_t nWorkshopDepotId, pCStrA pchFolder) {
	DEBUGBREAK("SteamAPI_ISteamUGC_BInitWorkshopForGameServer");
	return (g_SteamClientGameServer->SteamUGC).BInitWorkshopForGameServer(nWorkshopDepotId, pchFolder);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamUGC_SuspendDownloads(IpSteamUGC pSelf, Bool bSuspend) {
	DEBUGBREAK("SteamAPI_ISteamUGC_SuspendDownloads");
	return (g_SteamClientGameServer->SteamUGC).SuspendDownloads(bSuspend);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_StartPlaytimeTracking(IpSteamUGC pSelf, pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) {
	DEBUGBREAK("SteamAPI_ISteamUGC_StartPlaytimeTracking");
	return (g_SteamClientGameServer->SteamUGC).StartPlaytimeTracking(pPublishedFileId, nNumPublishedFileIds);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_StopPlaytimeTracking(IpSteamUGC pSelf, pPublishedFileId_t pPublishedFileId, Uint32 nNumPublishedFileIds) {
	DEBUGBREAK("SteamAPI_ISteamUGC_StopPlaytimeTracking");
	return (g_SteamClientGameServer->SteamUGC).StopPlaytimeTracking(pPublishedFileId, nNumPublishedFileIds);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems(IpSteamUGC pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems");
	return (g_SteamClientGameServer->SteamUGC).StopPlaytimeTrackingForAllItems();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_AddDependency(IpSteamUGC pSelf, PublishedFileId_t nParentPublishedFileId, PublishedFileId_t nChildPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddDependency");
	return (g_SteamClientGameServer->SteamUGC).AddDependency(nParentPublishedFileId, nChildPublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_RemoveDependency(IpSteamUGC pSelf, PublishedFileId_t nParentPublishedFileId, PublishedFileId_t nChildPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RemoveDependency");
	return (g_SteamClientGameServer->SteamUGC).RemoveDependency(nParentPublishedFileId, nChildPublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_AddAppDependency(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_AddAppDependency");
	return (g_SteamClientGameServer->SteamUGC).AddAppDependency(nPublishedFileId, iAppId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_RemoveAppDependency(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_RemoveAppDependency");
	return (g_SteamClientGameServer->SteamUGC).RemoveAppDependency(nPublishedFileId, iAppId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_GetAppDependencies(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetAppDependencies");
	return (g_SteamClientGameServer->SteamUGC).GetAppDependencies(nPublishedFileId);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_DeleteItem(IpSteamUGC pSelf, PublishedFileId_t nPublishedFileId) {
	DEBUGBREAK("SteamAPI_ISteamUGC_DeleteItem");
	return (g_SteamClientGameServer->SteamUGC).DeleteItem(nPublishedFileId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamUGC_ShowWorkshopEULA(IpSteamUGC pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUGC_ShowWorkshopEULA");
	return (g_SteamClientGameServer->SteamUGC).ShowWorkshopEULA();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamUGC_GetWorkshopEULAStatus(IpSteamUGC pSelf) {
	DEBUGBREAK("SteamAPI_ISteamUGC_GetWorkshopEULAStatus");
	return (g_SteamClientGameServer->SteamUGC).GetWorkshopEULAStatus();
}

/* ISteamAppList */

_FREE_API_ IpSteamAppList _S_CALL_ SteamAPI_SteamAppList_v001(){
	DEBUGBREAK("SteamAPI_SteamAppList_v001");
	return g_SteamClientGameServer->GetISteamAppList(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMAPPLIST_INTERFACE_VERSION001"
	);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamAppList_GetNumInstalledApps(IpSteamAppList pSelf) {
	DEBUGBREAK("SteamAPI_ISteamAppList_GetNumInstalledApps");
	return (g_SteamClientGameServer->SteamAppList).GetNumInstalledApps();
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamAppList_GetInstalledApps(IpSteamAppList pSelf, pAppId_t pnAppId, Uint32 nMaxAppIds) {
	DEBUGBREAK("SteamAPI_ISteamAppList_GetInstalledApps");
	return (g_SteamClientGameServer->SteamAppList).GetInstalledApps(pnAppId, nMaxAppIds);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamAppList_GetAppName(IpSteamAppList pSelf, AppId_t iAppId, pStrA pchName, Int32 cchName) {
	DEBUGBREAK("SteamAPI_ISteamAppList_GetAppName");
	return (g_SteamClientGameServer->SteamAppList).GetAppName(iAppId, pchName, cchName);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamAppList_GetAppInstallDir(IpSteamAppList pSelf, AppId_t iAppId, pStrA pchDirectory, Int32 cchDirectory) {
	DEBUGBREAK("SteamAPI_ISteamAppList_GetAppInstallDir");
	return (g_SteamClientGameServer->SteamAppList).GetAppInstallDir(iAppId, pchDirectory, cchDirectory);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamAppList_GetAppBuildId(IpSteamAppList pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamAppList_GetAppBuildId");
	return (g_SteamClientGameServer->SteamAppList).GetAppBuildId(iAppId);
}

/* ISteamHTMLSurface */

_FREE_API_ IpSteamHTMLSurface _S_CALL_ SteamAPI_SteamHTMLSurface_v005() {
	DEBUGBREAK("SteamAPI_SteamHTMLSurface_v005");
	return g_SteamClientGameServer->GetISteamHTMLSurface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMHTMLSURFACE_INTERFACE_VERSION_005"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTMLSurface_Init(IpSteamHTMLSurface pSelf) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_Init");
	return (g_SteamClientGameServer->SteamHTMLSurface).Init();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamHTMLSurface_Shutdown(IpSteamHTMLSurface pSelf) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_Shutdown");
	return (g_SteamClientGameServer->SteamHTMLSurface).Shutdown();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamHTMLSurface_CreateBrowser(IpSteamHTMLSurface pSelf, pCStrA pchUserAgent, pCStrA pchUserCSS) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_CreateBrowser");
	return (g_SteamClientGameServer->SteamHTMLSurface).CreateBrowser(pchUserAgent, pchUserCSS);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_RemoveBrowser(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_RemoveBrowser");
	return (g_SteamClientGameServer->SteamHTMLSurface).RemoveBrowser(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_LoadURL(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, pCStrA pchURL, pCStrA pchPostData) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_LoadURL");
	return (g_SteamClientGameServer->SteamHTMLSurface).LoadURL(hHTMLBrowser, pchURL, pchPostData);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetSize(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Uint32 Cx, Uint32 Cy) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetSize");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetSize(hHTMLBrowser, Cx, Cy);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_StopLoad(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_StopLoad");
	return (g_SteamClientGameServer->SteamHTMLSurface).StopLoad(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_Reload(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_Reload");
	return (g_SteamClientGameServer->SteamHTMLSurface).Reload(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_GoBack(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_GoBack");
	return (g_SteamClientGameServer->SteamHTMLSurface).GoBack(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_GoForward(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_GoForward");
	return (g_SteamClientGameServer->SteamHTMLSurface).GoForward(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_AddHeader(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_AddHeader");
	return (g_SteamClientGameServer->SteamHTMLSurface).AddHeader(hHTMLBrowser, pchKey, pchValue);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_ExecuteJavascript(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, pCStrA pchScript) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_ExecuteJavascript");
	return (g_SteamClientGameServer->SteamHTMLSurface).ExecuteJavascript(hHTMLBrowser, pchScript);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_MouseUp(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_MouseUp");
	return (g_SteamClientGameServer->SteamHTMLSurface).MouseUp(hHTMLBrowser, eMouseButton);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_MouseDown(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_MouseDown");
	return (g_SteamClientGameServer->SteamHTMLSurface).MouseDown(hHTMLBrowser, eMouseButton);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_MouseDoubleClick(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_MouseDoubleClick");
	return (g_SteamClientGameServer->SteamHTMLSurface).MouseDoubleClick(hHTMLBrowser, eMouseButton);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_MouseMove(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_MouseMove");
	return (g_SteamClientGameServer->SteamHTMLSurface).MouseMove(hHTMLBrowser, x, y);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_MouseWheel(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Int32 delta) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_MouseWheel");
	return (g_SteamClientGameServer->SteamHTMLSurface).MouseWheel(hHTMLBrowser, delta);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_KeyDown(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers, Bool bIsSystemKey) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_KeyDown");
	return (g_SteamClientGameServer->SteamHTMLSurface).KeyDown(hHTMLBrowser, nNativeKeyCode, eHTMLKeyModifiers, bIsSystemKey);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_KeyUp(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_KeyUp");
	return (g_SteamClientGameServer->SteamHTMLSurface).KeyUp(hHTMLBrowser, nNativeKeyCode, eHTMLKeyModifiers);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_KeyChar(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_KeyChar");
	return (g_SteamClientGameServer->SteamHTMLSurface).KeyChar(hHTMLBrowser, cUnicodeChar, eHTMLKeyModifiers);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetHorizontalScroll(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetHorizontalScroll");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetHorizontalScroll(hHTMLBrowser, nAbsolutePixelScroll);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetVerticalScroll(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetVerticalScroll");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetVerticalScroll(hHTMLBrowser, nAbsolutePixelScroll);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetKeyFocus(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Bool bHasKeyFocus) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetKeyFocus");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetKeyFocus(hHTMLBrowser, bHasKeyFocus);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_ViewSource(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_ViewSource");
	return (g_SteamClientGameServer->SteamHTMLSurface).ViewSource(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_CopyToClipboard(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_CopyToClipboard");
	return (g_SteamClientGameServer->SteamHTMLSurface).CopyToClipboard(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_PasteFromClipboard(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_PasteFromClipboard");
	return (g_SteamClientGameServer->SteamHTMLSurface).PasteFromClipboard(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_Find(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, pCStrA pchSearchStr, Bool bCurrentlyInFind, Bool bReverse) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_Find");
	return (g_SteamClientGameServer->SteamHTMLSurface).Find(hHTMLBrowser, pchSearchStr, bCurrentlyInFind, bReverse);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_StopFind(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_StopFind");
	return (g_SteamClientGameServer->SteamHTMLSurface).StopFind(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_GetLinkAtPosition(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_GetLinkAtPosition");
	return (g_SteamClientGameServer->SteamHTMLSurface).GetLinkAtPosition(hHTMLBrowser, x, y);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetCookie(IpSteamHTMLSurface pSelf, pCStrA pchHostname, pCStrA pchKey, pCStrA pchValue, pCStrA pchPath, RTime32 nExpires, Bool bSecure, Bool bHTTPOnly) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetCookie");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetPageScaleFactor(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Float Zoom, Int32 nPointX, Int32 nPointY) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetPageScaleFactor");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetPageScaleFactor(hHTMLBrowser, Zoom, nPointX, nPointY);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetBackgroundMode(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Bool bBackgroundMode) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetBackgroundMode");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetBackgroundMode(hHTMLBrowser, bBackgroundMode);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Float DPIScaling) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor");
	return (g_SteamClientGameServer->SteamHTMLSurface).SetDPIScalingFactor(hHTMLBrowser, DPIScaling);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_OpenDeveloperTools(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_OpenDeveloperTools");
	return (g_SteamClientGameServer->SteamHTMLSurface).OpenDeveloperTools(hHTMLBrowser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_AllowStartRequest(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Bool bAllowed) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_AllowStartRequest");
	return (g_SteamClientGameServer->SteamHTMLSurface).AllowStartRequest(hHTMLBrowser, bAllowed);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_JSDialogResponse(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, Bool bResult) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_JSDialogResponse");
	return (g_SteamClientGameServer->SteamHTMLSurface).JSDialogResponse(hHTMLBrowser, bResult);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse(IpSteamHTMLSurface pSelf, HTMLBrowser hHTMLBrowser, pCStrA *pchSelectedFiles) {
	DEBUGBREAK("SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse");
	return (g_SteamClientGameServer->SteamHTMLSurface).FileLoadDialogResponse(hHTMLBrowser, pchSelectedFiles);
}

/* ISteamInventory */

_FREE_API_ IpSteamInventory _S_CALL_ SteamAPI_SteamInventory_v003() {
	DEBUGBREAK("SteamAPI_SteamInventory_v003");
	return g_SteamClientGameServer->GetISteamInventory(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMINVENTORY_INTERFACE_V003"
	);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamInventory_GetResultStatus(IpSteamInventory pSelf, SteamInventoryResult_t hResult) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetResultStatus");
	return (g_SteamClientGameServer->SteamInventory).GetResultStatus(hResult);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetResultItems(IpSteamInventory pSelf, SteamInventoryResult_t hResult, pSteamItemDetails_t pItemsArray, pUint32 pnItemsArraySize) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetResultItems");
	return (g_SteamClientGameServer->SteamInventory).GetResultItems(hResult, pItemsArray, pnItemsArraySize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetResultItemProperty(IpSteamInventory pSelf, SteamInventoryResult_t hResult, Uint32 nItemIndex, pCStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetResultItemProperty");
	return (g_SteamClientGameServer->SteamInventory).GetResultItemProperty(hResult, nItemIndex, pchPropertyName, pchValue, pnValueSize);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamInventory_GetResultTimestamp(IpSteamInventory pSelf, SteamInventoryResult_t hResult) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetResultTimestamp");
	return (g_SteamClientGameServer->SteamInventory).GetResultTimestamp(hResult);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_CheckResultSteamID(IpSteamInventory pSelf, SteamInventoryResult_t hResult, SteamId_t_Uint64 SteamIdExpected) {
	DEBUGBREAK("SteamAPI_ISteamInventory_CheckResultSteamID");
	return (g_SteamClientGameServer->SteamInventory).CheckResultSteamId(hResult, SteamId_t{ SteamIdExpected });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInventory_DestroyResult(IpSteamInventory pSelf, SteamInventoryResult_t hResult) {
	DEBUGBREAK("SteamAPI_ISteamInventory_DestroyResult");
	return (g_SteamClientGameServer->SteamInventory).DestroyResult(hResult);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetAllItems(IpSteamInventory pSelf, pSteamInventoryResult_t phResult) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetAllItems");
	return (g_SteamClientGameServer->SteamInventory).GetAllItems(phResult);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetItemsByID(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, const pSteamItemInstanceId_t pInstanceIds, Uint32 nCountInstanceIds) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetItemsByID");
	return (g_SteamClientGameServer->SteamInventory).GetItemsById(phResult, pInstanceIds, nCountInstanceIds);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_SerializeResult(IpSteamInventory pSelf, SteamInventoryResult_t hResult, pVoid pvData, pUint32 pnData) {
	DEBUGBREAK("SteamAPI_ISteamInventory_SerializeResult");
	return (g_SteamClientGameServer->SteamInventory).SerializeResult(hResult, pvData, pnData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_DeserializeResult(IpSteamInventory pSelf, pSteamInventoryResult_t pOutResultHandle, pCVoid pvData, Uint32 nData, Bool bRESERVED_MUST_BE_FALSE) {
	DEBUGBREAK("SteamAPI_ISteamInventory_DeserializeResult");
	return (g_SteamClientGameServer->SteamInventory).DeserializeResult(pOutResultHandle, pvData, nData, bRESERVED_MUST_BE_FALSE);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GenerateItems(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, const pSteamItemDef_t pArrayItemDefs, const pUint32 pnArrayQuantity, Uint32 nArrayLength) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GenerateItems");
	return (g_SteamClientGameServer->SteamInventory).GenerateItems(phResult, pArrayItemDefs, pnArrayQuantity, nArrayLength);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GrantPromoItems(IpSteamInventory pSelf, pSteamInventoryResult_t phResult) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GrantPromoItems");
	return (g_SteamClientGameServer->SteamInventory).GrantPromoItems(phResult);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_AddPromoItem(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, SteamItemDef_t SteamItemDef) {
	DEBUGBREAK("SteamAPI_ISteamInventory_AddPromoItem");
	return (g_SteamClientGameServer->SteamInventory).AddPromoItem(phResult, SteamItemDef);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_AddPromoItems(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, const pSteamItemDef_t pArrayItemDefs, Uint32 nArrayLength) {
	DEBUGBREAK("SteamAPI_ISteamInventory_AddPromoItems");
	return (g_SteamClientGameServer->SteamInventory).AddPromoItems(phResult, pArrayItemDefs, nArrayLength);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_ConsumeItem(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, SteamItemInstanceId_t ConsumeItemId, Uint32 nQuantity) {
	DEBUGBREAK("SteamAPI_ISteamInventory_ConsumeItem");
	return (g_SteamClientGameServer->SteamInventory).ConsumeItem(phResult, ConsumeItemId, nQuantity);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_ExchangeItems(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, const pSteamItemDef_t pArrayGenerate, const pUint32 pnArrayGenerateQuantity, Uint32 nArrayGenerateLength, const pSteamItemInstanceId_t pArrayDestroy, const pUint32 pnArrayDestroyQuantity, Uint32 nArrayDestroyLength) {
	DEBUGBREAK("SteamAPI_ISteamInventory_ExchangeItems");
	return (g_SteamClientGameServer->SteamInventory).ExchangeItems(phResult, pArrayGenerate, pnArrayGenerateQuantity, nArrayGenerateLength, pArrayDestroy, pnArrayDestroyQuantity, nArrayDestroyLength);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_TransferItemQuantity(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, SteamItemInstanceId_t ItemIdSource, Uint32 nQuantity, SteamItemInstanceId_t ItemIdDest) {
	DEBUGBREAK("SteamAPI_ISteamInventory_TransferItemQuantity");
	return (g_SteamClientGameServer->SteamInventory).TransferItemQuantity(phResult, ItemIdSource, nQuantity, ItemIdDest);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamInventory_SendItemDropHeartbeat(IpSteamInventory pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInventory_SendItemDropHeartbeat");
	return (g_SteamClientGameServer->SteamInventory).SendItemDropHeartbeat();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_TriggerItemDrop(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, SteamItemDef_t DropListDefinition) {
	DEBUGBREAK("SteamAPI_ISteamInventory_TriggerItemDrop");
	return (g_SteamClientGameServer->SteamInventory).TriggerItemDrop(phResult, DropListDefinition);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_TradeItems(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, SteamId_t_Uint64 SteamIdTradePartner, const pSteamItemInstanceId_t pArrayGive, const pUint32 pArrayGiveQuantity, Uint32 nArrayGiveLength, const pSteamItemInstanceId_t pArrayGet, const pUint32 pArrayGetQuantity, Uint32 nArrayGetLength) {
	DEBUGBREAK("SteamAPI_ISteamInventory_TradeItems");
	return (g_SteamClientGameServer->SteamInventory).TradeItems(phResult, SteamId_t{ SteamIdTradePartner }, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_LoadItemDefinitions(IpSteamInventory pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInventory_LoadItemDefinitions");
	return (g_SteamClientGameServer->SteamInventory).LoadSteamItemDefinitions();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetItemDefinitionIDs(IpSteamInventory pSelf, pSteamItemDef_t pItemDefIds, pUint32 pnItemDefIDsArraySize) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetItemDefinitionIDs");
	return (g_SteamClientGameServer->SteamInventory).GetSteamItemDefinitionIds(pItemDefIds, pnItemDefIDsArraySize);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetItemDefinitionProperty(IpSteamInventory pSelf, SteamItemDef_t iDefinition, pCStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetItemDefinitionProperty");
	return (g_SteamClientGameServer->SteamInventory).GetSteamItemDefinitionProperty(iDefinition, pchPropertyName, pchValue, pnValueSize);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs(IpSteamInventory pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs");
	return (g_SteamClientGameServer->SteamInventory).RequestEligiblePromoSteamItemDefinitionsIds(SteamId_t{ SteamId });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs(IpSteamInventory pSelf, SteamId_t_Uint64 SteamId, pSteamItemDef_t pItemDefIds, pUint32 pnItemDefIdsArraySize) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs");
	return (g_SteamClientGameServer->SteamInventory).GetEligiblePromoSteamItemDefinitionIds(SteamId_t{ SteamId }, pItemDefIds, pnItemDefIdsArraySize);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamInventory_StartPurchase(IpSteamInventory pSelf, const pSteamItemDef_t pArrayItemDefs, const pUint32 pnArrayQuantity, Uint32 nArrayLength) {
	DEBUGBREAK("SteamAPI_ISteamInventory_StartPurchase");
	return (g_SteamClientGameServer->SteamInventory).StartPurchase(pArrayItemDefs, pnArrayQuantity, nArrayLength);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamInventory_RequestPrices(IpSteamInventory pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInventory_RequestPrices");
	return (g_SteamClientGameServer->SteamInventory).RequestPrices();
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamInventory_GetNumItemsWithPrices(IpSteamInventory pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetNumItemsWithPrices");
	return (g_SteamClientGameServer->SteamInventory).GetNumItemsWithPrices();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetItemsWithPrices(IpSteamInventory pSelf, pSteamItemDef_t pArrayItemDefs, pUint64 pCurrentPrices, pUint64 pBasePrices, Uint32 nArrayLength) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetItemsWithPrices");
	return (g_SteamClientGameServer->SteamInventory).GetItemsWithPrices(pArrayItemDefs, pCurrentPrices, pBasePrices, nArrayLength);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_GetItemPrice(IpSteamInventory pSelf, SteamItemDef_t iDefinition, pUint64 pCurrentPrice, pUint64 pBasePrice) {
	DEBUGBREAK("SteamAPI_ISteamInventory_GetItemPrice");
	return (g_SteamClientGameServer->SteamInventory).GetItemPrice(iDefinition, pCurrentPrice, pBasePrice);
}

_FREE_API_ SteamInventoryUpdateHandle_t _S_CALL_ SteamAPI_ISteamInventory_StartUpdateProperties(IpSteamInventory pSelf) {
	DEBUGBREAK("SteamAPI_ISteamInventory_StartUpdateProperties");
	return (g_SteamClientGameServer->SteamInventory).StartUpdateProperties();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_RemoveProperty(IpSteamInventory pSelf, SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName) {
	DEBUGBREAK("SteamAPI_ISteamInventory_RemoveProperty");
	return (g_SteamClientGameServer->SteamInventory).RemoveProperty(hSteamInventoryUpdate, nItemId, pchPropertyName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_SetPropertyString(IpSteamInventory pSelf, SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, pCStrA pchPropertyValue) {
	DEBUGBREAK("SteamAPI_ISteamInventory_SetPropertyString");
	return (g_SteamClientGameServer->SteamInventory).SetProperty(hSteamInventoryUpdate, nItemId, pchPropertyName, pchPropertyValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_SetPropertyBool(IpSteamInventory pSelf, SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Bool bValue) {
	DEBUGBREAK("SteamAPI_ISteamInventory_SetPropertyBool");
	return (g_SteamClientGameServer->SteamInventory).SetProperty(hSteamInventoryUpdate, nItemId, pchPropertyName, bValue);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_SetPropertyInt64(IpSteamInventory pSelf, SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Int64 Value) {
	DEBUGBREAK("SteamAPI_ISteamInventory_SetPropertyInt64");
	return (g_SteamClientGameServer->SteamInventory).SetProperty(hSteamInventoryUpdate, nItemId, pchPropertyName, Value);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_SetPropertyFloat(IpSteamInventory pSelf, SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Float Value) {
	DEBUGBREAK("SteamAPI_ISteamInventory_SetPropertyFloat");
	return (g_SteamClientGameServer->SteamInventory).SetProperty(hSteamInventoryUpdate, nItemId, pchPropertyName, Value);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_SubmitUpdateProperties(IpSteamInventory pSelf, SteamInventoryUpdateHandle_t hSteamInventoryUpdate, pSteamInventoryResult_t phResult) {
	DEBUGBREAK("SteamAPI_ISteamInventory_SubmitUpdateProperties");
	return (g_SteamClientGameServer->SteamInventory).SubmitUpdateProperties(hSteamInventoryUpdate, phResult);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamInventory_InspectItem(IpSteamInventory pSelf, pSteamInventoryResult_t phResult, pCStrA pchItemToken) {
	DEBUGBREAK("SteamAPI_ISteamInventory_InspectItem");
	return (g_SteamClientGameServer->SteamInventory).InspectItem(phResult, pchItemToken);
}

/* ISteamVideo */

_FREE_API_ IpSteamVideo _S_CALL_ SteamAPI_SteamVideo_v002() {
	DEBUGBREAK("SteamAPI_SteamVideo_v002");
	return g_SteamClientGameServer->GetISteamVideo(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMVIDEO_INTERFACE_V002"
	);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamVideo_GetVideoURL(IpSteamVideo pSelf, AppId_t iVideoAppId) {
	DEBUGBREAK("SteamAPI_ISteamVideo_GetVideoURL");
	return (g_SteamClientGameServer->SteamVideo).GetVideoURL(iVideoAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamVideo_IsBroadcasting(IpSteamVideo pSelf, pInt32 pnNumViewers) {
	DEBUGBREAK("SteamAPI_ISteamVideo_IsBroadcasting");
	return (g_SteamClientGameServer->SteamVideo).IsBroadcasting(pnNumViewers);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamVideo_GetOPFSettings(IpSteamVideo pSelf, AppId_t iVideoAppId) {
	DEBUGBREAK("SteamAPI_ISteamVideo_GetOPFSettings");
	return (g_SteamClientGameServer->SteamVideo).GetOPFSettings(iVideoAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamVideo_GetOPFStringForApp(IpSteamVideo pSelf, AppId_t iVideoAppId, pStrA pchOPFString, pInt32 pnOPFString) {
	DEBUGBREAK("SteamAPI_ISteamVideo_GetOPFStringForApp");
	return (g_SteamClientGameServer->SteamVideo).GetOPFStringForApp(iVideoAppId, pchOPFString, pnOPFString);
}

/* ISteamTV */

_FREE_API_ IpSteamTV _S_CALL_ SteamAPI_SteamTV_v001() {
	DEBUGBREAK("SteamAPI_SteamTV_v001");
	return (IpSteamTV)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMTV_INTERFACE_V001"
	));
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamTV_IsBroadcasting(IpSteamTV pSelf, pInt32 pnNumViewers) {
	DEBUGBREAK("SteamAPI_ISteamTV_IsBroadcasting");
	return (g_SteamClientGameServer->SteamTV).IsBroadcasting(pnNumViewers);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamTV_AddBroadcastGameData(IpSteamTV pSelf, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamTV_AddBroadcastGameData");
	return (g_SteamClientGameServer->SteamTV).AddBroadcastGameData(pchKey, pchValue);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamTV_RemoveBroadcastGameData(IpSteamTV pSelf, pCStrA pchKey) {
	DEBUGBREAK("SteamAPI_ISteamTV_RemoveBroadcastGameData");
	return (g_SteamClientGameServer->SteamTV).RemoveBroadcastGameData(pchKey);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamTV_AddTimelineMarker(IpSteamTV pSelf, pCStrA pchTemplateName, Bool bPersistent, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB) {
	DEBUGBREAK("SteamAPI_ISteamTV_AddTimelineMarker");
	return (g_SteamClientGameServer->SteamTV).AddTimelineMarker(pchTemplateName, bPersistent, nColorR, nColorG, nColorB);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamTV_RemoveTimelineMarker(IpSteamTV pSelf) {
	DEBUGBREAK("SteamAPI_ISteamTV_RemoveTimelineMarker");
	return (g_SteamClientGameServer->SteamTV).RemoveTimelineMarker();
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamTV_AddRegion(IpSteamTV pSelf, pCStrA pchElementName, pCStrA pchTimelineDataSection, pCVoid pvSteamTVRegion, Int32 eSteamTVRegionBehavior) {
	DEBUGBREAK("SteamAPI_ISteamTV_AddRegion");
	return (g_SteamClientGameServer->SteamTV).AddRegion(pchElementName, pchTimelineDataSection, pvSteamTVRegion, eSteamTVRegionBehavior);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamTV_RemoveRegion(IpSteamTV pSelf, Uint32 hRegion) {
	DEBUGBREAK("SteamAPI_ISteamTV_RemoveRegion");
	return (g_SteamClientGameServer->SteamTV).RemoveRegion(hRegion);
}

/* ISteamParentalSettings */

_FREE_API_ IpSteamParentalSettings _S_CALL_ SteamAPI_SteamParentalSettings_v001() {
	DEBUGBREAK("SteamAPI_SteamParentalSettings_v001");
	return g_SteamClientGameServer->GetISteamParentalSettings(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMPARENTALSETTINGS_INTERFACE_VERSION001"
	);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled(IpSteamParentalSettings pSelf) {
	DEBUGBREAK("SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled");
	return (g_SteamClientGameServer->SteamParentalSettings).BIsParentalLockEnabled();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParentalSettings_BIsParentalLockLocked(IpSteamParentalSettings pSelf) {
	DEBUGBREAK("SteamAPI_ISteamParentalSettings_BIsParentalLockLocked");
	return (g_SteamClientGameServer->SteamParentalSettings).BIsParentalLockLocked();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParentalSettings_BIsAppBlocked(IpSteamParentalSettings pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamParentalSettings_BIsAppBlocked");
	return (g_SteamClientGameServer->SteamParentalSettings).BIsAppBlocked(iAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParentalSettings_BIsAppInBlockList(IpSteamParentalSettings pSelf, AppId_t iAppId) {
	DEBUGBREAK("SteamAPI_ISteamParentalSettings_BIsAppInBlockList");
	return (g_SteamClientGameServer->SteamParentalSettings).BIsAppInBlockList(iAppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParentalSettings_BIsFeatureBlocked(IpSteamParentalSettings pSelf, EParentalFeature eParentalFeature) {
	DEBUGBREAK("SteamAPI_ISteamParentalSettings_BIsFeatureBlocked");
	return (g_SteamClientGameServer->SteamParentalSettings).BIsFeatureBlocked(eParentalFeature);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList(IpSteamParentalSettings pSelf, EParentalFeature eParentalFeature) {
	DEBUGBREAK("SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList");
	return (g_SteamClientGameServer->SteamParentalSettings).BIsFeatureInBlockList(eParentalFeature);
}

/* ISteamRemotePlay */

_FREE_API_ IpSteamRemotePlay _S_CALL_ SteamAPI_SteamRemotePlay_v001() {
	DEBUGBREAK("SteamAPI_SteamRemotePlay_v001");
	return g_SteamClientGameServer->GetISteamRemotePlay(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "STEAMREMOTEPLAY_INTERFACE_VERSION001"
	);
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_ISteamRemotePlay_GetSessionCount(IpSteamRemotePlay pSelf) {
	DEBUGBREAK("SteamAPI_ISteamRemotePlay_GetSessionCount");
	return (g_SteamClientGameServer->SteamRemotePlay).GetSessionCount();
}

_FREE_API_ RemotePlaySessionId_t _S_CALL_ SteamAPI_ISteamRemotePlay_GetSessionID(IpSteamRemotePlay pSelf, Int32 iSessionIndex) {
	DEBUGBREAK("SteamAPI_ISteamRemotePlay_GetSessionID");
	return (g_SteamClientGameServer->SteamRemotePlay).GetSessionID(iSessionIndex);
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamRemotePlay_GetSessionSteamID(IpSteamRemotePlay pSelf, RemotePlaySessionId_t SessionId) {
	DEBUGBREAK("SteamAPI_ISteamRemotePlay_GetSessionSteamID");
	return (g_SteamClientGameServer->SteamRemotePlay).GetSessionSteamID(SessionId).SteamId_Uint64;
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamRemotePlay_GetSessionClientName(IpSteamRemotePlay pSelf, RemotePlaySessionId_t SessionId) {
	DEBUGBREAK("SteamAPI_ISteamRemotePlay_GetSessionClientName");
	return (g_SteamClientGameServer->SteamRemotePlay).GetSessionClientName(SessionId);
}

_FREE_API_ ESteamDeviceFormFactor _S_CALL_ SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor(IpSteamRemotePlay pSelf, RemotePlaySessionId_t SessionId) {
	DEBUGBREAK("SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor");
	return (g_SteamClientGameServer->SteamRemotePlay).GetSessionClientFormFactor(SessionId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemotePlay_BGetSessionClientResolution(IpSteamRemotePlay pSelf, RemotePlaySessionId_t SessionId, pInt32 pCx, pInt32 pCy) {
	DEBUGBREAK("SteamAPI_ISteamRemotePlay_BGetSessionClientResolution");
	return (g_SteamClientGameServer->SteamRemotePlay).BGetSessionClientResolution(SessionId, pCx, pCy);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite(IpSteamRemotePlay pSelf, SteamId_t_Uint64 SteamIdFriend) {
	DEBUGBREAK("SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite");
	return (g_SteamClientGameServer->SteamRemotePlay).BSendRemotePlayTogetherInvite(SteamId_t{ SteamIdFriend });
}

/* ISteamNetworkingMessages */

_FREE_API_ IpSteamNetworkingMessages _S_CALL_ SteamAPI_SteamNetworkingMessages_v002() {
	DEBUGBREAK("SteamAPI_SteamNetworkingMessages_v002");
	return (IpSteamNetworkingMessages)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworkingMessages002"
	));
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingMessages_SendMessageToUser(IpSteamNetworkingMessages pSelf, const pSteamNetworkingIdentity pIdentityRemote, pCVoid pvData, Uint32 cbData, Int32 nSendFlags, Int32 nRemoteChannel) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingMessages_SendMessageToUser");
	return (g_SteamClientGameServer->SteamNetworkingMessages).SendMessageToUser(pIdentityRemote, pvData, cbData, nSendFlags, nRemoteChannel);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel(IpSteamNetworkingMessages pSelf, Int32 nLocalChannel, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel");
	return (g_SteamClientGameServer->SteamNetworkingMessages).ReceiveMessagesOnChannel(nLocalChannel, ppMessages, nMessages);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser(IpSteamNetworkingMessages pSelf, const pSteamNetworkingIdentity pIdentityRemote) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser");
	return (g_SteamClientGameServer->SteamNetworkingMessages).AcceptSessionWithUser(pIdentityRemote);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser(IpSteamNetworkingMessages pSelf, const pSteamNetworkingIdentity pIdentityRemote) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser");
	return (g_SteamClientGameServer->SteamNetworkingMessages).CloseSessionWithUser(pIdentityRemote);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser(IpSteamNetworkingMessages pSelf, const pSteamNetworkingIdentity pIdentityRemote, Int32 nLocalChannel) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser");
	return (g_SteamClientGameServer->SteamNetworkingMessages).CloseChannelWithUser(pIdentityRemote, nLocalChannel);
}

_FREE_API_ ESteamNetworkingConnectionState _S_CALL_ SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo(IpSteamNetworkingMessages pSelf, const pSteamNetworkingIdentity pIdentityRemote, pSteamNetConnectionInfo_t pConnectionInfo, pSteamNetConnectionRealTimeStatus_t pQuickStatus) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo");
	return (g_SteamClientGameServer->SteamNetworkingMessages).GetSessionConnectionInfo(pIdentityRemote, pConnectionInfo, pQuickStatus);
}

/* ISteamNetworkingSockets */

_FREE_API_ IpSteamNetworkingSockets _S_CALL_ SteamAPI_SteamNetworkingSockets_v008() {
	DEBUGBREAK("SteamAPI_SteamNetworkingSockets_v008");
	return (IpSteamNetworkingSockets)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworkingSockets008"
	));
}

_FREE_API_ IpSteamNetworkingSockets _S_CALL_ SteamAPI_SteamNetworkingSockets_v009() {
	DEBUGBREAK("SteamAPI_SteamNetworkingSockets_v009");
	return (IpSteamNetworkingSockets)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworkingSockets009"
	));
}

_FREE_API_ IpSteamNetworkingSockets _S_CALL_ SteamAPI_SteamNetworkingSockets_v011() {
	DEBUGBREAK("SteamAPI_SteamNetworkingSockets_v011");
	return (IpSteamNetworkingSockets)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworkingSockets011"
	));
}

_FREE_API_ IpSteamNetworkingSockets _S_CALL_ SteamAPI_SteamNetworkingSockets_v012() {
	DEBUGBREAK("SteamAPI_SteamNetworkingSockets_v012");
	return (IpSteamNetworkingSockets)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworkingSockets012"
	));
}

_FREE_API_ HSteamListenSocket _S_CALL_ SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP(IpSteamNetworkingSockets pSelf, const pSteamNetworkingIPAddr pLocalAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CreateListenSocketIP(pLocalAddr, nOptions, pOptions);
}

_FREE_API_ HSteamNetConnection _S_CALL_ SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress(IpSteamNetworkingSockets pSelf, const pSteamNetworkingIPAddr pAddr, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ConnectByIPAddress(pAddr, nOptions, pOptions);
}

_FREE_API_ HSteamListenSocket _S_CALL_ SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P(IpSteamNetworkingSockets pSelf, Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CreateListenSocketP2P(nLocalVirtualPort, nOptions, pOptions);
}

_FREE_API_ HSteamNetConnection _S_CALL_ SteamAPI_ISteamNetworkingSockets_ConnectP2P(IpSteamNetworkingSockets pSelf, const pSteamNetworkingIdentity pIdentityRemote, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ConnectP2P");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ConnectP2P(pIdentityRemote, nRemoteVirtualPort, nOptions, pOptions);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_AcceptConnection(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_AcceptConnection");
	return (g_SteamClientGameServer->SteamNetworkingSockets).AcceptConnection(hConnection);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_CloseConnection(IpSteamNetworkingSockets pSelf, HSteamNetConnection hPeer, Int32 nReason, pCStrA pchDebug, Bool bEnableLinger) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CloseConnection");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CloseConnection(hPeer, nReason, pchDebug, bEnableLinger);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_CloseListenSocket(IpSteamNetworkingSockets pSelf, HSteamListenSocket hSocket) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CloseListenSocket");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CloseListenSocket(hSocket);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_SetConnectionUserData(IpSteamNetworkingSockets pSelf, HSteamNetConnection hPeer, Int64 nUserData) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_SetConnectionUserData");
	return (g_SteamClientGameServer->SteamNetworkingSockets).SetConnectionUserData(hPeer, nUserData);
}

_FREE_API_ Int64 _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetConnectionUserData(IpSteamNetworkingSockets pSelf, HSteamNetConnection hPeer) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetConnectionUserData");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetConnectionUserData(hPeer);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingSockets_SetConnectionName(IpSteamNetworkingSockets pSelf, HSteamNetConnection hPeer, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_SetConnectionName");
	return (g_SteamClientGameServer->SteamNetworkingSockets).SetConnectionName(hPeer, pchName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetConnectionName(IpSteamNetworkingSockets pSelf, HSteamNetConnection hPeer, pStrA pchName, Int32 cchName) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetConnectionName");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetConnectionName(hPeer, pchName, cchName);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_SendMessageToConnection(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, pCVoid pvData, Uint32 cbData, Int32 nSendFlags, pInt64 pOutMessageNumber) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_SendMessageToConnection");
	return (g_SteamClientGameServer->SteamNetworkingSockets).SendMessageToConnection(hConnection, pvData, cbData, nSendFlags, pOutMessageNumber);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingSockets_SendMessages(IpSteamNetworkingSockets pSelf, Int32 nMessages, pSteamNetworkingMessage_t *pMessages, pInt64 pMessageNumberOrResult) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_SendMessages");
	return (g_SteamClientGameServer->SteamNetworkingSockets).SendMessages(nMessages, pMessages, pMessageNumberOrResult);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection");
	return (g_SteamClientGameServer->SteamNetworkingSockets).FlushMessagesOnConnection(hConnection);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ReceiveMessagesOnConnection(hConnection, ppMessages, nMessages);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetConnectionInfo(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, pSteamNetConnectionInfo_t pInfo) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetConnectionInfo");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetConnectionInfo(hConnection, pInfo);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStatus, Int32 nLanes, pSteamNetConnectionRealTimeLaneStatus_t pLanes) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetConnectionRealTimeStatus(hConnection, pStatus, nLanes, pLanes);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetQuickConnectionStatus(IpSteamNetworkingSockets009 pSelf, HSteamNetConnection hConnection, pSteamNetConnectionRealTimeStatus_t pStats) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetQuickConnectionStatus");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetQuickConnectionStatus(hConnection, pStats);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, pStrA pchString, Int32 cchString) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetDetailedConnectionStatus(hConnection, pchString, cchString);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress(IpSteamNetworkingSockets pSelf, HSteamListenSocket hSocket, pSteamNetworkingIPAddr pSteamNetworkingIPAddr) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetListenSocketAddress(hSocket, pSteamNetworkingIPAddr);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_CreateSocketPair(IpSteamNetworkingSockets pSelf, pHSteamNetConnection phConnection1, pHSteamNetConnection phConnection2, Bool bUseNetworkLoopback, const pSteamNetworkingIdentity pIdentity1, const pSteamNetworkingIdentity pIdentity2) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CreateSocketPair");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CreateSocketPair(phConnection1, phConnection2, bUseNetworkLoopback, pIdentity1, pIdentity2);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, Int32 nNumLanes, const pInt32 pLanePriorities, const pUint16 pLaneWeights) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ConfigureConnectionLanes(hConnection, nNumLanes, pLanePriorities, pLaneWeights);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetIdentity(IpSteamNetworkingSockets pSelf, pSteamNetworkingIdentity pIdentity) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetIdentity");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetIdentity(pIdentity);
}

_FREE_API_ ESteamNetworkingAvailability _S_CALL_ SteamAPI_ISteamNetworkingSockets_InitAuthentication(IpSteamNetworkingSockets pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_InitAuthentication");
	return (g_SteamClientGameServer->SteamNetworkingSockets).InitAuthentication();
}

_FREE_API_ ESteamNetworkingAvailability _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus(IpSteamNetworkingSockets pSelf, pSteamNetAuthenticationStatus_t pDetails) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetAuthenticationStatus(pDetails);
}

_FREE_API_ HSteamNetPollGroup _S_CALL_ SteamAPI_ISteamNetworkingSockets_CreatePollGroup(IpSteamNetworkingSockets pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CreatePollGroup");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CreatePollGroup();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_DestroyPollGroup(IpSteamNetworkingSockets pSelf, HSteamNetPollGroup hPollGroup) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_DestroyPollGroup");
	return (g_SteamClientGameServer->SteamNetworkingSockets).DestroyPollGroup(hPollGroup);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, HSteamNetPollGroup hPollGroup) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup");
	return (g_SteamClientGameServer->SteamNetworkingSockets).SetConnectionPollGroup(hConnection, hPollGroup);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup(IpSteamNetworkingSockets pSelf, HSteamNetPollGroup hPollGroup, pSteamNetworkingMessage_t *ppMessages, Int32 nMessages) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ReceiveMessagesOnPollGroup(hPollGroup, ppMessages, nMessages);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket(IpSteamNetworkingSockets pSelf, pCVoid pvTicket, Int32 cbTicket, pSteamDatagramRelayAuthTicket pParsedTicket) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ReceivedRelayAuthTicket(pvTicket, cbTicket, pParsedTicket);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer(IpSteamNetworkingSockets pSelf, const pSteamNetworkingIdentity pIdentityGameServer, Int32 nRemoteVirtualPort, pSteamDatagramRelayAuthTicket pParsedTicket) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer");
	return (g_SteamClientGameServer->SteamNetworkingSockets).FindRelayAuthTicketForServer(pIdentityGameServer, nRemoteVirtualPort, pParsedTicket);
}

_FREE_API_ HSteamNetConnection _S_CALL_ SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer(IpSteamNetworkingSockets pSelf, const pSteamNetworkingIdentity pIdentityTarget, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ConnectToHostedDedicatedServer(pIdentityTarget, nRemoteVirtualPort, nOptions, pOptions);
}

_FREE_API_ Uint16 _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort(IpSteamNetworkingSockets pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetHostedDedicatedServerPort();
}

_FREE_API_ SteamNetworkingPOPID _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID(IpSteamNetworkingSockets pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetHostedDedicatedServerPOPID();
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress(IpSteamNetworkingSockets pSelf, pSteamDatagramHostedAddress pRouting) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetHostedDedicatedServerAddress(pRouting);
}

_FREE_API_ HSteamListenSocket _S_CALL_ SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket(IpSteamNetworkingSockets pSelf, Int32 nLocalVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CreateHostedDedicatedServerListenSocket(nLocalVirtualPort, nOptions, pOptions);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin(IpSteamNetworkingSockets pSelf, pSteamDatagramGameCoordinatorServerLogin pLoginInfo, pInt32 pcbSignedBlob, pVoid pvBlob) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetGameCoordinatorServerLogin(pLoginInfo, pcbSignedBlob, pvBlob);
}

_FREE_API_ HSteamNetConnection _S_CALL_ SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling(IpSteamNetworkingSockets pSelf, IpSteamNetworkingConnectionCustomSignaling pSignaling, const pSteamNetworkingIdentity pPeerIdentity, Int32 nRemoteVirtualPort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ConnectP2PCustomSignaling(pSignaling, pPeerIdentity, nRemoteVirtualPort, nOptions, pOptions);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal(IpSteamNetworkingSockets pSelf, pCVoid pMsg, Int32 cbMsg, IpSteamNetworkingCustomSignalingRecvContext pContext) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ReceivedP2PCustomSignal(pMsg, cbMsg, pContext);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetCertificateRequest(IpSteamNetworkingSockets pSelf, pInt32 pcbBlob, pVoid pvBlob, pSteamNetworkingErrMsg pErrMsg) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetCertificateRequest");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetCertificateRequest(pcbBlob, pvBlob, pErrMsg);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_SetCertificate(IpSteamNetworkingSockets pSelf, pCVoid pCertificate, Int32 cbCertificate, pSteamNetworkingErrMsg pErrMsg) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_SetCertificate");
	return (g_SteamClientGameServer->SteamNetworkingSockets).SetCertificate(pCertificate, cbCertificate, pErrMsg);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingSockets_ResetIdentity(IpSteamNetworkingSockets pSelf, const pSteamNetworkingIdentity pIdentity) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_ResetIdentity");
	return (g_SteamClientGameServer->SteamNetworkingSockets).ResetIdentity(pIdentity);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingSockets_RunCallbacks(IpSteamNetworkingSockets pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_RunCallbacks");
	return (g_SteamClientGameServer->SteamNetworkingSockets).RunCallbacks();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP(IpSteamNetworkingSockets pSelf, Int32 nNumPorts) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP");
	return (g_SteamClientGameServer->SteamNetworkingSockets).BeginAsyncRequestFakeIP(nNumPorts);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetFakeIP(IpSteamNetworkingSockets pSelf, Int32 idxFirstPort, pSteamNetworkingFakeIPResult_t pInfo) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetFakeIP");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetFakeIP(idxFirstPort, pInfo);
}

_FREE_API_ HSteamListenSocket _S_CALL_ SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP(IpSteamNetworkingSockets pSelf, Int32 idxFakePort, Int32 nOptions, const pSteamNetworkingConfigValue_t pOptions) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CreateListenSocketP2PFakeIP(idxFakePort, nOptions, pOptions);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection(IpSteamNetworkingSockets pSelf, HSteamNetConnection hConnection, pSteamNetworkingIPAddr pAddr) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection");
	return (g_SteamClientGameServer->SteamNetworkingSockets).GetRemoteFakeIPForConnection(hConnection, pAddr);
}

_FREE_API_ IpSteamNetworkingFakeUDPPort _S_CALL_ SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort(IpSteamNetworkingSockets pSelf, Int32 iFakeServerPort) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort");
	return (g_SteamClientGameServer->SteamNetworkingSockets).CreateFakeUDPPort(iFakeServerPort);
}

/* ISteamNetworkingConnectionCustomSignaling */

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingConnectionCustomSignaling_SendSignal(IpSteamNetworkingConnectionCustomSignaling pSelf, HSteamNetConnection hConnectionection, const pSteamNetConnectionInfo_t pInfo, pCVoid pvMsg, Int32 cbMsg) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingConnectionCustomSignaling_SendSignal");
	if (pSelf != NULL)
		return pSelf->SendSignal(hConnectionection, pInfo, pvMsg, cbMsg);
	return False;
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingConnectionCustomSignaling_Release(IpSteamNetworkingConnectionCustomSignaling pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingConnectionCustomSignaling_Release");
	if (pSelf != NULL)
		pSelf->Release();
}

/* ISteamNetworkingCustomSignalingRecvContext */

_FREE_API_ IpSteamNetworkingConnectionCustomSignaling _S_CALL_ SteamAPI_ISteamNetworkingCustomSignalingRecvContext_OnConnectRequest(IpSteamNetworkingCustomSignalingRecvContext pSelf, HSteamNetConnection hConnectionection, const pSteamNetworkingIdentity pIdentityPeer) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingCustomSignalingRecvContext_OnConnectRequest");
	if (pSelf != NULL)
		return pSelf->_OnConnectRequest(hConnectionection, pIdentityPeer);
	return NULL;
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingCustomSignalingRecvContext_SendRejectionSignal(IpSteamNetworkingCustomSignalingRecvContext pSelf, const pSteamNetworkingIdentity pIdentityPeer, pCVoid pvMsg, Int32 cbMsg) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingCustomSignalingRecvContext_SendRejectionSignal");
	if (pSelf != NULL)
		pSelf->SendRejectionSignal(pIdentityPeer, pvMsg, cbMsg);
}

/* ISteamNetworkingUtils */

_FREE_API_ IpSteamNetworkingUtils _S_CALL_ SteamAPI_SteamNetworkingUtils_v003() {
	DEBUGBREAK("SteamAPI_SteamNetworkingUtils_v003");
	return (IpSteamNetworkingUtils)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworkingUtils003"
	));
}

_FREE_API_ IpSteamNetworkingUtils _S_CALL_ SteamAPI_SteamNetworkingUtils_v004() {
	DEBUGBREAK("SteamAPI_SteamNetworkingUtils_v004");
	return (IpSteamNetworkingUtils)(g_SteamClientGameServer->GetISteamGenericInterface(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamNetworkingUtils004"
	));
}

_FREE_API_ pSteamNetworkingMessage_t _S_CALL_ SteamAPI_ISteamNetworkingUtils_AllocateMessage(IpSteamNetworkingUtils pSelf, Int32 cbAllocate) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_AllocateMessage");
	return (g_SteamClientGameServer->SteamNetworkingUtils).AllocateMessage(cbAllocate);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess(IpSteamNetworkingUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess");
	return (g_SteamClientGameServer->SteamNetworkingUtils).InitRelayNetworkAccess();
}

_FREE_API_ ESteamNetworkingAvailability _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus(IpSteamNetworkingUtils pSelf, pSteamRelayNetworkStatus_t pDetails) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetRelayNetworkStatus(pDetails);
}

_FREE_API_ Float _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation(IpSteamNetworkingUtils pSelf, pSteamNetworkPingLocation_t pResult) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetLocalPingLocation(pResult);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations(IpSteamNetworkingUtils pSelf, const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations");
	return (g_SteamClientGameServer->SteamNetworkingUtils).EstimatePingTimeBetweenTwoLocations(pLocation1, pLocation2);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost(IpSteamNetworkingUtils pSelf, const pSteamNetworkPingLocation_t pRemoteLocation) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost");
	return (g_SteamClientGameServer->SteamNetworkingUtils).EstimatePingTimeFromLocalHost(pRemoteLocation);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString(IpSteamNetworkingUtils pSelf, const pSteamNetworkPingLocation_t pLocation, pStrA pchBuf, Int32 cchBuf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).ConvertPingLocationToString(pLocation, pchBuf, cchBuf);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_ParsePingLocationString(IpSteamNetworkingUtils pSelf, pCStrA pchString, pSteamNetworkPingLocation_t pResult) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_ParsePingLocationString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).ParsePingLocationString(pchString, pResult);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate(IpSteamNetworkingUtils pSelf, Float MaxAgeSeconds) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate");
	return (g_SteamClientGameServer->SteamNetworkingUtils).CheckPingDataUpToDate(MaxAgeSeconds);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter(IpSteamNetworkingUtils pSelf, SteamNetworkingPOPID PopId, pSteamNetworkingPOPID pViaRelayPoP) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetPingToDataCenter(PopId, pViaRelayPoP);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP(IpSteamNetworkingUtils pSelf, SteamNetworkingPOPID PopId) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetDirectPingToPOP(PopId);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetPOPCount(IpSteamNetworkingUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetPOPCount");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetPOPCount();
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetPOPList(IpSteamNetworkingUtils pSelf, pSteamNetworkingPOPID pList, Int32 nList) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetPOPList");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetPOPList(pList, nList);
}

_FREE_API_ SteamNetworkingMicroseconds _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp(IpSteamNetworkingUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetLocalTimestamp();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction(IpSteamNetworkingUtils pSelf, ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pFunction) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetDebugOutputFunction(eDetailLevel, pFunction);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_IsFakeIPv4(IpSteamNetworkingUtils pSelf, Uint32 IPv4) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_IsFakeIPv4");
	return (g_SteamClientGameServer->SteamNetworkingUtils).IsFakeIPv4(IPv4);
}

_FREE_API_ ESteamNetworkingFakeIPType _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType(IpSteamNetworkingUtils pSelf, Uint32 IPv4) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetIPv4FakeIPType(IPv4);
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP(IpSteamNetworkingUtils pSelf, const pSteamNetworkingIPAddr pFakeIP, pSteamNetworkingIdentity pRealIdentity) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetRealIdentityForFakeIP(pFakeIP, pRealIdentity);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueInt32(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eValue, Int32 Value) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueInt32");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Int32, &Value);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueFloat(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eValue, Float Value) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueFloat");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Float, &Value);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueString(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eValue, pCStrA Value) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_String, Value);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValuePtr(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eValue, pVoid Value) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValuePtr");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Ptr, &Value);
}

#pragma warning(push)
#pragma warning(disable: 4312)

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueInt32(IpSteamNetworkingUtils pSelf, HSteamNetConnection hConnection, ESteamNetworkingConfigValue eValue, Int32 Value) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueInt32");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, k_ESteamNetworkingConfig_Connection, (pVoid)(hConnection), k_ESteamNetworkingConfig_Int32, &Value);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueFloat(IpSteamNetworkingUtils pSelf, HSteamNetConnection hConnection, ESteamNetworkingConfigValue eValue, Float Value) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueFloat");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, k_ESteamNetworkingConfig_Connection, (pVoid)(hConnection), k_ESteamNetworkingConfig_Float, &Value);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueString(IpSteamNetworkingUtils pSelf, HSteamNetConnection hConnection, ESteamNetworkingConfigValue eValue, pCStrA Value) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, k_ESteamNetworkingConfig_Connection, (pVoid)(hConnection), k_ESteamNetworkingConfig_String, Value);
}

#pragma warning(pop)

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetConnectionStatusChanged(IpSteamNetworkingUtils pSelf, SteamNetConnectionStatusChanged pCallback) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetConnectionStatusChanged");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(k_ESteamNetworkingConfig_Callback_ConnectionStatusChanged, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Ptr, &pCallback);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetAuthenticationStatusChanged(IpSteamNetworkingUtils pSelf, SteamNetAuthenticationStatusChanged pCallback) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetAuthenticationStatusChanged");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(k_ESteamNetworkingConfig_Callback_AuthStatusChanged, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Ptr, &pCallback);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamRelayNetworkStatusChanged(IpSteamNetworkingUtils pSelf, SteamRelayNetworkStatusChanged pCallback) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamRelayNetworkStatusChanged");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(k_ESteamNetworkingConfig_Callback_RelayNetworkStatusChanged, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Ptr, &pCallback);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_FakeIPResult(IpSteamNetworkingUtils pSelf, SteamNetworkingFakeIPResult pCallback) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_FakeIPResult");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(k_ESteamNetworkingConfig_Callback_FakeIPResult, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Ptr, &pCallback);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionRequest(IpSteamNetworkingUtils pSelf, SteamNetworkingMessagesSessionRequest pCallback) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionRequest");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(k_ESteamNetworkingConfig_Callback_MessagesSessionRequest, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Ptr, &pCallback);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionFailed(IpSteamNetworkingUtils pSelf, SteamNetworkingMessagesSessionFailed pCallback) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionFailed");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(k_ESteamNetworkingConfig_Callback_MessagesSessionFailed, k_ESteamNetworkingConfig_Global, NULL, k_ESteamNetworkingConfig_Ptr, &pCallback);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetConfigValue(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, pVoid pScopeObj, ESteamNetworkingConfigDataType eDataType, pCVoid pArg) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetConfigValue");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(eValue, eScopeType, pScopeObj, eDataType, pArg);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SetConfigValueStruct(IpSteamNetworkingUtils pSelf, const pSteamNetworkingConfigValue_t pOpt, ESteamNetworkingConfigScope eScopeType, pVoid pScopeObj) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SetConfigValueStruct");
	if (pOpt != NULL)
		return (g_SteamClientGameServer->SteamNetworkingUtils).SetConfigValue(pOpt->eValue, eScopeType, pScopeObj, pOpt->eDataType, (pOpt->eDataType == k_ESteamNetworkingConfig_String) ? (pCVoid)(pOpt->pchStr) : &pOpt->pvData);
	return False;
}

_FREE_API_ ESteamNetworkingGetConfigValueResult _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetConfigValue(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, pVoid pScopeObj, pESteamNetworkingConfigDataType peDataType, pVoid pResult, pSizeOF cbResult) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetConfigValue");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetConfigValue(eValue, eScopeType, pScopeObj, peDataType, pResult, cbResult);
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eValue, pESteamNetworkingConfigDataType peDataType, pESteamNetworkingConfigScope peScope) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetConfigValueInfo(eValue, peDataType, peScope);
}

_FREE_API_ ESteamNetworkingConfigValue _S_CALL_ SteamAPI_ISteamNetworkingUtils_GetFirstConfigValue(IpSteamNetworkingUtils pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_GetFirstConfigValue");
	return (g_SteamClientGameServer->SteamNetworkingUtils).GetFirstConfigValue();
}

_FREE_API_ ESteamNetworkingConfigValue _S_CALL_ SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues(IpSteamNetworkingUtils pSelf, ESteamNetworkingConfigValue eCurrent, Bool bEnumerateDevVars) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues");
	return (g_SteamClientGameServer->SteamNetworkingUtils).IterateGenericEditableConfigValues(eCurrent, bEnumerateDevVars);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString(IpSteamNetworkingUtils pSelf, const pSteamNetworkingIPAddr pAddr, pStrA pchStr, Uint32 cchStr, Bool bWithPort) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIPAddr_ToString(pAddr, pchStr, cchStr, bWithPort);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString(IpSteamNetworkingUtils pSelf, pSteamNetworkingIPAddr pAddr, pCStrA pchStr) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIPAddr_ParseString(pAddr, pchStr);
}

_FREE_API_ ESteamNetworkingFakeIPType _S_CALL_ SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType(IpSteamNetworkingUtils pSelf, const pSteamNetworkingIPAddr pAddr) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIPAddr_GetFakeIPType(pAddr);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString(IpSteamNetworkingUtils pSelf, const pSteamNetworkingIdentity pIdentity, pStrA pchStr, Uint32 cchStr) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIdentity_ToString(pIdentity, pchStr, cchStr);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString(IpSteamNetworkingUtils pSelf, pSteamNetworkingIdentity pIdentity, pCStrA pchStr) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIdentity_ParseString(pIdentity, pchStr);
}

/* ISteamGameServer */

_FREE_API_ IpSteamGameServer _S_CALL_ SteamAPI_SteamGameServer_v013() {
	DEBUGBREAK("SteamAPI_SteamGameServer_v013");
	return g_SteamClientGameServer->GetISteamGameServer(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamGameServer013"
	);
}

_FREE_API_ IpSteamGameServer _S_CALL_ SteamAPI_SteamGameServer_v014() {
	DEBUGBREAK("SteamAPI_SteamGameServer_v014");
	return g_SteamClientGameServer->GetISteamGameServer(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamGameServer014"
	);
}

_FREE_API_ IpSteamGameServer _S_CALL_ SteamAPI_SteamGameServer_v015() {
	DEBUGBREAK("SteamAPI_SteamGameServer_v015");
	return g_SteamClientGameServer->GetISteamGameServer(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamGameServer015"
	);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetProduct(IpSteamGameServer pSelf, pCStrA pchProduct) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetProduct");
	return (g_SteamClientGameServer->SteamGameServer).SetProduct(pchProduct);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetGameDescription(IpSteamGameServer pSelf, pCStrA pchGameDescription) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetGameDescription");
	return (g_SteamClientGameServer->SteamGameServer).SetGameDescription(pchGameDescription);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetModDir(IpSteamGameServer pSelf, pCStrA pchModDir) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetModDir");
	return (g_SteamClientGameServer->SteamGameServer).SetModDir(pchModDir);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetDedicatedServer(IpSteamGameServer pSelf, Bool bDedicated) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetDedicatedServer");
	return (g_SteamClientGameServer->SteamGameServer).SetDedicatedServer(bDedicated);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_LogOn(IpSteamGameServer pSelf, pCStrA pchToken) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_LogOn");
	return (g_SteamClientGameServer->SteamGameServer).LogOn();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_LogOnAnonymous(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_LogOnAnonymous");
	return (g_SteamClientGameServer->SteamGameServer).LogOnAnonymous();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_LogOff(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_LogOff");
	return (g_SteamClientGameServer->SteamGameServer).LogOff();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_BLoggedOn(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_BLoggedOn");
	return (g_SteamClientGameServer->SteamGameServer).BLoggedOn();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_BSecure(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_BSecure");
	return (g_SteamClientGameServer->SteamGameServer).BSecure();
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamGameServer_GetSteamID(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_GetSteamID");
	return (g_SteamClientGameServer->SteamGameServer).GetSteamID().SteamId_Uint64;
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_WasRestartRequested(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_WasRestartRequested");
	return (g_SteamClientGameServer->SteamGameServer).WasRestartRequested();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetMaxPlayerCount(IpSteamGameServer pSelf, Int32 cPlayersMax) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetMaxPlayerCount");
	return (g_SteamClientGameServer->SteamGameServer).SetMaxPlayerCount(cPlayersMax);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetBotPlayerCount(IpSteamGameServer pSelf, Int32 cBotplayers) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetBotPlayerCount");
	return (g_SteamClientGameServer->SteamGameServer).SetBotPlayerCount(cBotplayers);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetServerName(IpSteamGameServer pSelf, pCStrA pchServerName) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetServerName");
	return (g_SteamClientGameServer->SteamGameServer).SetServerName(pchServerName);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetMapName(IpSteamGameServer pSelf, pCStrA pchMapName) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetMapName");
	return (g_SteamClientGameServer->SteamGameServer).SetMapName(pchMapName);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetPasswordProtected(IpSteamGameServer pSelf, Bool bPasswordProtected) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetPasswordProtected");
	return (g_SteamClientGameServer->SteamGameServer).SetPasswordProtected(bPasswordProtected);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetSpectatorPort(IpSteamGameServer pSelf, Uint16 SpectatorPort) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetSpectatorPort");
	return (g_SteamClientGameServer->SteamGameServer).SetSpectatorPort(SpectatorPort);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetSpectatorServerName(IpSteamGameServer pSelf, pCStrA pchSpectatorServerName) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetSpectatorServerName");
	return (g_SteamClientGameServer->SteamGameServer).SetSpectatorServerName(pchSpectatorServerName);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_ClearAllKeyValues(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_ClearAllKeyValues");
	return (g_SteamClientGameServer->SteamGameServer).ClearAllKeyValues();
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetKeyValue(IpSteamGameServer pSelf, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetKeyValue");
	return (g_SteamClientGameServer->SteamGameServer).SetKeyValue(pchKey, pchValue);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetGameTags(IpSteamGameServer pSelf, pCStrA pchGameTags) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetGameTags");
	return (g_SteamClientGameServer->SteamGameServer).SetGameTags(pchGameTags);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetGameData(IpSteamGameServer pSelf, pCStrA pchGameData) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetGameData");
	return (g_SteamClientGameServer->SteamGameServer).SetGameData(pchGameData);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetRegion(IpSteamGameServer pSelf, pCStrA pchRegion) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetRegion");
	return (g_SteamClientGameServer->SteamGameServer).SetRegion(pchRegion);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate(IpSteamGameServer pSelf, Uint32 nIPClient, pCVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate");
	return (g_SteamClientGameServer->SteamGameServer).SendUserConnectAndAuthenticate(nIPClient, pvAuthBlob, cbAuthBlobSize, pSteamIdUser);
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection");
	return (g_SteamClientGameServer->SteamGameServer).CreateUnauthenticatedUserConnection().SteamId_Uint64;
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SendUserDisconnect(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SendUserDisconnect");
	return (g_SteamClientGameServer->SteamGameServer).SendUserDisconnect(SteamId_t{ SteamIdUser });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_BUpdateUserData(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchPlayerName, Uint32 Score) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_BUpdateUserData");
	return (g_SteamClientGameServer->SteamGameServer).BUpdateUserData(SteamId_t{ SteamIdUser }, pchPlayerName, Score);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetAdvertiseServerActive(IpSteamGameServer pSelf, Bool bActive) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetAdvertiseServerActive");
	return (g_SteamClientGameServer->SteamGameServer).SetAdvertiseServerActive(bActive);
}

_FREE_API_ HAuthTicket _S_CALL_ SteamAPI_ISteamGameServer_GetAuthSessionTicket(IpSteamGameServer pSelf, pVoid pvTicket, Int32 cbMaxTicket, pUint32 pcbTicket, const pSteamNetworkingIdentity pSnid) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_GetAuthSessionTicket");
	return (g_SteamClientGameServer->SteamGameServer).GetAuthSessionTicket(pvTicket, cbMaxTicket, pcbTicket, pSnid);
}

_FREE_API_ EBeginAuthSessionResult _S_CALL_ SteamAPI_ISteamGameServer_BeginAuthSession(IpSteamGameServer pSelf, pCVoid pbAuthTicket, Int32 cbAuthTicket, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_BeginAuthSession");
	return (g_SteamClientGameServer->SteamGameServer).BeginAuthSession(pbAuthTicket, cbAuthTicket, SteamId_t{ SteamId });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_EndAuthSession(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_EndAuthSession");
	return (g_SteamClientGameServer->SteamGameServer).EndAuthSession(SteamId_t{ SteamId });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_CancelAuthTicket(IpSteamGameServer pSelf, HAuthTicket hAuthTicket) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_CancelAuthTicket");
	return (g_SteamClientGameServer->SteamGameServer).CancelAuthTicket(hAuthTicket);
}

_FREE_API_ EUserHasLicenseForAppResult _S_CALL_ SteamAPI_ISteamGameServer_UserHasLicenseForApp(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamId, AppId_t AppId) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_UserHasLicenseForApp");
	return (g_SteamClientGameServer->SteamGameServer).UserHasLicenseForApp(SteamId_t{ SteamId }, AppId);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_RequestUserGroupStatus(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamIdUser, SteamId_t_Uint64 SteamIdGroup) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_RequestUserGroupStatus");
	return (g_SteamClientGameServer->SteamGameServer).RequestUserGroupStatus(SteamId_t{ SteamIdUser }, SteamId_t{ SteamIdGroup });
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_GetGameplayStats(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_GetGameplayStats");
	return (g_SteamClientGameServer->SteamGameServer).GetGameplayStats();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamGameServer_GetServerReputation(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_GetServerReputation");
	return (g_SteamClientGameServer->SteamGameServer).GetServerReputation();
}

_FREE_API_ SteamIPAddress_t _S_CALL_ SteamAPI_ISteamGameServer_GetPublicIP(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_GetPublicIP");
	return (g_SteamClientGameServer->SteamGameServer).GetPublicIP();
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_HandleIncomingPacket(IpSteamGameServer pSelf, pCVoid pvData, Int32 cbData, Uint32 srcIP, Uint16 srcPort) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_HandleIncomingPacket");
	return (g_SteamClientGameServer->SteamGameServer).HandleIncomingPacket(pvData, cbData, srcIP, srcPort);
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamGameServer_GetNextOutgoingPacket(IpSteamGameServer pSelf, pVoid pvOut, Int32 cbOut, pUint32 pNetAdr, pUint16 pPort) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_GetNextOutgoingPacket");
	return (g_SteamClientGameServer->SteamGameServer).GetNextOutgoingPacket(pvOut, cbOut, pNetAdr, pPort);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_EnableHeartbeats(IpSteamGameServer pSelf, Bool bActive) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_EnableHeartbeats");
	return (g_SteamClientGameServer->SteamGameServer).EnableHeartbeats(bActive);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SetHeartbeatInterval(IpSteamGameServer pSelf, Int32 iHeartbeatInterval) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SetHeartbeatInterval");
	return (g_SteamClientGameServer->SteamGameServer).SetHeartbeatInterval(iHeartbeatInterval);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_ForceHeartbeat(IpSteamGameServer pSelf) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_ForceHeartbeat");
	return (g_SteamClientGameServer->SteamGameServer).ForceHeartbeat();
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamGameServer_AssociateWithClan(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamIdClan) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_AssociateWithClan");
	return (g_SteamClientGameServer->SteamGameServer).AssociateWithClan(SteamId_t{ SteamIdClan });
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamIdNewPlayer) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility");
	return (g_SteamClientGameServer->SteamGameServer).ComputeNewPlayerCompatibility(SteamId_t{ SteamIdNewPlayer });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED(IpSteamGameServer pSelf, Uint32 nIPClient, pCVoid pvAuthBlob, Uint32 cbAuthBlobSize, pSteamId_t pSteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED");
	return (g_SteamClientGameServer->SteamGameServer).SendUserConnectAndAuthenticate(nIPClient, pvAuthBlob, cbAuthBlobSize, pSteamIdUser);
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED(IpSteamGameServer pSelf, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED");
	return (g_SteamClientGameServer->SteamGameServer).SendUserDisconnect(SteamId_t{ SteamIdUser });
}

/* ISteamGameServerStats */

_FREE_API_ IpSteamGameServerStats _S_CALL_ SteamAPI_SteamGameServerStats_v001() {
	DEBUGBREAK("SteamAPI_SteamGameServerStats_v001");
	return g_SteamClientGameServer->GetISteamGameServerStats(
		k_HSteamUser_LocalUser,
		k_HSteamPipe_Client, "SteamGameServerStats001"
	);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamGameServerStats_RequestUserStats(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_RequestUserStats");
	return (g_SteamClientGameServer->SteamGameServerStats).RequestUserStats(SteamId_t{ SteamIdUser });
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_GetUserStatInt32(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, pInt32 pData) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_GetUserStatInt32");
	return (g_SteamClientGameServer->SteamGameServerStats).GetUserStat(SteamId_t{ SteamIdUser }, pchName, pData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_GetUserStatFloat(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, pFloat pData) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_GetUserStatFloat");
	return (g_SteamClientGameServer->SteamGameServerStats).GetUserStat(SteamId_t{ SteamIdUser }, pchName, pData);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_GetUserAchievement(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, pBool pbAchieved) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_GetUserAchievement");
	return (g_SteamClientGameServer->SteamGameServerStats).GetUserAchievement(SteamId_t{ SteamIdUser }, pchName, pbAchieved);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_SetUserStatInt32(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, Int32 Data) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_SetUserStatInt32");
	return (g_SteamClientGameServer->SteamGameServerStats).SetUserStat(SteamId_t{ SteamIdUser }, pchName, Data);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_SetUserStatFloat(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, Float Data) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_SetUserStatFloat");
	return (g_SteamClientGameServer->SteamGameServerStats).SetUserStat(SteamId_t{ SteamIdUser }, pchName, Data);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName, Float CountThisSession, Double SessionLength) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat");
	return (g_SteamClientGameServer->SteamGameServerStats).UpdateUserAvgRateStat(SteamId_t{ SteamIdUser }, pchName, CountThisSession, SessionLength);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_SetUserAchievement(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_SetUserAchievement");
	return (g_SteamClientGameServer->SteamGameServerStats).SetUserAchievement(SteamId_t{ SteamIdUser }, pchName);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_ISteamGameServerStats_ClearUserAchievement(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_ClearUserAchievement");
	return (g_SteamClientGameServer->SteamGameServerStats).ClearUserAchievement(SteamId_t{ SteamIdUser }, pchName);
}

_FREE_API_ SteamAPICall_t _S_CALL_ SteamAPI_ISteamGameServerStats_StoreUserStats(IpSteamGameServerStats pSelf, SteamId_t_Uint64 SteamIdUser) {
	DEBUGBREAK("SteamAPI_ISteamGameServerStats_StoreUserStats");
	return (g_SteamClientGameServer->SteamGameServerStats).StoreUserStats(SteamId_t{ SteamIdUser });
}

/* ISteamNetworkingFakeUDPPort */

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingFakeUDPPort_DestroyFakeUDPPort(IpSteamNetworkingFakeUDPPort pSelf) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingFakeUDPPort_DestroyFakeUDPPort");
	if (pSelf != NULL)
		pSelf->DestroyFakeUDPPort();
}

_FREE_API_ EResult _S_CALL_ SteamAPI_ISteamNetworkingFakeUDPPort_SendMessageToFakeIP(IpSteamNetworkingFakeUDPPort pSelf, const pSteamNetworkingIPAddr pRemoteAddress, pCVoid pvData, Uint32 cbData, Int32 nSendFlags) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingFakeUDPPort_SendMessageToFakeIP");
	if (pSelf != NULL)
		return pSelf->SendMessageToFakeIP(pRemoteAddress, pvData, cbData, nSendFlags);
	return k_EResultFail;
}

_FREE_API_ Int32 _S_CALL_ SteamAPI_ISteamNetworkingFakeUDPPort_ReceiveMessages(IpSteamNetworkingFakeUDPPort pSelf, pSteamNetworkingMessage_t *ppMessages, Int32 nMaxMessages) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingFakeUDPPort_ReceiveMessages");
	if (pSelf != NULL)
		return pSelf->ReceiveMessages(ppMessages, nMaxMessages);
	return 0;
}

_FREE_API_ void _S_CALL_ SteamAPI_ISteamNetworkingFakeUDPPort_ScheduleCleanup(IpSteamNetworkingFakeUDPPort pSelf, const pSteamNetworkingIPAddr pRemoteAddress) {
	DEBUGBREAK("SteamAPI_ISteamNetworkingFakeUDPPort_ScheduleCleanup");
	if (pSelf != NULL)
		pSelf->ScheduleCleanup(pRemoteAddress);
}

/* SteamIPAddress_t */

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamIPAddress_t_IsSet(pSteamIPAddress_t pSelf) {
	DEBUGBREAK("SteamAPI_SteamIPAddress_t_IsSet");

	if (pSelf != NULL) {
		if (pSelf->eSteamIPType <= k_ESteamIPTypeIPv6) {
			return True;
		}
	}

	return False;

}

/* MatchMakingKeyValuePair_t */

_FREE_API_ void _S_CALL_ SteamAPI_MatchMakingKeyValuePair_t_Construct(pMatchMakingKeyValuePair_t pSelf) {
	DEBUGBREAK("SteamAPI_MatchMakingKeyValuePair_t_Construct");

	if (pSelf != NULL) {
		pSelf->chKey[0] = '\0';
		pSelf->chValue[0] = '\0';
	}

}

/* servernetadr_t */

_FREE_API_ void _S_CALL_ SteamAPI_servernetadr_t_Construct(pServerNETAdrr_t pSelf) {
	DEBUGBREAK("SteamAPI_servernetadr_t_Construct");
	if (pSelf != NULL) {
		pSelf->ConnectionPort = 0U;
		pSelf->nIP = 0U;
		pSelf->QueryPort = 0U;
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_servernetadr_t_Init(pServerNETAdrr_t pSelf, Uint32 nIP, Uint16 QueryPort, Uint16 ConnectionPort) {
	DEBUGBREAK("SteamAPI_servernetadr_t_Init");
	if (pSelf != NULL) {
		pSelf->ConnectionPort = QueryPort;
		pSelf->nIP = nIP;
		pSelf->QueryPort = QueryPort;
	}
}

_FREE_API_ Uint16 _S_CALL_ SteamAPI_servernetadr_t_GetQueryPort(pServerNETAdrr_t pSelf) {
	DEBUGBREAK("SteamAPI_servernetadr_t_GetQueryPort");
	if (pSelf != NULL)
		return pSelf->QueryPort;
	return 0U;
}

_FREE_API_ void _S_CALL_ SteamAPI_servernetadr_t_SetQueryPort(pServerNETAdrr_t pSelf, Uint16 QueryPort) {
	DEBUGBREAK("SteamAPI_servernetadr_t_SetQueryPort");
	if (pSelf != NULL) {
		pSelf->QueryPort = QueryPort;
	}
}

_FREE_API_ Uint16 _S_CALL_ SteamAPI_servernetadr_t_GetConnectionPort(pServerNETAdrr_t pSelf) {
	DEBUGBREAK("SteamAPI_servernetadr_t_GetConnectionPort");
	if (pSelf != NULL)
		return pSelf->ConnectionPort;
	return 0U;
}

_FREE_API_ void _S_CALL_ SteamAPI_servernetadr_t_SetConnectionPort(pServerNETAdrr_t pSelf, Uint16 ConnectionPort) {
	DEBUGBREAK("SteamAPI_servernetadr_t_SetConnectionPort");
	if (pSelf != NULL) {
		pSelf->ConnectionPort = ConnectionPort;
	}
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_servernetadr_t_GetIP(pServerNETAdrr_t pSelf) {
	DEBUGBREAK("SteamAPI_servernetadr_t_GetIP");
	if (pSelf != NULL)
		return pSelf->nIP;
	return 0U;
}

_FREE_API_ void _S_CALL_ SteamAPI_servernetadr_t_SetIP(pServerNETAdrr_t pSelf, Uint32 nIP) {
	DEBUGBREAK("SteamAPI_servernetadr_t_SetIP");
	if (pSelf != NULL) {
		pSelf->nIP = nIP;
	}
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_servernetadr_t_GetConnectionAddressString(pServerNETAdrr_t pSelf) {
	DEBUGBREAK("SteamAPI_servernetadr_t_GetConnectionAddressString");
	if (pSelf != NULL) {
		g_chString[0] = '\0';
		wsprintfA(
			g_chString, "%u.%u.%u.%u:%u", (Uint32)(((pByte)(&pSelf->nIP))[0]),
			(Uint32)(((pByte)(&pSelf->nIP))[1]), (Uint32)(((pByte)(&pSelf->nIP))[2]),
			(Uint32)(((pByte)(&pSelf->nIP))[3]), (Uint32)(pSelf->ConnectionPort)
		);
		return (pCStrA)(g_chString);
	}
	return (pCStrA)("");
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_servernetadr_t_GetQueryAddressString(pServerNETAdrr_t pSelf) {
	DEBUGBREAK("SteamAPI_servernetadr_t_GetQueryAddressString");
	if (pSelf != NULL) {
		g_chString[0] = '\0';
		wsprintfA(
			g_chString, "%u.%u.%u.%u:%u", (Uint32)(((pByte)(&pSelf->nIP))[0]),
			(Uint32)(((pByte)(&pSelf->nIP))[1]), (Uint32)(((pByte)(&pSelf->nIP))[2]),
			(Uint32)(((pByte)(&pSelf->nIP))[3]), (Uint32)(pSelf->QueryPort)
		);
		return (pCStrA)(g_chString);
	}
	return (pCStrA)("");
}

_FREE_API_ Bool _S_CALL_ SteamAPI_servernetadr_t_IsLessThan(pServerNETAdrr_t pSelf, const pServerNETAdrr_t pOther) {
	DEBUGBREAK("SteamAPI_servernetadr_t_IsLessThan");
	if (pSelf != NULL && pOther != NULL)
		return pSelf->ConnectionPort < pOther->ConnectionPort ||
			pSelf->QueryPort < pOther->QueryPort;
	return False;
}

_FREE_API_ void _S_CALL_ SteamAPI_servernetadr_t_Assign(pServerNETAdrr_t pSelf, const pServerNETAdrr_t pOther) {
	DEBUGBREAK("SteamAPI_servernetadr_t_Assign");
	if (pSelf != NULL && pOther != NULL) {
		pSelf->ConnectionPort = pOther->ConnectionPort;
		pSelf->nIP = pOther->nIP;
		pSelf->QueryPort = pOther->QueryPort;
	}
}

/* gameserveritem_t */

_FREE_API_ void _S_CALL_ SteamAPI_gameserveritem_t_Construct(pGameServerItem_t pSelf) {
	DEBUGBREAK("SteamAPI_gameserveritem_t_Construct");
	if (pSelf != NULL) {
		for (SizeOF i = 0; i < sizeof(GameServerItem_t); i++) {
			((pByte)(pSelf))[i] = 0x00;
		}
	}
}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_gameserveritem_t_GetName(pGameServerItem_t pSelf) {
	DEBUGBREAK("SteamAPI_gameserveritem_t_GetName");
	if (pSelf != NULL)
		return (pCStrA)(pSelf->chServerName);
	return (pCStrA)("");
}

_FREE_API_ void _S_CALL_ SteamAPI_gameserveritem_t_SetName(pGameServerItem_t pSelf, pCStrA pchName) {
	DEBUGBREAK("SteamAPI_gameserveritem_t_SetName");
	if (pSelf != NULL)
		StrA_Copy(pSelf->chServerName, sizeof(pSelf->chServerName) / sizeof(CharA), pchName);
}

/* SteamNetworkingIPAddr */

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIPAddr_Clear(pSteamNetworkingIPAddr pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_Clear");
	if (pSelf != NULL) {
		for (SizeOF i = 0; i < sizeof(SteamNetworkingIPAddr); i++) {
			((pByte)(pSelf))[i] = 0x00;
		}
	}
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros(pSteamNetworkingIPAddr pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros");

	if (pSelf != NULL) {
		for (SizeOF i = 0; i < sizeof(pSelf->IPv6); i++)
			if (pSelf->IPv6[i] != 0x00) return False;
		return True;
	}

	return False;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIPAddr_SetIPv6(pSteamNetworkingIPAddr pSelf, pCUint8 Ipv6, Uint16 Port) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_SetIPv6");
	if (pSelf != NULL) {
		for (SizeOF i = 0; i < sizeof(pSelf->IPv6); i++)
			pSelf->IPv6[i] = Ipv6[i];
		pSelf->Port = Port;
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIPAddr_SetIPv4(pSteamNetworkingIPAddr pSelf, Uint32 nIP, Uint16 Port) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_SetIPv4");
	if (pSelf != NULL) {
		pSelf->IPv4.x0000000000000000 = 0x0000000000000000;
		pSelf->IPv4.x0000 = 0x0000;
		pSelf->IPv4.xFFFF = 0xFFFF;
		pSelf->IPv4.cbIPv4[0] = ((pByte)(&nIP))[0];
		pSelf->IPv4.cbIPv4[1] = ((pByte)(&nIP))[1];
		pSelf->IPv4.cbIPv4[2] = ((pByte)(&nIP))[2];
		pSelf->IPv4.cbIPv4[3] = ((pByte)(&nIP))[3];
		pSelf->Port = Port;
	}
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIPAddr_IsIPv4(pSteamNetworkingIPAddr pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_IsIPv4");
	
	if (pSelf != NULL) {
		if (
			pSelf->IPv4.x0000000000000000 == 0x0000000000000000 &&
			pSelf->IPv4.x0000 == 0x0000 &&
			pSelf->IPv4.xFFFF == 0xFFFF
		) {
			return True;
		}
	}

	return False;

}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_SteamNetworkingIPAddr_GetIPv4(pSteamNetworkingIPAddr pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_GetIPv4");
	
	if (pSelf != NULL) {
		Uint32 nIP = 0U;
		((pByte)(&nIP))[0] = pSelf->IPv4.cbIPv4[0];
		((pByte)(&nIP))[1] = pSelf->IPv4.cbIPv4[1];
		((pByte)(&nIP))[2] = pSelf->IPv4.cbIPv4[2];
		((pByte)(&nIP))[3] = pSelf->IPv4.cbIPv4[3];
		return nIP;
	}

	return 0U;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost(pSteamNetworkingIPAddr pSelf, Uint16 Port) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost");
	if (pSelf != NULL) {
		for (SizeOF i = 0; i < sizeof(pSelf->IPv6) - 1U; i++) 
			pSelf->IPv6[i] = 0x00;
		pSelf->IPv6[15] = 0x01;
		pSelf->Port = Port;
	}
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIPAddr_IsLocalHost(pSteamNetworkingIPAddr pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_IsLocalHost");
	
	if (pSelf != NULL) {

		if (
			pSelf->IPv4.x0000000000000000 == 0x0000000000000000 &&
			pSelf->IPv4.x0000 == 0x0000 &&
			pSelf->IPv4.xFFFF == 0xFFFF &&
			pSelf->IPv4.cbIPv4[0] == 127 &&
			pSelf->IPv4.cbIPv4[1] == 0 &&
			pSelf->IPv4.cbIPv4[2] == 0 &&
			pSelf->IPv4.cbIPv4[3] == 1
		) {
			return True;
		}

		for (SizeOF i = 0; i < sizeof(pSelf->IPv6) - 1U; i++) {
			if (pSelf->IPv6[i] != 0x00) return False;
		}

		if (pSelf->IPv6[15] == 0x01)
			return True;

	}
	
	return False;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIPAddr_ToString(pSteamNetworkingIPAddr pSelf, pStrA pchStr, Uint32 cchStr, Bool bWithPort) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_ToString");
	if (pSelf != NULL)
		(g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIPAddr_ToString(pSelf, pchStr, cchStr, bWithPort);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIPAddr_ParseString(pSteamNetworkingIPAddr pSelf, pCStrA pchStr) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_ParseString");
	if (pSelf != NULL)
		return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIPAddr_ParseString(pSelf, pchStr);
	return False;
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIPAddr_IsEqualTo(pSteamNetworkingIPAddr pSelf, const pSteamNetworkingIPAddr pOther) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_IsEqualTo");
	
	if (pSelf != NULL && pOther != NULL) {
		
		for (SizeOF i = 0; i < sizeof(SteamNetworkingIPAddr); i++) {
			if (((pByte)(pSelf))[i] != ((pByte)(pOther))[i])
				return False;
		}

		return True;

	}

	return False;

}

_FREE_API_ ESteamNetworkingFakeIPType _S_CALL_ SteamAPI_SteamNetworkingIPAddr_GetFakeIPType(pSteamNetworkingIPAddr pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_GetFakeIPType");
	return k_ESteamNetworkingFakeIPType_NotFake;
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIPAddr_IsFakeIP(pSteamNetworkingIPAddr pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddr_IsFakeIP");
	return False;
}

/* SteamNetworkingIdentity */

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_Clear(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_Clear");
	if (pSelf != NULL) {
		for (SizeOF i = 0; i < sizeof(SteamNetworkingIdentity); i++) {
			((pByte)(pSelf))[i] = 0x00;
		}
	}
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_IsInvalid(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_IsInvalid");
	if (pSelf != NULL)
		return (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_Invalid);
	return False;
}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetSteamID(pSteamNetworkingIdentity pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetSteamID");
	if (pSelf != NULL) {
		pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_SteamId;
		pSelf->cbSize = sizeof(SteamId_t);
		pSelf->SteamId = SteamId_t{ SteamId };
	}
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetSteamID(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetSteamID");
	
	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_SteamId)
			return pSelf->SteamId.SteamId_Uint64;
	}

	return 0U;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetSteamID64(pSteamNetworkingIdentity pSelf, SteamId_t_Uint64 SteamId) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetSteamID64");
	if (pSelf != NULL) {
		pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_SteamId;
		pSelf->cbSize = sizeof(SteamId_t_Uint64);
		pSelf->SteamId = SteamId_t{ SteamId };
	}
}

_FREE_API_ SteamId_t_Uint64 _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetSteamID64(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetSteamID64");

	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_SteamId)
			return pSelf->SteamId.SteamId_Uint64;
	}

	return 0U;

}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID(pSteamNetworkingIdentity pSelf, pCStrA pchString) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID");
	
	if (pSelf != NULL && pchString != NULL) {
		SizeOF cchString = StrA_Count(pchString) + 1U;
		if (cchString <= sizeof(pSelf->chXboxPairwiseID)) {
			pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_XboxPairwiseId;
			pSelf->cbSize = (Int32)(cchString);
			StrA_Copy(pSelf->chXboxPairwiseID, pSelf->cbSize, pchString);
			return True;
		}
	}

	return False;

}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID");
	
	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_XboxPairwiseId)
			return (pCStrA)(pSelf->chXboxPairwiseID);
	}

	return (pCStrA)("");

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetPSNID(pSteamNetworkingIdentity pSelf, Uint64 PSnId) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetPSNID");
	if (pSelf != NULL) {
		pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_SonyPSN;
		pSelf->cbSize = sizeof(Uint64);
		pSelf->PSnId = PSnId;
	}
}

_FREE_API_ Uint64 _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetPSNID(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetPSNID");

	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_SonyPSN)
			return pSelf->PSnId;
	}

	return 0U;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetStadiaID(pSteamNetworkingIdentity pSelf, Uint64 StadiaId) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetStadiaID");
	if (pSelf != NULL) {
		pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_GoogleStadia;
		pSelf->cbSize = sizeof(Uint64);
		pSelf->PSnId = StadiaId;
	}
}

_FREE_API_ Uint64 _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetStadiaID(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetStadiaID");

	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_GoogleStadia)
			return pSelf->StadiaId;
	}

	return 0U;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetIPAddr(pSteamNetworkingIdentity pSelf, const pSteamNetworkingIPAddr pAddr) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetIPAddr");
	if (pSelf != NULL && pAddr != NULL) {
		pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_IPAddress;
		pSelf->cbSize = sizeof(SteamNetworkingIPAddr);
		for (SizeOF i = 0; i < sizeof(SteamNetworkingIPAddr); i++) {
			((pByte)(&pSelf->SteamNetworkingIPAddr))[i] = ((pByte)(pAddr))[i];
		}
	}
}

_FREE_API_ const pSteamNetworkingIPAddr _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetIPAddr(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetIPAddr");

	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_IPAddress)
			return &pSelf->SteamNetworkingIPAddr;
	}

	return NULL;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetIPv4Addr(pSteamNetworkingIdentity pSelf, Uint32 IPv4, Uint16 Port) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetIPv4Addr");
	if (pSelf != NULL) {
		pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_IPAddress;
		pSelf->cbSize = sizeof(Uint32);
		pSelf->SteamNetworkingIPAddr.IPv4.x0000000000000000 = 0x0000000000000000;
		pSelf->SteamNetworkingIPAddr.IPv4.x0000 = 0x0000;
		pSelf->SteamNetworkingIPAddr.IPv4.xFFFF = 0xFFFF;
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[0] = ((pByte)(&IPv4))[0];
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[1] = ((pByte)(&IPv4))[1];
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[2] = ((pByte)(&IPv4))[2];
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[3] = ((pByte)(&IPv4))[3];
		pSelf->SteamNetworkingIPAddr.Port = Port;
	}
}

_FREE_API_ Uint32 _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetIPv4(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetIPv4");
	
	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_IPAddress) {
			Uint32 IPv4 = 0U;
			((pByte)(&IPv4))[0] = pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[0];
			((pByte)(&IPv4))[1] = pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[1];
			((pByte)(&IPv4))[2] = pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[2];
			((pByte)(&IPv4))[3] = pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[3];
			return IPv4;
		}
	}

	return 0U;

}

_FREE_API_ ESteamNetworkingFakeIPType _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetFakeIPType(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetFakeIPType");
	return k_ESteamNetworkingFakeIPType_NotFake;
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_IsFakeIP(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_IsFakeIP");
	return False;
}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetLocalHost(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetLocalHost");
	if (pSelf != NULL) {
		pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_IPAddress;
		pSelf->cbSize = sizeof(SteamNetworkingIPAddr);
		pSelf->SteamNetworkingIPAddr.IPv4.x0000000000000000 = 0x0000000000000000;
		pSelf->SteamNetworkingIPAddr.IPv4.x0000 = 0x0000;
		pSelf->SteamNetworkingIPAddr.IPv4.xFFFF = 0xFFFF;
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[0] = 127;
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[1] = 0;
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[2] = 0;
		pSelf->SteamNetworkingIPAddr.IPv4.cbIPv4[3] = 1;
		pSelf->SteamNetworkingIPAddr.Port = 80;
	}
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_IsLocalHost(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_IsLocalHost");

	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_IPAddress)
			return SteamAPI_SteamNetworkingIPAddr_IsLocalHost(&pSelf->SteamNetworkingIPAddr);
	}

	return False;

}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetGenericString(pSteamNetworkingIdentity pSelf, pCStrA pchString) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetGenericString");

	if (pSelf != NULL && pchString != NULL) {
		SizeOF cchString = StrA_Count(pchString) + 1U;
		if (cchString <= sizeof(pSelf->chGenericString)) {
			pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_GenericString;
			pSelf->cbSize = (Int32)(cchString);
			StrA_Copy(pSelf->chGenericString, pSelf->cbSize, pchString);
			return True;
		}
	}

	return False;

}

_FREE_API_ pCStrA _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetGenericString(pSteamNetworkingIdentity pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetGenericString");

	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_GenericString)
			return (pCStrA)(pSelf->chGenericString);
	}

	return (pCStrA)("");

}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_SetGenericBytes(pSteamNetworkingIdentity pSelf, pCVoid pvData, Uint32 cbData) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_SetGenericBytes");

	if (pSelf != NULL && pvData != NULL && cbData != 0U) {
		if (cbData <= sizeof(pSelf->GenericBytes)) {
			pSelf->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_GenericBytes;
			pSelf->cbSize = cbData;
			for (Int32 i = 0; i < pSelf->cbSize; i++)
				pSelf->GenericBytes[i] = ((pCByte)(pvData))[i];
			return True;
		}
	}

	return False;

}

_FREE_API_ pCByte _S_CALL_ SteamAPI_SteamNetworkingIdentity_GetGenericBytes(pSteamNetworkingIdentity pSelf, pInt32 cbData) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_GetGenericBytes");

	if (pSelf != NULL) {
		if (pSelf->eSteamNetworkingIdentityType == k_ESteamNetworkingIdentityType_GenericBytes)
			return (pCByte)(pSelf->GenericBytes);
	}

	return NULL;

}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_IsEqualTo(pSteamNetworkingIdentity pSelf, const pSteamNetworkingIdentity pOther) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_IsEqualTo");
	
	if (pSelf != NULL && pOther != NULL) {
		for (SizeOF i = 0; i < sizeof(SteamNetworkingIdentity); i++)
			if (((pByte)(pSelf))[i] != ((pByte)(pOther))[i]) return False;
		return True;
	}

	return False;

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingIdentity_ToString(pSteamNetworkingIdentity pSelf, pStrA pchString, Uint32 cchString) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_ToString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIdentity_ToString(pSelf, pchString, cchString);
}

_FREE_API_ Bool _S_CALL_ SteamAPI_SteamNetworkingIdentity_ParseString(pSteamNetworkingIdentity pSelf, pCStrA pchStr) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentity_ParseString");
	return (g_SteamClientGameServer->SteamNetworkingUtils).SteamNetworkingIdentity_ParseString(pSelf, pchStr);
}

/* SteamNetworkingMessage_t */

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingMessage_t_Release(pSteamNetworkingMessage_t pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingMessage_t_Release");
	if (pSelf != NULL) {
		if (pSelf->Release != NULL) {
			pSelf->Release(pSelf);
		}
	}
}

/* SteamNetworkingConfigValue_t */

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingConfigValue_t_SetInt32(pSteamNetworkingConfigValue_t pSelf, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, Int32 Data) {
	DEBUGBREAK("SteamAPI_SteamNetworkingConfigValue_t_SetInt32");
	if (pSelf != NULL) {
		pSelf->eValue = eSteamNetworkingConfigValue;
		pSelf->eDataType = k_ESteamNetworkingConfig_Int32;
		pSelf->Int32 = Data;
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingConfigValue_t_SetInt64(pSteamNetworkingConfigValue_t pSelf, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, Int64 Data) {
	DEBUGBREAK("SteamAPI_SteamNetworkingConfigValue_t_SetInt64");
	if (pSelf != NULL) {
		pSelf->eValue = eSteamNetworkingConfigValue;
		pSelf->eDataType = k_ESteamNetworkingConfig_Int64;
		pSelf->Int64 = Data;
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingConfigValue_t_SetFloat(pSteamNetworkingConfigValue_t pSelf, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, Float Data) {
	DEBUGBREAK("SteamAPI_SteamNetworkingConfigValue_t_SetFloat");
	if (pSelf != NULL) {
		pSelf->eValue = eSteamNetworkingConfigValue;
		pSelf->eDataType = k_ESteamNetworkingConfig_Float;
		pSelf->Float = Data;
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingConfigValue_t_SetPtr(pSteamNetworkingConfigValue_t pSelf, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pCStrA Data) {
	DEBUGBREAK("SteamAPI_SteamNetworkingConfigValue_t_SetPtr");
	if (pSelf != NULL) {
		pSelf->eValue = eSteamNetworkingConfigValue;
		pSelf->eDataType = k_ESteamNetworkingConfig_Ptr;
		pSelf->pchStr = Data;
	}
}

_FREE_API_ void _S_CALL_ SteamAPI_SteamNetworkingConfigValue_t_SetString(pSteamNetworkingConfigValue_t pSelf, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pVoid Data) {
	DEBUGBREAK("SteamAPI_SteamNetworkingConfigValue_t_SetString");
	if (pSelf != NULL) {
		pSelf->eValue = eSteamNetworkingConfigValue;
		pSelf->eDataType = k_ESteamNetworkingConfig_Ptr;
		pSelf->pvData = Data;
	}
}

/* SteamNetworkingPOPIDRender */

_FREE_API_ pCStrA _S_CALL_ SteamAPI_SteamNetworkingPOPIDRender_c_str(pSteamNetworkingPOPIDRender pSelf){
	DEBUGBREAK("SteamAPI_SteamNetworkingPOPIDRender_c_str");
	if (pSelf != NULL)
		return (pCStrA)(pSelf->chArray);
	return (pCStrA)("");
}

/* SteamNetworkingIdentityRender */

_FREE_API_ pCStrA _S_CALL_ SteamAPI_SteamNetworkingIdentityRender_c_str(pSteamNetworkingIdentityRender pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIdentityRender_c_str");
	if (pSelf != NULL)
		return (pCStrA)(pSelf->chArray);
	return (pCStrA)("");
}

/* SteamNetworkingIPAddrRender */

_FREE_API_ pCStrA _S_CALL_ SteamAPI_SteamNetworkingIPAddrRender_c_str(pSteamNetworkingIPAddrRender pSelf) {
	DEBUGBREAK("SteamAPI_SteamNetworkingIPAddrRender_c_str");
	if (pSelf != NULL)
		return (pCStrA)(pSelf->chArray);
	return (pCStrA)("");
}

/* SteamDatagramHostedAddress */

_FREE_API_ void _S_CALL_ SteamAPI_SteamDatagramHostedAddress_Clear(pSteamDatagramHostedAddress pSelf) {
	DEBUGBREAK("SteamAPI_SteamDatagramHostedAddress_Clear");
	
	if (pSelf != NULL) {
		pSelf->cbSize = 0;
		for (SizeOF i = 0; i < sizeof(pSelf->Data); i++) {
			pSelf->Data[i] = 0x00;
		}
	}

}

_FREE_API_ SteamNetworkingPOPID _S_CALL_ SteamAPI_SteamDatagramHostedAddress_GetPopID(pSteamDatagramHostedAddress pSelf) {
	DEBUGBREAK("SteamAPI_SteamDatagramHostedAddress_GetPopID");
	
	if (pSelf != NULL) {
		return ((((SteamNetworkingPOPID)(pSelf->Data[0])) << 16) | (((SteamNetworkingPOPID)(pSelf->Data[1])) << 8) |
			(((SteamNetworkingPOPID)(pSelf->Data[2]))) | (((SteamNetworkingPOPID)(pSelf->Data[3])) << 24));
	}

	return (SteamNetworkingPOPID)(0U);

}

_FREE_API_ void _S_CALL_ SteamAPI_SteamDatagramHostedAddress_SetDevAddress(pSteamDatagramHostedAddress pSelf, Uint32 nIP, Uint16 Port, SteamNetworkingPOPID PopId) {
	DEBUGBREAK("SteamAPI_SteamDatagramHostedAddress_SetDevAddress");

	if (pSelf != NULL) {
		pSelf->cbSize = 12;
		pSelf->Data[0] = (Byte)(PopId >> 16);
		pSelf->Data[1] = (Byte)(PopId >> 8);
		pSelf->Data[2] = (Byte)(PopId);
		pSelf->Data[3] = (Byte)(PopId >> 24);
		pSelf->Data[4] = (Byte)(0x01);
		pSelf->Data[5] = (Byte)(0x01);
		pSelf->Data[6] = (Byte)(Port);
		pSelf->Data[7] = (Byte)(Port >> 8);
		pSelf->Data[8] = (Byte)(nIP);
		pSelf->Data[9] = (Byte)(nIP >> 8);
		pSelf->Data[10] = (Byte)(nIP >> 16);
		pSelf->Data[11] = (Byte)(nIP >> 24);
	}

}

#pragma endregion
