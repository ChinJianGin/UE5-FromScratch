#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"

#include "BeatActor.generated.h"

UCLASS()
class MYTESTCORE_API ABeatActor : public AActor
{
    GENERATED_BODY()

    public:
        ABeatActor(const FObjectInitializer& ObjectInitializer);
        virtual void BeginPlay() override;
        virtual void Tick(float DeltaTime) override;

        UFUNCTION()
        void TimelineProgress(float value);
    protected:
        FTimeline CurveTimeline;

        UPROPERTY(EditAnywhere, Category="Timeline")
        UCurveFloat* CurveFloat;

        UPROPERTY()
        FVector StartLoc;

        UPROPERTY()
        FVector EndLoc;

        UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mesh")
        USceneComponent* BeatMesh;

    private:
        UFUNCTION()
        void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

        UFUNCTION()
        void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

        enum class Quadrant{
            First = 0, Second, Third, Fourth
        };

        Quadrant WhichQua;

        void TestQuadrant();
};