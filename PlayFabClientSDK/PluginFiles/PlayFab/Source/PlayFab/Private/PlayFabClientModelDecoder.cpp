//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Client
// SDK Version: 0.0.151130
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

    /**  */
    tempStruct.PhotonCustomAuthenticationToken = response->GetObjectField("data")->GetStringField("PhotonCustomAuthenticationToken");

    return tempStruct;
}

FClientLoginResult UPlayFabClientModelDecoder::decodeLoginResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientLoginResult tempStruct;

    /** Unique token authorizing the user and game at the server level, for the current session. */
    tempStruct.SessionTicket = response->GetObjectField("data")->GetStringField("SessionTicket");

    /** Player's unique PlayFabId. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** True if the account was newly created on this login. */
    tempStruct.NewlyCreated = response->GetObjectField("data")->GetBoolField("NewlyCreated");

    /** Settings specific to this user. */
    tempStruct.SettingsForUser = response->GetObjectField("data")->GetObjectField("SettingsForUser");

    return tempStruct;
}

FClientRegisterPlayFabUserResult UPlayFabClientModelDecoder::decodeRegisterPlayFabUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRegisterPlayFabUserResult tempStruct;

    /** PlayFab unique identifier for this newly created account. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** Unique token identifying the user and game at the server level, for the current session. */
    tempStruct.SessionTicket = response->GetObjectField("data")->GetStringField("SessionTicket");

    /** PlayFab unique user name. */
    tempStruct.Username = response->GetObjectField("data")->GetStringField("Username");

    /** Settings specific to this user. */
    tempStruct.SettingsForUser = response->GetObjectField("data")->GetObjectField("SettingsForUser");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FClientAddUsernamePasswordResult UPlayFabClientModelDecoder::decodeAddUsernamePasswordResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddUsernamePasswordResult tempStruct;

    /** PlayFab unique user name. */
    tempStruct.Username = response->GetObjectField("data")->GetStringField("Username");

    return tempStruct;
}

FClientGetAccountInfoResult UPlayFabClientModelDecoder::decodeGetAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetAccountInfoResult tempStruct;

    /** Account information for the local user. */
    tempStruct.AccountInfo = response->GetObjectField("data")->GetObjectField("AccountInfo");

    return tempStruct;
}

FClientGetPlayFabIDsFromFacebookIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromFacebookIDsResult tempStruct;

    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromGameCenterIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGameCenterIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromGameCenterIDsResult tempStruct;

    /** Mapping of Game Center identifiers to PlayFab identifiers. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromGoogleIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGoogleIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromGoogleIDsResult tempStruct;

    /** Mapping of Google identifiers to PlayFab identifiers. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetPlayFabIDsFromSteamIDsResult UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayFabIDsFromSteamIDsResult tempStruct;

    /** Mapping of Steam identifiers to PlayFab identifiers. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectArrayField("Data");

    return tempStruct;
}

FClientGetUserCombinedInfoResult UPlayFabClientModelDecoder::decodeGetUserCombinedInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserCombinedInfoResult tempStruct;

    /** Unique PlayFab identifier of the owner of the combined info. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** Account information for the user. */
    tempStruct.AccountInfo = response->GetObjectField("data")->GetObjectField("AccountInfo");

    /** Array of inventory items in the user's current inventory. */
    tempStruct.Inventory = response->GetObjectField("data")->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = response->GetObjectField("data")->GetObjectField("VirtualCurrencyRechargeTimes");

    /** User specific custom data. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    /** The version of the UserData that was returned. */
    tempStruct.DataVersion = int(response->GetObjectField("data")->GetNumberField("DataVersion"));

    /** User specific read-only data. */
    tempStruct.ReadOnlyData = response->GetObjectField("data")->GetObjectField("ReadOnlyData");

    /** The version of the Read-Only UserData that was returned. */
    tempStruct.ReadOnlyDataVersion = int(response->GetObjectField("data")->GetNumberField("ReadOnlyDataVersion"));

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

    /** Current title display name for the user (this will be the original display name if the rename attempt failed). */
    tempStruct.DisplayName = response->GetObjectField("data")->GetStringField("DisplayName");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

FClientGetLeaderboardResult UPlayFabClientModelDecoder::decodeGetLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardResult tempStruct;

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = response->GetObjectField("data")->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetFriendLeaderboardAroundCurrentUserResult UPlayFabClientModelDecoder::decodeGetFriendLeaderboardAroundCurrentUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetFriendLeaderboardAroundCurrentUserResult tempStruct;

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = response->GetObjectField("data")->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetLeaderboardAroundCurrentUserResult UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCurrentUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardAroundCurrentUserResult tempStruct;

    /** Ordered listing of users and their positions in the requested leaderboard. */
    tempStruct.Leaderboard = response->GetObjectField("data")->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetUserDataResult UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserDataResult tempStruct;

    /** User specific data for this title. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = int(response->GetObjectField("data")->GetNumberField("DataVersion"));

    return tempStruct;
}

FClientGetUserStatisticsResult UPlayFabClientModelDecoder::decodeGetUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserStatisticsResult tempStruct;

    /** User statistics for the active title. */
    tempStruct.UserStatistics = response->GetObjectField("data")->GetObjectField("UserStatistics");

    return tempStruct;
}

FClientUpdateUserDataResult UPlayFabClientModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateUserDataResult tempStruct;

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = int(response->GetObjectField("data")->GetNumberField("DataVersion"));

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

    /** Array of inventory objects. */
    tempStruct.Catalog = response->GetObjectField("data")->GetObjectArrayField("Catalog");

    return tempStruct;
}

FClientGetStoreItemsResult UPlayFabClientModelDecoder::decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetStoreItemsResult tempStruct;

    /** Array of store items. */
    tempStruct.Store = response->GetObjectField("data")->GetObjectArrayField("Store");

    return tempStruct;
}

FClientGetTitleDataResult UPlayFabClientModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTitleDataResult tempStruct;

    /** a dictionary object of key / value pairs */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    return tempStruct;
}

FClientGetTitleNewsResult UPlayFabClientModelDecoder::decodeGetTitleNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTitleNewsResult tempStruct;

    /** Array of news items. */
    tempStruct.News = response->GetObjectField("data")->GetObjectArrayField("News");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

FClientModifyUserVirtualCurrencyResult UPlayFabClientModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientModifyUserVirtualCurrencyResult tempStruct;

    /** User currency was subtracted from. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** Name of the virtual currency which was modified. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetStringField("VirtualCurrency");

    /** Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    tempStruct.BalanceChange = int(response->GetObjectField("data")->GetNumberField("BalanceChange"));

    /** Balance of the virtual currency after modification. */
    tempStruct.Balance = int(response->GetObjectField("data")->GetNumberField("Balance"));

    return tempStruct;
}

FClientConfirmPurchaseResult UPlayFabClientModelDecoder::decodeConfirmPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientConfirmPurchaseResult tempStruct;

    /** Purchase order identifier. */
    tempStruct.OrderId = response->GetObjectField("data")->GetStringField("OrderId");

    /** Date and time of the purchase. */
    tempStruct.PurchaseDate = response->GetObjectField("data")->GetStringField("PurchaseDate");

    /** Array of items purchased. */
    tempStruct.Items = response->GetObjectField("data")->GetObjectArrayField("Items");

    return tempStruct;
}

FClientConsumeItemResult UPlayFabClientModelDecoder::decodeConsumeItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientConsumeItemResult tempStruct;

    /** Unique instance identifier of the item with uses consumed. */
    tempStruct.ItemInstanceId = response->GetObjectField("data")->GetStringField("ItemInstanceId");

    /** Number of uses remaining on the item. */
    tempStruct.RemainingUses = int(response->GetObjectField("data")->GetNumberField("RemainingUses"));

    return tempStruct;
}

FClientGetCharacterInventoryResult UPlayFabClientModelDecoder::decodeGetCharacterInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterInventoryResult tempStruct;

    /** PlayFab unique identifier of the user whose character inventory is being returned. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** Unique identifier of the character for this inventory. */
    tempStruct.CharacterId = response->GetObjectField("data")->GetStringField("CharacterId");

    /** Array of inventory items belonging to the character. */
    tempStruct.Inventory = response->GetObjectField("data")->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the character. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = response->GetObjectField("data")->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FClientGetPurchaseResult UPlayFabClientModelDecoder::decodeGetPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPurchaseResult tempStruct;

    /** Purchase order identifier. */
    tempStruct.OrderId = response->GetObjectField("data")->GetStringField("OrderId");

    /** Payment provider used for transaction (If not VC) */
    tempStruct.PaymentProvider = response->GetObjectField("data")->GetStringField("PaymentProvider");

    /** Provider transaction ID (If not VC) */
    tempStruct.TransactionId = response->GetObjectField("data")->GetStringField("TransactionId");

    /** PlayFab transaction status */
    tempStruct.TransactionStatus = response->GetObjectField("data")->GetStringField("TransactionStatus");

    /** Date and time of the purchase. */
    tempStruct.PurchaseDate = response->GetObjectField("data")->GetStringField("PurchaseDate");

    /** Array of items purchased. */
    tempStruct.Items = response->GetObjectField("data")->GetObjectArrayField("Items");

    return tempStruct;
}

FClientGetUserInventoryResult UPlayFabClientModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetUserInventoryResult tempStruct;

    /** Array of inventory items in the user's current inventory. */
    tempStruct.Inventory = response->GetObjectField("data")->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = response->GetObjectField("data")->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FClientPayForPurchaseResult UPlayFabClientModelDecoder::decodePayForPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientPayForPurchaseResult tempStruct;

    /** Purchase order identifier. */
    tempStruct.OrderId = response->GetObjectField("data")->GetStringField("OrderId");

    /** Status of the transaction. */
    tempStruct.Status = response->GetObjectField("data")->GetStringField("Status");

    /** Virtual currency cost of the transaction. */
    tempStruct.VCAmount = response->GetObjectField("data")->GetObjectField("VCAmount");

    /** Real world currency for the transaction. */
    tempStruct.PurchaseCurrency = response->GetObjectField("data")->GetStringField("PurchaseCurrency");

    /** Real world cost of the transaction. */
    tempStruct.PurchasePrice = int(response->GetObjectField("data")->GetNumberField("PurchasePrice"));

    /** Local credit applied to the transaction (provider specific). */
    tempStruct.CreditApplied = int(response->GetObjectField("data")->GetNumberField("CreditApplied"));

    /** Provider used for the transaction. */
    tempStruct.ProviderData = response->GetObjectField("data")->GetStringField("ProviderData");

    /** URL to the purchase provider page that details the purchase. */
    tempStruct.PurchaseConfirmationPageURL = response->GetObjectField("data")->GetStringField("PurchaseConfirmationPageURL");

    /** Current virtual currency totals for the user. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetObjectField("VirtualCurrency");

    return tempStruct;
}

FClientPurchaseItemResult UPlayFabClientModelDecoder::decodePurchaseItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientPurchaseItemResult tempStruct;

    /** Details for the items purchased. */
    tempStruct.Items = response->GetObjectField("data")->GetObjectArrayField("Items");

    return tempStruct;
}

FClientRedeemCouponResult UPlayFabClientModelDecoder::decodeRedeemCouponResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRedeemCouponResult tempStruct;

    /** Items granted to the player as a result of redeeming the coupon. */
    tempStruct.GrantedItems = response->GetObjectField("data")->GetObjectArrayField("GrantedItems");

    return tempStruct;
}

FClientReportPlayerClientResult UPlayFabClientModelDecoder::decodeReportPlayerClientResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientReportPlayerClientResult tempStruct;

    /**  */
    tempStruct.Updated = response->GetObjectField("data")->GetBoolField("Updated");

    /**  */
    tempStruct.SubmissionsRemaining = int(response->GetObjectField("data")->GetNumberField("SubmissionsRemaining"));

    return tempStruct;
}

FClientStartPurchaseResult UPlayFabClientModelDecoder::decodeStartPurchaseResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientStartPurchaseResult tempStruct;

    /** Purchase order identifier. */
    tempStruct.OrderId = response->GetObjectField("data")->GetStringField("OrderId");

    /** Cart items to be purchased. */
    tempStruct.Contents = response->GetObjectField("data")->GetObjectArrayField("Contents");

    /** Available methods by which the user can pay. */
    tempStruct.PaymentOptions = response->GetObjectField("data")->GetObjectArrayField("PaymentOptions");

    /** Current virtual currency totals for the user. */
    tempStruct.VirtualCurrencyBalances = response->GetObjectField("data")->GetObjectField("VirtualCurrencyBalances");

    return tempStruct;
}

FClientUnlockContainerItemResult UPlayFabClientModelDecoder::decodeUnlockContainerItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUnlockContainerItemResult tempStruct;

    /** Unique instance identifier of the container unlocked. */
    tempStruct.UnlockedItemInstanceId = response->GetObjectField("data")->GetStringField("UnlockedItemInstanceId");

    /** Unique instance identifier of the key used to unlock the container, if applicable. */
    tempStruct.UnlockedWithItemInstanceId = response->GetObjectField("data")->GetStringField("UnlockedWithItemInstanceId");

    /** Items granted to the player as a result of unlocking the container. */
    tempStruct.GrantedItems = response->GetObjectField("data")->GetObjectArrayField("GrantedItems");

    /** Virtual currency granted to the player as a result of unlocking the container. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetObjectField("VirtualCurrency");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

FClientAddFriendResult UPlayFabClientModelDecoder::decodeAddFriendResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAddFriendResult tempStruct;

    /** True if the friend request was processed successfully. */
    tempStruct.Created = response->GetObjectField("data")->GetBoolField("Created");

    return tempStruct;
}

FClientGetFriendsListResult UPlayFabClientModelDecoder::decodeGetFriendsListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetFriendsListResult tempStruct;

    /** Array of friends found. */
    tempStruct.Friends = response->GetObjectField("data")->GetObjectArrayField("Friends");

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

    /** array of games found */
    tempStruct.Games = response->GetObjectField("data")->GetObjectArrayField("Games");

    /** total number of players across all servers */
    tempStruct.PlayerCount = int(response->GetObjectField("data")->GetNumberField("PlayerCount"));

    /** number of games running */
    tempStruct.GameCount = int(response->GetObjectField("data")->GetNumberField("GameCount"));

    return tempStruct;
}

FClientGameServerRegionsResult UPlayFabClientModelDecoder::decodeGameServerRegionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGameServerRegionsResult tempStruct;

    /** array of regions found matching the request parameters */
    tempStruct.Regions = response->GetObjectField("data")->GetObjectArrayField("Regions");

    return tempStruct;
}

FClientMatchmakeResult UPlayFabClientModelDecoder::decodeMatchmakeResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientMatchmakeResult tempStruct;

    /** unique lobby identifier of the server matched */
    tempStruct.LobbyID = response->GetObjectField("data")->GetStringField("LobbyID");

    /** IP address of the server */
    tempStruct.ServerHostname = response->GetObjectField("data")->GetStringField("ServerHostname");

    /** port number to use for non-http communications with the server */
    tempStruct.ServerPort = int(response->GetObjectField("data")->GetNumberField("ServerPort"));

    /** server authorization ticket (used by RedeemCoupon to validate user insertion into the game) */
    tempStruct.Ticket = response->GetObjectField("data")->GetStringField("Ticket");

    /** timestamp for when the server will expire, if applicable */
    tempStruct.Expires = response->GetObjectField("data")->GetStringField("Expires");

    /** time in milliseconds the application is configured to wait on matchmaking results */
    tempStruct.PollWaitTimeMS = int(response->GetObjectField("data")->GetNumberField("PollWaitTimeMS"));

    /** result of match making process */
    tempStruct.Status = response->GetObjectField("data")->GetStringField("Status");

    return tempStruct;
}

FClientStartGameResult UPlayFabClientModelDecoder::decodeStartGameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientStartGameResult tempStruct;

    /** unique identifier for the lobby of the server started */
    tempStruct.LobbyID = response->GetObjectField("data")->GetStringField("LobbyID");

    /** server IP address */
    tempStruct.ServerHostname = response->GetObjectField("data")->GetStringField("ServerHostname");

    /** port on the server to be used for communication */
    tempStruct.ServerPort = int(response->GetObjectField("data")->GetNumberField("ServerPort"));

    /** unique identifier for the server */
    tempStruct.Ticket = response->GetObjectField("data")->GetStringField("Ticket");

    /** timestamp for when the server should expire, if applicable */
    tempStruct.Expires = response->GetObjectField("data")->GetStringField("Expires");

    /** password required to log into the server */
    tempStruct.Password = response->GetObjectField("data")->GetStringField("Password");

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

    /** Unique identifier for the shared group. */
    tempStruct.SharedGroupId = response->GetObjectField("data")->GetStringField("SharedGroupId");

    return tempStruct;
}

FClientGetPublisherDataResult UPlayFabClientModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPublisherDataResult tempStruct;

    /** a dictionary object of key / value pairs */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    return tempStruct;
}

FClientGetSharedGroupDataResult UPlayFabClientModelDecoder::decodeGetSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetSharedGroupDataResult tempStruct;

    /** Data for the requested keys. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    /** List of PlayFabId identifiers for the members of this group, if requested. */
    tempStruct.Members = FString::Join(response->GetObjectField("data")->GetStringArrayField("Members"), TEXT(","));

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

FClientGetCloudScriptUrlResult UPlayFabClientModelDecoder::decodeGetCloudScriptUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCloudScriptUrlResult tempStruct;

    /** URL of the Cloud Script logic server. */
    tempStruct.Url = response->GetObjectField("data")->GetStringField("Url");

    return tempStruct;
}

FClientRunCloudScriptResult UPlayFabClientModelDecoder::decodeRunCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientRunCloudScriptResult tempStruct;

    /** id of Cloud Script run */
    tempStruct.ActionId = response->GetObjectField("data")->GetStringField("ActionId");

    /** version of Cloud Script run */
    tempStruct.Version = int(response->GetObjectField("data")->GetNumberField("Version"));

    /** revision of Cloud Script run */
    tempStruct.Revision = int(response->GetObjectField("data")->GetNumberField("Revision"));

    /** return values from the server action as a dynamic object */
    tempStruct.Results = response->GetObjectField("data")->GetObjectField("Results");

    /** return values from the server action as a JSON encoded string */
    tempStruct.ResultsEncoded = response->GetObjectField("data")->GetStringField("ResultsEncoded");

    /** any log statements generated during the run of this action */
    tempStruct.ActionLog = response->GetObjectField("data")->GetStringField("ActionLog");

    /** time this script took to run, in seconds */
    tempStruct.ExecutionTime = int(response->GetObjectField("data")->GetNumberField("ExecutionTime"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FClientGetContentDownloadUrlResult UPlayFabClientModelDecoder::decodeGetContentDownloadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetContentDownloadUrlResult tempStruct;

    /** URL for downloading content via HTTP GET or HEAD method. The URL will expire in 1 hour. */
    tempStruct.URL = response->GetObjectField("data")->GetStringField("URL");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

FClientListUsersCharactersResult UPlayFabClientModelDecoder::decodeListUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientListUsersCharactersResult tempStruct;

    /**  */
    tempStruct.Characters = response->GetObjectField("data")->GetObjectArrayField("Characters");

    return tempStruct;
}

FClientGetCharacterLeaderboardResult UPlayFabClientModelDecoder::decodeGetCharacterLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterLeaderboardResult tempStruct;

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = response->GetObjectField("data")->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetLeaderboardAroundCharacterResult UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardAroundCharacterResult tempStruct;

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = response->GetObjectField("data")->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGetLeaderboardForUsersCharactersResult UPlayFabClientModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetLeaderboardForUsersCharactersResult tempStruct;

    /** Ordered list of leaderboard entries. */
    tempStruct.Leaderboard = response->GetObjectField("data")->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FClientGrantCharacterToUserResult UPlayFabClientModelDecoder::decodeGrantCharacterToUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGrantCharacterToUserResult tempStruct;

    /** Unique identifier tagged to this character. */
    tempStruct.CharacterId = response->GetObjectField("data")->GetStringField("CharacterId");

    /** Type of character that was created. */
    tempStruct.CharacterType = response->GetObjectField("data")->GetStringField("CharacterType");

    /**  */
    tempStruct.Result = response->GetObjectField("data")->GetBoolField("Result");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

FClientGetCharacterDataResult UPlayFabClientModelDecoder::decodeGetCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetCharacterDataResult tempStruct;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    tempStruct.CharacterId = response->GetObjectField("data")->GetStringField("CharacterId");

    /** User specific data for this title. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = int(response->GetObjectField("data")->GetNumberField("DataVersion"));

    return tempStruct;
}

FClientUpdateCharacterDataResult UPlayFabClientModelDecoder::decodeUpdateCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientUpdateCharacterDataResult tempStruct;

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = int(response->GetObjectField("data")->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Amazon-Specific APIs
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// Trading
//////////////////////////////////////////////////////

FClientAcceptTradeResponse UPlayFabClientModelDecoder::decodeAcceptTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientAcceptTradeResponse tempStruct;

    /**  */
    tempStruct.Trade = response->GetObjectField("data")->GetObjectField("Trade");

    return tempStruct;
}

FClientCancelTradeResponse UPlayFabClientModelDecoder::decodeCancelTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientCancelTradeResponse tempStruct;

    /**  */
    tempStruct.Trade = response->GetObjectField("data")->GetObjectField("Trade");

    return tempStruct;
}

FClientGetPlayerTradesResponse UPlayFabClientModelDecoder::decodeGetPlayerTradesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetPlayerTradesResponse tempStruct;

    /**  */
    tempStruct.OpenedTrades = response->GetObjectField("data")->GetObjectArrayField("OpenedTrades");

    /**  */
    tempStruct.AcceptedTrades = response->GetObjectField("data")->GetObjectArrayField("AcceptedTrades");

    return tempStruct;
}

FClientGetTradeStatusResponse UPlayFabClientModelDecoder::decodeGetTradeStatusResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientGetTradeStatusResponse tempStruct;

    /**  */
    tempStruct.Trade = response->GetObjectField("data")->GetObjectField("Trade");

    return tempStruct;
}

FClientOpenTradeResponse UPlayFabClientModelDecoder::decodeOpenTradeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FClientOpenTradeResponse tempStruct;

    /**  */
    tempStruct.Trade = response->GetObjectField("data")->GetObjectField("Trade");

    return tempStruct;
}



