#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Matchmaker
// SDK Version: 0.0.151116
//////////////////////////////////////////////////////////////////////////////////////////////

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabMatchmakerModels.h"
#include "PlayFabMatchmakerModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabMatchmakerModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Matchmaker API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Matchmaking APIs
    //////////////////////////////////////////////////////

    /** Decode the AuthUserResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking APIs Models")
        static FMatchmakerAuthUserResponse decodeAuthUserResponseResponse(UPlayFabJsonObject* response);

    /** Decode the PlayerJoinedResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking APIs Models")
        static FMatchmakerPlayerJoinedResponse decodePlayerJoinedResponseResponse(UPlayFabJsonObject* response);

    /** Decode the PlayerLeftResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking APIs Models")
        static FMatchmakerPlayerLeftResponse decodePlayerLeftResponseResponse(UPlayFabJsonObject* response);

    /** Decode the StartGameResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking APIs Models")
        static FMatchmakerStartGameResponse decodeStartGameResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UserInfoResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking APIs Models")
        static FMatchmakerUserInfoResponse decodeUserInfoResponseResponse(UPlayFabJsonObject* response);



};
