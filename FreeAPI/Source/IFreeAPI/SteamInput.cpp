// -----------------------------------------------------------------------------
#include "SteamInput.h"
// -----------------------------------------------------------------------------

Bool _SteamInput_::Init(Bool bExplicitlyCallRunFrame) {

	return True;

}

Bool _SteamInput_::Shutdown() {

	return True;

}

Bool _SteamInput_::SetInputActionManifestFilePath(const pStrA pchInputActionManifestAbsolutePath) {

	return True;

}

void _SteamInput_::RunFrame(Bool bReservedValue) {

	/* Empty Method */

}

Bool _SteamInput_::BWaitForData(Bool bWaitForever, Uint32 Timeout) {

	return False;

}

Bool _SteamInput_::BNewDataAvailable() {

	return False;

}

Int32 _SteamInput_::GetConnectedControllers(pInputHandle_t hController) {

	return 0;

}

void _SteamInput_::EnableDeviceCallbacks() {

	/* Empty Method */

}

void _SteamInput_::EnableActionEventCallbacks(SteamInputActionEventCallback pFunction) {

	/* Empty Method */

}

InputActionSetHandle_t _SteamInput_::GetActionSetHandle(const pStrA pszActionSetName) {

	return (InputActionSetHandle_t)(0x0000000000000000);

}

void _SteamInput_::ActivateActionSet(InputHandle_t hController, InputActionSetHandle_t hActionSet) {

	/* Empty Method */

}

InputActionSetHandle_t _SteamInput_::GetCurrentActionSet(InputHandle_t hController) {

	return (InputActionSetHandle_t)(0x0000000000000000);

}

void _SteamInput_::ActivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) {

	/* Empty Method */

}

void _SteamInput_::DeactivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) {

	/* Empty Method */

}

void _SteamInput_::DeactivateAllActionSetLayers(InputHandle_t hController) {

	/* Empty Method */

}

Int32 _SteamInput_::GetActiveActionSetLayers(InputHandle_t hController, pInputActionSetHandle_t phController) {

	return 0;

}

InputDigitalActionHandle_t _SteamInput_::GetDigitalActionHandle(const pStrA pszActionName) {

	return (InputDigitalActionHandle_t)(0x0000000000000000);

}

InputDigitalActionData_t _SteamInput_::GetDigitalActionData(InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) {

	InputDigitalActionData_t inputDigitalActionData{};
	inputDigitalActionData.bActive = False;
	inputDigitalActionData.bState = False;

	return inputDigitalActionData;

}

Int32 _SteamInput_::GetDigitalActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, pEInputActionOrigin peInputActionOrigin) {

	return 0;

}

const pStrA _SteamInput_::GetStringForDigitalActionName(InputDigitalActionHandle_t hDigitalAction) {

	return (const pStrA)(
		""
	);

}

InputAnalogActionHandle_t _SteamInput_::GetAnalogActionHandle(const pStrA pszActionName) {

	return (InputAnalogActionHandle_t)(0x0000000000000000);

}

InputAnalogActionData_t _SteamInput_::GetAnalogActionData(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) {

	InputAnalogActionData_t inputAnalogActionData{};
	inputAnalogActionData.bActive = False;
	inputAnalogActionData.eInputSourceMode = k_EInputSourceMode_None;
	inputAnalogActionData.x = 0.0F;
	inputAnalogActionData.y = 0.0F;

	return inputAnalogActionData;

}

Int32 _SteamInput_::GetAnalogActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, pEInputActionOrigin peInputActionOrigin) {

	return 0;

}

const pStrA _SteamInput_::GetGlyphPNGForActionOrigin(EInputActionOrigin eInputActionOrigin, ESteamInputGlyphSize eSteamInputGlyphSize, Uint32 nFlags) {

	return (const pStrA)(
		""
	);

}

const pStrA _SteamInput_::GetGlyphSVGForActionOrigin(EInputActionOrigin eInputActionOrigin, Uint32 nFlags) {

	return (const pStrA)(
		""
	);

}

const pStrA _SteamInput_::GetGlyphForActionOrigin_Legacy(EInputActionOrigin eInputActionOrigin) {

	switch (eInputActionOrigin) {
		case k_EInputActionOrigin_SteamController_A:
			return (const pStrA)(
				"SteamController_A"
			);
			break;
		case k_EInputActionOrigin_SteamController_B:
			return (const pStrA)(
				"SteamController_B"
			);
			break;
		case k_EInputActionOrigin_SteamController_X:
			return (const pStrA)(
				"SteamController_X"
			);
			break;
		case k_EInputActionOrigin_SteamController_Y:
			return (const pStrA)(
				"SteamController_Y"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftBumper:
			return (const pStrA)(
				"SteamController_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightBumper:
			return (const pStrA)(
				"SteamController_RightBumper"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftGrip:
			return (const pStrA)(
				"SteamController_LeftGrip"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightGrip:
			return (const pStrA)(
				"SteamController_RightGrip"
			);
			break;
		case k_EInputActionOrigin_SteamController_Start:
			return (const pStrA)(
				"SteamController_Start"
			);
			break;
		case k_EInputActionOrigin_SteamController_Back:
			return (const pStrA)(
				"SteamController_Back"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_Touch:
			return (const pStrA)(
				"SteamController_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_Swipe:
			return (const pStrA)(
				"SteamController_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_Click:
			return (const pStrA)(
				"SteamController_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadNorth:
			return (const pStrA)(
				"SteamController_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadSouth:
			return (const pStrA)(
				"SteamController_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadWest:
			return (const pStrA)(
				"SteamController_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftPad_DPadEast:
			return (const pStrA)(
				"SteamController_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_Touch:
			return (const pStrA)(
				"SteamController_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_Swipe:
			return (const pStrA)(
				"SteamController_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_Click:
			return (const pStrA)(
				"SteamController_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadNorth:
			return (const pStrA)(
				"SteamController_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadSouth:
			return (const pStrA)(
				"SteamController_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadWest:
			return (const pStrA)(
				"SteamController_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightPad_DPadEast:
			return (const pStrA)(
				"SteamController_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftTrigger_Pull:
			return (const pStrA)(
				"SteamController_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftTrigger_Click:
			return (const pStrA)(
				"SteamController_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightTrigger_Pull:
			return (const pStrA)(
				"SteamController_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_SteamController_RightTrigger_Click:
			return (const pStrA)(
				"SteamController_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_Move:
			return (const pStrA)(
				"SteamController_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_Click:
			return (const pStrA)(
				"SteamController_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadNorth:
			return (const pStrA)(
				"SteamController_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadSouth:
			return (const pStrA)(
				"SteamController_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadWest:
			return (const pStrA)(
				"SteamController_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamController_LeftStick_DPadEast:
			return (const pStrA)(
				"SteamController_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Move:
			return (const pStrA)(
				"SteamController_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Pitch:
			return (const pStrA)(
				"SteamController_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Yaw:
			return (const pStrA)(
				"SteamController_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_SteamController_Gyro_Roll:
			return (const pStrA)(
				"SteamController_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved0:
			return (const pStrA)(
				"SteamController_Reserved0"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved1:
			return (const pStrA)(
				"SteamController_Reserved1"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved2:
			return (const pStrA)(
				"SteamController_Reserved2"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved3:
			return (const pStrA)(
				"SteamController_Reserved3"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved4:
			return (const pStrA)(
				"SteamController_Reserved4"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved5:
			return (const pStrA)(
				"SteamController_Reserved5"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved6:
			return (const pStrA)(
				"SteamController_Reserved6"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved7:
			return (const pStrA)(
				"SteamController_Reserved7"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved8:
			return (const pStrA)(
				"SteamController_Reserved8"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved9:
			return (const pStrA)(
				"SteamController_Reserved9"
			);
			break;
		case k_EInputActionOrigin_SteamController_Reserved10:
			return (const pStrA)(
				"SteamController_Reserved10"
			);
			break;
		case k_EInputActionOrigin_PS4_X:
			return (const pStrA)(
				"PS4_X"
			);
			break;
		case k_EInputActionOrigin_PS4_Circle:
			return (const pStrA)(
				"PS4_Circle"
			);
			break;
		case k_EInputActionOrigin_PS4_Triangle:
			return (const pStrA)(
				"PS4_Triangle"
			);
			break;
		case k_EInputActionOrigin_PS4_Square:
			return (const pStrA)(
				"PS4_Square"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftBumper:
			return (const pStrA)(
				"PS4_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_PS4_RightBumper:
			return (const pStrA)(
				"PS4_RightBumper"
			);
			break;
		case k_EInputActionOrigin_PS4_Options:
			return (const pStrA)(
				"PS4_Options"
			);
			break;
		case k_EInputActionOrigin_PS4_Share:
			return (const pStrA)(
				"PS4_Share"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_Touch:
			return (const pStrA)(
				"PS4_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_Swipe:
			return (const pStrA)(
				"PS4_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_Click:
			return (const pStrA)(
				"PS4_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadNorth:
			return (const pStrA)(
				"PS4_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadSouth:
			return (const pStrA)(
				"PS4_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadWest:
			return (const pStrA)(
				"PS4_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftPad_DPadEast:
			return (const pStrA)(
				"PS4_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_Touch:
			return (const pStrA)(
				"PS4_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_Swipe:
			return (const pStrA)(
				"PS4_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_Click:
			return (const pStrA)(
				"PS4_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadNorth:
			return (const pStrA)(
				"PS4_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadSouth:
			return (const pStrA)(
				"PS4_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadWest:
			return (const pStrA)(
				"PS4_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_RightPad_DPadEast:
			return (const pStrA)(
				"PS4_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_Touch:
			return (const pStrA)(
				"PS4_CenterPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_Swipe:
			return (const pStrA)(
				"PS4_CenterPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_Click:
			return (const pStrA)(
				"PS4_CenterPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadNorth:
			return (const pStrA)(
				"PS4_CenterPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadSouth:
			return (const pStrA)(
				"PS4_CenterPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadWest:
			return (const pStrA)(
				"PS4_CenterPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_CenterPad_DPadEast:
			return (const pStrA)(
				"PS4_CenterPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftTrigger_Pull:
			return (const pStrA)(
				"PS4_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftTrigger_Click:
			return (const pStrA)(
				"PS4_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_RightTrigger_Pull:
			return (const pStrA)(
				"PS4_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS4_RightTrigger_Click:
			return (const pStrA)(
				"PS4_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_Move:
			return (const pStrA)(
				"PS4_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_Click:
			return (const pStrA)(
				"PS4_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadNorth:
			return (const pStrA)(
				"PS4_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadSouth:
			return (const pStrA)(
				"PS4_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadWest:
			return (const pStrA)(
				"PS4_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_LeftStick_DPadEast:
			return (const pStrA)(
				"PS4_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_Move:
			return (const pStrA)(
				"PS4_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_Click:
			return (const pStrA)(
				"PS4_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadNorth:
			return (const pStrA)(
				"PS4_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadSouth:
			return (const pStrA)(
				"PS4_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadWest:
			return (const pStrA)(
				"PS4_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS4_RightStick_DPadEast:
			return (const pStrA)(
				"PS4_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_North:
			return (const pStrA)(
				"PS4_DPad_North"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_South:
			return (const pStrA)(
				"PS4_DPad_South"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_West:
			return (const pStrA)(
				"PS4_DPad_West"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_East:
			return (const pStrA)(
				"PS4_DPad_East"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Move:
			return (const pStrA)(
				"PS4_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Pitch:
			return (const pStrA)(
				"PS4_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Yaw:
			return (const pStrA)(
				"PS4_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_PS4_Gyro_Roll:
			return (const pStrA)(
				"PS4_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_PS4_DPad_Move:
			return (const pStrA)(
				"PS4_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved1:
			return (const pStrA)(
				"PS4_Reserved1"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved2:
			return (const pStrA)(
				"PS4_Reserved2"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved3:
			return (const pStrA)(
				"PS4_Reserved3"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved4:
			return (const pStrA)(
				"PS4_Reserved4"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved5:
			return (const pStrA)(
				"PS4_Reserved5"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved6:
			return (const pStrA)(
				"PS4_Reserved6"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved7:
			return (const pStrA)(
				"PS4_Reserved7"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved8:
			return (const pStrA)(
				"PS4_Reserved8"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved9:
			return (const pStrA)(
				"PS4_Reserved9"
			);
			break;
		case k_EInputActionOrigin_PS4_Reserved10:
			return (const pStrA)(
				"PS4_Reserved10"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_A:
			return (const pStrA)(
				"XBoxOne_A"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_B:
			return (const pStrA)(
				"XBoxOne_B"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_X:
			return (const pStrA)(
				"XBoxOne_X"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Y:
			return (const pStrA)(
				"XBoxOne_Y"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftBumper:
			return (const pStrA)(
				"XBoxOne_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightBumper:
			return (const pStrA)(
				"XBoxOne_RightBumper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Menu:
			return (const pStrA)(
				"XBoxOne_Menu"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_View:
			return (const pStrA)(
				"XBoxOne_View"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftTrigger_Pull:
			return (const pStrA)(
				"XBoxOne_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftTrigger_Click:
			return (const pStrA)(
				"XBoxOne_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightTrigger_Pull:
			return (const pStrA)(
				"XBoxOne_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightTrigger_Click:
			return (const pStrA)(
				"XBoxOne_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_Move:
			return (const pStrA)(
				"XBoxOne_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_Click:
			return (const pStrA)(
				"XBoxOne_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadNorth:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadSouth:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadWest:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftStick_DPadEast:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_Move:
			return (const pStrA)(
				"XBoxOne_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_Click:
			return (const pStrA)(
				"XBoxOne_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadNorth:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadSouth:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadWest:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightStick_DPadEast:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_North:
			return (const pStrA)(
				"XBoxOne_DPad_North"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_South:
			return (const pStrA)(
				"XBoxOne_DPad_South"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_West:
			return (const pStrA)(
				"XBoxOne_DPad_West"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_East:
			return (const pStrA)(
				"XBoxOne_DPad_East"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_DPad_Move:
			return (const pStrA)(
				"XBoxOne_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftGrip_Lower:
			return (const pStrA)(
				"XBoxOne_LeftGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_LeftGrip_Upper:
			return (const pStrA)(
				"XBoxOne_LeftGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightGrip_Lower:
			return (const pStrA)(
				"XBoxOne_RightGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_RightGrip_Upper:
			return (const pStrA)(
				"XBoxOne_RightGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Share:
			return (const pStrA)(
				"XBoxOne_Share"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved6:
			return (const pStrA)(
				"XBoxOne_Reserved6"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved7:
			return (const pStrA)(
				"XBoxOne_Reserved7"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved8:
			return (const pStrA)(
				"XBoxOne_Reserved8"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved9:
			return (const pStrA)(
				"XBoxOne_Reserved9"
			);
			break;
		case k_EInputActionOrigin_XBoxOne_Reserved10:
			return (const pStrA)(
				"XBoxOne_Reserved10"
			);
			break;
		case k_EInputActionOrigin_XBox360_A:
			return (const pStrA)(
				"XBox360_A"
			);
			break;
		case k_EInputActionOrigin_XBox360_B:
			return (const pStrA)(
				"XBox360_B"
			);
			break;
		case k_EInputActionOrigin_XBox360_X:
			return (const pStrA)(
				"XBox360_X"
			);
			break;
		case k_EInputActionOrigin_XBox360_Y:
			return (const pStrA)(
				"XBox360_Y"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftBumper:
			return (const pStrA)(
				"XBox360_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightBumper:
			return (const pStrA)(
				"XBox360_RightBumper"
			);
			break;
		case k_EInputActionOrigin_XBox360_Start:
			return (const pStrA)(
				"XBox360_Start"
			);
			break;
		case k_EInputActionOrigin_XBox360_Back:
			return (const pStrA)(
				"XBox360_Back"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftTrigger_Pull:
			return (const pStrA)(
				"XBox360_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftTrigger_Click:
			return (const pStrA)(
				"XBox360_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightTrigger_Pull:
			return (const pStrA)(
				"XBox360_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightTrigger_Click:
			return (const pStrA)(
				"XBox360_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_Move:
			return (const pStrA)(
				"XBox360_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_Click:
			return (const pStrA)(
				"XBox360_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadNorth:
			return (const pStrA)(
				"XBox360_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadSouth:
			return (const pStrA)(
				"XBox360_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadWest:
			return (const pStrA)(
				"XBox360_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBox360_LeftStick_DPadEast:
			return (const pStrA)(
				"XBox360_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_Move:
			return (const pStrA)(
				"XBox360_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_Click:
			return (const pStrA)(
				"XBox360_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadNorth:
			return (const pStrA)(
				"XBox360_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadSouth:
			return (const pStrA)(
				"XBox360_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadWest:
			return (const pStrA)(
				"XBox360_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_XBox360_RightStick_DPadEast:
			return (const pStrA)(
				"XBox360_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_North:
			return (const pStrA)(
				"XBox360_DPad_North"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_South:
			return (const pStrA)(
				"XBox360_DPad_South"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_West:
			return (const pStrA)(
				"XBox360_DPad_West"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_East:
			return (const pStrA)(
				"XBox360_DPad_East"
			);
			break;
		case k_EInputActionOrigin_XBox360_DPad_Move:
			return (const pStrA)(
				"XBox360_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved1:
			return (const pStrA)(
				"XBox360_Reserved1"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved2:
			return (const pStrA)(
				"XBox360_Reserved2"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved3:
			return (const pStrA)(
				"XBox360_Reserved3"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved4:
			return (const pStrA)(
				"XBox360_Reserved4"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved5:
			return (const pStrA)(
				"XBox360_Reserved5"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved6:
			return (const pStrA)(
				"XBox360_Reserved6"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved7:
			return (const pStrA)(
				"XBox360_Reserved7"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved8:
			return (const pStrA)(
				"XBox360_Reserved8"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved9:
			return (const pStrA)(
				"XBox360_Reserved9"
			);
			break;
		case k_EInputActionOrigin_XBox360_Reserved10:
			return (const pStrA)(
				"XBox360_Reserved10"
			);
			break;
		case k_EInputActionOrigin_Switch_A:
			return (const pStrA)(
				"Switch_A"
			);
			break;
		case k_EInputActionOrigin_Switch_B:
			return (const pStrA)(
				"Switch_B"
			);
			break;
		case k_EInputActionOrigin_Switch_X:
			return (const pStrA)(
				"Switch_X"
			);
			break;
		case k_EInputActionOrigin_Switch_Y:
			return (const pStrA)(
				"Switch_Y"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftBumper:
			return (const pStrA)(
				"Switch_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_Switch_RightBumper:
			return (const pStrA)(
				"Switch_RightBumper"
			);
			break;
		case k_EInputActionOrigin_Switch_Plus:
			return (const pStrA)(
				"Switch_Plus"
			);
			break;
		case k_EInputActionOrigin_Switch_Minus:
			return (const pStrA)(
				"Switch_Minus"
			);
			break;
		case k_EInputActionOrigin_Switch_Capture:
			return (const pStrA)(
				"Switch_Capture"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftTrigger_Pull:
			return (const pStrA)(
				"Switch_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftTrigger_Click:
			return (const pStrA)(
				"Switch_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_RightTrigger_Pull:
			return (const pStrA)(
				"Switch_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_Switch_RightTrigger_Click:
			return (const pStrA)(
				"Switch_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_Move:
			return (const pStrA)(
				"Switch_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_Click:
			return (const pStrA)(
				"Switch_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadNorth:
			return (const pStrA)(
				"Switch_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadSouth:
			return (const pStrA)(
				"Switch_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadWest:
			return (const pStrA)(
				"Switch_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftStick_DPadEast:
			return (const pStrA)(
				"Switch_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_Move:
			return (const pStrA)(
				"Switch_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_Click:
			return (const pStrA)(
				"Switch_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadNorth:
			return (const pStrA)(
				"Switch_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadSouth:
			return (const pStrA)(
				"Switch_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadWest:
			return (const pStrA)(
				"Switch_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_Switch_RightStick_DPadEast:
			return (const pStrA)(
				"Switch_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_North:
			return (const pStrA)(
				"Switch_DPad_North"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_South:
			return (const pStrA)(
				"Switch_DPad_South"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_West:
			return (const pStrA)(
				"Switch_DPad_West"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_East:
			return (const pStrA)(
				"Switch_DPad_East"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Move:
			return (const pStrA)(
				"Switch_ProGyro_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Pitch:
			return (const pStrA)(
				"Switch_ProGyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Yaw:
			return (const pStrA)(
				"Switch_ProGyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_Switch_ProGyro_Roll:
			return (const pStrA)(
				"Switch_ProGyro_Roll"
			);
			break;
		case k_EInputActionOrigin_Switch_DPad_Move:
			return (const pStrA)(
				"Switch_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved1:
			return (const pStrA)(
				"Switch_Reserved1"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved2:
			return (const pStrA)(
				"Switch_Reserved2"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved3:
			return (const pStrA)(
				"Switch_Reserved3"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved4:
			return (const pStrA)(
				"Switch_Reserved4"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved5:
			return (const pStrA)(
				"Switch_Reserved5"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved6:
			return (const pStrA)(
				"Switch_Reserved6"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved7:
			return (const pStrA)(
				"Switch_Reserved7"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved8:
			return (const pStrA)(
				"Switch_Reserved8"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved9:
			return (const pStrA)(
				"Switch_Reserved9"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved10:
			return (const pStrA)(
				"Switch_Reserved10"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Move:
			return (const pStrA)(
				"Switch_RightGyro_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Pitch:
			return (const pStrA)(
				"Switch_RightGyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Yaw:
			return (const pStrA)(
				"Switch_RightGyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGyro_Roll:
			return (const pStrA)(
				"Switch_RightGyro_Roll"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Move:
			return (const pStrA)(
				"Switch_LeftGyro_Move"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Pitch:
			return (const pStrA)(
				"Switch_LeftGyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Yaw:
			return (const pStrA)(
				"Switch_LeftGyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGyro_Roll:
			return (const pStrA)(
				"Switch_LeftGyro_Roll"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGrip_Lower:
			return (const pStrA)(
				"Switch_LeftGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_Switch_LeftGrip_Upper:
			return (const pStrA)(
				"Switch_LeftGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGrip_Lower:
			return (const pStrA)(
				"Switch_RightGrip_Lower"
			);
			break;
		case k_EInputActionOrigin_Switch_RightGrip_Upper:
			return (const pStrA)(
				"Switch_RightGrip_Upper"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_N:
			return (const pStrA)(
				"Switch_JoyConButton_N"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_E:
			return (const pStrA)(
				"Switch_JoyConButton_E"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_S:
			return (const pStrA)(
				"Switch_JoyConButton_S"
			);
			break;
		case k_EInputActionOrigin_Switch_JoyConButton_W:
			return (const pStrA)(
				"Switch_JoyConButton_W"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved15:
			return (const pStrA)(
				"Switch_Reserved15"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved16:
			return (const pStrA)(
				"Switch_Reserved16"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved17:
			return (const pStrA)(
				"Switch_Reserved17"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved18:
			return (const pStrA)(
				"Switch_Reserved18"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved19:
			return (const pStrA)(
				"Switch_Reserved19"
			);
			break;
		case k_EInputActionOrigin_Switch_Reserved20:
			return (const pStrA)(
				"Switch_Reserved20"
			);
			break;
		case k_EInputActionOrigin_PS5_X:
			return (const pStrA)(
				"PS5_X"
			);
			break;
		case k_EInputActionOrigin_PS5_Circle:
			return (const pStrA)(
				"PS5_Circle"
			);
			break;
		case k_EInputActionOrigin_PS5_Triangle:
			return (const pStrA)(
				"PS5_Triangle"
			);
			break;
		case k_EInputActionOrigin_PS5_Square:
			return (const pStrA)(
				"PS5_Square"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftBumper:
			return (const pStrA)(
				"PS5_LeftBumper"
			);
			break;
		case k_EInputActionOrigin_PS5_RightBumper:
			return (const pStrA)(
				"PS5_RightBumper"
			);
			break;
		case k_EInputActionOrigin_PS5_Option:
			return (const pStrA)(
				"PS5_Option"
			);
			break;
		case k_EInputActionOrigin_PS5_Create:
			return (const pStrA)(
				"PS5_Create"
			);
			break;
		case k_EInputActionOrigin_PS5_Mute:
			return (const pStrA)(
				"PS5_Mute"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_Touch:
			return (const pStrA)(
				"PS5_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_Swipe:
			return (const pStrA)(
				"PS5_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_Click:
			return (const pStrA)(
				"PS5_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadNorth:
			return (const pStrA)(
				"PS5_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadSouth:
			return (const pStrA)(
				"PS5_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadWest:
			return (const pStrA)(
				"PS5_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftPad_DPadEast:
			return (const pStrA)(
				"PS5_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_Touch:
			return (const pStrA)(
				"PS5_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_Swipe:
			return (const pStrA)(
				"PS5_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_Click:
			return (const pStrA)(
				"PS5_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadNorth:
			return (const pStrA)(
				"PS5_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadSouth:
			return (const pStrA)(
				"PS5_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadWest:
			return (const pStrA)(
				"PS5_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_RightPad_DPadEast:
			return (const pStrA)(
				"PS5_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_Touch:
			return (const pStrA)(
				"PS5_CenterPad_Touch"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_Swipe:
			return (const pStrA)(
				"PS5_CenterPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_Click:
			return (const pStrA)(
				"PS5_CenterPad_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadNorth:
			return (const pStrA)(
				"PS5_CenterPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadSouth:
			return (const pStrA)(
				"PS5_CenterPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadWest:
			return (const pStrA)(
				"PS5_CenterPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_CenterPad_DPadEast:
			return (const pStrA)(
				"PS5_CenterPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftTrigger_Pull:
			return (const pStrA)(
				"PS5_LeftTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftTrigger_Click:
			return (const pStrA)(
				"PS5_LeftTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_RightTrigger_Pull:
			return (const pStrA)(
				"PS5_RightTrigger_Pull"
			);
			break;
		case k_EInputActionOrigin_PS5_RightTrigger_Click:
			return (const pStrA)(
				"PS5_RightTrigger_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_Move:
			return (const pStrA)(
				"PS5_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_Click:
			return (const pStrA)(
				"PS5_LeftStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadNorth:
			return (const pStrA)(
				"PS5_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadSouth:
			return (const pStrA)(
				"PS5_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadWest:
			return (const pStrA)(
				"PS5_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftStick_DPadEast:
			return (const pStrA)(
				"PS5_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_Move:
			return (const pStrA)(
				"PS5_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_Click:
			return (const pStrA)(
				"PS5_RightStick_Click"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadNorth:
			return (const pStrA)(
				"PS5_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadSouth:
			return (const pStrA)(
				"PS5_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadWest:
			return (const pStrA)(
				"PS5_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_PS5_RightStick_DPadEast:
			return (const pStrA)(
				"PS5_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_North:
			return (const pStrA)(
				"PS5_DPad_North"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_South:
			return (const pStrA)(
				"PS5_DPad_South"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_West:
			return (const pStrA)(
				"PS5_DPad_West"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_East:
			return (const pStrA)(
				"PS5_DPad_East"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Move:
			return (const pStrA)(
				"PS5_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Pitch:
			return (const pStrA)(
				"PS5_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Yaw:
			return (const pStrA)(
				"PS5_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_PS5_Gyro_Roll:
			return (const pStrA)(
				"PS5_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_PS5_DPad_Move:
			return (const pStrA)(
				"PS5_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftGrip:
			return (const pStrA)(
				"PS5_LeftGrip"
			);
			break;
		case k_EInputActionOrigin_PS5_RightGrip:
			return (const pStrA)(
				"PS5_RightGrip"
			);
			break;
		case k_EInputActionOrigin_PS5_LeftFn:
			return (const pStrA)(
				"PS5_LeftFn"
			);
			break;
		case k_EInputActionOrigin_PS5_RightFn:
			return (const pStrA)(
				"PS5_RightFn"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved5:
			return (const pStrA)(
				"PS5_Reserved5"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved6:
			return (const pStrA)(
				"PS5_Reserved6"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved7:
			return (const pStrA)(
				"PS5_Reserved7"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved8:
			return (const pStrA)(
				"PS5_Reserved8"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved9:
			return (const pStrA)(
				"PS5_Reserved9"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved10:
			return (const pStrA)(
				"PS5_Reserved10"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved11:
			return (const pStrA)(
				"PS5_Reserved11"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved12:
			return (const pStrA)(
				"PS5_Reserved12"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved13:
			return (const pStrA)(
				"PS5_Reserved13"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved14:
			return (const pStrA)(
				"PS5_Reserved14"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved15:
			return (const pStrA)(
				"PS5_Reserved15"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved16:
			return (const pStrA)(
				"PS5_Reserved16"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved17:
			return (const pStrA)(
				"PS5_Reserved17"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved18:
			return (const pStrA)(
				"PS5_Reserved18"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved19:
			return (const pStrA)(
				"PS5_Reserved19"
			);
			break;
		case k_EInputActionOrigin_PS5_Reserved20:
			return (const pStrA)(
				"PS5_Reserved20"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_A:
			return (const pStrA)(
				"SteamDeck_A"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_B:
			return (const pStrA)(
				"SteamDeck_B"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_X:
			return (const pStrA)(
				"SteamDeck_X"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Y:
			return (const pStrA)(
				"SteamDeck_Y"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L1:
			return (const pStrA)(
				"SteamDeck_L1"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R1:
			return (const pStrA)(
				"SteamDeck_R1"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Menu:
			return (const pStrA)(
				"SteamDeck_Menu"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_View:
			return (const pStrA)(
				"SteamDeck_View"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_Touch:
			return (const pStrA)(
				"SteamDeck_LeftPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_Swipe:
			return (const pStrA)(
				"SteamDeck_LeftPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_Click:
			return (const pStrA)(
				"SteamDeck_LeftPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadNorth:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadSouth:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadWest:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftPad_DPadEast:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_Touch:
			return (const pStrA)(
				"SteamDeck_RightPad_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_Swipe:
			return (const pStrA)(
				"SteamDeck_RightPad_Swipe"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_Click:
			return (const pStrA)(
				"SteamDeck_RightPad_Click"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadNorth:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadSouth:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadWest:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightPad_DPadEast:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L2_SoftPull:
			return (const pStrA)(
				"SteamDeck_L2_SoftPull"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L2:
			return (const pStrA)(
				"SteamDeck_L2"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R2_SoftPull:
			return (const pStrA)(
				"SteamDeck_R2_SoftPull"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R2:
			return (const pStrA)(
				"SteamDeck_R2"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_Move:
			return (const pStrA)(
				"SteamDeck_LeftStick_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L3:
			return (const pStrA)(
				"SteamDeck_L3"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadNorth:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadSouth:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadWest:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_DPadEast:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_LeftStick_Touch:
			return (const pStrA)(
				"SteamDeck_LeftStick_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_Move:
			return (const pStrA)(
				"SteamDeck_RightStick_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R3:
			return (const pStrA)(
				"SteamDeck_R3"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadNorth:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadNorth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadSouth:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadSouth"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadWest:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadWest"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_DPadEast:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadEast"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_RightStick_Touch:
			return (const pStrA)(
				"SteamDeck_RightStick_Touch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L4:
			return (const pStrA)(
				"SteamDeck_L4"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R4:
			return (const pStrA)(
				"SteamDeck_R4"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_L5:
			return (const pStrA)(
				"SteamDeck_L5"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_R5:
			return (const pStrA)(
				"SteamDeck_R5"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_Move:
			return (const pStrA)(
				"SteamDeck_DPad_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_North:
			return (const pStrA)(
				"SteamDeck_DPad_North"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_South:
			return (const pStrA)(
				"SteamDeck_DPad_South"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_West:
			return (const pStrA)(
				"SteamDeck_DPad_West"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_DPad_East:
			return (const pStrA)(
				"SteamDeck_DPad_East"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Move:
			return (const pStrA)(
				"SteamDeck_Gyro_Move"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Pitch:
			return (const pStrA)(
				"SteamDeck_Gyro_Pitch"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Yaw:
			return (const pStrA)(
				"SteamDeck_Gyro_Yaw"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Gyro_Roll:
			return (const pStrA)(
				"SteamDeck_Gyro_Roll"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved1:
			return (const pStrA)(
				"SteamDeck_Reserved1"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved2:
			return (const pStrA)(
				"SteamDeck_Reserved2"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved3:
			return (const pStrA)(
				"SteamDeck_Reserved3"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved4:
			return (const pStrA)(
				"SteamDeck_Reserved4"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved5:
			return (const pStrA)(
				"SteamDeck_Reserved5"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved6:
			return (const pStrA)(
				"SteamDeck_Reserved6"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved7:
			return (const pStrA)(
				"SteamDeck_Reserved7"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved8:
			return (const pStrA)(
				"SteamDeck_Reserved8"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved9:
			return (const pStrA)(
				"SteamDeck_Reserved9"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved10:
			return (const pStrA)(
				"SteamDeck_Reserved10"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved11:
			return (const pStrA)(
				"SteamDeck_Reserved11"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved12:
			return (const pStrA)(
				"SteamDeck_Reserved12"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved13:
			return (const pStrA)(
				"SteamDeck_Reserved13"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved14:
			return (const pStrA)(
				"SteamDeck_Reserved14"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved15:
			return (const pStrA)(
				"SteamDeck_Reserved15"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved16:
			return (const pStrA)(
				"SteamDeck_Reserved16"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved17:
			return (const pStrA)(
				"SteamDeck_Reserved17"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved18:
			return (const pStrA)(
				"SteamDeck_Reserved18"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved19:
			return (const pStrA)(
				"SteamDeck_Reserved19"
			);
			break;
		case k_EInputActionOrigin_SteamDeck_Reserved20:
			return (const pStrA)(
				"SteamDeck_Reserved20"
			);
			break;
	}

	return (const pStrA)(
		""
	);

}

const pStrA _SteamInput_::GetStringForActionOrigin(EInputActionOrigin eInputActionOrigin) {

	return this->GetGlyphForActionOrigin_Legacy(eInputActionOrigin);

}

const pStrA _SteamInput_::GetStringForAnalogActionName(InputAnalogActionHandle_t hDigitalAction) {

	return (const pStrA)(
		""
	);

}

void _SteamInput_::StopAnalogActionMomentum(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) {

	/* Empty Method */

}

InputMotionData_t _SteamInput_::GetMotionData(InputHandle_t hController) {

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

	/* Empty Method */

}

void _SteamInput_::TriggerVibrationExtended(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed, Uint16 LeftTriggerSpeed, Uint16 RightTriggerSpeed) {

	/* Empty Method */

}

void _SteamInput_::TriggerSimpleHapticEvent(InputHandle_t hController, EControllerHapticLocation eControllerHapticLocation, Uint8 nIntensity, Uint8 nGainDB, Uint8 nOtherIntensity, Uint8 nOtherGainDB) {

	/* Empty Method */

}

void _SteamInput_::SetLEDColor(InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) {

	/* Empty Method */

}

void _SteamInput_::Legacy_TriggerHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) {

	/* Empty Method */

}

void _SteamInput_::Legacy_TriggerRepeatedHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) {

	/* Empty Method */

}

Bool _SteamInput_::ShowBindingPanel(InputHandle_t hController) {

	return True;

}

ESteamInputType _SteamInput_::GetInputTypeForHandle(InputHandle_t hController) {

	return k_ESteamInputType_Unknown;

}

InputHandle_t _SteamInput_::GetControllerForGamepadIndex(Int32 nIndex) {

	return (InputHandle_t)(0x0000000000000000);

}

Int32 _SteamInput_::GetGamepadIndexForController(InputHandle_t ulhController) {

	return 0;

}

const pStrA _SteamInput_::GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) {

	return this->GetGlyphForXboxOrigin(eXboxOrigin);

}

const pStrA _SteamInput_::GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) {

	switch (eXboxOrigin) {
		case k_EXboxOrigin_A:
			return (const pStrA)(
				"A"
			);
			break;
		case k_EXboxOrigin_B:
			return (const pStrA)(
				"B"
			);
			break;
		case k_EXboxOrigin_X:
			return (const pStrA)(
				"X"
			);
			break;
		case k_EXboxOrigin_Y:
			return (const pStrA)(
				"Y"
			);
			break;
		case k_EXboxOrigin_LeftBumper:
			return (const pStrA)(
				"LeftBumper"
			);
			break;
		case k_EXboxOrigin_RightBumper:
			return (const pStrA)(
				"RightBumper"
			);
			break;
		case k_EXboxOrigin_Menu:
			return (const pStrA)(
				"Menu"
			);
			break;
		case k_EXboxOrigin_View:
			return (const pStrA)(
				"View"
			);
			break;
		case k_EXboxOrigin_LeftTrigger_Pull:
			return (const pStrA)(
				"LeftTrigger_Pull"
			);
			break;
		case k_EXboxOrigin_LeftTrigger_Click:
			return (const pStrA)(
				"LeftTrigger_Click"
			);
			break;
		case k_EXboxOrigin_RightTrigger_Pull:
			return (const pStrA)(
				"RightTrigger_Pull"
			);
			break;
		case k_EXboxOrigin_RightTrigger_Click:
			return (const pStrA)(
				"RightTrigger_Click"
			);
			break;
		case k_EXboxOrigin_LeftStick_Move:
			return (const pStrA)(
				"LeftStick_Move"
			);
			break;
		case k_EXboxOrigin_LeftStick_Click:
			return (const pStrA)(
				"LeftStick_Click"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadNorth:
			return (const pStrA)(
				"LeftStick_DPadNorth"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadSouth:
			return (const pStrA)(
				"LeftStick_DPadSouth"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadWest:
			return (const pStrA)(
				"LeftStick_DPadWest"
			);
			break;
		case k_EXboxOrigin_LeftStick_DPadEast:
			return (const pStrA)(
				"LeftStick_DPadEast"
			);
			break;
		case k_EXboxOrigin_RightStick_Move:
			return (const pStrA)(
				"RightStick_Move"
			);
			break;
		case k_EXboxOrigin_RightStick_Click:
			return (const pStrA)(
				"RightStick_Click"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadNorth:
			return (const pStrA)(
				"RightStick_DPadNorth"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadSouth:
			return (const pStrA)(
				"RightStick_DPadSouth"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadWest:
			return (const pStrA)(
				"RightStick_DPadWest"
			);
			break;
		case k_EXboxOrigin_RightStick_DPadEast:
			return (const pStrA)(
				"RightStick_DPadEast"
			);
			break;
		case k_EXboxOrigin_DPad_North:
			return (const pStrA)(
				"DPad_North"
			);
			break;
		case k_EXboxOrigin_DPad_South:
			return (const pStrA)(
				"DPad_South"
			);
			break;
		case k_EXboxOrigin_DPad_West:
			return (const pStrA)(
				"DPad_West"
			);
			break;
		case k_EXboxOrigin_DPad_East:
			return (const pStrA)(
				"DPad_East"
			);
			break;
	}

	return (const pStrA)(
		""
	);

}

EInputActionOrigin _SteamInput_::GetActionOriginFromXboxOrigin(InputHandle_t hController, EXboxOrigin eXboxOrigin) {

	return k_EInputActionOrigin_None;

}

EInputActionOrigin _SteamInput_::TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceXboxOrigin) {

	return k_EInputActionOrigin_None;

}

Bool _SteamInput_::GetDeviceBindingRevision(InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) {

	if (pMajor != NULL) {
		*pMajor = 0;
	}

	if (pMinor != NULL) {
		*pMinor = 0;
	}

	return False;

}

Uint32 _SteamInput_::GetRemotePlaySessionID(InputHandle_t hController) {

	return 0x00000000;

}

Uint16 _SteamInput_::GetSessionInputConfigurationSettings() {

	return 0x0000;

}

void _SteamInput_::SetDualSenseTriggerEffect(InputHandle_t hController, const pScePadTriggerEffect pScePadTriggerEffect) {

	/* Empty Method */

}
