// -----------------------------------------------------------------------------
#include "SteamInventory.h"
// -----------------------------------------------------------------------------

EResult _SteamInventory_::GetResultStatus(SteamInventoryResult_t hSteamInventoryResult) {
	DEBUGBREAK("ISteamInventory::GetResultStatus");

	return k_EResultOK;

}

Bool _SteamInventory_::GetResultItems(SteamInventoryResult_t hSteamInventoryResult, pSteamItemDetails_t pSteamItemDetails, pUint32 pnItemsArraySize) {
	DEBUGBREAK("ISteamInventory::GetResultItems");

	return False;

}

Bool _SteamInventory_::GetResultItemProperty(SteamInventoryResult_t hSteamInventoryResult, Uint32 iItem, pCStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) {
	DEBUGBREAK("ISteamInventory::GetResultItemProperty");

	return False;

}

Uint32 _SteamInventory_::GetResultTimestamp(SteamInventoryResult_t hSteamInventoryResult) {
	DEBUGBREAK("ISteamInventory::GetResultTimestamp");

	/* January 1, 1970 (start of Unix epoch) in "ticks" */
	const Int64 UnixTimeStart = 0x019DB1DED53E8000;

	Uint64 UTCTime = 0U;
	GetSystemTimeAsFileTime((LPFILETIME)(&UTCTime));

	return (Uint32)((UTCTime - UnixTimeStart) / 10000000);

}

Bool _SteamInventory_::CheckResultSteamId(SteamInventoryResult_t hSteamInventoryResult, SteamId_t SteamIdExpected) {
	DEBUGBREAK("ISteamInventory::CheckResultSteamId");

	return False;

}

void _SteamInventory_::DestroyResult(SteamInventoryResult_t hSteamInventoryResult) {
	DEBUGBREAK("ISteamInventory::DestroyResult");

	/* Empty Method */

}

Bool _SteamInventory_::GetAllItems(pSteamInventoryResult_t phSteamInventoryResult) {
	DEBUGBREAK("ISteamInventory::GetAllItems");

	return False;

}

Bool _SteamInventory_::GetItemsById(pSteamInventoryResult_t phSteamInventoryResult, const pSteamItemInstanceId_t pSteamItemInstanceId, Uint32 nCountSteamItemInstanceId) {
	DEBUGBREAK("ISteamInventory::GetItemsById");

	return False;

}

Bool _SteamInventory_::SerializeResult(SteamInventoryResult_t hSteamInventoryResult, pVoid pvData, pUint32 pnData) {
	DEBUGBREAK("ISteamInventory::SerializeResult");

	return False;

}

Bool _SteamInventory_::DeserializeResult(pSteamInventoryResult_t pOuthSteamInventoryResult, pCVoid pvData, Uint32 nData, Bool bRESERVED_MUST_BE_FALSE) {
	DEBUGBREAK("ISteamInventory::DeserializeResult");

	return False;

}

Bool _SteamInventory_::GenerateItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamItemDef_t pArraySteamItemDef, const pUint32 pnArrayQuantity, Uint32 nArrayLength) {
	DEBUGBREAK("ISteamInventory::GenerateItems");

	return False;

}

Bool _SteamInventory_::GrantPromoItems(pSteamInventoryResult_t phSteamInventoryResult) {
	DEBUGBREAK("ISteamInventory::GrantPromoItems");

	return False;

}

Bool _SteamInventory_::AddPromoItem(pSteamInventoryResult_t phSteamInventoryResult, SteamItemDef_t SteamItemDef) {
	DEBUGBREAK("ISteamInventory::AddPromoItem");

	return False;

}

Bool _SteamInventory_::AddPromoItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamItemDef_t pArraySteamItemDef, Uint32 nArrayLength) {
	DEBUGBREAK("ISteamInventory::AddPromoItems");

	return False;

}

Bool _SteamInventory_::ConsumeItem(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t ComsumeItemId, Uint32 nQuantity) {
	DEBUGBREAK("ISteamInventory::ConsumeItem");

	return False;

}

Bool _SteamInventory_::ExchangeItems(pSteamInventoryResult_t phSteamInventoryResult, const pSteamItemDef_t pArrayGenerate, const pUint32 pnArrayGenerateQuantity, Uint32 nArrayGenerateLength, const pSteamItemInstanceId_t pArrayDestroy, const pUint32 pnArrayDestroyQuantity, Uint32 nArrayDestroyLength) {
	DEBUGBREAK("ISteamInventory::ExchangeItems");

	return False;

}

Bool _SteamInventory_::TransferItemQuantity(pSteamInventoryResult_t phSteamInventoryResult, SteamItemInstanceId_t SteamItemInstanceIdSource, Uint32 nQuantity, SteamItemInstanceId_t SteamItemInstanceIdDest) {
	DEBUGBREAK("ISteamInventory::TransferItemQuantity");

	return False;

}

void _SteamInventory_::SendItemDropHeartbeat() {
	DEBUGBREAK("ISteamInventory::SendItemDropHeartbeat");

	/* Empty Method */

}

Bool _SteamInventory_::TriggerItemDrop(pSteamInventoryResult_t phSteamInventoryResult, SteamItemDef_t DropListDefinition) {
	DEBUGBREAK("ISteamInventory::TriggerItemDrop");

	return False;

}

Bool _SteamInventory_::TradeItems(pSteamInventoryResult_t phSteamInventoryResult, SteamId_t SteamIdTradePartner, const pSteamItemInstanceId_t pArrayGive, const pUint32 pArrayGiveQuantity, Uint32 nArrayGiveLength, pSteamItemInstanceId_t pArrayGet, const pUint32 pArrayGetQuantity, Uint32 nArrayGetLength) {
	DEBUGBREAK("ISteamInventory::TradeItems");

	return False;

}

Bool _SteamInventory_::LoadSteamItemDefinitions() {
	DEBUGBREAK("ISteamInventory::LoadSteamItemDefinitions");

	return False;

}

Bool _SteamInventory_::GetSteamItemDefinitionIds(pSteamItemDef_t pSteamItemDefId, pUint32 pnSteamItemDefIdsArraySize) {
	DEBUGBREAK("ISteamInventory::GetSteamItemDefinitionIds");

	return False;

}

Bool _SteamInventory_::GetSteamItemDefinitionProperty(SteamItemDef_t SteamItemDef, pCStrA pchPropertyName, pStrA pchValue, pUint32 pnValueSize) {
	DEBUGBREAK("ISteamInventory::GetSteamItemDefinitionProperty");

	return False;

}

SteamAPICall_t _SteamInventory_::RequestEligiblePromoSteamItemDefinitionsIds(SteamId_t SteamId) {
	DEBUGBREAK("ISteamInventory::RequestEligiblePromoSteamItemDefinitionsIds");

	return k_SteamAPICall_Invalid;

}

Bool _SteamInventory_::GetEligiblePromoSteamItemDefinitionIds(SteamId_t SteamId, pSteamItemDef_t pSteamItemDefId, pUint32 pnSteamItemDefIdArraySize) {
	DEBUGBREAK("ISteamInventory::GetEligiblePromoSteamItemDefinitionIds");

	return False;

}

SteamAPICall_t _SteamInventory_::StartPurchase(const pSteamItemDef_t pArraySteamItemDefs, const pUint32 pnArrayQuantity, Uint32 nArrayLength) {
	DEBUGBREAK("ISteamInventory::StartPurchase");

	return k_SteamAPICall_Invalid;

}

SteamAPICall_t _SteamInventory_::RequestPrices() {
	DEBUGBREAK("ISteamInventory::RequestPrices");

	return k_SteamAPICall_Invalid;

}

Uint32 _SteamInventory_::GetNumItemsWithPrices() {
	DEBUGBREAK("ISteamInventory::GetNumItemsWithPrices");

	return 0U;

}

Bool _SteamInventory_::GetItemsWithPrices(pSteamItemDef_t pArraySteamItemDefs, pUint64 pCurrentPrices, pUint64 pBasePrices, Uint32 nArrayLength) {
	DEBUGBREAK("ISteamInventory::GetItemsWithPrices");

	return False;

}

Bool _SteamInventory_::GetItemPrice(SteamItemDef_t SteamItemDef, pUint64 pCurrentPrice, pUint64 pBasePrice) {
	DEBUGBREAK("ISteamInventory::GetItemPrice");

	return False;

}

SteamInventoryUpdateHandle_t _SteamInventory_::StartUpdateProperties() {
	DEBUGBREAK("ISteamInventory::StartUpdateProperties");

	return k_SteamInventoryUpdateHandle_Invalid;

}

Bool _SteamInventory_::RemoveProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName) {
	DEBUGBREAK("ISteamInventory::RemoveProperty");

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, pCStrA pchPropertyValue) {
	DEBUGBREAK("ISteamInventory::SetProperty");

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Bool bValue) {
	DEBUGBREAK("ISteamInventory::SetProperty");

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Int64 Value) {
	DEBUGBREAK("ISteamInventory::SetProperty");

	return False;

}

Bool _SteamInventory_::SetProperty(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, SteamItemInstanceId_t nItemId, pCStrA pchPropertyName, Float Value) {
	DEBUGBREAK("ISteamInventory::SetProperty");

	return False;

}

Bool _SteamInventory_::SubmitUpdateProperties(SteamInventoryUpdateHandle_t hSteamInventoryUpdate, pSteamInventoryResult_t phSteamInventoryResult) {
	DEBUGBREAK("ISteamInventory::SubmitUpdateProperties");

	return False;

}

Bool _SteamInventory_::InspectItem(pSteamInventoryResult_t phSteamInventoryResult, pCStrA pchItemToken) {
	DEBUGBREAK("ISteamInventory::InspectItem");

	return False;

}
