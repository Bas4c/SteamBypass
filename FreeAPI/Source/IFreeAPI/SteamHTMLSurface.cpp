// -----------------------------------------------------------------------------
#include "SteamHTMLSurface.h"
// -----------------------------------------------------------------------------

Bool _SteamHTMLSurface_::Init() {

	return True;

}

Bool _SteamHTMLSurface_::Shutdown() {

	return True;

}

SteamAPICall_t _SteamHTMLSurface_::CreateBrowser(pCStrA pchUserAgent, pCStrA pchUserCSS) {

	return k_SteamAPICall_Invalid;

}

void _SteamHTMLSurface_::RemoveBrowser(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::LoadURL(HTMLBrowser hHTMLBrowser, pCStrA pchURL, pCStrA pchPostData) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetSize(HTMLBrowser hHTMLBrowser, Uint32 Cx, Uint32 Cy) {

	/* Empty Method */

}

void _SteamHTMLSurface_::StopLoad(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::Reload(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::GoBack(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::GoForward(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::AddHeader(HTMLBrowser hHTMLBrowser, pCStrA pchKey, pCStrA pchValue) {

	/* Empty Method */

}

void _SteamHTMLSurface_::ExecuteJavascript(HTMLBrowser hHTMLBrowser, pCStrA pchScript) {

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseUp(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseDown(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseDoubleClick(HTMLBrowser hHTMLBrowser, EHTMLMouseButton eMouseButton) {

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseMove(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) {

	/* Empty Method */

}

void _SteamHTMLSurface_::MouseWheel(HTMLBrowser hHTMLBrowser, Int32 delta) {

	/* Empty Method */

}


void _SteamHTMLSurface_::KeyDown(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) {

	/* Empty Method */

}

void _SteamHTMLSurface_::KeyDown(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers, Bool bIsSystemKey) {

	/* Empty Method */

}

void _SteamHTMLSurface_::KeyUp(HTMLBrowser hHTMLBrowser, Uint32 KeyCode, EHTMLKeyModifiers eHTMLKeyModifiers) {

	/* Empty Method */

}

void _SteamHTMLSurface_::KeyChar(HTMLBrowser hHTMLBrowser, Uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetHorizontalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetVerticalScroll(HTMLBrowser hHTMLBrowser, Uint32 nAbsolutePixelScroll) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetKeyFocus(HTMLBrowser hHTMLBrowser, Bool bHasKeyFocus) {

	/* Empty Method */

}

void _SteamHTMLSurface_::ViewSource(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::CopyToClipboard(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::PasteFromClipboard(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::Find(HTMLBrowser hHTMLBrowser, pCStrA pchSearchStr, Bool bCurrentlyInFind, Bool bReverse) {

	/* Empty Method */

}

void _SteamHTMLSurface_::StopFind(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::GetLinkAtPosition(HTMLBrowser hHTMLBrowser, Int32 x, Int32 y) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetCookie(pCStrA pchHostname, pCStrA pchKey, pCStrA pchValue, pCStrA pchPath, RTime32 nExpires, Bool bSecure, Bool bHTTPOnly) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetPageScaleFactor(HTMLBrowser hHTMLBrowser, Float Zoom, Int32 nPointX, Int32 nPointY) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetBackgroundMode(HTMLBrowser hHTMLBrowser, Bool bBackgroundMode) {

	/* Empty Method */

}

void _SteamHTMLSurface_::SetDPIScalingFactor(HTMLBrowser hHTMLBrowser, Float DPIScaling) {

	/* Empty Method */

}

void _SteamHTMLSurface_::OpenDeveloperTools(HTMLBrowser hHTMLBrowser) {

	/* Empty Method */

}

void _SteamHTMLSurface_::AllowStartRequest(HTMLBrowser hHTMLBrowser, Bool bAllowed) {

	/* Empty Method */

}

void _SteamHTMLSurface_::JSDialogResponse(HTMLBrowser hHTMLBrowser, Bool bResult) {

	/* Empty Method */

}

void _SteamHTMLSurface_::FileLoadDialogResponse(HTMLBrowser hHTMLBrowser, pCStrA *pchSelectedFiles) {

	/* Empty Method */

}
