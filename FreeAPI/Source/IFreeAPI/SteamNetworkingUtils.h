#ifndef _STEAMNETWORKINGUTILS_
#define _STEAMNETWORKINGUTILS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamNetworkingUtils.h"
// -----------------------------------------------------------------------------

typedef class _SteamNetworkingUtils_ : public _ISteamNetworkingUtils001_,
 public _ISteamNetworkingUtils002_, public _ISteamNetworkingUtils003_,
 public _ISteamNetworkingUtils_ {
public:

	_SteamNetworkingUtils_() = default;
	_SteamNetworkingUtils_(const _SteamNetworkingUtils_&) = delete;
	_SteamNetworkingUtils_& operator=(const _SteamNetworkingUtils_&) = delete;

	pSteamNetworkingMessage_t AllocateMessage(Int32 cbAllocateData) override;
	void InitRelayNetworkAccess() override;
	ESteamNetworkingAvailability GetRelayNetworkStatus(pSteamRelayNetworkStatus_t pDetails) override;
	Float GetLocalPingLocation(SteamNetworkPingLocation_t pResult) override;
	Int32 EstimatePingTimeBetweenTwoLocations(const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) override;
	Int32 EstimatePingTimeFromLocalHost(const pSteamNetworkPingLocation_t pRemoteLocation) override;
	void ConvertPingLocationToString(const pSteamNetworkPingLocation_t pLocation, pStrA pchBuf, Int32 cchBuf) override;
	Bool ParsePingLocationString(pCStrA pchString, pSteamNetworkPingLocation_t pResult) override;
	Bool CheckPingDataUpToDate(Float MaxAgeSeconds) override;
	Bool IsPingMeasurementInProgress() override;
	Int32 GetPingToDataCenter(SteamNetworkingPOPID PopId, pSteamNetworkingPOPID pViaRelayPoP) override;
	Int32 GetDirectPingToPOP(SteamNetworkingPOPID PopId) override;
	Int32 GetPOPCount() override;
	Int32 GetPOPList(pSteamNetworkingPOPID pList, Int32 nList) override;
	SteamNetworkingMicroseconds GetLocalTimestamp() override;
	void SetDebugOutputFunction(ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pFunction) override;
	Bool IsFakeIPv4(Uint32 IPv4) override;
	ESteamNetworkingFakeIPType GetIPv4FakeIPType(Uint32 IPv4) override;
	EResult GetRealIdentityForFakeIP(const pSteamNetworkingIPAddr pFakeIP, pSteamNetworkingIdentity pRealIdentity) override;

	Bool SetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, ESteamNetworkingConfigDataType eDataType, pCVoid pArg) override;
	ESteamNetworkingGetConfigValueResult GetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid ScopeObj, pESteamNetworkingConfigDataType pDataType, pVoid pResult, pSizeOF cbResult) override;
	/* Return True of config value or False if not exist */
	Bool GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pCStrA *pchName, pESteamNetworkingConfigDataType pDataType, pESteamNetworkingConfigScope pScope, pESteamNetworkingConfigValue pNextValue) override;
	/* Return name of config value or NULL if not exist */
	pCStrA GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pESteamNetworkingConfigDataType pDataType, pESteamNetworkingConfigScope pScope) override;
	ESteamNetworkingConfigValue GetFirstConfigValue() override;
	ESteamNetworkingConfigValue IterateGenericEditableConfigValues(ESteamNetworkingConfigValue eCurrent, Bool bEnumerateDevVars) override;
	void SteamNetworkingIPAddr_ToString(const pSteamNetworkingIPAddr pAddr, pStrA pchStr, SizeOF cchStr, Bool bWithPort) override;
	Bool SteamNetworkingIPAddr_ParseString(pSteamNetworkingIPAddr pAddr, pCStrA pchStr) override;
	ESteamNetworkingFakeIPType SteamNetworkingIPAddr_GetFakeIPType(const pSteamNetworkingIPAddr pAddr) override;
	void SteamNetworkingIdentity_ToString(const pSteamNetworkingIdentity pIdentity, pStrA pchStr, SizeOF cchStr) override;
	Bool SteamNetworkingIdentity_ParseString(pSteamNetworkingIdentity pIdentity, pCStrA pchStr) override;

	~_SteamNetworkingUtils_() = default;

} SteamNetworkingUtils, *pSteamNetworkingUtils;

#endif // !_STEAMNETWORKINGUTILS_
