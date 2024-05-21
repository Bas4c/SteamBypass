#ifndef _ISTEAMINPUT_
#define _ISTEAMINPUT_

#include "..\..\FreeAPI.Typedef.h"

#define k_SteamInputMaxCount ((Uint64)(16))
#define k_SteamInputMaxAnalogCount ((Uint64)(24))
#define k_SteamInputMaxDigitalCount ((Uint64)(256))
#define k_SteamInputMaxOrigins ((Uint64)(8))
#define k_SteamInputMaxActiveLayers ((Uint64)(16))

#define k_SteamInputHandleAllControllers Uint64_MAX

#define k_SteamInputMinAnalogData ((Float)(-1.0F))
#define k_SteamInputMaxAnalogData ((Float)(1.0F))

typedef enum _EInputSource_ {

	k_EInputSource_None,
	k_EInputSource_LeftTrackpad,
	k_EInputSource_RightTrackpad,
	k_EInputSource_Joystick,
	k_EInputSource_ABXY,
	k_EInputSource_Switch,
	k_EInputSource_LeftTrigger,
	k_EInputSource_RightTrigger,
	k_EInputSource_LeftBumper,
	k_EInputSource_RightBumper,
	k_EInputSource_Gyro,
	k_EInputSource_CenterTrackpad,
	k_EInputSource_RightJoystick,
	k_EInputSource_DPad,
	k_EInputSource_Key,
	k_EInputSource_Mouse,
	k_EInputSource_LeftGyro,
	k_EInputSource_Count

} EInputSource, *pEInputSource;

typedef enum _EInputSourceMode_ {

	k_EInputSourceMode_None,
	k_EInputSourceMode_Dpad,
	k_EInputSourceMode_Buttons,
	k_EInputSourceMode_FourButtons,
	k_EInputSourceMode_AbsoluteMouse,
	k_EInputSourceMode_RelativeMouse,
	k_EInputSourceMode_JoystickMove,
	k_EInputSourceMode_JoystickMouse,
	k_EInputSourceMode_JoystickCamera,
	k_EInputSourceMode_ScrollWheel,
	k_EInputSourceMode_Trigger,
	k_EInputSourceMode_TouchMenu,
	k_EInputSourceMode_MouseJoystick,
	k_EInputSourceMode_MouseRegion,
	k_EInputSourceMode_RadialMenu,
	k_EInputSourceMode_SingleButton,
	k_EInputSourceMode_Switches

} EInputSourceMode, *pEInputSourceMode;

typedef enum _EInputActionOrigin_ {

	k_EInputActionOrigin_None,
	k_EInputActionOrigin_SteamController_A,
	k_EInputActionOrigin_SteamController_B,
	k_EInputActionOrigin_SteamController_X,
	k_EInputActionOrigin_SteamController_Y,
	k_EInputActionOrigin_SteamController_LeftBumper,
	k_EInputActionOrigin_SteamController_RightBumper,
	k_EInputActionOrigin_SteamController_LeftGrip,
	k_EInputActionOrigin_SteamController_RightGrip,
	k_EInputActionOrigin_SteamController_Start,
	k_EInputActionOrigin_SteamController_Back,
	k_EInputActionOrigin_SteamController_LeftPad_Touch,
	k_EInputActionOrigin_SteamController_LeftPad_Swipe,
	k_EInputActionOrigin_SteamController_LeftPad_Click,
	k_EInputActionOrigin_SteamController_LeftPad_DPadNorth,
	k_EInputActionOrigin_SteamController_LeftPad_DPadSouth,
	k_EInputActionOrigin_SteamController_LeftPad_DPadWest,
	k_EInputActionOrigin_SteamController_LeftPad_DPadEast,
	k_EInputActionOrigin_SteamController_RightPad_Touch,
	k_EInputActionOrigin_SteamController_RightPad_Swipe,
	k_EInputActionOrigin_SteamController_RightPad_Click,
	k_EInputActionOrigin_SteamController_RightPad_DPadNorth,
	k_EInputActionOrigin_SteamController_RightPad_DPadSouth,
	k_EInputActionOrigin_SteamController_RightPad_DPadWest,
	k_EInputActionOrigin_SteamController_RightPad_DPadEast,
	k_EInputActionOrigin_SteamController_LeftTrigger_Pull,
	k_EInputActionOrigin_SteamController_LeftTrigger_Click,
	k_EInputActionOrigin_SteamController_RightTrigger_Pull,
	k_EInputActionOrigin_SteamController_RightTrigger_Click,
	k_EInputActionOrigin_SteamController_LeftStick_Move,
	k_EInputActionOrigin_SteamController_LeftStick_Click,
	k_EInputActionOrigin_SteamController_LeftStick_DPadNorth,
	k_EInputActionOrigin_SteamController_LeftStick_DPadSouth,
	k_EInputActionOrigin_SteamController_LeftStick_DPadWest,
	k_EInputActionOrigin_SteamController_LeftStick_DPadEast,
	k_EInputActionOrigin_SteamController_Gyro_Move,
	k_EInputActionOrigin_SteamController_Gyro_Pitch,
	k_EInputActionOrigin_SteamController_Gyro_Yaw,
	k_EInputActionOrigin_SteamController_Gyro_Roll,
	k_EInputActionOrigin_SteamController_Reserved0,
	k_EInputActionOrigin_SteamController_Reserved1,
	k_EInputActionOrigin_SteamController_Reserved2,
	k_EInputActionOrigin_SteamController_Reserved3,
	k_EInputActionOrigin_SteamController_Reserved4,
	k_EInputActionOrigin_SteamController_Reserved5,
	k_EInputActionOrigin_SteamController_Reserved6,
	k_EInputActionOrigin_SteamController_Reserved7,
	k_EInputActionOrigin_SteamController_Reserved8,
	k_EInputActionOrigin_SteamController_Reserved9,
	k_EInputActionOrigin_SteamController_Reserved10,
	k_EInputActionOrigin_PS4_X,
	k_EInputActionOrigin_PS4_Circle,
	k_EInputActionOrigin_PS4_Triangle,
	k_EInputActionOrigin_PS4_Square,
	k_EInputActionOrigin_PS4_LeftBumper,
	k_EInputActionOrigin_PS4_RightBumper,
	k_EInputActionOrigin_PS4_Options,
	k_EInputActionOrigin_PS4_Share,
	k_EInputActionOrigin_PS4_LeftPad_Touch,
	k_EInputActionOrigin_PS4_LeftPad_Swipe,
	k_EInputActionOrigin_PS4_LeftPad_Click,
	k_EInputActionOrigin_PS4_LeftPad_DPadNorth,
	k_EInputActionOrigin_PS4_LeftPad_DPadSouth,
	k_EInputActionOrigin_PS4_LeftPad_DPadWest,
	k_EInputActionOrigin_PS4_LeftPad_DPadEast,
	k_EInputActionOrigin_PS4_RightPad_Touch,
	k_EInputActionOrigin_PS4_RightPad_Swipe,
	k_EInputActionOrigin_PS4_RightPad_Click,
	k_EInputActionOrigin_PS4_RightPad_DPadNorth,
	k_EInputActionOrigin_PS4_RightPad_DPadSouth,
	k_EInputActionOrigin_PS4_RightPad_DPadWest,
	k_EInputActionOrigin_PS4_RightPad_DPadEast,
	k_EInputActionOrigin_PS4_CenterPad_Touch,
	k_EInputActionOrigin_PS4_CenterPad_Swipe,
	k_EInputActionOrigin_PS4_CenterPad_Click,
	k_EInputActionOrigin_PS4_CenterPad_DPadNorth,
	k_EInputActionOrigin_PS4_CenterPad_DPadSouth,
	k_EInputActionOrigin_PS4_CenterPad_DPadWest,
	k_EInputActionOrigin_PS4_CenterPad_DPadEast,
	k_EInputActionOrigin_PS4_LeftTrigger_Pull,
	k_EInputActionOrigin_PS4_LeftTrigger_Click,
	k_EInputActionOrigin_PS4_RightTrigger_Pull,
	k_EInputActionOrigin_PS4_RightTrigger_Click,
	k_EInputActionOrigin_PS4_LeftStick_Move,
	k_EInputActionOrigin_PS4_LeftStick_Click,
	k_EInputActionOrigin_PS4_LeftStick_DPadNorth,
	k_EInputActionOrigin_PS4_LeftStick_DPadSouth,
	k_EInputActionOrigin_PS4_LeftStick_DPadWest,
	k_EInputActionOrigin_PS4_LeftStick_DPadEast,
	k_EInputActionOrigin_PS4_RightStick_Move,
	k_EInputActionOrigin_PS4_RightStick_Click,
	k_EInputActionOrigin_PS4_RightStick_DPadNorth,
	k_EInputActionOrigin_PS4_RightStick_DPadSouth,
	k_EInputActionOrigin_PS4_RightStick_DPadWest,
	k_EInputActionOrigin_PS4_RightStick_DPadEast,
	k_EInputActionOrigin_PS4_DPad_North,
	k_EInputActionOrigin_PS4_DPad_South,
	k_EInputActionOrigin_PS4_DPad_West,
	k_EInputActionOrigin_PS4_DPad_East,
	k_EInputActionOrigin_PS4_Gyro_Move,
	k_EInputActionOrigin_PS4_Gyro_Pitch,
	k_EInputActionOrigin_PS4_Gyro_Yaw,
	k_EInputActionOrigin_PS4_Gyro_Roll,
	k_EInputActionOrigin_PS4_DPad_Move,
	k_EInputActionOrigin_PS4_Reserved1,
	k_EInputActionOrigin_PS4_Reserved2,
	k_EInputActionOrigin_PS4_Reserved3,
	k_EInputActionOrigin_PS4_Reserved4,
	k_EInputActionOrigin_PS4_Reserved5,
	k_EInputActionOrigin_PS4_Reserved6,
	k_EInputActionOrigin_PS4_Reserved7,
	k_EInputActionOrigin_PS4_Reserved8,
	k_EInputActionOrigin_PS4_Reserved9,
	k_EInputActionOrigin_PS4_Reserved10,
	k_EInputActionOrigin_XBoxOne_A,
	k_EInputActionOrigin_XBoxOne_B,
	k_EInputActionOrigin_XBoxOne_X,
	k_EInputActionOrigin_XBoxOne_Y,
	k_EInputActionOrigin_XBoxOne_LeftBumper,
	k_EInputActionOrigin_XBoxOne_RightBumper,
	k_EInputActionOrigin_XBoxOne_Menu,
	k_EInputActionOrigin_XBoxOne_View,
	k_EInputActionOrigin_XBoxOne_LeftTrigger_Pull,
	k_EInputActionOrigin_XBoxOne_LeftTrigger_Click,
	k_EInputActionOrigin_XBoxOne_RightTrigger_Pull,
	k_EInputActionOrigin_XBoxOne_RightTrigger_Click,
	k_EInputActionOrigin_XBoxOne_LeftStick_Move,
	k_EInputActionOrigin_XBoxOne_LeftStick_Click,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadNorth,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadSouth,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadWest,
	k_EInputActionOrigin_XBoxOne_LeftStick_DPadEast,
	k_EInputActionOrigin_XBoxOne_RightStick_Move,
	k_EInputActionOrigin_XBoxOne_RightStick_Click,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadNorth,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadSouth,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadWest,
	k_EInputActionOrigin_XBoxOne_RightStick_DPadEast,
	k_EInputActionOrigin_XBoxOne_DPad_North,
	k_EInputActionOrigin_XBoxOne_DPad_South,
	k_EInputActionOrigin_XBoxOne_DPad_West,
	k_EInputActionOrigin_XBoxOne_DPad_East,
	k_EInputActionOrigin_XBoxOne_DPad_Move,
	k_EInputActionOrigin_XBoxOne_LeftGrip_Lower,
	k_EInputActionOrigin_XBoxOne_LeftGrip_Upper,
	k_EInputActionOrigin_XBoxOne_RightGrip_Lower,
	k_EInputActionOrigin_XBoxOne_RightGrip_Upper,
	k_EInputActionOrigin_XBoxOne_Share,
	k_EInputActionOrigin_XBoxOne_Reserved6,
	k_EInputActionOrigin_XBoxOne_Reserved7,
	k_EInputActionOrigin_XBoxOne_Reserved8,
	k_EInputActionOrigin_XBoxOne_Reserved9,
	k_EInputActionOrigin_XBoxOne_Reserved10,
	k_EInputActionOrigin_XBox360_A,
	k_EInputActionOrigin_XBox360_B,
	k_EInputActionOrigin_XBox360_X,
	k_EInputActionOrigin_XBox360_Y,
	k_EInputActionOrigin_XBox360_LeftBumper,
	k_EInputActionOrigin_XBox360_RightBumper,
	k_EInputActionOrigin_XBox360_Start,
	k_EInputActionOrigin_XBox360_Back,
	k_EInputActionOrigin_XBox360_LeftTrigger_Pull,
	k_EInputActionOrigin_XBox360_LeftTrigger_Click,
	k_EInputActionOrigin_XBox360_RightTrigger_Pull,
	k_EInputActionOrigin_XBox360_RightTrigger_Click,
	k_EInputActionOrigin_XBox360_LeftStick_Move,
	k_EInputActionOrigin_XBox360_LeftStick_Click,
	k_EInputActionOrigin_XBox360_LeftStick_DPadNorth,
	k_EInputActionOrigin_XBox360_LeftStick_DPadSouth,
	k_EInputActionOrigin_XBox360_LeftStick_DPadWest,
	k_EInputActionOrigin_XBox360_LeftStick_DPadEast,
	k_EInputActionOrigin_XBox360_RightStick_Move,
	k_EInputActionOrigin_XBox360_RightStick_Click,
	k_EInputActionOrigin_XBox360_RightStick_DPadNorth,
	k_EInputActionOrigin_XBox360_RightStick_DPadSouth,
	k_EInputActionOrigin_XBox360_RightStick_DPadWest,
	k_EInputActionOrigin_XBox360_RightStick_DPadEast,
	k_EInputActionOrigin_XBox360_DPad_North,
	k_EInputActionOrigin_XBox360_DPad_South,
	k_EInputActionOrigin_XBox360_DPad_West,
	k_EInputActionOrigin_XBox360_DPad_East,
	k_EInputActionOrigin_XBox360_DPad_Move,
	k_EInputActionOrigin_XBox360_Reserved1,
	k_EInputActionOrigin_XBox360_Reserved2,
	k_EInputActionOrigin_XBox360_Reserved3,
	k_EInputActionOrigin_XBox360_Reserved4,
	k_EInputActionOrigin_XBox360_Reserved5,
	k_EInputActionOrigin_XBox360_Reserved6,
	k_EInputActionOrigin_XBox360_Reserved7,
	k_EInputActionOrigin_XBox360_Reserved8,
	k_EInputActionOrigin_XBox360_Reserved9,
	k_EInputActionOrigin_XBox360_Reserved10,
	k_EInputActionOrigin_Switch_A,
	k_EInputActionOrigin_Switch_B,
	k_EInputActionOrigin_Switch_X,
	k_EInputActionOrigin_Switch_Y,
	k_EInputActionOrigin_Switch_LeftBumper,
	k_EInputActionOrigin_Switch_RightBumper,
	k_EInputActionOrigin_Switch_Plus,
	k_EInputActionOrigin_Switch_Minus,
	k_EInputActionOrigin_Switch_Capture,
	k_EInputActionOrigin_Switch_LeftTrigger_Pull,
	k_EInputActionOrigin_Switch_LeftTrigger_Click,
	k_EInputActionOrigin_Switch_RightTrigger_Pull,
	k_EInputActionOrigin_Switch_RightTrigger_Click,
	k_EInputActionOrigin_Switch_LeftStick_Move,
	k_EInputActionOrigin_Switch_LeftStick_Click,
	k_EInputActionOrigin_Switch_LeftStick_DPadNorth,
	k_EInputActionOrigin_Switch_LeftStick_DPadSouth,
	k_EInputActionOrigin_Switch_LeftStick_DPadWest,
	k_EInputActionOrigin_Switch_LeftStick_DPadEast,
	k_EInputActionOrigin_Switch_RightStick_Move,
	k_EInputActionOrigin_Switch_RightStick_Click,
	k_EInputActionOrigin_Switch_RightStick_DPadNorth,
	k_EInputActionOrigin_Switch_RightStick_DPadSouth,
	k_EInputActionOrigin_Switch_RightStick_DPadWest,
	k_EInputActionOrigin_Switch_RightStick_DPadEast,
	k_EInputActionOrigin_Switch_DPad_North,
	k_EInputActionOrigin_Switch_DPad_South,
	k_EInputActionOrigin_Switch_DPad_West,
	k_EInputActionOrigin_Switch_DPad_East,
	k_EInputActionOrigin_Switch_ProGyro_Move,
	k_EInputActionOrigin_Switch_ProGyro_Pitch,
	k_EInputActionOrigin_Switch_ProGyro_Yaw,
	k_EInputActionOrigin_Switch_ProGyro_Roll,
	k_EInputActionOrigin_Switch_DPad_Move,
	k_EInputActionOrigin_Switch_Reserved1,
	k_EInputActionOrigin_Switch_Reserved2,
	k_EInputActionOrigin_Switch_Reserved3,
	k_EInputActionOrigin_Switch_Reserved4,
	k_EInputActionOrigin_Switch_Reserved5,
	k_EInputActionOrigin_Switch_Reserved6,
	k_EInputActionOrigin_Switch_Reserved7,
	k_EInputActionOrigin_Switch_Reserved8,
	k_EInputActionOrigin_Switch_Reserved9,
	k_EInputActionOrigin_Switch_Reserved10,
	k_EInputActionOrigin_Switch_RightGyro_Move,
	k_EInputActionOrigin_Switch_RightGyro_Pitch,
	k_EInputActionOrigin_Switch_RightGyro_Yaw,
	k_EInputActionOrigin_Switch_RightGyro_Roll,
	k_EInputActionOrigin_Switch_LeftGyro_Move,
	k_EInputActionOrigin_Switch_LeftGyro_Pitch,
	k_EInputActionOrigin_Switch_LeftGyro_Yaw,
	k_EInputActionOrigin_Switch_LeftGyro_Roll,
	k_EInputActionOrigin_Switch_LeftGrip_Lower,
	k_EInputActionOrigin_Switch_LeftGrip_Upper,
	k_EInputActionOrigin_Switch_RightGrip_Lower,
	k_EInputActionOrigin_Switch_RightGrip_Upper,
	k_EInputActionOrigin_Switch_JoyConButton_N,
	k_EInputActionOrigin_Switch_JoyConButton_E,
	k_EInputActionOrigin_Switch_JoyConButton_S,
	k_EInputActionOrigin_Switch_JoyConButton_W,
	k_EInputActionOrigin_Switch_Reserved15,
	k_EInputActionOrigin_Switch_Reserved16,
	k_EInputActionOrigin_Switch_Reserved17,
	k_EInputActionOrigin_Switch_Reserved18,
	k_EInputActionOrigin_Switch_Reserved19,
	k_EInputActionOrigin_Switch_Reserved20,
	k_EInputActionOrigin_PS5_X,
	k_EInputActionOrigin_PS5_Circle,
	k_EInputActionOrigin_PS5_Triangle,
	k_EInputActionOrigin_PS5_Square,
	k_EInputActionOrigin_PS5_LeftBumper,
	k_EInputActionOrigin_PS5_RightBumper,
	k_EInputActionOrigin_PS5_Option,
	k_EInputActionOrigin_PS5_Create,
	k_EInputActionOrigin_PS5_Mute,
	k_EInputActionOrigin_PS5_LeftPad_Touch,
	k_EInputActionOrigin_PS5_LeftPad_Swipe,
	k_EInputActionOrigin_PS5_LeftPad_Click,
	k_EInputActionOrigin_PS5_LeftPad_DPadNorth,
	k_EInputActionOrigin_PS5_LeftPad_DPadSouth,
	k_EInputActionOrigin_PS5_LeftPad_DPadWest,
	k_EInputActionOrigin_PS5_LeftPad_DPadEast,
	k_EInputActionOrigin_PS5_RightPad_Touch,
	k_EInputActionOrigin_PS5_RightPad_Swipe,
	k_EInputActionOrigin_PS5_RightPad_Click,
	k_EInputActionOrigin_PS5_RightPad_DPadNorth,
	k_EInputActionOrigin_PS5_RightPad_DPadSouth,
	k_EInputActionOrigin_PS5_RightPad_DPadWest,
	k_EInputActionOrigin_PS5_RightPad_DPadEast,
	k_EInputActionOrigin_PS5_CenterPad_Touch,
	k_EInputActionOrigin_PS5_CenterPad_Swipe,
	k_EInputActionOrigin_PS5_CenterPad_Click,
	k_EInputActionOrigin_PS5_CenterPad_DPadNorth,
	k_EInputActionOrigin_PS5_CenterPad_DPadSouth,
	k_EInputActionOrigin_PS5_CenterPad_DPadWest,
	k_EInputActionOrigin_PS5_CenterPad_DPadEast,
	k_EInputActionOrigin_PS5_LeftTrigger_Pull,
	k_EInputActionOrigin_PS5_LeftTrigger_Click,
	k_EInputActionOrigin_PS5_RightTrigger_Pull,
	k_EInputActionOrigin_PS5_RightTrigger_Click,
	k_EInputActionOrigin_PS5_LeftStick_Move,
	k_EInputActionOrigin_PS5_LeftStick_Click,
	k_EInputActionOrigin_PS5_LeftStick_DPadNorth,
	k_EInputActionOrigin_PS5_LeftStick_DPadSouth,
	k_EInputActionOrigin_PS5_LeftStick_DPadWest,
	k_EInputActionOrigin_PS5_LeftStick_DPadEast,
	k_EInputActionOrigin_PS5_RightStick_Move,
	k_EInputActionOrigin_PS5_RightStick_Click,
	k_EInputActionOrigin_PS5_RightStick_DPadNorth,
	k_EInputActionOrigin_PS5_RightStick_DPadSouth,
	k_EInputActionOrigin_PS5_RightStick_DPadWest,
	k_EInputActionOrigin_PS5_RightStick_DPadEast,
	k_EInputActionOrigin_PS5_DPad_North,
	k_EInputActionOrigin_PS5_DPad_South,
	k_EInputActionOrigin_PS5_DPad_West,
	k_EInputActionOrigin_PS5_DPad_East,
	k_EInputActionOrigin_PS5_Gyro_Move,
	k_EInputActionOrigin_PS5_Gyro_Pitch,
	k_EInputActionOrigin_PS5_Gyro_Yaw,
	k_EInputActionOrigin_PS5_Gyro_Roll,
	k_EInputActionOrigin_PS5_DPad_Move,
	k_EInputActionOrigin_PS5_LeftGrip,
	k_EInputActionOrigin_PS5_RightGrip,
	k_EInputActionOrigin_PS5_LeftFn,
	k_EInputActionOrigin_PS5_RightFn,
	k_EInputActionOrigin_PS5_Reserved5,
	k_EInputActionOrigin_PS5_Reserved6,
	k_EInputActionOrigin_PS5_Reserved7,
	k_EInputActionOrigin_PS5_Reserved8,
	k_EInputActionOrigin_PS5_Reserved9,
	k_EInputActionOrigin_PS5_Reserved10,
	k_EInputActionOrigin_PS5_Reserved11,
	k_EInputActionOrigin_PS5_Reserved12,
	k_EInputActionOrigin_PS5_Reserved13,
	k_EInputActionOrigin_PS5_Reserved14,
	k_EInputActionOrigin_PS5_Reserved15,
	k_EInputActionOrigin_PS5_Reserved16,
	k_EInputActionOrigin_PS5_Reserved17,
	k_EInputActionOrigin_PS5_Reserved18,
	k_EInputActionOrigin_PS5_Reserved19,
	k_EInputActionOrigin_PS5_Reserved20,
	k_EInputActionOrigin_SteamDeck_A,
	k_EInputActionOrigin_SteamDeck_B,
	k_EInputActionOrigin_SteamDeck_X,
	k_EInputActionOrigin_SteamDeck_Y,
	k_EInputActionOrigin_SteamDeck_L1,
	k_EInputActionOrigin_SteamDeck_R1,
	k_EInputActionOrigin_SteamDeck_Menu,
	k_EInputActionOrigin_SteamDeck_View,
	k_EInputActionOrigin_SteamDeck_LeftPad_Touch,
	k_EInputActionOrigin_SteamDeck_LeftPad_Swipe,
	k_EInputActionOrigin_SteamDeck_LeftPad_Click,
	k_EInputActionOrigin_SteamDeck_LeftPad_DPadNorth,
	k_EInputActionOrigin_SteamDeck_LeftPad_DPadSouth,
	k_EInputActionOrigin_SteamDeck_LeftPad_DPadWest,
	k_EInputActionOrigin_SteamDeck_LeftPad_DPadEast,
	k_EInputActionOrigin_SteamDeck_RightPad_Touch,
	k_EInputActionOrigin_SteamDeck_RightPad_Swipe,
	k_EInputActionOrigin_SteamDeck_RightPad_Click,
	k_EInputActionOrigin_SteamDeck_RightPad_DPadNorth,
	k_EInputActionOrigin_SteamDeck_RightPad_DPadSouth,
	k_EInputActionOrigin_SteamDeck_RightPad_DPadWest,
	k_EInputActionOrigin_SteamDeck_RightPad_DPadEast,
	k_EInputActionOrigin_SteamDeck_L2_SoftPull,
	k_EInputActionOrigin_SteamDeck_L2,
	k_EInputActionOrigin_SteamDeck_R2_SoftPull,
	k_EInputActionOrigin_SteamDeck_R2,
	k_EInputActionOrigin_SteamDeck_LeftStick_Move,
	k_EInputActionOrigin_SteamDeck_L3,
	k_EInputActionOrigin_SteamDeck_LeftStick_DPadNorth,
	k_EInputActionOrigin_SteamDeck_LeftStick_DPadSouth,
	k_EInputActionOrigin_SteamDeck_LeftStick_DPadWest,
	k_EInputActionOrigin_SteamDeck_LeftStick_DPadEast,
	k_EInputActionOrigin_SteamDeck_LeftStick_Touch,
	k_EInputActionOrigin_SteamDeck_RightStick_Move,
	k_EInputActionOrigin_SteamDeck_R3,
	k_EInputActionOrigin_SteamDeck_RightStick_DPadNorth,
	k_EInputActionOrigin_SteamDeck_RightStick_DPadSouth,
	k_EInputActionOrigin_SteamDeck_RightStick_DPadWest,
	k_EInputActionOrigin_SteamDeck_RightStick_DPadEast,
	k_EInputActionOrigin_SteamDeck_RightStick_Touch,
	k_EInputActionOrigin_SteamDeck_L4,
	k_EInputActionOrigin_SteamDeck_R4,
	k_EInputActionOrigin_SteamDeck_L5,
	k_EInputActionOrigin_SteamDeck_R5,
	k_EInputActionOrigin_SteamDeck_DPad_Move,
	k_EInputActionOrigin_SteamDeck_DPad_North,
	k_EInputActionOrigin_SteamDeck_DPad_South,
	k_EInputActionOrigin_SteamDeck_DPad_West,
	k_EInputActionOrigin_SteamDeck_DPad_East,
	k_EInputActionOrigin_SteamDeck_Gyro_Move,
	k_EInputActionOrigin_SteamDeck_Gyro_Pitch,
	k_EInputActionOrigin_SteamDeck_Gyro_Yaw,
	k_EInputActionOrigin_SteamDeck_Gyro_Roll,
	k_EInputActionOrigin_SteamDeck_Reserved1,
	k_EInputActionOrigin_SteamDeck_Reserved2,
	k_EInputActionOrigin_SteamDeck_Reserved3,
	k_EInputActionOrigin_SteamDeck_Reserved4,
	k_EInputActionOrigin_SteamDeck_Reserved5,
	k_EInputActionOrigin_SteamDeck_Reserved6,
	k_EInputActionOrigin_SteamDeck_Reserved7,
	k_EInputActionOrigin_SteamDeck_Reserved8,
	k_EInputActionOrigin_SteamDeck_Reserved9,
	k_EInputActionOrigin_SteamDeck_Reserved10,
	k_EInputActionOrigin_SteamDeck_Reserved11,
	k_EInputActionOrigin_SteamDeck_Reserved12,
	k_EInputActionOrigin_SteamDeck_Reserved13,
	k_EInputActionOrigin_SteamDeck_Reserved14,
	k_EInputActionOrigin_SteamDeck_Reserved15,
	k_EInputActionOrigin_SteamDeck_Reserved16,
	k_EInputActionOrigin_SteamDeck_Reserved17,
	k_EInputActionOrigin_SteamDeck_Reserved18,
	k_EInputActionOrigin_SteamDeck_Reserved19,
	k_EInputActionOrigin_SteamDeck_Reserved20,
	k_EInputActionOrigin_Count,
	k_EInputActionOrigin_MaximumPossibleValue = 32767

} EInputActionOrigin, *pEInputActionOrigin;

typedef enum _EXboxOrigin_ {

	k_EXboxOrigin_A,
	k_EXboxOrigin_B,
	k_EXboxOrigin_X,
	k_EXboxOrigin_Y,
	k_EXboxOrigin_LeftBumper,
	k_EXboxOrigin_RightBumper,
	k_EXboxOrigin_Menu,
	k_EXboxOrigin_View,
	k_EXboxOrigin_LeftTrigger_Pull,
	k_EXboxOrigin_LeftTrigger_Click,
	k_EXboxOrigin_RightTrigger_Pull,
	k_EXboxOrigin_RightTrigger_Click,
	k_EXboxOrigin_LeftStick_Move,
	k_EXboxOrigin_LeftStick_Click,
	k_EXboxOrigin_LeftStick_DPadNorth,
	k_EXboxOrigin_LeftStick_DPadSouth,
	k_EXboxOrigin_LeftStick_DPadWest,
	k_EXboxOrigin_LeftStick_DPadEast,
	k_EXboxOrigin_RightStick_Move,
	k_EXboxOrigin_RightStick_Click,
	k_EXboxOrigin_RightStick_DPadNorth,
	k_EXboxOrigin_RightStick_DPadSouth,
	k_EXboxOrigin_RightStick_DPadWest,
	k_EXboxOrigin_RightStick_DPadEast,
	k_EXboxOrigin_DPad_North,
	k_EXboxOrigin_DPad_South,
	k_EXboxOrigin_DPad_West,
	k_EXboxOrigin_DPad_East,
	k_EXboxOrigin_Count

} EXboxOrigin, *pEXboxOrigin;

typedef enum _ESteamControllerPad_ {

	k_ESteamControllerPad_Left,
	k_ESteamControllerPad_Right

} ESteamControllerPad, *pESteamControllerPad;

typedef enum _EControllerHapticLocation_ {

	k_EControllerHapticLocation_Left = (1 << k_ESteamControllerPad_Left),
	k_EControllerHapticLocation_Right = (1 << k_ESteamControllerPad_Right),
	k_EControllerHapticLocation_Both = (1 << k_ESteamControllerPad_Left | 1 << k_ESteamControllerPad_Right)

} EControllerHapticLocation, *pEControllerHapticLocation;

typedef enum _EControllerHapticType_ {

	k_EControllerHapticType_Off,
	k_EControllerHapticType_Tick,
	k_EControllerHapticType_Click

} EControllerHapticType, *pEControllerHapticType;

typedef enum _ESteamInputType_ {

	k_ESteamInputType_Unknown,
	k_ESteamInputType_SteamController,
	k_ESteamInputType_XBox360Controller,
	k_ESteamInputType_XBoxOneController,
	k_ESteamInputType_GenericGamepad,
	k_ESteamInputType_PS4Controller,
	k_ESteamInputType_AppleMFiController,
	k_ESteamInputType_AndroidController,
	k_ESteamInputType_SwitchJoyConPair,
	k_ESteamInputType_SwitchJoyConSingle,
	k_ESteamInputType_SwitchProController,
	k_ESteamInputType_MobileTouch,
	k_ESteamInputType_PS3Controller,
	k_ESteamInputType_PS5Controller,
	k_ESteamInputType_SteamDeckController,
	k_ESteamInputType_Count,
	k_ESteamInputType_MaximumPossibleValue = 255

} ESteamInputType, *pESteamInputType;

typedef enum _ESteamInputConfigurationEnableType_ {

	k_ESteamInputConfigurationEnableType_None = 0x00000000,
	k_ESteamInputConfigurationEnableType_Playstation = 0x00000001,
	k_ESteamInputConfigurationEnableType_Xbox = 0x00000002,
	k_ESteamInputConfigurationEnableType_Generic = 0x00000004,
	k_ESteamInputConfigurationEnableType_Switch = 0x00000008

} ESteamInputConfigurationEnableType, *pESteamInputConfigurationEnableType;

typedef enum _ESteamInputLEDFlag_ {

	k_ESteamInputLEDFlag_SetColor,
	k_ESteamInputLEDFlag_RestoreUserDefault

} ESteamInputLEDFlag, *pESteamInputLEDFlag;

typedef enum _ESteamInputGlyphSize_ {

	k_ESteamInputGlyphSize_Small,
	k_ESteamInputGlyphSize_Medium,
	k_ESteamInputGlyphSize_Large,
	k_ESteamInputGlyphSize_Count

} ESteamInputGlyphSize, *pESteamInputGlyphSize;

typedef enum _ESteamInputGlyphStyle_ {

	ESteamInputGlyphStyle_Knockout = 0x00,
	ESteamInputGlyphStyle_Light = 0x01,
	ESteamInputGlyphStyle_Dark = 0x02,
	ESteamInputGlyphStyle_NeutralColorABXY = 0x10,
	ESteamInputGlyphStyle_SolidABXY = 0x20

} ESteamInputGlyphStyle, *pESteamInputGlyphStyle;

typedef enum _ESteamInputActionEventType_ {

	ESteamInputActionEventType_DigitalAction,
	ESteamInputActionEventType_AnalogAction

} ESteamInputActionEventType, *pESteamInputActionEventType;

typedef Uint64 InputHandle_t, *pInputHandle_t;
typedef Uint64 InputActionSetHandle_t, *pInputActionSetHandle_t;
typedef Uint64 InputDigitalActionHandle_t, *pInputDigitalActionHandle_t;
typedef Uint64 InputAnalogActionHandle_t, *pInputAnalogActionHandle_t;

#pragma pack(push, 1)

typedef struct _InputAnalogActionData_t_ {
	
	EInputSourceMode eInputSourceMode;
	Float x, y;
	Bool bActive;

} InputAnalogActionData_t, *pInputAnalogActionData_t;

typedef struct _InputDigitalActionData_t_ {
	
	Bool bState;
	Bool bActive;

} InputDigitalActionData_t, *pInputDigitalActionData_t;

typedef struct _InputMotionData_t_ {

	Float rotQuatX;
	Float rotQuatY;
	Float rotQuatZ;
	Float rotQuatW;
	Float posAccelX;
	Float posAccelY;
	Float posAccelZ;
	Float rotVelX;
	Float rotVelY;
	Float rotVelZ;

} InputMotionData_t, *pInputMotionData_t;

typedef struct _InputMotionDataV2_t_ {
	
	Float driftCorrectedQuatX;
	Float driftCorrectedQuatY;
	Float driftCorrectedQuatZ;
	Float driftCorrectedQuatW;
	Float sensorFusionQuatX;
	Float sensorFusionQuatY;
	Float sensorFusionQuatZ;
	Float sensorFusionQuatW;
	Float deferredSensorFusionQuatX;
	Float deferredSensorFusionQuatY;
	Float deferredSensorFusionQuatZ;
	Float deferredSensorFusionQuatW;

	/* Same as accel but values are calibrated such that 1 nit = 1G.
	    X = Right
	    Y = Forward out through the joystick USB port.
	    Z = Up through the joystick axis. */
	Float gravityX;
	Float gravityY;
	Float gravityZ;

	/* Local Space (controller relative)
	   X = Pitch = left to right axis
	   Y = Roll = axis through charging port
	   Z = Yaw = axis through sticks */
	Float degreesPerSecondX;
	Float degreesPerSecondY;
	Float degreesPerSecondZ;

} InputMotionDataV2_t, *pInputMotionDataV2_t;

// -----------------------------------------------------------------------------
// Purpose: When callbacks are enabled this fires each time a controller action
//  state changes
// -----------------------------------------------------------------------------
typedef struct _SteamInputActionEvent_t_ {

	InputHandle_t hController;
	ESteamInputActionEventType eSteamInputActionEventType;

	union {

		struct {
			InputAnalogActionHandle_t hAction;
			InputAnalogActionData_t hAnalogAction;
		};

		struct {
			InputDigitalActionHandle_t hAction;
			InputDigitalActionData_t hDigitalAction;
		};

	} x;

} SteamInputActionEvent_t, *pSteamInputActionEvent_t;

typedef struct _ScePadTriggerEffectOff_ {

	Uint8 Padding[48];

} ScePadTriggerEffectOff, *pScePadTriggerEffectOff;
typedef struct _ScePadTriggerEffectFeedback_ {

	Uint8 Position;
	Uint8 Strength;
	Uint8 Padding[46];

} ScePadTriggerEffectFeedback, *pScePadTriggerEffectFeedback;
typedef struct _ScePadTriggerEffectWeapon_ {

	Uint8 StartPosition;
	Uint8 EndPosition;
	Uint8 Strength;
	Uint8 Padding[45];

} ScePadTriggerEffectWeapon, *pScePadTriggerEffectWeapon;
typedef struct _ScePadTriggerEffectVibration_ {

	Uint8 Position;
	Uint8 Amplitude;
	Uint8 Frequency;
	Uint8 Padding[45];

} ScePadTriggerEffectVibration, *pScePadTriggerEffectVibration;
typedef struct _ScePadTriggerEffectMultiplePositionFeedback_ {

	Uint8 Strength[10];
	Uint8 Padding[38];

} ScePadTriggerEffectMultiplePositionFeedback, *pScePadTriggerEffectMultiplePositionFeedback;
typedef struct _ScePadTriggerEffectSlopeFeedback_ {

	Uint8 StartPosition;
	Uint8 EndPosition;
	Uint8 StartStrength;
	Uint8 EndStrength;
	Uint8 Padding[44];

} ScePadTriggerEffectSlopeFeedback, *pScePadTriggerEffectSlopeFeedback;
typedef struct _ScePadTriggerEffectMultiplePositionVibration_ {

	Uint8 Frequency;
	Uint8 Amplitude[10];
	Uint8 Padding[37];

} ScePadTriggerEffectMultiplePositionVibration, *pScePadTriggerEffectMultiplePositionVibration;
typedef struct _ScePadTriggerEffect_ {

	Uint8 TriggerMask;
	Uint8 Padding[7];

	union {

		ScePadTriggerEffectOff ScePadTriggerEffectOff;
		ScePadTriggerEffectFeedback ScePadTriggerEffectFeedback;
		ScePadTriggerEffectWeapon ScePadTriggerEffectWeapon;
		ScePadTriggerEffectVibration ScePadTriggerEffectVibration;
		ScePadTriggerEffectMultiplePositionFeedback ScePadTriggerEffectMultiplePositionFeedback;
		ScePadTriggerEffectSlopeFeedback ScePadTriggerEffectSlopeFeedback;
		ScePadTriggerEffectMultiplePositionVibration ScePadTriggerEffectMultiplePositionVibration;

	} Command[2];

} ScePadTriggerEffect, *pScePadTriggerEffect;

#pragma pack(pop)

typedef void (*SteamInputActionEventCallback) (pSteamInputActionEvent_t pSteamInputActionEvent);

typedef class _ISteamInput001_ {
public:

	virtual Bool Init(Bool bExplicitlyCallRunFrame) = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame(Bool bReservedValue) = 0;
	virtual Int32 GetConnectedControllers(pInputHandle_t hController) = 0;
	virtual InputActionSetHandle_t GetActionSetHandle(const pStrA pszActionSetName) = 0;
	virtual void ActivateActionSet(InputHandle_t hController, InputActionSetHandle_t hActionSet) = 0;
	virtual InputActionSetHandle_t GetCurrentActionSet(InputHandle_t hController) = 0;
	virtual void ActivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateAllActionSetLayers(InputHandle_t hController) = 0;
	virtual Int32 GetActiveActionSetLayers(InputHandle_t hController, pInputActionSetHandle_t phController) = 0;
	virtual InputDigitalActionHandle_t GetDigitalActionHandle(const pStrA pszActionName) = 0;
	virtual InputDigitalActionData_t GetDigitalActionData(InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, pEInputActionOrigin peInputActionOrigin) = 0;
	virtual InputAnalogActionHandle_t GetAnalogActionHandle(const pStrA pszActionName) = 0;
	virtual InputAnalogActionData_t GetAnalogActionData(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, pEInputActionOrigin peInputActionOrigin) = 0;
	virtual const pStrA GetGlyphForActionOrigin_Legacy(EInputActionOrigin eInputActionOrigin) = 0;
	virtual const pStrA GetStringForActionOrigin(EInputActionOrigin eInputActionOrigin) = 0;
	virtual void StopAnalogActionMomentum(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual InputMotionData_t GetMotionData(InputHandle_t hController) = 0;
	virtual void TriggerVibration(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void SetLEDColor(InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;
	virtual void Legacy_TriggerHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void Legacy_TriggerRepeatedHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual Bool ShowBindingPanel(InputHandle_t hController) = 0;
	virtual ESteamInputType GetInputTypeForHandle(InputHandle_t hController) = 0;
	virtual InputHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual Int32 GetGamepadIndexForController(InputHandle_t hController) = 0;
	virtual const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual EInputActionOrigin GetActionOriginFromXboxOrigin(InputHandle_t hController, EXboxOrigin eXboxOrigin) = 0;
	virtual EInputActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceXboxOrigin) = 0;
	virtual Bool GetDeviceBindingRevision(InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) = 0;
	virtual Uint32 GetRemotePlaySessionID(InputHandle_t hController) = 0;

} ISteamInput001, *IpSteamInput001;

typedef class _ISteamInput002_ {
public:

	virtual Bool Init(Bool bExplicitlyCallRunFrame) = 0;
	virtual Bool Shutdown() = 0;
	virtual void RunFrame(Bool bReservedValue) = 0;
	virtual Int32 GetConnectedControllers(pInputHandle_t hController) = 0;
	virtual InputActionSetHandle_t GetActionSetHandle(const pStrA pszActionSetName) = 0;
	virtual void ActivateActionSet(InputHandle_t hController, InputActionSetHandle_t hActionSet) = 0;
	virtual InputActionSetHandle_t GetCurrentActionSet(InputHandle_t hController) = 0;
	virtual void ActivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateAllActionSetLayers(InputHandle_t hController) = 0;
	virtual Int32 GetActiveActionSetLayers(InputHandle_t hController, pInputActionSetHandle_t phController) = 0;
	virtual InputDigitalActionHandle_t GetDigitalActionHandle(const pStrA pszActionName) = 0;
	virtual InputDigitalActionData_t GetDigitalActionData(InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, pEInputActionOrigin peInputActionOrigin) = 0;
	virtual InputAnalogActionHandle_t GetAnalogActionHandle(const pStrA pszActionName) = 0;
	virtual InputAnalogActionData_t GetAnalogActionData(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, pEInputActionOrigin peInputActionOrigin) = 0;
	virtual const pStrA GetGlyphForActionOrigin_Legacy(EInputActionOrigin eInputActionOrigin) = 0;
	virtual const pStrA GetStringForActionOrigin(EInputActionOrigin eInputActionOrigin) = 0;
	virtual void StopAnalogActionMomentum(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual InputMotionData_t GetMotionData(InputHandle_t hController) = 0;
	virtual void TriggerVibration(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void SetLEDColor(InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;
	virtual void Legacy_TriggerHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void Legacy_TriggerRepeatedHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual Bool ShowBindingPanel(InputHandle_t hController) = 0;
	virtual ESteamInputType GetInputTypeForHandle(InputHandle_t hController) = 0;
	virtual InputHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual Int32 GetGamepadIndexForController(InputHandle_t hController) = 0;
	virtual const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual EInputActionOrigin GetActionOriginFromXboxOrigin(InputHandle_t hController, EXboxOrigin eXboxOrigin) = 0;
	virtual EInputActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceXboxOrigin) = 0;
	virtual Bool GetDeviceBindingRevision(InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) = 0;
	virtual Uint32 GetRemotePlaySessionID(InputHandle_t hController) = 0;

} ISteamInput002, *IpSteamInput002;

typedef class _ISteamInput005_ {
public:

	virtual Bool Init(Bool bExplicitlyCallRunFrame) = 0;
	virtual Bool Shutdown() = 0;
	virtual Bool SetInputActionManifestFilePath(const pStrA pchInputActionManifestAbsolutePath) = 0;
	virtual void RunFrame(Bool bReservedValue) = 0;
	virtual Bool BWaitForData(Bool bWaitForever, Uint32 Timeout) = 0;
	virtual Bool BNewDataAvailable() = 0;
	virtual Int32 GetConnectedControllers(pInputHandle_t hController) = 0;
	virtual void EnableDeviceCallbacks() = 0;
	virtual void EnableActionEventCallbacks(SteamInputActionEventCallback pFunction) = 0;
	virtual InputActionSetHandle_t GetActionSetHandle(const pStrA pszActionSetName) = 0;
	virtual void ActivateActionSet(InputHandle_t hController, InputActionSetHandle_t hActionSet) = 0;
	virtual InputActionSetHandle_t GetCurrentActionSet(InputHandle_t hController) = 0;
	virtual void ActivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateAllActionSetLayers(InputHandle_t hController) = 0;
	virtual Int32 GetActiveActionSetLayers(InputHandle_t hController, pInputActionSetHandle_t phController) = 0;
	virtual InputDigitalActionHandle_t GetDigitalActionHandle(const pStrA pszActionName) = 0;
	virtual InputDigitalActionData_t GetDigitalActionData(InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, pEInputActionOrigin peInputActionOrigin) = 0;
	virtual const pStrA GetStringForDigitalActionName(InputDigitalActionHandle_t hDigitalAction) = 0;
	virtual InputAnalogActionHandle_t GetAnalogActionHandle(const pStrA pszActionName) = 0;
	virtual InputAnalogActionData_t GetAnalogActionData(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, pEInputActionOrigin peInputActionOrigin) = 0;
	virtual const pStrA GetGlyphPNGForActionOrigin(EInputActionOrigin eInputActionOrigin, ESteamInputGlyphSize eSteamInputGlyphSize, Uint32 nFlags) = 0;
	virtual const pStrA GetGlyphSVGForActionOrigin(EInputActionOrigin eInputActionOrigin, Uint32 nFlags) = 0;
	virtual const pStrA GetGlyphForActionOrigin_Legacy(EInputActionOrigin eInputActionOrigin) = 0;
	virtual const pStrA GetStringForActionOrigin(EInputActionOrigin eInputActionOrigin) = 0;
	virtual const pStrA GetStringForAnalogActionName(InputAnalogActionHandle_t hDigitalAction) = 0;
	virtual void StopAnalogActionMomentum(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual InputMotionData_t GetMotionData(InputHandle_t hController) = 0;
	virtual void TriggerVibration(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void TriggerVibrationExtended(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed, Uint16 LeftTriggerSpeed, Uint16 RightTriggerSpeed) = 0;
	virtual void TriggerSimpleHapticEvent(InputHandle_t hController, EControllerHapticLocation eControllerHapticLocation, Uint8 nIntensity, Uint8 nGainDB, Uint8 nOtherIntensity, Uint8 nOtherGainDB) = 0;
	virtual void SetLEDColor(InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;
	virtual void Legacy_TriggerHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void Legacy_TriggerRepeatedHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;
	virtual Bool ShowBindingPanel(InputHandle_t hController) = 0;
	virtual ESteamInputType GetInputTypeForHandle(InputHandle_t hController) = 0;
	virtual InputHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual Int32 GetGamepadIndexForController(InputHandle_t hController) = 0;
	virtual const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual EInputActionOrigin GetActionOriginFromXboxOrigin(InputHandle_t hController, EXboxOrigin eXboxOrigin) = 0;
	virtual EInputActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceXboxOrigin) = 0;
	virtual Bool GetDeviceBindingRevision(InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) = 0;
	virtual Uint32 GetRemotePlaySessionID(InputHandle_t hController) = 0;
	virtual Uint16 GetSessionInputConfigurationSettings() = 0;

} ISteamInput005, *IpSteamInput005;

// -----------------------------------------------------------------------------
// Purpose: Steam Input API
// -----------------------------------------------------------------------------
typedef class _ISteamInput_ {
public:

	virtual Bool Init(Bool bExplicitlyCallRunFrame) = 0;
	virtual Bool Shutdown() = 0;
	virtual Bool SetInputActionManifestFilePath(const pStrA pchInputActionManifestAbsolutePath) = 0;

	/* Synchronize API state with the latest Steam Input action data available. This
	    is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
	    possible latency, you call this directly before reading controller state. */
	virtual void RunFrame(Bool bReservedValue) = 0;

	virtual Bool BWaitForData(Bool bWaitForever, Uint32 Timeout) = 0;
	virtual Bool BNewDataAvailable() = 0;
	virtual Int32 GetConnectedControllers(/* [out(k_SteamInputMaxCount)] */ pInputHandle_t hController) = 0;

	virtual void EnableDeviceCallbacks() = 0;
	virtual void EnableActionEventCallbacks(SteamInputActionEventCallback pFunction) = 0;

	virtual InputActionSetHandle_t GetActionSetHandle(const pStrA pszActionSetName) = 0;
	virtual void ActivateActionSet(InputHandle_t hController, InputActionSetHandle_t hActionSet) = 0;
	virtual InputActionSetHandle_t GetCurrentActionSet(InputHandle_t hController) = 0;

	virtual void ActivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateActionSetLayer(InputHandle_t hController, InputActionSetHandle_t hActionSetLayer) = 0;
	virtual void DeactivateAllActionSetLayers(InputHandle_t hController) = 0;
	virtual Int32 GetActiveActionSetLayers(InputHandle_t hController, /* [out(k_SteamInputMaxActiveLayers)] */ pInputActionSetHandle_t phController) = 0;

	virtual InputDigitalActionHandle_t GetDigitalActionHandle(const pStrA pszActionName) = 0;
	virtual InputDigitalActionData_t GetDigitalActionData(InputHandle_t hController, InputDigitalActionHandle_t hDigitalAction) = 0;
	virtual Int32 GetDigitalActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputDigitalActionHandle_t hDigitalAction, /* [out(k_SteamInputMaxOrigins)]*/ pEInputActionOrigin peInputActionOrigin) = 0;
	virtual const pStrA GetStringForDigitalActionName(InputDigitalActionHandle_t hDigitalAction) = 0;

	virtual InputAnalogActionHandle_t GetAnalogActionHandle(const pStrA pszActionName) = 0;
	virtual InputAnalogActionData_t GetAnalogActionData(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual Int32 GetAnalogActionOrigins(InputHandle_t hController, InputActionSetHandle_t hActionSet, InputAnalogActionHandle_t hAnalogAction, /* [out(k_SteamInputMaxOrigins)]*/ pEInputActionOrigin peInputActionOrigin) = 0;
	
	virtual const pStrA GetGlyphPNGForActionOrigin(EInputActionOrigin eInputActionOrigin, ESteamInputGlyphSize eSteamInputGlyphSize, Uint32 nFlags) = 0;
	virtual const pStrA GetGlyphSVGForActionOrigin(EInputActionOrigin eInputActionOrigin, Uint32 nFlags) = 0;
	
	virtual const pStrA GetGlyphForActionOrigin_Legacy(EInputActionOrigin eInputActionOrigin) = 0;
	virtual const pStrA GetStringForActionOrigin(EInputActionOrigin eInputActionOrigin) = 0;
	
	virtual const pStrA GetStringForAnalogActionName(InputAnalogActionHandle_t hDigitalAction) = 0;
	virtual void StopAnalogActionMomentum(InputHandle_t hController, InputAnalogActionHandle_t hAnalogAction) = 0;
	virtual InputMotionData_t GetMotionData(InputHandle_t hController) = 0;

	virtual void TriggerVibration(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed) = 0;
	virtual void TriggerVibrationExtended(InputHandle_t hController, Uint16 LeftSpeed, Uint16 RightSpeed, Uint16 LeftTriggerSpeed, Uint16 RightTriggerSpeed) = 0;
	virtual void TriggerSimpleHapticEvent(InputHandle_t hController, EControllerHapticLocation eControllerHapticLocation, Uint8 nIntensity, Uint8 nGainDB, Uint8 nOtherIntensity, Uint8 nOtherGainDB) = 0;
	virtual void SetLEDColor(InputHandle_t hController, Uint8 nColorR, Uint8 nColorG, Uint8 nColorB, Uint32 nFlags) = 0;
	virtual void Legacy_TriggerHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds) = 0;
	virtual void Legacy_TriggerRepeatedHapticPulse(InputHandle_t hController, ESteamControllerPad eTargetPad, Uint16 DurationMicroSeconds, Uint16 OffMicroSeconds, Uint16 nRepeat, Uint32 nFlags) = 0;

	virtual Bool ShowBindingPanel(InputHandle_t hController) = 0;
	virtual ESteamInputType GetInputTypeForHandle(InputHandle_t hController) = 0;
	virtual InputHandle_t GetControllerForGamepadIndex(Int32 nIndex) = 0;
	virtual Int32 GetGamepadIndexForController(InputHandle_t hController) = 0;

	virtual const pStrA GetStringForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;
	virtual const pStrA GetGlyphForXboxOrigin(EXboxOrigin eXboxOrigin) = 0;

	virtual EInputActionOrigin GetActionOriginFromXboxOrigin(InputHandle_t hController, EXboxOrigin eXboxOrigin) = 0;
	/* k_EInputActionOrigin_None */
	virtual EInputActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceXboxOrigin) = 0;
	virtual Bool GetDeviceBindingRevision(InputHandle_t hController, pInt32 pMajor, pInt32 pMinor) = 0;
	virtual Uint32 GetRemotePlaySessionID(InputHandle_t hController) = 0;
	virtual Uint16 GetSessionInputConfigurationSettings() = 0;
	virtual void SetDualSenseTriggerEffect(InputHandle_t hController, const pScePadTriggerEffect pScePadTriggerEffect) = 0;

} ISteamInput, *IpSteamInput;

#define STEAMINPUT_INTERFACE_VERSION "SteamInput006"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_SteamInputDeviceConnected_t_ ((Int32)(k_iSteamControllerCallbacks + 1))
typedef struct _SteamInputDeviceConnected_t_ {

	InputHandle_t hConnectedDevice;

} SteamInputDeviceConnected_t, *pSteamInputDeviceConnected_t;

#define k_iCallbback_SteamInputDeviceDisconnected_t_ ((Int32)(k_iSteamControllerCallbacks + 2))
typedef struct _SteamInputDeviceDisconnected_t_ {

	InputHandle_t hDisconnectedDevice;

} SteamInputDeviceDisconnected_t, *pSteamInputDeviceDisconnected_t;

#define k_iCallbback_SteamInputConfigurationLoaded_t_ ((Int32)(k_iSteamControllerCallbacks + 3))
typedef struct _SteamInputConfigurationLoaded_t_ {

	AppId_t iAppId;
	InputHandle_t hDevice;
	SteamId_t MappingCreator;
	Uint32 nMajorRevision;
	Uint32 nMinorRevision;
	Bool bUsesSteamInputAPI;
	Bool bUsesGamepadAPI;

} SteamInputConfigurationLoaded_t, *pSteamInputConfigurationLoaded_t;

#define k_iCallbback_SteamInputGamepadSlotChange_t_ ((Int32)(k_iSteamControllerCallbacks + 4))
typedef struct _SteamInputGamepadSlotChange_t_ {

	AppId_t iAppId;
	InputHandle_t hDevice;
	ESteamInputType eDeviceType;
	Int32 nOldGamepadSlot;
	Int32 nNewGamepadSlot;

} SteamInputGamepadSlotChange_t, *pSteamInputGamepadSlotChange_t;

#pragma pack(pop)

#endif // _ISTEAMINPUT_
