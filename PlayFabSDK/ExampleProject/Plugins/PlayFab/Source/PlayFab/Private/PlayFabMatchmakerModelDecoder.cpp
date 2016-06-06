//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Matchmaker
// SDK Version: 0.0.160606
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
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Boolean indicating if the user has been authorized to use the external match-making service. */
    tempStruct.Authorized = !(dataObj->HasField("Authorized")) ? false : dataObj->GetBoolField("Authorized");

    /** PlayFab unique identifier of the account that has been authorized. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

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
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** Unique identifier for the lobby in the new Game Server Instance. */
    tempStruct.GameID = !(dataObj->HasField("GameID")) ? TEXT("") : dataObj->GetStringField("GameID");

    /** IP address of the new Game Server Instance. */
    tempStruct.ServerHostname = !(dataObj->HasField("ServerHostname")) ? TEXT("") : dataObj->GetStringField("ServerHostname");

    /** Port number for communication with the Game Server Instance. */
    tempStruct.ServerPort = !(dataObj->HasField("ServerPort")) ? 0 : int(dataObj->GetNumberField("ServerPort"));

    return tempStruct;
}

FMatchmakerUserInfoResponse UPlayFabMatchmakerModelDecoder::decodeUserInfoResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerUserInfoResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    /** PlayFab unique identifier of the user whose information was requested. */
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    /** PlayFab unique user name. */
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");

    /** Title specific display name, if set. */
    tempStruct.TitleDisplayName = !(dataObj->HasField("TitleDisplayName")) ? TEXT("") : dataObj->GetStringField("TitleDisplayName");

    /** Array of inventory items in the user's current inventory. */
    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");

    /** Array of virtual currency balance(s) belonging to the user. */
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    /** Array of remaining times and timestamps for virtual currencies. */
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    /** Boolean indicating whether the user is a developer. */
    tempStruct.IsDeveloper = !(dataObj->HasField("IsDeveloper")) ? false : dataObj->GetBoolField("IsDeveloper");

    /** Steam unique identifier, if the user has an associated Steam account. */
    tempStruct.SteamId = !(dataObj->HasField("SteamId")) ? TEXT("") : dataObj->GetStringField("SteamId");

    return tempStruct;
}


