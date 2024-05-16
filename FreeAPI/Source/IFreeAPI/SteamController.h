#ifndef _STEAMCONTROLLER_
#define _STEAMCONTROLLER_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamController.h"
// -----------------------------------------------------------------------------

typedef class _SteamController_ : public _ISteamController_ {
public:

	_SteamController_() = default;
	_SteamController_(const _SteamController_&) = delete;
	_SteamController_& operator=(const _SteamController_&) = delete;

	Bool Init() override;
	Bool Shutdown() override;

	/* Synchronize API state with the latest Steam Input action data available. This
		is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
		possible latency, you call this directly before reading controller state. */
	void RunFrame() override;

	/* Returns the number of handles written to phController */
	Int32 GetConnectedControllers(pControllerHandle_t phController) override;
	
	ControllerActionSetHandle_t GetActionSetHandle(const pStrA pchActionSetName) override;
	void ActivateActionSet(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet) override;
	ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t hController) override;
	void ActivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) override;
	void DeactivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) override;
	void DeactivateAllActionSetLayers(ControllerHandle_t hController) override;

	/* Returns the number of handles written to phActionSetLayer */
	Int32 GetActiveActionSetLayers(ControllerHandle_t hController, pControllerActionSetHandle_t phActionSetLayer) override;
	
	ControllerDigitalActionHandle_t GetDigitalActionHandle(const pStrA pchActionName) override;
	ControllerDigitalActionData_t GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) override;
	/* Returns the number of handles written to peControllerActionOrigin */
	Int32 GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) override;

	ControllerAnalogActionHandle_t GetAnalogActionHandle(const pStrA pchActionName) override;
	ControllerAnalogActionData_t GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) override;
	/* Returns the number of handles written to peControllerActionOrigin */
	Int32 GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) override;

	const pStrA GetGlyphForActionOrigin(EControllerActionOrigin eControllerActionOrigin) override;
	const pStrA GetStringForActionOrigin(EControllerActionOrigin eControllerActionOrigin) override;

	void StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) override;
	ControllerMotionData_t GetMotionData(ControllerHandle_t hController) override;

	void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) override;
	void TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) override;
	void TriggerVibration(ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) override;
	void SetLEDColor(ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) override;

	Bool ShowBindingPanel(ControllerHandle_t hController) override;
	ESteamInputType GetInputTypeForHandle(ControllerHandle_t hController) override;

	/* Returns the associated controller handle for the specified emulated gamepad - can be used with the above 2 Functions
		to identify controllers presented to your game over Xinput. Returns 0 if the Xinput index isn't associated with Steam Input */
	ControllerHandle_t GetControllerForGamepadIndex(Int32 iController) override;
	/* Returns the associated gamepad index for the specified controller, if emulating a gamepad or -1 if not associated with an Xinput index */
	Int32 GetGamepadIndexForController(ControllerHandle_t hController) override;

	const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) override;
	const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) override;

	EControllerActionOrigin GetActionOriginFromXboxOrigin_(ControllerHandle_t hController, EXboxOrigin eXboxOrigin) override;
	EControllerActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin) override;

	Bool GetControllerBindingRevision(ControllerHandle_t hController, pInt32 pMajor, pInt32 pMinor) override;

	~_SteamController_() = default;

} SteamController, *pSteamController;

#endif // !_STEAMCONTROLLER_
