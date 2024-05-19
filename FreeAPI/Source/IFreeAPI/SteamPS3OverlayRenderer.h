#ifndef _STEAMPS3OVERLAYRENDERER_
#define _STEAMPS3OVERLAYRENDERER_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamPS3OverlayRenderer.h"
// -----------------------------------------------------------------------------

typedef class _SteamPS3OverlayRenderer_ : public _ISteamPS3OverlayRenderer_ {
public:

	_SteamPS3OverlayRenderer_() = default;
	_SteamPS3OverlayRenderer_(const _SteamPS3OverlayRenderer_&) = delete;
	_SteamPS3OverlayRenderer_& operator=(const _SteamPS3OverlayRenderer_&) = delete;

	Bool BHostInitialize(Uint32 nScreenWidth, Uint32 nScreenHeight, Uint32 nRefreshRate, IpSteamPS3OverlayRenderHost pRenderHost, pVoid pCellFontLibrary) override;
	void Render() override;
	Bool BHandleCellPadData(const pVoid pCellPadData) override;
	Bool BResetInputState() override;

	~_SteamPS3OverlayRenderer_() = default;

} SteamPS3OverlayRenderer, *pSteamPS3OverlayRenderer;

#endif // !_STEAMPS3OVERLAYRENDERER_
