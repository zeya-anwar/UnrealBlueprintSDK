//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Server
// SDK Version: 0.0.160414
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabServerAPI.h"

UPlayFabServerAPI* Server_proxy = NULL;

UPlayFabServerAPI::UPlayFabServerAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    Server_proxy = this;
}

void UPlayFabServerAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabServerAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabServerAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////
/** Validated a client's session ticket, and if successful, returns details for that user */
UPlayFabServerAPI* UPlayFabServerAPI::AuthenticateSessionTicket(FServerAuthenticateSessionTicketRequest request,
    FDelegateOnSuccessAuthenticateSessionTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAuthenticateSessionTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAuthenticateSessionTicket);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AuthenticateSessionTicket";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.SessionTicket.IsEmpty() || request.SessionTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SessionTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SessionTicket"), request.SessionTicket);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAuthenticateSessionTicket(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerAuthenticateSessionTicketResult result = UPlayFabServerModelDecoder::decodeAuthenticateSessionTicketResultResponse(response.responseData);
        if (OnSuccessAuthenticateSessionTicket.IsBound())
        {
            OnSuccessAuthenticateSessionTicket.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayFabIDsFromFacebookIDs(FServerGetPlayFabIDsFromFacebookIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromFacebookIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayFabIDsFromFacebookIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayFabIDsFromFacebookIDs";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    // Check to see if string is empty
    if (request.FacebookIDs.IsEmpty() || request.FacebookIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FacebookIDs"));
    }
    else
    {
        TArray<FString> FacebookIDsArray;
        FString(request.FacebookIDs).ParseIntoArray(FacebookIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FacebookIDs"), FacebookIDsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayFabIDsFromFacebookIDs(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetPlayFabIDsFromFacebookIDsResult result = UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromFacebookIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromFacebookIDs.Execute(result);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayFabIDsFromSteamIDs(FServerGetPlayFabIDsFromSteamIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromSteamIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromSteamIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayFabIDsFromSteamIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayFabIDsFromSteamIDs";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    // Copy int array to float
    TArray<float> tempArray;
    for (int32 i = 0; i < request.SteamIDs.Num(); ++i)
    {
        tempArray.Add(float(request.SteamIDs[i]));
    }
    OutRestJsonObj->SetNumberArrayField(TEXT("SteamIDs"), tempArray);

    // Check to see if string is empty
    if (request.SteamStringIDs.IsEmpty() || request.SteamStringIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SteamStringIDs"));
    }
    else
    {
        TArray<FString> SteamStringIDsArray;
        FString(request.SteamStringIDs).ParseIntoArray(SteamStringIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("SteamStringIDs"), SteamStringIDsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayFabIDsFromSteamIDs(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetPlayFabIDsFromSteamIDsResult result = UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromSteamIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromSteamIDs.Execute(result);
        }
    }
}

/** Retrieves the relevant details for a specified user */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserAccountInfo(FServerGetUserAccountInfoRequest request,
    FDelegateOnSuccessGetUserAccountInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserAccountInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserAccountInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserAccountInfo";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserAccountInfo(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserAccountInfoResult result = UPlayFabServerModelDecoder::decodeGetUserAccountInfoResultResponse(response.responseData);
        if (OnSuccessGetUserAccountInfo.IsBound())
        {
            OnSuccessGetUserAccountInfo.Execute(result);
        }
    }
}

/** Sends an iOS/Android Push Notification to a specific user, if that user's device has been configured for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified. */
UPlayFabServerAPI* UPlayFabServerAPI::SendPushNotification(FServerSendPushNotificationRequest request,
    FDelegateOnSuccessSendPushNotification onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSendPushNotification = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSendPushNotification);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SendPushNotification";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Recipient.IsEmpty() || request.Recipient == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Recipient"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Recipient"), request.Recipient);
    }

    if (request.Message.IsEmpty() || request.Message == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Message"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Message"), request.Message);
    }

    if (request.Subject.IsEmpty() || request.Subject == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Subject"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Subject"), request.Subject);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSendPushNotification(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerSendPushNotificationResult result = UPlayFabServerModelDecoder::decodeSendPushNotificationResultResponse(response.responseData);
        if (OnSuccessSendPushNotification.IsBound())
        {
            OnSuccessSendPushNotification.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteUsers(FServerDeleteUsersRequest request,
    FDelegateOnSuccessDeleteUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessDeleteUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperDeleteUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/DeleteUsers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    }
    else
    {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }

    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperDeleteUsers(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerDeleteUsersResult result = UPlayFabServerModelDecoder::decodeDeleteUsersResultResponse(response.responseData);
        if (OnSuccessDeleteUsers.IsBound())
        {
            OnSuccessDeleteUsers.Execute(result);
        }
    }
}

/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboard(FServerGetLeaderboardRequest request,
    FDelegateOnSuccessGetLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboard";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboard(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetLeaderboardResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetLeaderboard.IsBound())
        {
            OnSuccessGetLeaderboard.Execute(result);
        }
    }
}

/** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardAroundUser(FServerGetLeaderboardAroundUserRequest request,
    FDelegateOnSuccessGetLeaderboardAroundUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboardAroundUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboardAroundUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboardAroundUser(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetLeaderboardAroundUserResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardAroundUserResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardAroundUser.IsBound())
        {
            OnSuccessGetLeaderboardAroundUser.Execute(result);
        }
    }
}

/** Retrieves the current version and values for the indicated statistics, for the local player. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerStatistics(FServerGetPlayerStatisticsRequest request,
    FDelegateOnSuccessGetPlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Check to see if string is empty
    if (request.StatisticNames.IsEmpty() || request.StatisticNames == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticNames"));
    }
    else
    {
        TArray<FString> StatisticNamesArray;
        FString(request.StatisticNames).ParseIntoArray(StatisticNamesArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("StatisticNames"), StatisticNamesArray);
    }

    OutRestJsonObj->SetObjectArrayField(TEXT("StatisticNameVersions"), request.StatisticNameVersions);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerStatistics(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetPlayerStatisticsResult result = UPlayFabServerModelDecoder::decodeGetPlayerStatisticsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatistics.IsBound())
        {
            OnSuccessGetPlayerStatistics.Execute(result);
        }
    }
}

/** Retrieves the information on the available versions of the specified statistic. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerStatisticVersions(FServerGetPlayerStatisticVersionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerStatisticVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerStatisticVersions";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetPlayerStatisticVersionsResult result = UPlayFabServerModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatisticVersions.IsBound())
        {
            OnSuccessGetPlayerStatisticVersions.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserData.IsBound())
        {
            OnSuccessGetUserData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserInternalData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserInternalData.IsBound())
        {
            OnSuccessGetUserInternalData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserPublisherData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherData.IsBound())
        {
            OnSuccessGetUserPublisherData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherInternalData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserPublisherInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserPublisherInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserPublisherInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherInternalData.IsBound())
        {
            OnSuccessGetUserPublisherInternalData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherReadOnlyData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserPublisherReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessGetUserPublisherReadOnlyData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserReadOnlyData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserReadOnlyData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserReadOnlyData.IsBound())
        {
            OnSuccessGetUserReadOnlyData.Execute(result);
        }
    }
}

/** Retrieves the details of all title-specific statistics for the user */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserStatistics(FServerGetUserStatisticsRequest request,
    FDelegateOnSuccessGetUserStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserStatistics(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserStatisticsResult result = UPlayFabServerModelDecoder::decodeGetUserStatisticsResultResponse(response.responseData);
        if (OnSuccessGetUserStatistics.IsBound())
        {
            OnSuccessGetUserStatistics.Execute(result);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the user */
UPlayFabServerAPI* UPlayFabServerAPI::UpdatePlayerStatistics(FServerUpdatePlayerStatisticsRequest request,
    FDelegateOnSuccessUpdatePlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdatePlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdatePlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdatePlayerStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetObjectArrayField(TEXT("Statistics"), request.Statistics);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdatePlayerStatistics(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdatePlayerStatisticsResult result = UPlayFabServerModelDecoder::decodeUpdatePlayerStatisticsResultResponse(response.responseData);
        if (OnSuccessUpdatePlayerStatistics.IsBound())
        {
            OnSuccessUpdatePlayerStatistics.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserData.IsBound())
        {
            OnSuccessUpdateUserData.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserInternalData(FServerUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserInternalData.IsBound())
        {
            OnSuccessUpdateUserInternalData.Execute(result);
        }
    }
}

/** Updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserPublisherData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherData.IsBound())
        {
            OnSuccessUpdateUserPublisherData.Execute(result);
        }
    }
}

/** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherInternalData(FServerUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserPublisherInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserPublisherInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherInternalData.IsBound())
        {
            OnSuccessUpdateUserPublisherInternalData.Execute(result);
        }
    }
}

/** Updates the publisher-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherReadOnlyData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserPublisherReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessUpdateUserPublisherReadOnlyData.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserReadOnlyData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserReadOnlyData.IsBound())
        {
            OnSuccessUpdateUserReadOnlyData.Execute(result);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the user. By default, clients are not permitted to update statistics. Developers may override this setting in the Game Manager > Settings > API Features. */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserStatistics(FServerUpdateUserStatisticsRequest request,
    FDelegateOnSuccessUpdateUserStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.UserStatistics != NULL) OutRestJsonObj->SetObjectField(TEXT("UserStatistics"), request.UserStatistics);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserStatistics(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateUserStatisticsResult result = UPlayFabServerModelDecoder::decodeUpdateUserStatisticsResultResponse(response.responseData);
        if (OnSuccessUpdateUserStatistics.IsBound())
        {
            OnSuccessUpdateUserStatistics.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabServerAPI* UPlayFabServerAPI::GetCatalogItems(FServerGetCatalogItemsRequest request,
    FDelegateOnSuccessGetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCatalogItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCatalogItems";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCatalogItems(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetCatalogItemsResult result = UPlayFabServerModelDecoder::decodeGetCatalogItemsResultResponse(response.responseData);
        if (OnSuccessGetCatalogItems.IsBound())
        {
            OnSuccessGetCatalogItems.Execute(result);
        }
    }
}

/** Retrieves the key-value store of custom publisher settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetPublisherData(FServerGetPublisherDataRequest request,
    FDelegateOnSuccessGetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPublisherData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetPublisherDataResult result = UPlayFabServerModelDecoder::decodeGetPublisherDataResultResponse(response.responseData);
        if (OnSuccessGetPublisherData.IsBound())
        {
            OnSuccessGetPublisherData.Execute(result);
        }
    }
}

/** Retrieves the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleData(FServerGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetTitleData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetTitleData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetTitleDataResult result = UPlayFabServerModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        if (OnSuccessGetTitleData.IsBound())
        {
            OnSuccessGetTitleData.Execute(result);
        }
    }
}

/** Retrieves the key-value store of custom internal title settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleInternalData(FServerGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetTitleInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetTitleInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetTitleInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetTitleInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetTitleDataResult result = UPlayFabServerModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        if (OnSuccessGetTitleInternalData.IsBound())
        {
            OnSuccessGetTitleInternalData.Execute(result);
        }
    }
}

/** Retrieves the title news feed, as configured in the developer portal */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleNews(FServerGetTitleNewsRequest request,
    FDelegateOnSuccessGetTitleNews onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetTitleNews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetTitleNews);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetTitleNews";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetTitleNews(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetTitleNewsResult result = UPlayFabServerModelDecoder::decodeGetTitleNewsResultResponse(response.responseData);
        if (OnSuccessGetTitleNews.IsBound())
        {
            OnSuccessGetTitleNews.Execute(result);
        }
    }
}

/** Updates the key-value store of custom publisher settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetPublisherData(FServerSetPublisherDataRequest request,
    FDelegateOnSuccessSetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Key.IsEmpty() || request.Key == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }

    if (request.Value.IsEmpty() || request.Value == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Value"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Value"), request.Value);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetPublisherData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerSetPublisherDataResult result = UPlayFabServerModelDecoder::decodeSetPublisherDataResultResponse(response.responseData);
        if (OnSuccessSetPublisherData.IsBound())
        {
            OnSuccessSetPublisherData.Execute(result);
        }
    }
}

/** Updates the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetTitleData(FServerSetTitleDataRequest request,
    FDelegateOnSuccessSetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetTitleData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Key.IsEmpty() || request.Key == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }

    if (request.Value.IsEmpty() || request.Value == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Value"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Value"), request.Value);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetTitleData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerSetTitleDataResult result = UPlayFabServerModelDecoder::decodeSetTitleDataResultResponse(response.responseData);
        if (OnSuccessSetTitleData.IsBound())
        {
            OnSuccessSetTitleData.Execute(result);
        }
    }
}

/** Updates the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetTitleInternalData(FServerSetTitleDataRequest request,
    FDelegateOnSuccessSetTitleInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetTitleInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetTitleInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetTitleInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Key.IsEmpty() || request.Key == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }

    if (request.Value.IsEmpty() || request.Value == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Value"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Value"), request.Value);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetTitleInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerSetTitleDataResult result = UPlayFabServerModelDecoder::decodeSetTitleDataResultResponse(response.responseData);
        if (OnSuccessSetTitleInternalData.IsBound())
        {
            OnSuccessSetTitleInternalData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments  the character's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::AddCharacterVirtualCurrency(FServerAddCharacterVirtualCurrencyRequest request,
    FDelegateOnSuccessAddCharacterVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddCharacterVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddCharacterVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddCharacterVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddCharacterVirtualCurrency(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerModifyCharacterVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyCharacterVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessAddCharacterVirtualCurrency.IsBound())
        {
            OnSuccessAddCharacterVirtualCurrency.Execute(result);
        }
    }
}

/** Increments  the user's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::AddUserVirtualCurrency(FServerAddUserVirtualCurrencyRequest request,
    FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddUserVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddUserVirtualCurrency(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerModifyUserVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessAddUserVirtualCurrency.IsBound())
        {
            OnSuccessAddUserVirtualCurrency.Execute(result);
        }
    }
}

/** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::ConsumeItem(FServerConsumeItemRequest request,
    FDelegateOnSuccessConsumeItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessConsumeItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperConsumeItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ConsumeItem";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    OutRestJsonObj->SetNumberField(TEXT("ConsumeCount"), request.ConsumeCount);
    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperConsumeItem(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerConsumeItemResult result = UPlayFabServerModelDecoder::decodeConsumeItemResultResponse(response.responseData);
        if (OnSuccessConsumeItem.IsBound())
        {
            OnSuccessConsumeItem.Execute(result);
        }
    }
}

/** Retrieves the specified character's current inventory of virtual goods */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterInventory(FServerGetCharacterInventoryRequest request,
    FDelegateOnSuccessGetCharacterInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterInventory";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterInventory(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetCharacterInventoryResult result = UPlayFabServerModelDecoder::decodeGetCharacterInventoryResultResponse(response.responseData);
        if (OnSuccessGetCharacterInventory.IsBound())
        {
            OnSuccessGetCharacterInventory.Execute(result);
        }
    }
}

/** Retrieves the specified user's current inventory of virtual goods */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserInventory(FServerGetUserInventoryRequest request,
    FDelegateOnSuccessGetUserInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserInventory";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserInventory(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetUserInventoryResult result = UPlayFabServerModelDecoder::decodeGetUserInventoryResultResponse(response.responseData);
        if (OnSuccessGetUserInventory.IsBound())
        {
            OnSuccessGetUserInventory.Execute(result);
        }
    }
}

/** Adds the specified items to the specified character's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToCharacter(FServerGrantItemsToCharacterRequest request,
    FDelegateOnSuccessGrantItemsToCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGrantItemsToCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantItemsToCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantItemsToCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Annotation.IsEmpty() || request.Annotation == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Annotation"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Annotation"), request.Annotation);
    }

    // Check to see if string is empty
    if (request.ItemIds.IsEmpty() || request.ItemIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemIds"));
    }
    else
    {
        TArray<FString> ItemIdsArray;
        FString(request.ItemIds).ParseIntoArray(ItemIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ItemIds"), ItemIdsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantItemsToCharacter(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGrantItemsToCharacterResult result = UPlayFabServerModelDecoder::decodeGrantItemsToCharacterResultResponse(response.responseData);
        if (OnSuccessGrantItemsToCharacter.IsBound())
        {
            OnSuccessGrantItemsToCharacter.Execute(result);
        }
    }
}

/** Adds the specified items to the specified user's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToUser(FServerGrantItemsToUserRequest request,
    FDelegateOnSuccessGrantItemsToUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGrantItemsToUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantItemsToUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantItemsToUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Annotation.IsEmpty() || request.Annotation == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Annotation"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Annotation"), request.Annotation);
    }

    // Check to see if string is empty
    if (request.ItemIds.IsEmpty() || request.ItemIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemIds"));
    }
    else
    {
        TArray<FString> ItemIdsArray;
        FString(request.ItemIds).ParseIntoArray(ItemIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ItemIds"), ItemIdsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantItemsToUser(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGrantItemsToUserResult result = UPlayFabServerModelDecoder::decodeGrantItemsToUserResultResponse(response.responseData);
        if (OnSuccessGrantItemsToUser.IsBound())
        {
            OnSuccessGrantItemsToUser.Execute(result);
        }
    }
}

/** Adds the specified items to the specified user inventories */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToUsers(FServerGrantItemsToUsersRequest request,
    FDelegateOnSuccessGrantItemsToUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGrantItemsToUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantItemsToUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantItemsToUsers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    OutRestJsonObj->SetObjectArrayField(TEXT("ItemGrants"), request.ItemGrants);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantItemsToUsers(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGrantItemsToUsersResult result = UPlayFabServerModelDecoder::decodeGrantItemsToUsersResultResponse(response.responseData);
        if (OnSuccessGrantItemsToUsers.IsBound())
        {
            OnSuccessGrantItemsToUsers.Execute(result);
        }
    }
}

/** Modifies the number of remaining uses of a player's inventory item */
UPlayFabServerAPI* UPlayFabServerAPI::ModifyItemUses(FServerModifyItemUsesRequest request,
    FDelegateOnSuccessModifyItemUses onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessModifyItemUses = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperModifyItemUses);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ModifyItemUses";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    OutRestJsonObj->SetNumberField(TEXT("UsesToAdd"), request.UsesToAdd);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperModifyItemUses(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerModifyItemUsesResult result = UPlayFabServerModelDecoder::decodeModifyItemUsesResultResponse(response.responseData);
        if (OnSuccessModifyItemUses.IsBound())
        {
            OnSuccessModifyItemUses.Execute(result);
        }
    }
}

/** Moves an item from a character's inventory into another of the users's character's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToCharacterFromCharacter(FServerMoveItemToCharacterFromCharacterRequest request,
    FDelegateOnSuccessMoveItemToCharacterFromCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessMoveItemToCharacterFromCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperMoveItemToCharacterFromCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/MoveItemToCharacterFromCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.GivingCharacterId.IsEmpty() || request.GivingCharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GivingCharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GivingCharacterId"), request.GivingCharacterId);
    }

    if (request.ReceivingCharacterId.IsEmpty() || request.ReceivingCharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceivingCharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceivingCharacterId"), request.ReceivingCharacterId);
    }

    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperMoveItemToCharacterFromCharacter(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerMoveItemToCharacterFromCharacterResult result = UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromCharacterResultResponse(response.responseData);
        if (OnSuccessMoveItemToCharacterFromCharacter.IsBound())
        {
            OnSuccessMoveItemToCharacterFromCharacter.Execute(result);
        }
    }
}

/** Moves an item from a user's inventory into their character's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToCharacterFromUser(FServerMoveItemToCharacterFromUserRequest request,
    FDelegateOnSuccessMoveItemToCharacterFromUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessMoveItemToCharacterFromUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperMoveItemToCharacterFromUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/MoveItemToCharacterFromUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperMoveItemToCharacterFromUser(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerMoveItemToCharacterFromUserResult result = UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromUserResultResponse(response.responseData);
        if (OnSuccessMoveItemToCharacterFromUser.IsBound())
        {
            OnSuccessMoveItemToCharacterFromUser.Execute(result);
        }
    }
}

/** Moves an item from a character's inventory into the owning user's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToUserFromCharacter(FServerMoveItemToUserFromCharacterRequest request,
    FDelegateOnSuccessMoveItemToUserFromCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessMoveItemToUserFromCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperMoveItemToUserFromCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/MoveItemToUserFromCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperMoveItemToUserFromCharacter(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerMoveItemToUserFromCharacterResult result = UPlayFabServerModelDecoder::decodeMoveItemToUserFromCharacterResultResponse(response.responseData);
        if (OnSuccessMoveItemToUserFromCharacter.IsBound())
        {
            OnSuccessMoveItemToUserFromCharacter.Execute(result);
        }
    }
}

/** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/2015/06/18/using-stores-and-coupons-game-manager */
UPlayFabServerAPI* UPlayFabServerAPI::RedeemCoupon(FServerRedeemCouponRequest request,
    FDelegateOnSuccessRedeemCoupon onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRedeemCoupon = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRedeemCoupon);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RedeemCoupon";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.CouponCode.IsEmpty() || request.CouponCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CouponCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CouponCode"), request.CouponCode);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRedeemCoupon(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerRedeemCouponResult result = UPlayFabServerModelDecoder::decodeRedeemCouponResultResponse(response.responseData);
        if (OnSuccessRedeemCoupon.IsBound())
        {
            OnSuccessRedeemCoupon.Execute(result);
        }
    }
}

/** Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service representatives for the title can take action concerning potentially toxic players. */
UPlayFabServerAPI* UPlayFabServerAPI::ReportPlayer(FServerReportPlayerServerRequest request,
    FDelegateOnSuccessReportPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessReportPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperReportPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ReportPlayer";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.ReporterId.IsEmpty() || request.ReporterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReporterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReporterId"), request.ReporterId);
    }

    if (request.ReporteeId.IsEmpty() || request.ReporteeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReporteeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReporteeId"), request.ReporteeId);
    }

    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Comment.IsEmpty() || request.Comment == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Comment"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Comment"), request.Comment);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperReportPlayer(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerReportPlayerServerResult result = UPlayFabServerModelDecoder::decodeReportPlayerServerResultResponse(response.responseData);
        if (OnSuccessReportPlayer.IsBound())
        {
            OnSuccessReportPlayer.Execute(result);
        }
    }
}

/** Revokes access to an item in a user's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::RevokeInventoryItem(FServerRevokeInventoryItemRequest request,
    FDelegateOnSuccessRevokeInventoryItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRevokeInventoryItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRevokeInventoryItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RevokeInventoryItem";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRevokeInventoryItem(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerRevokeInventoryResult result = UPlayFabServerModelDecoder::decodeRevokeInventoryResultResponse(response.responseData);
        if (OnSuccessRevokeInventoryItem.IsBound())
        {
            OnSuccessRevokeInventoryItem.Execute(result);
        }
    }
}

/** Decrements the character's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::SubtractCharacterVirtualCurrency(FServerSubtractCharacterVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractCharacterVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSubtractCharacterVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSubtractCharacterVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SubtractCharacterVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSubtractCharacterVirtualCurrency(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerModifyCharacterVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyCharacterVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessSubtractCharacterVirtualCurrency.IsBound())
        {
            OnSuccessSubtractCharacterVirtualCurrency.Execute(result);
        }
    }
}

/** Decrements the user's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::SubtractUserVirtualCurrency(FServerSubtractUserVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSubtractUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSubtractUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SubtractUserVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerModifyUserVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessSubtractUserVirtualCurrency.IsBound())
        {
            OnSuccessSubtractUserVirtualCurrency.Execute(result);
        }
    }
}

/** Opens a specific container (ContainerItemInstanceId), with a specific key (KeyItemInstanceId, when required), and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabServerAPI* UPlayFabServerAPI::UnlockContainerInstance(FServerUnlockContainerInstanceRequest request,
    FDelegateOnSuccessUnlockContainerInstance onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlockContainerInstance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUnlockContainerInstance);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UnlockContainerInstance";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.ContainerItemInstanceId.IsEmpty() || request.ContainerItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ContainerItemInstanceId"), request.ContainerItemInstanceId);
    }

    if (request.KeyItemInstanceId.IsEmpty() || request.KeyItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeyItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("KeyItemInstanceId"), request.KeyItemInstanceId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUnlockContainerInstance(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUnlockContainerItemResult result = UPlayFabServerModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        if (OnSuccessUnlockContainerInstance.IsBound())
        {
            OnSuccessUnlockContainerInstance.Execute(result);
        }
    }
}

/** Searches Player or Character inventory for any ItemInstance matching the given CatalogItemId, if necessary unlocks it using any appropriate key, and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabServerAPI* UPlayFabServerAPI::UnlockContainerItem(FServerUnlockContainerItemRequest request,
    FDelegateOnSuccessUnlockContainerItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlockContainerItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUnlockContainerItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UnlockContainerItem";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.ContainerItemId.IsEmpty() || request.ContainerItemId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerItemId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ContainerItemId"), request.ContainerItemId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUnlockContainerItem(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUnlockContainerItemResult result = UPlayFabServerModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        if (OnSuccessUnlockContainerItem.IsBound())
        {
            OnSuccessUnlockContainerItem.Execute(result);
        }
    }
}

/** Updates the key-value pair data tagged to the specified item, which is read-only from the client. */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserInventoryItemCustomData(FServerUpdateUserInventoryItemDataRequest request,
    FDelegateOnSuccessUpdateUserInventoryItemCustomData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserInventoryItemCustomData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserInventoryItemCustomData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserInventoryItemCustomData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserInventoryItemCustomData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        if (OnSuccessUpdateUserInventoryItemCustomData.IsBound())
        {
            OnSuccessUpdateUserInventoryItemCustomData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Informs the PlayFab match-making service that the user specified has left the Game Server Instance */
UPlayFabServerAPI* UPlayFabServerAPI::NotifyMatchmakerPlayerLeft(FServerNotifyMatchmakerPlayerLeftRequest request,
    FDelegateOnSuccessNotifyMatchmakerPlayerLeft onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessNotifyMatchmakerPlayerLeft = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperNotifyMatchmakerPlayerLeft);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/NotifyMatchmakerPlayerLeft";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.LobbyId.IsEmpty() || request.LobbyId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperNotifyMatchmakerPlayerLeft(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerNotifyMatchmakerPlayerLeftResult result = UPlayFabServerModelDecoder::decodeNotifyMatchmakerPlayerLeftResultResponse(response.responseData);
        if (OnSuccessNotifyMatchmakerPlayerLeft.IsBound())
        {
            OnSuccessNotifyMatchmakerPlayerLeft.Execute(result);
        }
    }
}

/** Validates a Game Server session ticket and returns details about the user */
UPlayFabServerAPI* UPlayFabServerAPI::RedeemMatchmakerTicket(FServerRedeemMatchmakerTicketRequest request,
    FDelegateOnSuccessRedeemMatchmakerTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRedeemMatchmakerTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRedeemMatchmakerTicket);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RedeemMatchmakerTicket";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Ticket.IsEmpty() || request.Ticket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Ticket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Ticket"), request.Ticket);
    }

    if (request.LobbyId.IsEmpty() || request.LobbyId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRedeemMatchmakerTicket(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerRedeemMatchmakerTicketResult result = UPlayFabServerModelDecoder::decodeRedeemMatchmakerTicketResultResponse(response.responseData);
        if (OnSuccessRedeemMatchmakerTicket.IsBound())
        {
            OnSuccessRedeemMatchmakerTicket.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Steam-Specific APIs
//////////////////////////////////////////////////////
/** Awards the specified users the specified Steam achievements */
UPlayFabServerAPI* UPlayFabServerAPI::AwardSteamAchievement(FServerAwardSteamAchievementRequest request,
    FDelegateOnSuccessAwardSteamAchievement onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAwardSteamAchievement = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAwardSteamAchievement);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AwardSteamAchievement";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetObjectArrayField(TEXT("Achievements"), request.Achievements);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAwardSteamAchievement(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerAwardSteamAchievementResult result = UPlayFabServerModelDecoder::decodeAwardSteamAchievementResultResponse(response.responseData);
        if (OnSuccessAwardSteamAchievement.IsBound())
        {
            OnSuccessAwardSteamAchievement.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////
/** Logs a custom analytics event */
UPlayFabServerAPI* UPlayFabServerAPI::LogEvent(FServerLogEventRequest request,
    FDelegateOnSuccessLogEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLogEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperLogEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/LogEvent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.EntityId.IsEmpty() || request.EntityId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("EntityId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("EntityId"), request.EntityId);
    }

    if (request.EntityType.IsEmpty() || request.EntityType == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("EntityType"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("EntityType"), request.EntityType);
    }

    if (request.Timestamp.IsEmpty() || request.Timestamp == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }

    if (request.EventName.IsEmpty() || request.EventName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }

    if (request.Body != NULL) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);
    OutRestJsonObj->SetBoolField(TEXT("ProfileSetEvent"), request.ProfileSetEvent);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperLogEvent(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerLogEventResult result = UPlayFabServerModelDecoder::decodeLogEventResultResponse(response.responseData);
        if (OnSuccessLogEvent.IsBound())
        {
            OnSuccessLogEvent.Execute(result);
        }
    }
}

/** Writes a character-based event into PlayStream. */
UPlayFabServerAPI* UPlayFabServerAPI::WriteCharacterEvent(FServerWriteServerCharacterEventRequest request,
    FDelegateOnSuccessWriteCharacterEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessWriteCharacterEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperWriteCharacterEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/WriteCharacterEvent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.EventName.IsEmpty() || request.EventName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }

    if (request.Timestamp.IsEmpty() || request.Timestamp == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }

    if (request.Body != NULL) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperWriteCharacterEvent(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerWriteEventResponse result = UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        if (OnSuccessWriteCharacterEvent.IsBound())
        {
            OnSuccessWriteCharacterEvent.Execute(result);
        }
    }
}

/** Writes a player-based event into PlayStream. */
UPlayFabServerAPI* UPlayFabServerAPI::WritePlayerEvent(FServerWriteServerPlayerEventRequest request,
    FDelegateOnSuccessWritePlayerEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessWritePlayerEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperWritePlayerEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/WritePlayerEvent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.EventName.IsEmpty() || request.EventName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }

    if (request.Timestamp.IsEmpty() || request.Timestamp == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }

    if (request.Body != NULL) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperWritePlayerEvent(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerWriteEventResponse result = UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        if (OnSuccessWritePlayerEvent.IsBound())
        {
            OnSuccessWritePlayerEvent.Execute(result);
        }
    }
}

/** Writes a title-based event into PlayStream. */
UPlayFabServerAPI* UPlayFabServerAPI::WriteTitleEvent(FServerWriteTitleEventRequest request,
    FDelegateOnSuccessWriteTitleEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessWriteTitleEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperWriteTitleEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/WriteTitleEvent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.EventName.IsEmpty() || request.EventName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }

    if (request.Timestamp.IsEmpty() || request.Timestamp == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }

    if (request.Body != NULL) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperWriteTitleEvent(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerWriteEventResponse result = UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        if (OnSuccessWriteTitleEvent.IsBound())
        {
            OnSuccessWriteTitleEvent.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group (and the server) can add new members. */
UPlayFabServerAPI* UPlayFabServerAPI::AddSharedGroupMembers(FServerAddSharedGroupMembersRequest request,
    FDelegateOnSuccessAddSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddSharedGroupMembers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    }
    else
    {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddSharedGroupMembers(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerAddSharedGroupMembersResult result = UPlayFabServerModelDecoder::decodeAddSharedGroupMembersResultResponse(response.responseData);
        if (OnSuccessAddSharedGroupMembers.IsBound())
        {
            OnSuccessAddSharedGroupMembers.Execute(result);
        }
    }
}

/** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. When created by a server, the group will initially have no members. */
UPlayFabServerAPI* UPlayFabServerAPI::CreateSharedGroup(FServerCreateSharedGroupRequest request,
    FDelegateOnSuccessCreateSharedGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessCreateSharedGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperCreateSharedGroup);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/CreateSharedGroup";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperCreateSharedGroup(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerCreateSharedGroupResult result = UPlayFabServerModelDecoder::decodeCreateSharedGroupResultResponse(response.responseData);
        if (OnSuccessCreateSharedGroup.IsBound())
        {
            OnSuccessCreateSharedGroup.Execute(result);
        }
    }
}

/** Deletes a shared group, freeing up the shared group ID to be reused for a new group */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteSharedGroup(FServerDeleteSharedGroupRequest request,
    FDelegateOnSuccessDeleteSharedGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessDeleteSharedGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperDeleteSharedGroup);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/DeleteSharedGroup";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperDeleteSharedGroup(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        if (OnSuccessDeleteSharedGroup.IsBound())
        {
            OnSuccessDeleteSharedGroup.Execute(result);
        }
    }
}

/** Retrieves data stored in a shared group object, as well as the list of members in the group. The server can access all public and private group data. */
UPlayFabServerAPI* UPlayFabServerAPI::GetSharedGroupData(FServerGetSharedGroupDataRequest request,
    FDelegateOnSuccessGetSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetSharedGroupData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetBoolField(TEXT("GetMembers"), request.GetMembers);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetSharedGroupData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetSharedGroupDataResult result = UPlayFabServerModelDecoder::decodeGetSharedGroupDataResultResponse(response.responseData);
        if (OnSuccessGetSharedGroupData.IsBound())
        {
            OnSuccessGetSharedGroupData.Execute(result);
        }
    }
}

/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. */
UPlayFabServerAPI* UPlayFabServerAPI::RemoveSharedGroupMembers(FServerRemoveSharedGroupMembersRequest request,
    FDelegateOnSuccessRemoveSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRemoveSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRemoveSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RemoveSharedGroupMembers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    }
    else
    {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRemoveSharedGroupMembers(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerRemoveSharedGroupMembersResult result = UPlayFabServerModelDecoder::decodeRemoveSharedGroupMembersResultResponse(response.responseData);
        if (OnSuccessRemoveSharedGroupMembers.IsBound())
        {
            OnSuccessRemoveSharedGroupMembers.Execute(result);
        }
    }
}

/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group (and the server) can update the data. */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateSharedGroupData(FServerUpdateSharedGroupDataRequest request,
    FDelegateOnSuccessUpdateSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateSharedGroupData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateSharedGroupData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateSharedGroupDataResult result = UPlayFabServerModelDecoder::decodeUpdateSharedGroupDataResultResponse(response.responseData);
        if (OnSuccessUpdateSharedGroupData.IsBound())
        {
            OnSuccessUpdateSharedGroupData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Executes a CloudScript function, with the 'currentPlayerId' variable set to the specified PlayFabId parameter value. */
UPlayFabServerAPI* UPlayFabServerAPI::ExecuteCloudScript(FServerExecuteCloudScriptServerRequest request,
    FDelegateOnSuccessExecuteCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessExecuteCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperExecuteCloudScript);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ExecuteCloudScript";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.FunctionName.IsEmpty() || request.FunctionName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }

    if (request.FunctionParameter != NULL) OutRestJsonObj->SetObjectField(TEXT("FunctionParameter"), request.FunctionParameter);
    if (request.RevisionSelection.IsEmpty() || request.RevisionSelection == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("RevisionSelection"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("RevisionSelection"), request.RevisionSelection);
    }

    OutRestJsonObj->SetNumberField(TEXT("SpecificRevision"), request.SpecificRevision);
    OutRestJsonObj->SetBoolField(TEXT("GeneratePlayStreamEvent"), request.GeneratePlayStreamEvent);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperExecuteCloudScript(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerExecuteCloudScriptResult result = UPlayFabServerModelDecoder::decodeExecuteCloudScriptResultResponse(response.responseData);
        if (OnSuccessExecuteCloudScript.IsBound())
        {
            OnSuccessExecuteCloudScript.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://community.playfab.com/hc/en-us/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service */
UPlayFabServerAPI* UPlayFabServerAPI::GetContentDownloadUrl(FServerGetContentDownloadUrlRequest request,
    FDelegateOnSuccessGetContentDownloadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetContentDownloadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetContentDownloadUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetContentDownloadUrl";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Key.IsEmpty() || request.Key == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }

    if (request.HttpMethod.IsEmpty() || request.HttpMethod == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("HttpMethod"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("HttpMethod"), request.HttpMethod);
    }

    OutRestJsonObj->SetBoolField(TEXT("ThruCDN"), request.ThruCDN);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetContentDownloadUrl(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetContentDownloadUrlResult result = UPlayFabServerModelDecoder::decodeGetContentDownloadUrlResultResponse(response.responseData);
        if (OnSuccessGetContentDownloadUrl.IsBound())
        {
            OnSuccessGetContentDownloadUrl.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Deletes the specific character ID from the specified user. */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteCharacterFromUser(FServerDeleteCharacterFromUserRequest request,
    FDelegateOnSuccessDeleteCharacterFromUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessDeleteCharacterFromUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperDeleteCharacterFromUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/DeleteCharacterFromUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    OutRestJsonObj->SetBoolField(TEXT("SaveCharacterInventory"), request.SaveCharacterInventory);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperDeleteCharacterFromUser(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerDeleteCharacterFromUserResult result = UPlayFabServerModelDecoder::decodeDeleteCharacterFromUserResultResponse(response.responseData);
        if (OnSuccessDeleteCharacterFromUser.IsBound())
        {
            OnSuccessDeleteCharacterFromUser.Execute(result);
        }
    }
}

/** Lists all of the characters that belong to a specific user. CharacterIds are not globally unique; characterId must be evaluated with the parent PlayFabId to guarantee uniqueness. */
UPlayFabServerAPI* UPlayFabServerAPI::GetAllUsersCharacters(FServerListUsersCharactersRequest request,
    FDelegateOnSuccessGetAllUsersCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetAllUsersCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetAllUsersCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetAllUsersCharacters";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetAllUsersCharacters(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerListUsersCharactersResult result = UPlayFabServerModelDecoder::decodeListUsersCharactersResultResponse(response.responseData);
        if (OnSuccessGetAllUsersCharacters.IsBound())
        {
            OnSuccessGetAllUsersCharacters.Execute(result);
        }
    }
}

/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterLeaderboard(FServerGetCharacterLeaderboardRequest request,
    FDelegateOnSuccessGetCharacterLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterLeaderboard";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CharacterType.IsEmpty() || request.CharacterType == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterLeaderboard(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetCharacterLeaderboardResult result = UPlayFabServerModelDecoder::decodeGetCharacterLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetCharacterLeaderboard.IsBound())
        {
            OnSuccessGetCharacterLeaderboard.Execute(result);
        }
    }
}

/** Retrieves the details of all title-specific statistics for the specific character */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterStatistics(FServerGetCharacterStatisticsRequest request,
    FDelegateOnSuccessGetCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterStatistics(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetCharacterStatisticsResult result = UPlayFabServerModelDecoder::decodeGetCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessGetCharacterStatistics.IsBound())
        {
            OnSuccessGetCharacterStatistics.Execute(result);
        }
    }
}

/** Retrieves a list of ranked characters for the given statistic, centered on the requested user */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardAroundCharacter(FServerGetLeaderboardAroundCharacterRequest request,
    FDelegateOnSuccessGetLeaderboardAroundCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboardAroundCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboardAroundCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CharacterType.IsEmpty() || request.CharacterType == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboardAroundCharacter(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetLeaderboardAroundCharacterResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardAroundCharacter.IsBound())
        {
            OnSuccessGetLeaderboardAroundCharacter.Execute(result);
        }
    }
}

/** Retrieves a list of all of the user's characters for the given statistic. */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardForUserCharacters(FServerGetLeaderboardForUsersCharactersRequest request,
    FDelegateOnSuccessGetLeaderboardForUserCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboardForUserCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboardForUserCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboardForUserCharacters";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboardForUserCharacters(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetLeaderboardForUsersCharactersResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardForUserCharacters.IsBound())
        {
            OnSuccessGetLeaderboardForUserCharacters.Execute(result);
        }
    }
}

/** Grants the specified character type to the user. CharacterIds are not globally unique; characterId must be evaluated with the parent PlayFabId to guarantee uniqueness. */
UPlayFabServerAPI* UPlayFabServerAPI::GrantCharacterToUser(FServerGrantCharacterToUserRequest request,
    FDelegateOnSuccessGrantCharacterToUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGrantCharacterToUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantCharacterToUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantCharacterToUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterName.IsEmpty() || request.CharacterName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterName"), request.CharacterName);
    }

    if (request.CharacterType.IsEmpty() || request.CharacterType == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantCharacterToUser(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGrantCharacterToUserResult result = UPlayFabServerModelDecoder::decodeGrantCharacterToUserResultResponse(response.responseData);
        if (OnSuccessGrantCharacterToUser.IsBound())
        {
            OnSuccessGrantCharacterToUser.Execute(result);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the specific character */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterStatistics(FServerUpdateCharacterStatisticsRequest request,
    FDelegateOnSuccessUpdateCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CharacterStatistics != NULL) OutRestJsonObj->SetObjectField(TEXT("CharacterStatistics"), request.CharacterStatistics);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterStatistics(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateCharacterStatisticsResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterStatistics.IsBound())
        {
            OnSuccessUpdateCharacterStatistics.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////
/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterData(FServerGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetCharacterDataResult result = UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        if (OnSuccessGetCharacterData.IsBound())
        {
            OnSuccessGetCharacterData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user's character which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterInternalData(FServerGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetCharacterDataResult result = UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        if (OnSuccessGetCharacterInternalData.IsBound())
        {
            OnSuccessGetCharacterInternalData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user's character which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterReadOnlyData(FServerGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterReadOnlyData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerGetCharacterDataResult result = UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        if (OnSuccessGetCharacterReadOnlyData.IsBound())
        {
            OnSuccessGetCharacterReadOnlyData.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user's chjaracter which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterData(FServerUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateCharacterDataResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterData.IsBound())
        {
            OnSuccessUpdateCharacterData.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user's character which cannot  be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterInternalData(FServerUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCharacterInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterInternalData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateCharacterDataResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterInternalData.IsBound())
        {
            OnSuccessUpdateCharacterInternalData.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user's character which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterReadOnlyData(FServerUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCharacterReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterReadOnlyData(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FServerUpdateCharacterDataResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterReadOnlyData.IsBound())
        {
            OnSuccessUpdateCharacterReadOnlyData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////


void UPlayFabServerAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    FPlayFabBaseModel myResponse;

    // Check we have result to process futher
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.ErrorCode = 500;
        myResponse.responseError.ErrorName = "Request Error";
        myResponse.responseError.ErrorMessage = "HTTP Request Error";

        myResponse.responseData = ResponseJsonObj;

        Server_proxy->OnPlayFabResponse.Broadcast(myResponse, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
    {
        if (!ResponseJsonObj->GetRootObject().IsValid())
        {
            // As we assume it's recommended way to use current class, but not the only one,
            // it will be the warning instead of error
            UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));
        }
    }

    // Serialize data to json string
    FString InputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&InputString);
    FJsonSerializer::Serialize(ResponseJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *InputString);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;

    // Broadcast the result event
    Server_proxy->OnPlayFabResponse.Broadcast(myResponse, true);
}

void UPlayFabServerAPI::Activate()
{
    FString RequestUrl = TEXT("https://") + IPlayFab::Get().getGameTitleId() + IPlayFab::PlayFabURL;

    // Build the full request url
    if (cloudScript)
    {
        RequestUrl = TEXT("https://") + IPlayFab::Get().getGameTitleId() + IPlayFab::PlayFabLogicURL + FString::FromInt(IPlayFab::Get().CloudScriptVersion) + TEXT("/prod");
    }

    RequestUrl = RequestUrl + PlayFabRequestURL;

    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);

    if (useSessionTicket)
    {
        HttpRequest->SetHeader("X-Authentication", IPlayFab::Get().getSessionTicket());
    }
    if (useSecretKey)
    {
        HttpRequest->SetHeader("X-SecretKey", IPlayFab::Get().getSecretApiKey());
    }

    // Set verb
    HttpRequest->SetVerb("POST");


    // Set content-type
    HttpRequest->SetHeader("Content-Type", "application/json");

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    // Apply additional headers
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
    {
        HttpRequest->SetHeader(It.Key(), It.Value());
    }

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabServerAPI::OnProcessRequestComplete);

    // Execute the request
    HttpRequest->ProcessRequest();
}

void UPlayFabServerAPI::ResetResponseData()
{
    if (ResponseJsonObj != NULL)
    {
        ResponseJsonObj->Reset();
    }
    else
    {
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    }

    bIsValidJsonResponse = false;
}
