
#pragma once
#include "CoreMinimal.h"
#include "Camera/CameraActor.h"

#include "MainCamera.generated.h"

UCLASS()
class AMainCamera : public ACameraActor
{
    GENERATED_BODY()

    public:
        AMainCamera(const FObjectInitializer& ObjectInitializer);
        virtual void BeginPlay() override;
};