//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Matchmaker
// SDK Version: 0.0.160307
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabMatchmakerAPI.h"

UPlayFabMatchmakerAPI* Matchmaker_proxy = NULL;

UPlayFabMatchmakerAPI::UPlayFabMatchmakerAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    Matchmaker_proxy = this;
}

void UPlayFabMatchmakerAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabMatchmakerAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabMatchmakerAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Matchmaker API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Validates a user with the PlayFab service */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::AuthUser(FMatchmakerAuthUserRequest request,
    FDelegateOnSuccessAuthUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessAuthUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperAuthUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/AuthUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.AuthorizationTicket.IsEmpty() || request.AuthorizationTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthorizationTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthorizationTicket"), request.AuthorizationTicket);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperAuthUser(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FMatchmakerAuthUserResponse result = UPlayFabMatchmakerModelDecoder::decodeAuthUserResponseResponse(response.responseData);
        if (OnSuccessAuthUser.IsBound())
        {
            OnSuccessAuthUser.Execute(result);
        }
    }
}

/** Informs the PlayFab game server hosting service that the indicated user has joined the Game Server Instance specified */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::PlayerJoined(FMatchmakerPlayerJoinedRequest request,
    FDelegateOnSuccessPlayerJoined onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessPlayerJoined = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperPlayerJoined);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/PlayerJoined";
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

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperPlayerJoined(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FMatchmakerPlayerJoinedResponse result = UPlayFabMatchmakerModelDecoder::decodePlayerJoinedResponseResponse(response.responseData);
        if (OnSuccessPlayerJoined.IsBound())
        {
            OnSuccessPlayerJoined.Execute(result);
        }
    }
}

/** Informs the PlayFab game server hosting service that the indicated user has left the Game Server Instance specified */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::PlayerLeft(FMatchmakerPlayerLeftRequest request,
    FDelegateOnSuccessPlayerLeft onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessPlayerLeft = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperPlayerLeft);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/PlayerLeft";
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

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperPlayerLeft(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FMatchmakerPlayerLeftResponse result = UPlayFabMatchmakerModelDecoder::decodePlayerLeftResponseResponse(response.responseData);
        if (OnSuccessPlayerLeft.IsBound())
        {
            OnSuccessPlayerLeft.Execute(result);
        }
    }
}

/** Instructs the PlayFab game server hosting service to instantiate a new Game Server Instance */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::StartGame(FMatchmakerStartGameRequest request,
    FDelegateOnSuccessStartGame onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessStartGame = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperStartGame);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/StartGame";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;


    // Setup request object
    if (request.Build.IsEmpty() || request.Build == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Build"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Build"), request.Build);
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

    if (request.CustomCommandLineData.IsEmpty() || request.CustomCommandLineData == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomCommandLineData"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomCommandLineData"), request.CustomCommandLineData);
    }

    if (request.ExternalMatchmakerEventEndpoint.IsEmpty() || request.ExternalMatchmakerEventEndpoint == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ExternalMatchmakerEventEndpoint"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ExternalMatchmakerEventEndpoint"), request.ExternalMatchmakerEventEndpoint);
    }


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperStartGame(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FMatchmakerStartGameResponse result = UPlayFabMatchmakerModelDecoder::decodeStartGameResponseResponse(response.responseData);
        if (OnSuccessStartGame.IsBound())
        {
            OnSuccessStartGame.Execute(result);
        }
    }
}

/** Retrieves the relevant details for a specified user, which the external match-making service can then use to compute effective matches */
UPlayFabMatchmakerAPI* UPlayFabMatchmakerAPI::UserInfo(FMatchmakerUserInfoRequest request,
    FDelegateOnSuccessUserInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure)
{
    // Objects containing request data
    UPlayFabMatchmakerAPI* manager = NewObject<UPlayFabMatchmakerAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Assign delegates
    manager->OnSuccessUserInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMatchmakerAPI::HelperUserInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Matchmaker/UserInfo";
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

    OutRestJsonObj->SetNumberField(TEXT("MinCatalogVersion"), request.MinCatalogVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMatchmakerRequestCompleted
void UPlayFabMatchmakerAPI::HelperUserInfo(FPlayFabBaseModel response, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error);
        }
    }
    else
    {
        FMatchmakerUserInfoResponse result = UPlayFabMatchmakerModelDecoder::decodeUserInfoResponseResponse(response.responseData);
        if (OnSuccessUserInfo.IsBound())
        {
            OnSuccessUserInfo.Execute(result);
        }
    }
}



void UPlayFabMatchmakerAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

        Matchmaker_proxy->OnPlayFabResponse.Broadcast(myResponse, false);

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
    Matchmaker_proxy->OnPlayFabResponse.Broadcast(myResponse, true);
}

void UPlayFabMatchmakerAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabMatchmakerAPI::OnProcessRequestComplete);

    // Execute the request
    HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerAPI::ResetResponseData()
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
