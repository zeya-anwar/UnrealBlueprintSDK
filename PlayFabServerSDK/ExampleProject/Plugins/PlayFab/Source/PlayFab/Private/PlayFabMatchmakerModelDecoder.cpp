//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Matchmaker
// SDK Version: 0.0.151123
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabMatchmakerModelDecoder.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Matchmaker API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////

FMatchmakerAuthUserResponse UPlayFabMatchmakerModelDecoder::decodeAuthUserResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerAuthUserResponse tempStruct;

    /** Boolean indicating if the user has been authorized to use the external match-making service. */
    tempStruct.Authorized = response->GetObjectField("data")->GetBoolField("Authorized");

    /** PlayFab unique identifier of the account that has been authorized. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    return tempStruct;
}

FMatchmakerPlayerJoinedResponse UPlayFabMatchmakerModelDecoder::decodePlayerJoinedResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerPlayerJoinedResponse tempStruct;

    return tempStruct;
}

FMatchmakerPlayerLeftResponse UPlayFabMatchmakerModelDecoder::decodePlayerLeftResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerPlayerLeftResponse tempStruct;

    return tempStruct;
}

FMatchmakerStartGameResponse UPlayFabMatchmakerModelDecoder::decodeStartGameResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerStartGameResponse tempStruct;

    /** Unique identifier for the lobby in the new Game Server Instance. */
    tempStruct.GameID = response->GetObjectField("data")->GetStringField("GameID");

    /** IP address of the new Game Server Instance. */
    tempStruct.ServerHostname = response->GetObjectField("data")->GetStringField("ServerHostname");

    /** Port number for communication with the Game Server Instance. */
    tempStruct.ServerPort = int(response->GetObjectField("data")->GetNumberField("ServerPort"));

    return tempStruct;
}

FMatchmakerUserInfoResponse UPlayFabMatchmakerModelDecoder::decodeUserInfoResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerUserInfoResponse tempStruct;

    /** PlayFab unique identifier of the user whose information was requested. */
    tempStruct.PlayFabId = response->GetObjectField("data")->GetStringField("PlayFabId");

    /** PlayFab unique user name. */
    tempStruct.Username = response->GetObjectField("data")->GetStringField("Username");

    /** Title specific display name, if set. */
    tempStruct.TitleDisplayName = response->GetObjectField("data")->GetStringField("TitleDisplayName");

    /** Array of inventory items in the user's current inventory. */
    tempStruct.Inventory = response->GetObjectField("data")->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = response->GetObjectField("data")->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = response->GetObjectField("data")->GetObjectField("VirtualCurrencyRechargeTimes");

    /** Boolean indicating whether the user is a developer. */
    tempStruct.IsDeveloper = response->GetObjectField("data")->GetBoolField("IsDeveloper");

    /** Steam unique identifier, if the user has an associated Steam account. */
    tempStruct.SteamId = response->GetObjectField("data")->GetStringField("SteamId");

    return tempStruct;
}



