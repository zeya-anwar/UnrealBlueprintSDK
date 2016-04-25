//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Admin
// SDK Version: 0.0.160425
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabEnums.h"
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
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserAccountInfo(FAdminLookupUserAccountInfoRequest request,
    FDelegateOnSuccessGetUserAccountInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserAccountInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserAccountInfo);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserAccountInfo(FPlayFabBaseModel response, bool successful)
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
        FAdminLookupUserAccountInfoResult result = UPlayFabAdminModelDecoder::decodeLookupUserAccountInfoResultResponse(response.responseData);
        if (OnSuccessGetUserAccountInfo.IsBound())
        {
            OnSuccessGetUserAccountInfo.Execute(result);
        }
    }
}

/** Resets all title-specific information about a particular account, including user data, virtual currency balances, inventory, purchase history, and statistics */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetUsers(FAdminResetUsersRequest request,
    FDelegateOnSuccessResetUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessResetUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperResetUsers);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperResetUsers(FPlayFabBaseModel response, bool successful)
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
        FAdminBlankResult result = UPlayFabAdminModelDecoder::decodeBlankResultResponse(response.responseData);
        if (OnSuccessResetUsers.IsBound())
        {
            OnSuccessResetUsers.Execute(result);
        }
    }
}

/** Forces an email to be sent to the registered email address for the specified account, with a link allowing the user to change the password */
UPlayFabAdminAPI* UPlayFabAdminAPI::SendAccountRecoveryEmail(FAdminSendAccountRecoveryEmailRequest request,
    FDelegateOnSuccessSendAccountRecoveryEmail onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSendAccountRecoveryEmail = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSendAccountRecoveryEmail);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSendAccountRecoveryEmail(FPlayFabBaseModel response, bool successful)
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
        FAdminSendAccountRecoveryEmailResult result = UPlayFabAdminModelDecoder::decodeSendAccountRecoveryEmailResultResponse(response.responseData);
        if (OnSuccessSendAccountRecoveryEmail.IsBound())
        {
            OnSuccessSendAccountRecoveryEmail.Execute(result);
        }
    }
}

/** Updates the title specific display name for a user */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserTitleDisplayName(FAdminUpdateUserTitleDisplayNameRequest request,
    FDelegateOnSuccessUpdateUserTitleDisplayName onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserTitleDisplayName = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserTitleDisplayName);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserTitleDisplayName(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateUserTitleDisplayNameResult result = UPlayFabAdminModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(response.responseData);
        if (OnSuccessUpdateUserTitleDisplayName.IsBound())
        {
            OnSuccessUpdateUserTitleDisplayName.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Adds a new player statistic configuration to the title, optionally allowing the developer to specify a reset interval and an aggregation method. */
UPlayFabAdminAPI* UPlayFabAdminAPI::CreatePlayerStatisticDefinition(FAdminCreatePlayerStatisticDefinitionRequest request,
    FDelegateOnSuccessCreatePlayerStatisticDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessCreatePlayerStatisticDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperCreatePlayerStatisticDefinition);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/CreatePlayerStatisticDefinition";
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

    OutRestJsonObj->SetStringField(TEXT("VersionChangeInterval"), GetEnumValueToString<EStatisticResetIntervalOption>(TEXT("EStatisticResetIntervalOption"), request.VersionChangeInterval));
    OutRestJsonObj->SetStringField(TEXT("AggregationMethod"), GetEnumValueToString<EStatisticAggregationMethod>(TEXT("EStatisticAggregationMethod"), request.AggregationMethod));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperCreatePlayerStatisticDefinition(FPlayFabBaseModel response, bool successful)
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
        FAdminCreatePlayerStatisticDefinitionResult result = UPlayFabAdminModelDecoder::decodeCreatePlayerStatisticDefinitionResultResponse(response.responseData);
        if (OnSuccessCreatePlayerStatisticDefinition.IsBound())
        {
            OnSuccessCreatePlayerStatisticDefinition.Execute(result);
        }
    }
}

/** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteUsers(FAdminDeleteUsersRequest request,
    FDelegateOnSuccessDeleteUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessDeleteUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeleteUsers);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeleteUsers(FPlayFabBaseModel response, bool successful)
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
        FAdminDeleteUsersResult result = UPlayFabAdminModelDecoder::decodeDeleteUsersResultResponse(response.responseData);
        if (OnSuccessDeleteUsers.IsBound())
        {
            OnSuccessDeleteUsers.Execute(result);
        }
    }
}

/** Retrieves a download URL for the requested report */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetDataReport(FAdminGetDataReportRequest request,
    FDelegateOnSuccessGetDataReport onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetDataReport = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetDataReport);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetDataReport(FPlayFabBaseModel response, bool successful)
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
        FAdminGetDataReportResult result = UPlayFabAdminModelDecoder::decodeGetDataReportResultResponse(response.responseData);
        if (OnSuccessGetDataReport.IsBound())
        {
            OnSuccessGetDataReport.Execute(result);
        }
    }
}

/** Retrieves the configuration information for all player statistics defined in the title, regardless of whether they have a reset interval. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayerStatisticDefinitions(FAdminGetPlayerStatisticDefinitionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticDefinitions onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticDefinitions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayerStatisticDefinitions);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayerStatisticDefinitions";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayerStatisticDefinitions(FPlayFabBaseModel response, bool successful)
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
        FAdminGetPlayerStatisticDefinitionsResult result = UPlayFabAdminModelDecoder::decodeGetPlayerStatisticDefinitionsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatisticDefinitions.IsBound())
        {
            OnSuccessGetPlayerStatisticDefinitions.Execute(result);
        }
    }
}

/** Retrieves the information on the available versions of the specified statistic. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayerStatisticVersions(FAdminGetPlayerStatisticVersionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayerStatisticVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayerStatisticVersions";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, bool successful)
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
        FAdminGetPlayerStatisticVersionsResult result = UPlayFabAdminModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatisticVersions.IsBound())
        {
            OnSuccessGetPlayerStatisticVersions.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserData.IsBound())
        {
            OnSuccessGetUserData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserInternalData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserInternalData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserInternalData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserInternalData.IsBound())
        {
            OnSuccessGetUserInternalData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserPublisherData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserPublisherData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherData.IsBound())
        {
            OnSuccessGetUserPublisherData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherInternalData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserPublisherInternalData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserPublisherInternalData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherInternalData.IsBound())
        {
            OnSuccessGetUserPublisherInternalData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherReadOnlyData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserPublisherReadOnlyData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessGetUserPublisherReadOnlyData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserReadOnlyData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserReadOnlyData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserReadOnlyData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserReadOnlyData.IsBound())
        {
            OnSuccessGetUserReadOnlyData.Execute(result);
        }
    }
}

/** Resets the indicated statistic, removing all player entries for it and backing up the old values. */
UPlayFabAdminAPI* UPlayFabAdminAPI::IncrementPlayerStatisticVersion(FAdminIncrementPlayerStatisticVersionRequest request,
    FDelegateOnSuccessIncrementPlayerStatisticVersion onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessIncrementPlayerStatisticVersion = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperIncrementPlayerStatisticVersion);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/IncrementPlayerStatisticVersion";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperIncrementPlayerStatisticVersion(FPlayFabBaseModel response, bool successful)
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
        FAdminIncrementPlayerStatisticVersionResult result = UPlayFabAdminModelDecoder::decodeIncrementPlayerStatisticVersionResultResponse(response.responseData);
        if (OnSuccessIncrementPlayerStatisticVersion.IsBound())
        {
            OnSuccessIncrementPlayerStatisticVersion.Execute(result);
        }
    }
}

/** Completely removes all statistics for the specified user, for the current game */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetUserStatistics(FAdminResetUserStatisticsRequest request,
    FDelegateOnSuccessResetUserStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessResetUserStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperResetUserStatistics);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperResetUserStatistics(FPlayFabBaseModel response, bool successful)
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
        FAdminResetUserStatisticsResult result = UPlayFabAdminModelDecoder::decodeResetUserStatisticsResultResponse(response.responseData);
        if (OnSuccessResetUserStatistics.IsBound())
        {
            OnSuccessResetUserStatistics.Execute(result);
        }
    }
}

/** Updates a player statistic configuration for the title, optionally allowing the developer to specify a reset interval. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdatePlayerStatisticDefinition(FAdminUpdatePlayerStatisticDefinitionRequest request,
    FDelegateOnSuccessUpdatePlayerStatisticDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdatePlayerStatisticDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdatePlayerStatisticDefinition);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdatePlayerStatisticDefinition";
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

    OutRestJsonObj->SetStringField(TEXT("VersionChangeInterval"), GetEnumValueToString<EStatisticResetIntervalOption>(TEXT("EStatisticResetIntervalOption"), request.VersionChangeInterval));
    OutRestJsonObj->SetStringField(TEXT("AggregationMethod"), GetEnumValueToString<EStatisticAggregationMethod>(TEXT("EStatisticAggregationMethod"), request.AggregationMethod));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdatePlayerStatisticDefinition(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdatePlayerStatisticDefinitionResult result = UPlayFabAdminModelDecoder::decodeUpdatePlayerStatisticDefinitionResultResponse(response.responseData);
        if (OnSuccessUpdatePlayerStatisticDefinition.IsBound())
        {
            OnSuccessUpdatePlayerStatisticDefinition.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserData);

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

    OutRestJsonObj->SetStringField(TEXT("Permission"), GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserData(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserData.IsBound())
        {
            OnSuccessUpdateUserData.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserInternalData(FAdminUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserInternalData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserInternalData(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserInternalData.IsBound())
        {
            OnSuccessUpdateUserInternalData.Execute(result);
        }
    }
}

/** Updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserPublisherData);

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

    OutRestJsonObj->SetStringField(TEXT("Permission"), GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserPublisherData(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherData.IsBound())
        {
            OnSuccessUpdateUserPublisherData.Execute(result);
        }
    }
}

/** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherInternalData(FAdminUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserPublisherInternalData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherInternalData.IsBound())
        {
            OnSuccessUpdateUserPublisherInternalData.Execute(result);
        }
    }
}

/** Updates the publisher-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherReadOnlyData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserPublisherReadOnlyData);

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

    OutRestJsonObj->SetStringField(TEXT("Permission"), GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessUpdateUserPublisherReadOnlyData.Execute(result);
        }
    }
}

/** Updates the title-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserReadOnlyData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserReadOnlyData);

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

    OutRestJsonObj->SetStringField(TEXT("Permission"), GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission));

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserReadOnlyData.IsBound())
        {
            OnSuccessUpdateUserReadOnlyData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Adds a new news item to the title's news feed */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddNews(FAdminAddNewsRequest request,
    FDelegateOnSuccessAddNews onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddNews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddNews);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddNews(FPlayFabBaseModel response, bool successful)
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
        FAdminAddNewsResult result = UPlayFabAdminModelDecoder::decodeAddNewsResultResponse(response.responseData);
        if (OnSuccessAddNews.IsBound())
        {
            OnSuccessAddNews.Execute(result);
        }
    }
}

/** Adds one or more virtual currencies to the set defined for the title. Virtual Currencies have a maximum value of 2,147,483,647 when granted to a player. Any value over that will be discarded. */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddVirtualCurrencyTypes(FAdminAddVirtualCurrencyTypesRequest request,
    FDelegateOnSuccessAddVirtualCurrencyTypes onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddVirtualCurrencyTypes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddVirtualCurrencyTypes);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddVirtualCurrencyTypes(FPlayFabBaseModel response, bool successful)
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
        FAdminBlankResult result = UPlayFabAdminModelDecoder::decodeBlankResultResponse(response.responseData);
        if (OnSuccessAddVirtualCurrencyTypes.IsBound())
        {
            OnSuccessAddVirtualCurrencyTypes.Execute(result);
        }
    }
}

/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCatalogItems(FAdminGetCatalogItemsRequest request,
    FDelegateOnSuccessGetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetCatalogItems);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetCatalogItems(FPlayFabBaseModel response, bool successful)
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
        FAdminGetCatalogItemsResult result = UPlayFabAdminModelDecoder::decodeGetCatalogItemsResultResponse(response.responseData);
        if (OnSuccessGetCatalogItems.IsBound())
        {
            OnSuccessGetCatalogItems.Execute(result);
        }
    }
}

/** Retrieves the key-value store of custom publisher settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPublisherData(FAdminGetPublisherDataRequest request,
    FDelegateOnSuccessGetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPublisherData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPublisherData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetPublisherDataResult result = UPlayFabAdminModelDecoder::decodeGetPublisherDataResultResponse(response.responseData);
        if (OnSuccessGetPublisherData.IsBound())
        {
            OnSuccessGetPublisherData.Execute(result);
        }
    }
}

/** Retrieves the random drop table configuration for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetRandomResultTables(FAdminGetRandomResultTablesRequest request,
    FDelegateOnSuccessGetRandomResultTables onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetRandomResultTables = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetRandomResultTables);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetRandomResultTables(FPlayFabBaseModel response, bool successful)
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
        FAdminGetRandomResultTablesResult result = UPlayFabAdminModelDecoder::decodeGetRandomResultTablesResultResponse(response.responseData);
        if (OnSuccessGetRandomResultTables.IsBound())
        {
            OnSuccessGetRandomResultTables.Execute(result);
        }
    }
}

/** Retrieves the set of items defined for the specified store, including all prices defined */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetStoreItems(FAdminGetStoreItemsRequest request,
    FDelegateOnSuccessGetStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetStoreItems);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetStoreItems(FPlayFabBaseModel response, bool successful)
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
        FAdminGetStoreItemsResult result = UPlayFabAdminModelDecoder::decodeGetStoreItemsResultResponse(response.responseData);
        if (OnSuccessGetStoreItems.IsBound())
        {
            OnSuccessGetStoreItems.Execute(result);
        }
    }
}

/** Retrieves the key-value store of custom title settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetTitleData(FAdminGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetTitleData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetTitleData(FPlayFabBaseModel response, bool successful)
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
        FAdminGetTitleDataResult result = UPlayFabAdminModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        if (OnSuccessGetTitleData.IsBound())
        {
            OnSuccessGetTitleData.Execute(result);
        }
    }
}

/** Retuns the list of all defined virtual currencies for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::ListVirtualCurrencyTypes(FAdminListVirtualCurrencyTypesRequest request,
    FDelegateOnSuccessListVirtualCurrencyTypes onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessListVirtualCurrencyTypes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperListVirtualCurrencyTypes);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ListVirtualCurrencyTypes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperListVirtualCurrencyTypes(FPlayFabBaseModel response, bool successful)
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
        FAdminListVirtualCurrencyTypesResult result = UPlayFabAdminModelDecoder::decodeListVirtualCurrencyTypesResultResponse(response.responseData);
        if (OnSuccessListVirtualCurrencyTypes.IsBound())
        {
            OnSuccessListVirtualCurrencyTypes.Execute(result);
        }
    }
}

/** Creates the catalog configuration of all virtual goods for the specified catalog version */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetCatalogItems(FAdminUpdateCatalogItemsRequest request,
    FDelegateOnSuccessSetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetCatalogItems);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetCatalogItems(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateCatalogItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateCatalogItemsResultResponse(response.responseData);
        if (OnSuccessSetCatalogItems.IsBound())
        {
            OnSuccessSetCatalogItems.Execute(result);
        }
    }
}

/** Sets all the items in one virtual store */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetStoreItems(FAdminUpdateStoreItemsRequest request,
    FDelegateOnSuccessSetStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetStoreItems);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetStoreItems(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateStoreItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateStoreItemsResultResponse(response.responseData);
        if (OnSuccessSetStoreItems.IsBound())
        {
            OnSuccessSetStoreItems.Execute(result);
        }
    }
}

/** Creates and updates the key-value store of custom title settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetTitleData(FAdminSetTitleDataRequest request,
    FDelegateOnSuccessSetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetTitleData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetTitleData(FPlayFabBaseModel response, bool successful)
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
        FAdminSetTitleDataResult result = UPlayFabAdminModelDecoder::decodeSetTitleDataResultResponse(response.responseData);
        if (OnSuccessSetTitleData.IsBound())
        {
            OnSuccessSetTitleData.Execute(result);
        }
    }
}

/** Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the exact restrictions can be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html. Currently, Amazon device Messaging is not supported. */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetupPushNotification(FAdminSetupPushNotificationRequest request,
    FDelegateOnSuccessSetupPushNotification onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetupPushNotification = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetupPushNotification);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetupPushNotification(FPlayFabBaseModel response, bool successful)
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
        FAdminSetupPushNotificationResult result = UPlayFabAdminModelDecoder::decodeSetupPushNotificationResultResponse(response.responseData);
        if (OnSuccessSetupPushNotification.IsBound())
        {
            OnSuccessSetupPushNotification.Execute(result);
        }
    }
}

/** Updates the catalog configuration for virtual goods in the specified catalog version */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateCatalogItems(FAdminUpdateCatalogItemsRequest request,
    FDelegateOnSuccessUpdateCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateCatalogItems);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateCatalogItems(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateCatalogItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateCatalogItemsResultResponse(response.responseData);
        if (OnSuccessUpdateCatalogItems.IsBound())
        {
            OnSuccessUpdateCatalogItems.Execute(result);
        }
    }
}

/** Updates the random drop table configuration for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateRandomResultTables(FAdminUpdateRandomResultTablesRequest request,
    FDelegateOnSuccessUpdateRandomResultTables onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateRandomResultTables = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateRandomResultTables);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateRandomResultTables(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateRandomResultTablesResult result = UPlayFabAdminModelDecoder::decodeUpdateRandomResultTablesResultResponse(response.responseData);
        if (OnSuccessUpdateRandomResultTables.IsBound())
        {
            OnSuccessUpdateRandomResultTables.Execute(result);
        }
    }
}

/** Updates an existing virtual item store with new or modified items */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateStoreItems(FAdminUpdateStoreItemsRequest request,
    FDelegateOnSuccessUpdateStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateStoreItems);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateStoreItems(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateStoreItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateStoreItemsResultResponse(response.responseData);
        if (OnSuccessUpdateStoreItems.IsBound())
        {
            OnSuccessUpdateStoreItems.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments the specified virtual currency by the stated amount */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddUserVirtualCurrency(FAdminAddUserVirtualCurrencyRequest request,
    FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddUserVirtualCurrency);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddUserVirtualCurrency(FPlayFabBaseModel response, bool successful)
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
        FAdminModifyUserVirtualCurrencyResult result = UPlayFabAdminModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessAddUserVirtualCurrency.IsBound())
        {
            OnSuccessAddUserVirtualCurrency.Execute(result);
        }
    }
}

/** Retrieves the specified user's current inventory of virtual goods */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserInventory(FAdminGetUserInventoryRequest request,
    FDelegateOnSuccessGetUserInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserInventory);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserInventory(FPlayFabBaseModel response, bool successful)
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
        FAdminGetUserInventoryResult result = UPlayFabAdminModelDecoder::decodeGetUserInventoryResultResponse(response.responseData);
        if (OnSuccessGetUserInventory.IsBound())
        {
            OnSuccessGetUserInventory.Execute(result);
        }
    }
}

/** Adds the specified items to the specified user inventories */
UPlayFabAdminAPI* UPlayFabAdminAPI::GrantItemsToUsers(FAdminGrantItemsToUsersRequest request,
    FDelegateOnSuccessGrantItemsToUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGrantItemsToUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGrantItemsToUsers);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGrantItemsToUsers(FPlayFabBaseModel response, bool successful)
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
        FAdminGrantItemsToUsersResult result = UPlayFabAdminModelDecoder::decodeGrantItemsToUsersResultResponse(response.responseData);
        if (OnSuccessGrantItemsToUsers.IsBound())
        {
            OnSuccessGrantItemsToUsers.Execute(result);
        }
    }
}

/** Revokes access to an item in a user's inventory */
UPlayFabAdminAPI* UPlayFabAdminAPI::RevokeInventoryItem(FAdminRevokeInventoryItemRequest request,
    FDelegateOnSuccessRevokeInventoryItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRevokeInventoryItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRevokeInventoryItem);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRevokeInventoryItem(FPlayFabBaseModel response, bool successful)
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
        FAdminRevokeInventoryResult result = UPlayFabAdminModelDecoder::decodeRevokeInventoryResultResponse(response.responseData);
        if (OnSuccessRevokeInventoryItem.IsBound())
        {
            OnSuccessRevokeInventoryItem.Execute(result);
        }
    }
}

/** Decrements the specified virtual currency by the stated amount */
UPlayFabAdminAPI* UPlayFabAdminAPI::SubtractUserVirtualCurrency(FAdminSubtractUserVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSubtractUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSubtractUserVirtualCurrency);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, bool successful)
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
        FAdminModifyUserVirtualCurrencyResult result = UPlayFabAdminModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessSubtractUserVirtualCurrency.IsBound())
        {
            OnSuccessSubtractUserVirtualCurrency.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Retrieves the details for a specific completed session, including links to standard out and standard error logs */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetMatchmakerGameInfo(FAdminGetMatchmakerGameInfoRequest request,
    FDelegateOnSuccessGetMatchmakerGameInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetMatchmakerGameInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetMatchmakerGameInfo);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetMatchmakerGameInfo(FPlayFabBaseModel response, bool successful)
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
        FAdminGetMatchmakerGameInfoResult result = UPlayFabAdminModelDecoder::decodeGetMatchmakerGameInfoResultResponse(response.responseData);
        if (OnSuccessGetMatchmakerGameInfo.IsBound())
        {
            OnSuccessGetMatchmakerGameInfo.Execute(result);
        }
    }
}

/** Retrieves the details of defined game modes for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetMatchmakerGameModes(FAdminGetMatchmakerGameModesRequest request,
    FDelegateOnSuccessGetMatchmakerGameModes onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetMatchmakerGameModes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetMatchmakerGameModes);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetMatchmakerGameModes(FPlayFabBaseModel response, bool successful)
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
        FAdminGetMatchmakerGameModesResult result = UPlayFabAdminModelDecoder::decodeGetMatchmakerGameModesResultResponse(response.responseData);
        if (OnSuccessGetMatchmakerGameModes.IsBound())
        {
            OnSuccessGetMatchmakerGameModes.Execute(result);
        }
    }
}

/** Updates the game server mode details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::ModifyMatchmakerGameModes(FAdminModifyMatchmakerGameModesRequest request,
    FDelegateOnSuccessModifyMatchmakerGameModes onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessModifyMatchmakerGameModes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperModifyMatchmakerGameModes);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperModifyMatchmakerGameModes(FPlayFabBaseModel response, bool successful)
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
        FAdminModifyMatchmakerGameModesResult result = UPlayFabAdminModelDecoder::decodeModifyMatchmakerGameModesResultResponse(response.responseData);
        if (OnSuccessModifyMatchmakerGameModes.IsBound())
        {
            OnSuccessModifyMatchmakerGameModes.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Custom Server Management
//////////////////////////////////////////////////////
/** Adds the game server executable specified (previously uploaded - see GetServerBuildUploadUrl) to the set of those a client is permitted to request in a call to StartGame */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddServerBuild(FAdminAddServerBuildRequest request,
    FDelegateOnSuccessAddServerBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddServerBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddServerBuild);

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
    OutRestJsonObj->SetNumberField(TEXT("MinFreeGameSlots"), request.MinFreeGameSlots);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddServerBuild(FPlayFabBaseModel response, bool successful)
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
        FAdminAddServerBuildResult result = UPlayFabAdminModelDecoder::decodeAddServerBuildResultResponse(response.responseData);
        if (OnSuccessAddServerBuild.IsBound())
        {
            OnSuccessAddServerBuild.Execute(result);
        }
    }
}

/** Retrieves the build details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetServerBuildInfo(FAdminGetServerBuildInfoRequest request,
    FDelegateOnSuccessGetServerBuildInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetServerBuildInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetServerBuildInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetServerBuildInfo";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetServerBuildInfo(FPlayFabBaseModel response, bool successful)
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
        FAdminGetServerBuildInfoResult result = UPlayFabAdminModelDecoder::decodeGetServerBuildInfoResultResponse(response.responseData);
        if (OnSuccessGetServerBuildInfo.IsBound())
        {
            OnSuccessGetServerBuildInfo.Execute(result);
        }
    }
}

/** Retrieves the pre-authorized URL for uploading a game server package containing a build (does not enable the build for use - see AddServerBuild) */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetServerBuildUploadUrl(FAdminGetServerBuildUploadURLRequest request,
    FDelegateOnSuccessGetServerBuildUploadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetServerBuildUploadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetServerBuildUploadUrl);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetServerBuildUploadUrl(FPlayFabBaseModel response, bool successful)
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
        FAdminGetServerBuildUploadURLResult result = UPlayFabAdminModelDecoder::decodeGetServerBuildUploadURLResultResponse(response.responseData);
        if (OnSuccessGetServerBuildUploadUrl.IsBound())
        {
            OnSuccessGetServerBuildUploadUrl.Execute(result);
        }
    }
}

/** Retrieves the build details for all game server executables which are currently defined for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::ListServerBuilds(FAdminListBuildsRequest request,
    FDelegateOnSuccessListServerBuilds onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessListServerBuilds = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperListServerBuilds);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ListServerBuilds";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperListServerBuilds(FPlayFabBaseModel response, bool successful)
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
        FAdminListBuildsResult result = UPlayFabAdminModelDecoder::decodeListBuildsResultResponse(response.responseData);
        if (OnSuccessListServerBuilds.IsBound())
        {
            OnSuccessListServerBuilds.Execute(result);
        }
    }
}

/** Updates the build details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::ModifyServerBuild(FAdminModifyServerBuildRequest request,
    FDelegateOnSuccessModifyServerBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessModifyServerBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperModifyServerBuild);

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
    OutRestJsonObj->SetNumberField(TEXT("MinFreeGameSlots"), request.MinFreeGameSlots);
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperModifyServerBuild(FPlayFabBaseModel response, bool successful)
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
        FAdminModifyServerBuildResult result = UPlayFabAdminModelDecoder::decodeModifyServerBuildResultResponse(response.responseData);
        if (OnSuccessModifyServerBuild.IsBound())
        {
            OnSuccessModifyServerBuild.Execute(result);
        }
    }
}

/** Removes the game server executable specified from the set of those a client is permitted to request in a call to StartGame */
UPlayFabAdminAPI* UPlayFabAdminAPI::RemoveServerBuild(FAdminRemoveServerBuildRequest request,
    FDelegateOnSuccessRemoveServerBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRemoveServerBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRemoveServerBuild);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRemoveServerBuild(FPlayFabBaseModel response, bool successful)
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
        FAdminRemoveServerBuildResult result = UPlayFabAdminModelDecoder::decodeRemoveServerBuildResultResponse(response.responseData);
        if (OnSuccessRemoveServerBuild.IsBound())
        {
            OnSuccessRemoveServerBuild.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Updates the key-value store of custom publisher settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetPublisherData(FAdminSetPublisherDataRequest request,
    FDelegateOnSuccessSetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetPublisherData);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetPublisherData(FPlayFabBaseModel response, bool successful)
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
        FAdminSetPublisherDataResult result = UPlayFabAdminModelDecoder::decodeSetPublisherDataResultResponse(response.responseData);
        if (OnSuccessSetPublisherData.IsBound())
        {
            OnSuccessSetPublisherData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Gets the contents and information of a specific Cloud Script revision. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCloudScriptRevision(FAdminGetCloudScriptRevisionRequest request,
    FDelegateOnSuccessGetCloudScriptRevision onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCloudScriptRevision = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetCloudScriptRevision);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetCloudScriptRevision(FPlayFabBaseModel response, bool successful)
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
        FAdminGetCloudScriptRevisionResult result = UPlayFabAdminModelDecoder::decodeGetCloudScriptRevisionResultResponse(response.responseData);
        if (OnSuccessGetCloudScriptRevision.IsBound())
        {
            OnSuccessGetCloudScriptRevision.Execute(result);
        }
    }
}

/** Lists all the current cloud script versions. For each version, information about the current published and latest revisions is also listed. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCloudScriptVersions(FAdminGetCloudScriptVersionsRequest request,
    FDelegateOnSuccessGetCloudScriptVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCloudScriptVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetCloudScriptVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCloudScriptVersions";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetCloudScriptVersions(FPlayFabBaseModel response, bool successful)
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
        FAdminGetCloudScriptVersionsResult result = UPlayFabAdminModelDecoder::decodeGetCloudScriptVersionsResultResponse(response.responseData);
        if (OnSuccessGetCloudScriptVersions.IsBound())
        {
            OnSuccessGetCloudScriptVersions.Execute(result);
        }
    }
}

/** Sets the currently published revision of a title Cloud Script */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetPublishedRevision(FAdminSetPublishedRevisionRequest request,
    FDelegateOnSuccessSetPublishedRevision onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetPublishedRevision = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetPublishedRevision);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetPublishedRevision(FPlayFabBaseModel response, bool successful)
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
        FAdminSetPublishedRevisionResult result = UPlayFabAdminModelDecoder::decodeSetPublishedRevisionResultResponse(response.responseData);
        if (OnSuccessSetPublishedRevision.IsBound())
        {
            OnSuccessSetPublishedRevision.Execute(result);
        }
    }
}

/** Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one file should be submitted in the revision. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateCloudScript(FAdminUpdateCloudScriptRequest request,
    FDelegateOnSuccessUpdateCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateCloudScript);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateCloudScript";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetObjectArrayField(TEXT("Files"), request.Files);
    OutRestJsonObj->SetBoolField(TEXT("Publish"), request.Publish);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateCloudScript(FPlayFabBaseModel response, bool successful)
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
        FAdminUpdateCloudScriptResult result = UPlayFabAdminModelDecoder::decodeUpdateCloudScriptResultResponse(response.responseData);
        if (OnSuccessUpdateCloudScript.IsBound())
        {
            OnSuccessUpdateCloudScript.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** Delete a content file from the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteContent(FAdminDeleteContentRequest request,
    FDelegateOnSuccessDeleteContent onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessDeleteContent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeleteContent);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeleteContent(FPlayFabBaseModel response, bool successful)
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
        FAdminBlankResult result = UPlayFabAdminModelDecoder::decodeBlankResultResponse(response.responseData);
        if (OnSuccessDeleteContent.IsBound())
        {
            OnSuccessDeleteContent.Execute(result);
        }
    }
}

/** List all contents of the title and get statistics such as size */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetContentList(FAdminGetContentListRequest request,
    FDelegateOnSuccessGetContentList onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetContentList = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetContentList);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetContentList(FPlayFabBaseModel response, bool successful)
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
        FAdminGetContentListResult result = UPlayFabAdminModelDecoder::decodeGetContentListResultResponse(response.responseData);
        if (OnSuccessGetContentList.IsBound())
        {
            OnSuccessGetContentList.Execute(result);
        }
    }
}

/** Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned URL uploads the content. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetContentUploadUrl(FAdminGetContentUploadUrlRequest request,
    FDelegateOnSuccessGetContentUploadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetContentUploadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetContentUploadUrl);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetContentUploadUrl(FPlayFabBaseModel response, bool successful)
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
        FAdminGetContentUploadUrlResult result = UPlayFabAdminModelDecoder::decodeGetContentUploadUrlResultResponse(response.responseData);
        if (OnSuccessGetContentUploadUrl.IsBound())
        {
            OnSuccessGetContentUploadUrl.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Completely removes all statistics for the specified character, for the current game */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetCharacterStatistics(FAdminResetCharacterStatisticsRequest request,
    FDelegateOnSuccessResetCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessResetCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperResetCharacterStatistics);

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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperResetCharacterStatistics(FPlayFabBaseModel response, bool successful)
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
        FAdminResetCharacterStatisticsResult result = UPlayFabAdminModelDecoder::decodeResetCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessResetCharacterStatistics.IsBound())
        {
            OnSuccessResetCharacterStatistics.Execute(result);
        }
    }
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
