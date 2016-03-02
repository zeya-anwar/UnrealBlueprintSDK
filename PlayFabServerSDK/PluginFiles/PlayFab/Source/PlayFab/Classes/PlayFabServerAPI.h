#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Server
// SDK Version: 0.0.160222
//////////////////////////////////////////////////////////////////////////////////////////////

#include "OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabServerModels.h"
#include "PlayFabPrivatePCH.h"
#include "PlayFabServerAPI.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayFabServerRequestCompleted, FPlayFabBaseModel, response, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class UPlayFabServerAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:

    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnFailurePlayFabError, FPlayFabError, error);

    UPROPERTY(BlueprintAssignable)
    FOnPlayFabServerRequestCompleted OnPlayFabResponse;
    
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
    // Generated PlayFab Server API Functions
    //////////////////////////////////////////////////////////////////////////

    

    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAuthenticateSessionTicket, FServerAuthenticateSessionTicketResult, result);

    /** Validated a client's session ticket, and if successful, returns details for that user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* AuthenticateSessionTicket(FServerAuthenticateSessionTicketRequest request,
        FDelegateOnSuccessAuthenticateSessionTicket onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAuthenticateSessionTicket(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs, FServerGetPlayFabIDsFromFacebookIDsResult, result);

    /** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetPlayFabIDsFromFacebookIDs(FServerGetPlayFabIDsFromFacebookIDsRequest request,
        FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPlayFabIDsFromFacebookIDs(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPlayFabIDsFromSteamIDs, FServerGetPlayFabIDsFromSteamIDsResult, result);

    /** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetPlayFabIDsFromSteamIDs(FServerGetPlayFabIDsFromSteamIDsRequest request,
        FDelegateOnSuccessGetPlayFabIDsFromSteamIDs onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPlayFabIDsFromSteamIDs(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserAccountInfo, FServerGetUserAccountInfoResult, result);

    /** Retrieves the relevant details for a specified user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserAccountInfo(FServerGetUserAccountInfoRequest request,
        FDelegateOnSuccessGetUserAccountInfo onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserAccountInfo(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSendPushNotification, FServerSendPushNotificationResult, result);

    /** Sends an iOS/Android Push Notification to a specific user, if that user's device has been configured for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* SendPushNotification(FServerSendPushNotificationRequest request,
        FDelegateOnSuccessSendPushNotification onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSendPushNotification(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessDeleteUsers, FServerDeleteUsersResult, result);

    /** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* DeleteUsers(FServerDeleteUsersRequest request,
        FDelegateOnSuccessDeleteUsers onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperDeleteUsers(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetLeaderboard, FServerGetLeaderboardResult, result);

    /** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetLeaderboard(FServerGetLeaderboardRequest request,
        FDelegateOnSuccessGetLeaderboard onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetLeaderboard(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetLeaderboardAroundUser, FServerGetLeaderboardAroundUserResult, result);

    /** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetLeaderboardAroundUser(FServerGetLeaderboardAroundUserRequest request,
        FDelegateOnSuccessGetLeaderboardAroundUser onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetLeaderboardAroundUser(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPlayerStatistics, FServerGetPlayerStatisticsResult, result);

    /** Retrieves the current version and values for the indicated statistics, for the local player. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetPlayerStatistics(FServerGetPlayerStatisticsRequest request,
        FDelegateOnSuccessGetPlayerStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPlayerStatistics(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPlayerStatisticVersions, FServerGetPlayerStatisticVersionsResult, result);

    /** Retrieves the information on the available versions of the specified statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetPlayerStatisticVersions(FServerGetPlayerStatisticVersionsRequest request,
        FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserData, FServerGetUserDataResult, result);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserData(FServerGetUserDataRequest request,
        FDelegateOnSuccessGetUserData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserInternalData, FServerGetUserDataResult, result);

    /** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserInternalData(FServerGetUserDataRequest request,
        FDelegateOnSuccessGetUserInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserPublisherData, FServerGetUserDataResult, result);

    /** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserPublisherData(FServerGetUserDataRequest request,
        FDelegateOnSuccessGetUserPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserPublisherData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserPublisherInternalData, FServerGetUserDataResult, result);

    /** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserPublisherInternalData(FServerGetUserDataRequest request,
        FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserPublisherInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserPublisherReadOnlyData, FServerGetUserDataResult, result);

    /** Retrieves the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserPublisherReadOnlyData(FServerGetUserDataRequest request,
        FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserReadOnlyData, FServerGetUserDataResult, result);

    /** Retrieves the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserReadOnlyData(FServerGetUserDataRequest request,
        FDelegateOnSuccessGetUserReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserStatistics, FServerGetUserStatisticsResult, result);

    /** Retrieves the details of all title-specific statistics for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserStatistics(FServerGetUserStatisticsRequest request,
        FDelegateOnSuccessGetUserStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserStatistics(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdatePlayerStatistics, FServerUpdatePlayerStatisticsResult, result);

    /** Updates the values of the specified title-specific statistics for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdatePlayerStatistics(FServerUpdatePlayerStatisticsRequest request,
        FDelegateOnSuccessUpdatePlayerStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdatePlayerStatistics(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserData, FServerUpdateUserDataResult, result);

    /** Updates the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserData(FServerUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserInternalData, FServerUpdateUserDataResult, result);

    /** Updates the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserInternalData(FServerUpdateUserInternalDataRequest request,
        FDelegateOnSuccessUpdateUserInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserPublisherData, FServerUpdateUserDataResult, result);

    /** Updates the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserPublisherData(FServerUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserPublisherData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserPublisherInternalData, FServerUpdateUserDataResult, result);

    /** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserPublisherInternalData(FServerUpdateUserInternalDataRequest request,
        FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserPublisherReadOnlyData, FServerUpdateUserDataResult, result);

    /** Updates the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserPublisherReadOnlyData(FServerUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserReadOnlyData, FServerUpdateUserDataResult, result);

    /** Updates the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserReadOnlyData(FServerUpdateUserDataRequest request,
        FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserStatistics, FServerUpdateUserStatisticsResult, result);

    /** Updates the values of the specified title-specific statistics for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserStatistics(FServerUpdateUserStatisticsRequest request,
        FDelegateOnSuccessUpdateUserStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserStatistics(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCatalogItems, FServerGetCatalogItemsResult, result);

    /** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetCatalogItems(FServerGetCatalogItemsRequest request,
        FDelegateOnSuccessGetCatalogItems onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCatalogItems(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetTitleData, FServerGetTitleDataResult, result);

    /** Retrieves the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetTitleData(FServerGetTitleDataRequest request,
        FDelegateOnSuccessGetTitleData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetTitleData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetTitleInternalData, FServerGetTitleDataResult, result);

    /** Retrieves the key-value store of custom internal title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetTitleInternalData(FServerGetTitleDataRequest request,
        FDelegateOnSuccessGetTitleInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetTitleInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetTitleNews, FServerGetTitleNewsResult, result);

    /** Retrieves the title news feed, as configured in the developer portal */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetTitleNews(FServerGetTitleNewsRequest request,
        FDelegateOnSuccessGetTitleNews onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetTitleNews(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetTitleData, FServerSetTitleDataResult, result);

    /** Updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* SetTitleData(FServerSetTitleDataRequest request,
        FDelegateOnSuccessSetTitleData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetTitleData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetTitleInternalData, FServerSetTitleDataResult, result);

    /** Updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* SetTitleInternalData(FServerSetTitleDataRequest request,
        FDelegateOnSuccessSetTitleInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetTitleInternalData(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAddCharacterVirtualCurrency, FServerModifyCharacterVirtualCurrencyResult, result);

    /** Increments  the character's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* AddCharacterVirtualCurrency(FServerAddCharacterVirtualCurrencyRequest request,
        FDelegateOnSuccessAddCharacterVirtualCurrency onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAddCharacterVirtualCurrency(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAddUserVirtualCurrency, FServerModifyUserVirtualCurrencyResult, result);

    /** Increments  the user's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* AddUserVirtualCurrency(FServerAddUserVirtualCurrencyRequest request,
        FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAddUserVirtualCurrency(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessConsumeItem, FServerConsumeItemResult, result);

    /** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* ConsumeItem(FServerConsumeItemRequest request,
        FDelegateOnSuccessConsumeItem onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperConsumeItem(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCharacterInventory, FServerGetCharacterInventoryResult, result);

    /** Retrieves the specified character's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetCharacterInventory(FServerGetCharacterInventoryRequest request,
        FDelegateOnSuccessGetCharacterInventory onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCharacterInventory(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetUserInventory, FServerGetUserInventoryResult, result);

    /** Retrieves the specified user's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetUserInventory(FServerGetUserInventoryRequest request,
        FDelegateOnSuccessGetUserInventory onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetUserInventory(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGrantItemsToCharacter, FServerGrantItemsToCharacterResult, result);

    /** Adds the specified items to the specified character's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GrantItemsToCharacter(FServerGrantItemsToCharacterRequest request,
        FDelegateOnSuccessGrantItemsToCharacter onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGrantItemsToCharacter(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGrantItemsToUser, FServerGrantItemsToUserResult, result);

    /** Adds the specified items to the specified user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GrantItemsToUser(FServerGrantItemsToUserRequest request,
        FDelegateOnSuccessGrantItemsToUser onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGrantItemsToUser(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGrantItemsToUsers, FServerGrantItemsToUsersResult, result);

    /** Adds the specified items to the specified user inventories */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GrantItemsToUsers(FServerGrantItemsToUsersRequest request,
        FDelegateOnSuccessGrantItemsToUsers onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGrantItemsToUsers(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessModifyItemUses, FServerModifyItemUsesResult, result);

    /** Modifies the number of remaining uses of a player's inventory item */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* ModifyItemUses(FServerModifyItemUsesRequest request,
        FDelegateOnSuccessModifyItemUses onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperModifyItemUses(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessMoveItemToCharacterFromCharacter, FServerMoveItemToCharacterFromCharacterResult, result);

    /** Moves an item from a character's inventory into another of the users's character's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* MoveItemToCharacterFromCharacter(FServerMoveItemToCharacterFromCharacterRequest request,
        FDelegateOnSuccessMoveItemToCharacterFromCharacter onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperMoveItemToCharacterFromCharacter(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessMoveItemToCharacterFromUser, FServerMoveItemToCharacterFromUserResult, result);

    /** Moves an item from a user's inventory into their character's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* MoveItemToCharacterFromUser(FServerMoveItemToCharacterFromUserRequest request,
        FDelegateOnSuccessMoveItemToCharacterFromUser onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperMoveItemToCharacterFromUser(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessMoveItemToUserFromCharacter, FServerMoveItemToUserFromCharacterResult, result);

    /** Moves an item from a character's inventory into the owning user's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* MoveItemToUserFromCharacter(FServerMoveItemToUserFromCharacterRequest request,
        FDelegateOnSuccessMoveItemToUserFromCharacter onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperMoveItemToUserFromCharacter(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessRedeemCoupon, FServerRedeemCouponResult, result);

    /** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/2015/06/18/using-stores-and-coupons-game-manager */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* RedeemCoupon(FServerRedeemCouponRequest request,
        FDelegateOnSuccessRedeemCoupon onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperRedeemCoupon(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessReportPlayer, FServerReportPlayerServerResult, result);

    /** Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service representatives for the title can take action concerning potentially toxic players. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* ReportPlayer(FServerReportPlayerServerRequest request,
        FDelegateOnSuccessReportPlayer onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperReportPlayer(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessRevokeInventoryItem, FServerRevokeInventoryResult, result);

    /** Revokes access to an item in a user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* RevokeInventoryItem(FServerRevokeInventoryItemRequest request,
        FDelegateOnSuccessRevokeInventoryItem onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperRevokeInventoryItem(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSubtractCharacterVirtualCurrency, FServerModifyCharacterVirtualCurrencyResult, result);

    /** Decrements the character's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* SubtractCharacterVirtualCurrency(FServerSubtractCharacterVirtualCurrencyRequest request,
        FDelegateOnSuccessSubtractCharacterVirtualCurrency onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSubtractCharacterVirtualCurrency(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSubtractUserVirtualCurrency, FServerModifyUserVirtualCurrencyResult, result);

    /** Decrements the user's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* SubtractUserVirtualCurrency(FServerSubtractUserVirtualCurrencyRequest request,
        FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUnlockContainerInstance, FServerUnlockContainerItemResult, result);

    /** Opens a specific container (ContainerItemInstanceId), with a specific key (KeyItemInstanceId, when required), and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UnlockContainerInstance(FServerUnlockContainerInstanceRequest request,
        FDelegateOnSuccessUnlockContainerInstance onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUnlockContainerInstance(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUnlockContainerItem, FServerUnlockContainerItemResult, result);

    /** Searches Player or Character inventory for any ItemInstance matching the given CatalogItemId, if necessary unlocks it using any appropriate key, and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UnlockContainerItem(FServerUnlockContainerItemRequest request,
        FDelegateOnSuccessUnlockContainerItem onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUnlockContainerItem(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateUserInventoryItemCustomData, FServerUpdateUserInventoryItemDataResult, result);

    /** Updates the key-value pair data tagged to the specified item, which is read-only from the client. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateUserInventoryItemCustomData(FServerUpdateUserInventoryItemDataRequest request,
        FDelegateOnSuccessUpdateUserInventoryItemCustomData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateUserInventoryItemCustomData(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Friend List Management
    //////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Matchmaking APIs
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessNotifyMatchmakerPlayerLeft, FServerNotifyMatchmakerPlayerLeftResult, result);

    /** Informs the PlayFab match-making service that the user specified has left the Game Server Instance */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* NotifyMatchmakerPlayerLeft(FServerNotifyMatchmakerPlayerLeftRequest request,
        FDelegateOnSuccessNotifyMatchmakerPlayerLeft onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperNotifyMatchmakerPlayerLeft(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessRedeemMatchmakerTicket, FServerRedeemMatchmakerTicketResult, result);

    /** Validates a Game Server session ticket and returns details about the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* RedeemMatchmakerTicket(FServerRedeemMatchmakerTicketRequest request,
        FDelegateOnSuccessRedeemMatchmakerTicket onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperRedeemMatchmakerTicket(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Steam-Specific APIs
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAwardSteamAchievement, FServerAwardSteamAchievementResult, result);

    /** Awards the specified users the specified Steam achievements */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Steam-Specific APIs ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* AwardSteamAchievement(FServerAwardSteamAchievementRequest request,
        FDelegateOnSuccessAwardSteamAchievement onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Steam-Specific APIs ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAwardSteamAchievement(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessLogEvent, FServerLogEventResult, result);

    /** Logs a custom analytics event */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* LogEvent(FServerLogEventRequest request,
        FDelegateOnSuccessLogEvent onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperLogEvent(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessAddSharedGroupMembers, FServerAddSharedGroupMembersResult, result);

    /** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group (and the server) can add new members. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* AddSharedGroupMembers(FServerAddSharedGroupMembersRequest request,
        FDelegateOnSuccessAddSharedGroupMembers onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperAddSharedGroupMembers(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessCreateSharedGroup, FServerCreateSharedGroupResult, result);

    /** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. When created by a server, the group will initially have no members. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* CreateSharedGroup(FServerCreateSharedGroupRequest request,
        FDelegateOnSuccessCreateSharedGroup onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperCreateSharedGroup(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessDeleteSharedGroup, FServerEmptyResult, result);

    /** Deletes a shared group, freeing up the shared group ID to be reused for a new group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* DeleteSharedGroup(FServerDeleteSharedGroupRequest request,
        FDelegateOnSuccessDeleteSharedGroup onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperDeleteSharedGroup(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetPublisherData, FServerGetPublisherDataResult, result);

    /** Retrieves the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetPublisherData(FServerGetPublisherDataRequest request,
        FDelegateOnSuccessGetPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetPublisherData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetSharedGroupData, FServerGetSharedGroupDataResult, result);

    /** Retrieves data stored in a shared group object, as well as the list of members in the group. The server can access all public and private group data. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetSharedGroupData(FServerGetSharedGroupDataRequest request,
        FDelegateOnSuccessGetSharedGroupData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetSharedGroupData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessRemoveSharedGroupMembers, FServerRemoveSharedGroupMembersResult, result);

    /** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* RemoveSharedGroupMembers(FServerRemoveSharedGroupMembersRequest request,
        FDelegateOnSuccessRemoveSharedGroupMembers onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperRemoveSharedGroupMembers(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessSetPublisherData, FServerSetPublisherDataResult, result);

    /** Updates the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* SetPublisherData(FServerSetPublisherDataRequest request,
        FDelegateOnSuccessSetPublisherData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperSetPublisherData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateSharedGroupData, FServerUpdateSharedGroupDataResult, result);

    /** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group (and the server) can update the data. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateSharedGroupData(FServerUpdateSharedGroupDataRequest request,
        FDelegateOnSuccessUpdateSharedGroupData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateSharedGroupData(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetContentDownloadUrl, FServerGetContentDownloadUrlResult, result);

    /** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://community.playfab.com/hc/en-us/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Content ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetContentDownloadUrl(FServerGetContentDownloadUrlRequest request,
        FDelegateOnSuccessGetContentDownloadUrl onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Content ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetContentDownloadUrl(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessDeleteCharacterFromUser, FServerDeleteCharacterFromUserResult, result);

    /** Deletes the specific character ID from the specified user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* DeleteCharacterFromUser(FServerDeleteCharacterFromUserRequest request,
        FDelegateOnSuccessDeleteCharacterFromUser onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperDeleteCharacterFromUser(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetAllUsersCharacters, FServerListUsersCharactersResult, result);

    /** Lists all of the characters that belong to a specific user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetAllUsersCharacters(FServerListUsersCharactersRequest request,
        FDelegateOnSuccessGetAllUsersCharacters onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetAllUsersCharacters(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCharacterLeaderboard, FServerGetCharacterLeaderboardResult, result);

    /** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetCharacterLeaderboard(FServerGetCharacterLeaderboardRequest request,
        FDelegateOnSuccessGetCharacterLeaderboard onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCharacterLeaderboard(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCharacterStatistics, FServerGetCharacterStatisticsResult, result);

    /** Retrieves the details of all title-specific statistics for the specific character */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetCharacterStatistics(FServerGetCharacterStatisticsRequest request,
        FDelegateOnSuccessGetCharacterStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCharacterStatistics(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetLeaderboardAroundCharacter, FServerGetLeaderboardAroundCharacterResult, result);

    /** Retrieves a list of ranked characters for the given statistic, centered on the requested user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetLeaderboardAroundCharacter(FServerGetLeaderboardAroundCharacterRequest request,
        FDelegateOnSuccessGetLeaderboardAroundCharacter onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetLeaderboardAroundCharacter(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetLeaderboardForUserCharacters, FServerGetLeaderboardForUsersCharactersResult, result);

    /** Retrieves a list of all of the user's characters for the given statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetLeaderboardForUserCharacters(FServerGetLeaderboardForUsersCharactersRequest request,
        FDelegateOnSuccessGetLeaderboardForUserCharacters onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetLeaderboardForUserCharacters(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGrantCharacterToUser, FServerGrantCharacterToUserResult, result);

    /** Grants the specified character type to the user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GrantCharacterToUser(FServerGrantCharacterToUserRequest request,
        FDelegateOnSuccessGrantCharacterToUser onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGrantCharacterToUser(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateCharacterStatistics, FServerUpdateCharacterStatisticsResult, result);

    /** Updates the values of the specified title-specific statistics for the specific character */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateCharacterStatistics(FServerUpdateCharacterStatisticsRequest request,
        FDelegateOnSuccessUpdateCharacterStatistics onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateCharacterStatistics(FPlayFabBaseModel response, bool successful);



    ///////////////////////////////////////////////////////
    // Character Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCharacterData, FServerGetCharacterDataResult, result);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetCharacterData(FServerGetCharacterDataRequest request,
        FDelegateOnSuccessGetCharacterData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCharacterData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCharacterInternalData, FServerGetCharacterDataResult, result);

    /** Retrieves the title-specific custom data for the user's character which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetCharacterInternalData(FServerGetCharacterDataRequest request,
        FDelegateOnSuccessGetCharacterInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCharacterInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessGetCharacterReadOnlyData, FServerGetCharacterDataResult, result);

    /** Retrieves the title-specific custom data for the user's character which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* GetCharacterReadOnlyData(FServerGetCharacterDataRequest request,
        FDelegateOnSuccessGetCharacterReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperGetCharacterReadOnlyData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateCharacterData, FServerUpdateCharacterDataResult, result);

    /** Updates the title-specific custom data for the user's chjaracter which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateCharacterData(FServerUpdateCharacterDataRequest request,
        FDelegateOnSuccessUpdateCharacterData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateCharacterData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateCharacterInternalData, FServerUpdateCharacterDataResult, result);

    /** Updates the title-specific custom data for the user's character which cannot  be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateCharacterInternalData(FServerUpdateCharacterDataRequest request,
        FDelegateOnSuccessUpdateCharacterInternalData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateCharacterInternalData(FPlayFabBaseModel response, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateOnSuccessUpdateCharacterReadOnlyData, FServerUpdateCharacterDataResult, result);

    /** Updates the title-specific custom data for the user's character which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    static UPlayFabServerAPI* UpdateCharacterReadOnlyData(FServerUpdateCharacterDataRequest request,
        FDelegateOnSuccessUpdateCharacterReadOnlyData onSuccess,
        FDelegateOnFailurePlayFabError onFailure);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
    void HelperUpdateCharacterReadOnlyData(FPlayFabBaseModel response, bool successful);



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
    FDelegateOnSuccessAuthenticateSessionTicket OnSuccessAuthenticateSessionTicket;
    FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs OnSuccessGetPlayFabIDsFromFacebookIDs;
    FDelegateOnSuccessGetPlayFabIDsFromSteamIDs OnSuccessGetPlayFabIDsFromSteamIDs;
    FDelegateOnSuccessGetUserAccountInfo OnSuccessGetUserAccountInfo;
    FDelegateOnSuccessSendPushNotification OnSuccessSendPushNotification;
    FDelegateOnSuccessDeleteUsers OnSuccessDeleteUsers;
    FDelegateOnSuccessGetLeaderboard OnSuccessGetLeaderboard;
    FDelegateOnSuccessGetLeaderboardAroundUser OnSuccessGetLeaderboardAroundUser;
    FDelegateOnSuccessGetPlayerStatistics OnSuccessGetPlayerStatistics;
    FDelegateOnSuccessGetPlayerStatisticVersions OnSuccessGetPlayerStatisticVersions;
    FDelegateOnSuccessGetUserData OnSuccessGetUserData;
    FDelegateOnSuccessGetUserInternalData OnSuccessGetUserInternalData;
    FDelegateOnSuccessGetUserPublisherData OnSuccessGetUserPublisherData;
    FDelegateOnSuccessGetUserPublisherInternalData OnSuccessGetUserPublisherInternalData;
    FDelegateOnSuccessGetUserPublisherReadOnlyData OnSuccessGetUserPublisherReadOnlyData;
    FDelegateOnSuccessGetUserReadOnlyData OnSuccessGetUserReadOnlyData;
    FDelegateOnSuccessGetUserStatistics OnSuccessGetUserStatistics;
    FDelegateOnSuccessUpdatePlayerStatistics OnSuccessUpdatePlayerStatistics;
    FDelegateOnSuccessUpdateUserData OnSuccessUpdateUserData;
    FDelegateOnSuccessUpdateUserInternalData OnSuccessUpdateUserInternalData;
    FDelegateOnSuccessUpdateUserPublisherData OnSuccessUpdateUserPublisherData;
    FDelegateOnSuccessUpdateUserPublisherInternalData OnSuccessUpdateUserPublisherInternalData;
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData OnSuccessUpdateUserPublisherReadOnlyData;
    FDelegateOnSuccessUpdateUserReadOnlyData OnSuccessUpdateUserReadOnlyData;
    FDelegateOnSuccessUpdateUserStatistics OnSuccessUpdateUserStatistics;
    FDelegateOnSuccessGetCatalogItems OnSuccessGetCatalogItems;
    FDelegateOnSuccessGetTitleData OnSuccessGetTitleData;
    FDelegateOnSuccessGetTitleInternalData OnSuccessGetTitleInternalData;
    FDelegateOnSuccessGetTitleNews OnSuccessGetTitleNews;
    FDelegateOnSuccessSetTitleData OnSuccessSetTitleData;
    FDelegateOnSuccessSetTitleInternalData OnSuccessSetTitleInternalData;
    FDelegateOnSuccessAddCharacterVirtualCurrency OnSuccessAddCharacterVirtualCurrency;
    FDelegateOnSuccessAddUserVirtualCurrency OnSuccessAddUserVirtualCurrency;
    FDelegateOnSuccessConsumeItem OnSuccessConsumeItem;
    FDelegateOnSuccessGetCharacterInventory OnSuccessGetCharacterInventory;
    FDelegateOnSuccessGetUserInventory OnSuccessGetUserInventory;
    FDelegateOnSuccessGrantItemsToCharacter OnSuccessGrantItemsToCharacter;
    FDelegateOnSuccessGrantItemsToUser OnSuccessGrantItemsToUser;
    FDelegateOnSuccessGrantItemsToUsers OnSuccessGrantItemsToUsers;
    FDelegateOnSuccessModifyItemUses OnSuccessModifyItemUses;
    FDelegateOnSuccessMoveItemToCharacterFromCharacter OnSuccessMoveItemToCharacterFromCharacter;
    FDelegateOnSuccessMoveItemToCharacterFromUser OnSuccessMoveItemToCharacterFromUser;
    FDelegateOnSuccessMoveItemToUserFromCharacter OnSuccessMoveItemToUserFromCharacter;
    FDelegateOnSuccessRedeemCoupon OnSuccessRedeemCoupon;
    FDelegateOnSuccessReportPlayer OnSuccessReportPlayer;
    FDelegateOnSuccessRevokeInventoryItem OnSuccessRevokeInventoryItem;
    FDelegateOnSuccessSubtractCharacterVirtualCurrency OnSuccessSubtractCharacterVirtualCurrency;
    FDelegateOnSuccessSubtractUserVirtualCurrency OnSuccessSubtractUserVirtualCurrency;
    FDelegateOnSuccessUnlockContainerInstance OnSuccessUnlockContainerInstance;
    FDelegateOnSuccessUnlockContainerItem OnSuccessUnlockContainerItem;
    FDelegateOnSuccessUpdateUserInventoryItemCustomData OnSuccessUpdateUserInventoryItemCustomData;
    FDelegateOnSuccessNotifyMatchmakerPlayerLeft OnSuccessNotifyMatchmakerPlayerLeft;
    FDelegateOnSuccessRedeemMatchmakerTicket OnSuccessRedeemMatchmakerTicket;
    FDelegateOnSuccessAwardSteamAchievement OnSuccessAwardSteamAchievement;
    FDelegateOnSuccessLogEvent OnSuccessLogEvent;
    FDelegateOnSuccessAddSharedGroupMembers OnSuccessAddSharedGroupMembers;
    FDelegateOnSuccessCreateSharedGroup OnSuccessCreateSharedGroup;
    FDelegateOnSuccessDeleteSharedGroup OnSuccessDeleteSharedGroup;
    FDelegateOnSuccessGetPublisherData OnSuccessGetPublisherData;
    FDelegateOnSuccessGetSharedGroupData OnSuccessGetSharedGroupData;
    FDelegateOnSuccessRemoveSharedGroupMembers OnSuccessRemoveSharedGroupMembers;
    FDelegateOnSuccessSetPublisherData OnSuccessSetPublisherData;
    FDelegateOnSuccessUpdateSharedGroupData OnSuccessUpdateSharedGroupData;
    FDelegateOnSuccessGetContentDownloadUrl OnSuccessGetContentDownloadUrl;
    FDelegateOnSuccessDeleteCharacterFromUser OnSuccessDeleteCharacterFromUser;
    FDelegateOnSuccessGetAllUsersCharacters OnSuccessGetAllUsersCharacters;
    FDelegateOnSuccessGetCharacterLeaderboard OnSuccessGetCharacterLeaderboard;
    FDelegateOnSuccessGetCharacterStatistics OnSuccessGetCharacterStatistics;
    FDelegateOnSuccessGetLeaderboardAroundCharacter OnSuccessGetLeaderboardAroundCharacter;
    FDelegateOnSuccessGetLeaderboardForUserCharacters OnSuccessGetLeaderboardForUserCharacters;
    FDelegateOnSuccessGrantCharacterToUser OnSuccessGrantCharacterToUser;
    FDelegateOnSuccessUpdateCharacterStatistics OnSuccessUpdateCharacterStatistics;
    FDelegateOnSuccessGetCharacterData OnSuccessGetCharacterData;
    FDelegateOnSuccessGetCharacterInternalData OnSuccessGetCharacterInternalData;
    FDelegateOnSuccessGetCharacterReadOnlyData OnSuccessGetCharacterReadOnlyData;
    FDelegateOnSuccessUpdateCharacterData OnSuccessUpdateCharacterData;
    FDelegateOnSuccessUpdateCharacterInternalData OnSuccessUpdateCharacterInternalData;
    FDelegateOnSuccessUpdateCharacterReadOnlyData OnSuccessUpdateCharacterReadOnlyData;

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
