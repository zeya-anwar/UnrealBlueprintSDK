//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
// This cpp file is the main cpp file for the plugin. We set up globals here.
//
// SDK Version: 0.0.151116
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"


const FString IPlayFab::PlayFabURL(TEXT(".playfabapi.com"));
const FString IPlayFab::PlayFabLogicURL(TEXT(".playfablogic.com/"));

class FPlayFab : public IPlayFab
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override
    {
        //Force classes to be compiled on shipping build
        UPlayFabJsonObject::StaticClass();
        UPlayFabJsonValue::StaticClass();

        UPlayFabAdminAPI::StaticClass();
        UPlayFabMatchmakerAPI::StaticClass();
        UPlayFabServerAPI::StaticClass();
        UPlayFabClientAPI::StaticClass();
    }

    virtual void ShutdownModule() override
    {

    }

};

IMPLEMENT_MODULE(FPlayFab, PlayFab)

DEFINE_LOG_CATEGORY(LogPlayFab);
