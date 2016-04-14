#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Admin
// SDK Version: 0.0.160414
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

    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnFailurePlayFabError, FPlayFabError, error);

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
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserAccountInfo, FAdminLookupUserAccountInfoResult, result);

    /** Retrieves the relevant details for a specified user, based upon a match against a supplied unique identifier */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserAccountInfo(FAdminLookupUserAccountInfoRequest request,
        FDelegateOnSuccessGetUserAccountInfo onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserAccountInfo(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessResetUsers, FAdminBlankResult, result);

    /** Resets all title-specific information about a particular account, including user data, virtual currency balances, inventory, purchase history, and statistics */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* ResetUsers(FAdminResetUsersRequest request,
        FDelegateOnSuccessResetUsers onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperResetUsers(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSendAccountRecoveryEmail, FAdminSendAccountRecoveryEmailResult, result);

    /** Forces an email to be sent to the registered email address for the specified account, with a link allowing the user to change the password */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SendAccountRecoveryEmail(FAdminSendAccountRecoveryEmailRequest request,
        FDelegateOnSuccessSendAccountRecoveryEmail onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSendAccountRecoveryEmail(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserTitleDisplayName, FAdminUpdateUserTitleDisplayNameResult, result);

    /** Updates the title specific display name for a user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateUserTitleDisplayName(FAdminUpdateUserTitleDisplayNameRequest request,
        FDelegateOnSuccessUpdateUserTitleDisplayName onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserTitleDisplayName(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessCreatePlayerStatisticDefinition, FAdminCreatePlayerStatisticDefinitionResult, result);

    /** Adds a new player statistic configuration to the title, optionally allowing the developer to specify a reset interval. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* CreatePlayerStatisticDefinition(FAdminCreatePlayerStatisticDefinitionRequest request,
        FDelegateOnSuccessCreatePlayerStatisticDefinition onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperCreatePlayerStatisticDefinition(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessDeleteUsers, FAdminDeleteUsersResult, result);

    /** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* DeleteUsers(FAdminDeleteUsersRequest request,
        FDelegateOnSuccessDeleteUsers onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperDeleteUsers(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetDataReport, FAdminGetDataReportResult, result);

    /** Retrieves a download URL for the requested report */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetDataReport(FAdminGetDataReportRequest request,
        FDelegateOnSuccessGetDataReport onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetDataReport(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPlayerStatisticDefinitions, FAdminGetPlayerStatisticDefinitionsResult, result);

    /** Retrieves the configuration information for all player statistics defined in the title, regardless of whether they have a reset interval. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetPlayerStatisticDefinitions(FAdminGetPlayerStatisticDefinitionsRequest request,
        FDelegateOnSuccessGetPlayerStatisticDefinitions onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPlayerStatisticDefinitions(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPlayerStatisticVersions, FAdminGetPlayerStatisticVersionsResult, result);

    /** Retrieves the information on the available versions of the specified statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetPlayerStatisticVersions(FAdminGetPlayerStatisticVersionsRequest request,
        FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserData, FAdminGetUserDataResult, result);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserData(FAdminGetUserDataRequest request,
        FDelegateOnSuccessGetUserData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserInternalData, FAdminGetUserDataResult, result);

    /** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserInternalData(FAdminGetUserDataRequest request,
        FDelegateOnSuccessGetUserInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserPublisherData, FAdminGetUserDataResult, result);

    /** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserPublisherData(FAdminGetUserDataRequest request,
        FDelegateOnSuccessGetUserPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserPublisherData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserPublisherInternalData, FAdminGetUserDataResult, result);

    /** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserPublisherInternalData(FAdminGetUserDataRequest request,
        FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserPublisherInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserPublisherReadOnlyData, FAdminGetUserDataResult, result);

    /** Retrieves the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserPublisherReadOnlyData(FAdminGetUserDataRequest request,
        FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserReadOnlyData, FAdminGetUserDataResult, result);

    /** Retrieves the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserReadOnlyData(FAdminGetUserDataRequest request,
        FDelegateOnSuccessGetUserReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessIncrementPlayerStatisticVersion, FAdminIncrementPlayerStatisticVersionResult, result);

    /** Resets the indicated statistic, removing all player entries for it and backing up the old values. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* IncrementPlayerStatisticVersion(FAdminIncrementPlayerStatisticVersionRequest request,
        FDelegateOnSuccessIncrementPlayerStatisticVersion onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperIncrementPlayerStatisticVersion(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessResetUserStatistics, FAdminResetUserStatisticsResult, result);

    /** Completely removes all statistics for the specified user, for the current game */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* ResetUserStatistics(FAdminResetUserStatisticsRequest request,
        FDelegateOnSuccessResetUserStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperResetUserStatistics(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdatePlayerStatisticDefinition, FAdminUpdatePlayerStatisticDefinitionResult, result);

    /** Updates a player statistic configuration for the title, optionally allowing the developer to specify a reset interval. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdatePlayerStatisticDefinition(FAdminUpdatePlayerStatisticDefinitionRequest request,
        FDelegateOnSuccessUpdatePlayerStatisticDefinition onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdatePlayerStatisticDefinition(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserData, FAdminUpdateUserDataResult, result);

    /** Updates the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateUserData(FAdminUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserInternalData, FAdminUpdateUserDataResult, result);

    /** Updates the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateUserInternalData(FAdminUpdateUserInternalDataRequest request,
        FDelegateOnSuccessUpdateUserInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserPublisherData, FAdminUpdateUserDataResult, result);

    /** Updates the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateUserPublisherData(FAdminUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserPublisherData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserPublisherInternalData, FAdminUpdateUserDataResult, result);

    /** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateUserPublisherInternalData(FAdminUpdateUserInternalDataRequest request,
        FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserPublisherReadOnlyData, FAdminUpdateUserDataResult, result);

    /** Updates the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateUserPublisherReadOnlyData(FAdminUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserReadOnlyData, FAdminUpdateUserDataResult, result);

    /** Updates the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateUserReadOnlyData(FAdminUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAddNews, FAdminAddNewsResult, result);

    /** Adds a new news item to the title's news feed */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* AddNews(FAdminAddNewsRequest request,
        FDelegateOnSuccessAddNews onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAddNews(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAddVirtualCurrencyTypes, FAdminBlankResult, result);

    /** Adds one or more virtual currencies to the set defined for the title. Virtual Currencies have a maximum value of 2,147,483,647 when granted to a player. Any value over that will be discarded. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* AddVirtualCurrencyTypes(FAdminAddVirtualCurrencyTypesRequest request,
        FDelegateOnSuccessAddVirtualCurrencyTypes onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAddVirtualCurrencyTypes(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCatalogItems, FAdminGetCatalogItemsResult, result);

    /** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetCatalogItems(FAdminGetCatalogItemsRequest request,
        FDelegateOnSuccessGetCatalogItems onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCatalogItems(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPublisherData, FAdminGetPublisherDataResult, result);

    /** Retrieves the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetPublisherData(FAdminGetPublisherDataRequest request,
        FDelegateOnSuccessGetPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPublisherData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetRandomResultTables, FAdminGetRandomResultTablesResult, result);

    /** Retrieves the random drop table configuration for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetRandomResultTables(FAdminGetRandomResultTablesRequest request,
        FDelegateOnSuccessGetRandomResultTables onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetRandomResultTables(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetStoreItems, FAdminGetStoreItemsResult, result);

    /** Retrieves the set of items defined for the specified store, including all prices defined */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetStoreItems(FAdminGetStoreItemsRequest request,
        FDelegateOnSuccessGetStoreItems onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetStoreItems(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetTitleData, FAdminGetTitleDataResult, result);

    /** Retrieves the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetTitleData(FAdminGetTitleDataRequest request,
        FDelegateOnSuccessGetTitleData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetTitleData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessListVirtualCurrencyTypes, FAdminListVirtualCurrencyTypesResult, result);

    /** Retuns the list of all defined virtual currencies for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* ListVirtualCurrencyTypes(FAdminListVirtualCurrencyTypesRequest request,
        FDelegateOnSuccessListVirtualCurrencyTypes onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperListVirtualCurrencyTypes(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetCatalogItems, FAdminUpdateCatalogItemsResult, result);

    /** Creates the catalog configuration of all virtual goods for the specified catalog version */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SetCatalogItems(FAdminUpdateCatalogItemsRequest request,
        FDelegateOnSuccessSetCatalogItems onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetCatalogItems(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetStoreItems, FAdminUpdateStoreItemsResult, result);

    /** Sets all the items in one virtual store */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SetStoreItems(FAdminUpdateStoreItemsRequest request,
        FDelegateOnSuccessSetStoreItems onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetStoreItems(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetTitleData, FAdminSetTitleDataResult, result);

    /** Creates and updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SetTitleData(FAdminSetTitleDataRequest request,
        FDelegateOnSuccessSetTitleData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetTitleData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetupPushNotification, FAdminSetupPushNotificationResult, result);

    /** Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the exact restrictions can be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html. Currently, Amazon device Messaging is not supported. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SetupPushNotification(FAdminSetupPushNotificationRequest request,
        FDelegateOnSuccessSetupPushNotification onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetupPushNotification(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateCatalogItems, FAdminUpdateCatalogItemsResult, result);

    /** Updates the catalog configuration for virtual goods in the specified catalog version */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateCatalogItems(FAdminUpdateCatalogItemsRequest request,
        FDelegateOnSuccessUpdateCatalogItems onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateCatalogItems(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateRandomResultTables, FAdminUpdateRandomResultTablesResult, result);

    /** Updates the random drop table configuration for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateRandomResultTables(FAdminUpdateRandomResultTablesRequest request,
        FDelegateOnSuccessUpdateRandomResultTables onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateRandomResultTables(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateStoreItems, FAdminUpdateStoreItemsResult, result);

    /** Updates an existing virtual item store with new or modified items */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateStoreItems(FAdminUpdateStoreItemsRequest request,
        FDelegateOnSuccessUpdateStoreItems onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateStoreItems(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAddUserVirtualCurrency, FAdminModifyUserVirtualCurrencyResult, result);

    /** Increments the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* AddUserVirtualCurrency(FAdminAddUserVirtualCurrencyRequest request,
        FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAddUserVirtualCurrency(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserInventory, FAdminGetUserInventoryResult, result);

    /** Retrieves the specified user's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetUserInventory(FAdminGetUserInventoryRequest request,
        FDelegateOnSuccessGetUserInventory onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserInventory(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGrantItemsToUsers, FAdminGrantItemsToUsersResult, result);

    /** Adds the specified items to the specified user inventories */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GrantItemsToUsers(FAdminGrantItemsToUsersRequest request,
        FDelegateOnSuccessGrantItemsToUsers onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGrantItemsToUsers(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessRevokeInventoryItem, FAdminRevokeInventoryResult, result);

    /** Revokes access to an item in a user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* RevokeInventoryItem(FAdminRevokeInventoryItemRequest request,
        FDelegateOnSuccessRevokeInventoryItem onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperRevokeInventoryItem(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSubtractUserVirtualCurrency, FAdminModifyUserVirtualCurrencyResult, result);

    /** Decrements the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SubtractUserVirtualCurrency(FAdminSubtractUserVirtualCurrencyRequest request,
        FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Matchmaking APIs
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetMatchmakerGameInfo, FAdminGetMatchmakerGameInfoResult, result);

    /** Retrieves the details for a specific completed session, including links to standard out and standard error logs */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetMatchmakerGameInfo(FAdminGetMatchmakerGameInfoRequest request,
        FDelegateOnSuccessGetMatchmakerGameInfo onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetMatchmakerGameInfo(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetMatchmakerGameModes, FAdminGetMatchmakerGameModesResult, result);

    /** Retrieves the details of defined game modes for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetMatchmakerGameModes(FAdminGetMatchmakerGameModesRequest request,
        FDelegateOnSuccessGetMatchmakerGameModes onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetMatchmakerGameModes(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessModifyMatchmakerGameModes, FAdminModifyMatchmakerGameModesResult, result);

    /** Updates the game server mode details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* ModifyMatchmakerGameModes(FAdminModifyMatchmakerGameModesRequest request,
        FDelegateOnSuccessModifyMatchmakerGameModes onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperModifyMatchmakerGameModes(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Custom Server Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAddServerBuild, FAdminAddServerBuildResult, result);

    /** Adds the game server executable specified (previously uploaded - see GetServerBuildUploadUrl) to the set of those a client is permitted to request in a call to StartGame */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* AddServerBuild(FAdminAddServerBuildRequest request,
        FDelegateOnSuccessAddServerBuild onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAddServerBuild(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetServerBuildInfo, FAdminGetServerBuildInfoResult, result);

    /** Retrieves the build details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetServerBuildInfo(FAdminGetServerBuildInfoRequest request,
        FDelegateOnSuccessGetServerBuildInfo onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetServerBuildInfo(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetServerBuildUploadUrl, FAdminGetServerBuildUploadURLResult, result);

    /** Retrieves the pre-authorized URL for uploading a game server package containing a build (does not enable the build for use - see AddServerBuild) */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetServerBuildUploadUrl(FAdminGetServerBuildUploadURLRequest request,
        FDelegateOnSuccessGetServerBuildUploadUrl onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetServerBuildUploadUrl(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessListServerBuilds, FAdminListBuildsResult, result);

    /** Retrieves the build details for all game server executables which are currently defined for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* ListServerBuilds(FAdminListBuildsRequest request,
        FDelegateOnSuccessListServerBuilds onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperListServerBuilds(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessModifyServerBuild, FAdminModifyServerBuildResult, result);

    /** Updates the build details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* ModifyServerBuild(FAdminModifyServerBuildRequest request,
        FDelegateOnSuccessModifyServerBuild onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperModifyServerBuild(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessRemoveServerBuild, FAdminRemoveServerBuildResult, result);

    /** Removes the game server executable specified from the set of those a client is permitted to request in a call to StartGame */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* RemoveServerBuild(FAdminRemoveServerBuildRequest request,
        FDelegateOnSuccessRemoveServerBuild onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperRemoveServerBuild(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetPublisherData, FAdminSetPublisherDataResult, result);

    /** Updates the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SetPublisherData(FAdminSetPublisherDataRequest request,
        FDelegateOnSuccessSetPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetPublisherData(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCloudScriptRevision, FAdminGetCloudScriptRevisionResult, result);

    /** Gets the contents and information of a specific Cloud Script revision. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetCloudScriptRevision(FAdminGetCloudScriptRevisionRequest request,
        FDelegateOnSuccessGetCloudScriptRevision onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCloudScriptRevision(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCloudScriptVersions, FAdminGetCloudScriptVersionsResult, result);

    /** Lists all the current cloud script versions. For each version, information about the current published and latest revisions is also listed. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetCloudScriptVersions(FAdminGetCloudScriptVersionsRequest request,
        FDelegateOnSuccessGetCloudScriptVersions onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCloudScriptVersions(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetPublishedRevision, FAdminSetPublishedRevisionResult, result);

    /** Sets the currently published revision of a title Cloud Script */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* SetPublishedRevision(FAdminSetPublishedRevisionRequest request,
        FDelegateOnSuccessSetPublishedRevision onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetPublishedRevision(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateCloudScript, FAdminUpdateCloudScriptResult, result);

    /** Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one file should be submitted in the revision. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* UpdateCloudScript(FAdminUpdateCloudScriptRequest request,
        FDelegateOnSuccessUpdateCloudScript onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateCloudScript(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessDeleteContent, FAdminBlankResult, result);

    /** Delete a content file from the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* DeleteContent(FAdminDeleteContentRequest request,
        FDelegateOnSuccessDeleteContent onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperDeleteContent(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetContentList, FAdminGetContentListResult, result);

    /** List all contents of the title and get statistics such as size */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetContentList(FAdminGetContentListRequest request,
        FDelegateOnSuccessGetContentList onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetContentList(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetContentUploadUrl, FAdminGetContentUploadUrlResult, result);

    /** Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned URL uploads the content. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* GetContentUploadUrl(FAdminGetContentUploadUrlRequest request,
        FDelegateOnSuccessGetContentUploadUrl onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetContentUploadUrl(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessResetCharacterStatistics, FAdminResetCharacterStatisticsResult, result);

    /** Completely removes all statistics for the specified character, for the current game */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabAdminAPI* ResetCharacterStatistics(FAdminResetCharacterStatisticsRequest request,
        FDelegateOnSuccessResetCharacterStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperResetCharacterStatistics(FPlayFabBaseModel response, bool successful);



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
    
    FDelegateOnFailurePlayFabError OnFailure;
    FDelegateOnSuccessGetUserAccountInfo OnSuccessGetUserAccountInfo;
    FDelegateOnSuccessResetUsers OnSuccessResetUsers;
    FDelegateOnSuccessSendAccountRecoveryEmail OnSuccessSendAccountRecoveryEmail;
    FDelegateOnSuccessUpdateUserTitleDisplayName OnSuccessUpdateUserTitleDisplayName;
    FDelegateOnSuccessCreatePlayerStatisticDefinition OnSuccessCreatePlayerStatisticDefinition;
    FDelegateOnSuccessDeleteUsers OnSuccessDeleteUsers;
    FDelegateOnSuccessGetDataReport OnSuccessGetDataReport;
    FDelegateOnSuccessGetPlayerStatisticDefinitions OnSuccessGetPlayerStatisticDefinitions;
    FDelegateOnSuccessGetPlayerStatisticVersions OnSuccessGetPlayerStatisticVersions;
    FDelegateOnSuccessGetUserData OnSuccessGetUserData;
    FDelegateOnSuccessGetUserInternalData OnSuccessGetUserInternalData;
    FDelegateOnSuccessGetUserPublisherData OnSuccessGetUserPublisherData;
    FDelegateOnSuccessGetUserPublisherInternalData OnSuccessGetUserPublisherInternalData;
    FDelegateOnSuccessGetUserPublisherReadOnlyData OnSuccessGetUserPublisherReadOnlyData;
    FDelegateOnSuccessGetUserReadOnlyData OnSuccessGetUserReadOnlyData;
    FDelegateOnSuccessIncrementPlayerStatisticVersion OnSuccessIncrementPlayerStatisticVersion;
    FDelegateOnSuccessResetUserStatistics OnSuccessResetUserStatistics;
    FDelegateOnSuccessUpdatePlayerStatisticDefinition OnSuccessUpdatePlayerStatisticDefinition;
    FDelegateOnSuccessUpdateUserData OnSuccessUpdateUserData;
    FDelegateOnSuccessUpdateUserInternalData OnSuccessUpdateUserInternalData;
    FDelegateOnSuccessUpdateUserPublisherData OnSuccessUpdateUserPublisherData;
    FDelegateOnSuccessUpdateUserPublisherInternalData OnSuccessUpdateUserPublisherInternalData;
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData OnSuccessUpdateUserPublisherReadOnlyData;
    FDelegateOnSuccessUpdateUserReadOnlyData OnSuccessUpdateUserReadOnlyData;
    FDelegateOnSuccessAddNews OnSuccessAddNews;
    FDelegateOnSuccessAddVirtualCurrencyTypes OnSuccessAddVirtualCurrencyTypes;
    FDelegateOnSuccessGetCatalogItems OnSuccessGetCatalogItems;
    FDelegateOnSuccessGetPublisherData OnSuccessGetPublisherData;
    FDelegateOnSuccessGetRandomResultTables OnSuccessGetRandomResultTables;
    FDelegateOnSuccessGetStoreItems OnSuccessGetStoreItems;
    FDelegateOnSuccessGetTitleData OnSuccessGetTitleData;
    FDelegateOnSuccessListVirtualCurrencyTypes OnSuccessListVirtualCurrencyTypes;
    FDelegateOnSuccessSetCatalogItems OnSuccessSetCatalogItems;
    FDelegateOnSuccessSetStoreItems OnSuccessSetStoreItems;
    FDelegateOnSuccessSetTitleData OnSuccessSetTitleData;
    FDelegateOnSuccessSetupPushNotification OnSuccessSetupPushNotification;
    FDelegateOnSuccessUpdateCatalogItems OnSuccessUpdateCatalogItems;
    FDelegateOnSuccessUpdateRandomResultTables OnSuccessUpdateRandomResultTables;
    FDelegateOnSuccessUpdateStoreItems OnSuccessUpdateStoreItems;
    FDelegateOnSuccessAddUserVirtualCurrency OnSuccessAddUserVirtualCurrency;
    FDelegateOnSuccessGetUserInventory OnSuccessGetUserInventory;
    FDelegateOnSuccessGrantItemsToUsers OnSuccessGrantItemsToUsers;
    FDelegateOnSuccessRevokeInventoryItem OnSuccessRevokeInventoryItem;
    FDelegateOnSuccessSubtractUserVirtualCurrency OnSuccessSubtractUserVirtualCurrency;
    FDelegateOnSuccessGetMatchmakerGameInfo OnSuccessGetMatchmakerGameInfo;
    FDelegateOnSuccessGetMatchmakerGameModes OnSuccessGetMatchmakerGameModes;
    FDelegateOnSuccessModifyMatchmakerGameModes OnSuccessModifyMatchmakerGameModes;
    FDelegateOnSuccessAddServerBuild OnSuccessAddServerBuild;
    FDelegateOnSuccessGetServerBuildInfo OnSuccessGetServerBuildInfo;
    FDelegateOnSuccessGetServerBuildUploadUrl OnSuccessGetServerBuildUploadUrl;
    FDelegateOnSuccessListServerBuilds OnSuccessListServerBuilds;
    FDelegateOnSuccessModifyServerBuild OnSuccessModifyServerBuild;
    FDelegateOnSuccessRemoveServerBuild OnSuccessRemoveServerBuild;
    FDelegateOnSuccessSetPublisherData OnSuccessSetPublisherData;
    FDelegateOnSuccessGetCloudScriptRevision OnSuccessGetCloudScriptRevision;
    FDelegateOnSuccessGetCloudScriptVersions OnSuccessGetCloudScriptVersions;
    FDelegateOnSuccessSetPublishedRevision OnSuccessSetPublishedRevision;
    FDelegateOnSuccessUpdateCloudScript OnSuccessUpdateCloudScript;
    FDelegateOnSuccessDeleteContent OnSuccessDeleteContent;
    FDelegateOnSuccessGetContentList OnSuccessGetContentList;
    FDelegateOnSuccessGetContentUploadUrl OnSuccessGetContentUploadUrl;
    FDelegateOnSuccessResetCharacterStatistics OnSuccessResetCharacterStatistics;

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
