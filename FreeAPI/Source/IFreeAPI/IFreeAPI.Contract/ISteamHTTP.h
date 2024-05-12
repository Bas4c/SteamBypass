#ifndef _ISTEAMHTTP_
#define _ISTEAMHTTP_

#include "..\..\FreeAPI.Typedef.h"

typedef Uint32 HTTPRequestHandle, *pHTTPRequestHandle;
#define k_HTTPRequestHandle_Invalid ((HTTPRequestHandle)(0x00000000))

typedef Uint32 HTTPCookieContainerHandle, *pHTTPCookieContainerHandle;
#define k_HTTPCookieContainerHandle_Invalid ((HTTPRequestHandle)(0x00000000))

// -----------------------------------------------------------------------------
// Purpose: Interface to HTTP client
// -----------------------------------------------------------------------------
typedef class _ISteamHTTP_ {
public:

	virtual HTTPRequestHandle CreateHTTPRequest(EHTTPMethod eHTTPRequestMethod, const pStrA pchAbsoluteURL) = 0;

	/* Set a context value for the request, which will be returned in the HTTPRequestCompleted_t callback after
	    sending the request. This is just so the caller can easily keep track of which callbacks go with which request data. */
	virtual Bool SetHTTPRequestContextValue(HTTPRequestHandle hRequest, Uint64 ContextValue) = 0;

	/* Set timeout in seconds for the HTTP request, must be called prior to sending the request.  Default
	    timeout is 60 seconds if you don't call this. Returns False if the handle is invalid, or the request
	    has already been sent. */
	virtual Bool SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, Uint32 nTimeoutSeconds) = 0;
	virtual Bool SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, const pStrA pchHeaderName, const pStrA pchHeaderValue) = 0;
	virtual Bool SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, const pStrA pchParamName, const pStrA pchParamValue) = 0;
	virtual Bool SendHTTPRequest(HTTPRequestHandle hRequest, pSteamAPICall_t hCall) = 0;

	/* Sends the HTTP request, will return False on a bad handle, otherwise use SteamCallHandle to wait on
	    asynchronous response via callback for completion, and listen for HTTPRequestHeadersReceived_t and 
	    HTTPRequestDataReceived_t callbacks while streaming. */
	virtual Bool SendHTTPRequestAndStreamResponse(HTTPRequestHandle hRequest, /* [out] */ pSteamAPICall_t hCall) = 0;
	
	virtual Bool DeferHTTPRequest(HTTPRequestHandle hRequest) = 0;
	virtual Bool PrioritizeHTTPRequest(HTTPRequestHandle hRequest) = 0;

	virtual Bool GetHTTPResponseHeaderSize(HTTPRequestHandle hRequest, const pStrA pchHeaderName, /* [out] */ pUint32 pnResponseHeaderSize) = 0;
	virtual Bool GetHTTPResponseHeaderValue(HTTPRequestHandle hRequest, const pStrA pchHeaderName, /* [out] */ pUint8 pnHeaderValue, Uint32 nHeaderValue) = 0;

	virtual Bool GetHTTPResponseBodySize(HTTPRequestHandle hRequest, /* [out] */ pUint32 pnBodySize) = 0;
	virtual Bool GetHTTPResponseBodyData(HTTPRequestHandle hRequest, pUint8 pnBodyData, Uint32 nBodyData) = 0;

	virtual Bool GetHTTPStreamingResponseBodyData(HTTPRequestHandle hRequest, Uint32 cOffset, pUint8 pnBodyData, Uint32 nBodyData) = 0;

	virtual Bool ReleaseHTTPRequest(HTTPRequestHandle hRequest) = 0;
	virtual Bool GetHTTPDownloadProgressPct(HTTPRequestHandle hRequest, /* [out] */ pFloat pPercent) = 0;
	virtual Bool SetHTTPRequestRawPostBody(HTTPRequestHandle hRequest, const pStrA pchContentType, pUint8 pbBody, Uint32 cbBody) = 0;

	/* Creates a cookie container handle which you must later free with ReleaseCookieContainer(). If bAllowResponsesToModify=true
	    than any response to your requests using this cookie container may add new cookies which may be transmitted with
	    future requests. If bAllowResponsesToModify=False than only cookies you explicitly set will be sent. This API is just for
	    during process lifetime, after steam restarts no cookies are persisted and you have no way to access the cookie container across
	    repeat executions of your process. */
	virtual HTTPCookieContainerHandle CreateCookieContainer(Bool bAllowResponsesToModify) = 0;
	virtual Bool ReleaseCookieContainer(HTTPCookieContainerHandle hCookieContainer) = 0;
	virtual Bool SetCookie(HTTPCookieContainerHandle hCookieContainer, const pStrA pchHost, const pStrA pchUrl, const pStrA pchCookie) = 0;
	virtual Bool SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer) = 0;
	
	virtual Bool SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, const pStrA pchUserAgentInfo) = 0;
	virtual Bool SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, Bool bRequireVerifiedCertificate) = 0;

	virtual Bool SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, Uint32 nMilliseconds) = 0;
	virtual Bool GetHTTPRequestWasTimedOut(HTTPRequestHandle hRequest, /* [out] */ pBool pbWasTimedOut) = 0;

} ISteamHTTP, *IpSteamHTTP;

#define STEAMHTTP_INTERFACE_VERSION "STEAMHTTP_INTERFACE_VERSION003"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_HTTPRequestCompleted_t ((Int32)(k_iSteamHTTPCallbacks + 1))
typedef struct _HTTPRequestCompleted_t_ {

	HTTPRequestHandle hRequest;
	Uint64 ContextValue;
	Bool bRequestSuccessful;
	EHTTPStatusCode eHTTPStatusCode;
	Uint32 nBodySize;

} HTTPRequestCompleted_t, *pHTTPRequestCompleted_t;

#define k_iCallbback_HTTPRequestHeadersReceived_t ((Int32)(k_iSteamHTTPCallbacks + 2))
typedef struct _HTTPRequestHeadersReceived_t_ {

	HTTPRequestHandle hRequest;
	Uint64 ContextValue;

} HTTPRequestHeadersReceived_t, *pHTTPRequestHeadersReceived_t;

#define k_iCallbback_HTTPRequestDataReceived_t ((Int32)(k_iSteamHTTPCallbacks + 3))
typedef struct _HTTPRequestDataReceived_t_ {

	HTTPRequestHandle hRequest;
	Uint64 ContextValue;
	Uint32 cOffset;
	Uint32 cBytesReceived;

} HTTPRequestDataReceived_t, *pHTTPRequestDataReceived_t;

#pragma pack(pop)

#endif // _ISTEAMHTTP_
