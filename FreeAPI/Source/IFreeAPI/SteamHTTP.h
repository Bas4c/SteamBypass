#ifndef _STEAMHTTP_
#define _STEAMHTTP_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamHTTP.h"
// -----------------------------------------------------------------------------

typedef class _SteamHTTP_ : public _ISteamHTTP001_,
 public _ISteamHTTP002_, public _ISteamHTTP_ {
public:

	_SteamHTTP_() = default;
	_SteamHTTP_(const _SteamHTTP_&) = delete;
	_SteamHTTP_& operator=(const _SteamHTTP_&) = delete;

	HTTPRequestHandle CreateHTTPRequest(EHTTPMethod eHTTPRequestMethod, pCStrA pchAbsoluteURL) override;

	/* Set a context value for the request, which will be returned in the HTTPRequestCompleted_t callback after
		sending the request. This is just so the caller can easily keep track of which callbacks go with which request data. */
	Bool SetHTTPRequestContextValue(HTTPRequestHandle hRequest, Uint64 ContextValue) override;

	/* Set timeout in seconds for the HTTP request, must be called prior to sending the request.  Default
		timeout is 60 seconds if you don't call this. Returns False if the handle is invalid, or the request
		has already been sent. */
	Bool SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, Uint32 nTimeoutSeconds) override;
	Bool SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pCStrA pchHeaderValue) override;
	Bool SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, pCStrA pchParamName, pCStrA pchParamValue) override;
	Bool SendHTTPRequest(HTTPRequestHandle hRequest, pSteamAPICall_t hCall) override;

	/* Sends the HTTP request, will return False on a bad handle, otherwise use SteamCallHandle to wait on
		asynchronous response via callback for completion, and listen for HTTPRequestHeadersReceived_t and
		HTTPRequestDataReceived_t callbacks while streaming. */
	Bool SendHTTPRequestAndStreamResponse(HTTPRequestHandle hRequest, pSteamAPICall_t hCall) override;

	Bool DeferHTTPRequest(HTTPRequestHandle hRequest) override;
	Bool PrioritizeHTTPRequest(HTTPRequestHandle hRequest) override;

	Bool GetHTTPResponseHeaderSize(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint32 pnResponseHeaderSize) override;
	Bool GetHTTPResponseHeaderValue(HTTPRequestHandle hRequest, pCStrA pchHeaderName, pUint8 pnHeaderValue, Uint32 nHeaderValue) override;

	Bool GetHTTPResponseBodySize(HTTPRequestHandle hRequest, pUint32 pnBodySize) override;
	Bool GetHTTPResponseBodyData(HTTPRequestHandle hRequest, pUint8 pnBodyData, Uint32 nBodyData) override;

	Bool GetHTTPStreamingResponseBodyData(HTTPRequestHandle hRequest, Uint32 cOffset, pUint8 pnBodyData, Uint32 nBodyData) override;

	Bool ReleaseHTTPRequest(HTTPRequestHandle hRequest) override;
	Bool GetHTTPDownloadProgressPct(HTTPRequestHandle hRequest, pFloat pPercent) override;
	Bool SetHTTPRequestRawPostBody(HTTPRequestHandle hRequest, pCStrA pchContentType, pUint8 pbBody, Uint32 cbBody) override;

	/* Creates a cookie container handle which you must later free with ReleaseCookieContainer(). If bAllowResponsesToModify=true
		than any response to your requests using this cookie container may add new cookies which may be transmitted with
		future requests. If bAllowResponsesToModify=False than only cookies you explicitly set will be sent. This API is just for
		during process lifetime, after steam restarts no cookies are persisted and you have no way to access the cookie container across
		repeat executions of your process. */
	HTTPCookieContainerHandle CreateCookieContainer(Bool bAllowResponsesToModify) override;
	Bool ReleaseCookieContainer(HTTPCookieContainerHandle hCookieContainer) override;
	Bool SetCookie(HTTPCookieContainerHandle hCookieContainer, pCStrA pchHost, pCStrA pchUrl, pCStrA pchCookie) override;
	Bool SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer) override;

	Bool SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, pCStrA pchUserAgentInfo) override;
	Bool SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, Bool bRequireVerifiedCertificate) override;

	Bool SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, Uint32 nMilliseconds) override;
	Bool GetHTTPRequestWasTimedOut(HTTPRequestHandle hRequest, pBool pbWasTimedOut) override;

	~_SteamHTTP_() = default;

} SteamHTTP, *pSteamHTTP;

#endif // !_STEAMHTTP_
