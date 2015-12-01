//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Admin
// SDK Version: 0.0.151130
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabAdminModelDecoder.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Admin API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FAdminLookupUserAccountInfoResult UPlayFabAdminModelDecoder::decodeLookupUserAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminLookupUserAccountInfoResult tempStruct;

    /** User info for the user matching the request */
    tempStruct.UserInfo = response->GetObjectField("data")->GetObjectField("UserInfo");

    return tempStruct;
}

FAdminBlankResult UPlayFabAdminModelDecoder::decodeBlankResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminBlankResult tempStruct;

    return tempStruct;
}

FAdminSendAccountRecoveryEmailResult UPlayFabAdminModelDecoder::decodeSendAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSendAccountRecoveryEmailResult tempStruct;

    return tempStruct;
}

FAdminUpdateUserTitleDisplayNameResult UPlayFabAdminModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateUserTitleDisplayNameResult tempStruct;

    /** current title display name for the user (this will be the original display name if the rename attempt failed) */
    tempStruct.DisplayName = response->GetObjectField("data")->GetStringField("DisplayName");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

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

    /**  */
    tempStruct.DownloadUrl = response->GetObjectField("data")->GetStringField("DownloadUrl");

    return tempStruct;
}

FAdminGetUserDataResult UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserDataResult tempStruct;

    /** PlayFab unique identifier of the user whose custom data is being returned. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = int(response->GetObjectField("data")->GetNumberField("DataVersion"));

    /** User specific data for this title. */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    return tempStruct;
}

FAdminResetUserStatisticsResult UPlayFabAdminModelDecoder::decodeResetUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminResetUserStatisticsResult tempStruct;

    return tempStruct;
}

FAdminUpdateUserDataResult UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateUserDataResult tempStruct;

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    tempStruct.DataVersion = int(response->GetObjectField("data")->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

FAdminAddNewsResult UPlayFabAdminModelDecoder::decodeAddNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminAddNewsResult tempStruct;

    /** Unique id of the new news item */
    tempStruct.NewsId = response->GetObjectField("data")->GetStringField("NewsId");

    return tempStruct;
}

FAdminGetCatalogItemsResult UPlayFabAdminModelDecoder::decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCatalogItemsResult tempStruct;

    /** Array of items which can be purchased. */
    tempStruct.Catalog = response->GetObjectField("data")->GetObjectArrayField("Catalog");

    return tempStruct;
}

FAdminGetRandomResultTablesResult UPlayFabAdminModelDecoder::decodeGetRandomResultTablesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetRandomResultTablesResult tempStruct;

    /** array of random result tables currently available */
    tempStruct.Tables = response->GetObjectField("data")->GetObjectField("Tables");

    return tempStruct;
}

FAdminGetStoreItemsResult UPlayFabAdminModelDecoder::decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetStoreItemsResult tempStruct;

    /** Array of items which can be purchased from this store. */
    tempStruct.Store = response->GetObjectField("data")->GetObjectArrayField("Store");

    return tempStruct;
}

FAdminGetTitleDataResult UPlayFabAdminModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetTitleDataResult tempStruct;

    /** a dictionary object of key / value pairs */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    return tempStruct;
}

FAdminListVirtualCurrencyTypesResult UPlayFabAdminModelDecoder::decodeListVirtualCurrencyTypesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminListVirtualCurrencyTypesResult tempStruct;

    /** List of virtual currency names defined for this title */
    tempStruct.VirtualCurrencies = response->GetObjectField("data")->GetObjectArrayField("VirtualCurrencies");

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

    /** Amazon Resource Name for the created notification topic. */
    tempStruct.ARN = response->GetObjectField("data")->GetStringField("ARN");

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

FAdminGetUserInventoryResult UPlayFabAdminModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserInventoryResult tempStruct;

    /** PlayFab unique identifier of the user whose inventory is being returned. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** Array of inventory items belonging to the user. */
    tempStruct.Inventory = response->GetObjectField("data")->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = response->GetObjectField("data")->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FAdminGrantItemsToUsersResult UPlayFabAdminModelDecoder::decodeGrantItemsToUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGrantItemsToUsersResult tempStruct;

    /** Array of items granted to users. */
    tempStruct.ItemGrantResults = response->GetObjectField("data")->GetObjectArrayField("ItemGrantResults");

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

    /** unique identifier of the lobby  */
    tempStruct.LobbyId = response->GetObjectField("data")->GetStringField("LobbyId");

    /** unique identifier of the Game Server Instance for this lobby */
    tempStruct.TitleId = response->GetObjectField("data")->GetStringField("TitleId");

    /** time when the Game Server Instance was created */
    tempStruct.StartTime = response->GetObjectField("data")->GetStringField("StartTime");

    /** time when Game Server Instance is currently scheduled to end */
    tempStruct.EndTime = response->GetObjectField("data")->GetStringField("EndTime");

    /** game mode for this Game Server Instance */
    tempStruct.Mode = response->GetObjectField("data")->GetStringField("Mode");

    /** version identifier of the game server executable binary being run */
    tempStruct.BuildVersion = response->GetObjectField("data")->GetStringField("BuildVersion");

    /** region in which the Game Server Instance is running */
    tempStruct.Region = response->GetObjectField("data")->GetStringField("Region");

    /** array of unique PlayFab identifiers for users currently connected to this Game Server Instance */
    tempStruct.Players = FString::Join(response->GetObjectField("data")->GetStringArrayField("Players"), TEXT(","));

    /** IP address for this Game Server Instance */
    tempStruct.ServerAddress = response->GetObjectField("data")->GetStringField("ServerAddress");

    /** communication port for this Game Server Instance */
    tempStruct.ServerPort = int(response->GetObjectField("data")->GetNumberField("ServerPort"));

    return tempStruct;
}

FAdminGetMatchmakerGameModesResult UPlayFabAdminModelDecoder::decodeGetMatchmakerGameModesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetMatchmakerGameModesResult tempStruct;

    /** array of game modes available for the specified build */
    tempStruct.GameModes = response->GetObjectField("data")->GetObjectArrayField("GameModes");

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

    /** unique identifier for this build executable */
    tempStruct.BuildId = response->GetObjectField("data")->GetStringField("BuildId");

    /** array of regions where this build can used, when it is active */
    tempStruct.ActiveRegions = FString::Join(response->GetObjectField("data")->GetStringArrayField("ActiveRegions"), TEXT(","));

    /** maximum number of game server instances that can run on a single host machine */
    tempStruct.MaxGamesPerHost = int(response->GetObjectField("data")->GetNumberField("MaxGamesPerHost"));

    /** appended to the end of the command line when starting game servers */
    tempStruct.CommandLineTemplate = response->GetObjectField("data")->GetStringField("CommandLineTemplate");

    /** path to the game server executable. Defaults to gameserver.exe */
    tempStruct.ExecutablePath = response->GetObjectField("data")->GetStringField("ExecutablePath");

    /** developer comment(s) for this build */
    tempStruct.Comment = response->GetObjectField("data")->GetStringField("Comment");

    /** time this build was last modified (or uploaded, if this build has never been modified) */
    tempStruct.Timestamp = response->GetObjectField("data")->GetStringField("Timestamp");

    /** Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a title has been selected */
    tempStruct.TitleId = response->GetObjectField("data")->GetStringField("TitleId");

    /** the current status of the build validation and processing steps */
    tempStruct.Status = response->GetObjectField("data")->GetStringField("Status");

    return tempStruct;
}

FAdminGetServerBuildInfoResult UPlayFabAdminModelDecoder::decodeGetServerBuildInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetServerBuildInfoResult tempStruct;

    /** unique identifier for this build executable */
    tempStruct.BuildId = response->GetObjectField("data")->GetStringField("BuildId");

    /** array of regions where this build can used, when it is active */
    tempStruct.ActiveRegions = FString::Join(response->GetObjectField("data")->GetStringArrayField("ActiveRegions"), TEXT(","));

    /** maximum number of game server instances that can run on a single host machine */
    tempStruct.MaxGamesPerHost = int(response->GetObjectField("data")->GetNumberField("MaxGamesPerHost"));

    /** developer comment(s) for this build */
    tempStruct.Comment = response->GetObjectField("data")->GetStringField("Comment");

    /** time this build was last modified (or uploaded, if this build has never been modified) */
    tempStruct.Timestamp = response->GetObjectField("data")->GetStringField("Timestamp");

    /** Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a title has been selected */
    tempStruct.TitleId = response->GetObjectField("data")->GetStringField("TitleId");

    /** the current status of the build validation and processing steps */
    tempStruct.Status = response->GetObjectField("data")->GetStringField("Status");

    /** error message, if any, about this build */
    tempStruct.ErrorMessage = response->GetObjectField("data")->GetStringField("ErrorMessage");

    return tempStruct;
}

FAdminGetServerBuildUploadURLResult UPlayFabAdminModelDecoder::decodeGetServerBuildUploadURLResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetServerBuildUploadURLResult tempStruct;

    /** pre-authorized URL for uploading the game server build package */
    tempStruct.URL = response->GetObjectField("data")->GetStringField("URL");

    return tempStruct;
}

FAdminListBuildsResult UPlayFabAdminModelDecoder::decodeListBuildsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminListBuildsResult tempStruct;

    /** array of uploaded game server builds */
    tempStruct.Builds = response->GetObjectField("data")->GetObjectArrayField("Builds");

    return tempStruct;
}

FAdminModifyServerBuildResult UPlayFabAdminModelDecoder::decodeModifyServerBuildResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminModifyServerBuildResult tempStruct;

    /** unique identifier for this build executable */
    tempStruct.BuildId = response->GetObjectField("data")->GetStringField("BuildId");

    /** array of regions where this build can used, when it is active */
    tempStruct.ActiveRegions = FString::Join(response->GetObjectField("data")->GetStringArrayField("ActiveRegions"), TEXT(","));

    /** maximum number of game server instances that can run on a single host machine */
    tempStruct.MaxGamesPerHost = int(response->GetObjectField("data")->GetNumberField("MaxGamesPerHost"));

    /** appended to the end of the command line when starting game servers */
    tempStruct.CommandLineTemplate = response->GetObjectField("data")->GetStringField("CommandLineTemplate");

    /** path to the game server executable. Defaults to gameserver.exe */
    tempStruct.ExecutablePath = response->GetObjectField("data")->GetStringField("ExecutablePath");

    /** developer comment(s) for this build */
    tempStruct.Comment = response->GetObjectField("data")->GetStringField("Comment");

    /** time this build was last modified (or uploaded, if this build has never been modified) */
    tempStruct.Timestamp = response->GetObjectField("data")->GetStringField("Timestamp");

    /** Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a title has been selected */
    tempStruct.TitleId = response->GetObjectField("data")->GetStringField("TitleId");

    /** the current status of the build validation and processing steps */
    tempStruct.Status = response->GetObjectField("data")->GetStringField("Status");

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

FAdminGetPublisherDataResult UPlayFabAdminModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPublisherDataResult tempStruct;

    /** a dictionary object of key / value pairs */
    tempStruct.Data = response->GetObjectField("data")->GetObjectField("Data");

    return tempStruct;
}

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

    /** Version number. */
    tempStruct.Version = int(response->GetObjectField("data")->GetNumberField("Version"));

    /** Revision number. */
    tempStruct.Revision = int(response->GetObjectField("data")->GetNumberField("Revision"));

    /** Time this revision was created */
    tempStruct.CreatedAt = response->GetObjectField("data")->GetStringField("CreatedAt");

    /** List of Cloud Script files in this revision. */
    tempStruct.Files = response->GetObjectField("data")->GetObjectArrayField("Files");

    /** True if this is the currently published revision */
    tempStruct.IsPublished = response->GetObjectField("data")->GetBoolField("IsPublished");

    return tempStruct;
}

FAdminGetCloudScriptVersionsResult UPlayFabAdminModelDecoder::decodeGetCloudScriptVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCloudScriptVersionsResult tempStruct;

    /** List of versions */
    tempStruct.Versions = response->GetObjectField("data")->GetObjectArrayField("Versions");

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

    /** Cloud Script version updated */
    tempStruct.Version = int(response->GetObjectField("data")->GetNumberField("Version"));

    /** New revision number created */
    tempStruct.Revision = int(response->GetObjectField("data")->GetNumberField("Revision"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FAdminGetContentListResult UPlayFabAdminModelDecoder::decodeGetContentListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetContentListResult tempStruct;

    /** Number of content items returned. We currently have a maximum of 1000 items limit. */
    tempStruct.ItemCount = int(response->GetObjectField("data")->GetNumberField("ItemCount"));

    /** The total size of listed contents in bytes */
    tempStruct.TotalSize = int(response->GetObjectField("data")->GetNumberField("TotalSize"));

    /**  */
    tempStruct.Contents = response->GetObjectField("data")->GetObjectArrayField("Contents");

    return tempStruct;
}

FAdminGetContentUploadUrlResult UPlayFabAdminModelDecoder::decodeGetContentUploadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetContentUploadUrlResult tempStruct;

    /** URL for uploading content via HTTP PUT method. The URL will expire in 1 hour. */
    tempStruct.URL = response->GetObjectField("data")->GetStringField("URL");

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



