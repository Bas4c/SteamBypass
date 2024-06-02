// -----------------------------------------------------------------------------
#include "SteamController.h"
// -----------------------------------------------------------------------------

Bool _SteamController_::Init(pCStrA pchAbsolutePathToControllerConfigVDF) {
	DEBUGBREAK("ISteamController::Init");

	return True;

}

Bool _SteamController_::Init() {
	DEBUGBREAK("ISteamController::Init");

	return True;

}

Bool _SteamController_::Shutdown() {
	DEBUGBREAK("ISteamController::Shutdown");

	return True;

}

void _SteamController_::RunFrame() {
	DEBUGBREAK("ISteamController::RunFrame");

	/* Empty Method */

}

Int32 _SteamController_::GetConnectedControllers(pControllerHandle_t phController) {
	DEBUGBREAK("ISteamController::GetConnectedControllers");

	return 0;

}

ControllerActionSetHandle_t _SteamController_::GetActionSetHandle(pCStrA pchActionSetName) {
	DEBUGBREAK("ISteamController::GetActionSetHandle");

	return (ControllerActionSetHandle_t)(0xFFFFFFFFFFFFFFFF);

}

void _SteamController_::ActivateActionSet(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet) {
	DEBUGBREAK("ISteamController::ActivateActionSet");

	/* Empty Method */

}

ControllerActionSetHandle_t _SteamController_::GetCurrentActionSet(ControllerHandle_t hController) {
	DEBUGBREAK("ISteamController::GetCurrentActionSet");

	return (ControllerActionSetHandle_t)(0xFFFFFFFFFFFFFFFF);

}

void _SteamController_::ActivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("ISteamController::ActivateActionSetLayer");

	/* Empty Method */

}

void _SteamController_::DeactivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) {
	DEBUGBREAK("ISteamController::DeactivateActionSetLayer");

	/* Empty Method */

}

void _SteamController_::DeactivateAllActionSetLayers(ControllerHandle_t hController) {
	DEBUGBREAK("ISteamController::DeactivateAllActionSetLayers");

	/* Empty Method */

}

Int32 _SteamController_::GetActiveActionSetLayers(ControllerHandle_t hController, pControllerActionSetHandle_t phActionSetLayer) {
	DEBUGBREAK("ISteamController::GetActiveActionSetLayers");

	return 0;

}

ControllerDigitalActionHandle_t _SteamController_::GetDigitalActionHandle(pCStrA pchActionName) {
	DEBUGBREAK("ISteamController::GetDigitalActionHandle");

	return (ControllerDigitalActionHandle_t)(0x0000000000000000);

}

ControllerDigitalActionData_t _SteamController_::GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) {
	DEBUGBREAK("ISteamController::GetDigitalActionData");

	ControllerDigitalActionData_t controllerDigitalActionData{};
	controllerDigitalActionData.bActive = False;
	controllerDigitalActionData.bState = False;

	return controllerDigitalActionData;

}

Int32 _SteamController_::GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) {
	DEBUGBREAK("ISteamController::GetDigitalActionOrigins");

	return 0;

}

ControllerAnalogActionHandle_t _SteamController_::GetAnalogActionHandle(pCStrA pchActionName) {
	DEBUGBREAK("ISteamController::GetAnalogActionHandle");

	return (ControllerAnalogActionHandle_t)(0x0000000000000000);

}

ControllerAnalogActionData_t _SteamController_::GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("ISteamController::GetAnalogActionData");

	ControllerAnalogActionData_t controllerAnalogActionData{};
	controllerAnalogActionData.bActive = False;
	controllerAnalogActionData.eInputSourceMode = k_EInputSourceMode_None;
	controllerAnalogActionData.x = 0.0F;
	controllerAnalogActionData.y = 0.0F;

	return controllerAnalogActionData;

}

Int32 _SteamController_::GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) {
	DEBUGBREAK("ISteamController::GetAnalogActionOrigins");

	return 0;

}

pCStrA _SteamController_::GetGlyphForActionOrigin(EControllerActionOrigin eControllerActionOrigin) {
	DEBUGBREAK("ISteamController::GetGlyphForActionOrigin");

	switch (eControllerActionOrigin) {
		case k_EControllerActionOrigin_A:
			return (pCStrA)(
				"A"
			);
			break;
		case k_EControllerActionOrigin_B:
			return (pCStrA)(
				"B"
			);
			break;
		case k_EControllerActionOrigin_X:
			return (pCStrA)(
				"X"
			);
			break;
		case k_EControllerActionOrigin_Y:
			return (pCStrA)(
				"Y"
			);
			break;
		case k_EControllerActionOrigin_LeftBumper:
			return (pCStrA)(
				"LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_RightBumper:
			return (pCStrA)(
				"RightBumper"
			);
			break;
		case k_EControllerActionOrigin_LeftGrip:
			return (pCStrA)(
				"LeftGrip"
			);
			break;
		case k_EControllerActionOrigin_RightGrip:
			return (pCStrA)(
				"RightGrip"
			);
			break;
		case k_EControllerActionOrigin_Start:
			return (pCStrA)(
				"Start"
			);
			break;
		case k_EControllerActionOrigin_Back:
			return (pCStrA)(
				"Back"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_Touch:
			return (pCStrA)(
				"LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_Swipe:
			return (pCStrA)(
				"LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_Click:
			return (pCStrA)(
				"LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadNorth:
			return (pCStrA)(
				"LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadSouth:
			return (pCStrA)(
				"LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadWest:
			return (pCStrA)(
				"LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_LeftPad_DPadEast:
			return (pCStrA)(
				"LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_RightPad_Touch:
			return (pCStrA)(
				"RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_RightPad_Swipe:
			return (pCStrA)(
				"RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_RightPad_Click:
			return (pCStrA)(
				"RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadNorth:
			return (pCStrA)(
				"RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadSouth:
			return (pCStrA)(
				"RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadWest:
			return (pCStrA)(
				"RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_RightPad_DPadEast:
			return (pCStrA)(
				"RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_LeftTrigger_Pull:
			return (pCStrA)(
				"LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_LeftTrigger_Click:
			return (pCStrA)(
				"LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_RightTrigger_Pull:
			return (pCStrA)(
				"RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_RightTrigger_Click:
			return (pCStrA)(
				"RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_Move:
			return (pCStrA)(
				"LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_Click:
			return (pCStrA)(
				"LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadNorth:
			return (pCStrA)(
				"LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadSouth:
			return (pCStrA)(
				"LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadWest:
			return (pCStrA)(
				"LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_LeftStick_DPadEast:
			return (pCStrA)(
				"LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Move:
			return (pCStrA)(
				"Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Pitch:
			return (pCStrA)(
				"Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Yaw:
			return (pCStrA)(
				"Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Gyro_Roll:
			return (pCStrA)(
				"Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_PS4_X:
			return (pCStrA)(
				"PS4_X"
			);
			break;
		case k_EControllerActionOrigin_PS4_Circle:
			return (pCStrA)(
				"PS4_Circle"
			);
			break;
		case k_EControllerActionOrigin_PS4_Triangle:
			return (pCStrA)(
				"PS4_Triangle"
			);
			break;
		case k_EControllerActionOrigin_PS4_Square:
			return (pCStrA)(
				"PS4_Square"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftBumper:
			return (pCStrA)(
				"PS4_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightBumper:
			return (pCStrA)(
				"PS4_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_PS4_Options:
			return (pCStrA)(
				"PS4_Options"
			);
			break;
		case k_EControllerActionOrigin_PS4_Share:
			return (pCStrA)(
				"PS4_Share"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_Touch:
			return (pCStrA)(
				"PS4_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_Swipe:
			return (pCStrA)(
				"PS4_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_Click:
			return (pCStrA)(
				"PS4_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadNorth:
			return (pCStrA)(
				"PS4_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadSouth:
			return (pCStrA)(
				"PS4_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadWest:
			return (pCStrA)(
				"PS4_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftPad_DPadEast:
			return (pCStrA)(
				"PS4_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_Touch:
			return (pCStrA)(
				"PS4_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_Swipe:
			return (pCStrA)(
				"PS4_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_Click:
			return (pCStrA)(
				"PS4_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadNorth:
			return (pCStrA)(
				"PS4_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadSouth:
			return (pCStrA)(
				"PS4_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadWest:
			return (pCStrA)(
				"PS4_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightPad_DPadEast:
			return (pCStrA)(
				"PS4_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_Touch:
			return (pCStrA)(
				"PS4_CenterPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_Swipe:
			return (pCStrA)(
				"PS4_CenterPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_Click:
			return (pCStrA)(
				"PS4_CenterPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadNorth:
			return (pCStrA)(
				"PS4_CenterPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadSouth:
			return (pCStrA)(
				"PS4_CenterPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadWest:
			return (pCStrA)(
				"PS4_CenterPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_CenterPad_DPadEast:
			return (pCStrA)(
				"PS4_CenterPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftTrigger_Pull:
			return (pCStrA)(
				"PS4_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftTrigger_Click:
			return (pCStrA)(
				"PS4_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightTrigger_Pull:
			return (pCStrA)(
				"PS4_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightTrigger_Click:
			return (pCStrA)(
				"PS4_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_Move:
			return (pCStrA)(
				"PS4_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_Click:
			return (pCStrA)(
				"PS4_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadNorth:
			return (pCStrA)(
				"PS4_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadSouth:
			return (pCStrA)(
				"PS4_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadWest:
			return (pCStrA)(
				"PS4_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_LeftStick_DPadEast:
			return (pCStrA)(
				"PS4_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_Move:
			return (pCStrA)(
				"PS4_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_Click:
			return (pCStrA)(
				"PS4_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadNorth:
			return (pCStrA)(
				"PS4_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadSouth:
			return (pCStrA)(
				"PS4_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadWest:
			return (pCStrA)(
				"PS4_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS4_RightStick_DPadEast:
			return (pCStrA)(
				"PS4_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_North:
			return (pCStrA)(
				"PS4_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_South:
			return (pCStrA)(
				"PS4_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_West:
			return (pCStrA)(
				"PS4_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_East:
			return (pCStrA)(
				"PS4_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Move:
			return (pCStrA)(
				"PS4_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Pitch:
			return (pCStrA)(
				"PS4_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Yaw:
			return (pCStrA)(
				"PS4_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_PS4_Gyro_Roll:
			return (pCStrA)(
				"PS4_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_A:
			return (pCStrA)(
				"XBoxOne_A"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_B:
			return (pCStrA)(
				"XBoxOne_B"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_X:
			return (pCStrA)(
				"XBoxOne_X"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_Y:
			return (pCStrA)(
				"XBoxOne_Y"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftBumper:
			return (pCStrA)(
				"XBoxOne_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightBumper:
			return (pCStrA)(
				"XBoxOne_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_Menu:
			return (pCStrA)(
				"XBoxOne_Menu"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_View:
			return (pCStrA)(
				"XBoxOne_View"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftTrigger_Pull:
			return (pCStrA)(
				"XBoxOne_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftTrigger_Click:
			return (pCStrA)(
				"XBoxOne_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightTrigger_Pull:
			return (pCStrA)(
				"XBoxOne_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightTrigger_Click:
			return (pCStrA)(
				"XBoxOne_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_Move:
			return (pCStrA)(
				"XBoxOne_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_Click:
			return (pCStrA)(
				"XBoxOne_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadNorth:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadSouth:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadWest:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftStick_DPadEast:
			return (pCStrA)(
				"XBoxOne_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_Move:
			return (pCStrA)(
				"XBoxOne_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_Click:
			return (pCStrA)(
				"XBoxOne_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadNorth:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadSouth:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadWest:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightStick_DPadEast:
			return (pCStrA)(
				"XBoxOne_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_North:
			return (pCStrA)(
				"XBoxOne_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_South:
			return (pCStrA)(
				"XBoxOne_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_West:
			return (pCStrA)(
				"XBoxOne_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_East:
			return (pCStrA)(
				"XBoxOne_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_XBox360_A:
			return (pCStrA)(
				"XBox360_A"
			);
			break;
		case k_EControllerActionOrigin_XBox360_B:
			return (pCStrA)(
				"XBox360_B"
			);
			break;
		case k_EControllerActionOrigin_XBox360_X:
			return (pCStrA)(
				"XBox360_X"
			);
			break;
		case k_EControllerActionOrigin_XBox360_Y:
			return (pCStrA)(
				"XBox360_Y"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftBumper:
			return (pCStrA)(
				"XBox360_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightBumper:
			return (pCStrA)(
				"XBox360_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_XBox360_Start:
			return (pCStrA)(
				"XBox360_Start"
			);
			break;
		case k_EControllerActionOrigin_XBox360_Back:
			return (pCStrA)(
				"XBox360_Back"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftTrigger_Pull:
			return (pCStrA)(
				"XBox360_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftTrigger_Click:
			return (pCStrA)(
				"XBox360_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightTrigger_Pull:
			return (pCStrA)(
				"XBox360_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightTrigger_Click:
			return (pCStrA)(
				"XBox360_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_Move:
			return (pCStrA)(
				"XBox360_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_Click:
			return (pCStrA)(
				"XBox360_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadNorth:
			return (pCStrA)(
				"XBox360_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadSouth:
			return (pCStrA)(
				"XBox360_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadWest:
			return (pCStrA)(
				"XBox360_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBox360_LeftStick_DPadEast:
			return (pCStrA)(
				"XBox360_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_Move:
			return (pCStrA)(
				"XBox360_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_Click:
			return (pCStrA)(
				"XBox360_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadNorth:
			return (pCStrA)(
				"XBox360_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadSouth:
			return (pCStrA)(
				"XBox360_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadWest:
			return (pCStrA)(
				"XBox360_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_XBox360_RightStick_DPadEast:
			return (pCStrA)(
				"XBox360_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_North:
			return (pCStrA)(
				"XBox360_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_South:
			return (pCStrA)(
				"XBox360_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_West:
			return (pCStrA)(
				"XBox360_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_East:
			return (pCStrA)(
				"XBox360_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_A:
			return (pCStrA)(
				"SteamV2_A"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_B:
			return (pCStrA)(
				"SteamV2_B"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_X:
			return (pCStrA)(
				"SteamV2_X"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Y:
			return (pCStrA)(
				"SteamV2_Y"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftBumper:
			return (pCStrA)(
				"SteamV2_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightBumper:
			return (pCStrA)(
				"SteamV2_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Lower:
			return (pCStrA)(
				"SteamV2_LeftGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Upper:
			return (pCStrA)(
				"SteamV2_LeftGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Lower:
			return (pCStrA)(
				"SteamV2_RightGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Upper:
			return (pCStrA)(
				"SteamV2_RightGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftBumper_Pressure:
			return (pCStrA)(
				"SteamV2_LeftBumper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightBumper_Pressure:
			return (pCStrA)(
				"SteamV2_RightBumper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Pressure:
			return (pCStrA)(
				"SteamV2_LeftGrip_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Pressure:
			return (pCStrA)(
				"SteamV2_RightGrip_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftGrip_Upper_Pressure:
			return (pCStrA)(
				"SteamV2_LeftGrip_Upper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightGrip_Upper_Pressure:
			return (pCStrA)(
				"SteamV2_RightGrip_Upper_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Start:
			return (pCStrA)(
				"SteamV2_Start"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Back:
			return (pCStrA)(
				"SteamV2_Back"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Touch:
			return (pCStrA)(
				"SteamV2_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Swipe:
			return (pCStrA)(
				"SteamV2_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Click:
			return (pCStrA)(
				"SteamV2_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_Pressure:
			return (pCStrA)(
				"SteamV2_LeftPad_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadNorth:
			return (pCStrA)(
				"SteamV2_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadSouth:
			return (pCStrA)(
				"SteamV2_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadWest:
			return (pCStrA)(
				"SteamV2_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftPad_DPadEast:
			return (pCStrA)(
				"SteamV2_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Touch:
			return (pCStrA)(
				"SteamV2_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Swipe:
			return (pCStrA)(
				"SteamV2_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Click:
			return (pCStrA)(
				"SteamV2_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_Pressure:
			return (pCStrA)(
				"SteamV2_RightPad_Pressure"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadNorth:
			return (pCStrA)(
				"SteamV2_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadSouth:
			return (pCStrA)(
				"SteamV2_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadWest:
			return (pCStrA)(
				"SteamV2_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightPad_DPadEast:
			return (pCStrA)(
				"SteamV2_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftTrigger_Pull:
			return (pCStrA)(
				"SteamV2_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftTrigger_Click:
			return (pCStrA)(
				"SteamV2_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightTrigger_Pull:
			return (pCStrA)(
				"SteamV2_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_RightTrigger_Click:
			return (pCStrA)(
				"SteamV2_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_Move:
			return (pCStrA)(
				"SteamV2_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_Click:
			return (pCStrA)(
				"SteamV2_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadNorth:
			return (pCStrA)(
				"SteamV2_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadSouth:
			return (pCStrA)(
				"SteamV2_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadWest:
			return (pCStrA)(
				"SteamV2_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_LeftStick_DPadEast:
			return (pCStrA)(
				"SteamV2_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Move:
			return (pCStrA)(
				"SteamV2_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Pitch:
			return (pCStrA)(
				"SteamV2_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Yaw:
			return (pCStrA)(
				"SteamV2_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_SteamV2_Gyro_Roll:
			return (pCStrA)(
				"SteamV2_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_A:
			return (pCStrA)(
				"Switch_A"
			);
			break;
		case k_EControllerActionOrigin_Switch_B:
			return (pCStrA)(
				"Switch_B"
			);
			break;
		case k_EControllerActionOrigin_Switch_X:
			return (pCStrA)(
				"Switch_X"
			);
			break;
		case k_EControllerActionOrigin_Switch_Y:
			return (pCStrA)(
				"Switch_Y"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftBumper:
			return (pCStrA)(
				"Switch_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightBumper:
			return (pCStrA)(
				"Switch_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_Switch_Plus:
			return (pCStrA)(
				"Switch_Plus"
			);
			break;
		case k_EControllerActionOrigin_Switch_Minus:
			return (pCStrA)(
				"Switch_Minus"
			);
			break;
		case k_EControllerActionOrigin_Switch_Capture:
			return (pCStrA)(
				"Switch_Capture"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftTrigger_Pull:
			return (pCStrA)(
				"Switch_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftTrigger_Click:
			return (pCStrA)(
				"Switch_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightTrigger_Pull:
			return (pCStrA)(
				"Switch_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightTrigger_Click:
			return (pCStrA)(
				"Switch_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_Move:
			return (pCStrA)(
				"Switch_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_Click:
			return (pCStrA)(
				"Switch_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadNorth:
			return (pCStrA)(
				"Switch_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadSouth:
			return (pCStrA)(
				"Switch_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadWest:
			return (pCStrA)(
				"Switch_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftStick_DPadEast:
			return (pCStrA)(
				"Switch_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_Move:
			return (pCStrA)(
				"Switch_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_Click:
			return (pCStrA)(
				"Switch_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadNorth:
			return (pCStrA)(
				"Switch_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadSouth:
			return (pCStrA)(
				"Switch_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadWest:
			return (pCStrA)(
				"Switch_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightStick_DPadEast:
			return (pCStrA)(
				"Switch_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_North:
			return (pCStrA)(
				"Switch_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_South:
			return (pCStrA)(
				"Switch_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_West:
			return (pCStrA)(
				"Switch_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_East:
			return (pCStrA)(
				"Switch_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Move:
			return (pCStrA)(
				"Switch_ProGyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Pitch:
			return (pCStrA)(
				"Switch_ProGyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Yaw:
			return (pCStrA)(
				"Switch_ProGyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Switch_ProGyro_Roll:
			return (pCStrA)(
				"Switch_ProGyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Move:
			return (pCStrA)(
				"Switch_RightGyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Pitch:
			return (pCStrA)(
				"Switch_RightGyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Yaw:
			return (pCStrA)(
				"Switch_RightGyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGyro_Roll:
			return (pCStrA)(
				"Switch_RightGyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Move:
			return (pCStrA)(
				"Switch_LeftGyro_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Pitch:
			return (pCStrA)(
				"Switch_LeftGyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Yaw:
			return (pCStrA)(
				"Switch_LeftGyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGyro_Roll:
			return (pCStrA)(
				"Switch_LeftGyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGrip_Lower:
			return (pCStrA)(
				"Switch_LeftGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_Switch_LeftGrip_Upper:
			return (pCStrA)(
				"Switch_LeftGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGrip_Lower:
			return (pCStrA)(
				"Switch_RightGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_Switch_RightGrip_Upper:
			return (pCStrA)(
				"Switch_RightGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_PS4_DPad_Move:
			return (pCStrA)(
				"PS4_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_DPad_Move:
			return (pCStrA)(
				"XBoxOne_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_XBox360_DPad_Move:
			return (pCStrA)(
				"XBox360_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_Switch_DPad_Move:
			return (pCStrA)(
				"Switch_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_X:
			return (pCStrA)(
				"PS5_X"
			);
			break;
		case k_EControllerActionOrigin_PS5_Circle:
			return (pCStrA)(
				"PS5_Circle"
			);
			break;
		case k_EControllerActionOrigin_PS5_Triangle:
			return (pCStrA)(
				"PS5_Triangle"
			);
			break;
		case k_EControllerActionOrigin_PS5_Square:
			return (pCStrA)(
				"PS5_Square"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftBumper:
			return (pCStrA)(
				"PS5_LeftBumper"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightBumper:
			return (pCStrA)(
				"PS5_RightBumper"
			);
			break;
		case k_EControllerActionOrigin_PS5_Option:
			return (pCStrA)(
				"PS5_Option"
			);
			break;
		case k_EControllerActionOrigin_PS5_Create:
			return (pCStrA)(
				"PS5_Create"
			);
			break;
		case k_EControllerActionOrigin_PS5_Mute:
			return (pCStrA)(
				"PS5_Mute"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_Touch:
			return (pCStrA)(
				"PS5_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_Swipe:
			return (pCStrA)(
				"PS5_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_Click:
			return (pCStrA)(
				"PS5_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadNorth:
			return (pCStrA)(
				"PS5_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadSouth:
			return (pCStrA)(
				"PS5_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadWest:
			return (pCStrA)(
				"PS5_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftPad_DPadEast:
			return (pCStrA)(
				"PS5_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_Touch:
			return (pCStrA)(
				"PS5_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_Swipe:
			return (pCStrA)(
				"PS5_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_Click:
			return (pCStrA)(
				"PS5_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadNorth:
			return (pCStrA)(
				"PS5_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadSouth:
			return (pCStrA)(
				"PS5_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadWest:
			return (pCStrA)(
				"PS5_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightPad_DPadEast:
			return (pCStrA)(
				"PS5_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_Touch:
			return (pCStrA)(
				"PS5_CenterPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_Swipe:
			return (pCStrA)(
				"PS5_CenterPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_Click:
			return (pCStrA)(
				"PS5_CenterPad_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadNorth:
			return (pCStrA)(
				"PS5_CenterPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadSouth:
			return (pCStrA)(
				"PS5_CenterPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadWest:
			return (pCStrA)(
				"PS5_CenterPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_CenterPad_DPadEast:
			return (pCStrA)(
				"PS5_CenterPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftTrigger_Pull:
			return (pCStrA)(
				"PS5_LeftTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftTrigger_Click:
			return (pCStrA)(
				"PS5_LeftTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightTrigger_Pull:
			return (pCStrA)(
				"PS5_RightTrigger_Pull"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightTrigger_Click:
			return (pCStrA)(
				"PS5_RightTrigger_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_Move:
			return (pCStrA)(
				"PS5_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_Click:
			return (pCStrA)(
				"PS5_LeftStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadNorth:
			return (pCStrA)(
				"PS5_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadSouth:
			return (pCStrA)(
				"PS5_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadWest:
			return (pCStrA)(
				"PS5_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftStick_DPadEast:
			return (pCStrA)(
				"PS5_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_Move:
			return (pCStrA)(
				"PS5_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_Click:
			return (pCStrA)(
				"PS5_RightStick_Click"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadNorth:
			return (pCStrA)(
				"PS5_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadSouth:
			return (pCStrA)(
				"PS5_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadWest:
			return (pCStrA)(
				"PS5_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightStick_DPadEast:
			return (pCStrA)(
				"PS5_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_Move:
			return (pCStrA)(
				"PS5_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_North:
			return (pCStrA)(
				"PS5_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_South:
			return (pCStrA)(
				"PS5_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_West:
			return (pCStrA)(
				"PS5_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_PS5_DPad_East:
			return (pCStrA)(
				"PS5_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Move:
			return (pCStrA)(
				"PS5_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Pitch:
			return (pCStrA)(
				"PS5_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Yaw:
			return (pCStrA)(
				"PS5_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_PS5_Gyro_Roll:
			return (pCStrA)(
				"PS5_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftGrip_Lower:
			return (pCStrA)(
				"XBoxOne_LeftGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_LeftGrip_Upper:
			return (pCStrA)(
				"XBoxOne_LeftGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightGrip_Lower:
			return (pCStrA)(
				"XBoxOne_RightGrip_Lower"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_RightGrip_Upper:
			return (pCStrA)(
				"XBoxOne_RightGrip_Upper"
			);
			break;
		case k_EControllerActionOrigin_XBoxOne_Share:
			return (pCStrA)(
				"XBoxOne_Share"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_A:
			return (pCStrA)(
				"SteamDeck_A"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_B:
			return (pCStrA)(
				"SteamDeck_B"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_X:
			return (pCStrA)(
				"SteamDeck_X"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Y:
			return (pCStrA)(
				"SteamDeck_Y"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L1:
			return (pCStrA)(
				"SteamDeck_L1"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R1:
			return (pCStrA)(
				"SteamDeck_R1"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Menu:
			return (pCStrA)(
				"SteamDeck_Menu"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_View:
			return (pCStrA)(
				"SteamDeck_View"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_Touch:
			return (pCStrA)(
				"SteamDeck_LeftPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_Swipe:
			return (pCStrA)(
				"SteamDeck_LeftPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_Click:
			return (pCStrA)(
				"SteamDeck_LeftPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadNorth:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadSouth:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadWest:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftPad_DPadEast:
			return (pCStrA)(
				"SteamDeck_LeftPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_Touch:
			return (pCStrA)(
				"SteamDeck_RightPad_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_Swipe:
			return (pCStrA)(
				"SteamDeck_RightPad_Swipe"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_Click:
			return (pCStrA)(
				"SteamDeck_RightPad_Click"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadNorth:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadSouth:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadWest:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightPad_DPadEast:
			return (pCStrA)(
				"SteamDeck_RightPad_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L2_SoftPull:
			return (pCStrA)(
				"SteamDeck_L2_SoftPull"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L2:
			return (pCStrA)(
				"SteamDeck_L2"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R2_SoftPull:
			return (pCStrA)(
				"SteamDeck_R2_SoftPull"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R2:
			return (pCStrA)(
				"SteamDeck_R2"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_Move:
			return (pCStrA)(
				"SteamDeck_LeftStick_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L3:
			return (pCStrA)(
				"SteamDeck_L3"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadNorth:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadSouth:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadWest:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_DPadEast:
			return (pCStrA)(
				"SteamDeck_LeftStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_LeftStick_Touch:
			return (pCStrA)(
				"SteamDeck_LeftStick_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_Move:
			return (pCStrA)(
				"SteamDeck_RightStick_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R3:
			return (pCStrA)(
				"SteamDeck_R3"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadNorth:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadNorth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadSouth:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadSouth"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadWest:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadWest"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_DPadEast:
			return (pCStrA)(
				"SteamDeck_RightStick_DPadEast"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_RightStick_Touch:
			return (pCStrA)(
				"SteamDeck_RightStick_Touch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L4:
			return (pCStrA)(
				"SteamDeck_L4"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R4:
			return (pCStrA)(
				"SteamDeck_R4"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_L5:
			return (pCStrA)(
				"SteamDeck_L5"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_R5:
			return (pCStrA)(
				"SteamDeck_R5"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_Move:
			return (pCStrA)(
				"SteamDeck_DPad_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_North:
			return (pCStrA)(
				"SteamDeck_DPad_North"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_South:
			return (pCStrA)(
				"SteamDeck_DPad_South"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_West:
			return (pCStrA)(
				"SteamDeck_DPad_West"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_DPad_East:
			return (pCStrA)(
				"SteamDeck_DPad_East"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Move:
			return (pCStrA)(
				"SteamDeck_Gyro_Move"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Pitch:
			return (pCStrA)(
				"SteamDeck_Gyro_Pitch"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Yaw:
			return (pCStrA)(
				"SteamDeck_Gyro_Yaw"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Gyro_Roll:
			return (pCStrA)(
				"SteamDeck_Gyro_Roll"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved1:
			return (pCStrA)(
				"SteamDeck_Reserved1"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved2:
			return (pCStrA)(
				"SteamDeck_Reserved2"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved3:
			return (pCStrA)(
				"SteamDeck_Reserved3"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved4:
			return (pCStrA)(
				"SteamDeck_Reserved4"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved5:
			return (pCStrA)(
				"SteamDeck_Reserved5"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved6:
			return (pCStrA)(
				"SteamDeck_Reserved6"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved7:
			return (pCStrA)(
				"SteamDeck_Reserved7"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved8:
			return (pCStrA)(
				"SteamDeck_Reserved8"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved9:
			return (pCStrA)(
				"SteamDeck_Reserved9"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved10:
			return (pCStrA)(
				"SteamDeck_Reserved10"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved11:
			return (pCStrA)(
				"SteamDeck_Reserved11"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved12:
			return (pCStrA)(
				"SteamDeck_Reserved12"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved13:
			return (pCStrA)(
				"SteamDeck_Reserved13"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved14:
			return (pCStrA)(
				"SteamDeck_Reserved14"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved15:
			return (pCStrA)(
				"SteamDeck_Reserved15"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved16:
			return (pCStrA)(
				"SteamDeck_Reserved16"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved17:
			return (pCStrA)(
				"SteamDeck_Reserved17"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved18:
			return (pCStrA)(
				"SteamDeck_Reserved18"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved19:
			return (pCStrA)(
				"SteamDeck_Reserved19"
			);
			break;
		case k_EControllerActionOrigin_SteamDeck_Reserved20:
			return (pCStrA)(
				"SteamDeck_Reserved20"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_N:
			return (pCStrA)(
				"Switch_JoyConButton_N"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_E:
			return (pCStrA)(
				"Switch_JoyConButton_E"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_S:
			return (pCStrA)(
				"Switch_JoyConButton_S"
			);
			break;
		case k_EControllerActionOrigin_Switch_JoyConButton_W:
			return (pCStrA)(
				"Switch_JoyConButton_W"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftGrip:
			return (pCStrA)(
				"PS5_LeftGrip"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightGrip:
			return (pCStrA)(
				"PS5_RightGrip"
			);
			break;
		case k_EControllerActionOrigin_PS5_LeftFn:
			return (pCStrA)(
				"PS5_LeftFn"
			);
			break;
		case k_EControllerActionOrigin_PS5_RightFn:
			return (pCStrA)(
				"PS5_RightFn"
			);
			break;
	}

	return (pCStrA)(
		""
	);

}

pCStrA _SteamController_::GetStringForActionOrigin(EControllerActionOrigin eControllerActionOrigin) {
	DEBUGBREAK("ISteamController::GetStringForActionOrigin");

	return this->GetGlyphForActionOrigin(eControllerActionOrigin);

}

void _SteamController_::StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) {
	DEBUGBREAK("ISteamController::StopAnalogActionMomentum");

	/* Empty Method */

}

ControllerMotionData_t _SteamController_::GetMotionData(ControllerHandle_t hController) {
	DEBUGBREAK("ISteamController::GetMotionData");

	ControllerMotionData_t controllerMotionData{};

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
	DEBUGBREAK("ISteamController::TriggerHapticPulse");

	/* Empty Method */

}

void _SteamController_::TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) {
	DEBUGBREAK("ISteamController::TriggerRepeatedHapticPulse");

	/* Empty Method */

}

void _SteamController_::TriggerVibration(ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) {
	DEBUGBREAK("ISteamController::TriggerVibration");

	/* Empty Method */

}

void _SteamController_::SetLEDColor(ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) {
	DEBUGBREAK("ISteamController::SetLEDColor");

	/* Empty Method */

}

Bool _SteamController_::ShowBindingPanel(ControllerHandle_t hController) {
	DEBUGBREAK("ISteamController::ShowBindingPanel");

	return True;

}

ESteamInputType _SteamController_::GetInputTypeForHandle(ControllerHandle_t hController) {
	DEBUGBREAK("ISteamController::GetInputTypeForHandle");

	return k_ESteamInputType_Unknown;

}

ControllerHandle_t _SteamController_::GetControllerForGamepadIndex(Int32 iController) {
	DEBUGBREAK("ISteamController::GetControllerForGamepadIndex");

	return (ControllerHandle_t)(0x0000000000000000);

}

Int32 _SteamController_::GetGamepadIndexForController(ControllerHandle_t hController) {
	DEBUGBREAK("ISteamController::GetGamepadIndexForController");

	return 0;

}

pCStrA _SteamController_::GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("ISteamController::GetStringForXboxOrigin");

	return this->GetGlyphForXboxOrigin(eXboxOrigin);

}

pCStrA _SteamController_::GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("ISteamController::GetGlyphForXboxOrigin");

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

EControllerActionOrigin _SteamController_::GetActionOriginFromXboxOrigin_(ControllerHandle_t hController, EXboxOrigin eXboxOrigin) {
	DEBUGBREAK("ISteamController::GetActionOriginFromXboxOrigin_");

	return k_EControllerActionOrigin_None;

}

EControllerActionOrigin _SteamController_::TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin) {
	DEBUGBREAK("ISteamController::TranslateActionOrigin");

	return k_EControllerActionOrigin_None;

}

Bool _SteamController_::GetControllerBindingRevision(ControllerHandle_t hController, pInt32 pMajor, pInt32 pMinor) {
	DEBUGBREAK("ISteamController::GetControllerBindingRevision");

	if (pMajor != NULL) {
		*pMajor = 0;
	}

	if (pMinor != NULL) {
		*pMinor = 0;
	}

	return False;

}

Bool _SteamController_::GetControllerState(Uint32 iController, pSteamControllerState_t pSteamControllerState) {
	DEBUGBREAK("ISteamController::GetControllerState");
	
	if (pSteamControllerState != NULL) {
		
		pSteamControllerState->nPacket = 0U;
		pSteamControllerState->nFlagsButtons = (Uint64)(0x0000000000000000);

		pSteamControllerState->LeftPadX = 0;
		pSteamControllerState->LeftPadY = 0;

		pSteamControllerState->RightPadX = 0;
		pSteamControllerState->RightPadY = 0;
		
		return True;

	}
	
	return False;
}

void _SteamController_::SetOverrideMode(pCStrA pchMode) {
	DEBUGBREAK("ISteamController::SetOverrideMode");

	/* Empty Method */

}

Bool _SteamController_::ActivateMode(ControllerHandle_t hController, Int32 eMode) {
	DEBUGBREAK("ISteamController::ActivateMode");

	return True;

}

Int32 _SteamController_::GetJoystickForHandle(ControllerHandle_t hController) {
	DEBUGBREAK("ISteamController::GetJoystickForHandle");
	
	return 0;

}

ControllerHandle_t _SteamController_::GetHandleForJoystick(Int32 hJoystick) {
	DEBUGBREAK("ISteamController::GetHandleForJoystick");

	return (ControllerHandle_t)(0x0000000000000000);

}

Int32 _SteamController_::GetModeAnalogOutputData(ControllerHandle_t hController, Int32 hAnalogData) {
	DEBUGBREAK("ISteamController::GetModeAnalogOutputData");
	
	return 0;

}

Bool _SteamController_::ShowDigitalActionOrigins(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) {
	DEBUGBREAK("ISteamController::ShowDigitalActionOrigins");
	
	return False;

}

Bool _SteamController_::ShowAnalogActionOrigins(ControllerHandle_t hController, ControllerAnalogActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) {
	DEBUGBREAK("ISteamController::ShowAnalogActionOrigins");
	
	return False;

}
