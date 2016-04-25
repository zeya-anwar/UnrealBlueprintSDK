#include "PlayFabPrivatePCH.h"
#include "PlayFabJsonObject.h"
#include "PlayFabEnums.generated.h"

#pragma once

template <typename EnumType>
static FORCEINLINE EnumType GetEnumValueFromString(const FString& EnumName, const FString& String)
{ 
	UEnum* Enum = FindObject<UEnum>(ANY_PACKAGE, *EnumName, true);
	if(!Enum) 
        return EnumType(0);
	return (EnumType)Enum->FindEnumIndex(FName(*String));
}

template<typename EnumType>
static FORCEINLINE FString GetEnumValueToString(const FString& Name, EnumType Value)
{
    const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
    if (!enumPtr)
        return FString("0");
    return enumPtr->GetEnumName((int32)Value);
}

// Enum for CloudScriptRevisionOption
UENUM(BlueprintType)
enum class ECloudScriptRevisionOption : uint8
{
    Live UMETA(DisplayName = "Live"),
    Latest UMETA(DisplayName = "Latest"),
    Specific UMETA(DisplayName = "Specific"),
};

// Enum for Currency
UENUM(BlueprintType)
enum class ECurrency : uint8
{
    AED UMETA(DisplayName = "AED"),
    AFN UMETA(DisplayName = "AFN"),
    ALL UMETA(DisplayName = "ALL"),
    AMD UMETA(DisplayName = "AMD"),
    ANG UMETA(DisplayName = "ANG"),
    AOA UMETA(DisplayName = "AOA"),
    ARS UMETA(DisplayName = "ARS"),
    AUD UMETA(DisplayName = "AUD"),
    AWG UMETA(DisplayName = "AWG"),
    AZN UMETA(DisplayName = "AZN"),
    BAM UMETA(DisplayName = "BAM"),
    BBD UMETA(DisplayName = "BBD"),
    BDT UMETA(DisplayName = "BDT"),
    BGN UMETA(DisplayName = "BGN"),
    BHD UMETA(DisplayName = "BHD"),
    BIF UMETA(DisplayName = "BIF"),
    BMD UMETA(DisplayName = "BMD"),
    BND UMETA(DisplayName = "BND"),
    BOB UMETA(DisplayName = "BOB"),
    BRL UMETA(DisplayName = "BRL"),
    BSD UMETA(DisplayName = "BSD"),
    BTN UMETA(DisplayName = "BTN"),
    BWP UMETA(DisplayName = "BWP"),
    BYR UMETA(DisplayName = "BYR"),
    BZD UMETA(DisplayName = "BZD"),
    CAD UMETA(DisplayName = "CAD"),
    CDF UMETA(DisplayName = "CDF"),
    CHF UMETA(DisplayName = "CHF"),
    CLP UMETA(DisplayName = "CLP"),
    CNY UMETA(DisplayName = "CNY"),
    COP UMETA(DisplayName = "COP"),
    CRC UMETA(DisplayName = "CRC"),
    CUC UMETA(DisplayName = "CUC"),
    CUP UMETA(DisplayName = "CUP"),
    CVE UMETA(DisplayName = "CVE"),
    CZK UMETA(DisplayName = "CZK"),
    DJF UMETA(DisplayName = "DJF"),
    DKK UMETA(DisplayName = "DKK"),
    DOP UMETA(DisplayName = "DOP"),
    DZD UMETA(DisplayName = "DZD"),
    EGP UMETA(DisplayName = "EGP"),
    ERN UMETA(DisplayName = "ERN"),
    ETB UMETA(DisplayName = "ETB"),
    EUR UMETA(DisplayName = "EUR"),
    FJD UMETA(DisplayName = "FJD"),
    FKP UMETA(DisplayName = "FKP"),
    GBP UMETA(DisplayName = "GBP"),
    GEL UMETA(DisplayName = "GEL"),
    GGP UMETA(DisplayName = "GGP"),
    GHS UMETA(DisplayName = "GHS"),
    GIP UMETA(DisplayName = "GIP"),
    GMD UMETA(DisplayName = "GMD"),
    GNF UMETA(DisplayName = "GNF"),
    GTQ UMETA(DisplayName = "GTQ"),
    GYD UMETA(DisplayName = "GYD"),
    HKD UMETA(DisplayName = "HKD"),
    HNL UMETA(DisplayName = "HNL"),
    HRK UMETA(DisplayName = "HRK"),
    HTG UMETA(DisplayName = "HTG"),
    HUF UMETA(DisplayName = "HUF"),
    IDR UMETA(DisplayName = "IDR"),
    ILS UMETA(DisplayName = "ILS"),
    IMP UMETA(DisplayName = "IMP"),
    INR UMETA(DisplayName = "INR"),
    IQD UMETA(DisplayName = "IQD"),
    IRR UMETA(DisplayName = "IRR"),
    ISK UMETA(DisplayName = "ISK"),
    JEP UMETA(DisplayName = "JEP"),
    JMD UMETA(DisplayName = "JMD"),
    JOD UMETA(DisplayName = "JOD"),
    JPY UMETA(DisplayName = "JPY"),
    KES UMETA(DisplayName = "KES"),
    KGS UMETA(DisplayName = "KGS"),
    KHR UMETA(DisplayName = "KHR"),
    KMF UMETA(DisplayName = "KMF"),
    KPW UMETA(DisplayName = "KPW"),
    KRW UMETA(DisplayName = "KRW"),
    KWD UMETA(DisplayName = "KWD"),
    KYD UMETA(DisplayName = "KYD"),
    KZT UMETA(DisplayName = "KZT"),
    LAK UMETA(DisplayName = "LAK"),
    LBP UMETA(DisplayName = "LBP"),
    LKR UMETA(DisplayName = "LKR"),
    LRD UMETA(DisplayName = "LRD"),
    LSL UMETA(DisplayName = "LSL"),
    LYD UMETA(DisplayName = "LYD"),
    MAD UMETA(DisplayName = "MAD"),
    MDL UMETA(DisplayName = "MDL"),
    MGA UMETA(DisplayName = "MGA"),
    MKD UMETA(DisplayName = "MKD"),
    MMK UMETA(DisplayName = "MMK"),
    MNT UMETA(DisplayName = "MNT"),
    MOP UMETA(DisplayName = "MOP"),
    MRO UMETA(DisplayName = "MRO"),
    MUR UMETA(DisplayName = "MUR"),
    MVR UMETA(DisplayName = "MVR"),
    MWK UMETA(DisplayName = "MWK"),
    MXN UMETA(DisplayName = "MXN"),
    MYR UMETA(DisplayName = "MYR"),
    MZN UMETA(DisplayName = "MZN"),
    NAD UMETA(DisplayName = "NAD"),
    NGN UMETA(DisplayName = "NGN"),
    NIO UMETA(DisplayName = "NIO"),
    NOK UMETA(DisplayName = "NOK"),
    NPR UMETA(DisplayName = "NPR"),
    NZD UMETA(DisplayName = "NZD"),
    OMR UMETA(DisplayName = "OMR"),
    PAB UMETA(DisplayName = "PAB"),
    PEN UMETA(DisplayName = "PEN"),
    PGK UMETA(DisplayName = "PGK"),
    PHP UMETA(DisplayName = "PHP"),
    PKR UMETA(DisplayName = "PKR"),
    PLN UMETA(DisplayName = "PLN"),
    PYG UMETA(DisplayName = "PYG"),
    QAR UMETA(DisplayName = "QAR"),
    RON UMETA(DisplayName = "RON"),
    RSD UMETA(DisplayName = "RSD"),
    RUB UMETA(DisplayName = "RUB"),
    RWF UMETA(DisplayName = "RWF"),
    SAR UMETA(DisplayName = "SAR"),
    SBD UMETA(DisplayName = "SBD"),
    SCR UMETA(DisplayName = "SCR"),
    SDG UMETA(DisplayName = "SDG"),
    SEK UMETA(DisplayName = "SEK"),
    SGD UMETA(DisplayName = "SGD"),
    SHP UMETA(DisplayName = "SHP"),
    SLL UMETA(DisplayName = "SLL"),
    SOS UMETA(DisplayName = "SOS"),
    SPL UMETA(DisplayName = "SPL"),
    SRD UMETA(DisplayName = "SRD"),
    STD UMETA(DisplayName = "STD"),
    SVC UMETA(DisplayName = "SVC"),
    SYP UMETA(DisplayName = "SYP"),
    SZL UMETA(DisplayName = "SZL"),
    THB UMETA(DisplayName = "THB"),
    TJS UMETA(DisplayName = "TJS"),
    TMT UMETA(DisplayName = "TMT"),
    TND UMETA(DisplayName = "TND"),
    TOP UMETA(DisplayName = "TOP"),
    TRY UMETA(DisplayName = "TRY"),
    TTD UMETA(DisplayName = "TTD"),
    TVD UMETA(DisplayName = "TVD"),
    TWD UMETA(DisplayName = "TWD"),
    TZS UMETA(DisplayName = "TZS"),
    UAH UMETA(DisplayName = "UAH"),
    UGX UMETA(DisplayName = "UGX"),
    USD UMETA(DisplayName = "USD"),
    UYU UMETA(DisplayName = "UYU"),
    UZS UMETA(DisplayName = "UZS"),
    VEF UMETA(DisplayName = "VEF"),
    VND UMETA(DisplayName = "VND"),
    VUV UMETA(DisplayName = "VUV"),
    WST UMETA(DisplayName = "WST"),
    XAF UMETA(DisplayName = "XAF"),
    XCD UMETA(DisplayName = "XCD"),
    XDR UMETA(DisplayName = "XDR"),
    XOF UMETA(DisplayName = "XOF"),
    XPF UMETA(DisplayName = "XPF"),
    YER UMETA(DisplayName = "YER"),
    ZAR UMETA(DisplayName = "ZAR"),
    ZMW UMETA(DisplayName = "ZMW"),
    ZWD UMETA(DisplayName = "ZWD"),
};

// Enum for MatchmakeStatus
UENUM(BlueprintType)
enum class EMatchmakeStatus : uint8
{
    Complete UMETA(DisplayName = "Complete"),
    Waiting UMETA(DisplayName = "Waiting"),
    GameNotFound UMETA(DisplayName = "GameNotFound"),
};

// Enum for Region
UENUM(BlueprintType)
enum class ERegion : uint8
{
    USCentral UMETA(DisplayName = "USCentral"),
    USEast UMETA(DisplayName = "USEast"),
    EUWest UMETA(DisplayName = "EUWest"),
    Singapore UMETA(DisplayName = "Singapore"),
    Japan UMETA(DisplayName = "Japan"),
    Brazil UMETA(DisplayName = "Brazil"),
    Australia UMETA(DisplayName = "Australia"),
};

// Enum for TitleActivationStatus
UENUM(BlueprintType)
enum class ETitleActivationStatus : uint8
{
    None UMETA(DisplayName = "None"),
    ActivatedTitleKey UMETA(DisplayName = "ActivatedTitleKey"),
    PendingSteam UMETA(DisplayName = "PendingSteam"),
    ActivatedSteam UMETA(DisplayName = "ActivatedSteam"),
    RevokedSteam UMETA(DisplayName = "RevokedSteam"),
};

// Enum for TradeStatus
UENUM(BlueprintType)
enum class ETradeStatus : uint8
{
    Invalid UMETA(DisplayName = "Invalid"),
    Opening UMETA(DisplayName = "Opening"),
    Open UMETA(DisplayName = "Open"),
    Accepting UMETA(DisplayName = "Accepting"),
    Accepted UMETA(DisplayName = "Accepted"),
    Filled UMETA(DisplayName = "Filled"),
    Cancelled UMETA(DisplayName = "Cancelled"),
};

// Enum for TransactionStatus
UENUM(BlueprintType)
enum class ETransactionStatus : uint8
{
    CreateCart UMETA(DisplayName = "CreateCart"),
    Init UMETA(DisplayName = "Init"),
    Approved UMETA(DisplayName = "Approved"),
    Succeeded UMETA(DisplayName = "Succeeded"),
    FailedByProvider UMETA(DisplayName = "FailedByProvider"),
    DisputePending UMETA(DisplayName = "DisputePending"),
    RefundPending UMETA(DisplayName = "RefundPending"),
    Refunded UMETA(DisplayName = "Refunded"),
    RefundFailed UMETA(DisplayName = "RefundFailed"),
    ChargedBack UMETA(DisplayName = "ChargedBack"),
    FailedByUber UMETA(DisplayName = "FailedByUber"),
    FailedByPlayFab UMETA(DisplayName = "FailedByPlayFab"),
    Revoked UMETA(DisplayName = "Revoked"),
    TradePending UMETA(DisplayName = "TradePending"),
    Traded UMETA(DisplayName = "Traded"),
    Upgraded UMETA(DisplayName = "Upgraded"),
    StackPending UMETA(DisplayName = "StackPending"),
    Stacked UMETA(DisplayName = "Stacked"),
    Other UMETA(DisplayName = "Other"),
    Failed UMETA(DisplayName = "Failed"),
};

// Enum for UserDataPermission
UENUM(BlueprintType)
enum class EUserDataPermission : uint8
{
    Private UMETA(DisplayName = "Private"),
    Public UMETA(DisplayName = "Public"),
};

// Enum for UserOrigination
UENUM(BlueprintType)
enum class EUserOrigination : uint8
{
    Organic UMETA(DisplayName = "Organic"),
    Steam UMETA(DisplayName = "Steam"),
    Google UMETA(DisplayName = "Google"),
    Amazon UMETA(DisplayName = "Amazon"),
    Facebook UMETA(DisplayName = "Facebook"),
    Kongregate UMETA(DisplayName = "Kongregate"),
    GamersFirst UMETA(DisplayName = "GamersFirst"),
    Unknown UMETA(DisplayName = "Unknown"),
    IOS UMETA(DisplayName = "IOS"),
    LoadTest UMETA(DisplayName = "LoadTest"),
    Android UMETA(DisplayName = "Android"),
    PSN UMETA(DisplayName = "PSN"),
    GameCenter UMETA(DisplayName = "GameCenter"),
    CustomId UMETA(DisplayName = "CustomId"),
    XboxLive UMETA(DisplayName = "XboxLive"),
    Parse UMETA(DisplayName = "Parse"),
};

