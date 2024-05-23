// -----------------------------------------------------------------------------
#include "SteamInventory.h"
// -----------------------------------------------------------------------------

EResult _SteamInventory_::GetResultStatus(SteamInventoryResult_t hSteamInventoryResult) {

	return k_EResultOK;

}

Bool _SteamInventory_::GetResultItems(SteamInventoryResult_t hSteamInventoryResult, pSteamItemDetails_t pSteamItemDetails, pUint32 pnItemsArraySize) {

	return False;

}

Bool _SteamInventory_::GetResultItemProperty(SteamInventoryResult_t hSteamInventoryResult, Uint32 iItem, pCStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) {

	return False;

}

Uint32 _SteamInventory_::GetResultTimestamp(SteamInventoryResult_t hSteamInventoryResult) {

	/* January 1, 1970 (start of Unix epoch) in "ticks" */
	const Int64 UnixTimeStart = 0x019DB1DED53E8000;

	Uint64 UTCTime = 0U;
	GetSystemTimeAsFileTime((LPFILETIME)(&UTCTime));

	return (Uint32)((UTCTime - UnixTimeStart) / 10000000);

}

Bool _SteamInventory_::CheckResultSteamId(SteamInventoryResult_t hSteamInventoryResult, SteamId_t SteamIdExpected) {

	return False;

}

void _SteamInventory_::DestroyResult(SteamInventoryResult_t hSteamInventoryResult) {

	/* Empty Method */

}

Bool _SteamInventory_::GetAllItems(pSteamInventoryResult_t phSteamInventoryResult) {

	return False;

}

Bool _SteamInventory_::GetItemsById(pSteamInventoryResult_t phSteamInventoryResult, const pSteamItemInstanceId_t pSteamItemInstanceId, Uint32 nCountSteamItemInstanceId) {

	return False;

}

Bool _SteamInventory_::SerializeResult(SteamInventoryResult_t hSteamInventoryResult, pVoid pvData, pUint32 pnData) {

	return False;

}

Bool _SteamInventory_::DeserializeResult(pSteamInventoryResult_t pOuthSteamInventoryResult, const pVoid pvData, Uint32 nData, Bool bRESERVED_MUST_BE_FALSE) {

	return False;

}

Bool _SteamInventory_::GenerateItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArraySteamItemDef, const pUint32 pnArrayQuantity, Uint32 nArrayLength) {

	return False;

}

Bool _SteamInventory_::GrantPromoItems(pSteamInventoryResult_t phSteamInventoryResult) {

	return False;

}

Bool _SteamInventory_::AddPromoItem(pSteamInventoryResult_t phSteamInventoryResult, SteamSteamItemDef_t SteamSteamItemDef) {

	return False;

}

Bool _SteamInventory_::AddPromoItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArraySteamItemDef, Uint32 nArrayLength) {

	return False;

}

Bool _SteamInventory_::ConsumeItem(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t ComsumeItemId, Uint32 nQuantity) {

	return False;

}

Bool _SteamInventory_::ExchangeItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamSteamItemDef_t pArrayGenerate, const pUint32 pnArrayGenerateQuantity, Uint32 nArrayGenerateLength, const pSteamItemInstanceId_t pArrayDestroy, const pUint32 pnArrayDestroyQuantity, Uint32 nArrayDestroyLength) {

	return False;

}

Bool _SteamInventory_::TransferItemQuantity(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t SteamItemInstanceIdSource, Uint32 nQuantity, SteamItemInstanceId_t SteamItemInstanceIdDest) {

	return False;

}

void _SteamInventory_::SendItemDropHeartbeat() {

	/* Empty Method */

}

Bool _SteamInventory_::TriggerItemDrop(pSteamInventoryResult_t phSteamInventoryResult, SteamSteamItemDef_t DropListDefinition) {

	return False;

}

Bool _SteamInventory_::TradeItems(pSteamInventoryResult_t phSteamInventoryResult, SteamId_t SteamIdTradePartner, const pSteamItemInstanceId_t pArrayGive, const pUint32 pArrayGiveQuantity, Uint32 nArrayGiveLength, pSteamItemInstanceId_t pArrayGet, const pUint32 pArrayGetQuantity, Uint32 nArrayGetLength) {

	return False;

}

Bool _SteamInventory_::LoadSteamItemDefinitions() {

	return False;

}

Bool _SteamInventory_::GetSteamItemDefinitionIds(pSteamSteamItemDef_t pSteamItemDefId, pUint32 pnSteamItemDefIdsArraySize) {

	return False;

}

Bool _SteamInventory_::GetSteamItemDefinitionProperty(SteamSteamItemDef_t SteamSteamItemDef, pCStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) {

	return False;

}

SteamAPICall_t _SteamInventory_::RequestEligiblePromoSteamItemDefinitionsIds(SteamId_t SteamId) {

	return k_SteamAPICall_Invalid;

}

Bool _SteamInventory_::GetEligiblePromoSteamItemDefinitionIds(SteamId_t SteamId, pSteamSteamItemDef_t pSteamItemDefId, pUint32 pnSteamItemDefIdArraySize) {

	return False;

}

SteamAPICall_t _SteamInventory_::StartPurchase(const pSteamSteamItemDef_t pArraySteamItemDefs, const pUint32 punArrayQuantity, Uint32 nArrayLength) {

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamInventory_::RequestPrices() {

	return k_SteamAPICall_Invalid;

}

Uint32 _SteamInventory_::GetNumItemsWithPrices() {

	return 0U;

}

Bool _SteamInventory_::GetItemsWithPrices(pSteamSteamItemDef_t pArraySteamItemDefs, pUint64 pCurrentPrices, pUint64 pBasePrices, Uint32 nArrayLength) {

	return False;

}

Bool _SteamInventory_::GetItemPrice(SteamSteamItemDef_t SteamSteamItemDef, pUint64 pCurrentPrice, pUint64 pBasePrice) {

	return False;

}

SteamInventoryUpdateHandle_t _SteamInventory_::StartUpdateProperties() {

	return k_SteamInventoryUpdateHandle_Invalid;

}

Bool _SteamInventory_::RemoveProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName) {

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, pCStrA pchPropertyValue) {

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Bool bValue) {

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Int64 Value) {

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Float Value) {

	return False;

}

Bool _SteamInventory_::SubmitUpdateProperties(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, pSteamInventoryResult_t phSteamInventoryResult) {

	return False;

}

Bool _SteamInventory_::InspectItem(pSteamInventoryResult_t phSteamInventoryResult, pCStrA pchItemToken) {

	return False;

}
