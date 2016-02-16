//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Server
// SDK Version: 0.0.160215
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
UPlayFabServerAPI* UPlayFabServerAPI::AuthenticateSessionTicket(FServerAuthenticateSessionTicketRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayFabIDsFromFacebookIDs(FServerGetPlayFabIDsFromFacebookIDsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayFabIDsFromSteamIDs(FServerGetPlayFabIDsFromSteamIDsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the relevant details for a specified user */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserAccountInfo(FServerGetUserAccountInfoRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Sends an iOS/Android Push Notification to a specific user, if that user's device has been configured for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified. */
UPlayFabServerAPI* UPlayFabServerAPI::SendPushNotification(FServerSendPushNotificationRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteUsers(FServerDeleteUsersRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboard(FServerGetLeaderboardRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardAroundUser(FServerGetLeaderboardAroundUserRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserData(FServerGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserInternalData(FServerGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherData(FServerGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherInternalData(FServerGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherReadOnlyData(FServerGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserReadOnlyData(FServerGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the details of all title-specific statistics for the user */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserStatistics(FServerGetUserStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserData(FServerUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserInternalData(FServerUpdateUserInternalDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherData(FServerUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherInternalData(FServerUpdateUserInternalDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the publisher-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherReadOnlyData(FServerUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the title-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserReadOnlyData(FServerUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the values of the specified title-specific statistics for the user */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserStatistics(FServerUpdateUserStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabServerAPI* UPlayFabServerAPI::GetCatalogItems(FServerGetCatalogItemsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleData(FServerGetTitleDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the key-value store of custom internal title settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleInternalData(FServerGetTitleDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the title news feed, as configured in the developer portal */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleNews(FServerGetTitleNewsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetTitleData(FServerSetTitleDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetTitleInternalData(FServerSetTitleDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments  the character's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::AddCharacterVirtualCurrency(FServerAddCharacterVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Increments  the user's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::AddUserVirtualCurrency(FServerAddUserVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::ConsumeItem(FServerConsumeItemRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the specified character's current inventory of virtual goods */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterInventory(FServerGetCharacterInventoryRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the specified user's current inventory of virtual goods */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserInventory(FServerGetUserInventoryRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Adds the specified items to the specified character's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToCharacter(FServerGrantItemsToCharacterRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Adds the specified items to the specified user's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToUser(FServerGrantItemsToUserRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Adds the specified items to the specified user inventories */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToUsers(FServerGrantItemsToUsersRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Modifies the number of remaining uses of a player's inventory item */
UPlayFabServerAPI* UPlayFabServerAPI::ModifyItemUses(FServerModifyItemUsesRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Moves an item from a character's inventory into another of the users's character's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToCharacterFromCharacter(FServerMoveItemToCharacterFromCharacterRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Moves an item from a user's inventory into their character's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToCharacterFromUser(FServerMoveItemToCharacterFromUserRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Moves an item from a character's inventory into the owning user's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToUserFromCharacter(FServerMoveItemToUserFromCharacterRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/2015/06/18/using-stores-and-coupons-game-manager */
UPlayFabServerAPI* UPlayFabServerAPI::RedeemCoupon(FServerRedeemCouponRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service representatives for the title can take action concerning potentially toxic players. */
UPlayFabServerAPI* UPlayFabServerAPI::ReportPlayer(FServerReportPlayerServerRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Revokes access to an item in a user's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::RevokeInventoryItem(FServerRevokeInventoryItemRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Decrements the character's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::SubtractCharacterVirtualCurrency(FServerSubtractCharacterVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Decrements the user's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::SubtractUserVirtualCurrency(FServerSubtractUserVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Opens a specific container (ContainerItemInstanceId), with a specific key (KeyItemInstanceId, when required), and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabServerAPI* UPlayFabServerAPI::UnlockContainerInstance(FServerUnlockContainerInstanceRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Searches Player or Character inventory for any ItemInstance matching the given CatalogItemId, if necessary unlocks it using any appropriate key, and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabServerAPI* UPlayFabServerAPI::UnlockContainerItem(FServerUnlockContainerItemRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the key-value pair data tagged to the specified item, which is read-only from the client. */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserInventoryItemCustomData(FServerUpdateUserInventoryItemDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserInventoryItemCustomData";
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


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Informs the PlayFab match-making service that the user specified has left the Game Server Instance */
UPlayFabServerAPI* UPlayFabServerAPI::NotifyMatchmakerPlayerLeft(FServerNotifyMatchmakerPlayerLeftRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Validates a Game Server session ticket and returns details about the user */
UPlayFabServerAPI* UPlayFabServerAPI::RedeemMatchmakerTicket(FServerRedeemMatchmakerTicketRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Steam-Specific APIs
//////////////////////////////////////////////////////
/** Awards the specified users the specified Steam achievements */
UPlayFabServerAPI* UPlayFabServerAPI::AwardSteamAchievement(FServerAwardSteamAchievementRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////
/** Logs a custom analytics event */
UPlayFabServerAPI* UPlayFabServerAPI::LogEvent(FServerLogEventRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group (and the server) can add new members. */
UPlayFabServerAPI* UPlayFabServerAPI::AddSharedGroupMembers(FServerAddSharedGroupMembersRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. When created by a server, the group will initially have no members. */
UPlayFabServerAPI* UPlayFabServerAPI::CreateSharedGroup(FServerCreateSharedGroupRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Deletes a shared group, freeing up the shared group ID to be reused for a new group */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteSharedGroup(FServerDeleteSharedGroupRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the key-value store of custom publisher settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetPublisherData(FServerGetPublisherDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves data stored in a shared group object, as well as the list of members in the group. The server can access all public and private group data. */
UPlayFabServerAPI* UPlayFabServerAPI::GetSharedGroupData(FServerGetSharedGroupDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. */
UPlayFabServerAPI* UPlayFabServerAPI::RemoveSharedGroupMembers(FServerRemoveSharedGroupMembersRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the key-value store of custom publisher settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetPublisherData(FServerSetPublisherDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group (and the server) can update the data. */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateSharedGroupData(FServerUpdateSharedGroupDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://community.playfab.com/hc/en-us/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service */
UPlayFabServerAPI* UPlayFabServerAPI::GetContentDownloadUrl(FServerGetContentDownloadUrlRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Deletes the specific character ID from the specified user. */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteCharacterFromUser(FServerDeleteCharacterFromUserRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Lists all of the characters that belong to a specific user. */
UPlayFabServerAPI* UPlayFabServerAPI::GetAllUsersCharacters(FServerListUsersCharactersRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterLeaderboard(FServerGetCharacterLeaderboardRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the details of all title-specific statistics for the specific character */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterStatistics(FServerGetCharacterStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves a list of ranked characters for the given statistic, centered on the requested user */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardAroundCharacter(FServerGetLeaderboardAroundCharacterRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves a list of all of the user's characters for the given statistic. */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardForUserCharacters(FServerGetLeaderboardForUsersCharactersRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Grants the specified character type to the user. */
UPlayFabServerAPI* UPlayFabServerAPI::GrantCharacterToUser(FServerGrantCharacterToUserRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the values of the specified title-specific statistics for the specific character */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterStatistics(FServerUpdateCharacterStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////
/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterData(FServerGetCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the title-specific custom data for the user's character which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterInternalData(FServerGetCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Retrieves the title-specific custom data for the user's character which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterReadOnlyData(FServerGetCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the title-specific custom data for the user's chjaracter which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterData(FServerUpdateCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the title-specific custom data for the user's character which cannot  be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterInternalData(FServerUpdateCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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

/** Updates the title-specific custom data for the user's character which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterReadOnlyData(FServerUpdateCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

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
