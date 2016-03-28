//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Client
// SDK Version: 0.0.160328
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabClientAPI.h"

UPlayFabClientAPI* Client_proxy = NULL;

UPlayFabClientAPI::UPlayFabClientAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    Client_proxy = this;
}

void UPlayFabClientAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabClientAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabClientAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Client API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////
/** Gets a Photon custom authentication token that can be used to securely join the player into a Photon room. See https://api.playfab.com/docs/using-photon-with-playfab/ for more details. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPhotonAuthenticationToken(FClientGetPhotonAuthenticationTokenRequest request,
    FDelegateOnSuccessGetPhotonAuthenticationToken onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPhotonAuthenticationToken = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPhotonAuthenticationToken);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPhotonAuthenticationToken";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.PhotonApplicationId.IsEmpty() || request.PhotonApplicationId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PhotonApplicationId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PhotonApplicationId"), request.PhotonApplicationId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPhotonAuthenticationToken(FPlayFabBaseModel response, bool successful)
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
        FClientGetPhotonAuthenticationTokenResult result = UPlayFabClientModelDecoder::decodeGetPhotonAuthenticationTokenResultResponse(response.responseData);
        if (OnSuccessGetPhotonAuthenticationToken.IsBound())
        {
            OnSuccessGetPhotonAuthenticationToken.Execute(result);
        }
    }
}

/** Signs the user in using the Android device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithAndroidDeviceID(FClientLoginWithAndroidDeviceIDRequest request,
    FDelegateOnSuccessLoginWithAndroidDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithAndroidDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithAndroidDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithAndroidDeviceID";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.AndroidDevice.IsEmpty() || request.AndroidDevice == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDevice"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), request.AndroidDevice);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithAndroidDeviceID(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithAndroidDeviceID.IsBound())
        {
            OnSuccessLoginWithAndroidDeviceID.Execute(result);
        }
    }
}

/** Signs the user in using a custom unique identifier generated by the title, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithCustomID(FClientLoginWithCustomIDRequest request,
    FDelegateOnSuccessLoginWithCustomID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithCustomID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithCustomID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithCustomID";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.CustomId.IsEmpty() || request.CustomId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithCustomID(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithCustomID.IsBound())
        {
            OnSuccessLoginWithCustomID.Execute(result);
        }
    }
}

/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithEmailAddress(FClientLoginWithEmailAddressRequest request,
    FDelegateOnSuccessLoginWithEmailAddress onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithEmailAddress = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithEmailAddress);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithEmailAddress";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithEmailAddress(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithEmailAddress.IsBound())
        {
            OnSuccessLoginWithEmailAddress.Execute(result);
        }
    }
}

/** Signs the user in using a Facebook access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithFacebook(FClientLoginWithFacebookRequest request,
    FDelegateOnSuccessLoginWithFacebook onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithFacebook = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithFacebook);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithFacebook";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithFacebook(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithFacebook.IsBound())
        {
            OnSuccessLoginWithFacebook.Execute(result);
        }
    }
}

/** Signs the user in using an iOS Game Center player identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithGameCenter(FClientLoginWithGameCenterRequest request,
    FDelegateOnSuccessLoginWithGameCenter onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithGameCenter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithGameCenter);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithGameCenter";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.PlayerId.IsEmpty() || request.PlayerId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayerId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayerId"), request.PlayerId);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithGameCenter(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithGameCenter.IsBound())
        {
            OnSuccessLoginWithGameCenter.Execute(result);
        }
    }
}

/** Signs the user in using a Google account access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithGoogleAccount(FClientLoginWithGoogleAccountRequest request,
    FDelegateOnSuccessLoginWithGoogleAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithGoogleAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithGoogleAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithGoogleAccount";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.PublisherId.IsEmpty() || request.PublisherId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PublisherId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PublisherId"), request.PublisherId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithGoogleAccount(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithGoogleAccount.IsBound())
        {
            OnSuccessLoginWithGoogleAccount.Execute(result);
        }
    }
}

/** Signs the user in using the vendor-specific iOS device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithIOSDeviceID(FClientLoginWithIOSDeviceIDRequest request,
    FDelegateOnSuccessLoginWithIOSDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithIOSDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithIOSDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithIOSDeviceID";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.DeviceId.IsEmpty() || request.DeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.DeviceModel.IsEmpty() || request.DeviceModel == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceModel"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceModel"), request.DeviceModel);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithIOSDeviceID(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithIOSDeviceID.IsBound())
        {
            OnSuccessLoginWithIOSDeviceID.Execute(result);
        }
    }
}

/** Signs the user in using a Kongregate player account. */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithKongregate(FClientLoginWithKongregateRequest request,
    FDelegateOnSuccessLoginWithKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithKongregate);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithKongregate";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.KongregateId.IsEmpty() || request.KongregateId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("KongregateId"), request.KongregateId);
    }

    if (request.AuthTicket.IsEmpty() || request.AuthTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthTicket"), request.AuthTicket);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithKongregate(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithKongregate.IsBound())
        {
            OnSuccessLoginWithKongregate.Execute(result);
        }
    }
}

/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithPlayFab(FClientLoginWithPlayFabRequest request,
    FDelegateOnSuccessLoginWithPlayFab onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithPlayFab = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithPlayFab);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithPlayFab";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithPlayFab(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithPlayFab.IsBound())
        {
            OnSuccessLoginWithPlayFab.Execute(result);
        }
    }
}

/** Signs the user in using a Steam authentication ticket, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithSteam(FClientLoginWithSteamRequest request,
    FDelegateOnSuccessLoginWithSteam onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLoginWithSteam = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithSteam);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithSteam";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.SteamTicket.IsEmpty() || request.SteamTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SteamTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SteamTicket"), request.SteamTicket);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLoginWithSteam(FPlayFabBaseModel response, bool successful)
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
        FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
        if (OnSuccessLoginWithSteam.IsBound())
        {
            OnSuccessLoginWithSteam.Execute(result);
        }
    }
}

/** Registers a new Playfab user account, returning a session identifier that can subsequently be used for API calls which require an authenticated user. You must supply either a username or an email address. */
UPlayFabClientAPI* UPlayFabClientAPI::RegisterPlayFabUser(FClientRegisterPlayFabUserRequest request,
    FDelegateOnSuccessRegisterPlayFabUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRegisterPlayFabUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRegisterPlayFabUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RegisterPlayFabUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }

    OutRestJsonObj->SetBoolField(TEXT("RequireBothUsernameAndEmail"), request.RequireBothUsernameAndEmail);
    if (request.DisplayName.IsEmpty() || request.DisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DisplayName"), request.DisplayName);
    }

    if (request.Origination.IsEmpty() || request.Origination == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Origination"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Origination"), request.Origination);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRegisterPlayFabUser(FPlayFabBaseModel response, bool successful)
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
        FClientRegisterPlayFabUserResult result = UPlayFabClientModelDecoder::decodeRegisterPlayFabUserResultResponse(response.responseData);
        if (OnSuccessRegisterPlayFabUser.IsBound())
        {
            OnSuccessRegisterPlayFabUser.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Adds playfab username/password auth to an existing semi-anonymous account created via a 3rd party auth method. */
UPlayFabClientAPI* UPlayFabClientAPI::AddUsernamePassword(FClientAddUsernamePasswordRequest request,
    FDelegateOnSuccessAddUsernamePassword onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddUsernamePassword = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddUsernamePassword);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddUsernamePassword";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddUsernamePassword(FPlayFabBaseModel response, bool successful)
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
        FClientAddUsernamePasswordResult result = UPlayFabClientModelDecoder::decodeAddUsernamePasswordResultResponse(response.responseData);
        if (OnSuccessAddUsernamePassword.IsBound())
        {
            OnSuccessAddUsernamePassword.Execute(result);
        }
    }
}

/** Retrieves the user's PlayFab account details */
UPlayFabClientAPI* UPlayFabClientAPI::GetAccountInfo(FClientGetAccountInfoRequest request,
    FDelegateOnSuccessGetAccountInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetAccountInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetAccountInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetAccountInfo";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetAccountInfo(FPlayFabBaseModel response, bool successful)
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
        FClientGetAccountInfoResult result = UPlayFabClientModelDecoder::decodeGetAccountInfoResultResponse(response.responseData);
        if (OnSuccessGetAccountInfo.IsBound())
        {
            OnSuccessGetAccountInfo.Execute(result);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(FClientGetPlayFabIDsFromFacebookIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromFacebookIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromFacebookIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromFacebookIDs";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromFacebookIDs(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayFabIDsFromFacebookIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromFacebookIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromFacebookIDs.Execute(result);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Game Center identifiers (referenced in the Game Center Programming Guide as the Player Identifier). */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(FClientGetPlayFabIDsFromGameCenterIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromGameCenterIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromGameCenterIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromGameCenterIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromGameCenterIDs";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    // Check to see if string is empty
    if (request.GameCenterIDs.IsEmpty() || request.GameCenterIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameCenterIDs"));
    }
    else
    {
        TArray<FString> GameCenterIDsArray;
        FString(request.GameCenterIDs).ParseIntoArray(GameCenterIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("GameCenterIDs"), GameCenterIDsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromGameCenterIDs(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayFabIDsFromGameCenterIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGameCenterIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromGameCenterIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromGameCenterIDs.Execute(result);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Google identifiers. The Google identifiers are the IDs for the user accounts, available as "id" in the Google+ People API calls. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(FClientGetPlayFabIDsFromGoogleIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromGoogleIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromGoogleIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromGoogleIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromGoogleIDs";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    // Check to see if string is empty
    if (request.GoogleIDs.IsEmpty() || request.GoogleIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GoogleIDs"));
    }
    else
    {
        TArray<FString> GoogleIDsArray;
        FString(request.GoogleIDs).ParseIntoArray(GoogleIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("GoogleIDs"), GoogleIDsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromGoogleIDs(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayFabIDsFromGoogleIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromGoogleIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromGoogleIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromGoogleIDs.Execute(result);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Kongregate identifiers. The Kongregate identifiers are the IDs for the user accounts, available as "user_id" from the Kongregate API methods(ex: http://developers.kongregate.com/docs/client/getUserId). */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(FClientGetPlayFabIDsFromKongregateIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromKongregateIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromKongregateIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromKongregateIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromKongregateIDs";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    // Check to see if string is empty
    if (request.KongregateIDs.IsEmpty() || request.KongregateIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateIDs"));
    }
    else
    {
        TArray<FString> KongregateIDsArray;
        FString(request.KongregateIDs).ParseIntoArray(KongregateIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KongregateIDs"), KongregateIDsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromKongregateIDs(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayFabIDsFromKongregateIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromKongregateIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromKongregateIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromKongregateIDs.Execute(result);
        }
    }
}

/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromSteamIDs(FClientGetPlayFabIDsFromSteamIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromSteamIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromSteamIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayFabIDsFromSteamIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromSteamIDs";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayFabIDsFromSteamIDs(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayFabIDsFromSteamIDsResult result = UPlayFabClientModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(response.responseData);
        if (OnSuccessGetPlayFabIDsFromSteamIDs.IsBound())
        {
            OnSuccessGetPlayFabIDsFromSteamIDs.Execute(result);
        }
    }
}

/** Retrieves all requested data for a user in one unified request. By default, this API returns all  data for the locally signed-in user. The input parameters may be used to limit the data retrieved to any subset of the available data, as well as retrieve the available data for a different user. Note that certain data, including inventory, virtual currency balances, and personally identifying information, may only be retrieved for the locally signed-in user. In the example below, a request is made for the account details, virtual currency balances, and specified user data for the locally signed-in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserCombinedInfo(FClientGetUserCombinedInfoRequest request,
    FDelegateOnSuccessGetUserCombinedInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserCombinedInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserCombinedInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserCombinedInfo";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.TitleDisplayName.IsEmpty() || request.TitleDisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TitleDisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), request.TitleDisplayName);
    }

    OutRestJsonObj->SetBoolField(TEXT("GetAccountInfo"), request.GetAccountInfo);
    OutRestJsonObj->SetBoolField(TEXT("GetInventory"), request.GetInventory);
    OutRestJsonObj->SetBoolField(TEXT("GetVirtualCurrency"), request.GetVirtualCurrency);
    OutRestJsonObj->SetBoolField(TEXT("GetUserData"), request.GetUserData);
    // Check to see if string is empty
    if (request.UserDataKeys.IsEmpty() || request.UserDataKeys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("UserDataKeys"));
    }
    else
    {
        TArray<FString> UserDataKeysArray;
        FString(request.UserDataKeys).ParseIntoArray(UserDataKeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("UserDataKeys"), UserDataKeysArray);
    }

    OutRestJsonObj->SetBoolField(TEXT("GetReadOnlyData"), request.GetReadOnlyData);
    // Check to see if string is empty
    if (request.ReadOnlyDataKeys.IsEmpty() || request.ReadOnlyDataKeys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReadOnlyDataKeys"));
    }
    else
    {
        TArray<FString> ReadOnlyDataKeysArray;
        FString(request.ReadOnlyDataKeys).ParseIntoArray(ReadOnlyDataKeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ReadOnlyDataKeys"), ReadOnlyDataKeysArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserCombinedInfo(FPlayFabBaseModel response, bool successful)
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
        FClientGetUserCombinedInfoResult result = UPlayFabClientModelDecoder::decodeGetUserCombinedInfoResultResponse(response.responseData);
        if (OnSuccessGetUserCombinedInfo.IsBound())
        {
            OnSuccessGetUserCombinedInfo.Execute(result);
        }
    }
}

/** Links the Android device identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkAndroidDeviceID(FClientLinkAndroidDeviceIDRequest request,
    FDelegateOnSuccessLinkAndroidDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkAndroidDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkAndroidDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkAndroidDeviceID";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.AndroidDevice.IsEmpty() || request.AndroidDevice == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDevice"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), request.AndroidDevice);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkAndroidDeviceID(FPlayFabBaseModel response, bool successful)
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
        FClientLinkAndroidDeviceIDResult result = UPlayFabClientModelDecoder::decodeLinkAndroidDeviceIDResultResponse(response.responseData);
        if (OnSuccessLinkAndroidDeviceID.IsBound())
        {
            OnSuccessLinkAndroidDeviceID.Execute(result);
        }
    }
}

/** Links the custom identifier, generated by the title, to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkCustomID(FClientLinkCustomIDRequest request,
    FDelegateOnSuccessLinkCustomID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkCustomID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkCustomID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkCustomID";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.CustomId.IsEmpty() || request.CustomId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkCustomID(FPlayFabBaseModel response, bool successful)
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
        FClientLinkCustomIDResult result = UPlayFabClientModelDecoder::decodeLinkCustomIDResultResponse(response.responseData);
        if (OnSuccessLinkCustomID.IsBound())
        {
            OnSuccessLinkCustomID.Execute(result);
        }
    }
}

/** Links the Facebook account associated with the provided Facebook access token to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkFacebookAccount(FClientLinkFacebookAccountRequest request,
    FDelegateOnSuccessLinkFacebookAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkFacebookAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkFacebookAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkFacebookAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkFacebookAccount(FPlayFabBaseModel response, bool successful)
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
        FClientLinkFacebookAccountResult result = UPlayFabClientModelDecoder::decodeLinkFacebookAccountResultResponse(response.responseData);
        if (OnSuccessLinkFacebookAccount.IsBound())
        {
            OnSuccessLinkFacebookAccount.Execute(result);
        }
    }
}

/** Links the Game Center account associated with the provided Game Center ID to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkGameCenterAccount(FClientLinkGameCenterAccountRequest request,
    FDelegateOnSuccessLinkGameCenterAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkGameCenterAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkGameCenterAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkGameCenterAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.GameCenterId.IsEmpty() || request.GameCenterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameCenterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameCenterId"), request.GameCenterId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkGameCenterAccount(FPlayFabBaseModel response, bool successful)
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
        FClientLinkGameCenterAccountResult result = UPlayFabClientModelDecoder::decodeLinkGameCenterAccountResultResponse(response.responseData);
        if (OnSuccessLinkGameCenterAccount.IsBound())
        {
            OnSuccessLinkGameCenterAccount.Execute(result);
        }
    }
}

/** Links the currently signed-in user account to the Google account specified by the Google account access token */
UPlayFabClientAPI* UPlayFabClientAPI::LinkGoogleAccount(FClientLinkGoogleAccountRequest request,
    FDelegateOnSuccessLinkGoogleAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkGoogleAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkGoogleAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkGoogleAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkGoogleAccount(FPlayFabBaseModel response, bool successful)
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
        FClientLinkGoogleAccountResult result = UPlayFabClientModelDecoder::decodeLinkGoogleAccountResultResponse(response.responseData);
        if (OnSuccessLinkGoogleAccount.IsBound())
        {
            OnSuccessLinkGoogleAccount.Execute(result);
        }
    }
}

/** Links the vendor-specific iOS device identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkIOSDeviceID(FClientLinkIOSDeviceIDRequest request,
    FDelegateOnSuccessLinkIOSDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkIOSDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkIOSDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkIOSDeviceID";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.DeviceId.IsEmpty() || request.DeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.DeviceModel.IsEmpty() || request.DeviceModel == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceModel"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceModel"), request.DeviceModel);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkIOSDeviceID(FPlayFabBaseModel response, bool successful)
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
        FClientLinkIOSDeviceIDResult result = UPlayFabClientModelDecoder::decodeLinkIOSDeviceIDResultResponse(response.responseData);
        if (OnSuccessLinkIOSDeviceID.IsBound())
        {
            OnSuccessLinkIOSDeviceID.Execute(result);
        }
    }
}

/** Links the Kongregate identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkKongregate(FClientLinkKongregateAccountRequest request,
    FDelegateOnSuccessLinkKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkKongregate);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkKongregate";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.KongregateId.IsEmpty() || request.KongregateId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("KongregateId"), request.KongregateId);
    }

    if (request.AuthTicket.IsEmpty() || request.AuthTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthTicket"), request.AuthTicket);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkKongregate(FPlayFabBaseModel response, bool successful)
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
        FClientLinkKongregateAccountResult result = UPlayFabClientModelDecoder::decodeLinkKongregateAccountResultResponse(response.responseData);
        if (OnSuccessLinkKongregate.IsBound())
        {
            OnSuccessLinkKongregate.Execute(result);
        }
    }
}

/** Links the Steam account associated with the provided Steam authentication ticket to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkSteamAccount(FClientLinkSteamAccountRequest request,
    FDelegateOnSuccessLinkSteamAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLinkSteamAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLinkSteamAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkSteamAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.SteamTicket.IsEmpty() || request.SteamTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SteamTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SteamTicket"), request.SteamTicket);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLinkSteamAccount(FPlayFabBaseModel response, bool successful)
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
        FClientLinkSteamAccountResult result = UPlayFabClientModelDecoder::decodeLinkSteamAccountResultResponse(response.responseData);
        if (OnSuccessLinkSteamAccount.IsBound())
        {
            OnSuccessLinkSteamAccount.Execute(result);
        }
    }
}

/** Forces an email to be sent to the registered email address for the user's account, with a link allowing the user to change the password */
UPlayFabClientAPI* UPlayFabClientAPI::SendAccountRecoveryEmail(FClientSendAccountRecoveryEmailRequest request,
    FDelegateOnSuccessSendAccountRecoveryEmail onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSendAccountRecoveryEmail = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperSendAccountRecoveryEmail);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SendAccountRecoveryEmail";
    manager->useSessionTicket = false;
    manager->useSecretKey = false;


    // Setup request object
    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.PublisherId.IsEmpty() || request.PublisherId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PublisherId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PublisherId"), request.PublisherId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperSendAccountRecoveryEmail(FPlayFabBaseModel response, bool successful)
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
        FClientSendAccountRecoveryEmailResult result = UPlayFabClientModelDecoder::decodeSendAccountRecoveryEmailResultResponse(response.responseData);
        if (OnSuccessSendAccountRecoveryEmail.IsBound())
        {
            OnSuccessSendAccountRecoveryEmail.Execute(result);
        }
    }
}

/** Unlinks the related Android device identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkAndroidDeviceID(FClientUnlinkAndroidDeviceIDRequest request,
    FDelegateOnSuccessUnlinkAndroidDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkAndroidDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkAndroidDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkAndroidDeviceID";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkAndroidDeviceID(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkAndroidDeviceIDResult result = UPlayFabClientModelDecoder::decodeUnlinkAndroidDeviceIDResultResponse(response.responseData);
        if (OnSuccessUnlinkAndroidDeviceID.IsBound())
        {
            OnSuccessUnlinkAndroidDeviceID.Execute(result);
        }
    }
}

/** Unlinks the related custom identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkCustomID(FClientUnlinkCustomIDRequest request,
    FDelegateOnSuccessUnlinkCustomID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkCustomID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkCustomID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkCustomID";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.CustomId.IsEmpty() || request.CustomId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkCustomID(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkCustomIDResult result = UPlayFabClientModelDecoder::decodeUnlinkCustomIDResultResponse(response.responseData);
        if (OnSuccessUnlinkCustomID.IsBound())
        {
            OnSuccessUnlinkCustomID.Execute(result);
        }
    }
}

/** Unlinks the related Facebook account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkFacebookAccount(FClientUnlinkFacebookAccountRequest request,
    FDelegateOnSuccessUnlinkFacebookAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkFacebookAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkFacebookAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkFacebookAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkFacebookAccount(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkFacebookAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkFacebookAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkFacebookAccount.IsBound())
        {
            OnSuccessUnlinkFacebookAccount.Execute(result);
        }
    }
}

/** Unlinks the related Game Center account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkGameCenterAccount(FClientUnlinkGameCenterAccountRequest request,
    FDelegateOnSuccessUnlinkGameCenterAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkGameCenterAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkGameCenterAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkGameCenterAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkGameCenterAccount(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkGameCenterAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkGameCenterAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkGameCenterAccount.IsBound())
        {
            OnSuccessUnlinkGameCenterAccount.Execute(result);
        }
    }
}

/** Unlinks the related Google account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkGoogleAccount(FClientUnlinkGoogleAccountRequest request,
    FDelegateOnSuccessUnlinkGoogleAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkGoogleAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkGoogleAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkGoogleAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkGoogleAccount(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkGoogleAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkGoogleAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkGoogleAccount.IsBound())
        {
            OnSuccessUnlinkGoogleAccount.Execute(result);
        }
    }
}

/** Unlinks the related iOS device identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkIOSDeviceID(FClientUnlinkIOSDeviceIDRequest request,
    FDelegateOnSuccessUnlinkIOSDeviceID onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkIOSDeviceID = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkIOSDeviceID);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkIOSDeviceID";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.DeviceId.IsEmpty() || request.DeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkIOSDeviceID(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkIOSDeviceIDResult result = UPlayFabClientModelDecoder::decodeUnlinkIOSDeviceIDResultResponse(response.responseData);
        if (OnSuccessUnlinkIOSDeviceID.IsBound())
        {
            OnSuccessUnlinkIOSDeviceID.Execute(result);
        }
    }
}

/** Unlinks the related Kongregate identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkKongregate(FClientUnlinkKongregateAccountRequest request,
    FDelegateOnSuccessUnlinkKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkKongregate);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkKongregate";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkKongregate(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkKongregateAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkKongregateAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkKongregate.IsBound())
        {
            OnSuccessUnlinkKongregate.Execute(result);
        }
    }
}

/** Unlinks the related Steam account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkSteamAccount(FClientUnlinkSteamAccountRequest request,
    FDelegateOnSuccessUnlinkSteamAccount onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlinkSteamAccount = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlinkSteamAccount);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkSteamAccount";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlinkSteamAccount(FPlayFabBaseModel response, bool successful)
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
        FClientUnlinkSteamAccountResult result = UPlayFabClientModelDecoder::decodeUnlinkSteamAccountResultResponse(response.responseData);
        if (OnSuccessUnlinkSteamAccount.IsBound())
        {
            OnSuccessUnlinkSteamAccount.Execute(result);
        }
    }
}

/** Updates the title specific display name for the user */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserTitleDisplayName(FClientUpdateUserTitleDisplayNameRequest request,
    FDelegateOnSuccessUpdateUserTitleDisplayName onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserTitleDisplayName = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateUserTitleDisplayName);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserTitleDisplayName";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateUserTitleDisplayName(FPlayFabBaseModel response, bool successful)
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
        FClientUpdateUserTitleDisplayNameResult result = UPlayFabClientModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(response.responseData);
        if (OnSuccessUpdateUserTitleDisplayName.IsBound())
        {
            OnSuccessUpdateUserTitleDisplayName.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Retrieves a list of ranked friends of the current player for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboard(FClientGetFriendLeaderboardRequest request,
    FDelegateOnSuccessGetFriendLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetFriendLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetFriendLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboard";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetFriendLeaderboard(FPlayFabBaseModel response, bool successful)
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
        FClientGetLeaderboardResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetFriendLeaderboard.IsBound())
        {
            OnSuccessGetFriendLeaderboard.Execute(result);
        }
    }
}

/** Retrieves a list of ranked friends of the current player for the given statistic, centered on the currently signed-in user */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboardAroundCurrentUser(FClientGetFriendLeaderboardAroundCurrentUserRequest request,
    FDelegateOnSuccessGetFriendLeaderboardAroundCurrentUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetFriendLeaderboardAroundCurrentUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetFriendLeaderboardAroundCurrentUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboardAroundCurrentUser";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetFriendLeaderboardAroundCurrentUser(FPlayFabBaseModel response, bool successful)
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
        FClientGetFriendLeaderboardAroundCurrentUserResult result = UPlayFabClientModelDecoder::decodeGetFriendLeaderboardAroundCurrentUserResultResponse(response.responseData);
        if (OnSuccessGetFriendLeaderboardAroundCurrentUser.IsBound())
        {
            OnSuccessGetFriendLeaderboardAroundCurrentUser.Execute(result);
        }
    }
}

/** Retrieves a list of ranked friends of the current player for the given statistic, centered on the requested PlayFab user. If PlayFabId is empty or null will return currently logged in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboardAroundPlayer(FClientGetFriendLeaderboardAroundPlayerRequest request,
    FDelegateOnSuccessGetFriendLeaderboardAroundPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetFriendLeaderboardAroundPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetFriendLeaderboardAroundPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboardAroundPlayer";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetFriendLeaderboardAroundPlayer(FPlayFabBaseModel response, bool successful)
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
        FClientGetFriendLeaderboardAroundPlayerResult result = UPlayFabClientModelDecoder::decodeGetFriendLeaderboardAroundPlayerResultResponse(response.responseData);
        if (OnSuccessGetFriendLeaderboardAroundPlayer.IsBound())
        {
            OnSuccessGetFriendLeaderboardAroundPlayer.Execute(result);
        }
    }
}

/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboard(FClientGetLeaderboardRequest request,
    FDelegateOnSuccessGetLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboard";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboard(FPlayFabBaseModel response, bool successful)
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
        FClientGetLeaderboardResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetLeaderboard.IsBound())
        {
            OnSuccessGetLeaderboard.Execute(result);
        }
    }
}

/** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundCurrentUser(FClientGetLeaderboardAroundCurrentUserRequest request,
    FDelegateOnSuccessGetLeaderboardAroundCurrentUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundCurrentUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboardAroundCurrentUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundCurrentUser";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboardAroundCurrentUser(FPlayFabBaseModel response, bool successful)
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
        FClientGetLeaderboardAroundCurrentUserResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCurrentUserResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardAroundCurrentUser.IsBound())
        {
            OnSuccessGetLeaderboardAroundCurrentUser.Execute(result);
        }
    }
}

/** Retrieves a list of ranked users for the given statistic, centered on the requested player. If PlayFabId is empty or null will return currently logged in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundPlayer(FClientGetLeaderboardAroundPlayerRequest request,
    FDelegateOnSuccessGetLeaderboardAroundPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboardAroundPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundPlayer";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboardAroundPlayer(FPlayFabBaseModel response, bool successful)
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
        FClientGetLeaderboardAroundPlayerResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardAroundPlayerResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardAroundPlayer.IsBound())
        {
            OnSuccessGetLeaderboardAroundPlayer.Execute(result);
        }
    }
}

/** Retrieves the indicated statistics (current version and values for all statistics, if none are specified), for the local player. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerStatistics(FClientGetPlayerStatisticsRequest request,
    FDelegateOnSuccessGetPlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerStatistics";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerStatistics(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayerStatisticsResult result = UPlayFabClientModelDecoder::decodeGetPlayerStatisticsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatistics.IsBound())
        {
            OnSuccessGetPlayerStatistics.Execute(result);
        }
    }
}

/** Retrieves the information on the available versions of the specified statistic. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerStatisticVersions(FClientGetPlayerStatisticVersionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerStatisticVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerStatisticVersions";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayerStatisticVersionsResult result = UPlayFabClientModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatisticVersions.IsBound())
        {
            OnSuccessGetPlayerStatisticVersions.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserData(FPlayFabBaseModel response, bool successful)
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
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserData.IsBound())
        {
            OnSuccessGetUserData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserPublisherData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserPublisherData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserPublisherData(FPlayFabBaseModel response, bool successful)
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
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherData.IsBound())
        {
            OnSuccessGetUserPublisherData.Execute(result);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserPublisherReadOnlyData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserPublisherReadOnlyData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, bool successful)
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
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessGetUserPublisherReadOnlyData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserReadOnlyData(FClientGetUserDataRequest request,
    FDelegateOnSuccessGetUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserReadOnlyData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserReadOnlyData(FPlayFabBaseModel response, bool successful)
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
        FClientGetUserDataResult result = UPlayFabClientModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserReadOnlyData.IsBound())
        {
            OnSuccessGetUserReadOnlyData.Execute(result);
        }
    }
}

/** Retrieves the details of all title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserStatistics(FClientGetUserStatisticsRequest request,
    FDelegateOnSuccessGetUserStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserStatistics";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserStatistics(FPlayFabBaseModel response, bool successful)
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
        FClientGetUserStatisticsResult result = UPlayFabClientModelDecoder::decodeGetUserStatisticsResultResponse(response.responseData);
        if (OnSuccessGetUserStatistics.IsBound())
        {
            OnSuccessGetUserStatistics.Execute(result);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::UpdatePlayerStatistics(FClientUpdatePlayerStatisticsRequest request,
    FDelegateOnSuccessUpdatePlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdatePlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdatePlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdatePlayerStatistics";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    OutRestJsonObj->SetObjectArrayField(TEXT("Statistics"), request.Statistics);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdatePlayerStatistics(FPlayFabBaseModel response, bool successful)
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
        FClientUpdatePlayerStatisticsResult result = UPlayFabClientModelDecoder::decodeUpdatePlayerStatisticsResultResponse(response.responseData);
        if (OnSuccessUpdatePlayerStatistics.IsBound())
        {
            OnSuccessUpdatePlayerStatistics.Execute(result);
        }
    }
}

/** Creates and updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserData(FClientUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateUserData(FPlayFabBaseModel response, bool successful)
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
        FClientUpdateUserDataResult result = UPlayFabClientModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserData.IsBound())
        {
            OnSuccessUpdateUserData.Execute(result);
        }
    }
}

/** Creates and updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserPublisherData(FClientUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserPublisherData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateUserPublisherData(FPlayFabBaseModel response, bool successful)
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
        FClientUpdateUserDataResult result = UPlayFabClientModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherData.IsBound())
        {
            OnSuccessUpdateUserPublisherData.Execute(result);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserStatistics(FClientUpdateUserStatisticsRequest request,
    FDelegateOnSuccessUpdateUserStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateUserStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateUserStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserStatistics";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.UserStatistics != NULL) OutRestJsonObj->SetObjectField(TEXT("UserStatistics"), request.UserStatistics);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateUserStatistics(FPlayFabBaseModel response, bool successful)
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
        FClientUpdateUserStatisticsResult result = UPlayFabClientModelDecoder::decodeUpdateUserStatisticsResultResponse(response.responseData);
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
UPlayFabClientAPI* UPlayFabClientAPI::GetCatalogItems(FClientGetCatalogItemsRequest request,
    FDelegateOnSuccessGetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCatalogItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCatalogItems";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCatalogItems(FPlayFabBaseModel response, bool successful)
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
        FClientGetCatalogItemsResult result = UPlayFabClientModelDecoder::decodeGetCatalogItemsResultResponse(response.responseData);
        if (OnSuccessGetCatalogItems.IsBound())
        {
            OnSuccessGetCatalogItems.Execute(result);
        }
    }
}

/** Retrieves the set of items defined for the specified store, including all prices defined */
UPlayFabClientAPI* UPlayFabClientAPI::GetStoreItems(FClientGetStoreItemsRequest request,
    FDelegateOnSuccessGetStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetStoreItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetStoreItems";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetStoreItems(FPlayFabBaseModel response, bool successful)
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
        FClientGetStoreItemsResult result = UPlayFabClientModelDecoder::decodeGetStoreItemsResultResponse(response.responseData);
        if (OnSuccessGetStoreItems.IsBound())
        {
            OnSuccessGetStoreItems.Execute(result);
        }
    }
}

/** Retrieves the key-value store of custom title settings */
UPlayFabClientAPI* UPlayFabClientAPI::GetTitleData(FClientGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTitleData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetTitleData(FPlayFabBaseModel response, bool successful)
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
        FClientGetTitleDataResult result = UPlayFabClientModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        if (OnSuccessGetTitleData.IsBound())
        {
            OnSuccessGetTitleData.Execute(result);
        }
    }
}

/** Retrieves the title news feed, as configured in the developer portal */
UPlayFabClientAPI* UPlayFabClientAPI::GetTitleNews(FClientGetTitleNewsRequest request,
    FDelegateOnSuccessGetTitleNews onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetTitleNews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetTitleNews);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTitleNews";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetTitleNews(FPlayFabBaseModel response, bool successful)
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
        FClientGetTitleNewsResult result = UPlayFabClientModelDecoder::decodeGetTitleNewsResultResponse(response.responseData);
        if (OnSuccessGetTitleNews.IsBound())
        {
            OnSuccessGetTitleNews.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments the user's balance of the specified virtual currency by the stated amount */
UPlayFabClientAPI* UPlayFabClientAPI::AddUserVirtualCurrency(FClientAddUserVirtualCurrencyRequest request,
    FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddUserVirtualCurrency";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddUserVirtualCurrency(FPlayFabBaseModel response, bool successful)
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
        FClientModifyUserVirtualCurrencyResult result = UPlayFabClientModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessAddUserVirtualCurrency.IsBound())
        {
            OnSuccessAddUserVirtualCurrency.Execute(result);
        }
    }
}

/** Confirms with the payment provider that the purchase was approved (if applicable) and adjusts inventory and virtual currency balances as appropriate */
UPlayFabClientAPI* UPlayFabClientAPI::ConfirmPurchase(FClientConfirmPurchaseRequest request,
    FDelegateOnSuccessConfirmPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessConfirmPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperConfirmPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ConfirmPurchase";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.OrderId.IsEmpty() || request.OrderId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperConfirmPurchase(FPlayFabBaseModel response, bool successful)
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
        FClientConfirmPurchaseResult result = UPlayFabClientModelDecoder::decodeConfirmPurchaseResultResponse(response.responseData);
        if (OnSuccessConfirmPurchase.IsBound())
        {
            OnSuccessConfirmPurchase.Execute(result);
        }
    }
}

/** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
UPlayFabClientAPI* UPlayFabClientAPI::ConsumeItem(FClientConsumeItemRequest request,
    FDelegateOnSuccessConsumeItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessConsumeItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperConsumeItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ConsumeItem";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperConsumeItem(FPlayFabBaseModel response, bool successful)
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
        FClientConsumeItemResult result = UPlayFabClientModelDecoder::decodeConsumeItemResultResponse(response.responseData);
        if (OnSuccessConsumeItem.IsBound())
        {
            OnSuccessConsumeItem.Execute(result);
        }
    }
}

/** Retrieves the specified character's current inventory of virtual goods */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterInventory(FClientGetCharacterInventoryRequest request,
    FDelegateOnSuccessGetCharacterInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterInventory";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterInventory(FPlayFabBaseModel response, bool successful)
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
        FClientGetCharacterInventoryResult result = UPlayFabClientModelDecoder::decodeGetCharacterInventoryResultResponse(response.responseData);
        if (OnSuccessGetCharacterInventory.IsBound())
        {
            OnSuccessGetCharacterInventory.Execute(result);
        }
    }
}

/** Retrieves a completed purchase along with its current PlayFab status. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPurchase(FClientGetPurchaseRequest request,
    FDelegateOnSuccessGetPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPurchase";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.OrderId.IsEmpty() || request.OrderId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPurchase(FPlayFabBaseModel response, bool successful)
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
        FClientGetPurchaseResult result = UPlayFabClientModelDecoder::decodeGetPurchaseResultResponse(response.responseData);
        if (OnSuccessGetPurchase.IsBound())
        {
            OnSuccessGetPurchase.Execute(result);
        }
    }
}

/** Retrieves the user's current inventory of virtual goods */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserInventory(FClientGetUserInventoryRequest request,
    FDelegateOnSuccessGetUserInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetUserInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetUserInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserInventory";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetUserInventory(FPlayFabBaseModel response, bool successful)
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
        FClientGetUserInventoryResult result = UPlayFabClientModelDecoder::decodeGetUserInventoryResultResponse(response.responseData);
        if (OnSuccessGetUserInventory.IsBound())
        {
            OnSuccessGetUserInventory.Execute(result);
        }
    }
}

/** Selects a payment option for purchase order created via StartPurchase */
UPlayFabClientAPI* UPlayFabClientAPI::PayForPurchase(FClientPayForPurchaseRequest request,
    FDelegateOnSuccessPayForPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessPayForPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperPayForPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/PayForPurchase";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.OrderId.IsEmpty() || request.OrderId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }

    if (request.ProviderName.IsEmpty() || request.ProviderName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ProviderName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ProviderName"), request.ProviderName);
    }

    if (request.Currency.IsEmpty() || request.Currency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Currency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Currency"), request.Currency);
    }

    if (request.ProviderTransactionId.IsEmpty() || request.ProviderTransactionId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ProviderTransactionId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ProviderTransactionId"), request.ProviderTransactionId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperPayForPurchase(FPlayFabBaseModel response, bool successful)
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
        FClientPayForPurchaseResult result = UPlayFabClientModelDecoder::decodePayForPurchaseResultResponse(response.responseData);
        if (OnSuccessPayForPurchase.IsBound())
        {
            OnSuccessPayForPurchase.Execute(result);
        }
    }
}

/** Buys a single item with virtual currency. You must specify both the virtual currency to use to purchase, as well as what the client believes the price to be. This lets the server fail the purchase if the price has changed. */
UPlayFabClientAPI* UPlayFabClientAPI::PurchaseItem(FClientPurchaseItemRequest request,
    FDelegateOnSuccessPurchaseItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessPurchaseItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperPurchaseItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/PurchaseItem";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.ItemId.IsEmpty() || request.ItemId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }

    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Price"), request.Price);
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperPurchaseItem(FPlayFabBaseModel response, bool successful)
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
        FClientPurchaseItemResult result = UPlayFabClientModelDecoder::decodePurchaseItemResultResponse(response.responseData);
        if (OnSuccessPurchaseItem.IsBound())
        {
            OnSuccessPurchaseItem.Execute(result);
        }
    }
}

/** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/using-stores-and-coupons-game-manager/ */
UPlayFabClientAPI* UPlayFabClientAPI::RedeemCoupon(FClientRedeemCouponRequest request,
    FDelegateOnSuccessRedeemCoupon onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRedeemCoupon = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRedeemCoupon);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RedeemCoupon";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.CouponCode.IsEmpty() || request.CouponCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CouponCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CouponCode"), request.CouponCode);
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRedeemCoupon(FPlayFabBaseModel response, bool successful)
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
        FClientRedeemCouponResult result = UPlayFabClientModelDecoder::decodeRedeemCouponResultResponse(response.responseData);
        if (OnSuccessRedeemCoupon.IsBound())
        {
            OnSuccessRedeemCoupon.Execute(result);
        }
    }
}

/** Submit a report for another player (due to bad bahavior, etc.), so that customer service representatives for the title can take action concerning potentially toxic players. */
UPlayFabClientAPI* UPlayFabClientAPI::ReportPlayer(FClientReportPlayerClientRequest request,
    FDelegateOnSuccessReportPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessReportPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperReportPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ReportPlayer";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.ReporteeId.IsEmpty() || request.ReporteeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReporteeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReporteeId"), request.ReporteeId);
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperReportPlayer(FPlayFabBaseModel response, bool successful)
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
        FClientReportPlayerClientResult result = UPlayFabClientModelDecoder::decodeReportPlayerClientResultResponse(response.responseData);
        if (OnSuccessReportPlayer.IsBound())
        {
            OnSuccessReportPlayer.Execute(result);
        }
    }
}

/** Creates an order for a list of items from the title catalog */
UPlayFabClientAPI* UPlayFabClientAPI::StartPurchase(FClientStartPurchaseRequest request,
    FDelegateOnSuccessStartPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessStartPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperStartPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/StartPurchase";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

    OutRestJsonObj->SetObjectArrayField(TEXT("Items"), request.Items);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperStartPurchase(FPlayFabBaseModel response, bool successful)
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
        FClientStartPurchaseResult result = UPlayFabClientModelDecoder::decodeStartPurchaseResultResponse(response.responseData);
        if (OnSuccessStartPurchase.IsBound())
        {
            OnSuccessStartPurchase.Execute(result);
        }
    }
}

/** Decrements the user's balance of the specified virtual currency by the stated amount */
UPlayFabClientAPI* UPlayFabClientAPI::SubtractUserVirtualCurrency(FClientSubtractUserVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSubtractUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperSubtractUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SubtractUserVirtualCurrency";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, bool successful)
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
        FClientModifyUserVirtualCurrencyResult result = UPlayFabClientModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessSubtractUserVirtualCurrency.IsBound())
        {
            OnSuccessSubtractUserVirtualCurrency.Execute(result);
        }
    }
}

/** Opens the specified container, with the specified key (when required), and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabClientAPI* UPlayFabClientAPI::UnlockContainerInstance(FClientUnlockContainerInstanceRequest request,
    FDelegateOnSuccessUnlockContainerInstance onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlockContainerInstance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlockContainerInstance);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlockContainerInstance";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlockContainerInstance(FPlayFabBaseModel response, bool successful)
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
        FClientUnlockContainerItemResult result = UPlayFabClientModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        if (OnSuccessUnlockContainerInstance.IsBound())
        {
            OnSuccessUnlockContainerInstance.Execute(result);
        }
    }
}

/** Searches target inventory for an ItemInstance matching the given CatalogItemId, if necessary unlocks it using an appropriate key, and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabClientAPI* UPlayFabClientAPI::UnlockContainerItem(FClientUnlockContainerItemRequest request,
    FDelegateOnSuccessUnlockContainerItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUnlockContainerItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUnlockContainerItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlockContainerItem";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUnlockContainerItem(FPlayFabBaseModel response, bool successful)
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
        FClientUnlockContainerItemResult result = UPlayFabClientModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        if (OnSuccessUnlockContainerItem.IsBound())
        {
            OnSuccessUnlockContainerItem.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////
/** Adds the PlayFab user, based upon a match against a supplied unique identifier, to the friend list of the local user. At least one of FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName should be initialized. */
UPlayFabClientAPI* UPlayFabClientAPI::AddFriend(FClientAddFriendRequest request,
    FDelegateOnSuccessAddFriend onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddFriend = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddFriend);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddFriend";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }

    if (request.FriendUsername.IsEmpty() || request.FriendUsername == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendUsername"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendUsername"), request.FriendUsername);
    }

    if (request.FriendEmail.IsEmpty() || request.FriendEmail == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendEmail"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendEmail"), request.FriendEmail);
    }

    if (request.FriendTitleDisplayName.IsEmpty() || request.FriendTitleDisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendTitleDisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendTitleDisplayName"), request.FriendTitleDisplayName);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddFriend(FPlayFabBaseModel response, bool successful)
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
        FClientAddFriendResult result = UPlayFabClientModelDecoder::decodeAddFriendResultResponse(response.responseData);
        if (OnSuccessAddFriend.IsBound())
        {
            OnSuccessAddFriend.Execute(result);
        }
    }
}

/** Retrieves the current friend list for the local user, constrained to users who have PlayFab accounts. Friends from linked accounts (Facebook, Steam) are also included. You may optionally exclude some linked services' friends. */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendsList(FClientGetFriendsListRequest request,
    FDelegateOnSuccessGetFriendsList onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetFriendsList = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetFriendsList);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendsList";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetFriendsList(FPlayFabBaseModel response, bool successful)
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
        FClientGetFriendsListResult result = UPlayFabClientModelDecoder::decodeGetFriendsListResultResponse(response.responseData);
        if (OnSuccessGetFriendsList.IsBound())
        {
            OnSuccessGetFriendsList.Execute(result);
        }
    }
}

/** Removes a specified user from the friend list of the local user */
UPlayFabClientAPI* UPlayFabClientAPI::RemoveFriend(FClientRemoveFriendRequest request,
    FDelegateOnSuccessRemoveFriend onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRemoveFriend = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRemoveFriend);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RemoveFriend";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRemoveFriend(FPlayFabBaseModel response, bool successful)
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
        FClientRemoveFriendResult result = UPlayFabClientModelDecoder::decodeRemoveFriendResultResponse(response.responseData);
        if (OnSuccessRemoveFriend.IsBound())
        {
            OnSuccessRemoveFriend.Execute(result);
        }
    }
}

/** Updates the tag list for a specified user in the friend list of the local user */
UPlayFabClientAPI* UPlayFabClientAPI::SetFriendTags(FClientSetFriendTagsRequest request,
    FDelegateOnSuccessSetFriendTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessSetFriendTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperSetFriendTags);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SetFriendTags";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }

    // Check to see if string is empty
    if (request.Tags.IsEmpty() || request.Tags == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Tags"));
    }
    else
    {
        TArray<FString> TagsArray;
        FString(request.Tags).ParseIntoArray(TagsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Tags"), TagsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperSetFriendTags(FPlayFabBaseModel response, bool successful)
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
        FClientSetFriendTagsResult result = UPlayFabClientModelDecoder::decodeSetFriendTagsResultResponse(response.responseData);
        if (OnSuccessSetFriendTags.IsBound())
        {
            OnSuccessSetFriendTags.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// IOS-Specific APIs
//////////////////////////////////////////////////////
/** Registers the iOS device to receive push notifications */
UPlayFabClientAPI* UPlayFabClientAPI::RegisterForIOSPushNotification(FClientRegisterForIOSPushNotificationRequest request,
    FDelegateOnSuccessRegisterForIOSPushNotification onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRegisterForIOSPushNotification = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRegisterForIOSPushNotification);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RegisterForIOSPushNotification";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.DeviceToken.IsEmpty() || request.DeviceToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceToken"), request.DeviceToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), request.SendPushNotificationConfirmation);
    if (request.ConfirmationMessage.IsEmpty() || request.ConfirmationMessage == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ConfirmationMessage"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ConfirmationMessage"), request.ConfirmationMessage);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRegisterForIOSPushNotification(FPlayFabBaseModel response, bool successful)
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
        FClientRegisterForIOSPushNotificationResult result = UPlayFabClientModelDecoder::decodeRegisterForIOSPushNotificationResultResponse(response.responseData);
        if (OnSuccessRegisterForIOSPushNotification.IsBound())
        {
            OnSuccessRegisterForIOSPushNotification.Execute(result);
        }
    }
}

/** Restores all in-app purchases based on the given refresh receipt. */
UPlayFabClientAPI* UPlayFabClientAPI::RestoreIOSPurchases(FClientRestoreIOSPurchasesRequest request,
    FDelegateOnSuccessRestoreIOSPurchases onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRestoreIOSPurchases = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRestoreIOSPurchases);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RestoreIOSPurchases";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.ReceiptData.IsEmpty() || request.ReceiptData == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptData"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptData"), request.ReceiptData);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRestoreIOSPurchases(FPlayFabBaseModel response, bool successful)
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
        FClientRestoreIOSPurchasesResult result = UPlayFabClientModelDecoder::decodeRestoreIOSPurchasesResultResponse(response.responseData);
        if (OnSuccessRestoreIOSPurchases.IsBound())
        {
            OnSuccessRestoreIOSPurchases.Execute(result);
        }
    }
}

/** Validates with the Apple store that the receipt for an iOS in-app purchase is valid and that it matches the purchased catalog item */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateIOSReceipt(FClientValidateIOSReceiptRequest request,
    FDelegateOnSuccessValidateIOSReceipt onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessValidateIOSReceipt = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperValidateIOSReceipt);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateIOSReceipt";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.ReceiptData.IsEmpty() || request.ReceiptData == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptData"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptData"), request.ReceiptData);
    }

    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }

    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperValidateIOSReceipt(FPlayFabBaseModel response, bool successful)
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
        FClientValidateIOSReceiptResult result = UPlayFabClientModelDecoder::decodeValidateIOSReceiptResultResponse(response.responseData);
        if (OnSuccessValidateIOSReceipt.IsBound())
        {
            OnSuccessValidateIOSReceipt.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Get details about all current running game servers matching the given parameters. */
UPlayFabClientAPI* UPlayFabClientAPI::GetCurrentGames(FClientCurrentGamesRequest request,
    FDelegateOnSuccessGetCurrentGames onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCurrentGames = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCurrentGames);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCurrentGames";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.Region.IsEmpty() || request.Region == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }

    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    if (request.GameMode.IsEmpty() || request.GameMode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }

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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCurrentGames(FPlayFabBaseModel response, bool successful)
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
        FClientCurrentGamesResult result = UPlayFabClientModelDecoder::decodeCurrentGamesResultResponse(response.responseData);
        if (OnSuccessGetCurrentGames.IsBound())
        {
            OnSuccessGetCurrentGames.Execute(result);
        }
    }
}

/**  Get details about the regions hosting game servers matching the given parameters. */
UPlayFabClientAPI* UPlayFabClientAPI::GetGameServerRegions(FClientGameServerRegionsRequest request,
    FDelegateOnSuccessGetGameServerRegions onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetGameServerRegions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetGameServerRegions);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetGameServerRegions";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetGameServerRegions(FPlayFabBaseModel response, bool successful)
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
        FClientGameServerRegionsResult result = UPlayFabClientModelDecoder::decodeGameServerRegionsResultResponse(response.responseData);
        if (OnSuccessGetGameServerRegions.IsBound())
        {
            OnSuccessGetGameServerRegions.Execute(result);
        }
    }
}

/** Attempts to locate a game session matching the given parameters. If the goal is to match the player into a specific active session, only the LobbyId is required. Otherwise, the BuildVersion, GameMode, and Region are all required parameters. Note that parameters specified in the search are required (they are not weighting factors). If a slot is found in a server instance matching the parameters, the slot will be assigned to that player, removing it from the availabe set. In that case, the information on the game session will be returned, otherwise the Status returned will be GameNotFound. Note that EnableQueue is deprecated at this time. */
UPlayFabClientAPI* UPlayFabClientAPI::Matchmake(FClientMatchmakeRequest request,
    FDelegateOnSuccessMatchmake onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessMatchmake = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperMatchmake);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/Matchmake";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    if (request.Region.IsEmpty() || request.Region == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }

    if (request.GameMode.IsEmpty() || request.GameMode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }

    if (request.LobbyId.IsEmpty() || request.LobbyId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    OutRestJsonObj->SetBoolField(TEXT("EnableQueue"), request.EnableQueue);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperMatchmake(FPlayFabBaseModel response, bool successful)
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
        FClientMatchmakeResult result = UPlayFabClientModelDecoder::decodeMatchmakeResultResponse(response.responseData);
        if (OnSuccessMatchmake.IsBound())
        {
            OnSuccessMatchmake.Execute(result);
        }
    }
}

/** Start a new game server with a given configuration, add the current player and return the connection information. */
UPlayFabClientAPI* UPlayFabClientAPI::StartGame(FClientStartGameRequest request,
    FDelegateOnSuccessStartGame onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessStartGame = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperStartGame);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/StartGame";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    if (request.Region.IsEmpty() || request.Region == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }

    if (request.GameMode.IsEmpty() || request.GameMode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CustomCommandLineData.IsEmpty() || request.CustomCommandLineData == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomCommandLineData"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomCommandLineData"), request.CustomCommandLineData);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperStartGame(FPlayFabBaseModel response, bool successful)
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
        FClientStartGameResult result = UPlayFabClientModelDecoder::decodeStartGameResultResponse(response.responseData);
        if (OnSuccessStartGame.IsBound())
        {
            OnSuccessStartGame.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Android-Specific APIs
//////////////////////////////////////////////////////
/** Registers the Android device to receive push notifications */
UPlayFabClientAPI* UPlayFabClientAPI::AndroidDevicePushNotificationRegistration(FClientAndroidDevicePushNotificationRegistrationRequest request,
    FDelegateOnSuccessAndroidDevicePushNotificationRegistration onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAndroidDevicePushNotificationRegistration = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAndroidDevicePushNotificationRegistration);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AndroidDevicePushNotificationRegistration";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.DeviceToken.IsEmpty() || request.DeviceToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceToken"), request.DeviceToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), request.SendPushNotificationConfirmation);
    if (request.ConfirmationMessege.IsEmpty() || request.ConfirmationMessege == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ConfirmationMessege"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ConfirmationMessege"), request.ConfirmationMessege);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAndroidDevicePushNotificationRegistration(FPlayFabBaseModel response, bool successful)
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
        FClientAndroidDevicePushNotificationRegistrationResult result = UPlayFabClientModelDecoder::decodeAndroidDevicePushNotificationRegistrationResultResponse(response.responseData);
        if (OnSuccessAndroidDevicePushNotificationRegistration.IsBound())
        {
            OnSuccessAndroidDevicePushNotificationRegistration.Execute(result);
        }
    }
}

/** Validates a Google Play purchase and gives the corresponding item to the player. */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateGooglePlayPurchase(FClientValidateGooglePlayPurchaseRequest request,
    FDelegateOnSuccessValidateGooglePlayPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessValidateGooglePlayPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperValidateGooglePlayPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateGooglePlayPurchase";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.ReceiptJson.IsEmpty() || request.ReceiptJson == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptJson"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptJson"), request.ReceiptJson);
    }

    if (request.Signature.IsEmpty() || request.Signature == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Signature"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Signature"), request.Signature);
    }

    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }

    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperValidateGooglePlayPurchase(FPlayFabBaseModel response, bool successful)
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
        FClientValidateGooglePlayPurchaseResult result = UPlayFabClientModelDecoder::decodeValidateGooglePlayPurchaseResultResponse(response.responseData);
        if (OnSuccessValidateGooglePlayPurchase.IsBound())
        {
            OnSuccessValidateGooglePlayPurchase.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////
/** Logs a custom analytics event */
UPlayFabClientAPI* UPlayFabClientAPI::LogEvent(FClientLogEventRequest request,
    FDelegateOnSuccessLogEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessLogEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLogEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LogEvent";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperLogEvent(FPlayFabBaseModel response, bool successful)
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
        FClientLogEventResult result = UPlayFabClientModelDecoder::decodeLogEventResultResponse(response.responseData);
        if (OnSuccessLogEvent.IsBound())
        {
            OnSuccessLogEvent.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group can add new members. */
UPlayFabClientAPI* UPlayFabClientAPI::AddSharedGroupMembers(FClientAddSharedGroupMembersRequest request,
    FDelegateOnSuccessAddSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAddSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAddSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddSharedGroupMembers";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAddSharedGroupMembers(FPlayFabBaseModel response, bool successful)
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
        FClientAddSharedGroupMembersResult result = UPlayFabClientModelDecoder::decodeAddSharedGroupMembersResultResponse(response.responseData);
        if (OnSuccessAddSharedGroupMembers.IsBound())
        {
            OnSuccessAddSharedGroupMembers.Execute(result);
        }
    }
}

/** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. Upon creation, the current user will be the only member of the group. */
UPlayFabClientAPI* UPlayFabClientAPI::CreateSharedGroup(FClientCreateSharedGroupRequest request,
    FDelegateOnSuccessCreateSharedGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessCreateSharedGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperCreateSharedGroup);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/CreateSharedGroup";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperCreateSharedGroup(FPlayFabBaseModel response, bool successful)
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
        FClientCreateSharedGroupResult result = UPlayFabClientModelDecoder::decodeCreateSharedGroupResultResponse(response.responseData);
        if (OnSuccessCreateSharedGroup.IsBound())
        {
            OnSuccessCreateSharedGroup.Execute(result);
        }
    }
}

/** Retrieves the key-value store of custom publisher settings */
UPlayFabClientAPI* UPlayFabClientAPI::GetPublisherData(FClientGetPublisherDataRequest request,
    FDelegateOnSuccessGetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPublisherData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPublisherData(FPlayFabBaseModel response, bool successful)
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
        FClientGetPublisherDataResult result = UPlayFabClientModelDecoder::decodeGetPublisherDataResultResponse(response.responseData);
        if (OnSuccessGetPublisherData.IsBound())
        {
            OnSuccessGetPublisherData.Execute(result);
        }
    }
}

/** Retrieves data stored in a shared group object, as well as the list of members in the group. Non-members of the group may use this to retrieve group data, including membership, but they will not receive data for keys marked as private. */
UPlayFabClientAPI* UPlayFabClientAPI::GetSharedGroupData(FClientGetSharedGroupDataRequest request,
    FDelegateOnSuccessGetSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetSharedGroupData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetSharedGroupData(FPlayFabBaseModel response, bool successful)
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
        FClientGetSharedGroupDataResult result = UPlayFabClientModelDecoder::decodeGetSharedGroupDataResultResponse(response.responseData);
        if (OnSuccessGetSharedGroupData.IsBound())
        {
            OnSuccessGetSharedGroupData.Execute(result);
        }
    }
}

/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. */
UPlayFabClientAPI* UPlayFabClientAPI::RemoveSharedGroupMembers(FClientRemoveSharedGroupMembersRequest request,
    FDelegateOnSuccessRemoveSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRemoveSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRemoveSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RemoveSharedGroupMembers";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRemoveSharedGroupMembers(FPlayFabBaseModel response, bool successful)
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
        FClientRemoveSharedGroupMembersResult result = UPlayFabClientModelDecoder::decodeRemoveSharedGroupMembersResultResponse(response.responseData);
        if (OnSuccessRemoveSharedGroupMembers.IsBound())
        {
            OnSuccessRemoveSharedGroupMembers.Execute(result);
        }
    }
}

/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group can update the data. */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateSharedGroupData(FClientUpdateSharedGroupDataRequest request,
    FDelegateOnSuccessUpdateSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateSharedGroupData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateSharedGroupData(FPlayFabBaseModel response, bool successful)
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
        FClientUpdateSharedGroupDataResult result = UPlayFabClientModelDecoder::decodeUpdateSharedGroupDataResultResponse(response.responseData);
        if (OnSuccessUpdateSharedGroupData.IsBound())
        {
            OnSuccessUpdateSharedGroupData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Sony-specific APIs
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Executes a CloudScript function, with the 'currentPlayerId' set to the PlayFab ID of the authenticated player. */
UPlayFabClientAPI* UPlayFabClientAPI::ExecuteCloudScript(FClientExecuteCloudScriptRequest request,
    FDelegateOnSuccessExecuteCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessExecuteCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperExecuteCloudScript);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ExecuteCloudScript";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperExecuteCloudScript(FPlayFabBaseModel response, bool successful)
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
        FClientExecuteCloudScriptResult result = UPlayFabClientModelDecoder::decodeExecuteCloudScriptResultResponse(response.responseData);
        if (OnSuccessExecuteCloudScript.IsBound())
        {
            OnSuccessExecuteCloudScript.Execute(result);
        }
    }
}

/** Retrieves the title-specific URL for Cloud Script servers. This must be queried once, prior  to making any calls to RunCloudScript. */
UPlayFabClientAPI* UPlayFabClientAPI::GetCloudScriptUrl(FClientGetCloudScriptUrlRequest request,
    FDelegateOnSuccessGetCloudScriptUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCloudScriptUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCloudScriptUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCloudScriptUrl";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("Testing"), request.Testing);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCloudScriptUrl(FPlayFabBaseModel response, bool successful)
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
        FClientGetCloudScriptUrlResult result = UPlayFabClientModelDecoder::decodeGetCloudScriptUrlResultResponse(response.responseData);
        if (OnSuccessGetCloudScriptUrl.IsBound())
        {
            OnSuccessGetCloudScriptUrl.Execute(result);
        }
    }
}

/** Triggers a particular server action, passing the provided inputs to the hosted Cloud Script. An action in this context is a handler in the JavaScript. NOTE: Before calling this API, you must call GetCloudScriptUrl to be assigned a Cloud Script server URL. When using an official PlayFab SDK, this URL is stored internally in the SDK, but GetCloudScriptUrl must still be manually called. */
UPlayFabClientAPI* UPlayFabClientAPI::RunCloudScript(FClientRunCloudScriptRequest request,
    FDelegateOnSuccessRunCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessRunCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperRunCloudScript);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RunCloudScript";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;
    manager->cloudScript = true;


    // Setup request object
    if (request.ActionId.IsEmpty() || request.ActionId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ActionId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ActionId"), request.ActionId);
    }

    if (request.Params != NULL) OutRestJsonObj->SetObjectField(TEXT("Params"), request.Params);
    if (request.ParamsEncoded != "") OutRestJsonObj->SetStringField(TEXT("ParamsEncoded"), request.ParamsEncoded);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperRunCloudScript(FPlayFabBaseModel response, bool successful)
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
        FClientRunCloudScriptResult result = UPlayFabClientModelDecoder::decodeRunCloudScriptResultResponse(response.responseData);
        if (OnSuccessRunCloudScript.IsBound())
        {
            OnSuccessRunCloudScript.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://community.playfab.com/hc/en-us/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service */
UPlayFabClientAPI* UPlayFabClientAPI::GetContentDownloadUrl(FClientGetContentDownloadUrlRequest request,
    FDelegateOnSuccessGetContentDownloadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetContentDownloadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetContentDownloadUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetContentDownloadUrl";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetContentDownloadUrl(FPlayFabBaseModel response, bool successful)
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
        FClientGetContentDownloadUrlResult result = UPlayFabClientModelDecoder::decodeGetContentDownloadUrlResultResponse(response.responseData);
        if (OnSuccessGetContentDownloadUrl.IsBound())
        {
            OnSuccessGetContentDownloadUrl.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Lists all of the characters that belong to a specific user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetAllUsersCharacters(FClientListUsersCharactersRequest request,
    FDelegateOnSuccessGetAllUsersCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetAllUsersCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetAllUsersCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetAllUsersCharacters";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetAllUsersCharacters(FPlayFabBaseModel response, bool successful)
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
        FClientListUsersCharactersResult result = UPlayFabClientModelDecoder::decodeListUsersCharactersResultResponse(response.responseData);
        if (OnSuccessGetAllUsersCharacters.IsBound())
        {
            OnSuccessGetAllUsersCharacters.Execute(result);
        }
    }
}

/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterLeaderboard(FClientGetCharacterLeaderboardRequest request,
    FDelegateOnSuccessGetCharacterLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterLeaderboard";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterLeaderboard(FPlayFabBaseModel response, bool successful)
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
        FClientGetCharacterLeaderboardResult result = UPlayFabClientModelDecoder::decodeGetCharacterLeaderboardResultResponse(response.responseData);
        if (OnSuccessGetCharacterLeaderboard.IsBound())
        {
            OnSuccessGetCharacterLeaderboard.Execute(result);
        }
    }
}

/** Retrieves the details of all title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterStatistics(FClientGetCharacterStatisticsRequest request,
    FDelegateOnSuccessGetCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterStatistics";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterStatistics(FPlayFabBaseModel response, bool successful)
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
        FClientGetCharacterStatisticsResult result = UPlayFabClientModelDecoder::decodeGetCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessGetCharacterStatistics.IsBound())
        {
            OnSuccessGetCharacterStatistics.Execute(result);
        }
    }
}

/** Retrieves a list of ranked characters for the given statistic, centered on the requested Character ID */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundCharacter(FClientGetLeaderboardAroundCharacterRequest request,
    FDelegateOnSuccessGetLeaderboardAroundCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboardAroundCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundCharacter";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboardAroundCharacter(FPlayFabBaseModel response, bool successful)
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
        FClientGetLeaderboardAroundCharacterResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardAroundCharacter.IsBound())
        {
            OnSuccessGetLeaderboardAroundCharacter.Execute(result);
        }
    }
}

/** Retrieves a list of all of the user's characters for the given statistic. */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardForUserCharacters(FClientGetLeaderboardForUsersCharactersRequest request,
    FDelegateOnSuccessGetLeaderboardForUserCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetLeaderboardForUserCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetLeaderboardForUserCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardForUserCharacters";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetLeaderboardForUserCharacters(FPlayFabBaseModel response, bool successful)
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
        FClientGetLeaderboardForUsersCharactersResult result = UPlayFabClientModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(response.responseData);
        if (OnSuccessGetLeaderboardForUserCharacters.IsBound())
        {
            OnSuccessGetLeaderboardForUserCharacters.Execute(result);
        }
    }
}

/** Grants the specified character type to the user. */
UPlayFabClientAPI* UPlayFabClientAPI::GrantCharacterToUser(FClientGrantCharacterToUserRequest request,
    FDelegateOnSuccessGrantCharacterToUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGrantCharacterToUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGrantCharacterToUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GrantCharacterToUser";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.ItemId.IsEmpty() || request.ItemId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }

    if (request.CharacterName.IsEmpty() || request.CharacterName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterName"), request.CharacterName);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGrantCharacterToUser(FPlayFabBaseModel response, bool successful)
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
        FClientGrantCharacterToUserResult result = UPlayFabClientModelDecoder::decodeGrantCharacterToUserResultResponse(response.responseData);
        if (OnSuccessGrantCharacterToUser.IsBound())
        {
            OnSuccessGrantCharacterToUser.Execute(result);
        }
    }
}

/** Updates the values of the specified title-specific statistics for the specific character */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateCharacterStatistics(FClientUpdateCharacterStatisticsRequest request,
    FDelegateOnSuccessUpdateCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateCharacterStatistics";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateCharacterStatistics(FPlayFabBaseModel response, bool successful)
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
        FClientUpdateCharacterStatisticsResult result = UPlayFabClientModelDecoder::decodeUpdateCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterStatistics.IsBound())
        {
            OnSuccessUpdateCharacterStatistics.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////
/** Retrieves the title-specific custom data for the character which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterData(FClientGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterData(FPlayFabBaseModel response, bool successful)
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
        FClientGetCharacterDataResult result = UPlayFabClientModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        if (OnSuccessGetCharacterData.IsBound())
        {
            OnSuccessGetCharacterData.Execute(result);
        }
    }
}

/** Retrieves the title-specific custom data for the character which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterReadOnlyData(FClientGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetCharacterReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetCharacterReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterReadOnlyData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetCharacterReadOnlyData(FPlayFabBaseModel response, bool successful)
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
        FClientGetCharacterDataResult result = UPlayFabClientModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        if (OnSuccessGetCharacterReadOnlyData.IsBound())
        {
            OnSuccessGetCharacterReadOnlyData.Execute(result);
        }
    }
}

/** Creates and updates the title-specific custom data for the user's character which is readable  and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateCharacterData(FClientUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUpdateCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperUpdateCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateCharacterData";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
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

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperUpdateCharacterData(FPlayFabBaseModel response, bool successful)
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
        FClientUpdateCharacterDataResult result = UPlayFabClientModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        if (OnSuccessUpdateCharacterData.IsBound())
        {
            OnSuccessUpdateCharacterData.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Amazon-Specific APIs
//////////////////////////////////////////////////////
/** Validates with Amazon that the receipt for an Amazon App Store in-app purchase is valid and that it matches the purchased catalog item */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateAmazonIAPReceipt(FClientValidateAmazonReceiptRequest request,
    FDelegateOnSuccessValidateAmazonIAPReceipt onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessValidateAmazonIAPReceipt = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperValidateAmazonIAPReceipt);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateAmazonIAPReceipt";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.ReceiptId.IsEmpty() || request.ReceiptId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptId"), request.ReceiptId);
    }

    if (request.UserId.IsEmpty() || request.UserId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("UserId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("UserId"), request.UserId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }

    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperValidateAmazonIAPReceipt(FPlayFabBaseModel response, bool successful)
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
        FClientValidateAmazonReceiptResult result = UPlayFabClientModelDecoder::decodeValidateAmazonReceiptResultResponse(response.responseData);
        if (OnSuccessValidateAmazonIAPReceipt.IsBound())
        {
            OnSuccessValidateAmazonIAPReceipt.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Trading
//////////////////////////////////////////////////////
/** Accepts an open trade. If the call is successful, the offered and accepted items will be swapped between the two players' inventories. */
UPlayFabClientAPI* UPlayFabClientAPI::AcceptTrade(FClientAcceptTradeRequest request,
    FDelegateOnSuccessAcceptTrade onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAcceptTrade = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAcceptTrade);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AcceptTrade";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.OfferingPlayerId.IsEmpty() || request.OfferingPlayerId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OfferingPlayerId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OfferingPlayerId"), request.OfferingPlayerId);
    }

    if (request.TradeId.IsEmpty() || request.TradeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }

    // Check to see if string is empty
    if (request.AcceptedInventoryInstanceIds.IsEmpty() || request.AcceptedInventoryInstanceIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AcceptedInventoryInstanceIds"));
    }
    else
    {
        TArray<FString> AcceptedInventoryInstanceIdsArray;
        FString(request.AcceptedInventoryInstanceIds).ParseIntoArray(AcceptedInventoryInstanceIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("AcceptedInventoryInstanceIds"), AcceptedInventoryInstanceIdsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAcceptTrade(FPlayFabBaseModel response, bool successful)
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
        FClientAcceptTradeResponse result = UPlayFabClientModelDecoder::decodeAcceptTradeResponseResponse(response.responseData);
        if (OnSuccessAcceptTrade.IsBound())
        {
            OnSuccessAcceptTrade.Execute(result);
        }
    }
}

/** Cancels an open trade. */
UPlayFabClientAPI* UPlayFabClientAPI::CancelTrade(FClientCancelTradeRequest request,
    FDelegateOnSuccessCancelTrade onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessCancelTrade = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperCancelTrade);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/CancelTrade";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.TradeId.IsEmpty() || request.TradeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperCancelTrade(FPlayFabBaseModel response, bool successful)
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
        FClientCancelTradeResponse result = UPlayFabClientModelDecoder::decodeCancelTradeResponseResponse(response.responseData);
        if (OnSuccessCancelTrade.IsBound())
        {
            OnSuccessCancelTrade.Execute(result);
        }
    }
}

/** Gets all trades the player has either opened or accepted, optionally filtered by trade status. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerTrades(FClientGetPlayerTradesRequest request,
    FDelegateOnSuccessGetPlayerTrades onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetPlayerTrades = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetPlayerTrades);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerTrades";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.StatusFilter.IsEmpty() || request.StatusFilter == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatusFilter"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatusFilter"), request.StatusFilter);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetPlayerTrades(FPlayFabBaseModel response, bool successful)
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
        FClientGetPlayerTradesResponse result = UPlayFabClientModelDecoder::decodeGetPlayerTradesResponseResponse(response.responseData);
        if (OnSuccessGetPlayerTrades.IsBound())
        {
            OnSuccessGetPlayerTrades.Execute(result);
        }
    }
}

/** Gets the current status of an existing trade. */
UPlayFabClientAPI* UPlayFabClientAPI::GetTradeStatus(FClientGetTradeStatusRequest request,
    FDelegateOnSuccessGetTradeStatus onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessGetTradeStatus = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperGetTradeStatus);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTradeStatus";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.OfferingPlayerId.IsEmpty() || request.OfferingPlayerId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OfferingPlayerId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OfferingPlayerId"), request.OfferingPlayerId);
    }

    if (request.TradeId.IsEmpty() || request.TradeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperGetTradeStatus(FPlayFabBaseModel response, bool successful)
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
        FClientGetTradeStatusResponse result = UPlayFabClientModelDecoder::decodeGetTradeStatusResponseResponse(response.responseData);
        if (OnSuccessGetTradeStatus.IsBound())
        {
            OnSuccessGetTradeStatus.Execute(result);
        }
    }
}

/** Opens a new outstanding trade. */
UPlayFabClientAPI* UPlayFabClientAPI::OpenTrade(FClientOpenTradeRequest request,
    FDelegateOnSuccessOpenTrade onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessOpenTrade = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperOpenTrade);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/OpenTrade";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    // Check to see if string is empty
    if (request.OfferedInventoryInstanceIds.IsEmpty() || request.OfferedInventoryInstanceIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OfferedInventoryInstanceIds"));
    }
    else
    {
        TArray<FString> OfferedInventoryInstanceIdsArray;
        FString(request.OfferedInventoryInstanceIds).ParseIntoArray(OfferedInventoryInstanceIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("OfferedInventoryInstanceIds"), OfferedInventoryInstanceIdsArray);
    }

    // Check to see if string is empty
    if (request.RequestedCatalogItemIds.IsEmpty() || request.RequestedCatalogItemIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("RequestedCatalogItemIds"));
    }
    else
    {
        TArray<FString> RequestedCatalogItemIdsArray;
        FString(request.RequestedCatalogItemIds).ParseIntoArray(RequestedCatalogItemIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("RequestedCatalogItemIds"), RequestedCatalogItemIdsArray);
    }

    // Check to see if string is empty
    if (request.AllowedPlayerIds.IsEmpty() || request.AllowedPlayerIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AllowedPlayerIds"));
    }
    else
    {
        TArray<FString> AllowedPlayerIdsArray;
        FString(request.AllowedPlayerIds).ParseIntoArray(AllowedPlayerIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("AllowedPlayerIds"), AllowedPlayerIdsArray);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperOpenTrade(FPlayFabBaseModel response, bool successful)
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
        FClientOpenTradeResponse result = UPlayFabClientModelDecoder::decodeOpenTradeResponseResponse(response.responseData);
        if (OnSuccessOpenTrade.IsBound())
        {
            OnSuccessOpenTrade.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Advertising
//////////////////////////////////////////////////////
/** Attributes an install for advertisment. */
UPlayFabClientAPI* UPlayFabClientAPI::AttributeInstall(FClientAttributeInstallRequest request,
    FDelegateOnSuccessAttributeInstall onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAttributeInstall = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperAttributeInstall);

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AttributeInstall";
    manager->useSessionTicket = true;
    manager->useSecretKey = false;


    // Setup request object
    if (request.Idfa.IsEmpty() || request.Idfa == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Idfa"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Idfa"), request.Idfa);
    }

    if (request.Android_Id.IsEmpty() || request.Android_Id == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Android_Id"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Android_Id"), request.Android_Id);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabClientRequestCompleted
void UPlayFabClientAPI::HelperAttributeInstall(FPlayFabBaseModel response, bool successful)
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
        FClientAttributeInstallResult result = UPlayFabClientModelDecoder::decodeAttributeInstallResultResponse(response.responseData);
        if (OnSuccessAttributeInstall.IsBound())
        {
            OnSuccessAttributeInstall.Execute(result);
        }
    }
}


///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////


void UPlayFabClientAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

        Client_proxy->OnPlayFabResponse.Broadcast(myResponse, false);

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

    if (isLoginRequest)
    {
        IPlayFab* pfSettings = &(IPlayFab::Get());
        pfSettings->setSessionTicket(myResponse.responseData->GetObjectField("data")->GetStringField("SessionTicket"));
        bool needsAttribution = myResponse.responseData->GetObjectField("data")->GetBoolField("SessionTicket");
        if (needsAttribution && !pfSettings->DisableAdvertising && !pfSettings->AdvertisingIdType.IsEmpty() && !pfSettings->AdvertisingIdValue.IsEmpty())
        {
            FClientAttributeInstallRequest request;
            bool makeAttrCall = true;
            if (pfSettings->AdvertisingIdType == IPlayFab::AD_TYPE_IDFA)
                request.Idfa = pfSettings->AdvertisingIdValue;
            else if (pfSettings->AdvertisingIdType == IPlayFab::AD_TYPE_ANDROID_ID)
                request.Android_Id = pfSettings->AdvertisingIdValue;
            else
                makeAttrCall = false;
            if (makeAttrCall)
            {
                FDelegateOnSuccessAttributeInstall onSuccess;
                FDelegateOnFailurePlayFabError onFailure;
                auto callObj = AttributeInstall(request, onSuccess, onFailure);
                callObj->Activate();
                if (callObj->IsValidLowLevel())
                    callObj->ConditionalBeginDestroy();
            }
        }
    }

    // Broadcast the result event
    Client_proxy->OnPlayFabResponse.Broadcast(myResponse, true);
}

void UPlayFabClientAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabClientAPI::OnProcessRequestComplete);

    // Execute the request
    HttpRequest->ProcessRequest();
}

void UPlayFabClientAPI::ResetResponseData()
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
