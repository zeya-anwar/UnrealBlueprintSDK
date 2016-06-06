//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Client
// SDK Version: 0.0.160606
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabClientModelDecoder.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Client API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

FClientGetPhotonAuthenticationTokenResult UPlayFabClientModelDecoder::decodeGetPhotonAuthenticationTokenResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPhotonAuthenticationTokenResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The Photon authentication token for this game-session. */
    tempStruct.PhotonCustomAuthenticationToken = !(dataObj->HasField("PhotonCustomAuthenticationToken")) ? TEXT("") : dataObj->GetStringField("PhotonCustomAuthenticationToken");

    return tempStruct;
}

FClientLoginResult UPlayFabClientModelDecoder::decodeLoginResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLoginResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique token authorizing the user and game at the server level, for the current session. */
    tempStruct.SessionTicket = !(dataObj->HasField("SessionTicket")) ? TEXT("") : dataObj->GetStringField("SessionTicket");

    /** Player's unique PlayFabId. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** True if the account was newly created on this login. */
    tempStruct.NewlyCreated = !(dataObj->HasField("NewlyCreated")) ? false : dataObj->GetBoolField("NewlyCreated");

    /** Settings specific to this user. */
    tempStruct.SettingsForUser = !(dataObj->HasField("SettingsForUser")) ? nullptr : dataObj->GetObjectField("SettingsForUser");

    /** The time of this user's previous login. If there was no previous login, then it's DateTime.MinValue */
    tempStruct.LastLoginTime = !(dataObj->HasField("LastLoginTime")) ? TEXT("") : dataObj->GetStringField("LastLoginTime");

    return tempStruct;
}

FClientRegisterPlayFabUserResult UPlayFabClientModelDecoder::decodeRegisterPlayFabUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRegisterPlayFabUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique identifier for this newly created account. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Unique token identifying the user and game at the server level, for the current session. */
    tempStruct.SessionTicket = !(dataObj->HasField("SessionTicket")) ? TEXT("") : dataObj->GetStringField("SessionTicket");

    /** PlayFab unique user name. */
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");

    /** Settings specific to this user. */
    tempStruct.SettingsForUser = !(dataObj->HasField("SettingsForUser")) ? nullptr : dataObj->GetObjectField("SettingsForUser");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FClientAddUsernamePasswordResult UPlayFabClientModelDecoder::decodeAddUsernamePasswordResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddUsernamePasswordResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique user name. */
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");

    return tempStruct;
}

FClientGetAccountInfoResult UPlayFabClientModelDecoder::decodeGetAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetAccountInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Account information for the local user. */
    tempStruct.AccountInfo = !(dataObj->HasField("AccountInfo")) ? nullptr : dataObj->GetObjectField("AccountInfo");

    return tempStruct;
}

FClientGetPlayFabIDsFromFacebookIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromFacebookIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromGameCenterIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGameCenterIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromGameCenterIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Mapping of Game Center identifiers to PlayFab identifiers. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromGoogleIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGoogleIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromGoogleIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Mapping of Google identifiers to PlayFab identifiers. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromKongregateIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromKongregateIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromKongregateIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Mapping of Kongregate identifiers to PlayFab identifiers. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromSteamIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromSteamIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Mapping of Steam identifiers to PlayFab identifiers. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetUserCombinedInfoResult UPlayFabClientModelDecoder::decodeGetUserCombinedInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserCombinedInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique PlayFab identifier of the owner of the combined info. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Account information for the user. */
    tempStruct.AccountInfo = !(dataObj->HasField("AccountInfo")) ? nullptr : dataObj->GetObjectField("AccountInfo");

    /** Array of inventory items in the user's current inventory. */
    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    /** User specific custom data. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    /** The version of the UserData that was returned. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    /** User specific read-only data. */
    tempStruct.ReadOnlyData = !(dataObj->HasField("ReadOnlyData")) ? nullptr : dataObj->GetObjectField("ReadOnlyData");

    /** The version of the Read-Only UserData that was returned. */
    tempStruct.ReadOnlyDataVersion = !(dataObj->HasField("ReadOnlyDataVersion")) ? 0 : int(dataObj->GetNumberField("ReadOnlyDataVersion"));

    return tempStruct;
}

FClientLinkAndroidDeviceIDResult UPlayFabClientModelDecoder::decodeLinkAndroidDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkAndroidDeviceIDResult tempStruct;

    return tempStruct;
}

FClientLinkCustomIDResult UPlayFabClientModelDecoder::decodeLinkCustomIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkCustomIDResult tempStruct;

    return tempStruct;
}

FClientLinkFacebookAccountResult UPlayFabClientModelDecoder::decodeLinkFacebookAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkFacebookAccountResult tempStruct;

    return tempStruct;
}

FClientLinkGameCenterAccountResult UPlayFabClientModelDecoder::decodeLinkGameCenterAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkGameCenterAccountResult tempStruct;

    return tempStruct;
}

FClientLinkGoogleAccountResult UPlayFabClientModelDecoder::decodeLinkGoogleAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkGoogleAccountResult tempStruct;

    return tempStruct;
}

FClientLinkIOSDeviceIDResult UPlayFabClientModelDecoder::decodeLinkIOSDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkIOSDeviceIDResult tempStruct;

    return tempStruct;
}

FClientLinkKongregateAccountResult UPlayFabClientModelDecoder::decodeLinkKongregateAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkKongregateAccountResult tempStruct;

    return tempStruct;
}

FClientLinkSteamAccountResult UPlayFabClientModelDecoder::decodeLinkSteamAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLinkSteamAccountResult tempStruct;

    return tempStruct;
}

FClientReportPlayerClientResult UPlayFabClientModelDecoder::decodeReportPlayerClientResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientReportPlayerClientResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Indicates whether this action completed successfully. */
    tempStruct.Updated = !(dataObj->HasField("Updated")) ? false : dataObj->GetBoolField("Updated");

    /** The number of remaining reports which may be filed today. */
    tempStruct.SubmissionsRemaining = !(dataObj->HasField("SubmissionsRemaining")) ? 0 : int(dataObj->GetNumberField("SubmissionsRemaining"));

    return tempStruct;
}

FClientSendAccountRecoveryEmailResult UPlayFabClientModelDecoder::decodeSendAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientSendAccountRecoveryEmailResult tempStruct;

    return tempStruct;
}

FClientUnlinkAndroidDeviceIDResult UPlayFabClientModelDecoder::decodeUnlinkAndroidDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkAndroidDeviceIDResult tempStruct;

    return tempStruct;
}

FClientUnlinkCustomIDResult UPlayFabClientModelDecoder::decodeUnlinkCustomIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkCustomIDResult tempStruct;

    return tempStruct;
}

FClientUnlinkFacebookAccountResult UPlayFabClientModelDecoder::decodeUnlinkFacebookAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkFacebookAccountResult tempStruct;

    return tempStruct;
}

FClientUnlinkGameCenterAccountResult UPlayFabClientModelDecoder::decodeUnlinkGameCenterAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkGameCenterAccountResult tempStruct;

    return tempStruct;
}

FClientUnlinkGoogleAccountResult UPlayFabClientModelDecoder::decodeUnlinkGoogleAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkGoogleAccountResult tempStruct;

    return tempStruct;
}

FClientUnlinkIOSDeviceIDResult UPlayFabClientModelDecoder::decodeUnlinkIOSDeviceIDResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkIOSDeviceIDResult tempStruct;

    return tempStruct;
}

FClientUnlinkKongregateAccountResult UPlayFabClientModelDecoder::decodeUnlinkKongregateAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkKongregateAccountResult tempStruct;

    return tempStruct;
}

FClientUnlinkSteamAccountResult UPlayFabClientModelDecoder::decodeUnlinkSteamAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlinkSteamAccountResult tempStruct;

    return tempStruct;
}

FClientUpdateUserTitleDisplayNameResult UPlayFabClientModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateUserTitleDisplayNameResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Current title display name for the user (this will be the original display name if the rename attempt failed). */
    tempStruct.DisplayName = !(dataObj->HasField("DisplayName")) ? TEXT("") : dataObj->GetStringField("DisplayName");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

FClientGetLeaderboardResult UPlayFabClientModelDecoder::decodeGetLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetFriendLeaderboardAroundCurrentUserResult UPlayFabClientModelDecoder::decodeGetFriendLeaderboardAroundCurrentUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetFriendLeaderboardAroundCurrentUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetFriendLeaderboardAroundPlayerResult UPlayFabClientModelDecoder::decodeGetFriendLeaderboardAroundPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetFriendLeaderboardAroundPlayerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetLeaderboardAroundCurrentUserResult UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCurrentUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardAroundCurrentUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetLeaderboardAroundPlayerResult UPlayFabClientModelDecoder::decodeGetLeaderboardAroundPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardAroundPlayerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetPlayerStatisticsResult UPlayFabClientModelDecoder::decodeGetPlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** User statistics for the requested user. */
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statistics");

    return tempStruct;
}

FClientGetPlayerStatisticVersionsResult UPlayFabClientModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerStatisticVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** version change history of the statistic */
    tempStruct.StatisticVersions = !(dataObj->HasField("StatisticVersions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticVersions");

    return tempStruct;
}

FClientGetUserDataResult UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** User specific data for this title. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}

FClientGetUserStatisticsResult UPlayFabClientModelDecoder::decodeGetUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** User statistics for the active title. */
    tempStruct.UserStatistics = !(dataObj->HasField("UserStatistics")) ? nullptr : dataObj->GetObjectField("UserStatistics");

    return tempStruct;
}

FClientUpdatePlayerStatisticsResult UPlayFabClientModelDecoder::decodeUpdatePlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdatePlayerStatisticsResult tempStruct;

    return tempStruct;
}

FClientUpdateUserDataResult UPlayFabClientModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}

FClientUpdateUserStatisticsResult UPlayFabClientModelDecoder::decodeUpdateUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateUserStatisticsResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

FClientGetCatalogItemsResult UPlayFabClientModelDecoder::decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCatalogItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items which can be purchased. */
    tempStruct.Catalog = !(dataObj->HasField("Catalog")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Catalog");

    return tempStruct;
}

FClientGetPublisherDataResult UPlayFabClientModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPublisherDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** a dictionary object of key / value pairs */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FClientGetStoreItemsResult UPlayFabClientModelDecoder::decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetStoreItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items which can be purchased from this store. */
    tempStruct.Store = !(dataObj->HasField("Store")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Store");

    return tempStruct;
}

FClientGetTitleDataResult UPlayFabClientModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTitleDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** a dictionary object of key / value pairs */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FClientGetTitleNewsResult UPlayFabClientModelDecoder::decodeGetTitleNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTitleNewsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of news items. */
    tempStruct.News = !(dataObj->HasField("News")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("News");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

FClientModifyUserVirtualCurrencyResult UPlayFabClientModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientModifyUserVirtualCurrencyResult tempStruct;
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

FClientConfirmPurchaseResult UPlayFabClientModelDecoder::decodeConfirmPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientConfirmPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Purchase order identifier. */
    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");

    /** Date and time of the purchase. */
    tempStruct.PurchaseDate = !(dataObj->HasField("PurchaseDate")) ? TEXT("") : dataObj->GetStringField("PurchaseDate");

    /** Array of items purchased. */
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FClientConsumeItemResult UPlayFabClientModelDecoder::decodeConsumeItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientConsumeItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique instance identifier of the item with uses consumed. */
    tempStruct.ItemInstanceId = !(dataObj->HasField("ItemInstanceId")) ? TEXT("") : dataObj->GetStringField("ItemInstanceId");

    /** Number of uses remaining on the item. */
    tempStruct.RemainingUses = !(dataObj->HasField("RemainingUses")) ? 0 : int(dataObj->GetNumberField("RemainingUses"));

    return tempStruct;
}

FClientGetCharacterInventoryResult UPlayFabClientModelDecoder::decodeGetCharacterInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

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

FClientGetPurchaseResult UPlayFabClientModelDecoder::decodeGetPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Purchase order identifier. */
    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");

    /** Payment provider used for transaction (If not VC) */
    tempStruct.PaymentProvider = !(dataObj->HasField("PaymentProvider")) ? TEXT("") : dataObj->GetStringField("PaymentProvider");

    /** Provider transaction ID (If not VC) */
    tempStruct.TransactionId = !(dataObj->HasField("TransactionId")) ? TEXT("") : dataObj->GetStringField("TransactionId");

    /** PlayFab transaction status */
    tempStruct.TransactionStatus = !(dataObj->HasField("TransactionStatus")) ? TEXT("") : dataObj->GetStringField("TransactionStatus");

    /** Date and time of the purchase. */
    tempStruct.PurchaseDate = !(dataObj->HasField("PurchaseDate")) ? TEXT("") : dataObj->GetStringField("PurchaseDate");

    /** Array of items purchased. */
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FClientGetUserInventoryResult UPlayFabClientModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of inventory items belonging to the user. */
    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FClientPayForPurchaseResult UPlayFabClientModelDecoder::decodePayForPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientPayForPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Purchase order identifier. */
    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");

    /** Status of the transaction. */
    GetEnumValueFromString<ETransactionStatus>(TEXT("ETransactionStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    /** Virtual currency cost of the transaction. */
    tempStruct.VCAmount = !(dataObj->HasField("VCAmount")) ? nullptr : dataObj->GetObjectField("VCAmount");

    /** Real world currency for the transaction. */
    tempStruct.PurchaseCurrency = !(dataObj->HasField("PurchaseCurrency")) ? TEXT("") : dataObj->GetStringField("PurchaseCurrency");

    /** Real world cost of the transaction. */
    tempStruct.PurchasePrice = !(dataObj->HasField("PurchasePrice")) ? 0 : int(dataObj->GetNumberField("PurchasePrice"));

    /** Local credit applied to the transaction (provider specific). */
    tempStruct.CreditApplied = !(dataObj->HasField("CreditApplied")) ? 0 : int(dataObj->GetNumberField("CreditApplied"));

    /** Provider used for the transaction. */
    tempStruct.ProviderData = !(dataObj->HasField("ProviderData")) ? TEXT("") : dataObj->GetStringField("ProviderData");

    /** URL to the purchase provider page that details the purchase. */
    tempStruct.PurchaseConfirmationPageURL = !(dataObj->HasField("PurchaseConfirmationPageURL")) ? TEXT("") : dataObj->GetStringField("PurchaseConfirmationPageURL");

    /** Current virtual currency totals for the user. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    return tempStruct;
}

FClientPurchaseItemResult UPlayFabClientModelDecoder::decodePurchaseItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientPurchaseItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Details for the items purchased. */
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FClientRedeemCouponResult UPlayFabClientModelDecoder::decodeRedeemCouponResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRedeemCouponResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Items granted to the player as a result of redeeming the coupon. */
    tempStruct.GrantedItems = !(dataObj->HasField("GrantedItems")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GrantedItems");

    return tempStruct;
}

FClientStartPurchaseResult UPlayFabClientModelDecoder::decodeStartPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientStartPurchaseResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Purchase order identifier. */
    tempStruct.OrderId = !(dataObj->HasField("OrderId")) ? TEXT("") : dataObj->GetStringField("OrderId");

    /** Cart items to be purchased. */
    tempStruct.Contents = !(dataObj->HasField("Contents")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Contents");

    /** Available methods by which the user can pay. */
    tempStruct.PaymentOptions = !(dataObj->HasField("PaymentOptions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("PaymentOptions");

    /** Current virtual currency totals for the user. */
    tempStruct.VirtualCurrencyBalances = !(dataObj->HasField("VirtualCurrencyBalances")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyBalances");

    return tempStruct;
}

FClientUnlockContainerItemResult UPlayFabClientModelDecoder::decodeUnlockContainerItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlockContainerItemResult tempStruct;
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



///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

FClientAddFriendResult UPlayFabClientModelDecoder::decodeAddFriendResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddFriendResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** True if the friend request was processed successfully. */
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");

    return tempStruct;
}

FClientGetFriendsListResult UPlayFabClientModelDecoder::decodeGetFriendsListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetFriendsListResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of friends found. */
    tempStruct.Friends = !(dataObj->HasField("Friends")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Friends");

    return tempStruct;
}

FClientRemoveFriendResult UPlayFabClientModelDecoder::decodeRemoveFriendResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRemoveFriendResult tempStruct;

    return tempStruct;
}

FClientSetFriendTagsResult UPlayFabClientModelDecoder::decodeSetFriendTagsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientSetFriendTagsResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// IOS-Specific APIs
//////////////////////////////////////////////////////

FClientRegisterForIOSPushNotificationResult UPlayFabClientModelDecoder::decodeRegisterForIOSPushNotificationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRegisterForIOSPushNotificationResult tempStruct;

    return tempStruct;
}

FClientRestoreIOSPurchasesResult UPlayFabClientModelDecoder::decodeRestoreIOSPurchasesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRestoreIOSPurchasesResult tempStruct;

    return tempStruct;
}

FClientValidateIOSReceiptResult UPlayFabClientModelDecoder::decodeValidateIOSReceiptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientValidateIOSReceiptResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////

FClientCurrentGamesResult UPlayFabClientModelDecoder::decodeCurrentGamesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientCurrentGamesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** array of games found */
    tempStruct.Games = !(dataObj->HasField("Games")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Games");

    /** total number of players across all servers */
    tempStruct.PlayerCount = !(dataObj->HasField("PlayerCount")) ? 0 : int(dataObj->GetNumberField("PlayerCount"));

    /** number of games running */
    tempStruct.GameCount = !(dataObj->HasField("GameCount")) ? 0 : int(dataObj->GetNumberField("GameCount"));

    return tempStruct;
}

FClientGameServerRegionsResult UPlayFabClientModelDecoder::decodeGameServerRegionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGameServerRegionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** array of regions found matching the request parameters */
    tempStruct.Regions = !(dataObj->HasField("Regions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Regions");

    return tempStruct;
}

FClientMatchmakeResult UPlayFabClientModelDecoder::decodeMatchmakeResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientMatchmakeResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** unique lobby identifier of the server matched */
    tempStruct.LobbyID = !(dataObj->HasField("LobbyID")) ? TEXT("") : dataObj->GetStringField("LobbyID");

    /** IP address of the server */
    tempStruct.ServerHostname = !(dataObj->HasField("ServerHostname")) ? TEXT("") : dataObj->GetStringField("ServerHostname");

    /** port number to use for non-http communications with the server */
    tempStruct.ServerPort = !(dataObj->HasField("ServerPort")) ? 0 : int(dataObj->GetNumberField("ServerPort"));

    /** server authorization ticket (used by RedeemCoupon to validate user insertion into the game) */
    tempStruct.Ticket = !(dataObj->HasField("Ticket")) ? TEXT("") : dataObj->GetStringField("Ticket");

    /** timestamp for when the server will expire, if applicable */
    tempStruct.Expires = !(dataObj->HasField("Expires")) ? TEXT("") : dataObj->GetStringField("Expires");

    /** time in milliseconds the application is configured to wait on matchmaking results */
    tempStruct.PollWaitTimeMS = !(dataObj->HasField("PollWaitTimeMS")) ? 0 : int(dataObj->GetNumberField("PollWaitTimeMS"));

    /** result of match making process */
    GetEnumValueFromString<EMatchmakeStatus>(TEXT("EMatchmakeStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    return tempStruct;
}

FClientStartGameResult UPlayFabClientModelDecoder::decodeStartGameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientStartGameResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** unique identifier for the lobby of the server started */
    tempStruct.LobbyID = !(dataObj->HasField("LobbyID")) ? TEXT("") : dataObj->GetStringField("LobbyID");

    /** server IP address */
    tempStruct.ServerHostname = !(dataObj->HasField("ServerHostname")) ? TEXT("") : dataObj->GetStringField("ServerHostname");

    /** port on the server to be used for communication */
    tempStruct.ServerPort = !(dataObj->HasField("ServerPort")) ? 0 : int(dataObj->GetNumberField("ServerPort"));

    /** unique identifier for the server */
    tempStruct.Ticket = !(dataObj->HasField("Ticket")) ? TEXT("") : dataObj->GetStringField("Ticket");

    /** timestamp for when the server should expire, if applicable */
    tempStruct.Expires = !(dataObj->HasField("Expires")) ? TEXT("") : dataObj->GetStringField("Expires");

    /** password required to log into the server */
    tempStruct.Password = !(dataObj->HasField("Password")) ? TEXT("") : dataObj->GetStringField("Password");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Android-Specific APIs
//////////////////////////////////////////////////////

FClientAndroidDevicePushNotificationRegistrationResult UPlayFabClientModelDecoder::decodeAndroidDevicePushNotificationRegistrationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAndroidDevicePushNotificationRegistrationResult tempStruct;

    return tempStruct;
}

FClientValidateGooglePlayPurchaseResult UPlayFabClientModelDecoder::decodeValidateGooglePlayPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientValidateGooglePlayPurchaseResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

FClientLogEventResult UPlayFabClientModelDecoder::decodeLogEventResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLogEventResult tempStruct;

    return tempStruct;
}

FClientWriteEventResponse UPlayFabClientModelDecoder::decodeWriteEventResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientWriteEventResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The unique identifier of the event. This can be used to retrieve the event's properties using the GetEvent API. The values of this identifier consist of ASCII characters and are not constrained to any particular format. */
    tempStruct.EventId = !(dataObj->HasField("EventId")) ? TEXT("") : dataObj->GetStringField("EventId");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

FClientAddSharedGroupMembersResult UPlayFabClientModelDecoder::decodeAddSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddSharedGroupMembersResult tempStruct;

    return tempStruct;
}

FClientCreateSharedGroupResult UPlayFabClientModelDecoder::decodeCreateSharedGroupResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientCreateSharedGroupResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique identifier for the shared group. */
    tempStruct.SharedGroupId = !(dataObj->HasField("SharedGroupId")) ? TEXT("") : dataObj->GetStringField("SharedGroupId");

    return tempStruct;
}

FClientGetSharedGroupDataResult UPlayFabClientModelDecoder::decodeGetSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetSharedGroupDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Data for the requested keys. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    /** List of PlayFabId identifiers for the members of this group, if requested. */
    tempStruct.Members = !(dataObj->HasField("Members")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Members"), TEXT(","));

    return tempStruct;
}

FClientRemoveSharedGroupMembersResult UPlayFabClientModelDecoder::decodeRemoveSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRemoveSharedGroupMembersResult tempStruct;

    return tempStruct;
}

FClientUpdateSharedGroupDataResult UPlayFabClientModelDecoder::decodeUpdateSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateSharedGroupDataResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Sony-specific APIs
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

FClientExecuteCloudScriptResult UPlayFabClientModelDecoder::decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientExecuteCloudScriptResult tempStruct;
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

FClientGetCloudScriptUrlResult UPlayFabClientModelDecoder::decodeGetCloudScriptUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCloudScriptUrlResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** URL of the Cloud Script logic server. */
    tempStruct.Url = !(dataObj->HasField("Url")) ? TEXT("") : dataObj->GetStringField("Url");

    return tempStruct;
}

FClientRunCloudScriptResult UPlayFabClientModelDecoder::decodeRunCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRunCloudScriptResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** id of Cloud Script run */
    tempStruct.ActionId = !(dataObj->HasField("ActionId")) ? TEXT("") : dataObj->GetStringField("ActionId");

    /** version of Cloud Script run */
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    /** revision of Cloud Script run */
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));

    /** return values from the server action as a dynamic object */
    tempStruct.Results = !(dataObj->HasField("Results")) ? nullptr : dataObj->GetObjectField("Results");

    /** return values from the server action as a JSON encoded string */
    tempStruct.ResultsEncoded = !(dataObj->HasField("ResultsEncoded")) ? TEXT("") : dataObj->GetStringField("ResultsEncoded");

    /** any log statements generated during the run of this action */
    tempStruct.ActionLog = !(dataObj->HasField("ActionLog")) ? TEXT("") : dataObj->GetStringField("ActionLog");

    /** time this script took to run, in seconds */
    tempStruct.ExecutionTime = !(dataObj->HasField("ExecutionTime")) ? 0 : int(dataObj->GetNumberField("ExecutionTime"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FClientGetContentDownloadUrlResult UPlayFabClientModelDecoder::decodeGetContentDownloadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetContentDownloadUrlResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** URL for downloading content via HTTP GET or HEAD method. The URL will expire in 1 hour. */
    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

FClientListUsersCharactersResult UPlayFabClientModelDecoder::decodeListUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientListUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The requested list of characters. */
    tempStruct.Characters = !(dataObj->HasField("Characters")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Characters");

    return tempStruct;
}

FClientGetCharacterLeaderboardResult UPlayFabClientModelDecoder::decodeGetCharacterLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetCharacterStatisticsResult UPlayFabClientModelDecoder::decodeGetCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The requested character statistics. */
    tempStruct.CharacterStatistics = !(dataObj->HasField("CharacterStatistics")) ? nullptr : dataObj->GetObjectField("CharacterStatistics");

    return tempStruct;
}

FClientGetLeaderboardAroundCharacterResult UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardAroundCharacterResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetLeaderboardForUsersCharactersResult UPlayFabClientModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardForUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGrantCharacterToUserResult UPlayFabClientModelDecoder::decodeGrantCharacterToUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGrantCharacterToUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique identifier tagged to this character. */
    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");

    /** Type of character that was created. */
    tempStruct.CharacterType = !(dataObj->HasField("CharacterType")) ? TEXT("") : dataObj->GetStringField("CharacterType");

    /** Indicates whether this character was created successfully. */
    tempStruct.Result = !(dataObj->HasField("Result")) ? false : dataObj->GetBoolField("Result");

    return tempStruct;
}

FClientUpdateCharacterStatisticsResult UPlayFabClientModelDecoder::decodeUpdateCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateCharacterStatisticsResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

FClientGetCharacterDataResult UPlayFabClientModelDecoder::decodeGetCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");

    /** User specific data for this title. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}

FClientUpdateCharacterDataResult UPlayFabClientModelDecoder::decodeUpdateCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Amazon-Specific APIs
//////////////////////////////////////////////////////

FClientValidateAmazonReceiptResult UPlayFabClientModelDecoder::decodeValidateAmazonReceiptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientValidateAmazonReceiptResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Trading
//////////////////////////////////////////////////////

FClientAcceptTradeResponse UPlayFabClientModelDecoder::decodeAcceptTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAcceptTradeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Details about trade which was just accepted. */
    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}

FClientCancelTradeResponse UPlayFabClientModelDecoder::decodeCancelTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientCancelTradeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Details about trade which was just canceled. */
    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}

FClientGetPlayerTradesResponse UPlayFabClientModelDecoder::decodeGetPlayerTradesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerTradesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The trades for this player which are currently available to be accepted. */
    tempStruct.OpenedTrades = !(dataObj->HasField("OpenedTrades")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("OpenedTrades");

    /** History of trades which this player has accepted. */
    tempStruct.AcceptedTrades = !(dataObj->HasField("AcceptedTrades")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("AcceptedTrades");

    return tempStruct;
}

FClientGetTradeStatusResponse UPlayFabClientModelDecoder::decodeGetTradeStatusResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTradeStatusResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Information about the requested trade. */
    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}

FClientOpenTradeResponse UPlayFabClientModelDecoder::decodeOpenTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientOpenTradeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The information about the trade that was just opened. */
    tempStruct.Trade = !(dataObj->HasField("Trade")) ? nullptr : dataObj->GetObjectField("Trade");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Advertising
//////////////////////////////////////////////////////

FClientAttributeInstallResult UPlayFabClientModelDecoder::decodeAttributeInstallResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAttributeInstallResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////


