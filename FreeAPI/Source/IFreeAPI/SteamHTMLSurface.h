#ifndef _STEAMHTMLSURFACE_
#define _STEAMHTMLSURFACE_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamHTMLSurface.h"
// -----------------------------------------------------------------------------

typedef class _SteamHTMLSurface_ : public _ISteamHTMLSurface_ {
public:

	_SteamHTMLSurface_() = default;
	_SteamHTMLSurface_(const _SteamHTMLSurface_&) = delete;
	_SteamHTMLSurface_& operator=(const _SteamHTMLSurface_&) = delete;

	Bool Init() override;
	Bool Shutdown() override;
	SteamAPICall_t CreateBrowser(const pStrA pchUserAgent, const pStrA pchUserCSS) override;
	void RemoveBrowser(HTMLBrowser hHTMLBrowser) override;
	void LoadURL(HTMLBrowser hHTMLBrowser, const pStrA pchURL, const pStrA pchPostData) override;
	void SetSize(HTMLBrowser hHTMLBrowser, Uint32 Cx, Uint32 Cy) override;
	void StopLoad(HTMLBrowser hHTMLBrowser) override;
	void Reload(HTMLBrowser hHTMLBrowser) override;
	void GoBack(HTMLBrowser hHTMLBrowser) override;
	void GoForward(HTMLBrowser hHTMLBrowser) override;
	void AddHeader(HTMLBrowser hHTMLBrowser, const pStrA pchKey, const pStrA pchValue) override;
	void ExecuteJavascript(HTMLBrowser hHTMLBrowser, const pStrA pchScript) override;
	void MouseUp(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) override;
	void MouseDown(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) override;
	void MouseDoubleClick(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) override;
	void MouseMove(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) override;
	void MouseWheel(HTMLBrowser hHTMLBrowser, Int32 delta) override;
	void KeyDown(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers, Bool bIsSystemKey) override;
	void KeyUp(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) override;
	void KeyChar(HTMLBrowser hHTMLBrowser, Uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers) override;
	void SetHorizontalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) override;
	void SetVerticalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) override;
	void SetKeyFocus(HTMLBrowser hHTMLBrowser, Bool bHasKeyFocus) override;
	void ViewSource(HTMLBrowser hHTMLBrowser) override;
	void CopyToClipboard(HTMLBrowser hHTMLBrowser) override;
	void PasteFromClipboard(HTMLBrowser hHTMLBrowser) override;
	void Find(HTMLBrowser hHTMLBrowser, const pStrA pchSearchStr, Bool bCurrentlyInFind, Bool bReverse) override;
	void StopFind(HTMLBrowser hHTMLBrowser) override;
	void GetLinkAtPosition(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) override;
	void SetCookie(const pStrA pchHostname, const pStrA pchKey, const pStrA pchValue, const pStrA pchPath, RTime32 nExpires, Bool bSecure, Bool bHTTPOnly) override;
	void SetPageScaleFactor(HTMLBrowser hHTMLBrowser, Float Zoom, Int32 nPointX, Int32 nPointY) override;
	void SetBackgroundMode(HTMLBrowser hHTMLBrowser, Bool bBackgroundMode) override;
	void SetDPIScalingFactor(HTMLBrowser hHTMLBrowser, Float DPIScaling) override;
	void OpenDeveloperTools(HTMLBrowser hHTMLBrowser) override;
	void AllowStartRequest(HTMLBrowser hHTMLBrowser, Bool bAllowed) override;
	void JSDialogResponse(HTMLBrowser hHTMLBrowser, Bool bResult) override;
	void FileLoadDialogResponse(HTMLBrowser hHTMLBrowser, const pStrA *pchSelectedFiles) override;

	~_SteamHTMLSurface_() override = default;

} SteamHTMLSurfacem, *pSteamHTMLSurface;

#endif // !_STEAMHTMLSURFACE_