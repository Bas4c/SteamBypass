#ifndef _ISTEAMINVENTORY_
#define _ISTEAMINVENTORY_

#include "..\..\FreeAPI.Typedef.h"

typedef Uint64 SteamItemInstanceId_t, *pSteamItemInstanceId_t;
#define k_SteamItemInstanceId_Invalid ((SteamItemInstanceId_t)(0xFFFFFFFFFFFFFFFFF));

typedef Int32 SteamSteamItemDef_t, *pSteamSteamItemDef_t;
#define k_SteamSteamItemDef_Invalid ((SteamItemInstanceId_t)(0x00000000));

typedef enum _ESteamItemFlags_ {

	k_ESteamItemNoTrade = 0x00000001,
	k_ESteamItemRemoved = 0x00000100,
	k_ESteamItemConsumed = 0x00000200

} ESteamItemFlags, *pESteamItemFlags;

typedef struct _SteamItemDetails_t_ {

	SteamItemInstanceId_t SteamItemInstanceId;
	SteamSteamItemDef_t SteamSteamItemDef;
	Uint16 nQuantity;
	Uint16 nFlags;

} SteamItemDetails_t, *pSteamItemDetails_t;

typedef Int32 SteamInventoryResult_t, *pSteamInventoryResult_t;
#define k_SteamInventoryResult_Invalid ((SteamInventoryResult_t)(-1))

typedef Uint64 SteamInventoryUpdateHandle_t,*pSteamInventoryUpdateHandle_t;
#define k_SteamInventoryUpdateHandle_Invalid ((SteamInventoryUpdateHandle_t)(0xFFFFFFFFFFFFFFFF))

// -----------------------------------------------------------------------------
// Purpose: Steam Inventory query and manipulation API
// -----------------------------------------------------------------------------
typedef class _ISteamInventory_ {
public:

	/* Possible values:
	   k_EResultPending - still in progress
	   k_EResultOK - done, result ready
	   k_EResultExpired - done, result ready, maybe out of date (see DeserializeResult)
	   k_EResultInvalidParam - ERROR: invalid API call parameters
	   k_EResultServiceUnavailable - ERROR: service temporarily down, you may retry later
	   k_EResultLimitExceeded - ERROR: operation would exceed per-user inventory limits
	   k_EResultFail - ERROR: unknown / generic error */
	virtual EResult GetResultStatus(SteamInventoryResult_t hSteamInventoryResult) = 0;
	virtual Bool GetResultItems(SteamInventoryResult_t hSteamInventoryResult, /* [out] */ pSteamItemDetails_t pSteamItemDetails, /* [in/out] */ pUint32 pnItemsArraySize) = 0;
	virtual Bool GetResultItemProperty(SteamInventoryResult_t hSteamInventoryResult, Uint32 iItem, const pStrA pchPropertyName, /* [out] */ pStrA pchValue, /* [in/out] */ pUint32 pnValueSize) = 0;
	virtual Uint32 GetResultTimestamp(SteamInventoryResult_t hSteamInventoryResult) = 0;
	virtual Bool CheckResultSteamId(SteamInventoryResult_t hSteamInventoryResult, SteamId_t SteamIdExpected) = 0;
	virtual void DestroyResult(SteamInventoryResult_t hSteamInventoryResult) = 0;

	virtual Bool GetAllItems(/* [out] */ pSteamInventoryResult_t phSteamInventoryResult) = 0;
	virtual Bool GetItemsById(/* [out] */ pSteamInventoryResult_t phSteamInventoryResult, const pSteamItemInstanceId_t pSteamItemInstanceId, Uint32 nCountSteamItemInstanceId) = 0;
	virtual Bool SerializeResult(SteamInventoryResult_t hSteamInventoryResult, /* [out] */ pVoid pvData, pUint32 pnData) = 0;
	virtual Bool DeserializeResult(pSteamInventoryResult_t pOuthSteamInventoryResult, const pVoid pvData, Uint32 nData, Bool bRESERVED_MUST_BE_FALSE) = 0;

	virtual Bool GenerateItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArraySteamItemDef, const pUint32 pnArrayQuantity, Uint32 nArrayLength) = 0;
	virtual Bool GrantPromoItems(pSteamInventoryResult_t phSteamInventoryResult) = 0;
	virtual Bool AddPromoItem(pSteamInventoryResult_t phSteamInventoryResult, SteamSteamItemDef_t SteamSteamItemDef) = 0;
	virtual Bool AddPromoItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArraySteamItemDef, Uint32 nArrayLength) = 0;
	virtual Bool ConsumeItem(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t ComsumeItemId, Uint32 nQuantity) = 0;
	virtual Bool ExchangeItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArrayGenerate, const pUint32 pnArrayGenerateQuantity, Uint32 nArrayGenerateLength, const pSteamItemInstanceId_t pArrayDestroy, const pUint32 pnArrayDestroyQuantity, Uint32 nArrayDestroyLength) = 0;
	virtual Bool TransferItemQuantity(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t SteamItemInstanceIdSource, Uint32 nQuantity, SteamItemInstanceId_t SteamItemInstanceIdDest) = 0;
	virtual void SendItemDropHeartbeat() = 0;
	virtual Bool TriggerItemDrop(pSteamInventoryResult_t phSteamInventoryResult, SteamSteamItemDef_t DropListDefinition) = 0;
	virtual Bool TradeItems(pSteamInventoryResult_t phSteamInventoryResult, SteamId_t SteamIdTradePartner, const pSteamItemInstanceId_t pArrayGive, const pUint32 pArrayGiveQuantity, Uint32 nArrayGiveLength, pSteamItemInstanceId_t pArrayGet, const pUint32 pArrayGetQuantity, Uint32 nArrayGetLength) = 0;
	virtual Bool LoadSteamItemDefinitions() = 0;
	virtual Bool GetSteamItemDefinitionIds(/* [out] */ pSteamSteamItemDef_t pSteamItemDefId, pUint32 pnSteamItemDefIdsArraySize) = 0;

	virtual Bool GetSteamItemDefinitionProperty(SteamSteamItemDef_t SteamSteamItemDef, const pStrA pchPropertyName, /* [out] */ pStrA pchValue, /* [in\out] */ pUint32 pnValueSize) = 0;
	virtual SteamAPICall_t RequestEligiblePromoSteamItemDefinitionsIds(SteamId_t SteamId) = 0;
	virtual Bool GetEligiblePromoSteamItemDefinitionIds(SteamId_t SteamId, /* [out] */ pSteamSteamItemDef_t pSteamItemDefId, /* [in/out] */ pUint32 pnSteamItemDefIdArraySize) = 0;
	virtual SteamAPICall_t StartPurchase(const pSteamSteamItemDef_t pArraySteamItemDefs, const pUint32 punArrayQuantity, Uint32 nArrayLength) = 0;
	virtual SteamAPICall_t RequestPrices() = 0;
	virtual Uint32 GetNumItemsWithPrices() = 0;
	virtual Bool GetItemsWithPrices(pSteamSteamItemDef_t pArraySteamItemDefs, /* [out] */ pUint64 pCurrentPrices, /* [out] */ pUint64 pBasePrices, Uint32 nArrayLength) = 0;
	virtual Bool GetItemPrice(SteamSteamItemDef_t SteamSteamItemDef, /* [out] */ pUint64 pCurrentPrice, /* [out] */ pUint64 pBasePrice) = 0;
	virtual SteamInventoryUpdateHandle_t StartUpdateProperties() = 0;
	virtual Bool RemoveProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName) = 0;
	virtual Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, const pStrA pchPropertyValue) = 0;
	virtual Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, Bool bValue) = 0;
	virtual Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, Int64 Value) = 0;
	virtual Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, Float Value) = 0;

	virtual Bool SubmitUpdateProperties(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, pSteamInventoryResult_t phSteamInventoryResult) = 0;
	virtual Bool InspectItem(pSteamInventoryResult_t phSteamInventoryResult, const pStrA pchItemToken) = 0;

} ISteamInventory, *IpSteamInventory;

#define STEAMINVENTORY_INTERFACE_VERSION "STEAMINVENTORY_INTERFACE_V003"

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
	#pragma pack(push, 4)
#else
	#pragma pack(push, 8)
#endif

#define k_iCallbback_SteamInventoryResultReady_t_ ((Int32)(k_iSteamInventoryCallbacks + 0))
typedef struct _SteamInventoryResultReady_t_ {

	SteamInventoryResult_t hSteamInventoryUpdate;
	EResult eResult;

} SteamInventoryResultReady_t, *pSteamInventoryResultReady_t;

#define k_iCallbback_SteamInventoryFullUpdate_t_ ((Int32)(k_iSteamInventoryCallbacks + 1))
typedef struct _SteamInventoryFullUpdate_t_ {

	SteamInventoryResult_t hSteamInventoryUpdate;

} SteamInventoryFullUpdate_t, *pSteamInventoryFullUpdate_t;

#define k_iCallbback_SteamInventoryDefinitionUpdate_t_ ((Int32)(k_iSteamInventoryCallbacks + 2))
typedef struct _SteamInventoryDefinitionUpdate_t_ {

	Int32 Unused;

} SteamInventoryDefinitionUpdate_t, *pSteamInventoryDefinitionUpdate_t;

#define k_iCallbback_SteamInventoryEligiblePromoSteamItemDefIds_t_ ((Int32)(k_iSteamInventoryCallbacks + 3))
typedef struct _SteamInventoryEligiblePromoSteamItemDefIds_t_ {

	EResult eResult;
	SteamId_t SteamId;
	Int32 nEligiblePromoSteamItemDefs;
	Bool bCachedData;

} SteamInventoryEligiblePromoSteamItemDefIds_t, *pSteamInventoryEligiblePromoSteamItemDefIds_t;

#define k_iCallbback_SteamInventoryStartPurchaseResult_t_ ((Int32)(k_iSteamInventoryCallbacks + 4))
typedef struct _SteamInventoryStartPurchaseResult_t_ {

	EResult eResult;
	Uint64 OrderId;
	Uint64 TransferId;

} SteamInventoryStartPurchaseResult_t, *pSteamInventoryStartPurchaseResult_t;

#define k_iCallbback_SteamInventoryRequestPricesResult_t_ ((Int32)(k_iSteamInventoryCallbacks + 5))
typedef struct _SteamInventoryRequestPricesResult_t_ {

	EResult eResult;
	CharA chCurrency[4];

} SteamInventoryRequestPricesResult_t, *pSteamInventoryRequestPricesResult_t;

#pragma pack(pop)

#endif // _ISTEAMINVENTORY_
