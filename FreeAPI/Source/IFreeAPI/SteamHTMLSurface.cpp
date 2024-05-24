// -----------------------------------------------------------------------------
#include "SteamHTMLSurface.h"
// -----------------------------------------------------------------------------

Bool _SteamHTMLSurface_::Init() {
	DEBUGBREAK("ISteamHTMLSurface::Init");

	return True;

}

Bool _SteamHTMLSurface_::Shutdown() {
	DEBUGBREAK("ISteamHTMLSurface::Shutdown");

	return True;

}

SteamAPICall_t _SteamHTMLSurface_::CreateBrowser(pCStrA pchUserAgent, pCStrA pchUserCSS) {
	DEBUGBREAK("ISteamHTMLSurface::CreateBrowser");

	return k_SteamAPICall_Invalid;

}

void _SteamHTMLSurface_::RemoveBrowser(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::RemoveBrowser");

	/* Empty Method */

}

void _SteamHTMLSurface_::LoadURL(HTMLBrowser hHTMLBrowser, pCStrA pchURL, pCStrA pchPostData) {
	DEBUGBREAK("ISteamHTMLSurface::LoadURL");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetSize(HTMLBrowser hHTMLBrowser, Uint32 Cx, Uint32 Cy) {
	DEBUGBREAK("ISteamHTMLSurface::SetSize");

	/* Empty Method */

}

void _SteamHTMLSurface_::StopLoad(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::StopLoad");

	/* Empty Method */

}

void _SteamHTMLSurface_::Reload(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::Reload");

	/* Empty Method */

}

void _SteamHTMLSurface_::GoBack(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::GoBack");

	/* Empty Method */

}

void _SteamHTMLSurface_::GoForward(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::GoForward");

	/* Empty Method */

}

void _SteamHTMLSurface_::AddHeader(HTMLBrowser hHTMLBrowser, pCStrA pchKey, pCStrA pchValue) {
	DEBUGBREAK("ISteamHTMLSurface::AddHeader");

	/* Empty Method */

}

void _SteamHTMLSurface_::ExecuteJavascript(HTMLBrowser hHTMLBrowser, pCStrA pchScript) {
	DEBUGBREAK("ISteamHTMLSurface::ExecuteJavascript");

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseUp(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {
	DEBUGBREAK("ISteamHTMLSurface::MouseUp");

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseDown(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {
	DEBUGBREAK("ISteamHTMLSurface::MouseDown");

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseDoubleClick(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {
	DEBUGBREAK("ISteamHTMLSurface::MouseDoubleClick");

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseMove(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) {
	DEBUGBREAK("ISteamHTMLSurface::MouseMove");

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseWheel(HTMLBrowser hHTMLBrowser, Int32 delta) {
	DEBUGBREAK("ISteamHTMLSurface::MouseWheel");

	/* Empty Method */

}


void _SteamHTMLSurface_::KeyDown(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) {
	DEBUGBREAK("ISteamHTMLSurface::KeyDown");

	/* Empty Method */

}

void _SteamHTMLSurface_::KeyDown(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers, Bool bIsSystemKey) {
	DEBUGBREAK("ISteamHTMLSurface::KeyDown");

	/* Empty Method */

}

void _SteamHTMLSurface_::KeyUp(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) {
	DEBUGBREAK("ISteamHTMLSurface::KeyUp");

	/* Empty Method */

}

void _SteamHTMLSurface_::KeyChar(HTMLBrowser hHTMLBrowser, Uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers) {
	DEBUGBREAK("ISteamHTMLSurface::KeyChar");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetHorizontalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) {
	DEBUGBREAK("ISteamHTMLSurface::SetHorizontalScroll");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetVerticalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) {
	DEBUGBREAK("ISteamHTMLSurface::SetVerticalScroll");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetKeyFocus(HTMLBrowser hHTMLBrowser, Bool bHasKeyFocus) {
	DEBUGBREAK("ISteamHTMLSurface::SetKeyFocus");

	/* Empty Method */

}

void _SteamHTMLSurface_::ViewSource(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::ViewSource");

	/* Empty Method */

}

void _SteamHTMLSurface_::CopyToClipboard(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::CopyToClipboard");

	/* Empty Method */

}

void _SteamHTMLSurface_::PasteFromClipboard(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::PasteFromClipboard");

	/* Empty Method */

}

void _SteamHTMLSurface_::Find(HTMLBrowser hHTMLBrowser, pCStrA pchSearchStr, Bool bCurrentlyInFind, Bool bReverse) {
	DEBUGBREAK("ISteamHTMLSurface::Find");

	/* Empty Method */

}

void _SteamHTMLSurface_::StopFind(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::StopFind");

	/* Empty Method */

}

void _SteamHTMLSurface_::GetLinkAtPosition(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) {
	DEBUGBREAK("ISteamHTMLSurface::GetLinkAtPosition");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetCookie(pCStrA pchHostname, pCStrA pchKey, pCStrA pchValue, pCStrA pchPath, RTime32 nExpires, Bool bSecure, Bool bHTTPOnly) {
	DEBUGBREAK("ISteamHTMLSurface::SetCookie");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetPageScaleFactor(HTMLBrowser hHTMLBrowser, Float Zoom, Int32 nPointX, Int32 nPointY) {
	DEBUGBREAK("ISteamHTMLSurface::SetPageScaleFactor");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetBackgroundMode(HTMLBrowser hHTMLBrowser, Bool bBackgroundMode) {
	DEBUGBREAK("ISteamHTMLSurface::SetBackgroundMode");

	/* Empty Method */

}

void _SteamHTMLSurface_::SetDPIScalingFactor(HTMLBrowser hHTMLBrowser, Float DPIScaling) {
	DEBUGBREAK("ISteamHTMLSurface::SetDPIScalingFactor");

	/* Empty Method */

}

void _SteamHTMLSurface_::OpenDeveloperTools(HTMLBrowser hHTMLBrowser) {
	DEBUGBREAK("ISteamHTMLSurface::OpenDeveloperTools");

	/* Empty Method */

}

void _SteamHTMLSurface_::AllowStartRequest(HTMLBrowser hHTMLBrowser, Bool bAllowed) {
	DEBUGBREAK("ISteamHTMLSurface::AllowStartRequest");

	/* Empty Method */

}

void _SteamHTMLSurface_::JSDialogResponse(HTMLBrowser hHTMLBrowser, Bool bResult) {
	DEBUGBREAK("ISteamHTMLSurface::JSDialogResponse");

	/* Empty Method */

}

void _SteamHTMLSurface_::FileLoadDialogResponse(HTMLBrowser hHTMLBrowser, pCStrA *pchSelectedFiles) {
	DEBUGBREAK("ISteamHTMLSurface::FileLoadDialogResponse");

	/* Empty Method */

}
