#include "MyTestCore.h"
#include "Modules/ModuleManager.h"

#include "Log.h"

void FMyTestCore::StartupModule()
{
    UE_LOG(LogMyTestCore, Log, TEXT("MyTestCore module starting up"));
}

void FMyTestCore::ShutdownModule()
{
    UE_LOG(LogMyTestCore, Log, TEXT("MyTestCore module shutting down"));
}

IMPLEMENT_PRIMARY_GAME_MODULE(FMyTestCore, MyTestCore, "MyTestCore");