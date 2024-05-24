#ifndef _ISTEAMPS3OVERLAYRENDERER_
#define _ISTEAMPS3OVERLAYRENDERER_

#include "..\..\FreeAPI.Typedef.h"

typedef enum _EOverlayGradientDirection_ {

	k_EOverlayGradientHorizontal = 1,
	k_EOverlayGradientVertical,
	k_EOverlayGradientNone,

} EOverlayGradientDirection, *pEOverlayGradientDirection;

// -----------------------------------------------------------------------------
// Purpose: Calbback Interface the game must expose to Steam for rendering
// -----------------------------------------------------------------------------
typedef class _ISteamPS3OverlayRenderHost_ {
public:

	virtual void DrawTexturedRect(Int32 x0, Int32 y0, Int32 x1, Int32 y1, Float u0, Float v0, Float u1, Float v1, Int32 iTextureID, Dword colorStart, Dword colorEnd, EOverlayGradientDirection eOverlayGradientDirection) = 0;
	virtual void LoadOrUpdateTexture(Int32 iTextureId, Bool bIsFullTexture, Int32 x0, Int32 y0, Uint32 Cx, Uint32 Cy, Int32 cbBytes, /* [out] */ pByte pbData) = 0;
	virtual void DeleteTexture(Int32 iTextureId) = 0;
	virtual void DeleteAllTextures() = 0;

} ISteamPS3OverlayRenderHost, *IpSteamPS3OverlayRenderHost;

// -----------------------------------------------------------------------------
// Purpose: Interface Steam exposes for the game to tell it when to render
// -----------------------------------------------------------------------------
typedef class _ISteamPS3OverlayRender_ {
public:

	virtual Bool BHostInitialize(Uint32 nScreenWidth, Uint32 nScreenHeight, Uint32 nRefreshRate, IpSteamPS3OverlayRenderHost pRenderHost, pVoid pCellFontLibrary) = 0;
	virtual void Render() = 0;
	virtual Bool BHandleCellPadData(const pVoid pCellPadData) = 0;
	virtual Bool BResetInputState() = 0;

} ISteamPS3OverlayRender, *IpSteamPS3OverlayRender;

#endif // _ISTEAMPS3OVERLAYRENDERER_
