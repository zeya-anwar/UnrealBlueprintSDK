//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Server
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabServerModelDecoder.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

FServerAuthenticateSessionTicketResult UPlayFabServerModelDecoder::decodeAuthenticateSessionTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerAuthenticateSessionTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Account info for the user whose session ticket was supplied. */
    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FServerGetPlayFabIDsFromFacebookIDsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromFacebookIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetPlayFabIDsFromSteamIDsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromSteamIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Mapping of Steam identifiers to PlayFab identifiers. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetUserAccountInfoResult UPlayFabServerModelDecoder::decodeGetUserAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserAccountInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Account details for the user whose information was requested. */
    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}

FServerSendPushNotificationResult UPlayFabServerModelDecoder::decodeSendPushNotificationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSendPushNotificationResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

FServerDeleteUsersResult UPlayFabServerModelDecoder::decodeDeleteUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerDeleteUsersResult tempStruct;

    return tempStruct;
}

FServerGetLeaderboardResult UPlayFabServerModelDecoder::decodeGetLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGetLeaderboardAroundUserResult UPlayFabServerModelDecoder::decodeGetLeaderboardAroundUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardAroundUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGetPlayerStatisticsResult UPlayFabServerModelDecoder::decodeGetPlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique identifier of the user whose statistics are being returned */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** User statistics for the requested user. */
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statistics");

    return tempStruct;
}

FServerGetPlayerStatisticVersionsResult UPlayFabServerModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerStatisticVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** version change history of the statistic */
    tempStruct.StatisticVersions = !(dataObj->HasField("StatisticVersions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticVersions");

    return tempStruct;
}

FServerGetUserDataResult UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique identifier of the user whose custom data is being returned. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    /** User specific data for this title. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FServerGetUserStatisticsResult UPlayFabServerModelDecoder::decodeGetUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique identifier of the user whose statistics are being returned. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** User statistics for the requested user. */
    tempStruct.UserStatistics = !(dataObj->HasField("UserStatistics")) ? nullptr : dataObj->GetObjectField("UserStatistics");

    return tempStruct;
}

FServerUpdatePlayerStatisticsResult UPlayFabServerModelDecoder::decodeUpdatePlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdatePlayerStatisticsResult tempStruct;

    return tempStruct;
}

FServerUpdateUserDataResult UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}

FServerUpdateUserStatisticsResult UPlayFabServerModelDecoder::decodeUpdateUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateUserStatisticsResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

FServerGetCatalogItemsResult UPlayFabServerModelDecoder::decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCatalogItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items which can be purchased. */
    tempStruct.Catalog = !(dataObj->HasField("Catalog")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Catalog");

    return tempStruct;
}

FServerGetPublisherDataResult UPlayFabServerModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPublisherDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** a dictionary object of key / value pairs */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FServerGetTitleDataResult UPlayFabServerModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetTitleDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** a dictionary object of key / value pairs */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FServerGetTitleNewsResult UPlayFabServerModelDecoder::decodeGetTitleNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetTitleNewsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of news items. */
    tempStruct.News = !(dataObj->HasField("News")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("News");

    return tempStruct;
}

FServerSetPublisherDataResult UPlayFabServerModelDecoder::decodeSetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetPublisherDataResult tempStruct;

    return tempStruct;
}

FServerSetTitleDataResult UPlayFabServerModelDecoder::decodeSetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetTitleDataResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

FServerModifyCharacterVirtualCurrencyResult UPlayFabServerModelDecoder::decodeModifyCharacterVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerModifyCharacterVirtualCurrencyResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Name of the virtual currency which was modified. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? TEXT("") : dataObj->GetStringField("VirtualCurrency");

    /** Balance of the virtual currency after modification. */
    tempStruct.Balance = !(dataObj->HasField("Balance")) ? 0 : int(dataObj->GetNumberField("Balance"));

    return tempStruct;
}

FServerModifyUserVirtualCurrencyResult UPlayFabServerModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerModifyUserVirtualCurrencyResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** User currency was subtracted from. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Name of the virtual currency which was modified. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? TEXT("") : dataObj->GetStringField("VirtualCurrency");

    /** Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    tempStruct.BalanceChange = !(dataObj->HasField("BalanceChange")) ? 0 : int(dataObj->GetNumberField("BalanceChange"));

    /** Balance of the virtual currency after modification. */
    tempStruct.Balance = !(dataObj->HasField("Balance")) ? 0 : int(dataObj->GetNumberField("Balance"));

    return tempStruct;
}

FServerConsumeItemResult UPlayFabServerModelDecoder::decodeConsumeItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerConsumeItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique instance identifier of the item with uses consumed. */
    tempStruct.ItemInstanceId = !(dataObj->HasField("ItemInstanceId")) ? TEXT("") : dataObj->GetStringField("ItemInstanceId");

    /** Number of uses remaining on the item. */
    tempStruct.RemainingUses = !(dataObj->HasField("RemainingUses")) ? 0 : int(dataObj->GetNumberField("RemainingUses"));

    return tempStruct;
}

FServerEvaluateRandomResultTableResult UPlayFabServerModelDecoder::decodeEvaluateRandomResultTableResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerEvaluateRandomResultTableResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique identifier for the item returned from the Random Result Table evaluation, for the given catalog. */
    tempStruct.ResultItemId = !(dataObj->HasField("ResultItemId")) ? TEXT("") : dataObj->GetStringField("ResultItemId");

    return tempStruct;
}

FServerGetCharacterInventoryResult UPlayFabServerModelDecoder::decodeGetCharacterInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Unique identifier of the character for this inventory. */
    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");

    /** Array of inventory items belonging to the character. */
    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the character. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FServerGetUserInventoryResult UPlayFabServerModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Array of inventory items belonging to the user. */
    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FServerGrantItemsToCharacterResult UPlayFabServerModelDecoder::decodeGrantItemsToCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantItemsToCharacterResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items granted to users. */
    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FServerGrantItemsToUserResult UPlayFabServerModelDecoder::decodeGrantItemsToUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantItemsToUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items granted to users. */
    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FServerGrantItemsToUsersResult UPlayFabServerModelDecoder::decodeGrantItemsToUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantItemsToUsersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items granted to users. */
    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FServerModifyItemUsesResult UPlayFabServerModelDecoder::decodeModifyItemUsesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerModifyItemUsesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique instance identifier of the item with uses consumed. */
    tempStruct.ItemInstanceId = !(dataObj->HasField("ItemInstanceId")) ? TEXT("") : dataObj->GetStringField("ItemInstanceId");

    /** Number of uses remaining on the item. */
    tempStruct.RemainingUses = !(dataObj->HasField("RemainingUses")) ? 0 : int(dataObj->GetNumberField("RemainingUses"));

    return tempStruct;
}

FServerMoveItemToCharacterFromCharacterResult UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerMoveItemToCharacterFromCharacterResult tempStruct;

    return tempStruct;
}

FServerMoveItemToCharacterFromUserResult UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerMoveItemToCharacterFromUserResult tempStruct;

    return tempStruct;
}

FServerMoveItemToUserFromCharacterResult UPlayFabServerModelDecoder::decodeMoveItemToUserFromCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerMoveItemToUserFromCharacterResult tempStruct;

    return tempStruct;
}

FServerRedeemCouponResult UPlayFabServerModelDecoder::decodeRedeemCouponResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRedeemCouponResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Items granted to the player as a result of redeeming the coupon. */
    tempStruct.GrantedItems = !(dataObj->HasField("GrantedItems")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GrantedItems");

    return tempStruct;
}

FServerReportPlayerServerResult UPlayFabServerModelDecoder::decodeReportPlayerServerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerReportPlayerServerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Indicates whether this action completed successfully. */
    tempStruct.Updated = !(dataObj->HasField("Updated")) ? false : dataObj->GetBoolField("Updated");

    /** The number of remaining reports which may be filed today by this reporting player. */
    tempStruct.SubmissionsRemaining = !(dataObj->HasField("SubmissionsRemaining")) ? 0 : int(dataObj->GetNumberField("SubmissionsRemaining"));

    return tempStruct;
}

FServerRevokeInventoryResult UPlayFabServerModelDecoder::decodeRevokeInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRevokeInventoryResult tempStruct;

    return tempStruct;
}

FServerUnlockContainerItemResult UPlayFabServerModelDecoder::decodeUnlockContainerItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUnlockContainerItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique instance identifier of the container unlocked. */
    tempStruct.UnlockedItemInstanceId = !(dataObj->HasField("UnlockedItemInstanceId")) ? TEXT("") : dataObj->GetStringField("UnlockedItemInstanceId");

    /** Unique instance identifier of the key used to unlock the container, if applicable. */
    tempStruct.UnlockedWithItemInstanceId = !(dataObj->HasField("UnlockedWithItemInstanceId")) ? TEXT("") : dataObj->GetStringField("UnlockedWithItemInstanceId");

    /** Items granted to the player as a result of unlocking the container. */
    tempStruct.GrantedItems = !(dataObj->HasField("GrantedItems")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GrantedItems");

    /** Virtual currency granted to the player as a result of unlocking the container. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    return tempStruct;
}

FServerEmptyResult UPlayFabServerModelDecoder::decodeEmptyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerEmptyResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////

FServerNotifyMatchmakerPlayerLeftResult UPlayFabServerModelDecoder::decodeNotifyMatchmakerPlayerLeftResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerNotifyMatchmakerPlayerLeftResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** State of user leaving the Game Server Instance. */
    GetEnumValueFromString<EPlayerConnectionState>(TEXT("EPlayerConnectionState"), dataObj->GetStringField("PlayerState"), tempStruct.PlayerState);

    return tempStruct;
}

FServerRedeemMatchmakerTicketResult UPlayFabServerModelDecoder::decodeRedeemMatchmakerTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRedeemMatchmakerTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Boolean indicating whether the ticket was validated by the PlayFab service. */
    tempStruct.TicketIsValid = !(dataObj->HasField("TicketIsValid")) ? false : dataObj->GetBoolField("TicketIsValid");

    /** Error value if the ticket was not validated. */
    tempStruct.Error = !(dataObj->HasField("Error")) ? TEXT("") : dataObj->GetStringField("Error");

    /** User account information for the user validated. */
    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}

FServerSetGameServerInstanceDataResult UPlayFabServerModelDecoder::decodeSetGameServerInstanceDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetGameServerInstanceDataResult tempStruct;

    return tempStruct;
}

FServerSetGameServerInstanceStateResult UPlayFabServerModelDecoder::decodeSetGameServerInstanceStateResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetGameServerInstanceStateResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Steam-Specific APIs
//////////////////////////////////////////////////////

FServerAwardSteamAchievementResult UPlayFabServerModelDecoder::decodeAwardSteamAchievementResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerAwardSteamAchievementResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of achievements granted. */
    tempStruct.AchievementResults = !(dataObj->HasField("AchievementResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("AchievementResults");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

FServerLogEventResult UPlayFabServerModelDecoder::decodeLogEventResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerLogEventResult tempStruct;

    return tempStruct;
}

FServerWriteEventResponse UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerWriteEventResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The unique identifier of the event. This can be used to retrieve the event's properties using the GetEvent API. The values of this identifier consist of ASCII characters and are not constrained to any particular format. */
    tempStruct.EventId = !(dataObj->HasField("EventId")) ? TEXT("") : dataObj->GetStringField("EventId");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

FServerAddSharedGroupMembersResult UPlayFabServerModelDecoder::decodeAddSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerAddSharedGroupMembersResult tempStruct;

    return tempStruct;
}

FServerCreateSharedGroupResult UPlayFabServerModelDecoder::decodeCreateSharedGroupResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerCreateSharedGroupResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique identifier for the shared group. */
    tempStruct.SharedGroupId = !(dataObj->HasField("SharedGroupId")) ? TEXT("") : dataObj->GetStringField("SharedGroupId");

    return tempStruct;
}

FServerGetSharedGroupDataResult UPlayFabServerModelDecoder::decodeGetSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetSharedGroupDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Data for the requested keys. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    /** List of PlayFabId identifiers for the members of this group, if requested. */
    tempStruct.Members = !(dataObj->HasField("Members")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Members"), TEXT(","));

    return tempStruct;
}

FServerRemoveSharedGroupMembersResult UPlayFabServerModelDecoder::decodeRemoveSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRemoveSharedGroupMembersResult tempStruct;

    return tempStruct;
}

FServerUpdateSharedGroupDataResult UPlayFabServerModelDecoder::decodeUpdateSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateSharedGroupDataResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

FServerExecuteCloudScriptResult UPlayFabServerModelDecoder::decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerExecuteCloudScriptResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The name of the function that executed */
    tempStruct.FunctionName = !(dataObj->HasField("FunctionName")) ? TEXT("") : dataObj->GetStringField("FunctionName");

    /** The revision of the CloudScript that executed */
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));

    /** The object returned from the CloudScript function, if any */
    tempStruct.FunctionResult = !(dataObj->HasField("FunctionResult")) ? nullptr : dataObj->GetObjectField("FunctionResult");

    /** Entries logged during the function execution. These include both entries logged in the function code using log.info() and log.error() and error entries for API and HTTP request failures. */
    tempStruct.Logs = !(dataObj->HasField("Logs")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Logs");

    /**  */
    tempStruct.ExecutionTimeSeconds = !(dataObj->HasField("ExecutionTimeSeconds")) ? 0 : int(dataObj->GetNumberField("ExecutionTimeSeconds"));

    /**  */
    tempStruct.MemoryConsumedBytes = !(dataObj->HasField("MemoryConsumedBytes")) ? 0 : int(dataObj->GetNumberField("MemoryConsumedBytes"));

    /** Number of PlayFab API requests issued by the CloudScript function */
    tempStruct.APIRequestsIssued = !(dataObj->HasField("APIRequestsIssued")) ? 0 : int(dataObj->GetNumberField("APIRequestsIssued"));

    /** Number of external HTTP requests issued by the CloudScript function */
    tempStruct.HttpRequestsIssued = !(dataObj->HasField("HttpRequestsIssued")) ? 0 : int(dataObj->GetNumberField("HttpRequestsIssued"));

    /** Information about the error, if any, that occured during execution */
    tempStruct.Error = !(dataObj->HasField("Error")) ? nullptr : dataObj->GetObjectField("Error");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FServerGetContentDownloadUrlResult UPlayFabServerModelDecoder::decodeGetContentDownloadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetContentDownloadUrlResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** URL for downloading content via HTTP GET or HEAD method. The URL will expire in 1 hour. */
    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

FServerDeleteCharacterFromUserResult UPlayFabServerModelDecoder::decodeDeleteCharacterFromUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerDeleteCharacterFromUserResult tempStruct;

    return tempStruct;
}

FServerListUsersCharactersResult UPlayFabServerModelDecoder::decodeListUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerListUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The requested list of characters. */
    tempStruct.Characters = !(dataObj->HasField("Characters")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Characters");

    return tempStruct;
}

FServerGetCharacterLeaderboardResult UPlayFabServerModelDecoder::decodeGetCharacterLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGetCharacterStatisticsResult UPlayFabServerModelDecoder::decodeGetCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique identifier of the user whose character statistics are being returned. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Unique identifier of the character for the statistics. */
    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");

    /** Character statistics for the requested user. */
    tempStruct.CharacterStatistics = !(dataObj->HasField("CharacterStatistics")) ? nullptr : dataObj->GetObjectField("CharacterStatistics");

    return tempStruct;
}

FServerGetLeaderboardAroundCharacterResult UPlayFabServerModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardAroundCharacterResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGetLeaderboardForUsersCharactersResult UPlayFabServerModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardForUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGrantCharacterToUserResult UPlayFabServerModelDecoder::decodeGrantCharacterToUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantCharacterToUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique identifier tagged to this character. */
    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");

    return tempStruct;
}

FServerUpdateCharacterStatisticsResult UPlayFabServerModelDecoder::decodeUpdateCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateCharacterStatisticsResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

FServerGetCharacterDataResult UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    /** User specific data for this title. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");

    return tempStruct;
}

FServerUpdateCharacterDataResult UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////


