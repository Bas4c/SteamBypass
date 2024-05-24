// -----------------------------------------------------------------------------
#include "SteamHTTP.h"
// -----------------------------------------------------------------------------

HTTPRequestHandle _SteamHTTP_::CreateHTTPRequest(EHTTPMethod eHTTPRequestMethod, pCStrA pchAbsoluteURL) {
	DEBUGBREAK("ISteamHTTP::CreateHTTPRequest");

	return k_HTTPRequestHandle_Invalid;

}

Bool _SteamHTTP_::SetHTTPRequestContextValue(HTTPRequestHandle hRequest, Uint64 ContextValue) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestContextValue");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, Uint32 nTimeoutSeconds) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestNetworkActivityTimeout");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pCStrA pchHeaderValue) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestHeaderValue");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, pCStrA pchParamName, pCStrA pchParamValue) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestGetOrPostParameter");

	return False;

}

Bool _SteamHTTP_::SendHTTPRequest(HTTPRequestHandle hRequest, pSteamAPICall_t hCall) {
	DEBUGBREAK("ISteamHTTP::SendHTTPRequest");

	return False;

}

Bool _SteamHTTP_::SendHTTPRequestAndStreamResponse(HTTPRequestHandle hRequest, pSteamAPICall_t hCall) {
	DEBUGBREAK("ISteamHTTP::SendHTTPRequestAndStreamResponse");

	return False;

}

Bool _SteamHTTP_::DeferHTTPRequest(HTTPRequestHandle hRequest) {
	DEBUGBREAK("ISteamHTTP::DeferHTTPRequest");

	return False;

}

Bool _SteamHTTP_::PrioritizeHTTPRequest(HTTPRequestHandle hRequest) {
	DEBUGBREAK("ISteamHTTP::PrioritizeHTTPRequest");

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseHeaderSize(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint32 pnResponseHeaderSize) {
	DEBUGBREAK("ISteamHTTP::GetHTTPResponseHeaderSize");

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseHeaderValue(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint8 pnHeaderValue, Uint32 nHeaderValue) {
	DEBUGBREAK("ISteamHTTP::GetHTTPResponseHeaderValue");

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseBodySize(HTTPRequestHandle hRequest, pUint32 pnBodySize) {
	DEBUGBREAK("ISteamHTTP::GetHTTPResponseBodySize");

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseBodyData(HTTPRequestHandle hRequest, pUint8 pnBodyData, Uint32 nBodyData) {
	DEBUGBREAK("ISteamHTTP::GetHTTPResponseBodyData");

	return False;

}

Bool _SteamHTTP_::GetHTTPStreamingResponseBodyData(HTTPRequestHandle hRequest, Uint32 cOffset, pUint8 pnBodyData, Uint32 nBodyData) {
	DEBUGBREAK("ISteamHTTP::GetHTTPStreamingResponseBodyData");

	return False;

}

Bool _SteamHTTP_::ReleaseHTTPRequest(HTTPRequestHandle hRequest) {
	DEBUGBREAK("ISteamHTTP::ReleaseHTTPRequest");

	return False;

}

Bool _SteamHTTP_::GetHTTPDownloadProgressPct(HTTPRequestHandle hRequest, pFloat pPercent) {
	DEBUGBREAK("ISteamHTTP::GetHTTPDownloadProgressPct");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestRawPostBody(HTTPRequestHandle hRequest, pCStrA pchContentType, pUint8 pbBody, Uint32 cbBody) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestRawPostBody");

	return False;

}

HTTPCookieContainerHandle _SteamHTTP_::CreateCookieContainer(Bool bAllowResponsesToModify) {
	DEBUGBREAK("ISteamHTTP::CreateCookieContainer");

	return k_HTTPCookieContainerHandle_Invalid;

}

Bool _SteamHTTP_::ReleaseCookieContainer(HTTPCookieContainerHandle hCookieContainer) {
	DEBUGBREAK("ISteamHTTP::ReleaseCookieContainer");

	return False;

}

Bool _SteamHTTP_::SetCookie(HTTPCookieContainerHandle hCookieContainer, pCStrA pchHost, pCStrA pchUrl, pCStrA pchCookie) {
	DEBUGBREAK("ISteamHTTP::SetCookie");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestCookieContainer");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, pCStrA pchUserAgentInfo) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestUserAgentInfo");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, Bool bRequireVerifiedCertificate) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestRequiresVerifiedCertificate");

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, Uint32 nMilliseconds) {
	DEBUGBREAK("ISteamHTTP::SetHTTPRequestAbsoluteTimeoutMS");

	return False;

}

Bool _SteamHTTP_::GetHTTPRequestWasTimedOut(HTTPRequestHandle hRequest, pBool pbWasTimedOut) {
	DEBUGBREAK("ISteamHTTP::GetHTTPRequestWasTimedOut");

	return False;

}
