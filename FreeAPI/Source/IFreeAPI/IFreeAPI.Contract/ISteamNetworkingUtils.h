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

	k_ESteamNetworkingFakeIPType_Invalid,
	k_ESteamNetworkingFakeIPType_NotFake,
	k_ESteamNetworkingFakeIPType_GlobalIPv4,
	k_ESteamNetworkingFakeIPType_LocalIPv4,

	k_ESteamNetworkingFakeIPType_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingFakeIPType, *pESteamNetworkingFakeIPType;
typedef enum _ESteamNetworkingGetConfigValueResult_ {

	k_ESteamNetworkingGetConfigValue_OK = 1,
	k_ESteamNetworkingGetConfigValueResult_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingGetConfigValueResult, *pESteamNetworkingGetConfigValueResult;

typedef enum _ESteamNetworkingSocketsDebugOutputType_ {

	k_ESteamNetworkingSocketsDebugOutputType_None = 0,
	k_ESteamNetworkingSocketsDebugOutputType_Warning = 4,
	k_ESteamNetworkingSocketsDebugOutputType_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingSocketsDebugOutputType, *pESteamNetworkingSocketsDebugOutputType;
typedef void (*FSteamNetworkingSocketsDebugOutput) (ESteamNetworkingSocketsDebugOutputType nType, pCStrA pchMsg);

typedef enum _ESteamNetworkingConfigScope_ {

	k_ESteamNetworkingConfig_Global = 1,
	k_ESteamNetworkingConfig_SocketsInterface = 2,
	k_ESteamNetworkingConfig_ListenSocket = 3,
	k_ESteamNetworkingConfig_Connection = 4,
	k_ESteamNetworkingConfigScope_Force32Bit = 0x7FFFFFFF

} ESteamNetworkingConfigScope, *pESteamNetworkingConfigScope;
typedef struct _SteamRelayNetworkStatus_t_ SteamRelayNetworkStatus_t, *pSteamRelayNetworkStatus_t;

typedef class _ISteamNetworkingUtils001_ {
public:

	virtual ESteamNetworkingAvailability GetRelayNetworkStatus(pSteamRelayNetworkStatus_t pDetails) = 0;
	virtual Float GetLocalPingLocation(SteamNetworkPingLocation_t pResult) = 0;
	virtual Int32 EstimatePingTimeBetweenTwoLocations(const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) = 0;
	virtual Int32 EstimatePingTimeFromLocalHost(const pSteamNetworkPingLocation_t pRemoteLocation) = 0;
	virtual void ConvertPingLocationToString(const pSteamNetworkPingLocation_t pLocation, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool ParsePingLocationString(pCStrA pchString, pSteamNetworkPingLocation_t pResult) = 0;
	virtual Bool CheckPingDataUpToDate(Float MaxAgeSeconds) = 0;
	virtual Bool IsPingMeasurementInProgress() = 0;
	virtual Int32 GetPingToDataCenter(SteamNetworkingPOPID PopId, pSteamNetworkingPOPID pViaRelayPoP) = 0;
	virtual Int32 GetDirectPingToPOP(SteamNetworkingPOPID PopId) = 0;
	virtual Int32 GetPOPCount() = 0;
	virtual Int32 GetPOPList(pSteamNetworkingPOPID pList, Int32 nList) = 0;
	virtual SteamNetworkingMicroseconds GetLocalTimestamp() = 0;
	virtual void SetDebugOutputFunction(ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pFunction) = 0;
	virtual Bool SetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, ESteamNetworkingConfigDataType eDataType, pCVoid pArg) = 0;
	virtual ESteamNetworkingGetConfigValueResult GetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, pESteamNetworkingConfigDataType pDataType, pVoid pResult, pSizeOF cbResult) = 0;
	virtual Bool GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pCStrA *pchName, pESteamNetworkingConfigDataType pDataType, pESteamNetworkingConfigScope pScope, pESteamNetworkingConfigValue pNextValue) = 0;
	virtual ESteamNetworkingConfigValue GetFirstConfigValue() = 0;
	virtual void SteamNetworkingIPAddr_ToString(const pSteamNetworkingIPAddr pAddr, pStrA pchStr, SizeOF cchStr, Bool bWithPort) = 0;
	virtual Bool SteamNetworkingIPAddr_ParseString(pSteamNetworkingIPAddr pAddr, pCStrA pchStr) = 0;
	virtual void SteamNetworkingIdentity_ToString(const pSteamNetworkingIdentity pIdentity, pStrA pchStr, SizeOF cchStr) = 0;
	virtual Bool SteamNetworkingIdentity_ParseString(pSteamNetworkingIdentity pIdentity, pCStrA pchStr) = 0;

} ISteamNetworkingUtils001, *IpSteamNetworkingUtils001;

typedef class _ISteamNetworkingUtils002_ {
public:

	virtual void InitRelayNetworkAccess() = 0;
	virtual ESteamNetworkingAvailability GetRelayNetworkStatus(pSteamRelayNetworkStatus_t pDetails) = 0;
	virtual Float GetLocalPingLocation(SteamNetworkPingLocation_t pResult) = 0;
	virtual Int32 EstimatePingTimeBetweenTwoLocations(const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) = 0;
	virtual Int32 EstimatePingTimeFromLocalHost(const pSteamNetworkPingLocation_t pRemoteLocation) = 0;
	virtual void ConvertPingLocationToString(const pSteamNetworkPingLocation_t pLocation, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool ParsePingLocationString(pCStrA pchString, pSteamNetworkPingLocation_t pResult) = 0;
	virtual Bool CheckPingDataUpToDate(Float MaxAgeSeconds) = 0;
	virtual Int32 GetPingToDataCenter(SteamNetworkingPOPID PopId, pSteamNetworkingPOPID pViaRelayPoP) = 0;
	virtual Int32 GetDirectPingToPOP(SteamNetworkingPOPID PopId) = 0;
	virtual Int32 GetPOPCount() = 0;
	virtual Int32 GetPOPList(pSteamNetworkingPOPID pList, Int32 nList) = 0;
	virtual SteamNetworkingMicroseconds GetLocalTimestamp() = 0;
	virtual void SetDebugOutputFunction(ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pFunction) = 0;
	virtual Bool SetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, ESteamNetworkingConfigDataType eDataType, pCVoid pArg) = 0;
	virtual ESteamNetworkingGetConfigValueResult GetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, pESteamNetworkingConfigDataType pDataType, pVoid pResult, pSizeOF cbResult) = 0;
	virtual Bool GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pCStrA *pchName, pESteamNetworkingConfigDataType pDataType, pESteamNetworkingConfigScope pScope, pESteamNetworkingConfigValue pNextValue) = 0;
	virtual ESteamNetworkingConfigValue GetFirstConfigValue() = 0;
	virtual void SteamNetworkingIPAddr_ToString(const pSteamNetworkingIPAddr pAddr, pStrA pchStr, SizeOF cchStr, Bool bWithPort) = 0;
	virtual Bool SteamNetworkingIPAddr_ParseString(pSteamNetworkingIPAddr pAddr, pCStrA pchStr) = 0;
	virtual void SteamNetworkingIdentity_ToString(const pSteamNetworkingIdentity pIdentity, pStrA pchStr, SizeOF cchStr) = 0;
	virtual Bool SteamNetworkingIdentity_ParseString(pSteamNetworkingIdentity pIdentity, pCStrA pchStr) = 0;

} ISteamNetworkingUtils002, *IpSteamNetworkingUtils002;

typedef class _ISteamNetworkingUtils003_ {
public:

	virtual pSteamNetworkingMessage_t AllocateMessage(Int32 cbAllocateData) = 0;
	virtual void InitRelayNetworkAccess() = 0;
	virtual ESteamNetworkingAvailability GetRelayNetworkStatus(pSteamRelayNetworkStatus_t pDetails) = 0;
	virtual Float GetLocalPingLocation(SteamNetworkPingLocation_t pResult) = 0;
	virtual Int32 EstimatePingTimeBetweenTwoLocations(const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) = 0;
	virtual Int32 EstimatePingTimeFromLocalHost(const pSteamNetworkPingLocation_t pRemoteLocation) = 0;
	virtual void ConvertPingLocationToString(const pSteamNetworkPingLocation_t pLocation, pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool ParsePingLocationString(pCStrA pchString, pSteamNetworkPingLocation_t pResult) = 0;
	virtual Bool CheckPingDataUpToDate(Float MaxAgeSeconds) = 0;
	virtual Int32 GetPingToDataCenter(SteamNetworkingPOPID PopId, pSteamNetworkingPOPID pViaRelayPoP) = 0;
	virtual Int32 GetDirectPingToPOP(SteamNetworkingPOPID PopId) = 0;
	virtual Int32 GetPOPCount() = 0;
	virtual Int32 GetPOPList(pSteamNetworkingPOPID pList, Int32 nList) = 0;
	virtual SteamNetworkingMicroseconds GetLocalTimestamp() = 0;
	virtual void SetDebugOutputFunction(ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pFunction) = 0;
	virtual Bool SetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, ESteamNetworkingConfigDataType eDataType, pCVoid pArg) = 0;
	virtual ESteamNetworkingGetConfigValueResult GetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, pESteamNetworkingConfigDataType pDataType, pVoid pResult, pSizeOF cbResult) = 0;
	virtual Bool GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pCStrA *pchName, pESteamNetworkingConfigDataType pDataType, pESteamNetworkingConfigScope pScope, pESteamNetworkingConfigValue pNextValue) = 0;
	virtual ESteamNetworkingConfigValue GetFirstConfigValue() = 0;
	virtual void SteamNetworkingIPAddr_ToString(const pSteamNetworkingIPAddr pAddr, pStrA pchStr, SizeOF cchStr, Bool bWithPort) = 0;
	virtual Bool SteamNetworkingIPAddr_ParseString(pSteamNetworkingIPAddr pAddr, pCStrA pchStr) = 0;
	virtual void SteamNetworkingIdentity_ToString(const pSteamNetworkingIdentity pIdentity, pStrA pchStr, SizeOF cchStr) = 0;
	virtual Bool SteamNetworkingIdentity_ParseString(pSteamNetworkingIdentity pIdentity, pCStrA pchStr) = 0;

} ISteamNetworkingUtils003, *IpSteamNetworkingUtils003;

typedef class _ISteamNetworkingUtils_ {
public:

	virtual pSteamNetworkingMessage_t AllocateMessage(Int32 cbAllocateData) = 0;
	virtual void InitRelayNetworkAccess() = 0;
	virtual ESteamNetworkingAvailability GetRelayNetworkStatus(/* [out] */ pSteamRelayNetworkStatus_t pDetails) = 0;
	virtual Float GetLocalPingLocation(/* [out] */ SteamNetworkPingLocation_t pResult) = 0;
	virtual Int32 EstimatePingTimeBetweenTwoLocations(const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) = 0;
	virtual Int32 EstimatePingTimeFromLocalHost(const pSteamNetworkPingLocation_t pRemoteLocation) = 0;
	virtual void ConvertPingLocationToString(const pSteamNetworkPingLocation_t pLocation, /* [out] */ pStrA pchBuf, Int32 cchBuf) = 0;
	virtual Bool ParsePingLocationString(pCStrA pchString, pSteamNetworkPingLocation_t pResult) = 0;
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

	virtual Bool SetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, ESteamNetworkingConfigDataType eDataType, pCVoid pArg) = 0;
	virtual ESteamNetworkingGetConfigValueResult GetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, /* [out] */ pVoid ScopeObj, /* [out] */ pESteamNetworkingConfigDataType pDataType, /* [out] */ pVoid pResult, pSizeOF cbResult) = 0;
	/* Return name of config value or NULL if not exist */
	virtual pCStrA GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, /* [out] */ pESteamNetworkingConfigDataType pDataType, /* [out] */ pESteamNetworkingConfigScope pScope) = 0;
	virtual ESteamNetworkingConfigValue IterateGenericEditableConfigValues(ESteamNetworkingConfigValue eCurrent, Bool bEnumerateDevVars) = 0;
	virtual void SteamNetworkingIPAddr_ToString(const pSteamNetworkingIPAddr pAddr, pStrA pchStr, SizeOF cchStr, Bool bWithPort) = 0;
	virtual Bool SteamNetworkingIPAddr_ParseString(/* [out] */ pSteamNetworkingIPAddr pAddr, pCStrA pchStr) = 0;
	virtual ESteamNetworkingFakeIPType SteamNetworkingIPAddr_GetFakeIPType(const pSteamNetworkingIPAddr pAddr) = 0;
	virtual void SteamNetworkingIdentity_ToString(const pSteamNetworkingIdentity pIdentity, pStrA pchStr, SizeOF cchStr) = 0;
	virtual Bool SteamNetworkingIdentity_ParseString(/* [out] */ pSteamNetworkingIdentity pIdentity, pCStrA pchStr) = 0;

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
