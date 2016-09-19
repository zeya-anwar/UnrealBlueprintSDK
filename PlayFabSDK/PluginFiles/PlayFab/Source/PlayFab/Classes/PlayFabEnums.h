#include "PlayFabPrivatePCH.h"
#include "PlayFabJsonObject.h"
#include "PlayFabEnums.generated.h"

#pragma once

// PlayFab enums start with "pfenum_" in order to avoid code-name conflicts - For JSON, remove that prefix, and send only the expected portion (the display name is not fetchable when compiled)
static const FString prefix = TEXT("pfenum_");

template <typename EnumType>
static FORCEINLINE bool GetEnumValueFromString(const FString& enumTypeName, const FString& input, EnumType& output)
{
    UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *enumTypeName, true);
    if (!enumPtr)
    {
        output = EnumType(0);
        return false;
    }

    FString fullInput;
    if (!input.StartsWith(*prefix))
        fullInput = prefix + input;
    else
        fullInput = input;
    output = (EnumType)enumPtr->FindEnumIndex(FName(*fullInput));
    return true;
}

template<typename EnumType>
static FORCEINLINE bool GetEnumValueToString(const FString& enumTypeName, const EnumType& input, FString& output)
{
    const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *enumTypeName, true);
    if (!enumPtr)
    {
        output = FString("0");
        return false;
    }

    output = enumPtr->GetEnumName((int32)input);
    if (output.StartsWith(*prefix))
        output.RemoveAt(0, 7, false);
    return true;
}

// Enum for Currency
UENUM(BlueprintType)
enum class ECurrency : uint8
{
    pfenum_AED UMETA(DisplayName = "AED"),
    pfenum_AFN UMETA(DisplayName = "AFN"),
    pfenum_ALL UMETA(DisplayName = "ALL"),
    pfenum_AMD UMETA(DisplayName = "AMD"),
    pfenum_ANG UMETA(DisplayName = "ANG"),
    pfenum_AOA UMETA(DisplayName = "AOA"),
    pfenum_ARS UMETA(DisplayName = "ARS"),
    pfenum_AUD UMETA(DisplayName = "AUD"),
    pfenum_AWG UMETA(DisplayName = "AWG"),
    pfenum_AZN UMETA(DisplayName = "AZN"),
    pfenum_BAM UMETA(DisplayName = "BAM"),
    pfenum_BBD UMETA(DisplayName = "BBD"),
    pfenum_BDT UMETA(DisplayName = "BDT"),
    pfenum_BGN UMETA(DisplayName = "BGN"),
    pfenum_BHD UMETA(DisplayName = "BHD"),
    pfenum_BIF UMETA(DisplayName = "BIF"),
    pfenum_BMD UMETA(DisplayName = "BMD"),
    pfenum_BND UMETA(DisplayName = "BND"),
    pfenum_BOB UMETA(DisplayName = "BOB"),
    pfenum_BRL UMETA(DisplayName = "BRL"),
    pfenum_BSD UMETA(DisplayName = "BSD"),
    pfenum_BTN UMETA(DisplayName = "BTN"),
    pfenum_BWP UMETA(DisplayName = "BWP"),
    pfenum_BYR UMETA(DisplayName = "BYR"),
    pfenum_BZD UMETA(DisplayName = "BZD"),
    pfenum_CAD UMETA(DisplayName = "CAD"),
    pfenum_CDF UMETA(DisplayName = "CDF"),
    pfenum_CHF UMETA(DisplayName = "CHF"),
    pfenum_CLP UMETA(DisplayName = "CLP"),
    pfenum_CNY UMETA(DisplayName = "CNY"),
    pfenum_COP UMETA(DisplayName = "COP"),
    pfenum_CRC UMETA(DisplayName = "CRC"),
    pfenum_CUC UMETA(DisplayName = "CUC"),
    pfenum_CUP UMETA(DisplayName = "CUP"),
    pfenum_CVE UMETA(DisplayName = "CVE"),
    pfenum_CZK UMETA(DisplayName = "CZK"),
    pfenum_DJF UMETA(DisplayName = "DJF"),
    pfenum_DKK UMETA(DisplayName = "DKK"),
    pfenum_DOP UMETA(DisplayName = "DOP"),
    pfenum_DZD UMETA(DisplayName = "DZD"),
    pfenum_EGP UMETA(DisplayName = "EGP"),
    pfenum_ERN UMETA(DisplayName = "ERN"),
    pfenum_ETB UMETA(DisplayName = "ETB"),
    pfenum_EUR UMETA(DisplayName = "EUR"),
    pfenum_FJD UMETA(DisplayName = "FJD"),
    pfenum_FKP UMETA(DisplayName = "FKP"),
    pfenum_GBP UMETA(DisplayName = "GBP"),
    pfenum_GEL UMETA(DisplayName = "GEL"),
    pfenum_GGP UMETA(DisplayName = "GGP"),
    pfenum_GHS UMETA(DisplayName = "GHS"),
    pfenum_GIP UMETA(DisplayName = "GIP"),
    pfenum_GMD UMETA(DisplayName = "GMD"),
    pfenum_GNF UMETA(DisplayName = "GNF"),
    pfenum_GTQ UMETA(DisplayName = "GTQ"),
    pfenum_GYD UMETA(DisplayName = "GYD"),
    pfenum_HKD UMETA(DisplayName = "HKD"),
    pfenum_HNL UMETA(DisplayName = "HNL"),
    pfenum_HRK UMETA(DisplayName = "HRK"),
    pfenum_HTG UMETA(DisplayName = "HTG"),
    pfenum_HUF UMETA(DisplayName = "HUF"),
    pfenum_IDR UMETA(DisplayName = "IDR"),
    pfenum_ILS UMETA(DisplayName = "ILS"),
    pfenum_IMP UMETA(DisplayName = "IMP"),
    pfenum_INR UMETA(DisplayName = "INR"),
    pfenum_IQD UMETA(DisplayName = "IQD"),
    pfenum_IRR UMETA(DisplayName = "IRR"),
    pfenum_ISK UMETA(DisplayName = "ISK"),
    pfenum_JEP UMETA(DisplayName = "JEP"),
    pfenum_JMD UMETA(DisplayName = "JMD"),
    pfenum_JOD UMETA(DisplayName = "JOD"),
    pfenum_JPY UMETA(DisplayName = "JPY"),
    pfenum_KES UMETA(DisplayName = "KES"),
    pfenum_KGS UMETA(DisplayName = "KGS"),
    pfenum_KHR UMETA(DisplayName = "KHR"),
    pfenum_KMF UMETA(DisplayName = "KMF"),
    pfenum_KPW UMETA(DisplayName = "KPW"),
    pfenum_KRW UMETA(DisplayName = "KRW"),
    pfenum_KWD UMETA(DisplayName = "KWD"),
    pfenum_KYD UMETA(DisplayName = "KYD"),
    pfenum_KZT UMETA(DisplayName = "KZT"),
    pfenum_LAK UMETA(DisplayName = "LAK"),
    pfenum_LBP UMETA(DisplayName = "LBP"),
    pfenum_LKR UMETA(DisplayName = "LKR"),
    pfenum_LRD UMETA(DisplayName = "LRD"),
    pfenum_LSL UMETA(DisplayName = "LSL"),
    pfenum_LYD UMETA(DisplayName = "LYD"),
    pfenum_MAD UMETA(DisplayName = "MAD"),
    pfenum_MDL UMETA(DisplayName = "MDL"),
    pfenum_MGA UMETA(DisplayName = "MGA"),
    pfenum_MKD UMETA(DisplayName = "MKD"),
    pfenum_MMK UMETA(DisplayName = "MMK"),
    pfenum_MNT UMETA(DisplayName = "MNT"),
    pfenum_MOP UMETA(DisplayName = "MOP"),
    pfenum_MRO UMETA(DisplayName = "MRO"),
    pfenum_MUR UMETA(DisplayName = "MUR"),
    pfenum_MVR UMETA(DisplayName = "MVR"),
    pfenum_MWK UMETA(DisplayName = "MWK"),
    pfenum_MXN UMETA(DisplayName = "MXN"),
    pfenum_MYR UMETA(DisplayName = "MYR"),
    pfenum_MZN UMETA(DisplayName = "MZN"),
    pfenum_NAD UMETA(DisplayName = "NAD"),
    pfenum_NGN UMETA(DisplayName = "NGN"),
    pfenum_NIO UMETA(DisplayName = "NIO"),
    pfenum_NOK UMETA(DisplayName = "NOK"),
    pfenum_NPR UMETA(DisplayName = "NPR"),
    pfenum_NZD UMETA(DisplayName = "NZD"),
    pfenum_OMR UMETA(DisplayName = "OMR"),
    pfenum_PAB UMETA(DisplayName = "PAB"),
    pfenum_PEN UMETA(DisplayName = "PEN"),
    pfenum_PGK UMETA(DisplayName = "PGK"),
    pfenum_PHP UMETA(DisplayName = "PHP"),
    pfenum_PKR UMETA(DisplayName = "PKR"),
    pfenum_PLN UMETA(DisplayName = "PLN"),
    pfenum_PYG UMETA(DisplayName = "PYG"),
    pfenum_QAR UMETA(DisplayName = "QAR"),
    pfenum_RON UMETA(DisplayName = "RON"),
    pfenum_RSD UMETA(DisplayName = "RSD"),
    pfenum_RUB UMETA(DisplayName = "RUB"),
    pfenum_RWF UMETA(DisplayName = "RWF"),
    pfenum_SAR UMETA(DisplayName = "SAR"),
    pfenum_SBD UMETA(DisplayName = "SBD"),
    pfenum_SCR UMETA(DisplayName = "SCR"),
    pfenum_SDG UMETA(DisplayName = "SDG"),
    pfenum_SEK UMETA(DisplayName = "SEK"),
    pfenum_SGD UMETA(DisplayName = "SGD"),
    pfenum_SHP UMETA(DisplayName = "SHP"),
    pfenum_SLL UMETA(DisplayName = "SLL"),
    pfenum_SOS UMETA(DisplayName = "SOS"),
    pfenum_SPL UMETA(DisplayName = "SPL"),
    pfenum_SRD UMETA(DisplayName = "SRD"),
    pfenum_STD UMETA(DisplayName = "STD"),
    pfenum_SVC UMETA(DisplayName = "SVC"),
    pfenum_SYP UMETA(DisplayName = "SYP"),
    pfenum_SZL UMETA(DisplayName = "SZL"),
    pfenum_THB UMETA(DisplayName = "THB"),
    pfenum_TJS UMETA(DisplayName = "TJS"),
    pfenum_TMT UMETA(DisplayName = "TMT"),
    pfenum_TND UMETA(DisplayName = "TND"),
    pfenum_TOP UMETA(DisplayName = "TOP"),
    pfenum_TRY UMETA(DisplayName = "TRY"),
    pfenum_TTD UMETA(DisplayName = "TTD"),
    pfenum_TVD UMETA(DisplayName = "TVD"),
    pfenum_TWD UMETA(DisplayName = "TWD"),
    pfenum_TZS UMETA(DisplayName = "TZS"),
    pfenum_UAH UMETA(DisplayName = "UAH"),
    pfenum_UGX UMETA(DisplayName = "UGX"),
    pfenum_USD UMETA(DisplayName = "USD"),
    pfenum_UYU UMETA(DisplayName = "UYU"),
    pfenum_UZS UMETA(DisplayName = "UZS"),
    pfenum_VEF UMETA(DisplayName = "VEF"),
    pfenum_VND UMETA(DisplayName = "VND"),
    pfenum_VUV UMETA(DisplayName = "VUV"),
    pfenum_WST UMETA(DisplayName = "WST"),
    pfenum_XAF UMETA(DisplayName = "XAF"),
    pfenum_XCD UMETA(DisplayName = "XCD"),
    pfenum_XDR UMETA(DisplayName = "XDR"),
    pfenum_XOF UMETA(DisplayName = "XOF"),
    pfenum_XPF UMETA(DisplayName = "XPF"),
    pfenum_YER UMETA(DisplayName = "YER"),
    pfenum_ZAR UMETA(DisplayName = "ZAR"),
    pfenum_ZMW UMETA(DisplayName = "ZMW"),
    pfenum_ZWD UMETA(DisplayName = "ZWD"),
};

// Enum for GameBuildStatus
UENUM(BlueprintType)
enum class EGameBuildStatus : uint8
{
    pfenum_Available UMETA(DisplayName = "Available"),
    pfenum_Validating UMETA(DisplayName = "Validating"),
    pfenum_InvalidBuildPackage UMETA(DisplayName = "InvalidBuildPackage"),
    pfenum_Processing UMETA(DisplayName = "Processing"),
    pfenum_FailedToProcess UMETA(DisplayName = "FailedToProcess"),
};

// Enum for LoginIdentityProvider
UENUM(BlueprintType)
enum class ELoginIdentityProvider : uint8
{
    pfenum_Unknown UMETA(DisplayName = "Unknown"),
    pfenum_PlayFab UMETA(DisplayName = "PlayFab"),
    pfenum_Custom UMETA(DisplayName = "Custom"),
    pfenum_GameCenter UMETA(DisplayName = "GameCenter"),
    pfenum_GooglePlay UMETA(DisplayName = "GooglePlay"),
    pfenum_Steam UMETA(DisplayName = "Steam"),
    pfenum_XBoxLive UMETA(DisplayName = "XBoxLive"),
    pfenum_PSN UMETA(DisplayName = "PSN"),
    pfenum_Kongregate UMETA(DisplayName = "Kongregate"),
    pfenum_Facebook UMETA(DisplayName = "Facebook"),
    pfenum_IOSDevice UMETA(DisplayName = "IOSDevice"),
    pfenum_AndroidDevice UMETA(DisplayName = "AndroidDevice"),
    pfenum_Twitch UMETA(DisplayName = "Twitch"),
};

// Enum for PushNotificationPlatform
UENUM(BlueprintType)
enum class EPushNotificationPlatform : uint8
{
    pfenum_ApplePushNotificationService UMETA(DisplayName = "ApplePushNotificationService"),
    pfenum_GoogleCloudMessaging UMETA(DisplayName = "GoogleCloudMessaging"),
};

// Enum for Region
UENUM(BlueprintType)
enum class ERegion : uint8
{
    pfenum_USCentral UMETA(DisplayName = "USCentral"),
    pfenum_USEast UMETA(DisplayName = "USEast"),
    pfenum_EUWest UMETA(DisplayName = "EUWest"),
    pfenum_Singapore UMETA(DisplayName = "Singapore"),
    pfenum_Japan UMETA(DisplayName = "Japan"),
    pfenum_Brazil UMETA(DisplayName = "Brazil"),
    pfenum_Australia UMETA(DisplayName = "Australia"),
};

// Enum for ResolutionOutcome
UENUM(BlueprintType)
enum class EResolutionOutcome : uint8
{
    pfenum_Revoke UMETA(DisplayName = "Revoke"),
    pfenum_Reinstate UMETA(DisplayName = "Reinstate"),
    pfenum_Manual UMETA(DisplayName = "Manual"),
};

// Enum for ResultTableNodeType
UENUM(BlueprintType)
enum class EResultTableNodeType : uint8
{
    pfenum_ItemId UMETA(DisplayName = "ItemId"),
    pfenum_TableId UMETA(DisplayName = "TableId"),
};

// Enum for SourceType
UENUM(BlueprintType)
enum class ESourceType : uint8
{
    pfenum_Admin UMETA(DisplayName = "Admin"),
    pfenum_BackEnd UMETA(DisplayName = "BackEnd"),
    pfenum_GameClient UMETA(DisplayName = "GameClient"),
    pfenum_GameServer UMETA(DisplayName = "GameServer"),
    pfenum_Partner UMETA(DisplayName = "Partner"),
    pfenum_Stream UMETA(DisplayName = "Stream"),
};

// Enum for StatisticAggregationMethod
UENUM(BlueprintType)
enum class EStatisticAggregationMethod : uint8
{
    pfenum_Last UMETA(DisplayName = "Last"),
    pfenum_Min UMETA(DisplayName = "Min"),
    pfenum_Max UMETA(DisplayName = "Max"),
    pfenum_Sum UMETA(DisplayName = "Sum"),
};

// Enum for StatisticResetIntervalOption
UENUM(BlueprintType)
enum class EStatisticResetIntervalOption : uint8
{
    pfenum_Never UMETA(DisplayName = "Never"),
    pfenum_Hour UMETA(DisplayName = "Hour"),
    pfenum_Day UMETA(DisplayName = "Day"),
    pfenum_Week UMETA(DisplayName = "Week"),
    pfenum_Month UMETA(DisplayName = "Month"),
};

// Enum for StatisticVersionArchivalStatus
UENUM(BlueprintType)
enum class EStatisticVersionArchivalStatus : uint8
{
    pfenum_NotScheduled UMETA(DisplayName = "NotScheduled"),
    pfenum_Scheduled UMETA(DisplayName = "Scheduled"),
    pfenum_Queued UMETA(DisplayName = "Queued"),
    pfenum_InProgress UMETA(DisplayName = "InProgress"),
    pfenum_Complete UMETA(DisplayName = "Complete"),
};

// Enum for TitleActivationStatus
UENUM(BlueprintType)
enum class ETitleActivationStatus : uint8
{
    pfenum_None UMETA(DisplayName = "None"),
    pfenum_ActivatedTitleKey UMETA(DisplayName = "ActivatedTitleKey"),
    pfenum_PendingSteam UMETA(DisplayName = "PendingSteam"),
    pfenum_ActivatedSteam UMETA(DisplayName = "ActivatedSteam"),
    pfenum_RevokedSteam UMETA(DisplayName = "RevokedSteam"),
};

// Enum for UserDataPermission
UENUM(BlueprintType)
enum class EUserDataPermission : uint8
{
    pfenum_Private UMETA(DisplayName = "Private"),
    pfenum_Public UMETA(DisplayName = "Public"),
};

// Enum for UserOrigination
UENUM(BlueprintType)
enum class EUserOrigination : uint8
{
    pfenum_Organic UMETA(DisplayName = "Organic"),
    pfenum_Steam UMETA(DisplayName = "Steam"),
    pfenum_Google UMETA(DisplayName = "Google"),
    pfenum_Amazon UMETA(DisplayName = "Amazon"),
    pfenum_Facebook UMETA(DisplayName = "Facebook"),
    pfenum_Kongregate UMETA(DisplayName = "Kongregate"),
    pfenum_GamersFirst UMETA(DisplayName = "GamersFirst"),
    pfenum_Unknown UMETA(DisplayName = "Unknown"),
    pfenum_IOS UMETA(DisplayName = "IOS"),
    pfenum_LoadTest UMETA(DisplayName = "LoadTest"),
    pfenum_Android UMETA(DisplayName = "Android"),
    pfenum_PSN UMETA(DisplayName = "PSN"),
    pfenum_GameCenter UMETA(DisplayName = "GameCenter"),
    pfenum_CustomId UMETA(DisplayName = "CustomId"),
    pfenum_XboxLive UMETA(DisplayName = "XboxLive"),
    pfenum_Parse UMETA(DisplayName = "Parse"),
    pfenum_Twitch UMETA(DisplayName = "Twitch"),
};

// Enum for CloudScriptRevisionOption
UENUM(BlueprintType)
enum class ECloudScriptRevisionOption : uint8
{
    pfenum_Live UMETA(DisplayName = "Live"),
    pfenum_Latest UMETA(DisplayName = "Latest"),
    pfenum_Specific UMETA(DisplayName = "Specific"),
};

// Enum for GameInstanceState
UENUM(BlueprintType)
enum class EGameInstanceState : uint8
{
    pfenum_Open UMETA(DisplayName = "Open"),
    pfenum_Closed UMETA(DisplayName = "Closed"),
};

// Enum for PlayerConnectionState
UENUM(BlueprintType)
enum class EPlayerConnectionState : uint8
{
    pfenum_Unassigned UMETA(DisplayName = "Unassigned"),
    pfenum_Connecting UMETA(DisplayName = "Connecting"),
    pfenum_Participating UMETA(DisplayName = "Participating"),
    pfenum_Participated UMETA(DisplayName = "Participated"),
    pfenum_Reconnecting UMETA(DisplayName = "Reconnecting"),
};

// Enum for MatchmakeStatus
UENUM(BlueprintType)
enum class EMatchmakeStatus : uint8
{
    pfenum_Complete UMETA(DisplayName = "Complete"),
    pfenum_Waiting UMETA(DisplayName = "Waiting"),
    pfenum_GameNotFound UMETA(DisplayName = "GameNotFound"),
    pfenum_NoAvailableSlots UMETA(DisplayName = "NoAvailableSlots"),
    pfenum_SessionClosed UMETA(DisplayName = "SessionClosed"),
};

// Enum for TradeStatus
UENUM(BlueprintType)
enum class ETradeStatus : uint8
{
    pfenum_Invalid UMETA(DisplayName = "Invalid"),
    pfenum_Opening UMETA(DisplayName = "Opening"),
    pfenum_Open UMETA(DisplayName = "Open"),
    pfenum_Accepting UMETA(DisplayName = "Accepting"),
    pfenum_Accepted UMETA(DisplayName = "Accepted"),
    pfenum_Filled UMETA(DisplayName = "Filled"),
    pfenum_Cancelled UMETA(DisplayName = "Cancelled"),
};

// Enum for TransactionStatus
UENUM(BlueprintType)
enum class ETransactionStatus : uint8
{
    pfenum_CreateCart UMETA(DisplayName = "CreateCart"),
    pfenum_Init UMETA(DisplayName = "Init"),
    pfenum_Approved UMETA(DisplayName = "Approved"),
    pfenum_Succeeded UMETA(DisplayName = "Succeeded"),
    pfenum_FailedByProvider UMETA(DisplayName = "FailedByProvider"),
    pfenum_DisputePending UMETA(DisplayName = "DisputePending"),
    pfenum_RefundPending UMETA(DisplayName = "RefundPending"),
    pfenum_Refunded UMETA(DisplayName = "Refunded"),
    pfenum_RefundFailed UMETA(DisplayName = "RefundFailed"),
    pfenum_ChargedBack UMETA(DisplayName = "ChargedBack"),
    pfenum_FailedByUber UMETA(DisplayName = "FailedByUber"),
    pfenum_FailedByPlayFab UMETA(DisplayName = "FailedByPlayFab"),
    pfenum_Revoked UMETA(DisplayName = "Revoked"),
    pfenum_TradePending UMETA(DisplayName = "TradePending"),
    pfenum_Traded UMETA(DisplayName = "Traded"),
    pfenum_Upgraded UMETA(DisplayName = "Upgraded"),
    pfenum_StackPending UMETA(DisplayName = "StackPending"),
    pfenum_Stacked UMETA(DisplayName = "Stacked"),
    pfenum_Other UMETA(DisplayName = "Other"),
    pfenum_Failed UMETA(DisplayName = "Failed"),
};

