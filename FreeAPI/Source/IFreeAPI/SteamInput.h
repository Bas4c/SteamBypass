#ifndef _STEAMINPUT_
#define _STEAMINPUT_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamInput.h"
// -----------------------------------------------------------------------------

typedef class _SteamInput_ : public _ISteamInput001_,
 public _ISteamInput002_, public _ISteamInput005_,
 public _ISteamInput_ {
public:

	_SteamInput_() = default;
	_SteamInput_(const _SteamInput_&) = delete;
	_SteamInput_& operator=(const _SteamInput_&) = delete;

	Bool Init(Bool bExplicitlyCallRunFrame) override;
	Bool Shutdown() override;
	Bool SetInputActionManifestFilePath(const pStrA pchInputActionManifestAbsolutePath) override;

	/* Synchronize API state with the latest Steam Input action data available. This
		is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
		possible latency, you call this directly before reading controller state. */
	void RunFrame(Bool bReservedValue) override;

	Bool BWaitForData(Bool bWaitForever, Uint32 Timeout) override;
	Bool BNewDataAvailable() override;
	Int32 GetConnectedControllers(pInputHandle_t hController) override;

	void EnableDeviceCallbacks() override;
	void EnableActionEventCallbacks(SteamInputActionEventCallback pFunction) override;

	InputActionSetHandle_t GetActionSetHandle(const pStrA pszActionSetName) override;
	void ActivateActionSet(InputHandle_t hController, InputActionSetHandle_t hActionSet) override;
	InputActionSetHandle_t GetCurrentActionSet(InputHandle_t hController) override;

	void ActivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) override;
	void DeactivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) override;
	void DeactivateAllActionSetLayers(InputHandle_t hController) override;
	Int32 GetActiveActionSetLayers(InputHandle_t hController, pInputActionSetHandle_t phController) override;

	InputDigitalActionHandle_t GetDigitalActionHandle(const pStrA pszActionName) override;
	InputDigitalActionData_t GetDigitalActionData(InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) override;
	Int32 GetDigitalActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, pEInputActionOrigin peInputActionOrigin) override;
	const pStrA GetStringForDigitalActionName(InputDigitalActionHandle_t hDigitalAction) override;

	InputAnalogActionHandle_t GetAnalogActionHandle(const pStrA pszActionName) override;
	InputAnalogActionData_t GetAnalogActionData(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) override;
	Int32 GetAnalogActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, pEInputActionOrigin peInputActionOrigin) override;

	const pStrA GetGlyphPNGForActionOrigin(EInputActionOrigin eInputActionOrigin, ESteamInputGlyphSize eSteamInputGlyphSize, Uint32 nFlags) override;
	const pStrA GetGlyphSVGForActionOrigin(EInputActionOrigin eInputActionOrigin, Uint32 nFlags) override;

	const pStrA GetGlyphForActionOrigin_Legacy(EInputActionOrigin eInputActionOrigin) override;
	const pStrA GetStringForActionOrigin(EInputActionOrigin eInputActionOrigin) override;

	const pStrA GetStringForAnalogActionName(InputAnalogActionHandle_t hDigitalAction) override;
	void StopAnalogActionMomentum(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) override;
	InputMotionData_t GetMotionData(InputHandle_t hController) override;

	void TriggerVibration(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) override;
	void TriggerVibrationExtended(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed, Uint16 LeftTriggerSpeed, Uint16 RightTriggerSpeed) override;
	void TriggerSimpleHapticEvent(InputHandle_t hController, EControllerHapticLocation eControllerHapticLocation, Uint8 nIntensity, Uint8 nGainDB, Uint8 nOtherIntensity, Uint8 nOtherGainDB) override;
	void SetLEDColor(InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) override;
	void Legacy_TriggerHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) override;
	void Legacy_TriggerRepeatedHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) override;

	Bool ShowBindingPanel(InputHandle_t hController) override;
	ESteamInputType GetInputTypeForHandle(InputHandle_t hController) override;
	InputHandle_t GetControllerForGamepadIndex(Int32 nIndex) override;
	Int32 GetGamepadIndexForController(InputHandle_t ulhController) override;

	const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) override;
	const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) override;

	EInputActionOrigin GetActionOriginFromXboxOrigin(InputHandle_t hController, EXboxOrigin eXboxOrigin) override;
	/* k_EInputActionOrigin_None */
	EInputActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceXboxOrigin) override;
	Bool GetDeviceBindingRevision(InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) override;
	Uint32 GetRemotePlaySessionID(InputHandle_t hController) override;
	Uint16 GetSessionInputConfigurationSettings() override;
	void SetDualSenseTriggerEffect(InputHandle_t hController, const pScePadTriggerEffect pScePadTriggerEffect) override;

	~_SteamInput_() = default;

} SteamInput, *pSteamInput;

#endif // !_STEAMINPUT_
