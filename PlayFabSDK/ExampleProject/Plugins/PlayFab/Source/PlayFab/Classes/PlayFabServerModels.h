#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Server
// SDK Version: 0.0.160222
//////////////////////////////////////////////////////////////////////////////////////////////

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabServerModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAuthenticateSessionTicketRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Session ticket as issued by a PlayFab client login API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString SessionTicket;

};

USTRUCT(BlueprintType)
struct FServerAuthenticateSessionTicketResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Account info for the user whose session ticket was supplied. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* UserInfo;
};



///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromFacebookIDsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of unique Facebook identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString FacebookIDs;

};

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromFacebookIDsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;

};

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromSteamIDsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Deprecated: Please use SteamStringIDs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<int32> SteamIDs;

    /** Array of unique Steam identifiers (Steam profile IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString SteamStringIDs;

};

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromSteamIDsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Mapping of Steam identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;

};

USTRUCT(BlueprintType)
struct FServerGetUserAccountInfoRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;

};

USTRUCT(BlueprintType)
struct FServerGetUserAccountInfoResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Account details for the user whose information was requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* UserInfo;
};

USTRUCT(BlueprintType)
struct FServerSendPushNotificationRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFabId of the recipient of the push notification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Recipient;

    /** Text of message to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Message;

    /** Subject of message to send (may not be displayed in all platforms. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Subject;

};

USTRUCT(BlueprintType)
struct FServerSendPushNotificationResult
{
    GENERATED_USTRUCT_BODY()

public:

};



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerDeleteUsersRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabIds;

};

USTRUCT(BlueprintType)
struct FServerDeleteUsersResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;

    /** First entry in the leaderboard to be retrieved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 StartPosition;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;

};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundUserRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundUserResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;

};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** user for whom statistics are being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** statistics to return */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticNames;

    /** statistics to return, if StatisticNames is not set (only statistics which have a version matching that provided will be returned) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticNameVersions;

};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose statistics are being returned */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** User statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;

};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticVersionsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;

};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticVersionsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;

};

USTRUCT(BlueprintType)
struct FServerGetUserDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString Keys;

    /** The version that currently exists according to the caller. The call will return the data for all of the keys if the version in the system is greater than this. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 IfChangedFromDataVersion;
};

USTRUCT(BlueprintType)
struct FServerGetUserDataResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose custom data is being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 DataVersion;
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data;

};

USTRUCT(BlueprintType)
struct FServerGetUserStatisticsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** User for whom statistics are being requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

};

USTRUCT(BlueprintType)
struct FServerGetUserStatisticsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose statistics are being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** User statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* UserStatistics;

};

USTRUCT(BlueprintType)
struct FServerUpdatePlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** Statistics to be updated with the provided values */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;

};

USTRUCT(BlueprintType)
struct FServerUpdatePlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerUpdateUserDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data;

    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString KeysToRemove;

    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        EPermissionEnum Permission;

};

USTRUCT(BlueprintType)
struct FServerUpdateUserDataResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 DataVersion;
};

USTRUCT(BlueprintType)
struct FServerUpdateUserInternalDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data;

    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString KeysToRemove;

};

USTRUCT(BlueprintType)
struct FServerUpdateUserStatisticsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;

    /** Statistics to be updated with the provided values. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* UserStatistics;

};

USTRUCT(BlueprintType)
struct FServerUpdateUserStatisticsResult
{
    GENERATED_USTRUCT_BODY()

public:

};



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerGetCatalogItemsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Which catalog is being requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString CatalogVersion;

};

USTRUCT(BlueprintType)
struct FServerGetCatalogItemsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;

};

USTRUCT(BlueprintType)
struct FServerGetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Keys;

};

USTRUCT(BlueprintType)
struct FServerGetTitleDataResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;

};

USTRUCT(BlueprintType)
struct FServerGetTitleNewsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Limits the results to the last n entries. Defaults to 10 if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        int32 Count;
};

USTRUCT(BlueprintType)
struct FServerGetTitleNewsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of news items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> News;

};

USTRUCT(BlueprintType)
struct FServerSetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Key;

    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Value;

};

USTRUCT(BlueprintType)
struct FServerSetTitleDataResult
{
    GENERATED_USTRUCT_BODY()

public:

};



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAddCharacterVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose virtual currency balance is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;

    /** Amount to be added to the character balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount;
};

USTRUCT(BlueprintType)
struct FServerModifyCharacterVirtualCurrencyResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;

    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Balance;
};

USTRUCT(BlueprintType)
struct FServerAddUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose virtual currency balance is to be increased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;

    /** Amount to be added to the user balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount;
};

USTRUCT(BlueprintType)
struct FServerModifyUserVirtualCurrencyResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** User currency was subtracted from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;

    /** Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 BalanceChange;
    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Balance;
};

USTRUCT(BlueprintType)
struct FServerConsumeItemRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique instance identifier of the item to be consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

    /** Number of uses to consume from the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 ConsumeCount;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

};

USTRUCT(BlueprintType)
struct FServerConsumeItemResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique instance identifier of the item with uses consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

    /** Number of uses remaining on the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 RemainingUses;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterInventoryRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Used to limit results to only those from a specific catalog version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;

};

USTRUCT(BlueprintType)
struct FServerGetCharacterInventoryResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose character inventory is being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique identifier of the character for this inventory. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Array of inventory items belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;

    /** Array of virtual currency balance(s) belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;

    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes;

};

USTRUCT(BlueprintType)
struct FServerGetUserInventoryRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

};

USTRUCT(BlueprintType)
struct FServerGetUserInventoryResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose inventory is being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Array of inventory items belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;

    /** Array of virtual currency balance(s) belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;

    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes;

};

USTRUCT(BlueprintType)
struct FServerGrantItemsToCharacterRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** String detailing any additional information concerning this operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Annotation;

    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;

};

USTRUCT(BlueprintType)
struct FServerGrantItemsToCharacterResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;

};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUserRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** String detailing any additional information concerning this operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Annotation;

    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;

};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUserResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;

};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUsersRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;

    /** Array of items to grant and the users to whom the items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrants;

};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUsersResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;

};

USTRUCT(BlueprintType)
struct FServerModifyItemUsesRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose item is being modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique instance identifier of the item to be modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

    /** Number of uses to add to the item. Can be negative to remove uses. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 UsesToAdd;
};

USTRUCT(BlueprintType)
struct FServerModifyItemUsesResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique instance identifier of the item with uses consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

    /** Number of uses remaining on the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 RemainingUses;
};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromCharacterRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique identifier of the character that currently has the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString GivingCharacterId;

    /** Unique identifier of the character that will be receiving the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReceivingCharacterId;

    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromCharacterResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromUserRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromUserResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerMoveItemToUserFromCharacterRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

};

USTRUCT(BlueprintType)
struct FServerMoveItemToUserFromCharacterResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerRedeemCouponRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Generated coupon code to redeem. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CouponCode;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Catalog version of the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;

};

USTRUCT(BlueprintType)
struct FServerRedeemCouponResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Items granted to the player as a result of redeeming the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;

};

USTRUCT(BlueprintType)
struct FServerReportPlayerServerRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFabId of the reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporterId;

    /** PlayFabId of the reported player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporteeId;

    /** Optional additional comment by reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Comment;

};

USTRUCT(BlueprintType)
struct FServerReportPlayerServerResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Indicates whether this action completed successfully. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        bool Updated;
    /** The number of remaining reports which may be filed today by this reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 SubmissionsRemaining;
};

USTRUCT(BlueprintType)
struct FServerRevokeInventoryItemRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

};

USTRUCT(BlueprintType)
struct FServerRevokeInventoryResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerSubtractCharacterVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;

    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount;
};

USTRUCT(BlueprintType)
struct FServerSubtractUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose virtual currency balance is to be decreased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;

    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount;
};

USTRUCT(BlueprintType)
struct FServerUnlockContainerInstanceRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** ItemInstanceId of the container to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ContainerItemInstanceId;

    /** ItemInstanceId of the key that will be consumed by unlocking this container.  If the container requires a key, this parameter is required. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString KeyItemInstanceId;

    /** Specifies the catalog version that should be used to determine container contents.  If unspecified, uses catalog associated with the item instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;

};

USTRUCT(BlueprintType)
struct FServerUnlockContainerItemResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique instance identifier of the container unlocked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString UnlockedItemInstanceId;

    /** Unique instance identifier of the key used to unlock the container, if applicable. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString UnlockedWithItemInstanceId;

    /** Items granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;

    /** Virtual currency granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;

};

USTRUCT(BlueprintType)
struct FServerUnlockContainerItemRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Catalog ItemId of the container type to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ContainerItemId;

    /** Specifies the catalog version that should be used to determine container contents.  If unspecified, uses default/primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;

};

USTRUCT(BlueprintType)
struct FServerUpdateUserInventoryItemDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;

    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;

    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* Data;

    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString KeysToRemove;

};

USTRUCT(BlueprintType)
struct FServerUpdateUserInventoryItemDataResult
{
    GENERATED_USTRUCT_BODY()

public:

};



///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerNotifyMatchmakerPlayerLeftRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier of the Game Instance the user is leaving. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        FString LobbyId;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        FString PlayFabId;

};

USTRUCT(BlueprintType)
struct FServerNotifyMatchmakerPlayerLeftResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** State of user leaving the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        FString PlayerState;

};

USTRUCT(BlueprintType)
struct FServerRedeemMatchmakerTicketRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Server authorization ticket passed back from a call to Matchmake or StartGame. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        FString Ticket;

    /** Unique identifier of the Game Server Instance that is asking for validation of the authorization ticket. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        FString LobbyId;

};

USTRUCT(BlueprintType)
struct FServerRedeemMatchmakerTicketResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Boolean indicating whether the ticket was validated by the PlayFab service. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        bool TicketIsValid;
    /** Error value if the ticket was not validated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        FString Error;

    /** User account information for the user validated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking APIs Models")
        UPlayFabJsonObject* UserInfo;
};



///////////////////////////////////////////////////////
// Steam-Specific APIs
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAwardSteamAchievementRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of achievements to grant and the users to whom they are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Steam-Specific APIs Models")
        TArray<UPlayFabJsonObject*> Achievements;

};

USTRUCT(BlueprintType)
struct FServerAwardSteamAchievementResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Array of achievements granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Steam-Specific APIs Models")
        TArray<UPlayFabJsonObject*> AchievementResults;

};



///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerLogEventRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab User Id of the player associated with this event. For non-player associated events, this must be null and EntityId must be set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString PlayFabId;

    /** For non player-associated events, a unique ID for the entity associated with this event. For player associated events, this must be null and PlayFabId must be set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EntityId;

    /** For non player-associated events, the type of entity associated with this event. For player associated events, this must be null. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EntityType;

    /** Optional timestamp for this event. If null, the a timestamp is auto-assigned to the event on the server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;

    /** A unique event name which will be used as the table name in the Redshift database. The name will be made lower case, and cannot not contain spaces. The use of underscores is recommended, for readability. Events also cannot match reserved terms. The PlayFab reserved terms are 'log_in' and 'purchase', 'create' and 'request', while the Redshift reserved terms can be found here: http://docs.aws.amazon.com/redshift/latest/dg/r_pg_keywords.html. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;

    /** Contains all the data for this event. Event Values can be strings, booleans or numerics (float, double, integer, long) and must be consistent on a per-event basis (if the Value for Key 'A' in Event 'Foo' is an integer the first time it is sent, it must be an integer in all subsequent 'Foo' events). As with event names, Keys must also not use reserved words (see above). Finally, the size of the Body for an event must be less than 32KB (UTF-8 format). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body;

    /** Flag to set event Body as profile details in the Redshift database as well as a standard event. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        bool ProfileSetEvent;
};

USTRUCT(BlueprintType)
struct FServerLogEventResult
{
    GENERATED_USTRUCT_BODY()

public:

};



///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAddSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;

    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString PlayFabIds;

};

USTRUCT(BlueprintType)
struct FServerAddSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerCreateSharedGroupRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the shared group (a random identifier will be assigned, if one is not specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;

};

USTRUCT(BlueprintType)
struct FServerCreateSharedGroupResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;

};

USTRUCT(BlueprintType)
struct FServerDeleteSharedGroupRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;

};

USTRUCT(BlueprintType)
struct FServerEmptyResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerGetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /**  array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Keys;

};

USTRUCT(BlueprintType)
struct FServerGetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data;

};

USTRUCT(BlueprintType)
struct FServerGetSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;

    /** Specific keys to retrieve from the shared group (if not specified, all keys will be returned, while an empty array indicates that no keys should be returned). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Keys;

    /** If true, return the list of all members of the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        bool GetMembers;
};

USTRUCT(BlueprintType)
struct FServerGetSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Data for the requested keys. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data;

    /** List of PlayFabId identifiers for the members of this group, if requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Members;

};

USTRUCT(BlueprintType)
struct FServerRemoveSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;

    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString PlayFabIds;

};

USTRUCT(BlueprintType)
struct FServerRemoveSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerSetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Key;

    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Value;

};

USTRUCT(BlueprintType)
struct FServerSetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerUpdateSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;

    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data;

    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString KeysToRemove;

    /** Permission to be applied to all user data keys in this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        EPermissionEnum Permission;

};

USTRUCT(BlueprintType)
struct FServerUpdateSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()

public:

};



///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerGetContentDownloadUrlRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Key of the content item to fetch, usually formatted as a path, e.g. images/a.png */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString Key;

    /** HTTP method to fetch item - GET or HEAD. Use HEAD when only fetching metadata. Default is GET. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString HttpMethod;

    /** True if download through CDN. CDN provides better download bandwidth and time. However, if you want latest, non-cached version of the content, set this to false. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        bool ThruCDN;
};

USTRUCT(BlueprintType)
struct FServerGetContentDownloadUrlResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** URL for downloading content via HTTP GET or HEAD method. The URL will expire in 1 hour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString URL;

};



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerDeleteCharacterFromUserRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;

    /** If true, the character's inventory will be transferred up to the owning user; otherwise, this request will purge those items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        bool SaveCharacterInventory;
};

USTRUCT(BlueprintType)
struct FServerDeleteCharacterFromUserResult
{
    GENERATED_USTRUCT_BODY()

public:

};

USTRUCT(BlueprintType)
struct FServerListUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

};

USTRUCT(BlueprintType)
struct FServerListUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** The requested list of characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Characters;

};

USTRUCT(BlueprintType)
struct FServerGetCharacterLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;

    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;

    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;

    /** First entry in the leaderboard to be retrieved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 StartPosition;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterLeaderboardResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;

};

USTRUCT(BlueprintType)
struct FServerGetCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;

};

USTRUCT(BlueprintType)
struct FServerGetCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** PlayFab unique identifier of the user whose character statistics are being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

    /** Unique identifier of the character for the statistics. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;

    /** Character statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;

};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundCharacterRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;

    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;

    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundCharacterResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;

};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardForUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardForUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;

};

USTRUCT(BlueprintType)
struct FServerGrantCharacterToUserRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

    /** Non-unique display name of the character being granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterName;

    /** Type of the character being granted; statistics can be sliced based on this value. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;

};

USTRUCT(BlueprintType)
struct FServerGrantCharacterToUserResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique identifier tagged to this character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;

};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;

    /** Statistics to be updated with the provided values. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;

};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()

public:

};



///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerGetCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;

    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString Keys;

    /** The version that currently exists according to the caller. The call will return the data for all of the keys if the version in the system is greater than this. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 IfChangedFromDataVersion;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterDataResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 DataVersion;
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* Data;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;

};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()

public:

    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;

    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;

    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* Data;

    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString KeysToRemove;

    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        EPermissionEnum Permission;

};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterDataResult
{
    GENERATED_USTRUCT_BODY()

public:

    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 DataVersion;
};


