#ifndef _ISTEAMHTMLSURFACE_
#define _ISTEAMHTMLSURFACE_

#include "..\..\FreeAPI.Typedef.h"

typedef Uint32 HTMLBrowser, *pHTMLBrowser;
#define k_HTMLBrowser_Invalid ((HTMLBrowser)(0x00000000))

typedef enum _EHTMLMouseButton_ {

	k_EHTMLMouseButton_Left,
	k_EHTMLMouseButton_Right,
	k_EHTMLMouseButton_Middle

} EHTMLMouseButton, *pEHTMLMouseButton;

typedef enum _EMouseCursor_ {

	K_EMouseCursor_DC_user,
	K_EMouseCursor_DC_none,
	K_EMouseCursor_DC_arrow,
	K_EMouseCursor_DC_ibeam,
	K_EMouseCursor_DC_hourglass,
	K_EMouseCursor_DC_waitarrow,
	K_EMouseCursor_DC_crosshair,
	K_EMouseCursor_DC_up,
	K_EMouseCursor_DC_sizenw,
	K_EMouseCursor_DC_sizese,
	K_EMouseCursor_DC_sizene,
	K_EMouseCursor_DC_sizesw,
	K_EMouseCursor_DC_sizew,
	K_EMouseCursor_DC_sizee,
	K_EMouseCursor_DC_sizen,
	K_EMouseCursor_DC_sizes,
	K_EMouseCursor_DC_sizewe,
	K_EMouseCursor_DC_sizens,
	K_EMouseCursor_DC_sizeall,
	K_EMouseCursor_DC_no,
	K_EMouseCursor_DC_hand,
	K_EMouseCursor_DC_blank,
	K_EMouseCursor_DC_middle_pan,
	K_EMouseCursor_DC_north_pan,
	K_EMouseCursor_DC_north_east_pan,
	K_EMouseCursor_DC_east_pan,
	K_EMouseCursor_DC_south_east_pan,
	K_EMouseCursor_DC_south_pan,
	K_EMouseCursor_DC_south_west_pan,
	K_EMouseCursor_DC_west_pan,
	K_EMouseCursor_DC_north_west_pan,
	K_EMouseCursor_DC_alias,
	K_EMouseCursor_DC_cell,
	K_EMouseCursor_DC_colresize,
	K_EMouseCursor_DC_copycur,
	K_EMouseCursor_DC_verticaltext,
	K_EMouseCursor_DC_rowresize,
	K_EMouseCursor_DC_zoomin,
	K_EMouseCursor_DC_zoomout,
	K_EMouseCursor_DC_help,
	K_EMouseCursor_DC_custom,
	K_EMouseCursor_DC_last

} EMouseCursor, *pEMouseCursor;

typedef enum _EHTMLKeyModifiers_ {

	k_EHTMLKeyModifier_None = 0x00000000,
	k_EHTMLKeyModifier_AltDown = 0x00000001,
	k_EHTMLKeyModifier_CtrlDown = 0x00000004,
	k_EHTMLKeyModifier_ShiftDown = 0x00000008,

} EHTMLKeyModifiers, *pEHTMLKeyModifiers;

// -----------------------------------------------------------------------------
// Purpose: Functions to interact with HTML pages
// -----------------------------------------------------------------------------
typedef class _ISteamHTMLSurface_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;
	virtual SteamAPICall_t CreateBrowser(const pStrA pchUserAgent, const pStrA pchUserCSS) = 0;
	virtual void RemoveBrowser(HTMLBrowser hHTMLBrowser) = 0;
	virtual void LoadURL(HTMLBrowser hHTMLBrowser, const pStrA pchURL, const pStrA pchPostData) = 0;
	virtual void SetSize(HTMLBrowser hHTMLBrowser, Uint32 Cx, Uint32 Cy) = 0;
	virtual void StopLoad(HTMLBrowser hHTMLBrowser) = 0;
	virtual void Reload(HTMLBrowser hHTMLBrowser) = 0;
	virtual void GoBack(HTMLBrowser hHTMLBrowser) = 0;
	virtual void GoForward(HTMLBrowser hHTMLBrowser) = 0;
	virtual void AddHeader(HTMLBrowser hHTMLBrowser, const pStrA pchKey, const pStrA pchValue) = 0;
	virtual void ExecuteJavascript(HTMLBrowser hHTMLBrowser, const pStrA pchScript) = 0;
	virtual void MouseUp(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) = 0;
	virtual void MouseDown(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) = 0;
	virtual void MouseDoubleClick(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) = 0;
	virtual void MouseMove(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) = 0;
	virtual void MouseWheel(HTMLBrowser hHTMLBrowser, Int32 delta) = 0;
	virtual void KeyDown(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers, Bool bIsSystemKey) = 0;
	virtual void KeyUp(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) = 0;
	virtual void KeyChar(HTMLBrowser hHTMLBrowser, Uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers) = 0;
	virtual void SetHorizontalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) = 0;
	virtual void SetVerticalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) = 0;
	virtual void SetKeyFocus(HTMLBrowser hHTMLBrowser, Bool bHasKeyFocus) = 0;
	virtual void ViewSource(HTMLBrowser hHTMLBrowser) = 0;
	virtual void CopyToClipboard(HTMLBrowser hHTMLBrowser) = 0;
	virtual void PasteFromClipboard(HTMLBrowser hHTMLBrowser) = 0;
	virtual void Find(HTMLBrowser hHTMLBrowser, const pStrA pchSearchStr, Bool bCurrentlyInFind, Bool bReverse) = 0;
	virtual void StopFind(HTMLBrowser hHTMLBrowser) = 0;
	virtual void GetLinkAtPosition(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) = 0;
	virtual void SetCookie(const pStrA pchHostname, const pStrA pchKey, const pStrA pchValue, const pStrA pchPath, RTime32 nExpires, Bool bSecure, Bool bHTTPOnly) = 0;
	virtual void SetPageScaleFactor(HTMLBrowser hHTMLBrowser, Float Zoom, Int32 nPointX, Int32 nPointY) = 0;
	virtual void SetBackgroundMode(HTMLBrowser hHTMLBrowser, Bool bBackgroundMode) = 0;
	virtual void SetDPIScalingFactor(HTMLBrowser hHTMLBrowser, Float DPIScaling) = 0;
	virtual void OpenDeveloperTools(HTMLBrowser hHTMLBrowser) = 0;
	virtual void AllowStartRequest(HTMLBrowser hHTMLBrowser, Bool bAllowed) = 0;
	virtual void JSDialogResponse(HTMLBrowser hHTMLBrowser, Bool bResult) = 0;
	virtual void FileLoadDialogResponse(HTMLBrowser hHTMLBrowser, const pStrA *pchSelectedFiles) = 0;
	
	virtual ~_ISteamHTMLSurface_() = default;

} ISteamHTMLSurface, *IpSteamHTMLSurface;

#define STEAMHTMLSURFACE_INTERFACE_VERSION "STEAMHTMLSURFACE_INTERFACE_VERSION_005"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_HTML_BrowserReady_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 1))
typedef struct _HTML_BrowserReady_t_ {
	
	HTMLBrowser hHTMLBrowser;

} HTML_BrowserReady_t, *pHTML_BrowserReady_t;

#define k_iCallbback_HTML_NeedsPaint_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 2))
typedef struct _HTML_NeedsPaint_t_ {
	
	HTMLBrowser hHTMLBrowser;
	const pStrA pBGRA;
	Uint32 nWide;
	Uint32 nTall;
	Uint32 nUpdateX;
	Uint32 nUpdateY;
	Uint32 nUpdateWide;
	Uint32 nUpdateTall;
	Uint32 nScrollX;
	Uint32 nScrollY;
	Float PageScale;
	Uint32 nPageSerial;

} HTML_NeedsPaint_t, *pHTML_NeedsPaint_t;

#define k_iCallbback_HTML_StartRequest_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 3))
typedef struct _HTML_StartRequest_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchURL;
	const pStrA pchTarget;
	const pStrA pchPostData;
	Bool bIsRedirect;

} HTML_StartRequest_t, *pHTML_StartRequest_t;

#define k_iCallbback_HTML_CloseBrowser_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 4))
typedef struct _HTML_CloseBrowser_t_ {
	
	HTMLBrowser hHTMLBrowser;

} HTML_CloseBrowser_t, *pHTML_CloseBrowser_t;

#define k_iCallbback_HTML_URLChanged_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 5))
typedef struct _HTML_URLChanged_t_ {
	
	HTMLBrowser hHTMLBrowser;
	const pStrA pchURL;
	const pStrA pchPostData;
	Bool bIsRedirect;
	const pStrA pchPageTitle;
	Bool bNewNavigation;

} HTML_URLChanged_t, *pHTML_URLChanged_t;

#define k_iCallbback_HTML_FinishedRequest_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 6))
typedef struct _HTML_FinishedRequest_t_ {
	
	HTMLBrowser hHTMLBrowser;
	const pStrA pchURL;
	const pStrA pchPageTitle;

} HTML_FinishedRequest_t, *pHTML_FinishedRequest_t;

#define k_iCallbback_HTML_OpenLinkInNewTab_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 7))
typedef struct _HTML_OpenLinkInNewTab_t_ {
	
	HTMLBrowser hHTMLBrowser;
	const pStrA pchURL;

} HTML_OpenLinkInNewTab_t, *pHTML_OpenLinkInNewTab_t;

#define k_iCallbback_HTML_ChangedTitle_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 8))
typedef struct _HTML_ChangedTitle_t_ {
	
	HTMLBrowser hHTMLBrowser;
	const pStrA pchTitle;

} HTML_ChangedTitle_t, *pHTML_ChangedTitle_t;

#define k_iCallbback_HTML_SearchResults_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 9))
typedef struct _HTML_SearchResults_t_ {
	
	HTMLBrowser hHTMLBrowser;
	Uint32 nResults;
	Uint32 nCurrentMatch;

} HTML_SearchResults_t, *pHTML_SearchResults_t;

#define k_iCallbback_HTML_CanGoBackAndForward_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 10))
typedef struct _HTML_CanGoBackAndForward_t_ {
	
	HTMLBrowser hHTMLBrowser;
	Bool bCanGoBack;
	Bool bCanGoForward;

} HTML_CanGoBackAndForward_t, *pHTML_CanGoBackAndForward_t;

#define k_iCallbback_HTML_HorizontalScroll_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 11))
typedef struct _HTML_HorizontalScroll_t_ {
	
	HTMLBrowser hHTMLBrowser;
	Uint32 nScrollMax;
	Uint32 nScrollCurrent;
	Float PageScale;
	Bool bVisible;
	Uint32 nPageSize;

} HTML_HorizontalScroll_t, *pHTML_HorizontalScroll_t;

#define k_iCallbback_HTML_VerticalScroll_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 12))
typedef struct _HTML_VerticalScroll_t_ {

	HTMLBrowser hHTMLBrowser;
	Uint32 nScrollMax;
	Uint32 nScrollCurrent;
	Float PageScale;
	Bool bVisible;
	Uint32 nPageSize;

} HTML_VerticalScroll_t, *pHTML_VerticalScroll_t;

#define k_iCallbback_HTML_LinkAtPosition_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 13))
typedef struct _HTML_LinkAtPosition_t_ {

	HTMLBrowser hHTMLBrowser;
	Uint32 x;
	Uint32 y;
	const pStrA pchURL;
	Bool bInput;
	Bool bLiveLink;

} HTML_LinkAtPosition_t, *pHTML_LinkAtPosition_t;

#define k_iCallbback_HTML_JSAlert_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 14))
typedef struct _HTML_JSAlert_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchMessage;

} HTML_JSAlert_t, *pHTML_JSAlert_t;

#define k_iCallbback_HTML_JSConfirm_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 15))
typedef struct _HTML_JSConfirm_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchMessage;

} HTML_JSConfirt, *pHTML_JSConfirm_t;

#define k_iCallbback_HTML_FileOpenDialog_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 16))
typedef struct _HTML_FileOpenDialog_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchTitle;
	const pStrA pchInitialFile;

} HTML_FileOpenDialog_t, *pHTML_FileOpenDialog_t;

#define k_iCallbback_HTML_NewWindow_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 21))
typedef struct _HTML_NewWindow_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchURL;
	Uint32 nX;
	Uint32 nY;
	Uint32 nWide;
	Uint32 nTall;
	HTMLBrowser nNewWindow_BrowserHandle_IGNORE;

} HTML_NewWindow_t, *pHTML_NewWindow_t;

#define k_iCallbback_HTML_SetCursor_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 22))
typedef struct _HTML_SetCursor_t_ {

	HTMLBrowser hHTMLBrowser;
	Uint32 eMouseCursor;

} HTML_SetCursor_t, *pHTML_SetCursor_t;

#define k_iCallbback_HTML_StatusText_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 23))
typedef struct _HTML_StatusText_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchMsg;

} HTML_StatusText_t, *pHTML_StatusText_t;

#define k_iCallbback_HTML_ShowToolTip_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 24))
typedef struct _HTML_ShowToolTip_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchMsg;

} HTML_ShowToolTip_t, *pHTML_ShowToolTip_t;

#define k_iCallbback_HTML_UpdateToolTip_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 25))
typedef struct _HTML_UpdateToolTip_t_ {

	HTMLBrowser hHTMLBrowser;
	const pStrA pchMsg;

} HTML_UpdateToolTip_t, *pHTML_UpdateToolTip_t;

#define k_iCallbback_HTML_HideToolTip_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 26))
typedef struct _HTML_HideToolTip_t_ {

	HTMLBrowser hHTMLBrowser;

} HTML_HideToolTip_t, *pHTML_HideToolTip_t;

#define k_iCallbback_HTML_BrowserRestarted_t ((Int32)(k_iSteamHTMLSurfaceCallbacks + 27))
typedef struct _HTML_BrowserRestarted_t_ {

	HTMLBrowser hHTMLBrowser;
	HTMLBrowser hHTMLBrowsernOld;

} HTML_BrowserRestarted_t, *pHTML_BrowserRestarted_t;

#pragma pack(pop)

#endif // _ISTEAMHTMLSURFACE_
