#ifndef _ISTEAMNETWORKINGUTILS_
#define _ISTEAMNETWORKINGUTILS_

#include "..\..\FreeAPI.Typedef.h"

typedef void (*SteamNetConnectionStatusChanged) (pVoid pData);
typedef void (*SteamNetAuthenticationStatusChanged) (pVoid pData);
typedef void (*SteamRelayNetworkStatusChanged) (pVoid pData);
typedef void (*SteamNetworkingMessagesSessionRequest) (pVoid pData);
typedef void (*SteamNetworkingMessagesSessionFailed) (pVoid pData);
typedef void (*SteamNetworkingFakeIPResult) (pVoid pData);

typedef enum _ESteamNetworkingFakeIPType_ {

	k_ESteamNetworkingFakeIPType_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingFakeIPType, * pESteamNetworkingFakeIPType;
typedef enum _ESteamNetworkingGetConfigValueResult_ {

	k_ESteamNetworkingGetConfigValue_OK = 1,
	k_ESteamNetworkingGetConfigValueResult_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingGetConfigValueResult, *pESteamNetworkingGetConfigValueResult;

typedef enum _ESteamNetworkingSocketsDebugOutputType_ {

	k_ESteamNetworkingSocketsDebugOutputType_None = 0,
	k_ESteamNetworkingSocketsDebugOutputType_Warning = 4,
	k_ESteamNetworkingSocketsDebugOutputType_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingSocketsDebugOutputType, *pESteamNetworkingSocketsDebugOutputType;
typedef void (*FSteamNetworkingSocketsDebugOutput) (ESteamNetworkingSocketsDebugOutputType nType, const pStrA pchMsg);

typedef enum _ESteamNetworkingConfigScope_ {

	k_ESteamNetworkingConfig_Global = 1,
	k_ESteamNetworkingConfig_SocketsInterface = 2,
	k_ESteamNetworkingConfig_ListenSocket = 3,
	k_ESteamNetworkingConfig_Connection = 4,
	k_ESteamNetworkingConfigScope__Force32Bit = 0x7FFFFFFF

} ESteamNetworkingConfigScope, *pESteamNetworkingConfigScope;
typedef struct _SteamRelayNetworkStatus_t_ SteamRelayNetworkStatus_t, *pSteamRelayNetworkStatus_t;

typedef class _ISteamNetworkingUtils_ {
public:

	virtual pSteamNetworkingMessage_t AllocateMessage(Int32 cbAllocate) = 0;
	virtual void InitRelayNetworkAccess() = 0;
	virtual ESteamNetworkingAvailability GetRelayNetworkStatus(/* [out] */ pSteamRelayNetworkStatus_t pDetails) = 0;
	virtual Float GetLocalPingLocation(/* [out] */ SteamNetworkPingLocation_t pResult) = 0;
	virtual Int32 EstimatePingTimeBetweenTwoLocations(const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) = 0;
	virtual Int32 EstimatePingTimeFromLocalHost(const pSteamNetworkPingLocation_t pRemoteLocation) = 0;
	virtual void ConvertPingLocationToString(const pSteamNetworkPingLocation_t pLocation, /* [out] */ pStrA pchBuf, Int32 cchBufSize) = 0;
	virtual Bool ParsePingLocationString(const pStrA pchString, pSteamNetworkPingLocation_t pResult) = 0;
	virtual Bool CheckPingDataUpToDate(Float MaxAgeSeconds) = 0;
	virtual Int32 GetPingToDataCenter(SteamNetworkingPOPID PopId, /* [out] */ pSteamNetworkingPOPID pViaRelayPoP) = 0;
	virtual Int32 GetDirectPingToPOP(SteamNetworkingPOPID PopId) = 0;
	virtual Int32 GetPOPCount() = 0;
	virtual Int32 GetPOPList(/* [out] */ pSteamNetworkingPOPID pList, Int32 nList) = 0;
	virtual SteamNetworkingMicroseconds GetLocalTimestamp() = 0;
	virtual void SetDebugOutputFunction(ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pFunction) = 0;
	virtual Bool IsFakeIPv4(Uint32 IPv4) = 0;
	virtual ESteamNetworkingFakeIPType GetIPv4FakeIPType(Uint32 IPv4) = 0;
	virtual EResult GetRealIdentityForFakeIP(const pSteamNetworkingIPAddr pFakeIP, /* [out] */ pSteamNetworkingIdentity pRealIdentity) = 0;
	
	virtual Bool SetGlobalConfigValueInt32(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, Int32 Value) = 0;
	virtual Bool SetGlobalConfigValueFloat(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, Float Value) = 0;
	virtual Bool SetGlobalConfigValueString(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, const pStrA Value) = 0;
	virtual Bool SetGlobalConfigValuePtr(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pVoid Value) = 0;
	
	virtual Bool SetConnectionConfigValueInt32(HSteamNetConnection hConnection, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, Int32 Value) = 0;
	virtual Bool SetConnectionConfigValueFloat(HSteamNetConnection hConnection, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, Float Value) = 0;
	virtual Bool SetConnectionConfigValueString(HSteamNetConnection hConnection, ESteamNetworkingConfigValue eSteamNetworkingConfigValue, const pStrA Value) = 0;
	
	virtual Bool SetGlobalCallback_SteamNetConnectionStatusChanged(SteamNetConnectionStatusChanged pFunction) = 0;
	virtual Bool SetGlobalCallback_SteamNetAuthenticationStatusChanged(SteamNetAuthenticationStatusChanged pFunction) = 0;
	virtual Bool SetGlobalCallback_SteamRelayNetworkStatusChanged(SteamRelayNetworkStatusChanged pFunction) = 0;
	virtual Bool SetGlobalCallback_FakeIPResult(SteamNetworkingFakeIPResult pFunction) = 0;
	virtual Bool SetGlobalCallback_MessagesSessionRequest(SteamNetworkingMessagesSessionRequest pFunction) = 0;
	virtual Bool SetGlobalCallback_MessagesSessionFailed(SteamNetworkingMessagesSessionFailed pFunction) = 0;
	
	virtual Bool SetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid scopeObj, ESteamNetworkingConfigDataType eDataType, const pVoid pArg) = 0;
	virtual Bool SetConfigValueStruct(const pSteamNetworkingConfigValue_t pOptional, ESteamNetworkingConfigScope eScopeType, pVoid pScopeObject) = 0;
	virtual ESteamNetworkingGetConfigValueResult GetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, /* [out] */ pVoid scopeObj, /* [out] */ pESteamNetworkingConfigDataType pDataType, /* [out] */ pVoid pResult, pSizeOF cbResult) = 0;
	virtual const pStrA GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, /* [out] */ pESteamNetworkingConfigDataType pDataType, /* [out] */ pESteamNetworkingConfigScope pScope) = 0;
	virtual ESteamNetworkingConfigValue IterateGenericEditableConfigValues(ESteamNetworkingConfigValue eCurrent, Bool bEnumerateDevVars) = 0;
	virtual void SteamNetworkingIPAddr_ToString(const pSteamNetworkingIPAddr pAddr, pStrA buf, size_t cbBuf, Bool bWithPort) = 0;
	virtual Bool SteamNetworkingIPAddr_ParseString(/* [out] */ pSteamNetworkingIPAddr pAddr, const pStrA pchStr) = 0;
	virtual ESteamNetworkingFakeIPType SteamNetworkingIPAddr_GetFakeIPType(const pSteamNetworkingIPAddr pAddr) = 0;
	virtual void SteamNetworkingIdentity_ToString(const pSteamNetworkingIdentity pIdentity, pVoid pbBuf, SizeOF cBBuf) = 0;
	virtual Bool SteamNetworkingIdentity_ParseString(/* [out] */ pSteamNetworkingIdentity pIdentity, const pStrA pchStr) = 0;

} ISteamNetworkingUtils, *IpSteamNetworkingUtils;

#define STEAMNETWORKINGUTILS_INTERFACE_VERSION "SteamNetworkingUtils004"

#define k_iCallbback_SteamRelayNetworkStatus_t_ ((Int32)(k_iSteamNetworkingUtilsCallbacks + 1))
typedef struct _SteamRelayNetworkStatus_t_ {

	ESteamNetworkingAvailability eAvail;
	Int32 bPingMeasurementInProgress;
	ESteamNetworkingAvailability eAvailNetworkConfig;
	ESteamNetworkingAvailability eAvailAnyRelay;
	CharA chDebugMsg[256];

} SteamRelayNetworkStatus_t, *pSteamRelayNetworkStatus_t;

#endif // _ISTEAMNETWORKINGUTILS_
