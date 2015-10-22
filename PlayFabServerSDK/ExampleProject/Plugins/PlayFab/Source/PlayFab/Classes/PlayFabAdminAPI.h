#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Admin
// API Version: 1.7.20151019
// SDK Version: 0.0.151019
//////////////////////////////////////////////////////////////////////////////////////////////

#include "OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabAdminModels.h"
#include "PlayFabPrivatePCH.h"
#include "PlayFabAdminAPI.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayFabAdminRequestCompleted, FPlayFabBaseModel, response, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class UPlayFabAdminAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:

    UPROPERTY(BlueprintAssignable)
    FOnPlayFabAdminRequestCompleted OnPlayFabResponse;

    /** Set the Request Json object */
    //UFUNCTION(BlueprintCallable, Category = "PlayFab")
        void SetRequestObject(UPlayFabJsonObject* JsonObject);

    /** Get the Response Json object */
    //UFUNCTION(BlueprintCallable, Category = "PlayFab")
        UPlayFabJsonObject* GetResponseObject();

    /** Applies percent-encoding to text */
    //UFUNCTION(BlueprintCallable, Category = "PlayFab")
        static FString PercentEncode(const FString& Text);

    /** Reset saved response data */
    //UFUNCTION(BlueprintCallable, Category = "PlayFab")
        void ResetResponseData();

    /** UOnlineBlueprintCallProxyBase interface */
    virtual void Activate() override;

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Admin API Functions
    //////////////////////////////////////////////////////////////////////////

    

    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////
    /** Retrieves the relevant details for a specified user, based upon a match against a supplied unique identifier */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserAccountInfo(FAdminLookupUserAccountInfoRequest request);

    /** Resets all title-specific information about a particular account, including user data, virtual currency balances, inventory, purchase history, and statistics */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ResetUsers(FAdminResetUsersRequest request);

    /** Forces an email to be sent to the registered email address for the specified account, with a link allowing the user to change the password */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SendAccountRecoveryEmail(FAdminSendAccountRecoveryEmailRequest request);

    /** Updates the title specific display name for a user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserTitleDisplayName(FAdminUpdateUserTitleDisplayNameRequest request);



    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////
    /** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteUsers(FAdminDeleteUsersRequest request);

    /** Retrieves a download URL for the requested report */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetDataReport(FAdminGetDataReportRequest request);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserData(FAdminGetUserDataRequest request);

    /** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserInternalData(FAdminGetUserDataRequest request);

    /** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserPublisherData(FAdminGetUserDataRequest request);

    /** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserPublisherInternalData(FAdminGetUserDataRequest request);

    /** Retrieves the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserPublisherReadOnlyData(FAdminGetUserDataRequest request);

    /** Retrieves the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserReadOnlyData(FAdminGetUserDataRequest request);

    /** Completely removes all statistics for the specified user, for the current game */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ResetUserStatistics(FAdminResetUserStatisticsRequest request);

    /** Updates the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserData(FAdminUpdateUserDataRequest request);

    /** Updates the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserInternalData(FAdminUpdateUserInternalDataRequest request);

    /** Updates the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserPublisherData(FAdminUpdateUserDataRequest request);

    /** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserPublisherInternalData(FAdminUpdateUserInternalDataRequest request);

    /** Updates the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserPublisherReadOnlyData(FAdminUpdateUserDataRequest request);

    /** Updates the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserReadOnlyData(FAdminUpdateUserDataRequest request);



    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////
    /** Adds a new news item to the title's news feed */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddNews(FAdminAddNewsRequest request);

    /** Adds one or more virtual currencies to the set defined for the title. Virtual Currencies have a maximum value of 2,147,483,647 when granted to a player. Any value over that will be discarded. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddVirtualCurrencyTypes(FAdminAddVirtualCurrencyTypesRequest request);

    /** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetCatalogItems(FAdminGetCatalogItemsRequest request);

    /** Retrieves the random drop table configuration for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetRandomResultTables(FAdminGetRandomResultTablesRequest request);

    /** Retrieves the set of items defined for the specified store, including all prices defined */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetStoreItems(FAdminGetStoreItemsRequest request);

    /** Retrieves the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetTitleData(FAdminGetTitleDataRequest request);

    /** Retuns the list of all defined virtual currencies for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ListVirtualCurrencyTypes(FAdminListVirtualCurrencyTypesRequest request);

    /** Creates the catalog configuration of all virtual goods for the specified catalog version */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetCatalogItems(FAdminUpdateCatalogItemsRequest request);

    /** Sets all the items in one virtual store */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetStoreItems(FAdminUpdateStoreItemsRequest request);

    /** Creates and updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetTitleData(FAdminSetTitleDataRequest request);

    /** Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the exact restrictions can be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html. Currently, Amazon device Messaging is not supported. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetupPushNotification(FAdminSetupPushNotificationRequest request);

    /** Updates the catalog configuration for virtual goods in the specified catalog version */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateCatalogItems(FAdminUpdateCatalogItemsRequest request);

    /** Updates the random drop table configuration for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateRandomResultTables(FAdminUpdateRandomResultTablesRequest request);

    /** Updates an existing virtual item store with new or modified items */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateStoreItems(FAdminUpdateStoreItemsRequest request);



    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////
    /** Increments the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddUserVirtualCurrency(FAdminAddUserVirtualCurrencyRequest request);

    /** Retrieves the specified user's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserInventory(FAdminGetUserInventoryRequest request);

    /** Adds the specified items to the specified user inventories */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GrantItemsToUsers(FAdminGrantItemsToUsersRequest request);

    /** Revokes access to an item in a user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RevokeInventoryItem(FAdminRevokeInventoryItemRequest request);

    /** Decrements the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SubtractUserVirtualCurrency(FAdminSubtractUserVirtualCurrencyRequest request);



    ///////////////////////////////////////////////////////
    // Matchmaking APIs
    //////////////////////////////////////////////////////
    /** Retrieves the details for a specific completed session, including links to standard out and standard error logs */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetMatchmakerGameInfo(FAdminGetMatchmakerGameInfoRequest request);

    /** Retrieves the details of defined game modes for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetMatchmakerGameModes(FAdminGetMatchmakerGameModesRequest request);

    /** Updates the game server mode details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ModifyMatchmakerGameModes(FAdminModifyMatchmakerGameModesRequest request);



    ///////////////////////////////////////////////////////
    // Custom Server Management
    //////////////////////////////////////////////////////
    /** Adds the game server executable specified (previously uploaded - see GetServerBuildUploadUrl) to the set of those a client is permitted to request in a call to StartGame */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddServerBuild(FAdminAddServerBuildRequest request);

    /** Retrieves the build details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetServerBuildInfo(FAdminGetServerBuildInfoRequest request);

    /** Retrieves the pre-authorized URL for uploading a game server package containing a build (does not enable the build for use - see AddServerBuild) */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetServerBuildUploadUrl(FAdminGetServerBuildUploadURLRequest request);

    /** Retrieves the build details for all game server executables which are currently defined for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ListServerBuilds(FAdminListBuildsRequest request);

    /** Updates the build details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ModifyServerBuild(FAdminModifyServerBuildRequest request);

    /** Removes the game server executable specified from the set of those a client is permitted to request in a call to StartGame */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RemoveServerBuild(FAdminRemoveServerBuildRequest request);



    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////
    /** Retrieves the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPublisherData(FAdminGetPublisherDataRequest request);

    /** Updates the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetPublisherData(FAdminSetPublisherDataRequest request);



    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////
    /** Gets the contents and information of a specific Cloud Script revision. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetCloudScriptRevision(FAdminGetCloudScriptRevisionRequest request);

    /** Lists all the current cloud script versions. For each version, information about the current published and latest revisions is also listed. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetCloudScriptVersions(FAdminGetCloudScriptVersionsRequest request);

    /** Sets the currently published revision of a title Cloud Script */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetPublishedRevision(FAdminSetPublishedRevisionRequest request);

    /** Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one file should be submitted in the revision. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateCloudScript(FAdminUpdateCloudScriptRequest request);



    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////
    /** Delete a content file from the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteContent(FAdminDeleteContentRequest request);

    /** List all contents of the title and get statistics such as size */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetContentList(FAdminGetContentListRequest request);

    /** Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned URL uploads the content. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetContentUploadUrl(FAdminGetContentUploadUrlRequest request);



    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////
    /** Completely removes all statistics for the specified character, for the current game */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ResetCharacterStatistics(FAdminResetCharacterStatisticsRequest request);



    /** PlayFab Request Info */
    FString PlayFabRequestURL;
    bool useSecretKey = false;
    bool useSessionTicket = false;
    bool cloudScript = false;
    bool isLoginRequest = false;

    /** Is the response valid JSON? */
    bool bIsValidJsonResponse;
    FString ResponseContent;
    int32 ResponseCode;

private:
    /** Internal bind function for the IHTTPRequest::OnProcessRequestCompleted() event */
    void OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:

    /** Internal request data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* RequestJsonObj;

    /** Response data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* ResponseJsonObj;

    /** Mapping of header section to values. Used to generate final header string for request */
    TMap<FString, FString> RequestHeaders;
};
