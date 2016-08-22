//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Admin
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabAdminModelDecoder.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Admin API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FAdminBanUsersResult UPlayFabAdminModelDecoder::decodeBanUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminBanUsersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Information on the bans that were applied */
    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminLookupUserAccountInfoResult UPlayFabAdminModelDecoder::decodeLookupUserAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminLookupUserAccountInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** User info for the user matching the request */
    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}

FAdminGetUserBansResult UPlayFabAdminModelDecoder::decodeGetUserBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Information about the bans */
    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminBlankResult UPlayFabAdminModelDecoder::decodeBlankResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminBlankResult tempStruct;

    return tempStruct;
}

FAdminRevokeAllBansForUserResult UPlayFabAdminModelDecoder::decodeRevokeAllBansForUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRevokeAllBansForUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Information on the bans that were revoked. */
    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminRevokeBansResult UPlayFabAdminModelDecoder::decodeRevokeBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRevokeBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Information on the bans that were revoked */
    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminSendAccountRecoveryEmailResult UPlayFabAdminModelDecoder::decodeSendAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSendAccountRecoveryEmailResult tempStruct;

    return tempStruct;
}

FAdminUpdateBansResult UPlayFabAdminModelDecoder::decodeUpdateBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Information on the bans that were updated */
    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminUpdateUserTitleDisplayNameResult UPlayFabAdminModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateUserTitleDisplayNameResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** current title display name for the user (this will be the original display name if the rename attempt failed) */
    tempStruct.DisplayName = !(dataObj->HasField("DisplayName")) ? TEXT("") : dataObj->GetStringField("DisplayName");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

FAdminCreatePlayerStatisticDefinitionResult UPlayFabAdminModelDecoder::decodeCreatePlayerStatisticDefinitionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminCreatePlayerStatisticDefinitionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** created statistic definition */
    tempStruct.Statistic = !(dataObj->HasField("Statistic")) ? nullptr : dataObj->GetObjectField("Statistic");

    return tempStruct;
}

FAdminDeleteUsersResult UPlayFabAdminModelDecoder::decodeDeleteUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeleteUsersResult tempStruct;

    return tempStruct;
}

FAdminGetDataReportResult UPlayFabAdminModelDecoder::decodeGetDataReportResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetDataReportResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** The URL where the requested report can be downloaded. */
    tempStruct.DownloadUrl = !(dataObj->HasField("DownloadUrl")) ? TEXT("") : dataObj->GetStringField("DownloadUrl");

    return tempStruct;
}

FAdminGetPlayerStatisticDefinitionsResult UPlayFabAdminModelDecoder::decodeGetPlayerStatisticDefinitionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerStatisticDefinitionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** the player statistic definitions for the title */
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statistics");

    return tempStruct;
}

FAdminGetPlayerStatisticVersionsResult UPlayFabAdminModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerStatisticVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** version change history of the statistic */
    tempStruct.StatisticVersions = !(dataObj->HasField("StatisticVersions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticVersions");

    return tempStruct;
}

FAdminGetUserDataResult UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique identifier of the user whose custom data is being returned. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    /** User specific data for this title. */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FAdminIncrementPlayerStatisticVersionResult UPlayFabAdminModelDecoder::decodeIncrementPlayerStatisticVersionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminIncrementPlayerStatisticVersionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** version change history of the statistic */
    tempStruct.StatisticVersion = !(dataObj->HasField("StatisticVersion")) ? nullptr : dataObj->GetObjectField("StatisticVersion");

    return tempStruct;
}

FAdminResetUserStatisticsResult UPlayFabAdminModelDecoder::decodeResetUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminResetUserStatisticsResult tempStruct;

    return tempStruct;
}

FAdminUpdatePlayerStatisticDefinitionResult UPlayFabAdminModelDecoder::decodeUpdatePlayerStatisticDefinitionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdatePlayerStatisticDefinitionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** updated statistic definition */
    tempStruct.Statistic = !(dataObj->HasField("Statistic")) ? nullptr : dataObj->GetObjectField("Statistic");

    return tempStruct;
}

FAdminUpdateUserDataResult UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

FAdminAddNewsResult UPlayFabAdminModelDecoder::decodeAddNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminAddNewsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique id of the new news item */
    tempStruct.NewsId = !(dataObj->HasField("NewsId")) ? TEXT("") : dataObj->GetStringField("NewsId");

    return tempStruct;
}

FAdminDeleteStoreResult UPlayFabAdminModelDecoder::decodeDeleteStoreResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeleteStoreResult tempStruct;

    return tempStruct;
}

FAdminGetCatalogItemsResult UPlayFabAdminModelDecoder::decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCatalogItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items which can be purchased. */
    tempStruct.Catalog = !(dataObj->HasField("Catalog")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Catalog");

    return tempStruct;
}

FAdminGetPublisherDataResult UPlayFabAdminModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPublisherDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** a dictionary object of key / value pairs */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FAdminGetRandomResultTablesResult UPlayFabAdminModelDecoder::decodeGetRandomResultTablesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetRandomResultTablesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** array of random result tables currently available */
    tempStruct.Tables = !(dataObj->HasField("Tables")) ? nullptr : dataObj->GetObjectField("Tables");

    return tempStruct;
}

FAdminGetStoreItemsResult UPlayFabAdminModelDecoder::decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetStoreItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items which can be purchased from this store. */
    tempStruct.Store = !(dataObj->HasField("Store")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Store");

    return tempStruct;
}

FAdminGetTitleDataResult UPlayFabAdminModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetTitleDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** a dictionary object of key / value pairs */
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FAdminListVirtualCurrencyTypesResult UPlayFabAdminModelDecoder::decodeListVirtualCurrencyTypesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminListVirtualCurrencyTypesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** List of virtual currency names defined for this title */
    tempStruct.VirtualCurrencies = !(dataObj->HasField("VirtualCurrencies")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("VirtualCurrencies");

    return tempStruct;
}

FAdminUpdateCatalogItemsResult UPlayFabAdminModelDecoder::decodeUpdateCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateCatalogItemsResult tempStruct;

    return tempStruct;
}

FAdminUpdateStoreItemsResult UPlayFabAdminModelDecoder::decodeUpdateStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateStoreItemsResult tempStruct;

    return tempStruct;
}

FAdminSetTitleDataResult UPlayFabAdminModelDecoder::decodeSetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetTitleDataResult tempStruct;

    return tempStruct;
}

FAdminSetupPushNotificationResult UPlayFabAdminModelDecoder::decodeSetupPushNotificationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetupPushNotificationResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Amazon Resource Name for the created notification topic. */
    tempStruct.ARN = !(dataObj->HasField("ARN")) ? TEXT("") : dataObj->GetStringField("ARN");

    return tempStruct;
}

FAdminUpdateRandomResultTablesResult UPlayFabAdminModelDecoder::decodeUpdateRandomResultTablesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateRandomResultTablesResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

FAdminModifyUserVirtualCurrencyResult UPlayFabAdminModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminModifyUserVirtualCurrencyResult tempStruct;
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

FAdminGetUserInventoryResult UPlayFabAdminModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserInventoryResult tempStruct;
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

FAdminGrantItemsToUsersResult UPlayFabAdminModelDecoder::decodeGrantItemsToUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGrantItemsToUsersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of items granted to users. */
    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FAdminRevokeInventoryResult UPlayFabAdminModelDecoder::decodeRevokeInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRevokeInventoryResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////

FAdminGetMatchmakerGameInfoResult UPlayFabAdminModelDecoder::decodeGetMatchmakerGameInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetMatchmakerGameInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** unique identifier of the lobby  */
    tempStruct.LobbyId = !(dataObj->HasField("LobbyId")) ? TEXT("") : dataObj->GetStringField("LobbyId");

    /** unique identifier of the Game Server Instance for this lobby */
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    /** time when the Game Server Instance was created */
    tempStruct.StartTime = !(dataObj->HasField("StartTime")) ? TEXT("") : dataObj->GetStringField("StartTime");

    /** time when Game Server Instance is currently scheduled to end */
    tempStruct.EndTime = !(dataObj->HasField("EndTime")) ? TEXT("") : dataObj->GetStringField("EndTime");

    /** game mode for this Game Server Instance */
    tempStruct.Mode = !(dataObj->HasField("Mode")) ? TEXT("") : dataObj->GetStringField("Mode");

    /** version identifier of the game server executable binary being run */
    tempStruct.BuildVersion = !(dataObj->HasField("BuildVersion")) ? TEXT("") : dataObj->GetStringField("BuildVersion");

    /** region in which the Game Server Instance is running */
    GetEnumValueFromString<ERegion>(TEXT("ERegion"), dataObj->GetStringField("Region"), tempStruct.Region);

    /** array of unique PlayFab identifiers for users currently connected to this Game Server Instance */
    tempStruct.Players = !(dataObj->HasField("Players")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Players"), TEXT(","));

    /** IP address for this Game Server Instance */
    tempStruct.ServerAddress = !(dataObj->HasField("ServerAddress")) ? TEXT("") : dataObj->GetStringField("ServerAddress");

    /** communication port for this Game Server Instance */
    tempStruct.ServerPort = !(dataObj->HasField("ServerPort")) ? 0 : int(dataObj->GetNumberField("ServerPort"));

    return tempStruct;
}

FAdminGetMatchmakerGameModesResult UPlayFabAdminModelDecoder::decodeGetMatchmakerGameModesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetMatchmakerGameModesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** array of game modes available for the specified build */
    tempStruct.GameModes = !(dataObj->HasField("GameModes")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameModes");

    return tempStruct;
}

FAdminModifyMatchmakerGameModesResult UPlayFabAdminModelDecoder::decodeModifyMatchmakerGameModesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminModifyMatchmakerGameModesResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Custom Server Management
//////////////////////////////////////////////////////

FAdminAddServerBuildResult UPlayFabAdminModelDecoder::decodeAddServerBuildResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminAddServerBuildResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** unique identifier for this build executable */
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");

    /** array of regions where this build can used, when it is active */
    tempStruct.ActiveRegions = !(dataObj->HasField("ActiveRegions")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ActiveRegions"), TEXT(","));

    /** maximum number of game server instances that can run on a single host machine */
    tempStruct.MaxGamesPerHost = !(dataObj->HasField("MaxGamesPerHost")) ? 0 : int(dataObj->GetNumberField("MaxGamesPerHost"));

    /** minimum capacity of additional game server instances that can be started before the autoscaling service starts new host machines (given the number of current running host machines and game server instances) */
    tempStruct.MinFreeGameSlots = !(dataObj->HasField("MinFreeGameSlots")) ? 0 : int(dataObj->GetNumberField("MinFreeGameSlots"));

    /** appended to the end of the command line when starting game servers */
    tempStruct.CommandLineTemplate = !(dataObj->HasField("CommandLineTemplate")) ? TEXT("") : dataObj->GetStringField("CommandLineTemplate");

    /** path to the game server executable. Defaults to gameserver.exe */
    tempStruct.ExecutablePath = !(dataObj->HasField("ExecutablePath")) ? TEXT("") : dataObj->GetStringField("ExecutablePath");

    /** developer comment(s) for this build */
    tempStruct.Comment = !(dataObj->HasField("Comment")) ? TEXT("") : dataObj->GetStringField("Comment");

    /** time this build was last modified (or uploaded, if this build has never been modified) */
    tempStruct.Timestamp = !(dataObj->HasField("Timestamp")) ? TEXT("") : dataObj->GetStringField("Timestamp");

    /** Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a title has been selected. */
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    /** the current status of the build validation and processing steps */
    GetEnumValueFromString<EGameBuildStatus>(TEXT("EGameBuildStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    return tempStruct;
}

FAdminGetServerBuildInfoResult UPlayFabAdminModelDecoder::decodeGetServerBuildInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetServerBuildInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** unique identifier for this build executable */
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");

    /** array of regions where this build can used, when it is active */
    tempStruct.ActiveRegions = !(dataObj->HasField("ActiveRegions")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ActiveRegions"), TEXT(","));

    /** maximum number of game server instances that can run on a single host machine */
    tempStruct.MaxGamesPerHost = !(dataObj->HasField("MaxGamesPerHost")) ? 0 : int(dataObj->GetNumberField("MaxGamesPerHost"));

    /** minimum capacity of additional game server instances that can be started before the autoscaling service starts new host machines (given the number of current running host machines and game server instances) */
    tempStruct.MinFreeGameSlots = !(dataObj->HasField("MinFreeGameSlots")) ? 0 : int(dataObj->GetNumberField("MinFreeGameSlots"));

    /** developer comment(s) for this build */
    tempStruct.Comment = !(dataObj->HasField("Comment")) ? TEXT("") : dataObj->GetStringField("Comment");

    /** time this build was last modified (or uploaded, if this build has never been modified) */
    tempStruct.Timestamp = !(dataObj->HasField("Timestamp")) ? TEXT("") : dataObj->GetStringField("Timestamp");

    /** Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a title has been selected. */
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    /** the current status of the build validation and processing steps */
    GetEnumValueFromString<EGameBuildStatus>(TEXT("EGameBuildStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    /** error message, if any, about this build */
    tempStruct.ErrorMessage = !(dataObj->HasField("ErrorMessage")) ? TEXT("") : dataObj->GetStringField("ErrorMessage");

    return tempStruct;
}

FAdminGetServerBuildUploadURLResult UPlayFabAdminModelDecoder::decodeGetServerBuildUploadURLResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetServerBuildUploadURLResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** pre-authorized URL for uploading the game server build package */
    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}

FAdminListBuildsResult UPlayFabAdminModelDecoder::decodeListBuildsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminListBuildsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** array of uploaded game server builds */
    tempStruct.Builds = !(dataObj->HasField("Builds")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Builds");

    return tempStruct;
}

FAdminModifyServerBuildResult UPlayFabAdminModelDecoder::decodeModifyServerBuildResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminModifyServerBuildResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** unique identifier for this build executable */
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");

    /** array of regions where this build can used, when it is active */
    tempStruct.ActiveRegions = !(dataObj->HasField("ActiveRegions")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ActiveRegions"), TEXT(","));

    /** maximum number of game server instances that can run on a single host machine */
    tempStruct.MaxGamesPerHost = !(dataObj->HasField("MaxGamesPerHost")) ? 0 : int(dataObj->GetNumberField("MaxGamesPerHost"));

    /** minimum capacity of additional game server instances that can be started before the autoscaling service starts new host machines (given the number of current running host machines and game server instances) */
    tempStruct.MinFreeGameSlots = !(dataObj->HasField("MinFreeGameSlots")) ? 0 : int(dataObj->GetNumberField("MinFreeGameSlots"));

    /** appended to the end of the command line when starting game servers */
    tempStruct.CommandLineTemplate = !(dataObj->HasField("CommandLineTemplate")) ? TEXT("") : dataObj->GetStringField("CommandLineTemplate");

    /** path to the game server executable. Defaults to gameserver.exe */
    tempStruct.ExecutablePath = !(dataObj->HasField("ExecutablePath")) ? TEXT("") : dataObj->GetStringField("ExecutablePath");

    /** developer comment(s) for this build */
    tempStruct.Comment = !(dataObj->HasField("Comment")) ? TEXT("") : dataObj->GetStringField("Comment");

    /** time this build was last modified (or uploaded, if this build has never been modified) */
    tempStruct.Timestamp = !(dataObj->HasField("Timestamp")) ? TEXT("") : dataObj->GetStringField("Timestamp");

    /** Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a title has been selected. */
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    /** the current status of the build validation and processing steps */
    GetEnumValueFromString<EGameBuildStatus>(TEXT("EGameBuildStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    return tempStruct;
}

FAdminRemoveServerBuildResult UPlayFabAdminModelDecoder::decodeRemoveServerBuildResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRemoveServerBuildResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

FAdminSetPublisherDataResult UPlayFabAdminModelDecoder::decodeSetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetPublisherDataResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

FAdminGetCloudScriptRevisionResult UPlayFabAdminModelDecoder::decodeGetCloudScriptRevisionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCloudScriptRevisionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Version number. */
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    /** Revision number. */
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));

    /** Time this revision was created */
    tempStruct.CreatedAt = !(dataObj->HasField("CreatedAt")) ? TEXT("") : dataObj->GetStringField("CreatedAt");

    /** List of Cloud Script files in this revision. */
    tempStruct.Files = !(dataObj->HasField("Files")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Files");

    /** True if this is the currently published revision */
    tempStruct.IsPublished = !(dataObj->HasField("IsPublished")) ? false : dataObj->GetBoolField("IsPublished");

    return tempStruct;
}

FAdminGetCloudScriptVersionsResult UPlayFabAdminModelDecoder::decodeGetCloudScriptVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCloudScriptVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** List of versions */
    tempStruct.Versions = !(dataObj->HasField("Versions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Versions");

    return tempStruct;
}

FAdminSetPublishedRevisionResult UPlayFabAdminModelDecoder::decodeSetPublishedRevisionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetPublishedRevisionResult tempStruct;

    return tempStruct;
}

FAdminUpdateCloudScriptResult UPlayFabAdminModelDecoder::decodeUpdateCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateCloudScriptResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Cloud Script version updated */
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    /** New revision number created */
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FAdminGetContentListResult UPlayFabAdminModelDecoder::decodeGetContentListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetContentListResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Number of content items returned. We currently have a maximum of 1000 items limit. */
    tempStruct.ItemCount = !(dataObj->HasField("ItemCount")) ? 0 : int(dataObj->GetNumberField("ItemCount"));

    /** The total size of listed contents in bytes. */
    tempStruct.TotalSize = !(dataObj->HasField("TotalSize")) ? 0 : int(dataObj->GetNumberField("TotalSize"));

    /** List of content items. */
    tempStruct.Contents = !(dataObj->HasField("Contents")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Contents");

    return tempStruct;
}

FAdminGetContentUploadUrlResult UPlayFabAdminModelDecoder::decodeGetContentUploadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetContentUploadUrlResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** URL for uploading content via HTTP PUT method. The URL will expire in 1 hour. */
    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

FAdminResetCharacterStatisticsResult UPlayFabAdminModelDecoder::decodeResetCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminResetCharacterStatisticsResult tempStruct;

    return tempStruct;
}



///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

FAdminGetAllSegmentsResult UPlayFabAdminModelDecoder::decodeGetAllSegmentsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetAllSegmentsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of segments for this title. */
    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FAdminGetPlayerSegmentsResult UPlayFabAdminModelDecoder::decodeGetPlayerSegmentsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerSegmentsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Array of segments the requested player currently belongs to. */
    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FAdminGetPlayersInSegmentResult UPlayFabAdminModelDecoder::decodeGetPlayersInSegmentResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayersInSegmentResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Count of profiles matching this segment. */
    tempStruct.ProfilesInSegment = !(dataObj->HasField("ProfilesInSegment")) ? 0 : int(dataObj->GetNumberField("ProfilesInSegment"));

    /** Continuation token to use to retrieve subsequent pages of results. If token returns null there are no more results. */
    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");

    /** Array of player profiles in this segment. */
    tempStruct.PlayerProfiles = !(dataObj->HasField("PlayerProfiles")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("PlayerProfiles");

    return tempStruct;
}


