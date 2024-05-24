// -----------------------------------------------------------------------------
#include "SteamParentalSettings.h"
// -----------------------------------------------------------------------------

Bool _SteamParentalSettings_::BIsParentalLockEnabled() {
	DEBUGBREAK("ISteamParentalSettings::BIsParentalLockEnabled");

	return False;

}

Bool _SteamParentalSettings_::BIsParentalLockLocked() {
	DEBUGBREAK("ISteamParentalSettings::BIsParentalLockLocked");

	return False;

}

Bool _SteamParentalSettings_::BIsAppBlocked(AppId_t iAppId) {
	DEBUGBREAK("ISteamParentalSettings::BIsAppBlocked");

	return False;

}

Bool _SteamParentalSettings_::BIsAppInBlockList(AppId_t iAppId) {
	DEBUGBREAK("ISteamParentalSettings::BIsAppInBlockList");

	return False;

}

Bool _SteamParentalSettings_::BIsFeatureBlocked(EParentalFeature eParentalFeature) {
	DEBUGBREAK("ISteamParentalSettings::BIsFeatureBlocked");
	
	return False;

}

Bool _SteamParentalSettings_::BIsFeatureInBlockList(EParentalFeature eParentalFeature) {
	DEBUGBREAK("ISteamParentalSettings::BIsFeatureInBlockList");

	return False;

}
