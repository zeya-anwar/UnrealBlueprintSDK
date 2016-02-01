#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Server
// SDK Version: 0.0.160201
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
    /** Validated a client's session ticket, and if successful, returns details for that user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AuthenticateSessionTicket(FServerAuthenticateSessionTicketRequest request);



    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////
    /** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromFacebookIDs(FServerGetPlayFabIDsFromFacebookIDsRequest request);

    /** Retrieves the relevant details for a specified user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserAccountInfo(FServerGetUserAccountInfoRequest request);

    /** Sends an iOS/Android Push Notification to a specific user, if that user's device has been configured for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SendPushNotification(FServerSendPushNotificationRequest request);



    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////
    /** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeleteUsers(FServerDeleteUsersRequest request);

    /** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboard(FServerGetLeaderboardRequest request);

    /** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboardAroundUser(FServerGetLeaderboardAroundUserRequest request);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserData(FServerGetUserDataRequest request);

    /** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserInternalData(FServerGetUserDataRequest request);

    /** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserPublisherData(FServerGetUserDataRequest request);

    /** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserPublisherInternalData(FServerGetUserDataRequest request);

    /** Retrieves the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserPublisherReadOnlyData(FServerGetUserDataRequest request);

    /** Retrieves the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserReadOnlyData(FServerGetUserDataRequest request);

    /** Retrieves the details of all title-specific statistics for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserStatistics(FServerGetUserStatisticsRequest request);

    /** Updates the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserData(FServerUpdateUserDataRequest request);

    /** Updates the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserInternalData(FServerUpdateUserInternalDataRequest request);

    /** Updates the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserPublisherData(FServerUpdateUserDataRequest request);

    /** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserPublisherInternalData(FServerUpdateUserInternalDataRequest request);

    /** Updates the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserPublisherReadOnlyData(FServerUpdateUserDataRequest request);

    /** Updates the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserReadOnlyData(FServerUpdateUserDataRequest request);

    /** Updates the values of the specified title-specific statistics for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserStatistics(FServerUpdateUserStatisticsRequest request);



    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////
    /** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCatalogItems(FServerGetCatalogItemsRequest request);

    /** Retrieves the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetTitleData(FServerGetTitleDataRequest request);

    /** Retrieves the key-value store of custom internal title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetTitleInternalData(FServerGetTitleDataRequest request);

    /** Retrieves the title news feed, as configured in the developer portal */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetTitleNews(FServerGetTitleNewsRequest request);

    /** Updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetTitleData(FServerSetTitleDataRequest request);

    /** Updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetTitleInternalData(FServerSetTitleDataRequest request);



    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////
    /** Increments  the character's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddCharacterVirtualCurrency(FServerAddCharacterVirtualCurrencyRequest request);

    /** Increments  the user's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddUserVirtualCurrency(FServerAddUserVirtualCurrencyRequest request);

    /** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* ConsumeItem(FServerConsumeItemRequest request);

    /** Retrieves the specified character's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterInventory(FServerGetCharacterInventoryRequest request);

    /** Retrieves the specified user's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserInventory(FServerGetUserInventoryRequest request);

    /** Adds the specified items to the specified character's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantItemsToCharacter(FServerGrantItemsToCharacterRequest request);

    /** Adds the specified items to the specified user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantItemsToUser(FServerGrantItemsToUserRequest request);

    /** Adds the specified items to the specified user inventories */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantItemsToUsers(FServerGrantItemsToUsersRequest request);

    /** Modifies the number of remaining uses of a player's inventory item */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* ModifyItemUses(FServerModifyItemUsesRequest request);

    /** Moves an item from a character's inventory into another of the users's character's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* MoveItemToCharacterFromCharacter(FServerMoveItemToCharacterFromCharacterRequest request);

    /** Moves an item from a user's inventory into their character's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* MoveItemToCharacterFromUser(FServerMoveItemToCharacterFromUserRequest request);

    /** Moves an item from a character's inventory into the owning user's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* MoveItemToUserFromCharacter(FServerMoveItemToUserFromCharacterRequest request);

    /** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/2015/06/18/using-stores-and-coupons-game-manager */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RedeemCoupon(FServerRedeemCouponRequest request);

    /** Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service representatives for the title can take action concerning potentially toxic players. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* ReportPlayer(FServerReportPlayerServerRequest request);

    /** Revokes access to an item in a user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RevokeInventoryItem(FServerRevokeInventoryItemRequest request);

    /** Decrements the character's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SubtractCharacterVirtualCurrency(FServerSubtractCharacterVirtualCurrencyRequest request);

    /** Decrements the user's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SubtractUserVirtualCurrency(FServerSubtractUserVirtualCurrencyRequest request);

    /** Updates the key-value pair data tagged to the specified item, which is read-only from the client. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserInventoryItemCustomData(FServerUpdateUserInventoryItemDataRequest request);



    ///////////////////////////////////////////////////////
    // Friend List Management
    //////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Matchmaking APIs
    //////////////////////////////////////////////////////
    /** Informs the PlayFab match-making service that the user specified has left the Game Server Instance */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* NotifyMatchmakerPlayerLeft(FServerNotifyMatchmakerPlayerLeftRequest request);

    /** Validates a Game Server session ticket and returns details about the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking APIs ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RedeemMatchmakerTicket(FServerRedeemMatchmakerTicketRequest request);



    ///////////////////////////////////////////////////////
    // Steam-Specific APIs
    //////////////////////////////////////////////////////
    /** Awards the specified users the specified Steam achievements */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Steam-Specific APIs ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AwardSteamAchievement(FServerAwardSteamAchievementRequest request);



    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////
    /** Logs a custom analytics event */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LogEvent(FServerLogEventRequest request);



    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////
    /** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group (and the server) can add new members. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddSharedGroupMembers(FServerAddSharedGroupMembersRequest request);

    /** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. When created by a server, the group will initially have no members. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* CreateSharedGroup(FServerCreateSharedGroupRequest request);

    /** Deletes a shared group, freeing up the shared group ID to be reused for a new group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeleteSharedGroup(FServerDeleteSharedGroupRequest request);

    /** Retrieves the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPublisherData(FServerGetPublisherDataRequest request);

    /** Retrieves data stored in a shared group object, as well as the list of members in the group. The server can access all public and private group data. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetSharedGroupData(FServerGetSharedGroupDataRequest request);

    /** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RemoveSharedGroupMembers(FServerRemoveSharedGroupMembersRequest request);

    /** Updates the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetPublisherData(FServerSetPublisherDataRequest request);

    /** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group (and the server) can update the data. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateSharedGroupData(FServerUpdateSharedGroupDataRequest request);



    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////
    /** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://support.playfab.com/support/discussions/topics/1000059929 */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetContentDownloadUrl(FServerGetContentDownloadUrlRequest request);



    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////
    /** Deletes the specific character ID from the specified user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeleteCharacterFromUser(FServerDeleteCharacterFromUserRequest request);

    /** Lists all of the characters that belong to a specific user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetAllUsersCharacters(FServerListUsersCharactersRequest request);

    /** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterLeaderboard(FServerGetCharacterLeaderboardRequest request);

    /** Retrieves the details of all title-specific statistics for the specific character */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterStatistics(FServerGetCharacterStatisticsRequest request);

    /** Retrieves a list of ranked characters for the given statistic, centered on the requested user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboardAroundCharacter(FServerGetLeaderboardAroundCharacterRequest request);

    /** Retrieves a list of all of the user's characters for the given statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboardForUserCharacters(FServerGetLeaderboardForUsersCharactersRequest request);

    /** Grants the specified character type to the user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantCharacterToUser(FServerGrantCharacterToUserRequest request);

    /** Updates the values of the specified title-specific statistics for the specific character */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterStatistics(FServerUpdateCharacterStatisticsRequest request);



    ///////////////////////////////////////////////////////
    // Character Data
    //////////////////////////////////////////////////////
    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterData(FServerGetCharacterDataRequest request);

    /** Retrieves the title-specific custom data for the user's character which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterInternalData(FServerGetCharacterDataRequest request);

    /** Retrieves the title-specific custom data for the user's character which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterReadOnlyData(FServerGetCharacterDataRequest request);

    /** Updates the title-specific custom data for the user's chjaracter which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterData(FServerUpdateCharacterDataRequest request);

    /** Updates the title-specific custom data for the user's character which cannot  be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterInternalData(FServerUpdateCharacterDataRequest request);

    /** Updates the title-specific custom data for the user's character which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterReadOnlyData(FServerUpdateCharacterDataRequest request);



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
