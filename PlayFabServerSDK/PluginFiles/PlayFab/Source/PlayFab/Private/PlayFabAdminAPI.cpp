//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Admin
// API Version: 1.9.20151109
// SDK Version: 0.0.151019
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabAdminAPI.h"

UPlayFabAdminAPI* Admin_proxy = NULL;

UPlayFabAdminAPI::UPlayFabAdminAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    Admin_proxy = this;
}

void UPlayFabAdminAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabAdminAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabAdminAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Admin API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Retrieves the relevant details for a specified user, based upon a match against a supplied unique identifier */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserAccountInfo(FAdminLookupUserAccountInfoRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserAccountInfo";
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

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.TitleDisplayName.IsEmpty() || request.TitleDisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TitleDisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), request.TitleDisplayName);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Resets all title-specific information about a particular account, including user data, virtual currency balances, inventory, purchase history, and statistics */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetUsers(FAdminResetUsersRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ResetUsers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetObjectArrayField(TEXT("Users"), request.Users);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Forces an email to be sent to the registered email address for the specified account, with a link allowing the user to change the password */
UPlayFabAdminAPI* UPlayFabAdminAPI::SendAccountRecoveryEmail(FAdminSendAccountRecoveryEmailRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SendAccountRecoveryEmail";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the title specific display name for a user */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserTitleDisplayName(FAdminUpdateUserTitleDisplayNameRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserTitleDisplayName";
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

    if (request.DisplayName.IsEmpty() || request.DisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DisplayName"), request.DisplayName);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteUsers(FAdminDeleteUsersRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeleteUsers";
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

/** Retrieves a download URL for the requested report */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetDataReport(FAdminGetDataReportRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetDataReport";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.ReportName.IsEmpty() || request.ReportName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReportName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReportName"), request.ReportName);
    }

    OutRestJsonObj->SetNumberField(TEXT("Year"), request.Year);
    OutRestJsonObj->SetNumberField(TEXT("Month"), request.Month);
    OutRestJsonObj->SetNumberField(TEXT("Day"), request.Day);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserData(FAdminGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserInternalData(FAdminGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserInternalData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherData(FAdminGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserPublisherData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherInternalData(FAdminGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserPublisherInternalData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherReadOnlyData(FAdminGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserPublisherReadOnlyData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserReadOnlyData(FAdminGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserReadOnlyData";
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

/** Completely removes all statistics for the specified user, for the current game */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetUserStatistics(FAdminResetUserStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ResetUserStatistics";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserData(FAdminUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserInternalData(FAdminUpdateUserInternalDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserInternalData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherData(FAdminUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserPublisherData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherInternalData(FAdminUpdateUserInternalDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserPublisherInternalData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherReadOnlyData(FAdminUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserPublisherReadOnlyData";
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
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserReadOnlyData(FAdminUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserReadOnlyData";
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


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Adds a new news item to the title's news feed */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddNews(FAdminAddNewsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddNews";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Timestamp.IsEmpty() || request.Timestamp == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }

    if (request.Title.IsEmpty() || request.Title == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Title"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Title"), request.Title);
    }

    if (request.Body.IsEmpty() || request.Body == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Body"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Body"), request.Body);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Adds one or more virtual currencies to the set defined for the title. Virtual Currencies have a maximum value of 2,147,483,647 when granted to a player. Any value over that will be discarded. */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddVirtualCurrencyTypes(FAdminAddVirtualCurrencyTypesRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddVirtualCurrencyTypes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetObjectArrayField(TEXT("VirtualCurrencies"), request.VirtualCurrencies);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCatalogItems(FAdminGetCatalogItemsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCatalogItems";
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

/** Retrieves the random drop table configuration for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetRandomResultTables(FAdminGetRandomResultTablesRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetRandomResultTables";
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

/** Retrieves the set of items defined for the specified store, including all prices defined */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetStoreItems(FAdminGetStoreItemsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetStoreItems";
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

    if (request.StoreId.IsEmpty() || request.StoreId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the key-value store of custom title settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetTitleData(FAdminGetTitleDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetTitleData";
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

/** Retuns the list of all defined virtual currencies for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::ListVirtualCurrencyTypes(FAdminListVirtualCurrencyTypesRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ListVirtualCurrencyTypes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Creates the catalog configuration of all virtual goods for the specified catalog version */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetCatalogItems(FAdminUpdateCatalogItemsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetCatalogItems";
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

    OutRestJsonObj->SetObjectArrayField(TEXT("Catalog"), request.Catalog);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Sets all the items in one virtual store */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetStoreItems(FAdminUpdateStoreItemsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetStoreItems";
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

    if (request.StoreId.IsEmpty() || request.StoreId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    OutRestJsonObj->SetObjectArrayField(TEXT("Store"), request.Store);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Creates and updates the key-value store of custom title settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetTitleData(FAdminSetTitleDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetTitleData";
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

/** Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the exact restrictions can be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html. Currently, Amazon device Messaging is not supported. */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetupPushNotification(FAdminSetupPushNotificationRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetupPushNotification";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Name.IsEmpty() || request.Name == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }

    if (request.Platform.IsEmpty() || request.Platform == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Platform"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Platform"), request.Platform);
    }

    if (request.Key.IsEmpty() || request.Key == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }

    if (request.Credential.IsEmpty() || request.Credential == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Credential"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Credential"), request.Credential);
    }

    OutRestJsonObj->SetBoolField(TEXT("OverwriteOldARN"), request.OverwriteOldARN);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the catalog configuration for virtual goods in the specified catalog version */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateCatalogItems(FAdminUpdateCatalogItemsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateCatalogItems";
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

    OutRestJsonObj->SetObjectArrayField(TEXT("Catalog"), request.Catalog);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the random drop table configuration for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateRandomResultTables(FAdminUpdateRandomResultTablesRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateRandomResultTables";
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

    OutRestJsonObj->SetObjectArrayField(TEXT("Tables"), request.Tables);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates an existing virtual item store with new or modified items */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateStoreItems(FAdminUpdateStoreItemsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateStoreItems";
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

    if (request.StoreId.IsEmpty() || request.StoreId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    OutRestJsonObj->SetObjectArrayField(TEXT("Store"), request.Store);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments the specified virtual currency by the stated amount */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddUserVirtualCurrency(FAdminAddUserVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddUserVirtualCurrency";
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

/** Retrieves the specified user's current inventory of virtual goods */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserInventory(FAdminGetUserInventoryRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserInventory";
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

/** Adds the specified items to the specified user inventories */
UPlayFabAdminAPI* UPlayFabAdminAPI::GrantItemsToUsers(FAdminGrantItemsToUsersRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GrantItemsToUsers";
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

/** Revokes access to an item in a user's inventory */
UPlayFabAdminAPI* UPlayFabAdminAPI::RevokeInventoryItem(FAdminRevokeInventoryItemRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RevokeInventoryItem";
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

/** Decrements the specified virtual currency by the stated amount */
UPlayFabAdminAPI* UPlayFabAdminAPI::SubtractUserVirtualCurrency(FAdminSubtractUserVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SubtractUserVirtualCurrency";
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


///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Retrieves the details for a specific completed session, including links to standard out and standard error logs */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetMatchmakerGameInfo(FAdminGetMatchmakerGameInfoRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetMatchmakerGameInfo";
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



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the details of defined game modes for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetMatchmakerGameModes(FAdminGetMatchmakerGameModesRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetMatchmakerGameModes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the game server mode details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::ModifyMatchmakerGameModes(FAdminModifyMatchmakerGameModesRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ModifyMatchmakerGameModes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    OutRestJsonObj->SetObjectArrayField(TEXT("GameModes"), request.GameModes);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Custom Server Management
//////////////////////////////////////////////////////
/** Adds the game server executable specified (previously uploaded - see GetServerBuildUploadUrl) to the set of those a client is permitted to request in a call to StartGame */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddServerBuild(FAdminAddServerBuildRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddServerBuild";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.BuildId.IsEmpty() || request.BuildId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }

    if (request.CommandLineTemplate.IsEmpty() || request.CommandLineTemplate == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CommandLineTemplate"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CommandLineTemplate"), request.CommandLineTemplate);
    }

    if (request.ExecutablePath.IsEmpty() || request.ExecutablePath == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ExecutablePath"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ExecutablePath"), request.ExecutablePath);
    }

    // Check to see if string is empty
    if (request.ActiveRegions.IsEmpty() || request.ActiveRegions == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ActiveRegions"));
    }
    else
    {
        TArray<FString> ActiveRegionsArray;
        FString(request.ActiveRegions).ParseIntoArray(ActiveRegionsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ActiveRegions"), ActiveRegionsArray);
    }

    if (request.Comment.IsEmpty() || request.Comment == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Comment"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Comment"), request.Comment);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxGamesPerHost"), request.MaxGamesPerHost);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the build details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetServerBuildInfo(FAdminGetServerBuildInfoRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetServerBuildInfo";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;


    // Setup request object
    if (request.BuildId.IsEmpty() || request.BuildId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the pre-authorized URL for uploading a game server package containing a build (does not enable the build for use - see AddServerBuild) */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetServerBuildUploadUrl(FAdminGetServerBuildUploadURLRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetServerBuildUploadUrl";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.BuildId.IsEmpty() || request.BuildId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the build details for all game server executables which are currently defined for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::ListServerBuilds(FAdminListBuildsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ListServerBuilds";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the build details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::ModifyServerBuild(FAdminModifyServerBuildRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ModifyServerBuild";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.BuildId.IsEmpty() || request.BuildId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }

    if (request.Timestamp.IsEmpty() || request.Timestamp == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }

    // Check to see if string is empty
    if (request.ActiveRegions.IsEmpty() || request.ActiveRegions == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ActiveRegions"));
    }
    else
    {
        TArray<FString> ActiveRegionsArray;
        FString(request.ActiveRegions).ParseIntoArray(ActiveRegionsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ActiveRegions"), ActiveRegionsArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxGamesPerHost"), request.MaxGamesPerHost);
    if (request.CommandLineTemplate.IsEmpty() || request.CommandLineTemplate == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CommandLineTemplate"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CommandLineTemplate"), request.CommandLineTemplate);
    }

    if (request.ExecutablePath.IsEmpty() || request.ExecutablePath == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ExecutablePath"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ExecutablePath"), request.ExecutablePath);
    }

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

/** Removes the game server executable specified from the set of those a client is permitted to request in a call to StartGame */
UPlayFabAdminAPI* UPlayFabAdminAPI::RemoveServerBuild(FAdminRemoveServerBuildRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RemoveServerBuild";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.BuildId.IsEmpty() || request.BuildId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Retrieves the key-value store of custom publisher settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPublisherData(FAdminGetPublisherDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPublisherData";
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

/** Updates the key-value store of custom publisher settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetPublisherData(FAdminSetPublisherDataRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetPublisherData";
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
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Gets the contents and information of a specific Cloud Script revision. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCloudScriptRevision(FAdminGetCloudScriptRevisionRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCloudScriptRevision";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetNumberField(TEXT("Revision"), request.Revision);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Lists all the current cloud script versions. For each version, information about the current published and latest revisions is also listed. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCloudScriptVersions(FAdminGetCloudScriptVersionsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCloudScriptVersions";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Sets the currently published revision of a title Cloud Script */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetPublishedRevision(FAdminSetPublishedRevisionRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetPublishedRevision";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetNumberField(TEXT("Revision"), request.Revision);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one file should be submitted in the revision. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateCloudScript(FAdminUpdateCloudScriptRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateCloudScript";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetObjectArrayField(TEXT("Files"), request.Files);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** Delete a content file from the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteContent(FAdminDeleteContentRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeleteContent";
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



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** List all contents of the title and get statistics such as size */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetContentList(FAdminGetContentListRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetContentList";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Prefix.IsEmpty() || request.Prefix == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Prefix"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Prefix"), request.Prefix);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned URL uploads the content. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetContentUploadUrl(FAdminGetContentUploadUrlRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetContentUploadUrl";
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

    if (request.ContentType.IsEmpty() || request.ContentType == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ContentType"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ContentType"), request.ContentType);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Completely removes all statistics for the specified character, for the current game */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetCharacterStatistics(FAdminResetCharacterStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ResetCharacterStatistics";
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



void UPlayFabAdminAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

        Admin_proxy->OnPlayFabResponse.Broadcast(myResponse, false);

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

    if (isLoginRequest) IPlayFab::Get().setSessionTicket(myResponse.responseData->GetObjectField("data")->GetStringField("SessionTicket"));

    // Broadcast the result event
    Admin_proxy->OnPlayFabResponse.Broadcast(myResponse, true);
}

void UPlayFabAdminAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabAdminAPI::OnProcessRequestComplete);

    // Execute the request
    HttpRequest->ProcessRequest();
}

void UPlayFabAdminAPI::ResetResponseData()
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