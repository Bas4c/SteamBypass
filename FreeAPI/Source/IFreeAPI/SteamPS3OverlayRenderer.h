#ifndef _STEAMPS3OVERLAYRENDERER_
#define _STEAMPS3OVERLAYRENDERER_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\CommonX.h"
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamPS3OverlayRenderer.h"
// -----------------------------------------------------------------------------

typedef class _SteamPS3OverlayRender_ : public _ISteamPS3OverlayRender_ {
public:

	_SteamPS3OverlayRender_() = default;
	_SteamPS3OverlayRender_(const _SteamPS3OverlayRender_&) = delete;
	_SteamPS3OverlayRender_& operator=(const _SteamPS3OverlayRender_&) = delete;

	Bool BHostInitialize(Uint32 nScreenWidth, Uint32 nScreenHeight, Uint32 nRefreshRate, IpSteamPS3OverlayRenderHost pRenderHost, pVoid pCellFontLibrary) override;
	void Render() override;
	Bool BHandleCellPadData(const pVoid pCellPadData) override;
	Bool BResetInputState() override;

	~_SteamPS3OverlayRender_() = default;

} SteamPS3OverlayRender, *pSteamPS3OverlayRender;

#endif // !_STEAMPS3OVERLAYRENDERER_
