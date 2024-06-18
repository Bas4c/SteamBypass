// -----------------------------------------------------------------------------
#include "SteamInput.h"
// -----------------------------------------------------------------------------

Bool _SteamInput_::Init(Bool bExplicitlyCallRunFrame) {
	DEBUGBREAK("ISteamInput::Init");

	return True;

}

Bool _SteamInput_::Shutdown() {
	DEBUGBREAK("ISteamInput::Shutdown");

	return True;

}

Bool _SteamInput_::SetInputActionManifestFilePath(pCStrA pchInputActionManifestAbsolutePath) {
	DEBUGBREAK("ISteamInput::SetInputActionManifestFilePath");

	return True;

}

void _SteamInput_::RunFrame(Bool bReservedValue) {
	DEBUGBREAK("ISteamInput::RunFrame");

	/* Empty Method */

}

Bool _SteamInput_::BWaitForData(Bool bWaitForever, Uint32 Timeout) {
	DEBUGBREAK("ISteamInput::BWaitForData");

	return False;

}

Bool _SteamInput_::BNewDataAvailable() {
	DEBUGBREAK("ISteamInput::BNewDataAvailable");

	return False;

}

Int32 _SteamInput_::GetConnectedControllers(pInputHandle_t hController) {
	DEBUGBREAK("ISteamInput::GetConnectedControllers");

	return 0;

}

void _SteamInput_::EnableDeviceCallbacks() {
	DEBUGBREAK("ISteamInput::EnableDeviceCallbacks");

	/* Empty Method */

}

void _SteamInput_::EnableActionEventCallbacks(SteamInputActionEventCallback pFunction) {
	DEBUGBREAK("ISteamInput::EnableActionEventCallbacks");

	/* Empty Method */

}

InputActionSetHandle_t _SteamInput_::GetActionSetHandle(pCStrA pchActionSetName) {
	DEBUGBREAK("ISteamInput::GetActionSetHandle");

	return (InputActionSetHandle_t)(0x0000000000000000);

}

void _SteamInput_::ActivateActionSet(InputHandle_t hController, InputActionSetHandle_t hActionSet) {
	DEBUGBREAK("ISteamInput::ActivateActionSet");

	/* Empty Method */

}

InputActionSetHandle_t _SteamInput_::GetCurrentActionSet(InputHandle_t hController) {
	DEBUGBREAK("ISteamInput::GetCurrentActionSet");

	return (InputActionSetHandle_t)(0x0000000000000000);

}

void _SteamInput_::ActivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("ISteamInput::ActivateActionSetLayer");

	/* Empty Method */

}

void _SteamInput_::DeactivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("ISteamInput::DeactivateActionSetLayer");

	/* Empty Method */

}

void _SteamInput_::DeactivateAllActionSetLayers(InputHandle_t hController) {
	DEBUGBREAK("ISteamInput::DeactivateAllActionSetLayers");

	/* Empty Method */

}

Int32 _SteamInput_::GetActiveActionSetLayers(InputHandle_t hController, pInputActionSetHandle_t phController) {
	DEBUGBREAK("ISteamInput::GetActiveActionSetLayers");

	return 0;

}

InputDigitalActionHandle_t _SteamInput_::GetDigitalActionHandle(pCStrA pchActionSetName) {
	DEBUGBREAK("ISteamInput::GetDigitalActionHandle");

	return (InputDigitalActionHandle_t)(0x0000000000000000);

}

InputDigitalActionData_t _SteamInput_::GetDigitalActionData(InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) {
	DEBUGBREAK("ISteamInput::GetDigitalActionData");

	InputDigitalActionData_t inputDigitalActionData{};
	inputDigitalActionData.bActive = False;
	inputDigitalActionData.bState = False;

	return inputDigitalActionData;

}

Int32 _SteamInput_::GetDigitalActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, pEInputActionOrigin peInputActionOrigin) {
	DEBUGBREAK("ISteamInput::GetDigitalActionOrigins");

	return 0;

}

pCStrA _SteamInput_::GetStringForDigitalActionName(InputDigitalActionHandle_t hDigitalAction) {
	DEBUGBREAK("ISteamInput::GetStringForDigitalActionName");

	return (pCStrA)(
		""
	);

}

InputAnalogActionHandle_t _SteamInput_::GetAnalogActionHandle(pCStrA pchActionSetName) {
	DEBUGBREAK("ISteamInput::GetAnalogActionHandle");

	return (InputAnalogActionHandle_t)(0x0000000000000000);

}

InputAnalogActionData_t _SteamInput_::GetAnalogActionData(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("ISteamInput::GetAnalogActionData");

	InputAnalogActionData_t inputAnalogActionData{};
	inputAnalogActionData.bActive = False;
	inputAnalogActionData.eInputSourceMode = k_EInputSourceMode_None;
	inputAnalogActionData.x = 0.0F;
	inputAnalogActionData.y = 0.0F;

	return inputAnalogActionData;

}

Int32 _SteamInput_::GetAnalogActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, pEInputActionOrigin peInputActionOrigin) {
	DEBUGBREAK("ISteamInput::GetAnalogActionOrigins");

	return 0;

}

pCStrA _SteamInput_::GetGlyphPNGForActionOrigin(EInputActionOrigin eInputActionOrigin, ESteamInputGlyphSize eSteamInputGlyphSize, Uint32 nFlags) {
	DEBUGBREAK("ISteamInput::GetGlyphPNGForActionOrigin");

	return (pCStrA)(
		""
	);

}

pCStrA _SteamInput_::GetGlyphSVGForActionOrigin(EInputActionOrigin eInputActionOrigin, Uint32 nFlags) {
	DEBUGBREAK("ISteamInput::GetGlyphSVGForActionOrigin");

	return (pCStrA)(
		""
	);

}

pCStrA _SteamInput_::GetGlyphForActionOrigin_Legacy(EInputActionOrigin eInputActionOrigin) {
	DEBUGBREAK("ISteamInput::GetGlyphForActionOrigin_Legacy");

	switch (eInputActionOrigin) {
		case k_EInputActionOrigin_SteamController_A:
			return (pCStrA)(
				"SteamController_A"
			);
			break;
		case k_EInputActionOrigin_SteamController_B:
			return (pCStrA)(
				"SteamController_B"
			);
			break;
		case k_EInputActionOrigin_SteamController_X:
			return (pCStrA)(
				"SteamController_X"
			);
			break;
		case k_EInputActionOrigin_SteamController_Y:
			return (pCStrA)(
				"SteamController_Y"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftBumper:
			return (pCStrA)(
				"SteamController_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightBumper:
			return (pCStrA)(
				"SteamController_RightBumper"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftGrip:
			return (pCStrA)(
				"SteamController_LeftGrip"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightGrip:
			return (pCStrA)(
				"SteamController_RightGrip"
			);
			break;
		case k_EInputActionOrigin_SteamController_Start:
			return (pCStrA)(
				"SteamController_Start"
			);
			break;
		case k_EInputActionOrigin_SteamController_Back:
			return (pCStrA)(
				"SteamController_Back"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_Touch:
			return (pCStrA)(
				"SteamController_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_Swipe:
			return (pCStrA)(
				"SteamController_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_Click:
			return (pCStrA)(
				"SteamController_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadNorth:
			return (pCStrA)(
				"SteamController_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadSouth:
			return (pCStrA)(
				"SteamController_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadWest:
			return (pCStrA)(
				"SteamController_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadEast:
			return (pCStrA)(
				"SteamController_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_Touch:
			return (pCStrA)(
				"SteamController_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_Swipe:
			return (pCStrA)(
				"SteamController_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_Click:
			return (pCStrA)(
				"SteamController_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadNorth:
			return (pCStrA)(
				"SteamController_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadSouth:
			return (pCStrA)(
				"SteamController_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadWest:
			return (pCStrA)(
				"SteamController_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadEast:
			return (pCStrA)(
				"SteamController_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftTrigger_Pull:
			return (pCStrA)(
				"SteamController_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftTrigger_Click:
			return (pCStrA)(
				"SteamController_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightTrigger_Pull:
			return (pCStrA)(
				"SteamController_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightTrigger_Click:
			return (pCStrA)(
				"SteamController_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_Move:
			return (pCStrA)(
				"SteamController_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_Click:
			return (pCStrA)(
				"SteamController_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadNorth:
			return (pCStrA)(
				"SteamController_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadSouth:
			return (pCStrA)(
				"SteamController_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadWest:
			return (pCStrA)(
				"SteamController_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadEast:
			return (pCStrA)(
				"SteamController_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Move:
			return (pCStrA)(
				"SteamController_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Pitch:
			return (pCStrA)(
				"SteamController_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Yaw:
			return (pCStrA)(
				"SteamController_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Roll:
			return (pCStrA)(
				"SteamController_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved0:
			return (pCStrA)(
				"SteamController_Reserved0"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved1:
			return (pCStrA)(
				"SteamController_Reserved1"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved2:
			return (pCStrA)(
				"SteamController_Reserved2"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved3:
			return (pCStrA)(
				"SteamController_Reserved3"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved4:
			return (pCStrA)(
				"SteamController_Reserved4"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved5:
			return (pCStrA)(
				"SteamController_Reserved5"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved6:
			return (pCStrA)(
				"SteamController_Reserved6"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved7:
			return (pCStrA)(
				"SteamController_Reserved7"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved8:
			return (pCStrA)(
				"SteamController_Reserved8"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved9:
			return (pCStrA)(
				"SteamController_Reserved9"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved10:
			return (pCStrA)(
				"SteamController_Reserved10"
			);
			break;
		case k_EInputActionOrigin_PS4_X:
			return (pCStrA)(
				"PS4_X"
			);
			break;
		case k_EInputActionOrigin_PS4_Circle:
			return (pCStrA)(
				"PS4_Circle"
			);
			break;
		case k_EInputActionOrigin_PS4_Triangle:
			return (pCStrA)(
				"PS4_Triangle"
			);
			break;
		case k_EInputActionOrigin_PS4_Square:
			return (pCStrA)(
				"PS4_Square"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftBumper:
			return (pCStrA)(
				"PS4_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_PS4_RightBumper:
			return (pCStrA)(
				"PS4_RightBumper"
			);
			break;
		case k_EInputActionOrigin_PS4_Options:
			return (pCStrA)(
				"PS4_Options"
			);
			break;
		case k_EInputActionOrigin_PS4_Share:
			return (pCStrA)(
				"PS4_Share"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_Touch:
			return (pCStrA)(
				"PS4_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_Swipe:
			return (pCStrA)(
				"PS4_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_Click:
			return (pCStrA)(
				"PS4_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadNorth:
			return (pCStrA)(
				"PS4_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadSouth:
			return (pCStrA)(
				"PS4_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadWest:
			return (pCStrA)(
				"PS4_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadEast:
			return (pCStrA)(
				"PS4_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_Touch:
			return (pCStrA)(
				"PS4_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_Swipe:
			return (pCStrA)(
				"PS4_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_Click:
			return (pCStrA)(
				"PS4_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadNorth:
			return (pCStrA)(
				"PS4_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadSouth:
			return (pCStrA)(
				"PS4_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadWest:
			return (pCStrA)(
				"PS4_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadEast:
			return (pCStrA)(
				"PS4_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_Touch:
			return (pCStrA)(
				"PS4_CenterPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_Swipe:
			return (pCStrA)(
				"PS4_CenterPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_Click:
			return (pCStrA)(
				"PS4_CenterPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadNorth:
			return (pCStrA)(
				"PS4_CenterPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadSouth:
			return (pCStrA)(
				"PS4_CenterPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadWest:
			return (pCStrA)(
				"PS4_CenterPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadEast:
			return (pCStrA)(
				"PS4_CenterPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftTrigger_Pull:
			return (pCStrA)(
				"PS4_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftTrigger_Click:
			return (pCStrA)(
				"PS4_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_RightTrigger_Pull:
			return (pCStrA)(
				"PS4_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS4_RightTrigger_Click:
			return (pCStrA)(
				"PS4_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_Move:
			return (pCStrA)(
				"PS4_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_Click:
			return (pCStrA)(
				"PS4_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadNorth:
			return (pCStrA)(
				"PS4_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadSouth:
			return (pCStrA)(
				"PS4_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadWest:
			return (pCStrA)(
				"PS4_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadEast:
			return (pCStrA)(
				"PS4_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_Move:
			return (pCStrA)(
				"PS4_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_Click:
			return (pCStrA)(
				"PS4_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadNorth:
			return (pCStrA)(
				"PS4_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadSouth:
			return (pCStrA)(
				"PS4_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadWest:
			return (pCStrA)(
				"PS4_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadEast:
			return (pCStrA)(
				"PS4_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_North:
			return (pCStrA)(
				"PS4_DPad_North"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_South:
			return (pCStrA)(
				"PS4_DPad_South"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_West:
			return (pCStrA)(
				"PS4_DPad_West"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_East:
			return (pCStrA)(
				"PS4_DPad_East"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Move:
			return (pCStrA)(
				"PS4_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Pitch:
			return (pCStrA)(
				"PS4_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Yaw:
			return (pCStrA)(
				"PS4_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Roll:
			return (pCStrA)(
				"PS4_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_Move:
			return (pCStrA)(
				"PS4_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved1:
			return (pCStrA)(
				"PS4_Reserved1"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved2:
			return (pCStrA)(
				"PS4_Reserved2"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved3:
			return (pCStrA)(
				"PS4_Reserved3"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved4:
			return (pCStrA)(
				"PS4_Reserved4"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved5:
			return (pCStrA)(
				"PS4_Reserved5"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved6:
			return (pCStrA)(
				"PS4_Reserved6"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved7:
			return (pCStrA)(
				"PS4_Reserved7"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved8:
			return (pCStrA)(
				"PS4_Reserved8"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved9:
			return (pCStrA)(
				"PS4_Reserved9"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved10:
			return (pCStrA)(
				"PS4_Reserved10"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_A:
			return (pCStrA)(
				"XBoxOne_A"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_B:
			return (pCStrA)(
				"XBoxOne_B"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_X:
			return (pCStrA)(
				"XBoxOne_X"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Y:
			return (pCStrA)(
				"XBoxOne_Y"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftBumper:
			return (pCStrA)(
				"XBoxOne_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightBumper:
			return (pCStrA)(
				"XBoxOne_RightBumper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Menu:
			return (pCStrA)(
				"XBoxOne_Menu"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_View:
			return (pCStrA)(
				"XBoxOne_View"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftTrigger_Pull:
			return (pCStrA)(
				"XBoxOne_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftTrigger_Click:
			return (pCStrA)(
				"XBoxOne_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightTrigger_Pull:
			return (pCStrA)(
				"XBoxOne_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightTrigger_Click:
			return (pCStrA)(
				"XBoxOne_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_Move:
			return (pCStrA)(
				"XBoxOne_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_Click:
			return (pCStrA)(
				"XBoxOne_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadNorth:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadSouth:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadWest:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadEast:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_Move:
			return (pCStrA)(
				"XBoxOne_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_Click:
			return (pCStrA)(
				"XBoxOne_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadNorth:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadSouth:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadWest:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadEast:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_North:
			return (pCStrA)(
				"XBoxOne_DPad_North"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_South:
			return (pCStrA)(
				"XBoxOne_DPad_South"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_West:
			return (pCStrA)(
				"XBoxOne_DPad_West"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_East:
			return (pCStrA)(
				"XBoxOne_DPad_East"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_Move:
			return (pCStrA)(
				"XBoxOne_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftGrip_Lower:
			return (pCStrA)(
				"XBoxOne_LeftGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftGrip_Upper:
			return (pCStrA)(
				"XBoxOne_LeftGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightGrip_Lower:
			return (pCStrA)(
				"XBoxOne_RightGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightGrip_Upper:
			return (pCStrA)(
				"XBoxOne_RightGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Share:
			return (pCStrA)(
				"XBoxOne_Share"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved6:
			return (pCStrA)(
				"XBoxOne_Reserved6"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved7:
			return (pCStrA)(
				"XBoxOne_Reserved7"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved8:
			return (pCStrA)(
				"XBoxOne_Reserved8"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved9:
			return (pCStrA)(
				"XBoxOne_Reserved9"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved10:
			return (pCStrA)(
				"XBoxOne_Reserved10"
			);
			break;
		case k_EInputActionOrigin_XBox360_A:
			return (pCStrA)(
				"XBox360_A"
			);
			break;
		case k_EInputActionOrigin_XBox360_B:
			return (pCStrA)(
				"XBox360_B"
			);
			break;
		case k_EInputActionOrigin_XBox360_X:
			return (pCStrA)(
				"XBox360_X"
			);
			break;
		case k_EInputActionOrigin_XBox360_Y:
			return (pCStrA)(
				"XBox360_Y"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftBumper:
			return (pCStrA)(
				"XBox360_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightBumper:
			return (pCStrA)(
				"XBox360_RightBumper"
			);
			break;
		case k_EInputActionOrigin_XBox360_Start:
			return (pCStrA)(
				"XBox360_Start"
			);
			break;
		case k_EInputActionOrigin_XBox360_Back:
			return (pCStrA)(
				"XBox360_Back"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftTrigger_Pull:
			return (pCStrA)(
				"XBox360_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftTrigger_Click:
			return (pCStrA)(
				"XBox360_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightTrigger_Pull:
			return (pCStrA)(
				"XBox360_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightTrigger_Click:
			return (pCStrA)(
				"XBox360_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_Move:
			return (pCStrA)(
				"XBox360_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_Click:
			return (pCStrA)(
				"XBox360_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadNorth:
			return (pCStrA)(
				"XBox360_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadSouth:
			return (pCStrA)(
				"XBox360_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadWest:
			return (pCStrA)(
				"XBox360_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadEast:
			return (pCStrA)(
				"XBox360_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_Move:
			return (pCStrA)(
				"XBox360_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_Click:
			return (pCStrA)(
				"XBox360_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadNorth:
			return (pCStrA)(
				"XBox360_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadSouth:
			return (pCStrA)(
				"XBox360_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadWest:
			return (pCStrA)(
				"XBox360_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadEast:
			return (pCStrA)(
				"XBox360_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_North:
			return (pCStrA)(
				"XBox360_DPad_North"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_South:
			return (pCStrA)(
				"XBox360_DPad_South"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_West:
			return (pCStrA)(
				"XBox360_DPad_West"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_East:
			return (pCStrA)(
				"XBox360_DPad_East"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_Move:
			return (pCStrA)(
				"XBox360_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved1:
			return (pCStrA)(
				"XBox360_Reserved1"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved2:
			return (pCStrA)(
				"XBox360_Reserved2"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved3:
			return (pCStrA)(
				"XBox360_Reserved3"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved4:
			return (pCStrA)(
				"XBox360_Reserved4"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved5:
			return (pCStrA)(
				"XBox360_Reserved5"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved6:
			return (pCStrA)(
				"XBox360_Reserved6"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved7:
			return (pCStrA)(
				"XBox360_Reserved7"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved8:
			return (pCStrA)(
				"XBox360_Reserved8"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved9:
			return (pCStrA)(
				"XBox360_Reserved9"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved10:
			return (pCStrA)(
				"XBox360_Reserved10"
			);
			break;
		case k_EInputActionOrigin_Switch_A:
			return (pCStrA)(
				"Switch_A"
			);
			break;
		case k_EInputActionOrigin_Switch_B:
			return (pCStrA)(
				"Switch_B"
			);
			break;
		case k_EInputActionOrigin_Switch_X:
			return (pCStrA)(
				"Switch_X"
			);
			break;
		case k_EInputActionOrigin_Switch_Y:
			return (pCStrA)(
				"Switch_Y"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftBumper:
			return (pCStrA)(
				"Switch_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_Switch_RightBumper:
			return (pCStrA)(
				"Switch_RightBumper"
			);
			break;
		case k_EInputActionOrigin_Switch_Plus:
			return (pCStrA)(
				"Switch_Plus"
			);
			break;
		case k_EInputActionOrigin_Switch_Minus:
			return (pCStrA)(
				"Switch_Minus"
			);
			break;
		case k_EInputActionOrigin_Switch_Capture:
			return (pCStrA)(
				"Switch_Capture"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftTrigger_Pull:
			return (pCStrA)(
				"Switch_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftTrigger_Click:
			return (pCStrA)(
				"Switch_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_RightTrigger_Pull:
			return (pCStrA)(
				"Switch_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_Switch_RightTrigger_Click:
			return (pCStrA)(
				"Switch_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_Move:
			return (pCStrA)(
				"Switch_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_Click:
			return (pCStrA)(
				"Switch_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadNorth:
			return (pCStrA)(
				"Switch_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadSouth:
			return (pCStrA)(
				"Switch_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadWest:
			return (pCStrA)(
				"Switch_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadEast:
			return (pCStrA)(
				"Switch_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_Move:
			return (pCStrA)(
				"Switch_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_Click:
			return (pCStrA)(
				"Switch_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadNorth:
			return (pCStrA)(
				"Switch_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadSouth:
			return (pCStrA)(
				"Switch_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadWest:
			return (pCStrA)(
				"Switch_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadEast:
			return (pCStrA)(
				"Switch_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_North:
			return (pCStrA)(
				"Switch_DPad_North"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_South:
			return (pCStrA)(
				"Switch_DPad_South"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_West:
			return (pCStrA)(
				"Switch_DPad_West"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_East:
			return (pCStrA)(
				"Switch_DPad_East"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Move:
			return (pCStrA)(
				"Switch_ProGyro_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Pitch:
			return (pCStrA)(
				"Switch_ProGyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Yaw:
			return (pCStrA)(
				"Switch_ProGyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Roll:
			return (pCStrA)(
				"Switch_ProGyro_Roll"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_Move:
			return (pCStrA)(
				"Switch_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved1:
			return (pCStrA)(
				"Switch_Reserved1"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved2:
			return (pCStrA)(
				"Switch_Reserved2"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved3:
			return (pCStrA)(
				"Switch_Reserved3"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved4:
			return (pCStrA)(
				"Switch_Reserved4"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved5:
			return (pCStrA)(
				"Switch_Reserved5"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved6:
			return (pCStrA)(
				"Switch_Reserved6"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved7:
			return (pCStrA)(
				"Switch_Reserved7"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved8:
			return (pCStrA)(
				"Switch_Reserved8"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved9:
			return (pCStrA)(
				"Switch_Reserved9"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved10:
			return (pCStrA)(
				"Switch_Reserved10"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Move:
			return (pCStrA)(
				"Switch_RightGyro_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Pitch:
			return (pCStrA)(
				"Switch_RightGyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Yaw:
			return (pCStrA)(
				"Switch_RightGyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Roll:
			return (pCStrA)(
				"Switch_RightGyro_Roll"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Move:
			return (pCStrA)(
				"Switch_LeftGyro_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Pitch:
			return (pCStrA)(
				"Switch_LeftGyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Yaw:
			return (pCStrA)(
				"Switch_LeftGyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Roll:
			return (pCStrA)(
				"Switch_LeftGyro_Roll"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGrip_Lower:
			return (pCStrA)(
				"Switch_LeftGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGrip_Upper:
			return (pCStrA)(
				"Switch_LeftGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGrip_Lower:
			return (pCStrA)(
				"Switch_RightGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGrip_Upper:
			return (pCStrA)(
				"Switch_RightGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_N:
			return (pCStrA)(
				"Switch_JoyConButton_N"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_E:
			return (pCStrA)(
				"Switch_JoyConButton_E"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_S:
			return (pCStrA)(
				"Switch_JoyConButton_S"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_W:
			return (pCStrA)(
				"Switch_JoyConButton_W"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved15:
			return (pCStrA)(
				"Switch_Reserved15"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved16:
			return (pCStrA)(
				"Switch_Reserved16"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved17:
			return (pCStrA)(
				"Switch_Reserved17"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved18:
			return (pCStrA)(
				"Switch_Reserved18"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved19:
			return (pCStrA)(
				"Switch_Reserved19"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved20:
			return (pCStrA)(
				"Switch_Reserved20"
			);
			break;
		case k_EInputActionOrigin_PS5_X:
			return (pCStrA)(
				"PS5_X"
			);
			break;
		case k_EInputActionOrigin_PS5_Circle:
			return (pCStrA)(
				"PS5_Circle"
			);
			break;
		case k_EInputActionOrigin_PS5_Triangle:
			return (pCStrA)(
				"PS5_Triangle"
			);
			break;
		case k_EInputActionOrigin_PS5_Square:
			return (pCStrA)(
				"PS5_Square"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftBumper:
			return (pCStrA)(
				"PS5_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_PS5_RightBumper:
			return (pCStrA)(
				"PS5_RightBumper"
			);
			break;
		case k_EInputActionOrigin_PS5_Option:
			return (pCStrA)(
				"PS5_Option"
			);
			break;
		case k_EInputActionOrigin_PS5_Create:
			return (pCStrA)(
				"PS5_Create"
			);
			break;
		case k_EInputActionOrigin_PS5_Mute:
			return (pCStrA)(
				"PS5_Mute"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_Touch:
			return (pCStrA)(
				"PS5_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_Swipe:
			return (pCStrA)(
				"PS5_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_Click:
			return (pCStrA)(
				"PS5_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadNorth:
			return (pCStrA)(
				"PS5_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadSouth:
			return (pCStrA)(
				"PS5_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadWest:
			return (pCStrA)(
				"PS5_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadEast:
			return (pCStrA)(
				"PS5_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_Touch:
			return (pCStrA)(
				"PS5_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_Swipe:
			return (pCStrA)(
				"PS5_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_Click:
			return (pCStrA)(
				"PS5_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadNorth:
			return (pCStrA)(
				"PS5_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadSouth:
			return (pCStrA)(
				"PS5_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadWest:
			return (pCStrA)(
				"PS5_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadEast:
			return (pCStrA)(
				"PS5_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_Touch:
			return (pCStrA)(
				"PS5_CenterPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_Swipe:
			return (pCStrA)(
				"PS5_CenterPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_Click:
			return (pCStrA)(
				"PS5_CenterPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadNorth:
			return (pCStrA)(
				"PS5_CenterPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadSouth:
			return (pCStrA)(
				"PS5_CenterPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadWest:
			return (pCStrA)(
				"PS5_CenterPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadEast:
			return (pCStrA)(
				"PS5_CenterPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftTrigger_Pull:
			return (pCStrA)(
				"PS5_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftTrigger_Click:
			return (pCStrA)(
				"PS5_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_RightTrigger_Pull:
			return (pCStrA)(
				"PS5_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS5_RightTrigger_Click:
			return (pCStrA)(
				"PS5_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_Move:
			return (pCStrA)(
				"PS5_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_Click:
			return (pCStrA)(
				"PS5_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadNorth:
			return (pCStrA)(
				"PS5_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadSouth:
			return (pCStrA)(
				"PS5_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadWest:
			return (pCStrA)(
				"PS5_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadEast:
			return (pCStrA)(
				"PS5_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_Move:
			return (pCStrA)(
				"PS5_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_Click:
			return (pCStrA)(
				"PS5_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadNorth:
			return (pCStrA)(
				"PS5_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadSouth:
			return (pCStrA)(
				"PS5_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadWest:
			return (pCStrA)(
				"PS5_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadEast:
			return (pCStrA)(
				"PS5_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_North:
			return (pCStrA)(
				"PS5_DPad_North"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_South:
			return (pCStrA)(
				"PS5_DPad_South"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_West:
			return (pCStrA)(
				"PS5_DPad_West"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_East:
			return (pCStrA)(
				"PS5_DPad_East"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Move:
			return (pCStrA)(
				"PS5_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Pitch:
			return (pCStrA)(
				"PS5_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Yaw:
			return (pCStrA)(
				"PS5_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Roll:
			return (pCStrA)(
				"PS5_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_Move:
			return (pCStrA)(
				"PS5_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftGrip:
			return (pCStrA)(
				"PS5_LeftGrip"
			);
			break;
		case k_EInputActionOrigin_PS5_RightGrip:
			return (pCStrA)(
				"PS5_RightGrip"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftFn:
			return (pCStrA)(
				"PS5_LeftFn"
			);
			break;
		case k_EInputActionOrigin_PS5_RightFn:
			return (pCStrA)(
				"PS5_RightFn"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved5:
			return (pCStrA)(
				"PS5_Reserved5"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved6:
			return (pCStrA)(
				"PS5_Reserved6"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved7:
			return (pCStrA)(
				"PS5_Reserved7"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved8:
			return (pCStrA)(
				"PS5_Reserved8"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved9:
			return (pCStrA)(
				"PS5_Reserved9"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved10:
			return (pCStrA)(
				"PS5_Reserved10"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved11:
			return (pCStrA)(
				"PS5_Reserved11"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved12:
			return (pCStrA)(
				"PS5_Reserved12"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved13:
			return (pCStrA)(
				"PS5_Reserved13"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved14:
			return (pCStrA)(
				"PS5_Reserved14"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved15:
			return (pCStrA)(
				"PS5_Reserved15"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved16:
			return (pCStrA)(
				"PS5_Reserved16"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved17:
			return (pCStrA)(
				"PS5_Reserved17"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved18:
			return (pCStrA)(
				"PS5_Reserved18"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved19:
			return (pCStrA)(
				"PS5_Reserved19"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved20:
			return (pCStrA)(
				"PS5_Reserved20"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_A:
			return (pCStrA)(
				"SteamDeck_A"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_B:
			return (pCStrA)(
				"SteamDeck_B"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_X:
			return (pCStrA)(
				"SteamDeck_X"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Y:
			return (pCStrA)(
				"SteamDeck_Y"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L1:
			return (pCStrA)(
				"SteamDeck_L1"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R1:
			return (pCStrA)(
				"SteamDeck_R1"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Menu:
			return (pCStrA)(
				"SteamDeck_Menu"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_View:
			return (pCStrA)(
				"SteamDeck_View"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_Touch:
			return (pCStrA)(
				"SteamDeck_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_Swipe:
			return (pCStrA)(
				"SteamDeck_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_Click:
			return (pCStrA)(
				"SteamDeck_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadNorth:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadSouth:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadWest:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadEast:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_Touch:
			return (pCStrA)(
				"SteamDeck_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_Swipe:
			return (pCStrA)(
				"SteamDeck_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_Click:
			return (pCStrA)(
				"SteamDeck_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadNorth:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadSouth:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadWest:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadEast:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L2_SoftPull:
			return (pCStrA)(
				"SteamDeck_L2_SoftPull"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L2:
			return (pCStrA)(
				"SteamDeck_L2"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R2_SoftPull:
			return (pCStrA)(
				"SteamDeck_R2_SoftPull"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R2:
			return (pCStrA)(
				"SteamDeck_R2"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_Move:
			return (pCStrA)(
				"SteamDeck_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L3:
			return (pCStrA)(
				"SteamDeck_L3"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadNorth:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadSouth:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadWest:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadEast:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_Touch:
			return (pCStrA)(
				"SteamDeck_LeftStick_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_Move:
			return (pCStrA)(
				"SteamDeck_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R3:
			return (pCStrA)(
				"SteamDeck_R3"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadNorth:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadSouth:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadWest:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadEast:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_Touch:
			return (pCStrA)(
				"SteamDeck_RightStick_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L4:
			return (pCStrA)(
				"SteamDeck_L4"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R4:
			return (pCStrA)(
				"SteamDeck_R4"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L5:
			return (pCStrA)(
				"SteamDeck_L5"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R5:
			return (pCStrA)(
				"SteamDeck_R5"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_Move:
			return (pCStrA)(
				"SteamDeck_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_North:
			return (pCStrA)(
				"SteamDeck_DPad_North"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_South:
			return (pCStrA)(
				"SteamDeck_DPad_South"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_West:
			return (pCStrA)(
				"SteamDeck_DPad_West"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_East:
			return (pCStrA)(
				"SteamDeck_DPad_East"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Move:
			return (pCStrA)(
				"SteamDeck_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Pitch:
			return (pCStrA)(
				"SteamDeck_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Yaw:
			return (pCStrA)(
				"SteamDeck_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Roll:
			return (pCStrA)(
				"SteamDeck_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved1:
			return (pCStrA)(
				"SteamDeck_Reserved1"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved2:
			return (pCStrA)(
				"SteamDeck_Reserved2"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved3:
			return (pCStrA)(
				"SteamDeck_Reserved3"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved4:
			return (pCStrA)(
				"SteamDeck_Reserved4"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved5:
			return (pCStrA)(
				"SteamDeck_Reserved5"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved6:
			return (pCStrA)(
				"SteamDeck_Reserved6"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved7:
			return (pCStrA)(
				"SteamDeck_Reserved7"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved8:
			return (pCStrA)(
				"SteamDeck_Reserved8"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved9:
			return (pCStrA)(
				"SteamDeck_Reserved9"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved10:
			return (pCStrA)(
				"SteamDeck_Reserved10"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved11:
			return (pCStrA)(
				"SteamDeck_Reserved11"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved12:
			return (pCStrA)(
				"SteamDeck_Reserved12"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved13:
			return (pCStrA)(
				"SteamDeck_Reserved13"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved14:
			return (pCStrA)(
				"SteamDeck_Reserved14"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved15:
			return (pCStrA)(
				"SteamDeck_Reserved15"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved16:
			return (pCStrA)(
				"SteamDeck_Reserved16"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved17:
			return (pCStrA)(
				"SteamDeck_Reserved17"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved18:
			return (pCStrA)(
				"SteamDeck_Reserved18"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved19:
			return (pCStrA)(
				"SteamDeck_Reserved19"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved20:
			return (pCStrA)(
				"SteamDeck_Reserved20"
			);
			break;
	}

	return (pCStrA)(
		""
	);

}

pCStrA _SteamInput_::GetStringForActionOrigin(EInputActionOrigin eInputActionOrigin) {
	DEBUGBREAK("ISteamInput::GetStringForActionOrigin");

	return this->GetGlyphForActionOrigin_Legacy(eInputActionOrigin);

}

pCStrA _SteamInput_::GetStringForAnalogActionName(InputAnalogActionHandle_t hDigitalAction) {
	DEBUGBREAK("ISteamInput::GetStringForAnalogActionName");

	return (pCStrA)(
		""
	);

}

void _SteamInput_::StopAnalogActionMomentum(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("ISteamInput::StopAnalogActionMomentum");

	/* Empty Method */

}

InputMotionData_t _SteamInput_::GetMotionData(InputHandle_t hController) {
	DEBUGBREAK("ISteamInput::GetMotionData");

	InputMotionData_t inputMotionData{};

	inputMotionData.posAccelX = 0.0F;
	inputMotionData.posAccelY = 0.0F;
	inputMotionData.posAccelZ = 0.0F;

	inputMotionData.rotQuatW = 0.0F;
	inputMotionData.rotQuatX = 0.0F;
	inputMotionData.rotQuatY = 0.0F;
	inputMotionData.rotQuatZ = 0.0F;

	inputMotionData.rotVelX = 0.0F;
	inputMotionData.rotVelY = 0.0F;
	inputMotionData.rotVelZ = 0.0F;

	return inputMotionData;

}

void _SteamInput_::TriggerVibration(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) {
	DEBUGBREAK("ISteamInput::TriggerVibration");

	/* Empty Method */

}

void _SteamInput_::TriggerVibrationExtended(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed, Uint16 LeftTriggerSpeed, Uint16 RightTriggerSpeed) {
	DEBUGBREAK("ISteamInput::TriggerVibrationExtended");

	/* Empty Method */

}

void _SteamInput_::TriggerSimpleHapticEvent(InputHandle_t hController, EControllerHapticLocation eControllerHapticLocation, Uint8 nIntensity, Uint8 nGainDB, Uint8 nOtherIntensity, Uint8 nOtherGainDB) {
	DEBUGBREAK("ISteamInput::TriggerSimpleHapticEvent");

	/* Empty Method */

}

void _SteamInput_::SetLEDColor(InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) {
	DEBUGBREAK("ISteamInput::SetLEDColor");

	/* Empty Method */

}

void _SteamInput_::Legacy_TriggerHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) {
	DEBUGBREAK("ISteamInput::Legacy_TriggerHapticPulse");

	/* Empty Method */

}

void _SteamInput_::Legacy_TriggerRepeatedHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) {
	DEBUGBREAK("ISteamInput::Legacy_TriggerRepeatedHapticPulse");

	/* Empty Method */

}

Bool _SteamInput_::ShowBindingPanel(InputHandle_t hController) {
	DEBUGBREAK("ISteamInput::ShowBindingPanel");

	return True;

}

ESteamInputType _SteamInput_::GetInputTypeForHandle(InputHandle_t hController) {
	DEBUGBREAK("ISteamInput::GetInputTypeForHandle");

	return k_ESteamInputType_Unknown;

}

InputHandle_t _SteamInput_::GetControllerForGamepadIndex(Int32 nIndex) {
	DEBUGBREAK("ISteamInput::GetControllerForGamepadIndex");

	return (InputHandle_t)(0x0000000000000000);

}

Int32 _SteamInput_::GetGamepadIndexForController(InputHandle_t hController) {
	DEBUGBREAK("ISteamInput::GetGamepadIndexForController");

	return 0;

}

pCStrA _SteamInput_::GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("ISteamInput::GetStringForXboxOrigin");

	return this->GetGlyphForXboxOrigin(eXboxOrigin);

}

pCStrA _SteamInput_::GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("ISteamInput::GetGlyphForXboxOrigin");

	switch (eXboxOrigin) {
		case k_EXboxOrigin_A:
			return (pCStrA)(
				"A"
			);
			break;
		case k_EXboxOrigin_B:
			return (pCStrA)(
				"B"
			);
			break;
		case k_EXboxOrigin_X:
			return (pCStrA)(
				"X"
			);
			break;
		case k_EXboxOrigin_Y:
			return (pCStrA)(
				"Y"
			);
			break;
		case k_EXboxOrigin_LeftBumper:
			return (pCStrA)(
				"LeftBumper"
			);
			break;
		case k_EXboxOrigin_RightBumper:
			return (pCStrA)(
				"RightBumper"
			);
			break;
		case k_EXboxOrigin_Menu:
			return (pCStrA)(
				"Menu"
			);
			break;
		case k_EXboxOrigin_View:
			return (pCStrA)(
				"View"
			);
			break;
		case k_EXboxOrigin_LeftTrigger_Pull:
			return (pCStrA)(
				"LeftTrigger_Pull"
			);
			break;
		case k_EXboxOrigin_LeftTrigger_Click:
			return (pCStrA)(
				"LeftTrigger_Click"
			);
			break;
		case k_EXboxOrigin_RightTrigger_Pull:
			return (pCStrA)(
				"RightTrigger_Pull"
			);
			break;
		case k_EXboxOrigin_RightTrigger_Click:
			return (pCStrA)(
				"RightTrigger_Click"
			);
			break;
		case k_EXboxOrigin_LeftStick_Move:
			return (pCStrA)(
				"LeftStick_Move"
			);
			break;
		case k_EXboxOrigin_LeftStick_Click:
			return (pCStrA)(
				"LeftStick_Click"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadNorth:
			return (pCStrA)(
				"LeftStick_DPadNorth"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadSouth:
			return (pCStrA)(
				"LeftStick_DPadSouth"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadWest:
			return (pCStrA)(
				"LeftStick_DPadWest"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadEast:
			return (pCStrA)(
				"LeftStick_DPadEast"
			);
			break;
		case k_EXboxOrigin_RightStick_Move:
			return (pCStrA)(
				"RightStick_Move"
			);
			break;
		case k_EXboxOrigin_RightStick_Click:
			return (pCStrA)(
				"RightStick_Click"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadNorth:
			return (pCStrA)(
				"RightStick_DPadNorth"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadSouth:
			return (pCStrA)(
				"RightStick_DPadSouth"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadWest:
			return (pCStrA)(
				"RightStick_DPadWest"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadEast:
			return (pCStrA)(
				"RightStick_DPadEast"
			);
			break;
		case k_EXboxOrigin_DPad_North:
			return (pCStrA)(
				"DPad_North"
			);
			break;
		case k_EXboxOrigin_DPad_South:
			return (pCStrA)(
				"DPad_South"
			);
			break;
		case k_EXboxOrigin_DPad_West:
			return (pCStrA)(
				"DPad_West"
			);
			break;
		case k_EXboxOrigin_DPad_East:
			return (pCStrA)(
				"DPad_East"
			);
			break;
	}

	return (pCStrA)(
		""
	);

}

EInputActionOrigin _SteamInput_::GetActionOriginFromXboxOrigin(InputHandle_t hController, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("ISteamInput::GetActionOriginFromXboxOrigin");

	return k_EInputActionOrigin_None;

}

EInputActionOrigin _SteamInput_::TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceXboxOrigin) {
	DEBUGBREAK("ISteamInput::TranslateActionOrigin");

	return k_EInputActionOrigin_None;

}

Bool _SteamInput_::GetDeviceBindingRevision(InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) {
	DEBUGBREAK("ISteamInput::GetDeviceBindingRevision");

	if (pMajor != NULL) {
		*pMajor = 0;
	}

	if (pMinor != NULL) {
		*pMinor = 0;
	}

	return False;

}

Uint32 _SteamInput_::GetRemotePlaySessionID(InputHandle_t hController) {
	DEBUGBREAK("ISteamInput::GetRemotePlaySessionID");

	return 0x00000000;

}

Uint16 _SteamInput_::GetSessionInputConfigurationSettings() {
	DEBUGBREAK("ISteamInput::GetSessionInputConfigurationSettings");

	return 0x0000;

}

void _SteamInput_::SetDualSenseTriggerEffect(InputHandle_t hController, const pScePadTriggerEffect pScePadTriggerEffect) {
	DEBUGBREAK("ISteamInput::SetDualSenseTriggerEffect");

	/* Empty Method */

}
