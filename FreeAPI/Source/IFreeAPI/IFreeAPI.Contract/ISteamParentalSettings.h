#ifndef _ISTEAMPARENTALSETTINGS_
#define _ISTEAMPARENTALSETTINGS_

#include "..\..\FreeAPI.Typedef.h"

typedef enum _EParentalFeature_ {

	k_EFeatureInvalid,
	k_EFeatureStore,
	k_EFeatureCommunity,
	k_EFeatureProfile,
	k_EFeatureFriends,
	k_EFeatureNews,
	k_EFeatureTrading,
	k_EFeatureSettings,
	k_EFeatureConsole,
	k_EFeatureBrowser,
	k_EFeatureParentalSetup,
	k_EFeatureLibrary,
	k_EFeatureTest,
	k_EFeatureSiteLicense,
	k_EFeatureKioskMode,
	k_EFeatureMax

} EParentalFeature, *pEParentalFeature;

// -----------------------------------------------------------------------------
// Purpose: Interface to Steam parental settings (Family View)
// -----------------------------------------------------------------------------
typedef class _ISteamParentalSettings_ {
public:

	virtual Bool BIsParentalLockEnabled() = 0;
	virtual Bool BIsParentalLockLocked() = 0;

	virtual Bool BIsAppBlocked(AppId_t iAppId) = 0;
	virtual Bool BIsAppInBlockList(AppId_t iAppId) = 0;

	virtual Bool BIsFeatureBlocked(EParentalFeature eParentalFeature) = 0;
	virtual Bool BIsFeatureInBlockList(EParentalFeature eParentalFeature) = 0;
	
} ISteamParentalSettings, *IpSteamParentalSettings;

#define STEAMPARENTALSETTINGS_INTERFACE_VERSION "STEAMPARENTALSETTINGS_INTERFACE_VERSION001"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

// -----------------------------------------------------------------------------
// Purpose: UGC querying callback
// -----------------------------------------------------------------------------
#define k_iCallbback_SteamParentalSettingsChanged_t ((Int32)(k_ISteamParentalSettingsCallbacks + 1))
typedef struct _SteamParentalSettingsChanged_t_ {

	Int32 Unused;

} SteamParentalSettingsChanged_t, *pSteamParentalSettingsChanged_t;

#pragma pack(pop)

#endif // _ISTEAMPARENTALSETTINGS_
