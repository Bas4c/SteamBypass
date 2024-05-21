#ifndef _STEAMINVENTORY_
#define _STEAMINVENTORY_

#include <Windows.h>
// -----------------------------------------------------------------------------
#include "..\StrX.h"
#include "IFreeAPI.Contract\ISteamInventory.h"
// -----------------------------------------------------------------------------

typedef class _SteamInventory_ : public _ISteamInventory001_,
 public _ISteamInventory002_, public _ISteamInventory_ {
public:

	_SteamInventory_() = default;
	_SteamInventory_(const _SteamInventory_&) = delete;
	_SteamInventory_& operator=(const _SteamInventory_&) = delete;

	/* Possible values:
	   k_EResultPending - still in progress
	   k_EResultOK - done, result ready
	   k_EResultExpired - done, result ready, maybe out of date (see DeserializeResult)
	   k_EResultInvalidParam - ERROR: invalid API call parameters
	   k_EResultServiceUnavailable - ERROR: service temporarily down, you may retry later
	   k_EResultLimitExceeded - ERROR: operation would exceed per-user inventory limits
	   k_EResultFail - ERROR: unknown / generic error */
	EResult GetResultStatus(SteamInventoryResult_t hSteamInventoryResult) override;
	Bool GetResultItems(SteamInventoryResult_t hSteamInventoryResult, pSteamItemDetails_t pSteamItemDetails, pUint32 pnItemsArraySize) override;
	Bool GetResultItemProperty(SteamInventoryResult_t hSteamInventoryResult, Uint32 iItem, const pStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) override;
	Uint32 GetResultTimestamp(SteamInventoryResult_t hSteamInventoryResult) override;
	Bool CheckResultSteamId(SteamInventoryResult_t hSteamInventoryResult, SteamId_t SteamIdExpected) override;
	void DestroyResult(SteamInventoryResult_t hSteamInventoryResult) override;

	Bool GetAllItems(pSteamInventoryResult_t phSteamInventoryResult) override;
	Bool GetItemsById(pSteamInventoryResult_t phSteamInventoryResult, const pSteamItemInstanceId_t pSteamItemInstanceId, Uint32 nCountSteamItemInstanceId) override;
	Bool SerializeResult(SteamInventoryResult_t hSteamInventoryResult, pVoid pvData, pUint32 pnData) override;
	Bool DeserializeResult(pSteamInventoryResult_t pOuthSteamInventoryResult, const pVoid pvData, Uint32 nData, Bool bRESERVED_MUST_BE_FALSE) override;

	Bool GenerateItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArraySteamItemDef, const pUint32 pnArrayQuantity, Uint32 nArrayLength) override;
	Bool GrantPromoItems(pSteamInventoryResult_t phSteamInventoryResult) override;
	Bool AddPromoItem(pSteamInventoryResult_t phSteamInventoryResult, SteamSteamItemDef_t SteamSteamItemDef) override;
	Bool AddPromoItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArraySteamItemDef, Uint32 nArrayLength) override;
	Bool ConsumeItem(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t ComsumeItemId, Uint32 nQuantity) override;
	Bool ExchangeItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArrayGenerate, const pUint32 pnArrayGenerateQuantity, Uint32 nArrayGenerateLength, const pSteamItemInstanceId_t pArrayDestroy, const pUint32 pnArrayDestroyQuantity, Uint32 nArrayDestroyLength) override;
	Bool TransferItemQuantity(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t SteamItemInstanceIdSource, Uint32 nQuantity, SteamItemInstanceId_t SteamItemInstanceIdDest) override;
	void SendItemDropHeartbeat() override;
	Bool TriggerItemDrop(pSteamInventoryResult_t phSteamInventoryResult, SteamSteamItemDef_t DropListDefinition) override;
	Bool TradeItems(pSteamInventoryResult_t phSteamInventoryResult, SteamId_t SteamIdTradePartner, const pSteamItemInstanceId_t pArrayGive, const pUint32 pArrayGiveQuantity, Uint32 nArrayGiveLength, pSteamItemInstanceId_t pArrayGet, const pUint32 pArrayGetQuantity, Uint32 nArrayGetLength) override;
	Bool LoadSteamItemDefinitions() override;
	Bool GetSteamItemDefinitionIds(pSteamSteamItemDef_t pSteamItemDefId, pUint32 pnSteamItemDefIdsArraySize) override;
	
	Bool GetSteamItemDefinitionProperty(SteamSteamItemDef_t SteamSteamItemDef, const pStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) override;
	SteamAPICall_t RequestEligiblePromoSteamItemDefinitionsIds(SteamId_t SteamId) override;
	Bool GetEligiblePromoSteamItemDefinitionIds(SteamId_t SteamId, pSteamSteamItemDef_t pSteamItemDefId, pUint32 pnSteamItemDefIdArraySize) override;
	SteamAPICall_t StartPurchase(const pSteamSteamItemDef_t pArraySteamItemDefs, const pUint32 punArrayQuantity, Uint32 nArrayLength) override;
	SteamAPICall_t RequestPrices() override;
	Uint32 GetNumItemsWithPrices() override;
	Bool GetItemsWithPrices(pSteamSteamItemDef_t pArraySteamItemDefs, pUint64 pCurrentPrices, pUint64 pBasePrices, Uint32 nArrayLength) override;
	Bool GetItemPrice(SteamSteamItemDef_t SteamSteamItemDef, pUint64 pCurrentPrice, pUint64 pBasePrice) override;
	SteamInventoryUpdateHandle_t StartUpdateProperties() override;
	Bool RemoveProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName) override;
	Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, const pStrA pchPropertyValue) override;
	Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, Bool bValue) override;
	Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, Int64 Value) override;
	Bool SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, const pStrA pchPropertyName, Float Value) override;
	
	Bool SubmitUpdateProperties(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, pSteamInventoryResult_t phSteamInventoryResult) override;
	Bool InspectItem(pSteamInventoryResult_t phSteamInventoryResult, const pStrA pchItemToken) override;

	~_SteamInventory_() = default;

} SteamInventory, *pSteamInventory;

#endif // !_STEAMINVENTORY_
