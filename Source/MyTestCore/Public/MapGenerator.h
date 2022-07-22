
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MapGenerator.generated.h"

UCLASS()
class AMapGenerator : public AActor
{
    GENERATED_BODY()

    public:
        UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
        class UBillboardComponent* Sprite;

    public:
        AMapGenerator(const FObjectInitializer& ObjectInitializer);
        virtual void BeginPlay() override;

    protected:
        UPROPERTY(VisibleAnywhere, Category="Base object")
        TArray<class UStaticMeshComponent*> Map;
};