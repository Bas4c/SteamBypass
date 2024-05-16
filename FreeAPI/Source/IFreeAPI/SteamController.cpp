// -----------------------------------------------------------------------------
#include "SteamController.h"
// -----------------------------------------------------------------------------

Bool _SteamController_::Init() {

	return True;

}

Bool _SteamController_::Shutdown() {

	return True;

}

void _SteamController_::RunFrame() {

	/* Empty Method */

}

Int32 _SteamController_::GetConnectedControllers(pControllerHandle_t phController) {

	return 0;

}

ControllerActionSetHandle_t _SteamController_::GetActionSetHandle(const pStrA pchActionSetName) {

	return (ControllerActionSetHandle_t)(0x0000000000000000);

}

void _SteamController_::ActivateActionSet(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet) {

	/* Empty Method */

}

ControllerActionSetHandle_t _SteamController_::GetCurrentActionSet(ControllerHandle_t hController) {

	return (ControllerActionSetHandle_t)(0x0000000000000000);

}

void _SteamController_::ActivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) {

	/* Empty Method */

}

void _SteamController_::DeactivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) {

	/* Empty Method */

}

void _SteamController_::DeactivateAllActionSetLayers(ControllerHandle_t hController) {

	/* Empty Method */

}

Int32 _SteamController_::GetActiveActionSetLayers(ControllerHandle_t hController, pControllerActionSetHandle_t phActionSetLayer) {

	return 0;

}

ControllerDigitalActionHandle_t _SteamController_::GetDigitalActionHandle(const pStrA pchActionName) {

	return (ControllerDigitalActionHandle_t)(0x0000000000000000);

}

ControllerDigitalActionData_t _SteamController_::GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) {

	ControllerDigitalActionData_t controllerDigitalActionData;
	controllerDigitalActionData.bActive = False;
	controllerDigitalActionData.bState = False;

	return controllerDigitalActionData;

}

Int32 _SteamController_::GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) {

	return 0;

}

ControllerAnalogActionHandle_t _SteamController_::GetAnalogActionHandle(const pStrA pchActionName) {

	return (ControllerAnalogActionHandle_t)(0x0000000000000000);

}

ControllerAnalogActionData_t _SteamController_::GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) {

	ControllerAnalogActionData_t controllerAnalogActionData;
	controllerAnalogActionData.bActive = False;
	controllerAnalogActionData.eInputSourceMode = k_EInputSourceMode_None;
	controllerAnalogActionData.x = 0.0F;
	controllerAnalogActionData.y = 0.0F;

	return controllerAnalogActionData;

}

Int32 _SteamController_::GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) {

	return 0;

}

const pStrA _SteamController_::GetGlyphForActionOrigin(EControllerActionOrigin eControllerActionOrigin) {

	switch (eControllerActionOrigin) {
		case k_EControllerActionOrigin_A:
			return (const pStrA)(
				"A"
			);
			break;
		case k_EControllerActionOrigin_B:
			return (const pStrA)(
				"B"
			);
			break;
		case k_EControllerActionOrigin_X:
			return (const pStrA)(
				"X"
			);
			break;
		case k_EControllerActionOrigin_Y:
			return (const pStrA)(
				"Y"
			);
			break;
		case k_EControllerActionOrigin_LeftBumper:
			return (const pStrA)(
				"LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_RightBumper:
			return (const pStrA)(
				"RightBumper"
			);
			break;
		case k_EControllerActionOrigin_LeftGrip:
			return (const pStrA)(
				"LeftGrip"
			);
			break;
		case k_EControllerActionOrigin_RightGrip:
			return (const pStrA)(
				"RightGrip"
			);
			break;
		case k_EControllerActionOrigin_Start:
			return (const pStrA)(
				"Start"
			);
			break;
		case k_EControllerActionOrigin_Back:
			return (const pStrA)(
				"Back"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_Touch:
			return (const pStrA)(
				"LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_Swipe:
			return (const pStrA)(
				"LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_Click:
			return (const pStrA)(
				"LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadNorth:
			return (const pStrA)(
				"LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadSouth:
			return (const pStrA)(
				"LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadWest:
			return (const pStrA)(
				"LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadEast:
			return (const pStrA)(
				"LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_RightPad_Touch:
			return (const pStrA)(
				"RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_RightPad_Swipe:
			return (const pStrA)(
				"RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_RightPad_Click:
			return (const pStrA)(
				"RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadNorth:
			return (const pStrA)(
				"RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadSouth:
			return (const pStrA)(
				"RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadWest:
			return (const pStrA)(
				"RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadEast:
			return (const pStrA)(
				"RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_LeftTrigger_Pull:
			return (const pStrA)(
				"LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_LeftTrigger_Click:
			return (const pStrA)(
				"LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_RightTrigger_Pull:
			return (const pStrA)(
				"RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_RightTrigger_Click:
			return (const pStrA)(
				"RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_Move:
			return (const pStrA)(
				"LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_Click:
			return (const pStrA)(
				"LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadNorth:
			return (const pStrA)(
				"LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadSouth:
			return (const pStrA)(
				"LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadWest:
			return (const pStrA)(
				"LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadEast:
			return (const pStrA)(
				"LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Move:
			return (const pStrA)(
				"Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Pitch:
			return (const pStrA)(
				"Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Yaw:
			return (const pStrA)(
				"Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Roll:
			return (const pStrA)(
				"Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_PS4_X:
			return (const pStrA)(
				"PS4_X"
			);
			break;
		case k_EControllerActionOrigin_PS4_Circle:
			return (const pStrA)(
				"PS4_Circle"
			);
			break;
		case k_EControllerActionOrigin_PS4_Triangle:
			return (const pStrA)(
				"PS4_Triangle"
			);
			break;
		case k_EControllerActionOrigin_PS4_Square:
			return (const pStrA)(
				"PS4_Square"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftBumper:
			return (const pStrA)(
				"PS4_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightBumper:
			return (const pStrA)(
				"PS4_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_PS4_Options:
			return (const pStrA)(
				"PS4_Options"
			);
			break;
		case k_EControllerActionOrigin_PS4_Share:
			return (const pStrA)(
				"PS4_Share"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_Touch:
			return (const pStrA)(
				"PS4_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_Swipe:
			return (const pStrA)(
				"PS4_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_Click:
			return (const pStrA)(
				"PS4_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadNorth:
			return (const pStrA)(
				"PS4_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadSouth:
			return (const pStrA)(
				"PS4_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadWest:
			return (const pStrA)(
				"PS4_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadEast:
			return (const pStrA)(
				"PS4_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_Touch:
			return (const pStrA)(
				"PS4_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_Swipe:
			return (const pStrA)(
				"PS4_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_Click:
			return (const pStrA)(
				"PS4_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadNorth:
			return (const pStrA)(
				"PS4_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadSouth:
			return (const pStrA)(
				"PS4_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadWest:
			return (const pStrA)(
				"PS4_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadEast:
			return (const pStrA)(
				"PS4_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_Touch:
			return (const pStrA)(
				"PS4_CenterPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_Swipe:
			return (const pStrA)(
				"PS4_CenterPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_Click:
			return (const pStrA)(
				"PS4_CenterPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadNorth:
			return (const pStrA)(
				"PS4_CenterPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadSouth:
			return (const pStrA)(
				"PS4_CenterPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadWest:
			return (const pStrA)(
				"PS4_CenterPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadEast:
			return (const pStrA)(
				"PS4_CenterPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftTrigger_Pull:
			return (const pStrA)(
				"PS4_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftTrigger_Click:
			return (const pStrA)(
				"PS4_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightTrigger_Pull:
			return (const pStrA)(
				"PS4_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightTrigger_Click:
			return (const pStrA)(
				"PS4_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_Move:
			return (const pStrA)(
				"PS4_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_Click:
			return (const pStrA)(
				"PS4_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadNorth:
			return (const pStrA)(
				"PS4_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadSouth:
			return (const pStrA)(
				"PS4_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadWest:
			return (const pStrA)(
				"PS4_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadEast:
			return (const pStrA)(
				"PS4_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_Move:
			return (const pStrA)(
				"PS4_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_Click:
			return (const pStrA)(
				"PS4_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadNorth:
			return (const pStrA)(
				"PS4_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadSouth:
			return (const pStrA)(
				"PS4_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadWest:
			return (const pStrA)(
				"PS4_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadEast:
			return (const pStrA)(
				"PS4_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_North:
			return (const pStrA)(
				"PS4_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_South:
			return (const pStrA)(
				"PS4_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_West:
			return (const pStrA)(
				"PS4_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_East:
			return (const pStrA)(
				"PS4_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Move:
			return (const pStrA)(
				"PS4_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Pitch:
			return (const pStrA)(
				"PS4_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Yaw:
			return (const pStrA)(
				"PS4_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Roll:
			return (const pStrA)(
				"PS4_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_A:
			return (const pStrA)(
				"XBoxOne_A"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_B:
			return (const pStrA)(
				"XBoxOne_B"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_X:
			return (const pStrA)(
				"XBoxOne_X"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_Y:
			return (const pStrA)(
				"XBoxOne_Y"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftBumper:
			return (const pStrA)(
				"XBoxOne_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightBumper:
			return (const pStrA)(
				"XBoxOne_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_Menu:
			return (const pStrA)(
				"XBoxOne_Menu"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_View:
			return (const pStrA)(
				"XBoxOne_View"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftTrigger_Pull:
			return (const pStrA)(
				"XBoxOne_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftTrigger_Click:
			return (const pStrA)(
				"XBoxOne_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightTrigger_Pull:
			return (const pStrA)(
				"XBoxOne_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightTrigger_Click:
			return (const pStrA)(
				"XBoxOne_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_Move:
			return (const pStrA)(
				"XBoxOne_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_Click:
			return (const pStrA)(
				"XBoxOne_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadNorth:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadSouth:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadWest:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadEast:
			return (const pStrA)(
				"XBoxOne_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_Move:
			return (const pStrA)(
				"XBoxOne_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_Click:
			return (const pStrA)(
				"XBoxOne_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadNorth:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadSouth:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadWest:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadEast:
			return (const pStrA)(
				"XBoxOne_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_North:
			return (const pStrA)(
				"XBoxOne_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_South:
			return (const pStrA)(
				"XBoxOne_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_West:
			return (const pStrA)(
				"XBoxOne_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_East:
			return (const pStrA)(
				"XBoxOne_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_XBox360_A:
			return (const pStrA)(
				"XBox360_A"
			);
			break;
		case k_EControllerActionOrigin_XBox360_B:
			return (const pStrA)(
				"XBox360_B"
			);
			break;
		case k_EControllerActionOrigin_XBox360_X:
			return (const pStrA)(
				"XBox360_X"
			);
			break;
		case k_EControllerActionOrigin_XBox360_Y:
			return (const pStrA)(
				"XBox360_Y"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftBumper:
			return (const pStrA)(
				"XBox360_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightBumper:
			return (const pStrA)(
				"XBox360_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_XBox360_Start:
			return (const pStrA)(
				"XBox360_Start"
			);
			break;
		case k_EControllerActionOrigin_XBox360_Back:
			return (const pStrA)(
				"XBox360_Back"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftTrigger_Pull:
			return (const pStrA)(
				"XBox360_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftTrigger_Click:
			return (const pStrA)(
				"XBox360_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightTrigger_Pull:
			return (const pStrA)(
				"XBox360_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightTrigger_Click:
			return (const pStrA)(
				"XBox360_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_Move:
			return (const pStrA)(
				"XBox360_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_Click:
			return (const pStrA)(
				"XBox360_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadNorth:
			return (const pStrA)(
				"XBox360_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadSouth:
			return (const pStrA)(
				"XBox360_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadWest:
			return (const pStrA)(
				"XBox360_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadEast:
			return (const pStrA)(
				"XBox360_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_Move:
			return (const pStrA)(
				"XBox360_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_Click:
			return (const pStrA)(
				"XBox360_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadNorth:
			return (const pStrA)(
				"XBox360_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadSouth:
			return (const pStrA)(
				"XBox360_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadWest:
			return (const pStrA)(
				"XBox360_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadEast:
			return (const pStrA)(
				"XBox360_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_North:
			return (const pStrA)(
				"XBox360_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_South:
			return (const pStrA)(
				"XBox360_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_West:
			return (const pStrA)(
				"XBox360_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_East:
			return (const pStrA)(
				"XBox360_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_A:
			return (const pStrA)(
				"SteamV2_A"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_B:
			return (const pStrA)(
				"SteamV2_B"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_X:
			return (const pStrA)(
				"SteamV2_X"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Y:
			return (const pStrA)(
				"SteamV2_Y"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftBumper:
			return (const pStrA)(
				"SteamV2_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightBumper:
			return (const pStrA)(
				"SteamV2_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Lower:
			return (const pStrA)(
				"SteamV2_LeftGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Upper:
			return (const pStrA)(
				"SteamV2_LeftGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Lower:
			return (const pStrA)(
				"SteamV2_RightGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Upper:
			return (const pStrA)(
				"SteamV2_RightGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftBumper_Pressure:
			return (const pStrA)(
				"SteamV2_LeftBumper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightBumper_Pressure:
			return (const pStrA)(
				"SteamV2_RightBumper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Pressure:
			return (const pStrA)(
				"SteamV2_LeftGrip_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Pressure:
			return (const pStrA)(
				"SteamV2_RightGrip_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Upper_Pressure:
			return (const pStrA)(
				"SteamV2_LeftGrip_Upper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Upper_Pressure:
			return (const pStrA)(
				"SteamV2_RightGrip_Upper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Start:
			return (const pStrA)(
				"SteamV2_Start"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Back:
			return (const pStrA)(
				"SteamV2_Back"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Touch:
			return (const pStrA)(
				"SteamV2_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Swipe:
			return (const pStrA)(
				"SteamV2_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Click:
			return (const pStrA)(
				"SteamV2_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Pressure:
			return (const pStrA)(
				"SteamV2_LeftPad_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadNorth:
			return (const pStrA)(
				"SteamV2_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadSouth:
			return (const pStrA)(
				"SteamV2_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadWest:
			return (const pStrA)(
				"SteamV2_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadEast:
			return (const pStrA)(
				"SteamV2_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Touch:
			return (const pStrA)(
				"SteamV2_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Swipe:
			return (const pStrA)(
				"SteamV2_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Click:
			return (const pStrA)(
				"SteamV2_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Pressure:
			return (const pStrA)(
				"SteamV2_RightPad_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadNorth:
			return (const pStrA)(
				"SteamV2_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadSouth:
			return (const pStrA)(
				"SteamV2_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadWest:
			return (const pStrA)(
				"SteamV2_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadEast:
			return (const pStrA)(
				"SteamV2_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftTrigger_Pull:
			return (const pStrA)(
				"SteamV2_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftTrigger_Click:
			return (const pStrA)(
				"SteamV2_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightTrigger_Pull:
			return (const pStrA)(
				"SteamV2_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightTrigger_Click:
			return (const pStrA)(
				"SteamV2_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_Move:
			return (const pStrA)(
				"SteamV2_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_Click:
			return (const pStrA)(
				"SteamV2_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadNorth:
			return (const pStrA)(
				"SteamV2_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadSouth:
			return (const pStrA)(
				"SteamV2_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadWest:
			return (const pStrA)(
				"SteamV2_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadEast:
			return (const pStrA)(
				"SteamV2_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Move:
			return (const pStrA)(
				"SteamV2_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Pitch:
			return (const pStrA)(
				"SteamV2_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Yaw:
			return (const pStrA)(
				"SteamV2_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Roll:
			return (const pStrA)(
				"SteamV2_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_A:
			return (const pStrA)(
				"Switch_A"
			);
			break;
		case k_EControllerActionOrigin_Switch_B:
			return (const pStrA)(
				"Switch_B"
			);
			break;
		case k_EControllerActionOrigin_Switch_X:
			return (const pStrA)(
				"Switch_X"
			);
			break;
		case k_EControllerActionOrigin_Switch_Y:
			return (const pStrA)(
				"Switch_Y"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftBumper:
			return (const pStrA)(
				"Switch_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightBumper:
			return (const pStrA)(
				"Switch_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_Switch_Plus:
			return (const pStrA)(
				"Switch_Plus"
			);
			break;
		case k_EControllerActionOrigin_Switch_Minus:
			return (const pStrA)(
				"Switch_Minus"
			);
			break;
		case k_EControllerActionOrigin_Switch_Capture:
			return (const pStrA)(
				"Switch_Capture"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftTrigger_Pull:
			return (const pStrA)(
				"Switch_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftTrigger_Click:
			return (const pStrA)(
				"Switch_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightTrigger_Pull:
			return (const pStrA)(
				"Switch_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightTrigger_Click:
			return (const pStrA)(
				"Switch_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_Move:
			return (const pStrA)(
				"Switch_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_Click:
			return (const pStrA)(
				"Switch_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadNorth:
			return (const pStrA)(
				"Switch_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadSouth:
			return (const pStrA)(
				"Switch_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadWest:
			return (const pStrA)(
				"Switch_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadEast:
			return (const pStrA)(
				"Switch_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_Move:
			return (const pStrA)(
				"Switch_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_Click:
			return (const pStrA)(
				"Switch_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadNorth:
			return (const pStrA)(
				"Switch_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadSouth:
			return (const pStrA)(
				"Switch_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadWest:
			return (const pStrA)(
				"Switch_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadEast:
			return (const pStrA)(
				"Switch_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_North:
			return (const pStrA)(
				"Switch_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_South:
			return (const pStrA)(
				"Switch_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_West:
			return (const pStrA)(
				"Switch_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_East:
			return (const pStrA)(
				"Switch_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Move:
			return (const pStrA)(
				"Switch_ProGyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Pitch:
			return (const pStrA)(
				"Switch_ProGyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Yaw:
			return (const pStrA)(
				"Switch_ProGyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Roll:
			return (const pStrA)(
				"Switch_ProGyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Move:
			return (const pStrA)(
				"Switch_RightGyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Pitch:
			return (const pStrA)(
				"Switch_RightGyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Yaw:
			return (const pStrA)(
				"Switch_RightGyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Roll:
			return (const pStrA)(
				"Switch_RightGyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Move:
			return (const pStrA)(
				"Switch_LeftGyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Pitch:
			return (const pStrA)(
				"Switch_LeftGyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Yaw:
			return (const pStrA)(
				"Switch_LeftGyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Roll:
			return (const pStrA)(
				"Switch_LeftGyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGrip_Lower:
			return (const pStrA)(
				"Switch_LeftGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGrip_Upper:
			return (const pStrA)(
				"Switch_LeftGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGrip_Lower:
			return (const pStrA)(
				"Switch_RightGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGrip_Upper:
			return (const pStrA)(
				"Switch_RightGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_Move:
			return (const pStrA)(
				"PS4_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_Move:
			return (const pStrA)(
				"XBoxOne_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_Move:
			return (const pStrA)(
				"XBox360_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_Move:
			return (const pStrA)(
				"Switch_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_X:
			return (const pStrA)(
				"PS5_X"
			);
			break;
		case k_EControllerActionOrigin_PS5_Circle:
			return (const pStrA)(
				"PS5_Circle"
			);
			break;
		case k_EControllerActionOrigin_PS5_Triangle:
			return (const pStrA)(
				"PS5_Triangle"
			);
			break;
		case k_EControllerActionOrigin_PS5_Square:
			return (const pStrA)(
				"PS5_Square"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftBumper:
			return (const pStrA)(
				"PS5_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightBumper:
			return (const pStrA)(
				"PS5_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_PS5_Option:
			return (const pStrA)(
				"PS5_Option"
			);
			break;
		case k_EControllerActionOrigin_PS5_Create:
			return (const pStrA)(
				"PS5_Create"
			);
			break;
		case k_EControllerActionOrigin_PS5_Mute:
			return (const pStrA)(
				"PS5_Mute"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_Touch:
			return (const pStrA)(
				"PS5_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_Swipe:
			return (const pStrA)(
				"PS5_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_Click:
			return (const pStrA)(
				"PS5_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadNorth:
			return (const pStrA)(
				"PS5_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadSouth:
			return (const pStrA)(
				"PS5_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadWest:
			return (const pStrA)(
				"PS5_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadEast:
			return (const pStrA)(
				"PS5_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_Touch:
			return (const pStrA)(
				"PS5_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_Swipe:
			return (const pStrA)(
				"PS5_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_Click:
			return (const pStrA)(
				"PS5_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadNorth:
			return (const pStrA)(
				"PS5_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadSouth:
			return (const pStrA)(
				"PS5_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadWest:
			return (const pStrA)(
				"PS5_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadEast:
			return (const pStrA)(
				"PS5_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_Touch:
			return (const pStrA)(
				"PS5_CenterPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_Swipe:
			return (const pStrA)(
				"PS5_CenterPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_Click:
			return (const pStrA)(
				"PS5_CenterPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadNorth:
			return (const pStrA)(
				"PS5_CenterPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadSouth:
			return (const pStrA)(
				"PS5_CenterPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadWest:
			return (const pStrA)(
				"PS5_CenterPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadEast:
			return (const pStrA)(
				"PS5_CenterPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftTrigger_Pull:
			return (const pStrA)(
				"PS5_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftTrigger_Click:
			return (const pStrA)(
				"PS5_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightTrigger_Pull:
			return (const pStrA)(
				"PS5_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightTrigger_Click:
			return (const pStrA)(
				"PS5_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_Move:
			return (const pStrA)(
				"PS5_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_Click:
			return (const pStrA)(
				"PS5_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadNorth:
			return (const pStrA)(
				"PS5_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadSouth:
			return (const pStrA)(
				"PS5_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadWest:
			return (const pStrA)(
				"PS5_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadEast:
			return (const pStrA)(
				"PS5_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_Move:
			return (const pStrA)(
				"PS5_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_Click:
			return (const pStrA)(
				"PS5_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadNorth:
			return (const pStrA)(
				"PS5_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadSouth:
			return (const pStrA)(
				"PS5_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadWest:
			return (const pStrA)(
				"PS5_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadEast:
			return (const pStrA)(
				"PS5_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_Move:
			return (const pStrA)(
				"PS5_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_North:
			return (const pStrA)(
				"PS5_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_South:
			return (const pStrA)(
				"PS5_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_West:
			return (const pStrA)(
				"PS5_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_East:
			return (const pStrA)(
				"PS5_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Move:
			return (const pStrA)(
				"PS5_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Pitch:
			return (const pStrA)(
				"PS5_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Yaw:
			return (const pStrA)(
				"PS5_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Roll:
			return (const pStrA)(
				"PS5_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftGrip_Lower:
			return (const pStrA)(
				"XBoxOne_LeftGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftGrip_Upper:
			return (const pStrA)(
				"XBoxOne_LeftGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightGrip_Lower:
			return (const pStrA)(
				"XBoxOne_RightGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightGrip_Upper:
			return (const pStrA)(
				"XBoxOne_RightGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_Share:
			return (const pStrA)(
				"XBoxOne_Share"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_A:
			return (const pStrA)(
				"SteamDeck_A"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_B:
			return (const pStrA)(
				"SteamDeck_B"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_X:
			return (const pStrA)(
				"SteamDeck_X"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Y:
			return (const pStrA)(
				"SteamDeck_Y"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L1:
			return (const pStrA)(
				"SteamDeck_L1"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R1:
			return (const pStrA)(
				"SteamDeck_R1"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Menu:
			return (const pStrA)(
				"SteamDeck_Menu"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_View:
			return (const pStrA)(
				"SteamDeck_View"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_Touch:
			return (const pStrA)(
				"SteamDeck_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_Swipe:
			return (const pStrA)(
				"SteamDeck_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_Click:
			return (const pStrA)(
				"SteamDeck_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadNorth:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadSouth:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadWest:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadEast:
			return (const pStrA)(
				"SteamDeck_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_Touch:
			return (const pStrA)(
				"SteamDeck_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_Swipe:
			return (const pStrA)(
				"SteamDeck_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_Click:
			return (const pStrA)(
				"SteamDeck_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadNorth:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadSouth:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadWest:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadEast:
			return (const pStrA)(
				"SteamDeck_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L2_SoftPull:
			return (const pStrA)(
				"SteamDeck_L2_SoftPull"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L2:
			return (const pStrA)(
				"SteamDeck_L2"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R2_SoftPull:
			return (const pStrA)(
				"SteamDeck_R2_SoftPull"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R2:
			return (const pStrA)(
				"SteamDeck_R2"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_Move:
			return (const pStrA)(
				"SteamDeck_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L3:
			return (const pStrA)(
				"SteamDeck_L3"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadNorth:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadSouth:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadWest:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadEast:
			return (const pStrA)(
				"SteamDeck_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_Touch:
			return (const pStrA)(
				"SteamDeck_LeftStick_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_Move:
			return (const pStrA)(
				"SteamDeck_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R3:
			return (const pStrA)(
				"SteamDeck_R3"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadNorth:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadSouth:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadWest:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadEast:
			return (const pStrA)(
				"SteamDeck_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_Touch:
			return (const pStrA)(
				"SteamDeck_RightStick_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L4:
			return (const pStrA)(
				"SteamDeck_L4"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R4:
			return (const pStrA)(
				"SteamDeck_R4"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L5:
			return (const pStrA)(
				"SteamDeck_L5"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R5:
			return (const pStrA)(
				"SteamDeck_R5"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_Move:
			return (const pStrA)(
				"SteamDeck_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_North:
			return (const pStrA)(
				"SteamDeck_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_South:
			return (const pStrA)(
				"SteamDeck_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_West:
			return (const pStrA)(
				"SteamDeck_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_East:
			return (const pStrA)(
				"SteamDeck_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Move:
			return (const pStrA)(
				"SteamDeck_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Pitch:
			return (const pStrA)(
				"SteamDeck_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Yaw:
			return (const pStrA)(
				"SteamDeck_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Roll:
			return (const pStrA)(
				"SteamDeck_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved1:
			return (const pStrA)(
				"SteamDeck_Reserved1"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved2:
			return (const pStrA)(
				"SteamDeck_Reserved2"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved3:
			return (const pStrA)(
				"SteamDeck_Reserved3"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved4:
			return (const pStrA)(
				"SteamDeck_Reserved4"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved5:
			return (const pStrA)(
				"SteamDeck_Reserved5"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved6:
			return (const pStrA)(
				"SteamDeck_Reserved6"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved7:
			return (const pStrA)(
				"SteamDeck_Reserved7"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved8:
			return (const pStrA)(
				"SteamDeck_Reserved8"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved9:
			return (const pStrA)(
				"SteamDeck_Reserved9"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved10:
			return (const pStrA)(
				"SteamDeck_Reserved10"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved11:
			return (const pStrA)(
				"SteamDeck_Reserved11"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved12:
			return (const pStrA)(
				"SteamDeck_Reserved12"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved13:
			return (const pStrA)(
				"SteamDeck_Reserved13"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved14:
			return (const pStrA)(
				"SteamDeck_Reserved14"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved15:
			return (const pStrA)(
				"SteamDeck_Reserved15"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved16:
			return (const pStrA)(
				"SteamDeck_Reserved16"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved17:
			return (const pStrA)(
				"SteamDeck_Reserved17"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved18:
			return (const pStrA)(
				"SteamDeck_Reserved18"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved19:
			return (const pStrA)(
				"SteamDeck_Reserved19"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved20:
			return (const pStrA)(
				"SteamDeck_Reserved20"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_N:
			return (const pStrA)(
				"Switch_JoyConButton_N"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_E:
			return (const pStrA)(
				"Switch_JoyConButton_E"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_S:
			return (const pStrA)(
				"Switch_JoyConButton_S"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_W:
			return (const pStrA)(
				"Switch_JoyConButton_W"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftGrip:
			return (const pStrA)(
				"PS5_LeftGrip"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightGrip:
			return (const pStrA)(
				"PS5_RightGrip"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftFn:
			return (const pStrA)(
				"PS5_LeftFn"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightFn:
			return (const pStrA)(
				"PS5_RightFn"
			);
			break;
	}

	return (const pStrA)(
		""
	);

}

const pStrA _SteamController_::GetStringForActionOrigin(EControllerActionOrigin eControllerActionOrigin) {

	return this->GetGlyphForActionOrigin(eControllerActionOrigin);

}

void _SteamController_::StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) {

	/* Empty Method */

}

ControllerMotionData_t _SteamController_::GetMotionData(ControllerHandle_t hController) {

	ControllerMotionData_t controllerMotionData;

	controllerMotionData.posAccelX = 0.0F;
	controllerMotionData.posAccelY = 0.0F;
	controllerMotionData.posAccelZ = 0.0F;

	controllerMotionData.rotQuatW = 0.0F;
	controllerMotionData.rotQuatX = 0.0F;
	controllerMotionData.rotQuatY = 0.0F;
	controllerMotionData.rotQuatZ = 0.0F;

	controllerMotionData.rotVelX = 0.0F;
	controllerMotionData.rotVelY = 0.0F;
	controllerMotionData.rotVelZ = 0.0F;

	return controllerMotionData;

}

void _SteamController_::TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) {

	/* Empty Method */

}

void _SteamController_::TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) {

	/* Empty Method */

}

void _SteamController_::TriggerVibration(ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) {

	/* Empty Method */

}

void _SteamController_::SetLEDColor(ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) {

	/* Empty Method */

}

Bool _SteamController_::ShowBindingPanel(ControllerHandle_t hController) {

	return True;

}

ESteamInputType _SteamController_::GetInputTypeForHandle(ControllerHandle_t hController) {

	return k_ESteamInputType_Unknown;

}

ControllerHandle_t _SteamController_::GetControllerForGamepadIndex(Int32 iController) {

	return (ControllerHandle_t)(0x0000000000000000);

}

Int32 _SteamController_::GetGamepadIndexForController(ControllerHandle_t hController) {

	return 0;

}

const pStrA _SteamController_::GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) {

	return this->GetGlyphForXboxOrigin(eXboxOrigin);

}

const pStrA _SteamController_::GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) {

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

EControllerActionOrigin _SteamController_::GetActionOriginFromXboxOrigin_(ControllerHandle_t hController, EXboxOrigin eXboxOrigin) {

	return k_EControllerActionOrigin_None;

}

EControllerActionOrigin _SteamController_::TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin) {

	return k_EControllerActionOrigin_None;

}

Bool _SteamController_::GetControllerBindingRevision(ControllerHandle_t hController, pInt32 pMajor, pInt32 pMinor) {

	if (pMajor != NULL) {
		*pMajor = 0;
	}

	if (pMinor != NULL) {
		*pMinor = 0;
	}

	return False;

}
