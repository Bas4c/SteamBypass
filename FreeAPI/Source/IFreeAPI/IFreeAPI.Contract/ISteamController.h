#ifndef _ISTEAMCONTROLLER_
#define _ISTEAMCONTROLLER_

#include "..\..\FreeAPI.Typedef.h"
#include "ISteamInput.h"

#define k_SteamControllerMaxCount ((Uint64)(16))
#define k_SteamControllerMaxAnalogAction ((Uint64)(24))
#define k_SteamControllerMaxDigitalAction ((Uint64)(256))
#define k_SteamControllerMaxOrigins ((Uint64)(8))
#define k_SteamControllerMaxActiveLayers ((Uint64)(16))

#define k_SteamControllerHandleAllControllers Uint64_MAX

#define k_SteamControllerMinAnalogActionData ((Float)(-1.0F))
#define k_SteamControllerMaxnAnalogActionData ((Float)(1.0F))

typedef enum _EControllerSource_ {

	k_EControllerSource_None,
	k_EControllerSource_LeftTrackpad,
	k_EControllerSource_RightTrackpad,
	k_EControllerSource_Joystick,
	k_EControllerSource_ABXY,
	k_EControllerSource_Switch,
	k_EControllerSource_LeftTrigger,
	k_EControllerSource_RightTrigger,
	k_EControllerSource_LeftBumper,
	k_EControllerSource_RightBumper,
	k_EControllerSource_Gyro,
	k_EControllerSource_CenterTrackpad,
	k_EControllerSource_RightJoystick,
	k_EControllerSource_DPad,
	k_EControllerSource_Key,
	k_EControllerSource_Mouse,
	k_EControllerSource_LeftGyro,
	k_EControllerSource_Count

} EControllerSource, *pEControllerSource;

typedef enum _EControllerSourceMode_ {

	k_EControllerSourceMode_None,
	k_EControllerSourceMode_Dpad,
	k_EControllerSourceMode_Buttons,
	k_EControllerSourceMode_FourButtons,
	k_EControllerSourceMode_AbsoluteMouse,
	k_EControllerSourceMode_RelativeMouse,
	k_EControllerSourceMode_JoystickMove,
	k_EControllerSourceMode_JoystickMouse,
	k_EControllerSourceMode_JoystickCamera,
	k_EControllerSourceMode_ScrollWheel,
	k_EControllerSourceMode_Trigger,
	k_EControllerSourceMode_TouchMenu,
	k_EControllerSourceMode_MouseJoystick,
	k_EControllerSourceMode_MouseRegion,
	k_EControllerSourceMode_RadialMenu,
	k_EControllerSourceMode_SingleButton,
	k_EControllerSourceMode_Switches

} EControllerSourceMode, *pEControllerSourceMode;

typedef enum _EControllerActionOrigin_ {

	k_EControllerActionOrigin_None,
	k_EControllerActionOrigin_A,
	k_EControllerActionOrigin_B,
	k_EControllerActionOrigin_X,
	k_EControllerActionOrigin_Y,
	k_EControllerActionOrigin_LeftBumper,
	k_EControllerActionOrigin_RightBumper,
	k_EControllerActionOrigin_LeftGrip,
	k_EControllerActionOrigin_RightGrip,
	k_EControllerActionOrigin_Start,
	k_EControllerActionOrigin_Back,
	k_EControllerActionOrigin_LeftPad_Touch,
	k_EControllerActionOrigin_LeftPad_Swipe,
	k_EControllerActionOrigin_LeftPad_Click,
	k_EControllerActionOrigin_LeftPad_DPadNorth,
	k_EControllerActionOrigin_LeftPad_DPadSouth,
	k_EControllerActionOrigin_LeftPad_DPadWest,
	k_EControllerActionOrigin_LeftPad_DPadEast,
	k_EControllerActionOrigin_RightPad_Touch,
	k_EControllerActionOrigin_RightPad_Swipe,
	k_EControllerActionOrigin_RightPad_Click,
	k_EControllerActionOrigin_RightPad_DPadNorth,
	k_EControllerActionOrigin_RightPad_DPadSouth,
	k_EControllerActionOrigin_RightPad_DPadWest,
	k_EControllerActionOrigin_RightPad_DPadEast,
	k_EControllerActionOrigin_LeftTrigger_Pull,
	k_EControllerActionOrigin_LeftTrigger_Click,
	k_EControllerActionOrigin_RightTrigger_Pull,
	k_EControllerActionOrigin_RightTrigger_Click,
	k_EControllerActionOrigin_LeftStick_Move,
	k_EControllerActionOrigin_LeftStick_Click,
	k_EControllerActionOrigin_LeftStick_DPadNorth,
	k_EControllerActionOrigin_LeftStick_DPadSouth,
	k_EControllerActionOrigin_LeftStick_DPadWest,
	k_EControllerActionOrigin_LeftStick_DPadEast,
	k_EControllerActionOrigin_Gyro_Move,
	k_EControllerActionOrigin_Gyro_Pitch,
	k_EControllerActionOrigin_Gyro_Yaw,
	k_EControllerActionOrigin_Gyro_Roll,
	k_EControllerActionOrigin_PS4_X,
	k_EControllerActionOrigin_PS4_Circle,
	k_EControllerActionOrigin_PS4_Triangle,
	k_EControllerActionOrigin_PS4_Square,
	k_EControllerActionOrigin_PS4_LeftBumper,
	k_EControllerActionOrigin_PS4_RightBumper,
	k_EControllerActionOrigin_PS4_Options,
	k_EControllerActionOrigin_PS4_Share,
	k_EControllerActionOrigin_PS4_LeftPad_Touch,
	k_EControllerActionOrigin_PS4_LeftPad_Swipe,
	k_EControllerActionOrigin_PS4_LeftPad_Click,
	k_EControllerActionOrigin_PS4_LeftPad_DPadNorth,
	k_EControllerActionOrigin_PS4_LeftPad_DPadSouth,
	k_EControllerActionOrigin_PS4_LeftPad_DPadWest,
	k_EControllerActionOrigin_PS4_LeftPad_DPadEast,
	k_EControllerActionOrigin_PS4_RightPad_Touch,
	k_EControllerActionOrigin_PS4_RightPad_Swipe,
	k_EControllerActionOrigin_PS4_RightPad_Click,
	k_EControllerActionOrigin_PS4_RightPad_DPadNorth,
	k_EControllerActionOrigin_PS4_RightPad_DPadSouth,
	k_EControllerActionOrigin_PS4_RightPad_DPadWest,
	k_EControllerActionOrigin_PS4_RightPad_DPadEast,
	k_EControllerActionOrigin_PS4_CenterPad_Touch,
	k_EControllerActionOrigin_PS4_CenterPad_Swipe,
	k_EControllerActionOrigin_PS4_CenterPad_Click,
	k_EControllerActionOrigin_PS4_CenterPad_DPadNorth,
	k_EControllerActionOrigin_PS4_CenterPad_DPadSouth,
	k_EControllerActionOrigin_PS4_CenterPad_DPadWest,
	k_EControllerActionOrigin_PS4_CenterPad_DPadEast,
	k_EControllerActionOrigin_PS4_LeftTrigger_Pull,
	k_EControllerActionOrigin_PS4_LeftTrigger_Click,
	k_EControllerActionOrigin_PS4_RightTrigger_Pull,
	k_EControllerActionOrigin_PS4_RightTrigger_Click,
	k_EControllerActionOrigin_PS4_LeftStick_Move,
	k_EControllerActionOrigin_PS4_LeftStick_Click,
	k_EControllerActionOrigin_PS4_LeftStick_DPadNorth,
	k_EControllerActionOrigin_PS4_LeftStick_DPadSouth,
	k_EControllerActionOrigin_PS4_LeftStick_DPadWest,
	k_EControllerActionOrigin_PS4_LeftStick_DPadEast,
	k_EControllerActionOrigin_PS4_RightStick_Move,
	k_EControllerActionOrigin_PS4_RightStick_Click,
	k_EControllerActionOrigin_PS4_RightStick_DPadNorth,
	k_EControllerActionOrigin_PS4_RightStick_DPadSouth,
	k_EControllerActionOrigin_PS4_RightStick_DPadWest,
	k_EControllerActionOrigin_PS4_RightStick_DPadEast,
	k_EControllerActionOrigin_PS4_DPad_North,
	k_EControllerActionOrigin_PS4_DPad_South,
	k_EControllerActionOrigin_PS4_DPad_West,
	k_EControllerActionOrigin_PS4_DPad_East,
	k_EControllerActionOrigin_PS4_Gyro_Move,
	k_EControllerActionOrigin_PS4_Gyro_Pitch,
	k_EControllerActionOrigin_PS4_Gyro_Yaw,
	k_EControllerActionOrigin_PS4_Gyro_Roll,
	k_EControllerActionOrigin_XBoxOne_A,
	k_EControllerActionOrigin_XBoxOne_B,
	k_EControllerActionOrigin_XBoxOne_X,
	k_EControllerActionOrigin_XBoxOne_Y,
	k_EControllerActionOrigin_XBoxOne_LeftBumper,
	k_EControllerActionOrigin_XBoxOne_RightBumper,
	k_EControllerActionOrigin_XBoxOne_Menu,
	k_EControllerActionOrigin_XBoxOne_View,
	k_EControllerActionOrigin_XBoxOne_LeftTrigger_Pull,
	k_EControllerActionOrigin_XBoxOne_LeftTrigger_Click,
	k_EControllerActionOrigin_XBoxOne_RightTrigger_Pull,
	k_EControllerActionOrigin_XBoxOne_RightTrigger_Click,
	k_EControllerActionOrigin_XBoxOne_LeftStick_Move,
	k_EControllerActionOrigin_XBoxOne_LeftStick_Click,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadNorth,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadSouth,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadWest,
	k_EControllerActionOrigin_XBoxOne_LeftStick_DPadEast,
	k_EControllerActionOrigin_XBoxOne_RightStick_Move,
	k_EControllerActionOrigin_XBoxOne_RightStick_Click,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadNorth,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadSouth,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadWest,
	k_EControllerActionOrigin_XBoxOne_RightStick_DPadEast,
	k_EControllerActionOrigin_XBoxOne_DPad_North,
	k_EControllerActionOrigin_XBoxOne_DPad_South,
	k_EControllerActionOrigin_XBoxOne_DPad_West,
	k_EControllerActionOrigin_XBoxOne_DPad_East,
	k_EControllerActionOrigin_XBox360_A,
	k_EControllerActionOrigin_XBox360_B,
	k_EControllerActionOrigin_XBox360_X,
	k_EControllerActionOrigin_XBox360_Y,
	k_EControllerActionOrigin_XBox360_LeftBumper,
	k_EControllerActionOrigin_XBox360_RightBumper,
	k_EControllerActionOrigin_XBox360_Start,
	k_EControllerActionOrigin_XBox360_Back,
	k_EControllerActionOrigin_XBox360_LeftTrigger_Pull,
	k_EControllerActionOrigin_XBox360_LeftTrigger_Click,
	k_EControllerActionOrigin_XBox360_RightTrigger_Pull,
	k_EControllerActionOrigin_XBox360_RightTrigger_Click,
	k_EControllerActionOrigin_XBox360_LeftStick_Move,
	k_EControllerActionOrigin_XBox360_LeftStick_Click,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadNorth,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadSouth,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadWest,
	k_EControllerActionOrigin_XBox360_LeftStick_DPadEast,
	k_EControllerActionOrigin_XBox360_RightStick_Move,
	k_EControllerActionOrigin_XBox360_RightStick_Click,
	k_EControllerActionOrigin_XBox360_RightStick_DPadNorth,
	k_EControllerActionOrigin_XBox360_RightStick_DPadSouth,
	k_EControllerActionOrigin_XBox360_RightStick_DPadWest,
	k_EControllerActionOrigin_XBox360_RightStick_DPadEast,
	k_EControllerActionOrigin_XBox360_DPad_North,
	k_EControllerActionOrigin_XBox360_DPad_South,
	k_EControllerActionOrigin_XBox360_DPad_West,
	k_EControllerActionOrigin_XBox360_DPad_East,
	k_EControllerActionOrigin_SteamV2_A,
	k_EControllerActionOrigin_SteamV2_B,
	k_EControllerActionOrigin_SteamV2_X,
	k_EControllerActionOrigin_SteamV2_Y,
	k_EControllerActionOrigin_SteamV2_LeftBumper,
	k_EControllerActionOrigin_SteamV2_RightBumper,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Lower,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Upper,
	k_EControllerActionOrigin_SteamV2_RightGrip_Lower,
	k_EControllerActionOrigin_SteamV2_RightGrip_Upper,
	k_EControllerActionOrigin_SteamV2_LeftBumper_Pressure,
	k_EControllerActionOrigin_SteamV2_RightBumper_Pressure,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Pressure,
	k_EControllerActionOrigin_SteamV2_RightGrip_Pressure,
	k_EControllerActionOrigin_SteamV2_LeftGrip_Upper_Pressure,
	k_EControllerActionOrigin_SteamV2_RightGrip_Upper_Pressure,
	k_EControllerActionOrigin_SteamV2_Start,
	k_EControllerActionOrigin_SteamV2_Back,
	k_EControllerActionOrigin_SteamV2_LeftPad_Touch,
	k_EControllerActionOrigin_SteamV2_LeftPad_Swipe,
	k_EControllerActionOrigin_SteamV2_LeftPad_Click,
	k_EControllerActionOrigin_SteamV2_LeftPad_Pressure,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadNorth,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadSouth,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadWest,
	k_EControllerActionOrigin_SteamV2_LeftPad_DPadEast,
	k_EControllerActionOrigin_SteamV2_RightPad_Touch,
	k_EControllerActionOrigin_SteamV2_RightPad_Swipe,
	k_EControllerActionOrigin_SteamV2_RightPad_Click,
	k_EControllerActionOrigin_SteamV2_RightPad_Pressure,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadNorth,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadSouth,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadWest,
	k_EControllerActionOrigin_SteamV2_RightPad_DPadEast,
	k_EControllerActionOrigin_SteamV2_LeftTrigger_Pull,
	k_EControllerActionOrigin_SteamV2_LeftTrigger_Click,
	k_EControllerActionOrigin_SteamV2_RightTrigger_Pull,
	k_EControllerActionOrigin_SteamV2_RightTrigger_Click,
	k_EControllerActionOrigin_SteamV2_LeftStick_Move,
	k_EControllerActionOrigin_SteamV2_LeftStick_Click,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadNorth,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadSouth,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadWest,
	k_EControllerActionOrigin_SteamV2_LeftStick_DPadEast,
	k_EControllerActionOrigin_SteamV2_Gyro_Move,
	k_EControllerActionOrigin_SteamV2_Gyro_Pitch,
	k_EControllerActionOrigin_SteamV2_Gyro_Yaw,
	k_EControllerActionOrigin_SteamV2_Gyro_Roll,
	k_EControllerActionOrigin_Switch_A,
	k_EControllerActionOrigin_Switch_B,
	k_EControllerActionOrigin_Switch_X,
	k_EControllerActionOrigin_Switch_Y,
	k_EControllerActionOrigin_Switch_LeftBumper,
	k_EControllerActionOrigin_Switch_RightBumper,
	k_EControllerActionOrigin_Switch_Plus,
	k_EControllerActionOrigin_Switch_Minus,
	k_EControllerActionOrigin_Switch_Capture,
	k_EControllerActionOrigin_Switch_LeftTrigger_Pull,
	k_EControllerActionOrigin_Switch_LeftTrigger_Click,
	k_EControllerActionOrigin_Switch_RightTrigger_Pull,
	k_EControllerActionOrigin_Switch_RightTrigger_Click,
	k_EControllerActionOrigin_Switch_LeftStick_Move,
	k_EControllerActionOrigin_Switch_LeftStick_Click,
	k_EControllerActionOrigin_Switch_LeftStick_DPadNorth,
	k_EControllerActionOrigin_Switch_LeftStick_DPadSouth,
	k_EControllerActionOrigin_Switch_LeftStick_DPadWest,
	k_EControllerActionOrigin_Switch_LeftStick_DPadEast,
	k_EControllerActionOrigin_Switch_RightStick_Move,
	k_EControllerActionOrigin_Switch_RightStick_Click,
	k_EControllerActionOrigin_Switch_RightStick_DPadNorth,
	k_EControllerActionOrigin_Switch_RightStick_DPadSouth,
	k_EControllerActionOrigin_Switch_RightStick_DPadWest,
	k_EControllerActionOrigin_Switch_RightStick_DPadEast,
	k_EControllerActionOrigin_Switch_DPad_North,
	k_EControllerActionOrigin_Switch_DPad_South,
	k_EControllerActionOrigin_Switch_DPad_West,
	k_EControllerActionOrigin_Switch_DPad_East,
	k_EControllerActionOrigin_Switch_ProGyro_Move,
	k_EControllerActionOrigin_Switch_ProGyro_Pitch,
	k_EControllerActionOrigin_Switch_ProGyro_Yaw,
	k_EControllerActionOrigin_Switch_ProGyro_Roll,
	k_EControllerActionOrigin_Switch_RightGyro_Move,
	k_EControllerActionOrigin_Switch_RightGyro_Pitch,
	k_EControllerActionOrigin_Switch_RightGyro_Yaw,
	k_EControllerActionOrigin_Switch_RightGyro_Roll,
	k_EControllerActionOrigin_Switch_LeftGyro_Move,
	k_EControllerActionOrigin_Switch_LeftGyro_Pitch,
	k_EControllerActionOrigin_Switch_LeftGyro_Yaw,
	k_EControllerActionOrigin_Switch_LeftGyro_Roll,
	k_EControllerActionOrigin_Switch_LeftGrip_Lower,
	k_EControllerActionOrigin_Switch_LeftGrip_Upper,
	k_EControllerActionOrigin_Switch_RightGrip_Lower,
	k_EControllerActionOrigin_Switch_RightGrip_Upper,
	k_EControllerActionOrigin_PS4_DPad_Move,
	k_EControllerActionOrigin_XBoxOne_DPad_Move,
	k_EControllerActionOrigin_XBox360_DPad_Move,
	k_EControllerActionOrigin_Switch_DPad_Move,
	k_EControllerActionOrigin_PS5_X,
	k_EControllerActionOrigin_PS5_Circle,
	k_EControllerActionOrigin_PS5_Triangle,
	k_EControllerActionOrigin_PS5_Square,
	k_EControllerActionOrigin_PS5_LeftBumper,
	k_EControllerActionOrigin_PS5_RightBumper,
	k_EControllerActionOrigin_PS5_Option,
	k_EControllerActionOrigin_PS5_Create,
	k_EControllerActionOrigin_PS5_Mute,
	k_EControllerActionOrigin_PS5_LeftPad_Touch,
	k_EControllerActionOrigin_PS5_LeftPad_Swipe,
	k_EControllerActionOrigin_PS5_LeftPad_Click,
	k_EControllerActionOrigin_PS5_LeftPad_DPadNorth,
	k_EControllerActionOrigin_PS5_LeftPad_DPadSouth,
	k_EControllerActionOrigin_PS5_LeftPad_DPadWest,
	k_EControllerActionOrigin_PS5_LeftPad_DPadEast,
	k_EControllerActionOrigin_PS5_RightPad_Touch,
	k_EControllerActionOrigin_PS5_RightPad_Swipe,
	k_EControllerActionOrigin_PS5_RightPad_Click,
	k_EControllerActionOrigin_PS5_RightPad_DPadNorth,
	k_EControllerActionOrigin_PS5_RightPad_DPadSouth,
	k_EControllerActionOrigin_PS5_RightPad_DPadWest,
	k_EControllerActionOrigin_PS5_RightPad_DPadEast,
	k_EControllerActionOrigin_PS5_CenterPad_Touch,
	k_EControllerActionOrigin_PS5_CenterPad_Swipe,
	k_EControllerActionOrigin_PS5_CenterPad_Click,
	k_EControllerActionOrigin_PS5_CenterPad_DPadNorth,
	k_EControllerActionOrigin_PS5_CenterPad_DPadSouth,
	k_EControllerActionOrigin_PS5_CenterPad_DPadWest,
	k_EControllerActionOrigin_PS5_CenterPad_DPadEast,
	k_EControllerActionOrigin_PS5_LeftTrigger_Pull,
	k_EControllerActionOrigin_PS5_LeftTrigger_Click,
	k_EControllerActionOrigin_PS5_RightTrigger_Pull,
	k_EControllerActionOrigin_PS5_RightTrigger_Click,
	k_EControllerActionOrigin_PS5_LeftStick_Move,
	k_EControllerActionOrigin_PS5_LeftStick_Click,
	k_EControllerActionOrigin_PS5_LeftStick_DPadNorth,
	k_EControllerActionOrigin_PS5_LeftStick_DPadSouth,
	k_EControllerActionOrigin_PS5_LeftStick_DPadWest,
	k_EControllerActionOrigin_PS5_LeftStick_DPadEast,
	k_EControllerActionOrigin_PS5_RightStick_Move,
	k_EControllerActionOrigin_PS5_RightStick_Click,
	k_EControllerActionOrigin_PS5_RightStick_DPadNorth,
	k_EControllerActionOrigin_PS5_RightStick_DPadSouth,
	k_EControllerActionOrigin_PS5_RightStick_DPadWest,
	k_EControllerActionOrigin_PS5_RightStick_DPadEast,
	k_EControllerActionOrigin_PS5_DPad_Move,
	k_EControllerActionOrigin_PS5_DPad_North,
	k_EControllerActionOrigin_PS5_DPad_South,
	k_EControllerActionOrigin_PS5_DPad_West,
	k_EControllerActionOrigin_PS5_DPad_East,
	k_EControllerActionOrigin_PS5_Gyro_Move,
	k_EControllerActionOrigin_PS5_Gyro_Pitch,
	k_EControllerActionOrigin_PS5_Gyro_Yaw,
	k_EControllerActionOrigin_PS5_Gyro_Roll,
	k_EControllerActionOrigin_XBoxOne_LeftGrip_Lower,
	k_EControllerActionOrigin_XBoxOne_LeftGrip_Upper,
	k_EControllerActionOrigin_XBoxOne_RightGrip_Lower,
	k_EControllerActionOrigin_XBoxOne_RightGrip_Upper,
	k_EControllerActionOrigin_XBoxOne_Share,
	k_EControllerActionOrigin_SteamDeck_A,
	k_EControllerActionOrigin_SteamDeck_B,
	k_EControllerActionOrigin_SteamDeck_X,
	k_EControllerActionOrigin_SteamDeck_Y,
	k_EControllerActionOrigin_SteamDeck_L1,
	k_EControllerActionOrigin_SteamDeck_R1,
	k_EControllerActionOrigin_SteamDeck_Menu,
	k_EControllerActionOrigin_SteamDeck_View,
	k_EControllerActionOrigin_SteamDeck_LeftPad_Touch,
	k_EControllerActionOrigin_SteamDeck_LeftPad_Swipe,
	k_EControllerActionOrigin_SteamDeck_LeftPad_Click,
	k_EControllerActionOrigin_SteamDeck_LeftPad_DPadNorth,
	k_EControllerActionOrigin_SteamDeck_LeftPad_DPadSouth,
	k_EControllerActionOrigin_SteamDeck_LeftPad_DPadWest,
	k_EControllerActionOrigin_SteamDeck_LeftPad_DPadEast,
	k_EControllerActionOrigin_SteamDeck_RightPad_Touch,
	k_EControllerActionOrigin_SteamDeck_RightPad_Swipe,
	k_EControllerActionOrigin_SteamDeck_RightPad_Click,
	k_EControllerActionOrigin_SteamDeck_RightPad_DPadNorth,
	k_EControllerActionOrigin_SteamDeck_RightPad_DPadSouth,
	k_EControllerActionOrigin_SteamDeck_RightPad_DPadWest,
	k_EControllerActionOrigin_SteamDeck_RightPad_DPadEast,
	k_EControllerActionOrigin_SteamDeck_L2_SoftPull,
	k_EControllerActionOrigin_SteamDeck_L2,
	k_EControllerActionOrigin_SteamDeck_R2_SoftPull,
	k_EControllerActionOrigin_SteamDeck_R2,
	k_EControllerActionOrigin_SteamDeck_LeftStick_Move,
	k_EControllerActionOrigin_SteamDeck_L3,
	k_EControllerActionOrigin_SteamDeck_LeftStick_DPadNorth,
	k_EControllerActionOrigin_SteamDeck_LeftStick_DPadSouth,
	k_EControllerActionOrigin_SteamDeck_LeftStick_DPadWest,
	k_EControllerActionOrigin_SteamDeck_LeftStick_DPadEast,
	k_EControllerActionOrigin_SteamDeck_LeftStick_Touch,
	k_EControllerActionOrigin_SteamDeck_RightStick_Move,
	k_EControllerActionOrigin_SteamDeck_R3,
	k_EControllerActionOrigin_SteamDeck_RightStick_DPadNorth,
	k_EControllerActionOrigin_SteamDeck_RightStick_DPadSouth,
	k_EControllerActionOrigin_SteamDeck_RightStick_DPadWest,
	k_EControllerActionOrigin_SteamDeck_RightStick_DPadEast,
	k_EControllerActionOrigin_SteamDeck_RightStick_Touch,
	k_EControllerActionOrigin_SteamDeck_L4,
	k_EControllerActionOrigin_SteamDeck_R4,
	k_EControllerActionOrigin_SteamDeck_L5,
	k_EControllerActionOrigin_SteamDeck_R5,
	k_EControllerActionOrigin_SteamDeck_DPad_Move,
	k_EControllerActionOrigin_SteamDeck_DPad_North,
	k_EControllerActionOrigin_SteamDeck_DPad_South,
	k_EControllerActionOrigin_SteamDeck_DPad_West,
	k_EControllerActionOrigin_SteamDeck_DPad_East,
	k_EControllerActionOrigin_SteamDeck_Gyro_Move,
	k_EControllerActionOrigin_SteamDeck_Gyro_Pitch,
	k_EControllerActionOrigin_SteamDeck_Gyro_Yaw,
	k_EControllerActionOrigin_SteamDeck_Gyro_Roll,
	k_EControllerActionOrigin_SteamDeck_Reserved1,
	k_EControllerActionOrigin_SteamDeck_Reserved2,
	k_EControllerActionOrigin_SteamDeck_Reserved3,
	k_EControllerActionOrigin_SteamDeck_Reserved4,
	k_EControllerActionOrigin_SteamDeck_Reserved5,
	k_EControllerActionOrigin_SteamDeck_Reserved6,
	k_EControllerActionOrigin_SteamDeck_Reserved7,
	k_EControllerActionOrigin_SteamDeck_Reserved8,
	k_EControllerActionOrigin_SteamDeck_Reserved9,
	k_EControllerActionOrigin_SteamDeck_Reserved10,
	k_EControllerActionOrigin_SteamDeck_Reserved11,
	k_EControllerActionOrigin_SteamDeck_Reserved12,
	k_EControllerActionOrigin_SteamDeck_Reserved13,
	k_EControllerActionOrigin_SteamDeck_Reserved14,
	k_EControllerActionOrigin_SteamDeck_Reserved15,
	k_EControllerActionOrigin_SteamDeck_Reserved16,
	k_EControllerActionOrigin_SteamDeck_Reserved17,
	k_EControllerActionOrigin_SteamDeck_Reserved18,
	k_EControllerActionOrigin_SteamDeck_Reserved19,
	k_EControllerActionOrigin_SteamDeck_Reserved20,
	k_EControllerActionOrigin_Switch_JoyConButton_N,
	k_EControllerActionOrigin_Switch_JoyConButton_E,
	k_EControllerActionOrigin_Switch_JoyConButton_S,
	k_EControllerActionOrigin_Switch_JoyConButton_W,
	k_EControllerActionOrigin_PS5_LeftGrip,
	k_EControllerActionOrigin_PS5_RightGrip,
	k_EControllerActionOrigin_PS5_LeftFn,
	k_EControllerActionOrigin_PS5_RightFn,
	k_EControllerActionOrigin_Count,
	k_EControllerActionOrigin_MaximumPossibleValue = 32767

} EControllerActionOrigin, *pEControllerActionOrigin;

typedef enum _ESteamControllerLEDFlag_ {

	k_ESteamControllerLEDFlag_SetColor,
	k_ESteamControllerLEDFlag_RestoreUserDefault

} ESteamControllerLEDFlag, *pESteamControllerLEDFlag;

typedef Uint64 ControllerHandle_t, *pControllerHandle_t;
typedef Uint64 ControllerActionSetHandle_t, *pControllerActionSetHandle_t;
typedef Uint64 ControllerDigitalActionHandle_t, *pControllerDigitalActionHandle_t;
typedef Uint64 ControllerAnalogActionHandle_t, *pControllerAnalogActionHandle_t;

#define ControllerAnalogActionData_t InputAnalogActionData_t
#define ControllerDigitalActionData_t InputDigitalActionData_t
#define ControllerMotionData_t InputMotionData_t
#define ControllerMotionDataV2_t InputMotionDataV2_t

typedef struct _SteamControllerState_t_ {
	
	/* If packet id matches that on your prior call, then the controller state hasn't been changed since 
	    your last call and there is no need to process it */
	Uint32 nPacket;
	Uint64 nFlagsButtons;

	Uint16 LeftPadX;
	Uint16 LeftPadY;

	Uint16 RightPadX;
	Uint16 RightPadY;

} SteamControllerState_t, *pSteamControllerState_t;

typedef class _ISteamController001_ {
public:

	virtual Bool Init(const pStrA pchAbsolutePathToControllerConfigVDF) = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame() = 0;
	virtual Bool GetControllerState(Uint32 iController, pSteamControllerState_t pSteamControllerState) = 0;
	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void SetOverrideMode(const pStrA pchMode) = 0;

} ISteamController001, *IpSteamController001;

typedef class _ISteamController002_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame() = 0;
	virtual Int32 GetConnectedControllers(pControllerHandle_t phController) = 0;
	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual Bool ActivateMode(ControllerHandle_t hController, Int32 eMode) = 0;
	virtual Int32 GetJoystickForHandle(ControllerHandle_t hController) = 0;
	virtual ControllerHandle_t GetHandleForJoystick(Int32 hJoystick) = 0;
	virtual Int32 GetModeAnalogOutputData(ControllerHandle_t hController, Int32 hAnalogData) = 0;

} ISteamController002, *IpSteamController002;

typedef class _ISteamController003_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame() = 0;
	virtual Int32 GetConnectedControllers(pControllerHandle_t phController) = 0;
	virtual Bool ShowBindingPanel(ControllerHandle_t hController) = 0;
	virtual ControllerActionSetHandle_t GetActionSetHandle(const pStrA pchActionSetName) = 0;
	virtual ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t hController) = 0;
	virtual ControllerDigitalActionHandle_t GetDigitalActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerDigitalActionData_t GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual ControllerAnalogActionHandle_t GetAnalogActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerAnalogActionData_t GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual void StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;

} ISteamController003, *IpSteamController003;

typedef class _ISteamController004_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame() = 0;
	virtual Int32 GetConnectedControllers(pControllerHandle_t phController) = 0;
	virtual Bool ShowBindingPanel(ControllerHandle_t hController) = 0;
	virtual ControllerActionSetHandle_t GetActionSetHandle(const pStrA pchActionSetName) = 0;
	virtual ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t hController) = 0;
	virtual ControllerDigitalActionHandle_t GetDigitalActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerDigitalActionData_t GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual ControllerAnalogActionHandle_t GetAnalogActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerAnalogActionData_t GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual void StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual Int32 GetGamepadIndexForController(ControllerHandle_t hController) = 0;
	virtual ControllerHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual ControllerMotionData_t GetMotionData(ControllerHandle_t hController) = 0;
	virtual Bool ShowDigitalActionOrigins(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) = 0;
	virtual Bool ShowAnalogActionOrigins(ControllerHandle_t hController, ControllerAnalogActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) = 0;

} ISteamController004, *IpSteamController004;

typedef class _ISteamController005_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame() = 0;
	virtual Int32 GetConnectedControllers(pControllerHandle_t phController) = 0;
	virtual Bool ShowBindingPanel(ControllerHandle_t hController) = 0;
	virtual ControllerActionSetHandle_t GetActionSetHandle(const pStrA pchActionSetName) = 0;
	virtual ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t hController) = 0;
	virtual ControllerDigitalActionHandle_t GetDigitalActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerDigitalActionData_t GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual ControllerAnalogActionHandle_t GetAnalogActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerAnalogActionData_t GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual void StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual void TriggerVibration(ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void SetLEDColor(ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;
	virtual Int32 GetGamepadIndexForController(ControllerHandle_t hController) = 0;
	virtual ControllerHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual ControllerMotionData_t GetMotionData(ControllerHandle_t hController) = 0;
	virtual Bool ShowDigitalActionOrigins(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) = 0;
	virtual Bool ShowAnalogActionOrigins(ControllerHandle_t hController, ControllerAnalogActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) = 0;
	virtual const pStrA GetStringForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;
	virtual const pStrA GetGlyphForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;

} ISteamController005, *IpSteamController005;

typedef class _ISteamController006_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame() = 0;
	virtual Int32 GetConnectedControllers(pControllerHandle_t phController) = 0;
	virtual Bool ShowBindingPanel(ControllerHandle_t hController) = 0;
	virtual ControllerActionSetHandle_t GetActionSetHandle(const pStrA pchActionSetName) = 0;
	virtual void ActivateActionSet(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet) = 0;
	virtual ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t hController) = 0;
	virtual void ActivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateAllActionSetLayers(ControllerHandle_t hController) = 0;
	virtual Int32 GetActiveActionSetLayers(ControllerHandle_t hController, pControllerActionSetHandle_t phController) = 0;
	virtual ControllerDigitalActionHandle_t GetDigitalActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerDigitalActionData_t GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual ControllerAnalogActionHandle_t GetAnalogActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerAnalogActionData_t GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual void StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual void TriggerVibration(ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void SetLEDColor(ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;
	virtual Int32 GetGamepadIndexForController(ControllerHandle_t hController) = 0;
	virtual ControllerHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual ControllerMotionData_t GetMotionData(ControllerHandle_t hController) = 0;
	virtual Bool ShowDigitalActionOrigins(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) = 0;
	virtual Bool ShowAnalogActionOrigins(ControllerHandle_t hController, ControllerAnalogActionHandle_t hDigitalAction, Float Scale, Float XPosition, Float YPosition) = 0;
	virtual const pStrA GetStringForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;
	virtual const pStrA GetGlyphForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;
	virtual ESteamInputType GetInputTypeForHandle(ControllerHandle_t hController) = 0;

} ISteamController006, *IpSteamController006;

typedef class _ISteamController007_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame() = 0;
	virtual Int32 GetConnectedControllers(pControllerHandle_t phController) = 0;
	virtual ControllerActionSetHandle_t GetActionSetHandle(const pStrA pchActionSetName) = 0;
	virtual void ActivateActionSet(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet) = 0;
	virtual ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t hController) = 0;
	virtual void ActivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateAllActionSetLayers(ControllerHandle_t hController) = 0;
	virtual Int32 GetActiveActionSetLayers(ControllerHandle_t hController, pControllerActionSetHandle_t phController) = 0;
	virtual ControllerDigitalActionHandle_t GetDigitalActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerDigitalActionData_t GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual ControllerAnalogActionHandle_t GetAnalogActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerAnalogActionData_t GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, pEControllerActionOrigin peControllerActionOrigin) = 0;
	virtual const pStrA GetGlyphForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;
	virtual const pStrA GetStringForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;
	virtual void StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual ControllerMotionData_t GetMotionData(ControllerHandle_t hController) = 0;
	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual void TriggerVibration(ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void SetLEDColor(ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;
	virtual Bool ShowBindingPanel(ControllerHandle_t hController) = 0;
	virtual ESteamInputType GetInputTypeForHandle(ControllerHandle_t hController) = 0;
	virtual ControllerHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual Int32 GetGamepadIndexForController(ControllerHandle_t hController) = 0;
	virtual const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual EControllerActionOrigin GetActionOriginFromXboxOrigin_(ControllerHandle_t hController, EXboxOrigin eXboxOrigin) = 0;
	virtual EControllerActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin) = 0;
	virtual Bool GetControllerBindingRevision(ControllerHandle_t hController, pInt32 pMajor, pInt32 pMinor) = 0;

} ISteamController007, *IpSteamController007;

// -----------------------------------------------------------------------------
// Purpose: Steam Input API
// -----------------------------------------------------------------------------
typedef class _ISteamController_ {
public:

	virtual Bool Init() = 0;
	virtual Bool Shutdown() = 0;

	/* Synchronize API state with the latest Steam Input action data available. This
		is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
		possible latency, you call this directly before reading controller state. */
	virtual void RunFrame() = 0;

	/* Returns the number of handles written to phController */
	virtual Int32 GetConnectedControllers(/* [out(k_SteamControllerMaxCount)] */ pControllerHandle_t phController) = 0;

	virtual ControllerActionSetHandle_t GetActionSetHandle(const pStrA pchActionSetName) = 0;
	virtual void ActivateActionSet(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet) = 0;
	virtual ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t hController) = 0;
	virtual void ActivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateActionSetLayer(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateAllActionSetLayers(ControllerHandle_t hController) = 0;
	
	/* Returns the number of handles written to phActionSetLayer */
	virtual Int32 GetActiveActionSetLayers(ControllerHandle_t hController, /* [out(k_SteamControllerMaxActiveLayers)] */ pControllerActionSetHandle_t phActionSetLayer) = 0;

	virtual ControllerDigitalActionHandle_t GetDigitalActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerDigitalActionData_t GetDigitalActionData(ControllerHandle_t hController, ControllerDigitalActionHandle_t hDigitalAction) = 0;
	/* Returns the number of handles written to peControllerActionOrigin */
	virtual Int32 GetDigitalActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerDigitalActionHandle_t hDigitalAction, /* [out(k_SteamControllerMaxOrigins)] */ pEControllerActionOrigin peControllerActionOrigin) = 0;

	virtual ControllerAnalogActionHandle_t GetAnalogActionHandle(const pStrA pchActionName) = 0;
	virtual ControllerAnalogActionData_t GetAnalogActionData(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	/* Returns the number of handles written to peControllerActionOrigin */
	virtual Int32 GetAnalogActionOrigins(ControllerHandle_t hController, ControllerActionSetHandle_t hActionSet, ControllerAnalogActionHandle_t hAnalogAction, /* [out(k_SteamControllerMaxOrigins)] */ pEControllerActionOrigin peControllerActionOrigin) = 0;

	virtual const pStrA GetGlyphForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;
	virtual const pStrA GetStringForActionOrigin(EControllerActionOrigin eControllerActionOrigin) = 0;

	virtual void StopAnalogActionMomentum(ControllerHandle_t hController, ControllerAnalogActionHandle_t hAnalogAction) = 0;
	virtual ControllerMotionData_t GetMotionData(ControllerHandle_t hController) = 0;

	virtual void TriggerHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSecondsonds) = 0;
	virtual void TriggerRepeatedHapticPulse(ControllerHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSecondsonds, Uint16 OffMicroSecondsonds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual void TriggerVibration(ControllerHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void SetLEDColor(ControllerHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;

	virtual Bool ShowBindingPanel(ControllerHandle_t hController) = 0;
	virtual ESteamInputType GetInputTypeForHandle(ControllerHandle_t hController) = 0;

	/* Returns the associated controller handle for the specified emulated gamepad - can be used with the above 2 Functions
	    to identify controllers presented to your game over Xinput. Returns 0 if the Xinput index isn't associated with Steam Input */
	virtual ControllerHandle_t GetControllerForGamepadIndex(Int32 iController) = 0;
	/* Returns the associated gamepad index for the specified controller, if emulating a gamepad or -1 if not associated with an Xinput index */
	virtual Int32 GetGamepadIndexForController(ControllerHandle_t hController) = 0;

	virtual const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;

	virtual EControllerActionOrigin GetActionOriginFromXboxOrigin_(ControllerHandle_t hController, EXboxOrigin eXboxOrigin) = 0;
	virtual EControllerActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin) = 0;

	virtual Bool GetControllerBindingRevision(ControllerHandle_t hController, /* [out] */ pInt32 pMajor, /* [out] */ pInt32 pMinor) = 0;

} ISteamController, *IpSteamController;

#define STEAMCONTROLLER_INTERFACE_VERSION "SteamController008"

#endif // _ISTEAMCONTROLLER_
