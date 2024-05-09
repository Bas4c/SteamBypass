#ifndef _STEAMPARENTALSETTINGS_
#define _STEAMPARENTALSETTINGS_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamParentalSettings.h"
// -----------------------------------------------------------------------------

typedef class _SteamParentalSettings_ : _ISteamParentalSettings_ {
public:

	_SteamParentalSettings_() = default;
	_SteamParentalSettings_(_SteamParentalSettings_&) = delete;
	_SteamParentalSettings_& operator=(_SteamParentalSettings_&) = delete;

	Bool BIsParentalLockEnabled() override;
	Bool BIsParentalLockLocked() override;

	Bool BIsAppBlocked(AppId_t iAppId) override;
	Bool BIsAppInBlockList(AppId_t iAppId) override;

	Bool BIsFeatureBlocked(EParentalFeature eParentalFeature) override;
	Bool BIsFeatureInBlockList(EParentalFeature eParentalFeature) override;

	~_SteamParentalSettings_() = default;

} SteamParentalSettings, *pSteamParentalSettings;

#endif // !_STEAMPARENTALSETTINGS_
