// -----------------------------------------------------------------------------
#include "SteamNetworkingUtils.h"
// -----------------------------------------------------------------------------

static void SteamAPI_ISteamNetworkingUtils_AllocateMessage_FreeData(pSteamNetworkingMessage_t pSteamNetworkingMessage) {

	if (pSteamNetworkingMessage != NULL) {
		if (pSteamNetworkingMessage->FreeData == SteamAPI_ISteamNetworkingUtils_AllocateMessage_FreeData) {
			if (pSteamNetworkingMessage->pvData != NULL) {
				LocalFree((HLOCAL)(pSteamNetworkingMessage->pvData));
				pSteamNetworkingMessage->pvData = NULL;
				pSteamNetworkingMessage->FreeData = NULL;
				pSteamNetworkingMessage->cbSize =  0;
			}
		}
	}

}

static void SteamAPI_ISteamNetworkingUtils_AllocateMessage_Release(pSteamNetworkingMessage_t pSteamNetworkingMessage) {

	if (pSteamNetworkingMessage != NULL) {
		/* FreeData can be pointing to Our Free Function or Game Free Function */
		if (pSteamNetworkingMessage->FreeData != NULL)
			pSteamNetworkingMessage->FreeData(pSteamNetworkingMessage);
		LocalFree((HLOCAL)(pSteamNetworkingMessage));
	}

}

pSteamNetworkingMessage_t _SteamNetworkingUtils_::AllocateMessage(Int32 cbAllocateData) {

	pSteamNetworkingMessage_t pSteamNetworkingMessage = (pSteamNetworkingMessage_t)(LocalAlloc(
		LPTR, sizeof(SteamNetworkingMessage_t)
	));

	if (pSteamNetworkingMessage != NULL) {
		
		pSteamNetworkingMessage->Release = SteamAPI_ISteamNetworkingUtils_AllocateMessage_Release;

		if (cbAllocateData > 0) {
			
			pSteamNetworkingMessage->pvData = (pVoid)(LocalAlloc(
				LPTR, cbAllocateData
			));

			if (pSteamNetworkingMessage->pvData != NULL) {

				pSteamNetworkingMessage->cbSize = cbAllocateData;
				pSteamNetworkingMessage->FreeData = SteamAPI_ISteamNetworkingUtils_AllocateMessage_FreeData;
				return pSteamNetworkingMessage;

			}

		} else {

			/* Game will Allocate 'pvData' Buffer */
			return pSteamNetworkingMessage;

		}

		LocalFree((HLOCAL)(pSteamNetworkingMessage));
		pSteamNetworkingMessage = NULL;

	}

	return NULL;

}

void _SteamNetworkingUtils_::InitRelayNetworkAccess() {

	/* Empty Method */

}

ESteamNetworkingAvailability _SteamNetworkingUtils_::GetRelayNetworkStatus(pSteamRelayNetworkStatus_t pDetails) {

	return k_ESteamNetworkingAvailability_Current;

}

Float _SteamNetworkingUtils_::GetLocalPingLocation(SteamNetworkPingLocation_t pResult) {

	return (-1.0F);

}

Int32 _SteamNetworkingUtils_::EstimatePingTimeBetweenTwoLocations(const pSteamNetworkPingLocation_t pLocation1, const pSteamNetworkPingLocation_t pLocation2) {

	return 0;

}

Int32 _SteamNetworkingUtils_::EstimatePingTimeFromLocalHost(const pSteamNetworkPingLocation_t pRemoteLocation) {

	return 0;

}

void _SteamNetworkingUtils_::ConvertPingLocationToString(const pSteamNetworkPingLocation_t pLocation, pStrA pchBuf, Int32 cchBuf) {

	const pStrA pchLocation = (const pStrA)("Local");

	if (pLocation != NULL && pchBuf != NULL && (SizeOF)(cchBuf) > StrA_Count(pchLocation) + 1U) {
		StrA_Copy(pchBuf, cchBuf, pchLocation);
	}

}

Bool _SteamNetworkingUtils_::ParsePingLocationString(const pStrA pchString, pSteamNetworkPingLocation_t pResult) {

	if (pchString != NULL && pResult != NULL) {
		
		for (SizeOF i = 0; i < sizeof(pResult->cbData); i++) {
			pResult->cbData[i] = 0x00;
		}

		return True;

	}

	return False;

}

Bool _SteamNetworkingUtils_::CheckPingDataUpToDate(Float MaxAgeSeconds) {

	return True;

}

Int32 _SteamNetworkingUtils_::GetPingToDataCenter(SteamNetworkingPOPID PopId, pSteamNetworkingPOPID pViaRelayPoP) {

	if (pViaRelayPoP != NULL) {
		*pViaRelayPoP = (SteamNetworkingPOPID)(0x00000000);
	}

	return 0;

}

Int32 _SteamNetworkingUtils_::GetDirectPingToPOP(SteamNetworkingPOPID PopId) {

	return 0;

}

Int32 _SteamNetworkingUtils_::GetPOPCount() {

	return 0;

}

Int32 _SteamNetworkingUtils_::GetPOPList(pSteamNetworkingPOPID pList, Int32 nList) {

	return 0;

}

SteamNetworkingMicroseconds _SteamNetworkingUtils_::GetLocalTimestamp() {

	Uint64 UTCTime = 0U;
	GetSystemTimeAsFileTime((LPFILETIME)(&UTCTime));

	return (SteamNetworkingMicroseconds)(
		UTCTime / 10
	);

}

void _SteamNetworkingUtils_::SetDebugOutputFunction(ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pFunction) {

	/* Empty Method */

}

Bool _SteamNetworkingUtils_::IsFakeIPv4(Uint32 IPv4) {

	return False;

}

ESteamNetworkingFakeIPType _SteamNetworkingUtils_::GetIPv4FakeIPType(Uint32 IPv4) {

	return k_ESteamNetworkingFakeIPType_NotFake;

}

EResult _SteamNetworkingUtils_::GetRealIdentityForFakeIP(const pSteamNetworkingIPAddr pFakeIP, pSteamNetworkingIdentity pRealIdentity) {

	return k_EResultNoMatch;

}


Bool _SteamNetworkingUtils_::SetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid scopeObj, ESteamNetworkingConfigDataType eDataType, const pVoid pArg) {

	return True;

}

ESteamNetworkingGetConfigValueResult _SteamNetworkingUtils_::GetConfigValue(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, ESteamNetworkingConfigScope eScopeType, pVoid scopeObj, pESteamNetworkingConfigDataType pDataType, pVoid pResult, pSizeOF cbResult) {

	return k_ESteamNetworkingGetConfigValue_OK;

}

const pStrA _SteamNetworkingUtils_::GetConfigValueInfo(ESteamNetworkingConfigValue eSteamNetworkingConfigValue, pESteamNetworkingConfigDataType pDataType, pESteamNetworkingConfigScope pScope) {

	return NULL;

}

ESteamNetworkingConfigValue _SteamNetworkingUtils_::IterateGenericEditableConfigValues(ESteamNetworkingConfigValue eCurrent, Bool bEnumerateDevVars) {

	return k_ESteamNetworkingConfig_Invalid;

}

void _SteamNetworkingUtils_::SteamNetworkingIPAddr_ToString(const pSteamNetworkingIPAddr pAddr, pStrA pchStr, SizeOF cchStr, Bool bWithPort) {

	/* "0000:0000:0000:0000:0000:0000:0000:0000%12345" */
	const SizeOF cchIPv6Addr = 16U * 2U + 7U + 1U + 3U;

	if (pAddr != NULL && pchStr != NULL && cchStr > cchIPv6Addr) {

		pchStr[0] = '\0';

		for (SizeOF i = 0; i < sizeof(pAddr->IPv6); i++) {

			CharA chByte[3] = { 0 };
			chByte[0] = ((pAddr->IPv6[i] & 0xF0) >> 4);
			chByte[1] = ((pAddr->IPv6[i] & 0x0F));
			chByte[2] = '\0';

			StrA_Cat(pchStr, cchStr, chByte);
			if (i % 2 != 0 && i < 15)
				StrA_Cat(pchStr, cchStr, (const pStrA)(":"));

		}

		if (bWithPort == True) {

			StrA_Cat(pchStr, cchStr, (const pStrA)("%"));

			CharA chPort[6] = { 0 };

			Uint16 Digit = 10000;
			Uint16 Port = pAddr->Port;
			Bool bConvert = False;

			SizeOF i = 0;
			while (Digit != 0) {

				if (Port / Digit != 0) {
					bConvert = True;
				}

				if (bConvert == True) {
					chPort[i] = (Port / Digit) + '0';
					i++;
				}

				Port %= Digit;
				Digit /= 10;

			}

			if (i == 0) {
				chPort[i] = '0';
				i++;
			}

			chPort[i] = '\0';

			StrA_Cat(pchStr, cchStr, chPort);

		}

	}

}

Bool _SteamNetworkingUtils_::SteamNetworkingIPAddr_ParseString(pSteamNetworkingIPAddr pAddr, const pStrA pchStr) {

	if (pAddr != NULL && pchStr != NULL) {

		Int32 cwchCount = MultiByteToWideChar(
			CP_UTF8, WC_COMPOSITECHECK, (LPSTR)(pchStr), -1,
			NULL, 0
		);

		if (cwchCount != 0) {

			pStrW pwchStr = (pStrW)(LocalAlloc(
				LPTR, cwchCount * sizeof(CharW)
			));

			if (pwchStr != NULL) {

				MultiByteToWideChar(
					CP_UTF8, WC_COMPOSITECHECK, (LPSTR)(pchStr), -1,
					(LPWSTR)(pwchStr), cwchCount
				);

				NET_ADDRESS_INFO netAdrr;

				if (ParseNetworkString(
					(LPCWSTR)(pwchStr), NET_STRING_IP_NETWORK,
					&netAdrr, NULL, NULL
				) == ERROR_SUCCESS) {
					
					if (netAdrr.Format == NET_ADDRESS_IPV4) {

						pAddr->IPv4.x0000000000000000 = 0x0000000000000000;
						pAddr->IPv4.x0000 = 0x0000;
						pAddr->IPv4.xFFFF = 0xFFFF;
						pAddr->IPv4.cbIPv4[0] = netAdrr.Ipv4Address.sin_addr.S_un.S_un_b.s_b1;
						pAddr->IPv4.cbIPv4[1] = netAdrr.Ipv4Address.sin_addr.S_un.S_un_b.s_b2;
						pAddr->IPv4.cbIPv4[2] = netAdrr.Ipv4Address.sin_addr.S_un.S_un_b.s_b3;
						pAddr->IPv4.cbIPv4[3] = netAdrr.Ipv4Address.sin_addr.S_un.S_un_b.s_b4;
						pAddr->Port = ((Uint16)(((pByte)(&netAdrr.Ipv4Address.sin_port))[0]) << 8) |
							((Uint16)((((pByte)(&netAdrr.Ipv4Address.sin_port))[1])));

					} else {

						for (SizeOF i = 0; i < 16U; i++) {
							pAddr->IPv6[i] = netAdrr.Ipv6Address.sin6_addr.u.Byte[i];
						}

						pAddr->Port = ((Uint16)(((pByte)(&netAdrr.Ipv6Address.sin6_port))[0]) << 8) |
							((Uint16)((((pByte)(&netAdrr.Ipv6Address.sin6_port))[1])));

					}

					LocalFree((HLOCAL)(pwchStr));
					return True;

				}

				LocalFree((HLOCAL)(pwchStr));

			}

		}

	}

	return False;

}

ESteamNetworkingFakeIPType _SteamNetworkingUtils_::SteamNetworkingIPAddr_GetFakeIPType(const pSteamNetworkingIPAddr pAddr) {

	return k_ESteamNetworkingFakeIPType_NotFake;

}

void _SteamNetworkingUtils_::SteamNetworkingIdentity_ToString(const pSteamNetworkingIdentity pIdentity, pStrA pchStr, SizeOF cchStr) {

	if (pIdentity != NULL && pchStr != NULL && cchStr > 0) {
		pchStr[0] = '\0';
	}
}

Bool _SteamNetworkingUtils_::SteamNetworkingIdentity_ParseString(pSteamNetworkingIdentity pIdentity, const pStrA pchStr) {

	if (pIdentity != NULL && pchStr != NULL) {

		pIdentity->eSteamNetworkingIdentityType = k_ESteamNetworkingIdentityType_IPAddress;
		pIdentity->cbSize = sizeof(SteamNetworkingIPAddr);
		pIdentity->SteamNetworkingIPAddr.IPv4.x0000000000000000 = 0x0000000000000000;
		pIdentity->SteamNetworkingIPAddr.IPv4.x0000 = 0x0000;
		pIdentity->SteamNetworkingIPAddr.IPv4.xFFFF = 0xFFFF;
		pIdentity->SteamNetworkingIPAddr.IPv4.cbIPv4[0] = 127;
		pIdentity->SteamNetworkingIPAddr.IPv4.cbIPv4[1] = 0;
		pIdentity->SteamNetworkingIPAddr.IPv4.cbIPv4[2] = 0;
		pIdentity->SteamNetworkingIPAddr.IPv4.cbIPv4[3] = 1;
		pIdentity->SteamNetworkingIPAddr.Port = 80;

		return True;

	}

	return False;

}
