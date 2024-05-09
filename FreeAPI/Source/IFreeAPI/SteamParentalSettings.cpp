// -----------------------------------------------------------------------------
#include "SteamParentalSettings.h"
// -----------------------------------------------------------------------------

Bool _SteamParentalSettings_::BIsParentalLockEnabled() {

	return False;

}

Bool _SteamParentalSettings_::BIsParentalLockLocked() {

	return False;

}

Bool _SteamParentalSettings_::BIsAppBlocked(AppId_t iAppId) {

	return False;

}

Bool _SteamParentalSettings_::BIsAppInBlockList(AppId_t iAppId) {

	return False;

}

Bool _SteamParentalSettings_::BIsFeatureBlocked(EParentalFeature eParentalFeature) {
	
	return False;

}

Bool _SteamParentalSettings_::BIsFeatureInBlockList(EParentalFeature eParentalFeature) {

	return False;

}
