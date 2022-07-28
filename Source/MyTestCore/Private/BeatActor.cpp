#include "BeatActor.h"
#include "Components/SphereComponent.h"

#define MOVE_RATIO_X 1.0
#define MOVE_RATIO_Y 1.8

ABeatActor::ABeatActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){

    PrimaryActorTick.bCanEverTick = true;
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    BeatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Beat Mesh"));
    BeatMesh->SetupAttachment(RootComponent);

    USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collide"));
    SphereComponent->SetupAttachment(RootComponent);
    SphereComponent->InitSphereRadius(60.f);
    // SphereComponent->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABeatActor::OnOverlapBegin);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ABeatActor::OnOverlapEnd);
}

void ABeatActor::BeginPlay(){
    Super::BeginPlay();

    if(CurveFloat){
        FOnTimelineFloat Timeline;
        Timeline.BindUFunction(this, FName("TimelineProgress"));
        CurveTimeline.AddInterpFloat(CurveFloat, Timeline);
        // CurveTimeline.SetLooping(true);

        StartLoc = EndLoc = this->GetActorLocation();

        TestQuadrant();

        switch (WhichQua) {
            case Quadrant::First:{
                EndLoc.X -= MOVE_RATIO_X;
                EndLoc.Y -= MOVE_RATIO_Y;
            }
            break;
            case Quadrant::Second:{
                EndLoc.X -= MOVE_RATIO_X;
                EndLoc.Y += MOVE_RATIO_Y;
            }
            break;
            case Quadrant::Third:{
                EndLoc.X += MOVE_RATIO_X;
                EndLoc.Y += MOVE_RATIO_Y;
            }
            break;
            case Quadrant::Fourth:{
                EndLoc.X += MOVE_RATIO_X;
                EndLoc.Y -= MOVE_RATIO_Y;
            }
            break;

            default:
            UE_LOG(LogTemp, Error, TEXT("Out of quadrant"));
        }

        CurveTimeline.PlayFromStart();
        UE_LOG(LogTemp, Warning, TEXT("Success"));
    }
}

void ABeatActor::Tick(float DeltaTime){
    Super::Tick(DeltaTime);

    CurveTimeline.TickTimeline(DeltaTime);
}

void ABeatActor::TimelineProgress(float value){
    FVector NewLocation = FMath::Lerp(StartLoc, EndLoc, value);
    SetActorLocation(NewLocation);
}

void ABeatActor::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComp, 
    AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, 
    int32 OtherBodyIndex, 
    bool bFromSweep, 
    const FHitResult& SweepResult){
        if((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)){
            UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherActor->GetName());
        }
}

void ABeatActor::OnOverlapEnd(
    UPrimitiveComponent* OverlappedComp, 
    AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, 
    int32 OtherBodyIndex){
        if((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)){
            UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherActor->GetName());
        }
}

void ABeatActor::TestQuadrant(){
    FVector CurPos = this->GetActorLocation();

    if(CurPos.X > 0){
        if(CurPos.Y > 0){
            WhichQua = Quadrant::First;
        }else{
            WhichQua = Quadrant::Second;
        }
    }else{
        if(CurPos.Y > 0){
            WhichQua = Quadrant::Fourth;
        }else{
            WhichQua = Quadrant::Third;
        }
    }
}