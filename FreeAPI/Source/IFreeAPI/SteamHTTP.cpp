// -----------------------------------------------------------------------------
#include "SteamHTTP.h"
// -----------------------------------------------------------------------------

HTTPRequestHandle _SteamHTTP_::CreateHTTPRequest(EHTTPMethod eHTTPRequestMethod, pCStrA pchAbsoluteURL) {

	return k_HTTPRequestHandle_Invalid;

}

Bool _SteamHTTP_::SetHTTPRequestContextValue(HTTPRequestHandle hRequest, Uint64 ContextValue) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, Uint32 nTimeoutSeconds) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pCStrA pchHeaderValue) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, pCStrA pchParamName, pCStrA pchParamValue) {

	return False;

}

Bool _SteamHTTP_::SendHTTPRequest(HTTPRequestHandle hRequest, pSteamAPICall_t hCall) {

	return False;

}

Bool _SteamHTTP_::SendHTTPRequestAndStreamResponse(HTTPRequestHandle hRequest, pSteamAPICall_t hCall) {

	return False;

}

Bool _SteamHTTP_::DeferHTTPRequest(HTTPRequestHandle hRequest) {

	return False;

}

Bool _SteamHTTP_::PrioritizeHTTPRequest(HTTPRequestHandle hRequest) {

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseHeaderSize(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint32 pnResponseHeaderSize) {

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseHeaderValue(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint8 pnHeaderValue, Uint32 nHeaderValue) {

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseBodySize(HTTPRequestHandle hRequest, pUint32 pnBodySize) {

	return False;

}

Bool _SteamHTTP_::GetHTTPResponseBodyData(HTTPRequestHandle hRequest, pUint8 pnBodyData, Uint32 nBodyData) {

	return False;

}

Bool _SteamHTTP_::GetHTTPStreamingResponseBodyData(HTTPRequestHandle hRequest, Uint32 cOffset, pUint8 pnBodyData, Uint32 nBodyData) {

	return False;

}

Bool _SteamHTTP_::ReleaseHTTPRequest(HTTPRequestHandle hRequest) {

	return False;

}

Bool _SteamHTTP_::GetHTTPDownloadProgressPct(HTTPRequestHandle hRequest, pFloat pPercent) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestRawPostBody(HTTPRequestHandle hRequest, pCStrA pchContentType, pUint8 pbBody, Uint32 cbBody) {

	return False;

}

HTTPCookieContainerHandle _SteamHTTP_::CreateCookieContainer(Bool bAllowResponsesToModify) {

	return k_HTTPCookieContainerHandle_Invalid;

}

Bool _SteamHTTP_::ReleaseCookieContainer(HTTPCookieContainerHandle hCookieContainer) {

	return False;

}

Bool _SteamHTTP_::SetCookie(HTTPCookieContainerHandle hCookieContainer, pCStrA pchHost, pCStrA pchUrl, pCStrA pchCookie) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, pCStrA pchUserAgentInfo) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, Bool bRequireVerifiedCertificate) {

	return False;

}

Bool _SteamHTTP_::SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, Uint32 nMilliseconds) {

	return False;

}

Bool _SteamHTTP_::GetHTTPRequestWasTimedOut(HTTPRequestHandle hRequest, pBool pbWasTimedOut) {

	return False;

}
