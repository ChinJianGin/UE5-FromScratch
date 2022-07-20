#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FMyTestCore : public IModuleInterface
{
    public:
    static inline FMyTestCore& Get()
    {
        return FModuleManager::LoadModuleChecked<FMyTestCore>("MyTestCore");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("MyTestCore");
    }

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};